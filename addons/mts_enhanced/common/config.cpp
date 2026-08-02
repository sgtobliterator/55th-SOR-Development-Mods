class CfgPatches
{
	class mts_common
	{
		name="mts - Common";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main"
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
	class mts_common
	{
		init="call compileScript ['\z\mts_enhanced\addons\common\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_common
	{
		init="call compileScript ['\z\mts_enhanced\addons\common\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_common
	{
		init="call compileScript ['\z\mts_enhanced\addons\common\XEH_postInit.sqf']";
	};
};
