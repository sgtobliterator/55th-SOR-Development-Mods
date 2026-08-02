#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Civilian dialog slider onSliderPosChanged handler. Reads all 3
 * role-mix sliders, rewrites each value label with the rounded
 * percentage, and updates the total indicator. Shared across all 3
 * civilian sliders.
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

private _display = findDisplay 70100;
if (isNull _display) exitWith {};

private _rows = [
    [localize LSTRING(role_residents), 70130, 70131],
    [localize LSTRING(role_idlers),    70132, 70133],
    [localize LSTRING(role_wanderers), 70134, 70135]
];

private _total = 0;
{
    _x params ["_name", "_sliderIdc", "_labelIdc"];
    private _val = round (sliderPosition (_display displayCtrl _sliderIdc));
    (_display displayCtrl _labelIdc) ctrlSetText format ["%1: %2%%", _name, _val];
    _total = _total + _val;
} forEach _rows;

(_display displayCtrl 70140) ctrlSetText format ["%1: %2%%", localize LSTRING(roleMix_total), _total];
