// =====================================================================
// GEA_fnc_buildAOConfig
//   Turn the Stage-2 dialog result into a typed AO config hashmap.
//
//   Keeping the index→key mapping isolated here means we can re-order
//   or add dialog rows without touching the spawn subsystems. Every
//   subsystem reads from the hashmap by key, never by position.
//
//   Stage-2 row order (mirrors fn_openConfigDialog.sqf, v0.8.0):
//      0  Radius (m)            number
//      1  AI Skill              number 0..1
//      2  Faction               string (className from CfgFactionClasses)
//      3  Patrol Groups         number
//      4  Garrison Groups       number   (replaces old "Infantry Count" + "Garrison %")
//      5  Static Turrets        number   (manned statics, face outward)
//      6  Vehicle Patrols       number
//      7  % Car                 number 0..100
//      8  % APC                 number 0..100
//      9  % Tank                number 0..100
//     10  Air Patrols           number
//     11  % Heli                number 0..100
//     12  % Jet                 number 0..100
//     13  % Drone               number 0..100
//     14  % Plane               number 0..100
//     15  Show AO Marker        bool
//     16  Simple Pathing        bool     (2 waypoints + cycle for all patrols)
//     17  Civilian Faction      string   (CfgFactionClasses className, "" = any civ)
//     18  Patrol Civilians      number   (wandering ambient civs)
//     19  Garrison Civilians    number   (civs placed inside buildings)
//     20  Civilian Cars         number   (empty parked civ cars)
//     21  Minefields            number   (perimeter mine clusters)
//     22  Show Minefield Markers bool
//     23  Roadblocks            number   (manned road blocks on the perimeter)
//     24  Heli Patrol Range     number   (max heli waypoint distance beyond radius)
//     25  Plane Patrol Range    number   (max jet/plane waypoint distance beyond radius)
//
//   NOTE: this positional order is shared by the ZEN dialog
//   (fn_openConfigDialog) AND the Eden editor module (fn_moduleInit).
//   If you re-order rows, update BOTH callers.
//
//   Type-% values are stored raw (0..100). They are auto-normalized by
//   the spawners at spawn time — the user does NOT need to make them
//   sum to 100. Only the ratios matter. If all weights are 0, the
//   spawner falls back to a uniform pick over non-empty pools.
// =====================================================================

#include "..\..\script_component.hpp"

params [
    ["_center", [0,0,0], [[]], [3]],
    ["_side",   east,    [west]],
    ["_values", [],      [[]]]
];

_values params [
    ["_radius",         500],
    ["_skill",          0.5],
    ["_faction",        ""],
    ["_patrolGroups",   3],
    ["_garrisonGroups", 5],
    ["_staticTurrets",  0],
    ["_vehiclePatrols", 1],
    ["_vehPctCar",      70],
    ["_vehPctApc",      20],
    ["_vehPctTank",     10],
    ["_airPatrols",     0],
    ["_airPctHeli",     60],
    ["_airPctJet",      20],
    ["_airPctDrone",    10],
    ["_airPctPlane",    10],
    ["_showMarker",     true],
    ["_simplePathing",  false],
    ["_civFaction",     ""],
    ["_civPatrol",      0],
    ["_civGarrison",    0],
    ["_civCars",        0],
    ["_mineFields",     0],
    ["_showMineMarkers", false],
    ["_roadblocks",     0],
    ["_heliRange",      1000],
    ["_planeRange",     2000]
];

// Round all count-like fields so float slider drift can't cause
// off-by-one spawns (e.g. value of 2.9 was floored to 2 by `for` loops).
_radius         = round _radius;
_patrolGroups   = round _patrolGroups;
_garrisonGroups = round _garrisonGroups;
_staticTurrets  = round _staticTurrets;
_vehiclePatrols = round _vehiclePatrols;
_airPatrols     = round _airPatrols;
_civPatrol      = round _civPatrol;
_civGarrison    = round _civGarrison;
_civCars        = round _civCars;
_mineFields     = round _mineFields;
_roadblocks     = round _roadblocks;
_heliRange      = round _heliRange;
_planeRange     = round _planeRange;

_vehPctCar   = round _vehPctCar;
_vehPctApc   = round _vehPctApc;
_vehPctTank  = round _vehPctTank;
_airPctHeli  = round _airPctHeli;
_airPctJet   = round _airPctJet;
_airPctDrone = round _airPctDrone;
_airPctPlane = round _airPctPlane;

private _aoId = format ["GEA_AO_%1_%2", diag_tickTime toFixed 0, floor random 100000];

private _cfg = createHashMapFromArray [
    ["id",              _aoId],
    ["center",          _center],
    ["radius",          _radius],
    ["side",            _side],
    ["faction",         _faction],
    ["skill",           _skill],
    ["patrolGroups",    _patrolGroups],
    ["garrisonGroups",  _garrisonGroups],
    ["staticTurrets",   _staticTurrets],
    ["vehiclePatrols",  _vehiclePatrols],
    ["vehiclePct",      [_vehPctCar, _vehPctApc, _vehPctTank]],   // [car, apc, tank]
    ["airPatrols",      _airPatrols],
    ["airPct",          [_airPctHeli, _airPctJet, _airPctDrone, _airPctPlane]],  // [heli, jet, drone, plane]
    ["showMarker",      _showMarker],
    ["simplePathing",   _simplePathing],
    ["civFaction",      _civFaction],
    ["civPatrol",       _civPatrol],
    ["civGarrison",     _civGarrison],
    ["civCars",         _civCars],
    ["mineFields",      _mineFields],
    ["showMineMarkers", _showMineMarkers],
    ["roadblocks",      _roadblocks],
    ["heliRange",       _heliRange],
    ["planeRange",      _planeRange],
    ["entities",        []],             // populated by spawners, drained by cleanup
    ["markers",         []],             // marker names for cleanup
    ["vehicleSpawns",   []],             // spawn positions for spacing checks
    ["obstacles",       []]              // shared [pos,radius] footprints — prevents overlap
];

_cfg
