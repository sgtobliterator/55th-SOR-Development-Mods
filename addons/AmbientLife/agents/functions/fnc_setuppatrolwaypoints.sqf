#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Adds N MOVE waypoints around the zone plus a closing CYCLE waypoint, so the
 * group walks a slow SAFE loop through the area (matches the fight-back
 * baseline -- weapons low at rest, engage when fired upon).
 *
 * Two paths:
 *   - 3DEN: creates real 3DEN waypoint entities via create3DENEntity. These
 *     render as markers in the editor view and survive into mission preview
 *     as functional waypoints (no runtime translation needed).
 *   - Runtime (Zeus / mission preview / MP): addWaypoint on the live group.
 *     Caller MUST ensure units already joined the group before this fires --
 *     adding waypoints to an empty group is unreliable. Runtime path also
 *     explicitly binds leadership via selectLeader: after createGroup +
 *     createUnit the implicit leader isn't always bound by the next frame,
 *     and addWaypoint without a leader has no path-planner to drive the
 *     group (Zeus-spawned patrols stand still otherwise).
 *
 * Arguments:
 * 0: Group <GROUP>
 * 1: Center <ARRAY>
 * 2: Radius <NUMBER>
 * 3: Use roads (optional, default false) <BOOL>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_grp, _center, 75, true] call digii_ambient_agents_fnc_setupPatrolWaypoints
 *
 * Public: No
 */

params ["_grp", "_center", "_radius", ["_useRoads", false, [false]]];

if (isNull _grp) exitWith {};

if (is3DEN) then {
    for "_i" from 0 to (PATROL_WAYPOINT_COUNT - 1) do {
        private _wpPos = [_center, _radius, _useRoads] call FUNC(pickPosWithRoadBias);
        private _wp = _grp create3DENEntity ["Waypoint", "Move", _wpPos];
        _wp set3DENAttribute ["Speed", "LIMITED"];
        _wp set3DENAttribute ["CombatMode", "YELLOW"];
        _wp set3DENAttribute ["Behaviour", "SAFE"];
        _wp set3DENAttribute ["Timeout", [5, 10, 15]];
    };
    // Closing CYCLE waypoint near the center.
    _grp create3DENEntity ["Waypoint", "Cycle", _center];
} else {
    private _unitsArr = units _grp;
    if (_unitsArr isEqualTo []) exitWith {};

    // Explicit leader bind. After createGroup + createUnit (sync) the
    // engine assigns leadership lazily; on the next-frame deferred call
    // the implicit leader may not be bound yet, and addWaypoint without
    // a leader has no path-planner to drive the group -- Zeus-spawned
    // patrols stand still.
    _grp selectLeader (_unitsArr select 0);

    _grp setBehaviour "SAFE";
    _grp setCombatMode "YELLOW";
    _grp setSpeedMode "LIMITED";

    for "_i" from 0 to (PATROL_WAYPOINT_COUNT - 1) do {
        private _wpPos = [_center, _radius, _useRoads] call FUNC(pickPosWithRoadBias);
        private _wp = _grp addWaypoint [_wpPos, 0];
        _wp setWaypointType "MOVE";
        _wp setWaypointSpeed "LIMITED";
        _wp setWaypointBehaviour "SAFE";
        _wp setWaypointCombatMode "YELLOW";
        _wp setWaypointTimeout [5, 10, 15];
    };

    private _cycle = _grp addWaypoint [_center, 0];
    _cycle setWaypointType "CYCLE";
};
