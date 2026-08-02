# GEA - AO Generator

An Arma 3 CBA/ZEN addon that dynamically generates enemy Area of Operations (AOs) at a position dropped by a Zeus curator or placed as an Eden Editor module. One module per AO - no scripting required.

**Version:** 0.9.8  
**Author:** Online90  
**Required:** Arma 3 (≥ 2.10), [CBA_A3](https://github.com/CBATeam/CBA_A3), [Zeus Enhanced (ZEN)](https://github.com/zen-mod/ZEN)

---

## Features

- **Infantry** - configurable patrol groups and garrison fireteams (units placed inside buildings)
- **Vehicles** - ground vehicle patrols with a weighted split across cars/MRAPs, APCs/IFVs, and tanks
- **Air** - helicopter, jet, drone, and plane patrols with configurable mix ratios and patrol range
- **Static defenses** - manned turrets placed on the AO perimeter, facing outward
- **Civilians** - ambient wandering civs, garrisoned civs inside buildings, and parked empty cars
- **Minefields** - perimeter mine clusters with optional map markers
- **Roadblocks** - manned wire-and-sandbag roadblocks on roads near the AO edge
- **AO marker** - side-colored objective marker + area ellipse visible to all players
- **Simple pathing** option for performance-sensitive missions (2-waypoint cycle instead of BIS dynamic patrol)
- **Dynamic faction support** - pick any `CfgFactionClasses` entry, or leave blank to auto-select the first faction for the chosen side
- **Cleanup system** - all spawned entities are tagged, tracked, and registered with Zeus for easy removal
- **Eden Editor bake** - tick "Generate in editor now" to immediately spawn editable entities and remove the module

---

## Installation

1. Download or clone this repository into your Arma 3 mods folder as `@GEA`.
2. Pack it as a PBO (e.g. using Mikero's tools or BI Tools) under the prefix `gea\ao_generator`.
3. Load with `-mod=@GEA` alongside CBA_A3 and ZEN.

The `$PBOPREFIX$` file contains the PBO prefix (`gea\ao_generator`).

---

## Usage

### Zeus / ZEN

1. Open Zeus and look for the **Generate Enemy AO** module in the ZEN custom modules list (attack icon).
2. Drop it on the map at the desired AO center.
3. A two-stage dialog opens: first pick the enemy side, then configure all AO parameters.
4. Click OK - the AO spawns on the server. A summary message is sent back to your curator.

To remove an AO, delete the anchor object that appears at the center via Zeus right-click. This also removes the AO markers.

### Eden Editor

1. Open the **Modules** panel (F5) and navigate to **Systems > Modules > GEA**.
2. Place the **Generate Enemy AO** module at the desired AO center.
3. Configure all parameters directly in the module's attribute panel.
4. Leave "Generate in editor now" unticked to have the AO spawn at mission start, or tick it to immediately bake entities into the editor as editable objects.

---

## Configuration Parameters

| Parameter | Default | Description |
|---|---|---|
| Side | `east` | BLUFOR / OPFOR / Independent / Civilian |
| Faction | *(auto)* | `CfgFactionClasses` classname - blank = first faction for the side |
| Radius (m) | `500` | AO radius in metres |
| AI Skill | `0.5` | Unit skill, 0.0 to 1.0 |
| Patrol Groups | `3` | Patrolling infantry groups |
| Garrison Groups | `5` | Small fireteams placed inside buildings (capped by available slots) |
| Static Turrets | `0` | Manned static weapons on the perimeter |
| Vehicle Patrols | `1` | Total ground vehicles |
| % Car / % APC / % Tank | `70/20/10` | Weighted mix for vehicle type (auto-normalized, ratios only matter) |
| Air Patrols | `0` | Total air assets |
| % Heli / % Jet / % Drone / % Plane | `60/20/10/10` | Weighted mix for air type |
| Heli Patrol Range (m) | `1000` | Max heli waypoint distance beyond AO radius |
| Plane Patrol Range (m) | `2000` | Max jet/plane waypoint distance beyond AO radius |
| Show AO Marker | `true` | Place a side-colored objective marker for all players |
| Simple Pathing | `false` | 2-waypoint cycle (performance) vs. BIS dynamic patrol (default) |
| Civilian Faction | *(auto)* | `CfgFactionClasses` classname for civilian units/cars |
| Patrol Civilians | `0` | Wandering ambient civilians |
| Garrison Civilians | `0` | Civilians inside buildings |
| Civilian Cars | `0` | Empty parked civilian cars scattered around the AO |
| Minefields | `0` | Perimeter mine clusters |
| Show Minefield Markers | `false` | Red hazard markers for each minefield |
| Roadblocks | `0` | Manned roadblocks on roads near the AO edge |
| Generate in editor now | `false` | Bake into editor entities immediately and remove module |

---

## Architecture

```
gea/ao_generator/
├── config.cpp               - CfgPatches, CfgFunctions, Eden module, CfgRemoteExec
├── script_component.hpp     - Shared macros (PREFIX, COMPONENT, DFUNC)
├── dialogs/
│   └── ao_generator_dialog.hpp
└── functions/
    ├── ao/                  - Core orchestration (generateAO, buildAOConfig, validateAOPosition, registerZenModule)
    ├── infantry/            - Patrol + garrison groups, patrol assignment
    ├── civilians/           - Ambient civs, garrisoned civs, parked cars
    ├── vehicles/            - Ground vehicle patrols
    ├── air/                 - Heli, jet, drone, plane patrols
    ├── statics/             - Static turret placement + crew selection
    ├── garrison/            - Building discovery + filling
    ├── mines/               - Minefield placement
    ├── roadblocks/          - Roadblock placement
    ├── factions/            - Dynamic faction/group pool discovery
    ├── cleanup/             - Entity tagging, tracking, despawn
    ├── debug/               - AO marker drawing
    ├── modules/             - Eden moduleInit + bake3DEN
    ├── settings/            - CBA settings registration
    └── ui/                  - Dialog open helpers (Stage 1 + Stage 2)
```

All spawning is server-authoritative. `CfgRemoteExec` whitelists only `GEA_fnc_generateAO` (server-only) and `GEA_fnc_drawAO` (curator client) for MP compatibility.

---

## License

This project does not currently have a license. All rights reserved unless otherwise stated.
