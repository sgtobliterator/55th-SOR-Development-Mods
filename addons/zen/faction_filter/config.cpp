class CfgPatches
{
	class zen_faction_filter
	{
		name="ZEN - Faction Filter";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_editor"
		};
		author="$STR_zen_main_Author";
		authors[]=
		{
			"mharis001",
			"Kex"
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
				"zen_faction_filter"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_faction_filter
	{
		init="call compileScript ['\x\zen\addons\faction_filter\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_faction_filter
	{
		init="call compileScript ['\x\zen\addons\faction_filter\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_faction_filter
	{
		init="call compileScript ['\x\zen\addons\faction_filter\XEH_postInit.sqf']";
	};
};
