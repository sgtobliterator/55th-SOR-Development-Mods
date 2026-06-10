// =====================================================================
// GEA_fnc_spawnVehiclePatrol
//   Spawns ONE ground vehicle + crew (+ optional cargo fireteam) and
//   gives the vehicle's group a patrol task around the AO.
//
//   v0.7.0 changes:
//     - Type selection is now driven by the orchestrator: caller passes
//       _wantType in ("car" | "apc" | "tank"). The orchestrator rolls
//       the type using the user's % sliders (auto-normalized) and asks
//       this spawner for one of that kind. The old hardcoded 70/20/10
//       weight inside this function is gone.
//     - If the requested bucket is empty, we fall through to the other
//       non-empty buckets in order (car → apc → tank) — same fallback
//       behaviour as before, just driven from outside.
//
//   Pool source — two tier:
//     TIER 1: faction-matched vehicles (keeps the theme)
//     TIER 2: side-matched   vehicles (fallback)
//
//   Returns: [_vehicle, _crewGroup, _cargoGroup, _actualType]
// =====================================================================

#include "..\..\script_component.hpp"

if (!isServer) exitWith { [objNull, grpNull, grpNull, ""] };

params [
    ["_aoConfig", createHashMap, [createHashMap]],
    ["_wantType", "car",         [""]]
];

private _center  = _aoConfig get "center";
private _radius  = _aoConfig get "radius";
private _side    = _aoConfig get "side";
private _faction = _aoConfig get "faction";
private _skill   = _aoConfig get "skill";
private _aoId    = _aoConfig get "id";

private _say = {
    params ["_msg"];
    diag_log text format ["[GEA] veh: %1", _msg];
};

// CfgVehicles "side" numeric.
private _sideNum = switch (_side) do {
    case east:        { 0 };
    case west:        { 1 };
    case independent: { 2 };
    case civilian:    { 3 };
    default           { -1 };
};

// ---------------------------------------------------------------------
// Classify a vehicle config into "car" / "apc" / "tank".
//   Editor subcategory is the most reliable signal (mods set it). For
//   anything that doesn't, we fall back to the inheritance tree:
//     Wheeled APC → apc, Tracked Tank/IFV → tank or apc.
// ---------------------------------------------------------------------
private _fnc_classify = {
    params ["_class", "_cfg"];

    private _sub = getText (_cfg >> "editorSubcategory");
    switch (true) do {
        case (_sub == "EdSubcat_Tanks"):  { "tank" };
        case (_sub == "EdSubcat_APCs"):   { "apc" };
        case (_sub == "EdSubcat_IFVs"):   { "apc" };
        case (_sub == "EdSubcat_Cars"):   { "car" };
        case (_sub == "EdSubcat_Trucks"): { "car" };
        default {
            if (_class isKindOf "Tank") then {
                "tank"
            } else {
                if (_class isKindOf "Wheeled_APC_F") then { "apc" } else { "car" }
            }
        };
    };
};

// ---------------------------------------------------------------------
// Build pools.  Iterate CfgVehicles once, bucket into faction/side ×
// car/apc/tank.
// ---------------------------------------------------------------------
private _faction_car  = [];
private _faction_apc  = [];
private _faction_tank = [];
private _side_car     = [];
private _side_apc     = [];
private _side_tank    = [];

{
    private _cfg   = _x;
    private _class = configName _cfg;

    if (getNumber (_cfg >> "scope") >= 2
        && { (_class isKindOf "Car") || (_class isKindOf "Tank") }
        && { !(_class isKindOf "ParachuteBase") }
        && { !(_class isKindOf "StaticWeapon") }
    ) then {
        private _vehSide    = getNumber (_cfg >> "side");
        private _vehFaction = getText   (_cfg >> "faction");
        private _cat        = [_class, _cfg] call _fnc_classify;

        if (_vehFaction == _faction) then {
            switch (_cat) do {
                case "car":  { _faction_car  pushBack _class };
                case "apc":  { _faction_apc  pushBack _class };
                case "tank": { _faction_tank pushBack _class };
            };
        };
        if (_vehSide == _sideNum) then {
            switch (_cat) do {
                case "car":  { _side_car  pushBack _class };
                case "apc":  { _side_apc  pushBack _class };
                case "tank": { _side_tank pushBack _class };
            };
        };
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));

// Tier select: faction first if it has ANY vehicle, otherwise side.
private _cars  = [];
private _apcs  = [];
private _tanks = [];
private _poolTier = "";

private _factionTotal = (count _faction_car) + (count _faction_apc) + (count _faction_tank);
private _sideTotal    = (count _side_car)    + (count _side_apc)    + (count _side_tank);

if (_factionTotal > 0) then {
    _cars     = _faction_car;
    _apcs     = _faction_apc;
    _tanks    = _faction_tank;
    _poolTier = "faction";
} else {
    if (_sideTotal > 0) then {
        _cars     = _side_car;
        _apcs     = _side_apc;
        _tanks    = _side_tank;
        _poolTier = "side-fallback";
    };
};

[format ["pool tier=%1 cars=%2 apcs=%3 tanks=%4 want=%5",
    _poolTier, count _cars, count _apcs, count _tanks, _wantType]] call _say;

if ((count _cars) + (count _apcs) + (count _tanks) == 0) exitWith {
    ["NO vehicles found for faction OR side — skipping."] call _say;
    [objNull, grpNull, grpNull, ""]
};

