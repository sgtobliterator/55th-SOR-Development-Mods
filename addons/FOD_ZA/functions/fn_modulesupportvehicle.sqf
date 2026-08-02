params [
	["_mode", "", [""]],
	["_input", [], [[]]]
];

_input params [
	["_module", objNull, [objNull]],
	["_isActivated", false, [true]],
	["_isCuratorPlaced", false, [true]]
];

private _followDistance = _module getVariable ["FOD_ZA_SV_FollowDistance", 50];

private _area = _module getVariable ["ObjectArea", [60, 60, 0, false, -1]];
if (is3DEN) then {
	private _size = (_module get3DENAttribute "Size3") select 0;
	_size params [["_a", 60, [0]], ["_b", 60, [0]]];
	_area = [_a, _b, 0, false, -1];
};

switch (_mode) do {
	case "init": {
		if (_isActivated && isServer) then {
			private _modulePos = getPosATL _module;
			private _syncedUnits = synchronizedObjects _module select { alive _x && { _x isKindOf "Man" } };

			if (count _syncedUnits == 0) exitWith {
				["[FOD_ZA_ModuleSupportVehicle] No units synced to module."] call FOD_ZA_fnc_debugMessage;
			};

			private _groups = [];
			{ _groups pushBackUnique (group _x); } forEach _syncedUnits;

			private _targetPos = ([(_groups select 0), _modulePos] call FOD_ZA_fnc_findNearestAllyPos) select 0;

			{ [_x, _targetPos, _followDistance] spawn FOD_ZA_fnc_taskSupportVehicle; } forEach _groups;

			["[FOD_ZA_ModuleSupportVehicle] %1 group(s), %2 units, supporting toward %3, follow distance %4m.",
				count _groups, count _syncedUnits, _targetPos, _followDistance] call FOD_ZA_fnc_debugMessage;
		};
	};
	case "attributesChanged3DEN": {};
	case "registeredToWorld3DEN": {};
	case "unregisteredFromWorld3DEN": {};
	case "connectionChanged3DEN": {};
	case "dragged3DEN": {};
};
