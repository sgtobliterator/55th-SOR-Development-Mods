class CfgPatches
{
	class zen_inventory
	{
		name="ZEN - Inventory";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_attributes"
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
				"zen_inventory"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_inventory
	{
		init="call compileScript ['\x\zen\addons\inventory\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_inventory
	{
		init="call compileScript ['\x\zen\addons\inventory\XEH_preInit.sqf']";
	};
};
class RscText;
class ctrlButton;
class ctrlListNBox;
class ctrlProgress;
class ctrlButtonPicture;
class ctrlStaticPictureKeepAspect;
class ctrlToolboxPictureKeepAspect;
class RscControlsGroupNoScrollbars;
class zen_common_RscLabel;
class zen_common_RscBackground;
class zen_common_RscEdit;
class zen_common_RscDisplay
{
	class controls
	{
		class Title;
		class Background;
		class Content;
		class ButtonOK;
		class ButtonCancel;
	};
};
class zen_inventory_display: zen_common_RscDisplay
{
	class controls: controls
	{
		class Title: Title
		{
		};
		class Background: Background
		{
		};
		class Content: Content
		{
			h="((13/3 + 15.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class CategoryBackground: RscText
				{
					idc=-1;
					x=0;
					y=0;
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((13/3 + 1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0.5};
				};
				class Category: ctrlToolboxPictureKeepAspect
				{
					idc=1500;
					x=0;
					y=0;
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((13/3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0};
					rows=2;
					columns=12;
					strings[]=
					{
						"\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_0_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\PrimaryWeapon_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\SecondaryWeapon_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Handgun_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemOptic_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemAcc_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemMuzzle_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemBipod_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\CargoMagAll_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Headgear_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Uniform_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Vest_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Backpack_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Goggles_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\NVGs_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Binoculars_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Map_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Compass_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Radio_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Watch_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\GPS_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\CargoThrow_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\CargoPut_ca.paa",
						"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\CargoMisc_ca.paa"
					};
				};
				class WeaponSpecific: RscControlsGroupNoScrollbars
				{
					idc=1512;
					x=0;
					y=0;
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((13/3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					show=0;
					class controls
					{
						class Title: RscText
						{
							idc=1513;
							x=0;
							y=0;
							w="((25) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class Picture: ctrlStaticPictureKeepAspect
						{
							idc=1514;
							x=0;
							y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((28/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((10/3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class Category: ctrlToolboxPictureKeepAspect
						{
							idc=1515;
							x="((28/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((50/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((10/3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							colorBackground[]={0,0,0,0};
							rows=1;
							columns=5;
							strings[]=
							{
								"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemOptic_ca.paa",
								"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemAcc_ca.paa",
								"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemMuzzle_ca.paa",
								"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemBipod_ca.paa",
								"\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\CargoMagAll_ca.paa"
							};
						};
						class ButtonClose: ctrlButtonPicture
						{
							idc=1516;
							text="\a3\3den\data\displays\display3den\search_end_ca.paa";
							tooltip="$STR_zen_inventory_Close_Tooltip";
							x="((25) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y=0;
							w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							colorBackground[]={0,0,0,0.5};
						};
					};
				};
				class Sorting: ctrlListNBox
				{
					idc=1501;
					x=0;
					y="((13/3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					sizeEx="((0.85) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					disableOverflow=1;
					columns[]={0,0.80000001};
					class Items
					{
						class Name
						{
							text="$STR_A3_RscAttributeName_Title";
							value=1;
						};
						class Amount
						{
							text="$STR_zen_common_Amount";
							data="value";
						};
					};
				};
				class ListBackground: zen_common_RscBackground
				{
					x=0;
					y="((13/3 + 1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((13) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class List: ctrlListNBox
				{
					idc=1503;
					idcLeft=1504;
					idcRight=1505;
					x=0;
					y="((13/3 + 1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((13) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					drawSideArrows=1;
					disableOverflow=1;
					tooltipPerColumn=0;
					columns[]={0.050000001,0.15000001,0.80000001};
				};
				class ButtonRemove: ctrlButton
				{
					idc=1504;
					text="−";
					font="RobotoCondensedBold";
					x=-1;
					y=-1;
					w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					sizeEx="((1.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class ButtonAdd: ButtonRemove
				{
					idc=1505;
					text="+";
				};
				class ButtonSearch: ctrlButtonPicture
				{
					idc=1506;
					text="\a3\Ui_f\data\GUI\RscCommon\RscButtonSearch\search_start_ca.paa";
					tooltip="$STR_zen_inventory_Search_Tooltip";
					x=0;
					y="((13/3 + 14.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0.5};
				};
				class SearchBar: zen_common_RscEdit
				{
					idc=1507;
					x="((1.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((13/3 + 14.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((8) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					sizeEx="((0.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Load: ctrlProgress
				{
					idc=1508;
					x="((14.4) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((13/3 + 14.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((8) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((0.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorFrame[]={1,1,1,1};
				};
				class ButtonWeapon: ButtonSearch
				{
					idc=1509;
					text="\a3\3den\data\displays\display3den\entitymenu\arsenal_ca.paa";
					tooltip="$STR_zen_inventory_Weapon_Tooltip";
					x="((22.6) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class ButtonReset: ButtonSearch
				{
					idc=1510;
					text="\x\zen\addons\inventory\ui\reset_ca.paa";
					tooltip="$STR_zen_inventory_Reset_Tooltip";
					x="((23.8) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class ButtonClear: ButtonSearch
				{
					idc=1511;
					text="\a3\3den\data\cfg3den\history\deleteitems_ca.paa";
					tooltip="$STR_zen_inventory_Clear_Tooltip";
					x="((25) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
			};
		};
		class ButtonOK: ButtonOK
		{
		};
		class ButtonCancel: ButtonCancel
		{
		};
	};
};
