class CfgPatches
{
	class mts_items
	{
		name="mts - Items";
		units[]=
		{
			"mts_items_marker_yellow_item",
			"mts_items_marker_mines_item"
		};
		weapons[]=
		{
			"mts_items_marker_yellow",
			"mts_items_marker_mines"
		};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"ace_interact_menu",
			"ace_common",
			"ace_interaction"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"Timi007",
			"Dan"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.1.260719";
		versionAr[]={1,10,1,260719};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_items
	{
		init="call compileScript ['\z\mts_enhanced\addons\items\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_items
	{
		init="call compileScript ['\z\mts_enhanced\addons\items\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_items
	{
		init="call compileScript ['\z\mts_enhanced\addons\items\XEH_postInit.sqf']";
	};
};
class Extended_DisplayLoad_EventHandlers
{
	class RscDisplayMission
	{
		mts_items="_this call compileScript ['\z\mts_enhanced\addons\items\XEH_missionDisplayLoad.sqf']";
	};
};
class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class ACE_SelfActions
		{
			class ACE_Equipment
			{
				class mts_items
				{
					displayName="$STR_mts_items_marker";
					insertChildren="_this call mts_items_fnc_getActions";
					icon="\z\mts_enhanced\addons\items\data\ui\icons\marker_white_icon.paa";
				};
			};
		};
	};
	class FlagSmall_F;
	class mts_items_marker_yellow: FlagSmall_F
	{
		author="$STR_mts_items_authors";
		displayName="$STR_mts_items_markerYellowDisplayName";
	};
	class Land_Sign_MinesTall_English_F;
	class mts_items_marker_mines: Land_Sign_MinesTall_English_F
	{
		author="$STR_mts_items_authors";
		displayName="$STR_mts_items_markerMinesDisplayName";
	};
	class Item_Base_F;
	class mts_items_item_base: Item_Base_F
	{
		author="$STR_mts_items_authors";
		scope=0;
		scopeCurator=0;
		editorCategory="EdCat_Equipment";
		editorSubcategory="EdSubcat_InventoryItems";
		vehicleClass="Items";
		model="\A3\Weapons_F\DummyItemHorizontal.p3d";
		class TransportItems
		{
		};
	};
	class mts_items_marker_yellow_item: mts_items_item_base
	{
		author="$STR_mts_items_authors";
		displayName="$STR_mts_items_markerYellowDisplayName";
		scope=2;
		scopeCurator=2;
		class TransportItems
		{
			class mts_items_marker_yellow
			{
				name="mts_items_marker_yellow";
				count=1;
			};
		};
	};
	class mts_items_marker_mines_item: mts_items_item_base
	{
		author="$STR_mts_items_authors";
		displayName="$STR_mts_items_markerMinesDisplayName";
		scope=2;
		scopeCurator=2;
		class TransportItems
		{
			class mts_items_marker_mines
			{
				name="mts_items_marker_mines";
				count=1;
			};
		};
	};
};
class CfgWeapons
{
	class CBA_MiscItem;
	class CBA_MiscItem_ItemInfo;
	class mts_items_marker_base: CBA_MiscItem
	{
		author="$STR_mts_items_authors";
		scope=0;
		descriptionShort="$STR_mts_items_markerDescription";
		descriptionUse="$STR_mts_items_markerDescription";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=5;
		};
	};
	class mts_items_marker_yellow: mts_items_marker_base
	{
		mts_items_vehicle="mts_items_marker_yellow";
		mts_items_icon="\z\mts_enhanced\addons\items\data\ui\icons\marker_yellow_place_icon.paa";
		scope=2;
		displayName="$STR_mts_items_markerYellowDisplayName";
		picture="\z\mts_enhanced\addons\items\data\ui\pictures\marker_yellow_item.paa";
	};
	class mts_items_marker_mines: mts_items_marker_base
	{
		mts_items_vehicle="mts_items_marker_mines";
		mts_items_icon="\z\mts_enhanced\addons\items\data\ui\icons\marker_mines_place_icon.paa";
		scope=2;
		displayName="$STR_mts_items_markerMinesDisplayName";
		picture="\z\mts_enhanced\addons\items\data\ui\pictures\marker_mines_item.paa";
	};
};
