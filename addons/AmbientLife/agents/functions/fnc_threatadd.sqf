#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Adds (or subtracts, if negative) to a civilian's threat variable.
 * Clamps to [0.0, 1.0] and rounds to the nearest 0.1 step. Broadcasts
 * the new value publicly so client-side visualizers / future behavior
 * dispatch can read it in dedicated MP.
 *
 * Used by:
 *   - fnc_initCivilianThreat (FiredNear and Killed event handlers)
 *   - fnc_threatTick (decay)
 *   - future Step 15 behavior dispatch (e.g. proximity panic)
 *
 * Arguments:
 * 0: Civilian unit <OBJECT>
 * 1: Signed delta to add to current threat <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_civ, 0.3] call digii_ambient_agents_fnc_threatAdd
 *
 * Public: No
 */

params [["_unit", objNull, [objNull]], ["_amount", 0, [0]]];
if (isNull _unit || {!alive _unit}) exitWith {};

private _t = _unit getVariable ["digii_ambient_threat", 0];
_t = ((_t + _amount) max 0) min 1;
_t = (round (_t * 10)) / 10;
_unit setVariable ["digii_ambient_threat", _t, true];
