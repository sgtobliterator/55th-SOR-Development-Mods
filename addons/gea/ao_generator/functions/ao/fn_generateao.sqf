// =====================================================================
// GEA_fnc_generateAO
//   Server-side orchestrator. Resolves the group + infantry pools once,
//   then dispatches each subsystem:
//     - infantry patrols
//     - garrison (units inside buildings, small fireteams)
//     - vehicle patrols (cars/APCs/tanks, weighted by user %)
//     - air patrols (heli/jet/drone/plane, weighted by user %)
//
//   Everything that gets spawned flows into registerCleanup which
//   tags entities, records them, and adds them to Zeus.
//
//   Diagnostics: per-step output goes to diag_log (.rpt) only. A single
//   summary chat is sent to the curator at the end so they see the
//   result without spam during spawning.
//
//   v0.7.0 changes:
//     - Garrison is now an absolute group count (garrisonGroups),
//       independent of patrols. Each garrison group is a small fireteam
//       (2-4 units) capped by available building slots.
//     - Vehicle / Air type mix comes from per-type % sliders, normalized
//       in this function and used to weight the pick per spawn slot.
//     - Air pipeline goes through 4 spawners: heli / jet / drone / plane.
//     - On marker spawn we also spawn a small visible "AO anchor" object
//       at the center, registered with Zeus. Deleting that anchor via
//       Zeus right-click removes the AO markers — fixes the bug where
//       markers were undeletable.
//
//   Returns: the AO id (string), or "" on early-exit.
// =====================================================================

#include "..\..\script_component.hpp"

if (!isServer) exitWith {
    diag_log text "[GEA] fn_generateAO called on client — ignoring (server-authoritative).";
    ""
};

params [
    ["_aoConfig", createHashMap, [createHashMap]],
    ["_callerOwner", 0, [0]]
];

private _aoId           = _aoConfig get "id";
private _center         = _aoConfig get "center";
private _radius         = _aoConfig get "radius";
private _side           = _aoConfig get "side";
private _faction        = _aoConfig get "faction";
private _patrolGroups   = _aoConfig get "patrolGroups";
private _garrisonGroups = _aoConfig get "garrisonGroups";
private _staticTurrets  = _aoConfig getOrDefault ["staticTurrets", 0];
private _vehiclePatrols = _aoConfig get "vehiclePatrols";
private _vehiclePct     = _aoConfig getOrDefault ["vehiclePct", [70, 20, 10]];
private _airPatrols     = _aoConfig get "airPatrols";
private _airPct         = _aoConfig getOrDefault ["airPct",     [60, 20, 10, 10]];
private _showMarker     = _aoConfig get "showMarker";

// .rpt-only diagnostic helper.
private _log = {
    params ["_msg"];
    diag_log text format ["[GEA] %1", _msg];
};

// Summary chat for the curator at the end of the run.
private _saySummary = {
    params ["_msg"];
    diag_log text format ["[GEA] %1", _msg];
    if (_callerOwner > 0) then {
        [format ["[GEA] %1", _msg]] remoteExec ["systemChat", _callerOwner];
    } else {
        systemChat format ["[GEA] %1", _msg];
    };
};

[format ["generateAO START id=%1 side=%2 faction=%3 r=%4 patrols=%5 garr=%6 statics=%7 veh=%8 vehPct=%9 air=%10 airPct=%11",
    _aoId, _side, _faction, _radius, _patrolGroups, _garrisonGroups,
    _staticTurrets, _vehiclePatrols, _vehiclePct, _airPatrols, _airPct]] call _log;

// --- Sanity --------------------------------------------------------------
if (!([_center] call GEA_fnc_validateAOPosition)) exitWith {
    ["AO position invalid (water?) — aborting."] call _saySummary;
    ""
};

// --- Group pool (infantry-only after the CfgGroups filter) ---------------
private _groupPool = [_side, _faction] call GEA_fnc_getGroupsForFaction;
[format ["Group pool for %1: %2", _faction, count _groupPool]] call _log;

if (_groupPool isEqualTo []) exitWith {
    [format ["No infantry groups available for '%1' — aborting.", _faction]] call _saySummary;
    ""
};
_aoConfig set ["groupPool", _groupPool];

// --- Infantry classnames cache (for garrison + vehicle cargo) -----------
// Tier 1: faction. Tier 2: side fallback.
private _sideNum = switch (_side) do {
    case east:        { 0 };
    case west:        { 1 };
    case independent: { 2 };
    case civilian:    { 3 };
    default           { -1 };
};

