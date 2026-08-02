#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

// delay by 1 Frame so ZEN initializes first
[
	{
		// ========== OBJECT ATTRIBUTES ==========
		// Combo: Set Target Filter (with CUSTOM option)
		[
			"Object",
			LLSTRING(SetFilterTitle),
			QZENGVAR(attributes,combo),
			[[
				["ALL", [LLSTRING(Filter_All), ""], ""],
				["AIR", [LLSTRING(filter_air), ""], ""],
				["GROUND", [LLSTRING(Filter_Ground), ""], ""],
				["ARMOR", [LLSTRING(Filter_Armor), ""], ""],
				["INFANTRY", [LLSTRING(filter_infantry), ""], ""],
				["CUSTOM", [LLSTRING(Filter_Custom), ""], ""]
			]],
			{
				if (_value == "CUSTOM") then {
					private _ent = _entity;
					private _grp = group _entity;
					[{
						params ["_ent", "_grp"];
						[QGVAR(setFilter), [_ent, "CUSTOM"], _grp] call CBA_fnc_targetEvent;
					}, [_ent, _grp]] call CBA_fnc_execNextFrame;
				} else {
					[QGVAR(setFilter), [_entity, _value], group _entity] call CBA_fnc_targetEvent;
				};
			},
			{(group _entity) getVariable ["targetFilterType", "ALL"]},
			{alive _entity && {_entity isKindOf "LandVehicle" || {_entity isKindOf "Air"} || {_entity isKindOf "Ship" || {_entity isKindOf "Man"}}}}
		] call ZENFUNC(attributes,addAttribute);

		// Object checkboxes for Custom filter
		[
			"Object",
			[LLSTRING(CustomFilterTitle), LLSTRING(CustomFilterTooltip)],
			QZENGVAR(attributes,checkboxes),
			[[
				[10,   0, 5,   CSTRING(CustomAir),      CSTRING(CustomFilterTooltip)],
				[15.5, 0, 5.5, CSTRING(CustomArmor),    CSTRING(CustomFilterTooltip)],
				[21,   0, 5,   CSTRING(CustomVehicles),  CSTRING(CustomFilterTooltip)],
				[10,   1, 5.5, CSTRING(CustomInfantry),  CSTRING(CustomFilterTooltip)],
				[15.5,   1, 5,   CSTRING(CustomNaval),     CSTRING(CustomFilterTooltip)]
			], 2],
			{
				private _grp = group _entity;
				private _cf = createHashMapFromArray [
					["Air",      _value select 0],
					["Armor",    _value select 1],
					["Vehicles", _value select 2],
					["Infantry", _value select 3],
					["Naval",    _value select 4]
				];
				_grp setVariable [QGVAR(customFilter), _cf, true];

				// Re-apply filter to clear/update ignored targets
				if (_grp getVariable ["targetFilterType", "ALL"] == "CUSTOM") then {
					[QGVAR(setFilter), [_entity], _grp] call CBA_fnc_targetEvent;
				};
			},
			{
				private _cf = (group _entity) getVariable [QGVAR(customFilter), createHashMap];
				[
					_cf getOrDefault ["Air", true],
					_cf getOrDefault ["Armor", true],
					_cf getOrDefault ["Vehicles", true],
					_cf getOrDefault ["Infantry", true],
					_cf getOrDefault ["Naval", true]
				]
			},
			{alive _entity && {_entity isKindOf "LandVehicle" || {_entity isKindOf "Air"} || {_entity isKindOf "Ship" || {_entity isKindOf "Man"}}}}
		] call ZENFUNC(attributes,addAttribute);

		// Object checkbox for override max engagement range
		[
			"Object",
			[LLSTRING(OverrideRangeTitle), LLSTRING(OverrideRangeTooltip)],
			QZENGVAR(attributes,checkboxes),
			[[
				[10,   0, 15,   CSTRING(OverrideRangeCheckbox), CSTRING(OverrideRangeCheckboxTooltip)]
			]],
			{
				private _grp = group _entity;
				_grp setVariable [QGVAR(overrideMaxEngageRange), _value select 0, true];
				diag_log format ["[ZET] Filter Override: %1", _value select 0];
				private _filter = _grp getVariable ["targetFilterType", "ALL"];
				private _cf = _grp getVariable [QGVAR(customFilter), createHashMap];
				[QGVAR(setFilter), [_entity], _grp] call CBA_fnc_targetEvent;

			},
			{
				(group _entity) getVariable [QGVAR(overrideMaxEngageRange), false];
			},
			{alive _entity && {_entity isKindOf "LandVehicle" || {_entity isKindOf "Air"} || {_entity isKindOf "Ship" || {_entity isKindOf "Man"}}}}
		] call ZENFUNC(attributes,addAttribute);

		// Object slider for max engagement range
		[
			"Object",
			[LLSTRING(MaxEngageRangeTitle), LLSTRING(MaxEngageRangeTooltip)],
			QZENGVAR(attributes,slider),
			[100, 10000, 100, false, 0],
			{
				private _grp = group _entity;
				_grp setVariable [QGVAR(maxEngageRange), _value, true];

				private _filter = _grp getVariable ["targetFilterType", "ALL"];
				private _cf = _grp getVariable [QGVAR(customFilter), createHashMap];
				private _override = _grp getVariable [QGVAR(overrideMaxEngageRange), false];
				[QGVAR(setFilter), [_entity], _grp] call CBA_fnc_targetEvent;
			},
			{
				(group _entity) getVariable [QGVAR(maxEngageRange), 10000];
			},
			{alive _entity && {_entity isKindOf "LandVehicle" || {_entity isKindOf "Air"} || {_entity isKindOf "Ship" || {_entity isKindOf "Man"}}}}
		] call ZENFUNC(attributes,addAttribute);

		// ========== GROUP ATTRIBUTES ==========
		// Combo: Set Target Filter (with CUSTOM option)
		[
			"Group",
			LLSTRING(SetFilterTitle),
			QZENGVAR(attributes,combo),
			[[
				["ALL", [LLSTRING(Filter_All), ""], ""],
				["AIR", [LLSTRING(filter_air), ""], ""],
				["GROUND", [LLSTRING(Filter_Ground), ""], ""],
				["ARMOR", [LLSTRING(Filter_Armor), ""], ""],
				["INFANTRY", [LLSTRING(filter_infantry), ""], ""],
				["CUSTOM", [LLSTRING(Filter_Custom), ""], ""]
			]],
			{
				if (_value == "CUSTOM") then {
					{
						private _grp = _x;
						private _cf = _grp getVariable [QGVAR(customFilter), createHashMap];
						[{
							params ["_leader", "_grp", "_cf"];
							[QGVAR(setFilter), [_leader, "CUSTOM"], _grp] call CBA_fnc_targetEvent;
						}, [leader _grp, _grp, _cf]] call CBA_fnc_execNextFrame;
					} forEach SELECTED_GROUPS;
				} else {
					{
						[QGVAR(setFilter), [leader _x, _value], _x] call CBA_fnc_targetEvent;
					} forEach SELECTED_GROUPS;
				};
			},
			{_entity getVariable ["targetFilterType", "ALL"]},
			{true}
		] call ZENFUNC(attributes,addAttribute);

		// Group checkboxes for Custom filter
		[
			"Group",
			[LLSTRING(CustomFilterTitle), LLSTRING(CustomFilterTooltip)],
			QZENGVAR(attributes,checkboxes),
			[[
				[10,   0, 5,   CSTRING(CustomAir),      CSTRING(CustomFilterTooltip)],
				[15.5, 0, 5.5, CSTRING(CustomArmor),    CSTRING(CustomFilterTooltip)],
				[21,   0, 5,   CSTRING(CustomVehicles),  CSTRING(CustomFilterTooltip)],
				[10,   1, 5.5, CSTRING(CustomInfantry),  CSTRING(CustomFilterTooltip)],
				[16,   1, 5,   CSTRING(CustomNaval),     CSTRING(CustomFilterTooltip)]
			], 2],
			{
				private _cf = createHashMapFromArray [
					["Air",      _value select 0],
					["Armor",    _value select 1],
					["Vehicles", _value select 2],
					["Infantry", _value select 3],
					["Naval",    _value select 4]
				];
				{
					_x setVariable [QGVAR(customFilter), _cf, true];

					// Re-apply filter to clear/update ignored targets
					if (_x getVariable ["targetFilterType", "ALL"] == "CUSTOM") then {
						[QGVAR(setFilter), [leader _x], _x] call CBA_fnc_targetEvent;
					};
				} forEach SELECTED_GROUPS;
			},
			{
				private _cf = _entity getVariable [QGVAR(customFilter), createHashMap];
				[
					_cf getOrDefault ["Air", true],
					_cf getOrDefault ["Armor", true],
					_cf getOrDefault ["Vehicles", true],
					_cf getOrDefault ["Infantry", true],
					_cf getOrDefault ["Naval", true]
				]
			},
			{true}
		] call ZENFUNC(attributes,addAttribute);

		// Group checkbox for override max engagement range
		[
			"Group",
			[LLSTRING(OverrideRangeTitle), LLSTRING(OverrideRangeTooltip)],
			QZENGVAR(attributes,checkboxes),
			[[
				[10,   0, 15,   CSTRING(OverrideRangeCheckbox), CSTRING(OverrideRangeCheckboxTooltip)]
			]],
			{
				{
					_x setVariable [QGVAR(overrideMaxEngageRange), _value select 0, true];
					diag_log format ["[ZET] Filter Override: %1", _value select 0];
					private _filter = _x getVariable ["targetFilterType", "ALL"];
					private _cf = _x getVariable [QGVAR(customFilter), createHashMap];
					[QGVAR(setFilter), [leader _x], _x] call CBA_fnc_targetEvent;
				} forEach SELECTED_GROUPS;

			},
			{
				_entity getVariable [QGVAR(overrideMaxEngageRange), false];
			},
			{true}
		] call ZENFUNC(attributes,addAttribute);

		// Object slider for max engagement range
		[
			"Group",
			[LLSTRING(MaxEngageRangeTitle), LLSTRING(MaxEngageRangeTooltip)],
			QZENGVAR(attributes,slider),
			[100, 10000, 100, false, 0],
			{
				{
					_x setVariable [QGVAR(maxEngageRange), _value, true];

					private _filter = _x getVariable ["targetFilterType", "ALL"];
					private _cf = _x getVariable [QGVAR(customFilter), createHashMap];
					private _override = _x getVariable [QGVAR(overrideMaxEngageRange), false];
					[QGVAR(setFilter), [leader _x], _x] call CBA_fnc_targetEvent;
				} forEach SELECTED_GROUPS;
			},
			{
				_entity getVariable [QGVAR(maxEngageRange), 10000];
			},
			{true}
		] call ZENFUNC(attributes,addAttribute);
	},
	[]
] call CBA_fnc_execNextFrame;

ADDON = true;
