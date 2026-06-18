_box = _this;

#include "55th_Arsenal_Modern_Infantry_Template.sqf"

private _arsenalItems = _infantryItems;
_arsenalItems = _arsenalItems arrayIntersect _arsenalItems;

//If you need to do testing, change _box to cursorObject

[_box, _arsenalItems, true] remoteExec ["ace_arsenal_fnc_initBox", 2];
