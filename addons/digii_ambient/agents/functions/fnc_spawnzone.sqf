#include "..\script_component.hpp"

/*
 * Author: DiGii
 * Spawns units for a zone. Always uses full units (not agents):
 *   - 3DEN editor: create3DENEntity (editor units)
 *   - Runtime:     createUnit into per-zone reusable groups
 *
 * Branches on `kind` (default "military"):
 *
 *   Military (kind="military"):
 *     - GUARD slots with useBuildings ON + an unused building ->
 *       garrisonBuilding (military baseline: AWARE/YELLOW, max 20).
 *     - PATROL slots -> spawnPatrolGroup (2-4 unit cyclic patrol).
 *     - OFFICER -> center-biased spawnSoloUnit from officer pool.
 *     - GUARD fallback / IDLER / WANDERER -> spawnSoloUnit.
 *
 *   Civilian (kind="civilian"):
 *     - CIV_GARRISON slots with useBuildings ON + an unused building ->
 *       garrisonBuilding with cap=3, passive=true (SAFE/BLUE residents).
 *     - CIV_GARRISON without a building -> falls through to passive IDLER.
 *     - IDLER / WANDERER -> spawnSoloUnit with passive=true (SAFE/BLUE).
 *     - No PATROL, no OFFICER. Skill fixed at 0.2.
 *
 * Arguments:
 * 0: Settings hashmap (id, center, radius, subFactionId, density, skillCap,
 *    roleMix, includeOfficer, useBuildings, useRoads, kind) <HASHMAP>
 *
 * Return Value:
 * Spawned units; empty on failure <ARRAY>
 *
 * Example:
 * [_settings] call digii_ambient_agents_fnc_spawnZone
 *
 * Public: No
 */

params ["_settings"];

private _kind = _settings getOrDefault ["kind", "military"];
private _isCivilian = _kind == "civilian";

private _zoneId         = _settings get "id";
private _center         = _settings get "center";
private _radius         = _settings get "radius";
private _subFactionId   = _settings get "subFactionId";
private _density        = _settings get "density";
private _skillCap       = if (_isCivilian) then { 0.2 } else { _settings get "skillCap" };
private _includeOfficer = _settings getOrDefault ["includeOfficer", false];
private _useBuildings   = _settings getOrDefault ["useBuildings",   false];
private _useRoads       = _settings getOrDefault ["useRoads",       false];

// Role mix defaults per kind: military 4-slot, civilian 3-slot.
private _roleMixDefault = if (_isCivilian) then { [34, 33, 33] } else { [50, 25, 15, 10] };
private _roleMix = _settings getOrDefault ["roleMix", _roleMixDefault];

private _unitPool = if (_isCivilian) then {
    [_subFactionId] call EFUNC(factions,getSubFactionUnitsCivilian)
} else {
    [_subFactionId] call EFUNC(factions,getSubFactionUnits)
};
if (_unitPool isEqualTo []) exitWith {
    diag_log format ["[digii_ambient] spawnZone: sub-faction %1 has no units (kind=%2)", _subFactionId, _kind];
    []
};

private _side = if (_isCivilian) then {
    civilian
} else {
    _subFactionId call EFUNC(factions,getSubFactionSide)
};

private _count = [_radius, _density] call FUNC(computeSpawnCount);
private _roles = [_count, _roleMix, _includeOfficer, _kind] call FUNC(distributeRoles);
private _spawned = [];

// Each solo unit (IDLER / WANDERER / OFFICER) gets its own per-unit
// group inside fnc_spawnSoloUnit -- no shared per-zone group anymore.
// Avoids formation interference + deleteWhenEmpty cascade issues.

// Candidate buildings for garrison. nearestObjects returns distance-sorted,
// but we pick at random below so garrisons spread across the zone instead of
// clustering at the center. Filter requires "has at least one defined
// position". Each Garrison slot consumes one building (random deleteAt)
// until the list is empty.
private _availableBuildings = [];
if (_useBuildings) then {
    _availableBuildings = (nearestObjects [_center, ["House", "Building"], _radius])
        select { _x buildingPos - 1 isNotEqualTo []};
};

// Civilian garrison parameters (no-op for military).
private _garrisonCap     = if (_isCivilian) then { CIVILIAN_GARRISON_MAX_UNITS_PER_BUILDING } else { GARRISON_MAX_UNITS_PER_BUILDING };
private _garrisonRoleTag = if (_isCivilian) then { ROLE_CIV_GARRISON } else { ROLE_GUARD };

for "_i" from 0 to (_count - 1) do {
    private _role = _roles select _i;
    private _doGarrison = (_role == _garrisonRoleTag) && {_useBuildings} && {_availableBuildings isNotEqualTo []};

    if (_doGarrison) then {
        private _bld = _availableBuildings deleteAt (floor random (count _availableBuildings));
        _spawned append ([_bld, _zoneId, _unitPool, _skillCap, _side, _garrisonCap, _isCivilian] call FUNC(garrisonBuilding));
    } else {
        if (_role == ROLE_PATROL) then {
            // Military-only path.
            _spawned append ([_zoneId, _center, _radius, _unitPool, _skillCap, _side, _useRoads] call FUNC(spawnPatrolGroup));
        } else {
            if (_role == ROLE_OFFICER) then {
                // Military-only path.
                private _officerPool = [_subFactionId] call EFUNC(factions,getSubFactionOfficers);
                if (_officerPool isEqualTo []) then { _officerPool = _unitPool };
                private _officerRadius = (_radius * 0.3) max 10;
                private _u = [_side, _center, _officerRadius, _officerPool, _skillCap, _zoneId, _role, false, false] call FUNC(spawnSoloUnit);
                if (!isNull _u) then { _spawned pushBack _u };
            } else {
                // GUARD / CIV_GARRISON without a building falls through to IDLER
                // (with appropriate passive flag for the kind).
                private _effRole = if (_role == _garrisonRoleTag) then { ROLE_IDLER } else { _role };
                private _u = [_side, _center, _radius, _unitPool, _skillCap, _zoneId, _effRole, _useRoads, _isCivilian] call FUNC(spawnSoloUnit);
                if (!isNull _u) then { _spawned pushBack _u };
            };
        };
    };
};

INFO_3("Spawned %1 units in zone %2 (kind=%3)",count _spawned,_zoneId,_kind);

_spawned
