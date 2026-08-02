#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Returns civilian infantry classnames for a civilian sub-faction.
 * Returns a copy so callers cannot mutate the cache.
 *
 * Arguments:
 * 0: Civilian sub-faction id (composite "factionClass:vehicleClass") <STRING>
 *
 * Return Value:
 * Civilian classnames; empty if id not cached <ARRAY>
 *
 * Example:
 * "CIV_F:Men" call digii_ambient_factions_fnc_getSubFactionUnitsCivilian
 *
 * Public: No
 */

params [["_id", "", [""]]];

if (isNil QGVAR(subFactionsCivilian)) then { [] call FUNC(enumerateSubFactions); };

private _entry = GVAR(subFactionsCivilian) get _id;
if (isNil "_entry") exitWith { [] };

+(_entry get "units")
