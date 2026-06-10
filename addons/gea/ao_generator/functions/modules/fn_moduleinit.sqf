// =====================================================================
// GEA_fnc_moduleInit
//   Eden (3DEN) editor module entry point — the no-Zeus path.
//
//   Placed via the editor's Systems (F5) > Modules menu under the "GEA"
//   category, this runs the EXACT same pipeline as the Zeus module:
//   it reads its attributes, assembles the shared positional _values
//   array, and hands off to GEA_fnc_buildAOConfig + GEA_fnc_generateAO.
//   No ZEN dialog, no curator — just place the module where you want the
//   AO centre, set the attributes, and hit Play.
//
//   Engine calls module functions as:
//       [_logic, _units, _activated] call GEA_fnc_moduleInit;
//
//   The module is declared `isGlobal = 2` (server-only execution), so
//   this runs on the server exactly once — matching generateAO's
//   server-authoritative contract. Attribute `expression`s still run on
//   every machine at mission init, so the variables we read below exist
//   on the server.
//
//   Attribute → variable mapping (see config.cpp class Attributes):
//     GEA_side            string  "west"|"east"|"independent"|"civilian"
//     GEA_faction         string  CfgFactionClasses className ("" = auto)
//     GEA_radius          number
//     GEA_skill           number  0..1
//     GEA_patrolGroups    number
//     GEA_garrisonGroups  number
//     GEA_staticTurrets   number
//     GEA_vehiclePatrols  number
//     GEA_vehPctCar/Apc/Tank          number 0..100
//     GEA_airPatrols      number
//     GEA_airPctHeli/Jet/Drone/Plane  number 0..100
//     GEA_showMarker      bool
// =====================================================================

#include "..\..\script_component.hpp"

// NOTE: do NOT strict-type the params. In 3DEN the engine invokes a
// module's `function` with a different argument shape (the first element
// is NOT the logic object — it can be a String), so a strict [objNull]
// filter throws a hard error. Read loosely.
params [["_logic", objNull], ["_units", []], ["_activated", true]];

// ---------------------------------------------------------------------
// EDITOR (3DEN) branch — MUST come before any _logic validity guards,
// because in 3DEN _logic is not a usable object here.
//
//   With is3DEN = 1 this function runs in the editor (e.g. on placement).
//   We don't trust _logic; instead we scan every editor entity for GEA
//   modules and attach a one-time attributesChanged3DEN hook to each.
//   When the user confirms a module's attributes with "Generate in editor
//   now" ticked, the hook bakes it into real editable entities and removes
//   the module. Leaving the box unticked keeps it a runtime generator that
//   spawns on Play, so both workflows are available.
// ---------------------------------------------------------------------
if (is3DEN) exitWith {
    // Scan every editor entity bucket for un-hooked GEA modules and attach
    // the bake-on-confirm event. Returns how many were newly hooked.
    private _scanAndHook = {
        private _hook = {
            params ["_entity"];
            private _go = _entity get3DENAttribute "GEA_generate";
            if (_go isEqualType []) then { _go = _go param [0, false] };
            if (_go isEqualTo true && { !(_entity getVariable ["GEA_baking", false]) }) then {
                _entity setVariable ["GEA_baking", true];
                [_entity] call GEA_fnc_bake3DEN;
            };
        };
        private _n = 0;
        {
            {
                if (_x isEqualType objNull && { !isNull _x }
                    && { (typeOf _x) == "GEA_Module_GenerateAO" }
                    && { !(_x getVariable ["GEA_edenHooked", false]) }
                ) then {
                    _x setVariable ["GEA_edenHooked", true];
                    _x addEventHandler ["AttributesChanged3DEN", _hook];
                    _n = _n + 1;
                };
            } forEach _x;
        } forEach all3DENEntities;
        _n
    };

    private _hooked = call _scanAndHook;
    // Safety net: the just-placed module may not be in all3DENEntities yet
    // at the instant its own init fires — re-scan a moment later.
    [_scanAndHook] spawn {
        params ["_f"];
        sleep 0.3;
        private _n = call _f;
        if (_n > 0) then { diag_log text format ["[GEA] editor hook (deferred) — %1 module(s) armed.", _n]; };
    };

    diag_log text format ["[GEA] editor hook pass — %1 new GEA module(s) armed.", _hooked];
};

