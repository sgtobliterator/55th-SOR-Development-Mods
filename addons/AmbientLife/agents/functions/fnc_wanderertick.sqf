#include "..\script_component.hpp"

/*
 * Author: DiGii
 * One "wandering" step for a lone WANDERER unit. Picks a fresh random
 * in-zone position, doMoves there, then re-schedules itself via
 * CBA_fnc_waitAndExecute for [WANDERER_PAUSE_MIN..WANDERER_PAUSE_MAX] seconds.
 *
 * The function is both the entry point and the recursion target: call it
 * once to start the cycle, it will keep rescheduling itself until the unit
 * is no longer alive (deleteVehicle from despawn, killed in combat, etc.),
 * at which point the alive check fails and no further callback is scheduled
 * - the loop dies cleanly with no extra cleanup.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Center <ARRAY>
 * 2: Radius <NUMBER>
 * 3: Use roads (optional, default false) <BOOL>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_unit, _center, 75, true] call digii_ambient_agents_fnc_wandererTick
 *
 * Public: No
 */

params ["_unit", "_center", "_radius", ["_useRoads", false, [false]]];
if (!alive _unit) exitWith {};

// Skip the doMove step when suppressed (civilian panic; the threat-band
// dispatcher has commanded the unit to cover and we don't want this tick
// to yank it back out). Always reschedule so the unit resumes wandering
// once the flag clears on return-to-CALM. Military Wanderers never have
// the suppression flag set -- this is a no-op for them.
if (!(_unit getVariable ["digii_ambient_suppressed", false])) then {
    private _pos = [_center, _radius, _useRoads] call FUNC(pickPosWithRoadBias);
    _unit doMove _pos;
};

private _delay = WANDERER_PAUSE_MIN + random (WANDERER_PAUSE_MAX - WANDERER_PAUSE_MIN);
[FUNC(wandererTick), [_unit, _center, _radius, _useRoads], _delay] call CBA_fnc_waitAndExecute;
