// =====================================================================
// GEA_fnc_spawnCivilians
//   Populates the AO with ambient INDIVIDUAL civilians. Mirrors the
//   troop model — two independent counts:
//
//     PATROL civilians  (config "civPatrol")   — placed on open ground,
//        each given a cheap 2-waypoint + cycle relaxed wander so they
//        walk around the AO.
//     GARRISON civilians (config "civGarrison") — placed inside building
//        positions and left standing. Capped by available slots.
//
//   Each civ is its own one-man group so they move independently. They
//   are civilian-side (neutral to all combat factions) and set SAFE.
//   Civilians always use 2 waypoints + cycle and ignore the global
//   "Simple Pathing" toggle — they're ambient flavour, not tactical.
//
//   Pool source — two tier:
//     TIER 1: men whose CfgVehicles `faction` == the chosen civ faction.
//     TIER 2: any civilian-side (`side` == 3) men as fallback.
//
//   Inputs:
//     _aoConfig : HashMap — reads center, radius, skill, id,
//                 civFaction (string), civPatrol, civGarrison.
//
//   Returns: array of created groups (orchestrator drains into cleanup).
// =====================================================================

#include "..\..\script_component.hpp"

if (!isServer) exitWith { [] };

params [["_aoConfig", createHashMap, [createHashMap]]];

private _center      = _aoConfig get "center";
private _radius      = _aoConfig get "radius";
private _skill       = _aoConfig get "skill";
private _aoId        = _aoConfig get "id";
private _civFaction  = _aoConfig getOrDefault ["civFaction", ""];
private _patrolN     = _aoConfig getOrDefault ["civPatrol", 0];
private _garrisonN   = _aoConfig getOrDefault ["civGarrison", 0];

private _say = {
    params ["_msg"];
    diag_log text format ["[GEA] civ: %1", _msg];
};

if (_patrolN <= 0 && _garrisonN <= 0) exitWith { [] };

// --- VR / virtual-entity reject (shared idiom) ----------------------
private _fnc_isVirtualMan = {
    params ["_cfg", "_class"];
    ((getText (_cfg >> "editorSubcategory")) == "EdSubcat_VirtualEntities")
        || { _class isKindOf "VirtualMan_F" }
        || { toLower _class find "_vr_" >= 0 }
};

// --- Build the civilian man pool ------------------------------------
private _factionMen = [];
private _sideMen    = [];
{
    private _cfg   = _x;
    private _class = configName _cfg;
    if (getNumber (_cfg >> "scope") >= 2
        && { _class isKindOf "CAManBase" }
        && { !([_cfg, _class] call _fnc_isVirtualMan) }
    ) then {
        if ((getText (_cfg >> "faction")) == _civFaction && _civFaction != "") then {
            _factionMen pushBack _class;
        };
        if ((getNumber (_cfg >> "side")) == 3) then {   // 3 = civilian
            _sideMen pushBack _class;
        };
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));

private _pool = if (count _factionMen > 0) then { _factionMen } else { _sideMen };
[format ["pool faction=%1 side=%2 -> using %3 classes", count _factionMen, count _sideMen, count _pool]] call _say;

if (_pool isEqualTo []) exitWith {
    ["NO civilian man classes found for faction OR civilian side — skipping."] call _say;
    []
};

private _created = [];

// Open-ground spawn finder (land, clear of buildings/walls).
private _fnc_openPos = {
    params ["_c", "_r"];
    private _p = [];
    for "_t" from 1 to 24 do {
        private _cand = _c getPos [random _r, random 360];
        if (!surfaceIsWater _cand
            && { (nearestObjects [_cand, ["Building","House","Wall"], 2]) isEqualTo [] }
        ) exitWith { _p = ASLToAGL (AGLToASL _cand) };
    };
    _p
};

// Spawn one civ at _pos; if _wander, give it a relaxed 2-wp + cycle loop.
private _fnc_spawnOne = {
    params ["_pos", "_wander"];
    private _grp  = createGroup [civilian, true];
    private _unit = _grp createUnit [selectRandom _pool, _pos, [], 0, "NONE"];
    if (isNull _unit) exitWith { deleteGroup _grp; grpNull };

    if (_wander) then { _unit setPosATL _pos } else { _unit setPosASL _pos };
    _unit setSkill _skill;
    _unit setVariable ["GEA_aoId", _aoId, true];
    _grp  setVariable ["GEA_aoId", _aoId, true];
    _grp setBehaviour "SAFE";
	
	_unit allowFleeing 0;
	_unit addEventHandler ["FiredNear", {
    params ["_unit", "_firer", "_distance"];
    if (_distance < 80) then {
        _unit allowFleeing 1;
        _unit removeEventHandler ["FiredNear", _thisEventHandle];
		};
	}];

    if (_wander) then {
        private _w1 = _grp addWaypoint [_center getPos [random _radius, random 360], 0];
        _w1 setWaypointType "MOVE"; _w1 setWaypointBehaviour "SAFE"; _w1 setWaypointSpeed "LIMITED";
        private _w2 = _grp addWaypoint [_center getPos [random _radius, random 360], 0];
        _w2 setWaypointType "MOVE"; _w2 setWaypointBehaviour "SAFE"; _w2 setWaypointSpeed "LIMITED";
        private _wc = _grp addWaypoint [getPosATL _unit, 0];
        _wc setWaypointType "CYCLE";
    } else {
        _unit setUnitPos "UP";   // stand in place
    };
    _grp
};

// --- PATROL civilians (wander open ground) --------------------------
private _patrolDone = 0;
for "_i" from 1 to _patrolN do {
    private _pos = [_center, _radius] call _fnc_openPos;
    if (_pos isEqualTo []) then { continue };
    private _g = [_pos, true] call _fnc_spawnOne;
    if (!isNull _g) then { _created pushBack _g; _patrolDone = _patrolDone + 1 };
};

// --- GARRISON civilians (inside buildings) --------------------------
private _garrDone = 0;
if (_garrisonN > 0) then {
    private _buildings = ([_center, _radius] call GEA_fnc_findBuildings) call BIS_fnc_arrayShuffle;
    private _slots = [];
    {
        {
            if (!(_x isEqualTo [0,0,0]) && { (_x select 2) > -5 }) then { _slots pushBack _x };
        } forEach (_x buildingPos -1);
    } forEach _buildings;
    _slots = _slots call BIS_fnc_arrayShuffle;
    [format ["garrison: %1 buildings, %2 usable slots in %3m", count _buildings, count _slots, _radius]] call _say;

    while {_garrDone < _garrisonN && {count _slots > 0}} do {
        private _pos = _slots deleteAt 0;
        private _g = [_pos, false] call _fnc_spawnOne;
        if (!isNull _g) then { _created pushBack _g; _garrDone = _garrDone + 1 };
    };
};

[format ["civilians placed — %1/%2 wandering, %3/%4 in houses.",
    _patrolDone, _patrolN, _garrDone, _garrisonN]] call _say;

_created
