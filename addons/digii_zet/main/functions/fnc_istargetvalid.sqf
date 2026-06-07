#include "..\script_component.hpp"
/*
    Function: digii_zet_main_fnc_isTargetValid

    Description:
        Checks whether a target is valid (allowed) for the given filter.

    Parameters:
        0: OBJECT - The target to check
        1: STRING - Filter type ("ALL", "AIR", "GROUND", "ARMOR", "INFANTRY", "CUSTOM")
        2: HASHMAP - Custom filter hashmap (only used when filter is "CUSTOM")
        3: OBJECT - GROUP of entity that wants to engage the target

    Returns:
        BOOL - true if the target is allowed, false if it should be blocked

    Example:
        [_target, "AIR", createHashMap, player] call digii_zet_main_fnc_isTargetValid;
*/

params ["_target", "_filter", "_customFilter", "_group"];

// Range gate — only enforced when override is enabled.
// Flat form so exitWith returns from the function, not just a nested then-scope.
if (
    (_group getVariable [QGVAR(overrideMaxEngageRange), false])
    && {((leader _group) distance _target) > (_group getVariable [QGVAR(maxEngageRange), 10000])}
) exitWith { false };

if (_filter == "ALL") exitWith { true };

if (_filter == "CUSTOM") exitWith {
    if (_target isKindOf "Air") exitWith {
        _customFilter getOrDefault ["Air", true]
    };
    if (_target isKindOf "Tank" || _target isKindOf "Wheeled_APC_F") exitWith {
        _customFilter getOrDefault ["Armor", true]
    };
    if (_target isKindOf "LandVehicle") exitWith {
        _customFilter getOrDefault ["Vehicles", true]
    };
    if (_target isKindOf "Man") exitWith {
        _customFilter getOrDefault ["Infantry", true]
    };
    if (_target isKindOf "Ship") exitWith {
        _customFilter getOrDefault ["Naval", true]
    };
    true
};

// Preset filters
switch (_filter) do {
    case "AIR":      { _target isKindOf "Air" };
    case "GROUND":   { _target isKindOf "LandVehicle" || _target isKindOf "Man" };
    case "ARMOR":    { _target isKindOf "Tank" || _target isKindOf "Wheeled_APC_F" };
    case "INFANTRY": { _target isKindOf "Man" };
    default          { true };
}
