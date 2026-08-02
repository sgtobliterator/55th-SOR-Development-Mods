#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Spawns one unit at a random position within the zone. Shared by all
 * non-garrison roles. Each solo unit lives alone in its own group so
 * doMove + setSpeedMode commands are individual (no formation
 * interference between roles, no cascade-delete when one role's command
 * empties a shared group).
 *
 * Arguments:
 * 0: Side for the per-unit group <SIDE>
 * 1: Center <ARRAY>
 * 2: Radius <NUMBER>
 * 3: Unit pool of classnames <ARRAY>
 * 4: Skill cap <NUMBER>
 * 5: Zone id <STRING>
 * 6: Role <STRING>
 * 7: Use roads (optional, default false) <BOOL>
 * 8: Passive (civilian) baseline (optional, default false) <BOOL>
 *
 * Return Value:
 * Created unit; objNull on failure <OBJECT>
 *
 * Example:
 * [east, _center, 75, _pool, 0.2, "zone_1", ROLE_IDLER, true] call digii_ambient_agents_fnc_spawnSoloUnit
 * [civilian, _center, 75, _pool, 0.2, "civ_1", ROLE_WANDERER, true, true] call digii_ambient_agents_fnc_spawnSoloUnit
 *
 * Public: No
 */

params [
    "_side", "_center", "_radius", "_unitPool", "_skillCap", "_zoneId", "_role",
    ["_useRoads", false, [false]],
    ["_passive", false, [false]]
];

private _pos = [_center, _radius, _useRoads] call FUNC(pickPosWithRoadBias);
private _unitClass = selectRandom _unitPool;

private _entity = if (is3DEN) then {
    // 3DEN: unary create3DENEntity gives each solo unit a fresh group
    // (the default 3DEN behavior). Suitable for IDLER / WANDERER /
    // OFFICER -- they don't share groups.
    create3DENEntity ["Object", _unitClass, _pos]
} else {
    // Runtime: createGroup [_side, true] per unit so each lives alone
    // in its own deleteWhenEmpty group. Avoids the previous "shared
    // zone group + joinSilent grpNull" pattern that cascade-deleted
    // the shared group and broke subsequent spawns.
    private _unitGrp = createGroup [_side, true];
    _unitGrp createUnit [_unitClass, _pos, [], 0, "NONE"]
};

if (isNull _entity) exitWith { objNull };

// Baseline:
//   Military: SAFE/YELLOW -- weapons low at rest, engages when fired upon.
//   Civilian (passive): SAFE/BLUE -- never engages.
// PATH disabling for static roles (Idler) happens per-role in applyRoleBehavior.
_entity setBehaviour "SAFE";
_entity setCombatMode (if (_passive) then { "BLUE" } else { "YELLOW" });
_entity setSkill _skillCap;
_entity setVariable ["digii_ambient_zoneId", _zoneId];
_entity setVariable ["digii_ambient_role", _role];

// Civilians: drop the engine's danger.fsm out of the loop. Our threat
// system fully covers panic / flee-to-cover, and civilians are pinned
// to combatMode BLUE so danger.fsm's combat escalation is dead weight
// that actively overrides our setUnitPos / setSpeedMode commands.
// Military units keep danger.fsm -- they need it for combat.
if (_passive) then {
    _entity disableAI "AUTOCOMBAT";
    _entity disableAI "FSM";
};

[_entity, _role, _center, _radius, _useRoads, _passive] call FUNC(applyRoleBehavior);

// Civilian threat-system hookup. Only runtime; 3DEN editor units
// self-init via their stamped Init attribute at preview.
if (_passive && {!is3DEN}) then {
    [_entity] call FUNC(initCivilianThreat);
};

_entity
