class ScrollBar;
class RscObject;
class RscText;
class RscTextSmall;
class RscTitle;
class RscProgress;
class RscProgressNotFreeze;
class RscPicture;
class RscLadderPicture;
class RscPictureKeepAspect;
class RscHTML;
class RscButton;
class RscShortcutButton;
class RscButtonSmall;
class RscEdit;
class RscCombo;
class RscListBox;
class RscListNBox;
class RscXListBox;
class RscTree;
class RscSlider;
class RscSliderH;
class RscXSliderH;
class RscActiveText;
class RscStructuredText;
class RscControlsGroup;
class RscBackgroundStripeTop;
class RscBackgroundStripeBottom;
class RscToolbox;
class RscMapControl;
class RscCheckBox;
class RscIGText;
class RscIGProgress;
class RscListBoxKeys;
class RscControlsGroupNoScrollbars;
class RscControlsGroupNoHScrollbars;
class RscControlsGroupNoVScrollbars;
class RscLine;
class RscActivePicture;
class RscButtonTextOnly;
class RscShortcutButtonMain;
class RscButtonEditor;
class RscIGUIShortcutButton;
class RscGearShortcutButton;
class RscButtonMenu;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscButtonMenuSteam;
class RscLoadingText;
class RscIGUIListBox;
class RscIGUIListNBox;
class RscFrame;
class RscBackground;
class RscBackgroundGUI;
class RscBackgroundGUILeft;
class RscBackgroundGUIRight;
class RscBackgroundGUIBottom;
class RscBackgroundGUITop;
class RscBackgroundGUIDark;
class RscBackgroundLogo;
class RscMapControlEmpty;
class RscVignette;
class RscTextMulti;
class RscTreeSearch;
class RscPictureAllowPixelSplit;
class RscPictureKeepAspectAllowPixelSplit;
class RscVideo;
class RscVideoKeepAspect;
class RscActivePictureKeepAspect;
class RscButtonMenuBIKI;
class RscListBoxMulti;
class RscEditMulti;
class RscEditReadOnly;
class RscEditMultiReadOnly;
class RscMapSignalBackground;
class RscMapSignalPicture;
class RscMapSignalText;
class RscColorPicker;
class RscInterlacingScreen;
class RscFeedback;
class RscTrafficLight;
class RscButtonSearch;
class RscIGUIText;
class RscOpticsText;
class RscOpticsValue;
class RscIGUIValue;
class RscButtonMenuMain;
class RscButtonTestCentered;
class RscDisplaySingleMission_ChallengeOverviewGroup;
class RscDisplayDebriefing_RscTextMultiline;
class RscDisplayDebriefing_ListGroup;
class RscButtonArsenal;
class RscTextNoShadow;
class RscButtonNoColor;
class RscToolboxButton;
class RscButtonCall;
class RscButtonAlarm;
class RscButtonDetector;
class RscButtonDiaryMenu;
class RscControlsTable;
class CA_Mainback;
class CA_Back;
class CA_Title_Back;
class CA_Black_Back;
class CA_Title;
class CA_Logo;
class CA_Logo_Small;
class CA_RscButton;
class CA_RscButton_dialog;
class CA_Ok;
class CA_Ok_image;
class CA_Ok_image2;
class CA_Ok_text;
class ctrlDefault;
class ctrlDefaultText;
class ctrlDefaultButton;
class ctrlCheckbox;
class ctrlCheckboxBaseline;
class ctrlActiveText;
class ctrlActivePicture;
class ctrlStatic;
class ctrlControlsGroup;
class ctrlControlsGroupNoHScrollbars;
class ctrlControlsGroupNoVScrollbars;
class ctrlControlsGroupNoScrollbars;
class ctrlStructuredText;
class ctrlStaticPicture;
class ctrlStaticPictureKeepAspect;
class ctrlStaticPictureTile;
class ctrlStaticFrame;
class ctrlStaticLine;
class ctrlStaticMulti;
class ctrlStaticBackground;
class ctrlStaticOverlay;
class ctrlStaticTitle;
class ctrlStaticFooter;
class ctrlStaticBackgroundDisable;
class ctrlStaticBackgroundDisableTiles;
class ctrlButton;
class ctrlButtonPicture;
class ctrlButtonPictureKeepAspect;
class ctrlButtonOK;
class ctrlButtonCancel;
class ctrlButtonClose;
class ctrlButtonToolbar;
class ctrlButtonSearch;
class ctrlButtonExpandAll;
class ctrlButtonCollapseAll;
class ctrlButtonFilter;
class ctrlEdit;
class ctrlEditMulti;
class ctrlSliderV;
class ctrlSliderH;
class ctrlCombo;
class ctrlComboToolbar;
class ctrlListbox;
class ctrlToolbox;
class ctrlToolboxPicture;
class ctrlToolboxPictureKeepAspect;
class ctrlCheckboxes;
class ctrlCheckboxesCheckbox;
class ctrlProgress;
class ctrlHTML;
class ctrlActivePictureKeepAspect;
class ctrlTree;
class ctrlShortcutButton;
class ctrlShortcutButtonOK;
class ctrlShortcutButtonCancel;
class ctrlShortcutButtonSteam;
class ctrlXListbox;
class ctrlXSliderV;
class ctrlXSliderH;
class ctrlMenu;
class ctrlMenuStrip;
class ctrlMap;
class ctrlMapEmpty;
class ctrlMapMain;
class ctrlListNBox;
class ctrlCheckboxToolbar;
class controls;
class VScrollbar;
class HScrollbar;
class FOD_ZA_RscControlsGroupNoScrollbars: RscControlsGroupNoScrollbars
{
	class VScrollbar: VScrollbar
	{
		width=0;
	};
	class HScrollbar: HScrollbar
	{
		height=0;
	};
};
class FOD_ZA_RscCombo: RscCombo
{
	deletable=0;
	fade=0;
	access=0;
	type=4;
	colorSelect[]={0,0,0,1};
	colorText[]={1,1,1,1};
	colorBackground[]={0,0,0,1};
	colorScrollbar[]={1,0,0,1};
	colorDisabled[]={1,1,1,0.25};
	colorPicture[]={1,1,1,1};
	colorPictureSelected[]={1,1,1,1};
	colorPictureDisabled[]={1,1,1,0.25};
	colorPictureRight[]={1,1,1,1};
	colorPictureRightSelected[]={1,1,1,1};
	colorPictureRightDisabled[]={1,1,1,0.25};
	colorTextRight[]={1,1,1,1};
	colorSelectRight[]={0,0,0,1};
	colorSelect2Right[]={0,0,0,1};
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={1,1,1,1};
	tooltipColorShade[]={0,0,0,0.64999998};
	soundSelect[]=
	{
		"\A3\ui_f\data\sound\RscCombo\soundSelect",
		0.1,
		1
	};
	soundExpand[]=
	{
		"\A3\ui_f\data\sound\RscCombo\soundExpand",
		0.1,
		1
	};
	soundCollapse[]=
	{
		"\A3\ui_f\data\sound\RscCombo\soundCollapse",
		0.1,
		1
	};
	maxHistoryDelay=1;
	class ComboScrollBar: ScrollBar
	{
		color[]={1,1,1,1};
	};
	style="0x10 + 0x200";
	font="RobotoCondensed";
	sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow=0;
	x=0;
	y=0;
	w=0.12;
	h=0.035;
	colorSelectBackground[]={1,1,1,0.69999999};
	arrowEmpty="\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa";
	arrowFull="\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa";
	wholeHeight=0.44999999;
	colorActive[]={1,0,0,1};
};
class FOD_ZA_ctrlButtonPictureKeepAspect: ctrlButtonPictureKeepAspect
{
	style="0x02 + 0x10 + 0x20 + 0x800";
};
class RscDisplayName
{
	idd=1234;
	class ControlsBackground
	{
		class Background: RscText
		{
			idc=-1;
			x="GUI_GRID_CENTER_X";
			y="GUI_GRID_CENTER_Y";
			w="40 * GUI_GRID_CENTER_W";
			h="25 * GUI_GRID_CENTER_H";
			colorBackground[]={0,0,0,0.80000001};
		};
	};
	class Controls
	{
		class ClickMe: RscButton
		{
			idc=-1;
			text="Click Me!";
			onButtonClick="hint 'You clicked the button!';";
			x="GUI_GRID_CENTER_X + 10 * GUI_GRID_CENTER_W";
			y="GUI_GRID_CENTER_Y + 12 * GUI_GRID_CENTER_H";
			w="20 * GUI_GRID_CENTER_W";
			h="1 * GUI_GRID_CENTER_H";
		};
	};
};
class CfgPatches
{
	class FOD_ZA
	{
		name="[Forges of Dorn] Zeus Additions";
		author="Phenosi, Basipek Bus";
		url="https://discord.gg/KY9seJDnWK";
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Functions_F",
			"A3_Modules_F",
			"A3_Structures_F_Exp_Civilian",
			"zen_context_menu",
			"zen_attributes",
			"zen_custom_modules",
			"cba_main",
			"A3_Ui_F",
			"3DEN",
			"A3_3DEN",
			"A3_Functions_F_Mark",
			"A3_Data_F_Decade_Loadorder"
		};
		units[]=
		{
			"PHEN_ModuleGarageInit",
			"FOD_ZA_ModuleSpawnAIGroup",
			"FOD_ZA_ModuleDefenseOP",
			"FOD_ZA_ModuleGarrisonVanilla",
			"FOD_ZA_ModuleTacticalPush",
			"FOD_ZA_ModuleMobilizeQRF",
			"FOD_ZA_ModuleSupportVehicle",
			"FOD_ZA_ModuleReserveQRF",
			"FOD_ZA_ModuleHitAndRun",
			"FOD_ZA_ModuleSetupAmbush"
		};
		weapons[]={};
	};
};
class CfgFunctions
{
	class kbf
	{
		class functions
		{
			file="\FOD_ZA\functions\Vehicle_Garage\kbf";
			class vehDamage
			{
			};
			class garageLoad
			{
			};
			class garageInit
			{
			};
			class ModuleGarageInit
			{
			};
		};
	};
	class A3_Mark_Modified
	{
		tag="PHEN";
		class Vehicles
		{
			file="\FOD_ZA\functions\Vehicle_Garage";
			class garage
			{
			};
			class garage3DEN
			{
			};
		};
	};
	class BBUS_vehiclearsenal
	{
		file="\FOD_ZA\functions";
		class vehiclearsenal
		{
			class addArsenalInit;
		};
	};
	class FOD_ZA_Modules
	{
		tag="FOD_ZA";
		class SpawnGroup
		{
			file="\FOD_ZA\functions";
			class ModuleSpawnAIGroup
			{
			};
		};
		class DefenseOP
		{
			file="\FOD_ZA\functions";
			class ModuleDefenseOP
			{
			};
		};
		class GarrisonVanilla
		{
			file="\FOD_ZA\functions";
			class ModuleGarrisonVanilla
			{
			};
		};
		class TacticalPush
		{
			file="\FOD_ZA\functions";
			class ModuleTacticalPush
			{
			};
		};
		class MobilizeQRF
		{
			file="\FOD_ZA\functions";
			class ModuleMobilizeQRF
			{
			};
		};
		class SupportVehicle
		{
			file="\FOD_ZA\functions";
			class ModuleSupportVehicle
			{
			};
		};
		class ReserveQRF
		{
			file="\FOD_ZA\functions";
			class ModuleReserveQRF
			{
			};
		};
		class HitAndRun
		{
			file="\FOD_ZA\functions";
			class ModuleHitAndRun
			{
			};
		};
		class SetupAmbush
		{
			file="\FOD_ZA\functions";
			class ModuleSetupAmbush
			{
			};
		};
	};
};
class CfgRemoteExec
{
	class Functions
	{
		class FOD_ZA_fnc_taskTacticalPushToggle
		{
			allowedTargets=2;
		};
		class FOD_ZA_fnc_taskSupportVehicleToggle
		{
			allowedTargets=2;
		};
		class FOD_ZA_fnc_curatorFeedbackShow
		{
			allowedTargets=2;
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class FOD_ZA_PreInit
	{
		init="call compile preprocessFileLineNumbers 'FOD_ZA\Bootstrap\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class FOD_ZA_PostInit
	{
		init="call compile preprocessFileLineNumbers 'FOD_ZA\Bootstrap\XEH_postInit.sqf'";
	};
};
class RscMessageBox: RscControlsGroupNoScrollbars
{
	idc=2351;
	x=-1;
	y=-1;
	w=0;
	h=0;
	class Controls
	{
		class BcgCommonTop: RscBackgroundGUITop
		{
			idc=235100;
			x=0;
			y=0;
			w="18.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]=
			{
				"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
				1
			};
		};
		class BcgCommon: RscBackgroundGUI
		{
			idc=235101;
			x=0;
			y="1.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="18.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,1};
		};
		class Text: RscStructuredText
		{
			idc=235102;
			x="0.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="1.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="17 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundButtonOK: RscBackgroundGUI
		{
			idc=235103;
			x=0;
			y="2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="6.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,1};
		};
		class BackgroundButtonMiddle: BackgroundButtonOK
		{
			idc=235104;
			x="6.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		class BackgroundButtonCancel: BackgroundButtonOK
		{
			idc=235105;
			x="12.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		class ButtonOK: RscButtonMenuOK
		{
			default=1;
			idc=235106;
			colorBackground[]={0,0,0,1};
			x=0;
			y="2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="6.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			idc=235107;
			colorBackground[]={0,0,0,1};
			x="12.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="2.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="6.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};
class BIS_RscDisplayGarage
{
	idd=-1;
	enableSimulation=1;
	scriptName="RscDisplayGarage";
	scriptPath="GUI";
	onLoad="[""onLoad"",_this,""RscDisplayGarage"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload="[""onUnload"",_this,""RscDisplayGarage"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	icon="\A3\Ui_f\data\Logos\a_64_ca.paa";
	logo="\A3\Ui_f\data\Logos\arsenal_1024_ca.paa";
	class ControlsBackground
	{
		class BlackLeft: RscText
		{
			colorBackground[]={0,0,0,1};
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneXAbs - safezoneX";
			h="safezoneH";
		};
		class BlackRight: BlackLeft
		{
			x="safezoneX + safezoneW";
		};
		class MouseArea: RscText
		{
			idc=899;
			style=16;
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="safezoneH";
		};
	};
	class Controls
	{
		class ArrowLeft: RscButton
		{
			idc=992;
			text="-";
			x=-1;
			y=-1;
			w="1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ArrowRight: ArrowLeft
		{
			idc=993;
			text="+";
			x=-1;
			y=-1;
			w="1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundLeft: RscText
		{
			fade=1;
			idc=994;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0.5};
		};
		class BackgroundRight: BackgroundLeft
		{
			idc=995;
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		class LineIcon: RscFrame
		{
			fade=1;
			idc=1803;
			x=-1;
			y=-1;
			w=0;
			h=0;
			colorText[]={0,0,0,1};
		};
		class LineTabLeft: RscText
		{
			fade=1;
			idc=1804;
			x=-1;
			y=-1;
			w="0.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,1};
		};
		class LineTabLeftSelected: RscText
		{
			idc=1805;
			x="safezoneX";
			y=-1;
			w="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0.80000001};
		};
		class LineTabRight: LineTabLeft
		{
			idc=1806;
		};
		class Tabs: RscFrame
		{
			fade=1;
			idc=1800;
			x="safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="1.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="40 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[]={0,0,0,0};
		};
		class FrameLeft: RscFrame
		{
			fade=1;
			idc=1801;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[]={0,0,0,1};
		};
		class FrameRight: FrameLeft
		{
			fade=1;
			idc=1802;
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		class Load: RscProgress
		{
			fade=1;
			idc=990;
			style=0;
			texture="#(argb,8,8,3)color(1,1,1,1)";
			colorBar[]={1,1,1,1};
			colorFrame[]={0,0,0,1};
			x="safezoneX";
			y="safezoneY + safezoneH - 0.0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="safezoneW";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class LoadCargo: Load
		{
			fade=1;
			idc=991;
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + safezoneH - 11.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Message: RscText
		{
			fade=1;
			idc=996;
			x="safezoneX + (0.5 * safezoneW) - (0.5 * ((safezoneW - 36 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) max 0.4))";
			y="21.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w="((safezoneW - 36 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) max 0.4)";
			h="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0.69999999};
			style=2;
			shadow=0;
			text="";
			sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Space: RscControlsGroup
		{
			x="safezoneX + safezoneW * 0.5 - 4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY";
			show=0;
			idc=27903;
			w="8.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class SpaceArsenalBackground: RscText
				{
					idc=26603;
					x="0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.69999999};
				};
				class SpaceArsenal: RscActivePicture
				{
					idc=26803;
					text="\a3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\spaceArsenal_ca.paa";
					x="1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip="$STR_A3_Arsenal";
				};
				class SpaceGarageBackground: SpaceArsenalBackground
				{
					idc=26604;
					x="4.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.69999999};
				};
				class SpaceGarage: SpaceArsenal
				{
					idc=26804;
					text="\a3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\spaceGarage_ca.paa";
					x="5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="1.99996 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip="$STR_A3_Garage";
				};
			};
		};
		class ControlBar: RscControlsGroupNoScrollbars
		{
			w="safezoneW";
			idc=44046;
			x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y="23.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class ButtonClose: RscButtonMenu
				{
					idc=44448;
					text="$STR_DISP_CLOSE";
					x="0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.2) - 0.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					shortcuts[]=
					{
						"0x00050000 + 1"
					};
					tooltip="$STR_A3_RscDisplayGarage_ButtonClose_tooltip";
				};
				class ButtonInterface: ButtonClose
				{
					idc=44151;
					text="$STR_CA_HIDE";
					x="2 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					w="((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1) - 0.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					tooltip="$STR_A3_RscDisplayArsenal_ButtonInterface_tooltip";
				};
				class ButtonRandom: ButtonInterface
				{
					idc=44150;
					text="$STR_A3_RscDisplayArsenal_ButtonRandom";
					x="3 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonRandom_tooltip";
				};
				class ButtonSave: ButtonInterface
				{
					idc=44146;
					text="$STR_DISP_INT_SAVE";
					x="4 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonSave_tooltip";
				};
				class ButtonLoad: ButtonInterface
				{
					idc=44147;
					text="$STR_DISP_INT_LOAD";
					x="5 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonLoad_tooltip";
				};
				class ButtonExport: ButtonInterface
				{
					idc=44148;
					text="$STR_A3_RscDisplayArsenal_ButtonExport";
					x="6 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonExport_tooltip";
				};
				class ButtonImport: ButtonInterface
				{
					idc=44149;
					text="$STR_A3_RscDisplayArsenal_ButtonImport";
					x="7 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonImport_tooltip";
				};
				class ButtonTry: ButtonInterface
				{
					idc=44347;
					text="$STR_A3_RscDisplayArsenal_ButtonOK";
					x="8 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonTry_tooltip";
					shortcuts[]=
					{
						"0x00050000 + 0",
						28,
						57,
						156
					};
				};
				class ButtonOK: ButtonInterface
				{
					idc=44346;
					text="$STR_DISP_CLOSE";
					x="9 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonOK_tooltip";
				};
			};
		};
		class Info: RscControlsGroup
		{
			x="safezoneX + safezoneW - 20.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + safezoneH - 4.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			fade=1;
			idc=25815;
			w="17.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class InfoBackground: RscText
				{
					idc=24515;
					x="2.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,1};
				};
				class InfoName: RscText
				{
					idc=24516;
					x="2.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class InfoAuthor: RscText
				{
					idc=24517;
					x="2.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={1,1,1,0.5};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class DLCBackground: RscText
				{
					fade=1;
					idc=24518;
					x="0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="2.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.5};
				};
				class DLCIcon: RscActivePicture
				{
					enabled=0;
					fade=1;
					color[]={1,1,1,1};
					colorActive[]={1,1,1,1};
					idc=24715;
					text="#(argb,8,8,3)color(1,1,1,1)";
					x="0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="2.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class Stats: RscControlsGroupNoScrollbars
		{
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + safezoneH - 10.6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			fade=1;
			enable=0;
			idc=28644;
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class StatsBackground: RscText
				{
					idc=27347;
					x="0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.5};
				};
				class Stat1: RscProgress
				{
					colorBar[]={1,1,1,1};
					colorFrame[]={0,0,0,0};
					idc=27348;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Stat2: Stat1
				{
					idc=27349;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Stat3: Stat1
				{
					idc=27350;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Stat4: Stat1
				{
					idc=27351;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="3.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Stat5: Stat1
				{
					idc=27352;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="4.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class StatText1: RscText
				{
					shadow=0;
					colorShadow[]={1,1,1,1};
					idc=27353;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={0,0,0,1};
					colorBackground[]={1,1,1,0.1};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class StatText2: StatText1
				{
					idc=27354;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={0,0,0,1};
					colorBackground[]={1,1,1,0.1};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class StatText3: StatText1
				{
					idc=27355;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={0,0,0,1};
					colorBackground[]={1,1,1,0.1};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class StatText4: StatText1
				{
					idc=27356;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="3.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={0,0,0,1};
					colorBackground[]={1,1,1,0.1};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class StatText5: StatText1
				{
					idc=27357;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="4.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={0,0,0,1};
					colorBackground[]={1,1,1,0.1};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class MouseBlock: RscText
		{
			idc=898;
			style=16;
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="safezoneH";
		};
		class Template: RscControlsGroup
		{
			fade=1;
			idc=35919;
			x="10 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="0.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="20 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="22.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class Title: RscTitle
				{
					style=0;
					colorBackground[]=
					{
						"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
					};
					idc=34619;
					text="";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="20 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class MainBackground: RscText
				{
					idc=34622;
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="20 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="20 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.80000001};
				};
				class Column1: RscText
				{
					idc=34620;
					x="0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={1,1,1,0.2};
				};
				class Column2: RscText
				{
					idc=34623;
					x="9.05 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={1,1,1,0.1};
				};
				class Column3: RscText
				{
					idc=34624;
					x="12.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={1,1,1,0.1};
				};
				class Column4: RscText
				{
					idc=34625;
					x="15.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="0.95 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={1,1,1,0.1};
				};
				class Column5: RscText
				{
					idc=34626;
					x="17.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="0.95 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={1,1,1,0.1};
				};
				class TextName: RscText
				{
					style=1;
					idc=34621;
					text="$STR_DISP_GAME_NAME";
					x="0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="19.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.2};
					sizeEx="0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class EditName: RscEdit
				{
					idc=35020;
					x="6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="19.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="13.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx="0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ValueName: RscListNBox
				{
					columns[]={0,0.44999999,0.55000001,0.64999998,0.75,0.80000001,0.85000002,0.89999998,0.94999999};
					idc=35119;
					x="0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx="0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ButtonOK: RscButtonMenu
				{
					idc=36019;
					text="$STR_DISP_OK";
					x="15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="21.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ButtonCancel: RscButtonMenu
				{
					idc=36020;
					text="$STR_DISP_CANCEL";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="21.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ButtonDelete: RscButtonMenu
				{
					idc=36021;
					text="$STR_DISP_DELETE";
					x="9.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="21.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class MessageBox: RscMessageBox
		{
		};
		class TabCar: RscButtonArsenal
		{
			idc="930 + 								0";
			idcx=930;
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\Car_ca.paa";
			x="safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 0.04 + 0 * 0.04";
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="(1.4 * 		2) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip="$STR_A3_RscDisplayGarage_tab_Car";
		};
		class IconCar: RscPicture
		{
			idc="900 + 								0";
			idcx=900;
			x=-1;
			y=-1;
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			color[]={1,1,1,0.80000001};
		};
		class ListCar: RscListBox
		{
			idc="960 + 							0";
			idcx=960;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListDisabledCar: RscText
		{
			idc="860 + 							0";
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			text="$STR_lib_info_na";
			style=2;
			show=0;
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
		class TabTank: RscButtonArsenal
		{
			idc="930 + 								1";
			idcx=931;
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\Tank_ca.paa";
			x="safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 0.04 + 3 * 0.04";
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="(1.4 * 		2) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip="$STR_A3_RscDisplayGarage_tab_Tank";
		};
		class IconTank: RscPicture
		{
			idc="900 + 								1";
			idcx=901;
			x=-1;
			y=-1;
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			color[]={1,1,1,0.80000001};
		};
		class ListTank: RscListBox
		{
			idc="960 + 							1";
			idcx=961;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListDisabledTank: RscText
		{
			idc="860 + 							1";
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			text="$STR_lib_info_na";
			style=2;
			show=0;
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
		class TabHelicopter: RscButtonArsenal
		{
			idc="930 + 							2";
			idcx=932;
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\Helicopter_ca.paa";
			x="safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 0.04 + 6 * 0.04";
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="(1.4 * 		2) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip="$STR_A3_RscDisplayGarage_tab_Helicopter";
		};
		class IconHelicopter: RscPicture
		{
			idc="900 + 							2";
			idcx=902;
			x=-1;
			y=-1;
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			color[]={1,1,1,0.80000001};
		};
		class ListHelicopter: RscListBox
		{
			idc="960 + 						2";
			idcx=962;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListDisabledHelicopter: RscText
		{
			idc="860 + 						2";
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			text="$STR_lib_info_na";
			style=2;
			show=0;
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
		class TabPlane: RscButtonArsenal
		{
			idc="930 + 								3";
			idcx=933;
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\Plane_ca.paa";
			x="safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 0.04 + 9 * 0.04";
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="(1.4 * 		2) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip="$STR_A3_RscDisplayGarage_tab_Plane";
		};
		class IconPlane: RscPicture
		{
			idc="900 + 								3";
			idcx=903;
			x=-1;
			y=-1;
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			color[]={1,1,1,0.80000001};
		};
		class ListPlane: RscListBox
		{
			idc="960 + 							3";
			idcx=963;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListDisabledPlane: RscText
		{
			idc="860 + 							3";
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			text="$STR_lib_info_na";
			style=2;
			show=0;
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
		class TabNaval: RscButtonArsenal
		{
			idc="930 + 								4";
			idcx=934;
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\Naval_ca.paa";
			x="safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 0.04 + 12 * 0.04";
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="(1.4 * 		2) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip="$STR_A3_RscDisplayGarage_tab_Naval";
		};
		class IconNaval: RscPicture
		{
			idc="900 + 								4";
			idcx=904;
			x=-1;
			y=-1;
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			color[]={1,1,1,0.80000001};
		};
		class ListNaval: RscListBox
		{
			idc="960 + 							4";
			idcx=964;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListDisabledNaval: RscText
		{
			idc="860 + 							4";
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			text="$STR_lib_info_na";
			style=2;
			show=0;
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
		class TabStatic: RscButtonArsenal
		{
			idc="930 + 							5";
			idcx=935;
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\Static_ca.paa";
			x="safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 0.04 + 15 * 0.04";
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="(1.4 * 		2) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip="$STR_A3_RscDisplayGarage_tab_Static";
		};
		class IconStatic: RscPicture
		{
			idc="900 + 							5";
			idcx=905;
			x=-1;
			y=-1;
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			color[]={1,1,1,0.80000001};
		};
		class ListStatic: RscListBox
		{
			idc="960 + 						5";
			idcx=965;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListDisabledStatic: RscText
		{
			idc="860 + 						5";
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			text="$STR_lib_info_na";
			style=2;
			show=0;
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
		class TabCrew: RscButtonArsenal
		{
			idc="930 + 							18";
			idcx=948;
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\Crew_ca.paa";
			x="safezoneX + safezoneW - 2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 0.04 + 0 * 0.04";
			w="(1.4 * 	1) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="(1.4 * 	1) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip="$STR_A3_RscDisplayGarage_tab_Crew";
		};
		class IconCrew: RscPicture
		{
			idc="900 + 							18";
			idcx=918;
			x=-1;
			y=-1;
			w="(1.4 * 	1) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			color[]={1,1,1,0.80000001};
		};
		class ListCrew: RscListBox
		{
			idc="960 + 						18";
			idcx=978;
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="15 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListDisabledCrew: RscText
		{
			idc="860 + 						18";
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="15 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			text="$STR_lib_info_na";
			style=2;
			show=0;
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
		class TabAnimationSources: RscButtonArsenal
		{
			idc="930 + 					19";
			idcx=949;
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\AnimationSources_ca.paa";
			x="safezoneX + safezoneW - 2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 0.04 + 1.5 * 0.04";
			w="(1.4 * 	1) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="(1.4 * 	1) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip="$STR_A3_RscDisplayGarage_tab_AnimationSources";
		};
		class IconAnimationSources: RscPicture
		{
			idc="900 + 					19";
			idcx=919;
			x=-1;
			y=-1;
			w="(1.4 * 	1) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			color[]={1,1,1,0.80000001};
		};
		class ListAnimationSources: RscListBox
		{
			idc="960 + 				19";
			idcx=979;
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="15 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListDisabledAnimationSources: RscText
		{
			idc="860 + 				19";
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="15 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			text="$STR_lib_info_na";
			style=2;
			show=0;
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
		class TabTextureSources: RscButtonArsenal
		{
			idc="930 + 					20";
			idcx=950;
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\TextureSources_ca.paa";
			x="safezoneX + safezoneW - 2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 0.04 + 3 * 0.04";
			w="(1.4 * 	1) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="(1.4 * 	1) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip="$STR_A3_RscDisplayGarage_tab_TextureSources";
		};
		class IconTextureSources: RscPicture
		{
			idc="900 + 					20";
			idcx=920;
			x=-1;
			y=-1;
			w="(1.4 * 	1) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			color[]={1,1,1,0.80000001};
		};
		class ListTextureSources: RscListBox
		{
			idc="960 + 				20";
			idcx=980;
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="15 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListDisabledTextureSources: RscText
		{
			idc="860 + 				20";
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="15 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			text="$STR_lib_info_na";
			style=2;
			show=0;
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
		delete TabPrimaryWeapon;
		delete IconPrimaryWeapon;
		delete ListPrimaryWeapon;
		delete TabSecondaryWeapon;
		delete IconSecondaryWeapon;
		delete ListSecondaryWeapon;
		delete TabHandgun;
		delete IconHandgun;
		delete ListHandgun;
		delete TabUniform;
		delete IconUniform;
		delete ListUniform;
		delete TabVest;
		delete IconVest;
		delete ListVest;
		delete TabBackpack;
		delete IconBackpack;
		delete ListBackpack;
		delete TabHeadgear;
		delete IconHeadgear;
		delete ListHeadgear;
		delete TabGoggles;
		delete IconGoggles;
		delete ListGoggles;
		delete TabNVGs;
		delete IconNVGs;
		delete ListNVGs;
		delete TabBinoculars;
		delete IconBinoculars;
		delete ListBinoculars;
		delete TabMap;
		delete IconMap;
		delete ListMap;
		delete TabGPS;
		delete IconGPS;
		delete ListGPS;
		delete TabRadio;
		delete IconRadio;
		delete ListRadio;
		delete TabCompass;
		delete IconCompass;
		delete ListCompass;
		delete TabWatch;
		delete IconWatch;
		delete ListWatch;
		delete TabFace;
		delete IconFace;
		delete ListFace;
		delete TabVoice;
		delete IconVoice;
		delete ListVoice;
		delete TabInsignia;
		delete IconInsignia;
		delete ListInsignia;
		delete TabItemOptic;
		delete IconItemOptic;
		delete ListItemOptic;
		delete TabItemAcc;
		delete IconItemAcc;
		delete ListItemAcc;
		delete TabItemMuzzle;
		delete IconItemMuzzle;
		delete ListItemMuzzle;
		delete TabCargoMag;
		delete IconCargoMag;
		delete ListCargoMag;
		delete TabCargoThrow;
		delete IconCargoThrow;
		delete ListCargoThrow;
		delete TabCargoPut;
		delete IconCargoPut;
		delete ListCargoPut;
		delete TabCargoMisc;
		delete IconCargoMisc;
		delete ListCargoMisc;
	};
};
class BIS_scDisplayGarage3DEN
{
	idd=-1;
	enableSimulation=1;
	scriptName="RscDisplayGarage";
	scriptPath="GUI";
	onLoad="[""onLoad"",_this,""RscDisplayGarage"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload="[""onUnload"",_this,""RscDisplayGarage"",'GUI'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	icon="\A3\Ui_f\data\Logos\a_64_ca.paa";
	logo="\A3\Ui_f\data\Logos\arsenal_1024_ca.paa";
	class ControlsBackground
	{
		class BlackLeft: RscText
		{
			colorBackground[]={0,0,0,1};
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneXAbs - safezoneX";
			h="safezoneH";
		};
		class BlackRight: BlackLeft
		{
			x="safezoneX + safezoneW";
		};
		class MouseArea: RscText
		{
			idc=899;
			style=16;
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="safezoneH";
		};
	};
	class Controls
	{
		class ArrowLeft: RscButton
		{
			idc=992;
			text="-";
			x=-1;
			y=-1;
			w="1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class ArrowRight: ArrowLeft
		{
			idc=993;
			text="+";
			x=-1;
			y=-1;
			w="1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BackgroundLeft: RscText
		{
			fade=1;
			idc=994;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0.5};
		};
		class BackgroundRight: BackgroundLeft
		{
			idc=995;
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		class LineIcon: RscFrame
		{
			fade=1;
			idc=1803;
			x=-1;
			y=-1;
			w=0;
			h=0;
			colorText[]={0,0,0,1};
		};
		class LineTabLeft: RscText
		{
			fade=1;
			idc=1804;
			x=-1;
			y=-1;
			w="0.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,1};
		};
		class LineTabLeftSelected: RscText
		{
			idc=1805;
			x="safezoneX";
			y=-1;
			w="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0.80000001};
		};
		class LineTabRight: LineTabLeft
		{
			idc=1806;
		};
		class Tabs: RscFrame
		{
			fade=1;
			idc=1800;
			x="safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="1.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="40 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[]={0,0,0,0};
		};
		class FrameLeft: RscFrame
		{
			fade=1;
			idc=1801;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[]={0,0,0,1};
		};
		class FrameRight: FrameLeft
		{
			fade=1;
			idc=1802;
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		class Load: RscProgress
		{
			fade=1;
			idc=990;
			style=0;
			texture="#(argb,8,8,3)color(1,1,1,1)";
			colorBar[]={1,1,1,1};
			colorFrame[]={0,0,0,1};
			x="safezoneX";
			y="safezoneY + safezoneH - 0.0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="safezoneW";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class LoadCargo: Load
		{
			fade=1;
			idc=991;
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + safezoneH - 11.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Message: RscText
		{
			fade=1;
			idc=996;
			x="safezoneX + (0.5 * safezoneW) - (0.5 * ((safezoneW - 36 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) max 0.4))";
			y="21.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w="((safezoneW - 36 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) max 0.4)";
			h="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0.69999999};
			style=2;
			shadow=0;
			text="";
			sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Space: RscControlsGroup
		{
			x="safezoneX + safezoneW * 0.5 - 4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY";
			show=0;
			idc=27903;
			w="8.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class SpaceArsenalBackground: RscText
				{
					idc=26603;
					x="0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.69999999};
				};
				class SpaceArsenal: RscActivePicture
				{
					idc=26803;
					text="\a3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\spaceArsenal_ca.paa";
					x="1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="2 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip="$STR_A3_Arsenal";
				};
				class SpaceGarageBackground: SpaceArsenalBackground
				{
					idc=26604;
					x="4.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.69999999};
				};
				class SpaceGarage: SpaceArsenal
				{
					idc=26804;
					text="\a3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\spaceGarage_ca.paa";
					x="5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="1.99996 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					tooltip="$STR_A3_Garage";
				};
			};
		};
		class ControlBar: RscControlsGroupNoScrollbars
		{
			w="safezoneW";
			idc=44046;
			x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y="23.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class ButtonClose: RscButtonMenu
				{
					idc=44448;
					text="$STR_DISP_CLOSE";
					x="0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.2) - 0.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					shortcuts[]=
					{
						"0x00050000 + 1"
					};
					tooltip="$STR_A3_RscDisplayGarage_ButtonClose_tooltip";
				};
				class ButtonInterface: ButtonClose
				{
					idc=44151;
					text="$STR_CA_HIDE";
					x="2 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					w="((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1) - 0.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					tooltip="$STR_A3_RscDisplayArsenal_ButtonInterface_tooltip";
				};
				class ButtonRandom: ButtonInterface
				{
					idc=44150;
					text="$STR_A3_RscDisplayArsenal_ButtonRandom";
					x="3 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonRandom_tooltip";
				};
				class ButtonSave: ButtonInterface
				{
					idc=44146;
					text="$STR_DISP_INT_SAVE";
					x="4 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonSave_tooltip";
				};
				class ButtonLoad: ButtonInterface
				{
					idc=44147;
					text="$STR_DISP_INT_LOAD";
					x="5 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonLoad_tooltip";
				};
				class ButtonExport: ButtonInterface
				{
					idc=44148;
					text="$STR_A3_RscDisplayArsenal_ButtonExport";
					x="6 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonExport_tooltip";
				};
				class ButtonImport: ButtonInterface
				{
					idc=44149;
					text="$STR_A3_RscDisplayArsenal_ButtonImport";
					x="7 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayGarage_ButtonImport_tooltip";
				};
				class ButtonOK: ButtonClose
				{
					idc=44346;
					text="$STR_A3_RscDisplayArsenal_ButtonOK";
					x="8 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
					tooltip="$STR_A3_RscDisplayArsenal_ButtonOK_tooltip";
					shortcuts[]=
					{
						"0x00050000 + 0",
						28,
						57,
						156
					};
				};
			};
		};
		class Info: RscControlsGroup
		{
			x="safezoneX + safezoneW - 20.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + safezoneH - 4.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			fade=1;
			idc=25815;
			w="17.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class InfoBackground: RscText
				{
					idc=24515;
					x="2.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,1};
				};
				class InfoName: RscText
				{
					idc=24516;
					x="2.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class InfoAuthor: RscText
				{
					idc=24517;
					x="2.6 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={1,1,1,0.5};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class DLCBackground: RscText
				{
					fade=1;
					idc=24518;
					x="0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="2.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.5};
				};
				class DLCIcon: RscActivePicture
				{
					enabled=0;
					fade=1;
					color[]={1,1,1,1};
					colorActive[]={1,1,1,1};
					idc=24715;
					text="#(argb,8,8,3)color(1,1,1,1)";
					x="0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="2.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class Stats: RscControlsGroupNoScrollbars
		{
			x="safezoneX + safezoneW - 17.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + safezoneH - 10.6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			fade=1;
			enable=0;
			idc=28644;
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class StatsBackground: RscText
				{
					idc=27347;
					x="0 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.5};
				};
				class Stat1: RscProgress
				{
					colorBar[]={1,1,1,1};
					colorFrame[]={0,0,0,0};
					idc=27348;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Stat2: Stat1
				{
					idc=27349;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Stat3: Stat1
				{
					idc=27350;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Stat4: Stat1
				{
					idc=27351;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="3.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Stat5: Stat1
				{
					idc=27352;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="4.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class StatText1: RscText
				{
					shadow=0;
					colorShadow[]={1,1,1,1};
					idc=27353;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={0,0,0,1};
					colorBackground[]={1,1,1,0.1};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class StatText2: StatText1
				{
					idc=27354;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={0,0,0,1};
					colorBackground[]={1,1,1,0.1};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class StatText3: StatText1
				{
					idc=27355;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={0,0,0,1};
					colorBackground[]={1,1,1,0.1};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class StatText4: StatText1
				{
					idc=27356;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="3.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={0,0,0,1};
					colorBackground[]={1,1,1,0.1};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class StatText5: StatText1
				{
					idc=27357;
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="4.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.9 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorText[]={0,0,0,1};
					colorBackground[]={1,1,1,0.1};
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class MouseBlock: RscText
		{
			idc=898;
			style=16;
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="safezoneH";
		};
		class Template: RscControlsGroup
		{
			fade=1;
			idc=35919;
			x="10 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="0.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w="20 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="22.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class Title: RscTitle
				{
					style=0;
					colorBackground[]=
					{
						"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
					};
					idc=34619;
					text="";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="20 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class MainBackground: RscText
				{
					idc=34622;
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="20 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="20 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.80000001};
				};
				class Column1: RscText
				{
					idc=34620;
					x="0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={1,1,1,0.2};
				};
				class Column2: RscText
				{
					idc=34623;
					x="9.05 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={1,1,1,0.1};
				};
				class Column3: RscText
				{
					idc=34624;
					x="12.85 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="1.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={1,1,1,0.1};
				};
				class Column4: RscText
				{
					idc=34625;
					x="15.7 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="0.95 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={1,1,1,0.1};
				};
				class Column5: RscText
				{
					idc=34626;
					x="17.6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="0.95 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={1,1,1,0.1};
				};
				class TextName: RscText
				{
					style=1;
					idc=34621;
					text="$STR_DISP_GAME_NAME";
					x="0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="19.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					colorBackground[]={0,0,0,0.2};
					sizeEx="0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class EditName: RscEdit
				{
					idc=35020;
					x="6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="19.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="13.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx="0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ValueName: RscListNBox
				{
					columns[]={0,0.44999999,0.55000001,0.64999998,0.75,0.80000001,0.85000002,0.89999998,0.94999999};
					idc=35119;
					x="0.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="1.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="19 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="17.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx="0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ButtonOK: RscButtonMenu
				{
					idc=36019;
					text="$STR_DISP_OK";
					x="15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="21.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ButtonCancel: RscButtonMenu
				{
					idc=36020;
					text="$STR_DISP_CANCEL";
					x="0 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="21.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ButtonDelete: RscButtonMenu
				{
					idc=36021;
					text="$STR_DISP_DELETE";
					x="9.9 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="21.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
		class MessageBox: RscMessageBox
		{
		};
		class TabAnimationSources: RscButtonArsenal
		{
			idc="930 + 				0";
			idcx=930;
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\AnimationSources_ca.paa";
			x="safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 0.04 + 0 * 0.04";
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="(1.4 * 		2) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip="$STR_A3_RscDisplayGarage_tab_AnimationSources";
		};
		class ListAnimationSources: RscListBox
		{
			idc="960 + 			0";
			idcx=960;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListDisabledAnimationSources: RscText
		{
			idc="860 + 			0";
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			text="$STR_lib_info_na";
			style=2;
			show=0;
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
		class TabTextureSources: RscButtonArsenal
		{
			idc="930 + 					1";
			idcx=931;
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\TextureSources_ca.paa";
			x="safezoneX + 0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 0.04 + 3 * 0.04";
			w="(1.4 * 		2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="(1.4 * 		2) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip="$STR_A3_RscDisplayGarage_tab_TextureSources";
		};
		class ListTextureSources: RscListBox
		{
			idc="960 + 				1";
			idcx=961;
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="1.4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListDisabledTextureSources: RscText
		{
			idc="860 + 				1";
			x="safezoneX + (1 + 1.5 * 	2) * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + 0.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="15 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="safezoneH - 2.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			text="$STR_lib_info_na";
			style=2;
			show=0;
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
	};
};
class GarageLoadDisplay: BIS_RscDisplayGarage
{
	idd=8765;
	class controls: Controls
	{
		class ArrowLeft: ArrowLeft
		{
		};
		class ArrowRight: ArrowRight
		{
		};
		class BackgroundLeft: BackgroundLeft
		{
		};
		class BackgroundRight: BackgroundRight
		{
		};
		class LineIcon: LineIcon
		{
		};
		class LineTabLeft: LineTabLeft
		{
		};
		class LineTabLeftSelected: LineTabLeftSelected
		{
		};
		class LineTabRight: LineTabRight
		{
		};
		class Tabs: Tabs
		{
		};
		class FrameLeft: FrameLeft
		{
		};
		class FrameRight: FrameRight
		{
		};
		class Load: Load
		{
		};
		class LoadCargo: LoadCargo
		{
		};
		class Message: Message
		{
		};
		class Space: Space
		{
		};
		class ControlBar: ControlBar
		{
			class controls: controls
			{
				class ButtonClose: ButtonClose
				{
				};
				class ButtonInterface: ButtonInterface
				{
				};
				class ButtonRandom: ButtonRandom
				{
				};
				class ButtonSave: ButtonSave
				{
				};
				class ButtonLoad: ButtonLoad
				{
				};
				class ButtonExport: ButtonExport
				{
				};
				class ButtonImport: ButtonImport
				{
				};
			};
		};
		class Info: Info
		{
			class controls: controls
			{
			};
		};
		class Stats: Stats
		{
			class controls: controls
			{
			};
		};
		class MouseBlock: MouseBlock
		{
		};
		class Template: Template
		{
		};
		class MessageBox: MessageBox
		{
		};
		class TabCar: TabCar
		{
		};
		class IconCar: IconCar
		{
		};
		class ListCar: ListCar
		{
		};
		class ListDisabledCar: ListDisabledCar
		{
		};
		class TabTank: TabTank
		{
		};
		class IconTank: IconTank
		{
		};
		class ListTank: ListTank
		{
		};
		class ListDisabledTank: ListDisabledTank
		{
		};
		class TabHelicopter: TabHelicopter
		{
		};
		class IconHelicopter: IconHelicopter
		{
		};
		class ListHelicopter: ListHelicopter
		{
		};
		class ListDisabledHelicopter: ListDisabledHelicopter
		{
		};
		class TabPlane: TabPlane
		{
		};
		class IconPlane: IconPlane
		{
		};
		class ListPlane: ListPlane
		{
		};
		class ListDisabledPlane: ListDisabledPlane
		{
		};
		class TabNaval: TabNaval
		{
		};
		class IconNaval: IconNaval
		{
		};
		class ListNaval: ListNaval
		{
		};
		class ListDisabledNaval: ListDisabledNaval
		{
		};
		class TabStatic: TabStatic
		{
		};
		class IconStatic: IconStatic
		{
		};
		class ListStatic: ListStatic
		{
		};
		class ListDisabledStatic: ListDisabledStatic
		{
		};
		class TabCrew: TabCrew
		{
		};
		class IconCrew: IconCrew
		{
		};
		class ListCrew: ListCrew
		{
		};
		class ListDisabledCrew: ListDisabledCrew
		{
		};
		class TabAnimationSources: TabAnimationSources
		{
		};
		class IconAnimationSources: IconAnimationSources
		{
		};
		class ListAnimationSources: ListAnimationSources
		{
		};
		class ListDisabledAnimationSources: ListDisabledAnimationSources
		{
		};
		class TabTextureSources: TabTextureSources
		{
		};
		class IconTextureSources: IconTextureSources
		{
		};
		class ListTextureSources: ListTextureSources
		{
		};
		class ListDisabledTextureSources: ListDisabledTextureSources
		{
		};
		class ControlBarDummy: FOD_ZA_RscControlsGroupNoScrollbars
		{
			idc=1866;
			x="8 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1) + 			(safezoneX)";
			y="23.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w="safezoneW";
			h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class ButtonTry: RscButtonMenu
				{
					idc=-1;
					text="";
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y="0 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1) - 0.1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class ButtonOK: ButtonTry
				{
					x="0.5 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 1 * 	((safezoneW - 1 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.1)";
				};
			};
		};
		class GarageStatsGroup: FOD_ZA_RscControlsGroupNoScrollbars
		{
			idc=1867;
			x="safezoneX + ((safezoneW - (			(			((safezoneW / safezoneH) min 1.2) / 40)*9.5)) / 2.0)";
			y="safezoneY + safezoneH - 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*7";
			w="(			(			((safezoneW / safezoneH) min 1.2) / 40)*9.5)";
			h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*5.2";
			class controls: controls
			{
				class GarageStatsBackground: RscPicture
				{
					idc=-1;
					colorBackground[]={0,0,0,0.5};
					text="#(argb,8,8,3)color(0.2,0.2,0.2,0.8)";
					x=0;
					y=0;
					w="(			(			((safezoneW / safezoneH) min 1.2) / 40)*9.5)";
					h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*2.3";
				};
				class GarageStatsModPicture: RscPictureKeepAspect
				{
					idc="(1867 + 2)";
					colorBackground[]={0,0,0,0.80000001};
					x="(			((safezoneW / safezoneH) min 1.2) / 40)*0.1";
					y="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.1";
					w="(			((safezoneW / safezoneH) min 1.2) / 40)*2.1";
					h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*2.1";
				};
				class GarageStatsMaxSpeed: RscProgress
				{
					idc="(1867 + 3)";
					colorFrame[]={0,0,0,0};
					colorBar[]={1,1,1,1};
					x="(			((safezoneW / safezoneH) min 1.2) / 40)*2.3";
					y="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.1";
					w="(			(			((safezoneW / safezoneH) min 1.2) / 40)*9.5) - (			(			((safezoneW / safezoneH) min 1.2) / 40) * 2.45)";
					h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class GarageStatsMaxSpeedText: RscText
				{
					idc=-1;
					colorText[]={0,0,0,1};
					colorShadow[]={1,1,1,1};
					colorBackground[]={1,1,1,0.1};
					text="$STR_A3_RSCDISPLAYGARAGE_STAT_MAX_SPEED";
					x="(			((safezoneW / safezoneH) min 1.2) / 40)*2.3";
					y="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.1";
					w="(			(			((safezoneW / safezoneH) min 1.2) / 40)*9.5) - (			(			((safezoneW / safezoneH) min 1.2) / 40) * 2.45)";
					h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					shadow=0;
				};
				class GarageStatsArmor: GarageStatsMaxSpeed
				{
					idc="(1867 + 4)";
					y="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*1.2";
				};
				class GarageStatsArmorText: GarageStatsMaxSpeedText
				{
					text="$STR_UI_ABAR";
					y="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*1.2";
				};
				class GarageSpawnButton: RscButton
				{
					idc="(1867 + 1)";
					font="PuristaMedium";
					text="SPAWN";
					tooltip="Ready?";
					colorBackground[]={0,0,0,0.5};
					x=0;
					y="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*2.5";
					w="(			(			((safezoneW / safezoneH) min 1.2) / 40)*9.5)";
					h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*1.5";
					onButtonClick=" 						_display = uiNamespace getVariable 'Garage_Display_Loadout'; 						missionNameSpace setVariable ['Garage_Spawn_Flag' ,true]; 						_display closeDisplay 1; 					";
				};
				class GarageSpawnType: RscCombo
				{
					idc=-1;
					font="PuristaMedium";
					text="Pylons settings";
					tooltip="Spawn Type";
					x=0;
					y="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*4.2";
					w="(			(			((safezoneW / safezoneH) min 1.2) / 40)*9.5)";
					h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					onLBSelChanged="missionNamespace setVariable ['Garage_SpawnType', _this select 1];";
					onLoad="(_this select 0) lbSetCurSel (missionNamespace getVariable ['Garage_SpawnType', 0]);";
					class Items
					{
						class OnlySpawn
						{
							text="Only Spawn";
							default=1;
						};
						class Getin
						{
							text="Get in";
						};
						class Flying
						{
							text="Flying";
						};
					};
				};
			};
		};
	};
};
class GarageSettingGroup: FOD_ZA_RscControlsGroupNoScrollbars
{
	idc=1872;
	x="(safezoneX + safezoneW) - (0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40)) - (0.6*			(			((safezoneW / safezoneH) min 1.2) / 40))";
	y="(safezoneY + safezoneH) - (0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) - (1.8*			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
	h="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls: controls
	{
		class GarageSettingBackground: RscPicture
		{
			idc=-1;
			colorBackground[]={0,0,0,0.5};
			text="#(argb,8,8,3)color(0.2,0.2,0.2,0.8)";
			x=0;
			y=0;
			w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			h="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class GaragePylonGroup: RscControlsGroupNoScrollbars
		{
			idc="(1872 + 1)";
			x=0;
			y=0;
			w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			h="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls: controls
			{
				class GaragePylonText: RscText
				{
					idc=-1;
					font="RobotoCondensedLight";
					text="Pylons settings";
					x=0;
					y=0;
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
					h="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) * 0.07";
				};
				class GaragePylonToggle: RscButton
				{
					idc="((1872 + 1) + 1)";
					font="RobotoCondensedLight";
					text="Option";
					tooltip="Change display";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.815";
					y=0;
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.185";
					h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					onButtonClick="_this call sel_toggle_setting";
				};
				class GaragePylonUIPicture: RscPictureKeepAspect
				{
					idc="((1872 + 1) + 2)";
					x=0;
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) * 0.07";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40)) * 0.921";
					h="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) * 0.907";
				};
				class GaragePylonPreset: RscCombo
				{
					idc="((1872 + 1) + 3)";
					colorBackground[]={0,0,0,0.80000001};
					font="RobotoCondensedLight";
					tooltip="Select Preset";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.03";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.086";
					w="(			(			((safezoneW / safezoneH) min 1.2) / 40)*5)";
					h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
					class Items
					{
						class Custom
						{
							text="Custom";
							default=1;
						};
					};
				};
				class GaragePylonMirror: RscCheckBox
				{
					idc=1990;
					font="RobotoCondensedLight";
					tooltip="Mirroring";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.815";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.086";
					w="(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class GaragePylonMirrorText: RscText
				{
					idc=-1;
					font="RobotoCondensedLight";
					text="Mirror";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.815+(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.086";
					w="(			(			((safezoneW / safezoneH) min 1.2) / 40)*5)";
					h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
				};
			};
		};
		class GarageOptionGroup: RscControlsGroupNoScrollbars
		{
			idc="(1872 + 6)";
			x=0;
			y=0;
			w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
			h="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls: controls
			{
				class GarageOptionText: RscText
				{
					idc=-1;
					font="RobotoCondensedLight";
					text="Option settings";
					x=0;
					y=0;
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))";
					h="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) * 0.07";
				};
				class GarageOptionToggle: RscButton
				{
					idc="((1872 + 6) + 1)";
					font="RobotoCondensedLight";
					text="Pylons";
					tooltip="Change display";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.815";
					y=0;
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.185";
					h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					onButtonClick="_this call sel_toggle_setting";
				};
				class GarageDamageText: RscText
				{
					idc=-1;
					font="RobotoCondensedLight";
					text="Damage";
					style=2;
					sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)*1.5";
					x=0;
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.086";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.5";
					h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)*2";
				};
				class GarageDamageListBackground: RscPicture
				{
					idc=-1;
					colorBackground[]={0,0,0,0.30000001};
					text="#(argb,8,8,3)color(0,0,0,0.3)";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.03";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.23";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.44";
					h="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.57";
				};
				class GarageDamageListArrowLeft: RscButton
				{
					idc="((1872 + 6) + 3)";
					text="-";
					x=-1;
					y=-1;
					w="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
					h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
					onButtonClick="_this call sel_damage_arrow;";
				};
				class GarageDamageListArrowRight: GarageDamageListArrowLeft
				{
					idc="((1872 + 6) + 4)";
					text="+";
					onButtonClick="_this call sel_damage_arrow;";
				};
				class GarageDamageList: RscListNBox
				{
					idc="((1872 + 6) + 2)";
					font="RobotoCondensedLight";
					idcLeft=1881;
					idcRight=1882;
					columns[]={0.07,0.63};
					drawSideArrows=1;
					disableOverflow=1;
					sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.03";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.23";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.44";
					h="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.57";
					colorBackground[]={0,0,0,0.30000001};
					colorSelectBackground[]={1,1,1,0.5};
					colorSelectBackground2[]={1,1,1,0.5};
					colorSelect[]={1,1,1,1};
					colorSelect2[]={1,1,1,1};
				};
				class GarageDamageDelayText: RscText
				{
					idc=-1;
					font="RobotoCondensedLight";
					text="DelaySec. [min,max] :";
					style=0;
					sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.029";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.82";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.23";
					h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
				};
				class GarageDamageDelayMin: RscEdit
				{
					idc="((1872 + 6) + 5)";
					font="RobotoCondensedLight";
					text="0";
					autocomplete="";
					linespacing=1;
					maxChars=4;
					style="0x01 + 0x40";
					sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.28";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.82";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.08";
					h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
					onKeyUp="(_this select 0) call sel_damage_delay";
				};
				class GarageDamageDelayMax: RscEdit
				{
					idc="((1872 + 6) + 6)";
					font="RobotoCondensedLight";
					text="0";
					autocomplete="";
					linespacing=1;
					maxChars=4;
					style="0x01 + 0x40";
					sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.38";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.82";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.08";
					h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
					onKeyUp="(_this select 0) call sel_damage_delay";
				};
				class GarageDamageReset: RscButton
				{
					idc=-1;
					font="RobotoCondensedLight";
					text="Reset All Damage";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.125";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.9";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.25";
					h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					onButtonClick="call sel_damage_reset;";
				};
				class GarageInsigniaText: RscText
				{
					idc=-1;
					font="RobotoCondensedLight";
					text="Insignia";
					style=2;
					sizeEx="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)*1.5";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.5";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.086";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.5";
					h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)*2";
				};
				class GarageInsigniaPointText: RscText
				{
					idc=-1;
					font="RobotoCondensedLight";
					text="Point:";
					style=2;
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.52";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.21";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.18";
					h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
				};
				class GarageInsigniaTexText: RscText
				{
					idc=-1;
					font="RobotoCondensedLight";
					text="Tex:";
					style=2;
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.72";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.21";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.25";
					h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
				};
				class GarageInsigniaPoint: RscListBox
				{
					idc="((1872 + 6) + 7)";
					font="RobotoCondensedLight";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.52";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.28";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.18";
					h="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.58";
				};
				class GarageInsigniaTex: RscListBox
				{
					idc="((1872 + 6) + 8)";
					font="RobotoCondensedLight";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.72";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.28";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.25";
					h="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.58";
				};
				class GarageInsigniaReset: RscButton
				{
					idc=-1;
					font="RobotoCondensedLight";
					text="Reset All Insignia";
					x="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.625";
					y="(0.45 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25))*0.9";
					w="(0.81 * ((((0.81 * 30 * 			(			((safezoneW / safezoneH) min 1.2) / 40)) min (safezoneW*0.5)) / (0.81 * 			(			((safezoneW / safezoneH) min 1.2) / 40))) min (((0.45 * 30 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) min (safezoneH*0.45)) / (0.45 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))) * 			(			((safezoneW / safezoneH) min 1.2) / 40))*0.25";
					h="(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					onButtonClick="call sel_insignia_reset;";
				};
			};
		};
	};
};
class GaragePylons: FOD_ZA_RscCombo
{
	idc=-1;
	colorBackground[]={0,0,0,0.80000001};
	font="RobotoCondensedLight";
	w="(			(			((safezoneW / safezoneH) min 1.2) / 40)*5)";
	h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
};
class GaragePylonTurrets: FOD_ZA_ctrlButtonPictureKeepAspect
{
	idc=-1;
	colorBackground[]={0,0,0,0.80000001};
	font="RobotoCondensedLight";
	w="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
	h="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)*0.9)";
};
class Display3DEN
{
	class ContextMenu: ctrlMenu
	{
		class Items
		{
			class Log
			{
				items[]+=
				{
					"SeparatorSelected",
					"FOD_LogCfgGroups"
				};
			};
			class FOD_LogCfgGroups
			{
				text="Log Faction Variables (FOD_ZA)";
				value=0;
				conditionShow="selectedObject";
				action="call FOD_ZA_fnc_logCfgGroupsClipboard;";
			};
		};
	};
};
class CfgFactionClasses
{
	class NO_CATEGORY;
	class FOD_ZA_Modules: NO_CATEGORY
	{
		displayName="[FOD] Zeus Additions";
	};
};
class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit;
			class Combo;
			class EditCodeMulti5;
			class EditMulti3;
			class EditMulti5;
			class Checkbox;
			class CheckboxNumber;
			class ModuleDescription;
			class Units;
		};
		class ModuleDescription
		{
			class AnyStaticObject;
		};
	};
	class FOD_ZA_ModuleSpawnAIGroup: Module_F
	{
		scope=2;
		displayName="Spawn AI Group";
		author="Phenosi";
		category="FOD_ZA_Modules";
		icon="a3\ui_f_curator\data\displays\rscdisplaycurator\modegroups_ca.paa";
		picture="a3\ui_f_curator\data\displays\rscdisplaycurator\modegroups_ca.paa";
		function="FOD_ZA_fnc_ModuleSpawnAIGroup";
		functionPriority=1;
		isGlobal=0;
		isTriggerActivated=1;
		isDisposable=1;
		is3DEN=1;
		curatorCanAttach=0;
		canSetArea=1;
		canSetAreaShape=1;
		class AttributeValues
		{
			size3[]={200,200,-1};
			isRectangle=0;
		};
		class Attributes: AttributesBase
		{
			class SPG_ClassPool: Edit
			{
				property="FOD_ZA_SPG_ClassPool";
				expression="_this setVariable ['FOD_ZA_SPG_ClassPool', _value, true];";
				displayName="Unit Classnames";
				tooltip="Classnames (, separated). One is picked at random per unit spawned. Lowest priority, ignored if Faction Classname or CfgGroups Classname is set.";
				typeName="STRING";
				defaultValue="""O_Soldier_F,O_Soldier_GL_F,O_Soldier_LAT_F,O_Soldier_AR_F""";
			};
			class SPG_FactionClass: Edit
			{
				property="FOD_ZA_SPG_FactionClass";
				expression="_this setVariable ['FOD_ZA_SPG_FactionClass', _value, true];";
				displayName="Faction Classname (optional)";
				tooltip="CfgFactionClasses classname (e.g. OPF_F). If set, overrides CfgGroups and Unit Classnames - units are drawn from this faction. Highest priority.";
				typeName="STRING";
				defaultValue="""""";
			};
			class SPG_CfgGroup: Edit
			{
				property="FOD_ZA_SPG_CfgGroup";
				expression="_this setVariable ['FOD_ZA_SPG_CfgGroup', _value, true];";
				displayName="CfgGroups Classname (optional)";
				tooltip="CfgGroups classname (e.g. OIA_InfSentry). If set and Faction Classname is empty, spawns this predefined group. Overrides Unit Classnames.";
				typeName="STRING";
				defaultValue="""""";
			};
			class SPG_GroupSize: Edit
			{
				property="FOD_ZA_SPG_GroupSize";
				expression="_this setVariable ['FOD_ZA_SPG_GroupSize', _value, true];";
				displayName="Group Size";
				tooltip="Number of units in the group.";
				typeName="NUMBER";
				defaultValue="4";
			};
			class SPG_Side: Combo
			{
				property="FOD_ZA_SPG_Side";
				expression="_this setVariable ['FOD_ZA_SPG_Side', _value, true];";
				displayName="Side";
				tooltip="Side of the spawned group.";
				typeName="STRING";
				defaultValue="""EAST""";
				class Values
				{
					class East
					{
						name="EAST (OPFOR)";
						value="EAST";
					};
					class West
					{
						name="WEST (BLUFOR)";
						value="WEST";
					};
					class Indep
					{
						name="INDEPENDENT";
						value="INDEPENDENT";
					};
					class Civ
					{
						name="CIVILIAN";
						value="CIVILIAN";
					};
				};
			};
			class SPG_LambsTask: Combo
			{
				property="FOD_ZA_SPG_LambsTask";
				expression="_this setVariable ['FOD_ZA_SPG_LambsTask', _value, true];";
				displayName="Task";
				tooltip="AI behaviour task assigned after spawning. [LAMBS] tasks require LAMBS Waypoints. [CBA] tasks require CBA (always loaded). [VANILLA] tasks have no extra dependency.";
				typeName="STRING";
				defaultValue="""patrol""";
				class Values
				{
					class LambsPatrol
					{
						name="[LAMBS] Patrol";
						value="patrol";
					};
					class LambsGarrison
					{
						name="[LAMBS] Garrison";
						value="garrison";
					};
					class LambsCamp
					{
						name="[LAMBS] Camp";
						value="camp";
					};
					class LambsDefend
					{
						name="[LAMBS] Defend";
						value="defend";
					};
					class LambsAmbush
					{
						name="[LAMBS] Ambush";
						value="ambush";
					};
					class LambsCQB
					{
						name="[LAMBS] CQB";
						value="cqb";
					};
					class LambsRush
					{
						name="[LAMBS] Rush";
						value="rush";
					};
					class LambsHunt
					{
						name="[LAMBS] Hunt";
						value="hunt";
					};
					class LambsCreep
					{
						name="[LAMBS] Creep";
						value="creep";
					};
					class LambsAssault
					{
						name="[LAMBS] Assault";
						value="assault";
					};
					class LambsReserve
					{
						name="[LAMBS] Reserve/QRF";
						value="reserve";
					};
					class LambsHitRun
					{
						name="[LAMBS] Hit & Run";
						value="hitandrun";
					};
					class CbaAttack
					{
						name="[CBA] Attack";
						value="cbaattack";
					};
					class CbaDefend
					{
						name="[CBA] Defend";
						value="cbadefend";
					};
					class CbaPatrol
					{
						name="[CBA] Patrol";
						value="cbapatrol";
					};
					class CbaSearch
					{
						name="[CBA] Search Area";
						value="cbasearch";
					};
					class VanSentry
					{
						name="[VANILLA] Sentry";
						value="sentry";
					};
					class VanGuard
					{
						name="[VANILLA] Guard";
						value="guard";
					};
					class VanSAD
					{
						name="[VANILLA] Seek & Destroy";
						value="seekanddestroy";
					};
					class VanGarrison
					{
						name="[VANILLA] Garrison";
						value="vanillagarrison";
					};
					class VanTacticalPush
					{
						name="[VANILLA] Tactical Push";
						value="tacticalpush";
					};
					class VanMobilizeQRF
					{
						name="[VANILLA] Mobilize QRF";
						value="mobilizeqrf";
					};
					class Random
					{
						name="Random";
						value="random";
					};
					class NoTask
					{
						name="No Task";
						value="notask";
					};
				};
			};
			class SPG_Skill: Edit
			{
				property="FOD_ZA_SPG_Skill";
				expression="_this setVariable ['FOD_ZA_SPG_Skill', _value, true];";
				displayName="Skill";
				tooltip="Unit skill level. 0.0 = lowest, 1.0 = highest.";
				typeName="NUMBER";
				defaultValue="0.85";
			};
			class SPG_PlayersOnly: Checkbox
			{
				property="FOD_ZA_SPG_PlayersOnly";
				expression="_this setVariable ['FOD_ZA_SPG_PlayersOnly', _value, true];";
				displayName="Players Only";
				tooltip="Note: Task Rush, Hunt, Creep, Reserve/QRF and Hit & Run ONLY react to player enemies, not AI when this is enabled.";
				typeName="BOOL";
				defaultValue="false";
			};
			class SPG_LoS: Checkbox
			{
				property="FOD_ZA_SPG_LoS";
				expression="_this setVariable ['FOD_ZA_SPG_LoS', _value, true];";
				displayName="Line of Sight Check";
				tooltip="Spawn the group at the nearest spot inside the area with no enemy line of sight, searching from the centre outwards. Falls back to the module centre if every spot is exposed.";
				typeName="BOOL";
				defaultValue="true";
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description[]=
			{
				"Spawns an AI group at the module position when activated.",
				"LAMBS Waypoints (lambs_wp) required for all [LAMBS]tasks",
				"Configure side, task, skill and group size in the module attributes.",
				"Set Faction Classname (e.g. OPF_F) to draw units from a faction - overrides Unit Classnames.",
				"Resize the area circle in the editor to set the task radius.",
				"Supports trigger-based activation - useful for timed spawns, reinforcement waves or dynamic ambushes.",
				"Tip: use a circular area (A = B) for the most predictable task radius behavior."
			};
		};
	};
	class PHEN_ModuleGarageInit: Module_F
	{
		scope=2;
		displayName="Vehicle Garage";
		icon="a3\ui_f\data\gui\rsc\rscdisplayarsenal\spacegarage_ca.paa";
		category="FOD_ZA_Modules";
		function="kbf_fnc_ModuleGarageInit";
		functionPriority=1;
		isGlobal=2;
		isTriggerActivated=0;
		isDisposable=1;
		is3DEN=1;
		curatorCanAttach=0;
		class Attributes: AttributesBase
		{
			class TypesArray: Combo
			{
				property="PHEN_ModuleGarageInit_TypesArray";
				expression="_this setVariable ['PHEN_ModuleGarageInit_TypesArray', _value, true];";
				displayName="Spawnable Types";
				tooltip="Select which vehicle types can be spawned.";
				typeName="STRING";
				defaultValue="""['Auto']""";
				class Values
				{
					class Auto
					{
						name="Auto (by surface)";
						value="['Auto']";
					};
					class All
					{
						name="All Types";
						value="['All']";
					};
					class Ground
					{
						name="Ground";
						value="['Ground']";
					};
					class Car
					{
						name="Car";
						value="['Car']";
					};
					class Tank
					{
						name="Tank";
						value="['Tank']";
					};
					class Helicopter
					{
						name="Helicopter";
						value="['Helicopter']";
					};
					class Plane
					{
						name="Plane";
						value="['Plane']";
					};
					class Ship
					{
						name="Ship";
						value="['Ship']";
					};
					class StaticWpn
					{
						name="Static Weapon";
						value="['StaticWeapon']";
					};
				};
			};
			class SidesArray: Combo
			{
				property="PHEN_ModuleGarageInit_SidesArray";
				expression="_this setVariable ['PHEN_ModuleGarageInit_SidesArray', _value, true];";
				displayName="Allowed Sides";
				tooltip="Select which side can use this spawner.";
				typeName="STRING";
				defaultValue="""['ALL']""";
				class Values
				{
					class All
					{
						name="All Sides";
						value="['ALL']";
					};
					class Blufor
					{
						name="BLUFOR";
						value="['BLUFOR']";
					};
					class Opfor
					{
						name="OPFOR";
						value="['OPFOR']";
					};
					class Indep
					{
						name="INDEP";
						value="['INDEP']";
					};
					class Civ
					{
						name="CIV";
						value="['CIV']";
					};
				};
			};
			class DisplayRange: Edit
			{
				property="PHEN_ModuleGarageInit_DisplayRange";
				expression="_this setVariable ['PHEN_ModuleGarageInit_DisplayRange', _value, true];";
				displayName="Display Distance (m)";
				tooltip="Distance at which the action becomes available.";
				defaultValue="10";
				typeName="NUMBER";
			};
			class Marker: Checkbox
			{
				property="PHEN_ModuleGarageInit_Marker";
				expression="_this setVariable ['PHEN_ModuleGarageInit_Marker', _value, true];";
				displayName="Show Map Marker";
				tooltip="If enabled, a map fitting marker will be created for this garage spawn point (based on Garage type).";
				defaultValue="false";
				typeName="BOOL";
			};
			class ExtraScript: Edit
			{
				property="PHEN_ModuleGarageInit_ExtraScript";
				expression="_this setVariable ['PHEN_ModuleGarageInit_ExtraScript', _value, true];";
				displayName="Additional Script";
				tooltip="Optional code/script executed on vehicle spawn. Variables: _veh, _point, etc.";
				defaultValue="";
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description[]=
			{
				"Adds a vehicle garage spawner to a static object.",
				"STEP 1: Sync this module to the object players interact with to open the garage.",
				"STEP 2: Sync this module to the object that will serve as the vehicle spawn point.",
				"Supports filtering by side and vehicle type, a custom spawn script and an optional map marker.",
				"Display Distance controls how close players must be before the garage action appears."
			};
			sync[]=
			{
				"AnyStaticObject"
			};
		};
	};
	class FOD_ZA_ModuleDefenseOP: Module_F
	{
		scope=2;
		displayName="Defense Op Generator";
		author="Phenosi";
		category="FOD_ZA_Modules";
		icon="a3\modules_f_curator\data\portraitobjectiveattackdefend_ca.paa";
		picture="a3\modules_f_curator\data\portraitobjectiveattackdefend_ca.paa";
		function="FOD_ZA_fnc_ModuleDefenseOP";
		functionPriority=1;
		isGlobal=0;
		isTriggerActivated=1;
		isDisposable=1;
		is3DEN=1;
		curatorCanAttach=0;
		canSetArea=1;
		canSetAreaShape=1;
		class AttributeValues
		{
			size3[]={100,100,-1};
			isRectangle=0;
		};
		class Attributes: AttributesBase
		{
			class DOP_Side: Combo
			{
				property="FOD_ZA_DOP_Side";
				expression="_this setVariable ['FOD_ZA_DOP_Side', _value, true];";
				displayName="Attacker Side";
				tooltip="Side of the attacking AI groups.";
				typeName="STRING";
				defaultValue="""EAST""";
				class Values
				{
					class East
					{
						name="EAST (OPFOR)";
						value="EAST";
					};
					class West
					{
						name="WEST (BLUFOR)";
						value="WEST";
					};
					class Indep
					{
						name="INDEPENDENT";
						value="INDEPENDENT";
					};
				};
			};
			class DOP_FactionClass: Edit
			{
				property="FOD_ZA_DOP_FactionClass";
				expression="_this setVariable ['FOD_ZA_DOP_FactionClass', _value, true];";
				displayName="Faction Classname";
				tooltip="CfgFactionClasses classname of the attacking faction (e.g. OPF_F, IND_F). Must match the selected side.";
				typeName="STRING";
				defaultValue="""OPF_F""";
			};
			class DOP_GroupFilter: Edit
			{
				property="FOD_ZA_DOP_GroupFilter";
				expression="_this setVariable ['FOD_ZA_DOP_GroupFilter', _value, true];";
				displayName="Group Filter";
				tooltip="CfgGroups classnames (, separated) to restrict which groups can spawn. Leave empty to use all groups from the faction.";
				typeName="STRING";
				defaultValue="""""";
			};
			class DOP_Rush: Checkbox
			{
				property="FOD_ZA_DOP_Rush";
				expression="_this setVariable ['FOD_ZA_DOP_Rush', _value, true];";
				displayName="LAMBS Rush";
				tooltip="Use LAMBS Rush? Otherwise groups get a Seek-and-Destroy waypoint.";
				typeName="BOOL";
				defaultValue="true";
			};
			class DOP_LoS: Checkbox
			{
				property="FOD_ZA_DOP_LoS";
				expression="_this setVariable ['FOD_ZA_DOP_LoS', _value, true];";
				displayName="Line of Sight Check";
				tooltip="Only spawn enemies behind cover (no direct line of sight to defenders).";
				typeName="BOOL";
				defaultValue="true";
			};
			class DOP_Interval: Edit
			{
				property="FOD_ZA_DOP_Interval";
				expression="_this setVariable ['FOD_ZA_DOP_Interval', _value, true];";
				displayName="Spawn Interval (s)";
				tooltip="Seconds between each group spawn.";
				typeName="NUMBER";
				defaultValue="30";
			};
			class DOP_Directional: Checkbox
			{
				property="FOD_ZA_DOP_Directional";
				expression="_this setVariable ['FOD_ZA_DOP_Directional', _value, true];";
				displayName="Directional Attack";
				tooltip="Restrict spawns to a directional sector instead of all 360 degrees. NOTE: bypasses terrain safety check.";
				typeName="BOOL";
				defaultValue="false";
			};
			class DOP_AttackDir: Combo
			{
				property="FOD_ZA_DOP_AttackDir";
				expression="_this setVariable ['FOD_ZA_DOP_AttackDir', _value, true];";
				displayName="Attack Direction";
				tooltip="Cardinal direction enemies spawn from. Only used when Directional Attack is enabled.";
				typeName="NUMBER";
				defaultValue="0";
				class Values
				{
					class N
					{
						name="N";
						value=0;
					};
					class NE
					{
						name="NE";
						value=45;
					};
					class E
					{
						name="E";
						value=90;
					};
					class SE
					{
						name="SE";
						value=135;
					};
					class S
					{
						name="S";
						value=180;
					};
					class SW
					{
						name="SW";
						value=225;
					};
					class W
					{
						name="W";
						value=270;
					};
					class NW
					{
						name="NW";
						value=315;
					};
				};
			};
			class DOP_AttackArc: Edit
			{
				property="FOD_ZA_DOP_AttackArc";
				expression="_this setVariable ['FOD_ZA_DOP_AttackArc', _value, true];";
				displayName="Attack Arc (deg)";
				tooltip="Total angular spread around the attack direction. 90 = plus/minus 45 deg either side. Only used when Directional Attack is enabled.";
				typeName="NUMBER";
				defaultValue="90";
			};
			class DOP_MaxTime: Edit
			{
				property="FOD_ZA_DOP_MaxTime";
				expression="_this setVariable ['FOD_ZA_DOP_MaxTime', _value, true];";
				displayName="Max Duration (s)";
				tooltip="Spawning stops after this many seconds. 0 = no time limit. Ignored if a Stop Condition is set.";
				typeName="NUMBER";
				defaultValue="0";
			};
			class DOP_Condition: Edit
			{
				property="#FOD_ZA_DOP_Condition";
				expression="_this setVariable ['#FOD_ZA_DOP_Condition', compile _value, true];";
				displayName="Stop Condition";
				validate="string";
				control="EditCodeMulti3";
				tooltip="SQF code (runs on server), spawning stops when this returns true. Overrides Max Duration. Leave empty to use the time limit instead. Example: !alive myObjective";
				typeName="STRING";
				defaultValue="""""";
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description[]=
			{
				"Continuously spawns AI groups attacking the module position until the OP ends.",
				"Requires LAMBS Waypoints (lambs_wp).",
				"Resize the area circle in the editor to set the spawn radius.",
				"Faction Classname: find it in the config browser under CfgFactionClasses (e.g. OPF_F).",
				"Group Filter: CfgGroups classnames (, separated); leave empty to use all groups in the faction.",
				"Directional Attack: restrict spawns to a compass sector using Direction and Arc attributes.",
				"Stops when Max Duration expires or Stop Condition returns true. Leave both empty to run indefinitely."
			};
		};
	};
	class FOD_ZA_ModuleGarrisonVanilla: Module_F
	{
		scope=2;
		displayName="Garrison Area (Vanilla)";
		author="Phenosi";
		category="FOD_ZA_Modules";
		icon="a3\ui_f\data\gui\cfg\communicationmenu\defend_ca.paa";
		picture="a3\ui_f\data\gui\cfg\communicationmenu\defend_ca.paa";
		function="FOD_ZA_fnc_ModuleGarrisonVanilla";
		functionPriority=1;
		isGlobal=0;
		isTriggerActivated=1;
		isDisposable=1;
		is3DEN=1;
		curatorCanAttach=0;
		canSetArea=1;
		canSetAreaShape=1;
		class AttributeValues
		{
			size3[]={100,100,-1};
			isRectangle=0;
		};
		class Attributes: AttributesBase
		{
			class MGV_SortByHeight: Checkbox
			{
				property="FOD_ZA_MGV_SortByHeight";
				expression="_this setVariable ['FOD_ZA_MGV_SortByHeight', _value, true];";
				displayName="Sort Positions by Height";
				tooltip="Assign building positions from highest floor down. Puts units on upper floors first.";
				typeName="BOOL";
				defaultValue="false";
			};
			class MGV_Patrol: Checkbox
			{
				property="FOD_ZA_MGV_Patrol";
				expression="_this setVariable ['FOD_ZA_MGV_Patrol', _value, true];";
				displayName="Patrol Element";
				tooltip="Split a small element (1-4 units) from the garrison to patrol the area. The rest hold position.";
				typeName="BOOL";
				defaultValue="false";
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description[]=
			{
				"Garrisons synced AI units into nearby building positions. No LAMBS required.",
				"STEP 1: Sync AI units or groups to this module.",
				"STEP 2: Resize the area circle to set the building search radius.",
				"Garrisoned units hold position until hit 3 times or suppressed by an enemy within 10-150 m.",
				"Sort by Height: fills upper floors first.",
				"Patrol Element: a small sub-element patrols the area while the rest hold."
			};
		};
	};
	class FOD_ZA_ModuleReserveQRF: Module_F
	{
		scope=2;
		displayName="Task Reserve/QRF";
		author="Phenosi";
		category="FOD_ZA_Modules";
		icon="\FOD_ZA\pictures\FOD_ZA_ReserveQRF_icon.paa";
		picture="\FOD_ZA\pictures\FOD_ZA_ReserveQRF_icon.paa";
		function="FOD_ZA_fnc_ModuleReserveQRF";
		functionPriority=1;
		isGlobal=0;
		isTriggerActivated=1;
		isDisposable=1;
		is3DEN=1;
		curatorCanAttach=0;
		canSetArea=1;
		canSetAreaShape=1;
		class AttributeValues
		{
			size3[]={150,150,-1};
			isRectangle=0;
		};
		class Attributes: AttributesBase
		{
			class RQ_PlayersOnly: Checkbox
			{
				property="FOD_ZA_RQ_PlayersOnly";
				expression="_this setVariable ['FOD_ZA_RQ_PlayersOnly', _value, true];";
				displayName="Players Only";
				tooltip="Only react to and rush toward player-controlled enemies.";
				typeName="BOOL";
				defaultValue="false";
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description[]=
			{
				"Holds synced AI groups in place until enemies are detected nearby, then rushes to assist.",
				"Uses LAMBS Waypoints for advanced tactics when available, otherwise falls back to a vanilla camp/rush implementation.",
				"STEP 1: Sync AI units or groups to this module.",
				"STEP 2: Resize the area circle to set the detection/rush radius.",
				"Players Only: only react to and target player-controlled enemies."
			};
		};
	};
	class FOD_ZA_ModuleHitAndRun: Module_F
	{
		scope=2;
		displayName="Task Hit & Run";
		author="Phenosi";
		category="FOD_ZA_Modules";
		icon="a3\ui_f\data\igui\cfg\simpletasks\types\run_ca.paa";
		picture="a3\ui_f\data\igui\cfg\simpletasks\types\run_ca.paa";
		function="FOD_ZA_fnc_ModuleHitAndRun";
		functionPriority=1;
		isGlobal=0;
		isTriggerActivated=1;
		isDisposable=1;
		is3DEN=1;
		curatorCanAttach=0;
		canSetArea=1;
		canSetAreaShape=1;
		class AttributeValues
		{
			size3[]={200,200,-1};
			isRectangle=0;
		};
		class Attributes: AttributesBase
		{
			class HR_PlayersOnly: Checkbox
			{
				property="FOD_ZA_HR_PlayersOnly";
				expression="_this setVariable ['FOD_ZA_HR_PlayersOnly', _value, true];";
				displayName="Players Only";
				tooltip="Only react to and engage player-controlled enemies.";
				typeName="BOOL";
				defaultValue="false";
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description[]=
			{
				"Sends synced AI groups to hunt the nearest enemy, engage briefly, then break contact and pull back, repeating.",
				"Uses LAMBS Waypoints for advanced tactics when available, otherwise falls back to a vanilla hunt/retreat implementation.",
				"STEP 1: Sync AI units or groups to this module.",
				"STEP 2: Resize the area circle to set the engagement radius.",
				"Players Only: only react to and target player-controlled enemies."
			};
		};
	};
	class FOD_ZA_ModuleSetupAmbush: Module_F
	{
		scope=2;
		displayName="Task Setup Ambush";
		author="Phenosi";
		category="FOD_ZA_Modules";
		icon="a3\ui_f\data\gui\cfg\hints\tactical_view_ca.paa";
		picture="a3\ui_f\data\gui\cfg\hints\tactical_view_ca.paa";
		function="FOD_ZA_fnc_ModuleSetupAmbush";
		functionPriority=1;
		isGlobal=0;
		isTriggerActivated=1;
		isDisposable=1;
		is3DEN=1;
		curatorCanAttach=0;
		canSetArea=1;
		canSetAreaShape=1;
		class AttributeValues
		{
			size3[]={100,100,-1};
			isRectangle=0;
		};
		class Attributes: AttributesBase
		{
			class SA_CoverType: Combo
			{
				property="FOD_ZA_SA_CoverType";
				expression="_this setVariable ['FOD_ZA_SA_CoverType', _value, true];";
				displayName="Cover Type";
				tooltip="What units should use as cover while in ambush.";
				typeName="NUMBER";
				defaultValue="0";
				class Values
				{
					class All
					{
						name="All (Buildings, Walls, Vegetation)";
						value=0;
					};
					class Buildings
					{
						name="Buildings Only";
						value=1;
					};
					class Walls
					{
						name="Walls / Fortifications Only";
						value=2;
					};
					class Vegetation
					{
						name="Vegetation Only";
						value=3;
					};
					class BuildingsVegetation
					{
						name="Buildings + Vegetation";
						value=4;
					};
					class BuildingsWalls
					{
						name="Buildings + Walls";
						value=5;
					};
					class WallsVegetation
					{
						name="Walls + Vegetation";
						value=6;
					};
				};
			};
			class SA_Patrol: Checkbox
			{
				property="FOD_ZA_SA_Patrol";
				expression="_this setVariable ['FOD_ZA_SA_Patrol', _value, true];";
				displayName="Patrol";
				tooltip="Split a small element to patrol the area while the rest hold the ambush.";
				typeName="BOOL";
				defaultValue="false";
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description[]=
			{
				"Moves synced AI groups into cover and holds them silent until contact (ambush).",
				"Uses LAMBS Waypoints for advanced tactics when available, otherwise falls back to a vanilla cover/patrol implementation.",
				"STEP 1: Sync AI units or groups to this module.",
				"STEP 2: Resize the area circle to set the ambush search radius.",
				"Cover Type: what units should use as cover while waiting.",
				"Patrol: a small sub-element patrols the area while the rest hold the ambush."
			};
		};
	};
	class FOD_ZA_ModuleTacticalPush: Module_F
	{
		scope=2;
		displayName="Task Tactical Push";
		author="Phenosi";
		category="FOD_ZA_Modules";
		icon="\FOD_ZA\pictures\FOD_ZA_TacPush_icon";
		picture="\FOD_ZA\pictures\FOD_ZA_TacPush_icon";
		function="FOD_ZA_fnc_ModuleTacticalPush";
		functionPriority=1;
		isGlobal=0;
		isTriggerActivated=1;
		isDisposable=1;
		is3DEN=1;
		curatorCanAttach=0;
		canSetArea=1;
		canSetAreaShape=1;
		class AttributeValues
		{
			size3[]={25,25,-1};
			isRectangle=0;
		};
		class Attributes: AttributesBase
		{
			class TP_BoundDistance: Edit
			{
				property="FOD_ZA_TP_BoundDistance";
				expression="_this setVariable ['FOD_ZA_TP_BoundDistance', _value, true];";
				displayName="Bound Distance";
				tooltip="Distance (m) covered in each push bound before stopping to check for cover or targets.";
				typeName="NUMBER";
				defaultValue="40";
			};
			class TP_PlayersOnly: Checkbox
			{
				property="FOD_ZA_TP_PlayersOnly";
				expression="_this setVariable ['FOD_ZA_TP_PlayersOnly', _value, true];";
				displayName="Players Only";
				tooltip="Only react to and engage player-controlled enemies.";
				typeName="BOOL";
				defaultValue="false";
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description[]=
			{
				"Pushes synced AI groups toward the module position. No LAMBS required.",
				"STEP 1: Sync AI units or groups to this module.",
				"STEP 2: Resize the area circle to set the arrival radius.",
				"Groups sprint toward the module in short bounds (AWARE, FULL speed, standing).",
				"When a group takes fire, it breaks to the nearest cover (or goes prone if none is found within 100 m), returns fire based on each unit's weapon, then resumes the push.",
				"Mounted groups drive toward the module and dismount automatically once close enough.",
				"On arrival, if enemies remain nearby the group clears them before standing down.",
				"Bound Distance: length of each push bound in meters.",
				"Players Only: only react to and target player-controlled enemies."
			};
		};
	};
	class FOD_ZA_ModuleMobilizeQRF: Module_F
	{
		scope=2;
		displayName="Task Mobilize QRF";
		author="Phenosi";
		category="FOD_ZA_Modules";
		icon="a3\soft_f_beta\truck_02\data\ui\truck_02_covered_ca.paa";
		picture="a3\soft_f_beta\truck_02\data\ui\truck_02_covered_ca.paa";
		function="FOD_ZA_fnc_ModuleMobilizeQRF";
		functionPriority=1;
		isGlobal=0;
		isTriggerActivated=1;
		isDisposable=1;
		is3DEN=1;
		curatorCanAttach=0;
		canSetArea=1;
		canSetAreaShape=1;
		class AttributeValues
		{
			size3[]={30,30,-1};
			isRectangle=0;
		};
		class Attributes: AttributesBase
		{
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description[]=
			{
				"Mounts synced AI groups into their nearby transport and rushes them to the nearest allied group in need. No LAMBS required.",
				"STEP 1: Sync AI units or groups (with their transport vehicle) to this module.",
				"STEP 2: Resize the area circle to set the arrival radius near the target ally.",
				"Units who don't fit in the available transport are left behind and removed.",
				"Ground transport drives in, helicopters land and unload, and fixed-wing transport paradrops the troops.",
				"On arrival, vehicle crew splits off as their own group and the dismounted troops take cover, then push the objective; an armed ground transport stays on as a Support Vehicle."
			};
		};
	};
	class FOD_ZA_ModuleSupportVehicle: Module_F
	{
		scope=2;
		displayName="Task Support Vehicle";
		author="Phenosi";
		category="FOD_ZA_Modules";
		icon="\FOD_ZA\pictures\FOD_ZA_SupportVic.paa";
		picture="\FOD_ZA\pictures\FOD_ZA_SupportVic.paa";
		function="FOD_ZA_fnc_ModuleSupportVehicle";
		functionPriority=1;
		isGlobal=0;
		isTriggerActivated=1;
		isDisposable=1;
		is3DEN=1;
		curatorCanAttach=0;
		canSetArea=1;
		canSetAreaShape=1;
		class AttributeValues
		{
			size3[]={50,50,-1};
			isRectangle=0;
		};
		class Attributes: AttributesBase
		{
			class SV_FollowDistance: Edit
			{
				property="FOD_ZA_SV_FollowDistance";
				expression="_this setVariable ['FOD_ZA_SV_FollowDistance', _value, true];";
				displayName="Follow Distance";
				tooltip="How far behind the supported allied group the vehicle stays.";
				typeName="NUMBER";
				defaultValue="50";
			};
			class ModuleDescription: ModuleDescription
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description[]=
			{
				"Sends a synced vehicle group to the nearest allied group in need, then has it follow and support that group from a distance, never overtaking it. No LAMBS required.",
				"Ground vehicles trail and suppress from behind; aircraft loiter overhead and switch to a search-and-destroy pass when an enemy is near.",
				"STEP 1: Sync a vehicle's group to this module.",
				"STEP 2: Resize the area circle to set the search radius for an allied group in need.",
				"Follow Distance: how far behind the supported group the vehicle stays.",
				"The vehicle never disembarks; if it is destroyed or immobilised, control is returned to normal AI."
			};
		};
	};
};
class CfgWaypoints
{
	class FOD_ZA_Tasks
	{
		displayName="[FOD] Zeus Additions";
		class FOD_ZA_TacticalPush
		{
			displayName="Task Tactical Push";
			file="\FOD_ZA\scripts\fod_wpTacticalPush.sqf";
			icon="\FOD_ZA\pictures\FOD_ZA_TacPush_icon.paa";
			tooltip="Group bounds toward the waypoint, taking cover and returning fire when shot at.";
		};
		class FOD_ZA_MobilizeQRF
		{
			displayName="Task Mobilize QRF";
			file="\FOD_ZA\scripts\fod_wpMobilizeQRF.sqf";
			icon="\a3\soft_f_beta\truck_02\data\ui\truck_02_covered_ca.paa";
			tooltip="Group mounts its transport and rushes to the waypoint, dismounting on arrival.";
		};
		class FOD_ZA_SupportVehicle
		{
			displayName="Task Support Vehicle";
			file="\FOD_ZA\scripts\fod_wpSupportVehicle.sqf";
			icon="\FOD_ZA\pictures\FOD_ZA_SupportVic.paa";
			tooltip="Vehicle anchors onto the nearest allied group near the waypoint and supports it from a distance.";
		};
		class FOD_ZA_Ambush
		{
			displayName="Task Setup Ambush";
			file="\FOD_ZA\scripts\fod_wpAmbush.sqf";
			icon="\FOD_ZA\pictures\FOD_ZA_SetupAmbush_icon.paa";
			tooltip="Group moves into cover near the waypoint and holds silent until contact.";
		};
		class FOD_ZA_Reserve
		{
			displayName="Task Reserve/QRF";
			file="\FOD_ZA\scripts\fod_wpReserve.sqf";
			icon="\FOD_ZA\pictures\FOD_ZA_ReserveQRF_icon.paa";
			tooltip="Group holds at the waypoint until enemy contact, then rushes to engage.";
		};
		class FOD_ZA_HitAndRun
		{
			displayName="Task Hit & Run";
			file="\FOD_ZA\scripts\fod_wpHitAndRun.sqf";
			icon="\a3\ui_f\data\igui\cfg\simpletasks\types\run_ca.paa";
			tooltip="Group engages near the waypoint, breaks contact, retreats, and repeats.";
		};
	};
};
class ZEN_WaypointTypes
{
	class fod_za_TacticalPush
	{
		displayName="Tactical Push";
		type="SCRIPTED";
		script="\FOD_ZA\scripts\fod_wpTacticalPush.sqf";
	};
	class fod_za_MobilizeQRF
	{
		displayName="Mobilize QRF";
		type="SCRIPTED";
		script="\FOD_ZA\scripts\fod_wpMobilizeQRF.sqf";
	};
	class fod_za_SupportVehicle
	{
		displayName="Support Vehicle";
		type="SCRIPTED";
		script="\FOD_ZA\scripts\fod_wpSupportVehicle.sqf";
	};
	class fod_za_Ambush
	{
		displayName="Setup Ambush";
		type="SCRIPTED";
		script="\FOD_ZA\scripts\fod_wpAmbush.sqf";
	};
	class fod_za_Reserve
	{
		displayName="Reserve/QRF";
		type="SCRIPTED";
		script="\FOD_ZA\scripts\fod_wpReserve.sqf";
	};
	class fod_za_HitAndRun
	{
		displayName="Hit & Run";
		type="SCRIPTED";
		script="\FOD_ZA\scripts\fod_wpHitAndRun.sqf";
	};
};
class ZEN_context_menu_actions
{
	class FOD_ZA_wp
	{
		displayName="FOD: ZA Waypoints";
		priority=2;
		condition="(_groups isNotEqualTo []) || (_objects isNotEqualTo [])";
		class A_TacticalPush
		{
			displayName="Task Tactical Push";
			statement="private _allGroups = +_groups; { _allGroups pushBackUnique (group _x); } forEach _objects; { [_x, ([_x, getPosATL (leader _x)] call FOD_ZA_fnc_findNearestEnemyPos), 25, 40] call FOD_ZA_fnc_taskTacticalPushToggle } forEach _allGroups;";
			icon="\FOD_ZA\pictures\FOD_ZA_TacPush_icon.paa";
		};
		class A_MobilizeQRF
		{
			displayName="Task Mobilize QRF";
			statement="private _allGroups = +_groups; { _allGroups pushBackUnique (group _x); } forEach _objects; { private _targetInfo = [_x, getPosATL (leader _x)] call FOD_ZA_fnc_findNearestAllyPos; [_x, (_targetInfo select 0), 30, (_targetInfo select 1), true] spawn FOD_ZA_fnc_taskMobilizeQRF } forEach _allGroups;";
			icon="a3\data_f_tacops\images\achtobeyondhope.jpg";
		};
		class A_SupportVehicle
		{
			displayName="Task Support Vehicle";
			statement="private _allGroups = +_groups; { _allGroups pushBackUnique (group _x); } forEach _objects; { [_x, ([_x, getPosATL (leader _x)] call FOD_ZA_fnc_findNearestAllyPos) select 0, 50] call FOD_ZA_fnc_taskSupportVehicleToggle } forEach _allGroups;";
			icon="a3\data_f_tacops\images\achtolifeline.jpg";
		};
		class A_SetupAmbush
		{
			displayName="Task Setup Ambush";
			statement="private _allGroups = +_groups; { _allGroups pushBackUnique (group _x); } forEach _objects; { [_x, _position, 100, [], false, 0, true, false] spawn FOD_ZA_fnc_taskEntrench } forEach _allGroups;";
			icon="a3\ui_f\data\gui\cfg\hints\tactical_view_ca.paa";
		};
		class A_HitAndRun
		{
			displayName="Task Hit & Run";
			statement="private _allGroups = +_groups; { _allGroups pushBackUnique (group _x); } forEach _objects; { [_x, _position, 200] spawn FOD_ZA_fnc_taskHitAndRun } forEach _allGroups;";
			icon="a3\ui_f\data\igui\cfg\simpletasks\types\run_ca.paa";
		};
		class A_Reserve
		{
			displayName="Task Reserve/QRF";
			statement="private _allGroups = +_groups; { _allGroups pushBackUnique (group _x); } forEach _objects; { [_x, 100] spawn FOD_ZA_fnc_taskReserve } forEach _allGroups;";
			icon="\FOD_ZA\pictures\FOD_ZA_ReserveQRF_icon.paa";
		};
	};
};
class cfgMods
{
	author="Phenosi";
	timepacked="1782394871";
};
