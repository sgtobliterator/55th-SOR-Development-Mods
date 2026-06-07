class CfgPatches
{
	class crowsza_main
	{
		name="main";
		units[]={};
		weapons[]={};
		requiredVersion=2.0999999;
		requiredAddons[]=
		{
			"cba_main",
			"zen_main",
			"zen_context_menu",
			"zen_custom_modules",
			"zen_attributes"
		};
		author="Crowdedlight";
		authorUrl="https://forums.bohemia.net/profile/1173289-crowdedlight/";
		version=2.2;
		versionStr="2.2";
		versionAr[]={2,2,2};
	};
};
class CfgFactionClasses
{
	class NO_CATEGORY;
	class CrowsZA_cat: NO_CATEGORY
	{
		displayName="Crows Zeus Additions";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class crowsza_main
		{
			list[]=
			{
				"crowsza_main"
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class crowsza_main
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\main\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class crowsza_main
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\main\XEH_postInit.sqf'";
	};
};
class Extended_PreStart_EventHandlers
{
	class crowsza_main
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\main\XEH_preStart.sqf'";
	};
};
