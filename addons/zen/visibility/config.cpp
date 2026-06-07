class CfgPatches
{
	class zen_visibility
	{
		name="ZEN - Visibility";
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
			"Brett"
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
				"zen_visibility"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_visibility
	{
		init="call compileScript ['\x\zen\addons\visibility\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_visibility
	{
		init="call compileScript ['\x\zen\addons\visibility\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_visibility
	{
		init="call compileScript ['\x\zen\addons\visibility\XEH_postInit.sqf']";
	};
};
