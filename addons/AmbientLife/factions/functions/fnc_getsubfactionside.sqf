#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Returns the BIS side object for a sub-faction.
 *
 * Arguments:
 * 0: Sub-faction id <STRING>
 *
 * Return Value:
 * Side; sideUnknown if not cached <SIDE>
 *
 * Example:
 * "BLU_F:Men" call digii_ambient_factions_fnc_getSubFactionSide
 *
 * Public: No
 */

params [["_id", "", [""]]];

if (isNil QGVAR(subFactions)) then { [] call FUNC(enumerateSubFactions); };

private _entry = GVAR(subFactions) get _id;
if (isNil "_entry") exitWith { sideUnknown };

_entry get "side"
