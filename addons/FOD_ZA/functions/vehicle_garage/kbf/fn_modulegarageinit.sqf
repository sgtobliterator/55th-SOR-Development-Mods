/*
	File: fn_ModuleGarageInit.sqf
	Author: Phenosi
	Description: 3DEN module execution for Vehicle Garage Init
*/

params [
	["_mode", "", [""]],
	["_input", [], [[]]]
];

if (!isServer) exitWith {};

switch (_mode) do {
	case "init": {
		_logic           = _input param [0, objNull, [objNull]];   // Module logic
		_isActivated     = _input param [1, true,    [true]];      // True when the module was activated, false when it is deactivated
		_isCuratorPlaced = _input param [2, false,   [true]];      // True if the module was placed by Zeus
		
		private _syncedObjects = synchronizedObjects _logic;

		if ((count _syncedObjects) > 0) then {
			private _obj = _syncedObjects select 0; // First synced object is "this"
			private _pointObj = _syncedObjects select 1; //Second Sync Object is Helipad/spawn location

			// Get attributes from the module
			private _typesStr     = _logic getVariable ["PHEN_ModuleGarageInit_TypesArray", "['Auto']"];
			private _sidesStr     = _logic getVariable ["PHEN_ModuleGarageInit_SidesArray", "['ALL']"];
			private _range        = _logic getVariable ["PHEN_ModuleGarageInit_DisplayRange", 10];
			private _marker       = _logic getVariable ["PHEN_ModuleGarageInit_Marker", false];
			private _script       = _logic getVariable ["PHEN_ModuleGarageInit_ExtraScript", ""];

			// Compile dropdown string values > arrays
			private _types = call compile _typesStr;
			private _sides = call compile _sidesStr;

			// Validate
			if (isNull _pointObj) exitWith {
				diag_log format ["[Garage Init] ERROR: Spawn point object '%1' not found", _pointVarName];
			};

			// Call function
			[_obj, _pointObj, _types, _sides, _range, _marker, _script] call kbf_fnc_garageInit;
		} else {
			diag_log "[Garage Init] WARNING: No objects synced to the module.";
		};

	};

	case "attributesChanged3DEN": {
		_logic = _input param [0,objNull,[objNull]];
	};

	case "registeredToWorld3DEN": {
		_logic = _input param [0,objNull,[objNull]];
	};

	case "unregisteredFromWorld3DEN": {
		_logic = _input param [0,objNull,[objNull]];
	};

	case "connectionChanged3DEN": {
		_logic = _input param [0,objNull,[objNull]];
	};

	case "dragged3DEN": {
		_logic = _input param [0,objNull,[objNull]];
	};
};
