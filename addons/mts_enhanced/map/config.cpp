class CfgPatches
{
	class mts_map
	{
		name="mts - Map";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"ace_interact_menu",
			"ace_common"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"PhILoX",
			"Timi007"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.0.251012";
		versionAr[]={1,10,0,251012};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_map
	{
		init="call compileScript ['\z\mts_enhanced\addons\map\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_map
	{
		init="call compileScript ['\z\mts_enhanced\addons\map\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_map
	{
		init="call compileScript ['\z\mts_enhanced\addons\map\XEH_postInit.sqf']";
	};
};
