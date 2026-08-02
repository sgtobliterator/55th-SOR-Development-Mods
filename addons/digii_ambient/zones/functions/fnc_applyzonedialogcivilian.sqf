#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Civilian dialog Apply handler. Reads dialog values, validates them
 * (fail-fast on first error via in-dialog FeedbackText), normalizes
 * 3-slot role mix to sum=100, writes everything to the logic via
 * setVariable on `digii_ambient_civZone_*` keys.
 *
 * Branches by context:
 *   - 3DEN: respawn from updated logic state via respawnModuleZoneCivilian.
 *   - Zeus / runtime: stamp placerUid + call registerFromLogicCivilian.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * Invoked by the dialog's Apply button (onButtonClick); do not call manually.
 *
 * Public: No
 */

private _display = findDisplay 70100;
if (isNull _display) exitWith {};

private _logic = GVAR(currentDialogLogic);
if (isNil "_logic" || {isNull _logic}) exitWith {
    diag_log "[digii_ambient] applyZoneDialogCivilian: no current logic";
    _display closeDisplay 1;
};

private _feedback = _display displayCtrl 70180;

// ===== READ ALL VALUES =====

private _radius   = parseNumber (ctrlText (_display displayCtrl 70110));
private _density  = parseNumber (ctrlText (_display displayCtrl 70113));

private _subCombo = _display displayCtrl 70111;
private _subSel = lbCurSel _subCombo;
private _subId = if (_subSel >= 0) then { _subCombo lbData _subSel } else { "" };

private _raw = [70130, 70132, 70134] apply { sliderPosition (_display displayCtrl _x) };
private _sum = (_raw select 0) + (_raw select 1) + (_raw select 2);

// ===== VALIDATION (fail-fast, in-dialog feedback) =====

if (_subId == "") exitWith {
    _feedback ctrlSetText (localize LSTRING(validation_subFactionRequired));
    diag_log "[digii_ambient] applyZoneDialogCivilian: rejected (empty sub-faction)";
};

if (_radius <= 0 || _radius > MAX_ZONE_RADIUS) exitWith {
    _feedback ctrlSetText format [localize LSTRING(validation_radiusRange), MAX_ZONE_RADIUS];
    diag_log format ["[digii_ambient] applyZoneDialogCivilian: rejected (radius=%1)", _radius];
};

if (_density < 1 || _density > 10) exitWith {
    _feedback ctrlSetText (localize LSTRING(validation_densityRange));
    diag_log format ["[digii_ambient] applyZoneDialogCivilian: rejected (density=%1)", _density];
};

if (_sum <= 0) exitWith {
    _feedback ctrlSetText (localize LSTRING(validation_roleMixZero));
    diag_log "[digii_ambient] applyZoneDialogCivilian: rejected (role mix sum = 0)";
};

// ===== NORMALIZE ROLE MIX (validation guarantees _sum > 0) =====

private _roleMix = _raw apply { round (_x / _sum * 100) };
// Absorb rounding drift into the last slot so the array sums to exactly 100.
private _adjusted = (_roleMix select 0) + (_roleMix select 1);
_roleMix set [2, 100 - _adjusted];

// ===== SAVE TO LOGIC =====

_logic setVariable ["digii_ambient_civZone_radius",       _radius,                                 true];
_logic setVariable ["digii_ambient_civZone_subFactionId", _subId,                                  true];
_logic setVariable ["digii_ambient_civZone_density",      _density,                                true];
_logic setVariable ["digii_ambient_civZone_useBuildings", cbChecked (_display displayCtrl 70114), true];
_logic setVariable ["digii_ambient_civZone_useRoads",     cbChecked (_display displayCtrl 70115), true];
_logic setVariable ["digii_ambient_civZone_roleMix",      _roleMix,                                true];

if (is3DEN) then {
    // 3DEN spawn: delegate to respawnModuleZoneCivilian which despawns
    // any existing tracked civilians first, then spawns fresh from the
    // logic's current state.
    [_logic] call FUNC(respawnModuleZoneCivilian);
    _display closeDisplay 1;
} else {
    // Zeus / runtime: settings are already broadcast via the
    // setVariable [..., ..., true] calls above. Route the actual
    // spawn to the server via CBA -- registerFromLogicCivilian is
    // gated on isServer, so calling it directly here would no-op on
    // a dedicated where the placing client != server.
    _logic setVariable ["digii_ambient_civZone_placerUid", getPlayerUID player, true];
    [QGVAR(applyZoneCivilianServer), [_logic]] call CBA_fnc_serverEvent;
    _display closeDisplay 1;
};
