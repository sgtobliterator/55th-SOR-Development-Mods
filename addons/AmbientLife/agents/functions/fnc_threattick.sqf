#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Self-rescheduling threat-decay tick for a single civilian. Subtracts
 * THREAT_DECAY_PER_TICK from the unit's threat each fire, clamped /
 * rounded by fnc_threatAdd. Re-schedules itself via CBA_fnc_waitAndExecute
 * every THREAT_TICK_INTERVAL seconds while the unit is alive; exits
 * cleanly when the unit dies / is deleted (alive check fails -> no
 * further callback scheduled, no PFH to clean up). Mirrors the
 * fnc_wandererTick pattern.
 *
 * Arguments:
 * 0: Civilian unit <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_civ] call digii_ambient_agents_fnc_threatTick
 *
 * Public: No
 */

params [["_unit", objNull, [objNull]]];
if (!alive _unit) exitWith {};

private _t = _unit getVariable ["digii_ambient_threat", 0];
if (_t > 0) then {
    [_unit, -THREAT_DECAY_PER_TICK] call FUNC(threatAdd);
};

// Edge-triggered band dispatch: compute the band the unit *should* be
// in after this tick's decay, compare to the band it's currently in,
// and only dispatch on transitions. Keeps applyThreatBand a one-shot
// state setter rather than a per-tick reaffirmation.
private _newT = _unit getVariable ["digii_ambient_threat", 0];
private _newBand = if (_newT >= THREAT_BAND_PANIC) then {
    "PANIC"
} else {
    if (_newT >= THREAT_BAND_ALERT) then { "ALERT" } else { "CALM" }
};
private _oldBand = _unit getVariable ["digii_ambient_threatBand", "CALM"];
if (_newBand != _oldBand) then {
    _unit setVariable ["digii_ambient_threatBand", _newBand, true];
    [_unit, _oldBand, _newBand] call FUNC(applyThreatBand);
};

[FUNC(threatTick), [_unit], THREAT_TICK_INTERVAL] call CBA_fnc_waitAndExecute;
