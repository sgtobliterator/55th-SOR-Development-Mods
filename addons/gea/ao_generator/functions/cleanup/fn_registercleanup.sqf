// =====================================================================
// GEA_fnc_registerCleanup
//   Records spawned entities into the AO config, tags them with the
//   AO id, and makes them editable in Zeus for every active curator.
//
//   The "Zeus editable" step is what makes a unit show up in the
//   curator's unit list / map markers. Without it, dynamically-spawned
//   units are invisible to Zeus even though they exist in the world.
//
//   Global registry of AOs lives in:
//     missionNamespace::GEA_activeAOs (HashMap<id, aoConfig>)
// =====================================================================

#include "..\..\script_component.hpp"

if (!isServer) exitWith {};

params [
    ["_aoConfig", createHashMap, [createHashMap]],
    ["_entities", [],            [[]]]
];

private _aoId = _aoConfig get "id";

// ---- Flatten ---------------------------------------------------------
// _entities may contain groups, units, and vehicles in any mix. For
// Zeus editing we need plain object handles (groups can't be added
// directly — we add their units instead).
private _editable = [];
{
    if (isNil "_x") then { continue };

    if (_x isEqualType grpNull) then {
        // It's a group: pull every unit out.
        {
            if (alive _x) then { _editable pushBackUnique _x };
        } forEach (units _x);
    } else {
        if (_x isEqualType objNull && { !isNull _x }) then {
            _editable pushBackUnique _x;
        };
    };
} forEach _entities;

// ---- Tag for cleanup -------------------------------------------------
{
    _x setVariable ["GEA_aoId", _aoId, true];
} forEach _editable;

// Also tag the groups themselves so we can despawn cleanly later.
{
    if (!isNil "_x" && { _x isEqualType grpNull }) then {
        _x setVariable ["GEA_aoId", _aoId, true];
    };
} forEach _entities;

// ---- Make Zeus-editable on every curator ----------------------------
// Pass [units, true] — the second arg means "and add their vehicles
// + groups recursively" so trucks, helis, and the groups themselves
// all light up in the unit list with one call.
if (!(_editable isEqualTo [])) then {
    {
        _x addCuratorEditableObjects [_editable, true];
    } forEach allCurators;
};

// ---- Persist into AO config + global registry -----------------------
private _existing = _aoConfig getOrDefault ["entities", []];
_aoConfig set ["entities", _existing + _entities];

private _registry = missionNamespace getVariable ["GEA_activeAOs", createHashMap];
_registry set [_aoId, _aoConfig];
missionNamespace setVariable ["GEA_activeAOs", _registry, true];

diag_log text format ["[GEA] registerCleanup: AO %1 — %2 entities, %3 Zeus-editable units, %4 curators",
    _aoId, count _entities, count _editable, count allCurators];

true
