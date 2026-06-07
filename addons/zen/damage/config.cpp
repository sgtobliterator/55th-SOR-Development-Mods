class CfgPatches
{
	class zen_damage
	{
		name="ZEN - Damage";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_attributes",
			"zen_dialog"
		};
		author="$STR_zen_main_Author";
		authors[]=
		{
			"NeilZar"
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
				"zen_damage"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_damage
	{
		init="call compileScript ['\x\zen\addons\damage\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_damage
	{
		init="call compileScript ['\x\zen\addons\damage\XEH_preInit.sqf']";
	};
};
