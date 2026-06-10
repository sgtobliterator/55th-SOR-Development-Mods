#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Dialog onLoad handler. Waits for the display to be ready, then populates
 * every control from the logic's current setVariable values. Populates the
 * sub-faction combo via lbAdd/lbSetData (the ZEI pattern that works inside
 * an RscDisplay, unlike the 3DEN attribute panel).
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
(_display displayCtrl 70080) ctrlSetText "";

// Numeric / text / checkbox controls
if (!isNull _logic) then {
    (_display displayCtrl 70010) ctrlSetText str (_logic getVariable ["digii_ambient_zone_radius", 75]);
    (_display displayCtrl 70013) ctrlSetText str (_logic getVariable ["digii_ambient_zone_density", 5]);
    (_display displayCtrl 70014) cbSetChecked (_logic getVariable ["digii_ambient_zone_useBuildings", true]);
    (_display displayCtrl 70015) cbSetChecked (_logic getVariable ["digii_ambient_zone_useRoads", true]);
    (_display displayCtrl 70016) ctrlSetText str (_logic getVariable ["digii_ambient_zone_skillCap", 0.2]);
    (_display displayCtrl 70017) cbSetChecked (_logic getVariable ["digii_ambient_zone_includeOfficer", false]);
};

// Sub-faction combo (dynamic from enumerated cache, sorted by label)
private _combo = _display displayCtrl 70011;
private _cache = [] call digii_ambient_factions_fnc_enumerateSubFactions;
lbClear _combo;
private _rows = (values _cache) apply { [_x get "label", _x get "id"] };
_rows sort true;

private _currentSub = if (!isNull _logic) then { _logic getVariable ["digii_ambient_zone_subFactionId", ""] } else { "" };
private _selIdx = -1;
{
    _x params ["_lbl", "_id"];
    private _idx = _combo lbAdd _lbl;
    _combo lbSetData [_idx, _id];
    if (_id == _currentSub) then { _selIdx = _idx };
} forEach _rows;
if (_selIdx > -1) then { _combo lbSetCurSel _selIdx };

// Role mix sliders (0-100) + initial value labels via updateRoleMixDisplay.
// Legacy 5-slot mix (G,P,I,Exerciser,W) migrates to 4-slot (G,P,I,W) by
// dropping slot 3 (Exerciser).
private _roleMix = if (!isNull _logic) then {
    _logic getVariable ["digii_ambient_zone_roleMix", [50, 25, 15, 10]]
} else {
    [50, 25, 15, 10]
};
if (count _roleMix == 5) then { _roleMix = [_roleMix#0, _roleMix#1, _roleMix#2, _roleMix#4] };

private _sliderIdcs = [70030, 70032, 70034, 70036];
{
    private _ctrl = _display displayCtrl _x;
    _ctrl sliderSetRange [0, 100];
    _ctrl sliderSetPosition (_roleMix select _forEachIndex);
} forEach _sliderIdcs;

[] call FUNC(updateRoleMixDisplay);
