#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Returns infantry classnames for a sub-faction. Returns a copy so callers
 * cannot mutate the cache.
 *
 * Arguments:
 * 0: Sub-faction id (composite "factionClass:vehicleClass") <STRING>
 *
 * Return Value:
 * Unit classnames; empty if id not cached <ARRAY>
 *
 * Example:
 * "BLU_F:Men" call digii_ambient_factions_fnc_getSubFactionUnits
 *
 * Public: No
 */

params [["_id", "", [""]]];

if (isNil QGVAR(subFactions)) then { [] call FUNC(enumerateSubFactions); };

private _entry = GVAR(subFactions) get _id;
if (isNil "_entry") exitWith { [] };

+(_entry get "units")
