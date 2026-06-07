class CfgPatches
{
	class zen_flashlight
	{
		name="ZEN - Flashlight";
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
				"zen_flashlight"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_flashlight
	{
		init="call compileScript ['\x\zen\addons\flashlight\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_flashlight
	{
		init="call compileScript ['\x\zen\addons\flashlight\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_flashlight
	{
		init="call compileScript ['\x\zen\addons\flashlight\XEH_postInit.sqf']";
	};
};
