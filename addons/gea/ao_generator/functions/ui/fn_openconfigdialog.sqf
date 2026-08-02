// =====================================================================
// GEA_fnc_openConfigDialog
//   Stage 2 of the AO setup - main configuration dialog.
//
//   The Faction dropdown is populated dynamically by
//   GEA_fnc_getFactionsForSide (scans CfgFactionClasses for the side
//   picked in Stage 1).
//
//   ZEN dynamic-dialog row format (per ZEN docs, verified):
//     [ TYPE, [displayName, tooltip(, section)], controlArgs, forceDefault ]
//       - controlArgs are TYPE-specific (see below).
//       - forceDefault (BOOL): true = ignore the curator's last-confirmed
//         value and always reset to the default; false = remember last input.
//         We use false so CBA GEA_def_* values pre-fill on first open and the
//         curator's tweaks stick afterwards.
//       - The 3rd config element ("section") is ignored by ZEN (the dynamic
//         dialog has no section grouping) but kept here for readability.
//   Control-specific args used here:
//     SLIDER   -> [min, max, default, decimals]
//     COMBO    -> [values, labels, defaultIndex]        (NO pictures slot)
//     CHECKBOX -> defaultCheckedBool                    (a bare BOOL, not [])
//
//   Inputs:
//     _center : PositionAGL
//     _side   : Side (west / east / independent / civilian)
//
//   On confirm: builds an AO config hashmap (fn_buildAOConfig) and
//   forwards it to the server-side orchestrator (fn_generateAO).
//   NOTE: _values comes back in row order; buildAOConfig owns the
//   index->key mapping, and row order is UNCHANGED by this fix.
// =====================================================================

#include "..\..\script_component.hpp"

if (isNil "zen_dialog_fnc_create") exitWith {
    diag_log text "[GEA] Zeus Enhanced not loaded - cannot open config dialog.";
};

params [
    ["_center", [0,0,0], [[]], [3]],
    ["_side",   east,    [west]]
];

// --- Dynamic faction list for the picked side ------------------------
private _factions      = [_side] call GEA_fnc_getFactionsForSide;
private _factionValues = _factions apply { _x select 0 };
private _factionLabels = _factions apply { _x select 1 };

if (_factionValues isEqualTo []) exitWith {
    [format ["No factions found for side %1.", _side], false, 5] call zen_common_fnc_showMessage;
};

// --- Civilian faction list (for the ambient-civilian options) --------
// Always civilian-side, regardless of the enemy side picked in Stage 1.
private _civFactions      = [civilian] call GEA_fnc_getFactionsForSide;
private _civFactionValues = _civFactions apply { _x select 0 };
private _civFactionLabels = _civFactions apply { _x select 1 };
if (_civFactionValues isEqualTo []) then {
    // No civilian factions loaded - keep the combo valid; the spawner
    // falls back to any civilian-side unit when the value is "".
    _civFactionValues = [""];
    _civFactionLabels = ["(any civilian)"];
};

// --- Defaults from CBA settings (GEA_def_*) --------------------------
// Server owners set these once; they pre-fill the dialog so curators
// don't re-enter common values every mission. Each falls back to the
// original hardcoded default if the setting isn't present.
private _dRadius      = round (missionNamespace getVariable ["GEA_def_radius",         500]);
private _dSkill       =        missionNamespace getVariable ["GEA_def_skill",          0.5];
private _dPatrol      = round (missionNamespace getVariable ["GEA_def_patrolGroups",   3]);
private _dGarr        = round (missionNamespace getVariable ["GEA_def_garrisonGroups", 5]);
private _dStatic      = round (missionNamespace getVariable ["GEA_def_staticTurrets",  0]);
private _dVeh         = round (missionNamespace getVariable ["GEA_def_vehiclePatrols", 1]);
private _dVehCar      = round (missionNamespace getVariable ["GEA_def_vehPctCar",      70]);
private _dVehApc      = round (missionNamespace getVariable ["GEA_def_vehPctApc",      20]);
private _dVehTank     = round (missionNamespace getVariable ["GEA_def_vehPctTank",     10]);
private _dAir         = round (missionNamespace getVariable ["GEA_def_airPatrols",     0]);
private _dAirHeli     = round (missionNamespace getVariable ["GEA_def_airPctHeli",     60]);
private _dAirJet      = round (missionNamespace getVariable ["GEA_def_airPctJet",      20]);
private _dAirDrone    = round (missionNamespace getVariable ["GEA_def_airPctDrone",    10]);
private _dAirPlane    = round (missionNamespace getVariable ["GEA_def_airPctPlane",    10]);
private _dShowMarker  =        missionNamespace getVariable ["GEA_def_showMarker",     true];
private _dSimple      =        missionNamespace getVariable ["GEA_def_simplePathing",  false];
private _dCivPatrol   = round (missionNamespace getVariable ["GEA_def_civPatrol",      0]);
private _dCivGarrison = round (missionNamespace getVariable ["GEA_def_civGarrison",    0]);
private _dCivCars     = round (missionNamespace getVariable ["GEA_def_civCars",        0]);
private _dMines       = round (missionNamespace getVariable ["GEA_def_mineFields",     0]);
private _dMineMarkers =        missionNamespace getVariable ["GEA_def_showMineMarkers", false];
private _dRoadblocks  = round (missionNamespace getVariable ["GEA_def_roadblocks",     0]);
private _dHeliRange   = round (missionNamespace getVariable ["GEA_def_heliRange",      1000]);
private _dPlaneRange  = round (missionNamespace getVariable ["GEA_def_planeRange",     2000]);