// --- Runtime path ----------------------------------------------------
if (isNil "_logic") exitWith {};
if !(_logic isEqualType objNull) exitWith {};
if (isNull _logic) exitWith {};
if (!_activated) exitWith {};

// Server-authoritative. isGlobal=2 should already guarantee this, but
// guard anyway so a misconfigured module can't double-spawn.
if (!isServer) exitWith {};

// --- Resolve side from the string attribute --------------------------
private _sideStr = _logic getVariable ["GEA_side", "east"];
private _side = switch (toLower _sideStr) do {
    case "west":        { west };
    case "east":        { east };
    case "independent": { independent };
    case "guer":        { independent };   // tolerate either spelling
    case "civilian":    { civilian };
    case "civ":         { civilian };
    default             { east };
};

// --- Faction: empty attribute → auto-pick the first faction for side -
private _faction = _logic getVariable ["GEA_faction", ""];
if (_faction isEqualTo "") then {
    private _facs = [_side] call GEA_fnc_getFactionsForSide;
    if (count _facs > 0) then {
        _faction = (_facs select 0) select 0;
        diag_log text format ["[GEA] module: no faction set, auto-picked '%1' for side %2.", _faction, _side];
    } else {
        diag_log text format ["[GEA] module: no faction set and none found for side %1 — aborting.", _side];
    };
};

// --- AO centre is the module's own position --------------------------
private _center = getPosATL _logic;

// --- Read the rest, with the same defaults as the dialog -------------
private _radius         = _logic getVariable ["GEA_radius",         500];
private _skill          = _logic getVariable ["GEA_skill",          0.5];
private _patrolGroups   = _logic getVariable ["GEA_patrolGroups",   3];
private _garrisonGroups = _logic getVariable ["GEA_garrisonGroups", 5];
private _staticTurrets  = _logic getVariable ["GEA_staticTurrets",  0];
private _vehiclePatrols = _logic getVariable ["GEA_vehiclePatrols", 1];
private _vehPctCar      = _logic getVariable ["GEA_vehPctCar",      70];
private _vehPctApc      = _logic getVariable ["GEA_vehPctApc",      20];
private _vehPctTank     = _logic getVariable ["GEA_vehPctTank",     10];
private _airPatrols     = _logic getVariable ["GEA_airPatrols",     0];
private _airPctHeli     = _logic getVariable ["GEA_airPctHeli",     60];
private _airPctJet      = _logic getVariable ["GEA_airPctJet",      20];
private _airPctDrone    = _logic getVariable ["GEA_airPctDrone",    10];
private _airPctPlane    = _logic getVariable ["GEA_airPctPlane",    10];
private _showMarker     = _logic getVariable ["GEA_showMarker",     true];

// --- Assemble the SHARED positional _values array -------------------
// Order MUST match fn_buildAOConfig (and the ZEN dialog rows).
private _values = [
    _radius,            // 0
    _skill,             // 1
    _faction,           // 2
    _patrolGroups,      // 3
    _garrisonGroups,    // 4
    _staticTurrets,     // 5
    _vehiclePatrols,    // 6
    _vehPctCar,         // 7
    _vehPctApc,         // 8
    _vehPctTank,        // 9
    _airPatrols,        // 10
    _airPctHeli,        // 11
    _airPctJet,         // 12
    _airPctDrone,       // 13
    _airPctPlane,       // 14
    _showMarker         // 15
];

private _aoCfg = [_center, _side, _values] call GEA_fnc_buildAOConfig;

diag_log text format ["[GEA] editor module firing AO at %1 (side=%2 faction=%3 r=%4).",
    _center, _side, _faction, _radius];

[_aoCfg, 0] call GEA_fnc_generateAO;
