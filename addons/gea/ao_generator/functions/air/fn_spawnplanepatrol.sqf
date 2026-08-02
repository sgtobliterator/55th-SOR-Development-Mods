// =====================================================================
// GEA_fnc_spawnPlanePatrol
//   Spawns one SLOW fixed-wing aircraft (maxSpeed < 600 km/h) — prop
//   trainers, recon planes, light CAS — patrolling the AO at moderate
//   altitude.
//
//   Slow planes have a smaller turning radius than fast jets, so they
//   can use a tighter waypoint pattern (radius +400..+1200m, 4-6 wps).
//
//   Two-tier pool:
//     TIER 1: faction-matched slow planes
//     TIER 2: side-matched   slow planes
//
//   Excludes UAVs (those go through fn_spawnDronePatrol).
//
//   Returns: [_plane, _crewGroup]
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
    diag_log text format ["[GEA] plane: %1", _msg];
};

private _sideNum = switch (_side) do {
    case east:        { 0 };
    case west:        { 1 };
    case independent: { 2 };
    case civilian:    { 3 };
    default           { -1 };
};

// ---------------------------------------------------------------------
// Pool — slow fixed-wing only. Threshold matches the inverse of
// fn_spawnJetPatrol so every plane in the world falls into exactly one
// of the two pools.
// ---------------------------------------------------------------------
private _factionPool = [];
private _sidePool    = [];

{
    private _cfg   = _x;
    private _class = configName _cfg;

    if (getNumber (_cfg >> "scope") >= 2
        && { _class isKindOf "Plane" }
        && { !(_class isKindOf "ParachuteBase") }
        && { getNumber (_cfg >> "isUav") == 0 }
        // Slow-plane filter: maxSpeed > 0 AND < 600. Entries with no
        // declared maxSpeed (0) are routed to fn_spawnJetPatrol instead,
        // so we don't double-bucket them.
        && { private _ms = getNumber (_cfg >> "maxSpeed"); _ms > 0 && _ms < 600 }
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
    ["NO slow planes found for faction OR side."] call _say;
    [objNull, grpNull]
};

private _class = selectRandom _pool;
[format ["picked %1", _class]] call _say;

// ---------------------------------------------------------------------
// Spawn outside the AO, moderate altitude (lower than jets — props
// usually cruise lower).
// ---------------------------------------------------------------------
// Reach capped by the "Plane Patrol Range" setting (max distance beyond
// the AO radius). Default (2000) leaves the original behaviour unchanged.
private _range    = _aoConfig getOrDefault ["planeRange", 2000];
private _maxDist  = _radius + _range;
private _spawnDist = ((_radius + 1000) min _maxDist) max (_radius + 400);
private _spawnPos  = _center getPos [_spawnDist, random 360];
_spawnPos set [2, 300];

private _plane = createVehicle [_class, _spawnPos, [], 0, "FLY"];
if (isNull _plane) exitWith {
    [format ["createVehicle null for %1", _class]] call _say;
    [objNull, grpNull]
};
_plane setPosATL _spawnPos;
_plane flyInHeight 250;

// Crew.
private _crewGroup = createVehicleCrew _plane;
if (isNull _crewGroup || { (units _crewGroup) isEqualTo [] }) exitWith {
    [format ["crew creation failed for %1", _class]] call _say;
    deleteVehicle _plane;
    [objNull, grpNull]
};
if ((side _crewGroup) != _side) then {
    [_crewGroup] joinSilent (createGroup [_side, true]);
};
{ _x setSkill _skill } forEach (units _crewGroup);

// ---------------------------------------------------------------------
// Waypoints — tighter than jets (slow planes turn faster). 4-6 points
// at random angles, distance radius +400..+1200m.
// ---------------------------------------------------------------------
while {count (waypoints _crewGroup) > 0} do {
    deleteWaypoint ((waypoints _crewGroup) select 0);
};

// "Simple Pathing" clamps the route to 2 waypoints for cheaper AI cost.
private _simple = _aoConfig getOrDefault ["simplePathing", false];
private _wpCount = if (_simple) then { 2 } else { 4 + (floor random 3) };   // 4..6
private _wpPositions = [];
for "_i" from 1 to _wpCount do {
    private _angle = random 360;
    private _dist  = (_radius + 400 + (random 800)) min _maxDist;
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

// Forward velocity nudge — props need less than jets but still need
// to not stall on spawn.
_plane setVelocity [
    (sin (getDir _plane)) * 70,
    (cos (getDir _plane)) * 70,
    0
];

_plane setVariable ["GEA_aoId", _aoId, true];

[format ["%1 patrolling (%2 waypoints, %3m base)", _class, _wpCount, _radius + 400]] call _say;

[_plane, _crewGroup]
