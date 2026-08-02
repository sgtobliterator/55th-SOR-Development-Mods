#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Idempotent Draw3D registration. Called from two paths:
 *   - Cfg3DEN.EventHandlers.onMissionLoad / onMissionNew (3DEN editor)
 *   - XEH_postInit (mission runtime / Zeus)
 *
 * Guarded by a missionNamespace flag. Each session has its own missionNamespace
 * so the flag re-resets across sessions (good: each session gets a fresh
 * registration). Within a session, prevents double-registration if both paths
 * trigger.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * [] call digii_ambient_zones_fnc_registerDraw3D
 *
 * Public: No
 */

if (!hasInterface) exitWith {};

if (missionNamespace getVariable [QGVAR(draw3DRegistered), false]) exitWith {};
missionNamespace setVariable [QGVAR(draw3DRegistered), true];

addMissionEventHandler ["Draw3D", {
    [] call FUNC(drawZones);
}];
