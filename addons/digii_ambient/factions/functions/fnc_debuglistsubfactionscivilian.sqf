#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Dumps the civilian sub-faction cache to systemChat, sorted ascending by
 * label. Callable from the debug console.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call digii_ambient_factions_fnc_debugListSubFactionsCivilian
 *
 * Public: Yes
 */

if (isNil QGVAR(subFactionsCivilian)) then { [] call FUNC(enumerateSubFactions); };

systemChat format ["[digii_ambient] %1 civilian sub-factions enumerated:", count GVAR(subFactionsCivilian)];

private _rows = (values GVAR(subFactionsCivilian)) apply { [_x get "label", _x] };
_rows sort true;

{
    _x params ["_label", "_entry"];
    systemChat format [
        "  %1 (%2 units) [id: %3]",
        _label,
        count (_entry get "units"),
        _entry get "id"
    ];
} forEach _rows;
