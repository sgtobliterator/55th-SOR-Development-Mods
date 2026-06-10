#include "script_component.hpp"

/*
 * Author: DiGii
 * CBA XEH postInit entry point for the zones component.
 *
 * Two responsibilities:
 *   - Register the Draw3D mission event handler (clients) so the
 *     3DEN orphan-cleanup poll fires. 3DEN editor path is handled
 *     separately via Cfg3DEN onMissionLoad/onMissionNew.
 *   - On the server, register CBA event handlers that the Apply
 *     dialog routes spawn requests through. Required so dedicated
 *     servers actually run registerFromLogic -- direct calls from
 *     the placing client get blocked by the `isServer` guard inside
 *     registerFromLogic.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * Auto-fired by CBA XEH; do not call manually.
 *
 * Public: No
 */

[] call FUNC(registerDraw3D);

if (isServer) then {
    [QGVAR(applyZoneServer), {
        params [["_logic", objNull, [objNull]]];
        if (isNull _logic) exitWith {};
        [_logic] call FUNC(registerFromLogic);
    }] call CBA_fnc_addEventHandler;

    [QGVAR(applyZoneCivilianServer), {
        params [["_logic", objNull, [objNull]]];
        if (isNull _logic) exitWith {};
        [_logic] call FUNC(registerFromLogicCivilian);
    }] call CBA_fnc_addEventHandler;
};
