#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Turns (count, roleMix, includeOfficer, kind) into a shuffled array of
 * role strings of length _count. Each entry is one of ROLE_* from
 * script_component.
 *
 * Algorithm:
 *   1. Military kind only: if officer requested AND count >= 1, reserve
 *      1 slot for OFFICER, distribute the rest across the 4-slot mix.
 *      Civilian kind ignores _includeOfficer.
 *   2. Per-slot target = round(remaining * mix[i] / sum(mix)).
 *   3. Drift between sum(targets) and remaining is absorbed by the
 *      largest slot so the output length matches exactly.
 *   4. Fisher-Yates shuffle, then (military) officer inserted at a
 *      random index.
 *
 * Kind-dependent shape:
 *   - military: 4-slot mix [Guard, Patrol, Idler, Wanderer]
 *   - civilian: 3-slot mix [CivGarrison, Idler, Wanderer]
 *
 * Arguments:
 * 0: Total units to assign <NUMBER>
 * 1: Role mix; per-slot 0-100, length depends on kind <ARRAY>
 * 2: Include officer (military only) <BOOL>
 * 3: Kind ("military" or "civilian", optional, default "military") <STRING>
 *
 * Return Value:
 * Role strings of length _count <ARRAY>
 *
 * Example:
 * [10, [50, 25, 15, 10], true, "military"] call digii_ambient_agents_fnc_distributeRoles
 * [10, [34, 33, 33],     false, "civilian"] call digii_ambient_agents_fnc_distributeRoles
 *
 * Public: No
 */

params [
    ["_count",          0,          [0]],
    ["_roleMix",        [],         [[]]],
    ["_includeOfficer", false,      [true]],
    ["_kind",           "military", [""]]
];

if (_count <= 0) exitWith {[]};

private _isCivilian = _kind == "civilian";
private _roleClasses = if (_isCivilian) then {
    [ROLE_CIV_GARRISON, ROLE_IDLER, ROLE_WANDERER]
} else {
    [ROLE_GUARD, ROLE_PATROL, ROLE_IDLER, ROLE_WANDERER]
};
private _slots = count _roleClasses;

// Defensive: pad short mix arrays with zeros so `select i` is always safe.
private _mix = +_roleMix;
while {count _mix < _slots} do { _mix pushBack 0 };

private _reserveOfficer = !_isCivilian && _includeOfficer && {_count >= 1};
private _remaining = if (_reserveOfficer) then { _count - 1 } else { _count };

private _result = [];

if (_remaining > 0) then {
    private _mixSum = 0;
    { _mixSum = _mixSum + _x } forEach _mix;

    if (_mixSum <= 0) then {
        // Pathological input: all-zero mix but we still need _remaining slots.
        // Fall back to all IDLER (least surprising).
        for "_i" from 1 to _remaining do { _result pushBack ROLE_IDLER };
    } else {
        private _targets = _mix apply { round (_x * _remaining / _mixSum) };

        // Absorb rounding drift into the largest slot so total matches.
        private _sum = 0;
        { _sum = _sum + _x } forEach _targets;
        private _drift = _remaining - _sum;
        if (_drift != 0) then {
            private _maxIdx = 0;
            for "_i" from 1 to (_slots - 1) do {
                if ((_targets select _i) > (_targets select _maxIdx)) then { _maxIdx = _i };
            };
            _targets set [_maxIdx, (_targets select _maxIdx) + _drift];
        };

        // Build flat role array.
        for "_i" from 0 to (_slots - 1) do {
            private _n = _targets select _i;
            private _role = _roleClasses select _i;
            for "_j" from 1 to _n do { _result pushBack _role };
        };
    };

    // Fisher-Yates shuffle (in-place).
    private _n = count _result;
    for "_i" from (_n - 1) to 1 step -1 do {
        private _j = floor (random (_i + 1));
        private _tmp = _result select _i;
        _result set [_i, _result select _j];
        _result set [_j, _tmp];
    };
};

if (_reserveOfficer) then {
    // Insert officer at a random position so it isn't always last.
    private _pos = floor (random ((count _result) + 1));
    _result insert [_pos, [ROLE_OFFICER]];
};

_result
