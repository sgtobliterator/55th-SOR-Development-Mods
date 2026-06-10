#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Slider onSliderPosChanged handler. Reads all 4 role-mix sliders, rewrites
 * each value label with the rounded percentage, and updates the total
 * indicator. Shared across all 4 sliders.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * Invoked from each slider's onSliderPosChanged event; do not call manually.
 *
 * Public: No
 */

private _display = findDisplay 70000;
if (isNull _display) exitWith {};

private _rows = [
    [localize LSTRING(role_guards),    70030, 70031],
    [localize LSTRING(role_patrols),   70032, 70033],
    [localize LSTRING(role_idlers),    70034, 70035],
    [localize LSTRING(role_wanderers), 70036, 70037]
];

private _total = 0;
{
    _x params ["_name", "_sliderIdc", "_labelIdc"];
    private _val = round (sliderPosition (_display displayCtrl _sliderIdc));
    (_display displayCtrl _labelIdc) ctrlSetText format ["%1: %2%%", _name, _val];
    _total = _total + _val;
} forEach _rows;

(_display displayCtrl 70040) ctrlSetText format ["%1: %2%%", localize LSTRING(roleMix_total), _total];
