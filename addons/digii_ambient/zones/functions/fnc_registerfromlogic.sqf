#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Reads a placed module logic's setVariable values, packages them as a
 * settings hashmap, calls fnc_registerZone, then deletes the logic.
 * Used by XEH_postInit to enumerate all 3DEN-placed modules at mission start
 * (sidesteps BIS fn_moduleInit's string-_logic quirk). Server-only.
 *
 * Arguments:
 * 0: Module logic <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_logic] call digii_ambient_zones_fnc_registerFromLogic
 *
 * Public: No
 */

params [["_logic", objNull, [objNull]]];
if (isNull _logic) exitWith {};
if (!isServer) exitWith {};

// 3DEN-placed at preview: setVariables on Module_F logic don't persist
// through mission.sqm save/load, so subFactionId reads back empty. The
// units spawned at 3DEN edit time persist in the world and carry their
// own per-unit Init attribute stamps (assembled by applyRoleBehavior /
// spawnPatrolGroup / garrisonBuilding 3DEN branches), so they
// reconstitute their behavior on their own. Nothing for this function
// to spawn -- bail cleanly. Zeus path always populates subFactionId
// in-memory before calling, so this guard never trips there.
if ((_logic getVariable ["digii_ambient_zone_subFactionId", ""]) == "") exitWith {
    diag_log "[digii_ambient] registerFromLogic: 3DEN-placed with empty settings, skipping (units self-init via Init attribute)";
};

// Migrate legacy 5-slot roleMix (G,P,I,Exerciser,W) to 4-slot (G,P,I,W)
// by dropping the Exerciser slot.
private _roleMix = _logic getVariable ["digii_ambient_zone_roleMix", [50, 25, 15, 10]];
if (count _roleMix == 5) then { _roleMix = [_roleMix#0, _roleMix#1, _roleMix#2, _roleMix#4] };

private _settings = createHashMapFromArray [
    ["center",         getPosATL _logic],
    ["radius",         _logic getVariable ["digii_ambient_zone_radius",         75]],
    ["subFactionId",   _logic getVariable ["digii_ambient_zone_subFactionId",   ""]],
    ["label",          _logic getVariable ["digii_ambient_zone_label",          ""]],
    ["density",        _logic getVariable ["digii_ambient_zone_density",        5]],
    ["useBuildings",   _logic getVariable ["digii_ambient_zone_useBuildings",   true]],
    ["useRoads",       _logic getVariable ["digii_ambient_zone_useRoads",       true]],
    ["skillCap",       _logic getVariable ["digii_ambient_zone_skillCap",       0.2]],
    ["includeOfficer", _logic getVariable ["digii_ambient_zone_includeOfficer", false]],
    ["roleMix",        _roleMix],
    ["placerUid",      _logic getVariable ["digii_ambient_zone_placerUid",      ""]]
];

private _id = _settings call FUNC(registerZone);
INFO_2("Registered zone %1 from logic at %2",_id,_settings get "center");

// Spawn agents for the zone and store refs in the registry entry.
private _entry = GVAR(registry) get _id;
private _spawned = [_entry] call EFUNC(agents,spawnZone);
_entry set ["agents", _spawned];

// Zeus-placed zone: add spawned agents to the placing curator so they
// can be selected / controlled without a manual add. Placer-scoped to
// match the ring visibility convention; other curators must add the
// units themselves if they want to manage them. Silent fall-through if
// the placer disconnected before spawn finished.
private _placerUid = _entry get "placerUid";
if (_placerUid != "" && {_spawned isNotEqualTo []}) then {
    private _curator = (allCurators select {
        _placerUid == getPlayerUID (getAssignedCuratorUnit _x)
    }) param [0, objNull];
    if (!isNull _curator) then {
        _curator addCuratorEditableObjects [_spawned, true];
    };
};

deleteVehicle _logic;
