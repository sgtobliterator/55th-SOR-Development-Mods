// init
disableSerialization;

private _3denDisplay = uiNamespace getVariable "Display3DEN";
private _dialog = _3denDisplay displayCtrl 9150;
private _dialogModal = _3denDisplay displayCtrl 9159;

// hide dialog
_dialog ctrlShow false;
_dialogModal ctrlShow false;
