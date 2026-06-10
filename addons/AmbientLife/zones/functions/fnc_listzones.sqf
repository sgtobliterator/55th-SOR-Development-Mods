#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Returns all zone ids currently in the registry.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Zone ids <ARRAY>
 *
 * Example:
 * call digii_ambient_zones_fnc_listZones
 *
 * Public: Yes
 */

if (isNil QGVAR(registry)) exitWith {[]};

keys GVAR(registry)