// ---------------------------------------------------------------------
// Pick from the requested bucket. Fall through to non-empty buckets
// in order (car → apc → tank) if the requested one is empty.
// ---------------------------------------------------------------------
private _picked     = "";
private _actualType = "";

private _fallback = ["car", "apc", "tank"];
private _tryOrder = [_wantType] + (_fallback select { _x != _wantType });

{
    private _bucket = switch (_x) do {
        case "car":  { _cars };
        case "apc":  { _apcs };
        case "tank": { _tanks };
        default      { [] };
    };
    if (count _bucket > 0) exitWith {
        _picked     = selectRandom _bucket;
        _actualType = _x;
    };
} forEach _tryOrder;

if (_picked == "") exitWith {
    ["all buckets empty after fallback — shouldn't happen."] call _say;
    [objNull, grpNull, grpNull, ""]
};

private _class = _picked;
[format ["picked %1 (want=%2 got=%3)", _class, _wantType, _actualType]] call _say;

// ---------------------------------------------------------------------
// Spawn position — prefer a road, validate clearance + spacing.
// ---------------------------------------------------------------------
private _clearance  = ((sizeOf _class) max 4) + 2;
private _minSpacing = 30;
private _spawnPos   = [];
private _spawnDir   = random 360;

private _prior = _aoConfig getOrDefault ["vehicleSpawns", []];

private _isClear = {
    params ["_p"];
    if (surfaceIsWater _p) exitWith { false };
    if (!((nearestObjects [_p, ["Building","House","Wall","Static"], _clearance]) isEqualTo [])) exitWith {
        false
    };
    private _tooClose = false;
    {
        if ((_p distance2D _x) < _minSpacing) exitWith { _tooClose = true };
    } forEach _prior;
    !_tooClose
};

private _roads = (_center nearRoads _radius) call BIS_fnc_arrayShuffle;
{
    private _candidate = getPosATL _x;
    if ([_candidate] call _isClear) exitWith {
        _spawnPos = _candidate;
        _spawnDir = getDir _x;
    };
} forEach _roads;

if (_spawnPos isEqualTo []) then {
    for "_try" from 1 to 32 do {
        private _candidate = _center getPos [random _radius, random 360];
        if ([_candidate] call _isClear) exitWith {
            _spawnPos = _candidate;
        };
    };
};

if (_spawnPos isEqualTo []) exitWith {
    [format ["no clear spawn position (clearance %1m, spacing %2m from %3 prior).",
        _clearance, _minSpacing, count _prior]] call _say;
    [objNull, grpNull, grpNull, ""]
};

_prior pushBack _spawnPos;
_aoConfig set ["vehicleSpawns", _prior];

// ---------------------------------------------------------------------
// Create vehicle + crew.
// ---------------------------------------------------------------------
private _veh = createVehicle [_class, _spawnPos, [], 0, "NONE"];
if (isNull _veh) exitWith {
    [format ["createVehicle returned null for %1", _class]] call _say;
    [objNull, grpNull, grpNull, ""]
};
_veh setDir _spawnDir;
_veh setPos _spawnPos;

private _crewGroup = createVehicleCrew _veh;
if (isNull _crewGroup || { (units _crewGroup) isEqualTo [] }) exitWith {
    [format ["crew creation failed for %1", _class]] call _say;
    deleteVehicle _veh;
    [objNull, grpNull, grpNull, ""]
};
if ((side _crewGroup) != _side) then {
    [_crewGroup] joinSilent (createGroup [_side, true]);
};
{ _x setSkill _skill } forEach (units _crewGroup);

// ---------------------------------------------------------------------
// Optional cargo fireteam — only for cars/APCs with cargo seats >= 4.
// Skip tanks: their cargo seats are usually 0.
// ---------------------------------------------------------------------
private _cargoGroup = grpNull;
private _capacity   = (_veh emptyPositions "cargo");

if (_capacity >= 4) then {
    private _infantryClasses = _aoConfig getOrDefault ["infantryClasses", []];
    if (!(_infantryClasses isEqualTo [])) then {
        _cargoGroup = createGroup [_side, true];
        private _crewSize = (_capacity min 4);   // load a small fireteam
        for "_i" from 1 to _crewSize do {
            private _ic = selectRandom _infantryClasses;
            private _u = _cargoGroup createUnit [_ic, _spawnPos, [], 0, "NONE"];
            if (!isNull _u) then {
                _u setSkill _skill;
                _u assignAsCargo _veh;
                _u moveInCargo _veh;
            };
        };
        [format ["+ cargo fireteam: %1 units", count (units _cargoGroup)]] call _say;
    };
};

// ---------------------------------------------------------------------
// Patrol behaviour.
// ---------------------------------------------------------------------
_crewGroup setBehaviour "AWARE";
_crewGroup setCombatMode "RED";
_crewGroup setSpeedMode "LIMITED";
[_crewGroup, _center, _radius] call BIS_fnc_taskPatrol;

if (!isNull _cargoGroup) then {
    _cargoGroup setBehaviour "AWARE";
    _cargoGroup setCombatMode "RED";
};

_veh setVariable ["GEA_aoId", _aoId, true];

[format ["%1 (%2) patrol started", _class, _actualType]] call _say;

[_veh, _crewGroup, _cargoGroup, _actualType]
