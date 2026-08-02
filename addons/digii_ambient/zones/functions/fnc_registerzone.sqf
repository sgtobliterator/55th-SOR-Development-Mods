#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Registers a new zone in GVAR(registry). Generates a UUID, applies defaults for
 * missing settings, writes the entry, returns the id. Server-only.
 *
 * Allowed settings keys (others ignored to keep callers from injecting internal
 * fields like 'agents' or 'draw3DHandle'):
 *   center, radius, subFactionId, label, density, roleMix,
 *   useBuildings, useRoads, skillCap, includeOfficer, placerUid
 *
 * Arguments:
 * 0: Settings <HASHMAP>
 *
 * Return Value:
 * Zone id; empty string if called off-server <STRING>
 *
 * Example:
 * private _s = createHashMapFromArray [["center", [100,100,0]], ["radius", 100]];
 * private _id = _s call digii_ambient_zones_fnc_registerZone;
 *
 * Public: Yes
 */

params [["_settings", createHashMap, [createHashMap]]];

if (!isServer) exitWith {""};

private _id = call EFUNC(common,uuid);

private _entry = createHashMapFromArray [
    ["id",             _id],
    ["center",         [0,0,0]],
    ["radius",         75],
    ["subFactionId",   ""],
    ["label",          ""],
    ["density",        5],
    ["roleMix",        [50, 25, 15, 10]],
    ["useBuildings",   true],
    ["useRoads",       true],
    ["skillCap",       0.2],
    ["includeOfficer", false],
    ["kind",           "military"],
    ["placerUid",      ""],
    ["agents",         []],
    ["draw3DHandle",   -1],
    ["createdBy",      profileName]
];

private _allowedKeys = [
    "center", "radius", "subFactionId", "label", "density", "roleMix",
    "useBuildings", "useRoads", "skillCap", "includeOfficer", "kind", "placerUid"
];

{
    if (_x in _allowedKeys) then { _entry set [_x, _y] };
} forEach _settings;

_entry set ["id", _id];

GVAR(registry) set [_id, _entry];

INFO_2("Registered zone %1 at %2",_id,_entry get "center");

_id
