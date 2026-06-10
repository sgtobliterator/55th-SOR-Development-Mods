// =====================================================================
// GEA_fnc_spawnHeliPatrol
//   Spawns one helicopter patrolling the AO at a safe altitude.
//
//   Waypoints are randomized (5-7 points at random angles and varying
//   distances from the AO center) instead of a fixed cardinal ring, so
//   flight paths feel less robotic. CYCLE'd at the end to loop forever.
//
//   Two-tier pool:
//     TIER 1: faction-matched helicopters
//     TIER 2: side-matched   helicopters
//
//   Returns: [_heli, _crewGroup]
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
    diag_log text format ["[GEA] heli: %1", _msg];
};

private _sideNum = switch (_side) do {
    case east:        { 0 };
    case west:        { 1 };
    case independent: { 2 };
    case civilian:    { 3 };
    default           { -1 };
};

// ---------------------------------------------------------------------
// Pool — faction first, side as fallback. Exclude planes (handled by
// fn_spawnJetPatrol). Helicopter is its own base class so isKindOf
// catches all rotorcraft cleanly.
// ---------------------------------------------------------------------
private _factionPool = [];
private _sidePool    = [];

{
    private _cfg   = _x;
    private _class = configName _cfg;

    if (getNumber (_cfg >> "scope") >= 2
        && { _class isKindOf "Helicopter" }
        && { !(_class isKindOf "Plane") }
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
    ["NO helicopters found for faction OR side."] call _say;
    [objNull, grpNull]
};

private _class = selectRandom _pool;
[format ["picked %1", _class]] call _say;

// ---------------------------------------------------------------------
// Spawn outside the AO at altitude.
// ---------------------------------------------------------------------
private _spawnDist = _radius + 800;
private _spawnPos  = _center getPos [_spawnDist, random 360];
_spawnPos set [2, 150];

private _heli = createVehicle [_class, _spawnPos, [], 0, "FLY"];
if (isNull _heli) exitWith {
    [format ["createVehicle null for %1", _class]] call _say;
    [objNull, grpNull]
};
_heli setPosATL _spawnPos;
_heli flyInHeight 130;

// ---------------------------------------------------------------------
// Crew.
// ---------------------------------------------------------------------
private _crewGroup = createVehicleCrew _heli;
if (isNull _crewGroup || { (units _crewGroup) isEqualTo [] }) exitWith {
    [format ["crew creation failed for %1", _class]] call _say;
    deleteVehicle _heli;
    [objNull, grpNull]
};
if ((side _crewGroup) != _side) then {
    [_crewGroup] joinSilent (createGroup [_side, true]);
};
{ _x setSkill _skill } forEach (units _crewGroup);

// ---------------------------------------------------------------------
// Randomized waypoint route. 5-7 waypoints, random angle, random
// distance (radius +500 .. +1000m). Looped via CYCLE at the end.
// ---------------------------------------------------------------------
while {count (waypoints _crewGroup) > 0} do {
    deleteWaypoint ((waypoints _crewGroup) select 0);
};

private _wpCount = 5 + (floor random 3);  // 5..7
private _wpPositions = [];
for "_i" from 1 to _wpCount do {
    private _angle = random 360;
    private _dist  = _radius + 500 + (random 500);
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

// Forward velocity nudge.
_heli setVelocity [
    (sin (getDir _heli)) * 40,
    (cos (getDir _heli)) * 40,
    0
];

_heli setVariable ["GEA_aoId", _aoId, true];

[format ["%1 orbiting (%2 waypoints, %3m base)", _class, _wpCount, _radius + 500]] call _say;

[_heli, _crewGroup]
