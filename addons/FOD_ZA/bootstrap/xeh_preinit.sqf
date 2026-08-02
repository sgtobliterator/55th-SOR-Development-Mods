
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

["FOD_ZA_spawnProtectDuration", "SLIDER",
    ["Spawn Protection Duration (s)", "Seconds a garage-spawned vehicle is invulnerable to damage after spawning. Set to 0 to disable."],
    ["[Forges of Dorn] Zeus Additions", "Garage Spawner"],
    [0, 30, 5, 0],
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

// Applies a temporary invulnerability window to a freshly spawned garage vehicle.
// Disables all damage for _duration seconds, then re-enables it.
FOD_ZA_fnc_vehicleSpawnProtect = {
    params [["_vehicle", objNull, [objNull]], ["_duration", 5, [0]]];
    if (isNull _vehicle) exitWith {};
    _vehicle allowDamage false;
    [_vehicle, _duration] spawn {
        params ["_vehicle", "_duration"];
        sleep _duration;
        if (isNull _vehicle) exitWith {};
        if (local _vehicle) then {
            _vehicle allowDamage true;
        } else {
            [_vehicle, true] remoteExec ["allowDamage", _vehicle];
        };
    };
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

// Searches from a module's center outwards for a spawn point inside the area radius that no enemy can see, first clear spot (closest to center) wins. Returns [0,0,0] when none is found or no enemies exist, so the caller can fall back to the module center.
// example, [_module, _radius, east] call FOD_ZA_fnc_findLoSSpawnInArea
FOD_ZA_fnc_findLoSSpawnInArea = {
	params [
		["_targetObj", objNull, [objNull]],
		["_radius", 100, [0]],
		["_side", east, [east]]
	];

	if (isNull _targetObj) exitWith { [0,0,0] };

	private _enemies = allUnits select {
		alive _x && { [_side, side _x] call BIS_fnc_sideIsEnemy }
	};

	// no enemies to hide from, let the caller keep the module center
	if (_enemies isEqualTo []) exitWith { [0,0,0] };

	private _center = getPosATL _targetObj;
	private _ringStep = (_radius / 6) max 10;
	private _ring = _ringStep;
	private _result = [0,0,0];

	// center outwards, the first out-of-LoS candidate is the closest one to the center
	while { _ring <= _radius && { _result isEqualTo [0,0,0] } } do {
		private _sampleCount = (round ((2 * pi * _ring) / _ringStep)) max 6;
		private _angleStep = 360 / _sampleCount;
		private _angleOffset = random 360;

		for "_i" from 0 to (_sampleCount - 1) do {
			private _angle = _angleOffset + (_i * _angleStep);
			private _candidate = _center getPos [_ring, _angle];
			if (surfaceIsWater _candidate) then { continue };

			private _candidateASL = AGLToASL [_candidate select 0, _candidate select 1, 0];
			private _hasLoS = false;
			{
				if (count (lineIntersectsWith [eyePos _x, _candidateASL]) == 0) exitWith { _hasLoS = true };
			} forEach _enemies;

			if (!_hasLoS) exitWith { _result = [_candidate select 0, _candidate select 1, 0]; };
		};

		_ring = _ring + _ringStep;
	};

	_result
};

// Picks a firing position for a ground support vehicle. First it looks for a spot within follow range of the ally that has clear line of sight to the threat (gun height to torso height). If nothing in range can see the enemy, it falls back to BIS_fnc_findOverwatch on the threat for a longer-range overwatch position. Returns [] when no usable position is found, so the caller can hold behind the ally instead.
// example, [_anchorPos, _enemyPos, _vehicle, 50] call FOD_ZA_fnc_findSupportFirePos
FOD_ZA_fnc_findSupportFirePos = {
	params [
		["_anchorPos", [], [[]]],
		["_enemyPos", [], [[]]],
		["_vehicle", objNull, [objNull]],
		["_followDistance", 50, [0]]
	];

	if (_anchorPos isEqualTo [] || { _enemyPos isEqualTo [] } || { isNull _vehicle }) exitWith { [] };

	// aim point near the threat's upper part,and the gun height the rounds actually leave from, so the LoS test matches firing geoe
	private _enemyASL = AGLToASL [_enemyPos select 0, _enemyPos select 1, 1.2];
	private _gunHeight = 2;

	// candidates fan out around the bearing from the ally toward the threat, so the vehicle ends up on the threat-facing side rather than behind cover
	private _dirToEnemy = [_anchorPos, _enemyPos] call BIS_fnc_dirTo;
	private _radii = [_followDistance * 0.6, _followDistance * 0.85, _followDistance];
	private _bearingOffsets = [0, 30, -30, 60, -60, 90, -90];

	private _best = [];
	{
		private _dist = _x;
		{
			private _angle = _dirToEnemy + _x;
			private _candidate = _anchorPos getPos [_dist, _angle];
			if (!(surfaceIsWater _candidate)) then {
				private _candidateASL = AGLToASL [_candidate select 0, _candidate select 1, _gunHeight];
				if (count (lineIntersectsWith [_candidateASL, _enemyASL, _vehicle]) == 0) exitWith {
					_best = [_candidate select 0, _candidate select 1, 0];
				};
			};
		} forEach _bearingOffsets;
		if (_best isNotEqualTo []) exitWith {};
	} forEach _radii;

	if (_best isNotEqualTo []) exitWith { _best };

	// nothing within follow range can see the threat, take an overwatch firing position on it instead
	private _searchRadius = (_followDistance * 3) max 150;
	private _overwatch = [_enemyPos, _searchRadius, 10] call BIS_fnc_findOverwatch;

	// BIS_fnc_findOverwatch returns a 2D [x, y] position (no z?!)
	if (!(_overwatch isEqualType []) || { count _overwatch < 2 }) exitWith { [] };

	// it returns the target itself when it finds nothing, the x and y then match the enemy, reject that so the vehicle doesn't drive onto the threat
	if ((_overwatch distance2D _enemyPos) < 25) exitWith { [] };

	// supply our own z (0 = ground) result is 2D, doMove snaps the ground vehicle to terrain anyway
	[_overwatch select 0, _overwatch select 1, 0]
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

// Shows a curator feedback message on this machine and every other connected client, so all Zeus operators see task start/stop notifications, not just whichever machine the task is running on.
// example, [format ["Tactical Push started for group %1", groupId _group]] call FOD_ZA_fnc_curatorFeedback
FOD_ZA_fnc_curatorFeedback = {
	params [["_message", "", [""]]];
	[_message] remoteExecCall ["FOD_ZA_fnc_curatorFeedbackShow", 0, false];
};

// Receiving end of FOD_ZA_fnc_curatorFeedback, only shows the message on machines with a player assigned to a curator module.
FOD_ZA_fnc_curatorFeedbackShow = {
	params [["_message", "", [""]]];
	if (isDedicated) exitWith {};
	if (isNull (getAssignedCuratorLogic player)) exitWith {};
	[objNull, _message] call BIS_fnc_showCuratorFeedbackMessage;
};


// Spawn AI Group, Custom LAMBS-compatible task functions

// Reserve / QRF, hold in place until an enemy is known, then rush to contact.
// example, [_grp, _radius] spawn FOD_ZA_fnc_taskReserve
// example (players only), [_grp, _radius, true] spawn FOD_ZA_fnc_taskReserve
FOD_ZA_fnc_taskReserve = {
	if !(canSuspend) exitWith { _this spawn FOD_ZA_fnc_taskReserve; };
	params ["_grp", "_radius", ["_playersOnly", false]];
	if (!local _grp) exitWith { false };
	private _hasLambsWp = isClass (configFile >> "CfgPatches" >> "lambs_wp");
	["[FOD_ZA_taskReserve] Group %1 holding as reserve, radius=%2m, playersOnly=%3, lambsWp=%4", groupId _grp, _radius, _playersOnly, _hasLambsWp] call FOD_ZA_fnc_debugMessage;

	if (_hasLambsWp) then {
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
	} else {
		// Vanilla fallback: camp in cover with stealth/hold-fire until Hit, FiredNear, or an enemy
		// enters the radius (killbox), then rush the nearest known enemy and soft-reset on arrival.
		private _campPos = getPosATL (leader _grp);

		[units _grp, _campPos, _radius, {
			params ["_units", "_reason"];
			[_units, _reason] spawn {
				params ["_units", "_reason"];
				private _grp = group (_units select 0);
				if ({ alive _x } count units _grp == 0) exitWith {};

				private _rushPos = [_grp, getPosATL (leader _grp)] call FOD_ZA_fnc_findNearestEnemyPos;
				["[FOD_ZA_taskReserve] Group %1 rushing to %2 (%3, vanilla).", groupId _grp, _rushPos, _reason] call FOD_ZA_fnc_debugMessage;

				_grp setBehaviour "AWARE";
				_grp setCombatMode "RED";
				_grp setSpeedMode "FULL";
				{ _x doMove _rushPos } forEach units _grp;

				waitUntil {
					sleep 5;
					{ alive _x } count units _grp == 0
					|| { leader _grp distance2D _rushPos < 50 }
					|| { ({ alive _x && { behaviour _x == "COMBAT" } } count units _grp) == 0 }
				};

				if ({ alive _x } count units _grp > 0) then {
					["[FOD_ZA_taskReserve] Group %1 rush complete, soft-resetting (vanilla).", groupId _grp] call FOD_ZA_fnc_debugMessage;
					_grp setBehaviour "AWARE";
					{ _x setUnitPos "AUTO"; _x setSpeedMode "FULL"; } forEach units _grp;
				};
			};
		}] call FOD_ZA_fnc_pushVanillaCamp;
	};
};

// Entrench, defend position using available cover. Adapted from lambs_wp_fnc_taskDefend (nkenny).
// example, [_grp, leader _grp, 50] spawn FOD_ZA_fnc_taskEntrench
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

	private _hasLambsWp = isClass (configFile >> "CfgPatches" >> "lambs_wp");

	["[FOD_ZA_taskEntrench] Group %1 init - radius=%2m, useCover=%3, stealth=%4, patrol=%5, lambsWp=%6", groupId _group, _radius, _useCover, _stealth, _patrol, _hasLambsWp] call FOD_ZA_fnc_debugMessage;

	_group enableAttack false;
	_group setFormation (["DIAMOND", "LINE"] select _stealth);
	_group setVariable ["Lambs_danger_disableGroupAI", true, true];
	if (_stealth || _teleport) then { _group setBehaviour (["COMBAT", "STEALTH"] select _stealth); };

	_group setVariable ["Lambs_main_currentTactic", "taskDefend", true];
	[_group] call CBA_fnc_clearWaypoints;

	private _wp = _group addWaypoint [AGLToASL _pos, -1, 0];
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
	_wp setWaypointPosition [AGLToASL ((_sortedByDist select 0) select 1), -1];

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

		if (_hasLambsWp) then {
			if (_area isEqualTo []) then {
				[_patrolGroup, _pos, _radius, 4, nil, true, false] call lambs_wp_fnc_taskPatrol;
			} else {
				private _area2 = +_area;
				_area2 set [0, (_area2 select 0) * 2];
				_area2 set [1, (_area2 select 1) * 2];
				[_patrolGroup, _pos, _radius, 4, _area2, true, false] call lambs_wp_fnc_taskPatrol;
			};
		} else {
			[_patrolGroup] call CBA_fnc_clearWaypoints;
			[_patrolGroup, _pos, _radius * 0.35, 3, "MOVE", "SAFE", "YELLOW", "LIMITED"] call CBA_fnc_taskPatrol;
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
			_args params ["_group", "_pos", "_radius", "_defensivePos", "_hasLambsWp"];

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
					_group setBehaviour "AWARE";
					_group setSpeedMode "FULL";
					{ _x setUnitPos "AUTO" } forEach (units _group);

					if (_hasLambsWp) then {
						[_group, false, true] call lambs_wp_fnc_taskReset;
						[_group, _radius, 0] spawn lambs_wp_fnc_taskRush;
					} else {
						[_group] call CBA_fnc_clearWaypoints;
						_group setCombatMode "RED";
						{ _x doMove (getPosATL _target) } forEach (units _group);
						{
							private _unit = _x;
							if (alive _unit && { [_unit] call FOD_ZA_fnc_pushWeaponReady } && { [_unit, _target] call FOD_ZA_fnc_pushLineOfFireClear }) then {
								([_unit] call FOD_ZA_fnc_pushClassifyUnit) params ["_category", "_weapon"];
								if (_category != "Skip") then {
									[_unit, _target, _category, _weapon, false] spawn FOD_ZA_fnc_pushFireUnit;
								};
							};
						} forEach (units _group);
					};
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

			if (_hasLambsWp) then {
				// night flares
				if (_leader call lambs_main_fnc_isNight) then {
					_units = [_units] call lambs_main_fnc_doUGL;
				};

				// man static weapons
				_units = [_units, _leader] call lambs_main_fnc_doGroupStaticFind;
			};

			if (!isNull _target && { _defendUpdate < time }) then {
				// enemy breached, chase them out
				if (_distance2D < _radius) exitWith {
					{ _x doMove (getPosATL _target); } forEach (units _group);
				};

				// enemy outside, reposition to best cover facing threat
				if (_distance2D > _radius) then {
					if (_hasLambsWp && { alive _leader && { getSuppression _leader < 0.5 } }) then {
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
		[_group, _pos, _radius, _defensivePos, _hasLambsWp]
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
		if (_hasLambsWp) then {
			{ [_x] call lambs_wp_fnc_doAssaultUnitReset } forEach (units _group);
		} else {
			{ [_x] call FOD_ZA_fnc_pushRestoreUnit } forEach (units _group);
		};
	};

	true
};

// Hit & Run, engage > break contact > regroup, repeat indefinitely.
// example, [_grp, _spawnPos, _radius] spawn FOD_ZA_fnc_taskHitAndRun
// example (players only), [_grp, _spawnPos, _radius, true] spawn FOD_ZA_fnc_taskHitAndRun
FOD_ZA_fnc_taskHitAndRun = {
	if !(canSuspend) exitWith { _this spawn FOD_ZA_fnc_taskHitAndRun; };
	params ["_grp", "_spawnPos", "_radius", ["_playersOnly", false]];

	if (!local _grp) exitWith { false };

	private _hasLambsWp = isClass (configFile >> "CfgPatches" >> "lambs_wp");

	["[FOD_ZA_taskHitAndRun] Group %1 starting hit & run, radius=%2m, playersOnly=%3, lambsWp=%4", groupId _grp, _radius, _playersOnly, _hasLambsWp] call FOD_ZA_fnc_debugMessage;
	_grp setVariable ["Lambs_danger_disableGroupAI", true, true];
	_grp setVariable ["Lambs_main_currentTactic", "taskHitAndRun", true];
	[_grp] call CBA_fnc_clearWaypoints;
	private _cycle = 0;
	while { { alive _x } count units _grp > 0 } do {
		_cycle = _cycle + 1;
		["[FOD_ZA_taskHitAndRun] Group %1 cycle %2 - hunting for contact", groupId _grp, _cycle] call FOD_ZA_fnc_debugMessage;
		_grp enableAttack true;

		if (_hasLambsWp) then {
			[_grp, _radius, 15, [], _spawnPos, _playersOnly, false, 2] spawn lambs_wp_fnc_taskHunt;
		} else {
			// "Hitting" phase: push toward the nearest known enemy at full alert, firing on visible targets while closing in
			_grp setCombatMode "RED";
			_grp setFormation "NONE";
			_grp setBehaviour "AWARE";
			_grp setSpeedMode "FULL";
			_grp setVariable ["FOD_HR_hunting", true];
			[_grp, _spawnPos, _radius, _playersOnly] spawn {
				params ["_grp", "_spawnPos", "_radius", "_playersOnly"];
				while { (_grp getVariable ["FOD_HR_hunting", false]) && { { alive _x } count units _grp > 0 } } do {
					private _enemyPos = [_grp, getPosATL (leader _grp)] call FOD_ZA_fnc_findNearestEnemyPos;
					{ _x doMove _enemyPos } forEach units _grp;
					{
						private _unit = _x;
						if (alive _unit && { [_unit] call FOD_ZA_fnc_pushWeaponReady }) then {
							private _visibleTargets = [[_unit], _playersOnly] call FOD_ZA_fnc_pushGetVisibleTargets;
							if (_visibleTargets isNotEqualTo []) then {
								private _visibleTarget = _visibleTargets select 0;
								([_unit] call FOD_ZA_fnc_pushClassifyUnit) params ["_category", "_weapon"];
								if (_category != "Skip" && { [_unit, _visibleTarget] call FOD_ZA_fnc_pushLineOfFireClear }) then {
									[_unit, _visibleTarget, _category, _weapon, false] spawn FOD_ZA_fnc_pushFireUnit;
								};
							};
						};
					} forEach units _grp;
					sleep 3;
				};
			};
		};

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
		_grp setVariable ["FOD_HR_hunting", false];
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
		private _wp = _grp addWaypoint [AGLToASL _retreatPos, -1];
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
			if (_hasLambsWp) then {
				[_grp, true, true] call lambs_wp_fnc_taskReset;
			} else {
				[_grp] call CBA_fnc_clearWaypoints;
			};
		};
		_grp setCombatMode "YELLOW";
		_grp setSpeedMode "NORMAL";
	};
};

// example, [_grp, _spawnPos, _radius] call FOD_ZA_fnc_taskSeekAndDestroy
FOD_ZA_fnc_taskSeekAndDestroy = {
	params [
		["_grp",      grpNull,  [grpNull]],
		["_spawnPos", [0,0,0],  [[]]],
		["_radius",   200,      [0]]
	];

	// nearest alive enemy player to spawn position
	private _grpSide = side _grp;
	private _players = allPlayers select { alive _x && { [_grpSide, side _x] call BIS_fnc_sideIsEnemy } };
	private _targetPos = if (count _players > 0) then {
		private _sorted = [_players, [], { _spawnPos distance (getPosATL _x) }, "ASCEND"] call BIS_fnc_sortBy;
		getPosATL (_sorted select 0)
	} else {
		_spawnPos
	};

	_grp setBehaviour "AWARE";
	_grp setCombatMode "RED";
	_grp setSpeedMode "FULL";

	private _wp = _grp addWaypoint [ATLtoASL _targetPos, -1];
	_wp setWaypointType "SAD";
	_wp setWaypointBehaviour "AWARE";
	_wp setWaypointCombatMode "RED";
	_wp setWaypointSpeed "FULL";

	["[FOD_ZA_taskSeekAndDestroy] Group %1 S&D to nearest player pos %2", groupId _grp, _targetPos] call FOD_ZA_fnc_debugMessage;
};

// example, [_grp, _spawnPos, _radius] call FOD_ZA_fnc_taskVanillaGarrison
// example (full), [_grp, _spawnPos, _radius, sortByHeight, patrol] call FOD_ZA_fnc_taskVanillaGarrison
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

		// route around the garrison area
		[_patrolGrp] call CBA_fnc_clearWaypoints;
		[_patrolGrp, _spawnPos, _radius * 0.35, 3, "MOVE", "SAFE", "YELLOW", "LIMITED"] call CBA_fnc_taskPatrol;

		// remaining garrison units hold position with PATH suppression behaviour
		if (count units _grp > 0) then {
			// private _holdWP = _grp addWaypoint [_spawnPos, 0];
			// _holdWP setWaypointType "HOLD";
			// _holdWP setWaypointStatements ["true", ""];

			{
				_x disableAI "PATH";
				_x setVariable ["FOD_garrison_hitCount", 0];

				private _hitEH = _x addEventHandler ["Hit", {
					params ["_unit", "_source", "_damage"];
					private _hitCount = (_unit getVariable ["FOD_garrison_hitCount", 0]) + 1;
					_unit setVariable ["FOD_garrison_hitCount", _hitCount];
					if (_hitCount < 3) exitWith {};
					_unit enableAI "PATH";
					_unit setVariable ["FOD_garrison_hitCount", nil];
					_unit removeEventHandler ["Hit", _thisEventHandler];
					_unit removeEventHandler ["FiredNear", _unit getVariable ["FOD_garrison_suppressEH", -1]];
				}];

				private _suppressEH = _x addEventHandler ["FiredNear", {
					params ["_unit", "_firer"];
					if (_firer isEqualTo _unit) exitWith {};
					private _isEnemy = [side _unit, side _firer] call BIS_fnc_sideIsEnemy;
					if (!_isEnemy) exitWith {};
					private _suppressMinDist = 10;
					private _suppressMaxDist = 150;
					private _fireDist = _unit distance _firer;
					if (!(_fireDist > _suppressMinDist && { _fireDist < _suppressMaxDist })) exitWith {};
					_unit enableAI "PATH";
					_unit removeEventHandler ["FiredNear", _thisEventHandler];
					_unit removeEventHandler ["Hit", _unit getVariable ["FOD_garrison_hitEH", -1]];
				}];

				_x setVariable ["FOD_garrison_hitEH", _hitEH];
				_x setVariable ["FOD_garrison_suppressEH", _suppressEH];
			} forEach units _grp;
		};
	} else {
		// private _wp = _grp addWaypoint [_spawnPos, 0];
		// _wp setWaypointType "HOLD";
		// _wp setWaypointStatements ["true", ""];

		{
			_x disableAI "PATH";
			_x setVariable ["FOD_garrison_hitCount", 0];

			private _hitEH = _x addEventHandler ["Hit", {
				params ["_unit", "_source", "_damage"];
				private _hitCount = (_unit getVariable ["FOD_garrison_hitCount", 0]) + 1;
				_unit setVariable ["FOD_garrison_hitCount", _hitCount];
				if (_hitCount < 3) exitWith {};
				_unit enableAI "PATH";
				_unit setVariable ["FOD_garrison_hitCount", nil];
				_unit removeEventHandler ["Hit", _thisEventHandler];
				_unit removeEventHandler ["FiredNear", _unit getVariable ["FOD_garrison_suppressEH", -1]];
			}];

			private _suppressEH = _x addEventHandler ["FiredNear", {
				params ["_unit", "_firer"];
				if (_firer isEqualTo _unit) exitWith {};
				private _isEnemy = [side _unit, side _firer] call BIS_fnc_sideIsEnemy;
				if (!_isEnemy) exitWith {};
				private _suppressMinDist = 10;
				private _suppressMaxDist = 150;
				private _fireDist = _unit distance _firer;
				if (!(_fireDist > _suppressMinDist && { _fireDist < _suppressMaxDist })) exitWith {};
				_unit enableAI "PATH";
				_unit removeEventHandler ["FiredNear", _thisEventHandler];
				_unit removeEventHandler ["Hit", _unit getVariable ["FOD_garrison_hitEH", -1]];
			}];

			_x setVariable ["FOD_garrison_hitEH", _hitEH];
			_x setVariable ["FOD_garrison_suppressEH", _suppressEH];
		} forEach units _grp;
	};

	["[FOD_ZA_taskVanillaGarrison] %1 units garrisoned, radius %2m.", count units _grp, _radius] call FOD_ZA_fnc_debugMessage;
};

// Tactical Push, helper functions

// Offsets a position array by distance and direction, works on positions not just objects.
// example, [getPosATL _unit, 10, 45] call FOD_ZA_fnc_pushOffsetPos
FOD_ZA_fnc_pushOffsetPos = {
	params [
		["_pos", [0,0,0], [[]]],
		["_distance", 0, [0]],
		["_direction", 0, [0]]
	];

	[
		(_pos select 0) + _distance * sin _direction,
		(_pos select 1) + _distance * cos _direction,
		_pos param [2, 0]
	]
};

// Position of the nearest alive enemy to _refPos (players first, then AI). If none known, a point 200m ahead of the group.
// example, [_grp, _refPos] call FOD_ZA_fnc_findNearestEnemyPos
FOD_ZA_fnc_findNearestEnemyPos = {
	params [
		["_grp", grpNull, [grpNull]],
		["_refPos", [0,0,0], [[]]]
	];

	private _grpSide = side _grp;

	// players take priority, fall back to any AI enemy if no enemy players exist
	private _enemyPlayers = allPlayers select { alive _x && { [_grpSide, side _x] call BIS_fnc_sideIsEnemy } };
	private _candidates = if (_enemyPlayers isNotEqualTo []) then {
		_enemyPlayers
	} else {
		allUnits select { alive _x && { (group _x) != _grp } && { [_grpSide, side _x] call BIS_fnc_sideIsEnemy } }
	};

	if (_candidates isEqualTo []) exitWith {
		// no known enemies at all, push forward in the group's current facing direction
		[_refPos, 200, getDir (leader _grp)] call FOD_ZA_fnc_pushOffsetPos
	};

	private _sortedCandidates = [_candidates, [], { _refPos distance (getPosATL _x) }, "ASCEND"] call BIS_fnc_sortBy;
	getPosATL (_sortedCandidates select 0)
};

// Nearest allied group in need near _refPos, returns [pos, group]. Players first, then AWARE/COMBAT AI groups beyond 75m (COMBAT before AWARE). [_refPos, grpNull] if none.
// example, [_grp, _refPos] call FOD_ZA_fnc_findNearestAllyPos
FOD_ZA_fnc_findNearestAllyPos = {
	params [
		["_grp", grpNull, [grpNull]],
		["_refPos", [0,0,0], [[]]]
	];

	private _grpSide = side _grp;

	// allied players first, then AI groups; exclude Zeus operators (a curator is a game master, not a unit on the ground to reinforce)
	private _alliedPlayers = allPlayers select { alive _x && { side _x == _grpSide } && { (group _x) != _grp } && { isNull (getAssignedCuratorLogic _x) } };
	if (_alliedPlayers isNotEqualTo []) exitWith {
		private _sortedPlayers = [_alliedPlayers, [], { _refPos distance (getPosATL _x) }, "ASCEND"] call BIS_fnc_sortBy;
		private _nearestPlayer = _sortedPlayers select 0;
		[getPosATL _nearestPlayer, group _nearestPlayer]
	};

	private _candidates = allGroups select {
		side _x == _grpSide && { _x != _grp } && { { alive _x } count units _x > 0 }
	};

	if (_candidates isEqualTo []) exitWith { [_refPos, grpNull] };

	// only AWARE/COMBAT groups beyond _minReinforceRange; closer ones are neighbours the QRF already absorbs (50m grab), not a fight to travel to
	private _minReinforceRange = 75;
	private _groupsInNeed = _candidates select {
		(behaviour (leader _x)) in ["AWARE", "COMBAT"] && { _refPos distance (getPosATL (leader _x)) > _minReinforceRange }
	};

	if (_groupsInNeed isEqualTo []) exitWith { [_refPos, grpNull] };

	// COMBAT groups before AWARE, nearest first within each; the COMBAT offset beats any real distance so all COMBAT sort ahead
	private _sortKey = {
		private _isCombat = (behaviour (leader _x)) isEqualTo "COMBAT";
		(if (_isCombat) then { 0 } else { 100000 }) + (_refPos distance (getPosATL (leader _x)))
	};
	private _sortedCandidates = [_groupsInNeed, [], _sortKey, "ASCEND"] call BIS_fnc_sortBy;
	private _bestGroup = _sortedCandidates select 0;

	[getPosATL (leader _bestGroup), _bestGroup]
};

// Nearest dry-land position to _pos, sampling rings outward and nudging one step inland off the waterline. Returns _pos if already on land, [] if no land within _maxRange.
// example, [getPosATL _unit] call FOD_ZA_fnc_findNearestLandPos
// example, [_pos, 600, 12] call FOD_ZA_fnc_findNearestLandPos
FOD_ZA_fnc_findNearestLandPos = {
	params [
		["_pos", [], [[], objNull]],
		["_maxRange", 600, [0]],
		["_step", 12, [0]]
	];

	if (_pos isEqualType objNull) then { _pos = getPosATL _pos; };
	if (_pos isEqualTo []) exitWith { [] };
	_step = _step max 1;

	// already on dry land, nothing to relocate
	if !(surfaceIsWater _pos) exitWith { _pos };

	private _landPos = [];
	private _radius = _step;

	while { _radius <= _maxRange && { _landPos isEqualTo [] } } do {
		// keep sample spacing roughly _step as the ring grows, clamped so big rings don't sample hundreds of points
		private _sampleCount = ((round ((2 * pi * _radius) / _step)) max 8) min 64;
		private _angleStep = 360 / _sampleCount;
		private _nearestDist = 1e10;

		for "_i" from 0 to (_sampleCount - 1) do {
			private _angle = _i * _angleStep;
			private _candidate = _pos getPos [_radius, _angle];
			private _candidateIsWater = surfaceIsWater _candidate;
			if (!_candidateIsWater) then {
				private _dist = _pos distance2D _candidate;
				if (_dist < _nearestDist) then {
					_nearestDist = _dist;
					// nudge one step further inland along the same bearing, but only if that point is still dry land
					private _inland = _pos getPos [_radius + _step, _angle];
					private _chosen = if !(surfaceIsWater _inland) then { _inland } else { _candidate };
					_landPos = [_chosen select 0, _chosen select 1, 0];
				};
			};
		};

		_radius = _radius + _step;
	};

	_landPos
};

// Moves any on-foot unit in _group standing over water onto the nearest land via FOD_ZA_fnc_findNearestLandPos. Returns the count relocated.
// example, [_dropGroup] call FOD_ZA_fnc_pushRescueSwimmers
FOD_ZA_fnc_pushRescueSwimmers = {
	params [["_group", grpNull, [grpNull, objNull]]];
	if (_group isEqualType objNull) then { _group = group _group; };
	if (isNull _group) exitWith { 0 };

	private _relocated = 0;
	{
		private _unit = _x;
		private _onFoot = vehicle _unit == _unit;
		private _overWater = surfaceIsWater (getPosATL _unit);
		if (alive _unit && { _onFoot } && { _overWater }) then {
			private _landPos = [getPosATL _unit, 600, 12] call FOD_ZA_fnc_findNearestLandPos;
			if (_landPos isNotEqualTo []) then {
				_unit setPosATL _landPos;
				_unit setVelocity [0, 0, 0];
				_relocated = _relocated + 1;
			};
		};
	} forEach (units _group);

	if (_relocated > 0) then {
		["[FOD_ZA_taskMobilizeQRF] Group %1 had %2 unit(s) come down in water, relocated to nearest land", groupId _group, _relocated] call FOD_ZA_fnc_debugMessage;
	};

	_relocated
};

// Classifies a unit's weapon, returns [category, weapon]. Launcher beats primary. With LAMBS RPG loaded, launcher units return "Skip" so FOD_ZA_fnc_pushFireUnit leaves them to LAMBS.
// example, [_unit] call FOD_ZA_fnc_pushClassifyUnit
FOD_ZA_fnc_pushClassifyUnit = {
	params [["_unit", objNull, [objNull]]];

	private _primaryWeapon = primaryWeapon _unit;
	private _secondaryWeapon = secondaryWeapon _unit;
	private _hasLambsRpg = isClass (configFile >> "CfgPatches" >> "lambs_rpg");

	if (_secondaryWeapon != "") then {
		private _secondaryType = (_secondaryWeapon call BIS_fnc_itemType) select 1;
		if (_secondaryType in ["Launcher", "MissileLauncher", "RocketLauncher"]) exitWith {
			if (_hasLambsRpg) then {
				["Skip", _secondaryWeapon]
			} else {
				["Launcher", _secondaryWeapon]
			}
		};
	};

	if (_primaryWeapon != "") then {
		private _primaryType = (_primaryWeapon call BIS_fnc_itemType) select 1;
		if (_primaryType in ["MachineGun", "SniperRifle", "Shotgun"]) exitWith {
			[_primaryType, _primaryWeapon]
		};
	};

	["Rifle", _primaryWeapon]
};

// Nearest cover position (buildings, walls, vegetation, rocks) within radius, preferring line of sight toward _enemyEyePos. Returns [] if none.
// example, [_unit, 100] call FOD_ZA_fnc_pushFindCover
// example (prefer cover with LoS toward the enemy), [_unit, 100, _enemyEyePos] call FOD_ZA_fnc_pushFindCover
FOD_ZA_fnc_pushFindCover = {
	params [
		["_unit", objNull, [objNull]],
		["_searchRadius", 100, [0]],
		["_enemyEyePos", [], [[]]]
	];

	private _unitPos = getPosATL _unit;
	private _candidates = [];

	{
		_candidates append (_x buildingPos -1);
	} forEach (nearestObjects [_unitPos, ["house", "building", "strategic"], _searchRadius]);

	private _terrainCover = nearestTerrainObjects [_unitPos, ["WALL", "BUNKER", "HIDE", "BUSH", "TREE", "SMALL TREE", "ROCK"], _searchRadius, false, true];
	_candidates append (_terrainCover apply { _x getPos [1, _x getDir _unitPos] });

	if (_candidates isEqualTo []) exitWith { [] };

	private _sortedCandidates = _candidates apply { [_unit distance2D _x, _x] };
	_sortedCandidates sort true;

	if (_enemyEyePos isEqualTo []) exitWith {
		(_sortedCandidates select 0) select 1
	};

	private _hasLineOfSight = {
		params ["_candidate"];
		private _coverPos = _candidate select 1;
		private _coverEyePos = [_coverPos select 0, _coverPos select 1, (_coverPos param [2, 0]) + 1.6];
		lineIntersectsSurfaces [_coverEyePos, _enemyEyePos, objNull, _unit] isEqualTo []
	};

	// prefer cover that holds ground or pushes closer to the enemy over cover that retreats
	private _enemyPos = [_enemyEyePos select 0, _enemyEyePos select 1, 0];
	private _unitDistToEnemy = _unitPos distance2D _enemyPos;
	private _forwardCandidates = _sortedCandidates select {
		((_x select 1) distance2D _enemyPos) <= _unitDistToEnemy
	};

	private _withLineOfSightForward = _forwardCandidates select { [_x] call _hasLineOfSight };
	if (_withLineOfSightForward isNotEqualTo []) exitWith {
		(_withLineOfSightForward select 0) select 1
	};

	if (_forwardCandidates isNotEqualTo []) exitWith {
		(_forwardCandidates select 0) select 1
	};

	private _withLineOfSight = _sortedCandidates select { [_x] call _hasLineOfSight };
	if (_withLineOfSight isNotEqualTo []) exitWith {
		(_withLineOfSight select 0) select 1
	};

	// truly no line-of-sight-positive cover anywhere, fall back to a random nearby spot
	// that isn't already occupied by another unit
	private _fallbackPos = _unitPos;
	private _fallbackFree = false;
	private _fallbackAttempts = 0;
	while { !_fallbackFree && { _fallbackAttempts < 5 } } do {
		_fallbackAttempts = _fallbackAttempts + 1;
		_fallbackPos = [_unitPos, 3 + random 5, random 360] call FOD_ZA_fnc_pushOffsetPos;
		_fallbackFree = (_fallbackPos nearEntities ["CAManBase", 1]) isEqualTo [];
	};
	_fallbackPos
};

// Gathers enemy targets visible (line of sight) to any of the given units.
// example, [_units, false] call FOD_ZA_fnc_pushGetVisibleTargets
FOD_ZA_fnc_pushGetVisibleTargets = {
	params [
		["_units", [], [[]]],
		["_playersOnly", false, [false]]
	];

	private _visibleTargets = [];

	{
		private _unit = _x;
		private _eyePos = eyePos _unit;

		{
			private _target = _x;
			private _crew = if (_target isKindOf "CAManBase") then { [_target] } else { crew _target };
			private _isPlayerCrewed = (_crew findIf { isPlayer _x }) != -1;

			if (
				alive _target
				&& { !_playersOnly || _isPlayerCrewed }
				&& { lineIntersectsSurfaces [_eyePos, eyePos _target, _unit, _target] isEqualTo [] }
			) then {
				_visibleTargets pushBackUnique _target;
			};
		} forEach (_unit targets [true, 250]);
	} forEach _units;

	_visibleTargets
};

// False if a friendly is in the firing cone between shooter and target (would risk friendly fire).
// example, [_unit, _target] call FOD_ZA_fnc_pushLineOfFireClear
FOD_ZA_fnc_pushLineOfFireClear = {
	params [
		["_unit", objNull, [objNull]],
		["_target", objNull, [objNull]]
	];

	if (isNull _unit || { isNull _target }) exitWith { true };

	private _shooterPos = eyePos _unit;
	private _targetPos = eyePos _target;
	private _targetDist = _shooterPos distance _targetPos;
	if (_targetDist < 1) exitWith { true };

	private _targetDir = _shooterPos vectorFromTo _targetPos;

	private _blocked = false;
	{
		if (_x != _unit && { alive _x } && { isNull objectParent _x }) then {
			private _friendPos = eyePos _x;
			private _friendDist = _shooterPos distance _friendPos;

			if (_friendDist > 1 && { _friendDist < _targetDist }) then {
				private _friendDir = _shooterPos vectorFromTo _friendPos;
				private _angleCos = _targetDir vectorDotProduct _friendDir;
				if (_angleCos > 0.997) exitWith { _blocked = true; };
			};
		};
	} forEach (units group _unit);

	!_blocked
};

// True if the unit's weapon is raised and ready: AWARE/COMBAT plus an "sras" aiming animation (matches standing, kneeling, prone; not lowered or sprinting).
// example, [_unit] call FOD_ZA_fnc_pushWeaponReady
FOD_ZA_fnc_pushWeaponReady = {
	params [["_unit", objNull, [objNull]]];

	private _behaviourReady = (behaviour _unit) in ["AWARE", "COMBAT"];
	if (!_behaviourReady) exitWith { false };

	private _animationState = toLower (animationState _unit);

	"sras" in _animationState
};

// Fires on a target with a pattern set by weapon category: MG bursts, sniper aimed shots, launcher at vehicles (rifle fallback), else short bursts.
// example, [_unit, _target, _category, _weapon, false] spawn FOD_ZA_fnc_pushFireUnit
FOD_ZA_fnc_pushFireUnit = {
	params [
		["_unit", objNull, [objNull]],
		["_target", objNull, [objNull]],
		["_category", "Rifle", [""]],
		["_weapon", "", [""]],
		["_playersOnly", false, [false]]
	];

	if (!alive _unit || isNull _target || { _weapon == "" } || { _category == "Skip" }) exitWith {};

	private _hasZenAI = isClass (configFile >> "CfgPatches" >> "zen_ai");

	// ensure weapons are raised and the unit is alert, exempting prone units
	if (combatMode _unit != "RED") then { _unit setCombatMode "RED"; };
	if (behaviour _unit != "COMBAT") then { _unit setBehaviour "COMBAT"; };

	if ((unitPos _unit) in ["Auto", "Up"]) then {
		_unit setUnitPosWeak "MIDDLE";
		_unit setUnitPos "MIDDLE";
	};

	if !(_hasZenAI) then {
		_unit doWatch _target;
		_unit doTarget _target;
	};

	_unit reveal [_target, 4];

	// let the stance/behaviour change settle before the first readiness check, otherwise the unit can still be mid-transition out of idle
	sleep 0.3;

	switch (_category) do {
		case "MachineGun": {
			if (_hasZenAI && { [_unit, _target] call FOD_ZA_fnc_pushLineOfFireClear } && { [_unit] call FOD_ZA_fnc_pushWeaponReady }) then {
				["[FOD_ZA_taskTacticalPush] Unit %1 suppressing with MG via ZEN AI, animation %2", name _unit, animationState _unit] call FOD_ZA_fnc_debugMessage;
				[_unit, _target, 6 + random 4, 3] call zen_ai_fnc_suppressiveFire;
			} else {
				private _burstRounds = 12 + floor (random 10);
				for "_i" from 1 to _burstRounds do {
					if (!alive _unit || { !alive _target }) exitWith {};
					if (([_unit, _target] call FOD_ZA_fnc_pushLineOfFireClear) && { [_unit] call FOD_ZA_fnc_pushWeaponReady }) then {
						["[FOD_ZA_taskTacticalPush] Unit %1 firing MG burst, animation %2", name _unit, animationState _unit] call FOD_ZA_fnc_debugMessage;
						[_unit, _weapon] call BIS_fnc_fire;
					};
					sleep (0.08 + random 0.12);
				};
			};
		};
		case "SniperRifle": {
			if (_hasZenAI && { [_unit, _target] call FOD_ZA_fnc_pushLineOfFireClear } && { [_unit] call FOD_ZA_fnc_pushWeaponReady }) then {
				["[FOD_ZA_taskTacticalPush] Unit %1 suppressing with sniper rifle via ZEN AI, animation %2", name _unit, animationState _unit] call FOD_ZA_fnc_debugMessage;
				[_unit, _target, 4 + random 3, 3] call zen_ai_fnc_suppressiveFire;
			} else {
				private _aimedShots = 1 + floor (random 2);
				for "_i" from 1 to _aimedShots do {
					if (!alive _unit || { !alive _target }) exitWith {};
					sleep (0.6 + random 1.4);
					if (([_unit, _target] call FOD_ZA_fnc_pushLineOfFireClear) && { [_unit] call FOD_ZA_fnc_pushWeaponReady }) then {
						["[FOD_ZA_taskTacticalPush] Unit %1 firing sniper shot, animation %2", name _unit, animationState _unit] call FOD_ZA_fnc_debugMessage;
						[_unit, _weapon] call BIS_fnc_fire;
					};
				};
			};
		};
		case "Launcher": {
			private _vehicleTargets = (_unit targets [true, 400]) select {
				private _crew = crew _x;
				alive _x
				&& { !(_x isKindOf "CAManBase") }
				&& { !_playersOnly || { (_crew findIf { isPlayer _x }) != -1 } }
			};

			if (_vehicleTargets isNotEqualTo []) then {
				private _vehicleTarget = selectRandom _vehicleTargets;
				_unit reveal [_vehicleTarget, 4];
				_unit doWatch _vehicleTarget;
				if (([_unit, _vehicleTarget] call FOD_ZA_fnc_pushLineOfFireClear) && { [_unit] call FOD_ZA_fnc_pushWeaponReady }) then {
					["[FOD_ZA_taskTacticalPush] Unit %1 firing launcher at vehicle, animation %2", name _unit, animationState _unit] call FOD_ZA_fnc_debugMessage;
					_unit fireAtTarget [_vehicleTarget, _weapon];
				};
			} else {
				private _riflemanWeapon = primaryWeapon _unit;
				if (_riflemanWeapon != "") then {
					if (_hasZenAI && { [_unit, _target] call FOD_ZA_fnc_pushLineOfFireClear } && { [_unit] call FOD_ZA_fnc_pushWeaponReady }) then {
						["[FOD_ZA_taskTacticalPush] Unit %1 suppressing with launcher fallback rifle via ZEN AI, animation %2", name _unit, animationState _unit] call FOD_ZA_fnc_debugMessage;
						[_unit, _target, 3 + random 2, 3] call zen_ai_fnc_suppressiveFire;
					} else {
						private _riflemanShots = 2 + floor (random 3);
						for "_i" from 1 to _riflemanShots do {
							if (!alive _unit || { !alive _target }) exitWith {};
							if (([_unit, _target] call FOD_ZA_fnc_pushLineOfFireClear) && { [_unit] call FOD_ZA_fnc_pushWeaponReady }) then {
								["[FOD_ZA_taskTacticalPush] Unit %1 firing launcher fallback rifle shot, animation %2", name _unit, animationState _unit] call FOD_ZA_fnc_debugMessage;
								[_unit, _riflemanWeapon] call BIS_fnc_fire;
							};
							sleep (0.25 + random 0.35);
						};
					};
				};
			};
		};
		default {
			if (_hasZenAI && { [_unit, _target] call FOD_ZA_fnc_pushLineOfFireClear } && { [_unit] call FOD_ZA_fnc_pushWeaponReady }) then {
				["[FOD_ZA_taskTacticalPush] Unit %1 suppressing via ZEN AI, animation %2", name _unit, animationState _unit] call FOD_ZA_fnc_debugMessage;
				[_unit, _target, 3 + random 2, 3] call zen_ai_fnc_suppressiveFire;
			} else {
				private _burstRounds = 2 + floor (random 3);
				for "_i" from 1 to _burstRounds do {
					if (!alive _unit || { !alive _target }) exitWith {};
					if (([_unit, _target] call FOD_ZA_fnc_pushLineOfFireClear) && { [_unit] call FOD_ZA_fnc_pushWeaponReady }) then {
						["[FOD_ZA_taskTacticalPush] Unit %1 firing default burst, animation %2", name _unit, animationState _unit] call FOD_ZA_fnc_debugMessage;
						[_unit, _weapon] call BIS_fnc_fire;
					};
					sleep (0.25 + random 0.35);
				};
			};
		};
	};

	if !(_hasZenAI) then {
		_unit doWatch objNull;
		_unit doTarget objNull;
	};
};

// Vehicle turret crew (not the driver) suppress a target, via ZEN AI if present, else fireAtTarget bursts. Checks the line of fire is clear before each shot.
// example, [_vehicle, _target] spawn FOD_ZA_fnc_pushFireVehicle
FOD_ZA_fnc_pushFireVehicle = {
	params [
		["_vehicle", objNull, [objNull]],
		["_target", objNull, [objNull]]
	];

	if (!alive _vehicle || { isNull _target } || { !alive _target }) exitWith {};

	private _hasZenAI = isClass (configFile >> "CfgPatches" >> "zen_ai");

	_vehicle reveal [_target, 4];

	private _turretCrew = (fullCrew [_vehicle, "", true]) select {
		((_x select 1) != "driver") && { alive (_x select 0) }
	};

	{
		_x params ["_gunner", "_role", "_turretPath"];
		if !(_turretPath isEqualType []) exitWith {};

		private _weapons = _vehicle weaponsTurret _turretPath;
		if (_weapons isEqualTo []) exitWith {};

		private _weapon = _weapons select 0;

		if (_hasZenAI && { [_gunner, _target] call FOD_ZA_fnc_pushLineOfFireClear }) then {
			["[FOD_ZA_taskSupportVehicle] Vehicle %1 gunner %2 suppressing with %3 via ZEN", typeOf _vehicle, name _gunner, _weapon] call FOD_ZA_fnc_debugMessage;
			[_gunner, _target, 6 + random 4, 3] call zen_ai_fnc_suppressiveFire;
		} else {

			_gunner doWatch _target;
			_gunner doTarget _target;

			private _burstRounds = 4 + floor (random 5);
			for "_i" from 1 to _burstRounds do {
				if (!alive _vehicle || { !alive _target }) exitWith {};
				if ([_gunner, _target] call FOD_ZA_fnc_pushLineOfFireClear) then {
					["[FOD_ZA_taskSupportVehicle] Vehicle %1 gunner %2 firing burst with %3", typeOf _vehicle, name _gunner, _weapon] call FOD_ZA_fnc_debugMessage;
					_gunner fireAtTarget [_target, _weapon];
				};
				sleep (0.3 + random 0.5);
			};
		};
	} forEach _turretCrew;
	
	{
		(_x select 0) doWatch objNull;
		(_x select 0) doTarget objNull;
	} forEach _turretCrew;
};

// Watches a vehicle ordered to drive somewhere and nudges it with setVehiclePosition if it stalls. Self-removes on arrival, death, immobilisation, or when the task moves on.
// example, [_vehicle, _group, "FOD_SV_taskGen", _taskGen] call FOD_ZA_fnc_pushUnstickVehicle
FOD_ZA_fnc_pushUnstickVehicle = {
	params ["_vehicle", "_group", "_taskGenVar", "_taskGen"];

	private _args = [_vehicle, _group, _taskGenVar, _taskGen, getPosATL _vehicle, time];

	private _pfh = [{
		params ["_args", "_pfhHandle"];
		_args params ["_vehicle", "_group", "_taskGenVar", "_taskGen", "_lastPos", "_lastMoveTime"];

		private _taskStillCurrent = (_group getVariable [_taskGenVar, 0]) == _taskGen;
		if (!alive _vehicle || { !canMove _vehicle } || { !_taskStillCurrent } || { moveToCompleted _vehicle }) exitWith {
			[_pfhHandle] call CBA_fnc_removePerFrameHandler;
			_vehicle setVariable ["FOD_unstickPFH", nil];
		};

		private _currentPos = getPosATL _vehicle;
		if (speed _vehicle > 1 || { _currentPos distance2D _lastPos > 4 }) exitWith {
			_args set [4, _currentPos];
			_args set [5, time];
		};

		if (time - _lastMoveTime > 25) then {
			["[FOD_ZA_pushUnstickVehicle] Vehicle %1 made no progress for %2s, nudging position", typeOf _vehicle, time - _lastMoveTime] call FOD_ZA_fnc_debugMessage;
			_vehicle setVehiclePosition [_currentPos, [], 5, "NONE"];
			_args set [4, getPosATL _vehicle];
			_args set [5, time];
		};
	}, 2, _args] call CBA_fnc_addPerFrameHandler;

	_vehicle setVariable ["FOD_unstickPFH", _pfh];
};

// Helpers below adapted from Sceptre common, previously used in SFS+
// Rotates a 3D vector around the Z axis, Z unchanged.
// example, [[10, 5, 2], 45] call FOD_ZA_fnc_pushRotateVector2D
FOD_ZA_fnc_pushRotateVector2D = {
	params ["_vector", "_angle"];
	_vector params ["_vectorX", "_vectorY", "_vectorZ"];
	[_vectorX * cos _angle - _vectorY * sin _angle, _vectorX * sin _angle + _vectorY * cos _angle, _vectorZ]
};

// Safe landing spot near _centerPos, clear of objects, water and steep slopes. Object clearance scales to the vehicle's footprint. Falls back to _centerPos.
// example, [_vehicle, _targetPos, 30] call FOD_ZA_fnc_pushFindHeliLandingPos
FOD_ZA_fnc_pushFindHeliLandingPos = {
	params ["_vehicle", "_centerPos", ["_maxDist", 100, [0]]];

	(boundingBoxReal _vehicle) params ["_bbMin", "_bbMax"];
	private _sizeX = (_bbMax select 0) - (_bbMin select 0);
	private _sizeY = (_bbMax select 1) - (_bbMin select 1);
	private _objClearance = (_sizeX + _sizeY) / 2;

	private _safePos = [_centerPos, 0, _maxDist, _objClearance, 0, 20, 0] call BIS_fnc_findSafePos;
	private _foundPos = [_safePos select 0, _safePos select 1, 0];

	if (_foundPos isEqualTo [0,0,0]) then {
		_foundPos = [_centerPos select 0, _centerPos select 1, _centerPos param [2, 0]];
	};

	_foundPos
};

// Ground touchdown point below an ASL position for a helicopter, allowing for landing gear height.
// example, [_vehicle, AGLToASL _targetPos] call FOD_ZA_fnc_pushHeliLandingPosASL
FOD_ZA_fnc_pushHeliLandingPosASL = {
	params ["_vehicle", "_posASL"];

	private _surfaceHit = lineIntersectsSurfaces [_posASL vectorAdd [0, 0, 50], _posASL vectorAdd [0, 0, -10], _vehicle, objNull, true, 1, "GEOM", "FIRE"];
	if (_surfaceHit isNotEqualTo []) then {
		_posASL = (_surfaceHit select 0) select 0;
	};

	private _gearHeight = 1;
	if (getNumber (configOf _vehicle >> "gearRetracting") == 1) then {
		_gearHeight = _gearHeight + (1.5 max (1.5 * getNumber (configOf _vehicle >> "gearDownTime")));
	};

	_posASL vectorAdd [0, 0, _gearHeight]
};

// Settles a helicopter after FOD_ZA_fnc_pushPilotHelicopterLand's flight path completes: lowers gear, dampens touchdown velocity, sets FOD_MQ_pilotLanded once at rest or the approach fails.
// example, [_vehicle, _landASL, _startTime, _controlTime] call FOD_ZA_fnc_pushPilotHelicopterLandSettle
FOD_ZA_fnc_pushPilotHelicopterLandSettle = {
	params ["_vehicle", "_landASL", "_startTime", "_controlTime"];

	if (!(_vehicle getVariable ["FOD_MQ_pilotApproached", false])) then {
		_vehicle setVariable ["FOD_MQ_pilotApproached", true];
		doStop _vehicle;
		_vehicle flyInHeight 0;
	};

	(_vehicle call BIS_fnc_getPitchBank) params ["_pitch", "_bank"];

	private _tooUnstable = abs _pitch > 30 || { abs _bank > 30 };
	private _tooFar = _vehicle distance2D _landASL > 20;
	private _timedOut = CBA_missionTime > (_startTime + _controlTime + 60);

	if (_tooUnstable || _tooFar || _timedOut) exitWith {
		_vehicle setVariable ["FOD_MQ_pilotLanded", true];
	};

	private _velocityVector = velocity _vehicle;

	if (isTouchingGround _vehicle) then {
		if (!isEngineOn _vehicle) then { _vehicle engineOn true; };
		// on contact, zero horizontal velocity so it plants instead of sliding, with a slight downward bias so it still registers as landed
		_vehicle setVelocity [0, 0, ((_velocityVector select 2) * 0.99) min -0.1];

		// also require low vertical speed, so a belly-bounce apex isn't mistaken for a settled landing
		if ((speed _vehicle) < 1 && { abs ((velocity _vehicle) select 2) < 1 }) then {
			_vehicle setVariable ["FOD_MQ_pilotLanded", true];
		};
	} else {
		_vehicle setVelocity [_velocityVector select 0, _velocityVector select 1, ((_velocityVector select 2) - 0.015) max -1];
	};
};

// PFH for FOD_ZA_fnc_pushPilotHelicopterLand: flies the precomputed bezier path to the landing point, then hands off to FOD_ZA_fnc_pushPilotHelicopterLandSettle.
FOD_ZA_fnc_pushPilotHelicopterLandSim = {
	params ["_args", "_pfhId"];
	_args params ["_vehicle", "_landASL", "_group", "_taskGen", "_lastPos", "_startTime", "_controlTime", "_posList", "_dirList", "_upList", "_lastTime"];

	private _taskStillCurrent = (_group getVariable ["FOD_MQ_taskGen", 0]) == _taskGen;
	private _abort = !alive _vehicle || { !alive driver _vehicle } || { !canMove _vehicle } || { !local _vehicle } || { !_taskStillCurrent };

	if (_abort) exitWith {
		[_pfhId] call CBA_fnc_removePerFrameHandler;
		if (alive _vehicle) then {
			_vehicle setVariable ["FOD_MQ_pilotActive", false];
			_vehicle flyInHeight 50;
			_vehicle doFollow _vehicle;
		};
	};

	// keep the gear down through the final approach. The AI re-raises it because the scripted velocity reads as fast flight, dropping the helicopter on its belly, so re-issue action ["LandGear"] every frame (it is a separate non-toggle action from LandGearUp, so re-issuing is safe)
	if (getNumber (configOf _vehicle >> "gearRetracting") == 1 && { !(_vehicle getVariable ["FOD_MQ_pilotLanded", false]) } && { _vehicle distance2D _landASL < 120 }) then {
		_vehicle action ["LandGear", _vehicle];
	};

	private _progress = (CBA_missionTime - _startTime) / _controlTime;
	private _delta = (CBA_missionTime - _lastTime) max 0.000001;
	_args set [10, CBA_missionTime];

	if (_progress > 1) exitWith {
		if (!(_vehicle getVariable ["FOD_MQ_pilotLanded", false])) then {
			[_vehicle, _landASL, _startTime, _controlTime] call FOD_ZA_fnc_pushPilotHelicopterLandSettle;
		};

		// hold on the ground until every passenger has left the cabin, then dwell briefly and hand control back; only a long safety timer can release it with troops aboard
		if (_vehicle getVariable ["FOD_MQ_pilotLanded", false]) then {
			if (isNil { _vehicle getVariable "FOD_MQ_pilotLandedAt" }) then {
				_vehicle setVariable ["FOD_MQ_pilotLandedAt", CBA_missionTime];
			};

			private _landedAt = _vehicle getVariable ["FOD_MQ_pilotLandedAt", CBA_missionTime];

			// re-pin every frame: the arrival logic splits the crew into a fresh AWARE group whose AI would fly off mid-unload and drop the rest from height. Cutting the engine is the strongest pin (no lift, no takeoff); the velocity clamp below backstops the frame before the next engine-off
			doStop _vehicle;
			_vehicle flyInHeight 0;
			if (isEngineOn _vehicle) then { _vehicle engineOn false; };

			// pin it dead-still: zero horizontal velocity and push down every frame (harder if airborne or rising) so it stays planted while the cabin empties
			private _vel = velocity _vehicle;
			private _downForce = if (!isTouchingGround _vehicle || { (_vel select 2) > 0 }) then { -3 } else { -1 };
			_vehicle setVelocity [0, 0, _downForce];

			// cabin is clear once the disembark handler confirms every held passenger has left (checked by vehicle, not seat, so it cannot release early)
			private _cabinClear = _vehicle getVariable ["FOD_MQ_cabinClear", true];

			// once clear, dwell briefly so troops step clear of the rotor disc before the helicopter powers up
			if (_cabinClear && { isNil { _vehicle getVariable "FOD_MQ_cabinClearAt" } }) then {
				_vehicle setVariable ["FOD_MQ_cabinClearAt", CBA_missionTime];
			};

			private _clearAt = _vehicle getVariable ["FOD_MQ_cabinClearAt", -1];
			private _dwellDone = _clearAt >= 0 && { CBA_missionTime - _clearAt > 4 };
			private _safetyExpired = CBA_missionTime - _landedAt > 120;

			if (_dwellDone || _safetyExpired) then {
				[_pfhId] call CBA_fnc_removePerFrameHandler;
				_vehicle setVariable ["FOD_MQ_pilotActive", false];
				_vehicle setVariable ["FOD_MQ_pilotLandedAt", nil];
				_vehicle setVariable ["FOD_MQ_cabinClearAt", nil];
			};
		};
	};

	private _pos = _progress bezierInterpolation _posList;
	private _dir = _progress bezierInterpolation _dirList;
	private _up = _progress bezierInterpolation _upList;
	private _velocity = (_pos vectorDiff _lastPos) vectorMultiply (1 / _delta);
	_args set [4, _pos];

	_vehicle setVelocityTransformation [_pos, _pos, _velocity, _velocity, _dir, _dir, _up, _up, _progress];
	_vehicle setVelocity _velocity;
};

// Takes direct flight control to fly a helicopter to and land it at an ASL position, bypassing AI for the final approach. Hands control back once landed, on failure, or when the task is superseded.
// example, [_vehicle, _landASL, _group, _taskGen] call FOD_ZA_fnc_pushPilotHelicopterLand
FOD_ZA_fnc_pushPilotHelicopterLand = {
	params ["_vehicle", "_landASL", "_group", "_taskGen"];

	if (!alive _vehicle || { !alive driver _vehicle } || { isPlayer driver _vehicle } || { !canMove _vehicle } || { !local _vehicle }) exitWith { false };

	private _startASL = getPosASL _vehicle;
	private _velocity = velocity _vehicle;
	private _maxSpeed = (getNumber (configOf _vehicle >> "maxSpeed")) / 3.6;
	private _seaHeight = linearConversion [0, 1, waves, 0, getNumber (configFile >> "CfgWorlds" >> worldName >> "Sea" >> "maxTide")] - getNumber (configOf _vehicle >> "maxFordingDepth");

	private _posList = [_startASL, _startASL vectorAdd _velocity];
	private _dirList = [vectorDir _vehicle, vectorDir _vehicle];
	private _upList = [vectorUp _vehicle, vectorUp _vehicle];
	private _pos = _posList select 1;
	private _dir = getDir _vehicle;
	if (_dir % 90 isEqualTo 0) then { _dir = _dir - 0.0001; };

	private _altitude = 50;
	private _approachDistance = 150;
	private _maxDropSpeed = -9.5;

	private _maxVelDist = 1100;
	private _accelMin = 2.5;
	private _accelMax = 6;
	private _pitchLimit = 70;
	private _bankLimit = 70;
	private _pitchCoef = 5.5;
	private _bankCoef = 6.5;
	private _yawSlow = 10;
	private _yawFast = 60;

	private _fnc_height = {
		params ["_queryPos", "_queryHeight"];
		private _surfaceHit = lineIntersectsSurfaces [_queryPos vectorAdd [0, 0, 2], _queryPos vectorAdd [0, 0, -_queryHeight], _vehicle, objNull, true, 1, "GEOM", "FIRE"];
		if (_surfaceHit isNotEqualTo []) then { _queryHeight = (_queryPos select 2) - (((_surfaceHit select 0) select 0) select 2); };
		_queryHeight
	};

	private _yVel = 0;
	private _distance2D = 0;
	private _targetVelocity = [];
	private _targetPos = [];
	private _minHeight = 0;
	private _height = 0;
	private _acceleration = 0;
	private _velocityChange = [];
	private _pitch = 0;
	private _bank = 0;
	private _targetDir = 0;
	private _yawLimit = 0;
	private _relDir = 0;

	while {
		_yVel = ([_velocity, -_dir] call FOD_ZA_fnc_pushRotateVector2D) select 1;
		_distance2D = _pos distance2D _landASL;
		_targetVelocity = (_pos vectorFromTo _landASL) vectorMultiply ([
			0.8,
			_maxSpeed,
			linearConversion [0, _maxVelDist, _distance2D, 0, 1, true],
			1.5
		] call BIS_fnc_easeOut);
		_targetPos = _pos vectorAdd _targetVelocity;

		if (_distance2D < _approachDistance) then {
			_minHeight = linearConversion [2, 8, _distance2D, 0, 8, true];
			_height = [_targetPos, 10] call _fnc_height;

			if (_height < _minHeight) then {
				_targetVelocity set [2, _maxDropSpeed max (_minHeight - _height) min 15];
			} else {
				_targetVelocity set [2, _maxDropSpeed max ((_landASL select 2) + _minHeight - (_pos select 2)) min 15];
			};

			_acceleration = linearConversion [0, 80, vectorMagnitude _velocity, _accelMin, _accelMax];
			_velocityChange = (_targetVelocity vectorDiff _velocity) apply { _x / _acceleration };
			_targetPos = _pos vectorAdd (_velocity vectorAdd _velocityChange);
			_targetPos set [2, (_targetPos select 2) max (getTerrainHeightASL _targetPos) max _seaHeight];
			_velocity = _targetPos vectorDiff _pos;

			[_velocityChange, -_dir, 2] call BIS_fnc_rotateVector3D
		} else {
			_height = [_targetPos, _altitude + 10] call _fnc_height;
			_targetVelocity set [2, _maxDropSpeed max (_altitude - _height) min 15];

			_acceleration = linearConversion [0, 80, vectorMagnitude _velocity, _accelMin + 2, _accelMax];
			_velocityChange = (_targetVelocity vectorDiff _velocity) apply { _x / _acceleration };
			_targetPos = _pos vectorAdd (_velocity vectorAdd _velocityChange);
			_targetPos set [2, (_targetPos select 2) max (((getTerrainHeightASL _targetPos) max _seaHeight) + 5)];
			_velocity = _targetPos vectorDiff _pos;

			[_velocityChange, -_dir, 2] call BIS_fnc_rotateVector3D
		} params ["_xVelChange", "_yVelChange"];

		_pitch = -_pitchLimit max (-_yVelChange * _pitchCoef) min _pitchLimit;
		_bank = -_bankLimit max (_xVelChange * _bankCoef) min _bankLimit;

		_targetDir = if (_distance2D < 15) then { _dir } else { _pos getDir _landASL };

		_yawLimit = linearConversion [0, 50, abs _yVel, _yawFast, _yawSlow, true];

		_dirList pushBack ([[0, cos _pitch, sin _pitch], 360 - _dir] call FOD_ZA_fnc_pushRotateVector2D);
		_upList pushBack ([[sin _bank, 0, cos _bank], 360 - _dir] call FOD_ZA_fnc_pushRotateVector2D);

		_relDir = (_targetDir - _dir) call CBA_fnc_simplifyAngle;
		_dir = (_dir + (-_yawLimit max ([_relDir, _relDir - 360] select (_relDir > 180)) min _yawLimit)) call CBA_fnc_simplifyAngle;
		if (_dir % 90 isEqualTo 0) then { _dir = _dir - 0.0001; };

		_pos = _pos vectorAdd _velocity;
		_pos set [2, (_pos select 2) max ((getTerrainHeightASL _pos) max _seaHeight)];
		_posList pushBack _pos;

		_landASL distance _pos > 2 && { count _posList < 300 }
	} do {};

	_posList pushBack (_landASL vectorAdd [0, 0, 0.4]);
	_posList pushBack _landASL;
	_dirList pushBack ([[0, cos 0, sin 0], 360 - _dir] call FOD_ZA_fnc_pushRotateVector2D);
	_upList pushBack ([[sin 0, 0, cos 0], 360 - _dir] call FOD_ZA_fnc_pushRotateVector2D);

	_vehicle engineOn true;
	doStop _vehicle;
	_vehicle setVariable ["FOD_MQ_pilotActive", true];
	_vehicle setVariable ["FOD_MQ_pilotApproached", false];
	_vehicle setVariable ["FOD_MQ_pilotLanded", false];
	_vehicle setVariable ["FOD_MQ_pilotLandedAt", nil];
	_vehicle setVariable ["FOD_MQ_cabinClearAt", nil];

	[
		FOD_ZA_fnc_pushPilotHelicopterLandSim,
		0,
		[_vehicle, _landASL, _group, _taskGen, _startASL, CBA_missionTime, count _posList, _posList, _dirList, _upList, CBA_missionTime]
	] call CBA_fnc_addPerFrameHandler;

	true
};

// Removes one unit's Tactical Push handlers and AI overrides, restoring normal AI.
// example, [_unit] call FOD_ZA_fnc_pushRestoreUnit
FOD_ZA_fnc_pushRestoreUnit = {
	params [["_unit", objNull, [objNull]]];

	if (isPlayer _unit) exitWith {};

	private _firedNearEH = _unit getVariable ["FOD_TP_firedNearEH", -1];
	if (_firedNearEH != -1) then {
		_unit removeEventHandler ["FiredNear", _firedNearEH];
		_unit setVariable ["FOD_TP_firedNearEH", nil];
	};
	if (alive _unit) then {
		_unit enableAI "AUTOCOMBAT";
		_unit enableAI "FSM";
		_unit setUnitPosWeak "AUTO"; _unit setUnitPos "AUTO";
		_unit doWatch objNull;
		_unit doTarget objNull;
		doStop _unit;
	};
};

// Removes a whole group's Tactical Push handlers and AI overrides, restoring normal AI.
// example, [_group] call FOD_ZA_fnc_pushRestoreUnits
FOD_ZA_fnc_pushRestoreUnits = {
	params [["_group", grpNull, [grpNull]]];

	{ [_x] call FOD_ZA_fnc_pushRestoreUnit; } forEach units _group;
	_group setVariable ["FOD_TP_underFire", nil];
	_group setVariable ["FOD_TP_active", nil, true];

	private _unitJoinedEH = _group getVariable ["FOD_TP_unitJoinedEH", -1];
	if (_unitJoinedEH != -1) then {
		_group removeEventHandler ["UnitJoined", _unitJoinedEH];
		_group setVariable ["FOD_TP_unitJoinedEH", nil];
	};

	private _leaderChangedEH = _group getVariable ["FOD_TP_leaderChangedEH", -1];
	if (_leaderChangedEH != -1) then {
		_group removeEventHandler ["LeaderChanged", _leaderChangedEH];
		_group setVariable ["FOD_TP_leaderChangedEH", nil];
	};
	_group setVariable ["FOD_TP_leaderChanged", nil];
};

// Hands a group back to LAMBS (or clears waypoints) and restores normal combat settings.
// example, [_group] call FOD_ZA_fnc_pushHandoffGroup
FOD_ZA_fnc_pushHandoffGroup = {
	params [["_group", grpNull, [grpNull]]];
	if ({ alive _x } count units _group == 0) exitWith {};

	if (isClass (configFile >> "CfgPatches" >> "lambs_wp")) then {
		[_group, true, true] call lambs_wp_fnc_taskReset;
	} else {
		[_group] call CBA_fnc_clearWaypoints;
	};

	_group setVariable ["Lambs_danger_disableGroupAI", false, true];
	_group enableAttack true;
	_group allowFleeing 0.5;
	_group setBehaviour "AWARE";
	_group setCombatMode "YELLOW";
	_group setSpeedMode "NORMAL";
	{ _x setUnitPos "AUTO" } forEach units _group;
};

// Cancels a running Tactical Push and restores normal AI, safe when none is running.
// example, [_group] call FOD_ZA_fnc_taskTacticalPushCancel
FOD_ZA_fnc_taskTacticalPushCancel = {
	params [["_group", grpNull, [grpNull, objNull]]];
	if (_group isEqualType objNull) then { _group = group _group; };
	if (isNull _group) exitWith {};

	_group setVariable ["FOD_TP_taskGen", (_group getVariable ["FOD_TP_taskGen", 0]) + 1];

	["[FOD_ZA_taskTacticalPush] Group %1 push cancelled, restoring AI control", groupId _group] call FOD_ZA_fnc_debugMessage;

	[_group] call FOD_ZA_fnc_pushRestoreUnits;
	[_group] call FOD_ZA_fnc_pushHandoffGroup;

	[format ["Tactical Push cancelled for group %1", groupId _group]] call FOD_ZA_fnc_curatorFeedback;
};

// Fires the camp break once, shared by all FOD_ZA_fnc_pushVanillaCamp triggers (Hit, FiredNear, killbox PFH).
// example, [_group, _campGen, _units, _onBreak, "hit"] call FOD_ZA_fnc_pushVanillaCampBreak
FOD_ZA_fnc_pushVanillaCampBreak = {
	params ["_group", "_campGen", "_units", "_onBreak", "_reason"];
	if ((_group getVariable ["FOD_camp_gen", 0]) != _campGen) exitWith {};
	_group setVariable ["FOD_camp_gen", _campGen + 1];

	{
		_x enableAI "PATH";
		_x removeEventHandler ["Hit", _x getVariable ["FOD_camp_hitEH", -1]];
		_x removeEventHandler ["FiredNear", _x getVariable ["FOD_camp_firedNearEH", -1]];
		_x setVariable ["FOD_camp_hitEH", nil];
		_x setVariable ["FOD_camp_firedNearEH", nil];
		_x setVariable ["FOD_camp_args", nil];
		_x setVariable ["FOD_camp_armed", false];
	} forEach _units;

	_group setBehaviour "AWARE";
	_group setCombatMode "RED";

	["[FOD_ZA_pushVanillaCamp] Group %1 camp broken (%2)", groupId _group, _reason] call FOD_ZA_fnc_debugMessage;
	[_units, _reason] call _onBreak;
};

// Holds a group in cover on stealth/hold-fire with idle animations until a hit, nearby enemy fire, or an enemy entering the camp radius escalates it. Scriptless take on the 3den camp pattern.
// example, [units _grp, getPosATL (leader _grp), _radius, { params ["_units","_reason"]; ... }] call FOD_ZA_fnc_pushVanillaCamp
FOD_ZA_fnc_pushVanillaCamp = {
	params [
		["_units", [], [[]]],
		["_campPos", [0,0,0], [[]]],
		["_radius", 75, [0]],
		["_onBreak", {}, [{}]]
	];

	if (_units isEqualTo []) exitWith {};
	private _group = group (_units select 0);
	private _campGen = (_group getVariable ["FOD_camp_gen", 0]) + 1;
	_group setVariable ["FOD_camp_gen", _campGen];

	{
		private _unit = _x;
		private _coverPos = [_unit, _radius] call FOD_ZA_fnc_pushFindCover;
		if (_coverPos isNotEqualTo []) then { _unit doMove _coverPos; };
		_unit disableAI "PATH";
		_unit setVariable ["FOD_camp_armed", true];
		[_unit, selectRandom ["STAND", "WATCH", "WATCH1", "WATCH2"], "ASIS", { !(_this getVariable ["FOD_camp_armed", true]) }, "AWARE"] call BIS_fnc_ambientAnimCombat;
	} forEach _units;

	_group setBehaviour "STEALTH";
	_group setCombatMode "GREEN";

	private _campArgs = [_group, _campGen, _units, _campPos, _radius, _onBreak];

	{
		private _unit = _x;
		_unit setVariable ["FOD_camp_args", _campArgs];

		private _hitEH = _unit addEventHandler ["Hit", {
			params ["_unit"];
			private _args = _unit getVariable ["FOD_camp_args", []];
			if (_args isEqualTo []) exitWith {};
			_args params ["_group", "_campGen", "_units", "_campPos", "_radius", "_onBreak"];
			[_group, _campGen, _units, _onBreak, "hit"] call FOD_ZA_fnc_pushVanillaCampBreak;
		}];

		private _firedNearEH = _unit addEventHandler ["FiredNear", {
			params ["_unit", "_firer", "", "", "", "", "_distance"];
			if (_firer isEqualTo _unit) exitWith {};
			if (!([side _unit, side _firer] call BIS_fnc_sideIsEnemy)) exitWith {};
			if (!(_distance > 10 && { _distance < 150 })) exitWith {};
			private _args = _unit getVariable ["FOD_camp_args", []];
			if (_args isEqualTo []) exitWith {};
			_args params ["_group", "_campGen", "_units", "_campPos", "_radius", "_onBreak"];
			[_group, _campGen, _units, _onBreak, "firedNear"] call FOD_ZA_fnc_pushVanillaCampBreak;
		}];

		_unit setVariable ["FOD_camp_hitEH", _hitEH];
		_unit setVariable ["FOD_camp_firedNearEH", _firedNearEH];
	} forEach _units;

	[{
		params ["_args", "_pfhHandle"];
		_args params ["_group", "_campGen", "_units", "_campPos", "_radius", "_onBreak"];

		if ((_group getVariable ["FOD_camp_gen", 0]) != _campGen) exitWith {
			[_pfhHandle] call CBA_fnc_removePerFrameHandler;
		};

		private _enemyInBox = allUnits select {
			alive _x && { [side _group, side _x] call BIS_fnc_sideIsEnemy } && { _x distance2D _campPos < _radius }
		};
		if (_enemyInBox isNotEqualTo []) then {
			[_group, _campGen, _units, _onBreak, "killbox"] call FOD_ZA_fnc_pushVanillaCampBreak;
			[_pfhHandle] call CBA_fnc_removePerFrameHandler;
		};
	}, 2, _campArgs] call CBA_fnc_addPerFrameHandler;
};

// Starts a Tactical Push on a group, or cancels an already-running one if reapplied to the same group.
// example, [_group, _targetPos, _radius, _boundDistance, _playersOnly] call FOD_ZA_fnc_taskTacticalPushToggle
FOD_ZA_fnc_taskTacticalPushToggle = {
	params [
		["_group", grpNull, [grpNull, objNull]],
		["_targetPos", [], [[], objNull]],
		["_radius", 25, [0]],
		["_boundDistance", 40, [0]],
		["_playersOnly", false, [false]]
	];

	if (_group isEqualType objNull) then { _group = group _group; };
	if (isNull _group) exitWith { false };

	// the group's AI and handlers must run where the group is local, so a Zeus curator on another machine hands the toggle off there instead of silently no-opping. groupOwner, not owner, since owner only resolves on the server
	if (!local _group) exitWith {
		// groupOwner returns 0 when the group isn't network-synced here yet (e.g. spawned by another Zeus); 0 isn't a valid remoteExec target on a non-dedicated host, so fall back to the server
		private _owner = groupOwner _group;
		if (_owner == 0) then { _owner = 2; };
		[_group, _targetPos, _radius, _boundDistance, _playersOnly] remoteExec ["FOD_ZA_fnc_taskTacticalPushToggle", _owner];
	};

	// debounce, so duplicate remoteExec hops or double clicks don't rapidly start then cancel the task
	private _now = time;
	if ((_now - (_group getVariable ["FOD_TP_lastToggle", -1000])) < 1) exitWith { false };
	_group setVariable ["FOD_TP_lastToggle", _now];

	if (_group getVariable ["FOD_TP_active", false]) exitWith {
		[_group] call FOD_ZA_fnc_taskTacticalPushCancel;
	};

	[format ["Tactical Push started for group %1", groupId _group]] call FOD_ZA_fnc_curatorFeedback;
	[_group, _targetPos, _radius, _boundDistance, _playersOnly] spawn FOD_ZA_fnc_taskTacticalPush;
};

// Cover and return-fire cycle: units break to cover (or go prone) and fire by weapon category. Shotgunners push closer instead of stopping.
// example, [_group, false] call FOD_ZA_fnc_taskTacticalPushReturnFire
FOD_ZA_fnc_taskTacticalPushReturnFire = {
	params [
		["_group", grpNull, [grpNull]],
		["_playersOnly", false, [false]]
	];

	private _activeUnits = units _group select { alive _x && { isNull objectParent _x } };
	if (_activeUnits isEqualTo []) exitWith {};

	["[FOD_ZA_taskTacticalPush] Group %1 taking fire, breaking to cover", groupId _group] call FOD_ZA_fnc_debugMessage;

	private _classifiedUnits = _activeUnits apply {
		private _classification = [_x] call FOD_ZA_fnc_pushClassifyUnit;
		_classification + [_x]
	};

	private _shotgunUnits = _classifiedUnits select { (_x select 0) == "Shotgun" };
	private _coverUnits = _classifiedUnits select { (_x select 0) != "Shotgun" };

	// rough enemy reference position so cover with a clear line of sight toward the threat is preferred
	private _enemyEyePos = ([_group, getPosATL (leader _group)] call FOD_ZA_fnc_findNearestEnemyPos) vectorAdd [0, 0, 1.6];

	// shotgunners keep pushing into close range instead of stopping, toward the enemy rather than
	// wherever they happened to be facing when they took fire
	private _enemyGroundPos = [_enemyEyePos select 0, _enemyEyePos select 1, 0];
	{
		_x params ["_category", "_weapon", "_unit"];
		private _unitPos = getPosATL _unit;
		private _xOffsetToEnemy = (_enemyGroundPos select 0) - (_unitPos select 0);
		private _yOffsetToEnemy = (_enemyGroundPos select 1) - (_unitPos select 1);
		private _dirToEnemy = _xOffsetToEnemy atan2 _yOffsetToEnemy;
		private _pushPos = [_unitPos, (10 + random 10), _dirToEnemy] call FOD_ZA_fnc_pushOffsetPos;
		_unit doMove _pushPos;
	} forEach _shotgunUnits;

	// everyone else, take cover or go prone
	{
		_x params ["_category", "_weapon", "_unit"];
		private _coverPos = [_unit, 100, _enemyEyePos] call FOD_ZA_fnc_pushFindCover;
		if (_coverPos isEqualTo []) then {
			doStop _unit;
			_unit setUnitPos "DOWN";
		} else {
			_unit setUnitPos "AUTO";
			_unit doMove _coverPos;
		};
	} forEach _coverUnits;

	// wait for units to reach cover, fallback after 15s so nobody gets stuck
	private _coverTimer = 0;
	waitUntil {
		sleep 1;
		_coverTimer = _coverTimer + 1;
		private _stillMoving = {
			_x params ["_category", "_weapon", "_unit"];
			alive _unit && { unitPos _unit != "DOWN" } && { !unitReady _unit }
		} count _coverUnits;
		_stillMoving == 0 || _coverTimer > (10 + random 10)
	};

	// crouch behind cover, pause, then stand to fire; units still mid-move at the fallback get forced into MIDDLE/UP anyway so one stuck unit can't stall the cycle
	{
		_x params ["_category", "_weapon", "_unit"];
		if (alive _unit && { unitPos _unit != "DOWN" }) then { _unit setUnitPos "MIDDLE"; };
	} forEach _coverUnits;

	sleep (7 + random 5);

	{
		_x params ["_category", "_weapon", "_unit"];
		if (alive _unit && { unitPos _unit != "DOWN" }) then { _unit setUnitPos "UP"; };
	} forEach _coverUnits;

	// look for a visible enemy among units that made it to cover or went prone
	private _firingUnits = (_coverUnits select { alive (_x select 2) }) apply { _x select 2 };
	private _visibleTargets = [_firingUnits, _playersOnly] call FOD_ZA_fnc_pushGetVisibleTargets;

	if (_visibleTargets isEqualTo []) exitWith {
		["[FOD_ZA_taskTacticalPush] Group %1 no visible targets, holding briefly", groupId _group] call FOD_ZA_fnc_debugMessage;
		sleep (5 + random 7);
		{
			if (alive _x) then {
				_x setUnitPos "AUTO";
				doStop _x;
				_x enableAI "AUTOCOMBAT";
				_x enableAI "FSM";
			};
		} forEach _firingUnits;
	};

	private _chosenTarget = selectRandom _visibleTargets;

	private _firingHandles = [];
	{
		_x params ["_category", "_weapon", "_unit"];
		if (alive _unit) then {
			private _hasLineOfSight = lineIntersectsSurfaces [eyePos _unit, eyePos _chosenTarget, _unit, _chosenTarget] isEqualTo [];
			if (_hasLineOfSight) then {
				_unit reveal [_chosenTarget, 4];
				_firingHandles pushBack ([_unit, _chosenTarget, _category, _weapon, _playersOnly] spawn FOD_ZA_fnc_pushFireUnit);
			};
		};
	} forEach _coverUnits;

	// wait for firing to finish, fallback after 30seconds
	private _fireTimer = 0;
	waitUntil {
		sleep 1;
		_fireTimer = _fireTimer + 1;
		({ !scriptDone _x } count _firingHandles) == 0 || _fireTimer > (20 + random 20)
	};

	// resume push stance; AUTOCOMBAT/FSM restored so the unit's AI aims while stationary, the bounding loop disables them again before the next bound
	{
		if (alive _x) then {
			_x setUnitPos "AUTO";
			_x doWatch objNull;
			doStop _x;
			_x enableAI "AUTOCOMBAT";
			_x enableAI "FSM";
		};
	} forEach _firingUnits;
};

// Fast bounding advance toward a target, breaking to cover and returning fire when shot at. Drives and dismounts first if the group starts mounted.
// example, [_group, _targetPos, 25, 40] spawn FOD_ZA_fnc_taskTacticalPush
// example (players only), [_group, _targetPos, 25, 40, true] spawn FOD_ZA_fnc_taskTacticalPush
FOD_ZA_fnc_taskTacticalPush = {
	if !(canSuspend) exitWith { _this spawn FOD_ZA_fnc_taskTacticalPush; };

	params [
		["_group", grpNull, [grpNull, objNull]],
		["_targetPos", [], [[], objNull]],
		["_radius", 25, [0]],
		["_boundDistance", 40, [0]],
		["_playersOnly", false, [false]]
	];

	if (_group isEqualType objNull) then { _group = group _group; };
	if (!local _group) exitWith { false };

	if (_targetPos isEqualType objNull) then { _targetPos = getPosATL _targetPos; };
	if (_targetPos isEqualTo []) exitWith { false };

	["[FOD_ZA_taskTacticalPush] Group %1 starting push toward %2, radius=%3m, bound=%4m, playersOnly=%5", groupId _group, _targetPos, _radius, _boundDistance, _playersOnly] call FOD_ZA_fnc_debugMessage;

	// generation counter, a fresh call replaces a still-running one on this group
	private _taskGen = (_group getVariable ["FOD_TP_taskGen", 0]) + 1;
	_group setVariable ["FOD_TP_taskGen", _taskGen];
	_group setVariable ["FOD_TP_active", true, true];

	_group setVariable ["Lambs_danger_disableGroupAI", true, true];
	_group setVariable ["Lambs_main_currentTactic", "taskTacticalPush", true];
	[_group] call CBA_fnc_clearWaypoints;
	_group enableAttack false;
	_group allowFleeing 0;
	_group setVariable ["FOD_TP_underFire", -1000];

	// disable own combat AI so it can't override our move/fire orders, and mark the group under fire only on nearby enemy fire (own/friendly ignored); JIP and reinforcement units get the same via UnitJoined below
	private _fnc_setupPushUnit = {
		params ["_unit"];
		if (!alive _unit) exitWith {};

		_unit disableAI "AUTOCOMBAT";
		_unit disableAI "FSM";

		if (isNil { _unit getVariable "FOD_TP_firedNearEH" }) then {
			private _firedNearEH = _unit addEventHandler ["FiredNear", {
				params ["_unit", "_firer", "_distance", "_weapon", "_muzzle", "_mode", "_ammo", "_gunner"];
				private _realFirer = if (isNull _gunner) then { _firer } else { _gunner };
				if (isNull _realFirer || { _realFirer == _unit } || { _distance > 100 }) exitWith {};
				if !([side _unit, side _realFirer] call BIS_fnc_sideIsEnemy) exitWith {};
				(group _unit) setVariable ["FOD_TP_underFire", time];
			}];
			_unit setVariable ["FOD_TP_firedNearEH", _firedNearEH];
		};
	};

	{ [_x] call _fnc_setupPushUnit; } forEach units _group;

	// cover reinforcements, and flag leader changes so the bounding loop refreshes orders (the new leader's FSM is disabled and would sit idle)
	if (isNil { _group getVariable "FOD_TP_unitJoinedEH" }) then {
		private _unitJoinedEH = _group addEventHandler ["UnitJoined", {
			params ["_group", "_newUnit"];
			[_newUnit] call _fnc_setupPushUnit;
		}];
		_group setVariable ["FOD_TP_unitJoinedEH", _unitJoinedEH];
	};

	if (isNil { _group getVariable "FOD_TP_leaderChangedEH" }) then {
		private _leaderChangedEH = _group addEventHandler ["LeaderChanged", {
			params ["_group", "_newLeader"];
			_group setVariable ["FOD_TP_leaderChanged", true];
		}];
		_group setVariable ["FOD_TP_leaderChangedEH", _leaderChangedEH];
	};

	// instantly board units assigned to a vehicle but not yet in it (e.g. a QRF truck spawned with its crew), instead of waiting for them to walk over
	{
		private _assignedVehicle = assignedVehicle _x;
		if (alive _x && { vehicle _x == _x } && { !isNull _assignedVehicle } && { alive _assignedVehicle }) then {
			_x moveInAny _assignedVehicle;
		};
	} forEach units _group;

	// if everyone is vehicle crew with no infantry to push on foot (e.g. a tank platoon), this isn't a Tactical Push job, hand off to a normal rush
	private _aliveUnits = units _group select { alive _x };
	private _vehicleCrewRoles = ["driver", "gunner", "turret", "commander"];
	private _spareInfantry = _aliveUnits select {
		(vehicle _x != _x) && { !((toLower ((assignedVehicleRole _x) param [0, ""])) in _vehicleCrewRoles) }
	};
	private _unitsOnFoot = _aliveUnits select { vehicle _x == _x };

	if (_aliveUnits isNotEqualTo [] && { _unitsOnFoot isEqualTo [] } && { _spareInfantry isEqualTo [] }) exitWith {
		["[FOD_ZA_taskTacticalPush] Group %1 is fully vehicle-crewed with no infantry to push on foot, handing off to a normal rush", groupId _group] call FOD_ZA_fnc_debugMessage;

		[_group] call FOD_ZA_fnc_pushRestoreUnits;
		[_group] call FOD_ZA_fnc_pushHandoffGroup;

		if (isClass (configFile >> "CfgPatches" >> "lambs_wp")) then {
			[_group, _radius, 15, [], _targetPos, _playersOnly] spawn lambs_wp_fnc_taskRush;
		} else {
			[_group, _targetPos, _radius] call FOD_ZA_fnc_taskSeekAndDestroy;
		};

		true
	};

	// mounted approach, drive toward the target then dismount once close
	private _vehicle = vehicle (leader _group);
	if (_vehicle != (leader _group)) then {
		private _dismountRadius = (_boundDistance max (_radius * 1.5)) * 3;

		["[FOD_ZA_taskTacticalPush] Group %1 mounted in %2, driving toward target (dismount inside %3m)", groupId _group, typeOf _vehicle, round _dismountRadius] call FOD_ZA_fnc_debugMessage;

		_vehicle setBehaviour "AWARE";
		_vehicle setSpeedMode "FULL";
		_vehicle doMove _targetPos;

		waitUntil {
			sleep 1;
			!alive _vehicle
			|| { { alive _x } count units _group == 0 }
			|| { _vehicle distance2D _targetPos < _dismountRadius }
			|| { moveToCompleted _vehicle }
			|| { !canMove _vehicle }
		};

		if ({ alive _x } count units _group > 0) then {
			if (alive _vehicle) then { doStop _vehicle; };

			private _mountedUnits = units _group select { alive _x && { vehicle _x == _vehicle } };

			if (_mountedUnits isNotEqualTo []) then {
				private _crewUnits = [];
				private _cargoUnits = _mountedUnits;

				// keep driver and gunner(s) in the vehicle, split them into their own group and hand back to normal AI rather than dragging them out; skip if the vehicle is destroyed or immobilised, then everyone bails
				if (alive _vehicle && { canMove _vehicle }) then {
					private _crewRoles = ["driver", "gunner", "turret", "commander"];
					_crewUnits = _mountedUnits select { (toLower ((assignedVehicleRole _x) param [0, ""])) in _crewRoles };
					_cargoUnits = _mountedUnits - _crewUnits;

					if (_cargoUnits isEqualTo []) then {
						_cargoUnits = _mountedUnits;
						_crewUnits = [];
					};
				};

				if (_crewUnits isNotEqualTo []) then {
					private _crewGroup = createGroup [side _group, true];
					{
						[_x] call FOD_ZA_fnc_pushRestoreUnit;
						[_x] joinSilent _crewGroup;
					} forEach _crewUnits;
					_crewGroup setBehaviour "AWARE";
					_crewGroup setCombatMode "YELLOW";
					_crewGroup setSpeedMode "NORMAL";
					["[FOD_ZA_taskTacticalPush] Group %1 split off vehicle crew (%2 unit(s)) into group %3", groupId _group, count _crewUnits, groupId _crewGroup] call FOD_ZA_fnc_debugMessage;
				};

				// fully detach the foot group from the vehicle so it isn't treated as their transport and they don't wander back to re-board
				_group leaveVehicle _vehicle;

				// instantly bail out, no animated getting-out delay
				_cargoUnits allowGetIn false;
				if (isClass (configFile >> "CfgPatches" >> "zen_common")) then {
					[_vehicle] call zen_common_fnc_ejectPassengers;
				} else {
					{
						unassignVehicle _x;
						_x moveOut _vehicle;
						uiSleep (random 1);
					} forEach _cargoUnits;
				};

				private _dismountTimer = 0;
				waitUntil {
					sleep 1;
					_dismountTimer = _dismountTimer + 1;
					({ alive _x && { vehicle _x == _vehicle } } count _cargoUnits) == 0 || _dismountTimer > 30
				};

				_cargoUnits allowGetIn true;

				private _vehicleStatus = if (!alive _vehicle) then { "destroyed" } else { if (!canMove _vehicle) then { "immobilised" } else { "alive" } };
				["[FOD_ZA_taskTacticalPush] Group %1 dismounted (vehicle %2), beginning push on foot", groupId _group, _vehicleStatus] call FOD_ZA_fnc_debugMessage;
			};
		};
	};

	// bounding advance loop
	_group setBehaviour "AWARE";
	_group setCombatMode "RED";
	_group setSpeedMode "FULL";
	_group setFormation "WEDGE";

	// the group advances continuously, only stopping for the cover/return-fire cycle when it takes fire; orders are refreshed periodically so units never idle at a stale waypoint
	private _pushCycle = 0;
	private _lastCoverBreak = -1000;
	private _coverCooldown = 10 + random 10;
	private _lastOrderTime = -1000;
	private _orderRefresh = 10 + random 10;
	// if the group is deleted mid push, units _group returns [] and the loop ends on its own; pushRestoreUnits/getVariable on the null group are safe no-ops
	while {
		{ alive _x } count units _group > 0
		&& { (_group getVariable ["FOD_TP_taskGen", 0]) == _taskGen }
	} do {
		sleep 3;

		if (_group getVariable ["FOD_TP_leaderChanged", false]) then {
			["[FOD_ZA_taskTacticalPush] Group %1 leader changed, refreshing group orders", groupId _group] call FOD_ZA_fnc_debugMessage;
			if (!isNull (leader _group)) then {
				private _leaderBehaviour = behaviour (leader _group);
				if (_leaderBehaviour in ["CARELESS", "SAFE"]) then { _group setBehaviour "AWARE"; };
			};
			if (combatMode _group != "RED") then { _group setCombatMode "RED"; };
			if (speedMode _group != "FULL") then { _group setSpeedMode "FULL"; };
			if (formation _group != "WEDGE") then { _group setFormation "WEDGE"; };
			_lastOrderTime = -1000;
			_group setVariable ["FOD_TP_leaderChanged", false];
		};

		private _underFireTime = _group getVariable ["FOD_TP_underFire", -1000];
		private _tookFire = ((time - _underFireTime) < 4) && ((time - _lastCoverBreak) > _coverCooldown);

		if (_tookFire) then {
			[_group, _playersOnly] call FOD_ZA_fnc_taskTacticalPushReturnFire;
			_lastCoverBreak = time;
			_coverCooldown = 10 + random 10;
			_group setVariable ["FOD_TP_underFire", -1000];
			_lastOrderTime = -1000;
		};

		if ((_group getVariable ["FOD_TP_taskGen", 0]) != _taskGen) exitWith {};

		private _leaderPos = getPosATL (leader _group);
		private _distanceToTarget = _leaderPos distance2D _targetPos;

		// arrival uses the group centroid, not just the leader, so the push doesn't end while stragglers are still far behind
		private _aliveGroupUnits = units _group select { alive _x };
		if (_aliveGroupUnits isEqualTo []) exitWith {};
		private _groupCentroid = [0, 0, 0];
		{ _groupCentroid = _groupCentroid vectorAdd (getPosATL _x); } forEach _aliveGroupUnits;
		_groupCentroid = _groupCentroid vectorMultiply (1 / count _aliveGroupUnits);

		if ((_groupCentroid distance2D _targetPos) < _radius) exitWith {};

		if ((time - _lastOrderTime) > _orderRefresh) then {
			_pushCycle = _pushCycle + 1;

			private _boundDist = (_boundDistance + random (_boundDistance * 0.5)) min _distanceToTarget;
			private _xOffset = (_targetPos select 0) - (_leaderPos select 0);
			private _yOffset = (_targetPos select 1) - (_leaderPos select 1);
			private _dirToTarget = _xOffset atan2 _yOffset;
			private _boundPos = [_leaderPos, _boundDist, _dirToTarget] call FOD_ZA_fnc_pushOffsetPos;

			["[FOD_ZA_taskTacticalPush] Group %1 cycle %2, pushing %3m toward target (%4m remaining)", groupId _group, _pushCycle, round _boundDist, round _distanceToTarget] call FOD_ZA_fnc_debugMessage;

			// keep at least _spacing between each unit's destination so the group doesn't bunch up, blacklisting each chosen spot for the rest of the group this cycle
			private _spacing = 4;
			private _takenSpreadPositions = [];
			{
				if (alive _x && { isNull objectParent _x }) then {
					private _fallbackPos = [_boundPos, random 8, random 360] call FOD_ZA_fnc_pushOffsetPos;
					private _blacklist = _takenSpreadPositions apply { [_x, _spacing] };
					private _spreadPos = [_boundPos, 0, 8, 0, 0, -1, 0, _blacklist, [_fallbackPos, _fallbackPos]] call BIS_fnc_findSafePos;
					_takenSpreadPositions pushBack _spreadPos;

					if (unitPos _x != "UP") then { _x setUnitPos "UP"; };
					// only escalate up to AWARE
					private _unitBehaviour = behaviour _x;
					if (_unitBehaviour in ["CARELESS", "SAFE"]) then { _x setBehaviour "AWARE"; };
					if (speedMode (group _x) != "FULL") then { _x setSpeedMode "FULL"; };
					// re-disable AUTOCOMBAT/FSM before moving again, return fire restores them while stationary
					_x disableAI "AUTOCOMBAT";
					_x disableAI "FSM";
					_x doMove _spreadPos;
				};
			} forEach units _group;

			_lastOrderTime = time;
		};
	};

	if ((_group getVariable ["FOD_TP_taskGen", 0]) != _taskGen) exitWith {
		["[FOD_ZA_taskTacticalPush] Group %1 push replaced by a newer task, exiting quietly", groupId _group] call FOD_ZA_fnc_debugMessage;
	};

	[_group] call FOD_ZA_fnc_pushRestoreUnits;

	if ({ alive _x } count units _group > 0) then {
		["[FOD_ZA_taskTacticalPush] Group %1 reached the target area, handing off", groupId _group] call FOD_ZA_fnc_debugMessage;

		// if enemies remain near the objective, clear it room by room instead of just standing down
		private _groupSide = side _group;
		private _clearRadius = _radius max 50;
		private _nearbyEnemies = allUnits select {
			alive _x
			&& { (group _x) != _group }
			&& { [_groupSide, side _x] call BIS_fnc_sideIsEnemy }
			&& { _x distance2D _targetPos < _clearRadius }
		};

		private _startedClear = false;
		if (_nearbyEnemies isNotEqualTo []) then {
			if (isClass (configFile >> "CfgPatches" >> "lambs_wp")) then {
				["[FOD_ZA_taskTacticalPush] Group %1 found %2 nearby enemies, starting CQB clear", groupId _group, count _nearbyEnemies] call FOD_ZA_fnc_debugMessage;
				[_group, _targetPos, _clearRadius] spawn lambs_wp_fnc_taskCQB;
				_startedClear = true;
			} else {
				if (isClass (configFile >> "CfgPatches" >> "zen_ai")) then {
					private _nearestBuilding = nearestObject [_targetPos, "House"];
					if (!isNull _nearestBuilding && { _nearestBuilding distance2D _targetPos < _clearRadius }) then {
						["[FOD_ZA_taskTacticalPush] Group %1 found %2 nearby enemies, searching %3", groupId _group, count _nearbyEnemies, typeOf _nearestBuilding] call FOD_ZA_fnc_debugMessage;
						[_group, _nearestBuilding] call zen_ai_fnc_searchBuilding;
						_startedClear = true;
					};
				};
			};
		};

		if (!_startedClear) then {
			[_group] call FOD_ZA_fnc_pushHandoffGroup;
		};
	};

	true
};

// Finds one nearby idle, same-side, dismounted, player-free, task-free infantry group and merges it into _group. Used by FOD_ZA_fnc_taskMobilizeQRF to gather strays. Runs once, returns true if one was absorbed.
// example, [_group, _vehicles, _searchRadius, _targetGroup] call FOD_ZA_fnc_taskMobilizeQRFGrabGroup
FOD_ZA_fnc_taskMobilizeQRFGrabGroup = {
	params [
		["_group", grpNull, [grpNull]],
		["_vehicles", [], [[]]],
		["_searchRadius", 50, [0]],
		["_targetGroup", grpNull, [grpNull]]
	];

	private _side = side _group;
	private _vehiclePositions = _vehicles apply { getPosATL _x };

	private _allGroups = allGroups;
	["[FOD_ZA_taskMobilizeQRFGrabGroup] Group %1 scanning %2 group(s) within %3m of vehicle position(s) %4", groupId _group, count _allGroups, _searchRadius, _vehiclePositions] call FOD_ZA_fnc_debugMessage;
	["[FOD_ZA_taskMobilizeQRFGrabGroup] Group %1 allGroups snapshot: %2", groupId _group, _allGroups apply { format ["%1 (side %2, %3 alive, leader pos %4, waypoints %5)", groupId _x, side _x, {alive _x} count units _x, getPosATL (leader _x), count (waypoints _x)] }] call FOD_ZA_fnc_debugMessage;

	// step 1, same side only, excluding ourselves and the group we're reinforcing
	private _sameSide = _allGroups select { side _x == _side && { _x != _group } && { _x != _targetGroup } };
	["[FOD_ZA_taskMobilizeQRFGrabGroup] Group %1, %2 group(s) on side %3 after excluding self and reinforcement target: %4", groupId _group, count _sameSide, _side, _sameSide apply { groupId _x }] call FOD_ZA_fnc_debugMessage;

	// step 2, fully dismounted groups only, nobody in that group is already riding in a vehicle
	private _dismounted = _sameSide select {
		private _units = units _x select { alive _x };
		_units isNotEqualTo [] && { (_units findIf { vehicle _x != _x }) == -1 }
	};
	["[FOD_ZA_taskMobilizeQRFGrabGroup] Group %1, %2 group(s) fully dismounted: %3", groupId _group, count _dismounted, _dismounted apply { groupId _x }] call FOD_ZA_fnc_debugMessage;

	// step 3, sort the dismounted groups by distance to the nearest vehicle, nearest first
	private _sorted = [_dismounted, [], {
		private _leaderPos = getPosATL (leader _x);
		private _distances = _vehiclePositions apply { _leaderPos distance2D _x };
		_distances sort true;
		_distances select 0
	}, "ASCEND"] call BIS_fnc_sortBy;

	// step 4, walk the sorted list once and take the first candidate that fits every remaining criterion
	private _selected = grpNull;
	{
		private _candidateGroup = _x;

		// exitWith inside forEach breaks the whole loop, so "found one, skip the rest" is a nested if/then instead
		if (isNull _selected) then {
			private _candidateUnits = units _candidateGroup select { alive _x };
			private _leaderPos = getPosATL (leader _candidateGroup);
			private _distances = _vehiclePositions apply { _leaderPos distance2D _x };
			_distances sort true;
			private _nearestDist = _distances select 0;

			if (_nearestDist < _searchRadius) then {
				private _rejectReason = "";
				// a fresh AI group has 1 implicit waypoint, so only reject groups with real orders (2 or more)
				if (_rejectReason == "" && { count (waypoints _candidateGroup) >= 2 }) then { _rejectReason = "has waypoints"; };
				if (_rejectReason == "" && { _candidateGroup getVariable ["FOD_TP_active", false] }) then { _rejectReason = "Tactical Push active"; };
				if (_rejectReason == "" && { _candidateGroup getVariable ["FOD_SV_active", false] }) then { _rejectReason = "Support Vehicle active"; };
				if (_rejectReason == "" && { (_candidateGroup getVariable ["FOD_MQ_taskGen", 0]) != 0 }) then { _rejectReason = "already has a Mobilize QRF task"; };
				if (_rejectReason == "" && { _candidateGroup getVariable ["FOD_ZA_ambushArmed", false] }) then { _rejectReason = "Setup Ambush armed"; };
				if (_rejectReason == "" && { _candidateGroup getVariable ["FOD_HR_hunting", false] }) then { _rejectReason = "Hit and Run active"; };
				if (_rejectReason == "" && { (_candidateUnits findIf { _x getVariable ["FOD_camp_armed", false] }) != -1 }) then { _rejectReason = "Reserve/QRF camp active"; };
				if (_rejectReason == "" && { (_candidateUnits findIf { isPlayer _x }) != -1 }) then { _rejectReason = "contains a player"; };

				if (_rejectReason == "") then {
					_selected = _candidateGroup;
					["[FOD_ZA_taskMobilizeQRFGrabGroup] Group %1, candidate %2 selected, %3m away, %4 unit(s)", groupId _group, groupId _candidateGroup, _nearestDist, count _candidateUnits] call FOD_ZA_fnc_debugMessage;
				} else {
					["[FOD_ZA_taskMobilizeQRFGrabGroup] Group %1, candidate %2 rejected, %3m away, %4", groupId _group, groupId _candidateGroup, _nearestDist, _rejectReason] call FOD_ZA_fnc_debugMessage;
				};
			} else {
				["[FOD_ZA_taskMobilizeQRFGrabGroup] Group %1, candidate %2 out of range, %3m away (limit %4m)", groupId _group, groupId _candidateGroup, _nearestDist, _searchRadius] call FOD_ZA_fnc_debugMessage;
			};
		};
	} forEach _sorted;

	if (isNull _selected) exitWith {
		["[FOD_ZA_taskMobilizeQRFGrabGroup] Group %1, no fitting group found within %2m", groupId _group, _searchRadius] call FOD_ZA_fnc_debugMessage;
		false
	};

	["[FOD_ZA_taskMobilizeQRFGrabGroup] Group %1 absorbing group %2 (%3 unit(s))", groupId _group, groupId _selected, count units _selected] call FOD_ZA_fnc_debugMessage;
	{ [_x] joinSilent _group } forEach (units _selected);

	true
};

// Absorbs cargo already riding in the transport that belongs to a different idle same-side group, merging it into _group. Run by FOD_ZA_fnc_taskMobilizeQRF before the radius grab so a pre-loaded transport mobilizes instead of cancelling for no passengers. Returns true if any were absorbed.
// example, [_group, _vehicles] call FOD_ZA_fnc_taskMobilizeQRFGrabCargo
FOD_ZA_fnc_taskMobilizeQRFGrabCargo = {
	params [
		["_group", grpNull, [grpNull]],
		["_vehicles", [], [[]]]
	];

	private _side = side _group;
	private _absorbed = [];

	{
		private _vehicle = _x;
		{
			private _unit = _x;
			private _unitGroup = group _unit;

			// never hijack a squad that is already running another FOD task or a Reserve/QRF camp
			private _busy = (_unitGroup getVariable ["FOD_TP_active", false])
				|| { _unitGroup getVariable ["FOD_SV_active", false] }
				|| { (_unitGroup getVariable ["FOD_MQ_taskGen", 0]) != 0 }
				|| { _unitGroup getVariable ["FOD_ZA_ambushArmed", false] }
				|| { _unitGroup getVariable ["FOD_HR_hunting", false] }
				|| { _unit getVariable ["FOD_camp_armed", false] };

			private _isForeignCargo = alive _unit
				&& { _unit isKindOf "Man" }
				&& { !isPlayer _unit }
				&& { _unitGroup != _group }
				&& { side _unitGroup == _side }
				&& { ((assignedVehicleRole _unit) param [0, ""]) == "cargo" }
				&& { !_busy };

			if (_isForeignCargo) then {
				_absorbed pushBackUnique _unit;
			};
		} forEach (crew _vehicle);
	} forEach _vehicles;

	if (_absorbed isEqualTo []) exitWith { false };

	["[FOD_ZA_taskMobilizeQRFGrabCargo] Group %1 absorbing %2 already-loaded passenger(s) from other group(s)", groupId _group, count _absorbed] call FOD_ZA_fnc_debugMessage;
	{ [_x] joinSilent _group } forEach _absorbed;

	true
};

// Mounts a group into its transport and rushes it to a target, dismounting and splitting off vehicle crew on arrival. Units that don't fit are removed.
// example, [_group, _targetPos, 30] spawn FOD_ZA_fnc_taskMobilizeQRF
FOD_ZA_fnc_taskMobilizeQRF = {
	params [
		["_group", grpNull, [grpNull, objNull]],
		["_targetPos", [], [[], objNull]],
		["_radius", 30, [0]],
		["_targetGroup", grpNull, [grpNull]],
		["_idleIfNoTarget", false, [false]]
	];

	if (_group isEqualType objNull) then { _group = group _group; };
	if (!local _group) exitWith { false };

	if (_targetPos isEqualType objNull) then { _targetPos = getPosATL _targetPos; };
	if (_targetPos isEqualTo []) exitWith { false };

	private _aliveUnits = units _group select { alive _x };
	private _vehicles = [];
	{
		private _unitVehicle = vehicle _x;
		if (_unitVehicle != _x) then {
			_vehicles pushBackUnique _unitVehicle;
		} else {
			private _assignedVehicle = assignedVehicle _x;
			if (!isNull _assignedVehicle && { alive _assignedVehicle }) then {
				_vehicles pushBackUnique _assignedVehicle;
			};
		};
	} forEach _aliveUnits;

	// if the vehicle's crew has nobody to send, widen the search before giving up; cargo riding along from mission start counts as passengers too, not just unassigned units
	private _fnc_hasCargo = {
		(_aliveUnits findIf {
			private _passengerVehicle = vehicle _x;
			_passengerVehicle != _x && { _vehicles findIf { _x isEqualTo _passengerVehicle } != -1 } && { ((assignedVehicleRole _x) select 0) == "cargo" }
		}) != -1
	};

	private _unassigned = _aliveUnits select { vehicle _x == _x };

	// nothing to reinforce and already mounted and underway, leave it alone instead of bumping FOD_MQ_taskGen and cancelling a live mobilization
	if (_idleIfNoTarget && { isNull _targetGroup } && { _unassigned isEqualTo [] } && { call _fnc_hasCargo }) exitWith {
		["[FOD_ZA_taskMobilizeQRF] Group %1 has no specific target and is already mobilized, leaving its current task untouched", groupId _group] call FOD_ZA_fnc_debugMessage;
		false
	};

	["[FOD_ZA_taskMobilizeQRF] Group %1 mobilizing toward %2, radius=%3m", groupId _group, _targetPos, _radius] call FOD_ZA_fnc_debugMessage;

	// generation counter, a fresh call replaces a still-running one on this group
	private _taskGen = (_group getVariable ["FOD_MQ_taskGen", 0]) + 1;
	_group setVariable ["FOD_MQ_taskGen", _taskGen];

	// first absorb any squad that is already riding in the transport but was never grouped to it (e.g. a transport pre-loaded with cargo at mission start), so it counts as passengers instead of the task cancelling for "no passengers"
	if (_vehicles isNotEqualTo [] && { [_group, _vehicles] call FOD_ZA_fnc_taskMobilizeQRFGrabCargo }) then {
		_aliveUnits = units _group select { alive _x };
		_unassigned = _aliveUnits select { vehicle _x == _x };
	};

	// if still empty, pick up a nearby idle infantry group, in case the module was placed on the vehicle crew but the squad beside it was never grouped to it
	if ((_vehicles isNotEqualTo []) && { _unassigned isEqualTo [] && { !(call _fnc_hasCargo) } }) then {
		["[FOD_ZA_taskMobilizeQRF] Group %1 has no passengers, searching for nearby infantry", groupId _group] call FOD_ZA_fnc_debugMessage;
		if ([_group, _vehicles, 50, _targetGroup] call FOD_ZA_fnc_taskMobilizeQRFGrabGroup) then {
			_aliveUnits = units _group select { alive _x };
		};
		_unassigned = _aliveUnits select { vehicle _x == _x };
	};

	// no transport available, rush the group there on foot and hand it off once it arrives
	if (_vehicles isEqualTo []) exitWith {
		["[FOD_ZA_taskMobilizeQRF] Group %1 has no transport, rushing on foot", groupId _group] call FOD_ZA_fnc_debugMessage;

		[_group] call CBA_fnc_clearWaypoints;
		_group setBehaviour "AWARE";
		_group setCombatMode "YELLOW";
		_group setSpeedMode "FULL";
		_group move _targetPos;

		[
			{
				params ["_group", "_targetPos", "_radius", "_taskGen", "_deadline"];
				{ alive _x } count units _group == 0
				|| { (_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen }
				|| { (getPosATL (leader _group)) distance2D _targetPos < _radius }
				|| { time > _deadline }
			},
			{
				params ["_group", "_targetPos", "_radius", "_taskGen"];
				if ((_group getVariable ["FOD_MQ_taskGen", 0]) == _taskGen && { { alive _x } count units _group > 0 }) then {
					[_group] call FOD_ZA_fnc_pushHandoffGroup;
				};
			},
			[_group, _targetPos, _radius, _taskGen, time + 60]
		] call CBA_fnc_waitUntilAndExecute;

		true
	};

	if (_unassigned isEqualTo [] && { !(call _fnc_hasCargo) }) exitWith {
		["[FOD_ZA_taskMobilizeQRF] Group %1 has no passengers to mobilize, cancelling task", groupId _group] call FOD_ZA_fnc_debugMessage;
		false
	};

	// board every unassigned unit into the nearest empty seat of the gathered vehicles
	{
		private _vehicle = _x;
		private _emptySeats = (fullCrew [_vehicle, "", true]) select { isNull (_x select 0) };

		{
			_x params ["", "_role", "_seatIndex"];
			if (_unassigned isEqualTo []) exitWith {};

			private _unit = _unassigned deleteAt 0;

			switch (toLower _role) do {
				case "driver": { _unit assignAsDriver _vehicle; _unit moveInDriver _vehicle; };
				case "commander": { _unit assignAsCommander _vehicle; _unit moveInCommander _vehicle; };
				case "gunner": { _unit assignAsGunner _vehicle; _unit moveInGunner _vehicle; };
				case "turret": {
					private _turretPath = if (_seatIndex isEqualType []) then { _seatIndex } else { [_seatIndex] };
					_unit assignAsTurret [_vehicle, _turretPath];
					_unit moveInTurret [_vehicle, _turretPath];
				};
				case "cargo": { _unit assignAsCargoIndex [_vehicle, _seatIndex]; _unit moveInCargo [_vehicle, _seatIndex]; };
			};
		} forEach _emptySeats;
	} forEach _vehicles;

	// units who still don't fit anywhere are removed
	private _leftBehind = _aliveUnits select { alive _x && { vehicle _x == _x } };
	if (_leftBehind isNotEqualTo []) then {
		["[FOD_ZA_taskMobilizeQRF] Group %1, %2 unit(s) didn't fit in transport and were removed", groupId _group, count _leftBehind] call FOD_ZA_fnc_debugMessage;
		{ 
			deleteVehicle _x;
		} forEach (_leftBehind);
	};

	// no ally actually needs reinforcing, the QRF's job here is just to assemble into the vehicle and stand by
	if (_idleIfNoTarget && { isNull _targetGroup }) exitWith {
		["[FOD_ZA_taskMobilizeQRF] Group %1 has no specific target to reinforce, holding mounted and ready", groupId _group] call FOD_ZA_fnc_debugMessage;
		[_group] call FOD_ZA_fnc_pushHandoffGroup;
		[format ["Mobilize QRF: %1 is assembled and standing by.", groupId _group]] call FOD_ZA_fnc_curatorFeedback;
		true
	};

	[_group] call CBA_fnc_clearWaypoints;
	private _targetNearRoad = (_targetPos nearRoads 30) isNotEqualTo [];
	private _planeVehicles = _vehicles select { _x isKindOf "Plane" && !(_x isKindOf "UAV") };
	private _heliVehicles = _vehicles select { _x isKindOf "Helicopter" && !(_x isKindOf "UAV") };
	private _groundVehicles = _vehicles - _heliVehicles - _planeVehicles;
	private _landingPads = [];

	{
		_x setBehaviour "AWARE";
		_x setSpeedMode "FULL";
		_x forceFollowRoad _targetNearRoad;
		_x doMove _targetPos;
		[_x, _group, "FOD_MQ_taskGen", _taskGen] call FOD_ZA_fnc_pushUnstickVehicle;
	} forEach _groundVehicles;

	// FOD_ZA_fnc_pushPilotHelicopterLand then takes direct flight control for the final approach and touchdown
	private _crewRoles = ["driver", "gunner", "turret", "commander"];
	{
		private _vehicle = _x;
		private _homePos = getPosATL _vehicle;
		private _landingPos = [_vehicle, _targetPos, 100] call FOD_ZA_fnc_pushFindHeliLandingPos;
		private _landingPad = "Land_HelipadEmpty_F" createVehicle _landingPos;
		_landingPad setPosATL _landingPos;
		_landingPads pushBack _landingPad;
		_vehicle setBehaviour "CARELESS";
		_vehicle setSpeedMode "FULL";
		_vehicle flyInHeight 50;
		_vehicle doMove _landingPos;

		// dummy waypoint at the pad so Zeus sees where the helicopter is headed, dropped once the pilot takes over
		private _wpLanding = _group addWaypoint [AGLToASL _landingPos, -1];
		_wpLanding setWaypointType "SCRIPTED";
		_wpLanding setWaypointStatements ["true", ""];
		_wpLanding setWaypointDescription "Landing Zone";
		_group setCurrentWaypoint _wpLanding;
		private _wpLandingIndex = (count (waypoints _group)) - 1;

		// the group counts as arrived while the helicopter is still airborne, which would make cargo bail out and fall; hold passengers in a waypointless group until touchdown, then return them for the normal dismount
		private _passengers = (units _group) select {
			alive _x && { vehicle _x == _vehicle } && { !(toLower ((assignedVehicleRole _x) param [0, ""]) in _crewRoles) }
		};
		private _holdingGroup = createGroup [side _group, true];
		{ [_x] joinSilent _holdingGroup } forEach _passengers;

		// heliReadyForDismount gates dismount, cabinClear gates the landing hold; both default true when there's nothing to hold and are driven by the disembark handler below
		private _nothingToHold = count _passengers == 0;
		_vehicle setVariable ["FOD_MQ_heliReadyForDismount", _nothingToHold];
		_vehicle setVariable ["FOD_MQ_cabinClear", _nothingToHold];

		["[FOD_ZA_taskMobilizeQRF] Group %1 helicopter %2 flying to %3, holding %4 passenger(s) until touchdown", groupId _group, typeOf _vehicle, _targetPos, count _passengers] call FOD_ZA_fnc_debugMessage;

		[_vehicle, _landingPos, _group, _taskGen, _wpLandingIndex] spawn {
			params ["_vehicle", "_landingPos", "_group", "_taskGen", "_wpLandingIndex"];
			waitUntil {
				sleep 1;
				!alive _vehicle
				|| { !canMove _vehicle }
				|| { (_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen }
				|| { _vehicle distance2D _landingPos < 650 && { !isTouchingGround _vehicle } }
			};

			if (alive _vehicle && { canMove _vehicle } && { (_group getVariable ["FOD_MQ_taskGen", 0]) == _taskGen }) then {
				private _landASL = [_vehicle, AGLToASL _landingPos] call FOD_ZA_fnc_pushHeliLandingPosASL;
				["[FOD_ZA_taskMobilizeQRF] Group %1 helicopter %2 close to %3, taking over for landing", groupId _group, typeOf _vehicle, _landingPos] call FOD_ZA_fnc_debugMessage;
				[_vehicle, _landASL, _group, _taskGen] call FOD_ZA_fnc_pushPilotHelicopterLand;
			};

			if (_wpLandingIndex >= 0 && { _wpLandingIndex < count (waypoints _group) }) then {
				deleteWaypoint [_group, _wpLandingIndex];
			};
		};

		[
			{
				params ["_args", "_pfhId"];
				_args params ["_vehicle", "_passengers", "_holdingGroup", "_group", "_taskGen", "_handedOff"];

				// abandon if the helicopter is gone or the task moved on; raise both flags so neither dismount nor the landing hold stalls
				if (!alive _vehicle || { (_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen }) exitWith {
					[_pfhId] call CBA_fnc_removePerFrameHandler;
					if (alive _vehicle) then {
						_vehicle setVariable ["FOD_MQ_heliReadyForDismount", true];
						_vehicle setVariable ["FOD_MQ_cabinClear", true];
					};
				};

				// wait for the helicopter to actually settle on the ground
				if (!(_vehicle getVariable ["FOD_MQ_pilotLanded", false])) exitWith {};

				// once landed, hand held passengers back to the QRF group (once) and signal dismount can begin; FOD_ZA_fnc_taskMobilizeQRFDismount does the eject
				if (!_handedOff) then {
					_args set [5, true];
					{ if (alive _x) then { [_x] joinSilent _group }; } forEach _passengers;
					_vehicle setVariable ["FOD_MQ_heliReadyForDismount", true];
				};

				// the landing hold keeps the helicopter pinned until FOD_MQ_cabinClear; raise it only once every held passenger has left the cabin
				private _stillAboard = _passengers select { alive _x && { vehicle _x == _vehicle } };

				if (_stillAboard isEqualTo []) then {
					_vehicle setVariable ["FOD_MQ_cabinClear", true];
					[_pfhId] call CBA_fnc_removePerFrameHandler;
				};
			},
			0,
			[_vehicle, _passengers, _holdingGroup, _group, _taskGen, false]
		] call CBA_fnc_addPerFrameHandler;

		// after cargo is out and the autopilot hands back, fly the helicopter home, land it with the same autopilot, then shut it down and clear waypoints so Zeus can remove it
		[_vehicle, _homePos, _group, _taskGen] spawn {
			params ["_vehicle", "_homePos", "_group", "_taskGen"];

			waitUntil {
				sleep 1;
				!alive _vehicle
				|| { !canMove _vehicle }
				|| { !alive driver _vehicle }
				|| { (_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen }
				|| { _vehicle getVariable ["FOD_MQ_pilotActive", false] }
			};

			waitUntil {
				sleep 1;
				!alive _vehicle
				|| { !canMove _vehicle }
				|| { !alive driver _vehicle }
				|| { (_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen }
				|| { !(_vehicle getVariable ["FOD_MQ_pilotActive", false]) }
			};

			if (!alive _vehicle || { !canMove _vehicle } || { !alive driver _vehicle } || { (_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen }) exitWith {};

			private _homeLandingPos = [_vehicle, _homePos, 30] call FOD_ZA_fnc_pushFindHeliLandingPos;

			// the landing hold cut the engine to pin it during unload, force it back on before the RTB move order
			_vehicle engineOn true;
			_vehicle setBehaviour "AWARE";
			_vehicle setSpeedMode "FULL";
			_vehicle flyInHeight 50;
			_vehicle doMove _homeLandingPos;

			waitUntil {
				sleep 1;
				!alive _vehicle
				|| { !canMove _vehicle }
				|| { !alive driver _vehicle }
				|| { (_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen }
				|| { _vehicle distance2D _homeLandingPos < 650 && { !isTouchingGround _vehicle } }
			};

			if (!alive _vehicle || { !canMove _vehicle } || { !alive driver _vehicle } || { (_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen }) exitWith {};

			private _landASL = [_vehicle, AGLToASL _homeLandingPos] call FOD_ZA_fnc_pushHeliLandingPosASL;
			["[FOD_ZA_taskMobilizeQRF] Group %1 helicopter %2 returning to LZ %3", groupId _group, typeOf _vehicle, _homeLandingPos] call FOD_ZA_fnc_debugMessage;
			[_vehicle, _landASL, _group, _taskGen] call FOD_ZA_fnc_pushPilotHelicopterLand;

			waitUntil {
				sleep 1;
				!alive _vehicle || { !(_vehicle getVariable ["FOD_MQ_pilotActive", false]) }
			};

			if (alive _vehicle && { canMove _vehicle } && { alive driver _vehicle }) then {
				[group driver _vehicle] call CBA_fnc_clearWaypoints;
				doStop _vehicle;
				_vehicle engineOn false;
				["[FOD_ZA_taskMobilizeQRF] Group %1 helicopter %2 shut down at LZ %3", groupId _group, typeOf _vehicle, _homePos] call FOD_ZA_fnc_debugMessage;
			};
		};
	} forEach _heliVehicles;

	// fixed-wing transport: paradrop the cargo over the target, then fly the plane home and delete it on arrival
	{
		private _vehicle = _x;
		private _homePos = getPosATL _vehicle;

		// commit the plane to the drop: CARELESS (AWARE made the VTOL wander instead of overflying), hold fire, full speed. The cargo rides this group to the drop, then splits into its own group once out so the plane can leave
		_group setBehaviour "CARELESS";
		_group setCombatMode "BLUE";
		_vehicle setSpeedMode "FULL";

		private _hasZenCommon = isClass (configFile >> "CfgPatches" >> "zen_common");

		private _hasZenAi = isClass (configFile >> "CfgPatches" >> "zen_ai");

		// paradrop waypoint wired like ZEN's Spawn Reinforcements module: SCRIPTED type and script read from ZEN's config so they match the installed ZEN. Set in one pass, frame-spacing once let the fast plane skip it as a plain MOVE during mission-start stutter. Manual fly-past below is the fallback without ZEN AI
		// waypoints are ASL but _targetPos/_homePos are ATL, convert them or the waypoint lands underground and the plane never drops
		private _targetPosASL = ATLtoASL _targetPos;
		private _homePosASL = ATLtoASL _homePos;

		private _wpDrop = _group addWaypoint [_targetPosASL, -1];
		if (_hasZenAi) then {
			private _paradropCfg = configFile >> "ZEN_WaypointTypes" >> "Paradrop";
			_wpDrop setWaypointType getText (_paradropCfg >> "type");
			_wpDrop setWaypointScript getText (_paradropCfg >> "script");
		} else {
			_wpDrop setWaypointType "MOVE";
		};

		private _wpHome = _group addWaypoint [_homePosASL, -1];
		_wpHome setWaypointType "MOVE";

		_group setCurrentWaypoint _wpDrop;

		["[FOD_ZA_taskMobilizeQRF] Group %1 plane %2 paradropping at %3 (%4), then returning to %5 to be deleted", groupId _group, typeOf _vehicle, _targetPos, ["manual fly-past", "ZEN SCRIPTED waypoint"] select _hasZenAi, _homePos] call FOD_ZA_fnc_debugMessage;

		[_vehicle, _targetPos, _hasZenCommon, _hasZenAi, _group, _wpHome, _radius, _taskGen] spawn {
			params ["_vehicle", "_targetPos", "_hasZenCommon", "_hasZenAi", "_group", "_wpHome", "_radius", "_taskGen"];

			// the delivered squad, captured before ejecting so we can split them off the instant they are all out
			private _cargoStick = (crew _vehicle) select { ((assignedVehicleRole _x) select 0) == "cargo" };
			private _fnc_cargoAboard = { { ((assignedVehicleRole _x) select 0) == "cargo" } count crew _vehicle };

			// give ZEN's paradrop waypoint a window to drop on its own, only fall through to the manual fly-past if the cargo is still aboard after
			if (_hasZenAi) then {
				private _zenGiveUpAt = CBA_missionTime + 30;
				waitUntil {
					sleep 1;
					!alive _vehicle || { call _fnc_cargoAboard == 0 } || { CBA_missionTime > _zenGiveUpAt }
				};
			};

			// manual fly-past, only runs if ZEN's waypoint has not already dropped them
			if (alive _vehicle && { call _fnc_cargoAboard > 0 }) then {
				["[FOD_ZA_taskMobilizeQRF] Plane %1 ZEN paradrop waypoint did not drop the cargo within the window, using manual fly-past", typeOf _vehicle] call FOD_ZA_fnc_debugMessage;

				private _driver = driver _vehicle;
				private _pilotSkill = skill _driver;
				_driver setSkill 1;
				_driver allowFleeing 0;

				private _offsetDistance = 2000;
				private _moveDelay = 2;
				private _timePerUnit = 1.2;
				private _nextMove = 0;
				private _dropPosition = _targetPos;
				private _passengerCount = 0;

				// periodically push the plane's move target past the drop point so it flies over it instead of stopping there
				waitUntil {
					if (!alive _vehicle) exitWith { true };

					if (CBA_missionTime >= _nextMove) then {
						private _direction = _vehicle getDir _targetPos;
						_dropPosition = _targetPos getPos [_offsetDistance, _direction];
						_vehicle doMove _dropPosition;
						_nextMove = CBA_missionTime + _moveDelay;
					};

					sleep 0.5;

					_passengerCount = call _fnc_cargoAboard;
					_vehicle distance2D _dropPosition < (vectorMagnitude (velocity _vehicle)) * _timePerUnit * _passengerCount / 2 + _offsetDistance
				};

				if (alive _vehicle) then {
					if (_hasZenCommon) then {
						[_vehicle] call zen_common_fnc_ejectPassengers;
					} else {
						private _passengers = (crew _vehicle) select { ((assignedVehicleRole _x) select 0) == "cargo" };
						{
							private _passenger = _x;
							if (alive _passenger) then {
								unassignVehicle _passenger;
								moveOut _passenger;

								if ((getPosASL _vehicle select 2) > 30) then {
									[_passenger] spawn {
										params ["_passenger"];
										private _openTime = CBA_missionTime + 1.5;
										waitUntil {
											sleep 0.1;
											!alive _passenger || { (getPosASL _passenger select 2) < 200 && { CBA_missionTime >= _openTime } }
										};
										if (alive _passenger) then {
											private _parachute = createVehicle ["Steerable_Parachute_F", getPosASL _passenger, [], 0, "NONE"];
											_parachute setPosASL (getPosASL _passenger);
											_parachute setDir getDir _passenger;
											_parachute setVelocity velocity _passenger;
											_passenger moveInDriver _parachute;
										};
									};
								};
							};

							sleep 1.2;
						} forEach _passengers;
					};
				};

				if (alive _driver) then {
					_driver setSkill _pilotSkill;
				};
			};

			if (!alive _vehicle) exitWith {};

			// drop done: split the dropped stick into its own group now, this frees the plane to fly straight home (no longer waiting on men under canopy) and keeps the follow-up push from grabbing the plane
			private _dropped = _cargoStick select { alive _x };
			private _dropGroup = createGroup [side _group, true];
			_dropped joinSilent _dropGroup;
			_dropGroup setBehaviour "AWARE";
			_dropGroup setCombatMode "YELLOW";

			_group setCurrentWaypoint _wpHome;

			// push only once every dropped man is on the ground (altitude covers the whole descent without needing a parachute object). Bail if re-tasked or the stick is wiped out
			private _landDeadline = time + 180;
			waitUntil {
				sleep 1;
				{ alive _x } count units _dropGroup == 0
				|| { (_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen }
				|| { (units _dropGroup findIf { alive _x && { ((getPosATLVisual _x) select 2) > 6 } }) == -1 }
				|| { time > _landDeadline }
			};

			if ((_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen || { { alive _x } count units _dropGroup == 0 }) exitWith {};

			// pull any of the stick that came down in the sea onto the coast first, so they push on foot not swimming
			[_dropGroup] call FOD_ZA_fnc_pushRescueSwimmers;

			[_dropGroup, _targetPos] spawn FOD_ZA_fnc_taskTacticalPush;
		};

		// delete the plane only once it has dropped its cargo and made it home, never with troops aboard; a long safety net still cleans up a plane that never drops
		[_vehicle, _group, _homePos] spawn {
			params ["_vehicle", "_group", "_homePos"];
			private _safetyAt = CBA_missionTime + 600;
			waitUntil {
				sleep 5;
				private _cargoLeft = { ((assignedVehicleRole _x) select 0) == "cargo" } count crew _vehicle;
				!alive _vehicle
				|| { _cargoLeft == 0 && { _vehicle distance2D _homePos < 200 } }
				|| { CBA_missionTime > _safetyAt }
			};
			if (alive _vehicle) then {
				{ deleteVehicle _x } forEach (crew _vehicle);
				deleteVehicle _vehicle;
			};
		};
	} forEach _planeVehicles;

	// planes handle their own paradrop/return/cleanup above and don't take part in the arrival wait or dismount below
	_vehicles = _groundVehicles + _heliVehicles;

	// helicopters count as arrived once they're within radius and have touched down; ground vehicles use the normal move/arrival check
	private _vehicleStillEnRoute = {
		params ["_vehicle", "_targetPos", "_radius"];
		if (!alive _vehicle || { !canMove _vehicle }) exitWith { false };
		if (_vehicle isKindOf "Helicopter" && !(_vehicle isKindOf "UAV")) exitWith {
			// a transport helicopter counts as arrived once it has landed and handed passengers back, not on proximity (its pad can sit outside the reinforce radius)
			!(_vehicle getVariable ["FOD_MQ_heliReadyForDismount", false])
		};
		!(_vehicle distance2D _targetPos < _radius) && { !(moveToCompleted _vehicle) }
	};

	// only run the generic arrival/dismount when there's a ground or helicopter vehicle. With a plane-only QRF this list is empty, findIf returns -1 (all arrived) and dismount would fire instantly, clearing the paradrop waypoint before the plane flies; planes self-handle that above
	if (_vehicles isNotEqualTo []) then {
		[
			{
				params ["_group", "_targetPos", "_radius", "_taskGen", "_vehicles", "_landingPads", "_vehicleStillEnRoute", "_deadline"];
				(_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen
				|| { (_vehicles findIf { [_x, _targetPos, _radius] call _vehicleStillEnRoute }) == -1 }
				|| { time > _deadline }
			},
			{
				params ["_group", "_targetPos", "_radius", "_taskGen", "_vehicles", "_landingPads"];
				[_group, _targetPos, _radius, _taskGen, _vehicles, _landingPads] call FOD_ZA_fnc_taskMobilizeQRFDismount;
			},
			[_group, _targetPos, _radius, _taskGen, _vehicles, _landingPads, _vehicleStillEnRoute, time + 90]
		] call CBA_fnc_waitUntilAndExecute;
	};
	// a plane-only QRF has nothing to land here; each plane's drop spawn above splits off its stick, flies home, and the stick pushes the objective

	true
};

// FOD_ZA_fnc_taskMobilizeQRF step 2: on arrival, splits operable vehicles' crew into their own group and dismounts cargo, then continues into FOD_ZA_fnc_taskMobilizeQRFCover.
// example, [_group, _targetPos, _radius, _taskGen, _vehicles, _landingPads] call FOD_ZA_fnc_taskMobilizeQRFDismount
FOD_ZA_fnc_taskMobilizeQRFDismount = {
	params ["_group", "_targetPos", "_radius", "_taskGen", "_vehicles", "_landingPads"];

	{ deleteVehicle _x } forEach _landingPads;

	if ((_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen) exitWith {
		["[FOD_ZA_taskMobilizeQRF] Group %1 mobilization replaced by a newer task, exiting quietly", groupId _group] call FOD_ZA_fnc_debugMessage;
	};

	// stop the unstick watchdog as dismount begins; the parked vehicles would otherwise read as stuck and get nudged while troops are getting out
	{
		private _unstickPFH = _x getVariable ["FOD_unstickPFH", -1];
		if (_unstickPFH != -1) then {
			[_unstickPFH] call CBA_fnc_removePerFrameHandler;
			_x setVariable ["FOD_unstickPFH", nil];
		};
		if (alive _x) then { _x forceFollowRoad false; doStop _x; };
	} forEach _vehicles;

	private _crewGroups = [];
	private _cargoUnits = [];

	// dismount, splitting vehicle crew off into their own group if the vehicle is still operable
	{
		private _vehicle = _x;
		private _mountedUnits = units _group select { alive _x && { vehicle _x == _vehicle } };

		if (_mountedUnits isNotEqualTo []) then {
			private _crewUnits = [];
			private _vehicleCargoUnits = _mountedUnits;

			if (alive _vehicle && { canMove _vehicle }) then {
				private _crewRoles = ["driver", "gunner", "turret", "commander"];
				_crewUnits = _mountedUnits select { (toLower ((assignedVehicleRole _x) param [0, ""])) in _crewRoles };
				_vehicleCargoUnits = _mountedUnits - _crewUnits;

				if (_vehicleCargoUnits isEqualTo []) then {
					_vehicleCargoUnits = _mountedUnits;
					_crewUnits = [];
				};
			};

			if (_crewUnits isNotEqualTo []) then {
				private _crewGroup = createGroup [side _group, true];
				{
					[_x] call FOD_ZA_fnc_pushRestoreUnit;
					[_x] joinSilent _crewGroup;
				} forEach _crewUnits;
				_crewGroup setBehaviour "AWARE";
				_crewGroup setCombatMode "YELLOW";
				_crewGroup setSpeedMode "NORMAL";
				_crewGroups pushBack _crewGroup;
				["[FOD_ZA_taskMobilizeQRF] Group %1 split off vehicle crew (%2 unit(s)) into group %3", groupId _group, count _crewUnits, groupId _crewGroup] call FOD_ZA_fnc_debugMessage;
			};

			_group leaveVehicle _vehicle;

			// instantly bail out, no animated getting-out delay
			_vehicleCargoUnits allowGetIn false;
			[_vehicleCargoUnits, _vehicle] spawn {
				params ["_cargoUnits", "_vehicle"];
				if (isClass (configFile >> "CfgPatches" >> "zen_common")) then {
					[_vehicle] call zen_common_fnc_ejectPassengers;
				} else {
					{
						unassignVehicle _x;
						_x moveOut _vehicle;
						sleep (random 1);
					} forEach _cargoUnits;
				};
			};

			_cargoUnits append _vehicleCargoUnits;
		};
	} forEach _vehicles;

	if (_cargoUnits isEqualTo []) exitWith {
		[_group, _taskGen, _crewGroups, _targetPos] call FOD_ZA_fnc_taskMobilizeQRFFinish;
	};

	[
		{
			params ["_group", "_targetPos", "_radius", "_taskGen", "_vehicles", "_cargoUnits", "_crewGroups", "_deadline"];
			({ alive _x && { (vehicle _x) in _vehicles } } count _cargoUnits) == 0 || { time > _deadline }
		},
		{
			params ["_group", "_targetPos", "_radius", "_taskGen", "_vehicles", "_cargoUnits", "_crewGroups"];
			_cargoUnits allowGetIn true;
			[_group, _taskGen, _crewGroups, _targetPos] call FOD_ZA_fnc_taskMobilizeQRFCover;
		},
		[_group, _targetPos, _radius, _taskGen, _vehicles, _cargoUnits, _crewGroups, time + 30]
	] call CBA_fnc_waitUntilAndExecute;
};

// FOD_ZA_fnc_taskMobilizeQRF step 3: sends dismounted units to cover and waits for them to settle, then continues into FOD_ZA_fnc_taskMobilizeQRFFinish.
// example, [_group, _taskGen, _crewGroups] call FOD_ZA_fnc_taskMobilizeQRFCover
FOD_ZA_fnc_taskMobilizeQRFCover = {
	params ["_group", "_taskGen", "_crewGroups", ["_targetPos", []]];

	private _movingUnits = [];
	{
		if (alive _x && { vehicle _x == _x }) then {
			private _coverPos = [_x, 50, []] call FOD_ZA_fnc_pushFindCover;
			if (_coverPos isNotEqualTo []) then {
				_x doMove _coverPos;
				_movingUnits pushBack [_x, _coverPos];
			};
		};
	} forEach (units _group select { alive _x });

	if (_movingUnits isEqualTo []) exitWith {
		[_group, _taskGen, _crewGroups, _targetPos] call FOD_ZA_fnc_taskMobilizeQRFFinish;
	};

	[
		{
			params ["_group", "_taskGen", "_crewGroups", "_movingUnits", "_deadline", "_targetPos"];
			(_movingUnits findIf {
				_x params ["_unit", "_coverPos"];
				alive _unit && { (_unit distance2D _coverPos) > 3 } && { !(moveToCompleted _unit) }
			}) == -1
			|| { time > _deadline }
		},
		{
			params ["_group", "_taskGen", "_crewGroups", "_movingUnits", "_deadline", "_targetPos"];
			[_group, _taskGen, _crewGroups, _targetPos] call FOD_ZA_fnc_taskMobilizeQRFFinish;
		},
		[_group, _taskGen, _crewGroups, _movingUnits, time + 10, _targetPos]
	] call CBA_fnc_waitUntilAndExecute;
};

// FOD_ZA_fnc_taskMobilizeQRF final step: restores AI, then dismounted infantry push the objective and armed transports stay on as Support Vehicles, else hands off.
// example, [_group, _taskGen, _crewGroups] call FOD_ZA_fnc_taskMobilizeQRFFinish
FOD_ZA_fnc_taskMobilizeQRFFinish = {
	params ["_group", "_taskGen", "_crewGroups", ["_targetPos", []]];

	if ((_group getVariable ["FOD_MQ_taskGen", 0]) != _taskGen) exitWith {
		["[FOD_ZA_taskMobilizeQRF] Group %1 mobilization replaced by a newer task, exiting quietly", groupId _group] call FOD_ZA_fnc_debugMessage;
	};

	[_group] call FOD_ZA_fnc_pushRestoreUnits;

	// follow-up, the dismounted infantry push the objective rather than just stand in cover; plain handoff if there's no target or nobody on foot
	private _dismountedInfantry = (units _group) select { alive _x && { vehicle _x == _x } };
	if (_targetPos isNotEqualTo [] && { _dismountedInfantry isNotEqualTo [] }) then {
		["[FOD_ZA_taskMobilizeQRF] Group %1 dismounted, pushing the objective at %2", groupId _group, _targetPos] call FOD_ZA_fnc_debugMessage;
		[_group, _targetPos] spawn FOD_ZA_fnc_taskTacticalPush;
	} else {
		[_group] call FOD_ZA_fnc_pushHandoffGroup;
	};

	// follow-up, an armed ground vehicle stays on as a Support Vehicle for the delivered group; air and unarmed transports are handed back to normal AI
	{
		private _crewGroup = _x;
		private _crewVehicle = vehicle (leader _crewGroup);
		private _isMounted = _crewVehicle != (leader _crewGroup);
		private _offensiveWeapons = (weapons _crewVehicle) select {
			private _wpnLower = toLower _x;
			((_wpnLower find "cmflare") < 0) && { (_wpnLower find "smokelauncher") < 0 } && { (_wpnLower find "chaff") < 0 }
		};
		private _isArmedGround = _isMounted && { !(_crewVehicle isKindOf "Air") } && { _offensiveWeapons isNotEqualTo [] };

		if (_isArmedGround && { _targetPos isNotEqualTo [] }) then {
			["[FOD_ZA_taskMobilizeQRF] Group %1 armed transport %2 staying on as Support Vehicle", groupId _crewGroup, typeOf _crewVehicle] call FOD_ZA_fnc_debugMessage;
			[_crewGroup, _targetPos] call FOD_ZA_fnc_taskSupportVehicleToggle;
		} else {
			[_crewGroup] call FOD_ZA_fnc_pushHandoffGroup;
		};
	} forEach _crewGroups;

	[format ["Mobilize QRF: %1 has arrived and is reinforcing the area.", groupId _group]] call FOD_ZA_fnc_curatorFeedback;
};

// Cancels a running Support Vehicle task and restores normal AI, safe when none is running.
// example, [_group] call FOD_ZA_fnc_taskSupportVehicleCancel
FOD_ZA_fnc_taskSupportVehicleCancel = {
	params [["_group", grpNull, [grpNull, objNull]]];
	if (_group isEqualType objNull) then { _group = group _group; };
	if (isNull _group) exitWith {};

	_group setVariable ["FOD_SV_taskGen", (_group getVariable ["FOD_SV_taskGen", 0]) + 1];
	_group setVariable ["FOD_SV_active", nil, true];

	["[FOD_ZA_taskSupportVehicle] Group %1 support cancelled, restoring AI control", groupId _group] call FOD_ZA_fnc_debugMessage;

	[_group] call FOD_ZA_fnc_pushHandoffGroup;

	[format ["Support Vehicle cancelled for group %1", groupId _group]] call FOD_ZA_fnc_curatorFeedback;
};

// Starts a Support Vehicle task on a group, or cancels an already-running one if reapplied to the same group.
// example, [_group, _targetPos, 60] call FOD_ZA_fnc_taskSupportVehicleToggle
FOD_ZA_fnc_taskSupportVehicleToggle = {
	params [
		["_group", grpNull, [grpNull, objNull]],
		["_targetPos", [], [[], objNull]],
		["_followDistance", 50, [0]]
	];

	if (_group isEqualType objNull) then { _group = group _group; };
	if (isNull _group) exitWith { false };

	// the group's AI and loop must run where the group is local, so a Zeus curator on another machine hands the toggle off there instead of silently no-opping. groupOwner, not owner, since owner only resolves on the server
	if (!local _group) exitWith {
		// groupOwner returns 0 when the group isn't network-synced here yet (e.g. spawned by another Zeus); 0 isn't a valid remoteExec target on a non-dedicated host, so fall back to the server
		private _owner = groupOwner _group;
		if (_owner == 0) then { _owner = 2; };
		[_group, _targetPos, _followDistance] remoteExec ["FOD_ZA_fnc_taskSupportVehicleToggle", _owner];
	};

	// debounce, so duplicate remoteExec hops or double clicks don't rapidly start then cancel the task
	private _now = time;
	if ((_now - (_group getVariable ["FOD_SV_lastToggle", -1000])) < 1) exitWith { false };
	_group setVariable ["FOD_SV_lastToggle", _now];

	if (_group getVariable ["FOD_SV_active", false]) exitWith {
		[_group] call FOD_ZA_fnc_taskSupportVehicleCancel;
	};

	[format ["Support Vehicle started for group %1", groupId _group]] call FOD_ZA_fnc_curatorFeedback;
	[_group, _targetPos, _followDistance] spawn FOD_ZA_fnc_taskSupportVehicle;
};

// Sends a vehicle group to support the nearest ally in need: drives to the area, then follows and fires from behind without overtaking. Holds if no ally, releases on death or immobilisation.
// example, [_group, _targetPos, 60] spawn FOD_ZA_fnc_taskSupportVehicle
FOD_ZA_fnc_taskSupportVehicle = {
	params [
		["_group", grpNull, [grpNull, objNull]],
		["_targetPos", [], [[], objNull]],
		["_followDistance", 50, [0]]
	];

	if (_group isEqualType objNull) then { _group = group _group; };
	if (!local _group) exitWith { false };

	if (_targetPos isEqualType objNull) then { _targetPos = getPosATL _targetPos; };
	if (_targetPos isEqualTo []) exitWith { false };

	private _vehicle = vehicle (leader _group);
	if (_vehicle == (leader _group)) exitWith {
		["[FOD_ZA_taskSupportVehicle] Group %1 leader is not mounted, Support Vehicle requires a vehicle group", groupId _group] call FOD_ZA_fnc_debugMessage;
		_group setVariable ["FOD_SV_active", nil, true];
		false
	};

	{
		_x setVariable ["lambs_danger_enableGroupReinforce", true, true];
		_x setVariable ["lambs_danger_dangerRadio", true, true];
	} forEach (units _group);

	["[FOD_ZA_taskSupportVehicle] Group %1 supporting toward %2, follow distance=%3m", groupId _group, _targetPos, _followDistance] call FOD_ZA_fnc_debugMessage;

	// generation counter, a fresh call replaces a still-running one on this group
	private _taskGen = (_group getVariable ["FOD_SV_taskGen", 0]) + 1;
	_group setVariable ["FOD_SV_taskGen", _taskGen];
	_group setVariable ["FOD_SV_active", true, true];

	private _isAir = _vehicle isKindOf "Air" && !(_vehicle isKindOf "UAV");

	// move to the target area, then into the anchor/follow phase (FOD_ZA_fnc_taskSupportVehicleAnchor for ground, FOD_ZA_fnc_taskSupportVehicleAirAnchor for aircraft)
	// always on the highest open-fire ROE (RED, open fire + engage at will / break formation) so the support vehicle engages from the off, including during the move in
	_vehicle setBehaviour "AWARE";
	_vehicle setCombatMode "RED";
	_vehicle setSpeedMode "FULL";
	if (_isAir) then {
		if (_vehicle isKindOf "Helicopter") then {
			_vehicle flyInHeight 15;
		};
	} else {
		_vehicle forceFollowRoad true;
	};
	_vehicle doMove _targetPos;
	if (!_isAir) then {
		[_vehicle, _group, "FOD_SV_taskGen", _taskGen] call FOD_ZA_fnc_pushUnstickVehicle;
	};

	[
		{
			params ["_group", "_vehicle", "_targetPos", "_followDistance", "_taskGen", "_isAir", "_deadline"];
			(_group getVariable ["FOD_SV_taskGen", 0]) != _taskGen
			|| !alive _vehicle
			|| { !canMove _vehicle }
			|| { _vehicle distance2D _targetPos < _followDistance }
			|| (moveToCompleted _vehicle)
			|| { time > _deadline }
		},
		{
			params ["_group", "_vehicle", "_targetPos", "_followDistance", "_taskGen", "_isAir"];
			if (_isAir) then {
				[_group, _vehicle, _targetPos, _followDistance, _taskGen] call FOD_ZA_fnc_taskSupportVehicleAirAnchor;
			} else {
				[_group, _vehicle, _targetPos, _followDistance, _taskGen] call FOD_ZA_fnc_taskSupportVehicleAnchor;
			};
		},
		[_group, _vehicle, _targetPos, _followDistance, _taskGen, _isAir, time + 90]
	] call CBA_fnc_waitUntilAndExecute;

	true
};

// FOD_ZA_fnc_taskSupportVehicle ground continuation: finds the ally to support and runs a PFH keeping the vehicle behind it (never overtaking) and suppressing enemies, until cancelled or the vehicle is lost.
// example, [_group, _vehicle, _targetPos, _followDistance, _taskGen] call FOD_ZA_fnc_taskSupportVehicleAnchor
FOD_ZA_fnc_taskSupportVehicleAnchor = {
	params ["_group", "_vehicle", "_targetPos", "_followDistance", "_taskGen"];

	if ((_group getVariable ["FOD_SV_taskGen", 0]) != _taskGen) exitWith {
		["[FOD_ZA_taskSupportVehicle] Group %1 support replaced by a newer task, exiting quietly", groupId _group] call FOD_ZA_fnc_debugMessage;
	};

	if (!alive _vehicle || { !canMove _vehicle }) exitWith {
		[_group] call FOD_ZA_fnc_taskSupportVehicleCancel;
	};

	// stop the unstick watchdog now the vehicle has reached its first anchor; a parked support vehicle would otherwise read as stuck and get nudged while holding position
	private _unstickPFH = _vehicle getVariable ["FOD_unstickPFH", -1];
	if (_unstickPFH != -1) then {
		[_unstickPFH] call CBA_fnc_removePerFrameHandler;
		_vehicle setVariable ["FOD_unstickPFH", nil];
	};

	_vehicle forceFollowRoad false;
	doStop _vehicle;

	// find the allied group to support near the target area
	private _anchorGroup = ([_group, _targetPos] call FOD_ZA_fnc_findNearestAllyPos) select 1;

	if (isNull _anchorGroup) then {
		["[FOD_ZA_taskSupportVehicle] Group %1 found no allies to support near %2, holding position", groupId _group, _targetPos] call FOD_ZA_fnc_debugMessage;
	} else {
		["[FOD_ZA_taskSupportVehicle] Group %1 anchoring onto group %2", groupId _group, groupId _anchorGroup] call FOD_ZA_fnc_debugMessage;
	};

	_vehicle setBehaviour "AWARE";
	_vehicle setCombatMode "RED";

	// persistent support handler: re-checks the anchor's position each interval and repositions behind it, never overtaking, until cancelled or the vehicle is lost
	[
		{
			params ["_args", "_pfhId"];
			_args params ["_group", "_vehicle", "_targetPos", "_followDistance", "_taskGen", "_anchorGroup"];

			private _taskGenChanged = (_group getVariable ["FOD_SV_taskGen", 0]) != _taskGen;
			private _groupEmpty = { alive _x } count units _group == 0;
			private _vehicleLost = !alive _vehicle || { !canMove _vehicle };

			if (_taskGenChanged || _groupEmpty || _vehicleLost) exitWith {
				[_pfhId] call CBA_fnc_removePerFrameHandler;

				if (_taskGenChanged) then {
					["[FOD_ZA_taskSupportVehicle] Group %1 support replaced by a newer task, exiting quietly", groupId _group] call FOD_ZA_fnc_debugMessage;
				} else {
					if (_groupEmpty) then {
						_group setVariable ["FOD_SV_active", nil, true];
					} else {
						// vehicle was destroyed or immobilised, release the group back to normal AI
						[_group] call FOD_ZA_fnc_taskSupportVehicleCancel;
					};
				};
			};

			_vehicle setBehaviour "AWARE";
			_vehicle setCombatMode "RED";

			if (!isNull _anchorGroup && { { alive _x } count units _anchorGroup > 0 }) then {
				private _anchorPos = getPosATL (leader _anchorGroup);
				private _anchorSide = side _anchorGroup;
				private _hasKnownEnemy = (allUnits findIf { alive _x && { [_anchorSide, side _x] call BIS_fnc_sideIsEnemy } }) != -1;
				private _enemyPos = if (_hasKnownEnemy) then {
					[_anchorGroup, _anchorPos] call FOD_ZA_fnc_findNearestEnemyPos
				} else {
					[]
				};

				// suppress the nearest known enemy within range, one burst at a time, never overlapping a burst already in progress
				if (_hasKnownEnemy && { !(_vehicle getVariable ["FOD_SV_firing", false]) }) then {
					private _enemyCandidates = allUnits select {
						alive _x
						&& { [_anchorSide, side _x] call BIS_fnc_sideIsEnemy }
						&& { _vehicle distance _x < 500 }
					};

					if (_enemyCandidates isNotEqualTo []) then {
						private _sortedEnemies = [_enemyCandidates, [], { _vehicle distance (getPosATL _x) }, "ASCEND"] call BIS_fnc_sortBy;
						private _enemyUnit = _sortedEnemies select 0;

						_vehicle setVariable ["FOD_SV_firing", true];
						[_vehicle, _enemyUnit] spawn {
							params ["_vehicle", "_enemyUnit"];
							[_vehicle, _enemyUnit] call FOD_ZA_fnc_pushFireVehicle;
							_vehicle setVariable ["FOD_SV_firing", false];
						};
					};
				};

				private _desiredPos = [];

				// with a known threat, seek a firing position that can see it: a spot within follow range with line of sight, else an overwatch position from BIS_fnc_findOverwatch
				if (_enemyPos isNotEqualTo []) then {
					_desiredPos = [_anchorPos, _enemyPos, _vehicle, _followDistance] call FOD_ZA_fnc_findSupportFirePos;
				};

				// no threat, or nothing usable found, hold behind the ally facing where the threat would be
				if (_desiredPos isEqualTo []) then {
					private _dirAway = if (_enemyPos isNotEqualTo []) then {
						([_anchorPos, _enemyPos] call BIS_fnc_dirTo) + 180
					} else {
						getDir (leader _anchorGroup)
					};
					_desiredPos = [_anchorPos, _followDistance, _dirAway] call FOD_ZA_fnc_pushOffsetPos;
				};

				if ((_vehicle distance2D _desiredPos) > 15) then {
					_vehicle doMove _desiredPos;
				};
			} else {
				// no allies left to support, hold position and keep watching for a new group in need
				if (!(moveToCompleted _vehicle) && { (speed _vehicle) > 1 }) then {
					doStop _vehicle;
				};

				private _newAnchorGroup = ([_group, _targetPos] call FOD_ZA_fnc_findNearestAllyPos) select 1;
				if (!isNull _newAnchorGroup) then {
					_args set [5, _newAnchorGroup];
					["[FOD_ZA_taskSupportVehicle] Group %1 found a new ally to support, group %2", groupId _group, groupId _newAnchorGroup] call FOD_ZA_fnc_debugMessage;
				};
			};
		},
		10,
		[_group, _vehicle, _targetPos, _followDistance, _taskGen, _anchorGroup]
	] call CBA_fnc_addPerFrameHandler;
};

// FOD_ZA_fnc_taskSupportVehicle air continuation: keeps the aircraft on station over the ally, loitering when no enemy is near and switching to Search and Destroy when one is. Helicopters held at 15m.
// example, [_group, _vehicle, _targetPos, _followDistance, _taskGen] call FOD_ZA_fnc_taskSupportVehicleAirAnchor
FOD_ZA_fnc_taskSupportVehicleAirAnchor = {
	params ["_group", "_vehicle", "_targetPos", "_followDistance", "_taskGen"];

	if ((_group getVariable ["FOD_SV_taskGen", 0]) != _taskGen) exitWith {
		["[FOD_ZA_taskSupportVehicle] Group %1 support replaced by a newer task, exiting quietly", groupId _group] call FOD_ZA_fnc_debugMessage;
	};

	if (!alive _vehicle || { !canMove _vehicle }) exitWith {
		[_group] call FOD_ZA_fnc_taskSupportVehicleCancel;
	};

	private _isHelicopter = _vehicle isKindOf "Helicopter";
	if (_isHelicopter) then {
		_vehicle flyInHeight 15;
	};

	_vehicle setBehaviour "AWARE";
	_vehicle setCombatMode "RED";

	private _anchorGroup = ([_group, _targetPos] call FOD_ZA_fnc_findNearestAllyPos) select 1;
	if (!isNull _anchorGroup) then {
		["[FOD_ZA_taskSupportVehicle] Group %1 anchoring onto group %2", groupId _group, groupId _anchorGroup] call FOD_ZA_fnc_debugMessage;
	} else {
		["[FOD_ZA_taskSupportVehicle] Group %1 found no allies to support near %2, loitering", groupId _group, _targetPos] call FOD_ZA_fnc_debugMessage;
	};

	private _stationPos = if (!isNull _anchorGroup) then { getPosATL (leader _anchorGroup) } else { _targetPos };

	[_group] call CBA_fnc_clearWaypoints;
	private _wp = _group addWaypoint [ATLtoASL _stationPos, -1];
	_wp setWaypointType "LOITER";
	_wp setWaypointLoiterType "CIRCLE_L";
	_wp setWaypointLoiterRadius _followDistance;
	_wp setWaypointSpeed "UNCHANGED";

	// persistent station-keeping handler: loiters over the ally, switches to Search and Destroy when an enemy is known nearby, until cancelled or the aircraft is lost
	[
		{
			params ["_args", "_pfhId"];
			_args params ["_group", "_vehicle", "_targetPos", "_followDistance", "_taskGen", "_anchorGroup", "_isHelicopter", "_loitering", "_lastStationPos"];

			private _taskGenChanged = (_group getVariable ["FOD_SV_taskGen", 0]) != _taskGen;
			private _groupEmpty = { alive _x } count units _group == 0;
			private _vehicleLost = !alive _vehicle || { !canMove _vehicle };

			if (_taskGenChanged || _groupEmpty || _vehicleLost) exitWith {
				[_pfhId] call CBA_fnc_removePerFrameHandler;
				[_group] call CBA_fnc_clearWaypoints;

				if (_taskGenChanged) then {
					["[FOD_ZA_taskSupportVehicle] Group %1 support replaced by a newer task, exiting quietly", groupId _group] call FOD_ZA_fnc_debugMessage;
				} else {
					if (_groupEmpty) then {
						_group setVariable ["FOD_SV_active", nil, true];
					} else {
						[_group] call FOD_ZA_fnc_taskSupportVehicleCancel;
					};
				};
			};

			if (_isHelicopter) then {
				_vehicle flyInHeight 15;
			};

			// keep the aircraft pinned to the highest open-fire ROE every cycle, in case a waypoint or AI system lowered it
			_vehicle setBehaviour "AWARE";
			_vehicle setCombatMode "RED";

			if (!isNull _anchorGroup && { { alive _x } count units _anchorGroup == 0 }) then {
				_anchorGroup = grpNull;
			};

			if (isNull _anchorGroup) then {
				_anchorGroup = ([_group, _targetPos] call FOD_ZA_fnc_findNearestAllyPos) select 1;
				if (!isNull _anchorGroup) then {
					_args set [5, _anchorGroup];
					["[FOD_ZA_taskSupportVehicle] Group %1 found a new ally to support, group %2", groupId _group, groupId _anchorGroup] call FOD_ZA_fnc_debugMessage;
				};
			};

			private _stationPos = if (!isNull _anchorGroup) then { getPosATL (leader _anchorGroup) } else { _targetPos };
			private _anchorSide = if (!isNull _anchorGroup) then { side _anchorGroup } else { side _group };
			private _searchRadius = _followDistance * 3;
			private _hasKnownEnemy = (allUnits findIf {
				alive _x && { [_anchorSide, side _x] call BIS_fnc_sideIsEnemy } && { _x distance2D _stationPos < _searchRadius }
			}) != -1;

			private _modeSwitched = false;

			if (_hasKnownEnemy && _loitering) then {
				[_group] call CBA_fnc_clearWaypoints;
				private _wp = _group addWaypoint [ATLtoASL _stationPos, -1];
				_wp setWaypointType "SAD";
				_wp setWaypointCompletionRadius _searchRadius;
				_wp setWaypointSpeed "FULL";
				_args set [7, false];
				_modeSwitched = true;
			};

			if (!_hasKnownEnemy && !_loitering) then {
				[_group] call CBA_fnc_clearWaypoints;
				private _wp = _group addWaypoint [ATLtoASL _stationPos, -1];
				_wp setWaypointType "LOITER";
				_wp setWaypointLoiterType "CIRCLE_L";
				_wp setWaypointLoiterRadius _followDistance;
				_wp setWaypointSpeed "UNCHANGED";
				_args set [7, true];
				_modeSwitched = true;
			};

			// the supported group keeps moving, so the loiter/SAD waypoint needs to follow it rather than staying put
			if (!_modeSwitched && { _stationPos distance2D _lastStationPos > (_followDistance / 2) }) then {
				[_group, 0] setWaypointPosition [ATLtoASL _stationPos, -1];
			};

			_args set [8, _stationPos];
		},
		10,
		[_group, _vehicle, _targetPos, _followDistance, _taskGen, _anchorGroup, _isHelicopter, true, _stationPos]
	] call CBA_fnc_addPerFrameHandler;
};
