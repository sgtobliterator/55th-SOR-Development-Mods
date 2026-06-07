#include "..\script_component.hpp"
/*
    Function: digii_zet_main_fnc_setTargetFilter

    Description:
        Sets target filter on an AI unit using dual group event handlers.
        EnemyDetected fires on initial enemy detection (primary).
        Filter is stored per-group. Supports preset filters and custom
        hashmap-based filters.

    Parameters:
        0: OBJECT - The unit to apply filter to
        1: STRING - Filter type ("ALL", "AIR", "GROUND", "ARMOR", "INFANTRY", "CUSTOM")
        2: HASHMAP - (Optional) Custom filter hashmap, only used when filter is "CUSTOM"

    Returns:
        BOOL - Success

    Example:
        [_unit, "AIR"] call digii_zet_main_fnc_setTargetFilter;
        [_unit, "CUSTOM", _customFilter] call digii_zet_main_fnc_setTargetFilter;
*/

params [
    ["_unit", objNull, [objNull]],
    ["_filterType", "ALL", [""]],
    ["_customFilter", createHashMap, [createHashMap]],
    ["_overrideMaxEngageRange", false, []],
    ["_maxEngageRange", 10000, []]
];

diag_log format ["[ZET] Filter override Event: %1", _overrideMaxEngageRange];

if (isNull _unit || !alive _unit) exitWith {
    false
};

private _group = group _unit;

private _ignoredTargets = _group getVariable [QGVAR(ignoredTargets), []];

_group setVariable ["targetFilterType", toUpper _filterType, true];

// Store custom filter hashmap if CUSTOM
if (toUpper _filterType == "CUSTOM") then {
    _group setVariable [QGVAR(customFilter), _customFilter, true];
};

// Persist override + range on the group so fnc_isTargetValid, the range-check
// PFH, and the Zeus attribute getter all see the same values regardless of
// whether setTargetFilter was called from Zeus or from fnc_applyEditorFilter.
_group setVariable [QGVAR(overrideMaxEngageRange), _overrideMaxEngageRange, true];
_group setVariable [QGVAR(maxEngageRange), _maxEngageRange, true];

//reset Ignored Targets
[_group, _filterType] call FUNC(clearIgnoredTargets);
diag_log format ["[ZET] Filter set: %1 -> %2", _group, toUpper _filterType];

// Reconcile range-check PFH with current override flag.
// PFH dynamically re-evaluates targets every 5s so that units moving in/out
// of range are re-ignored / un-ignored. Type filter is also re-checked via
// fnc_isTargetValid, so a unit entering range still gets filtered by type.
private _existingPfh = _group getVariable [QGVAR(rangeCheckPFH), -1];
if (_overrideMaxEngageRange) then {
    if (_existingPfh == -1) then {
        private _newPfhId = [{
            params ["_args", "_pfhId"];
            _args params ["_group"];

            // Self-terminate if the group is gone or override was turned off
            if (
                isNull _group
                || {(units _group) isEqualTo []}
                || {!(_group getVariable [QGVAR(overrideMaxEngageRange), false])}
            ) exitWith {
                [_pfhId] call CBA_fnc_removePerFrameHandler;
                if (!isNull _group) then {
                    _group setVariable [QGVAR(rangeCheckPFH), -1];
                };
            };

            private _filter = _group getVariable ["targetFilterType", "ALL"];
            private _cf     = _group getVariable [QGVAR(customFilter), createHashMap];
            private _ignoredTargets = _group getVariable [QGVAR(ignoredTargets), []];
            private _stillIgnored = [];

            // (a) Un-ignore previously-ignored targets that are now valid (e.g. moved back into range)
            {
                private _target = _x;
                if (!alive _target || {isNull _target}) then { continue };

                if ([_target, _filter, _cf, _group] call FUNC(isTargetValid)) then {
                    _group ignoreTarget [_target, false];
                    {
                        _x ignoreTarget [_target, false];
                        if (!isNull objectParent _x) then {
                            { _x ignoreTarget [_target, false] } forEach (crew vehicle _x);
                        };
                    } forEach (units _group);
                } else {
                    _stillIgnored pushBack _target;
                };
            } forEach +_ignoredTargets;

            // (b) Ignore currently-known targets that are now invalid (e.g. walked out of range)
            private _leader = leader _group;
            {
                private _target = _x;
                if (!alive _target || {isNull _target}) then { continue };
                if (_target in _stillIgnored) then { continue };

                if (!([_target, _filter, _cf, _group] call FUNC(isTargetValid))) then {
                    _group ignoreTarget _target;
                    _stillIgnored pushBackUnique _target;
                    {
                        _x doTarget objNull;
                        _x ignoreTarget _target;
                        if (!isNull objectParent _x) then {
                            { _x ignoreTarget _target } forEach (crew vehicle _x);
                        };
                    } forEach (units _group);
                };
            } forEach (_leader targets [true, 0]);

            _group setVariable [QGVAR(ignoredTargets), _stillIgnored];
        }, 5, [_group]] call CBA_fnc_addPerFrameHandler;

        _group setVariable [QGVAR(rangeCheckPFH), _newPfhId];
        diag_log format ["[ZET] Range-check PFH started for group: %1", _group];
    };
} else {
    if (_existingPfh != -1) then {
        [_existingPfh] call CBA_fnc_removePerFrameHandler;
        _group setVariable [QGVAR(rangeCheckPFH), -1];
        diag_log format ["[ZET] Range-check PFH stopped for group: %1", _group];
    };
};

