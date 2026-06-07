class CfgPatches
{
	class zen_position_logics
	{
		name="ZEN - Position Logics";
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
				"zen_position_logics"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_position_logics
	{
		init="call compileScript ['\x\zen\addons\position_logics\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_position_logics
	{
		init="call compileScript ['\x\zen\addons\position_logics\XEH_preInit.sqf']";
	};
};
