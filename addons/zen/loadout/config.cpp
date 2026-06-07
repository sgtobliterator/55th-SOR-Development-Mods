class CfgPatches
{
	class zen_loadout
	{
		name="ZEN - Loadout";
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
				"zen_loadout"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_loadout
	{
		init="call compileScript ['\x\zen\addons\loadout\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_loadout
	{
		init="call compileScript ['\x\zen\addons\loadout\XEH_preInit.sqf']";
	};
};
class ctrlButton;
class ctrlListNBox;
class ctrlButtonPicture;
class zen_common_RscBackground;
class zen_common_RscEdit;
class zen_common_RscCombo;
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
class zen_loadout_display: zen_common_RscDisplay
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
			h="((18.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class Weapon: zen_common_RscCombo
				{
					idc=1610;
					x=0;
					y=0;
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class ListBackground: zen_common_RscBackground
				{
					x=0;
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((16.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class List: ctrlListNBox
				{
					idc=1620;
					idcLeft=1630;
					idcRight=1640;
					x=0;
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((16.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					drawSideArrows=1;
					disableOverflow=1;
					columns[]={0.050000001,0.55000001,0.85000002};
				};
				class ButtonRemove: ctrlButton
				{
					idc=1630;
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
					idc=1640;
					text="+";
				};
				class ButtonSearch: ctrlButtonPicture
				{
					idc=1650;
					text="\a3\Ui_f\data\GUI\RscCommon\RscButtonSearch\search_start_ca.paa";
					x=0;
					y="((17.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0.5};
					offsetPressedX=0;
					offsetPressedY=0;
				};
				class SearchBar: zen_common_RscEdit
				{
					idc=1660;
					x="((1.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((17.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((8) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					sizeEx="((0.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class ButtonClear: ButtonSearch
				{
					idc=1670;
					text="\a3\3den\data\cfg3den\history\deleteitems_ca.paa";
					tooltip="$STR_disp_arcmap_clear";
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