// Reject VR / virtual-entity "soldiers" — these share real factions in
// vanilla, so an unfiltered faction/side scan can pick e.g. B_Soldier_VR_F
// to crew a turret. We want only real combat infantry.
private _fnc_isVirtualMan = {
    params ["_cfg", "_class"];
    if ((getText (_cfg >> "editorSubcategory")) == "EdSubcat_VirtualEntities") exitWith { true };
    if (_class isKindOf "VirtualMan_F") exitWith { true };
    if (toLower _class find "_vr_" >= 0) exitWith { true };
    false
};

private _infantryClasses = [];
{
    private _cfg   = _x;
    private _class = configName _cfg;
    if (getNumber (_cfg >> "scope") >= 2
        && { _class isKindOf "CAManBase" }
        && { !([_cfg, _class] call _fnc_isVirtualMan) }
        && { (getText (_cfg >> "faction")) == _faction }
    ) then {
        _infantryClasses pushBack _class;
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));

if (_infantryClasses isEqualTo []) then {
    // Side fallback.
    {
        private _cfg   = _x;
        private _class = configName _cfg;
        if (getNumber (_cfg >> "scope") >= 2
            && { _class isKindOf "CAManBase" }
            && { !([_cfg, _class] call _fnc_isVirtualMan) }
            && { (getNumber (_cfg >> "side")) == _sideNum }
        ) then {
            _infantryClasses pushBack _class;
        };
    } forEach ("true" configClasses (configFile >> "CfgVehicles"));
};
_aoConfig set ["infantryClasses", _infantryClasses];
[format ["Infantry classes cached: %1", count _infantryClasses]] call _log;

// =====================================================================
//  Weighted-pick helper.
//    _weights : array of non-negative numbers (any scale)
//    Returns  : an INDEX into _weights, picked with probability
//               proportional to its weight. If all weights are 0, picks
//               uniformly. If the array is empty, returns -1.
// =====================================================================
private _fnc_weightedPick = {
    params ["_weights"];
    private _n = count _weights;
    if (_n == 0) exitWith { -1 };

    private _total = 0;
    { _total = _total + (_x max 0) } forEach _weights;

    if (_total <= 0) exitWith {
        // All-zero → uniform fallback.
        floor (random _n)
    };

    private _roll = random _total;
    private _acc  = 0;
    private _idx  = -1;
    {
        _acc = _acc + (_x max 0);
        if (_roll < _acc) exitWith { _idx = _forEachIndex };
    } forEach _weights;
    if (_idx < 0) then { _idx = _n - 1 };   // float-edge safety
    _idx
};

// Master entity list (groups + vehicles) → registerCleanup at the end.
private _entities = [];

// =====================================================================
//  1) INFANTRY PATROLS
// =====================================================================
private _patrolsSpawned = 0;
for "_i" from 1 to _patrolGroups do {
    private _grp = [_aoConfig] call GEA_fnc_spawnPatrolGroup;
    if (!isNull _grp) then {
        _entities pushBack _grp;
        _patrolsSpawned = _patrolsSpawned + 1;
    };
};
[format ["Patrols: %1/%2 spawned.", _patrolsSpawned, _patrolGroups]] call _log;

// =====================================================================
//  2) GARRISON  (small fireteams, one per building)
//     Per-building size: random 2..4, capped by usable slot count.
//     Iterate until garrisonGroups groups placed OR no buildings left.
// =====================================================================
private _garrisonPlaced   = 0;
private _garrisonGroupsOk = 0;

if (_garrisonGroups > 0) then {
    private _buildings = [_center, _radius] call GEA_fnc_findBuildings;
    [format ["Garrison: target %1 groups, %2 candidate buildings.",
        _garrisonGroups, count _buildings]] call _log;

    _buildings = _buildings call BIS_fnc_arrayShuffle;

    while {_garrisonGroupsOk < _garrisonGroups && count _buildings > 0} do {
        private _b = _buildings deleteAt 0;
        // Real, valid slots (same filter as fillBuilding uses).
        private _slots = (_b buildingPos -1) select {
            !(_x isEqualTo [0,0,0]) && { (_x select 2) > -5 }
        };
        private _slotCount = count _slots;
        if (_slotCount < 1) then { continue };

        // Fireteam size: random 2..4, capped by usable slots.
        // If the building only has 1 slot, the loop above filtered it
        // already; floors the size at 1 for safety.
        private _per = ((2 + floor random 3) min _slotCount) max 1;

        private _grp = [_aoConfig, _b, _per] call GEA_fnc_spawnGarrisonGroup;
        if (!isNull _grp && { count (units _grp) > 0 }) then {
            _entities pushBack _grp;
            _garrisonPlaced   = _garrisonPlaced   + count (units _grp);
            _garrisonGroupsOk = _garrisonGroupsOk + 1;
        };
    };

    [format ["Garrison: %1 groups (%2 units) placed (of %3 requested).",
        _garrisonGroupsOk, _garrisonPlaced, _garrisonGroups]] call _log;
};

