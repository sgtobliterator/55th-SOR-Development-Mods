#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Spawns one patrol group: 2-4 units (random) clustered around a single
 * random in-zone pick, all in a fresh group with cyclic waypoints. Mirrors
 * fnc_garrisonBuilding's shape: one PATROL slot in the role array = one
 * call here = one group of N units, counted as a single slot against the
 * cap.
 *
 * 3DEN: seed-unit trick gives us a real group handle so subsequent binary
 * create3DENEntity calls join that group instead of fresh ones; seed is
 * deleted at the end and the group is marked garbageCollectGroup.
 *
 * Waypoints are wired AFTER units exist in the group. On the runtime path
 * (Zeus / mission preview) we additionally defer setupPatrolWaypoints by
 * one frame via CBA_fnc_execNextFrame: in a Zeus mid-mission spawn the
 * engine needs a frame between createUnit and addWaypoint for the group's
 * AI structures (leader, path planner) to settle. Without the deferral,
 * waypoints get added but don't bind to a path-following leader, and
 * Zeus patrols stand still.
 *
 * Arguments:
 * 0: Zone id <STRING>
 * 1: Center <ARRAY>
 * 2: Radius <NUMBER>
 * 3: Unit pool of classnames <ARRAY>
 * 4: Skill cap <NUMBER>
 * 5: Runtime group side (3DEN ignores; inherits seed) <SIDE>
 * 6: Use roads (optional, default false) <BOOL>
 *
 * Return Value:
 * Created units <ARRAY>
 *
 * Example:
 * ["zone_1", _center, 75, _pool, 0.2, east, true] call digii_ambient_agents_fnc_spawnPatrolGroup
 *
 * Public: No
 */

params ["_zoneId", "_center", "_radius", "_unitPool", "_skillCap", "_side", ["_useRoads", false, [false]]];

private _grpSize = PATROL_GROUP_MIN_UNITS + (floor random (PATROL_GROUP_MAX_UNITS - PATROL_GROUP_MIN_UNITS + 1));
private _cluster = [_center, _radius, _useRoads] call FUNC(pickPosWithRoadBias);

private _grp = grpNull;
private _seed = objNull;
if (is3DEN) then {
    _seed = create3DENEntity ["Object", _unitPool select 0, [0, 0, 0]];
    if (!isNull _seed) then { _grp = group _seed };
} else {
    _grp = createGroup [_side, true]; // deleteWhenEmpty = true
};
if (isNull _grp) exitWith {[]};

private _units = [];
for "_i" from 0 to (_grpSize - 1) do {
    private _pos = [_cluster, PATROL_CLUSTER_RADIUS] call FUNC(randomPosInRadius);
    private _cls = selectRandom _unitPool;

    private _entity = if (is3DEN) then {
        _grp create3DENEntity ["Object", _cls, _pos]
    } else {
        _grp createUnit [_cls, _pos, [], 0, "NONE"]
    };
    if (isNull _entity) then { continue };

    if (!is3DEN) then { _entity setPosATL _pos };

    // Fight-back baseline (matches spawnSoloUnit + setupPatrolWaypoints):
    // combat AI stays enabled so patrols engage when fired upon. LIMITED set
    // per-unit so walk speed is enforced -- CARELESS used to override this
    // to NORMAL even with group-level setSpeedMode LIMITED.
    _entity setBehaviour "SAFE";
    _entity setCombatMode "YELLOW";
    _entity setSpeedMode "LIMITED";
    _entity setSkill _skillCap;
    _entity setVariable ["digii_ambient_zoneId", _zoneId];
    _entity setVariable ["digii_ambient_role", ROLE_PATROL];

    _units pushBack _entity;
};

// Wire waypoints. 3DEN creates real editor waypoint entities (immediate).
// Runtime defers one frame so the AI structures settle after createUnit
// before addWaypoint binds them -- without this, Zeus patrols stand still.
if (is3DEN) then {
    [_grp, _center, _radius, _useRoads] call FUNC(setupPatrolWaypoints);
} else {
    [FUNC(setupPatrolWaypoints), [_grp, _center, _radius, _useRoads]] call CBA_fnc_execNextFrame;
};

if (is3DEN && {!isNull _seed}) then {
    _grp set3DENAttribute ["garbageCollectGroup", true];
    delete3DENEntities [_seed];
};

INFO_2("Spawned patrol group of %1 units in zone %2",count _units,_zoneId);

_units
