class CfgPatches
{
	class IRN_ambient_aircraft
	{
		name="IRN - Ambient_Aircraft";
		units[]={};
		weapons[]={};
		requiredVersion=2.1199999;
		requiredAddons[]=
		{
			"IRN_main",
			"A3_Modules_F",
			"zen_modules",
			"zen_custom_modules"
		};
		authors[]=
		{
			"IR0NSIGHT"
		};
		version=2;
		versionStr="2.0";
		versionAr[]={2,0,0,0};
	};
};
class Extended_PreStart_EventHandlers
{
	class IRN_ambient_aircraft
	{
		init="call compile preprocessFileLineNumbers '\z\IRN\addons\ambient_aircraft\XEH_preStart.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class IRN_ambient_aircraft
	{
		init="call compile preprocessFileLineNumbers '\z\IRN\addons\ambient_aircraft\XEH_preInit.sqf'";
		serverInit="call compile preprocessFileLineNumbers '\z\IRN\addons\ambient_aircraft\XEH_preInit_server.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class IRN_ambient_aircraft
	{
		init="call compile preprocessFileLineNumbers '\z\IRN\addons\ambient_aircraft\XEH_postInit.sqf'";
		clientInit="call compile preprocessFileLineNumbers '\z\IRN\addons\ambient_aircraft\XEH_postInit_client.sqf'";
	};
};
class CfgFactionClasses
{
	class NO_CATEGORY;
	class AMB_MODS: NO_CATEGORY
	{
		displayName="Ambient Modules";
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
			class CheckboxNumber;
			class ModuleDescription;
			class Units;
		};
		class ModuleDescription;
	};
	class IRN_ModuleBase: Module_F
	{
		author="IR0NSIGHT";
		category="AMB_MODS";
	};
	class IRN_Module_AmbientAA: IRN_ModuleBase
	{
		scope=2;
		isGlobal=0;
		isTriggerActivated=0;
		displayName="Ambient Anti-Air";
		function="IRN_ambient_aircraft_fnc_aaAmbientModule";
		class Attributes: AttributesBase
		{
			class LethalRange: Edit
			{
				property="irn_amb_ambientAA_lethalRange";
				displayName="Lethal Range";
				tooltip="<meters> AA will shoot down enemy aircraft inside this range. -1 to disable";
				typeName="NUMBER";
				defaultValue=-1;
			};
			class DetectionRange: Edit
			{
				property="irn_amb_ambientAA_detectionRange";
				displayName="Detection Range";
				tooltip="<meters> AA will detect and engange enemy aircraft inside this range";
				typeName="NUMBER";
				defaultValue=3000;
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="Synched AA Units will fire wildly at enemy aircraft without hitting them.";
		};
	};
	class IRN_Module_RandomAATarget: IRN_ModuleBase
	{
		scope=2;
		isGlobal=0;
		isTriggerActivated=0;
		displayName="Random Anti-Air Fire";
		function="IRN_ambient_aircraft_fnc_randomTargetModule";
		class Attributes: AttributesBase
		{
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="Each synched unit will randomly fire at an invisible target in the air. Target moves at height 150 across the unit for 10 seconds, than pauses for some time and repeats.";
		};
	};
	class IRN_Module_SniperAA: IRN_ModuleBase
	{
		scope=2;
		isGlobal=0;
		isTriggerActivated=0;
		displayName="Sniper Anti-Air";
		function="IRN_ambient_aircraft_fnc_aaSniperModule";
		class Attributes: AttributesBase
		{
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="Synched AA Units will instantly see and engage all enemy aircraft within 2km.";
		};
	};
	class IRN_Module_CruiseMissile: IRN_ModuleBase
	{
		scope=2;
		isGlobal=0;
		isTriggerActivated=1;
		icon="\z\IRN\addons\ambient_aircraft\images\icon_cruise_missile.paa";
		displayName="Cruise Missile Strike";
		function="IRN_ambient_aircraft_fnc_cruiseMissileModule";
		class Attributes: AttributesBase
		{
			class Altitude: Edit
			{
				property="irn_amb_cruiseMissile_altitude";
				displayName="Altitude";
				tooltip="<meters> Missile will follow terrain in this altitude.";
				typeName="NUMBER";
				defaultValue=40;
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="Will spawn a cruisemissile above synched object. If nothing is synched, the missile is spawned outside the map. Missile will target the module position";
		};
	};
	class IRN_Module_Airtraffic: IRN_ModuleBase
	{
		scope=2;
		isGlobal=0;
		isTriggerActivated=1;
		icon="\z\IRN\addons\ambient_aircraft\images\icon_airtraffic.paa";
		displayName="Airtraffic";
		function="IRN_ambient_aircraft_fnc_ambientAirtrafficModule";
		class Attributes: AttributesBase
		{
			class planeClass: Edit
			{
				property="irn_amb_airtraffic_planeClass";
				displayName="Plane Classname Array";
				tooltip="Which plane types to use.";
				typeName="STRING";
				defaultValue="['I_Plane_Fighter_03_dynamicLoadout_F','I_Plane_Fighter_03_dynamicLoadout_F','I_Plane_Fighter_03_dynamicLoadout_F']";
			};
			class weights: Edit
			{
				property="irn_amb_airtraffic_weights";
				displayName="class weights array";
				tooltip="How often to spawn this plane type compared to the others. one entry per plane class";
				typeName="STRING";
				defaultValue="[2, 4, 1]";
			};
			class squadSize: Edit
			{
				property="irn_amb_airtraffic_squadsize";
				displayName="squad size array";
				tooltip="How big the squads for each plane can be at max. one entry per plane class";
				typeName="STRING";
				defaultValue="[2, 4, 1]";
			};
			class timeout: Edit
			{
				property="irn_amb_airtraffic_timeout";
				displayName="Timeout between flights (mins)";
				tooltip="average time between flights";
				typeName="NUMBER";
				defaultValue=10;
			};
			class duration: Edit
			{
				property="irn_amb_airtraffic_duration";
				displayName="Duration (mins)";
				tooltip="how long the airtraffic will spawn new planes";
				typeName="NUMBER";
				defaultValue=30;
			};
			class side: Combo
			{
				property="irn_amb_airtraffic_side";
				displayName="side";
				tooltip="Planes will be of side (for radar mostly)";
				typeName="NUMBER";
				defaultValue=0;
				class Values
				{
					class civ
					{
						name="Civilian";
						value=0;
					};
					class blufor
					{
						name="BluFor";
						value=1;
					};
					class opfor
					{
						name="OpFor";
						value=2;
					};
					class ind
					{
						name="Independent";
						value=3;
					};
				};
			};
			class includeZones: Edit
			{
				property="irn_amb_airtraffic_includeZones";
				displayName="inclusion markers";
				tooltip="Only spawn flybys for players that are in these marker areas. array of marker names";
				typeName="STRING";
				defaultValue="['airtraffic_include_0']";
			};
			class excludeZones: Edit
			{
				property="irn_amb_airtraffic_excludeZones";
				displayName="exclusion markers";
				tooltip="Only spawn flybys for players that are not in these marker areas. array of marker names";
				typeName="STRING";
				defaultValue="['airtraffic_exclude_0']";
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="Will spawn passive aircraft flybys near player every couple of minutes.";
		};
	};
	class IRN_Module_Airstrike: IRN_ModuleBase
	{
		scope=2;
		isGlobal=0;
		isTriggerActivated=1;
		icon="\a3\modules_f\data\portraitmodule_ca.paa";
		displayName="Airstrike";
		function="IRN_ambient_aircraft_fnc_airstrikeModule";
		class Attributes: AttributesBase
		{
			class planeClass: Edit
			{
				property="irn_amb_Airstrike_planeClass";
				displayName="Plane Classname";
				tooltip="Which plane to use.";
				typeName="STRING";
				defaultValue="'I_Plane_Fighter_03_dynamicLoadout_F'";
			};
			class bombCount: Edit
			{
				property="irn_amb_Airstrike_bombCount";
				displayName="Bomb amount";
				tooltip="How many bombs to drop: 1 = precise hit, many=spread across area";
				typeName="NUMBER";
				defaultValue=3;
			};
			class altitude: Edit
			{
				property="irn_amb_Airstrike_altitude";
				displayName="Altitude";
				tooltip="Plane will fly in height x";
				typeName="NUMBER";
				defaultValue=150;
			};
			class side: Combo
			{
				property="irn_amb_Airstrike_side";
				displayName="side";
				tooltip="Plane will be of side";
				typeName="NUMBER";
				defaultValue=0;
				class Values
				{
					class civ
					{
						name="Civilian";
						value=0;
					};
					class blufor
					{
						name="BluFor";
						value=1;
					};
					class opfor
					{
						name="OpFor";
						value=2;
					};
					class ind
					{
						name="Independent";
						value=3;
					};
				};
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="Will spawn airstrikes targetting all synched objectsq. Planes spawn near the module, then fly towards their targets";
		};
	};
	class IRN_Module_Artillery: IRN_ModuleBase
	{
		scope=2;
		isGlobal=0;
		isTriggerActivated=1;
		icon="\z\IRN\addons\ambient_aircraft\images\icon_arty_3.paa";
		displayName="Artillery";
		function="IRN_ambient_aircraft_fnc_ArtilleryVolleyModule";
		class Attributes: AttributesBase
		{
			class radius: Edit
			{
				property="irn_amb_artillery_radius";
				displayName="Radius";
				tooltip="<meter> Radius where shells will impact";
				typeName="NUMBER";
				defaultValue=100;
			};
			class movingDistance: Edit
			{
				property="irn_amb_artillery_movingDistance";
				displayName="Moving Distance";
				tooltip="<meter> Impact field will move x meters during lifetime into module's direction.";
				typeName="NUMBER";
				defaultValue=0;
			};
			class duration: Edit
			{
				property="irn_amb_artillery_duration";
				displayName="duration";
				tooltip="<seconds> duration of shelling.";
				typeName="NUMBER";
				defaultValue=30;
			};
			class intensity: Edit
			{
				property="irn_amb_artillery_intensity";
				displayName="Intensity";
				tooltip="<seconds> Average time between impacts.";
				typeName="NUMBER";
				defaultValue=2;
			};
			class ammo: Combo
			{
				property="irn_amb_artillery_ammo";
				displayName="AmmAmmunitiono";
				tooltip="Ammunition type to be used";
				typeName="NUMBER";
				defaultValue=0;
				class Values
				{
					class option1
					{
						name="40mm Flare white";
						value=0;
					};
					class option2
					{
						name="40mm Flare red";
						value=1;
					};
					class option3
					{
						name="40mm Flare green";
						value=2;
					};
					class option4
					{
						name="40mm HE";
						value=3;
					};
					class option5
					{
						name="82mm Smoke";
						value=4;
					};
					class option6
					{
						name="82mm HE";
						value=5;
					};
					class option7
					{
						name="155mm Smoke";
						value=6;
					};
					class option8
					{
						name="155mm HE";
						value=7;
					};
					class option9
					{
						name="230mm HE Rocket";
						value=8;
					};
				};
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="Will shell the area around the module with artillery. The module direction is used for a moving barrage.";
		};
	};
};
