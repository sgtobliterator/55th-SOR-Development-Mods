#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Despawns any entities previously spawned for this logic, then spawns fresh
 * ones using the logic's current setVariable values + position. Used by:
 *   - fnc_applyZoneDialog (3DEN branch, after settings are saved)
 *   - OnObjectMoved 3DEN hook (silent respawn after drag)
 *
 * Arguments:
 * 0: Module logic <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_logic] call digii_ambient_zones_fnc_respawnModuleZone
 *
 * Public: No
 */

params [["_logic", objNull, [objNull]]];
if (isNull _logic) exitWith {};

private _zoneId = format ["3den_%1", _logic];

// Despawn whatever was tracked previously.
private _existing = _logic getVariable ["digii_ambient_zone_spawnedEntities", []];
if (count _existing > 0) then {
    private _despawnSettings = createHashMapFromArray [
        ["id",     _zoneId],
        ["agents", _existing]
    ];
    [_despawnSettings] call EFUNC(agents,despawnZone);
};

// Spawn fresh from current logic state. Migrate legacy 5-slot roleMix
// (G,P,I,Exerciser,W) to 4-slot (G,P,I,W) by dropping the Exerciser slot.
private _roleMix = _logic getVariable ["digii_ambient_zone_roleMix", [50, 25, 15, 10]];
if (count _roleMix == 5) then { _roleMix = [_roleMix#0, _roleMix#1, _roleMix#2, _roleMix#4] };

private _settings = createHashMapFromArray [
    ["id",           _zoneId],
    ["center",       getPosATL _logic],
    ["radius",       _logic getVariable ["digii_ambient_zone_radius",       75]],
    ["subFactionId", _logic getVariable ["digii_ambient_zone_subFactionId", ""]],
    ["density",      _logic getVariable ["digii_ambient_zone_density",      5]],
    ["skillCap",       _logic getVariable ["digii_ambient_zone_skillCap",       0.2]],
    ["roleMix",        _roleMix],
    ["includeOfficer", _logic getVariable ["digii_ambient_zone_includeOfficer", false]],
    ["useBuildings",   _logic getVariable ["digii_ambient_zone_useBuildings",   false]],
    ["useRoads",       _logic getVariable ["digii_ambient_zone_useRoads",       false]]
];

private _spawned = [_settings] call EFUNC(agents,spawnZone);
// NOT persistent (no `true`): _spawned is an array of object references
// which can't round-trip through mission.sqm serialization. Including it
// in the persistent Variables block makes 3DEN drop the *whole* block,
// taking subFactionId / radius / etc. with it. Keep it session-local --
// it's only read by the next Apply click within the same edit session
// to despawn previous editor entities.
_logic setVariable ["digii_ambient_zone_spawnedEntities", _spawned];

// Track for poll-based delete detection in fnc_drawZones (3DEN has no
// reliable OnDeletingEntities event, so we sweep this map each frame).
private _tracked = missionNamespace getVariable [QGVAR(tracked3DENModules), createHashMap];
_tracked set [_zoneId, [_logic, _spawned]];
missionNamespace setVariable [QGVAR(tracked3DENModules), _tracked];

diag_log format ["[digii_ambient] respawnModuleZone: respawned %1 entities for %2", count _spawned, _logic];
