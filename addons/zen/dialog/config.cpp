class CfgPatches
{
	class zen_dialog
	{
		name="ZEN - Dialog";
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
				"zen_dialog"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_dialog
	{
		init="call compileScript ['\x\zen\addons\dialog\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_dialog
	{
		init="call compileScript ['\x\zen\addons\dialog\XEH_preInit.sqf']";
	};
};
class RscText;
class RscEdit;
class ctrlXSliderH;
class RscControlsGroupNoScrollbars;
class zen_common_RscLabel;
class zen_common_RscBackground;
class zen_common_RscEdit;
class zen_common_RscCheckbox;
class zen_common_RscCombo;
class zen_common_RscListBox;
class zen_common_RscSides;
class zen_common_RscOwners;
class zen_dialog_Row_Base: RscControlsGroupNoScrollbars
{
	function="";
	idc=1000;
	x=0;
	y=0;
	w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls
	{
		class Label: zen_common_RscLabel
		{
			idc=1001;
		};
	};
};
class zen_dialog_Row_Checkbox: zen_dialog_Row_Base
{
	function="zen_dialog_fnc_gui_checkbox";
	class controls: controls
	{
		class Label: Label
		{
		};
		class Checkbox: zen_common_RscCheckbox
		{
			idc=1002;
		};
	};
};
class zen_dialog_Row_ColorRGB: zen_dialog_Row_Base
{
	function="zen_dialog_fnc_gui_color";
	h="((3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls: controls
	{
		class Label: Label
		{
		};
		class Preview: RscText
		{
			idc=1009;
			x=0;
			y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((10) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Red: ctrlXSliderH
		{
			idc=1010;
			x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y=0;
			w="((13.8) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			color[]={1,0,0,0.60000002};
			colorActive[]={1,0,0,1};
		};
		class Red_Edit: zen_common_RscEdit
		{
			idc=1011;
			x="((24) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y=0;
			w="((2) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Green: Red
		{
			idc=1012;
			y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			color[]={0,1,0,0.60000002};
			colorActive[]={0,1,0,1};
		};
		class Green_Edit: Red_Edit
		{
			idc=1013;
			y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Blue: Red
		{
			idc=1014;
			y="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			color[]={0,0,1,0.60000002};
			colorActive[]={0,0,1,1};
		};
		class Blue_Edit: Red_Edit
		{
			idc=1015;
			y="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
};
class zen_dialog_Row_ColorRGBA: zen_dialog_Row_ColorRGB
{
	h="((4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls: controls
	{
		class Label: Label
		{
		};
		class Preview: Preview
		{
			h="((3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Red: Red
		{
		};
		class Red_Edit: Red_Edit
		{
		};
		class Green: Green
		{
		};
		class Green_Edit: Green_Edit
		{
		};
		class Blue: Blue
		{
		};
		class Blue_Edit: Blue_Edit
		{
		};
		class Alpha: Red
		{
			idc=1016;
			y="((3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			color[]={1,1,1,0.60000002};
			colorActive[]={1,1,1,1};
		};
		class Alpha_Edit: Red_Edit
		{
			idc=1017;
			y="((3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
};
class zen_dialog_Row_Combo: zen_dialog_Row_Base
{
	function="zen_dialog_fnc_gui_combo";
	class controls: controls
	{
		class Label: Label
		{
		};
		class Combo: zen_common_RscCombo
		{
			idc=1003;
		};
	};
};
class zen_dialog_Row_Edit: zen_dialog_Row_Base
{
	function="zen_dialog_fnc_gui_edit";
	class controls: controls
	{
		class Label: Label
		{
		};
		class Edit: zen_common_RscEdit
		{
			idc=1004;
		};
	};
};
class zen_dialog_Row_EditMulti: zen_dialog_Row_Edit
{
	class controls: controls
	{
		class Label: Label
		{
			w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
		class Edit: Edit
		{
			style=16;
			x="pixelW";
			y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((26) * (((safezoneW / safezoneH) min 1.2) / 40)) - pixelW";
		};
	};
};
class zen_dialog_Row_EditCode: zen_dialog_Row_EditMulti
{
	class controls: controls
	{
		class Label: Label
		{
		};
		class Edit: Edit
		{
			font="EtelkaMonospacePro";
			sizeEx="((0.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			autocomplete="scripting";
		};
	};
};
class zen_dialog_Row_List: zen_dialog_Row_Base
{
	function="zen_dialog_fnc_gui_list";
	class controls: controls
	{
		class Label: Label
		{
			w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
		class List: zen_common_RscListBox
		{
			idc=1003;
		};
	};
};
class zen_dialog_Row_Owners: zen_dialog_Row_Base
{
	function="zen_dialog_fnc_gui_owners";
	h="((11) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls: controls
	{
		class Label: Label
		{
			w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
		class Owners: zen_common_RscOwners
		{
			idc=1008;
			y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
};
class zen_dialog_Row_Sides: zen_dialog_Row_Base
{
	function="zen_dialog_fnc_gui_sides";
	h="((2.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls: controls
	{
		class Label: Label
		{
			h="((2.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Background: zen_common_RscBackground
		{
		};
		class Sides: zen_common_RscSides
		{
			idc=1007;
		};
	};
};
class zen_dialog_Row_Slider: zen_dialog_Row_Base
{
	function="zen_dialog_fnc_gui_slider";
	class controls: controls
	{
		class Label: Label
		{
		};
		class Slider: ctrlXSliderH
		{
			idc=1005;
			x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y=0;
			w="((13.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Edit: zen_common_RscEdit
		{
			idc=1004;
			x="((23.7) * (((safezoneW / safezoneH) min 1.2) / 40))";
			w="((2.3) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
	};
};
class zen_dialog_Row_Toolbox: zen_dialog_Row_Base
{
	function="zen_dialog_fnc_gui_toolbox";
	class controls: controls
	{
		class Label: Label
		{
		};
	};
};
class zen_dialog_Row_VectorXY: zen_dialog_Row_Base
{
	function="zen_dialog_fnc_gui_vector";
	class controls: controls
	{
		class Label: Label
		{
		};
		class IconX: RscText
		{
			idc=-1;
			style=2;
			text="$STR_3DEN_Axis_X";
			x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y=0;
			w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			font="RobotoCondensedLight";
			colorBackground[]={0.76999998,0.18000001,0.1,1};
			shadow=0;
		};
		class EditX: zen_common_RscEdit
		{
			idc=1018;
			x="((11.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
			w="((6.8) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
		class IconY: IconX
		{
			text="$STR_3DEN_Axis_Y";
			x="((18.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			colorBackground[]={0.57999998,0.81999999,0.22,1};
		};
		class EditY: EditX
		{
			idc=1019;
			x="((19.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
	};
};
class zen_dialog_Row_VectorXYZ: zen_dialog_Row_VectorXY
{
	class controls: controls
	{
		class Label: Label
		{
		};
		class IconX: IconX
		{
		};
		class EditX: EditX
		{
			w="((12.4/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
		class IconY: IconY
		{
			x="((11.3 + 12.4/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
		class EditY: EditY
		{
			x="((12.4 + 12.4/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
			w="((12.4/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
		class IconZ: IconX
		{
			text="$STR_3DEN_Axis_Z";
			x="((12.5 + 2 * 12.4/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
			colorBackground[]={0.25999999,0.51999998,0.92000002,1};
		};
		class EditZ: EditX
		{
			idc=1020;
			x="((13.6 + 2 * 12.4/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
			w="((12.4/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
	};
};
