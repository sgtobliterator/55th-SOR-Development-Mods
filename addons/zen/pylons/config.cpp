class CfgPatches
{
	class zen_pylons
	{
		name="ZEN - Pylons";
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
				"zen_pylons"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_pylons
	{
		init="call compileScript ['\x\zen\addons\pylons\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_pylons
	{
		init="call compileScript ['\x\zen\addons\pylons\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_pylons
	{
		init="call compileScript ['\x\zen\addons\pylons\XEH_postInit.sqf']";
	};
};
class RscText;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class ctrlCombo;
class ctrlStatic;
class ctrlCheckbox;
class ctrlStaticBackground;
class ctrlStaticPictureKeepAspect;
class zen_pylons_display
{
	idd=-1;
	movingEnable=1;
	onLoad="uiNamespace setVariable [""zen_pylons_display"", _this select 0]";
	class controls
	{
		class Title: RscText
		{
			idc=10;
			x="((getResolution select 2) * 0.5 * pixelW) - (((124.2) * pixelW * pixelGrid * 0.5) + ((5) * pixelW * pixelGrid * 0.5)) / 2";
			y="((getResolution select 3) * 0.5 * pixelH) - (((69.9) * pixelH * pixelGrid * 0.5) + ((22) * pixelH * pixelGrid * 0.5)) / 2";
			w="((124.2) * pixelW * pixelGrid * 0.5) + ((5) * pixelW * pixelGrid * 0.5)";
			h="((5) * pixelH * pixelGrid * 0.5)";
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
			x="((getResolution select 2) * 0.5 * pixelW) - (((124.2) * pixelW * pixelGrid * 0.5) + ((5) * pixelW * pixelGrid * 0.5)) / 2";
			y="((getResolution select 3) * 0.5 * pixelH) - (((69.9) * pixelH * pixelGrid * 0.5) + ((11) * pixelH * pixelGrid * 0.5)) / 2";
			w="((124.2) * pixelW * pixelGrid * 0.5) + ((5) * pixelW * pixelGrid * 0.5)";
			h="((69.9) * pixelH * pixelGrid * 0.5) + ((11) * pixelH * pixelGrid * 0.5)";
			colorBackground[]={0,0,0,0.69999999};
		};
		class PictureBackground: ctrlStaticBackground
		{
			idc=-1;
			x="((getResolution select 2) * 0.5 * pixelW) - ((124.2) * pixelW * pixelGrid * 0.5) / 2";
			y="((getResolution select 3) * 0.5 * pixelH) - (((69.9) * pixelH * pixelGrid * 0.5) + ((6) * pixelH * pixelGrid * 0.5)) / 2";
			w="((124.2) * pixelW * pixelGrid * 0.5)";
			h="((69.9) * pixelH * pixelGrid * 0.5)";
		};
		class Picture: ctrlStaticPictureKeepAspect
		{
			idc=800;
			x="((getResolution select 2) * 0.5 * pixelW) - ((124.2) * pixelW * pixelGrid * 0.5) / 2";
			y="((getResolution select 3) * 0.5 * pixelH) - (((69.9) * pixelH * pixelGrid * 0.5) + ((6) * pixelH * pixelGrid * 0.5)) / 2";
			w="((124.2) * pixelW * pixelGrid * 0.5)";
			h="((69.9) * pixelH * pixelGrid * 0.5)";
		};
		class Presets: ctrlCombo
		{
			idc=810;
			x="((getResolution select 2) * 0.5 * pixelW) - ((124.2) * pixelW * pixelGrid * 0.5) / 2";
			y="((getResolution select 3) * 0.5 * pixelH) + (((69.9) * pixelH * pixelGrid * 0.5) + ((6) * pixelH * pixelGrid * 0.5)) / 2 - ((5) * pixelH * pixelGrid * 0.5)";
			w="((124.2) * pixelW * pixelGrid * 0.5) / 3";
			h="((5) * pixelH * pixelGrid * 0.5)";
		};
		class MirrorLabel: ctrlStatic
		{
			style=1;
			text="$STR_3DEN_Object_Attribute_PylonsMirror_displayName";
			tooltip="$STR_3DEN_Object_Attribute_PylonsMirror_tooltip";
			x="((getResolution select 2) * 0.5 * pixelW) + ((124.2) * pixelW * pixelGrid * 0.5) / 2 - ((35) * pixelW * pixelGrid * 0.5)";
			y="((getResolution select 3) * 0.5 * pixelH) + (((69.9) * pixelH * pixelGrid * 0.5) + ((6) * pixelH * pixelGrid * 0.5)) / 2 - ((5) * pixelH * pixelGrid * 0.5)";
			w="((30) * pixelW * pixelGrid * 0.5)";
			h="((5) * pixelH * pixelGrid * 0.5)";
		};
		class Mirror: ctrlCheckbox
		{
			idc=820;
			x="((getResolution select 2) * 0.5 * pixelW) + ((124.2) * pixelW * pixelGrid * 0.5) / 2 - ((5) * pixelW * pixelGrid * 0.5)";
			y="((getResolution select 3) * 0.5 * pixelH) + (((69.9) * pixelH * pixelGrid * 0.5) + ((6) * pixelH * pixelGrid * 0.5)) / 2 - ((5) * pixelH * pixelGrid * 0.5)";
			w="((5) * pixelW * pixelGrid * 0.5)";
			h="((5) * pixelH * pixelGrid * 0.5)";
		};
		class ButtonOK: RscButtonMenuOK
		{
			x="((getResolution select 2) * 0.5 * pixelW) + (((124.2) * pixelW * pixelGrid * 0.5) + ((5) * pixelW * pixelGrid * 0.5)) / 2 - ((25) * pixelW * pixelGrid * 0.5)";
			y="((getResolution select 3) * 0.5 * pixelH) + (((69.9) * pixelH * pixelGrid * 0.5) + ((22) * pixelH * pixelGrid * 0.5)) / 2 - ((5) * pixelH * pixelGrid * 0.5)";
			w="((25) * pixelW * pixelGrid * 0.5)";
			h="((5) * pixelH * pixelGrid * 0.5)";
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((124.2) * pixelW * pixelGrid * 0.5) + ((5) * pixelW * pixelGrid * 0.5)) / 2";
			y="((getResolution select 3) * 0.5 * pixelH) + (((69.9) * pixelH * pixelGrid * 0.5) + ((22) * pixelH * pixelGrid * 0.5)) / 2 - ((5) * pixelH * pixelGrid * 0.5)";
			w="((25) * pixelW * pixelGrid * 0.5)";
			h="((5) * pixelH * pixelGrid * 0.5)";
		};
	};
};
