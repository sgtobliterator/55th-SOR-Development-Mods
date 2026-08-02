// =====================================================================
// GEA_fnc_spawnRoadblock
//   Builds ONE manned roadblock on a road near the AO perimeter.
//
//   Roads ARE detectable in Arma 3 (nearRoads + roadsConnectedTo give us
//   position and heading), so we drop the block on the tarmac and orient
//   it to the road. Like statics/mines, we bias to the OUTER ring so
//   roadblocks sit on the approaches, not the centre.
//
//   Composition (aligned to the road) + 2-3 guards:
//     - Razor wire chicane across the carriageway.
//     - A small sandbag bunker on the shoulder, level with an end wire.
//     - A sandbag wall lining the shoulder in front of the wire.
//     - 2-3 infantry guards (faction/side pool) holding at the block.
//
//   Inputs:
//     _aoConfig : HashMap — reads center, radius, side, skill, id,
//                 infantryClasses (resolved by the orchestrator).
//
//   Returns: [ _objects(array), _guardGroup ]   ([], grpNull on failure)
// =====================================================================

#include "..\..\script_component.hpp"

if (!isServer) exitWith { [[], grpNull] };

params [["_aoConfig", createHashMap, [createHashMap]]];

private _center  = _aoConfig get "center";
private _radius  = _aoConfig get "radius";
private _side    = _aoConfig get "side";
private _skill   = _aoConfig get "skill";
private _aoId    = _aoConfig get "id";
private _infantryClasses = _aoConfig getOrDefault ["infantryClasses", []];

private _say = {
    params ["_msg"];
    diag_log text format ["[GEA] roadblock: %1", _msg];
};

// --- Component classes (vanilla; guarded with fallbacks) ------------
private _wireClass    = "Land_Razorwire_F";
private _bunkerClass  = "Land_BagBunker_Small_F";
private _sandbagClass = "Land_BagFence_Long_F";
if (!isClass (configFile >> "CfgVehicles" >> _wireClass))    then { _wireClass    = "Land_BagFence_Long_F" };
if (!isClass (configFile >> "CfgVehicles" >> _bunkerClass))  then { _bunkerClass  = "Land_BagBunker_Large_F" };
if (!isClass (configFile >> "CfgVehicles" >> _sandbagClass)) then { _sandbagClass = "Land_BagFence_Short_F" };

// --- Find a road segment near the AO perimeter ----------------------
private _prior = _aoConfig getOrDefault ["roadblockSpawns", []];

// Shared obstacle registry (statics/vehicles/cars also populate it) so a
// roadblock is never built on top of something already placed.
private _obstacles = _aoConfig getOrDefault ["obstacles", []];
private _blockFootprint = 10;   // the whole block roughly fills this radius

private _spotOk = {
    params ["_p"];
    // Keep blocks apart from each other...
    if (_prior findIf { (_p distance2D _x) < 40 } >= 0) exitWith { false };
    // ...and clear of any other placed object.
    (_obstacles findIf { (_p distance2D (_x select 0)) < ((_x select 1) + _blockFootprint) }) < 0
};

private _roads = (_center nearRoads _radius) call BIS_fnc_arrayShuffle;
[format ["roads found in AO: %1 (radius %2m)", count _roads, _radius]] call _say;
if (_roads isEqualTo []) exitWith {
    ["no roads in the AO — skipping roadblock."] call _say;
    [[], grpNull]
};

// Prefer outer-ring roads, then any road; respect spacing + obstacles.
private _outer = _roads select { (_center distance2D (getPosATL _x)) > (0.5 * _radius) };
private _ordered = _outer + (_roads - _outer);   // outer first, then the rest

private _road = objNull;
{
    if ([getPosATL _x] call _spotOk) exitWith { _road = _x };
} forEach _ordered;

if (isNull _road) exitWith {
    ["no clear road spot for a roadblock (all occupied / too close) — skipping."] call _say;
    [[], grpNull]
};

