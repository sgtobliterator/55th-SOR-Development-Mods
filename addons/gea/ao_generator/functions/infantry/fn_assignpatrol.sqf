// =====================================================================
// GEA_fnc_assignPatrol
//   Single point of truth for how a patrolling group gets its route.
//
//   The mod supports two pathing modes, chosen by the "Simple Pathing"
//   toggle (config key "simplePathing"):
//
//     DEFAULT (simple = false):
//       BIS_fnc_taskPatrol — the rich, dynamic vanilla patrol. Generates
//       many randomized waypoints around the AO. Great variety, but each
//       waypoint costs AI pathfinding work; lots of groups => FPS hit.
//
//     SIMPLE (simple = true):
//       Exactly 2 MOVE waypoints + a CYCLE back to the first. This keeps
//       a group moving/looping with the smallest possible waypoint graph,
//       which is much cheaper for the AI engine. Intended as a perf knob
//       for big AOs / weak servers.
//
//   This helper is used by infantry patrols and ground-vehicle patrols.
//   Air spawners build their own (long-range, outside-AO) waypoint route
//   and honour the same toggle inline by clamping their waypoint count.
//
//   Inputs:
//     _grp    : Group  — the group to route (must be non-null).
//     _center : Position — AO centre.
//     _radius : Number — AO radius (m).
//     _simple : Bool   — true => 2 waypoints + cycle; false => taskPatrol.
//
//   Returns: nothing.
// =====================================================================

#include "..\..\script_component.hpp"

params [
    ["_grp",    grpNull,   [grpNull]],
    ["_center", [0,0,0],   [[]], [3]],
    ["_radius", 500,       [0]],
    ["_simple", false,     [false]]
];

if (isNull _grp) exitWith {};

// --- Default: rich dynamic patrol -----------------------------------
if (!_simple) exitWith {
    [_grp, _center, _radius] call BIS_fnc_taskPatrol;
};

// --- Simple: 2 MOVE waypoints + CYCLE -------------------------------
// Clear anything BIS or a previous call may have left on the group.
while {count (waypoints _grp) > 0} do {
    deleteWaypoint ((waypoints _grp) select 0);
};

// Two destinations somewhere inside the AO (land only when we can find
// it within a few tries — falls back to the raw position otherwise).
private _fnc_pickPos = {
    params ["_c", "_r"];
    private _p = _c getPos [random _r, random 360];
    for "_t" from 1 to 8 do {
        if (!surfaceIsWater _p) exitWith {};
        _p = _c getPos [random _r, random 360];
    };
    _p
};

private _p1 = [_center, _radius] call _fnc_pickPos;
private _p2 = [_center, _radius] call _fnc_pickPos;

// Match the default (BIS_fnc_taskPatrol) posture: groups patrol in SAFE,
// not AWARE — they only go alert when they detect something. Keeping
// this consistent means the only difference between modes is waypoint
// count, never combat stance.
_grp setBehaviour "SAFE";

private _wp1 = _grp addWaypoint [_p1, 0];
_wp1 setWaypointType "MOVE";
_wp1 setWaypointBehaviour "SAFE";
_wp1 setWaypointSpeed "LIMITED";

private _wp2 = _grp addWaypoint [_p2, 0];
_wp2 setWaypointType "MOVE";
_wp2 setWaypointBehaviour "SAFE";
_wp2 setWaypointSpeed "LIMITED";

private _wpc = _grp addWaypoint [_p1, 0];
_wpc setWaypointType "CYCLE";
