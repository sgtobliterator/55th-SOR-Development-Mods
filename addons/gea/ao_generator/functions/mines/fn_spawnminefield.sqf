// =====================================================================
// GEA_fnc_spawnMinefield
//   Lays ONE minefield near the AO perimeter. Mirrors the static-turret
//   placement philosophy: the field centre is biased to the OUTER ring
//   (50–95% of radius) so minefields sit on the approaches to the
//   objective rather than in the middle of it.
//
//   Each field:
//     - random field radius clamped to a sensible band (not a single
//       mine, not a whole sector) — see MIN/MAX below.
//     - a moderate scatter of random mine types from the world's
//       MineBase pool (APERS, AT, bounding, tripwire, ... whatever is
//       loaded), placed with createMine.
//     - optional map marker (config key showMineMarkers): a red ellipse
//       sized to the field + a warning icon. Marker names are appended to
//       the AO's marker list so they clean up with the AO.
//
//   Inputs:
//     _aoConfig : HashMap — reads center, radius, id, showMineMarkers.
//
//   Returns: array of created mine objects (for cleanup).
// =====================================================================

#include "..\..\script_component.hpp"

if (!isServer) exitWith { [] };

params [["_aoConfig", createHashMap, [createHashMap]]];

private _center      = _aoConfig get "center";
private _radius      = _aoConfig get "radius";
private _aoId        = _aoConfig get "id";
private _showMarkers = _aoConfig getOrDefault ["showMineMarkers", false];

private _say = {
    params ["_msg"];
    diag_log text format ["[GEA] mine: %1", _msg];
};

// --- Mine pool — REAL buried/laid mines only -------------------------
// isKindOf "MineBase" is broad: it also catches demolition charges
// (C4 / satchel), command-detonated IEDs, sensor "targeting" munitions
// (SLAM), training/practice mines and any naval mines a mod adds. We
// want ordinary AP / AT land mines, so we reject anything whose class
// OR display name hits an exclusion keyword.
private _mineExclude = [
    "train","practice","dummy","decoy",   // training / non-live
    "naval","water","sea",                 // naval mines (not for land AOs)
    "ied","satchel","demo","charge","c4",  // command-detonated charges
    "slam","designator","target"           // sensor / targeting munitions
];
private _fnc_isRealMine = {
    params ["_cn"];
    private _c  = toLower _cn;
    private _dn = toLower getText (configFile >> "CfgVehicles" >> _cn >> "displayName");
    (_mineExclude findIf { (_c find _x >= 0) || (_dn find _x >= 0) }) < 0
};

private _minePool = _aoConfig getOrDefault ["minePool", []];
if (_minePool isEqualTo []) then {
    {
        private _cfg   = _x;
        private _class = configName _cfg;
        if (getNumber (_cfg >> "scope") >= 2
            && { _class isKindOf "MineBase" }
            && { [_class] call _fnc_isRealMine }
        ) then {
            _minePool pushBack _class;
        };
    } forEach ("true" configClasses (configFile >> "CfgVehicles"));
    _aoConfig set ["minePool", _minePool];   // cache for subsequent fields
};

[format ["mine pool size = %1", count _minePool]] call _say;

if (_minePool isEqualTo []) exitWith {
    ["NO MineBase classes found — skipping minefield."] call _say;
    []
};

// --- Field centre on the outer ring, on land ------------------------
private _fieldPos = [];
for "_t" from 1 to 32 do {
    private _dist = (0.5 + random 0.45) * _radius;
    private _cand = _center getPos [_dist, random 360];
    if (!surfaceIsWater _cand) exitWith { _fieldPos = _cand };
};
if (_fieldPos isEqualTo []) exitWith {
    ["no land found on the outer ring for a minefield."] call _say;
    []
};

// --- Field size + mine count ----------------------------------------
#define MINE_FIELD_MIN 12
#define MINE_FIELD_MAX 32
private _fieldR    = MINE_FIELD_MIN + random (MINE_FIELD_MAX - MINE_FIELD_MIN);
// Density: ~scale with field radius, clamped so a field is a threat but
// not a solid carpet.
private _mineCount = ((round (_fieldR * 0.7)) max 6) min 25;

