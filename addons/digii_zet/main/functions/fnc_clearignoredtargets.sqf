#include "..\script_component.hpp"
/*
    Function: digii_zet_main_fnc_clearIgnoredTargets

    Description:
        Clears previously ignored targets when the filter changes.
        Targets that are now valid under the new filter get un-ignored
        at both group and individual unit level (including crew).

    Parameters:
        0: GROUP - The group to clear targets for
        1: STRING - New filter type

    Returns:
        NONE

    Example:
        [_group, "AIR"] call digii_zet_main_fnc_clearIgnoredTargets;
*/

params["_group", "_filter"];

private _ignoredTargets = _group getVariable [QGVAR(ignoredTargets), []];

if ((count _ignoredTargets) == 0) exitWith {};

private _filterUpper = toUpper _filter;
private _cf = _group getVariable [QGVAR(customFilter), createHashMap];

private _stillBlocked = [];

{
	private _target = _x;

	// Remove dead/null targets
	if (!alive _target || isNull _target) then {
		continue
	};

	// Check if this target should be un-ignored under the new filter
	if ([_target, _filterUpper, _cf, _group] call FUNC(isTargetValid)) then {
		// Un-ignore at group level
		_group ignoreTarget [_target, false];

		// Un-ignore at unit level + crew (matches how EHs set ignores)
		{
			_x ignoreTarget [_target, false];
			if (!isNull objectParent _x) then {
				{ _x ignoreTarget [_target, false] } forEach (crew vehicle _x);
			};
		} forEach (units _group);
	} else {
		_stillBlocked pushBack _target;
	};
} forEach +_ignoredTargets;

_group setVariable [QGVAR(ignoredTargets), _stillBlocked];
