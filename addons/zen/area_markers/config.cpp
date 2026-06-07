class CfgPatches
{
	class zen_area_markers
	{
		name="ZEN - Area Markers";
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
				"zen_area_markers"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_area_markers
	{
		init="call compileScript ['\x\zen\addons\area_markers\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_area_markers
	{
		init="call compileScript ['\x\zen\addons\area_markers\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_area_markers
	{
		init="call compileScript ['\x\zen\addons\area_markers\XEH_postInit.sqf']";
	};
};
class RscText;
class RscPicture;
class ctrlXSliderH;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class ctrlToolboxPictureKeepAspect;
class RscControlsGroupNoScrollbars;
class zen_common_RscLabel;
class zen_common_RscBackground;
class zen_common_RscEdit;
class zen_common_RscCombo;
class zen_area_markers_icon: RscControlsGroupNoScrollbars
{
	idc=85800;
	x=0;
	y=0;
	w="((0.6) * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="((0.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls
	{
		class Image: RscPicture
		{
			idc=85810;
			text="\a3\3den\data\cfg3den\marker\texturecenter_ca.paa";
			x=0;
			y=0;
			w="((0.6) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((0.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Mouse: RscText
		{
			idc=85820;
			style=16;
			onMouseButtonDblClick="call zen_area_markers_fnc_onMouseDblClick";
			onMouseButtonDown="call zen_area_markers_fnc_onMouseButtonDown";
			onMouseButtonUp="call zen_area_markers_fnc_onMouseButtonUp";
			onMouseMoving="call zen_area_markers_fnc_onMouseMoving";
			x=0;
			y=0;
			w="((0.6) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((0.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
};
class zen_area_markers_configure: RscControlsGroupNoScrollbars
{
	idc=42870;
	x="safeZoneXAbs";
	y="safeZoneY";
	w="safeZoneWAbs";
	h="safeZoneH";
	class controls
	{
		class Container: RscControlsGroupNoScrollbars
		{
			idc=-1;
			x="safeZoneWAbs / 2 - ((13.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y="safeZoneH / 2 - ((6.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((27) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((13) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class Title: RscText
				{
					text="$STR_zen_area_markers_EditAreaMarker";
					x=0;
					y=0;
					w="((27) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]=
					{
						"(profileNamespace getVariable ['GUI_BCG_RGB_R',0.13])",
						"(profileNamespace getVariable ['GUI_BCG_RGB_G',0.54])",
						"(profileNamespace getVariable ['GUI_BCG_RGB_B',0.21])",
						"(profileNamespace getVariable ['GUI_BCG_RGB_A',0.8])"
					};
				};
				class Background: RscText
				{
					idc=-1;
					x=0;
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((27) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((10.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0.69999999};
				};
				class Transformation: RscControlsGroupNoScrollbars
				{
					idc=-1;
					x="((0.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((1.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					class controls
					{
						class Title: zen_common_RscLabel
						{
							text="$STR_3DEN_Object_AttributeCategory_Transformation";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
						class Background: zen_common_RscBackground
						{
							x=0;
							y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((2.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class SizeLabel: zen_common_RscLabel
						{
							text="$STR_3DEN_Trigger_Attribute_Size_displayName";
							tooltip="$STR_3DEN_Trigger_Attribute_Size_tooltip";
							x="((3) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((8.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
							colorBackground[]={0,0,0,0.69999999};
						};
						class IconA: RscText
						{
							idc=-1;
							style=2;
							text="$STR_3DEN_Axis_A";
							x="((12) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							font="RobotoCondensedLight";
							colorBackground[]={0.76999998,0.18000001,0.1,1};
							shadow=0;
						};
						class EditA: zen_common_RscEdit
						{
							idc=42871;
							x="((13.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + pixelH";
							w="((4.35) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) - pixelH";
							colorBackground[]={0,0,0,0.40000001};
						};
						class IconB: IconA
						{
							text="$STR_3DEN_Axis_B";
							x="((17.55) * (((safezoneW / safezoneH) min 1.2) / 40))";
							colorBackground[]={0.57999998,0.81999999,0.22,1};
						};
						class EditB: EditA
						{
							idc=42872;
							x="((18.65) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
						class RotationLabel: SizeLabel
						{
							text="$STR_3DEN_Object_Attribute_Rotation_displayName";
							tooltip="";
							y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class RotationSlider: ctrlXSliderH
						{
							idc=42873;
							x="((12) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((8.7) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class RotationEdit: zen_common_RscEdit
						{
							idc=42874;
							x="((20.8) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + pixelH";
							w="((2.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
							colorBackground[]={0,0,0,0.40000001};
						};
					};
				};
				class Style: RscControlsGroupNoScrollbars
				{
					idc=-1;
					x="((0.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((6.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					class controls
					{
						class Title: zen_common_RscLabel
						{
							text="$STR_3DEN_Marker_AttributeCategory_Style";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
						class Background: zen_common_RscBackground
						{
							x=0;
							y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((5.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class ShapeLabel: zen_common_RscLabel
						{
							text="$STR_3DEN_Trigger_Attribute_Shape_displayName";
							tooltip="$STR_3DEN_Trigger_Attribute_Shape_tooltip";
							x="((3) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((8.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							colorBackground[]={0,0,0,0.69999999};
						};
						class Shape: ctrlToolboxPictureKeepAspect
						{
							idc=42875;
							x="((12) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((11) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							colorBackground[]={0,0,0,0.69999999};
							rows=1;
							columns=2;
							strings[]=
							{
								"\a3\3DEN\Data\Attributes\Shape\rectangle_ca.paa",
								"\a3\3DEN\Data\Attributes\Shape\ellipse_ca.paa"
							};
							tooltips[]=
							{
								"$STR_3den_attributes_shapetrigger_rectangle",
								"$STR_3den_attributes_shapetrigger_ellipse"
							};
						};
						class BrushLabel: ShapeLabel
						{
							text="$STR_3DEN_Marker_Attribute_Brush_displayName";
							tooltip="$STR_3DEN_Marker_Attribute_Brush_tooltip";
							y="((3.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class Brush: zen_common_RscCombo
						{
							idc=42876;
							x="((12) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((3.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((11) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
						class ColorLabel: BrushLabel
						{
							text="$STR_3DEN_Marker_Attribute_Color_displayName";
							tooltip="$STR_3DEN_Marker_Attribute_Color_tooltip";
							y="((4.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class Color: Brush
						{
							idc=42877;
							y="((4.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class AlphaLabel: BrushLabel
						{
							text="$STR_3DEN_Marker_Attribute_Alpha_displayName";
							tooltip="";
							y="((5.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class AlphaSlider: ctrlXSliderH
						{
							idc=42878;
							x="((12) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((5.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((8.7) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class AlphaEdit: zen_common_RscEdit
						{
							idc=42879;
							x="((20.8) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((5.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + pixelH";
							w="((2.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
							colorBackground[]={0,0,0,0.40000001};
						};
					};
				};
				class ButtonOK: RscButtonMenuOK
				{
					idc=42880;
					x="((22) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((12) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((5) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class ButtonCancel: RscButtonMenuCancel
				{
					idc=42881;
					x=0;
					y="((12) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((5) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
			};
		};
	};
};
