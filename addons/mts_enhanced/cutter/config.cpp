class CfgPatches
{
	class mts_cutter
	{
		name="mts - Cutter";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"ace_common",
			"ace_interact_menu"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"PhILoX",
			"Timi007"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.0.251012";
		versionAr[]={1,10,0,251012};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_cutter
	{
		init="call compileScript ['\z\mts_enhanced\addons\cutter\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_cutter
	{
		init="call compileScript ['\z\mts_enhanced\addons\cutter\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_cutter
	{
		init="call compileScript ['\z\mts_enhanced\addons\cutter\XEH_postInit.sqf']";
	};
};
class CfgWeapons
{
	class CBA_MiscItem;
	class CBA_MiscItem_ItemInfo;
	class mts_cutter_folding_saw: CBA_MiscItem
	{
		scope=2;
		author="$STR_mts_cutter_authors";
		descriptionShort="$STR_mts_cutter_foldingSawDescription";
		descriptionUse="$STR_mts_cutter_foldingSawDescription";
		displayName="$STR_mts_cutter_foldingSaw";
		picture="\z\mts_enhanced\addons\cutter\data\pictures\folding_saw_item.paa";
		mts_cutter_canCutBushes=1;
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=1;
		};
	};
};
