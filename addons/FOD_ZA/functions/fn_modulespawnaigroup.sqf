params [
	["_mode", "", [""]],
	["_input", [], [[]]]
];

_input params [
	["_module", objNull, [objNull]],
	["_isActivated", false, [true]],
	["_isCuratorPlaced", false, [true]]
];

private _classPool     = _module getVariable ["FOD_ZA_SPG_ClassPool", "O_Soldier_F"];
private _factionClass  = _module getVariable ["FOD_ZA_SPG_FactionClass", ""];
private _cfgGroupClass = _module getVariable ["FOD_ZA_SPG_CfgGroup", ""];
private _groupSize     = _module getVariable ["FOD_ZA_SPG_GroupSize", 4];
private _sideStr       = _module getVariable ["FOD_ZA_SPG_Side", "EAST"];
private _taskKey       = _module getVariable ["FOD_ZA_SPG_LambsTask", "patrol"];
private _skill         = _module getVariable ["FOD_ZA_SPG_Skill", 0.85];
private _playersOnly   = _module getVariable ["FOD_ZA_SPG_PlayersOnly", false];

private _area = _module getVariable ["ObjectArea", [200, 200, 0, false, -1]];
if (is3DEN) then {
	private _size = (_module get3DENAttribute "Size3") select 0;
	_size params [["_a", 200, [0]], ["_b", 200, [0]]];
	_area = [_a, _b, 0, false, -1];
};
private _radius = round ((_area#0 + _area#1) / 2);

switch (_mode) do {
	case "init": {
		if (_isActivated && isServer) then {
			private _hasLambs    = isClass (configFile >> "CfgPatches" >> "lambs_wp");
			private _vanillaTasks = ["notask", "sentry", "guard", "seekanddestroy", "vanillagarrison"];
			private _cbaTasks     = ["cbaattack", "cbadefend", "cbapatrol", "cbasearch"];
			private _noLambsRequired = _vanillaTasks + _cbaTasks;
			private _taskKeyLower = toLower _taskKey;
			if (!_hasLambs && !(_taskKeyLower in _noLambsRequired) && { _taskKeyLower != "random" }) exitWith {
				["[FOD_ZA_ModuleSpawnAIGroup] ERROR: LAMBS Waypoints required but not detected. Use a vanilla task, CBA task, or No Task."] call FOD_ZA_fnc_debugMessage;
			};

			[_module, _classPool, _factionClass, _cfgGroupClass, _groupSize, _sideStr, _taskKey, _skill, _radius, _playersOnly, _hasLambs, _vanillaTasks, _cbaTasks] spawn {
				params ["_module", "_classPool", "_factionClass", "_cfgGroupClass", "_groupSize", "_sideStr", "_taskKey", "_skill", "_radius", "_playersOnly", "_hasLambs", "_vanillaTasks", "_cbaTasks"];

				private _spawnPos = getPosATL _module;

				private _side = switch (toUpper _sideStr) do {
					case "EAST":        { east };
					case "WEST":        { west };
					case "INDEPENDENT": { independent };
					case "CIVILIAN":    { civilian };
					default             { east };
				};

				private _sideKey = switch (toUpper _sideStr) do {
					case "EAST":        { "East" };
					case "WEST":        { "West" };
					case "INDEPENDENT": { "Indep" };
					default             { "East" };
				};

				private _grp = grpNull;

				// Priority 1, faction classname: build unit list from CfgVehicles infantry of that faction
				if (_factionClass != "") then {
					private _factPool = [];
					{
						if (getText (_x >> "faction") == _factionClass && { getNumber (_x >> "scope") == 2 }) then {
							_factPool pushBack (configName _x);
						};
					} forEach ("(configName _x isKindOf 'CAManBase')" configClasses (configFile >> "CfgVehicles"));

					if (count _factPool > 0) then {
						private _unitList = [];
						for "_i" from 1 to _groupSize do { _unitList pushBack (selectRandom _factPool); };
						_grp = [_spawnPos, _side, _unitList] call BIS_fnc_spawnGroup;
					} else {
						["[FOD_ZA_ModuleSpawnAIGroup] WARNING: Faction '%1' yielded no infantry, falling back.", _factionClass] call FOD_ZA_fnc_debugMessage;
					};
				};

				// Priority 2, CfgGroups classname: find config entry and spawn predefined group
				if (isNull _grp && { _cfgGroupClass != "" }) then {

					private _groupCfg = configNull;

					private _isPath = [_cfgGroupClass, ">>"] call BIS_fnc_inString;

					if (_isPath) then {

						private _parsedPath = call compile _cfgGroupClass;
						private _exists = isClass _parsedPath;

						if (_exists) then {
							_groupCfg = _parsedPath;
						};

					} else {

						private _sidePath = configFile >> "CfgGroups" >> _sideKey;
						private _sideValid = isClass _sidePath;

						if (_sideValid) then {
							{ 
								private _factionCfg = _x; 
								private _factionName = configName _factionCfg; 
												
								{ 
									private _categoryCfg = _x; 
									private _categoryName = configName _categoryCfg; 
											
									{ 
										private _entryCfg = _x; 
										private _entryName = configName _entryCfg; 
						
										if (_entryName == _cfgGroupClass) exitWith { 
											_groupCfg = _entryCfg; 
										}; 
						
									} forEach ("true" configClasses _categoryCfg); 
						
									if (!isNull _groupCfg) exitWith {}; 
						
								} forEach ("true" configClasses _factionCfg); 
						
								if (!isNull _groupCfg) exitWith {}; 
						
							} forEach ("true" configClasses _sidePath); 
						};

					};

					private _found = !isNull _groupCfg;

					if (_found) then {
						_grp = [_spawnPos, _side, _groupCfg] call BIS_fnc_spawnGroup;
					} else {
						["[FOD_ZA_ModuleSpawnAIGroup] WARNING: CfgGroups entry '%1' not found or invalid.", _cfgGroupClass] call FOD_ZA_fnc_debugMessage;
					};

				};

				// Priority 3, classpool fallback: parse classnames and build unit list
				if (isNull _grp) then {
					private _classes = (_classPool splitString ",") apply {
						private _cls = trim _x;
						if (count _cls >= 2 && { (_cls select [0,1]) == """" } && { (_cls select [count _cls - 1, 1]) == """" }) then {
							_cls select [1, count _cls - 2]
						} else {
							_cls
						}
					};
					_classes = _classes select { _x != "" };

					if (_classes isEqualTo []) exitWith {
						["[FOD_ZA_ModuleSpawnAIGroup] ERROR: No valid classnames configured."] call FOD_ZA_fnc_debugMessage;
					};

					private _unitList = [];
					for "_i" from 1 to _groupSize do { _unitList pushBack (selectRandom _classes); };
					_grp = [_spawnPos, _side, _unitList] call BIS_fnc_spawnGroup;
				};

				if (isNull _grp) exitWith {
					["[FOD_ZA_ModuleSpawnAIGroup] ERROR: Failed to spawn group."] call FOD_ZA_fnc_debugMessage;
				};

				_grp deleteGroupWhenEmpty true;
				{ _x setSkill _skill; _x setDir (random 360); } forEach units _grp;

				private _lambsMap = createHashMapFromArray [
					// vanilla tasks, no LAMBS or CBA required
					["notask",         {}],
					["sentry",         {
						private _sentryDir  = random 360;
						private _sentryDist = random _radius;
						private _sentryPos  = [(_spawnPos select 0) + (_sentryDist * sin _sentryDir), (_spawnPos select 1) + (_sentryDist * cos _sentryDir), 0];
						private _wp = _grp addWaypoint [_sentryPos, 0];
						_wp setWaypointType "SENTRY";
					}],
					["guard",          {
						private _wp = _grp addWaypoint [_spawnPos, 0];
						_wp setWaypointType "GUARD";
					}],
					["seekanddestroy", { [_grp, _spawnPos, _radius] call FOD_ZA_fnc_taskSeekAndDestroy }],
					["vanillagarrison",{ [_grp, _spawnPos, _radius] call FOD_ZA_fnc_taskVanillaGarrison }],
					// CBA tasks, CBA is always loaded
					["cbaattack",      { [_grp, _spawnPos, _radius] call CBA_fnc_taskAttack }],
					["cbadefend",      { [_grp, _spawnPos, _radius] call CBA_fnc_taskDefend }],
					["cbapatrol",      { [_grp, _spawnPos, _radius] call CBA_fnc_taskPatrol; _grp setBehaviour "SAFE"; _grp setCombatMode "YELLOW"; _grp setSpeedMode "LIMITED"; }],
					["cbasearch",      { [_grp, [_spawnPos, _radius, _radius, 0, false]] call CBA_fnc_taskSearchArea }],
					// LAMBS tasks
					["patrol",         { [_grp, _spawnPos, _radius, 4, [], true, true, true] call lambs_wp_fnc_taskPatrol         }],
					["garrison",       { [_grp, _spawnPos, _radius, [], true, false, -2] call lambs_wp_fnc_taskGarrison           }],
					["camp",           { [_grp, _spawnPos, _radius, [], true, true] call lambs_wp_fnc_taskCamp                   }],
					["defend",         { [_grp, _spawnPos, _radius, [], true, 5, false, true] spawn FOD_ZA_fnc_taskEntrench       }],
					["ambush",         { [_grp, _spawnPos, _radius, [], false, 0, true, false] spawn FOD_ZA_fnc_taskEntrench      }],
					["cqb",            { [_grp, _spawnPos, _radius] spawn lambs_wp_fnc_taskCQB                                   }],
					["rush",           { [_grp, _radius, 0, [], _spawnPos, _playersOnly] spawn lambs_wp_fnc_taskRush              }],
					["hunt",           { [_grp, _radius, 15, [], _spawnPos, _playersOnly, true, true] spawn lambs_wp_fnc_taskHunt }],
					["creep",          { [_grp, _radius, 15, [], _spawnPos, _playersOnly] spawn lambs_wp_fnc_taskCreep            }],
					["assault",        { [leader _grp, _spawnPos] spawn lambs_wp_fnc_taskAssault                                 }],
					["reserve",        { [_grp, _radius, _playersOnly] spawn FOD_ZA_fnc_taskReserve                              }],
					["hitandrun",      { [_grp, _spawnPos, _radius, _playersOnly] spawn FOD_ZA_fnc_taskHitAndRun                 }]
				];

				// random pool: non-lambs tasks when LAMBS absent, everything except notask when LAMBS present
				private _noLambsRequired = _vanillaTasks + _cbaTasks;
				private _lambsKeys = if (_hasLambs) then {
					keys _lambsMap - ["notask"]
				} else {
					_noLambsRequired - ["notask"]
				};

				private _taskKeyLower = toLower _taskKey;
				private _resolvedKey = if (_taskKeyLower == "random") then {
					selectRandom _lambsKeys
				} else {
					_taskKeyLower
				};

				private _taskCode = _lambsMap getOrDefault [
					_resolvedKey,
					{ [_grp, _spawnPos, _radius] call lambs_wp_fnc_taskPatrol }
				];
				[] call _taskCode;

				["[FOD_ZA_ModuleSpawnAIGroup] Spawned %1 units (%2) at module pos, task: %3 (radius: %4m)",
				count units _grp, _sideStr, _resolvedKey, _radius] call FOD_ZA_fnc_debugMessage;
			};
		};
	};
	case "attributesChanged3DEN": {};
	case "registeredToWorld3DEN": {};
	case "unregisteredFromWorld3DEN": {};
	case "connectionChanged3DEN": {};
	case "dragged3DEN": {};
};
