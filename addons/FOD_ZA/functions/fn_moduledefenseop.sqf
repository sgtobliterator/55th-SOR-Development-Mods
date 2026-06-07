params [
	["_mode", "", [""]],
	["_input", [], [[]]]
];

_input params [
	["_module", objNull, [objNull]],
	["_isActivated", false, [true]],
	["_isCuratorPlaced", false, [true]]
];

private _sideStr     = _module getVariable ["FOD_ZA_DOP_Side",        "EAST"];
private _factClass   = _module getVariable ["FOD_ZA_DOP_FactionClass", ""];
private _rush        = _module getVariable ["FOD_ZA_DOP_Rush",         true];
private _losToggle   = _module getVariable ["FOD_ZA_DOP_LoS",          true];
private _interval    = _module getVariable ["FOD_ZA_DOP_Interval",     30];
private _directional = _module getVariable ["FOD_ZA_DOP_Directional",  false];
private _attackDir   = _module getVariable ["FOD_ZA_DOP_AttackDir",    0];
private _attackArc   = _module getVariable ["FOD_ZA_DOP_AttackArc",    90];
private _filterStr   = _module getVariable ["FOD_ZA_DOP_GroupFilter",  ""];
private _maxTime     = _module getVariable ["FOD_ZA_DOP_MaxTime",       0];
private _condCode    = _module getVariable ["#FOD_ZA_DOP_Condition",    {}];

