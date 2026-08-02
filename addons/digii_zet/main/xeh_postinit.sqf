#include "script_component.hpp"

// Add eventhanlder
[QGVAR(setFilter), {
    params ["_unit", ["_filter", "", [""]]];

    private _grp = group _unit;

    // A non-empty _filter = caller picked a new type (Zeus combo / context menu);
    // persist it as the group's active filter. Arg-less callers (custom-filter
    // checkboxes, override, range slider) leave targetFilterType untouched.
    if (_filter != "") then {
        _grp setVariable ["targetFilterType", toUpper _filter, true];
    };

    private _filterType = _grp getVariable ["targetFilterType", "ALL"];
    private _cf = _grp getVariable [QGVAR(customFilter), createHashMap];
    private _override = _grp getVariable [QGVAR(overrideMaxEngageRange), false];
    private _maxRange = _grp getVariable [QGVAR(maxEngageRange), 10000];

    [_unit, _filterType, _cf, _override, _maxRange] call FUNC(setTargetFilter);
}] call CBA_fnc_addEventHandler;

if (!hasInterface) exitWith {};

// ========== ZEN CONTEXT MENU ==========
// ZEN ACTION_PARAMS: [_position, _objects, _groups, _waypoints, _markers, _hoveredEntity, _args]
diag_log "[ZET] Registering context menu actions...";

private _parentAction = [
    "digii_zet_targetFilter",
    LLSTRING(SetFilterTitle),
    "",
    {},
    {
        private _objects = _this select 1;
        private _hoveredEntity = _this select 5;
        (typeName _hoveredEntity == "OBJECT" && {!isNull _hoveredEntity} && {
            _hoveredEntity isKindOf "CAManBase" || _hoveredEntity isKindOf "LandVehicle" ||
            _hoveredEntity isKindOf "Air" || _hoveredEntity isKindOf "Ship"
        }) || typeName _hoveredEntity == "GROUP"
    }
] call zen_context_menu_fnc_createAction;

private _parentPath = [_parentAction] call zen_context_menu_fnc_addAction;

// Child actions for each filter type
{
    _x params ["_filterType", "_displayName"];

    private _childAction = [
        format ["digii_zet_filter_%1", _filterType],
        _displayName,
        "",
        {
            private _objects = _this select 1;
            private _hoveredEntity = _this select 5;
            private _args = _this select 6;

            diag_log format ["[ZET] Action clicked: %1 | hovered: %2 | objects: %3",
                _args, _hoveredEntity, count _objects];

            // Apply to hovered entity
            if (typeName _hoveredEntity == "OBJECT" && {!isNull _hoveredEntity}) then {
                [QGVAR(setFilter), [_hoveredEntity, _args], _hoveredEntity] call CBA_fnc_targetEvent;
            };

            if (typeName _hoveredEntity == "GROUP" && {!isNull _hoveredEntity}) then {
                [QGVAR(setFilter), [leader _hoveredEntity, _args], _hoveredEntity] call CBA_fnc_targetEvent;
            };

            // Apply to all selected objects (skip hoveredEntity to avoid duplicate)
            {
                if (_x isNotEqualTo _hoveredEntity) then {
                    [QGVAR(setFilter), [_x, _args], _x] call CBA_fnc_targetEvent;
                };
            } forEach _objects;
        },
        {true},
        _filterType
    ] call zen_context_menu_fnc_createAction;

    [_childAction, _parentPath] call zen_context_menu_fnc_addAction;
} forEach [
    ["ALL", LLSTRING(Filter_All)],
    ["AIR", LLSTRING(Filter_Air)],
    ["GROUND", LLSTRING(Filter_Ground)],
    ["ARMOR", LLSTRING(Filter_Armor)],
    ["INFANTRY", LLSTRING(Filter_Infantry)]
];

diag_log "[ZET] Context menu actions registered.";


