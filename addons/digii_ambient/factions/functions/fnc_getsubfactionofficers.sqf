#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Returns the sub-faction's officer classnames (collected separately during
 * enumeration). Returns a copy so callers cannot mutate the cache. Returns
 * empty array if the sub-faction has no officers configured -- callers
 * should fall back to fnc_getSubFactionUnits in that case.
 *
 * Arguments:
 * 0: Sub-faction id (composite "factionClass:vehicleClass") <STRING>
 *
 * Return Value:
 * Officer classnames; empty if id not cached or no officers <ARRAY>
 *
 * Example:
 * "BLU_F:Men" call digii_ambient_factions_fnc_getSubFactionOfficers
 *
 * Public: No
 */

params [["_id", "", [""]]];

if (isNil QGVAR(subFactions)) then { [] call FUNC(enumerateSubFactions); };

private _entry = GVAR(subFactions) get _id;
if (isNil "_entry") exitWith { [] };

+(_entry get "officers")