private _rPos = getPosATL _road;
_prior pushBack _rPos;
_aoConfig set ["roadblockSpawns", _prior];
// Reserve the block footprint so later placements (cars etc.) avoid it.
_obstacles pushBack [_rPos, _blockFootprint];
_aoConfig set ["obstacles", _obstacles];

// --- Road heading from a connected segment --------------------------
private _connected = roadsConnectedTo _road;
private _rDir = if (count _connected > 0) then {
    _rPos getDir (getPosATL (_connected select 0))
} else {
    getDir _road
};

// Road-relative unit vectors.
private _fwd = [sin _rDir,        cos _rDir,        0];
private _rgt = [sin (_rDir + 90), cos (_rDir + 90), 0];

private _objects = [];

// Place a static object at a road-relative offset (_along = forward,
// _across = right of the road heading), facing _dir.
private _placeObj = {
    params ["_cls", "_along", "_across", "_dir"];
    private _p = _rPos
        vectorAdd (_fwd vectorMultiply _along)
        vectorAdd (_rgt vectorMultiply _across);
    private _o = createVehicle [_cls, _p, [], 0, "CAN_COLLIDE"];
    if (!isNull _o) then {
        _o setDir _dir;
        _o setPosATL _p;
        _o setVariable ["GEA_aoId", _aoId, true];
        _objects pushBack _o;
    };
    _o
};

// --- Simple layout -------------------------------------------------
//   Three tidy razor-wire belts straight across the road, lightly
//   staggered. A sandbag wall sits beside each belt (inboard/right).
//   One bunker on the left shoulder overwatches the block.
//   (_along = forward along road, _across = right of road heading.)

// Razor-wire belts across the carriageway.
[_wireClass,  6, -1, _rDir] call _placeObj;
[_wireClass,  0,  1, _rDir] call _placeObj;
[_wireClass, -6, -1, _rDir] call _placeObj;

// Sandbag walls — one beside each wire belt, spanning across the road.
[_sandbagClass,  4.5, 2, _rDir] call _placeObj;
[_sandbagClass, -1.5, 2, _rDir] call _placeObj;
[_sandbagClass, -7.5, 2, _rDir] call _placeObj;

// Bunker on the left shoulder, overwatching the block.
[_bunkerClass, 3, -6, _rDir + 180] call _placeObj;

// --- Guards (2-3), holding at the block -----------------------------
private _guardGroup = grpNull;
if (!(_infantryClasses isEqualTo [])) then {
    _guardGroup = createGroup [_side, true];
    private _nGuards = 2 + floor random 2;   // 2..3
    for "_g" from 1 to _nGuards do {
        private _gp  = _rPos getPos [3 + random 4, _rDir + 90 + (random 120 - 60)];
        private _cls = [_infantryClasses] call GEA_fnc_pickTurretCrew;
        if (_cls == "") then { _cls = selectRandom _infantryClasses };
        private _u = _guardGroup createUnit [_cls, _gp, [], 0, "NONE"];
        if (!isNull _u) then {
            _u setSkill _skill;
            _u setVariable ["GEA_aoId", _aoId, true];
            _u setDir (_u getDir _rPos);
        };
    };
    if (count (units _guardGroup) > 0) then {
        _guardGroup setVariable ["GEA_aoId", _aoId, true];
        _guardGroup setBehaviour "AWARE";
        _guardGroup setCombatMode "RED";
        private _wp = _guardGroup addWaypoint [_rPos, 0];
        _wp setWaypointType "HOLD";
    } else {
        deleteGroup _guardGroup;
        _guardGroup = grpNull;
    };
};

[format ["roadblock built: %1 objects, %2 guards, %3m from centre.",
    count _objects,
    (if (isNull _guardGroup) then {0} else {count (units _guardGroup)}),
    round (_center distance2D _rPos)]] call _say;

[_objects, _guardGroup]
