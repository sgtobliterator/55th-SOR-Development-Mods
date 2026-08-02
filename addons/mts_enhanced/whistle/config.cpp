class CfgPatches
{
	class mts_whistle
	{
		name="mts - Whistle";
		units[]=
		{
			"mts_whistle_FOX40_Item"
		};
		weapons[]=
		{
			"mts_whistle_FOX40"
		};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"Timi007"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.1.260719";
		versionAr[]={1,10,1,260719};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_whistle
	{
		init="call compileScript ['\z\mts_enhanced\addons\whistle\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_whistle
	{
		init="call compileScript ['\z\mts_enhanced\addons\whistle\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_whistle
	{
		init="call compileScript ['\z\mts_enhanced\addons\whistle\XEH_postInit.sqf']";
	};
};
class CfgVehicles
{
	class Item_Base_F;
	class mts_whistle_FOX40_Item: Item_Base_F
	{
		scope=2;
		scopeCurator=2;
		displayName="$STR_mts_whistle_whistleDisplayName";
		author="$STR_mts_whistle_authors";
		editorCategory="EdCat_Equipment";
		editorSubcategory="EdSubcat_InventoryItems";
		model="\A3\Weapons_F\DummyItemHorizontal.p3d";
		class TransportItems
		{
			class mts_whistle_FOX40
			{
				name="mts_whistle_FOX40";
				count=1;
			};
		};
	};
};
class CfgWeapons
{
	class CBA_MiscItem;
	class CBA_MiscItem_ItemInfo;
	class mts_whistle_FOX40: CBA_MiscItem
	{
		scope=2;
		displayName="$STR_mts_whistle_whistleDisplayName";
		author="$STR_mts_whistle_authors";
		picture="\z\mts_enhanced\addons\whistle\data\ui\fox40_whistle_icon.paa";
		descriptionShort="$STR_mts_whistle_description";
		descriptionUse="$STR_mts_whistle_description";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=1;
		};
	};
};
class CfgSounds
{
	sounds[]={};
	class mts_whistle_FOX40Sound
	{
		sound[]=
		{
			"\z\mts_enhanced\addons\whistle\data\sounds\fox40_whistle_sound.ogg",
			10,
			1,
			300
		};
		titles[]={};
	};
};
