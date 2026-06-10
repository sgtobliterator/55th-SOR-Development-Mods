#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Toggleable runtime debug visualizer for WANDERER destinations. Draws a
 * yellow line from each wanderer's head to their expectedDestination plus
 * a small dot at the destination, so it's obvious where each unit is
 * heading (and whether targets distribute across the zone).
 *
 * First call enables; second call disables. Runtime only -- registers a
 * Draw3D mission event handler which doesn't fire in 3DEN editor mode.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call digii_ambient_agents_fnc_debugWanderers
 *
 * Public: Yes
 */

private _ehId = missionNamespace getVariable [QGVAR(debugWanderersEH), -1];

if (_ehId >= 0) then {
    removeMissionEventHandler ["Draw3D", _ehId];
    missionNamespace setVariable [QGVAR(debugWanderersEH), -1];
    systemChat "[digii_ambient] Wanderer destination viz: OFF";
} else {
    _ehId = addMissionEventHandler ["Draw3D", {
        {
            if (_x getVariable ["digii_ambient_role", ""] == ROLE_WANDERER && {alive _x}) then {
                private _dest = expectedDestination _x;
                if (count _dest > 0) then {
                    private _destPos = _dest select 0;
                    drawLine3D [(getPosATL _x) vectorAdd [0, 0, 1.6], _destPos, [1, 1, 0, 0.9]];
                    drawIcon3D ["", [1, 1, 0, 0.9], _destPos vectorAdd [0, 0, 0.5], 0.6, 0.6, 0, "", 1, 0.04, "TahomaB"];
                };
            };
        } forEach allUnits;
    }];
    missionNamespace setVariable [QGVAR(debugWanderersEH), _ehId];
    systemChat "[digii_ambient] Wanderer destination viz: ON";
};
