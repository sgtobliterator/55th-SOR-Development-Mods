------------------------------------------------------------------------------------------------------------------------------------
  Garage Spawner with Dynamic Vehicle Loadouts

      by Katsuobusi24
------------------------------------------------------------------------------------------------------------------------------------

**************************************************************************************************************************************************************************
Description:
This script is a vehicle spawner for tesing or practicing vehicles and pylon weapons.
This script is based on DCON's Multiplayer Vehicle Spawner.
This Script has been modifed and made into 3den/ZEN Modules + CBA settins by Phenosi

**************************************************************************************************************************************************************************
Features:
- Available in both of SP/MP.
- Compatible with MOD vehicles (CUP, RHS, Unsung etc...).
- During missions, players can open the Virtual Garage with Dynamic Vehicle Loadout that almost same as in 3DEN Editor.
- Players can set vehicle hitpoint damages(Some vehicle unable) and insignias(Only FIR, USAF MOD).
- Players can select the spawn type from "Only Spawn", "Get in", "Flying".
  ("Flying" is only available to planes and helicopters. If you use it on other vehicle types, same as "Get in".)
- Players can spawn a vehicle with crew selected in the garage. Types of spawning unit is discribed in "kbf\GarageParameters.sqf".
- Mission makers can set vehicle types available in the spawner.
- Mission makers can set white/black list and can set these list changed by sides.
- Mission makers can change spawnable vehicles by those sides. (The side of vehicle is described in its config.)
- Mission makers can set additional script executing when a vehicle spawn.
  In demo mission, it will execute the additional script that will delete the spawning vehicle destroyed or deserted for a certain period.

- The spawning point is defined by a object position.
- This script automatically add markers of spawning point and its effective area. The display name can be set by its variable name.
- The garage will be disabled when vehicles exist within 20m of the spawner and when someone open the garage in same place in multiplay.
  (If no one open the garage, but you can't open the garage, please use "Reset Garage Flag" for reset the flag.)
- This script add a action of deleting vehicles within the spawning area. But setting variable name "DFV_(some name)", the action can't delete these objects.

**************************************************************************************************************************************************************************
Installation/Usage:
edit by phenosi, file and fnc were out of date, Syntax didnt match up anymore
Put kbf folder, description.ext and init.sqf in your own mission folder.
If another description.ext or/and init.sqf already exist in it, copy contents and paste these in another description.ext/init.sqf.


Put this command in the object add actions.

Syntax
[this, spawn point object, spawnable types, enable sides, display distance, additional script] call kbf_fnc_garageInit;

| Parameter | Type            | Default    | Description                                                                                                                                                                                                                                    |
| --------- | --------------- | ---------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `_obj`    | Object          | `objNull`  | The object to which actions will be added.                                                                                                                                                                                                     |
| `_point`  | Object          | `objNull`  | The spawn point object where vehicles will spawn.                                                                                                                                                                                              |
| `_types`  | Array of String | `["Auto"]` | List of spawnable vehicle types for this spawner. If set to `["Auto"]`, types are determined by spawn point surface. Available types: `"All"`, `"Auto"`, `"Ground"`, `"Car"`, `"Tank"`, `"Helicopter"`, `"Plane"`, `"Ship"`, `"StaticWeapon"`. |
| `_sides`  | Array of String | `["ALL"]`  | List of sides allowed to use this spawner. If `["ALL"]`, all sides can use it. Available sides: `"ALL"`, `"BLUFOR"`, `"OPFOR"`, `"INDEP"`, `"CIV"`.                                                                                            |
| `_range`  | Number          | `10`       | The display distance (in meters) within which actions become available to the player.                                                                                                                                                          |
| `_script` | String          | `""`       | Additional code/script executed when a vehicle spawns. Available variables: `_veh` (spawned vehicle object), `_point` (spawn point), and others as defined in the script.                                                                      |


Examples
[this, GP_Airport] call kbf_fnc_garageInit;
// Spawner name: "Airport"
// Vehicle types auto-detected by spawn point surface (default ["Auto"])
// Default sides allowed: ["ALL"]
// Default display range: 10 meters
// No additional script executed

[this, GP_Airport_1, ["Car", "Tank"]] call kbf_fnc_garageInit;
// Spawner name: "Airport 1"
// Only cars and tanks can be spawned
// Default sides allowed: ["ALL"]
// Default display range: 10 meters
// No additional script executed

[this, GP_USS_Freedom, ["Ground"], 5] call kbf_fnc_garageInit;
// Spawner name: "USS Freedom"
// Vehicle types restricted to ground vehicles only
// Default sides allowed: ["ALL"]
// Display action range reduced to 5 meters
// No additional script executed

[this, GP_USS_Freedom, ["Auto"], 10, "[some arguments] execVM 'yourscript.sqf'"] call kbf_fnc_garageInit;
// Spawner name: "USS Freedom"
// Vehicle types auto-detected by spawn point surface
// Default sides allowed: ["ALL"]
// Display action range: 10 meters
// Executes external script "yourscript.sqf" on vehicle spawn, passing arguments as needed

**************************************************************************************************************************************************************************
Known issues:
- Error occur when you change selection too fast. Because the script can't finish processes in time.
- In Pylon settings of 3DEN Editor, turrets of RHS Tu-95 can be set as driver, gunnner and Navigation Plotter.
  But I haven't understood how to do that. So I now ignore it.

**************************************************************************************************************************************************************************
Credits & Thanks:
Yuruyaka ARMA3 club's member - For help debugging

**************************************************************************************************************************************************************************
Changelog:
v2.0 - Add white/black list, damage/insignia settings, and adjust scripts tree
v1.1 - First upload to Steam and some changes (Because of shutdown of Armaholic)
v1.0 - First upload to Armaholic