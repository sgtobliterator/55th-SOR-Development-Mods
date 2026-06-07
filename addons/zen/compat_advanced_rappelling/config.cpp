class CfgPatches
{
	class zen_compat_advanced_rappelling
	{
		name="ZEN - Advanced Rappelling Compatibility";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_ai"
		};
		author="$STR_zen_main_Author";
		authors[]=
		{
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
				"zen_compat_advanced_rappelling"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_compat_advanced_rappelling
	{
		init="call compileScript ['\x\zen\addons\compat_advanced_rappelling\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_compat_advanced_rappelling
	{
		init="call compileScript ['\x\zen\addons\compat_advanced_rappelling\XEH_preInit.sqf']";
	};
};
class ZEN_WaypointTypes
{
	class AdvancedRappel
	{
		displayName="$STR_zen_compat_advanced_rappelling_Rappel";
		type="SCRIPTED";
		script="\x\zen\addons\compat_advanced_rappelling\functions\fnc_waypointRappel.sqf";
		condition="!isNil 'AR_RAPPELLING_INIT'";
	};
};