// =====================================================================
//  2.5) STATIC DEFENCES  (manned static weapons, facing outward)
//     Each turret is a random StaticWeapon from the faction pool (side
//     fallback), placed on the AO perimeter pointing away from centre.
//     The spawner returns [_static, _crewGroup]; both go to cleanup.
// =====================================================================
private _staticsSpawned = 0;
for "_i" from 1 to _staticTurrets do {
    private _res = [_aoConfig] call GEA_fnc_spawnStaticDefense;
    _res params [["_static", objNull], ["_crewGrp", grpNull]];
    if (!isNull _static) then {
        _entities pushBack _static;
        if (!isNull _crewGrp) then { _entities pushBack _crewGrp };
        _staticsSpawned = _staticsSpawned + 1;
    };
};
[format ["Statics: %1/%2 spawned.", _staticsSpawned, _staticTurrets]] call _log;

// =====================================================================
//  3) VEHICLE PATROLS
//     Per slot: weighted pick over [car, apc, tank] using vehiclePct.
//     The spawner already handles fallback if the rolled bucket is empty.
// =====================================================================
private _vehiclesSpawned = 0;
private _vehTypeOrder    = ["car", "apc", "tank"];
private _vehTypeCounts   = createHashMap;
{ _vehTypeCounts set [_x, 0] } forEach _vehTypeOrder;

for "_i" from 1 to _vehiclePatrols do {
    private _pickIdx = [_vehiclePct] call _fnc_weightedPick;
    if (_pickIdx < 0) then { _pickIdx = 0 };
    private _wantType = _vehTypeOrder select _pickIdx;

    private _res = [_aoConfig, _wantType] call GEA_fnc_spawnVehiclePatrol;
    _res params [["_veh", objNull], ["_crewGrp", grpNull], ["_cargoGrp", grpNull], ["_actualType", _wantType]];

    if (!isNull _veh) then {
        _entities pushBack _veh;
        if (!isNull _crewGrp)  then { _entities pushBack _crewGrp };
        if (!isNull _cargoGrp) then { _entities pushBack _cargoGrp };
        _vehiclesSpawned = _vehiclesSpawned + 1;
        _vehTypeCounts set [_actualType, (_vehTypeCounts get _actualType) + 1];
    };
};
[format ["Vehicles: %1/%2 spawned. mix: car=%3 apc=%4 tank=%5",
    _vehiclesSpawned, _vehiclePatrols,
    _vehTypeCounts get "car", _vehTypeCounts get "apc", _vehTypeCounts get "tank"]] call _log;

// =====================================================================
//  4) AIR PATROLS  (heli / jet / drone / plane, weighted by airPct)
// =====================================================================
private _airTypeOrder = ["heli", "jet", "drone", "plane"];
private _airSpawnFns  = createHashMapFromArray [
    ["heli",  "GEA_fnc_spawnHeliPatrol"],
    ["jet",   "GEA_fnc_spawnJetPatrol"],
    ["drone", "GEA_fnc_spawnDronePatrol"],
    ["plane", "GEA_fnc_spawnPlanePatrol"]
];
private _airCounts = createHashMap;
{ _airCounts set [_x, 0] } forEach _airTypeOrder;

private _airSpawned = 0;

for "_i" from 1 to _airPatrols do {
    private _pickIdx = [_airPct] call _fnc_weightedPick;
    if (_pickIdx < 0) then { _pickIdx = 0 };
    private _wantType = _airTypeOrder select _pickIdx;

    // Try the requested type; if it returns null (empty pool), fall
    // through to the other 3 in their natural order.
    private _ac      = objNull;
    private _crewGrp = grpNull;
    private _gotType = "";

    private _tryOrder = [_wantType] + (_airTypeOrder select { _x != _wantType });
    {
        private _fnStr = _airSpawnFns get _x;
        private _res = [_aoConfig] call (missionNamespace getVariable [_fnStr, {}]);
        _res params [["_acX", objNull], ["_crewX", grpNull]];
        if (!isNull _acX) exitWith {
            _ac      = _acX;
            _crewGrp = _crewX;
            _gotType = _x;
        };
    } forEach _tryOrder;

    if (!isNull _ac) then {
        _entities pushBack _ac;
        if (!isNull _crewGrp) then { _entities pushBack _crewGrp };
        _airSpawned = _airSpawned + 1;
        _airCounts set [_gotType, (_airCounts get _gotType) + 1];
    };
};
[format ["Air: %1/%2 spawned. mix: heli=%3 jet=%4 drone=%5 plane=%6",
    _airSpawned, _airPatrols,
    _airCounts get "heli", _airCounts get "jet",
    _airCounts get "drone", _airCounts get "plane"]] call _log;

