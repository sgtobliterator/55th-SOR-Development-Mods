// settings
private _count_range = [1, 250];
private _spread_range = [1, 500];
private _default_count = 30;
private _default_spread = 60;
private _default_randomize = true;

// store current selection & init variables
uiNamespace setVariable ["Eden_Extended_Objects_multiply_selected_objects", (get3DENSelected "object")];
uiNamespace setVariable ["Eden_Extended_Objects_multiply_count", _default_count];
uiNamespace setVariable ["Eden_Extended_Objects_multiply_spread", _default_spread];
uiNamespace setVariable ["Eden_Extended_Objects_multiply_randomize_rotation", _default_randomize];

// init
disableSerialization;

private _3denDisplay = uiNamespace getVariable "Display3DEN";
private _dialog = _3denDisplay displayCtrl 9150;
private _dialogModal = _3denDisplay displayCtrl 9159;

private _count_slider = _3denDisplay displayCtrl 9151;
private _spread_slider = _3denDisplay displayCtrl 9152;
private _rotation_checkbox = _3denDisplay displayCtrl 9153;

// create dialog
_dialog ctrlShow true;
_dialogModal ctrlShow true;

// range & default
_count_slider sliderSetRange _count_range;
_count_slider sliderSetPosition _default_count;
_count_slider ctrlSetTooltip str(_default_count);
_spread_slider sliderSetRange _spread_range;
_spread_slider sliderSetPosition _default_spread;
_spread_slider ctrlSetTooltip str(_default_spread);
_rotation_checkbox cbSetChecked _default_randomize;
