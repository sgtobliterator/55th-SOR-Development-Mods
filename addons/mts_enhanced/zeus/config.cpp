class CfgPatches
{
	class mts_zeus
	{
		name="mts - Zeus";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"zen_custom_modules",
			"zen_dialog",
			"zen_common",
			"zen_context_menu",
			"zen_modules",
			"ace_zeus"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"PhILoX",
			"Timi007"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.1.260719";
		versionAr[]={1,10,1,260719};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_zeus
	{
		init="call compileScript ['\z\mts_enhanced\addons\zeus\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_zeus
	{
		init="call compileScript ['\z\mts_enhanced\addons\zeus\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_zeus
	{
		init="call compileScript ['\z\mts_enhanced\addons\zeus\XEH_postInit.sqf']";
	};
};
class Extended_DisplayLoad_EventHandlers
{
	class RscDisplayCurator
	{
		mts_zeus_curatorDisplayOpened="call mts_zeus_fnc_onZeusDisplayOpen";
	};
};
class CfgAmmo
{
	class F_40mm_White;
	class mts_zeus_artillery_ILLUM: F_40mm_White
	{
		timeToLive=30;
		lightColor[]={0.5,0.5,0.25,0};
		brightness=12;
		intensity=600000;
	};
};
class CfgVehicles
{
	class zen_modules_moduleCreateTarget;
	class mts_zeus_moduleArtyTarget: zen_modules_moduleCreateTarget
	{
		scopeCurator=1;
		function="";
	};
};
