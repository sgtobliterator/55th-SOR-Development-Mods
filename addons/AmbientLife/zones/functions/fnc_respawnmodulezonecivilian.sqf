#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Civilian sibling of fnc_respawnModuleZone. Despawns any entities
 * previously spawned for this civilian module logic, then spawns fresh
 * ones using the logic's current `digii_ambient_civZone_*` setVariable
 * values + position. Used by fnc_applyZoneDialogCivilian on the 3DEN
 * Apply path.
 *
 * Arguments:
 * 0: Module logic <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_logic] call digii_ambient_zones_fnc_respawnModuleZoneCivilian
 *
 * Public: No
 */

params [["_logic", objNull, [objNull]]];
if (isNull _logic) exitWith {};

private _zoneId = format ["3den_civ_%1", _logic];

// Despawn whatever was tracked previously.
private _existing = _logic getVariable ["digii_ambient_civZone_spawnedEntities", []];
if (count _existing > 0) then {
    private _despawnSettings = createHashMapFromArray [
        ["id",     _zoneId],
        ["agents", _existing]
    ];
    [_despawnSettings] call EFUNC(agents,despawnZone);
};

private _settings = createHashMapFromArray [
    ["id",           _zoneId],
    ["center",       getPosATL _logic],
    ["radius",       _logic getVariable ["digii_ambient_civZone_radius",       75]],
    ["subFactionId", _logic getVariable ["digii_ambient_civZone_subFactionId", ""]],
    ["density",      _logic getVariable ["digii_ambient_civZone_density",      5]],
    ["roleMix",      _logic getVariable ["digii_ambient_civZone_roleMix",      [34, 33, 33]]],
    ["useBuildings", _logic getVariable ["digii_ambient_civZone_useBuildings", true]],
    ["useRoads",     _logic getVariable ["digii_ambient_civZone_useRoads",     true]],
    ["kind",         "civilian"]
];

private _spawned = [_settings] call EFUNC(agents,spawnZone);
// NOT persistent (no `true`): _spawned is an array of object references
// which can't round-trip through mission.sqm serialization. Including it
// in the persistent Variables block makes 3DEN drop the *whole* block,
// taking subFactionId / radius / etc. with it. Keep it session-local --
// it's only read by the next Apply click within the same edit session
// to despawn previous editor entities.
_logic setVariable ["digii_ambient_civZone_spawnedEntities", _spawned];

// Track for poll-based delete detection in fnc_drawZones (3DEN has no
// reliable OnDeletingEntities event, so we sweep this map each frame).
private _tracked = missionNamespace getVariable [QGVAR(tracked3DENModules), createHashMap];
_tracked set [_zoneId, [_logic, _spawned]];
missionNamespace setVariable [QGVAR(tracked3DENModules), _tracked];

diag_log format ["[digii_ambient] respawnModuleZoneCivilian: respawned %1 entities for %2", count _spawned, _logic];