private _created = [];
for "_i" from 1 to _mineCount do {
    private _mPos = _fieldPos getPos [random _fieldR, random 360];
    if (surfaceIsWater _mPos) then { continue };
    private _type = selectRandom _minePool;
    private _mine = createMine [_type, _mPos, [], 0];
    if (!isNull _mine) then {
        _mine setVariable ["GEA_aoId", _aoId, true];
        _created pushBack _mine;
    };
};

// Make the mines Zeus-editable immediately. registerCleanup also does
// this at the end of the run, but script-created mines sometimes don't
// surface in the curator interface unless added explicitly here, so we
// register them with every active curator up front.
if (!(_created isEqualTo [])) then {
    {
        _x addCuratorEditableObjects [_created, true];
    } forEach allCurators;
};

// --- Optional map marker (tracked per-field for the anchor) ---------
private _fieldMarkers = [];
if (_showMarkers) then {
    private _areaName = format ["GEA_mine_area_%1_%2", _aoId, floor random 1e6];
    if ((createMarker [_areaName, _fieldPos]) != "") then {
        _areaName setMarkerShape "ELLIPSE";
        _areaName setMarkerColor "ColorRed";
        _areaName setMarkerBrush "DiagGrid";
        _areaName setMarkerSize [_fieldR, _fieldR];
        _fieldMarkers pushBack _areaName;
    };

    private _iconName = format ["GEA_mine_icon_%1_%2", _aoId, floor random 1e6];
    if ((createMarker [_iconName, _fieldPos]) != "") then {
        _iconName setMarkerType  "mil_warning";
        _iconName setMarkerColor "ColorRed";
        _iconName setMarkerText  "Mines";
        _fieldMarkers pushBack _iconName;
    };

    // Also track in the AO-wide marker list so a full AO despawn clears them.
    private _allMarkers = _aoConfig getOrDefault ["markers", []];
    _allMarkers append _fieldMarkers;
    _aoConfig set ["markers", _allMarkers];
};

// --- Per-field Zeus anchor ------------------------------------------
// Script-created mines don't reliably surface in the curator list on
// their own, so — exactly like the AO marker anchor — we spawn a small
// deletable handle at the field centre that OWNS this field's mines and
// markers. The curator can right-click → Delete the anchor to clear the
// whole field; its "Deleted" event handler removes the mines and markers
// together. The anchor is returned with the mines so it also flows
// through registerCleanup / despawnAO.
private _entitiesOut = +_created;
if (!(_created isEqualTo [])) then {
    private _anchor = createVehicle ["Sign_Sphere25cm_F", _fieldPos, [], 0, "CAN_COLLIDE"];
    if (!isNull _anchor) then {
        _anchor setPosATL [_fieldPos select 0, _fieldPos select 1, (getPosATL _anchor select 2) max 0.1];
        _anchor setVariable ["GEA_aoId",        _aoId,         true];
        _anchor setVariable ["GEA_isMineAnchor", true,         true];
        _anchor setVariable ["GEA_mines",       _created,      true];
        _anchor setVariable ["GEA_markers",     _fieldMarkers, true];
        _anchor allowDamage false;
        // Hide the 3D sphere from regular players (immersion). The object
        // still exists and still shows as a selectable icon in the Zeus /
        // curator interface, so the curator can right-click → Delete it.
        _anchor hideObjectGlobal true;

        _anchor addEventHandler ["Deleted", {
            params ["_e"];
            { if (!isNull _x) then { deleteVehicle _x }; } forEach (_e getVariable ["GEA_mines", []]);
            { deleteMarker _x } forEach (_e getVariable ["GEA_markers", []]);
            diag_log text format ["[GEA] mine anchor deleted — field cleared (aoId=%1)",
                _e getVariable ["GEA_aoId", ""]];
        }];

        _entitiesOut pushBack _anchor;

        // Make the anchor controllable for every active curator.
        { _x addCuratorEditableObjects [[_anchor], true]; } forEach allCurators;
    };
};

[format ["minefield: %1 mines over %2m at %3m from centre%4.",
    count _created, round _fieldR, round (_center distance2D _fieldPos),
    (if (_showMarkers) then {" (marked)"} else {""})]] call _say;

_entitiesOut
