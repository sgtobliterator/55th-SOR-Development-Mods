#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Returns a validated random position inside a circle. Uses findEmptyPosition
 * so the result is on flat terrain, not inside a wall or a closed building.
 * Up to 20 retries with fresh random candidates; falls back to a naive sample
 * if all attempts fail (rare but possible in pathologically dense areas).
 *
 * Arguments:
 * 0: Center <ARRAY>
 * 1: Radius <NUMBER>
 *
 * Return Value:
 * [x, y, z] position; z copied from center <ARRAY>
 *
 * Example:
 * [getPosATL player, 75] call digii_ambient_agents_fnc_randomPosInRadius
 *
 * Public: No
 */

params ["_center", "_radius"];

private _cx = _center select 0;
private _cy = _center select 1;
private _cz = _center select 2;

private _result = [];

for "_attempt" from 1 to 20 do {
    private _angle = random 360;
    private _r = sqrt (random 1) * _radius;
    private _candidate = [_cx + _r * cos _angle, _cy + _r * sin _angle];

    // Expand 0-3m from candidate looking for empty ground sized for a soldier.
    // The class is just a footprint hint; works for all sides / modded factions.
    private _empty = _candidate findEmptyPosition [0, 3, "B_Soldier_F"];

    if (count _empty > 0) exitWith {
        _result = [_empty select 0, _empty select 1, _cz];
    };
};

if (_result isEqualTo []) then {
    // 20 attempts all collided with structures. Fall back to naive sample so
    // we don't deadlock the spawn loop. Logged for visibility.
    private _angle = random 360;
    private _r = sqrt (random 1) * _radius;
    _result = [_cx + _r * cos _angle, _cy + _r * sin _angle, _cz];
    diag_log format ["[digii_ambient] randomPosInRadius: 20 attempts failed, falling back to naive sample at %1", _result];
};

_result