// Clamp combo defaults to their selectable index range.
_dVeh = (0 max _dVeh) min 10;
_dAir = (0 max _dAir) min 8;

// --- ZEN dialog rows -------------------------------------------------
//   [TYPE, [displayName, tooltip, section], controlArgs, forceDefault]
// Row index/order is significant - buildAOConfig reads by position.
private _content = [
    // -- General --
    ["SLIDER",
     ["Radius (m)", "AO radius", "General"],
     [100, 2000, _dRadius, 0], false],
    ["SLIDER",
     ["AI Skill", "Unit skill (0..1)", "General"],
     [0, 1, _dSkill, 2], false],

    // -- Enemy Composition --
    ["COMBO",
     ["Faction", "Faction for the selected side (dynamic scan of CfgFactionClasses).", "Enemy Composition"],
     [_factionValues, _factionLabels, 0], false],

    // -- Patrols & Garrison --
    // Patrol groups and garrison groups are independent counts now.
    // Garrison groups are kept SMALL (fireteam-sized) at spawn time so
    // we don't stuff 8 men into one room.
    ["SLIDER",
     ["Patrol Groups", "Number of patrolling infantry groups. Each group uses its faction template size (typically 6-10 men).", "Patrols & Garrison"],
     [0, 12, _dPatrol, 0], false],
    ["SLIDER",
     ["Garrison Groups", "Number of small garrison fireteams (2-4 units each) placed inside buildings. Caps at the number of usable buildings in the AO.", "Patrols & Garrison"],
     [0, 30, _dGarr, 0], false],

    // -- Static Defences ----------------------------------------------
    // Manned static weapons (HMG/GMG/AA/AT/mortar - whatever the faction
    // provides) placed around the AO, each facing outward from centre so
    // they form a rough defensive ring. Random class per turret.
    ["SLIDER",
     ["Static Turrets", "Number of manned static weapons to spawn. Each is a random static from the faction's pool (side fallback), placed on the AO perimeter facing outward.", "Static Defences"],
     [0, 20, _dStatic, 0], false],

    // -- Vehicles -----------------------------------------------------
    ["COMBO",
     ["Vehicle Patrols", "Number of ground vehicles to spawn (total). Use the % sliders below to control the mix.", "Vehicles"],
     [[0,1,2,3,4,5,6,7,8,9,10],
      ["None","1","2","3","4","5","6","7","8","9","10"],
      _dVeh], false],
    ["SLIDER",
     ["% Car",  "Share of vehicle patrols spawned as cars / MRAPs / technicals / trucks. Auto-normalized against the other vehicle %.", "Vehicles"],
     [0, 100, _dVehCar, 0], false],
    ["SLIDER",
     ["% APC",  "Share of vehicle patrols spawned as APCs / IFVs. Auto-normalized.", "Vehicles"],
     [0, 100, _dVehApc, 0], false],
    ["SLIDER",
     ["% Tank", "Share of vehicle patrols spawned as tanks (MBTs). Auto-normalized.", "Vehicles"],
     [0, 100, _dVehTank, 0], false],

    // -- Air ----------------------------------------------------------
    ["COMBO",
     ["Air Patrols", "Number of air assets to spawn (total). Use the % sliders below to control the mix.", "Air"],
     [[0,1,2,3,4,5,6,7,8],
      ["None","1","2","3","4","5","6","7","8"],
      _dAir], false],
    ["SLIDER",
     ["% Heli",  "Share of air patrols spawned as helicopters. Auto-normalized against the other air %.", "Air"],
     [0, 100, _dAirHeli, 0], false],
    ["SLIDER",
     ["% Jet",   "Share of air patrols spawned as fast jets (maxSpeed >= 600 km/h). Auto-normalized.", "Air"],
     [0, 100, _dAirJet, 0], false],
    ["SLIDER",
     ["% Drone", "Share of air patrols spawned as UAVs / drones (isUav = 1). Auto-normalized.", "Air"],
     [0, 100, _dAirDrone, 0], false],
    ["SLIDER",
     ["% Plane", "Share of air patrols spawned as slow / prop / CAS planes (maxSpeed < 600 km/h). Auto-normalized.", "Air"],
     [0, 100, _dAirPlane, 0], false],

    // -- Visibility --
    ["CHECKBOX",
     ["Show AO Marker", "Place a side-colored objective marker on the map for all players. A small AO anchor object is also placed at the center - delete it via Zeus to remove the markers.", "Visibility"],
     _dShowMarker, false],

    // -- Pathing & Performance ---------------------------------------- (idx 16)
    // Simple pathing trades patrol variety for AI performance: every
    // patrol (infantry, vehicle, air) gets just 2 waypoints + a cycle.
    ["CHECKBOX",
     ["Simple Pathing", "Performance option. ON = all patrols use only 2 waypoints + cycle (cheaper AI). OFF = rich dynamic patrols (default, recommended unless you have FPS issues).", "Pathing & Performance"],
     _dSimple, false],

    // -- Civilians ---------------------------------------------------- (idx 17-20)
    ["COMBO",
     ["Civilian Faction", "Which civilian faction to draw civs & cars from (dynamic scan). Adapts to loaded mods.", "Civilians"],
     [_civFactionValues, _civFactionLabels, 0], false],
    ["SLIDER",
     ["Patrol Civilians", "Number of wandering ambient civilians (walk around the AO). Neutral and relaxed.", "Civilians"],
     [0, 50, _dCivPatrol, 0], false],
    ["SLIDER",
     ["Garrison Civilians", "Number of civilians placed inside buildings (standing). Caps at the number of usable building positions.", "Civilians"],
     [0, 50, _dCivGarrison, 0], false],
    ["SLIDER",
     ["Civilian Cars", "Number of empty parked civilian cars on roads around the AO (no drivers - set dressing).", "Civilians"],
     [0, 30, _dCivCars, 0], false],

    // -- Minefields --------------------------------------------------- (idx 21-22)
    ["SLIDER",
     ["Minefields", "Number of minefields placed on the AO perimeter. Each is a cluster of random mines at a random (moderate) size.", "Minefields"],
     [0, 15, _dMines, 0], false],
    ["CHECKBOX",
     ["Show Minefield Markers", "Mark each minefield on the map with a red hazard ellipse + icon. Off = hidden hazards.", "Minefields"],
     _dMineMarkers, false],

    // -- Roadblocks --------------------------------------------------- (idx 23)
    ["SLIDER",
     ["Roadblocks", "Number of manned roadblocks (barbed wire + sandbag bunker + 2-3 guards) placed on roads near the AO edge. Needs roads in the area.", "Roadblocks"],
     [0, 12, _dRoadblocks, 0], false],

    // -- Air Patrol Range --------------------------------------------- (idx 24-25)
    // Max distance BEYOND the AO radius that aircraft roam. Lower these
    // to keep air patrols tight over the objective. Defaults match the
    // original hardcoded reach.
    ["SLIDER",
     ["Heli Patrol Range (m)", "Max distance beyond the AO radius for helicopter (and rotary drone) waypoints. Default 1000.", "Air Patrol Range"],
     [200, 3000, _dHeliRange, 0], false],
    ["SLIDER",
     ["Plane Patrol Range (m)", "Max distance beyond the AO radius for jet / plane (and fixed-wing drone) waypoints. Default 2000.", "Air Patrol Range"],
     [200, 4000, _dPlaneRange, 0], false]
];

[
    format ["Generate Enemy AO - %1", _side],
    _content,
    {
        params ["_values", "_args"];
        _args params ["_center", "_side"];

        // _values comes back in row order - buildAOConfig owns the
        // index->key mapping so dialog and config can evolve separately.
        private _aoCfg = [_center, _side, _values] call GEA_fnc_buildAOConfig;
        private _me    = clientOwner;

        // If we ARE the server (SP / hosted Zeus), call directly -
        // skips a remoteExec hop.
        if (isServer) then {
            [_aoCfg, _me] call GEA_fnc_generateAO;
        } else {
            [_aoCfg, _me] remoteExec ["GEA_fnc_generateAO", 2];
        };
    },
    {},
    [_center, _side]
] call zen_dialog_fnc_create;