#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Removes a zone from the registry, despawning its agents first. Server-only.
 *
 * Arguments:
 * 0: Zone id <STRING>
 *
 * Return Value:
 * True if zone existed and was removed, false otherwise <BOOL>
 *
 * Example:
 * "zone_1" call digii_ambient_zones_fnc_deleteZone
 *
 * Public: Yes
 */

params [["_id", "", [""]]];

if (!isServer) exitWith {false};

private _entry = GVAR(registry) get _id;
if (isNil "_entry") exitWith {false};

// Despawn entities before removing the registry entry.
[_entry] call EFUNC(agents,despawnZone);

GVAR(registry) deleteAt _id;

INFO_1("Deleted zone %1",_id);

true
