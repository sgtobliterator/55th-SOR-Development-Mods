
#include "\a3\ui_f\hpp\defineDIKCodes.inc"

// CBA Addon Settings for Garage Spawner with Dynamic Loadout
["GPs_bluforCrew", "EDITBOX", 
    ["BLUFOR Crew Class", "Classname of the crew spawned for BLUFOR vehicles."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    "B_crew_F", 
    1, {}, false
] call CBA_fnc_addSetting;

["GPs_opforCrew", "EDITBOX", 
    ["OPFOR Crew Class", "Classname of the crew spawned for OPFOR vehicles."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    "O_crew_F", 
    1, {}, false
] call CBA_fnc_addSetting;

["GPs_independentCrew", "EDITBOX", 
    ["Independent Crew Class", "Classname of the crew spawned for Independent vehicles."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    "I_crew_F", 
    1, {}, false
] call CBA_fnc_addSetting;

["GPs_civilianCrew", "EDITBOX", 
    ["Civilian Crew Class", "Classname of the crew spawned for Civilian vehicles."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    "C_man_w_worker_F", 
    1, {}, false
] call CBA_fnc_addSetting;

["GPs_otherCrew", "EDITBOX", 
    ["Other Crew Class", "Fallback classname for any other side."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    "C_man_polo_1_F", 
    1, {}, false
] call CBA_fnc_addSetting;


// Whitelist / Blacklist Settings
["GPs_useListType", "LIST", 
    ["Use Whitelist / Blacklist", "0: Disable List, 1: Enable Whitelist, 2: Enable Blacklist"], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    [[0,1,2], ["Disabled", "Whitelist", "Blacklist"], 1], 
    1, {}, false
] call CBA_fnc_addSetting;

["GPs_separateListBySide", "CHECKBOX", 
    ["Separate List by Side", "If true, whitelist/blacklist is separated per side and includes All list."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    false, 
    1, {}, false
] call CBA_fnc_addSetting;

["GPs_limitVehicleBySide", "CHECKBOX", 
    ["Limit Vehicle by Side", "If true, restricts spawnable vehicles to player’s side."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    false, 
    1, {}, false
] call CBA_fnc_addSetting;

["GPs_uavDisabled", "CHECKBOX", 
    ["Disable UAV Spawn", "If true, UAV spawning is disabled."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    false, 
    1, {}, false
] call CBA_fnc_addSetting;


// Vehicle Lists
// Use the typeOf classname of vehicles. Arrays are written as a string and split in code.
GPs_vehicleList_All = [];
["GPs_vehicleList_All", "EDITBOX", 
    ["All-Side Vehicle List", "Vehicle classnames (, separated) for all sides."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    "C_SUV_01_F", 
    1, { GPs_vehicleList_All = GPs_vehicleList_All splitString "," }, false
] call CBA_fnc_addSetting;

GPs_vehicleList_BLUFOR = [];
["GPs_vehicleList_BLUFOR", "EDITBOX", 
    ["BLUFOR Vehicle List", "Vehicle classnames (, separated) for BLUFOR."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    "B_MRAP_01_F,B_MRAP_01_gmg_F,B_MRAP_01_hmg_F", 
    1, { GPs_vehicleList_BLUFOR = GPs_vehicleList_BLUFOR splitString "," }, false
] call CBA_fnc_addSetting;

GPs_vehicleList_OPFOR = [];
["GPs_vehicleList_OPFOR", "EDITBOX", 
    ["OPFOR Vehicle List", "Vehicle classnames (, separated) for OPFOR."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    "O_MRAP_02_F,O_MRAP_02_gmg_F,O_MRAP_02_hmg_F", 
    1, { GPs_vehicleList_OPFOR = GPs_vehicleList_OPFOR splitString "," }, false
] call CBA_fnc_addSetting;

GPs_vehicleList_INDEP = [];
["GPs_vehicleList_INDEP", "EDITBOX", 
    ["Independent Vehicle List", "Vehicle classnames (, separated) for Independent side."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    "I_MRAP_03_F,I_MRAP_03_gmg_F,I_MRAP_03_hmg_F", 
    1, { GPs_vehicleList_INDEP = GPs_vehicleList_INDEP splitString "," }, false
] call CBA_fnc_addSetting;

GPs_vehicleList_CIV = [];
["GPs_vehicleList_CIV", "EDITBOX", 
    ["Civilian Vehicle List", "Vehicle classnames (, separated) for Civilian side."], 
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"], 
    "C_Van_01_transport_F,C_Van_01_box_F", 
    1, { GPs_vehicleList_CIV = GPs_vehicleList_CIV splitString "," }, false
] call CBA_fnc_addSetting;


// Allowed core classes 
_coreClasses = [
    "PistolCore",
    "RifleCore",
    "MGunCore",
    "LauncherCore",
    "GrenadeCore",
    "CannonCore",
    "DetectorCore"
];

_baseWeaponClasses = [
    "Pistol_Base_F",
    "Rifle_Base_F",
    "Rifle_Short_Base_F",
    "Rifle_Long_Base_F",
    "HandGunBase",
    "Launcher_Base_F",
    "DMR_01_base_F",
    "EBR_base_F",
    "GM6_base_F",
    "LRR_base_F",
    "DMR_02_base_F",
    "DMR_03_base_F",
    "DMR_04_base_F",
    "DMR_05_base_F",
    "DMR_06_base_F",
    "DMR_06_hunter_base_F",
    "DMR_07_base_F",
    "MMG_01_base_F",
    "MMG_02_base_F",
    "LMG_03_base_F",
    "arifle_Katiba_Base_F",
    "mk20_base_F",
    "arifle_MX_Base_F",
    "SDAR_base_F",
    "Tavor_base_F",
    "pdw2000_base_F",
    "SMG_01_Base",
    "SMG_02_base_F",
    "SMG_03_TR_BASE",
    "SMG_03C_BASE",
    "SMG_05_base_F",
    "arifle_AK12_base_F",
    "arifle_AK12_GL_base_F",
    "arifle_AKM_base_F",
    "arifle_AKS_base_F",
    "arifle_ARX_base_F",
    "arifle_CTAR_base_F",
    "arifle_CTAR_GL_base_F",
    "arifle_CTARS_base_F",
    "arifle_SPAR_01_base_F",
    "arifle_SPAR_01_GL_base_F",
    "arifle_SPAR_02_base_F",
    "arifle_SPAR_03_base_F",
    "arifle_MSBS65_base_F",
    "arifle_MSBS65_UBS_base_F",
    "arifle_MSBS65_GL_base_F",
    "arifle_MSBS65_Mark_base_F",
    "sgun_HunterShotgun_01_base_F",
    "sgun_HunterShotgun_01_sawedoff_base_F",
    "hgun_esd_01_base_F",
    "launch_MRAWS_base_F",
    "launch_Vorona_base_F",
    "launch_Titan_base",
    "launch_Titan_short_base",
    "launch_NLAW_F",
    "launch_RPG32_F"
];

private _allowedWeaponCores = _coreClasses + _baseWeaponClasses;

// Main infantry weapons 
BBUS_weapons_rifles = []; 
BBUS_weapons_handguns = []; 
BBUS_weapons_launchers = []; 
BBUS_weapons_other = []; 
 
// Vehicle/turret weapon categories 
BBUS_weapons_cannons = []; 
BBUS_weapons_rockets = []; 
BBUS_weapons_missiles = []; 
BBUS_weapons_bombs = []; 
 
// Iterate over all weapon configs 
{ 
	private _className = _x; 
	private _xPath = configFile >> "CfgWeapons" >> _className; 
	private _type = getNumber (_xPath >> "type"); 
	private _scope = getNumber (_xPath >> "scope"); 
	private _magazines = getArray (_xPath >> "magazines"); 

 // Check if weapon is a subclass of one of the allowed cores, Skip hidden or magless weapons 
 if ((_allowedWeaponCores findIf { _className isKindOf _x } == -1) and {(_scope != 0) and {count _magazines >= 1}}) then { 
	
	private _entry = [_className, getText (_xPath >> "displayName")]; 
	
	switch (true) do { 
	case (_type == 2): { BBUS_weapons_handguns pushBackUnique _entry }; 
	case (_type == 1): { BBUS_weapons_rifles pushBackUnique _entry }; 
	case (_type == 4): { BBUS_weapons_launchers pushBackUnique _entry }; 
	
	case (_type >= 65536): { 
	private _cursor = toLower getText (_xPath >> "cursor"); 
	private _lockSystem = getNumber (_xPath >> "weaponLockSystem"); 
	private _reloadTime = getNumber (_xPath >> "reloadTime"); 
	private _classLower = toLower _className; 
	
	switch (true) do { 
		case (_cursor find "cannon" > -1 || _classLower find "cannon" > -1): { 
		BBUS_weapons_cannons pushBackUnique _entry; 
		}; 
		case (_cursor find "rocket" > -1 || _classLower find "rocket" > -1): { 
		BBUS_weapons_rockets pushBackUnique _entry; 
		}; 
		case (_lockSystem > 0): { 
		BBUS_weapons_missiles pushBackUnique _entry; 
		}; 
		case (_cursor find "bomb" > -1 || _reloadTime > 5 || _classLower find "bomb" > -1): { 
		BBUS_weapons_bombs pushBackUnique _entry; 
		}; 
		default { 
		BBUS_weapons_cannons pushBackUnique _entry; 
		}; 
	}; 
	}; 
	
	default { 
	BBUS_weapons_other pushBackUnique _entry; 
	}; 
	};
 }; 
} forEach ((configFile >> "CfgWeapons") call BIS_fnc_getCfgSubClasses); 

// Create display versions of each category
BBUS_weaponCategories =[
    [ 
        BBUS_weapons_rifles, 
        BBUS_weapons_handguns, 
        BBUS_weapons_launchers, 
        BBUS_weapons_cannons, 
        BBUS_weapons_rockets, 
        BBUS_weapons_missiles, 
        BBUS_weapons_bombs, 
        BBUS_weapons_other 
    ], 
    [ 
        ["Infantry Rifles","","a3\ui_f\data\gui\cfg\hints\rifle_ca.paa",[255,255,255,255]], 
        ["Handguns","","a3\ui_f\data\gui\cfg\hints\gui_ca.paa",[255,255,255,255]], 
        ["Infantry Launchers","","a3\ui_f\data\gui\cfg\hints\launcher_ca.paa",[255,255,255,255]], 
        ["Vehicle Cannons","","a3\ui_f\data\gui\cfg\hints\warhead_types_ca.paa",[255,255,255,255]], 
        ["Rocket Launchers (unguided)","","a3\ui_f\data\gui\cfg\hints\missile_direct_ca.paa",[255,255,255,255]], 
        ["Missile Launchers (guided)","","a3\ui_f_jets\data\gui\cfg\hints\weaponsmissiles_ca.paa",[255,255,255,255]], 
        ["Bomb Launchers","","a3\ui_f_jets\data\gui\cfg\hints\weaponsbombs_ca.paa",[255,255,255,255]], 
        ["Other Weapons","","a3\ui_f\data\map\markers\military\unknown_ca.paa",[255,255,255,255]] 
    ],3]; 

// 3DEN context menu helper: "Log CfgGroups to Clipboard"
// Called from Cfg3DEN Log submenu. Copies the selected unit's faction class
// and all CfgGroups classnames to clipboard.
FOD_ZA_fnc_logCfgGroupsClipboard = {
    private _selected = get3DENSelected "Object";
    if (_selected isEqualTo []) exitWith {
        systemChat "FOD: No object selected. Select a unit in the editor first.";
    };

    private _unit    = _selected select 0;
    private _typeOf  = typeOf _unit;
    private _faction = getText (configFile >> "CfgVehicles" >> _typeOf >> "faction");

    if (_faction isEqualTo "") exitWith {
        systemChat format ["FOD: No faction found for class: %1", _typeOf];
    };

    private _sideNum = getNumber (configFile >> "CfgVehicles" >> _typeOf >> "side");
    private _sideCfg = ["East", "West", "Indep", "Civ"] # (_sideNum min 3);

    private _groups = [];
    {
        private _cat = _x;
        { _groups pushBack (configName _x); } forEach ("true" configClasses _cat);
    } forEach ("true" configClasses (configFile >> "CfgGroups" >> _sideCfg >> _faction));

    private _nl = toString [10];
    private _groupStr = _groups joinString _nl;

    copyToClipboard (format ["Faction: %1", _faction] + _nl + format ["Groups (%1):", count _groups] + _nl + _groupStr);
    systemChat format ["[FOD] Copied - Faction: %1, Groups (%2)", _faction, count _groups];
};

PHEN_fnc_findValidSpawnPos = {
    params ["_targetObj", "_radius", "_side", ['_LoSToggle', true]];

    private _center = getPosATL _targetObj;
    private _maxAttempts = 30;
    private _pos = [0,0,0];

    if (_LoSToggle) then {

        // Get all enemy units based on dynamic side hostility
        private _enemies = allUnits select {
            private _unitSide = side _x;
            (alive _x && ([_side, _unitSide] call BIS_fnc_sideIsEnemy))
        };

        for "_i" from 1 to _maxAttempts do {
            private _candidate = [_center, _radius, (_radius * 2), 3, 0, 0.1, 0] call BIS_fnc_findSafePos;

            if (_candidate isEqualTo [0,0,0]) then { continue }; //skip

            // Check LoS to ANY enemy unit
            private _hasLoS = false;

            if (count _candidate <= 2) then { _candidate = [_candidate#0, _candidate#1, 0]; };

            {
                private _intersect = lineIntersectsWith  [eyePos _x, AGLToASL _candidate];
                if (count _intersect == 0) exitWith { _hasLoS = true };
            } forEach _enemies;
            
            if (_hasLoS) then { continue }; //skip

            _pos = _candidate;
            break;
        };
    } else {

        for "_i" from 1 to _maxAttempts do {
            private _candidate = [_center, _radius, (_radius * 2), 3, 0, 0.1, 0] call BIS_fnc_findSafePos;

            if (_candidate isEqualTo [0,0,0]) then { continue }; //skip

            _pos = _candidate;
            break;
        };
        
    };
    
    //return value
    _pos
};

//FUNCTIONS
PHEN_rscdisplaygarage = {
    disableSerialization;

    _mode  = _this select 0;
    _params = _this select 1;

    uiNamespace setVariable ["PHEN_fnc_garage", PHEN_rscdisplaygarage];
    uiNamespace setVariable ["PHEN_rscdisplaygarage", PHEN_rscdisplaygarage];

    switch _mode do {
        case "onLoad": {
            private _display = _params select 0;
            uiNamespace setVariable ["PHEN_rscdisplaygarage_display", _display];

            // Save a safe reference to custom garage display
            uiNamespace setVariable ["PHEN_safe_arsenal_display", _display];

            if (isNil { missionNamespace getVariable "bis_fnc_arsenal_data" }) then {
                startLoadingScreen [""];
                ['Init', _params] spawn (uiNamespace getVariable "PHEN_fnc_garage");
            } else {
                ['Init', _params] call (uiNamespace getVariable "PHEN_fnc_garage");
            };
        };

        case "onUnload": {
            ['Exit', _params] call (uiNamespace getVariable "PHEN_fnc_garage");
            uiNamespace setVariable ["PHEN_rscdisplaygarage_display", displayNull];
        };
    };
};

// ZeusEditableObject function
// _object: object to add/remove
// _action: 0 = remove, 1 = add
// _persistent: true = keep synced until object is destroyed, false = run once
ZeusEditableObject = {
    params [
        ["_object", objNull, [objNull]],
        ["_action", 1, [0]],
        ["_persistent", false, [false]]
    ];

    // Validate object
    if (isNull _object) exitWith {
        diag_log "[PHEN_ZeusEditableObject] ERROR: Null object passed.";
    };

    // Validate action
    if !(_action in [0,1]) exitWith {
        diag_log format ["[PHEN_ZeusEditableObject] ERROR: Invalid action %1", _action];
    };

    // Function to add/remove
    private _apply = {
        params ["_object","_action"];
        {
            [_x, [[_object], (_action isEqualTo 1)]] remoteExec ["addCuratorEditableObjects", 0, true];
        } forEach allCurators;
    };

    // Run once immediately
    [_object, _action] call _apply;

    // If persistent, monitor object and re-apply until destroyed
    if (_persistent) then {
        [_object, _action, _apply] spawn {
            params ["_object","_action","_apply"];

            while {(!isNil "_object" && {alive _object} && {!(isNull _object)})} do {
                sleep 10;
                if (!isNil "_object" && {alive _object} && {!(isNull _object)}) then {
                    [_object, _action] call _apply;
                };
            };
        };
    };
};
publicVariable 'ZeusEditableObject';


// Spawn AI Group, Debug
["FOD_ZA_SPG_DebugMode", "CHECKBOX",
	["Spawn AI Group Debug", "Enable debug chat/log messages for the Spawn AI Group module."],
	["[Forges of Dorn] Zeus Additions", "Spawn AI Group"],
	false,
	1, {}, false
] call CBA_fnc_addSetting;

FOD_ZA_fnc_debugMessage = {
	private _msg  = _this select 0;
	private _args = _this select [1, count _this - 1];

	if !(missionNamespace getVariable ["FOD_ZA_SPG_DebugMode", false]) exitWith {};

	private _formatted = if (_args isEqualTo []) then {
		_msg
	} else {
		format ([_msg] + _args)
	};

	systemChat format ["[FOD_ZA SPG DEBUG] %1", _formatted];
	diag_log  format ["[FOD_ZA SPG DEBUG] %1", _formatted];
};


// Spawn AI Group, Custom LAMBS-compatible task functions

// Reserve / QRF: hold in place until an enemy is known, then rush to contact.
// example: [_grp, _radius] spawn FOD_ZA_fnc_taskReserve
// example (players only): [_grp, _radius, true] spawn FOD_ZA_fnc_taskReserve
FOD_ZA_fnc_taskReserve = {
	if !(canSuspend) exitWith { _this spawn FOD_ZA_fnc_taskReserve; };
	params ["_grp", "_radius", ["_playersOnly", false]];
	if (!local _grp) exitWith { false };
	["[FOD_ZA_taskReserve] Group %1 holding as reserve, radius=%2m, playersOnly=%3", groupId _grp, _radius, _playersOnly] call FOD_ZA_fnc_debugMessage;
	{
		// Current result is saved in variable _x
		_x setVariable ["lambs_danger_enableGroupReinforce", true, true];
		_x setVariable ["lambs_danger_dangerRadio", true, true];
	} forEach (units _grp);
	[_grp, true, true] call lambs_wp_fnc_taskReset;
	[_grp, getPosASL leader _grp, _radius, [], true, false] call lambs_wp_fnc_taskCamp;

	private _contactEnemy = objNull;
	private _lambsPos     = [];  // set if LAMBS tacticsReinforce triggered externally

	waitUntil {
		sleep 3;
		if ({ alive _x } count units _grp == 0) exitWith {
			["[FOD_ZA_taskReserve] Group %1 all units dead, exiting.", groupId _grp] call FOD_ZA_fnc_debugMessage;
			true
		};

		// Find the best-known enemy across all group members via targets, knowsAbout
		private _bestKnowsAbout = 0;
		private _totalTargets = 0;
		_contactEnemy = objNull;
		{
			private _unit = _x;
			private _tgts = _unit targets [true, 0, [], 0];
			_totalTargets = _totalTargets + count _tgts;
			{
				private _tgt = _x;
				if (
					alive _tgt
					&& { [side _grp, side group _tgt] call BIS_fnc_sideIsEnemy }
					&& { !_playersOnly || isPlayer _tgt }
				) then {
					private _ka = _unit knowsAbout _tgt;
					if (_ka > 0 && { _ka > _bestKnowsAbout }) then {
						_bestKnowsAbout = _ka;
						_contactEnemy = _tgt;
					};
				};
			} forEach _tgts;
		} forEach (units _grp select { alive _x });

		// Check if LAMBS tacticsReinforce triggered externally on this group
		if (isNull _contactEnemy) then {
			if (
				(_grp getVariable ["lambs_danger_isExecutingTactic", false])
				&& { (_grp getVariable ["Lambs_main_currentTactic", ""]) == "Reinforcing" }
			) then {
				_lambsPos = (leader _grp) getVariable ["Lambs_main_currentTarget", []];
				["[FOD_ZA_taskReserve] Group %1 LAMBS reinforce detected, target pos: %2", groupId _grp, _lambsPos] call FOD_ZA_fnc_debugMessage;
			};
		};

		!isNull _contactEnemy || { !(_lambsPos isEqualTo []) }
	};

	if ({ alive _x } count units _grp > 0) then {
		[_grp, true, true] call lambs_wp_fnc_taskReset;

		private _rushPos = [];
		if (!isNull _contactEnemy) then {
			// 0wn detection via targets, knowsAbout
			private _dist = leader _grp distance2D _contactEnemy;
			["[FOD_ZA_taskReserve] Group %1 contact: %2 (isPlayer=%3), dist=%4m, knowsAbout=%5",
				groupId _grp,
				typeOf _contactEnemy,
				isPlayer _contactEnemy,
				round _dist,
				(leader _grp) knowsAbout _contactEnemy
			] call FOD_ZA_fnc_debugMessage;
			if (_dist > _radius) then {
				_rushPos = getPosATL _contactEnemy;
				["[FOD_ZA_taskReserve] Group %1 contact outside radius (%2m > %3m), moving to last known position.", groupId _grp, round _dist, _radius] call FOD_ZA_fnc_debugMessage;
			} else {
				["[FOD_ZA_taskReserve] Group %1 contact inside radius (%2m), rushing.", groupId _grp, round _dist] call FOD_ZA_fnc_debugMessage;
			};
		} else {
			// LAMBS tacticsReinforce triggered, take over with distance-aware rush
			private _dist = leader _grp distance2D _lambsPos;
			["[FOD_ZA_taskReserve] Group %1 LAMBS reinforce: dist=%2m, radius=%3m.", groupId _grp, round _dist, _radius] call FOD_ZA_fnc_debugMessage;
			if (_dist > _radius) then {
				_rushPos = _lambsPos;
				["[FOD_ZA_taskReserve] Group %1 LAMBS target outside radius, rushing to position.", groupId _grp] call FOD_ZA_fnc_debugMessage;
			} else {
				["[FOD_ZA_taskReserve] Group %1 LAMBS target inside radius, rushing.", groupId _grp] call FOD_ZA_fnc_debugMessage;
			};
		};

		[_grp, _radius, 15, [], _rushPos, _playersOnly] spawn lambs_wp_fnc_taskRush;
		sleep 2;  // short pause for LAMBS to apply its tactic/task variables
		private _rushTactic = _grp getVariable ["Lambs_main_currentTactic", ""];
		private _rushTask   = (leader _grp) getVariable ["lambs_main_currentTask", ""];
		["[FOD_ZA_taskReserve] Group %1 rush started, tactic: %2, task: %3", groupId _grp, _rushTactic, _rushTask] call FOD_ZA_fnc_debugMessage;

		// Wait for rush to end; arrived at destination, tactic/task changed, and no units in COMBAT
		private _arrived = _rushPos isEqualTo [];
		waitUntil {
			sleep 5;
			if ({ alive _x } count units _grp == 0) exitWith { true };
			if (!_arrived && { leader _grp distance2D _rushPos < 50 }) then {
				["[FOD_ZA_taskReserve] Group %1 arrived at rush destination.", groupId _grp] call FOD_ZA_fnc_debugMessage;
				_arrived = true;
			};
			private _currentTactic = _grp getVariable ["Lambs_main_currentTactic", ""];
			private _currentTask   = (leader _grp) getVariable ["lambs_main_currentTask", ""];
			_arrived
			&& { _currentTactic != _rushTactic || { _currentTask != _rushTask } }
			&& { ({ alive _x && { behaviour _x == "COMBAT" } } count units _grp) == 0 }
		};

		if ({ alive _x } count units _grp > 0) then {
			["[FOD_ZA_taskReserve] Group %1 rush complete (tactic: %2, task: %3), soft-resetting.",
				groupId _grp,
				_grp getVariable ["Lambs_main_currentTactic", ""],
				(leader _grp) getVariable ["lambs_main_currentTask", ""]
			] call FOD_ZA_fnc_debugMessage;
			[_grp, true, true] call lambs_wp_fnc_taskReset;
			_grp setBehaviour "AWARE";
			{ _x setUnitPos "AUTO"; _x setSpeedMode "FULL"; } forEach units _grp;
		};
	};
};

// Entrench: defend position using available cover. Adapted from lambs_wp_fnc_taskDefend (nkenny).
// example: [_grp, leader _grp, 50] spawn FOD_ZA_fnc_taskEntrench
FOD_ZA_fnc_taskEntrench = {
	if !(canSuspend) exitWith { _this spawn FOD_ZA_fnc_taskEntrench; };

	params [
		["_group", grpNull, [grpNull, objNull]],
		["_pos",    [],     [objNull, []]],
		["_radius", 75,     [0]],
		["_area",   [],     [[]]],
		["_teleport", false, [false]],
		["_useCover", 0,    [0]],
		["_stealth",  false, [false]],
		["_patrol",   false, [false]]
	];

	if (!local _group) exitWith { false };
	if (_group isEqualType objNull) then { _group = group _group; };

	if (_pos isEqualTo []) then { _pos = leader _group; };
	_pos = _pos call CBA_fnc_getPos;

	["[FOD_ZA_taskEntrench] Group %1 init - radius=%2m, useCover=%3, stealth=%4, patrol=%5", groupId _group, _radius, _useCover, _stealth, _patrol] call FOD_ZA_fnc_debugMessage;

	_group enableAttack false;
	_group setFormation (["DIAMOND", "LINE"] select _stealth);
	_group setVariable ["Lambs_danger_disableGroupAI", true, true];
	if (_stealth || _teleport) then { _group setBehaviour (["COMBAT", "STEALTH"] select _stealth); };

	_group setVariable ["Lambs_main_currentTactic", "taskDefend", true];
	[_group] call CBA_fnc_clearWaypoints;

	private _wp = _group addWaypoint [_pos, 0, 0];
	_wp setWaypointType "HOLD";

	private _defensivePos = [];
	private _leaderASL = [((AGLToASL _pos) select 2) - 5, ((getPosASL (leader _group)) select 2) - 5] select ((leader _group) distance2D _pos < _radius);

	// buildings
	if (_useCover in [0, 1, 4, 5]) then {
		private _houses = nearestObjects [_pos, ["house", "building", "strategic"], _radius];
		{
			private _buildingPos = _x buildingPos -1;
			if (_useCover isNotEqualTo 2 && { _radius > 25 }) then {
				[_buildingPos, true] call CBA_fnc_shuffle;
				_buildingPos resize ((count _buildingPos) min 2);
			};
			_defensivePos append _buildingPos;
		} forEach _houses;
	};

	// walls and fortifications
	if (_useCover in [0, 2, 5, 6]) then {
		private _fortifications = (nearestObjects [_pos, ["strategic"], _radius]) select { (_x buildingPos -1) isEqualTo [] };
		_fortifications = _fortifications apply { _x getPos [1.5, _x getDir _pos] };
		_defensivePos append _fortifications;

		private _hide = nearestTerrainObjects [_pos, ["HIDE"], _radius, false, true];
		_hide = _hide select { ((getPosASL _x) select 2) > _leaderASL && { (str _x) find "mound" > 0 } };
		_hide append (nearestTerrainObjects [_pos, ["WALL", "BUNKER"], _radius, false, true]);
		_hide = _hide apply { _x getPos [1.5, _x getDir _pos] };
		_defensivePos append _hide;
	};

	// vegetation (or fallback if nothing found)
	if (_useCover in [0, 3, 4, 6] || { _defensivePos isEqualTo [] }) then {
		private _cover = nearestTerrainObjects [_pos, ["BUSH", "TREE", "SMALL TREE"], _radius, false, true];
		_cover = _cover select { ((getPosASL _x) select 2) > _leaderASL };
		_cover = _cover apply { _x getPos [1.5, _x getDir _pos] };
		_defensivePos append _cover;
	};

	if (_area isNotEqualTo []) then {
		_area params ["_a", "_b", "_angle", "_isRectangle", ["_c", -1]];
		_defensivePos = _defensivePos select { _x inArea [_pos, _a, _b, _angle, _isRectangle, _c] };
	};

	// stealth/ambush, don't place units on roads
	if (_stealth) then {
		_defensivePos = _defensivePos select { isNull (roadAt _x) };
	};

	["[FOD_ZA_taskEntrench] Group %1 found %2 defensive positions", groupId _group, count _defensivePos] call FOD_ZA_fnc_debugMessage;
	if (_defensivePos isEqualTo []) exitWith {
		["[FOD_ZA_taskEntrench] Group %1 WARNING: no defensive positions found, exiting", groupId _group] call FOD_ZA_fnc_debugMessage;
		false
	};

	// move hold waypoint to the closest defensive position, so the leader doesn't idle at the center
	private _sortedByDist = _defensivePos apply { [(leader _group) distance2D _x, _x] };
	_sortedByDist sort true;
	_wp setWaypointPosition [(_sortedByDist select 0) select 1, 0];

	// optional sub-patrol group
	if (_patrol) then {
		private _units = (units _group) select { isNull (objectParent _x) };
		reverse _units;
		private _patrolGroup = createGroup [(side _group), true];
		[_units deleteAt 0] join _patrolGroup;
		if (count _units > 4) then { [_units deleteAt 0] join _patrolGroup; };

		if (dynamicSimulationEnabled _group) then {
			[_patrolGroup, true] remoteExec ["enableDynamicSimulation", 2];
		};
		_patrolGroup setGroupIdGlobal [format ["Patrol (%1)", groupId _patrolGroup]];

		if (_area isEqualTo []) then {
			[_patrolGroup, _pos, _radius, 4, nil, true, false] call lambs_wp_fnc_taskPatrol;
		} else {
			private _area2 = +_area;
			_area2 set [0, (_area2 select 0) * 2];
			_area2 set [1, (_area2 select 1) * 2];
			[_patrolGroup, _pos, _radius, 4, _area2, true, false] call lambs_wp_fnc_taskPatrol;
		};

		_group setVariable ["lambs_wp_baseGroup", _patrolGroup];
		_group addEventHandler ["CombatModeChanged", {
			params ["_group"];
			private _patrolGroup = _group getVariable ["lambs_wp_baseGroup", grpNull];
			(units _patrolGroup) joinSilent _group;
			_group removeEventHandler [_thisEvent, _thisEventHandler];
		}];

		if (_stealth) then {
			_patrolGroup setBehaviour "AWARE";
			_patrolGroup setCombatMode "GREEN";
		};
	};

	if (_stealth) then {
		_group setCombatMode "WHITE";
		_group setVariable ["FOD_ZA_ambushArmed", true];
		["[FOD_ZA_taskEntrench] Group %1 ambush armed - holding stealth, waiting for contact", groupId _group] call FOD_ZA_fnc_debugMessage;
	};

	if (_teleport) then {
		private _units = (units _group) select { !(_x getVariable ["lambs_danger_forceMove", false]) && { (vehicle _x) isKindOf "CAManBase" } };
		if (count _units > count _defensivePos) then { _units resize (count _defensivePos) };
		[_defensivePos, true] call CBA_fnc_shuffle;
		{
			_x setVehiclePosition [_defensivePos select _forEachIndex, [], precision _x, "CAN_COLLIDE"];
			if (!_stealth) then { _x setUnitPosWeak selectRandom ["MIDDLE", "MIDDLE", "UP"]; };
			doStop _x;
		} forEach _units;
	} else {
		// spread to defensive positions without teleporting, so they don't all pile up at the hold waypoint
		private _units = (units _group) select { !(_x getVariable ["lambs_danger_forceMove", false]) && { (vehicle _x) isKindOf "CAManBase" } };
		if (count _units > count _defensivePos) then { _units resize (count _defensivePos) };
		[_defensivePos, true] call CBA_fnc_shuffle;
		{ _x doMove (_defensivePos select _forEachIndex); } forEach _units;
	};

	_group setVariable ["FOD_ZA_defendUpdate", time];

	private _handle = [
		{
			params ["_args"];
			_args params ["_group", "_pos", "_radius", "_defensivePos"];

			private _defendUpdate = _group getVariable ["FOD_ZA_defendUpdate", time];
			private _target       = (leader _group) findNearestEnemy _pos;
			private _getHideFrom  = (leader _group) getHideFrom _target;
			private _distance2D   = _pos distance2D _target;

			// ambush trigger; break stealth when enemy enters zone, group takes fire, or engine raises behaviour to COMBAT (contact from outside zone)
			if (_group getVariable ["FOD_ZA_ambushArmed", false]) then {
				private _inZone     = !isNull _target && { _distance2D < _radius };
				private _suppressed = ({ getSuppression _x > 0.1 } count (units _group)) > 0;
				private _inCombat   = behaviour (leader _group) isEqualTo "COMBAT";
				if (_inZone || _suppressed || _inCombat) then {
					["[FOD_ZA_taskEntrench] Group %1 AMBUSH TRIGGERED (%2) - rushing!", groupId _group, ["suppressed","inZone","inCombat"] select ([_inZone, _suppressed, _inCombat] find true)] call FOD_ZA_fnc_debugMessage;
					_group setVariable ["FOD_ZA_ambushArmed", false];
					_group setVariable ["Lambs_danger_disableGroupAI", false, true];
					_group enableAttack true;
					[_group, false, true] call lambs_wp_fnc_taskReset;
					_group setBehaviour "AWARE";
					_group setSpeedMode "FULL";
					{ _x setUnitPos "AUTO" } forEach (units _group);
					[_group, _radius, 0] spawn lambs_wp_fnc_taskRush;
				};
			};

			private _units = (units _group) select {
				simulationEnabled _x
				&& { isNull (objectParent _x) }
				&& { !(_x getVariable ["lambs_danger_forceMove", false]) }
				&& { !(currentCommand _x in ["GET IN", "ACTION", "HEAL"]) }
			};

			// push stacked/out-of-zone units back
			{
				private _unit = _x;
				private _nearby = _x nearEntities ["CAManBase", 1];
				if (_unit distance2D _pos > _radius || { count _nearby > 1 }) then {
					_unit doMove (_pos getPos [_radius * 0.9, _pos getDir _unit]);
					_units deleteAt _forEachIndex;
				};
			} forEach _units;

			if (isNull _target || { _getHideFrom distance2D [0, 0, 0] < 1 }) exitWith { false };

			private _leader = leader _group;

			// night flares
			if (_leader call lambs_main_fnc_isNight) then {
				_units = [_units] call lambs_main_fnc_doUGL;
			};

			// man static weapons
			_units = [_units, _leader] call lambs_main_fnc_doGroupStaticFind;

			if (!isNull _target && { _defendUpdate < time }) then {
				// enemy breached, chase them out
				if (_distance2D < _radius) exitWith {
					{ _x doMove (getPosATL _target); } forEach (units _group);
				};

				// enemy outside, reposition to best cover facing threat
				if (_distance2D > _radius) then {
					if (alive _leader && { getSuppression _leader < 0.5 }) then {
						[_leader] call lambs_main_fnc_doShareInformation;

						if ([side _group] call lambs_wp_fnc_sideHasArtillery
							&& { ([_leader, _getHideFrom, 200] call lambs_main_fnc_findNearbyFriendlies) isEqualTo [] }) then {
							[_leader, _getHideFrom] call lambs_main_fnc_doCallArtillery;
						};
					};

					_group setFormDir (_pos getDir _getHideFrom);

					_defensivePos = _defensivePos apply { [_getHideFrom distanceSqr _x, _x] };
					_defensivePos sort true;
					_defensivePos = _defensivePos apply { _x select 1 };

					if (count _units > count _defensivePos) then { _units resize (count _defensivePos) };

					{
						private _unit      = _x;
						private _movePos   = _defensivePos select _forEachIndex;
						private _moveDist  = _unit distance2D _movePos;

						if (_moveDist > 3 && { unitReady _unit || (currentCommand _unit) isEqualTo "STOP" }) then {
							_unit doMove _movePos;
							[
								{ params ["_unit"]; unitReady _unit },
								{ params ["_unit"]; doStop _unit },
								[_unit]
							] call CBA_fnc_waitUntilAndExecute;
						};

						if (_moveDist < 3 && { (currentCommand _unit) isNotEqualTo "STOP" }) then { doStop _unit; };

						if (_moveDist > _radius && { (getSuppression _unit) isEqualTo 0 } && { (currentCommand _unit) isEqualTo "STOP" }) then {
							_unit doFollow (leader _unit);
						};
					} forEach _units;
				};
				_group setVariable ["FOD_ZA_defendUpdate", time + 23];
			};
		},
		8,
		[_group, _pos, _radius, _defensivePos]
	] call CBA_fnc_addPerFrameHandler;

	private _waypointCount = count (waypoints _group);
	waitUntil {
		waitUntil { sleep 2; simulationEnabled (leader _group) };
		(units _group) findIf { alive _x } == -1
		|| { count (waypoints _group) isNotEqualTo _waypointCount }
	};

	[_handle] call CBA_fnc_removePerFrameHandler;
	["[FOD_ZA_taskEntrench] Group %1 exiting - %2 alive", groupId _group, { alive _x } count units _group] call FOD_ZA_fnc_debugMessage;

	if (!isNull _group) then {
		{ [_x] call lambs_wp_fnc_doAssaultUnitReset } forEach (units _group);
	};

	true
};

// Hit & Run: engage > break contact > regroup, repeat indefinitely.
// example: [_grp, _spawnPos, _radius] spawn FOD_ZA_fnc_taskHitAndRun
// example (players only): [_grp, _spawnPos, _radius, true] spawn FOD_ZA_fnc_taskHitAndRun
FOD_ZA_fnc_taskHitAndRun = {
	if !(canSuspend) exitWith { _this spawn FOD_ZA_fnc_taskHitAndRun; };
	params ["_grp", "_spawnPos", "_radius", ["_playersOnly", false]];

	if (!local _grp) exitWith { false };
	
	["[FOD_ZA_taskHitAndRun] Group %1 starting hit & run, radius=%2m, playersOnly=%3", groupId _grp, _radius, _playersOnly] call FOD_ZA_fnc_debugMessage;
	_grp setVariable ["Lambs_danger_disableGroupAI", true, true];
	_grp setVariable ["Lambs_main_currentTactic", "taskHitAndRun", true];
	[_grp] call CBA_fnc_clearWaypoints;
	private _cycle = 0;
	while { { alive _x } count units _grp > 0 } do {
		_cycle = _cycle + 1;
		["[FOD_ZA_taskHitAndRun] Group %1 cycle %2 - hunting for contact", groupId _grp, _cycle] call FOD_ZA_fnc_debugMessage;
		_grp enableAttack true;
		[_grp, _radius, 15, [], _spawnPos, _playersOnly, false, 2] spawn lambs_wp_fnc_taskHunt;
		waitUntil {
			sleep 5;
			private _triggered = if (_playersOnly) then {
				({
					alive _x && {
						private _unit = _x;
						(allPlayers findIf { alive _x && { [side group _unit, side group _x] call BIS_fnc_sideIsEnemy } && { _unit knowsAbout _x > 0.5 } }) >= 0
					}
				} count units _grp) > 0
			} else {
				({ alive _x && { behaviour _x == "COMBAT" } } count units _grp) > 0
			};
			_triggered || { { alive _x } count units _grp == 0 }
		};
		// [_grp, true, true] call lambs_wp_fnc_taskReset;
		// Break on first casualty, majority suppressed, or after max engagement time (60s)
		private _aliveOnContact = { alive _x } count units _grp;
		private _engageTimer = 0;
		private _retreatReason = "";
		waitUntil {
			sleep 3;
			_engageTimer = _engageTimer + 3;
			private _alive = { alive _x } count units _grp;
			if (_alive == 0)                                exitWith { _retreatReason = "wiped";       true };
			if (_alive < _aliveOnContact)                  exitWith { _retreatReason = "casualty";    true };
			if (_engageTimer >= 60)                         exitWith { _retreatReason = "timer";       true };
			if (_alive > 0 && { ({ alive _x && { getSuppression _x > 0.5 } } count units _grp) > (_alive / 2) }) exitWith { _retreatReason = "suppressed"; true };
			false
		};
		if ({ alive _x } count units _grp == 0) exitWith {};
		["[FOD_ZA_taskHitAndRun] Group %1 cycle %2 - breaking contact (reason: %3)", groupId _grp, _cycle, _retreatReason] call FOD_ZA_fnc_debugMessage;
		private _nearEnemy  = leader _grp findNearestEnemy (leader _grp);
		private _retreatDir = if (!isNull _nearEnemy) then {
			((leader _grp) getDir _nearEnemy) + 180
		} else { random 360 };
		private _retreatPos = (leader _grp) getPos [_radius * 0.4 + random (_radius * 0.3), _retreatDir];
		[_grp] call CBA_fnc_clearWaypoints;
		_grp enableAttack false;
		_grp setBehaviour "AWARE";
		_grp setCombatMode "GREEN";
		_grp setSpeedMode "FULL";
		{ _x setUnitPos "UP"; _x doMove _retreatPos } forEach units _grp;
		private _wp = _grp addWaypoint [_retreatPos, 20];
		_wp setWaypointType "MOVE";
		_wp setWaypointSpeed "FULL";
		_wp setWaypointCombatMode "GREEN";
		_grp setCurrentWaypoint _wp;
		private _aliveAtRetreat = { alive _x } count units _grp;
		private _retreatTimer = 0;
		waitUntil {
			sleep 3;
			_retreatTimer = _retreatTimer + 3;
			(leader _grp) distance _retreatPos < 80
				|| { { alive _x } count units _grp == 0 }
				|| { { alive _x && { !moveToCompleted _x } } count units _grp == 0 }
				|| { (_aliveAtRetreat - ({ alive _x } count units _grp)) >= 2 }
				|| { _retreatTimer >= 60 }
		};
		[_grp] call CBA_fnc_clearWaypoints;

		// Did they make it, or did the retreat 'fail'?
		if ((leader _grp) distance _retreatPos < 80 || { { alive _x } count units _grp == 0 }) then {
			sleep 20;
		} else {
			// Retreat failed (casualties or timeout), entrench and sit it out
			["[FOD_ZA_taskHitAndRun] Group %1 cycle %2 - retreat broken, entrenching", groupId _grp, _cycle] call FOD_ZA_fnc_debugMessage;
			{ _x setUnitPos "AUTO" } forEach units _grp;
			[_grp, leader _grp, _radius * 0.3, [], false, 0, false, false] spawn FOD_ZA_fnc_taskEntrench;
			sleep 30;
			[_grp, true, true] call lambs_wp_fnc_taskReset;
		};
		_grp setCombatMode "YELLOW";
		_grp setSpeedMode "NORMAL";
	};
};

// example: [_grp, _spawnPos, _radius] call FOD_ZA_fnc_taskSeekAndDestroy
FOD_ZA_fnc_taskSeekAndDestroy = {
	params [
		["_grp",      grpNull,  [grpNull]],
		["_spawnPos", [0,0,0],  [[]]],
		["_radius",   200,      [0]]
	];

	// nearest alive enemy player to spawn position
	private _grpSide = side _grp;
	private _players = allPlayers select { alive _x && ((_grpSide getFriend (side _x)) < 0.6) };
	private _targetPos = if (count _players > 0) then {
		private _sorted = [_players, [], { _spawnPos distance (getPosATL _x) }, "ASCEND"] call BIS_fnc_sortBy;
		getPosATL (_sorted select 0)
	} else {
		_spawnPos
	};

	_grp setBehaviour "AWARE";
	_grp setCombatMode "RED";
	_grp setSpeedMode "FULL";

	private _wp = _grp addWaypoint [_targetPos, 0];
	_wp setWaypointType "SAD";
	_wp setWaypointBehaviour "AWARE";
	_wp setWaypointCombatMode "RED";
	_wp setWaypointSpeed "FULL";

	["[FOD_ZA_taskSeekAndDestroy] Group %1 S&D to nearest player pos %2", groupId _grp, _targetPos] call FOD_ZA_fnc_debugMessage;
};

// example: [_grp, _spawnPos, _radius] call FOD_ZA_fnc_taskVanillaGarrison
// example (full): [_grp, _spawnPos, _radius, sortByHeight, patrol] call FOD_ZA_fnc_taskVanillaGarrison
FOD_ZA_fnc_taskVanillaGarrison = {
	params [
		["_grp",          grpNull, [grpNull]],
		["_spawnPos",     [0,0,0], [[]]],
		["_radius",       200,     [0]],
		["_sortByHeight", false,   [false]],
		["_patrol",       false,   [false]]
	];

	private _nearArr = (_spawnPos nearObjects _radius) select { count (_x buildingPos -1) > 0 };
	if (count _nearArr == 0) exitWith {
		["[FOD_ZA_taskVanillaGarrison] No buildings found in radius %1m.", _radius] call FOD_ZA_fnc_debugMessage;
	};
	_nearArr = _nearArr call BIS_fnc_arrayShuffle;

	// collect all building positions across every building in range
	private _allPoss = [];
	{
		private _poss = _x buildingPos -1;
		if (_sortByHeight) then { _poss = [_poss, [], { _x select 2 }, "DESCEND"] call BIS_fnc_sortBy; };
		_allPoss append _poss;
	} forEach _nearArr;
	_allPoss = _allPoss call BIS_fnc_arrayShuffle;

	if (count _allPoss == 0) exitWith {
		["[FOD_ZA_taskVanillaGarrison] No building positions found in radius %1m.", _radius] call FOD_ZA_fnc_debugMessage;
	};

	// move each unit to a building position
	{
		private _pos = _allPoss select (_forEachIndex min (count _allPoss - 1));
		_x setPosATL _pos;
		_x setDir (random 360);
	} forEach units _grp;

	if (_patrol) then {
		// split a small patrol element (2-4 units) from the garrison
		private _allUnits = units _grp;
		private _patrolSize = ((count _allUnits) min 4) max 1;
		if (count _allUnits >= 2) then { _patrolSize = _patrolSize max 2; };

		private _patrolGrp = createGroup [side _grp, true];
		_patrolGrp deleteGroupWhenEmpty true;
		{ _x joinSilent _patrolGrp } forEach (_allUnits select [0, _patrolSize]);

		_patrolGrp setBehaviour "SAFE";
		_patrolGrp setCombatMode "YELLOW";
		_patrolGrp setSpeedMode "LIMITED";

		// route around the garrison area
		private _pRadius = _radius * 0.35;
		for "_w" from 0 to 2 do {
			private _dir = _w * 120;
			private _wpPos = [(_spawnPos select 0) + (_pRadius * sin _dir), (_spawnPos select 1) + (_pRadius * cos _dir), 0];
			private _wp = _patrolGrp addWaypoint [_wpPos, 15];
			_wp setWaypointType "MOVE";
			_wp setWaypointBehaviour "SAFE";
			_wp setWaypointCombatMode "YELLOW";
			_wp setWaypointSpeed "LIMITED";
		};
		private _cycleWP = _patrolGrp addWaypoint [_spawnPos, 15];
		_cycleWP setWaypointType "CYCLE";

		// remaining garrison units hold position with PATH suppression behaviour
		if (count units _grp > 0) then {
			// private _holdWP = _grp addWaypoint [_spawnPos, 0];
			// _holdWP setWaypointType "HOLD";
			// _holdWP setWaypointStatements ["true", ""];

			{
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
			} forEach units _grp;
		};
	} else {
		// private _wp = _grp addWaypoint [_spawnPos, 0];
		// _wp setWaypointType "HOLD";
		// _wp setWaypointStatements ["true", ""];

		// disable path AI, re-enable on hit (always) or suppression (40% chance)
		{
			_x disableAI "PATH";

			private _hitEH = _x addEventHandler ["Hit", {
				params ["_unit"];
				_unit enableAI "PATH";
				_unit removeEventHandler ["Hit", _thisEventHandler];
				_unit removeEventHandler ["FiredNear", _unit getVariable ["FOD_garrison_suppressEH", -1]];
			}];

			private _suppressEH = _x addEventHandler ["FiredNear", {
				params ["_unit", "_firer"];
				// ignore self-fire and friendly fire
				if (_firer isEqualTo _unit || { (side _unit getFriend side _firer) >= 0.6 }) exitWith {};
				if (random 1 < 0.4) then {
					_unit enableAI "PATH";
					_unit removeEventHandler ["FiredNear", _thisEventHandler];
					_unit removeEventHandler ["Hit", _unit getVariable ["FOD_garrison_hitEH", -1]];
				};
			}];

			_x setVariable ["FOD_garrison_hitEH", _hitEH];
			_x setVariable ["FOD_garrison_suppressEH", _suppressEH];
		} forEach units _grp;
	};

	["[FOD_ZA_taskVanillaGarrison] %1 units garrisoned, radius %2m.", count units _grp, _radius] call FOD_ZA_fnc_debugMessage;
};
