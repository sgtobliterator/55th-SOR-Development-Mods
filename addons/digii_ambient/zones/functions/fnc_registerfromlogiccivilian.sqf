#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Civilian sibling of fnc_registerFromLogic. Reads
 * `digii_ambient_civZone_*` setVariable values from the module logic,
 * packages them as a settings hashmap with `kind = "civilian"`, calls
 * fnc_registerZone, spawns agents via the (kind-aware) spawn pipeline,
 * adds them to the placing curator if applicable, and deletes the
 * logic. Server-only.
 *
 * Arguments:
 * 0: Module logic <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_logic] call digii_ambient_zones_fnc_registerFromLogicCivilian
 *
 * Public: No
 */

params [["_logic", objNull, [objNull]]];
if (isNull _logic) exitWith {};
if (!isServer) exitWith {};

// 3DEN-placed at preview: the dialog's setVariables don't persist through
// mission.sqm save/load on Module_F logic entities, so subFactionId reads
// back empty. The civilians spawned at edit time persist in the world AND
// carry their own Init attribute stamp that calls fnc_initCivilianThreat
// on themselves at mission start. So there's nothing for this function to
// spawn -- bail cleanly. Zeus path always populates subFactionId in-memory
// before calling, so this guard never trips there.
if ((_logic getVariable ["digii_ambient_civZone_subFactionId", ""]) == "") exitWith {
    diag_log "[digii_ambient] registerFromLogicCivilian: 3DEN-placed with empty settings, skipping (civilians self-init via Init attribute)";
};

private _settings = createHashMapFromArray [
    ["center",       getPosATL _logic],
    ["radius",       _logic getVariable ["digii_ambient_civZone_radius",       75]],
    ["subFactionId", _logic getVariable ["digii_ambient_civZone_subFactionId", ""]],
    ["label",        _logic getVariable ["digii_ambient_civZone_label",        ""]],
    ["density",      _logic getVariable ["digii_ambient_civZone_density",      5]],
    ["useBuildings", _logic getVariable ["digii_ambient_civZone_useBuildings", true]],
    ["useRoads",     _logic getVariable ["digii_ambient_civZone_useRoads",     true]],
    ["roleMix",      _logic getVariable ["digii_ambient_civZone_roleMix",      [34, 33, 33]]],
    ["kind",         "civilian"],
    ["placerUid",    _logic getVariable ["digii_ambient_civZone_placerUid",    ""]]
];

private _id = _settings call FUNC(registerZone);
INFO_2("Registered civilian zone %1 from logic at %2",_id,_settings get "center");

// Spawn civilians for the zone and store refs in the registry entry.
private _entry = GVAR(registry) get _id;
private _spawned = [_entry] call EFUNC(agents,spawnZone);
_entry set ["agents", _spawned];

// Same curator hookup as the military path: Zeus-placed civilian zones
// (placerUid != "") get their agents added to the placing curator so
// they're immediately selectable without a manual add.
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
