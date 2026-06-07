#include "..\script_component.hpp"
/*
    Function: digii_zet_main_fnc_applyEditorFilter

    Description:
        Reads 3DEN attribute variables from an entity (object or group)
        and calls fnc_setTargetFilter with the appropriate parameters.
        Handles both Object and Group entity types.

    Parameters:
        0: OBJECT or GROUP - The entity to read filter settings from

    Returns:
        Nothing

    Example:
        [_entity] call digii_zet_main_fnc_applyEditorFilter;
*/

params ["_entity"];

// Detect entity type (object vs group)
private _isGroup = _entity isEqualType grpNull;

// Read stored combo value — different variable prefix for objects vs groups
private _varPrefix = ["digii_zet_main_", "digii_zet_main_grp"] select _isGroup;
private _filterValue = _entity getVariable [_varPrefix + "FilterValue", 0];
private _filters = ["ALL","AIR","GROUND","ARMOR","INFANTRY","CUSTOM"];
private _filterType = _filters select _filterValue;

private _override = (_entity getVariable [_varPrefix + "OverrideMaxEngageRange", 0]) == 1;
private _maxRange = _entity getVariable [_varPrefix + "MaxEngageRange", 10000];

// Skip only when there is nothing to apply (no type filter and no range cap)
if (_filterType == "ALL" && !_override) exitWith {};

// Get the unit to pass to setTargetFilter
private _unit = if (_isGroup) then { leader _entity } else { _entity };
if (isNull _unit || !alive _unit) exitWith {};

private _customFilter = if (_filterType == "CUSTOM") then {
    createHashMapFromArray [
        ["Air",      (_entity getVariable [_varPrefix + "CustomAir", 1]) == 1],
        ["Armor",    (_entity getVariable [_varPrefix + "CustomArmor", 1]) == 1],
        ["Vehicles", (_entity getVariable [_varPrefix + "CustomVehicles", 1]) == 1],
        ["Infantry", (_entity getVariable [_varPrefix + "CustomInfantry", 1]) == 1],
        ["Naval",    (_entity getVariable [_varPrefix + "CustomNaval", 1]) == 1]
    ]
} else {
    createHashMap
};

[_unit, _filterType, _customFilter, _override, _maxRange] call FUNC(setTargetFilter);
