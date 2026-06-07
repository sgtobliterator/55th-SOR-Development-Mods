//For Garage Spawner
// #include "\FOD_ZA\functions\Vehicle_Garage\kbf\GarageParameters.sqf"; //made into CBA3 settings
#include "\FOD_ZA\functions\Vehicle_Garage\kbf\fn_uavDisconnect.sqf";

private _hasZen = isClass (configFile >> "CfgPatches" >> "zen_custom_modules");
if !(_hasZen) exitWith
{
	diag_log "******CBA and/or ZEN not detected. They could be required for this mod's ZEUS modules.";
};

    ["[FOD] Zeus Additions", "Vehicle Garage", 
    {
        params ["_modulePosASL", "_attachedobject"];

        deletevehicle _logic;

        [_modulePosASL, _attachedobject] spawn {
            params ["_modulePosASL", "_attachedobject"];

            _obj = _attachedobject;
            if (
                !(_obj isKindOf "AllVehicles") &&
                !(_obj isKindOf "Static")
            ) exitWith { [objNull, "Selected object is not supported for Garage Actions!"] call BIS_fnc_showCuratorFeedbackMessage; };

            [_obj, {
            params ["_successful", "_obj", "_position"];

            _TypesArray = ["Auto (by surface)", "All Types", "Ground", "Car", "Tank", "Helicopter", "Plane", "Ship", "Static Weapon"];
            _SidesArray = ["All Sides", "BlUFOR", "OPFOR", "INDEP", "CIV"];

                if (_successful) then {
                    _mouseover = curatorMouseOver params ["_type", "_entity"];
                    ["Spawn Vehicle Garage",[
                            ["TOOLBOX", ["Vehicle Type", "Select which vehicle types can be spawned."], [0, 3, 3, _TypesArray, nil]],
                            ["TOOLBOX", ["Allowed Sides", "Select which side can use this spawner."], [0, 2, 3, _SidesArray, nil]],
                            ["SLIDER:RADIUS",["Display Distance (m)", "Distance at which the action becomes available."],[0,50,10,0,(ASLToATL _pos),[255,255,255,255]]],
                            ["CHECKBOX",["Show Map Marker","If enabled, a fitting map marker will be created for this garage spawn point (based on Garage type)."],[false]]
                        ], {
                        params["_values", "_arguments"];

                        _types = _values select 0;
                        _typesStr = ["['Auto']","['All']","['Ground']","['Car']","['Tank']","['Helicopter']","['Plane']","['Ship']","['StaticWeapon']"] select _types;

                        _sides = _values select 1;
                        _sidesStr = ["['ALL']","['BLUFOR']","['OPFOR']","['INDEP']","['CIV']"] select _sides;

                        _range = _values select 2;
                        _marker = _values select 3;

                        _script = _logic getVariable ["PHEN_ModuleGarageInit_ExtraScript", ""]; //not needed for ZEN usage

                        _obj = _arguments select 0;
                        _position = _arguments select 1;

                        _pointObj = "Land_HelipadEmpty_F" createvehicle (ASLToATL _position);
                        [_pointObj, 1] remoteExec ["ZeusEditableObject", 2];
                        _pointObj hideObjectGlobal true;

                        // Compile dropdown string values > arrays
                        private _types = call compile _typesStr;
                        private _sides = call compile _sidesStr;

                        // Validate
                        if (isNull _pointObj) exitWith {
                            diag_log format ["[Garage Init] ERROR: Spawn point object '%1' not found", _pointVarName];
                        };

                        // Call function
                        [_obj, _pointObj, _types, _sides, _range, _marker, _script] call kbf_fnc_garageInit;

                    }, {}, [_obj, _position]] call zen_dialog_fnc_create;
                };
            }, [], "Vehicle Spawn Location (Object Creation)"] call zen_common_fnc_selectposition;

        };

    }, 'a3\ui_f\data\gui\rsc\rscdisplayarsenal\spacegarage_ca.paa'] call zen_custom_modules_fnc_register;

