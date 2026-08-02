params ["_heli", "_targetPos", "_wpType"];

// Strip standard AI movement capabilities so they don't fight our custom physics
_heli disableAI "PATH";

// ==========================================
// INITIALIZATION & CACHING
// ==========================================
private _startAlt = (getPosATL _heli) # 2;
private _startDist = (_heli distance2D _targetPos) max 1; 
private _entrySpeed = (speed _heli) / 3.6; // Convert km/h to m/s

// Changed minimum transit altitude from 30 to 20
private _transitAlt = _startAlt max 20; 
private _descentDist = (_transitAlt * 4) max 150; // The distance at which the heli starts dropping Z-altitude

// Capture global terrain elevations for the Gradual ASL Glideslope
private _startASL_Z = getTerrainHeightASL (getPosASL _heli);
private _targetASL_Z = getTerrainHeightASL _targetPos;

// Capture exact orientation at the moment of script takeover for a smooth transition
private _pitchBank = _heli call BIS_fnc_getPitchBank;
private _currentPitch = _pitchBank # 0;
private _currentBank = -(_pitchBank # 1); 
private _currentYaw = getDir _heli;

// Capture exact velocity at the moment of script takeover
private _startVel = velocity _heli;
private _curVelX = _startVel # 0;
private _curVelY = _startVel # 1;
private _curVelZ = _startVel # 2;

private _grp = group driver _heli;
private _startingWP = currentWaypoint _grp;
private _nextRaycastTime = 0;

private _nextStateCheck = 0; 
private _phase1StartTime = time;
private _obstacleDetected = false;
private _avoidanceAlt = 0;
private _abortLanding = false;

// Initialize the LZ Pre-Scan variables
private _lzScanned = false;
private _lzHasObstacles = false;
private _lzHoverHeight = 0;
private _currentLzAvoidance = 0;

// Initialize the Zeus Drag Monitor variables
private _lastPos = getPosASL _heli;
private _lastTime = time;

// GO-AROUND INITIALIZATION
private _goAroundPhase = false;
private _goAroundYaw = _currentYaw;
private _goAroundExecuted = false; // Safeguard against infinite go-around loops
private _nextGoAroundCheck = 0; // Timer for the evaluation

// RECOVERY TURN INITIALIZATION
private _recoveryTurn = false;
private _recoveryDir = 0;

// ==========================================
// PHASE 1: UNIFIED TERRAIN-FOLLOWING & TOUCHDOWN
// ==========================================
while {true} do {
    
    // ------------------------------------------
    // DYNAMIC ABORT MONITOR (ZEUS DRAG CATCH)
    // ------------------------------------------
    private _currentTime = time;
    private _deltaTime = (_currentTime - _lastTime) max 0.01; 
    _lastTime = _currentTime;

    private _expectedMove = (vectorMagnitude velocity _heli) * _deltaTime;
    if (_lastPos distanceSqr (getPosASL _heli) > ((_expectedMove + 3) ^ 2)) then { _abortLanding = true; };
    _lastPos = getPosASL _heli;

    // ------------------------------------------
    // HEAVY LOGIC CHECKS (Throttled to 0.25s)
    // ------------------------------------------
    if (_currentTime > _nextStateCheck) then {
        _nextStateCheck = _currentTime + 0.25;

        if (count (waypoints _grp) == 0) then { _abortLanding = true; };
        private _curWpIdx = currentWaypoint _grp;
        if (_curWpIdx < count (waypoints _grp) && {(waypointPosition [_grp, _curWpIdx]) distance2D _targetPos > 25}) then { 
            _abortLanding = true; 
        };
        if (!local _heli) then { _abortLanding = true; };

        private _drv = driver _heli;
        if (isNull _drv || !alive _drv) then { 
            _abortLanding = true; 
        } else {
            if (!isNil "ace_common_fnc_isAwake") then {
                if (!([_drv] call ace_common_fnc_isAwake)) then { _abortLanding = true; };
            } else {
                if (lifeState _drv == "INCAPACITATED") then { _abortLanding = true; };
            };
        };

        private _isHumanMidLanding = false;
        if (!isNull _drv && {isPlayer _drv || !isNull (remoteControlled _drv)}) then { _isHumanMidLanding = true; };
        private _plt = currentPilot _heli;
        if (!isNull _plt && {isPlayer _plt || !isNull (remoteControlled _plt)}) then { _isHumanMidLanding = true; };
        if (_isHumanMidLanding) then { _abortLanding = true; };

        if (!isNull (getSlingLoad _heli) || !isEngineOn _heli) then { _abortLanding = true; };

        private _damageHRotor = _heli getHitPointDamage "HitHRotor";
        private _damageVRotor = _heli getHitPointDamage "HitVRotor";
        private _damageEngine = _heli getHitPointDamage "HitEngine";

        if (
            !alive _heli || 
            !canMove _heli || 
            fuel _heli <= 0 || 
            (!isNil "_damageHRotor" && {_damageHRotor >= 0.9}) || 
            (!isNil "_damageVRotor" && {_damageVRotor >= 0.9}) || 
            (!isNil "_damageEngine" && {_damageEngine >= 0.9})
        ) then {
            _abortLanding = true;
        };
    };

    if (_abortLanding || isTouchingGround _heli) exitWith {}; 

    // ------------------------------------------
    // FLIGHT PHYSICS MATH (Runs every 0.05s)
    // ------------------------------------------
    private _dist = _heli distance2D _targetPos;
    private _alt = (getPosATL _heli) # 2;
    private _currentSpeed = speed _heli;
    private _timeActive = _currentTime - _phase1StartTime;
    
    // Capture actual engine state for the Master Momentum Blender
    private _actualVel = velocity _heli; 
    private _actualPitchBank = _heli call BIS_fnc_getPitchBank;
    private _actualPitch = _actualPitchBank # 0;
    private _actualBank = -(_actualPitchBank # 1); 
    private _actualYaw = getDir _heli;

    private _relativeAlt = ((getPosASL _heli) # 2) - _targetASL_Z;

    // ==========================================
    // SMART LZ PRE-SCAN (70m COMMITMENT GATE)
    // ==========================================
    if (!_lzScanned && _dist < 70) then {
        _lzScanned = true;
        
        private _lzObstacles = nearestTerrainObjects [_targetPos, ["CHAPEL","CHURCH","FUELSTATION","HOSPITAL","HOUSE","LIGHTHOUSE","POWERLINES","POWERSOLAR","POWERWAVE","POWERWIND","ROCK","RUIN","TREE","WALL"], 25, false];
        
        if (count _lzObstacles > 0) then {
            _lzHasObstacles = true;
            private _highestObsASL = 0;
            
            private _maxObs = (count _lzObstacles) min 10;
            for "_i" from 0 to (_maxObs - 1) do {
                private _obs = _lzObstacles select _i;
                private _bbr = boundingBoxReal _obs;
                private _topZ = (_bbr select 1) select 2;
                
                private _obsASL = ((getPosASL _obs) # 2) + _topZ;
                if (_obsASL > _highestObsASL) then {
                    _highestObsASL = _obsASL;
                };
            };
            
            _lzHoverHeight = ((_highestObsASL - _targetASL_Z) max 0) + 5;
            _lzHoverHeight = _lzHoverHeight min 40; 
        };
    };

    // ==========================================
    // EACH-FRAME LANDING GEAR LOCK
    // ==========================================
    if ((_heli distance _targetPos) < 100 && isNil {_heli getVariable "BHL_GearEH"}) then {
        private _gearEH = addMissionEventHandler ["EachFrame", {
            private _h = _thisArgs select 0;
            
            // Failsafe: Self-clean if heli is deleted or destroyed
            if (isNull _h || !alive _h) exitWith { removeMissionEventHandler ["EachFrame", _thisEventHandler]; };
            
            // Failsafe: Prevent execution stack on ALT+TAB / SP Pause
            if (isGamePaused) exitWith {};
            
            if (!isNull driver _h) then {
                (driver _h) action ["LandGear", _h];
            };
        }, [_heli]];
        _heli setVariable ["BHL_GearEH", _gearEH];
    };

    // ==========================================
    // GO-AROUND TRIGGER & TERMINATION LOGIC
    // ==========================================
    if (!_goAroundPhase && !_goAroundExecuted && _dist < 200 && _alt > 75 && _relativeAlt > 150) then {
        _goAroundPhase = true;
        _goAroundYaw = _currentYaw; 
        _nextGoAroundCheck = _currentTime + 1; 
    };
    
    if (_goAroundPhase && _currentTime > _nextGoAroundCheck) then {
        _nextGoAroundCheck = _currentTime + 1;
        
        private _altASL = (getPosASL _heli) # 2;
        
        if (_dist >= 200 && (_alt < 175 || _relativeAlt < 175)) then {
            _goAroundPhase = false;
            _goAroundExecuted = true; 
            
            private _targetDir = _heli getDir _targetPos;
            private _mathDiff = _targetDir - _currentYaw;
            while {_mathDiff > 180} do {_mathDiff = _mathDiff - 360;};
            while {_mathDiff < -180} do {_mathDiff = _mathDiff + 360;};
            
            private _shortestDir = if (_mathDiff > 0) then { 1 } else { -1 }; 
            
            private _leftPos = _heli getPos [300, _currentYaw - 90];
            private _rightPos = _heli getPos [300, _currentYaw + 90];
            
            private _leftHeight = getTerrainHeightASL _leftPos;
            private _rightHeight = getTerrainHeightASL _rightPos;
            
            _recoveryTurn = true;
            _recoveryDir = _shortestDir; 
            
            if (_shortestDir == 1 && {(_rightHeight - _leftHeight) > 25}) then {
                _recoveryDir = -1; 
            };
            if (_shortestDir == -1 && {(_leftHeight - _rightHeight) > 25}) then {
                _recoveryDir = 1; 
            };
            
            // WIPE LZ MEMORY FOR THE SECOND ATTEMPT!
            _lzScanned = false;
            _lzHasObstacles = false;
            _lzHoverHeight = 0;
            _currentLzAvoidance = 0;
            
            _startDist = _dist max 1; 
            _startASL_Z = getTerrainHeightASL (getPosASL _heli); // Update ASL baseline for the new approach
            _entrySpeed = (speed _heli) / 3.6;
            _phase1StartTime = _currentTime; 
        };
    };

    // ==========================================
    // YAW & BANKING
    // ==========================================
    private _idealYaw = _heli getDir _targetPos;
    
    if (_goAroundPhase) then { 
        _idealYaw = _goAroundYaw; 
    } else {
        if (_dist < 10) then { _idealYaw = _currentYaw; };
    };

    private _yawDiff = _idealYaw - _currentYaw;
    while {_yawDiff > 180} do {_yawDiff = _yawDiff - 360;};
    while {_yawDiff < -180} do {_yawDiff = _yawDiff + 360;};

    if (_recoveryTurn && {abs _yawDiff < 30}) then {
        _recoveryTurn = false;
    };

    if (_recoveryTurn) then {
        if (_recoveryDir == 1 && _yawDiff < 0) then { _yawDiff = _yawDiff + 360; };
        if (_recoveryDir == -1 && _yawDiff > 0) then { _yawDiff = _yawDiff - 360; };
    };

    private _idealBank = 0;
    if (_dist > 25 && !_goAroundPhase) then { _idealBank = (_yawDiff * -2.5) min 50 max -50; };

    _currentBank = _currentBank + ((_idealBank - _currentBank) * 0.08); 

    private _speedFactor = (_currentSpeed / 50) min 1; 
    private _flatYawRate = _yawDiff * 0.05; 
    private _bankTurnRate = _currentBank * -0.015; 
    
    private _yawChange = (_flatYawRate * (1 - _speedFactor)) + (_bankTurnRate * _speedFactor);
    _yawChange = _yawChange min 1.5 max -1.5; 
    
    _currentYaw = _currentYaw + _yawChange;
    if (_currentYaw < 0) then { _currentYaw = _currentYaw + 360; };
    if (_currentYaw >= 360) then { _currentYaw = _currentYaw - 360; };

    // ==========================================
    // VELOCITY CALCULATION
    // ==========================================
    private _targetVel = 0;
    if (_goAroundPhase) then {
        _targetVel = (_currentSpeed / 3.6) max 17; 
    } else {
        if (_dist > 0.5) then {
            private _distFactor = sqrt ((_dist / _startDist) min 1);
            _targetVel = (_entrySpeed * _distFactor) max (2 min _dist); 
        }; 
        if (_dist > 50 && _alt < 20) then { _targetVel = _targetVel * ((_alt max 5) / 20); };
    };
    
    private _travelYaw = _currentYaw;
    if (_goAroundPhase) then { 
        _travelYaw = _goAroundYaw; 
    };
    if (_dist < 10 && !_goAroundPhase) then {
        _travelYaw = _heli getDir _targetPos;
    };
    
    private _idealVelX = sin _travelYaw * _targetVel;
    private _idealVelY = cos _travelYaw * _targetVel;

    private _idealAlt = -1; 
    if (_dist > _descentDist) then {
        _idealAlt = _transitAlt; 
    } else {
        private _descentRatio = _dist / _descentDist;
        _idealAlt = -1 + ((_transitAlt - -1) * _descentRatio);
    };

    // ==========================================
    // 3D TRAJECTORY FORWARD RADAR
    // ==========================================
    if (_dist > 30) then {
        if (_currentTime > _nextRaycastTime) then {
            
            private _flightDir = _curVelX atan2 _curVelY; 
            
            private _scanPos = _heli getPos [50, _flightDir];
            private _radarObstacles = nearestTerrainObjects [_scanPos, ["CHAPEL","CHURCH","FUELSTATION","HOSPITAL","HOUSE","LIGHTHOUSE","POWERLINES","POWERSOLAR","POWERWAVE","POWERWIND","ROCK","RUIN","TREE","WALL"], 15, false];
            
            _obstacleDetected = false;
            
            if (count _radarObstacles > 0) then {
                
                private _futureDist = (_dist - 50) max 0; 
                
                private _futureIdealAlt = -1; 
                if (_futureDist > _descentDist) then {
                    _futureIdealAlt = _transitAlt; 
                } else {
                    private _futureDescentRatio = _futureDist / _descentDist;
                    _futureIdealAlt = -1 + ((_transitAlt - -1) * _futureDescentRatio);
                };
                
                _futureIdealAlt = _futureIdealAlt + _avoidanceAlt; 
                
                private _futureProgressRatio = 1 - ((_futureDist / _startDist) min 1 max 0);
                private _futureExpectedTerrainASL = _startASL_Z + ((_targetASL_Z - _startASL_Z) * _futureProgressRatio);
                private _futureFlightASL = _futureExpectedTerrainASL + _futureIdealAlt;
                
                private _maxObs = (count _radarObstacles) min 5; 
                for "_i" from 0 to (_maxObs - 1) do {
                    private _obs = _radarObstacles select _i;
                    private _bbr = boundingBoxReal _obs;
                    private _topZ = (_bbr select 1) select 2;
                    private _obsASL = ((getPosASL _obs) # 2) + _topZ;
                    
                    if (_obsASL > (_futureFlightASL - 10)) then {
                        _obstacleDetected = true;
                        break; 
                    };
                };
            };
            
            if (_obstacleDetected) then { _transitAlt = _transitAlt + 2; };
            _nextRaycastTime = _currentTime + 0.25; 
        };
        private _targetAvoidance = if (_obstacleDetected) then { 25 } else { 0 };
        _avoidanceAlt = _avoidanceAlt + ((_targetAvoidance - _avoidanceAlt) * 0.1);
    } else {
        _obstacleDetected = false;
        _avoidanceAlt = 0; 
    };

    _idealAlt = _idealAlt + _avoidanceAlt;
    
    // ==========================================
    // OBSTACLE CANOPY HOVER ADJUSTMENT 
    // ==========================================
    private _targetLzAvoidance = 0;
    if (_lzHasObstacles && _dist >= 5) then {
        _targetLzAvoidance = _lzHoverHeight; 
    };
    
    _currentLzAvoidance = _currentLzAvoidance + ((_targetLzAvoidance - _currentLzAvoidance) * 0.05);
    _idealAlt = _idealAlt max _currentLzAvoidance;
    
    // ==========================================
    // THE VALLEY TRAP AVOIDANCE & UPHILL POP-UP
    // ==========================================
    private _altDiff = _idealAlt - _alt;
    
    private _progressRatio = 1 - ((_dist / _startDist) min 1 max 0);
    private _currentExpectedTerrainASL = _startASL_Z + ((_targetASL_Z - _startASL_Z) * _progressRatio);
    private _targetFlightASL = _currentExpectedTerrainASL + _idealAlt;
    
    // --- UPHILL APPROACH POP-UP FIX ---
    if (_startASL_Z <= _targetASL_Z + 15) then {
        private _popUpAlt = 20; 
        private _minApproachASL = _targetASL_Z;
        
        if (_dist > 80) then {
            private _distRange = (_startDist - 80) max 1;
            private _climbProgress = 1 - (((_dist - 80) max 0) / _distRange);
            _climbProgress = _climbProgress max 0 min 1;
            
            _minApproachASL = _startASL_Z + ((_targetASL_Z + _popUpAlt - _startASL_Z) * _climbProgress);
        } else {
            _minApproachASL = _targetASL_Z + (_popUpAlt * (_dist / 80));
        };
        
        _targetFlightASL = _targetFlightASL max _minApproachASL;
    };

    private _aslDiff = _targetFlightASL - ((getPosASL _heli) # 2);
    
    if (_startASL_Z <= _targetASL_Z + 15 && _dist < 80 && _alt > 5) then {
        _altDiff = _aslDiff; 
    } else {
        _altDiff = _altDiff max _aslDiff;
    };
    
    private _idealVelZ = 0;
    
    // ==========================================
    // THE GO-AROUND DESCENT 
    // ==========================================
    if (_goAroundPhase) then {
        _idealVelZ = -6; 
    } else {
        _idealVelZ = (_altDiff * 0.5) min 25 max -10; 
        if (_dist < 15 && _relativeAlt > -2) then { _idealVelZ = _idealVelZ min 0; };
        if (_dist < 10 && _relativeAlt > -1) then { _idealVelZ = _idealVelZ min -2.5; };
    };

    // ==========================================
    // PART 2: FLIGHT ATTITUDE & DELTA-V PHYSICS
    // ==========================================
    private _currentVelMag = (_currentSpeed / 3.6) max 0.1;
    private _deltaV = _currentVelMag - _targetVel; 

    private _idealPitch = 0;
    if (_goAroundPhase) then {
        _idealPitch = -8; 
    } else {
        if (_deltaV > 0.1) then {
            _idealPitch = (_deltaV * 2.5) min 40;
            if (_dist < 150) then { 
                _idealPitch = (_deltaV * 5) min 40; 
            };
        } else {
            if (_deltaV < -0.1) then {
                _idealPitch = (_deltaV * 1.5) max -25;
            };
        };
        
        // --- EVASION SUPPRESSION FIX ---
        if (_idealVelZ > 2 && _dist > 50) then {
            private _evasionWeight = (_idealVelZ / 15) min 1;
            _idealPitch = _idealPitch * (1 - _evasionWeight);
        };
        
        // --- TERMINAL FLARE FIX ---
        private _flareCap = 40;
        if (_alt < 1 && _dist < 3 && _relativeAlt > -1) then { _flareCap = _alt * 40; };
        _idealPitch = _idealPitch min _flareCap;
    };

    _idealPitch = _idealPitch - (abs _currentBank * 0.25); 
    _currentPitch = _currentPitch + ((_idealPitch - _currentPitch) * 0.04); 

    // ==========================================
    // KINEMATIC APPLICATION
    // ==========================================
    private _velLerpXY = 0.025; 
    
    // --- Dynamic Ground Effect Braking ---
    if (_dist < 15 && !_goAroundPhase) then {
        _velLerpXY = 0.025 + (0.065 * (1 - (_dist / 15)));
    };
    
    _curVelX = _curVelX + ((_idealVelX - _curVelX) * _velLerpXY);
    _curVelY = _curVelY + ((_idealVelY - _curVelY) * _velLerpXY);
    
    private _zLerp = if (_idealVelZ > _curVelZ) then { 0.2 } else { 0.1 };
    _curVelZ = _curVelZ + ((_idealVelZ - _curVelZ) * _zLerp);

    // ==========================================
    // THE MASTER MOMENTUM BLENDER 
    // ==========================================
    if (_timeActive < 2.5) then {
        private _engineWeight = 1 - (_timeActive / 2.5);
        _engineWeight = _engineWeight ^ 3; 

        _curVelX = (_curVelX * (1 - _engineWeight)) + ((_actualVel # 0) * _engineWeight);
        _curVelY = (_curVelY * (1 - _engineWeight)) + ((_actualVel # 1) * _engineWeight);
        _curVelZ = (_curVelZ * (1 - _engineWeight)) + ((_actualVel # 2) * _engineWeight);

        _currentPitch = (_currentPitch * (1 - _engineWeight)) + (_actualPitch * _engineWeight);
        _currentBank = (_currentBank * (1 - _engineWeight)) + (_actualBank * _engineWeight);

        private _yawDiffBlend = _actualYaw - _currentYaw;
        while {_yawDiffBlend > 180} do {_yawDiffBlend = _yawDiffBlend - 360;};
        while {_yawDiffBlend < -180} do {_yawDiffBlend = _yawDiffBlend + 360;};
        _currentYaw = _currentYaw + (_yawDiffBlend * _engineWeight);
        
        if (_currentYaw < 0) then { _currentYaw = _currentYaw + 360; };
        if (_currentYaw >= 360) then { _currentYaw = _currentYaw - 360; };
    };

    private _vDir = [
        sin(_currentYaw) * cos(_currentPitch),
        cos(_currentYaw) * cos(_currentPitch),
        sin(_currentPitch)
    ];
    private _vRight = [
        cos(_currentYaw) * cos(_currentBank) - sin(_currentYaw) * sin(_currentPitch) * sin(_currentBank),
        -sin(_currentYaw) * cos(_currentBank) - cos(_currentYaw) * sin(_currentPitch) * sin(_currentBank),
        cos(_currentPitch) * sin(_currentBank)
    ];
    private _vUp = _vRight vectorCrossProduct _vDir;

    _heli setVectorDirAndUp [_vDir, _vUp];
    _heli setVelocity [_curVelX, _curVelY, _curVelZ];

    sleep 0.05; 
};

// ==========================================
// ABORT HANDLER
// ==========================================
if (_abortLanding) exitWith {
    
    private _gearEH = _heli getVariable "BHL_GearEH";
    if (!isNil "_gearEH") then {
        removeMissionEventHandler ["EachFrame", _gearEH];
        _heli setVariable ["BHL_GearEH", nil];
    };

    if (alive _heli && local _heli) then {
        _heli enableAI "PATH";
        _heli enableAI "MOVE";
        
        private _isHumanBreak = false;
        private _plt = currentPilot _heli;
        if (!isNull _plt && {isPlayer _plt || !isNull (remoteControlled _plt)}) then { _isHumanBreak = true; };
        
        if (!_isHumanBreak && isEngineOn _heli && isNull (getSlingLoad _heli)) then {
            _heli flyInHeight 30; 
        };
    };
};

// ==========================================
// PHASE 2: INSTANT LOCK & WAKE-UP
// ==========================================

private _baseMass = getMass _heli; 
private _centerOfMass = getCenterOfMass _heli;

// Apply initial brief ground stick to prevent bouncing on frame 1
_heli addForce [(vectorUp _heli) vectorMultiply (_baseMass * -0.1), _centerOfMass];

private _helipad = "Land_HelipadEmpty_F" createVehicleLocal _targetPos;

_heli disableAI "MOVE"; 

if (!isNull _helipad) then { deleteVehicle _helipad; };

_heli enableAI "PATH";
_heli flyInHeight 0;

// ------------------------------------------
// BACKGROUND THREADS (THE UNIFIED ANCHOR)
// ------------------------------------------

[_heli, _grp, _targetPos, _wpType, _baseMass, _centerOfMass] spawn {
    params ["_heli", "_grp", "_targetPos", "_wpType", "_baseMass", "_centerOfMass"];
    
    private _anchorPos = getPosASL _heli;
    private _nextStateCheck = 0; 
    
    private _anchorStartTime = time;
    
    // --- NEW: EACH-FRAME CONTINUOUS ANCHOR PHYSICS ---
    // Smoothly pushes down every single frame, eliminating all 0.05s suspension bounce
    private _forceEH = addMissionEventHandler ["EachFrame", {
        private _args = _thisArgs;
        _args params ["_h", "_bMass", "_cMass", "_startTime"];
        
        // Failsafe: Self-clean if heli is deleted or destroyed 
        if (isNull _h || !alive _h) exitWith { removeMissionEventHandler ["EachFrame", _thisEventHandler]; };
        
        // Failsafe: Prevent massive physics spike on ALT+TAB / SP Pause
        if (isGamePaused) exitWith {};
        
        private _elapsed = (time - _startTime) max 0;
        private _lerpFactor = (_elapsed / 3) min 1; 
        
        // Interpolates multiplier from -0.1 to -0.4 over 3 seconds
        private _currentMultiplier = -0.1 + (_lerpFactor * (-0.4 - -0.1)); 
        private _currentDownForce = _bMass * _currentMultiplier;

        _h addForce [(vectorUp _h) vectorMultiply _currentDownForce, _cMass];
    }, [_heli, _baseMass, _centerOfMass, _anchorStartTime]];
    
    _heli setVariable ["BHL_ForceEH", _forceEH];

    // The while-loop is now strictly a lightweight state monitor for breaking the anchor
    while {true} do {
        sleep 0.05; 
        
        if (!alive _heli || !local _heli) exitWith {};
        
        if ((_anchorPos distance2D (getPosASL _heli)) > 5) exitWith {};
        _anchorPos = getPosASL _heli;
        
        private _breakAnchor = false;
        
        if (time > _nextStateCheck) then {
            _nextStateCheck = time + 0.25;
            
            private _drv = driver _heli;
            if (isNull _drv || !alive _drv) then { 
                _breakAnchor = true; 
            } else {
                private _isAwake = true;
                if (!isNil "ace_common_fnc_isAwake") then {
                    _isAwake = [_drv] call ace_common_fnc_isAwake;
                } else {
                    _isAwake = (lifeState _drv != "INCAPACITATED");
                };
                if (!_isAwake) then { _breakAnchor = true; };
            };
            
            if (!_breakAnchor) then {
                private _isHuman = false;
                if (!isNull _drv && {isPlayer _drv || !isNull (remoteControlled _drv)}) then { _isHuman = true; };
                private _plt = currentPilot _heli;
                if (!isNull _plt && {isPlayer _plt || !isNull (remoteControlled _plt)}) then { _isHuman = true; };
                if (_isHuman) then { _breakAnchor = true; };
            };
            
            if (!_breakAnchor && !isEngineOn _heli) then { 
                _breakAnchor = true; 
            };
            
            if (!_breakAnchor && count (waypoints _grp) == 0) then { _breakAnchor = true; };
            
            if (!_breakAnchor) then {
                private _curWpIdx = currentWaypoint _grp;
                if (_curWpIdx < count (waypoints _grp) && {(waypointPosition [_grp, _curWpIdx]) distance2D _targetPos > 25}) then { 
                    _breakAnchor = true; 
                };
            };
        };
        
        if (_breakAnchor) exitWith {};
    };
    
    // ==========================================
    // RESTORATION BLOCK
    // ==========================================
    private _gearEH = _heli getVariable "BHL_GearEH";
    if (!isNil "_gearEH") then {
        removeMissionEventHandler ["EachFrame", _gearEH];
        _heli setVariable ["BHL_GearEH", nil];
    };
    
    private _fEH = _heli getVariable "BHL_ForceEH";
    if (!isNil "_fEH") then {
        removeMissionEventHandler ["EachFrame", _fEH];
        _heli setVariable ["BHL_ForceEH", nil];
    };

    if (alive _heli && local _heli) then {
        _heli enableAI "MOVE";
        _heli enableAI "PATH";
        _heli land "NONE"; 
        
        private _isHuman = false;
        private _plt = currentPilot _heli;
        if (!isNull _plt && {isPlayer _plt || !isNull (remoteControlled _plt)}) then { _isHuman = true; };
        
        if (!_isHuman && !isNull driver _heli) then {
            _heli flyInHeight 30; 
        };
    };
};