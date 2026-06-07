class CfgPatches
{
	class zen_cover_map
	{
		name="ZEN - Cover Map";
		units[]=
		{
			"zen_cover_map_module"
		};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_modules"
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
				"zen_cover_map"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_cover_map
	{
		init="call compileScript ['\x\zen\addons\cover_map\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_cover_map
	{
		init="call compileScript ['\x\zen\addons\cover_map\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_cover_map
	{
		init="call compileScript ['\x\zen\addons\cover_map\XEH_postInit.sqf']";
	};
};
class CfgVehicles
{
	class zen_modules_moduleBase;
	class zen_cover_map_module: zen_modules_moduleBase
	{
		displayName="$STR_A3_CfgVehicles_ModuleCoverMap_F";
		curatorInfoType="zen_cover_map_display";
	};
};
class ctrlXSliderH;
class zen_common_RscLabel;
class zen_common_RscEdit;
class RscMapControl
{
	class CustomMark;
};
class zen_cover_map_RscMap: RscMapControl
{
	idc=100;
	alphaFadeStartScale=100;
	alphaFadeEndScale=100;
	scaleMin=9.9999997e-005;
	scaleMax=3;
	scaleDefault=1;
	showCountourInterval=0;
	class CustomMark: CustomMark
	{
		icon="#(argb,8,8,3)color(0,0,0,0)";
		color[]={0,0,0,0};
		size=0;
		importance=0;
		coefMin=0;
		coefMax=0;
	};
};
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
class zen_modules_RscDisplay: zen_common_RscDisplay
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
		};
		class ButtonOK: ButtonOK
		{
		};
		class ButtonCancel: ButtonCancel
		{
		};
	};
};
class zen_cover_map_display: zen_modules_RscDisplay
{
	function="zen_cover_map_fnc_handleLoad";
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
			h="((22.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class RotationLabel: zen_common_RscLabel
				{
					text="$STR_3DEN_Object_Attribute_Rotation_displayName";
				};
				class RotationSlider: ctrlXSliderH
				{
					idc=300;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y=0;
					w="((13.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class RotationEdit: zen_common_RscEdit
				{
					idc=400;
					x="((23.7) * (((safezoneW / safezoneH) min 1.2) / 40))";
					w="((2.3) * (((safezoneW / safezoneH) min 1.2) / 40))";
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