private _hasLambs = isClass (configFile >> "CfgPatches" >> "lambs_wp");
if (_hasLambs) then
{
	//GARRISON
	["[FOD] Zeus Additions", "Garrison Area", 
	{
		params [["_modulePosASL", [0,0,0]],["_attachedObject", objnull]];
		
		["Garrison In Area", [
			["sideS", ["Garrison Side (ONLY ONE!)", ""], [east]]
			], {
				params ["_values", "_arguments"];
				_arguments params ["_modulePosASL","_attachedObject"];
				_dropside = str (_values select 0);

				private _sideNumber = switch (_dropSide) do {
					case '[EAST]':           	{ 0 };
					case '[WEST]':           	{ 1 };
					case '[GUER]':     			{ 2 };
					case '[CIV]':        		{ 3 };
					default { -1 }; // fallback for unknown sides
				};
				if (_sideNumber isEqualTo -1) exitWith { [objNull, "No Proper Side was selected for the 'Garrison Area' module"] call BIS_fnc_showCuratorFeedbackMessage; };
				if (_sideNumber isEqualTo 3) exitWith { [objNull, "Civilian side is not supported for the 'Garrison Area' module"] call BIS_fnc_showCuratorFeedbackMessage; };

				_factionsFound = [];

				{
					// Get all factions but ignore story and virtual groups.
					if ((getNumber (_x >> 'side') == _sideNumber) and !(getText (configFile >> "CfgEditorSubcategories" >> (getText (_x >> "editorSubcategory")) >> "displayName") in ["Men (Story)","Men (Virtual Reality)"])) then {
						_factionsFound pushBackUnique [
							getNumber (_x >> "side"),
							getText (configFile >> "CfgFactionClasses" >> (getText (_x >> "faction")) >> "displayName"),
							getText (configFile >> "CfgEditorSubcategories" >> (getText (_x >> "editorSubcategory")) >> "displayName"),
							getText (_x >> "faction"),
							getText (_x >> "editorSubcategory"),
							getText (configFile >> "CfgFactionClasses" >> (getText (_x >> "faction")) >> "icon")
						];
					};
				} forEach ("(configName _x iskindOf 'CAManBase') && (getNumber (_x >> 'side') in [0, 1, 2]) && getNumber(_x >> 'scope') == 2" configClasses (configFile >> "CfgVehicles"));

				_factionsFound sort TRUE;
				_factionIndex = 0;
				_factions = _factionsFound;
				_factionspretty=[];
				{
					_x params ["_side", "_factName", "_catName", "_factClass", "_catClass","_picture"];
					_factionspretty pushBack [(format ["%1 - %2", _factName, _catName]),_factName,_picture,switch (_side) do {case 0: {[255,0,0,255]}; case 1: {[0,0,255,255]}; case 2: {[0,255,0,255]}; case 3: {[255,0,255,255]}; default {[255,255,255,255]};}];
				} forEach _factionsFound;

				BBUS_Garrison_factions = [_factions,_factionspretty];
			

				_options = ["Random","All","None", "Hit","Fired","Fired Near", "-","Suppressed",""];
				
				[
					"Garrison In Area", 
					[
						["COMBO",["Faction", ""],[_factions,_factionspretty, 0]],
						["SLIDER:RADIUS",["Radius", ""],[10,1000,100,0, ASLToAGL _modulePosASL, [255,255,0,255]]],
						["CHECKBOX",["Dynamic Simulation", "Dynamically simulate the spawned AI?"],[false]],
						["SLIDER",["Max Units", "Will stop filling buildings when past this by at least one."],[4,500,60,0]],
						["CHECKBOX",["Sort By Height", "Sort garrison placement by height?"],[false]],
						["TOOLBOX",["Exit Condition", ""], [0, 3, 3, _options, nil]], 
						["CHECKBOX",["Patrol", "Should garrison units patrol the area?"],[false]]
					],
					{	
						params ["_values", "_arguments"];

						[_values, _arguments] spawn {
							params ["_values", "_arguments"];
							_values params ["_faction","_radius","_dynamicsim","_amount","_SortByHeight","_exitCondition","_patrol"];
							_arguments params ["_modulePosASL", "_attachedObject","_sideNumber","_factions","_factionspretty"];

							ZEI_UiLastBuilding = objNull;

							_exitCondition = (_exitCondition - 2);

							private _nearArr = ((screenToWorld getMousePosition) nearObjects _radius) select { count (_x buildingPos -1) > 0 };
							if (count _nearArr <= 0) exitWith { ["No valid buildings within radius", "ERROR"] call ZEI_fnc_misc_logMsg };
							_nearArr = _nearArr call BIS_fnc_arrayShuffle;
							_total=0;

							_factClass = _faction#3;
							_catClass = _faction#4;

							private _tempList = "getText (_x >> 'faction') == _factClass && getText (_x >> 'editorSubcategory') == _catClass && (configName _x) isKindoF 'CAManBase' && getNumber(_x >> 'scope') == 2" configClasses (configFile >> "CfgVehicles");
							_fnc_notInString = {
								params ["_type"];
								
								private _notInString = true;
								{
									if (toLower _type find _x >= 0) exitWith { _notInString = FALSE };
								} forEach [ "_story", "_vr", "competitor", "ghillie", "miller", "survivor", "crew", "diver", "pilot", "rangemaster", "uav", "unarmed", "officer" ];
								
								_notInString
							};

							private _menList = _tempList select { ((configName _x) call _fnc_notInString) && (count getArray(_x >> "weapons") > 2) && (toLower getText (_x >> "backpack") find "para" < 0) };
							if (count _menList == 0) then { _menList = _tempList };
							if (count _menList == 0) exitWith {
								[format["No units found for faction: %1", _factClass], "ERROR"] call ZEI_fnc_misc_logMsg;
							};

							{
								if (_total > _amount) exitWith {};
								_poss = [_x] call BIS_fnc_buildingPositions;
								_spawningamount = random [1 min (count _poss), (_amount/(count _nearArr)) min (count _poss), (count _poss)];

								_spawnPos = position _x;
								private _side = switch (_sideNumber) do {
									case 0: { east };
									case 1: { west };
									case 2: { resistance };
									default { civilian };
								};
								_group = createGroup [_side, true];

								for "_i" from 1 to _spawningamount do {
									_unit = _group createUnit [configName (selectRandom _menList), _spawnPos, [], 0, "NONE"];
									if (_dynamicsim) then { _unit enableDynamicSimulation true; };
									[_unit, 1] remoteExec ["ZeusEditableObject", 2];
								};

								[_group, _x, _radius, [], true, _SortByHeight, _exitCondition, _patrol] call lambs_wp_fnc_taskGarrison;

								_total = _total + _spawningamount;
							} forEach _nearArr;
						};
					},
					{},
					[_modulePosASL, _attachedObject,_sideNumber,_factions,_factionspretty]
				] call zen_dialog_fnc_create;

		}, {}, [_modulePosASL, _attachedObject]] call zen_dialog_fnc_create;

	},"\FOD_ZA\pictures\Garrison.paa"] call zen_custom_modules_fnc_register;

	/*
		Defense Op Generator
	*/
	["[FOD] Zeus Additions", "Defense Op Generator", 
		{
			params [["_modulePosASL", [0,0,0]],["_attachedObject", objnull]];
			
			BBUS_Garrison_factions params ["_factions","_factionspretty"];

			["[STEP 1]: Pick the Enemy Side", [ 
				["sideS", ["Attacker Side (ONLY ONE!)", ""], [east]]
			], {
				params ["_values", "_arguments"];
				_arguments params ["_modulePosASL","_attachedObject"];
				_dropside = str (_values select 0);

				private _sideNumber = switch (_dropSide) do {
					case '[EAST]':           	{ 0 };
					case '[WEST]':           	{ 1 };
					case '[GUER]':     			{ 2 };
					case '[CIV]':        		{ 3 };
					default { -1 }; // fallback for unknown sides
				};
				if (_sideNumber isEqualTo -1) exitWith { [objNull, "No Proper Side was selected for the 'Defense Op Generator' module"] call BIS_fnc_showCuratorFeedbackMessage; };
				if (_sideNumber isEqualTo 3) exitWith { [objNull, "Civilian side is not supported for the 'Defense Op Generator' module"] call BIS_fnc_showCuratorFeedbackMessage; };

				_factionsFound = [];

				{
					private _cfg = _x;
					private _cfgSide = getNumber (_cfg >> "side");
					if (_cfgSide == _sideNumber) then {
						private _factionClass = getText (_cfg >> "faction");
						private _factionCfg = configFile >> "CfgFactionClasses" >> _factionClass;

						if (isClass _factionCfg) then {
							private _factionDisplay = getText (_factionCfg >> "displayName");
							private _icon = getText (_factionCfg >> "icon");

							// Only add unique faction entries
							private _entry = [_cfgSide, _factionDisplay, _factionClass, _icon];
							if !(_entry in _factionsFound) then {
								_factionsFound pushBack _entry;
							};
						};
					};
				} forEach ("(configName _x isKindOf 'AllVehicles')  && getNumber(_x >> 'scope') == 2" configClasses (configFile >> "CfgVehicles"));

				_factionsFound sort TRUE;
				_factionIndex = 0;
				_factions = _factionsFound;
				_factionspretty = [];

				{
					_x params ["_side", "_factName", "_factClass", "_picture"];
					_factionspretty pushBack [
						_factName,
						_factClass,
						_picture,
						switch (_side) do {
							case 0: {[255,0,0,255]};
							case 1: {[0,0,255,255]};
							case 2: {[0,255,0,255]};
							case 3: {[255,0,255,255]};
							default {[255,255,255,255]};
						}
					];
				} forEach _factions;


				BBUS_Garrison_factions = [_factions,_factionspretty];

				[
				"[STEP 2]: Basic Parameters", 
				[
					["COMBO",["Faction", ""],[_factions,_factionspretty,0]],
					["SLIDER:RADIUS",["Radius", "AI will spawn somewhere outside this range."],[25,2000,100,0,ASLToAGL _modulePosASL,[1,1,1,1]]],
					["CHECKBOX",["LAMBS Rush", "Use LAMBS RUSH? Otherwise uses seek and destroy waypoints."],[true]],
					["CHECKBOX",["Line of Sight check", "Should the Module check Line of Sight between units to only spawn enemies behind cover"],[true]],
					["SLIDER",["Spawn Interval", "Will spawn one squad each this many seconds have passed."],[4,500,30,0]],
					["CHECKBOX",["Directional Attack", "Restrict spawns to a directional sector instead of all 360 degrees. NOTE: bypasses terrain safety check - units may occasionally spawn on steep slopes or in water."], [false]],
					["TOOLBOX",["Attack Direction", "Cardinal direction enemies spawn from. Only used when Directional Attack is enabled."], [0, 1, 8, ["N", "NE", "E", "SE", "S", "SW", "W", "NW"]]],
					["SLIDER",["Attack Arc (deg)", "Total angular spread around the attack direction. 90 = plus/minus 45 deg either side. Only used when Directional Attack is enabled."], [30, 180, 90, 0]]
				],
				{
					params ["_values", "_arguments"];
					private _factionIndex = _values select 0;
					private _radius       = _values select 1;
					private _rush         = _values select 2;
					private _LoSToggle    = _values select 3;
					private _interval     = _values select 4;
					private _directional  = _values select 5;
					private _attackDir    = [0, 45, 90, 135, 180, 225, 270, 315] # (_values select 6);
					private _attackArc    = _values select 7;

					_arguments params ["_modulePosASL", "_attachedObject", "_dropside", "_sideNumber", "_factions", "_factionspretty"];
					private _factClass = _factionIndex select 2; // _factions entry: [_side, _factionDisplayName, _factionClassName, _iconPath]
					// hint str _factClass;

					// Find all group configs from CfgGroups
					_side = switch (_sideNumber) do { 
						case 0:            { "East" }; 
						case 1:            { "West" }; 
						case 2:       { "Indep" };  
						default { -1 }; // fallback for unknown sides 
						};

					if (typeName _side != "STRING") exitWith { [objNull, "Side Must be West, East or Independent for the 'Defense Op Generator' module"] call BIS_fnc_showCuratorFeedbackMessage;  };

					private _raw = configFile >> "CfgGroups" >> _side >> _factClass; 
					private _options = []; 
					
					{ 
						private _category = _x; 
						{ 
							private _group = _x; 
							private _name = getText (_group >> "name"); 
							private _className = configName _group; 
							_options pushBack [_name, _className]; 
						} forEach ("true" configClasses _category); 
					} forEach ("true" configClasses _raw); 

					// Build checkbox UI definitions
					private _checkboxDefs = [];
					{
					private _label = _x select 0;
					_checkboxDefs pushBack ["CHECKBOX", [_label, ""], [false]];
					} forEach _options;

					//Step 3 Dialog: Group Selector
					[
					"[STEP 3]: Filter the Groups to Spawn",
					_checkboxDefs,
					{
						params ["_vals", "_args"];
						_args params ["_modulePosASL", "_attachedObject", "_dropside", "_sideNumber", "_radius", "_rush", "_LoSToggle", "_interval", "_options", "_factClass", "_directional", "_attackDir", "_attackArc"];

						// Figure out which boxes were checked
						private _selGroups = [];
						for "_i" from 0 to (count _options - 1) do {
						if (_vals select _i) then {
							_selGroups pushBack (_options select _i select 1);
						};
						};

						//Execution
						hintSilent format ["Spawning %1 groups:\n%2", count _selGroups, _selGroups joinString "\n"];
						
						_bld = createVehicle ["VR_3DSelector_01_default_F", ASLTOATL _modulePosASL, [], 0, "CAN_COLLIDE"];
						[_bld, true] remoteExec ['hideObjectGlobal', 0];
						[_bld, false] remoteExec ['allowDamage', 0];

						{
							[_bld, false] remoteExec ['hideObjectGlobal', 0];
							[_bld, 1] remoteExec ["ZeusEditableObject", 2];
						} forEach allCurators;
						
						hint parseText "
							Defense objective ends when the  <br/> <t color='#ffff00'>'VR Selector'</t> <br/> 

							is no longer <t color='#ff0000'>ALIVE</t> / <t color='#FFFF00BF'>DELETED</t>!
							";

						[
							_selGroups,   // array of selected group classNames
							_factClass,   // faction class
							_sideNumber,
							_radius,
							_rush,
							_LoSToggle,
							_interval,
							_bld,
							_directional,
							_attackDir,
							_attackArc
						] spawn {
							params ["_groupClassnames", "_factClass", "_sideNumber", "_radius", "_rush", "_LoSToggle", "_interval", "_bld", "_directional", "_attackDir", "_attackArc"];

							private _side = switch (_sideNumber) do {
								case 0: { east };
								case 1: { west };
								case 2: { resistance };
								default { civilian };
							};

							_sideCfg = switch (_sideNumber) do { 
							case 0:            { "East" }; 
							case 1:            { "West" }; 
							case 2:   		   { "Indep" };  
							default { -1 }; // fallback for unknown sides 
							};
							
							while {alive _bld && !isNull _bld} do {

								// Get group classname from selection
								private _grpClass = selectRandom _groupClassnames;

								// Get position
								private _spawnPos = if (_directional) then {
									private _pos = [0,0,0];
									for "_attempt" from 1 to 15 do {
										private _angle     = _attackDir - (_attackArc / 2) + random _attackArc;
										private _dist      = _radius * 0.8 + random (_radius * 0.4);
										private _candidate = (getPosATL _bld) getPos [_dist, _angle];
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
									[_bld, _radius, _side, _LoSToggle] call PHEN_fnc_findValidSpawnPos
								};

								if !(_spawnPos isEqualTo [0,0,0]) then {
									
									// Find group config path from CfgGroups
									private _groupCfgPath = configNull;
									{
										private _category = _x;
										{
											if (configName _x == _grpClass) exitWith {
												_groupCfgPath = _x;
											};
										} forEach ("true" configClasses _category);
										if (!isNull _groupCfgPath) exitWith {};
									} forEach ("true" configClasses (configFile >> "CfgGroups" >> _sideCfg >> _factClass));

									if (isNull _groupCfgPath) exitWith {
										systemChat format ["Group class %1 not found in faction %2", _grpClass, _factClass];
									};

									// Spawn group
									_grp = [_spawnPos, _side, _groupCfgPath, [], [], [], [], [-1, 1], (_bld getRelDir _spawnPos)] call BIS_fnc_spawnGroup;

									//Ensure they are shown to Zeuses
									{
										[_x, 1] remoteExec ["ZeusEditableObject", 2];
									} forEach (units (_grp));

									//check locality before applying deleteGroupWhenEmpty
									if (local _grp) then
									{
										_grp deleteGroupWhenEmpty true;
									}
									else 
									{
										[_grp, true] remoteExec ["deleteGroupWhenEmpty", groupOwner _grp];
									}; 
 
									// Apply behavior
									if (_rush) then {
										[_grp, _radius, 15, [], getPosATL _bld, true] spawn lambs_wp_fnc_taskRush;
									} else {
										private _wp = _grp addWaypoint [getPosATL _bld, -1];
										_wp setWaypointType "SAD";
										_grp setSpeedMode "FULL";
										_grp setCombatBehaviour "AWARE";
										{ _x setUnitPos "UP"; } forEach units _grp;
									};
								} else {
									systemChat "No valid spawn position found!";
								};

								sleep _interval;
							};

							// Notify all Zeus players that the objective has ended
							{
								[objNull, "[FOD Defense OP] VR Selector deleted - enemy spawning has stopped."] remoteExec ["BIS_fnc_showCuratorFeedbackMessage", getAssignedCuratorUnit _x];
							} forEach allCurators;
						};

					},
					{}, // on cancel
					[_modulePosASL, _attachedObject, _dropside, _sideNumber, _radius, _rush, _LoSToggle, _interval, _options, _factClass, _directional, _attackDir, _attackArc]
					] call zen_dialog_fnc_create;

				},
				{},
				[_modulePosASL, _attachedObject, _dropside, _sideNumber, _factions, _factionspretty]
				] call zen_dialog_fnc_create;
		

		}, {}, [_modulePosASL, _attachedObject]] call zen_dialog_fnc_create;

	},"a3\modules_f_curator\data\portraitobjectiveattackdefend_ca.paa"] call zen_custom_modules_fnc_register;

	/*
		Spawn AI Group
	*/
	["[FOD] Zeus Additions", "Spawn AI Group",
	{
		params ["_modulePosASL", "_attachedObject"];

		private _tasksArr  = ["patrol", "garrison", "camp", "defend", "ambush", "cqb", "rush", "hunt", "creep", "assault", "reserve", "hitandrun", "cbaattack", "cbadefend", "cbapatrol", "cbasearch", "sentry", "guard", "seekanddestroy", "vanillagarrison", "random", " - ", "notask", " - "];
		private _tasksDisp = ["[LAMBS] Patrol", "[LAMBS] Garrison", "[LAMBS] Camp", "[LAMBS] Defend", "[LAMBS] Ambush", "[LAMBS] CQB", "[LAMBS] Rush", "[LAMBS] Hunt", "[LAMBS] Creep", "[LAMBS] Assault", "[LAMBS] Reserve/QRF", "[LAMBS] Hit & Run", "[CBA] Attack", "[CBA] Defend", "[CBA] Patrol", "[CBA] Search Area", "[VANILLA] Sentry", "[VANILLA] Guard", "[VANILLA] Seek & Destroy", "[VANILLA] Garrison", "Random", "", "No Task", ""];

		//STEP 1: Side 
		[
			"[STEP 1]: Spawn AI Group: Side",
			[
				["sideS", ["Side", "Side the spawned group will belong to."], [east]]
			],
			{
				params ["_values", "_arguments"];
				_arguments params ["_modulePosASL", "_tasksArr", "_tasksDisp"];

				private _side    = (_values select 0) select 0;                         // sideS returns [east], extract the SIDE type
				private _sideNum = [east, west, independent, civilian] find _side;  // 0=EAST 1=WEST 2=INDEP 3=CIV

				// Build faction list for this side from CfgVehicles
				private _factionsFound = [];
				{
					if (getNumber (_x >> "side") == _sideNum) then {
						private _factionClass = getText (_x >> "faction");
						private _factionCfg   = configFile >> "CfgFactionClasses" >> _factionClass;
						if (isClass _factionCfg) then {
							private _entry = [_sideNum, getText (_factionCfg >> "displayName"), _factionClass, getText (_factionCfg >> "icon")];
							if !(_entry in _factionsFound) then { _factionsFound pushBack _entry; };
						};
					};
				} forEach ("(configName _x isKindOf 'CAManBase') && getNumber(_x >> 'scope') == 2" configClasses (configFile >> "CfgVehicles"));

				_factionsFound sort true;

				private _factionsPretty = [];
				{
					_x params ["_s", "_factName", "_factClass", "_picture"];
					_factionsPretty pushBack [
						_factName, _factClass, _picture,
						switch (_s) do {
							case 0: {[255,0,0,255]}; case 1: {[0,0,255,255]};
							case 2: {[0,255,0,255]}; default {[255,255,255,255]};
						}
					];
				} forEach _factionsFound;

				["[FOD_ZA_SpawnAIGroup] Step 1: side=%1 sideNum=%2, factions found: %3", str _side, _sideNum, count _factionsFound] call FOD_ZA_fnc_debugMessage;

				//STEP 2: Faction & options 
				[
					"[STEP 2]: Spawn AI Group: Faction & Options",
					[
						["COMBO",         ["Faction",            "Faction to spawn."],                                             [_factionsFound, _factionsPretty, 0]],
						["TOOLBOX",       ["Task",                "AI behaviour task assigned after spawning."],                   [0, 8, 3, _tasksDisp, nil]],
						["SLIDER",        ["Skill",               "Unit skill level (0.0 = low, 1.0 = high)."],                   [0, 1, 0.85, 2]],
						["SLIDER:RADIUS", ["Radius (m)",          "Task radius in meters."],                                      [10, 1000, 200, 0, ASLToAGL _modulePosASL, [255, 255, 0, 255]]],
						["CHECKBOX",      ["Use Custom Classnames","Ignore faction - enter a classname pool instead."],            [false]],
						["CHECKBOX",      ["Players Only",         "Note: Task Rush, Hunt, Creep, Reserve/QRF and Hit & Run ONLY react to player enemies, not AI when this is enabled."], [false]]
					],
					{
						params ["_values", "_arguments"];
						_arguments params ["_modulePosASL", "_side", "_sideNum", "_tasksArr"];
						_values params ["_faction", "_taskIdx", "_skill", "_radius", "_useCustom", "_playersOnly"];

						private _taskKey   = _tasksArr select _taskIdx;
						private _factClass = _faction select 2;
						private _spawnPos  = ASLToAGL _modulePosASL;

						["[FOD_ZA_SpawnAIGroup] Step 2: faction=%1, task=%2, skill=%3, radius=%4m, useCustom=%5, playersOnly=%6", _factClass, _taskKey, _skill, _radius, _useCustom, _playersOnly] call FOD_ZA_fnc_debugMessage;

						if (_useCustom) then {

							//STEP 3A: Custom classname pool 
							[
								"[STEP 3A]: Spawn AI Group: Custom Classnames",
								[
									["EDIT",   ["Unit Classnames", "Classnames (, separated). One is picked at random per unit."], ["O_Soldier_F,O_Soldier_GL_F,O_Soldier_LAT_F,O_Soldier_AR_F"]],
									["SLIDER", ["Group Size",      "Number of units to spawn."],                                    [1, 20, 4, 0]]
								],
								{
									params ["_values", "_arguments"];
									_arguments params ["_spawnPos", "_side", "_taskKey", "_skill", "_radius"];
									_values params ["_classStr", "_groupSize"];

									// strip optional surrounding quotes from each classname, then filter blanks
									private _classes = (_classStr splitString ",") apply {
										private _c = trim _x;
										if (count _c >= 2 && { (_c select [0,1]) == """" } && { (_c select [count _c - 1, 1]) == """" }) then {
											_c select [1, count _c - 2]
										} else {
											_c
										}
									};
									_classes = _classes select { _x != "" };

									if (_classes isEqualTo []) exitWith {
										[objNull, "No valid classnames provided!"] call BIS_fnc_showCuratorFeedbackMessage;
									};

									[_spawnPos, _side, _classes, round _groupSize, _taskKey, _skill, _radius, _playersOnly] spawn {
										params ["_spawnPos", "_side", "_classes", "_groupSize", "_taskKey", "_skill", "_radius", ["_playersOnly", false]];

										private _grp = createGroup [_side, true];

										for "_i" from 1 to _groupSize do {
											private _unit = _grp createUnit [selectRandom _classes, _spawnPos, [], 5, "NONE"];
											_unit setSkill _skill;
											_unit setDir (random 360);
										};

										{ [_x, 1] remoteExec ["ZeusEditableObject", 2] } forEach units _grp;

										["[FOD_ZA_SpawnAIGroup] Step 3A: spawned %1 custom units, side=%2, task=%3, radius=%4m", count units _grp, str _side, _taskKey, _radius] call FOD_ZA_fnc_debugMessage;

										private _lambsMap = createHashMapFromArray [
											// vanilla tasks
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
											["cbapatrol",      { [_grp, _spawnPos, _radius] call CBA_fnc_taskPatrol }],
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
										private _lambsKeys = keys _lambsMap - ["notask"];
										private _resolvedKey = if (_taskKey == "random") then { selectRandom _lambsKeys } else { _taskKey };
										[] call (_lambsMap getOrDefault [_resolvedKey, { [_grp, _spawnPos, _radius] call lambs_wp_fnc_taskPatrol }]);
									};
								},
								{},
								[_spawnPos, _side, _taskKey, _skill, _radius, _playersOnly]
							] call zen_dialog_fnc_create;

						} else {

							//STEP 3B: CfgGroups picker 
							private _sideCfg = switch (_sideNum) do {
								case 0: { "East" }; case 1: { "West" }; case 2: { "Indep" }; default { "" };
							};

							private _options = [];
							{
								{ _options pushBack [getText (_x >> "name"), configName _x]; } forEach ("true" configClasses _x);
							} forEach ("true" configClasses (configFile >> "CfgGroups" >> _sideCfg >> _factClass));

							if (_options isEqualTo []) exitWith {
								[objNull, format ["No CfgGroups found for '%1'. Try 'Use Custom Classnames'.", _factClass]] call BIS_fnc_showCuratorFeedbackMessage;
							};

							[
								"[STEP 3B] Spawn AI Group: Select Groups",
								(_options apply { ["CHECKBOX", [_x select 0, ""], [false]] }),
								{
									params ["_vals", "_args"];
									_args params ["_spawnPos", "_side", "_sideNum", "_sideCfg", "_factClass", "_taskKey", "_skill", "_radius", "_options", "_playersOnly"];

									private _selGroups = [];
									for "_i" from 0 to (count _options - 1) do {
										if (_vals select _i) then { _selGroups pushBack (_options select _i select 1); };
									};

									if (_selGroups isEqualTo []) exitWith {
										[objNull, "No groups selected!"] call BIS_fnc_showCuratorFeedbackMessage;
									};

									[_spawnPos, _side, _sideCfg, _factClass, _selGroups, _taskKey, _skill, _radius, _playersOnly] spawn {
										params ["_spawnPos", "_side", "_sideCfg", "_factClass", "_selGroups", "_taskKey", "_skill", "_radius", "_playersOnly"];

										{
											private _grpClass = _x;

											// Find group config path in CfgGroups
											private _groupCfgPath = configNull;
											{
												{ if (configName _x == _grpClass) exitWith { _groupCfgPath = _x; }; } forEach ("true" configClasses _x);
												if (!isNull _groupCfgPath) exitWith {};
											} forEach ("true" configClasses (configFile >> "CfgGroups" >> _sideCfg >> _factClass));

											if (isNull _groupCfgPath) exitWith {
												systemChat format ["[FOD_ZA Spawn AI Group] Group '%1' not found in CfgGroups.", _grpClass];
											};

											private _grp = [_spawnPos, _side, _groupCfgPath] call BIS_fnc_spawnGroup;
											{ _x setSkill _skill } forEach units _grp;
											{ [_x, 1] remoteExec ["ZeusEditableObject", 2] } forEach units _grp;

											if (local _grp) then {
												_grp deleteGroupWhenEmpty true;
											} else {
												[_grp, true] remoteExec ["deleteGroupWhenEmpty", groupOwner _grp];
											};

											private _lambsMap = createHashMapFromArray [
												// vanilla tasks
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
												["cbapatrol",      { [_grp, _spawnPos, _radius] call CBA_fnc_taskPatrol }],
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
											private _lambsKeys = keys _lambsMap - ["notask"];
											private _resolvedKey = if (_taskKey == "random") then { selectRandom _lambsKeys } else { _taskKey };
											["[FOD_ZA_SpawnAIGroup] Step 3B: spawned group '%1' (%2 units), side=%3, task=%4, radius=%5m", _grpClass, count units _grp, str _side, _resolvedKey, _radius] call FOD_ZA_fnc_debugMessage;
											[] call (_lambsMap getOrDefault [_resolvedKey, { [_grp, _spawnPos, _radius] call lambs_wp_fnc_taskPatrol }]);

										} forEach _selGroups;
									};
								},
								{},
								[_spawnPos, _side, _sideNum, _sideCfg, _factClass, _taskKey, _skill, _radius, _options, _playersOnly]
							] call zen_dialog_fnc_create;
						};
					},
					{},
					[_modulePosASL, _side, _sideNum, _tasksArr]
				] call zen_dialog_fnc_create;
			},
			{},
			[_modulePosASL, _tasksArr, _tasksDisp]
		] call zen_dialog_fnc_create;

	}, "a3\ui_f_curator\data\displays\rscdisplaycurator\modegroups_ca.paa"] call zen_custom_modules_fnc_register;

} else {
	diag_log "******LAMBS not detected. Garrison Area will run in vanilla mode. Defense OP Generator and Spawn AI Group require LAMBS.";

	// vanilla garrison, no LAMBS required, registered only when LAMBS is absent
	["[FOD] Zeus Additions", "Garrison Area",
	{
		params [["_modulePosASL", [0,0,0]], ["_attachedObject", objNull]];

		["Garrison In Area",
		[
			["sideS", ["Garrison Side (ONLY ONE!)", ""], [east]]
		],
		{
			params ["_values", "_arguments"];
			_arguments params ["_modulePosASL", "_attachedObject"];
			private _dropSide = str (_values select 0);

			private _sideNumber = switch (_dropSide) do {
				case "[EAST]": { 0 };
				case "[WEST]": { 1 };
				case "[GUER]": { 2 };
				default { -1 };
			};
			if (_sideNumber isEqualTo -1) exitWith { [objNull, "No Proper Side was selected"] call BIS_fnc_showCuratorFeedbackMessage; };
			if (_sideNumber isEqualTo 3) exitWith { [objNull, "Civilian side is not supported"] call BIS_fnc_showCuratorFeedbackMessage; };

			private _factionsFound = [];
			{
				if ((getNumber (_x >> "side") == _sideNumber) && !(getText (configFile >> "CfgEditorSubcategories" >> (getText (_x >> "editorSubcategory")) >> "displayName") in ["Men (Story)", "Men (Virtual Reality)"])) then {
					_factionsFound pushBackUnique [
						getNumber (_x >> "side"),
						getText (configFile >> "CfgFactionClasses" >> (getText (_x >> "faction")) >> "displayName"),
						getText (configFile >> "CfgEditorSubcategories" >> (getText (_x >> "editorSubcategory")) >> "displayName"),
						getText (_x >> "faction"),
						getText (_x >> "editorSubcategory"),
						getText (configFile >> "CfgFactionClasses" >> (getText (_x >> "faction")) >> "icon")
					];
				};
			} forEach ("(configName _x isKindOf 'CAManBase') && (getNumber (_x >> 'side') in [0, 1, 2]) && getNumber(_x >> 'scope') == 2" configClasses (configFile >> "CfgVehicles"));

			_factionsFound sort true;
			private _factionsPretty = [];
			{
				_x params ["_side", "_factName", "_catName", "_factClass", "_catClass", "_picture"];
				_factionsPretty pushBack [
					format ["%1 - %2", _factName, _catName], _factName, _picture,
					switch (_side) do { case 0: {[255,0,0,255]}; case 1: {[0,0,255,255]}; case 2: {[0,255,0,255]}; default {[255,255,255,255]}; }
				];
			} forEach _factionsFound;

			[
				"Garrison In Area",
				[
					["COMBO",         ["Faction",            ""],                                                            [_factionsFound, _factionsPretty, 0]],
					["SLIDER:RADIUS", ["Radius",             ""],                                                            [10, 1000, 100, 0, ASLToAGL _modulePosASL, [255,255,0,255]]],
					["CHECKBOX",      ["Dynamic Simulation", "Dynamically simulate the spawned AI?"],                        [false]],
					["SLIDER",        ["Max Units",          "Will stop filling buildings when past this by at least one."], [4, 500, 60, 0]],
					["CHECKBOX",      ["Sort By Height",     "Sort garrison placement by height?"],                         [false]],
					["CHECKBOX",      ["Patrol",             "Should garrison units patrol the area?"],                     [false]]
				],
				{
					params ["_values", "_arguments"];
					[_values, _arguments] spawn {
						params ["_values", "_arguments"];
						_values params ["_faction", "_radius", "_dynamicSim", "_amount", "_sortByHeight", "_patrol"];
						_arguments params ["_modulePosASL", "_attachedObject", "_sideNumber", "_factionsFound", "_factionsPretty"];

						private _factClass = _faction select 3;
						private _catClass  = _faction select 4;

						private _tempList = "getText (_x >> 'faction') == _factClass && getText (_x >> 'editorSubcategory') == _catClass && (configName _x) isKindOf 'CAManBase' && getNumber(_x >> 'scope') == 2" configClasses (configFile >> "CfgVehicles");

						private _fnc_notInString = {
							params ["_type"];
							private _notInString = true;
							{ if (toLower _type find _x >= 0) exitWith { _notInString = false }; } forEach ["_story", "_vr", "competitor", "ghillie", "miller", "survivor", "crew", "diver", "pilot", "rangemaster", "uav", "unarmed", "officer"];
							_notInString
						};

						private _menList = _tempList select { ((configName _x) call _fnc_notInString) && (count getArray (_x >> "weapons") > 2) && (toLower getText (_x >> "backpack") find "para" < 0) };
						if (count _menList == 0) then { _menList = _tempList; };
						if (count _menList == 0) exitWith {
							[objNull, format ["No units found for faction: %1", _factClass]] call BIS_fnc_showCuratorFeedbackMessage;
						};

						private _side = switch (_sideNumber) do {
							case 0: { east };
							case 1: { west };
							case 2: { resistance };
							default { civilian };
						};

						private _nearArr = ((ASLToAGL _modulePosASL) nearObjects _radius) select { count (_x buildingPos -1) > 0 };
						if (count _nearArr <= 0) exitWith {
							[objNull, "No valid buildings within radius"] call BIS_fnc_showCuratorFeedbackMessage;
						};
						_nearArr = _nearArr call BIS_fnc_arrayShuffle;
						private _total = 0;
						private _allSpawnedUnits = [];

						{
							if (_total >= _amount) exitWith {};

							private _bld = _x;
							private _poss = _bld buildingPos -1;
							if (_sortByHeight) then { _poss = [_poss, [], { _x select 2 }, "DESCEND"] call BIS_fnc_sortBy; };
							if (count _poss == 0) then { continue };

							private _spawningAmount = (round (random [
								1 min (count _poss),
								(_amount / (count _nearArr)) min (count _poss),
								count _poss
							])) max 1;

							private _grp = createGroup [_side, true];

							for "_i" from 0 to (_spawningAmount - 1) do {
								private _pos = _poss select _i;
								private _unit = _grp createUnit [configName (selectRandom _menList), _pos, [], 0, "NONE"];
								_unit setPosATL _pos;
								_unit setDir (random 360);
								if (_dynamicSim) then { _unit enableDynamicSimulation true; };
								[_unit, 1] remoteExec ["ZeusEditableObject", 2];
								_allSpawnedUnits pushBack _unit;
							};

							// private _holdWp = _grp addWaypoint [position _bld, 0];
							// _holdWp setWaypointType "HOLD";
							// _holdWp setWaypointStatements ["true", ""];

							_total = _total + _spawningAmount;
						} forEach _nearArr;

						// split a single patrol element after all units are placed
						private _patrolUnits = [];
						if (_patrol && { count _allSpawnedUnits > 0 }) then {
							private _patrolSize = 1;
							if (count _allSpawnedUnits > 3)  then { _patrolSize = 2; };
							if (count _allSpawnedUnits > 7)  then { _patrolSize = 3; };
							if (count _allSpawnedUnits > 11) then { _patrolSize = 4; };

							private _workList = +_allSpawnedUnits;
							reverse _workList;
							_patrolUnits = _workList select [0, _patrolSize];

							private _patrolGrp = createGroup [_side, true];
							_patrolGrp deleteGroupWhenEmpty true;
							{ [_x] joinSilent _patrolGrp } forEach _patrolUnits;

							_patrolGrp setBehaviour "SAFE";
							_patrolGrp setCombatMode "YELLOW";
							_patrolGrp setSpeedMode "LIMITED";

							private _centerPos = ASLToAGL _modulePosASL;
							private _pRadius = _radius * 0.35;
							for "_w" from 0 to 2 do {
								private _dir = _w * 120;
								private _wpPos = [(_centerPos select 0) + (_pRadius * sin _dir), (_centerPos select 1) + (_pRadius * cos _dir), 0];
								private _wp = _patrolGrp addWaypoint [_wpPos, 15];
								_wp setWaypointType "MOVE";
								_wp setWaypointBehaviour "SAFE";
								_wp setWaypointCombatMode "YELLOW";
								_wp setWaypointSpeed "LIMITED";
							};
							private _cycleWP = _patrolGrp addWaypoint [_centerPos, 15];
							_cycleWP setWaypointType "CYCLE";
							_cycleWP setWaypointBehaviour "SAFE";
							_cycleWP setWaypointCombatMode "YELLOW";
							_cycleWP setWaypointSpeed "LIMITED";
						};

						// hold + disableAI + EH for all non-patrol units
						{
							if (_x in _patrolUnits) then { continue };
							_x disableAI "PATH";

							private _hitEH = _x addEventHandler ["Hit", {
								params ["_unit"];
								_unit enableAI "PATH";
								_unit removeEventHandler ["Hit", _thisEventHandler];
								_unit removeEventHandler ["FiredNear", _unit getVariable ["FOD_garrison_suppressEH", -1]];
							}];

							private _suppressEH = _x addEventHandler ["FiredNear", {
								params ["_unit", "_firer"];
								if (_firer isEqualTo _unit || { (side _unit getFriend side _firer) >= 0.6 }) exitWith {};
								if (random 1 < 0.4) then {
									_unit enableAI "PATH";
									_unit removeEventHandler ["FiredNear", _thisEventHandler];
									_unit removeEventHandler ["Hit", _unit getVariable ["FOD_garrison_hitEH", -1]];
								};
							}];

							_x setVariable ["FOD_garrison_hitEH", _hitEH];
							_x setVariable ["FOD_garrison_suppressEH", _suppressEH];
						} forEach _allSpawnedUnits;
					};
				},
				{},
				[_modulePosASL, _attachedObject, _sideNumber, _factionsFound, _factionsPretty]
			] call zen_dialog_fnc_create;
		},
		{},
		[_modulePosASL, _attachedObject]
		] call zen_dialog_fnc_create;

	}, "\FOD_ZA\pictures\Garrison.paa"] call zen_custom_modules_fnc_register;
};

//WEAPON ADD TURRET
// Register the module
["[FOD] Zeus Additions", "Vehicle Weapon Add", 
{
	params ["_modulePosASL","_attachedObject"];

	if (_attachedobject isKindOf "CAManBase") exitWith { [objNull, "Unit is not supported!"] call BIS_fnc_showCuratorFeedbackMessage;  };

	// First dialog - weapon category selection
	[
		"Select Weapon Category", 
		[
			["COMBO", ["Weapon Type", "Select the type of weapon to add"], BBUS_weaponCategories] // Default to Vehicle Cannons
		],
		{
			params ["_values", "_args"];
			_values params ["_categoryIndex"];
			_args params ["_modulePosASL", "_attachedObject"];
			
			private _weaponsList = _categoryIndex;
			//systemChat str _weaponsList;
			//modded people have a lot of weapons so we cache them at start

			_weaponsListDISPLAY = [];
			{
				_x params ["_Class","_Name"];
				
				// First try to get direct picture path
				private _picturePath = getText (configfile >> "CfgWeapons" >> _Class >> "picture");
				
				// If no picture defined, try to get the UI icon
				if (_picturePath == "") then {
					_picturePath = getText (configfile >> "CfgWeapons" >> _Class >> "UiPicture");
				};
				
				// If still nothing, determine default based on weapon type
				if (_picturePath == "") then {
					private _type = getNumber (configfile >> "CfgWeapons" >> _Class >> "type");
					
					_picturePath = switch (true) do {
						// Rifle
						case (_type == 1): { "\A3\ui_f\data\igui\cfg\weaponicons\pistol_ca.paa" };
						case (_type == 2): { "\A3\ui_f\data\igui\cfg\weaponicons\rifle_ca.paa" };
						case (_type == 4): { "\A3\ui_f\data\igui\cfg\weaponicons\launcher_ca.paa" };
						// Vehicle weapons
						case (_Class isKindOf "CannonCore"): { "\A3\ui_f\data\igui\cfg\weaponicons\cannon_ca.paa" };
						case (_Class isKindOf "MissileLauncher"): { "\A3\ui_f\data\igui\cfg\weaponicons\missile_ca.paa" };
						case (_Class isKindOf "RocketLauncher"): { "\A3\ui_f\data\igui\cfg\weaponicons\rocket_ca.paa" };
						// Default
						default { "\A3\ui_f\data\igui\cfg\weaponicons\mg_ca.paa" };
					};
				};
				
				// Ensure the path is lowercase (some mods use inconsistent casing)
				_picturePath = toLower _picturePath;
				
				_weaponsListDISPLAY pushBackUnique [
					_Name,
					_Class,
					_picturePath,
					[255,255,255,255]
				];
			} forEach _weaponsList;
			
			// Get available turret slots 
			private _slots = [[-1]] + (allTurrets [_attachedObject, false]); 
			private _slotsDisplay = ["Driver/Pilot"]; 
			{ 
				_slotsDisplay pushBackUnique format ["Turret %1", _forEachIndex + 1]; 
			} forEach (_slots select [1, count _slots - 1]); 

			_SlotSelectionDisplay = [_slots, _slotsDisplay, 0];

			// Second dialog - specific weapon and slot selection
			[
				"Select Weapon and Slot", 
				[
					["COMBO", ["Weapon", "Select specific weapon"], [_weaponsList, _weaponsListDISPLAY, 0]],
					["COMBO", ["Slot", "Slot to add the weapon to"], _SlotSelectionDisplay]
				],
				{
					params ["_values", "_args"];
					_values params ["_weapon", "_slotIndex"];
					_args params ["_modulePosASL", "_attachedObject", "_slots"];
					
					private _weaponClass = _weapon select 0;
					private _weaponName = _weapon select 1;

					// Debug output
					// systemChat format ["Adding weapon: %1 (%2)", _weaponName, _weaponClass];
					// systemChat format ["Slot: %1", _slotIndex];
					// systemChat format ["Target vehicle: %1 (%2)", typeOf _attachedObject, _attachedObject];
									
					// Add the weapon and a magazine
					_attachedObject addWeaponTurret [_weaponClass, _slotIndex];
					private _mags = getArray (configFile >> "CfgWeapons" >> _weaponClass >> "magazines");
					if (count _mags > 0) then {
						_attachedObject addMagazineTurret [selectRandom _mags, _slotIndex];
						[_attachedObject, 1] remoteExec ['setVehicleAmmo', 0];
					};
					
					// Create success message
					private _slotName = if (str slotIndex == '[-1]') then {
						"Driver/Pilot position"
					} else {
						format ["Turret %1", (_slotIndex#0)]
					};
					
					// Create success message 
					private _slotName = if (_slotIndex in [[-1]]) then { 
						"Driver/Pilot position" 
					} else { 
						format ["Turret %1", (_slotIndex#0)] 
					}; 
					
					private _message = format [ 
						"Added %1 to %2 (%3)",  
						_weaponName,  
						getText (configFile >> "CfgVehicles" >> typeOf _attachedObject >> "displayName"), 
						_slotName 
					];

					// Show message to curator 
					[objNull, _message] call BIS_fnc_showCuratorFeedbackMessage;
					// systemChat _message;

					// Configure vehicle loadout
					[_attachedObject] call zen_loadout_fnc_configure;
					
				},
				{},
				[_modulePosASL, _attachedObject, _slots]
			] call zen_dialog_fnc_create;
		},
		{},
		[_modulePosASL, _attachedObject]
	] call zen_dialog_fnc_create;
}, "\FOD_ZA\pictures\weaponadd.paa"] call zen_custom_modules_fnc_register;

//remove
["[FOD] Zeus Additions", "Vehicle Weapon Remove", 
{
	params ["_modulePosASL","_attachedObject"];
	
	_slots = [[-1]] + (allTurrets [_attachedObject, false]);
	_slotsdisplay = ["Driver/Pilot"];
	//choose slot first
	[
		"Remove Vehicle Weapon", 
		[
			["COMBO",["Slot", "Slot to remove a weapon from."],[_slots,_slotsdisplay,0]]
		],
		{
			_dialogReturn = _this select 0;
			_dialogReturn params ["_slot"];
			
			private _arguments = _this select 1; //passed arguments from zen_dialog_fnc_create
			_arguments params ["_modulePosASL", "_attachedObject"];
			
			private _onConfirm = {
				_this spawn {
					_dialogReturn = _this select 0;
					_dialogReturn params ["_weapon"];
					
					private _arguments = _this select 1; //passed arguments from zen_dialog_fnc_create
					_arguments params ["_modulePosASL", "_attachedObject","_slot"];
					
					_attachedObject removeWeaponTurret [_weapon,_slot];
				};
			};
			
			//get all weapons from slot and use their display names
			_weapons = _attachedObject weaponsTurret _slot;
			_weaponsdisplay = [];
			{
				_weaponsdisplay pushBackUnique [_x,(getText (configfile >> "CfgWeapons" >> _x >> "displayName"))];
			}forEach _weapons;
			
			//remove weapon from the slot now
			[
				"Remove Vehicle Weapon", 
				[
					["COMBO",["Weapon", "Weapon to remove."],[_weapons,_weaponsdisplay,0]]
				],
				_onConfirm,
				{},
				[_modulePosASL, _attachedObject,_slot]
			] call zen_dialog_fnc_create;
		},
		{},
		[_modulePosASL, _attachedObject]
	] call zen_dialog_fnc_create;

},"\FOD_ZA\pictures\weaponremove.paa"] call zen_custom_modules_fnc_register;
