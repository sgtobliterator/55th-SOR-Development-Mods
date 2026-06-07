class CfgPatches
{
	class zen_placement
	{
		name="ZEN - Placement";
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
			"Brett",
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
				"zen_placement"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_placement
	{
		init="call compileScript ['\x\zen\addons\placement\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_placement
	{
		init="call compileScript ['\x\zen\addons\placement\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_placement
	{
		init="call compileScript ['\x\zen\addons\placement\XEH_postInit.sqf']";
	};
};
