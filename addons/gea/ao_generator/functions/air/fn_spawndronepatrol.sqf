// =====================================================================
// GEA_fnc_spawnDronePatrol
//   Spawns one UAV / drone patrolling the AO. Covers both rotary drones
//   (quadcopters like Darter) and fixed-wing UAVs (Greyhawk, etc.) —
//   anything with isUav = 1 qualifies.
//
//   Drones are created with createVehicle + createVehicleCrew like
//   manned aircraft, but the crew is the AI pilot wired up by the
//   engine. We assign the drone's group to the AO side so it engages
//   players, and add a UAV AI override via createVehicleCrew which
//   handles all the AI-pilot plumbing.
//
//   Two-tier pool:
//     TIER 1: faction-matched UAVs
//     TIER 2: side-matched   UAVs
//
//   Returns: [_drone, _crewGroup]
// =====================================================================

#include "..\..\script_component.hpp"

if (!isServer) exitWith { [objNull, grpNull] };

params [["_aoConfig", createHashMap, [createHashMap]]];

private _center  = _aoConfig get "center";
private _radius  = _aoConfig get "radius";
private _side    = _aoConfig get "side";
private _faction = _aoConfig get "faction";
private _skill   = _aoConfig get "skill";
private _aoId    = _aoConfig get "id";

private _say = {
    params ["_msg"];
    diag_log text format ["[GEA] drone: %1", _msg];
};

private _sideNum = switch (_side) do {
    case east:        { 0 };
    case west:        { 1 };
    case independent: { 2 };
    case civilian:    { 3 };
    default           { -1 };
};

// ---------------------------------------------------------------------
// Pool — isUav == 1. Captures Air-class drones (planes + copters).
// Excludes static / wheeled / submersible UGV by requiring Air base.
// ---------------------------------------------------------------------
private _factionPool = [];
private _sidePool    = [];

{
    private _cfg   = _x;
    private _class = configName _cfg;

    if (getNumber (_cfg >> "scope") >= 2
        && { getNumber (_cfg >> "isUav") == 1 }
        && { _class isKindOf "Air" }
        && { !(_class isKindOf "ParachuteBase") }
    ) then {
        private _vehSide    = getNumber (_cfg >> "side");
        private _vehFaction = getText   (_cfg >> "faction");

        if (_vehFaction == _faction) then { _factionPool pushBack _class };
        if (_vehSide == _sideNum)    then { _sidePool    pushBack _class };
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));

private _pool = [];
private _poolTier = "";

if (!(_factionPool isEqualTo [])) then {
    _pool = _factionPool; _poolTier = "faction";
} else {
    if (!(_sidePool isEqualTo [])) then {
        _pool = _sidePool; _poolTier = "side-fallback";
    };
};

[format ["pool tier=%1 faction=%2 side=%3", _poolTier, count _factionPool, count _sidePool]] call _say;

if (_pool isEqualTo []) exitWith {
    ["NO drones/UAVs found for faction OR side."] call _say;
    [objNull, grpNull]
};

private _class = selectRandom _pool;
[format ["picked %1", _class]] call _say;

// Detect fixed-wing vs rotary so we can pick a sensible altitude/route.
private _cfgEntry = configFile >> "CfgVehicles" >> _class;
private _isFixedWing = _class isKindOf "Plane";

// Reach capped by the matching patrol-range setting: fixed-wing UAVs use
// "Plane Patrol Range", rotary drones use "Heli Patrol Range". Defaults
// preserve the original hardcoded behaviour.
private _range       = if (_isFixedWing) then { _aoConfig getOrDefault ["planeRange", 2000] } else { _aoConfig getOrDefault ["heliRange", 1000] };
private _maxDist     = _radius + _range;
private _spawnDist   = ((_radius + 800) min _maxDist) max (_radius + 300);
private _spawnAlt    = if (_isFixedWing) then { 250 } else { 100 };
private _flyHeight   = if (_isFixedWing) then { 220 } else { 90  };
private _wpDistBase  = if (_isFixedWing) then { _radius + 600 } else { _radius + 250 };
private _wpDistJit   = if (_isFixedWing) then { 800 } else { 500 };
private _simple      = _aoConfig getOrDefault ["simplePathing", false];
private _wpCount     = if (_simple) then { 2 } else { 5 + (floor random 3) };

private _spawnPos    = _center getPos [_spawnDist, random 360];
_spawnPos set [2, _spawnAlt];

private _drone = createVehicle [_class, _spawnPos, [], 0, "FLY"];
if (isNull _drone) exitWith {
    [format ["createVehicle null for %1", _class]] call _say;
    [objNull, grpNull]
};
_drone setPosATL _spawnPos;
_drone flyInHeight _flyHeight;

// AI pilot. createVehicleCrew handles the UAV AI hookup for us.
private _crewGroup = createVehicleCrew _drone;
if (isNull _crewGroup || { (units _crewGroup) isEqualTo [] }) exitWith {
    [format ["crew creation failed for %1", _class]] call _say;
    deleteVehicle _drone;
    [objNull, grpNull]
};
if ((side _crewGroup) != _side) then {
    [_crewGroup] joinSilent (createGroup [_side, true]);
};
{ _x setSkill _skill } forEach (units _crewGroup);

// ---------------------------------------------------------------------
// Patrol waypoints.
// ---------------------------------------------------------------------
while {count (waypoints _crewGroup) > 0} do {
    deleteWaypoint ((waypoints _crewGroup) select 0);
};

private _wpPositions = [];
for "_i" from 1 to _wpCount do {
    private _angle = random 360;
    private _dist  = (_wpDistBase + (random _wpDistJit)) min _maxDist;
    _wpPositions pushBack (_center getPos [_dist, _angle]);
};

{
    private _wp = _crewGroup addWaypoint [_x, 0];
    _wp setWaypointType "MOVE";
    _wp setWaypointSpeed "NORMAL";
    _wp setWaypointBehaviour "AWARE";
    _wp setWaypointCombatMode "RED";
} forEach _wpPositions;

private _cycle = _crewGroup addWaypoint [_wpPositions select 0, 0];
_cycle setWaypointType "CYCLE";

// Forward nudge so fixed-wing drones don't stall on spawn.
if (_isFixedWing) then {
    _drone setVelocity [
        (sin (getDir _drone)) * 60,
        (cos (getDir _drone)) * 60,
        0
    ];
};

_drone setVariable ["GEA_aoId", _aoId, true];

[format ["%1 (%2) orbiting (%3 waypoints)",
    _class, (if (_isFixedWing) then {"fixed-wing"} else {"rotary"}), _wpCount]] call _say;

[_drone, _crewGroup]
