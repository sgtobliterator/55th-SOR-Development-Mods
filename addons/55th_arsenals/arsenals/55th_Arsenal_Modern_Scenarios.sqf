_box = _this;

private _weapons = [

];

private _weaponMods = [

];

private _magazines = [

];

private _items = [

];

private _backpacks = [

];

private _vests = [

];

private _headgear = [

];

private _facewear = [

];

private _uniforms = [

];

private _arsenalItems = _weapons + _magazines + _items + _backpacks + _vests + _headgear + _facewear + _uniforms;
_arsenalItems = _arsenalItems arrayIntersect _arsenalItems;

//If you need to do testing, change _box to cursorObject

[_box, _arsenalItems, true] remoteExec ["ace_arsenal_fnc_initBox", 2];
