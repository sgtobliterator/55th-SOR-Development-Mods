class CfgPatches
{
	class zen_attributes
	{
		name="ZEN - Attributes";
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
				"zen_attributes"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_attributes
	{
		init="call compileScript ['\x\zen\addons\attributes\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_attributes
	{
		init="call compileScript ['\x\zen\addons\attributes\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_attributes
	{
		init="call compileScript ['\x\zen\addons\attributes\XEH_postInit.sqf']";
	};
};
class CfgFunctions
{
	class A3_Functions_F_Curator
	{
		class Curator
		{
			class showCuratorAttributes
			{
				file="\x\zen\addons\attributes\functions\fnc_bi_showCuratorAttributes.sqf";
			};
		};
	};
};
class CfgVehicles
{
	class All;
	class AllVehicles: All
	{
		curatorInfoType="";
		curatorInfoTypeEmpty="";
	};
	class FloatingStructure_F: All
	{
		curatorInfoType="";
		curatorInfoTypeEmpty="";
	};
	class Land;
	class Man: Land
	{
		curatorInfoType="";
		curatorInfoTypeEmpty="";
	};
	class ThingX;
	class ReammoBox_F: ThingX
	{
		curatorInfoType="";
		curatorInfoTypeEmpty="";
	};
};
class ctrlToolbox;
class ctrlToolboxPictureKeepAspect;
class ctrlXSliderH;
class ctrlButtonPictureKeepAspect;
class RscControlsGroupNoScrollbars;
class zen_common_RscLabel;
class zen_common_RscBackground;
class zen_common_RscEdit;
class zen_common_RscCombo;
class zen_attributes_base: RscControlsGroupNoScrollbars
{
	idc=400;
	function="";
	x=0;
	y=0;
	w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls
	{
		class Label: zen_common_RscLabel
		{
			idc=401;
		};
	};
};
class zen_attributes_checkboxes: zen_attributes_base
{
	function="zen_attributes_fnc_gui_checkboxes";
	class controls: controls
	{
		class Label: Label
		{
		};
		class Background: zen_common_RscBackground
		{
			idc=402;
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
};
class zen_attributes_code: zen_attributes_base
{
	function="zen_attributes_fnc_gui_code";
	h="((5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls: controls
	{
		class Label: Label
		{
		};
		class Combo: zen_common_RscCombo
		{
			idc=403;
			font="EtelkaMonospacePro";
			x="((10) * (((safezoneW / safezoneH) min 1.2) / 40))";
			w="((15) * (((safezoneW / safezoneH) min 1.2) / 40))";
			sizeEx="((0.65) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Mode: ctrlButtonPictureKeepAspect
		{
			idc=407;
			x="((25) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y=0;
			w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) - pixelH";
			offsetPressedX=0;
			offsetPressedY=0;
			colorBackground[]={0,0,0,0.5};
		};
		class Edit: zen_common_RscEdit
		{
			idc=404;
			style=16;
			font="EtelkaMonospacePro";
			x="pixelW";
			y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + pixelH";
			w="((26) * (((safezoneW / safezoneH) min 1.2) / 40)) - pixelW";
			h="((4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) - pixelH";
			sizeEx="((0.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			autocomplete="scripting";
		};
	};
};
class zen_attributes_combo: zen_attributes_base
{
	function="zen_attributes_fnc_gui_combo";
	class controls: controls
	{
		class Label: Label
		{
		};
		class Combo: zen_common_RscCombo
		{
			idc=403;
		};
	};
};
class zen_attributes_edit: zen_attributes_base
{
	function="zen_attributes_fnc_gui_edit";
	class controls: controls
	{
		class Label: Label
		{
		};
		class Edit: zen_common_RscEdit
		{
			idc=404;
		};
	};
};
class zen_attributes_icons: zen_attributes_base
{
	function="zen_attributes_fnc_gui_icons";
	h="((2.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls: controls
	{
		class Label: Label
		{
			h="((2.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Background: zen_common_RscBackground
		{
			idc=402;
		};
	};
};
class zen_attributes_slider: zen_attributes_base
{
	function="zen_attributes_fnc_gui_slider";
	class controls: controls
	{
		class Label: Label
		{
		};
		class Slider: ctrlXSliderH
		{
			idc=405;
			x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y=0;
			w="((13.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Edit: zen_common_RscEdit
		{
			idc=404;
			x="((23.7) * (((safezoneW / safezoneH) min 1.2) / 40))";
			w="((2.3) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
	};
};
class zen_attributes_toolbox: zen_attributes_base
{
	function="zen_attributes_fnc_gui_toolbox";
	class controls: controls
	{
		class Label: Label
		{
		};
	};
};
class zen_attributes_waypoint: zen_attributes_base
{
	function="zen_attributes_fnc_gui_waypoint";
	class controls: controls
	{
		class Label: Label
		{
			w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
		class Background: zen_common_RscBackground
		{
			idc=402;
			x=0;
			y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
		};
	};
};
class zen_attributes_loiter: zen_attributes_base
{
	function="zen_attributes_fnc_gui_loiter";
	h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls: controls
	{
		class Label: Label
		{
			h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Toolbox: ctrlToolboxPictureKeepAspect
		{
			idc=406;
			x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y=0;
			w="((15.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			rows=1;
			columns=2;
			strings[]=
			{
				"\a3\3den\data\attributes\loiterdirection\ccw_ca.paa",
				"\a3\3den\data\attributes\loiterdirection\cw_ca.paa"
			};
		};
	};
};
