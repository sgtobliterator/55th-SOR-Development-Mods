// =====================================================================
// GEA_fnc_pickTurretCrew
//   Pick a sensible classname to man a static weapon from a pool of
//   infantry classnames.
//
//   Rationale: a turret should be gunned by a regular soldier, not a
//   pilot, diver, or vehicle crewman (which looked wrong when they got
//   randomly picked). Selection order:
//     1. Riflemen (by classname or displayName containing "rifleman").
//     2. Any non-specialist ground infantry (pilots/divers/crew excluded).
//     3. Anything in the pool (last-resort fallback).
//
//   Returns: a classname string ("" if the pool is empty).
// =====================================================================

#include "..\..\script_component.hpp"

params [["_pool", [], [[]]]];

if (_pool isEqualTo []) exitWith { "" };

// Roles that should never crew a static turret.
private _bad = ["pilot", "heli", "diver", "_sdv", "crew", "crewman", "tank", "_para"];

private _ground = _pool select {
    private _c = toLower _x;
    (_bad findIf { _c find _x >= 0 }) < 0
};
if (_ground isEqualTo []) then { _ground = _pool };

// Prefer actual riflemen.
private _rifle = _ground select {
    private _c  = toLower _x;
    private _dn = toLower getText (configFile >> "CfgVehicles" >> _x >> "displayName");
    (_c find "rifleman" >= 0) || { _dn find "rifleman" >= 0 }
};

if !(_rifle isEqualTo []) exitWith { selectRandom _rifle };

selectRandom _ground
