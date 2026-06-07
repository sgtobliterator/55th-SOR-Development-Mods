class RscEdit;
class RscText;
class RscTree;
class ctrlActivePictureKeepAspect;
class ctrlButton;
class ctrlButtonCancel;
class ctrlButtonClose;
class ctrlButtonCollapseAll;
class ctrlButtonExpandAll;
class ctrlButtonOK;
class ctrlButtonPictureKeepAspect;
class ctrlButtonSearch;
class ctrlButtonToolbar;
class ctrlCheckbox;
class ctrlCheckboxToolbar;
class ctrlCombo;
class ctrlControlsGroup;
class ctrlControlsGroupNoScrollbars;
class ctrlEdit;
class ctrlEditMulti;
class ctrlListbox;
class ctrlListNBox;
class ctrlMap;
class ctrlMenu;
class ctrlMenuStrip;
class ctrlProgress;
class ctrlShortcutButtonSteam;
class ctrlStatic;
class ctrlStaticBackground;
class ctrlStaticBackgroundDisable;
class ctrlStaticBackgroundDisableTiles;
class ctrlStaticFooter;
class ctrlStaticFrame;
class ctrlStaticMulti;
class ctrlStaticOverlay;
class ctrlStaticPicture;
class ctrlStaticPictureKeepAspect;
class ctrlStaticTitle;
class ctrlStructuredText;
class ctrlToolbox;
class ctrlToolboxPictureKeepAspect;
class ctrlTree;
class ctrlXSliderH;
class scrollbar;
class ENH_ctrlButtonHelp: ctrlButtonPictureKeepAspect
{
	idc=-1;
	text="\a3\3den\data\displays\display3den\toolbar\help_tutorial_ca.paa";
	x=0;
	y=0;
	w="5 * (pixelW * pixelGrid * 0.50)";
	h="(5 * (pixelH * pixelGrid * 0.50))";
	onLoad="(_this#0) ctrlSetURLOverlayMode 1";
};
class ENH_3DEN_Attribute_Control_SideToolbox: ctrlToolboxPictureKeepAspect
{
	x="48 * (pixelW * pixelGrid * 0.50)";
	w="82 * (pixelW * pixelGrid * 0.50)";
	h="2 * (5 * (pixelH * pixelGrid * 0.50))";
	rows=1;
	columns=4;
	strings[]=
	{
		"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_west_ca.paa",
		"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_east_ca.paa",
		"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_guer_ca.paa",
		"\a3\3DEN\Data\Displays\Display3DEN\PanelRight\side_civ_ca.paa"
	};
	tooltips[]=
	{
		"$STR_WEST",
		"$STR_EAST",
		"$STR_GUERRILA",
		"$STR_CIVILIAN"
	};
	values[]={0,1,2,3};
};
class ENH_3DEN_Attribute_Control_ResetButton: ctrlButton
{
	idc=5;
	x="48 * (pixelW * pixelGrid * 0.50)";
	w="82 * (pixelW * pixelGrid * 0.50)";
	h="(5 * (pixelH * pixelGrid * 0.50))";
	text="$STR_ENH_MAIN_RESETANDDISABLE";
};
class ENH_3DEN_Attribute_Control_AttributeTitle: ctrlStatic
{
	style=1;
};
class ENH_3DEN_Attribute_Control_TitleX: ctrlStatic
{
	text="$STR_3DEN_AXIS_X";
	style=2;
	shadow=0;
	x="48 * (pixelW * pixelGrid * 0.50)";
	w="5 * (pixelW * pixelGrid * 0.50)";
	h="(5 * (pixelH * pixelGrid * 0.50))";
	colorBackground[]={0.76999998,0.18000001,0.1,1};
};
class ENH_3DEN_Attribute_Control_TitleY: ENH_3DEN_Attribute_Control_TitleX
{
	text="$STR_3DEN_AXIS_Y";
	x="(48 + 82 * (1 / 3)) * (pixelW * pixelGrid * 0.50)";
	colorBackground[]={0.57999998,0.81999999,0.22,1};
};
class ENH_3DEN_Attribute_Control_TitleZ: ENH_3DEN_Attribute_Control_TitleX
{
	text="$STR_3DEN_AXIS_Z";
	x="(48 + 82 * (2 / 3)) * (pixelW * pixelGrid * 0.50)";
	colorBackground[]={0.25999999,0.51999998,0.92000002,1};
};
class ENH_3DEN_Attribute_Control_ValueX: ctrlEdit
{
	text="0";
	x="(48 + 5) * (pixelW * pixelGrid * 0.50)";
	w="(82 / 3 - 5) * (pixelW * pixelGrid * 0.50)";
	h="(5 * (pixelH * pixelGrid * 0.50))";
	font="EtelkaMonospacePro";
	sizeEx="3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
};
class ENH_3DEN_Attribute_Control_ValueY: ENH_3DEN_Attribute_Control_ValueX
{
	x="(48 +82 * (1 / 3) +5) * (pixelW * pixelGrid * 0.50)";
};
class ENH_3DEN_Attribute_Control_ValueZ: ENH_3DEN_Attribute_Control_ValueX
{
	x="(48 +82 * (2 / 3) +5) * (pixelW * pixelGrid * 0.50)";
};
class ENH_3DEN_Attribute_Control_TitleA: ctrlStatic
{
	text="$STR_3DEN_AXIS_A";
	style=2;
	shadow=0;
	x="48 * (pixelW * pixelGrid * 0.50)";
	w="5 * (pixelW * pixelGrid * 0.50)";
	h="(5 * (pixelH * pixelGrid * 0.50))";
	colorText[]={1,1,1,1};
	colorBackground[]={0.76999998,0.18000001,0.1,1};
};
class ENH_3DEN_Attribute_Control_TitleB: ENH_3DEN_Attribute_Control_TitleA
{
	text="$STR_3DEN_AXIS_B";
	x="(48 + 82 * (1 / 3)) * (pixelW * pixelGrid * 0.50)";
	colorBackground[]={0.57999998,0.81999999,0.22,1};
};
class ENH_3DEN_Attribute_Control_TitleR: ENH_3DEN_Attribute_Control_TitleA
{
	text="$STR_ENH_BASE_CONTROLS_TITLE_R";
	x="48 * (pixelW * pixelGrid * 0.50)";
	colorBackground[]={0.92000002,0.27000001,1,0.44};
};
class ENH_3DEN_Attribute_Control_TitleAltitude: ENH_3DEN_Attribute_Control_TitleA
{
	text="$STR_ENH_BASE_CONTROLS_TITLE_A";
	x="48 * (pixelW * pixelGrid * 0.50)";
	colorBackground[]={1,0.44999999,0.23999999,1};
};
class ENH_3DEN_Attribute_Control_ValueA: ctrlEdit
{
	text="0";
	x="(48 + 5) * (pixelW * pixelGrid * 0.50)";
	w="(82 / 3 -5) * (pixelW * pixelGrid * 0.50)";
	h="(5 * (pixelH * pixelGrid * 0.50))";
	font="EtelkaMonospacePro";
	sizeEx="3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
};
class ENH_3DEN_Attribute_Control_ValueB: ENH_3DEN_Attribute_Control_ValueA
{
	x="(48 + 82 * (1 / 3) +5) * (pixelW * pixelGrid * 0.50)";
};
class ENH_3DEN_Attribute_Control_TitleZ_Front: ENH_3DEN_Attribute_Control_TitleZ
{
	x="48 * (pixelW * pixelGrid * 0.50)";
};
class ENH_3DEN_Attribute_Control_ValueZ_Front: ENH_3DEN_Attribute_Control_ValueZ
{
	x="(48 + 5) * (pixelW * pixelGrid * 0.50)";
};
class ENH_3DEN_Attribute_Control_TitleMin: ctrlStatic
{
	text="$STR_3DEN_ATTRIBUTES_TIMEOUT_TITLEMIN_TEXT";
	style=1;
	shadow=0;
	x="48 * (pixelW * pixelGrid * 0.50)";
	w="5 * 2 * (pixelW * pixelGrid * 0.50)";
	h="(5 * (pixelH * pixelGrid * 0.50))";
	colorText[]={1,1,1,1};
	colorBackground[]={1,1,1,0};
};
class ENH_3DEN_Attribute_Control_TitleMid: ENH_3DEN_Attribute_Control_TitleMin
{
	text="$STR_3DEN_ATTRIBUTES_TIMEOUT_TITLEMID_TEXT";
	x="(48 + 82 * (1 / 3)) * (pixelW * pixelGrid * 0.50)";
};
class ENH_3DEN_Attribute_Control_TitleMax: ENH_3DEN_Attribute_Control_TitleMin
{
	text="$STR_3DEN_ATTRIBUTES_TIMEOUT_TITLEMAX_TEXT";
	x="(48 +82 * (2 / 3)) * (pixelW * pixelGrid * 0.50)";
};
class ENH_3DEN_Attribute_Control_ValueMin: ctrlEdit
{
	x="(48 +(5 * 2)) * (pixelW * pixelGrid * 0.50)";
	w="(82 / 3 - 2 * 5) * (pixelW * pixelGrid * 0.50)";
	h="(5 * (pixelH * pixelGrid * 0.50))";
	font="EtelkaMonospacePro";
	sizeEx="3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
};
class ENH_3DEN_Attribute_Control_ValueMid: ENH_3DEN_Attribute_Control_ValueMin
{
	x="(48 +82 * (1 / 3) +(5 * 2)) * (pixelW * pixelGrid * 0.50)";
};
class ENH_3DEN_Attribute_Control_ValueMax: ENH_3DEN_Attribute_Control_ValueMin
{
	x="(48 +82 * (2 / 3) +(5 * 2)) * (pixelW * pixelGrid * 0.50)";
};
class ENH_3DEN_Attribute_Control_ValueFromClipboard: ctrlButtonPictureKeepAspect
{
	idc=-1;
	text="\x\enh\addons\main\data\clipboard_ca.paa";
	tooltip="$STR_ENH_BUTTON_PASTE_ARRAY_FROM_CLIPBOARD";
	x="(48 + 82 - 5) * (pixelW * pixelGrid * 0.50)";
	y=0;
	w="5 * (pixelW * pixelGrid * 0.50)";
	h="(5 * (pixelH * pixelGrid * 0.50))";
};
class ENH_3DEN_Attribute_Control_EditMulti5_Title: ctrlStaticFrame
{
	x="5 * (pixelW * pixelGrid * 0.50)";
	y=0;
	w="(48 + 82 - 5) * (pixelW * pixelGrid * 0.50)";
	h="5 * (5 * (pixelH * pixelGrid * 0.50))";
	colorBackground[]={0,0,0,0.5};
};
class ENH_3DEN_Attribute_Control_EditMulti5_Background: ctrlStaticOverlay
{
	x="5 * (pixelW * pixelGrid * 0.50)";
	y="2 * (pixelH * pixelGrid * 0.50)";
	w="(48 + 82 - 5) * (pixelW * pixelGrid * 0.50)";
	h="5 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
};
class ENH_3DEN_Attribute_Control_EditMulti5_Edit: ctrlEdit
{
	x="5 * (pixelW * pixelGrid * 0.50)";
	y="5 * (pixelH * pixelGrid * 0.50)";
	w="(48 + 82 - 5) * (pixelW * pixelGrid * 0.50)";
	h="5 * (5 * (pixelH * pixelGrid * 0.50)) - 6 * (pixelH * pixelGrid * 0.50)";
	style="0x10 + 0x200";
	colorBackground[]={0,0,0,0};
};
class ENH_3DENMinimap: ctrlMap
{
	scaleMax=3;
};
class CfgPatches
{
	class 3denEnhanced_CaptureFrameUI
	{
		author="R3vo";
		name="3den Enhanced - Capture Frame UI";
		requiredAddons[]=
		{
			"3denEnhanced"
		};
		requiredVersion=2.1800001;
		url="https://steamcommunity.com/sharedfiles/filedetails/?id=623475643";
		units[]={};
		weapons[]={};
	};
};
class RscDisplayCapture
{
	class Controls
	{
		class Index: RscTree
		{
			idcSearch=1337;
		};
		class Title: RscText
		{
			moving=0;
		};
		class Background: RscText
		{
			moving=0;
		};
		class SearchEditTree: RscEdit
		{
			idc=1337;
			x="(((safeZoneW / safeZoneH) min 1.2) / 40) + (safeZoneX) + 4 * (((safeZoneW / safeZoneH) min 1.2) / 40)";
			y="safeZoneY + 11.3 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)";
			w="10 * (((safeZoneW / safeZoneH) min 1.2) / 40)";
			h="((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonCollapseAll: ctrlButtonCollapseAll
		{
			x="(((safeZoneW / safeZoneH) min 1.2) / 40) + (safeZoneX) + 5 * (((safeZoneW / safeZoneH) min 1.2) / 40) + 10 * (((safeZoneW / safeZoneH) min 1.2) / 40)";
			y="safeZoneY + 11.3 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)";
			w="(((safeZoneW / safeZoneH) min 1.2) / 40)";
			h="((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)";
			onButtonClick="tvCollapseAll (ctrlParent (_this#0) displayCtrl 101)";
		};
		class ButtonExpandAll: ctrlButtonExpandAll
		{
			x="(((safeZoneW / safeZoneH) min 1.2) / 40) + (safeZoneX) + 5 * (((safeZoneW / safeZoneH) min 1.2) / 40) + 11 * (((safeZoneW / safeZoneH) min 1.2) / 40)";
			y="safeZoneY + 11.3 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)";
			w="(((safeZoneW / safeZoneH) min 1.2) / 40)";
			h="((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)";
			onButtonClick="tvExpandAll (ctrlParent (_this#0) displayCtrl 101)";
		};
		class ButtonPreviousData;
		class ButtonOpenPerfetto: ButtonPreviousData
		{
			idc=-1;
			text="Open Perfetto...";
			x="39.11 * (((safeZoneW / safeZoneH) min 1.2) / 40) + (safeZoneX)";
			url="https://ui.perfetto.dev/";
		};
	};
	class ControlsBackground
	{
		class Background: RscText
		{
			x="safeZoneX";
			y="safeZoneY";
			w="safeZoneW";
			h="safeZoneH";
			colorBackground[]={0.1,0.1,0.1,1};
		};
	};
};
