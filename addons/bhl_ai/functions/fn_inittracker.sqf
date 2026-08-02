private _heli = _this select 0;

[_heli] spawn {
    private _heliSpawned = _this select 0;
    
    private _cachedPos = [0,0,0];
    private _cachedType = "";
    
    private _monitoredWpPos = [-10000, -10000, 0]; 
    private _monitoredWpType = "";
    
    while {alive _heliSpawned} do {
        sleep 1;
        
        // MP Locality Gate. 
        if (local _heliSpawned) then {
            
            private _drv = driver _heliSpawned;
            
            // ACE3 / Vanilla Medical Check
            private _isAwake = true;
            if (!isNull _drv) then {
                if (!isNil "ace_common_fnc_isAwake") then {
                    _isAwake = [_drv] call ace_common_fnc_isAwake;
                } else {
                    _isAwake = (lifeState _drv != "INCAPACITATED");
                };
            };
            
            if (!isNull _drv && !(isPlayer _drv) && alive _drv && _isAwake) then {
                private _grp = group _drv;
                private _wpIndex = currentWaypoint _grp;
                
                if (_wpIndex < count (waypoints _grp)) then {
                    private _wpPos = waypointPosition [_grp, _wpIndex];
                    private _wpType = waypointType [_grp, _wpIndex];
                    
                    // Re-evaluate if the destination moves OR if you change the type in Zeus
                    if (_wpPos distance2D _monitoredWpPos > 10 || _wpType != _monitoredWpType) then {
                        
                        // ==========================================
                        // THE PHANTOM SCRIPT ANTIDOTE
                        // ==========================================
                        if (_monitoredWpType != "") then {
                            _heliSpawned land "NONE";
                            _drv doFollow (leader _grp);
                        };
                        
                        _monitoredWpPos = _wpPos; 
                        _monitoredWpType = _wpType; 
                        
                        // Convert the script path to lowercase for universal scanning
                        // (Saved original to allow exact reapplying if it's a ZEN waypoint)
                        private _originalScript = waypointScript [_grp, _wpIndex];
                        private _wpScript = toLower _originalScript;
                        
                        // ==========================================
                        // ZEN & VANILLA WAYPOINT DETECTION
                        // ==========================================
                        // Removed "UNLOAD" from compatibility array
                        private _isLandingWP = (
                            _wpType in ["TR UNLOAD", "GETOUT", "LAND"] || 
                            _wpScript find "wpland" > -1 || 
                            (_wpScript find "zen" > -1 && _wpScript find "land" > -1) // Zeus Enhanced (ZEN) Catch
                        );
                        
                        if (_isLandingWP) then {
                            
                            // ==========================================
                            // THE GHOST LANDING INTERCEPTOR & REISSUE
                            // ==========================================
                            // Executes precisely when the tracker registers the new landing waypoint
                            if (landResult _heliSpawned == "Found" || landResult _heliSpawned == "NotReady") then {
                                
                                // 1. Wipe the ghost state
                                _heliSpawned land "NONE";
                                
                                // 2. Cycle to MOVE to force the AI to clear its internal action buffer
                                [_grp, _wpIndex] setWaypointType "MOVE";
                                
                                // 3. Reissue the waypoint properly
                                if (_wpType == "LAND") then {
                                    // Per the BIKI comments: "LAND" is not a native setWaypointType argument. 
                                    // We must rebuild it as SCRIPTED using fn_wpLand.sqf
                                    [_grp, _wpIndex] setWaypointType "SCRIPTED";
                                    [_grp, _wpIndex] setWaypointScript "A3\functions_f\waypoints\fn_wpLand.sqf";
                                    
                                    // Update our monitored type so the loop doesn't instantly re-trigger
                                    _monitoredWpType = "SCRIPTED"; 
                                } else {
                                    // Handles TR UNLOAD, GETOUT, or ZEN waypoints perfectly
                                    [_grp, _wpIndex] setWaypointType _wpType;
                                    if (_originalScript != "") then {
                                        [_grp, _wpIndex] setWaypointScript _originalScript;
                                    };
                                };
                            };

                            // Reduced minimum waypoint cache distance to 100m
                            if (_heliSpawned distance2D _wpPos > 100) then {
                                _cachedPos = _wpPos;
                                _cachedType = "LANDING"; 
                            } else {
                                _cachedType = "IGNORE"; 
                            };
                        } else {
                            _cachedType = "";
                            _cachedPos = [0,0,0];
                        };
                    };
                } else {
                    // No active waypoints
                    _cachedType = "";
                    _cachedPos = [0,0,0];
                    _monitoredWpPos = [-10000, -10000, 0];
                    _monitoredWpType = "";
                };
                
                if (_cachedType == "LANDING") then {
                    private _speed = speed _heliSpawned; 

                    // Increased minimum trigger speed to 70km/h
                    if (_speed > 70) then {
                        private _dist = _heliSpawned distance2D _cachedPos;
                        
                        // Adjusted trigger distance multiplier to 4.2
                        private _triggerDist = (_speed * 4.2) max 500;

                        // Reverted inner distance threshold back to 50m
                        if (_dist < _triggerDist && _dist > 50) then {
                            
                            // call is blocking. The tracker will wait here until the landing logic completely finishes or aborts.
                            [_heliSpawned, _cachedPos, _cachedType] call BHL_fnc_landingLogic;
                            
                            _cachedType = "";
                            _cachedPos = [0,0,0];
                        };
                    };
                };
            };
        } else {
            _cachedType = "";
            _cachedPos = [0,0,0];
            _monitoredWpPos = [-10000, -10000, 0];
            _monitoredWpType = "";
        };
    };
};