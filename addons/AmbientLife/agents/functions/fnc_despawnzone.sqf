#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Deletes all entities tracked in the zone settings' "agents" field.
 * Each unit was spawned into its own per-unit group with
 * deleteWhenEmpty=true, so groups auto-clean once their unit is gone.
 * Branches on is3DEN for the right deletion primitive.
 *
 * Arguments:
 * 0: Settings hashmap (uses "id" and "agents") <HASHMAP>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_settings] call digii_ambient_agents_fnc_despawnZone
 *
 * Public: No
 */

params ["_settings"];

private _zoneId = _settings get "id";
private _agents = _settings getOrDefault ["agents", []];

{
    if (!isNull _x) then {
        if (is3DEN) then {
            delete3DENEntities [_x];
        } else {
            deleteVehicle _x;
        };
    };
} forEach _agents;

_settings set ["agents", []];

INFO_1("Despawned entities in zone %1",_zoneId);
