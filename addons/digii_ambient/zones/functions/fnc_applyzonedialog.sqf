#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Apply button handler. Reads dialog values, validates them (fail-fast on
 * first error via in-dialog FeedbackText), normalizes role mix to sum=100,
 * writes everything to the logic via setVariable.
 *
 * Branches by context:
 *   - 3DEN: respawn from updated logic state.
 *   - Zeus / runtime: stamp placerUid + call fnc_registerFromLogic.
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

private _display = findDisplay 70000;
if (isNull _display) exitWith {};

private _logic = GVAR(currentDialogLogic);
if (isNil "_logic" || {isNull _logic}) exitWith {
    diag_log "[digii_ambient] applyZoneDialog: no current logic";
    _display closeDisplay 1;
};

private _feedback = _display displayCtrl 70080;

// ===== READ ALL VALUES =====

private _radius   = parseNumber (ctrlText (_display displayCtrl 70010));
private _density  = parseNumber (ctrlText (_display displayCtrl 70013));
private _skillCap = parseNumber (ctrlText (_display displayCtrl 70016));

private _subCombo = _display displayCtrl 70011;
private _subSel = lbCurSel _subCombo;
private _subId = if (_subSel >= 0) then { _subCombo lbData _subSel } else { "" };

private _raw = [70030, 70032, 70034, 70036] apply { sliderPosition (_display displayCtrl _x) };
private _sum = (_raw select 0) + (_raw select 1) + (_raw select 2) + (_raw select 3);

// ===== VALIDATION (fail-fast, in-dialog feedback) =====

if (_subId == "") exitWith {
    _feedback ctrlSetText (localize LSTRING(validation_subFactionRequired));
    diag_log "[digii_ambient] applyZoneDialog: rejected (empty sub-faction)";
};

if (_radius <= 0 || _radius > MAX_ZONE_RADIUS) exitWith {
    _feedback ctrlSetText format [localize LSTRING(validation_radiusRange), MAX_ZONE_RADIUS];
    diag_log format ["[digii_ambient] applyZoneDialog: rejected (radius=%1)", _radius];
};

if (_density < 1 || _density > 10) exitWith {
    _feedback ctrlSetText (localize LSTRING(validation_densityRange));
    diag_log format ["[digii_ambient] applyZoneDialog: rejected (density=%1)", _density];
};

if (_skillCap < 0 || _skillCap > 1) exitWith {
    _feedback ctrlSetText (localize LSTRING(validation_skillCapRange));
    diag_log format ["[digii_ambient] applyZoneDialog: rejected (skillCap=%1)", _skillCap];
};

if (_sum <= 0) exitWith {
    _feedback ctrlSetText (localize LSTRING(validation_roleMixZero));
    diag_log "[digii_ambient] applyZoneDialog: rejected (role mix sum = 0)";
};

// ===== NORMALIZE ROLE MIX (validation guarantees _sum > 0) =====

private _roleMix = _raw apply { round (_x / _sum * 100) };
// Absorb rounding drift into the last slot so the array sums to exactly 100.
private _adjusted = (_roleMix select 0) + (_roleMix select 1) + (_roleMix select 2);
_roleMix set [3, 100 - _adjusted];

// ===== SAVE TO LOGIC =====

_logic setVariable ["digii_ambient_zone_radius",         _radius,                                 true];
_logic setVariable ["digii_ambient_zone_subFactionId",   _subId,                                  true];
_logic setVariable ["digii_ambient_zone_density",        _density,                                true];
_logic setVariable ["digii_ambient_zone_useBuildings",   cbChecked (_display displayCtrl 70014), true];
_logic setVariable ["digii_ambient_zone_useRoads",       cbChecked (_display displayCtrl 70015), true];
_logic setVariable ["digii_ambient_zone_skillCap",       _skillCap,                               true];
_logic setVariable ["digii_ambient_zone_includeOfficer", cbChecked (_display displayCtrl 70017), true];
_logic setVariable ["digii_ambient_zone_roleMix",        _roleMix,                                true];

if (is3DEN) then {
    // 3DEN spawn: delegate to respawnModuleZone which despawns any existing
    // tracked entities first, then spawns fresh from the logic's current state.
    [_logic] call FUNC(respawnModuleZone);
    _display closeDisplay 1;
} else {
    // Zeus / runtime: settings are already broadcast via the
    // setVariable [..., ..., true] calls above. Route the actual
    // spawn to the server via CBA -- registerFromLogic is gated on
    // isServer, so calling it directly here would no-op on a
    // dedicated where the placing client != server.
    _logic setVariable ["digii_ambient_zone_placerUid", getPlayerUID player, true];
    [QGVAR(applyZoneServer), [_logic]] call CBA_fnc_serverEvent;
    _display closeDisplay 1;
};
