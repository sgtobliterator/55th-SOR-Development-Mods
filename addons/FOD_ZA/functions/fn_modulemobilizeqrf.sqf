params [
	["_mode", "", [""]],
	["_input", [], [[]]]
];

_input params [
	["_module", objNull, [objNull]],
	["_isActivated", false, [true]],
	["_isCuratorPlaced", false, [true]]
];

private _area = _module getVariable ["ObjectArea", [30, 30, 0, false, -1]];
if (is3DEN) then {
	private _size = (_module get3DENAttribute "Size3") select 0;
	_size params [["_a", 30, [0]], ["_b", 30, [0]]];
	_area = [_a, _b, 0, false, -1];
};
private _radius = round ((_area#0 + _area#1) / 2);

switch (_mode) do {
	case "init": {
		if (_isActivated && isServer) then {
			private _modulePos = getPosATL _module;
			private _syncedUnits = synchronizedObjects _module select { alive _x && { _x isKindOf "Man" } };

			if (count _syncedUnits == 0) exitWith {
				["[FOD_ZA_ModuleMobilizeQRF] No units synced to module."] call FOD_ZA_fnc_debugMessage;
			};

			private _groups = [];
			{ _groups pushBackUnique (group _x); } forEach _syncedUnits;

			{
				// each group gets its own reinforcement target, so a group can never end up targeting its own current position
				private _targetInfo = [_x, _modulePos] call FOD_ZA_fnc_findNearestAllyPos;
				private _targetPos = _targetInfo select 0;
				private _targetGroup = _targetInfo select 1;
				[_x, _targetPos, _radius, _targetGroup, true] spawn FOD_ZA_fnc_taskMobilizeQRF;
			} forEach _groups;

			["[FOD_ZA_ModuleMobilizeQRF] %1 group(s), %2 units, mobilizing, radius %3m.",
				count _groups, count _syncedUnits, _radius] call FOD_ZA_fnc_debugMessage;
		};
	};
	case "attributesChanged3DEN": {};
	case "registeredToWorld3DEN": {};
	case "unregisteredFromWorld3DEN": {};
	case "connectionChanged3DEN": {};
	case "dragged3DEN": {};
};
