// =====================================================================
// GEA_fnc_getFactionsForSide
//   Dynamically scans CfgFactionClasses for factions belonging to the
//   given side. Replaces the old hardcoded faction list.
//
//   How it works:
//     1. Walk CfgFactionClasses (every loaded mod registers its
//        factions here — vanilla, RHS, CUP, GM, SOG, etc.).
//     2. For each entry, look at its `side` attribute (0=opfor,
//        1=blufor, 2=independent, 3=civilian — Arma's convention).
//     3. Return [[className, displayName], ...] sorted by displayName.
//
//   Usage:
//       _factions = [east] call GEA_fnc_getFactionsForSide;
//       // e.g. [["OPF_F","CSAT"], ["OPF_T_F","CSAT Pacific"], ["rhs_faction_msv","Russia (MSV)"], ...]
//
//   Notes:
//     * Some mods register factions with `side = -1` (logic/empty);
//       we skip those.
//     * Results are cached per-side in a missionNamespace hashmap so
//       repeated dialog opens stay snappy.
// =====================================================================

#include "..\..\script_component.hpp"

params [["_side", sideUnknown, [west]]];

// --- side -> Arma's CfgFactionClasses numeric id ---
private _sideId = switch (_side) do {
    case east:        { 0 };
    case west:        { 1 };
    case independent: { 2 };
    case civilian:    { 3 };
    default           { -1 };
};

if (_sideId < 0) exitWith { [] };

// --- cache ---
private _cache = missionNamespace getVariable ["GEA_factionCache", createHashMap];
if (_sideId in _cache) exitWith { _cache get _sideId };

// --- scan CfgFactionClasses ---
private _results = [];
{
    private _cfg = _x;
    private _className = configName _cfg;

    // Some mods omit `side` — default to -1 so we skip them.
    private _factionSide = getNumber (_cfg >> "side");
    if (isNumber (_cfg >> "side") && { _factionSide == _sideId }) then {
        private _displayName = getText (_cfg >> "displayName");
        if (_displayName isEqualTo "") then { _displayName = _className };
        _results pushBack [_className, _displayName];
    };
} forEach ("true" configClasses (configFile >> "CfgFactionClasses"));

// Sort by displayName (case-insensitive). `sort` on array-of-arrays
// would sort by className (element 0), so use BIS_fnc_sortBy to key
// on the display name instead.
_results = [_results, [], { toLower (_x select 1) }, "ASCEND"] call BIS_fnc_sortBy;

// --- store in cache ---
_cache set [_sideId, _results];
missionNamespace setVariable ["GEA_factionCache", _cache];

_results