// =====================================================================
//  Public AO markers (visible to all players) + AO anchor object.
//  The anchor is what makes the markers Zeus-deletable: deleting it
//  via right-click → its "Deleted" event handler wipes the markers.
// =====================================================================
private _markers     = _aoConfig getOrDefault ["markers", []];
private _anchorObj   = objNull;
private _factionDisplay = getText (configFile >> "CfgFactionClasses" >> _faction >> "displayName");
if (_factionDisplay isEqualTo "") then { _factionDisplay = _faction };

if (_showMarker) then {
    private _markerColor = switch (_side) do {
        case east:        { "ColorEAST" };
        case west:        { "ColorWEST" };
        case independent: { "ColorGUER" };
        case civilian:    { "ColorCIV" };
        default           { "ColorRed" };
    };

    private _areaName = format ["GEA_marker_area_%1", _aoId];
    if ((createMarker [_areaName, _center]) != "") then {
        _areaName setMarkerShape "ELLIPSE";
        _areaName setMarkerColor _markerColor;
        _areaName setMarkerBrush "Border";
        _areaName setMarkerSize [_radius, _radius];
        _markers pushBack _areaName;
    };

    private _iconName = format ["GEA_marker_icon_%1", _aoId];
    if ((createMarker [_iconName, _center]) != "") then {
        _iconName setMarkerType  "mil_objective";
        _iconName setMarkerColor _markerColor;
        _iconName setMarkerText  format ["AO of %1", _factionDisplay];
        _markers pushBack _iconName;
    };

    _aoConfig set ["markers", _markers];
    _aoConfig set ["factionDisplay", _factionDisplay];

    // --- AO anchor (Zeus-deletable handle for the markers) -----------
    // Sign_Sphere25cm_F is visible enough for the curator to spot on the
    // Zeus map yet small enough not to disrupt gameplay. Curator-deleting
    // it via right-click fires the "Deleted" EH and removes the markers.
    private _anchorClass = "Sign_Sphere25cm_F";
    _anchorObj = createVehicle [_anchorClass, _center, [], 0, "CAN_COLLIDE"];
    if (!isNull _anchorObj) then {
        _anchorObj setPosATL [_center select 0, _center select 1, (getPosATL _anchorObj select 2) max 0.1];
        _anchorObj setVariable ["GEA_aoId",     _aoId,    true];
        _anchorObj setVariable ["GEA_markers",  _markers, true];
        _anchorObj setVariable ["GEA_isAnchor", true,     true];
        _anchorObj allowDamage false;

        // When the anchor is deleted (via Zeus, /removeAllCurators, or
        // despawnAO), drop the markers. The EH fires on the host where
        // the object dies, which is the server for server-spawned objects.
        _anchorObj addEventHandler ["Deleted", {
            params ["_entity"];
            private _ms = _entity getVariable ["GEA_markers", []];
            { deleteMarker _x } forEach _ms;
            private _aid = _entity getVariable ["GEA_aoId", ""];
            diag_log text format ["[GEA] AO anchor deleted — %1 markers removed (aoId=%2)",
                count _ms, _aid];
        }];

        // Anchor counts as an entity so registerCleanup also Zeus-edits it.
        _entities pushBack _anchorObj;
    } else {
        diag_log text "[GEA] AO anchor createVehicle returned null — markers will NOT be Zeus-deletable.";
    };
};

// =====================================================================
//  Register everything (tag + Zeus-editable + global registry)
// =====================================================================
[_aoConfig, _entities] call GEA_fnc_registerCleanup;

// --- Final summary chat (single line, shown to curator) --------------
[format ["AO '%1' generated — %2 patrol, %3 garrison grp (%4 units), %5 static, %6 veh, %7 air.",
    _factionDisplay,
    _patrolsSpawned, _garrisonGroupsOk, _garrisonPlaced,
    _staticsSpawned, _vehiclesSpawned, _airSpawned]] call _saySummary;

_aoId
