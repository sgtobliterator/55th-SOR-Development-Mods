class CfgPatches
{
	class mts_database
	{
		name="mts - Database";
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
			"PhILoX"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.1.260719";
		versionAr[]={1,10,1,260719};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_database
	{
		init="call compileScript ['\z\mts_enhanced\addons\database\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_database
	{
		init="call compileScript ['\z\mts_enhanced\addons\database\XEH_preInit.sqf']";
	};
};
