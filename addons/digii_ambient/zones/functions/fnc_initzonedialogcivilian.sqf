#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Civilian dialog onLoad handler. Sibling of fnc_initZoneDialog.
 * Populates every control from the civilian logic's setVariable values
 * (`digii_ambient_civZone_*`); fills the sub-faction combo from the
 * civilian sub-faction cache.
 *
 * Arguments:
 * 0: Dialog display <DISPLAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * Invoked from the dialog's onLoad event; do not call manually.
 *
 * Public: No
 */

params ["_display"];

waitUntil { !isNull _display };

private _logic = GVAR(currentDialogLogic);
if (isNil "_logic") then { _logic = objNull };

// Reset the feedback line every time the dialog opens
(_display displayCtrl 70180) ctrlSetText "";

// Numeric / text / checkbox controls
if (!isNull _logic) then {
    (_display displayCtrl 70110) ctrlSetText str (_logic getVariable ["digii_ambient_civZone_radius", 75]);
    (_display displayCtrl 70113) ctrlSetText str (_logic getVariable ["digii_ambient_civZone_density", 5]);
    (_display displayCtrl 70114) cbSetChecked (_logic getVariable ["digii_ambient_civZone_useBuildings", true]);
    (_display displayCtrl 70115) cbSetChecked (_logic getVariable ["digii_ambient_civZone_useRoads", true]);
};

// Sub-faction combo (civilian cache, sorted by label)
private _combo = _display displayCtrl 70111;
if (isNil QEGVAR(factions,subFactionsCivilian)) then {
    [] call EFUNC(factions,enumerateSubFactions);
};
private _cache = EGVAR(factions,subFactionsCivilian);
lbClear _combo;
private _rows = (values _cache) apply { [_x get "label", _x get "id"] };
_rows sort true;

private _currentSub = if (!isNull _logic) then { _logic getVariable ["digii_ambient_civZone_subFactionId", ""] } else { "" };
private _selIdx = -1;
{
    _x params ["_lbl", "_id"];
    private _idx = _combo lbAdd _lbl;
    _combo lbSetData [_idx, _id];
    if (_id == _currentSub) then { _selIdx = _idx };
} forEach _rows;
if (_selIdx > -1) then { _combo lbSetCurSel _selIdx };

// Role mix sliders (0-100) + initial value labels via updateRoleMixDisplayCivilian.
// 3-slot: [Residents, Idlers, Wanderers].
private _roleMix = if (!isNull _logic) then {
    _logic getVariable ["digii_ambient_civZone_roleMix", [34, 33, 33]]
} else {
    [34, 33, 33]
};

private _sliderIdcs = [70130, 70132, 70134];
{
    private _ctrl = _display displayCtrl _x;
    _ctrl sliderSetRange [0, 100];
    _ctrl sliderSetPosition (_roleMix select _forEachIndex);
} forEach _sliderIdcs;

[] call FUNC(updateRoleMixDisplayCivilian);
