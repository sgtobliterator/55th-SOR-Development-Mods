#include "..\script_component.hpp"
/*
    Function: digii_zet_main_fnc_slider_onAttributeLoad

    Description:
        Wires the XSlider + Edit pair inside a ZET_NumberSlider controls group
        so they stay in sync, then seeds the controls with the stored value.

    Parameters:
        0: CONTROL - The controls group (passed by 3DEN as attributeLoad's _this)
        1: NUMBER  - The saved attribute value

    Returns:
        Nothing
*/

params ["_ctrlGroup", "_value"];

private _slider = _ctrlGroup controlsGroupCtrl IDC_ZET_RANGE_SLIDER;
private _edit   = _ctrlGroup controlsGroupCtrl IDC_ZET_RANGE_EDIT;

// Cross-reference so each handler can find its partner
_slider setVariable [QGVAR(sliderEdit), _edit];
_edit   setVariable [QGVAR(sliderCtrl), _slider];

// Seed initial values
_slider sliderSetPosition _value;
_edit   ctrlSetText format ["%1 m", round _value];

// Slider drag -> update edit live
_slider ctrlAddEventHandler ["SliderPosChanged", {
    params ["_ctrl", "_pos"];
    private _edit = _ctrl getVariable QGVAR(sliderEdit);
    if (!isNil "_edit") then {
        _edit ctrlSetText format ["%1 m", round _pos];
    };
}];

// Edit text -> update slider on focus loss
_edit ctrlAddEventHandler ["KillFocus", {
    params ["_ctrl"];
    private _slider = _ctrl getVariable QGVAR(sliderCtrl);
    if (isNil "_slider") exitWith {};
    private _typed = parseNumber (ctrlText _ctrl);
    _slider sliderSetPosition _typed;
    // Echo back the (possibly clamped) value
    private _pos = sliderPosition _slider;
    _ctrl ctrlSetText format ["%1 m", round _pos];
}];
