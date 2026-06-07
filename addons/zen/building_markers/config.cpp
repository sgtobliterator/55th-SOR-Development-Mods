class CfgPatches
{
	class zen_building_markers
	{
		name="ZEN - Building Markers";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_common"
		};
		author="$STR_zen_main_Author";
		authors[]=
		{
			"Ampersand"
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
				"zen_building_markers"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_building_markers
	{
		init="call compileScript ['\x\zen\addons\building_markers\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_building_markers
	{
		init="call compileScript ['\x\zen\addons\building_markers\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_building_markers
	{
		init="call compileScript ['\x\zen\addons\building_markers\XEH_postInit.sqf']";
	};
};
