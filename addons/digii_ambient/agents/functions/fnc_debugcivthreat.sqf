#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Toggleable runtime debug visualizer for civilian THREAT levels. Draws
 * a colored dot ~2m above each civilian's head with the threat value
 * (0.0..1.0) as a label. Color gradient: green at 0.0 → yellow at 0.5
 * → red at 1.0, so a panicking civilian is unmissable at a glance.
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
 * [] call digii_ambient_agents_fnc_debugCivThreat
 *
 * Public: Yes
 */

private _ehId = missionNamespace getVariable [QGVAR(debugCivThreatEH), -1];

if (_ehId >= 0) then {
    removeMissionEventHandler ["Draw3D", _ehId];
    missionNamespace setVariable [QGVAR(debugCivThreatEH), -1];
    systemChat "[digii_ambient] Civilian threat viz: OFF";
} else {
    _ehId = addMissionEventHandler ["Draw3D", {
        {
            if ((_x getVariable ["digii_ambient_passive", false]) && {alive _x}) then {
                private _t = _x getVariable ["digii_ambient_threat", 0];
                // Color gradient: 0.0..0.5 green→yellow, 0.5..1.0 yellow→red.
                private _color = if (_t < 0.5) then {
                    [_t * 2, 1, 0, 0.9]
                } else {
                    [1, 1 - ((_t - 0.5) * 2), 0, 0.9]
                };
                // Vertical beam above the head + text label at the top.
                // drawLine3D guarantees visibility at any range the unit
                // is renderable; drawIcon3D's text alone is small and
                // easy to miss against terrain.
                private _base  = (getPosATL _x) vectorAdd [0, 0, 0.5];
                private _top   = (getPosATL _x) vectorAdd [0, 0, 3];
                private _label = _top vectorAdd [0, 0, 0.3];
                drawLine3D [_base, _top, _color];
                drawIcon3D ["", _color, _label, 0.5, 0.5, 0, format ["%1", _t], 1, 0.05, "TahomaB"];
            };
        } forEach allUnits;
    }];
    missionNamespace setVariable [QGVAR(debugCivThreatEH), _ehId];
    systemChat "[digii_ambient] Civilian threat viz: ON";
};
