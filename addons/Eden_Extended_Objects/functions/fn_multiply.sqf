// get values
private _selectedObjects = uiNamespace getVariable "Eden_Extended_Objects_multiply_selected_objects";

if (count(_selectedObjects) > 0) then {
	private _count           = uiNamespace getVariable "Eden_Extended_Objects_multiply_count";
	private _max_spread      = uiNamespace getVariable "Eden_Extended_Objects_multiply_spread";
	private _random_rotation = uiNamespace getVariable "Eden_Extended_Objects_multiply_randomize_rotation";

	// get starting point
	private _ref_pos = getPos ( _selectedObjects select 0);

	// generate inside a single history event
	collect3DENHistory {
		for "_i" from 1 to _count do
		{
			{
				private _class = typeOf _x;
				if (_class != "") then {
					// set random pos
					private _pos = _ref_pos vectorAdd [(random _max_spread - _max_spread / 2), random _max_spread - _max_spread / 2, 0];
					// create
					private _new = create3DENEntity ["Object", _class, _pos];
					// rotate
					if (_random_rotation) then {
						_new set3DENAttribute ["rotation", [0, 0, random 360]];
					};
				};
			} forEach _selectedObjects;
		};
	};
};

// empty
uiNamespace setVariable ["Eden_Extended_Objects_multiply_selected_objects", []];
