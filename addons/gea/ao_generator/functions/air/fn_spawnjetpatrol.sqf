// =====================================================================
// GEA_fnc_spawnJetPatrol
//   Spawns one FAST jet (fixed-wing, maxSpeed >= 600 km/h) patrolling
//   the AO at altitude.
//
//   v0.7.0: filtered to fast jets only. Slow / prop / CAS planes go
//   through GEA_fnc_spawnPlanePatrol instead. The split is heuristic —
//   we use config "maxSpeed" because Arma doesn't expose a clean
//   "jet vs prop" flag and editorSubcategory groups them all under
//   "EdSubcat_Planes".
//
//   Jets need bigger waypoints than helis — they stall at low speed
//   and turn slowly. Orbit base radius is +800m and waypoints can
//   stretch out to +2000m so they actually fly through the area
//   instead of doing tight donuts.
//
//   Two-tier pool (same logic as fn_spawnHeliPatrol):
//     TIER 1: faction-matched fast jets
//     TIER 2: side-matched   fast jets
//
//   Excludes parachutes/UAVs/static airframes via scope filter and
//   isKindOf check.
//
//   Returns: [_jet, _crewGroup]
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
    diag_log text format ["[GEA] jet: %1", _msg];
};

private _sideNum = switch (_side) do {
    case east:        { 0 };
    case west:        { 1 };
    case independent: { 2 };
    case civilian:    { 3 };
    default           { -1 };
};

// ---------------------------------------------------------------------
// Pool. "Plane" base catches fighters / CAS / transport jets. We
// exclude ParachuteBase, and require at least one crew seat so we
// don't pick a UAV stub by accident (UAVs go through a different
// flow — those have isUav = 1).
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
        // Fast-jet filter: maxSpeed >= 600 km/h. Slow planes go via
        // fn_spawnPlanePatrol. Anything missing maxSpeed (==0) defaults
        // to "jet" so weird mod entries don't get silently dropped.
        && { private _ms = getNumber (_cfg >> "maxSpeed"); _ms == 0 || _ms >= 600 }
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
    ["NO jets found for faction OR side."] call _say;
    [objNull, grpNull]
};

private _class = selectRandom _pool;
[format ["picked %1", _class]] call _say;

// ---------------------------------------------------------------------
// Spawn well outside the AO, high.
// ---------------------------------------------------------------------
private _spawnDist = _radius + 1500;
private _spawnPos  = _center getPos [_spawnDist, random 360];
_spawnPos set [2, 500];

private _jet = createVehicle [_class, _spawnPos, [], 0, "FLY"];
if (isNull _jet) exitWith {
    [format ["createVehicle null for %1", _class]] call _say;
    [objNull, grpNull]
};
_jet setPosATL _spawnPos;
_jet flyInHeight 400;

// Crew.
private _crewGroup = createVehicleCrew _jet;
if (isNull _crewGroup || { (units _crewGroup) isEqualTo [] }) exitWith {
    [format ["crew creation failed for %1", _class]] call _say;
    deleteVehicle _jet;
    [objNull, grpNull]
};
if ((side _crewGroup) != _side) then {
    [_crewGroup] joinSilent (createGroup [_side, true]);
};
{ _x setSkill _skill } forEach (units _crewGroup);

// ---------------------------------------------------------------------
// Randomized long-range waypoints. 4-6 points at random angles, distance
// radius +800..+2000m so a jet actually has a turning circle.
// ---------------------------------------------------------------------
while {count (waypoints _crewGroup) > 0} do {
    deleteWaypoint ((waypoints _crewGroup) select 0);
};

private _wpCount = 4 + (floor random 3);   // 4..6
private _wpPositions = [];
for "_i" from 1 to _wpCount do {
    private _angle = random 360;
    private _dist  = _radius + 800 + (random 1200);
    _wpPositions pushBack (_center getPos [_dist, _angle]);
};

{
    private _wp = _crewGroup addWaypoint [_x, 0];
    _wp setWaypointType "MOVE";
    _wp setWaypointSpeed "FULL";
    _wp setWaypointBehaviour "AWARE";
    _wp setWaypointCombatMode "RED";
} forEach _wpPositions;

private _cycle = _crewGroup addWaypoint [_wpPositions select 0, 0];
_cycle setWaypointType "CYCLE";

// Forward velocity nudge so the jet doesn't stall on spawn.
_jet setVelocity [
    (sin (getDir _jet)) * 120,
    (cos (getDir _jet)) * 120,
    0
];

_jet setVariable ["GEA_aoId", _aoId, true];

[format ["%1 patrolling (%2 waypoints, %3m base)", _class, _wpCount, _radius + 800]] call _say;

[_jet, _crewGroup]
