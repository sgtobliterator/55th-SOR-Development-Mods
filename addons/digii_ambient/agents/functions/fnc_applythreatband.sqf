#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Per-civilian band-transition dispatcher. Called by fnc_threatTick
 * whenever a civilian's threat value crosses into a new band
 * (CALM / ALERT / PANIC). Sets the unit into the target visual/motor
 * state for the new band; direction of transition (up or down) doesn't
 * matter since each band has a single desired state.
 *
 * Per-role state (see plan for the behavior table):
 *
 *   IDLER:
 *     CALM   - disableAI PATH + setUnitPos UP + idle anim
 *     ALERT  - switchMove "" + setUnitPos MIDDLE (crouch, still no PATH)
 *     PANIC  - enableAI PATH + doMove to nearest cover building
 *
 *   WANDERER:
 *     CALM   - clear suppression, enableAI PATH, setUnitPos AUTO,
 *              setSpeedMode LIMITED (tick resumes; PATH was disabled
 *              by the snap-to-cover fallback)
 *     ALERT  - setSpeedMode FULL (run while wanderer tick still runs)
 *     PANIC  - set suppression + flee to nearest cover building (see
 *              _fleeToCover; uses joinSilent grpNull + delayed snap)
 *
 *   CIV_GARRISON:
 *     CALM   - setUnitPos AUTO
 *     ALERT  - (no change; standing in building is alert posture)
 *     PANIC  - setUnitPos DOWN (prone)
 *
 * No-cover fallback: if PANIC fires but no qualifying building is
 * within COVER_SEARCH_RADIUS, the unit goes prone in place.
 *
 * Arguments:
 * 0: Civilian unit <OBJECT>
 * 1: Previous band (informational; not branched on) <STRING>
 * 2: New band ("CALM" | "ALERT" | "PANIC") <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_civ, "CALM", "PANIC"] call digii_ambient_agents_fnc_applyThreatBand
 *
 * Public: No
 */

params [
    ["_unit",    objNull, [objNull]],
    ["_oldBand", "",      [""]],
    ["_newBand", "",      [""]]
];

if (isNull _unit || {!alive _unit}) exitWith {};

private _role = _unit getVariable ["digii_ambient_role", ""];

// Picks the closest building with at least one defined position within
// COVER_SEARCH_RADIUS, or objNull if none. Distance-sorted from
// nearestObjects.
private _findCover = {
    params ["_u"];
    private _candidates = (nearestObjects [_u, ["House", "Building"], COVER_SEARCH_RADIUS])
        select { _x buildingPos -1 isNotEqualTo [] };
    if (_candidates isEqualTo []) exitWith { objNull };
    _candidates select 0
};

// Send the unit to a random buildingPos inside the nearest cover
// building. Falls back to going prone in place if no cover is
// reachable. Detaches from the shared per-zone group so the
// individual doMove + setSpeedMode aren't fought by formation
// behavior, and schedules a delayed setPos snap onto the cover
// position so the unit lands inside regardless of Arma's flaky
// AI pathing through building doors. Returns true if cover was
// found and commanded, false otherwise.
private _fleeToCover = {
    params ["_u"];
    private _bld = [_u] call _findCover;
    if (isNull _bld) exitWith {
        _u setUnitPos "DOWN";
        false
    };
    private _coverPos = selectRandom (_bld buildingPos -1);

    // Private group so this unit's commands aren't overridden by the
    // shared zone group's formation behavior. createGroup later if
    // we want to rejoin on CALM; for v2.0, the new group simply
    // outlives the unit (deleteWhenEmpty cleans it up on death).
    [_u] joinSilent grpNull;

    _u switchMove "";
    _u enableAI "PATH";
    _u setSpeedMode "FULL";
    _u doMove _coverPos;

    // Snap-into-cover fallback: ~COVER_SNAP_DELAY seconds after the
    // doMove, if the unit is still alive and still in the PANIC
    // band, teleport them onto the chosen buildingPos and lock
    // PATH so they hold there. Bypasses doorway pathing failures.
    [
        {
            params ["_unit", "_pos"];
            if (!alive _unit) exitWith {};
            if (_unit getVariable ["digii_ambient_threatBand", "CALM"] != "PANIC") exitWith {};
            _unit setPos _pos;
            _unit disableAI "PATH";
            _unit setUnitPos "MIDDLE";
        },
        [_u, _coverPos],
        COVER_SNAP_DELAY
    ] call CBA_fnc_waitAndExecute;

    true
};

// Belt-and-suspenders reset applied on PANIC -> ALERT/CALM transitions
// for Idler/Wanderer: cancel any in-flight doMove from _fleeToCover and
// restore the SAFE/BLUE baseline so the band's subsequent setUnitPos /
// setSpeedMode commands actually stick. Civilians have AUTOCOMBAT/FSM
// disabled at spawn (fnc_spawnSoloUnit), so danger.fsm shouldn't be
// overriding anymore -- but _fleeToCover still leaves setSpeedMode FULL
// and (post-snap) setUnitPos MIDDLE behind that we must explicitly undo.
private _resetMotor = {
    params ["_u"];
    doStop _u;
    _u setBehaviour "SAFE";
    _u setCombatMode "BLUE";
};

switch (_role) do {
    case ROLE_IDLER: {
        switch (_newBand) do {
            case "CALM": {
                [_unit] call _resetMotor;
                _unit disableAI "PATH";
                _unit setUnitPos "UP";
                _unit switchMove (selectRandom IDLE_ANIMS);
            };
            case "ALERT": {
                [_unit] call _resetMotor;
                _unit switchMove "";
                _unit setUnitPos "MIDDLE";
            };
            case "PANIC": {
                _unit setVariable ["digii_ambient_suppressed", true, true];
                [_unit] call _fleeToCover;
            };
        };
    };

    case ROLE_WANDERER: {
        switch (_newBand) do {
            case "CALM": {
                _unit setVariable ["digii_ambient_suppressed", false, true];
                [_unit] call _resetMotor;
                _unit enableAI "PATH";          // snap-to-cover disables PATH; re-enable to wander out
                _unit setUnitPos "UP";
                _unit setSpeedMode "LIMITED";
                // wandererTick will issue a fresh doMove on its next fire.
            };
            case "ALERT": {
                _unit setVariable ["digii_ambient_suppressed", false, true];
                [_unit] call _resetMotor;
                _unit setSpeedMode "LIMITED";
                _unit setUnitPos "MIDDLE";
            };
            case "PANIC": {
                _unit setVariable ["digii_ambient_suppressed", true, true];
                [_unit] call _fleeToCover;
            };
        };
    };

    case ROLE_CIV_GARRISON: {
        switch (_newBand) do {
            case "CALM":  { _unit setUnitPos "UP"; };
            case "ALERT": { /* no change -- standing in building */ };
            case "PANIC": { _unit setUnitPos "DOWN"; };
        };
    };

    // Unknown role -- no-op (military roles never reach this dispatcher
    // because they never get fnc_initCivilianThreat called on them).
    default {};
};
