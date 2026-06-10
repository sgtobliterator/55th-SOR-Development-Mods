#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Generates a mission-unique zone id (not RFC-4122, just timestamp + random suffix).
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Zone id like "zone_1234567890_654321" <STRING>
 *
 * Example:
 * call digii_ambient_common_fnc_uuid
 *
 * Public: No
 */

private _t = round (diag_tickTime * 1000);
private _r = round (random 999999);
format ["zone_%1_%2", _t, _r]
