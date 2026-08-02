// =====================================================================
// GEA_fnc_cbaSettings
//   Registers GEA's CBA settings at preInit. These define the DEFAULT
//   values for every numeric / toggle option in the AO generator, so a
//   server owner (or solo player) can set their preferred defaults once —
//   in-game under Options → Addon Options → "GEA - AO Generator", or by
//   `force`-ing them in the server's CBA settings file — and have them
//   pre-filled every time the Zeus dialog is opened. The curator can
//   still override any value per-AO in the dialog.
//
//   DELIBERATELY NOT settings: Side and Faction (enemy) and the Civilian
//   Faction. Those are discovered dynamically from the loaded mods and
//   are always chosen in the dialog — baking them into CBA settings would
//   break as soon as the modset changes, so they stay runtime-only.
//
//   Each setting creates a global variable of the same name, e.g.
//   GEA_def_radius, which fn_openConfigDialog reads as its default.
//
//   Server config example (in the CBA settings .txt):
//       force GEA_def_radius        = 750;
//       force GEA_def_patrolGroups  = 5;
//       force GEA_def_simplePathing = true;
// =====================================================================

#include "..\..\script_component.hpp"

if (isNil "CBA_Settings_fnc_init") exitWith {
    diag_log text "[GEA] CBA not available — skipping settings registration.";
};

private _cat = "GEA - AO Generator";

// SLIDER helper.  [id, name, tooltip, subcategory, min, max, default, decimals]
private _S = {
    params ["_id", "_name", "_tip", "_sub", "_min", "_max", "_def", "_dec"];
    [_id, "SLIDER", [_name, _tip], [_cat, _sub], [_min, _max, _def, _dec]] call CBA_Settings_fnc_init;
};
// CHECKBOX helper. [id, name, tooltip, subcategory, default]
private _C = {
    params ["_id", "_name", "_tip", "_sub", "_def"];
    [_id, "CHECKBOX", [_name, _tip], [_cat, _sub], _def] call CBA_Settings_fnc_init;
};

// --- General ---------------------------------------------------------
["GEA_def_radius", "AO Radius (m)", "Default AO radius pre-filled in the dialog.", "General", 100, 2000, 500, 0] call _S;
["GEA_def_skill",  "AI Skill",      "Default unit skill (0..1).",                  "General", 0,   1,    0.5, 2] call _S;

// --- Patrols & Garrison ---------------------------------------------
["GEA_def_patrolGroups",   "Patrol Groups",   "Default number of patrolling infantry groups.", "Patrols & Garrison", 0, 12, 3, 0] call _S;
["GEA_def_garrisonGroups", "Garrison Groups", "Default number of garrison fireteams.",         "Patrols & Garrison", 0, 30, 5, 0] call _S;

// --- Static Defences -------------------------------------------------
["GEA_def_staticTurrets", "Static Turrets", "Default number of manned static weapons.", "Static Defences", 0, 20, 0, 0] call _S;

// --- Vehicles --------------------------------------------------------
["GEA_def_vehiclePatrols", "Vehicle Patrols", "Default number of ground vehicles.", "Vehicles", 0, 10, 1, 0] call _S;
["GEA_def_vehPctCar",      "% Car",           "Default car share (auto-normalized).",  "Vehicles", 0, 100, 70, 0] call _S;
["GEA_def_vehPctApc",      "% APC",           "Default APC share (auto-normalized).",  "Vehicles", 0, 100, 20, 0] call _S;
["GEA_def_vehPctTank",     "% Tank",          "Default tank share (auto-normalized).", "Vehicles", 0, 100, 10, 0] call _S;

// --- Air -------------------------------------------------------------
["GEA_def_airPatrols",  "Air Patrols", "Default number of air assets.",          "Air", 0, 8,   0,  0] call _S;
["GEA_def_airPctHeli",  "% Heli",      "Default heli share (auto-normalized).",  "Air", 0, 100, 60, 0] call _S;
["GEA_def_airPctJet",   "% Jet",       "Default jet share (auto-normalized).",   "Air", 0, 100, 20, 0] call _S;
["GEA_def_airPctDrone", "% Drone",     "Default drone share (auto-normalized).", "Air", 0, 100, 10, 0] call _S;
["GEA_def_airPctPlane", "% Plane",     "Default plane share (auto-normalized).", "Air", 0, 100, 10, 0] call _S;

// --- Civilians -------------------------------------------------------
["GEA_def_civPatrol",   "Patrol Civilians",   "Default number of wandering civilians.",        "Civilians", 0, 50, 0, 0] call _S;
["GEA_def_civGarrison", "Garrison Civilians", "Default number of civilians placed in houses.", "Civilians", 0, 50, 0, 0] call _S;
["GEA_def_civCars",     "Civilian Cars",      "Default number of parked civilian cars.",       "Civilians", 0, 30, 0, 0] call _S;

// --- Minefields ------------------------------------------------------
["GEA_def_mineFields", "Minefields", "Default number of perimeter minefields.", "Minefields", 0, 15, 0, 0] call _S;
["GEA_def_showMineMarkers", "Show Minefield Markers", "Default for the minefield map-marker toggle.", "Minefields", false] call _C;

// --- Roadblocks ------------------------------------------------------
["GEA_def_roadblocks", "Roadblocks", "Default number of manned roadblocks.", "Roadblocks", 0, 12, 0, 0] call _S;

// --- Air Patrol Range ------------------------------------------------
["GEA_def_heliRange",  "Heli Patrol Range (m)",  "Default max distance beyond the AO radius for helicopters/rotary drones.", "Air Patrol Range", 200, 3000, 1000, 0] call _S;
["GEA_def_planeRange", "Plane Patrol Range (m)", "Default max distance beyond the AO radius for jets/planes/fixed-wing drones.", "Air Patrol Range", 200, 4000, 2000, 0] call _S;

// --- Pathing & Visibility -------------------------------------------
["GEA_def_simplePathing", "Simple Pathing", "Default for the simple-pathing performance toggle.", "Pathing & Performance", false] call _C;
["GEA_def_showMarker",     "Show AO Marker", "Default for the AO map-marker toggle.",              "Visibility", true] call _C;

diag_log text "[GEA] CBA settings registered (GEA_def_*).";
