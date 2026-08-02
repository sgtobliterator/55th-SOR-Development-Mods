#include "..\script_component.hpp"

/*
 * Author: DiGii
 * One-time per-civilian init for the threat system. Called by the spawn
 * pipeline (fnc_spawnSoloUnit + fnc_garrisonBuilding) for every passive
 * unit at runtime. Sets the passive marker, primes the threat var to
 * zero, attaches FiredNear + Killed event handlers, and starts the
 * decay tick.
 *
 * The passive marker (`digii_ambient_passive = true`) is the canonical
 * "this is a civilian we should scare" flag -- the Killed propagation
 * uses it to filter neighbors so military Idler / Wanderer units (which
 * share role tags with civilians) don't get bumped.
 *
 * No-op in 3DEN editor mode: EHs and ticks are runtime-only; on preview,
 * the spawn pipeline reruns and re-initializes.
 *
 * Arguments:
 * 0: Civilian unit <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_civ] call digii_ambient_agents_fnc_initCivilianThreat
 *
 * Public: No
 */

params [["_unit", objNull, [objNull]]];
if (isNull _unit) exitWith {};
if (is3DEN) exitWith {};

_unit setVariable ["digii_ambient_passive", true, true];
_unit setVariable ["digii_ambient_threat", 0, true];
_unit setVariable ["digii_ambient_threatBand", "CALM", true];
_unit setVariable ["digii_ambient_suppressed", false, true];

// FiredNear: any shot within THREAT_GUNFIRE_RADIUS scares this civilian.
// Re-check distance against our tunable since the engine's default
// FiredNear range may differ. Ignore self-fired events (civilians have
// weapons <= 2 in practice, but be safe).
_unit addEventHandler ["FiredNear", {
    params ["_unit", "_firer", "_distance"];
    if (_firer isEqualTo _unit) exitWith {};
    if (_distance > THREAT_GUNFIRE_RADIUS) exitWith {};
    [_unit, THREAT_GUNFIRE_STEP] call FUNC(threatAdd);
}];

// Killed: when this civilian dies, propagate one-shot panic to alive
// civilians within THREAT_DEATH_RADIUS. Filter by the passive marker so
// only other civilians get the bump (military Idler / Wanderer share
// role tags but lack the marker).
_unit addEventHandler ["Killed", {
    params ["_unit"];
    private _nearby = _unit nearObjects ["CAManBase", THREAT_DEATH_RADIUS];
    {
        if (_x isNotEqualTo _unit && {alive _x} && {_x getVariable ["digii_ambient_passive", false]}) then {
            [_x, THREAT_DEATH_STEP] call FUNC(threatAdd);
        };
    } forEach _nearby;
}];

// Start the decay tick. Self-reschedules until the unit dies.
[FUNC(threatTick), [_unit], THREAT_TICK_INTERVAL] call CBA_fnc_waitAndExecute;
