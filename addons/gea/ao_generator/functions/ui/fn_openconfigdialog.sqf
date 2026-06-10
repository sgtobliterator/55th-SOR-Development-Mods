// =====================================================================
// GEA_fnc_openConfigDialog
//   Stage 2 of the AO setup — main configuration dialog.
//
//   The Faction dropdown is populated dynamically by
//   GEA_fnc_getFactionsForSide (scans CfgFactionClasses for the side
//   picked in Stage 1).
//
//   v0.7.0 changes:
//     - Patrol and Garrison are now independent counts.
//       * "Patrol Groups"   = number of patrolling infantry groups.
//       * "Garrison Groups" = number of garrison groups (one per building).
//       The old "Infantry Count" + "Garrison %" sliders are gone — they
//       coupled the two systems and made fine-tuning awkward.
//     - Vehicle type mix is exposed as 3 sliders (% Car / APC / Tank).
//     - Air type mix is exposed as 4 sliders (% Heli / Jet / Drone / Plane).
//       The values are auto-normalized at spawn time, so the user does
//       NOT need to make them sum to 100 — only the ratios matter.
//
//   Inputs:
//     _center : PositionAGL
//     _side   : Side (west / east / independent / civilian)
//
//   On confirm: builds an AO config hashmap (fn_buildAOConfig) and
//   forwards it to the server-side orchestrator (fn_generateAO).
// =====================================================================

#include "..\..\script_component.hpp"

if (isNil "zen_dialog_fnc_create") exitWith {
    diag_log text "[GEA] Zeus Enhanced not loaded — cannot open config dialog.";
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

// --- ZEN dialog rows -------------------------------------------------
//   [TYPE, [displayName, tooltip, section], data, default, isRequired]
// Row index is significant — buildAOConfig reads by position.
private _content = [
    // -- General --
    ["SLIDER",
     ["Radius (m)", "AO radius", "General"],
     [100, 2000, 500, 0], 500, true],
    ["SLIDER",
     ["AI Skill", "Unit skill (0..1)", "General"],
     [0, 1, 0.5, 2], 0.5, true],

    // -- Enemy Composition --
    ["COMBO",
     ["Faction", "Faction for the selected side (dynamic scan of CfgFactionClasses).", "Enemy Composition"],
     [_factionValues, _factionLabels, [], 0],
     _factionValues select 0, true],

    // -- Patrols & Garrison --
    // Patrol groups and garrison groups are independent counts now.
    // Garrison groups are kept SMALL (fireteam-sized) at spawn time so
    // we don't stuff 8 men into one room.
    ["SLIDER",
     ["Patrol Groups", "Number of patrolling infantry groups. Each group uses its faction template size (typically 6-10 men).", "Patrols & Garrison"],
     [0, 12, 3, 0], 3, true],
    ["SLIDER",
     ["Garrison Groups", "Number of small garrison fireteams (2-4 units each) placed inside buildings. Caps at the number of usable buildings in the AO.", "Patrols & Garrison"],
     [0, 30, 5, 0], 5, true],

    // -- Static Defences ----------------------------------------------
    // Manned static weapons (HMG/GMG/AA/AT/mortar — whatever the faction
    // provides) placed around the AO, each facing outward from centre so
    // they form a rough defensive ring. Random class per turret.
    ["SLIDER",
     ["Static Turrets", "Number of manned static weapons to spawn. Each is a random static from the faction's pool (side fallback), placed on the AO perimeter facing outward.", "Static Defences"],
     [0, 20, 0, 0], 0, false],

    // -- Vehicles -----------------------------------------------------
    ["COMBO",
     ["Vehicle Patrols", "Number of ground vehicles to spawn (total). Use the % sliders below to control the mix.", "Vehicles"],
     [[0,1,2,3,4,5,6,7,8,9,10],
      ["None","1","2","3","4","5","6","7","8","9","10"],
      [], 1],
     1, false],
    ["SLIDER",
     ["% Car",  "Share of vehicle patrols spawned as cars / MRAPs / technicals / trucks. Auto-normalized against the other vehicle %.", "Vehicles"],
     [0, 100, 70, 0], 70, false],
    ["SLIDER",
     ["% APC",  "Share of vehicle patrols spawned as APCs / IFVs. Auto-normalized.", "Vehicles"],
     [0, 100, 20, 0], 20, false],
    ["SLIDER",
     ["% Tank", "Share of vehicle patrols spawned as tanks (MBTs). Auto-normalized.", "Vehicles"],
     [0, 100, 10, 0], 10, false],

    // -- Air ----------------------------------------------------------
    ["COMBO",
     ["Air Patrols", "Number of air assets to spawn (total). Use the % sliders below to control the mix.", "Air"],
     [[0,1,2,3,4,5,6,7,8],
      ["None","1","2","3","4","5","6","7","8"],
      [], 0],
     0, false],
    ["SLIDER",
     ["% Heli",  "Share of air patrols spawned as helicopters. Auto-normalized against the other air %.", "Air"],
     [0, 100, 60, 0], 60, false],
    ["SLIDER",
     ["% Jet",   "Share of air patrols spawned as fast jets (maxSpeed >= 600 km/h). Auto-normalized.", "Air"],
     [0, 100, 20, 0], 20, false],
    ["SLIDER",
     ["% Drone", "Share of air patrols spawned as UAVs / drones (isUav = 1). Auto-normalized.", "Air"],
     [0, 100, 10, 0], 10, false],
    ["SLIDER",
     ["% Plane", "Share of air patrols spawned as slow / prop / CAS planes (maxSpeed < 600 km/h). Auto-normalized.", "Air"],
     [0, 100, 10, 0], 10, false],

    // -- Visibility --
    ["CHECKBOX",
     ["Show AO Marker", "Place a side-colored objective marker on the map for all players. A small AO anchor object is also placed at the center — delete it via Zeus to remove the markers.", "Visibility"],
     [], true, false]
];

[
    format ["Generate Enemy AO — %1", _side],
    _content,
    {
        params ["_values", "_args"];
        _args params ["_center", "_side"];

        // _values comes back in row order — buildAOConfig owns the
        // index→key mapping so dialog and config can evolve separately.
        private _aoCfg = [_center, _side, _values] call GEA_fnc_buildAOConfig;
        private _me    = clientOwner;

        // If we ARE the server (SP / hosted Zeus), call directly —
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
