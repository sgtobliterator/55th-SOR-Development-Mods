#include "..\script_component.hpp"
/*
    Function: digii_zet_main_fnc_slider_onAttributeSave

    Description:
        Returns the current slider position as the attribute's stored value.

    Parameters:
        0: CONTROL - The controls group (passed by 3DEN as attributeSave's _this)

    Returns:
        NUMBER - Slider position in real units (e.g. 100..10000 m)
*/

params ["_ctrlGroup"];

sliderPosition (_ctrlGroup controlsGroupCtrl IDC_ZET_RANGE_SLIDER)
