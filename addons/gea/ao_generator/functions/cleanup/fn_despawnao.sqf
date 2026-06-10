// =====================================================================
// GEA_fnc_despawnAO
//   Deletes every entity tagged with the given AO id, removes the AO's
//   markers, and removes the AO from the active registry.
//
//   v0.7.0: also clears the AO markers. The anchor object's "Deleted"
//   event handler would catch this when deleteVehicle hits the anchor,
//   but we also do an explicit pass so we're safe if the anchor was
//   never created (e.g. showMarker = false).
// =====================================================================

#include "..\..\script_component.hpp"

if (!isServer) exitWith {};

params [["_aoId", "", [""]]];

if (_aoId isEqualTo "") exitWith { false };

private _registry = missionNamespace getVariable ["GEA_activeAOs", createHashMap];
private _aoConfig = _registry getOrDefault [_aoId, createHashMap];
private _entities = _aoConfig getOrDefault ["entities", []];
private _markers  = _aoConfig getOrDefault ["markers",  []];

{
    if (_x isEqualType grpNull) then {
        { deleteVehicle _x } forEach (units _x);
        deleteGroup _x;
    } else {
        if (!isNull _x) then { deleteVehicle _x };
    };
} forEach _entities;

{ deleteMarker _x } forEach _markers;

_registry deleteAt _aoId;
missionNamespace setVariable ["GEA_activeAOs", _registry, true];

diag_log text format ["[GEA] AO %1 despawned (%2 entities, %3 markers removed).",
    _aoId, count _entities, count _markers];

true
