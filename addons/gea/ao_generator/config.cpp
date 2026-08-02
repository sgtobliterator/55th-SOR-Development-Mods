class CfgPatches
{
	class GEA_ao_generator
	{
		name="GEA - AO Generator";
		author="Online90";
		url="";
		units[]={};
		weapons[]={};
		requiredVersion=2.0999999;
		requiredAddons[]=
		{
			"A3_Functions_F",
			"cba_main",
			"zen_main"
		};
		version="0.9.0";
		versionStr="0.9.0";
		versionAr[]={0,9,0};
	};
};
class CfgRemoteExec
{
	class Functions
	{
		mode=1;
		jip=0;
		class GEA_fnc_generateAO
		{
			allowedTargets=2;
		};
		class GEA_fnc_drawAO
		{
			allowedTargets=0;
		};
	};
};
class CfgFunctions
{
	class GEA
	{
		class bootstrap
		{
			file="\gea\ao_generator\functions\ao";
			class registerZenModule
			{
				postInit=1;
			};
		};
		class settings
		{
			file="\gea\ao_generator\functions\settings";
			class cbaSettings
			{
				preInit=1;
			};
		};
		class modules
		{
			file="\gea\ao_generator\functions\modules";
			class moduleInit
			{
			};
			class bake3DEN
			{
			};
		};
		class ao
		{
			file="\gea\ao_generator\functions\ao";
			class generateAO
			{
			};
			class buildAOConfig
			{
			};
			class validateAOPosition
			{
			};
		};
		class infantry
		{
			file="\gea\ao_generator\functions\infantry";
			class spawnPatrolGroup
			{
			};
			class spawnGarrisonGroup
			{
			};
			class assignPatrol
			{
			};
		};
		class civilians
		{
			file="\gea\ao_generator\functions\civilians";
			class spawnCivilians
			{
			};
			class spawnCivilianCars
			{
			};
		};
		class mines
		{
			file="\gea\ao_generator\functions\mines";
			class spawnMinefield
			{
			};
		};
		class roadblocks
		{
			file="\gea\ao_generator\functions\roadblocks";
			class spawnRoadblock
			{
			};
		};
		class garrison
		{
			file="\gea\ao_generator\functions\garrison";
			class findBuildings
			{
			};
			class fillBuilding
			{
			};
		};
		class vehicles
		{
			file="\gea\ao_generator\functions\vehicles";
			class spawnVehiclePatrol
			{
			};
		};
		class statics
		{
			file="\gea\ao_generator\functions\statics";
			class spawnStaticDefense
			{
			};
			class pickTurretCrew
			{
			};
		};
		class air
		{
			file="\gea\ao_generator\functions\air";
			class spawnHeliPatrol
			{
			};
			class spawnJetPatrol
			{
			};
			class spawnDronePatrol
			{
			};
			class spawnPlanePatrol
			{
			};
		};
		class cleanup
		{
			file="\gea\ao_generator\functions\cleanup";
			class registerCleanup
			{
			};
			class despawnAO
			{
			};
		};
		class debug
		{
			file="\gea\ao_generator\functions\debug";
			class drawAO
			{
			};
		};
		class ui
		{
			file="\gea\ao_generator\functions\ui";
			class openDialog
			{
			};
			class openConfigDialog
			{
			};
		};
		class factions
		{
			file="\gea\ao_generator\functions\factions";
			class getSides
			{
			};
			class getFactionsForSide
			{
			};
			class getGroupsForFaction
			{
			};
		};
	};
};
class CfgFactionClasses
{
	class NO_CATEGORY;
	class GEA: NO_CATEGORY
	{
		displayName="GEA";
		priority=2;
		side=7;
	};
};
class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit;
			class Combo;
			class Checkbox;
			class ModuleDescription;
		};
		class ModuleDescription;
	};
	class GEA_Module_GenerateAO: Module_F
	{
		scope=2;
		scopeCurator=1;
		displayName="Generate Enemy AO";
		category="GEA";
		icon="\a3\ui_f\data\igui\cfg\simpletasks\types\attack_ca.paa";
		function="GEA_fnc_moduleInit";
		functionPriority=1;
		isGlobal=2;
		isTriggerActivated=0;
		isDisposable=0;
		is3DEN=1;
		class AttributeValues
		{
		};
		class Attributes: AttributesBase
		{
			class GEA_side: Combo
			{
				property="GEA_side";
				displayName="Side";
				tooltip="Side the AO enemy belongs to.";
				typeName="STRING";
				defaultValue="'east'";
				expression="_this setVariable ['GEA_side', _value]";
				class Values
				{
					class west
					{
						name="BLUFOR";
						value="west";
					};
					class east
					{
						name="OPFOR";
						value="east";
					};
					class guer
					{
						name="Independent";
						value="independent";
					};
					class civ
					{
						name="Civilian";
						value="civilian";
					};
				};
			};
			class GEA_faction: Edit
			{
				property="GEA_faction";
				displayName="Faction (classname)";
				tooltip="CfgFactionClasses classname (e.g. OPF_F, rhs_faction_msv). Leave blank to auto-pick the first faction for the chosen side.";
				typeName="STRING";
				defaultValue="''";
				expression="_this setVariable ['GEA_faction', _value]";
			};
			class GEA_radius: Edit
			{
				property="GEA_radius";
				displayName="Radius (m)";
				tooltip="AO radius in metres (100-2000 recommended).";
				typeName="NUMBER";
				defaultValue="500";
				expression="_this setVariable ['GEA_radius', _value]";
			};
			class GEA_skill: Edit
			{
				property="GEA_skill";
				displayName="AI Skill (0-1)";
				tooltip="Unit skill, 0.0 to 1.0.";
				typeName="NUMBER";
				defaultValue="0.5";
				expression="_this setVariable ['GEA_skill', _value]";
			};
			class GEA_patrolGroups: Edit
			{
				property="GEA_patrolGroups";
				displayName="Patrol Groups";
				tooltip="Number of patrolling infantry groups.";
				typeName="NUMBER";
				defaultValue="3";
				expression="_this setVariable ['GEA_patrolGroups', _value]";
			};
			class GEA_garrisonGroups: Edit
			{
				property="GEA_garrisonGroups";
				displayName="Garrison Groups";
				tooltip="Number of small garrison fireteams placed in buildings (caps at usable buildings).";
				typeName="NUMBER";
				defaultValue="5";
				expression="_this setVariable ['GEA_garrisonGroups', _value]";
			};
			class GEA_staticTurrets: Edit
			{
				property="GEA_staticTurrets";
				displayName="Static Turrets";
				tooltip="Number of manned static weapons placed on the perimeter, facing outward. Random class from the faction's static pool (side fallback).";
				typeName="NUMBER";
				defaultValue="0";
				expression="_this setVariable ['GEA_staticTurrets', _value]";
			};
			class GEA_vehiclePatrols: Edit
			{
				property="GEA_vehiclePatrols";
				displayName="Vehicle Patrols";
				tooltip="Total ground vehicles to spawn. Mix is set by the % values below.";
				typeName="NUMBER";
				defaultValue="1";
				expression="_this setVariable ['GEA_vehiclePatrols', _value]";
			};
			class GEA_vehPctCar: Edit
			{
				property="GEA_vehPctCar";
				displayName="% Car";
				tooltip="Share of vehicles spawned as cars/MRAPs/trucks. Auto-normalized against APC/Tank.";
				typeName="NUMBER";
				defaultValue="70";
				expression="_this setVariable ['GEA_vehPctCar', _value]";
			};
			class GEA_vehPctApc: Edit
			{
				property="GEA_vehPctApc";
				displayName="% APC";
				tooltip="Share of vehicles spawned as APCs/IFVs. Auto-normalized.";
				typeName="NUMBER";
				defaultValue="20";
				expression="_this setVariable ['GEA_vehPctApc', _value]";
			};
			class GEA_vehPctTank: Edit
			{
				property="GEA_vehPctTank";
				displayName="% Tank";
				tooltip="Share of vehicles spawned as tanks. Auto-normalized.";
				typeName="NUMBER";
				defaultValue="10";
				expression="_this setVariable ['GEA_vehPctTank', _value]";
			};
			class GEA_airPatrols: Edit
			{
				property="GEA_airPatrols";
				displayName="Air Patrols";
				tooltip="Total air assets to spawn. Mix is set by the % values below.";
				typeName="NUMBER";
				defaultValue="0";
				expression="_this setVariable ['GEA_airPatrols', _value]";
			};
			class GEA_airPctHeli: Edit
			{
				property="GEA_airPctHeli";
				displayName="% Heli";
				tooltip="Share of air spawned as helicopters. Auto-normalized.";
				typeName="NUMBER";
				defaultValue="60";
				expression="_this setVariable ['GEA_airPctHeli', _value]";
			};
			class GEA_airPctJet: Edit
			{
				property="GEA_airPctJet";
				displayName="% Jet";
				tooltip="Share of air spawned as fast jets. Auto-normalized.";
				typeName="NUMBER";
				defaultValue="20";
				expression="_this setVariable ['GEA_airPctJet', _value]";
			};
			class GEA_airPctDrone: Edit
			{
				property="GEA_airPctDrone";
				displayName="% Drone";
				tooltip="Share of air spawned as UAVs/drones. Auto-normalized.";
				typeName="NUMBER";
				defaultValue="10";
				expression="_this setVariable ['GEA_airPctDrone', _value]";
			};
			class GEA_airPctPlane: Edit
			{
				property="GEA_airPctPlane";
				displayName="% Plane";
				tooltip="Share of air spawned as slow/CAS planes. Auto-normalized.";
				typeName="NUMBER";
				defaultValue="10";
				expression="_this setVariable ['GEA_airPctPlane', _value]";
			};
			class GEA_showMarker: Checkbox
			{
				property="GEA_showMarker";
				displayName="Show AO Marker";
				tooltip="Place a side-colored objective marker + area ellipse for all players.";
				typeName="BOOL";
				defaultValue="true";
				expression="_this setVariable ['GEA_showMarker', _value]";
			};
			class GEA_simplePathing: Checkbox
			{
				property="GEA_simplePathing";
				displayName="Simple Pathing";
				tooltip="Performance option. ON = every patrol (infantry, vehicle, air) gets only 2 waypoints + cycle. OFF = rich dynamic BIS patrol (default).";
				typeName="BOOL";
				defaultValue="false";
				expression="_this setVariable ['GEA_simplePathing', _value]";
			};
			class GEA_civFaction: Edit
			{
				property="GEA_civFaction";
				displayName="Civilian Faction (classname)";
				tooltip="CfgFactionClasses civilian classname for civs/cars (e.g. CIV_F, CIV_IDAP_F). Leave blank to use any civilian-side units.";
				typeName="STRING";
				defaultValue="''";
				expression="_this setVariable ['GEA_civFaction', _value]";
			};
			class GEA_civPatrol: Edit
			{
				property="GEA_civPatrol";
				displayName="Patrol Civilians";
				tooltip="Number of wandering ambient civilians (walk around the AO).";
				typeName="NUMBER";
				defaultValue="0";
				expression="_this setVariable ['GEA_civPatrol', _value]";
			};
			class GEA_civGarrison: Edit
			{
				property="GEA_civGarrison";
				displayName="Garrison Civilians";
				tooltip="Number of civilians placed inside buildings (caps at usable slots).";
				typeName="NUMBER";
				defaultValue="0";
				expression="_this setVariable ['GEA_civGarrison', _value]";
			};
			class GEA_civCars: Edit
			{
				property="GEA_civCars";
				displayName="Civilian Cars";
				tooltip="Number of empty parked civilian cars to scatter around the AO (no drivers).";
				typeName="NUMBER";
				defaultValue="0";
				expression="_this setVariable ['GEA_civCars', _value]";
			};
			class GEA_mineFields: Edit
			{
				property="GEA_mineFields";
				displayName="Minefields";
				tooltip="Number of minefields to scatter on the AO perimeter. Each is a cluster of random mines of a random (moderate) size.";
				typeName="NUMBER";
				defaultValue="0";
				expression="_this setVariable ['GEA_mineFields', _value]";
			};
			class GEA_showMineMarkers: Checkbox
			{
				property="GEA_showMineMarkers";
				displayName="Show Minefield Markers";
				tooltip="Mark each minefield on the map with a red hazard ellipse + icon. OFF = hidden hazards.";
				typeName="BOOL";
				defaultValue="false";
				expression="_this setVariable ['GEA_showMineMarkers', _value]";
			};
			class GEA_roadblocks: Edit
			{
				property="GEA_roadblocks";
				displayName="Roadblocks";
				tooltip="Number of manned roadblocks (barbed wire + sandbag bunker + 2-3 guards) placed on roads near the AO edge.";
				typeName="NUMBER";
				defaultValue="0";
				expression="_this setVariable ['GEA_roadblocks', _value]";
			};
			class GEA_heliRange: Edit
			{
				property="GEA_heliRange";
				displayName="Heli Patrol Range (m)";
				tooltip="Max distance BEYOND the AO radius that helicopters (and rotary drones) will patrol. Lower = tighter orbit. Default 1000.";
				typeName="NUMBER";
				defaultValue="1000";
				expression="_this setVariable ['GEA_heliRange', _value]";
			};
			class GEA_planeRange: Edit
			{
				property="GEA_planeRange";
				displayName="Plane Patrol Range (m)";
				tooltip="Max distance BEYOND the AO radius that jets / planes (and fixed-wing drones) will patrol. Lower = tighter circuit. Default 2000.";
				typeName="NUMBER";
				defaultValue="2000";
				expression="_this setVariable ['GEA_planeRange', _value]";
			};
			class GEA_generate: Checkbox
			{
				property="GEA_generate";
				displayName="Generate in editor now";
				tooltip="Tick this and press OK to immediately spawn all units/turrets/vehicles as editable editor entities (with Zeus-style patrols), then remove this module. Leave unticked to keep it as a runtime generator that spawns on Play.";
				typeName="BOOL";
				defaultValue="false";
				expression="_this setVariable ['GEA_generate', _value]";
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="Generates an enemy AO (infantry patrols, garrisons, static turrets, vehicle & air patrols) centred on this module. Runs at mission start, no Zeus required. Place one module per AO.";
		};
	};
};
class cfgMods
{
	author="Online";
	timepacked="1782935307";
};
