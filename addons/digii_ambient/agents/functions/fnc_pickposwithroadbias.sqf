#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Drop-in replacement for fnc_randomPosInRadius that prefers road positions
 * when _useRoads is true. Strict bias (not probabilistic): if any roads
 * exist within the radius, picks one at random; otherwise (or if useRoads
 * is false) falls back to the in-zone random helper.
 *
 * Road segments are surface objects, so no findEmptyPosition validation
 * needed -- units placed there sit on the road surface.
 *
 * Arguments:
 * 0: Center <ARRAY>
 * 1: Radius <NUMBER>
 * 2: Use roads <BOOL>
 *
 * Return Value:
 * PositionATL [x, y, z] <ARRAY>
 *
 * Example:
 * [_center, 75, true] call digii_ambient_agents_fnc_pickPosWithRoadBias
 *
 * Public: No
 */

params ["_center", "_radius", "_useRoads"];

if (_useRoads) then {
    private _roads = _center nearRoads _radius;
    if (_roads isNotEqualTo []) exitWith { getPosATL (selectRandom _roads) };
};

[_center, _radius] call FUNC(randomPosInRadius)
