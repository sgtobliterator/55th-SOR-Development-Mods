class CfgPatches
{
	class zen_compat_ace
	{
		name="ZEN - ACE Compatibility";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_ai",
			"zen_modules",
			"ace_interaction",
			"ace_zeus"
		};
		skipWhenMissingDependencies=1;
		author="$STR_zen_main_Author";
		authors[]=
		{
			"mharis001"
		};
		url="$STR_zen_main_URL";
		version=1.15;
		versionStr="1.15.1.36";
		versionAr[]={1,15,1,36};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class zen
		{
			list[]+=
			{
				"zen_compat_ace"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_compat_ace
	{
		init="call compileScript ['\x\zen\addons\compat_ace\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_compat_ace
	{
		init="call compileScript ['\x\zen\addons\compat_ace\XEH_preInit.sqf']";
	};
};
class CfgVehicles
{
	class Module_F;
	class ModuleCurator_F: Module_F
	{
		function="zen_modules_fnc_bi_moduleCurator";
	};
	class ModuleEmpty_F;
	class ModuleMine_F: ModuleEmpty_F
	{
		function="zen_modules_fnc_bi_moduleMine";
	};
	class ace_zeus_moduleBase;
	class ace_zeus_moduleEditableObjects: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_moduleGlobalSetSkill: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_moduleGroupSide: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_moduleHeal: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_modulePatrolArea: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_moduleSimulation: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_moduleSuicideBomber: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_moduleSuppressiveFire: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_moduleTeleportPlayers: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_moduleToggleFlashlight: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_AddFullArsenal: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_RemoveFullArsenal: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_AddFullAceArsenal: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
	class ace_zeus_RemoveFullAceArsenal: ace_zeus_moduleBase
	{
		scopeCurator="2 - parseNumber (missionNamespace getVariable [""zen_compat_ace_hideModules"", true])";
	};
};
class ZEN_WaypointTypes
{
	class Fastrope
	{
		displayName="$STR_zen_compat_ace_Fastrope";
		type="SCRIPTED";
		script="\x\zen\addons\compat_ace\functions\fnc_waypointFastrope.sqf";
	};
};
class ACE_ZeusActions
{
	class ZeusUnits
	{
		class remoteControl
		{
			condition="call zen_compat_ace_fnc_canRemoteControl";
			statement="call zen_compat_ace_fnc_remoteControl";
		};
	};
};
