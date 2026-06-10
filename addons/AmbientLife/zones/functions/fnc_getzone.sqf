#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Returns a copy of the zone's settings hashmap. Array values inside
 * (roleMix, agents) are shared references - do not mutate them directly.
 *
 * Arguments:
 * 0: Zone id <STRING>
 *
 * Return Value:
 * Settings copy; empty hashmap if zone not found <HASHMAP>
 *
 * Example:
 * "zone_1" call digii_ambient_zones_fnc_getZone
 *
 * Public: Yes
 */

params [["_id", "", [""]]];

private _entry = GVAR(registry) get _id;
if (isNil "_entry") exitWith {createHashMap};

+_entry