// If setting to "ALL", check if group EHs can be removed
if (toUpper _filterType == "ALL" && !(_overrideMaxEngageRange)) exitWith {
    private _hasFilters = (_group getVariable ["targetFilterType", "ALL"]) != "ALL";

    if (!_hasFilters) then {
        private _ehED = _group getVariable ["digii_zet_filterEH_ED", -1];
        if (_ehED != -1) then {
            _group removeEventHandler ["EnemyDetected", _ehED];
            _group setVariable ["digii_zet_filterEH_ED", -1];
        };
        private _ehKAC = _group getVariable ["digii_zet_filterEH_KAC", -1];
        if (_ehKAC != -1) then {
            _group removeEventHandler ["KnowsAboutChanged", _ehKAC];
            _group setVariable ["digii_zet_filterEH_KAC", -1];
        };
    };

    diag_log "[ZET] Removed EVHs";
    true
};

// Immediately clear any existing invalid targets the unit already knows about
private _filterUpper = toUpper _filterType;
private _cf = _group getVariable [QGVAR(customFilter), createHashMap];
{
    private _target = _x;
    private _valid = [_target, _filterUpper, _cf, _group] call FUNC(isTargetValid);
    if (!_valid) then {
        diag_log format ["[ZET] Clearing existing target: %1", typeOf _target];
        _unit ignoreTarget _target;
        _ignoredTargets pushBackUnique _target;
    };

    _group setVariable [QGVAR(ignoredTargets), _ignoredTargets];
} forEach (_unit targets [true, 2000]);

// Add EnemyDetected EH if not already present (primary handler)
if ((_group getVariable ["digii_zet_filterEH_ED", -1]) == -1) then {
    private _ehId = _group addEventHandler ["EnemyDetected", {
        params ["_group", "_newTarget"];
        diag_log format ["[ZET] EnemyDetected: %1", typeOf _newTarget];

        private _filter = _group getVariable ["targetFilterType", "ALL"];
        private _override = _group getVariable [QGVAR(overrideMaxEngageRange), false];
        private _ignoredTargets = _group getVariable [QGVAR(ignoredTargets), []];
        diag_log format ["[ZET] ED checking: %1 | filter: %2 | override: %3", _group, _filter, _override];

        if (_filter != "ALL" || _override) then {
            private _cf = _group getVariable [QGVAR(customFilter), createHashMap];
            private _valid = [_newTarget, _filter, _cf, _group] call FUNC(isTargetValid);

            if (!_valid) then {
                diag_log format ["[ZET] ED Blocked: %1 forgetting %2 (filter: %3)", _group, typeOf _newTarget, _filter];
                _group ignoreTarget _newTarget;
                _ignoredTargets pushBackUnique _newTarget;

                _group setVariable [QGVAR(ignoredTargets), _ignoredTargets];

                {
                    private _unit = _x;

                    _unit doTarget objNull;
                    _unit ignoreTarget _newTarget;
                    if (!isNull objectParent _unit) then {
                        {
                            _x ignoreTarget _newTarget;
                        } forEach (crew vehicle _unit);
                    };
                } forEach (units _group);
            };
        };
    }];

    _group setVariable ["digii_zet_filterEH_ED", _ehId];
    diag_log format ["[ZET] EnemyDetected EH added to group: %1", _group];
};

// Add KnowsAboutChanged EH if not already present (backup enforcement)
if ((_group getVariable ["digii_zet_filterEH_KAC", -1]) == -1) then {
    private _ehId = _group addEventHandler ["KnowsAboutChanged", {
        params ["_group", "_targetUnit", "_newKnowsAbout", "_oldKnowsAbout"];

        // Only act when awareness is increasing
        if (_newKnowsAbout <= _oldKnowsAbout) exitWith {};

        private _filter = _group getVariable ["targetFilterType", "ALL"];
        private _override = _group getVariable [QGVAR(overrideMaxEngageRange), false];
        private _ignoredTargets = _group getVariable [QGVAR(ignoredTargets), []];
        diag_log format ["[ZET] KAC checking: %1 | filter: %2 | target: %3", _group, _filter, typeOf _targetUnit];

        if (_filter != "ALL" || _override) then {
            private _cf = _group getVariable [QGVAR(customFilter), createHashMap];
            private _valid = [_targetUnit, _filter, _cf, _group] call FUNC(isTargetValid);

            if (!_valid) then {
                diag_log format ["[ZET] KAC Blocked: %1 forgetting %2 (filter: %3)", _group, typeOf _targetUnit, _filter];
                _group ignoreTarget _targetUnit;
                _ignoredTargets pushBackUnique _targetUnit;

                _group setVariable [QGVAR(ignoredTargets), _ignoredTargets];

                {
                    private _unit = _x;

                    _unit doTarget objNull;
                    _unit ignoreTarget _targetUnit;
                    if (!isNull objectParent _unit) then {
                        {
                            _x ignoreTarget _targetUnit;
                        } forEach (crew vehicle _unit);
                    };
                } forEach (units _group);
            };
        };
    }];

    _group setVariable ["digii_zet_filterEH_KAC", _ehId];
    diag_log format ["[ZET] KnowsAboutChanged EH added to group: %1", _group];
};

true
