class CfgPatches
{
	class zen_compositions
	{
		name="ZEN - Compositions";
		units[]=
		{
			"zen_compositions_helper"
		};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_editor"
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
				"zen_compositions"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_compositions
	{
		init="call compileScript ['\x\zen\addons\compositions\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_compositions
	{
		init="call compileScript ['\x\zen\addons\compositions\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_compositions
	{
		init="call compileScript ['\x\zen\addons\compositions\XEH_postInit.sqf']";
	};
};
class Extended_DisplayLoad_EventHandlers
{
	class Display3DEN
	{
		zen_compositions="call (uiNamespace getVariable ""zen_compositions_fnc_initDisplay3DEN"")";
	};
	class Display3DENPlace
	{
		zen_compositions="call (uiNamespace getVariable ""zen_compositions_fnc_initDisplay3DEN"")";
	};
};
class CfgVehicleIcons
{
	zen_compositions_icon="\a3\3den\data\cfg3den\group\iconcustomcomposition_ca.paa";
};
class CBA_Extended_EventHandlers_base;
class CfgVehicles
{
	class Static;
	class zen_compositions_helper: Static
	{
		author="$STR_zen_main_Author";
		displayName="$STR_zen_compositions_Helper_DisplayName";
		icon="zen_compositions_icon";
		mapSize=0.5;
		scope=1;
		scopeCurator=1;
		class EventHandlers
		{
			init="_this call zen_compositions_fnc_initHelper";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
	};
};
class CfgGroups
{
	class Empty
	{
		class zen_compositions_category
		{
			name="";
			class zen_compositions_subcategory
			{
				name="";
				class zen_compositions_composition
				{
					name="";
					icon="";
					side=8;
					class Helper
					{
						vehicle="zen_compositions_helper";
						position[]={0,0,0};
						rank="";
						side=8;
						dir=0;
					};
				};
			};
		};
	};
};
class RscText;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscControlsGroupNoScrollbars;
class ctrlButtonPictureKeepAspect;
class zen_common_RscLabel;
class zen_common_RscBackground;
class zen_common_RscEdit;
class zen_common_RscCombo;
class zen_compositions_display
{
	idd=-1;
	movingEnable=1;
	onLoad="uiNamespace setVariable [""zen_compositions_display"", _this select 0]";
	class controls
	{
		class Title: RscText
		{
			idc=1000;
			x="((6.5) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			y="((9.85) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))/2))";
			w="((27) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorBackground[]=
			{
				"(profileNamespace getVariable ['GUI_BCG_RGB_R',0.13])",
				"(profileNamespace getVariable ['GUI_BCG_RGB_G',0.54])",
				"(profileNamespace getVariable ['GUI_BCG_RGB_B',0.21])",
				"(profileNamespace getVariable ['GUI_BCG_RGB_A',0.8])"
			};
			moving=1;
		};
		class Background: RscText
		{
			idc=-1;
			x="((6.5) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			y="((10.95) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))/2))";
			w="((27) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((3.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorBackground[]={0,0,0,0.69999999};
		};
		class CategoryLabel: zen_common_RscLabel
		{
			text="$STR_3DEN_Display3DENEditComposition_CategoryLabel_text";
			x="((7) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			y="((11.45) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))/2))";
			w="((10) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
		class CategoryEdit: zen_common_RscEdit
		{
			idc=1001;
			x="((17.1) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			y="((11.45) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))/2))";
			w="((14.8) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
		class CategoryList: zen_common_RscCombo
		{
			idc=1002;
			x="((31.9) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			y="((11.45) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))/2))";
			w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			sizeEx="((0.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class NameLabel: CategoryLabel
		{
			text="$STR_3DEN_Object_Attribute_UnitName_displayName";
			y="((12.55) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))/2))";
		};
		class NameEdit: CategoryEdit
		{
			idc=1003;
			y="((12.55) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))/2))";
			w="((15.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
		class ButtonOK: RscButtonMenuOK
		{
			x="((28.5) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			y="((14.15) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))/2))";
			w="((5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			x="((6.5) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			y="((14.15) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))/2))";
			w="((5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
};
class RscDisplayCurator
{
	class Controls
	{
		class Add: RscControlsGroupNoScrollbars
		{
			class controls
			{
				class CreateUnitsWest;
				class CreateGroupsEmpty: CreateUnitsWest
				{
					h="safeZoneH - ([9.3, 8.3] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class zen_compositions_panel: RscControlsGroupNoScrollbars
				{
					idc=9500;
					x=0;
					y="safeZoneH - ([4.2, 3.2] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="((11) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					class controls
					{
						class Create: ctrlButtonPictureKeepAspect
						{
							idc=9501;
							onButtonClick="call zen_compositions_fnc_buttonCreate";
							x="((0.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((0.05) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							text="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\customcomposition_add_ca.paa";
							tooltip="$STR_3DEN_Display3DEN_CustomCompositionPanel_Add_tooltip";
							colorFocused[]={0,0,0,0};
							colorBackground[]={0,0,0,0};
							colorBackgroundActive[]={0,0,0,0};
							colorBackgroundDisabled[]={0,0,0,0};
						};
						class Edit: Create
						{
							idc=9502;
							onLoad="(_this select 0) ctrlEnable false";
							onButtonClick="call zen_compositions_fnc_buttonEdit";
							x="((1.3) * (((safezoneW / safezoneH) min 1.2) / 40))";
							text="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\customcomposition_edit_ca.paa";
							tooltip="$STR_3DEN_Display3DEN_CustomCompositionPanel_Edit_tooltip";
						};
						class Randomize: Create
						{
							idc=9503;
							onButtonClick="call zen_compositions_fnc_buttonRandomize";
							x="((2.4) * (((safezoneW / safezoneH) min 1.2) / 40))";
							text="\x\zen\addons\compositions\ui\randomize_ca.paa";
							tooltip="";
						};
						class Delete: Edit
						{
							idc=9504;
							onButtonClick="call zen_compositions_fnc_buttonDelete";
							x="((9.8) * (((safezoneW / safezoneH) min 1.2) / 40))";
							text="\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
							tooltip="$STR_3DEN_Display3DEN_CustomCompositionPanel_Delete_tooltip";
						};
					};
				};
			};
		};
	};
};
