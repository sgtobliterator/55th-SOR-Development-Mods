#include "\a3\3DEN\UI\resincl.inc"

waituntil {!(IsNull (findDisplay IDD_DISPLAY3DEN))};

// remove existing handler, if present
private _handler = uiNamespace getVariable "Eden_Extended_Objects_multiplyHandler";
if (!isNil "_handler") then {
	(findDisplay IDD_DISPLAY3DEN) displayRemoveEventHandler ["KeyDown", _handler];
};

// add handler
_handler = (findDisplay IDD_DISPLAY3DEN) displayAddEventHandler ["KeyDown", {
	if (_this select 1 == 67) then {
		if (count (get3DENSelected "object") > 0) then {
			// do action a single history event
			collect3DENHistory {
				{
					private _class = typeOf _x;
					if (_class != "") then {
						_x set3DENAttribute ["rotation", [0, 0, random 360]];
					};
				} forEach (get3DENSelected "object");
			};
		};
	};
}];

// save
uiNamespace setVariable ["Eden_Extended_Objects_multiplyHandler", _handler];