private _area = _module getVariable ["ObjectArea", [100, 100, 0, false, -1]];
if (is3DEN) then {
	private _size = (_module get3DENAttribute "Size3") select 0;
	_size params [["_a", 100, [0]], ["_b", 100, [0]]];
	_area = [_a, _b, 0, false, -1];
};
private _radius = round ((_area#0 + _area#1) / 2);

switch (_mode) do {
	case "init": {
		if (_isActivated && isServer) then {
			if (!isClass (configFile >> "CfgPatches" >> "lambs_wp")) exitWith {
				["[FOD_ZA_ModuleDefenseOP] ERROR: LAMBS Waypoints is required but not detected."] call FOD_ZA_fnc_debugMessage;
			};

			if (_factClass isEqualTo "") exitWith {
				["[FOD_ZA_ModuleDefenseOP] ERROR: No faction classname configured."] call FOD_ZA_fnc_debugMessage;
			};

			private _sideNumber = switch (toUpper _sideStr) do {
				case "EAST":        { 0 };
				case "WEST":        { 1 };
				case "INDEPENDENT": { 2 };
				default             { 0 };
			};

			private _sideCfg = ["East", "West", "Indep"] # _sideNumber;

			// Gather all group classnames for this faction
			private _allGroupClassnames = [];
			{
				private _category = _x;
				{ _allGroupClassnames pushBack (configName _x); } forEach ("true" configClasses _category);
			} forEach ("true" configClasses (configFile >> "CfgGroups" >> _sideCfg >> _factClass));

			if (_allGroupClassnames isEqualTo []) exitWith {
				["[FOD_ZA_ModuleDefenseOP] ERROR: No groups found for faction '%1' (%2).", _factClass, _sideCfg] call FOD_ZA_fnc_debugMessage;
			};

			// Apply optional filter (, separated classnames; empty = all groups)
			private _groupClassnames = if (_filterStr isEqualTo "") then {
				_allGroupClassnames
			} else {
				private _filter = (_filterStr splitString ",") apply { trim _x };
				private _filtered = _allGroupClassnames select { _x in _filter };
				if (_filtered isEqualTo []) then {
					["[FOD_ZA_ModuleDefenseOP] WARNING: Group filter matched nothing - using all groups."] call FOD_ZA_fnc_debugMessage;
					_allGroupClassnames
				} else {
					_filtered
				}
			};

			[_groupClassnames, _factClass, _sideNumber, _sideCfg, _radius, _rush, _losToggle, _interval, _module, _directional, _attackDir, _attackArc, _maxTime, _condCode] spawn {
				params ["_groupClassnames", "_factClass", "_sideNumber", "_sideCfg", "_radius", "_rush", "_LoSToggle", "_interval", "_module", "_directional", "_attackDir", "_attackArc", "_maxTime", "_condCode"];

				private _side = [east, west, resistance] # _sideNumber;
				private _startTime = time;
				private _hasCondition = !(_condCode isEqualTo {});

				while {
					if (_hasCondition) then {
						!((call _condCode) isEqualTo true)
					} else {
						if (_maxTime > 0) then {
							time - _startTime < _maxTime
						} else {
							true
						}
					}
				} do {
					private _grpClass = selectRandom _groupClassnames;

					private _spawnPos = if (_directional) then {
						private _pos = [0,0,0];
						for "_attempt" from 1 to 15 do {
							private _angle     = _attackDir - (_attackArc / 2) + random _attackArc;
							private _dist      = _radius * 0.8 + random (_radius * 0.4);
							private _candidate = (getPosATL _module) getPos [_dist, _angle];
							if (surfaceIsWater _candidate) then { continue };
							if (_LoSToggle) then {
								private _enemies = allUnits select { alive _x && { [_side, side _x] call BIS_fnc_sideIsEnemy } };
								private _hasLoS = false;
								{ if (count (lineIntersectsWith [eyePos _x, AGLToASL _candidate]) == 0) exitWith { _hasLoS = true }; } forEach _enemies;
								if (_hasLoS) then { continue };
							};
							_pos = _candidate;
							break;
						};
						_pos
					} else {
						[_module, _radius, _side, _LoSToggle] call PHEN_fnc_findValidSpawnPos
					};

					if !(_spawnPos isEqualTo [0,0,0]) then {
						private _groupCfgPath = configNull;
						{
							private _category = _x;
							{
								if (configName _x == _grpClass) exitWith { _groupCfgPath = _x; };
							} forEach ("true" configClasses _category);
							if (!isNull _groupCfgPath) exitWith {};
						} forEach ("true" configClasses (configFile >> "CfgGroups" >> _sideCfg >> _factClass));

						if (isNull _groupCfgPath) exitWith {
							["[FOD_ZA_ModuleDefenseOP] ERROR: Group class %1 not found in faction %2.", _grpClass, _factClass] call FOD_ZA_fnc_debugMessage;
						};

						private _grp = [_spawnPos, _side, _groupCfgPath, [], [], [], [], [-1, 1], (_module getRelDir _spawnPos)] call BIS_fnc_spawnGroup;

						{ [_x, 1] remoteExec ["ZeusEditableObject", 2]; } forEach (units _grp);

						if (local _grp) then {
							_grp deleteGroupWhenEmpty true;
						} else {
							[_grp, true] remoteExec ["deleteGroupWhenEmpty", groupOwner _grp];
						};

						["[FOD_ZA_ModuleDefenseOP] Spawned group %1 (%2), task: %3, interval: %4s.", _grpClass, _sideCfg, (["SAD","Rush"] select _rush), _interval] call FOD_ZA_fnc_debugMessage;

						if (_rush) then {
							[_grp, _radius, 15, [], getPosATL _module, true] spawn lambs_wp_fnc_taskRush;
						} else {
							private _wp = _grp addWaypoint [getPosATL _module, -1];
							_wp setWaypointType "SAD";
							_grp setSpeedMode "FULL";
							_grp setCombatBehaviour "AWARE";
							{ _x setUnitPos "UP"; } forEach units _grp;
						};
					} else {
						["[FOD_ZA_ModuleDefenseOP] WARNING: No valid spawn position found, skipping wave."] call FOD_ZA_fnc_debugMessage;
					};

					sleep _interval;
				};

				{
					[objNull, "[FOD Defense OP] Ended - enemy spawning has stopped."] remoteExec ["BIS_fnc_showCuratorFeedbackMessage", getAssignedCuratorUnit _x];
				} forEach allCurators;
			};
		};
	};
	case "attributesChanged3DEN": {};
	case "registeredToWorld3DEN": {};
	case "unregisteredFromWorld3DEN": {};
	case "connectionChanged3DEN": {};
	case "dragged3DEN": {};
};
