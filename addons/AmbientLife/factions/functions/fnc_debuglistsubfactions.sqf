#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Dumps the sub-faction cache to systemChat, sorted ascending by label.
 * Callable from the debug console.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call digii_ambient_factions_fnc_debugListSubFactions
 *
 * Public: Yes
 */

if (isNil QGVAR(subFactions)) then { [] call FUNC(enumerateSubFactions); };

systemChat format ["[digii_ambient] %1 sub-factions enumerated:", count GVAR(subFactions)];

private _rows = (values GVAR(subFactions)) apply { [_x get "label", _x] };
_rows sort true;

{
    _x params ["_label", "_entry"];
    systemChat format [
        "  %1 (%2 units, %3 officers) [id: %4]",
        _label,
        count (_entry get "units"),
        count (_entry get "officers"),
        _entry get "id"
    ];
} forEach _rows;
