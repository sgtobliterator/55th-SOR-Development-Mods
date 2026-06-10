// =====================================================================
// GEA_fnc_spawnGarrisonGroup
//   Spawns exactly _count infantry units inside one building.
//
//   Previously this routed through BIS_fnc_spawnGroup + group templates
//   and then deleted the overspawned units. That approach had two
//   problems: (1) templates have fixed sizes so we wasted units and
//   (2) the post-delete `units _grp` count didn't always reflect the
//   final state, causing the orchestrator to undercount placed units.
//
//   New approach: pull infantry classnames from _aoConfig.infantryClasses
//   (cached once by fn_generateAO) and createUnit exactly _count times.
//   No overspawn, no race conditions in the entity count.
//
//   Inputs:
//     _aoConfig : AO hashmap (uses side / skill / infantryClasses / id)
//     _building : object to garrison
//     _count    : how many units to place (hard-capped at 4 — garrisons
//                 are meant to be fireteam-sized)
//
//   Returns: the spawned group (grpNull on failure).
// =====================================================================

#include "..\..\script_component.hpp"

#ifndef GEA_GARRISON_MAX_PER_BUILDING
    #define GEA_GARRISON_MAX_PER_BUILDING 4
#endif

if (!isServer) exitWith { grpNull };

params [
    ["_aoConfig", createHashMap, [createHashMap]],
    ["_building", objNull,       [objNull]],
    ["_count",    4,             [0]]
];

if (isNull _building) exitWith { grpNull };
// Clamp to the fireteam cap. Callers that ask for 6/8 get silently
// downsized so we never stuff a squad into a single house.
_count = _count min GEA_GARRISON_MAX_PER_BUILDING;
if (_count < 1)       exitWith { grpNull };

private _side             = _aoConfig get "side";
private _skill            = _aoConfig get "skill";
private _aoId             = _aoConfig get "id";
private _infantryClasses  = _aoConfig getOrDefault ["infantryClasses", []];

if (_infantryClasses isEqualTo []) exitWith {
    diag_log text "[GEA] spawnGarrisonGroup: no infantryClasses cached.";
    grpNull
};

private _grp = createGroup [_side, true];
if (isNull _grp) exitWith {
    diag_log text "[GEA] spawnGarrisonGroup: createGroup failed.";
    grpNull
};

// Stage units next to the building, then teleport via fillBuilding.
private _stagePos = (getPosATL _building) vectorAdd [random 4 - 2, random 4 - 2, 0];

for "_i" from 1 to _count do {
    private _class = selectRandom _infantryClasses;
    private _u = _grp createUnit [_class, _stagePos, [], 0, "NONE"];
    if (!isNull _u) then {
        _u setSkill _skill;
    };
};

// Place into building. fillBuilding returns whichever units actually
// got a valid slot — anything left over is deleted so we don't have
// stragglers in the street.
private _placed = [_building, units _grp, _count] call GEA_fnc_fillBuilding;

if (_placed isEqualTo []) exitWith {
    { deleteVehicle _x } forEach (units _grp);
    deleteGroup _grp;
    grpNull
};

{
    if (!(_x in _placed)) then { deleteVehicle _x };
} forEach (units _grp);

_grp setVariable ["GEA_aoId", _aoId, true];
_grp setBehaviour "AWARE";
_grp setCombatMode "RED";

_grp
