#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Mutates fields of an existing zone entry. Server-only.
 *
 * Arguments:
 * 0: Zone id <STRING>
 * 1: Patch hashmap; keys to update (same allow-list as registerZone) <HASHMAP>
 *
 * Return Value:
 * True if zone existed and was updated, false otherwise <BOOL>
 *
 * Example:
 * ["zone_1", createHashMapFromArray [["radius", 200]]] call digii_ambient_zones_fnc_updateZone
 *
 * Public: Yes
 */

params [["_id", "", [""]], ["_patch", createHashMap, [createHashMap]]];

if (!isServer) exitWith {false};

private _entry = GVAR(registry) get _id;
if (isNil "_entry") exitWith {false};

private _allowedKeys = [
    "center", "radius", "subFactionId", "label", "density", "roleMix",
    "useBuildings", "useRoads", "skillCap", "includeOfficer", "kind", "placerUid"
];

{
    if (_x in _allowedKeys) then { _entry set [_x, _y] };
} forEach _patch;

INFO_1("Updated zone %1",_id);

true
