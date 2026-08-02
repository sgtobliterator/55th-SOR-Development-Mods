params [
	["_mode", "", [""]],
	["_input", [], [[]]]
];

_input params [
	["_module", objNull, [objNull]],
	["_isActivated", false, [true]],
	["_isCuratorPlaced", false, [true]]
];

private _playersOnly = _module getVariable ["FOD_ZA_HR_PlayersOnly", false];

private _area = _module getVariable ["ObjectArea", [200, 200, 0, false, -1]];
if (is3DEN) then {
	private _size = (_module get3DENAttribute "Size3") select 0;
	_size params [["_a", 200, [0]], ["_b", 200, [0]]];
	_area = [_a, _b, 0, false, -1];
};
private _radius = round ((_area#0 + _area#1) / 2);

switch (_mode) do {
	case "init": {
		if (_isActivated && isServer) then {
			private _modulePos = getPosATL _module;
			private _syncedUnits = synchronizedObjects _module select { alive _x && { _x isKindOf "Man" } };

			if (count _syncedUnits == 0) exitWith {
				["[FOD_ZA_ModuleHitAndRun] No units synced to module."] call FOD_ZA_fnc_debugMessage;
			};

			private _groups = [];
			{ _groups pushBackUnique (group _x); } forEach _syncedUnits;

			{ [_x, _modulePos, _radius, _playersOnly] spawn FOD_ZA_fnc_taskHitAndRun; } forEach _groups;

			["[FOD_ZA_ModuleHitAndRun] %1 group(s), %2 units, engaging around module pos (radius %3m).",
				count _groups, count _syncedUnits, _radius] call FOD_ZA_fnc_debugMessage;
		};
	};
	case "attributesChanged3DEN": {};
	case "registeredToWorld3DEN": {};
	case "unregisteredFromWorld3DEN": {};
	case "connectionChanged3DEN": {};
	case "dragged3DEN": {};
};
