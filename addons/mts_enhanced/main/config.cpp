class CfgPatches
{
	class mts_main
	{
		name="mts - Main";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"cba_main"
		};
		author="$STR_mts_main_authors";
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.0.251012";
		versionAr[]={1,10,0,251012};
	};
};
class CfgSettings
{
	class CBA
	{
		class Versioning
		{
			class mts_main
			{
				main_addon="mts_main";
				class dependencies
				{
					CBA[]=
					{
						"cba_main",
						{3,18,1},
						"true"
					};
				};
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_main
	{
		init="call compileScript ['\z\mts_enhanced\addons\main\XEH_preInit.sqf']";
	};
};
