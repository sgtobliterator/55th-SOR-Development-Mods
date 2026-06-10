#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Dumps the zone registry to systemChat. Callable from the debug console.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call digii_ambient_zones_fnc_debugListZones
 *
 * Public: Yes
 */

if (isNil QGVAR(registry)) exitWith {
    systemChat "[digii_ambient] registry is nil";
};

private _n = count GVAR(registry);
systemChat format ["[digii_ambient] %1 zone(s) in registry:", _n];

{
    private _id = _x;
    private _e = _y;
    systemChat format [
        "  %1  center=%2  r=%3m  sf=%4  label=%5",
        _id,
        _e get "center",
        _e get "radius",
        _e get "subFactionId",
        _e get "label"
    ];
} forEach GVAR(registry);
