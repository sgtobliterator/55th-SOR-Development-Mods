#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Per-role behavior dispatcher for solo-spawned units. Called from
 * fnc_spawnSoloUnit after the unit is created and tagged. Branches on is3DEN
 * so runtime spawns get direct commands and 3DEN-placed units get equivalent
 * code stamped into their Init attribute (executed on mission preview).
 *
 * Garrisoned units (created in fnc_garrisonBuilding) bypass this dispatcher;
 * they have their own bespoke setup inline.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Role; one of ROLE_* <STRING>
 * 2: Zone center (used by WANDERER deferred Init) <ARRAY>
 * 3: Zone radius (used by WANDERER deferred Init) <NUMBER>
 * 4: Use roads (optional, default false) <BOOL>
 * 5: Passive (civilian) baseline (optional, default false) <BOOL>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_unit, ROLE_WANDERER, _center, 75, true] call digii_ambient_agents_fnc_applyRoleBehavior
 * [_unit, ROLE_WANDERER, _center, 75, true, true] call digii_ambient_agents_fnc_applyRoleBehavior
 *
 * Public: No
 */

params [
    "_unit", "_role", "_center", "_radius",
    ["_useRoads", false, [false]],
    ["_passive", false, [false]]
];
if (isNull _unit) exitWith {};

private _combatMode = if (_passive) then { "BLUE" } else { "YELLOW" };

// Suffix appended to the 3DEN Init stamp for passive (civilian) units.
// Carries two things at mission preview:
//   - threat-system self-init (FiredNear/Killed EHs + decay tick)
//   - disableAI AUTOCOMBAT/FSM so danger.fsm doesn't override our
//     setUnitPos / setSpeedMode commands (mirrors the runtime path
//     in fnc_spawnSoloUnit)
// The Init attribute persists through mission.sqm save/load; module
// logic setVariables do not, so the per-unit Init is the reliable carrier.
private _civInitSuffix = if (_passive) then {
    " this disableAI 'AUTOCOMBAT'; this disableAI 'FSM'; [this] call digii_ambient_agents_fnc_initCivilianThreat;"
} else {
    ""
};

switch (_role) do {
    case ROLE_IDLER: {
        private _dir = floor (random 360);
        private _anim = selectRandom IDLE_ANIMS;
        if (is3DEN) then {
            _unit set3DENAttribute ["rotation", [0, 0, _dir]];
            _unit set3DENAttribute ["Init", (format [
                "this setVariable ['digii_ambient_role', '%2']; this disableAI 'PATH'; this setUnitPos 'UP'; this switchMove '%1';",
                _anim, _role
            ]) + _civInitSuffix];
        } else {
            _unit disableAI "PATH";
            _unit setUnitPos "UP";
            _unit setDir _dir;
            _unit switchMove _anim;
        };
    };

    case ROLE_WANDERER: {
        // Lone random walk in SAFE behaviour at LIMITED speed. Self-rescheduling
        // tick via CBA_fnc_waitAndExecute; exits when the unit dies / is deleted.
        // _useRoads threads to wandererTick so each new target prefers roads.
        // Civilian (_passive) variant pins CombatMode BLUE so they never engage
        // even if armed.
        if (is3DEN) then {
            _unit set3DENAttribute ["Init", (format [
                "this setVariable ['digii_ambient_role', '%5']; this setBehaviour 'SAFE'; this setCombatMode '%4'; this setSpeedMode 'LIMITED'; [this, %1, %2, %3] call digii_ambient_agents_fnc_wandererTick;",
                _center,
                _radius,
                _useRoads,
                _combatMode,
                _role
            ]) + _civInitSuffix];
        } else {
            _unit setBehaviour "SAFE";
            _unit setCombatMode _combatMode;
            _unit setSpeedMode "LIMITED";
            [_unit, _center, _radius, _useRoads] call FUNC(wandererTick);
        };
    };

    // PATROL handled inline by fnc_spawnPatrolGroup (own group + 3DEN waypoint
    // entities); never reaches this dispatcher.

    case ROLE_OFFICER: {
        // Center-biased defender. PATH stays disabled so they hold position;
        // AWARE behaviour (more alert than the SAFE baseline). Combat AI is
        // already enabled by the spawnSoloUnit fight-back baseline -- no
        // enableAI calls needed here. Visually distinguished by the
        // officer-class uniform (from getSubFactionOfficers) more than the
        // animation; reusing IDLE_ANIMS for now.
        private _dir = floor (random 360);
        private _anim = selectRandom IDLE_ANIMS;
        if (is3DEN) then {
            _unit set3DENAttribute ["rotation", [0, 0, _dir]];
            _unit set3DENAttribute ["Init", format [
                "this setVariable ['digii_ambient_role', '%2']; this disableAI 'PATH'; this setUnitPos 'UP'; this setBehaviour 'AWARE'; this setCombatMode 'YELLOW'; this switchMove '%1';",
                _anim, _role
            ]];
        } else {
            _unit disableAI "PATH";
            _unit setUnitPos "UP";
            _unit setBehaviour "AWARE";
            _unit setCombatMode "YELLOW";
            _unit setDir _dir;
            _unit switchMove _anim;
        };
    };

    default {}; // GUARD handled by garrisonBuilding inline; unknown roles no-op
};
