// =====================================================================
// GEA_fnc_getGroupsForFaction
//   Returns spawnable group templates for a (side, faction) pair.
//
//   Two-tier strategy — many factions don't define their own CfgGroups
//   entries (e.g. CSAT Russian Spetsnaz, RHS sub-factions, ...), so we
//   need a fallback or the AO simply doesn't spawn.
//
//     TIER 1: CfgGroups walk — returns native, well-composed groups
//             ([Infantry], [Mechanized], [Weapons team], ...). Best
//             quality when available.
//
//     TIER 2: CfgVehicles fallback — scan for "Man" units belonging to
//             the faction and assemble a synthetic squad. Always works
//             as long as the faction has any infantry classnames.
//
//   Returns: array of mixed-form entries:
//     [<configPath or [<classnames>]>, displayName]
//
//   BIS_fnc_spawnGroup accepts either a CfgGroups config or an array
//   of unit classnames as its "type" argument, so callers can pass
//   either form straight through without branching.
// =====================================================================

#include "..\..\script_component.hpp"

params [
    ["_side",    east, [west]],
    ["_faction", "",   [""]]
];

if (_faction isEqualTo "") exitWith { [] };

// ---------------------------------------------------------------------
// TIER 1 — CfgGroups walk
// ---------------------------------------------------------------------
private _sideCfg = switch (_side) do {
    case east:        { configFile >> "CfgGroups" >> "East" };
    case west:        { configFile >> "CfgGroups" >> "West" };
    case independent: { configFile >> "CfgGroups" >> "Indep" };
    case civilian:    { configFile >> "CfgGroups" >> "Civilian" };
    default           { configNull };
};

private _results        = [];
private _skippedMotor   = 0;   // counted for logs — motorized/mech groups we excluded

// A CfgGroups "group" entry has child config entries — one per unit
// in the group — each with a "vehicle" property (the unit's class).
// If ANY child's vehicle is not isKindOf "Man", the group spawns a
// vehicle when called through BIS_fnc_spawnGroup. Patrol slot should
// only get pure-infantry templates so the vehicle-patrol slider is the
// only thing that can spawn cars.
private _fnc_isInfantryGroup = {
    params ["_groupCfg"];
    private _allInfantry = true;
    {
        private _veh = getText (_x >> "vehicle");
        if (_veh != "" && { !(_veh isKindOf "Man") }) exitWith {
            _allInfantry = false;
        };
    } forEach ("true" configClasses _groupCfg);
    _allInfantry
};

if (!isNull _sideCfg) then {
    {
        if ((configName _x) == _faction) then {
            {
                private _category = _x;
                {
                    if ([_x] call _fnc_isInfantryGroup) then {
                        _results pushBack [_x, getText (_x >> "name")];
                    } else {
                        _skippedMotor = _skippedMotor + 1;
                    };
                } forEach ("true" configClasses _category);
            } forEach ("true" configClasses _x);
        };
    } forEach ("true" configClasses _sideCfg);
};

if (!(_results isEqualTo [])) exitWith {
    diag_log text format ["[GEA] getGroupsForFaction: %1 infantry-only CfgGroups for %2 (skipped %3 motor/mech)",
        count _results, _faction, _skippedMotor];
    _results
};

// ---------------------------------------------------------------------
// TIER 2 — CfgVehicles fallback
// Build a few synthetic squad templates from any "Man" units assigned
// to this faction. We bucket by scope >= 2 (public) and skill, then
// produce three preset compositions: small fireteam, full squad,
// weapons squad. Quality varies wildly between mods but it ALWAYS
// produces something spawnable.
// ---------------------------------------------------------------------
private _menClasses = [];
{
    private _cfg = _x;
    private _cn  = configName _cfg;
    private _isVirtual = ((getText (_cfg >> "editorSubcategory")) == "EdSubcat_VirtualEntities")
        || { _cn isKindOf "VirtualMan_F" }
        || { toLower _cn find "_vr_" >= 0 };
    if (
        getNumber (_cfg >> "scope") >= 2 &&
        { !_isVirtual } &&
        { (getText (_cfg >> "faction")) == _faction } &&
        { getNumber (_cfg >> "isMan") == 1 || (configName (inheritsFrom _cfg)) in ["CAManBase", "Man"] }
    ) then {
        _menClasses pushBack _cn;
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));

if (_menClasses isEqualTo []) exitWith {
    diag_log text format ["[GEA] getGroupsForFaction: NO men found in CfgVehicles for %1 either.", _faction];
    []
};

// Pick reasonable role keywords so we get a mixed loadout, not 8 riflemen.
private _pick = {
    params ["_pool", "_keywords"];
    private _hit = _pool select { private _c = toLower _x; _keywords findIf { _c find _x >= 0 } >= 0 };
    if (_hit isEqualTo []) then { _pool } else { _hit }
};

private _rifle = [_menClasses, ["rifleman", "_r", "_g_f", "_soldier_f"]] call _pick;
private _at    = [_menClasses, ["_at", "_lat", "antitank"]]               call _pick;
private _mg    = [_menClasses, ["_ar", "mg", "_aar"]]                     call _pick;
private _med   = [_menClasses, ["medic", "corpsman"]]                     call _pick;
private _ldr   = [_menClasses, ["_tl", "_sl", "leader", "_o_f"]]          call _pick;

private _fireteam = [
    selectRandom _ldr, selectRandom _rifle, selectRandom _rifle, selectRandom _mg
];
private _squad = [
    selectRandom _ldr,
    selectRandom _rifle, selectRandom _rifle, selectRandom _rifle,
    selectRandom _mg,    selectRandom _at,    selectRandom _med
];
private _weaponsTeam = [
    selectRandom _ldr, selectRandom _mg, selectRandom _mg, selectRandom _at, selectRandom _at
];

[
    [_fireteam,    "Fireteam (synth)"],
    [_squad,       "Rifle Squad (synth)"],
    [_weaponsTeam, "Weapons Team (synth)"]
]
