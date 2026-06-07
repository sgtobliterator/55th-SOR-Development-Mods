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
	class 3denEnhanced
	{
		author="R3vo";
		is3DENMod=1;
		name="3den Enhanced - Main";
		requiredAddons[]=
		{
			"3DEN",
			"A3_Data_F_Decade_Loadorder"
		};
		requiredVersion=2.1800001;
		url="https://steamcommunity.com/sharedfiles/filedetails/?id=623475643";
		units[]={};
		weapons[]={};
	};
};
class Cfg3DEN
{
	class Notifications
	{
		class ENH_DataCopied
		{
			isWarning=0;
			text="$STR_A3_RSCDISPLAYARSENAL_MESSAGE_CLIPBOARD";
		};
		class ENH_ActionPerformed
		{
			isWarning=0;
			text="$STR_ENH_MAIN_NOTIFICATIONS_ACTIONPERFORMED";
		};
		class ENH_NoEntitiesSelected
		{
			isWarning=1;
			text="$STR_ENH_MAIN_NOTIFICATIONS_NOENTITIESSELECTED";
		};
		class ENH_NoEntitiesWithInventorySelected
		{
			isWarning=1;
			text="$STR_ENH_MAIN_NOTIFICATIONS_NOENTITIESWITHINVENTORYSELECTED";
		};
		class ENH_GetPythiaMod_Warning
		{
			isWarning=1;
			text="$STR_ENH_MAIN_NOTIFICATIONS_GETPYTHIA";
		};
		class ENH_PythiaMissingForBackup
		{
			isWarning=1;
			text="$STR_ENH_MAIN_NOTIFICATIONS_BACKUP_FAILED";
		};
		class ENH_SelectSecondPoint
		{
			isWarning=0;
			text="$STR_ENH_MAIN_MEASUREDISTANCE_SELECT2NDPOINT";
		};
		class ENH_NotEnoughBuildingPositions
		{
			isWarning=1;
			text="$STR_ENH_MAIN_GARRISON_NOTIFICATION";
		};
		class ENH_AlignEntities_WrongIndexValue
		{
			isWarning=1;
			text="$STR_ENH_MAIN_NOTIFICATIONS_ALIGN_ENTITIES_WRONG_INDEX";
		};
		class ENH_Garrison2_Disabled
		{
			isWarning=0;
			text="$STR_ENH_MAIN_NOTIFICATIONS_GARRISON2_DISABLED";
		};
		class ENH_Garrison2_Enabled
		{
			isWarning=0;
			text="$STR_ENH_MAIN_NOTIFICATIONS_GARRISON2_ENABLED";
		};
		class ENH_Garrison2_2D_Not_Supported
		{
			isWarning=1;
			text="$STR_ENH_MAIN_NOTIFICATIONS_GARRISON2_2D_NOT_SUPPORTED";
		};
		class ENH_Garrison2_All_Positions_Taken
		{
			isWarning=1;
			text="$STR_ENH_MAIN_NOTIFICATIONS_GARRISON2_ALL_POSITIONS_TAKEN";
		};
	};
	class EventHandlers
	{
		class ENH
		{
			init="call ENH_fnc_EH_init";
			onTerrainNew="call ENH_fnc_EH_onTerrainNew";
			onMissionPreviewEnd="call ENH_fnc_EH_onMissionPreviewEnd";
			onMissionLoad="call ENH_fnc_EH_onMissionLoad";
			onMissionNew="call ENH_fnc_EH_onMissionNew";
			onMissionPreview="call ENH_fnc_EH_onMissionPreview";
			onMissionSave="call ENH_fnc_createBackupMissionSQM";
			onMissionAutoSave="call ENH_fnc_createBackupMissionSQM";
		};
	};
	class Attributes
	{
		class Default;
		class Title: Default
		{
			class Controls
			{
				class Title: ctrlStatic
				{
					onLoad="_this spawn ENH_fnc_adjustTitleTextWidth";
				};
			};
		};
		class Slider: Title
		{
			class Controls;
		};
		class SliderMultiplier: Slider
		{
			class Controls: Controls
			{
				class Title;
				class Edit;
				class Value;
			};
		};
		class ENH_AdvancedDamage: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_advancedDamage_onAttributeLoad";
			attributeSave="_this call ENH_fnc_advancedDamage_onAttributeSave";
			class Controls: Controls
			{
			};
		};
		class ENH_Airdrop: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_airdrop_onAttributeLoad";
			attributeSave="_this call ENH_fnc_airdrop_onAttributeSave";
			h="11 * (5 * (pixelH * pixelGrid * 0.50)) + 35 * pixelH";
			class Controls: Controls
			{
				class ClassesTitle: Title
				{
					text="$STR_ENH_MAIN_AIRDROP_CLASSES_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_AIRDROP_CLASSES_TOOLTIP";
					h="4 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class ClassesValue: ctrlEditMulti
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="4 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class CenterTitle: Title
				{
					text="$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_DISPLAYNAME";
					tooltip="$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_TOOLTIP";
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class CenterTitleX: ENH_3DEN_Attribute_Control_TitleX
				{
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class CenterValueX: ENH_3DEN_Attribute_Control_ValueX
				{
					idc=1001;
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class CenterTitleY: ENH_3DEN_Attribute_Control_TitleY
				{
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class CenterValueY: ENH_3DEN_Attribute_Control_ValueY
				{
					idc=1002;
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class CenterTitleZ: ENH_3DEN_Attribute_Control_TitleZ
				{
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class CenterValueZ: ENH_3DEN_Attribute_Control_ValueZ
				{
					idc=1003;
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="(82 / 3 - 5 - 5) * (pixelW * pixelGrid * 0.50)";
				};
				class PasteStartValueFromClipboard: ENH_3DEN_Attribute_Control_ValueFromClipboard
				{
					idc=1004;
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class ConditionTitle: Title
				{
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
					text="$STR_ENH_MAIN_AIRDROP_CONDITION_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_AIRDROP_CONDITION_TOOLTIP";
				};
				class ConditionValue: ctrlEdit
				{
					idc=1005;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class AltitudeTitle: Title
				{
					y="6 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
					text="$STR_ENH_MAIN_ALTITUDE_DISPLAYNAME";
				};
				class AltitudeTitleA: ENH_3DEN_Attribute_Control_TitleAltitude
				{
					y="6 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class AltitudeValueA: ENH_3DEN_Attribute_Control_ValueA
				{
					idc=1006;
					y="6 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class RadiusTitle: Title
				{
					text="$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_DISPLAYNAME";
					tooltip="$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_TOOLTIP";
					y="7 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
				class RadiusTitleR: ENH_3DEN_Attribute_Control_TitleR
				{
					y="7 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
				class RadiusValueR: ENH_3DEN_Attribute_Control_ValueA
				{
					idc=1007;
					y="7 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
				class SideTitle: Title
				{
					text="$STR_ENH_MAIN_SIDE_DISPLAYNAME";
					y="8 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
					h="2 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class SideValue: ENH_3DEN_Attribute_Control_SideToolbox
				{
					idc=1008;
					y="8 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
					h="2 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class Reset: ENH_3DEN_Attribute_Control_ResetButton
				{
					y="10 * (5 * (pixelH * pixelGrid * 0.50)) + 30 * pixelH";
				};
			};
		};
		class ENH_AmbientAnimations: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_ambientAnimations_onAttributeLoad";
			attributeSave="_this call ENH_fnc_ambientAnimations_onAttributeSave";
			h="4 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
			class Controls: Controls
			{
				class AnimTitle: Title
				{
					text="$STR_ENH_MAIN_AMBIENTANIMATIONS_ANIMATION_DISPLAYNAME";
				};
				class Animation: ctrlCombo
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class CanExitTitle: Title
				{
					text="$STR_ENH_MAIN_AMBIENTANIMATIONS_CANEXIT_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_AMBIENTANIMATIONS_CANEXIT_TOOLTIP";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class CanExit: ctrlCheckbox
				{
					idc=1001;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class AttachTitle: Title
				{
					text="$STR_ENH_MAIN_AMBIENTANIMATIONS_ATTACH_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_AMBIENTANIMATIONS_ATTACH_TOOLTIP";
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class Attach: CanExit
				{
					idc=1002;
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class Reset: ENH_3DEN_Attribute_Control_ResetButton
				{
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
			};
		};
		class ENH_AmbientFlyby: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_ambientFlyby_onAttributeLoad";
			attributeSave="_this call ENH_fnc_ambientFlyby_onAttributeSave";
			h="22 * (5 * (pixelH * pixelGrid * 0.50)) + 50 * pixelH";
			class Controls: Controls
			{
				class Search: ctrlEdit
				{
					idc=1015;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="(82 - 5) * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					text="";
				};
				class SearchButton: ctrlButtonSearch
				{
					idc=1016;
					x="(48 + 82 - 5) * (pixelW * pixelGrid * 0.50)";
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class ClassesTitle: Title
				{
					text="$STR_ENH_MAIN_AMBIENTFLYBY_CLASSES_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_AMBIENTFLYBY_CLASSES_TOOLTIP";
					y="1 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					h="10 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class ClassesValue: ctrlTree
				{
					idc=1017;
					idcSearch=1015;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="1 * (5 * (pixelH * pixelGrid * 0.50))";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="10 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class StartTitle: Title
				{
					text="$STR_ENH_MAIN_AMBIENTFLYBY_STARTPOSITION_DISPLAYNAME";
					tooltip="$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_TOOLTIP";
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class StartTitleX: ENH_3DEN_Attribute_Control_TitleX
				{
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class StartValueX: ENH_3DEN_Attribute_Control_ValueX
				{
					idc=1001;
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class StartTitleY: ENH_3DEN_Attribute_Control_TitleY
				{
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class StartValueY: ENH_3DEN_Attribute_Control_ValueY
				{
					idc=1002;
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class StartTitleZ: ENH_3DEN_Attribute_Control_TitleZ
				{
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class StartValueZ: ENH_3DEN_Attribute_Control_ValueZ
				{
					idc=1003;
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="(82 / 3 - 5 - 5) * (pixelW * pixelGrid * 0.50)";
				};
				class PasteStartValueFromClipboard: ENH_3DEN_Attribute_Control_ValueFromClipboard
				{
					idc=1015;
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class StartRndOffsetTitle: Title
				{
					text="$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_DISPLAYNAME";
					tooltip="$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_TOOLTIP";
					y="12 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class StartRndOffsetTitleA: ENH_3DEN_Attribute_Control_TitleR
				{
					y="12 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class StartRndOffsetValueA: ENH_3DEN_Attribute_Control_ValueA
				{
					idc=1004;
					y="12 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class EndTitle: Title
				{
					text="$STR_ENH_MAIN_AMBIENTFLYBY_ENDPOSITION_DISPLAYNAME";
					tooltip="$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_TOOLTIP";
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class EndTitleX: ENH_3DEN_Attribute_Control_TitleX
				{
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class EndValueX: ENH_3DEN_Attribute_Control_ValueX
				{
					idc=1005;
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class EndTitleY: ENH_3DEN_Attribute_Control_TitleY
				{
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class EndValueY: ENH_3DEN_Attribute_Control_ValueY
				{
					idc=1006;
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class EndTitleZ: ENH_3DEN_Attribute_Control_TitleZ
				{
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class PasteEndValueFromClipboard: ENH_3DEN_Attribute_Control_ValueFromClipboard
				{
					idc=1016;
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class EndValueZ: StartValueZ
				{
					idc=1007;
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class EndRndOffsetTitle: StartRndOffsetTitle
				{
					y="14 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
				class EndRndOffsetTitleA: ENH_3DEN_Attribute_Control_TitleR
				{
					y="14 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
				class EndRndOffsetValueA: ENH_3DEN_Attribute_Control_ValueA
				{
					idc=1008;
					y="14 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
				class AltitudeTitle: Title
				{
					y="15 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
					text="$STR_ENH_MAIN_ALTITUDE_DISPLAYNAME";
				};
				class AltitudeTitleA: ENH_3DEN_Attribute_Control_TitleAltitude
				{
					y="15 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
				};
				class AltitudeValueZ: ENH_3DEN_Attribute_Control_ValueZ_Front
				{
					idc=1009;
					y="15 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
				};
				class SpeedTitle: Title
				{
					y="16 * (5 * (pixelH * pixelGrid * 0.50)) + 30 * pixelH";
					h="2 * (5 * (pixelH * pixelGrid * 0.50))";
					text="$STR_ENH_MAIN_AMBIENTFLYBY_SPEED_DISPLAYNAME";
				};
				class SpeedValue: ctrlToolboxPictureKeepAspect
				{
					idc=1010;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="16 * (5 * (pixelH * pixelGrid * 0.50)) + 30 * pixelH";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="2 * (5 * (pixelH * pixelGrid * 0.50))";
					rows=1;
					columns=3;
					strings[]=
					{
						"\a3\3DEN\Data\Attributes\SpeedMode\limited_ca.paa",
						"\a3\3DEN\Data\Attributes\SpeedMode\normal_ca.paa",
						"\a3\3DEN\Data\Attributes\SpeedMode\full_ca.paa"
					};
					tooltips[]=
					{
						"$STR_ENH_MAIN_SPEED_LIMITED",
						"$STR_ENH_MAIN_SPEED_NORMAL",
						"$STR_ENH_MAIN_SPEED_FULL"
					};
					values[]={0,1,2};
				};
				class SideTitle: Title
				{
					y="18 * (5 * (pixelH * pixelGrid * 0.50)) + 35 * pixelH";
					h="2 * (5 * (pixelH * pixelGrid * 0.50))";
					text="$STR_ENH_MAIN_SIDE_DISPLAYNAME";
				};
				class SideValue: ENH_3DEN_Attribute_Control_SideToolbox
				{
					idc=1011;
					y="18 * (5 * (pixelH * pixelGrid * 0.50)) + 35 * pixelH";
				};
				class DelayTitle: Title
				{
					text="$STR_3DEN_TRIGGER_ATTRIBUTE_TIMEOUT_DISPLAYNAME";
					y="20 * (5 * (pixelH * pixelGrid * 0.50)) + 40 * pixelH";
				};
				class DelayTitleMin: ENH_3DEN_Attribute_Control_TitleMin
				{
					y="20 * (5 * (pixelH * pixelGrid * 0.50)) + 40 * pixelH";
				};
				class DelayValueMin: ENH_3DEN_Attribute_Control_ValueMin
				{
					idc=1012;
					y="20 * (5 * (pixelH * pixelGrid * 0.50)) + 40 * pixelH";
				};
				class DelayTitleMid: ENH_3DEN_Attribute_Control_TitleMid
				{
					y="20 * (5 * (pixelH * pixelGrid * 0.50)) + 40 * pixelH";
				};
				class DelayValueMid: ENH_3DEN_Attribute_Control_ValueMid
				{
					idc=1013;
					y="20 * (5 * (pixelH * pixelGrid * 0.50)) + 40 * pixelH";
				};
				class DelayTitleMax: ENH_3DEN_Attribute_Control_TitleMax
				{
					y="20 * (5 * (pixelH * pixelGrid * 0.50)) + 40 * pixelH";
				};
				class DelayValueMax: ENH_3DEN_Attribute_Control_ValueMax
				{
					idc=1014;
					y="20 * (5 * (pixelH * pixelGrid * 0.50)) + 40 * pixelH";
				};
				class Reset: ENH_3DEN_Attribute_Control_ResetButton
				{
					y="21 * (5 * (pixelH * pixelGrid * 0.50)) + 45 * pixelH";
				};
			};
		};
		class ENH_CfgMusic: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_cfgMusic_onAttributeLoad";
			attributeSave="_this call ENH_fnc_cfgMusic_onAttributeSave";
			h="12 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
			class Controls: Controls
			{
				class Search: ctrlEdit
				{
					idc=1024;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="(82 - 5) * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					text="";
				};
				class SearchButton: ctrlButtonSearch
				{
					idc=1025;
					x="(48 + 82 - 5) * (pixelW * pixelGrid * 0.50)";
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class ClassesTitle: Title
				{
					text="$STR_ENH_MAIN_RANDOMMUSIC_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_RANDOMMUSIC_TOOLTIP";
					y="1 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					h="10 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class ClassesValue: ctrlTree
				{
					idc=1000;
					idcSearch=1024;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="1 * (5 * (pixelH * pixelGrid * 0.50))";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="10 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class Reset: ENH_3DEN_Attribute_Control_ResetButton
				{
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
			};
		};
		class ENH_DynamicSkill: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_dynamicSkill_onAttributeLoad";
			attributeSave="_this call ENH_fnc_dynamicSkill_onAttributeSave";
			h="17 * (5 * (pixelH * pixelGrid * 0.50)) + 90 * pixelH";
			class Controls: Controls
			{
				class EnableTitle: Title
				{
					text="$STR_ENH_MAIN_ENABLE";
				};
				class Enable: ctrlCheckbox
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class BLUFORDescriptionDeco: ctrlStatic
				{
					x="5 * (pixelW * pixelGrid * 0.50)";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
					w="5 * pixelW";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					colorBackground[]={1,1,1,0.050000001};
				};
				class BLUFORDescriptionHeader: ctrlStatic
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_BLUFORSKILL_DISPLAYNAME";
					x="5 * (pixelW * pixelGrid * 0.50) + 7 * pixelW";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
					w="(48 + 82 - 4) * (pixelW * pixelGrid * 0.50) - 7 * pixelW";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					colorText[]={1,1,1,0.40000001};
					colorBackground[]={1,1,1,0.050000001};
					colorShadow[]={0,0,0,0};
				};
				class SkillMinBLUFORTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLMIN_DISPLAYNAME";
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class SkillMinBLUFORValue: ctrlXSliderH
				{
					idc=1001;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
					w="(82 - 11) * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					sliderRange[]={0.2,1};
				};
				class SkillMinBLUFOREdit: ctrlEdit
				{
					idc=1002;
					x="(48 + 82 - 11) * (pixelW * pixelGrid * 0.50)";
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
					w="11 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class SkillAimMinBLUFORTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME";
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
				class SkillAimMinBLUFORValue: SkillMinBLUFORValue
				{
					idc=1003;
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
				class SkillAimMinBLUFOREdit: SkillMinBLUFOREdit
				{
					idc=1004;
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
				class SkillMaxBLUFORTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLMAX_DISPLAYNAME";
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
				};
				class SkillMaxBLUFORValue: SkillMinBLUFORValue
				{
					idc=1005;
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
				};
				class SkillMaxBLUFOREdit: SkillMinBLUFOREdit
				{
					idc=1006;
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
				};
				class SkillAimMaxBLUFORTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME";
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 30 * pixelH";
				};
				class SkillAimMaxBLUFORValue: SkillMinBLUFORValue
				{
					idc=1007;
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 30 * pixelH";
				};
				class SkillAimMaxBLUFOREdit: SkillMinBLUFOREdit
				{
					idc=1008;
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 30 * pixelH";
				};
				class OPFORDescriptionDeco: BLUFORDescriptionDeco
				{
					y="6 * (5 * (pixelH * pixelGrid * 0.50)) + 35 * pixelH";
				};
				class OPFORDescriptionHeader: BLUFORDescriptionHeader
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_OPFORSKILL_DISPLAYNAME";
					y="6 * (5 * (pixelH * pixelGrid * 0.50)) + 35 * pixelH";
				};
				class SkillMinOPFORTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLMIN_DISPLAYNAME";
					y="7 * (5 * (pixelH * pixelGrid * 0.50)) + 40 * pixelH";
				};
				class SkillMinOPFORValue: SkillMinBLUFORValue
				{
					idc=1009;
					y="7 * (5 * (pixelH * pixelGrid * 0.50)) + 40 * pixelH";
				};
				class SkillMinOPFOREdit: SkillMinBLUFOREdit
				{
					idc=1010;
					y="7 * (5 * (pixelH * pixelGrid * 0.50)) + 40 * pixelH";
				};
				class SkillAimMinOPFORTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME";
					y="8 * (5 * (pixelH * pixelGrid * 0.50)) + 45 * pixelH";
				};
				class SkillAimMinOPFORValue: SkillMinBLUFORValue
				{
					idc=1011;
					y="8 * (5 * (pixelH * pixelGrid * 0.50)) + 45 * pixelH";
				};
				class SkillAimMinOPFOREdit: SkillMinBLUFOREdit
				{
					idc=1012;
					y="8 * (5 * (pixelH * pixelGrid * 0.50)) + 45 * pixelH";
				};
				class SkillMaxOPFORTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLMAX_DISPLAYNAME";
					y="9 * (5 * (pixelH * pixelGrid * 0.50)) + 50 * pixelH";
				};
				class SkillMaxOPFORValue: SkillMinBLUFORValue
				{
					idc=1013;
					y="9 * (5 * (pixelH * pixelGrid * 0.50)) + 50 * pixelH";
				};
				class SkillMaxOPFOREdit: SkillMinBLUFOREdit
				{
					idc=1014;
					y="9 * (5 * (pixelH * pixelGrid * 0.50)) + 50 * pixelH";
				};
				class SkillAimMaxOPFORTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME";
					y="10 * (5 * (pixelH * pixelGrid * 0.50)) + 55 * pixelH";
				};
				class SkillAimMaxOPFORValue: SkillMinBLUFORValue
				{
					idc=1015;
					y="10 * (5 * (pixelH * pixelGrid * 0.50)) + 55 * pixelH";
				};
				class SkillAimMaxOPFOREdit: SkillMinBLUFOREdit
				{
					idc=1016;
					y="10 * (5 * (pixelH * pixelGrid * 0.50)) + 55 * pixelH";
				};
				class IndependentDescriptionDeco: BLUFORDescriptionDeco
				{
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 60 * pixelH";
				};
				class IndependentDescriptionHeader: BLUFORDescriptionHeader
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_IndependentSKILL_DISPLAYNAME";
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 60 * pixelH";
				};
				class SkillMinIndependentTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLMIN_DISPLAYNAME";
					y="12 * (5 * (pixelH * pixelGrid * 0.50)) + 65 * pixelH";
				};
				class SkillMinIndependentValue: SkillMinBLUFORValue
				{
					idc=1017;
					y="12 * (5 * (pixelH * pixelGrid * 0.50)) + 65 * pixelH";
				};
				class SkillMinIndependentEdit: SkillMinBLUFOREdit
				{
					idc=1018;
					y="12 * (5 * (pixelH * pixelGrid * 0.50)) + 65 * pixelH";
				};
				class SkillAimMinIndependentTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMIN_DISPLAYNAME";
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 70 * pixelH";
				};
				class SkillAimMinIndependentValue: SkillMinBLUFORValue
				{
					idc=1019;
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 70 * pixelH";
				};
				class SkillAimMinIndependentEdit: SkillMinBLUFOREdit
				{
					idc=1020;
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 70 * pixelH";
				};
				class SkillMaxIndependentTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLMAX_DISPLAYNAME";
					y="14 * (5 * (pixelH * pixelGrid * 0.50)) + 75 * pixelH";
				};
				class SkillMaxIndependentValue: SkillMinBLUFORValue
				{
					idc=1021;
					y="14 * (5 * (pixelH * pixelGrid * 0.50)) + 75 * pixelH";
				};
				class SkillMaxIndependentEdit: SkillMinBLUFOREdit
				{
					idc=1022;
					y="14 * (5 * (pixelH * pixelGrid * 0.50)) + 75 * pixelH";
				};
				class SkillAimMaxIndependentTitle: Title
				{
					text="$STR_ENH_MAIN_DYNAMICSKILL_SKILLAIMMAX_DISPLAYNAME";
					y="15 * (5 * (pixelH * pixelGrid * 0.50)) + 80 * pixelH";
				};
				class SkillAimMaxIndependentValue: SkillMinBLUFORValue
				{
					idc=1023;
					y="15 * (5 * (pixelH * pixelGrid * 0.50)) + 80 * pixelH";
				};
				class SkillAimMaxIndependentEdit: SkillMinBLUFOREdit
				{
					idc=1024;
					y="15 * (5 * (pixelH * pixelGrid * 0.50)) + 80 * pixelH";
				};
				class Reset: ENH_3DEN_Attribute_Control_ResetButton
				{
					y="16 * (5 * (pixelH * pixelGrid * 0.50)) + 85 * pixelH";
				};
			};
		};
		class ENH_EstablishingShot: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_establishingShot_onAttributeLoad";
			attributeSave="_this call ENH_fnc_establishingShot_onAttributeSave";
			h="8 * (5 * (pixelH * pixelGrid * 0.50)) + 35 * pixelH";
			class Controls: Controls
			{
				class CenterTitle: Title
				{
					text="$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_DISPLAYNAME";
					tooltip="$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_TOOLTIP";
				};
				class CenterTitleX: ENH_3DEN_Attribute_Control_TitleX
				{
				};
				class CenterValueX: ENH_3DEN_Attribute_Control_ValueX
				{
					idc=1000;
				};
				class CenterTitleY: ENH_3DEN_Attribute_Control_TitleY
				{
				};
				class CenterValueY: ENH_3DEN_Attribute_Control_ValueY
				{
					idc=1001;
				};
				class CenterTitleZ: ENH_3DEN_Attribute_Control_TitleZ
				{
				};
				class CenterValueZ: ENH_3DEN_Attribute_Control_ValueZ
				{
					idc=1002;
					w="(82 / 3 - 5 - 5) * (pixelW * pixelGrid * 0.50)";
				};
				class PasteStartValueFromClipboard: ENH_3DEN_Attribute_Control_ValueFromClipboard
				{
					idc=1003;
				};
				class TextTitle: Title
				{
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					text="$STR_ENH_MAIN_ESTABLISHINGSHOT_DISPLAYEDTEXT";
				};
				class TextValue: ctrlEdit
				{
					idc=1004;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="(82) * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class AltitudeTitle: Title
				{
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
					text="$STR_ENH_MAIN_ALTITUDE_DISPLAYNAME";
				};
				class AltitudeTitleA: ENH_3DEN_Attribute_Control_TitleAltitude
				{
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class AltitudeValueA: ENH_3DEN_Attribute_Control_ValueA
				{
					idc=1005;
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class RadiusTitle: Title
				{
					text="$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_DISPLAYNAME";
					tooltip="$STR_3DEN_OBJECT_ATTRIBUTE_PLACEMENT_TOOLTIP";
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class RadiusTitleR: ENH_3DEN_Attribute_Control_TitleR
				{
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class RadiusValueR: ENH_3DEN_Attribute_Control_ValueA
				{
					idc=1006;
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class AngleTitle: Title
				{
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
					text="$STR_ENH_MAIN_ESTABLISHINGSHOT_VIEWINGANGLE_DISPLAYNAME";
				};
				class AngleValue: ctrlXSliderH
				{
					idc=1007;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					w="(82 - 11) * (pixelW * pixelGrid * 0.50)";
					sliderPosition=45;
					sliderRange[]={0,360};
					sliderStep=5;
					lineSize=5;
				};
				class AngleEdit: ctrlEdit
				{
					idc=1008;
					x="(48 + 82 - 11) * (pixelW * pixelGrid * 0.50)";
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
					w="11 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class DirectionTitle: Title
				{
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
					w="48 * (pixelW * pixelGrid * 0.50)";
					h="2 * (5 * (pixelH * pixelGrid * 0.50))";
					text="$STR_ENH_MAIN_ESTABLISHINGSHOT_DIRECTION_DISPLAYNAME";
				};
				class DirectionValue: ctrlToolbox
				{
					idc=1009;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="2 * (5 * (pixelH * pixelGrid * 0.50))";
					rows=2;
					columns=1;
					strings[]=
					{
						"$STR_ENH_MAIN_ESTABLISHINGSHOT_ANTICLOCKWISE",
						"$STR_ENH_MAIN_ESTABLISHINGSHOT_CLOCKWISE"
					};
					values[]={0,1};
				};
				class Reset: ENH_3DEN_Attribute_Control_ResetButton
				{
					y="7 * (5 * (pixelH * pixelGrid * 0.50)) + 30 * pixelH";
				};
			};
		};
		class ENH_GroupMarker: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_groupMarker_onAttributeLoad";
			attributeSave="_this call ENH_fnc_groupMarker_onAttributeSave";
			h="6 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
			class Controls: Controls
			{
				class TypeTitle: Title
				{
					text="$STR_ENH_MAIN_GROUPMARKER_TYPE";
					tooltip="$STR_3DEN_MARKER_ATTRIBUTE_TYPE_TOOLTIP";
				};
				class Type: ctrlCombo
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					colorBackground[]={0.1,0.1,0.1,1};
					onLoad="_this spawn ENH_fnc_groupMarker_onLoad";
				};
				class ColorTitle: Title
				{
					text="$STR_ENH_MAIN_GROUPMARKER_COLOR";
					tooltip="$STR_3DEN_MARKER_ATTRIBUTE_COLOR_TOOLTIP";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class Color: Type
				{
					idc=1001;
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					onload="";
				};
				class TextTitle: Title
				{
					text="$STR_ENH_MAIN_GROUPMARKER_TEXT";
					tooltip="$STR_3DEN_MARKER_ATTRIBUTE_TEXT_TOOLTIP";
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class Text: ctrlEdit
				{
					idc=1002;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class ShowGroupSizeTitle: Title
				{
					text="$STR_ENH_MAIN_GROUPMARKER_SHOWGROUPSIZE";
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class ShowGroupSize: ctrlCheckbox
				{
					idc=1003;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class ShowGroupVehicleTitle: Title
				{
					text="$STR_ENH_MAIN_GROUPMARKER_VEHICLENAME";
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class ShowGroupVehicle: ctrlCheckbox
				{
					idc=1004;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class Reset: ENH_3DEN_Attribute_Control_ResetButton
				{
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
			};
		};
		class ENH_HoldAction: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_holdAction_onAttributeLoad";
			attributeSave="_this call ENH_fnc_holdAction_onAttributeSave";
			h="41 * (5 * (pixelH * pixelGrid * 0.50)) + 75 * pixelH";
			class Controls: Controls
			{
				class NameTitle: Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_NAME_DISPLAYNAME";
				};
				class Name: ctrlEdit
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class IdleIconTitle: Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_ICONIDLE_DISPLAYNAME";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					h="2 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class IdleIconBackground: ctrlStaticBackground
				{
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="10 * (pixelW * pixelGrid * 0.50)";
					h="2 * (5 * (pixelH * pixelGrid * 0.50))";
					colorBackground[]={0,0,0,0.30000001};
				};
				class IdleIcon: ctrlActivePictureKeepAspect
				{
					idc=1001;
					text="a3\weapons_f\data\placeholder_co.paa";
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="10 * (pixelW * pixelGrid * 0.50)";
					h="2 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class ProgressIconTitle: IdleIconTitle
				{
					text="$STR_ENH_MAIN_HOLDACTION_ICONPROGRESS_DISPLAYNAME";
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class ProgressIconBackground: IdleIconBackground
				{
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class ProgressIcon: IdleIcon
				{
					idc=1002;
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class ConditionShowBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
				{
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50) + 15 * pixelH";
				};
				class ConditionShowTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_CONDITIONSHOW_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_HOLDACTION_CONDITIONSHOW_TOOLTIP";
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class ConditionShow: ENH_3DEN_Attribute_Control_EditMulti5_Edit
				{
					idc=1003;
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * (pixelH * pixelGrid * 0.50) + 15 * pixelH";
					autocomplete="scripting";
				};
				class ConditionProgressBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
				{
					y="10 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50) + 20 * pixelH";
				};
				class ConditionProgressTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_CONDITIONPROGRESS_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_HOLDACTION_CONDITIONPROGRESS_TOOLTIP";
					y="10 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
				class ConditionProgress: ENH_3DEN_Attribute_Control_EditMulti5_Edit
				{
					idc=1004;
					y="10 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * (pixelH * pixelGrid * 0.50) + 20 * pixelH";
					autocomplete="scripting";
				};
				class CodeStartBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
				{
					y="15 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50) + 25 * pixelH";
				};
				class CodeStartTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_CODESTART_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_HOLDACTION_CODESTART_TOOLTIP";
					y="15 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
				};
				class CodeStart: ENH_3DEN_Attribute_Control_EditMulti5_Edit
				{
					idc=1005;
					y="15 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * (pixelH * pixelGrid * 0.50) + 25 * pixelH";
					autocomplete="scripting";
				};
				class CodeProgressBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
				{
					y="20 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50) + 30 * pixelH";
				};
				class CodeProgressTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_CODEPROGRESS_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_HOLDACTION_CODEPROGRESS_TOOLTIP";
					y="20 * (5 * (pixelH * pixelGrid * 0.50)) + 30 * pixelH";
				};
				class CodeProgress: ENH_3DEN_Attribute_Control_EditMulti5_Edit
				{
					idc=1006;
					y="20 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * (pixelH * pixelGrid * 0.50) + 30 * pixelH";
					autocomplete="scripting";
				};
				class CodeCompleteBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
				{
					y="25 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50) + 35 * pixelH";
				};
				class CodeCompleteTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_CODECOMPLETE_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_HOLDACTION_CODECOMPLETE_TOOLTIP";
					y="25 * (5 * (pixelH * pixelGrid * 0.50)) + 35 * pixelH";
				};
				class CodeComplete: ENH_3DEN_Attribute_Control_EditMulti5_Edit
				{
					idc=1007;
					y="25 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * (pixelH * pixelGrid * 0.50) + 35 * pixelH";
					autocomplete="scripting";
				};
				class CodeInterruptBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
				{
					y="30 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50) + 40 * pixelH";
				};
				class CodeInterruptTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_CODEINTERRUPT_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_HOLDACTION_CODEINTERRUPT_TOOLTIP";
					y="30 * (5 * (pixelH * pixelGrid * 0.50)) + 40 * pixelH";
				};
				class CodeInterrupt: ENH_3DEN_Attribute_Control_EditMulti5_Edit
				{
					idc=1008;
					y="30 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * (pixelH * pixelGrid * 0.50) + 40 * pixelH";
					autocomplete="scripting";
				};
				class DurationTitle: Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_DURATION_DISPLAYNAME";
					y="35 * (5 * (pixelH * pixelGrid * 0.50)) + 45 * pixelH";
				};
				class DurationValue: ctrlXSliderH
				{
					idc=1009;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="35 * (5 * (pixelH * pixelGrid * 0.50)) + 45 * pixelH";
					w="(82 - 11) * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					sliderRange[]={1,60};
					sliderStep=1;
					lineSize=1;
				};
				class DurationEdit: ctrlEdit
				{
					idc=1010;
					x="(48 + 82 - 11) * (pixelW * pixelGrid * 0.50)";
					y="35 * (5 * (pixelH * pixelGrid * 0.50)) + 45 * pixelH";
					w="11 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class PriorityTitle: Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_PRIORITY_DISPLAYNAME";
					y="36 * (5 * (pixelH * pixelGrid * 0.50)) + 50 * pixelH";
				};
				class PriorityValue: DurationValue
				{
					idc=1011;
					y="36 * (5 * (pixelH * pixelGrid * 0.50)) + 50 * pixelH";
					sliderRange[]={1,1000};
				};
				class PriorityEdit: DurationEdit
				{
					idc=1012;
					y="36 * (5 * (pixelH * pixelGrid * 0.50)) + 50 * pixelH";
				};
				class ShowUnconsciousTitle: Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_SHOWUNCONSCIOUSY_DISPLAYNAME";
					y="37 * (5 * (pixelH * pixelGrid * 0.50)) + 55 * pixelH";
				};
				class ShowUnconscious: ctrlCheckbox
				{
					idc=1013;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="37 * (5 * (pixelH * pixelGrid * 0.50)) + 55 * pixelH";
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class ShowWindowTitle: Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_SHOWWINDOW_DISPLAYNAME";
					y="38 * (5 * (pixelH * pixelGrid * 0.50)) + 60 * pixelH";
				};
				class ShowWindow: ShowUnconscious
				{
					idc=1014;
					y="38 * (5 * (pixelH * pixelGrid * 0.50)) + 60 * pixelH";
				};
				class RemoveAfterUseTitle: Title
				{
					text="$STR_ENH_MAIN_HOLDACTION_REMOVEONUSE_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_HOLDACTION_REMOVEONUSE_TOOLTIP";
					y="39 * (5 * (pixelH * pixelGrid * 0.50)) + 65 * pixelH";
				};
				class RemoveAfterUse: ShowUnconscious
				{
					idc=1015;
					y="39 * (5 * (pixelH * pixelGrid * 0.50)) + 65 * pixelH";
				};
				class Reset: ENH_3DEN_Attribute_Control_ResetButton
				{
					y="40 * (5 * (pixelH * pixelGrid * 0.50)) + 70 * pixelH";
				};
			};
		};
		class ENH_InputList: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_inputList_onAttributeLoad";
			attributeSave="_this call ENH_fnc_inputList_onAttributeSave";
			h="6 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
			class Controls: Controls
			{
				class Title: Title
				{
					h="5 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class Data: ctrlListbox
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="5 * (5 * (pixelH * pixelGrid * 0.50))";
					colorBackground[]={0.1,0.1,0.1,1};
				};
				class InputBox: ctrlEdit
				{
					idc=1001;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="(82 - 10) * (pixelW * pixelGrid * 0.50) - 4 * pixelW";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class Remove: ctrlButtonToolbar
				{
					idc=1002;
					text="\x\enh\addons\main\data\minus_ca.paa";
					tooltip="$STR_ENH_MAIN_INPUTLIST_REMOVE_TOOLTIP";
					x="(48 + 82 - 5) * (pixelW * pixelGrid * 0.50)";
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					onButtonClick="_this call ENH_fnc_inputList_remove";
				};
				class Add: Remove
				{
					idc=1003;
					text="\x\enh\addons\main\data\plus_ca.paa";
					tooltip="$STR_ENH_MAIN_INPUTLIST_ADD_TOOLTIP";
					x="(48 + 82 - 10) * (pixelW * pixelGrid * 0.50) - 2 * pixelW";
					onButtonClick="_this call ENH_fnc_inputList_add";
				};
			};
		};
		class ENH_IntroText: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_introText_onAttributeLoad";
			attributeSave="_this call ENH_fnc_introText_onAttributeSave";
			h="10 * (5 * (pixelH * pixelGrid * 0.50)) + 30 * pixelH";
			class Controls: Controls
			{
				class DelayTitle: Title
				{
					text="$STR_ENH_MAIN_INTROTEXT_INTRODELAY_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_INTROTEXT_INTRODELAY_TOOLTIP";
				};
				class DelayValue: ctrlXSliderH
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="(82 - 11) * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					sliderPosition=0;
					sliderRange[]={0,360};
					sliderStep=1;
					lineSize=1;
				};
				class DelayEdit: ctrlEdit
				{
					idc=1001;
					x="(48 + 82 - 11) * (pixelW * pixelGrid * 0.50)";
					w="11 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class Line1Title: Title
				{
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					text="$STR_ENH_MAIN_INTROTEXT_LINE1_DISPLAYNAME";
				};
				class Line1Value: ctrlEdit
				{
					idc=1002;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class Line2Title: Title
				{
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
					text="$STR_ENH_MAIN_INTROTEXT_LINE2_DISPLAYNAME";
					tooltip="";
				};
				class Line2Value: Line1Value
				{
					idc=1003;
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class Line3Title: Title
				{
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
					text="$STR_ENH_MAIN_INTROTEXT_LINE3_DISPLAYNAME";
				};
				class Line3Value: Line1Value
				{
					idc=1004;
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class IntroTypeTitle: Title
				{
					text="$STR_ENH_MAIN_INTROTEXT_INTROTYPE_DISPLAYNAME";
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
					h="5 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class IntroType: ctrlToolboxPictureKeepAspect
				{
					idc=1005;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="5 * (5 * (pixelH * pixelGrid * 0.50))";
					rows=1;
					columns=3;
					strings[]=
					{
						"\x\enh\addons\main\data\BIS_fnc_textTiles_preview_ca.paa",
						"\x\enh\addons\main\data\BIS_fnc_infoText_preview_ca.paa",
						"\x\enh\addons\main\data\BIS_fnc_EXP_camp_SITREP_preview_ca.paa"
					};
					values[]={0,1,2};
				};
				class Reset: ENH_3DEN_Attribute_Control_ResetButton
				{
					y="9 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
				};
			};
		};
		class Edit: Title
		{
			class Controls: Controls
			{
				class Title;
				class Value;
			};
		};
		class EditMulti3: Edit
		{
			class Controls: Controls
			{
				class Value: Value
				{
					h="69 * (pixelH * pixelGrid * 0.50)";
				};
				class Background: ctrlStaticOverlay
				{
					h="73 * (pixelH * pixelGrid * 0.50)";
				};
				class Title: ctrlStaticFrame
				{
					h="75 * (pixelH * pixelGrid * 0.50)";
				};
			};
		};
		class EditMulti5: EditMulti3
		{
			class Controls: Controls
			{
				class Value;
				class Background;
				class Title;
			};
		};
		class EditCodeMulti3: EditMulti3
		{
			h="57.5 * (pixelH * pixelGrid * 0.50)";
			class Controls: Controls
			{
				class Background: Background
				{
					h="55.5 * (pixelH * pixelGrid * 0.50)";
				};
				class Value: Value
				{
					h="52.5 * (pixelH * pixelGrid * 0.50) - (pixelH * pixelGrid * 0.50)";
				};
				class Title: Title
				{
					h="57.5 * (pixelH * pixelGrid * 0.50)";
				};
			};
		};
		class EditCodeMulti5: EditMulti5
		{
			h="75 * (pixelH * pixelGrid * 0.50)";
			class Controls: Controls
			{
				class Background: Background
				{
					h="73 * (pixelH * pixelGrid * 0.50)";
				};
				class Value: Value
				{
					h="69 * (pixelH * pixelGrid * 0.50)";
				};
				class Title: Title
				{
					h="75 * (pixelH * pixelGrid * 0.50)";
				};
			};
		};
		class ENH_MapIndicators: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_mapIndicators_onAttributeLoad";
			attributeSave="_this call ENH_fnc_mapIndicators_onAttributeSave";
			h="4 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
			class Controls: Controls
			{
				class FriendlyText: Title
				{
					text="$STR_ENH_MAIN_MAPINDICATORS_FRIENDLY";
					tooltip="$STR_ENH_MAIN_MAPINDICATORS_FRIENDLY_TOOLTIP";
				};
				class FriendlyValue: ctrlCheckbox
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class EnemyText: FriendlyText
				{
					text="$STR_ENH_MAIN_MAPINDICATORS_ENEMY";
					tooltip="$STR_ENH_MAIN_MAPINDICATORS_ENEMY_TOOLTIP";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class EnemyValue: FriendlyValue
				{
					idc=1001;
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class MinesText: FriendlyText
				{
					text="$STR_ENH_MAIN_MAPINDICATORS_MINES";
					tooltip="$STR_ENH_MAIN_MAPINDICATORS_MINES_TOOLTIP";
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class MinesValue: FriendlyValue
				{
					idc=1002;
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class PingText: FriendlyText
				{
					text="$STR_ENH_MAIN_MAPINDICATORS_PING";
					tooltip="$STR_ENH_MAIN_MAPINDICATORS_PING_TOOLTIP";
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class PingValue: FriendlyValue
				{
					idc=1003;
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
			};
		};
		class ENH_MarkerColor: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_markerColor_onAttributeLoad";
			attributeSave="_this call ENH_fnc_markerColor_onAttributeSave";
			h="6 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
			class Controls: Controls
			{
				class Title: Title
				{
				};
				class CheckboxEnable: ctrlCheckbox
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y=0;
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class SliderRed: ctrlXSliderH
				{
					idc=1001;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="1 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="(82 - 11) * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					sliderRange[]={0,1};
					color[]={1,0,0,0.5};
					colorActive[]={1,0,0,0.5};
				};
				class EditRed: ctrlEdit
				{
					idc=1002;
					x="(48 + 82 - 11) * (pixelW * pixelGrid * 0.50)";
					y="1 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="11 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class SliderGreen: SliderRed
				{
					idc=1003;
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
					color[]={0,1,0,0.5};
					colorActive[]={0,1,0,0.5};
				};
				class EditGreen: EditRed
				{
					idc=1004;
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class SliderBlue: SliderRed
				{
					idc=1005;
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
					color[]={0,0,1,0.5};
					colorActive[]={0,0,1,0.5};
				};
				class EditBlue: EditRed
				{
					idc=1006;
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class Preview: ctrlStatic
				{
					idc=1007;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					colorBackground[]={1,1,1,1};
				};
				class ComboHistory: ctrlCombo
				{
					idc=1008;
					onLoad="_this call ENH_fnc_markerColor_onAttributeLoad";
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
			};
		};
		class ENH_MarkerShape: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_markerShape_onAttributeLoad";
			attributeSave="_this call ENH_fnc_markerShape_onAttributeSave";
			h="8 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
			class Controls: Controls
			{
				class Title: Title
				{
					h="8 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class Value: ctrlToolbox
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="8 * (5 * (pixelH * pixelGrid * 0.50))";
					columns=2;
					rows=4;
					strings[]=
					{
						"a3\3den\data\attributes\default_ca.paa",
						"\x\enh\addons\main\data\triangle_ca.paa",
						"\x\enh\addons\main\data\pentagon_ca.paa",
						"\x\enh\addons\main\data\hexagon_ca.paa",
						"\x\enh\addons\main\data\heptagon_ca.paa",
						"\x\enh\addons\main\data\octagon_ca.paa",
						"\x\enh\addons\main\data\nonagon_ca.paa",
						"\x\enh\addons\main\data\decagon_ca.paa"
					};
					tooltips[]=
					{
						"$STR_A3_OPTIONS_DEFAULT",
						"$STR_ENH_MAIN_MARKER_SHAPE_TRIANGLE",
						"$STR_ENH_MAIN_MARKER_SHAPE_PENTAGON",
						"$STR_ENH_MAIN_MARKER_SHAPE_HEXAGON",
						"$STR_ENH_MAIN_MARKER_SHAPE_HEPTAGON",
						"$STR_ENH_MAIN_MARKER_SHAPE_OCTAGON",
						"$STR_ENH_MAIN_MARKER_SHAPE_NONAGON",
						"$STR_ENH_MAIN_MARKER_SHAPE_DECAGON"
					};
					style="0x02 + 0x30 + 0x800";
					onLoad="_this call ENH_fnc_markerShape_onAttributeLoad";
				};
			};
		};
		class ENH_MissionEnding_Casualties: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_missionEndingCasualties_onAttributeLoad";
			attributeSave="_this call ENH_fnc_missionEndingCasualties_onAttributeSave";
			h="6 * (5 * (pixelH * pixelGrid * 0.50)) + 25 * pixelH";
			class Controls: Controls
			{
				class ThresholdTitle: Title
				{
					text="$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_THRESHOLD_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_THRESHOLD_TOOLTIP";
				};
				class ThresholdValue: ctrlXSliderH
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="(82 - 10) * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					sliderPosition=5;
					sliderRange[]={1,100};
					sliderStep=1;
					lineSize=1;
				};
				class ThresholdEdit: ctrlEdit
				{
					idc=1001;
					x="(48 + 82 - 10) * (pixelW * pixelGrid * 0.50)";
					w="10 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class EndingTitle: Title
				{
					text="$STR_ENH_MAIN_MISSIONENDING_ENDING_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_MISSIONENDING_ENDING_TOOLTIP";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
				};
				class Ending: ctrlCombo
				{
					idc=1002;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					holeHeight="6 * CTRL_DEFAULT_H";
				};
				class IsWinTitle: Title
				{
					text="$STR_ENH_MAIN_MISSIONENDING_WIN_DISPLAYNAME";
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class IsWin: ctrlCheckbox
				{
					idc=1003;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class SideTitle: Title
				{
					text="$STR_ENH_MAIN_SIDE_DISPLAYNAME";
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
					h="2 * (5 * (pixelH * pixelGrid * 0.50))";
				};
				class SideValue: ENH_3DEN_Attribute_Control_SideToolbox
				{
					idc=1004;
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class Reset: ENH_3DEN_Attribute_Control_ResetButton
				{
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
			};
		};
		class ENH_SliderMulti120: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_slider_onAttributeLoad";
			attributeSave="_this call ENH_fnc_slider_onAttributeSave";
			class Controls: Controls
			{
				class Title: Title
				{
				};
				class Value: ctrlXSliderH
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="(82 - 10) * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					sliderPosition=1;
					sliderRange[]={0.1,120};
					sliderStep=0.1;
				};
				class Edit: ctrlEdit
				{
					idc=1001;
					x="(48 + 82 - 10) * (pixelW * pixelGrid * 0.50)";
					w="10 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
			};
		};
		class ENH_SliderMultiZero: SliderMultiplier
		{
			class Controls: Controls
			{
				class Title: Title
				{
				};
				class Edit: Edit
				{
				};
				class Value: Value
				{
					sliderRange[]={0,3};
					sliderPosition=1;
					lineSize=0.1;
					sliderStep=0.1;
				};
			};
		};
		class ENH_SPR: Title
		{
			attributeLoad="[_this, _value] call ENH_fnc_SPR_onAttributeLoad";
			attributeSave="_this call ENH_fnc_SPR_onAttributeSave";
			h="10 * (5 * (pixelH * pixelGrid * 0.50)) + 35 * pixelH";
			class Controls: Controls
			{
				class RulesetTitle: Title
				{
					text="$STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNTEMPLATES_DISPLAYNAME";
				};
				class Ruleset: ctrlCombo
				{
					idc=1000;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="82 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class RespawnTimeTitle: Title
				{
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					text="$STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNDELAY_DISPLAYNAME";
					tooltip="$STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNDELAY_TOOLTIP";
				};
				class RespawnTimeValue: ctrlXSliderH
				{
					idc=1001;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="(82 - 10) * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					sliderPosition=20;
					sliderRange[]={2,360};
					sliderStep=1;
					lineSize=1;
				};
				class RespawnTimeEdit: ctrlEdit
				{
					idc=1002;
					x="(48 + 82 - 10) * (pixelW * pixelGrid * 0.50)";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 5 * pixelH";
					w="10 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class CanDieTitle: Title
				{
					text="$STR_ENH_MAIN_SPR_CANDIE_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_SPR_CANDIE_TOOLTIP";
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
				};
				class CanDie: ctrlCheckbox
				{
					idc=1003;
					x="48 * (pixelW * pixelGrid * 0.50)";
					y="2* (5 * (pixelH * pixelGrid * 0.50)) + 10 * pixelH";
					w="5 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class RestoreLoadoutTitle: Title
				{
					text="$STR_ENH_MAIN_SAVELOADOUT_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_SAVELOADOUT_TOOLTIP";
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class RestoreLoadout: CanDie
				{
					idc=1004;
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * pixelH";
				};
				class CodeBackground: ENH_3DEN_Attribute_Control_EditMulti5_Background
				{
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50) + 20 * pixelH";
				};
				class CodeTitle: ENH_3DEN_Attribute_Control_EditMulti5_Title
				{
					text="$STR_ENH_MAIN_SPR_ONRESPAWNCODE_DISPLAYNAME";
					tooltip="$STR_ENH_MAIN_SPR_ONRESPAWNCODE_TOOLTIP";
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 20 * pixelH";
				};
				class Code: ENH_3DEN_Attribute_Control_EditMulti5_Edit
				{
					idc=1005;
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * (pixelH * pixelGrid * 0.50) + 20 * pixelH";
					autocomplete="scripting";
				};
				class Reset: ENH_3DEN_Attribute_Control_ResetButton
				{
					y="9 * (5 * (pixelH * pixelGrid * 0.50)) + 30 * pixelH";
				};
			};
		};
		class SubCategoryNoHeader1: Default
		{
			class Controls
			{
				class Group: ctrlControlsGroup
				{
					class Controls
					{
						class Title;
						class DescriptionDeco;
						class Description;
					};
				};
			};
		};
		class ENH_SubCategoryNoHeader1_Fixed: SubCategoryNoHeader1
		{
			attributeLoad="((_this controlsGroupCtrl 101) controlsGroupCtrl 102) ctrlSetStructuredText parseText gettext (_config >> 'description')";
			attributeSave="";
			h="(2.5 * (pixelH * pixelGrid * 0.50)) + 1 * 4.5 * (pixelH * pixelGrid * 0.50)";
			class Controls: Controls
			{
				class Group: Group
				{
					h="1 * 4.5 * (pixelH * pixelGrid * 0.50)";
					class Controls: Controls
					{
						class Title: Title
						{
							h="1 * 4.5 * (pixelH * pixelGrid * 0.50)";
						};
						class DescriptionDeco: DescriptionDeco
						{
							h="1 * 4.5 * (pixelH * pixelGrid * 0.50)";
						};
						class Description: Description
						{
							h="1 * 4.5 * (pixelH * pixelGrid * 0.50)";
						};
					};
				};
			};
		};
		class ENH_SubCategoryNoHeader2_Fixed: ENH_SubCategoryNoHeader1_Fixed
		{
			h="(2.5 * (pixelH * pixelGrid * 0.50)) + 2 * 4.5 * (pixelH * pixelGrid * 0.50)";
			class Controls: Controls
			{
				class Group: Group
				{
					h="2 * 4.5 * (pixelH * pixelGrid * 0.50)";
					class Controls: Controls
					{
						class Title: ctrlStatic
						{
							h="2 * 4.5 * (pixelH * pixelGrid * 0.50)";
						};
						class DescriptionDeco: DescriptionDeco
						{
							h="2 * 4.5 * (pixelH * pixelGrid * 0.50)";
						};
						class Description: Description
						{
							h="2 * 4.5 * (pixelH * pixelGrid * 0.50)";
						};
					};
				};
			};
		};
		class ENH_SubCategoryNoHeader3_Fixed: ENH_SubCategoryNoHeader1_Fixed
		{
			h="(2.5 * (pixelH * pixelGrid * 0.50)) + 3 * 4.5 * (pixelH * pixelGrid * 0.50)";
			class Controls: Controls
			{
				class Group: Group
				{
					h="3 * 4.5 * (pixelH * pixelGrid * 0.50)";
					class Controls: Controls
					{
						class Title: Title
						{
							h="3 * 4.5 * (pixelH * pixelGrid * 0.50)";
						};
						class DescriptionDeco: DescriptionDeco
						{
							h="3 * 4.5 * (pixelH * pixelGrid * 0.50)";
						};
						class Description: Description
						{
							h="3 * 4.5 * (pixelH * pixelGrid * 0.50)";
						};
					};
				};
			};
		};
	};
	class Mission
	{
		class Preferences
		{
			class AttributeCategories
			{
				class Camera
				{
					class Attributes
					{
						class ENH_DynamicViewDistance
						{
							displayName="$STR_ENH_MAIN_DYNAMICVIEWDISTANCE_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_DYNAMICVIEWDISTANCE_TOOLTIP";
							property="ENH_DynamicViewDistance";
							control="Checkbox";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DynamicViewDistance', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DynamicViewDistance', false]";
						};
					};
				};
				class Saving
				{
					class Attributes
					{
						class ENH_BackupMissionSQM
						{
							displayName="$STR_ENH_MAIN_BACKUPMISSIONSQM_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_BACKUPMISSIONSQM_TOOLTIP";
							property="ENH_BackupMissionSQM";
							control="Checkbox";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_BackupMissionSQM', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_BackupMissionSQM', false]";
						};
						class ENH_BackupMissionSQMPath
						{
							displayName="$STR_ENH_MAIN_BACKUPMISSIONSQMPATH_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_BACKUPMISSIONSQMPATH_TOOLTIP";
							property="ENH_BackupMissionSQMPath";
							control="Edit";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_BackupMissionSQMPath', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_BackupMissionSQMPath', '']";
						};
					};
				};
				class Misc
				{
					class Attributes
					{
						class ENH_HoldActionIcons
						{
							displayName="$STR_ENH_MAIN_PREFERENCES_HOLD_ACTION_ICONS_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_PREFERENCES_HOLD_ACTION_ICONS_TOOLTIP";
							property="ENH_HoldActionIcons";
							control="ENH_InputList";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_HoldActionIcons', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_HoldActionIcons', []]";
						};
					};
				};
				class ENH_Interface
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_INTERFACE";
					class Attributes
					{
						class ENH_CollapseAssetBrowser
						{
							displayName="$STR_ENH_MAIN_COLLAPSEASSETBROWSER";
							property="ENH_CollapseAssetBrowser";
							control="Checkbox";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_CollapseAssetBrowser', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_CollapseAssetBrowser', false]";
						};
						class ENH_CollapseEntityList: ENH_CollapseAssetBrowser
						{
							displayName="$STR_ENH_MAIN_COLLAPSEENTITYLIST";
							property="ENH_CollapseEntityList";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_CollapseEntityList', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_CollapseEntityList', false]";
						};
						class ENH_ShowPanelLeft: ENH_CollapseAssetBrowser
						{
							displayName="$STR_ENH_MAIN_SHOWLEFTPANEL";
							property="ENH_ShowPanelLeft";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_ShowPanelLeft', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_ShowPanelLeft', true]";
						};
						class ENH_ShowPanelRight: ENH_ShowPanelLeft
						{
							displayName="$STR_ENH_MAIN_SHOWRIGHTPANEL";
							property="ENH_ShowPanelRight";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_ShowPanelRight', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_ShowPanelRight', true]";
						};
						class ENH_MinimapSize
						{
							displayName="$STR_ENH_MAIN_MINIMAPSIZE";
							property="ENH_MinimapSize";
							control="Combo";
							class Values
							{
								class Disabled
								{
									name="$STR_DISABLED";
									value=0;
								};
								class Small
								{
									name="$STR_SMALL";
									value=1;
								};
								class Medium
								{
									name="$STR_MEDIUM";
									value=2;
								};
								class Large
								{
									name="$STR_LARGE";
									value=3;
								};
							};
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_MinimapSize', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_MinimapSize', 0]";
							typeName="NUMBER";
						};
						class ENH_MinimapScaleMultiplier
						{
							displayName="$STR_ENH_MAIN_MINIMAPSCALEMULTIPLIER";
							property="ENH_MinimapScaleMultiplier";
							control="SliderCameraSpeedMult";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_MinimapScaleMultiplier', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_MinimapScaleMultiplier', 1]";
						};
						class ENH_EntityCounter: ENH_ShowPanelLeft
						{
							displayName="$STR_ENH_MAIN_STATUSBAR_ENTITYCOUNTER_DISPLAYNAME";
							property="ENH_Statusbar_EntityCounter";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_EntityCounter', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_EntityCounter', true]";
						};
						class ENH_ToggleDrawBuildingPositions: ENH_ShowPanelLeft
						{
							displayName="$STR_ENH_MAIN_TOOLS_DRAWBUILDINGPOSITIONS";
							property="ENH_DrawBuildingPositions";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_DrawBuildingPositions', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_DrawBuildingPositions', false]";
						};
						class ENH_DrawDLCIcons: ENH_ShowPanelLeft
						{
							displayName="$STR_ENH_MAIN_TOOLS_DRAWDLCICONS";
							property="ENH_DrawDLCIcons";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_DrawDLCIcons', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_DrawDLCIcons', false]";
						};
						class ENH_ShowCustomMarkerColorAndShape: ENH_ShowPanelLeft
						{
							displayName="$STR_ENH_MAIN_PREFERENCES_SHOW_CUSTOM_MARKER_COLOR_AND_SHAPE_DISPLAYNAME";
							property="ENH_ShowCustomMarkerColorAndShape";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_ShowCustomMarkerColorAndShape', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_ShowCustomMarkerColorAndShape', true]";
						};
						class ENH_AdjustTitleTextWidth: ENH_ShowPanelLeft
						{
							displayName="$STR_ENH_MAIN_PREFERENCES_ADJUST_TITLE_WIDTH_DISPLAYNAME";
							property="ENH_AdjustTitleTextWidth";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_AdjustTitleTextWidth', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_AdjustTitleTextWidth', true]";
						};
						class ENH_3DENCommandPalette_Path: ENH_ShowPanelLeft
						{
							displayName="$STR_ENH_MAIN_PREFERENCES_3DEN_COMMAND_PALETTE_PATH_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_PREFERENCES_3DEN_COMMAND_PALETTE_PATH_TOOLTIP";
							property="ENH_3DENCommandPalette_Path";
							control="Edit";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Interface_3DENCommandPalette_Path', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Interface_3DENCommandPalette_Path', '']";
						};
					};
				};
				class ENH_Garrison2
				{
					collapsed=1;
					displayName="Garrison";
					class Attributes
					{
						class ENH_Garrison2_CreateLayer
						{
							displayName="$STR_ENH_MAIN_PREFERENCES_GARRISON2_CREATE_LAYER_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_PREFERENCES_GARRISON2_CREATE_LAYER_TOOLTIP";
							property="ENH_Garrison2_CreateLayer";
							control="Checkbox";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_CreateLayer', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_CreateLayer', false]";
						};
						class ENH_Garrison2_GroupTogether: ENH_Garrison2_CreateLayer
						{
							displayName="$STR_ENH_MAIN_PREFERENCES_GARRISON2_GROUP_TOGETHER_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_PREFERENCES_GARRISON2_GROUP_TOGETHER_TOOLTIP";
							property="ENH_Garrison2_GroupTogether";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_GroupTogether', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_GroupTogether', false]";
						};
						class ENH_Garrison2_RandomRotation: ENH_Garrison2_CreateLayer
						{
							displayName="$STR_ENH_MAIN_PREFERENCES_GARRISON2_RANDOM_ROTATION_DISPLAYNAME";
							property="ENH_Garrison2_RandomRotation";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_RandomRotation', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_RandomRotation', true]";
						};
						class ENH_Garrison2_DisablePathfinding: ENH_Garrison2_CreateLayer
						{
							displayName="$STR_ENH_MAIN_PREFERENCES_GARRISON2_DISABLE_PATHFINDING_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_PREFERENCES_GARRISON2_DISABLE_PATHFINDING_TOOLTIP";
							property="ENH_Garrison2_DisablePathfinding";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_DisablePathfinding', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_DisablePathfinding', false]";
						};
						class ENH_Garrison2_AutoSelectRemainingEntities: ENH_Garrison2_CreateLayer
						{
							displayName="$STR_ENH_MAIN_PREFERENCES_GARRISON2_AUTO_SELECT_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_PREFERENCES_GARRISON2_AUTO_SELECT_TOOLTIP";
							property="ENH_Garrison2_AutoSelectRemainingEntities";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_AutoSelectRemainingEntities', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_AutoSelectRemainingEntities', true]";
						};
						class ENH_Garrison2_CheckForTakenPositions: ENH_Garrison2_CreateLayer
						{
							displayName="$STR_ENH_MAIN_PREFERENCES_GARRISON2_CHECK_FOR_TAKEN_POSITIONS_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_PREFERENCES_GARRISON2_CHECK_FOR_TAKEN_POSITIONS_TOOLTIP";
							property="ENH_Garrison2_CheckForTakenPositions";
							expression="profileNamespace setVariable ['ENH_Garrison2_CheckForTakenPositions', _value]";
							defaultValue="profileNamespace getVariable ['ENH_Garrison2_CheckForTakenPositions', true]";
						};
						class ENH_Garrison2_Stance
						{
							displayName="$STR_3DEN_OBJECT_ATTRIBUTE_STANCE_DISPLAYNAME";
							property="ENH_Garrison2_Stance";
							control="Combo";
							typeName="NUMBER";
							class Values
							{
								class Stand
								{
									name="$STR_3DEN_ATTRIBUTES_STANCE_UP";
									value=0;
								};
								class Kneel
								{
									name="$STR_3DEN_ATTRIBUTES_STANCE_MIDDLE";
									value=1;
								};
								class Prone
								{
									name="$STR_3DEN_ATTRIBUTES_STANCE_DOWN";
									value=2;
								};
								class Large
								{
									name="$STR_3DEN_ATTRIBUTES_STANCE_DEFAULT";
									value=3;
								};
								class Random
								{
									name="$STR_3DEN_OBJECT_ATTRIBUTE_COMBO_DISPLAYNAME_RANDOM";
									value=4;
								};
								class RandomNoProne
								{
									name="$STR_ENH_MAIN_PREFERENCES_GARRISON2_STANCE_RANDOM_NO_PRONE_DISPLAYNAME";
									value=5;
								};
							};
							expression="profileNamespace setVariable ['ENH_EditorPreferences_Garrison2_Stance', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_Garrison2_Stance', 4]";
						};
					};
				};
				class ENH_DebugOptions
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_DEBUG_OPTIONS";
					class Attributes
					{
						class ENH_DebugOptions_Subcategory
						{
							description="$STR_ENH_MAIN_DEBUGOPTIONS_DESCRIPTION";
							property="ENH_DebugOptions_Subcategory";
							control="ENH_SubCategoryNoHeader3_Fixed";
						};
						class ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_ARSENAL_DISPLAYNAME";
							property="ENH_DebugOptions_Arsenal";
							control="Checkbox";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Arsenal', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Arsenal', false]";
						};
						class ENH_DebugOptions_Garage: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_GARAGE_DISPLAYNAME";
							property="ENH_DebugOptions_Garage";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Garage', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Garage', false]";
						};
						class ENH_DebugOptions_KillBLUFOR: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_KILLBLUFOR_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_DEBUGOPTIONS_KILLUNITS_TOOLTIP";
							property="ENH_DebugOptions_KillBLUFOR";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_KillBLUFOR', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_KillBLUFOR', false]";
						};
						class ENH_DebugOptions_KillOPFOR: ENH_DebugOptions_KillBLUFOR
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_KILLOPFOR_DISPLAYNAME";
							property="ENH_DebugOptions_KillOPFOR";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_KillOPFOR', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_KillOPFOR', false]";
						};
						class ENH_DebugOptions_KillIndependent: ENH_DebugOptions_KillBLUFOR
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_KILLINDEPENDENT_DISPLAYNAME";
							property="ENH_DebugOptions_KillIndependent";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_KillIndependent', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_KillIndependent', false]";
						};
						class ENH_DebugOptions_KillCivilian: ENH_DebugOptions_KillBLUFOR
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_KILLCIVILIAN_DISPLAYNAME";
							property="ENH_DEBUGOPTIONS_KILLCIVILIAN";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_KillCivilian', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_KillCivilian', false]";
						};
						class ENH_DebugOptions_KillCursor: ENH_DebugOptions_KillBLUFOR
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_KILLCURSOR_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_DEBUGOPTIONS_KILLCURSOR_TOOLTIP";
							property="ENH_DebugOptions_KillCursor";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_KillCursor', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_KillCursor', false]";
						};
						class ENH_DebugOptions_DeleteCorpse: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_DELETECORPSE_DISPLAYNAME";
							property="ENH_DebugOptions_DeleteCorpse";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_DeleteCorpse', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_DeleteCorpse', false]";
						};
						class ENH_DebugOptions_Teleport: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_TELEPORT";
							tooltip="$STR_ENH_MAIN_DEBUGOPTIONS_TELEPORT_TOOLTIP";
							property="ENH_DebugOptions_Teleport";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Teleport', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Teleport', false]";
						};
						class ENH_DebugOptions_VariableViewer: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_VARIABLEVIEWER_HEADER";
							property="ENH_DebugOptions_VariableViewer";
						};
						class ENH_DebugOptions_ActiveScripts: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_LOGSCRIPTS_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_DEBUGOPTIONS_LOGSCRIPTS_TOOLTIP";
							property="ENH_DebugOptions_ActiveScripts";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_ActiveScripts', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_ActiveScripts', false]";
						};
						class ENH_DebugOptions_Player_Subcategory: ENH_DebugOptions_Subcategory
						{
							description="$STR_MPTABLE_NAME";
							data="AttributeSystemSubcategory";
							control="ENH_SubCategoryNoHeader1_Fixed";
						};
						class ENH_DebugOptions_Invulnerability: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_INVULNERABILITY_DISPLAYNAME";
							property="ENH_DebugOptions_Invulnerability";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Invulnerability', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Invulnerability', false]";
						};
						class ENH_DebugOptions_Captive: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_CAPTIVE_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_CAPTIVE_TOOLTIP";
							property="ENH_DebugOptions_Captive";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Captive', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Captive', false]";
						};
						class ENH_DebugOptions_Stamina: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_STAMINA_DISPLAYNAME";
							property="ENH_DebugOptions_Stamina";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Stamina', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Stamina', false]";
						};
						class ENH_DebugOptions_Zeus: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_ZEUS_DISPLAYNAME";
							property="ENH_DebugOptions_Zeus";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_Zeus', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_Zeus', false]";
						};
						class ENH_DebugOptions_NoRecoil: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_NORECOIL";
							property="ENH_DebugOptions_NoRecoil";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_NoRecoil', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_NoRecoil', false]";
						};
						class ENH_DebugOptions_NoSway: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_NOSWAY";
							property="ENH_DebugOptions_NoSway";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_NoSway', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_NoSway', false]";
						};
						class ENH_DebugOptions_UnlimitedAmmo: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_UNLIMITEDAMMO";
							property="ENH_DebugOptions_UnlimitedAmmo";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_UnlimitedAmmo', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_UnlimitedAmmo', false]";
						};
						class ENH_DebugOptions_NoReload: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_NORELOAD";
							property="ENH_DebugOptions_NoReload";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_NoReload', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_NoReload', false]";
						};
						class ENH_DebugOptions_Subcategory_Drawing: ENH_DebugOptions_Player_Subcategory
						{
							description="$STR_ENH_MAIN_DEBUGOPTIONS_CATEGORY_VISUALIZATION";
						};
						class ENH_DebugOptions_BulletTracking: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_BULLETTRACKING_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_DEBUGOPTIONS_BULLETTRACKING_TOOLTIP";
							property="ENH_DebugOptions_BulletTracking";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_BulletTracking', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_BulletTracking', false]";
						};
						class ENH_DebugOptions_FPS: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_FPS_DISPLAYNAME";
							property="ENH_DebugOptions_FPS";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_FPS', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_FPS', false]";
						};
						class ENH_DebugOptions_DrawViewDirection: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_DRAWVIEWDIRECTION";
							tooltip="$STR_ENH_MAIN_DEBUGOPTIONS_DRAWVIEWDIRECTION_TOOLTIP";
							property="ENH_DebugOptions_DrawViewDirection";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_DrawViewDirection', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_DrawViewDirection', false]";
						};
						class ENH_DebugOptions_DynSimDebug: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_3DEN_DYNAMICSIMULATION_TEXTSINGULAR";
							tooltip="$STR_ENH_MAIN_DEBUGOPTIONS_DYNSIMDEBUG_TOOLTIP";
							property="ENH_DebugOptions_DynSimDebug";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_DynSimDebug', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_DynSimDebug', false]";
						};
						class ENH_DebugOptions_ShowGroups: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_SHOWGROUPS_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_DEBUGOPTIONS_SHOWGROUPS_TOOLTIP";
							property="ENH_DebugOptions_ShowGroups";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_ShowGroups', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_ShowGroups', false]";
						};
						class ENH_DebugOptions_DrawTriggers: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_DRAWTRIGGERS_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_DEBUGOPTIONS_DRAWTRIGGERS_TOOLTIP";
							property="ENH_DebugOptions_DrawTriggers";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_DrawTriggers', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_DrawTriggers', false]";
						};
						class ENH_DebugOptions_DebugPath: ENH_DebugOptions_Arsenal
						{
							displayName="Debug Path";
							property="ENH_DebugOptions_DebugPath";
							control="Combo";
							typeName="NUMBER";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_DebugPath', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_DebugPath', 0]";
							class Values
							{
								class Disabled
								{
									name="$STR_DISABLED";
									value=0;
								};
								class 2D
								{
									name="2D";
									value=1;
								};
								class 2Dand3D
								{
									name="2D + 3D";
									value=2;
								};
							};
						};
						class ENH_DebugOptions_Environment_Subcategory: ENH_DebugOptions_Player_Subcategory
						{
							description="$STR_A3_CREDITS_ENVIRONMENT";
						};
						class ENH_DebugOptions_SkipTime: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_SKIPTIME";
							property="ENH_DebugOptions_SkipTime";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_SkipTime', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_SkipTime', false]";
						};
						class ENH_DebugOptions_TimeMultiplier: ENH_DebugOptions_Arsenal
						{
							displayName="$STR_ENH_MAIN_DEBUGOPTIONS_TIMEMULTIPLIER";
							property="ENH_DebugOptions_TimeMultiplier";
							expression="profileNamespace setVariable ['ENH_EditorPreferences_DebugOptions_TimeMultiplier', _value]";
							defaultValue="profileNamespace getVariable ['ENH_EditorPreferences_DebugOptions_TimeMultiplier', false]";
						};
					};
				};
			};
		};
		class Intel
		{
			class AttributeCategories
			{
				class Date
				{
					class Attributes
					{
						class ENH_SliderMulti120
						{
							displayName="$STR_ENH_MAIN_TIMEMULTIPLIER_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_TIMEMULTIPLIER_TOOLTIP";
							property="ENH_timeMultiplier";
							control="ENH_SliderMulti120";
							expression="if (!is3DEN && isServer && _value != 1) then {setTimeMultiplier _value}";
							defaultValue=1;
						};
					};
				};
				class ENH_VisualSettings
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_ATTRIBUTECATEGORY_VISUALSETTINGS";
					class Attributes
					{
						class ENH_ViewDistance
						{
							displayName="$STR_ENH_MAIN_VIEWDISTANCE_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_VIEWDISTANCE_TOOLTIP";
							property="ENH_viewDistance";
							control="Edit";
							expression="if (!is3DEN && _value > 0 && hasInterface) then {setViewDistance _value}";
							defaultValue=-1;
							typeName="NUMBER";
						};
						class ENH_ObjViewDistance: ENH_ViewDistance
						{
							displayName="$STR_ENH_MAIN_OBJVIEWDISTANCE_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_OBJVIEWDISTANCE_TOOLTIP";
							property="ENH_objViewDistance";
							expression="if (!is3DEN && _value > 0 && hasInterface) then {setObjectViewDistance _value}";
						};
						class ENH_TerrainDetail
						{
							control="Combo";
							property="ENH_terrainDetail";
							displayName="$STR_ENH_MAIN_TERRAINDETAIL_DISPLAYNAME";
							expression="if (!is3DEN && _value > 0 && hasInterface) then {setTerrainGrid _value}";
							defaultValue=-1;
							typeName="NUMBER";
							class Values
							{
								class Unchanged
								{
									name="$STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TEXT";
									value=-1;
								};
								class GrassDisabled
								{
									name="$STR_ENH_MAIN_TERRAINGRID_GRASSDISABLED_DISPLAYNAME";
									value=50;
								};
								class Standard
								{
									name="$STR_ENH_MAIN_TERRAINGRID_STANDARD_DISPLAYNAME";
									value=25;
								};
								class High
								{
									name="$STR_ENH_MAIN_TERRAINGRID_HIGH_DISPLAYNAME";
									value=12.5;
								};
								class VeryHigh
								{
									name="$STR_ENH_MAIN_TERRAINGRID_VERYHIGH_DISPLAYNAME";
									value=6.25;
								};
								class Ultra
								{
									name="$STR_ENH_MAIN_TERRAINGRID_ULTRA_DISPLAYNAME";
									value=3.125;
								};
							};
						};
					};
				};
			};
		};
		class Scenario
		{
			class AttributeCategories
			{
				class ENH_Airdrop
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_AIRDROP_DISPLAYNAME";
					class Attributes
					{
						class ENH_Airdrop_Subcategory
						{
							description="$STR_ENH_MAIN_AIRDROP_DESCRIPTION";
							property="ENH_Airdrop_Subcategory";
							control="ENH_SubCategoryNoHeader2_Fixed";
						};
						class ENH_Airdrop
						{
							displayName="$STR_ENH_MAIN_AIRDROP_DISPLAYNAME";
							property="ENH_Airdrop";
							control="ENH_Airdrop";
							expression="                if (!is3DEN && ((_value # 0) isNotEqualTo []) && isServer) then                {                    _value spawn                    {                        scriptName 'ENH_Attribute_Airdrop';                        params ['_classes', '_center', '_condition', '_alt', '_r', '_side'];                        _condition = compile _condition;                        waitUntil {sleep 1; call _condition};                        private _group = createGroup _side;                        playSound3D ['A3\Data_F_Warlords\sfx\flyby.wss', objNull, false, _center vectorAdd [0, 0, 100], 2.5];                        ENH_Airdrop_Units = [];                        {                            _center set [2, _center # 2 + random [-20, 0, 20]];                            private _unit = _group createUnit [_x, _center, [], 0, 'NONE'];                            private _para = createVehicle ['Steerable_Parachute_F', _center getPos [_r * sqrt random 1, random 360], [], 0, 'FLY'];                            _unit moveInDriver _para;                            ENH_Airdrop_Units pushBack _unit;                        } forEach _classes;                    };                }";
							defaultValue="[[], [0, 0, 0], 'false', 500, 200, west]";
						};
					};
				};
				class ENH_AmbientFlyby
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_AMBIENTFLYBY_DISPLAYNAME";
					class Attributes
					{
						class ENH_AmbientFlyby_Subcategory
						{
							description="$STR_ENH_MAIN_AMBIENTFLYBY_DESCRIPTION";
							property="ENH_AmbientFlyby_Subcategory";
							control="ENH_SubCategoryNoHeader3_Fixed";
						};
						class ENH_AmbientFlyby
						{
							displayName="$STR_ENH_MAIN_AMBIENTFLYBY_DISPLAYNAME";
							property="ENH_ambientFlyby";
							control="ENH_AmbientFlyby";
							expression="            if (isServer && !is3DEN && ((_value # 0) isNotEqualTo [])) then            {                ENH_AmbientFlyby_Enabled = true;                _value spawn                {                    scriptName 'ENH_Attribute_AmbientFlyby';                    diag_log _this;                    params ['_classes', '_startPos', '_endPos', '_alt', '_speed', '_side', ['_delay', [300, 300, 300], [[], 0]], ['_rndStartOffset', 0], ['_rndEndOffset', 0]];                    if (_delay isEqualType 0) then {_delay = [_delay, _delay, _delay]};                                        while {ENH_AmbientFlyby_Enabled} do                    {                        sleep random _delay;                        [" \n "                            _startPos vectorAdd [random _rndStartOffset - random _rndStartOffset, random _rndStartOffset - random _rndStartOffset]," \n "                            _endPos vectorAdd [random _rndEndOffset - random _rndEndOffset, random _rndEndOffset - random _rndEndOffset]," \n "                            _alt," \n "                            _speed," \n "                            selectRandom _classes," \n "                            _side" \n "                        ] call BIS_fnc_ambientFlyby;                    };                };            }";
							defaultValue="[[], [0, 0, 0], [0, 0, 0], 500, 'normal', west, [300, 300, 300], 0, 0]";
						};
					};
				};
				class ENH_Briefing
				{
					collapsed=1;
					displayName="$STR_A3_CFGDIARY_FIXEDPAGES_DIARY";
					class Attributes
					{
						class ENH_Briefing_BLUFOR_Subcategory
						{
							description="$STR_WEST";
							data="AttributeSystemSubcategory";
							control="ENH_SubCategoryNoHeader1_Fixed";
						};
						class ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_SITUATION_TITLE";
							tooltip="$STR_ENH_MAIN_BRIEFING_TOOLTIP";
							property="ENH_Briefing_BLUFOR_Situation";
							control="EditMulti5";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_BLUFOR_Situation'; waitUntil {!isNull player}; if (side player == west) then {sleep 0.1; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SITUATION_TITLE', _this call BIS_fnc_localize]]}}};";
							defaultValue="''";
						};
						class ENH_Briefing_BLUFOR_Mission: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_MISSION_TITLE";
							property="ENH_Briefing_BLUFOR_Mission";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_BLUFOR_Mission'; waitUntil {!isNull player}; if (side player == west) then {sleep 0.2; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_MISSION_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_BLUFOR_Execution: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_EXECUTION_TITLE";
							property="ENH_Briefing_BLUFOR_Execution";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_BLUFOR_Execution'; waitUntil {!isNull player}; if (side player == west) then {sleep 0.3; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_EXECUTION_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_BLUFOR_Signal: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_SIGNAL_TITLE";
							property="ENH_Briefing_BLUFOR_Signal";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_BLUFOR_Signal'; waitUntil {!isNull player}; if (side player == west) then {sleep 0.4; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SIGNAL_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_OPFOR_Subcategory: ENH_Briefing_BLUFOR_Subcategory
						{
							description="$STR_EAST";
						};
						class ENH_Briefing_OPFOR_Situation: ENH_Briefing_BLUFOR_Situation
						{
							property="ENH_Briefing_OPFOR_Situation";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_OPFOR_Situation'; waitUntil {!isNull player}; if (side player == east) then {sleep 0.1; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SITUATION_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_OPFOR_Mission: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_MISSION_TITLE";
							property="ENH_Briefing_OPFOR_Mission";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_OPFOR_Mission'; waitUntil {!isNull player}; if (side player == east) then {sleep 0.2; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_MISSION_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_OPFOR_Execution: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_EXECUTION_TITLE";
							property="ENH_Briefing_OPFOR_Execution";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_OPFOR_Execution'; waitUntil {!isNull player}; if (side player == east) then {sleep 0.3; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_EXECUTION_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_OPFOR_Signal: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_SIGNAL_TITLE";
							property="ENH_Briefing_OPFOR_Signal";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_OPFOR_Signal'; waitUntil {!isNull player}; if (side player == east) then {sleep 0.4; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SIGNAL_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_Independent_Subcategory: ENH_Briefing_BLUFOR_Subcategory
						{
							description="$STR_GUERRILA";
						};
						class ENH_Briefing_Independent_Situation: ENH_Briefing_BLUFOR_Situation
						{
							property="ENH_Briefing_Independent_Situation";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Independent_Situation'; waitUntil {!isNull player}; if (side player == independent) then {sleep 0.1; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SITUATION_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_Independent_Mission: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_MISSION_TITLE";
							property="ENH_Briefing_Independent_Mission";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Independent_Mission'; waitUntil {!isNull player}; if (side player == independent) then {sleep 0.2; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_MISSION_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_Independent_Execution: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_EXECUTION_TITLE";
							property="ENH_Briefing_Independent_Execution";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Independent_Execution'; waitUntil {!isNull player}; if (side player == independent) then {sleep 0.3; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_EXECUTION_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_Independent_Signal: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_SIGNAL_TITLE";
							property="ENH_Briefing_Independent_Signal";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Independent_Signal'; waitUntil {!isNull player}; if (side player == independent) then {sleep 0.4; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SIGNAL_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_Civilian_Subcategory: ENH_Briefing_BLUFOR_Subcategory
						{
							description="$STR_CIVILIAN";
						};
						class ENH_Briefing_Civilian_Situation: ENH_Briefing_BLUFOR_Situation
						{
							property="ENH_Briefing_Civilian_Situation";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Civilian_Situation'; waitUntil {!isNull player}; if (side player == civilian) then {sleep 0.1; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SITUATION_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_Civilian_Mission: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_MISSION_TITLE";
							property="ENH_Briefing_Civilian_Mission";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Civilian_Mission'; waitUntil {!isNull player}; if (side player == civilian) then {sleep 0.2; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_MISSION_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_Civilian_Execution: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_EXECUTION_TITLE";
							property="ENH_Briefing_Civilian_Execution";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Civilian_Execution'; waitUntil {!isNull player}; if (side player == civilian) then {sleep 0.3; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_EXECUTION_TITLE', _this call BIS_fnc_localize]]}}};";
						};
						class ENH_Briefing_Civilian_Signal: ENH_Briefing_BLUFOR_Situation
						{
							displayName="$STR_A3_DIARY_SIGNAL_TITLE";
							property="ENH_Briefing_Civilian_Signal";
							expression="if (!is3DEN && hasInterface && _value != '') then {_value spawn {scriptName 'ENH_Briefing_Civilian_Signal'; waitUntil {!isNull player}; if (side player == civilian) then {sleep 0.4; player createDiaryRecord ['Diary', [localize 'STR_A3_DIARY_SIGNAL_TITLE', _this call BIS_fnc_localize]]}}};";
						};
					};
				};
				class ENH_EstablishingShot
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_ATTRIBUTECATEGORY_ESTABLISHINGSHOT";
					class Attributes
					{
						class ENH_EstablishingShot_Subcategory
						{
							description="$STR_ENH_MAIN_ESTABLISHINGSHOT_DESCRIPTION";
							data="AttributeSystemSubcategory";
							control="ENH_SubCategoryNoHeader1_Fixed";
						};
						class ENH_EstablishingShot
						{
							displayName="$STR_ENH_MAIN_ATTRIBUTECATEGORY_ESTABLISHINGSHOT";
							property="ENH_establisingShot";
							control="ENH_EstablishingShot";
							expression="if (!is3DEN && ((_value # 0) isNotEqualTo [0, 0, 0]) && hasInterface) then {_value spawn BIS_fnc_establishingShot}";
							defaultValue="[[0, 0, 0], getText (configFile >> 'CfgWorlds' >> worldName >> 'description'), 500, 200, 60, 0]";
						};
					};
				};
				class ENH_IntroText
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_INTROTEXT_DISPLAYNAME";
					class Attributes
					{
						class ENH_IntroText_Subcategory
						{
							description="$STR_ENH_MAIN_INTROTEXT_DESCRIPTION";
							data="AttributeSystemSubcategory";
							control="ENH_SubCategoryNoHeader1_Fixed";
						};
						class ENH_IntroText
						{
							displayName="$STR_ENH_MAIN_INTROTEXT_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_INTROTEXT_DESCRIPTION";
							property="ENH_introText";
							control="ENH_IntroText";
							expression="                if (!is3DEN && (_value # 0) > 0 && hasInterface) then                {                    _value spawn                    {                        scriptName 'ENH_Attribute_IntroText';                        params ['_delay', '_l1', '_l2', '_l3', '_type'];                        _l1 = _l1 call BIS_fnc_localize;                        _l2 = _l2 call BIS_fnc_localize;                        _l3 = _l3 call BIS_fnc_localize;                        uiSleep _delay;                        switch _type do                        {                            case 0:                            {                                private _text = parseText format                                [                                    ""<t align='right' size='1.6'><t font='PuristaBold' size='1.8'>%1<br/></t>%2<br/>%3</t>"",                                    _l1,                                    _l2,                                    _l3                                ];                                [_text, true] spawn BIS_fnc_textTiles;                            };                            case 1:                            {                                [_l1, _l2, _l3] spawn BIS_fnc_infoText;                            };                            case 2:                            {                                [_l1, _l2, _l3] spawn BIS_fnc_EXP_camp_SITREP;                            };                        };                    };                }";
							defaultValue="[0, briefingName, 'by ' + profileName, [daytime, 'HH:MM'] call BIS_fnc_TimeToString, 0]";
						};
					};
				};
				class ENH_MissionEnding_Casualties
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_DISPLAYNAME";
					class Attributes
					{
						class ENH_MissionEnding_Subcategory
						{
							description="$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_DESCRIPTION";
							property="ENH_MissionEnding_Subcategory";
							control="ENH_SubCategoryNoHeader3_Fixed";
						};
						class ENH_MissionEnding_Casualties
						{
							displayName="$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_MISSIONENDING_CASUALTIES_DESCRIPTION";
							property="ENH_missionEnding_casualties";
							control="ENH_MissionEnding_Casualties";
							expression="                if (!is3DEN && isServer && (_value # 1) != 'enddefault') then                {                    ENH_Casualties_Counter = 0;                                        addMissionEventHandler ['EntityKilled',                    {                        params ['_killed'];                        _thisArgs params ['_threshold', '_debriefing', '_isWin', '_side', '_threshold'];                                                if (side group _killed isEqualTo _side) then                        {                            ENH_Casualties_Counter = ENH_Casualties_Counter + 1;                        };                        if (ENH_Casualties_Counter >= _threshold) exitWith                        {                            removeMissionEventHandler [_thisEvent, _thisEventHandler];                            [_debriefing, _isWin] remoteExecCall ['BIS_fnc_endMission', 0];                        };                    }, _value];                };";
							defaultValue="[5, 'enddefault', false, civilian]";
						};
					};
				};
				class ENH_Volume
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_ATTRIBUTECATEGORY_VOLUME";
					class Attributes
					{
						class ENH_SoundVolume
						{
							displayName="$STR_ENH_MAIN_SOUNDVOLUME_DISPLAYNAME";
							tooltip="";
							property="ENH_soundVolume";
							control="Slider";
							expression="if (!is3DEN && hasInterface) then {0 fadeSound _value}";
							defaultValue=1;
						};
						class ENH_MusicVolume: ENH_SoundVolume
						{
							displayName="$STR_ENH_MAIN_MUSICVOLUME_DISPLAYNAME";
							property="ENH_musicVolume";
							expression="if (!is3DEN && hasInterface) then {0 fadeMusic _value}";
						};
						class ENH_RadioVolume: ENH_SoundVolume
						{
							displayName="$STR_ENH_MAIN_RADIOVOLUME_DISPLAYNAME";
							property="ENH_radioVolume";
							expression="if (!is3DEN && hasInterface) then {0 fadeRadio _value}";
						};
						class ENH_EnvironmentVolume: ENH_SoundVolume
						{
							displayName="$STR_ENH_MAIN_ENVIRONMENTVOLUME_DISPLAYNAME";
							property="ENH_environmentVolume";
							expression="if (!is3DEN && hasInterface) then {0 fadeEnvironment _value}";
						};
						class ENH_RandomMusic
						{
							displayName="$STR_ENH_MAIN_RANDOMMUSIC_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_RANDOMMUSIC_TOOLTIP";
							property="ENH_randomMusic";
							control="ENH_CfgMusic";
							expression="if (!is3DEN && (_value isNotEqualTo []) && hasInterface) then {playMusic (selectRandom _value)}";
							defaultValue="[]";
						};
					};
				};
				class ENH_SPR
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_SPR";
					class Attributes
					{
						class ENH_SPR_Subcategory
						{
							description="$STR_ENH_MAIN_SPR_DESCRIPTION";
							property="ENH_SPR_Subcategory";
							control="ENH_SubCategoryNoHeader2_Fixed";
						};
						class ENH_SPR
						{
							displayName="$STR_ENH_MAIN_SPR";
							property="ENH_SPR";
							control="ENH_SPR";
							expression="if (!is3DEN && _value # 0 > 0 && !isMultiplayer) then            {                ENH_SPR_Ruleset = _value param [0, 0];                ENH_SPR_Delay = _value param [1, 20];                ENH_SPR_CanDie = _value param [2, false];                ENH_SPR_RestoreLoadout = _value param [3, false];                ENH_SPR_OnRespawnCode = compile (_value param [4, '']);                ENH_SPR_Positions =                [                    allMapMarkers select {'respawn_east' in toLower _x} apply {getMarkerPos _x},                    allMapMarkers select {'respawn_west' in toLower _x} apply {getMarkerPos _x},                    allMapMarkers select {'respawn_guerilla' in toLower _x} apply {getMarkerPos _x},                    allMapMarkers select {'respawn_civilian' in toLower _x} apply {getMarkerPos _x}                ];                {                    _x setVariable ['ENH_SPR_OriginalSide', side group _x];                    _x setVariable ['ENH_SPR_OriginalLoadout', getUnitLoadout _x];                    _x addEventHandler ['handleDamage',                    {                        params ['_unit', '', '_damage', '', '', '_index'];                        if (!alive _unit || lifeState _unit isEqualTo 'INCAPACITATED') exitWith {0};                        if (_unit getVariable ['ENH_SPR_Tickets', 0] == 0) then                        {                            _unit removeEventHandler ['handleDamage', _thisEventHandler];                            _damage;                        };                        if (ENH_SPR_CanDie && _index in [1, 2] && _damage >= 1) exitWith                        {                            _unit removeEventHandler ['handleDamage', _thisEventHandler];                            1;                        };                        if (_index < 8 && (_damage min 0.95) == 0.95) then                        {                            setAccTime 1;                            _unit allowDamage false;                            _unit setCaptive true;                            _unit setUnconscious true;                            _unit setVariable ['ENH_SPR_Tickets', (_unit getVariable ['ENH_SPR_Tickets', 0]) - 1];                            if (isPlayer _unit) then {enableTeamSwitch false} else {removeSwitchableUnit _unit};                            moveOut _unit;                            _unit spawn ENH_fnc_SPR_respawnTimer;                        };                        _damage min 0.95;                    }];                } forEach (allUnits select {_x getVariable ['ENH_SPR_Tickets', 0] > 0});                                ENH_fnc_SPR_respawn =                {                    scriptName 'ENH_Attribute_SPR_Respawn';                    params ['_unit'];                    if (isPlayer _unit) then {enableTeamSwitch true} else {addSwitchableUnit _unit};                    if (ENH_SPR_RestoreLoadout) then {_unit setUnitLoadout (_unit getVariable 'ENH_SPR_OriginalLoadout')};                    private _sideID = (_unit getVariable 'ENH_SPR_OriginalSide') call BIS_fnc_sideID;                    private _positions = ENH_SPR_Positions select _sideID;                    if (_positions isNotEqualTo []) then                    {                        switch (ENH_SPR_Ruleset) do                        {                            case 3:                            {                                _unit setPos (([_positions, [], {_unit distance _x}, 'ASCEND'] call BIS_fnc_sortBy) select 0);                            };                            case 2:                            {                                _unit setPos selectRandom _positions;                            };                        };                    };                    _unit setUnconscious false;                    _unit allowDamage true;                    _unit setDamage 0;                    _unit switchMove '';                    _unit call ENH_SPR_OnRespawnCode;                    _unit spawn                    {                        sleep 8;                        _this setCaptive false;                    };                };                                ENH_fnc_SPR_respawnTimer =                {                    scriptName 'ENH_Attribute_SPR_RespawnTimer';                    params ['_unit'];                    private _respawnTime = time + ENH_SPR_Delay;                    if (isPlayer _unit) then                    {                        private _ctrlRespawnTimer = (call BIS_fnc_displayMission) ctrlCreate ['RscStructuredText',-1];                        _ctrlRespawnTimer ctrlSetPosition [0.25, 0, 0.5, 0.06];                        _ctrlRespawnTimer ctrlSetBackgroundColor [0, 0, 0, 0.1];                        _ctrlRespawnTimer ctrlCommit 0;                        ENH_SPR_OriginalVolume = [soundVolume, musicVolume, radioVolume, speechVolume, environmentVolume];                        0 cutText ['', 'BLACK OUT', 0.3];                        0.3 fadeSound 0;                        0.3 fadeMusic 0;                        0.3 fadeRadio 0;                        0.3 fadeSpeech 0;                        0.3 fadeEnvironment 0;                        showChat false;                        while {time < _respawnTime} do                        {                            _ctrlRespawnTimer ctrlSetStructuredText parseText format ['<t size=''1.25'' color=''#218a36'' align=''center''>%1</t>', [(_respawnTime - time), 'HH:MM'] call BIS_fnc_timeToString];                            sleep 0.1;                        };                        ctrlDelete _ctrlRespawnTimer;                        0 cutText ['', 'BLACK IN', 8];                        8 fadeSound (ENH_SPR_OriginalVolume # 0);                        8 fadeMusic (ENH_SPR_OriginalVolume # 1);                        8 fadeRadio (ENH_SPR_OriginalVolume # 2);                        8 fadeSpeech (ENH_SPR_OriginalVolume # 3);                        8 fadeEnvironment (ENH_SPR_OriginalVolume # 4);                        showChat true;                        [                            ['Respawned'],                            [format ['GRID: %1', mapGridPosition _unit]],                            [format ['Tickets left: %1', _unit getVariable 'ENH_SPR_Tickets']]                        ] spawn BIS_fnc_EXP_camp_SITREP;                    }                    else                    {                        private _respawnEH = -1;                        if ((side player getFriend (_unit getVariable 'ENH_SPR_OriginalSide')) >= 0.6) then                        {                            _respawnEH = addMissionEventHandler                            [                                'draw3D',                                {                                    drawIcon3D ['\a3\Modules_f\data\portraitRespawn_ca.paa', [0.13, 0.54, 0.21, 0.8], ASLToAGL ((_thisArgs # 0) modelToWorldVisualWorld [0, 0, 1]), 1, 1, 0, str round ((_thisArgs # 1) - time), 2];                                },                                [_unit, _respawnTime]                            ];                        };                        sleep ENH_SPR_Delay;                        removeMissionEventHandler ['draw3D', _respawnEH];                        [str _unit, 'onEachFrame'] call BIS_fnc_removeStackedEventHandler;                    };                    _unit call ENH_fnc_SPR_respawn;                };            }";
							defaultValue="[0, 20, false, false, '']";
						};
					};
				};
				class ENH_MissionEventHandlers_Global
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_GLOBAL_DISPLAYNAME";
					class Attributes
					{
						class ENH_MissionEventHandlers_Global_Subcategory
						{
							description="$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_GLOBAL_DESCRIPTION";
							property="ENH_MissionEventHandlers_Global_Subcategory";
							control="ENH_SubCategoryNoHeader3_Fixed";
						};
						class ENH_MissionEventHandlers_ArtilleryShellFired
						{
							displayName="ArtilleryShellFired";
							property="ENH_MissionEventHandlers_ArtilleryShellFired";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_ArtilleryShellFired_ID = addMissionEventHandler [""ArtilleryShellFired"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_BuildingChanged
						{
							displayName="BuildingChanged";
							property="ENH_MissionEventHandlers_BuildingChanged";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_BuildingChanged_ID = addMissionEventHandler [""BuildingChanged"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_CommandModeChanged
						{
							displayName="CommandModeChanged";
							property="ENH_MissionEventHandlers_CommandModeChanged";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_CommandModeChanged_ID = addMissionEventHandler [""CommandModeChanged"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_ControlsShifted
						{
							displayName="ControlsShifted";
							property="ENH_MissionEventHandlers_ControlsShifted";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_ControlsShifted_ID = addMissionEventHandler [""ControlsShifted"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_Draw2D
						{
							displayName="Draw2D";
							property="ENH_MissionEventHandlers_Draw2D";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_Draw2D_ID = addMissionEventHandler [""Draw2D"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_Draw3D
						{
							displayName="Draw3D";
							property="ENH_MissionEventHandlers_Draw3D";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_Draw3D_ID = addMissionEventHandler [""Draw3D"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_Drowned
						{
							displayName="Drowned";
							property="ENH_MissionEventHandlers_Drowned";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_Drowned_ID = addMissionEventHandler [""Drowned"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_EachFrame
						{
							displayName="EachFrame";
							property="ENH_MissionEventHandlers_EachFrame";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_EachFrame_ID = addMissionEventHandler [""EachFrame"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_Ended
						{
							displayName="Ended";
							property="ENH_MissionEventHandlers_Ended";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_Ended_ID = addMissionEventHandler [""Ended"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_MPEnded
						{
							displayName="MPEnded";
							property="ENH_MissionEventHandlers_MPEnded";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_MPEnded_ID = addMissionEventHandler [""MPEnded"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_EntityCreated
						{
							displayName="EntityCreated";
							property="ENH_MissionEventHandlers_EntityCreated";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_EntityCreated_ID = addMissionEventHandler [""EntityCreated"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_EntityDeleted
						{
							displayName="EntityDeleted";
							property="ENH_MissionEventHandlers_EntityDeleted";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_EntityDeleted_ID = addMissionEventHandler [""EntityDeleted"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_EntityKilled
						{
							displayName="EntityKilled";
							property="ENH_MissionEventHandlers_EntityKilled";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_EntityKilled_ID = addMissionEventHandler [""EntityKilled"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_EntityRespawned
						{
							displayName="EntityRespawned";
							property="ENH_MissionEventHandlers_EntityRespawned";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_EntityRespawned_ID = addMissionEventHandler [""EntityRespawned"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_ExtensionCallback
						{
							displayName="ExtensionCallback";
							property="ENH_MissionEventHandlers_ExtensionCallback";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_ExtensionCallback_ID = addMissionEventHandler [""ExtensionCallback"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_GroupCreated
						{
							displayName="GroupCreated";
							property="ENH_MissionEventHandlers_GroupCreated";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_GroupCreated_ID = addMissionEventHandler [""GroupCreated"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_GroupDeleted
						{
							displayName="GroupDeleted";
							property="ENH_MissionEventHandlers_GroupDeleted";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_GroupDeleted_ID = addMissionEventHandler [""GroupDeleted"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_GroupIconClick
						{
							displayName="GroupIconClick";
							property="ENH_MissionEventHandlers_GroupIconClick";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_GroupIconClick_ID = addMissionEventHandler [""GroupIconClick"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_GroupIconOverEnter
						{
							displayName="GroupIconOverEnter";
							property="ENH_MissionEventHandlers_GroupIconOverEnter";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_GroupIconOverEnter_ID = addMissionEventHandler [""GroupIconOverEnter"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_GroupIconOverLeave
						{
							displayName="GroupIconOverLeave";
							property="ENH_MissionEventHandlers_GroupIconOverLeave";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_GroupIconOverLeave_ID = addMissionEventHandler [""GroupIconOverLeave"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_HandleAccTime
						{
							displayName="HandleAccTime";
							property="ENH_MissionEventHandlers_HandleAccTime";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_HandleAccTime_ID = addMissionEventHandler [""HandleAccTime"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_HandleChatMessage
						{
							displayName="HandleChatMessage";
							property="ENH_MissionEventHandlers_HandleChatMessage";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_HandleChatMessage_ID = addMissionEventHandler [""HandleChatMessage"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_HCGroupSelectionChanged
						{
							displayName="HCGroupSelectionChanged";
							property="ENH_MissionEventHandlers_HCGroupSelectionChanged";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_HCGroupSelectionChanged_ID = addMissionEventHandler [""HCGroupSelectionChanged"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_Loaded
						{
							displayName="Loaded";
							property="ENH_MissionEventHandlers_Loaded";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_Loaded_ID = addMissionEventHandler [""Loaded"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_Map
						{
							displayName="Map";
							property="ENH_MissionEventHandlers_Map";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_Map_ID = addMissionEventHandler [""Map"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_MapSingleClick
						{
							displayName="MapSingleClick";
							property="ENH_MissionEventHandlers_MapSingleClick";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_MapSingleClick_ID = addMissionEventHandler [""MapSingleClick"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_MarkerCreated
						{
							displayName="MarkerCreated";
							property="ENH_MissionEventHandlers_MarkerCreated";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_MarkerCreated_ID = addMissionEventHandler [""MarkerCreated"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_MarkerDeleted
						{
							displayName="MarkerDeleted";
							property="ENH_MissionEventHandlers_MarkerDeleted";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_MarkerDeleted_ID = addMissionEventHandler [""MarkerDeleted"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_MarkerUpdated
						{
							displayName="MarkerUpdated";
							property="ENH_MissionEventHandlers_MarkerUpdated";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_MarkerUpdated_ID = addMissionEventHandler [""MarkerUpdated"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_PlayerViewChanged
						{
							displayName="PlayerViewChanged";
							property="ENH_MissionEventHandlers_PlayerViewChanged";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_PlayerViewChanged_ID = addMissionEventHandler [""PlayerViewChanged"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_PreloadStarted
						{
							displayName="PreloadStarted";
							property="ENH_MissionEventHandlers_PreloadStarted";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_PreloadStarted_ID = addMissionEventHandler [""PreloadStarted"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_PreloadFinished
						{
							displayName="PreloadFinished";
							property="ENH_MissionEventHandlers_PreloadFinished";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_PreloadFinished_ID = addMissionEventHandler [""PreloadFinished"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_ProjectileCreated
						{
							displayName="ProjectileCreated";
							property="ENH_MissionEventHandlers_ProjectileCreated";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_ProjectileCreated_ID = addMissionEventHandler [""ProjectileCreated"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_SaveGame
						{
							displayName="SaveGame";
							property="ENH_MissionEventHandlers_SaveGame";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_SaveGame_ID = addMissionEventHandler [""SaveGame"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_ScriptError
						{
							displayName="ScriptError";
							property="ENH_MissionEventHandlers_ScriptError";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_ScriptError_ID = addMissionEventHandler [""ScriptError"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_SelectedActionPerformed
						{
							displayName="SelectedActionPerformed";
							property="ENH_MissionEventHandlers_SelectedActionPerformed";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_SelectedActionPerformed_ID = addMissionEventHandler [""SelectedActionPerformed"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_SelectedActionChanged
						{
							displayName="SelectedActionChanged";
							property="ENH_MissionEventHandlers_SelectedActionChanged";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_SelectedActionChanged_ID = addMissionEventHandler [""SelectedActionChanged"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_SelectedRotorLibActionPerformed
						{
							displayName="SelectedRotorLibActionPerformed";
							property="ENH_MissionEventHandlers_SelectedRotorLibActionPerformed";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_SelectedRotorLibActionPerformed_ID = addMissionEventHandler [""SelectedRotorLibActionPerformed"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_SelectedRotorLibActionChanged
						{
							displayName="SelectedRotorLibActionChanged";
							property="ENH_MissionEventHandlers_SelectedRotorLibActionChanged";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_SelectedRotorLibActionChanged_ID = addMissionEventHandler [""SelectedRotorLibActionChanged"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_Service
						{
							displayName="Service";
							property="ENH_MissionEventHandlers_Service";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_Service_ID = addMissionEventHandler [""Service"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_TeamSwitch
						{
							displayName="TeamSwitch";
							property="ENH_MissionEventHandlers_TeamSwitch";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_TeamSwitch_ID = addMissionEventHandler [""TeamSwitch"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_UAVCrewCreated
						{
							displayName="UAVCrewCreated";
							property="ENH_MissionEventHandlers_UAVCrewCreated";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN) then {ENH_MissionEventHandlers_UAVCrewCreated_ID = addMissionEventHandler [""UAVCrewCreated"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
					};
				};
				class ENH_MissionEventHandlers_Server
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_SERVER_DISPLAYNAME";
					class Attributes
					{
						class ENH_MissionEventHandlers_Server_Subcategory
						{
							description="$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_SERVER_DESCRIPTION";
							property="ENH_MissionEventHandlers_Server_Subcategory";
							control="ENH_SubCategoryNoHeader3_Fixed";
						};
						class ENH_MissionEventHandlers_HandleDisconnect
						{
							displayName="HandleDisconnect";
							property="ENH_MissionEventHandlers_HandleDisconnect";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN && isServer) then {ENH_MissionEventHandlers_HandleDisconnect_ID = addMissionEventHandler [""HandleDisconnect"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_OnUserConnected
						{
							displayName="OnUserConnected";
							property="ENH_MissionEventHandlers_OnUserConnected";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN && isServer) then {ENH_MissionEventHandlers_OnUserConnected_ID = addMissionEventHandler [""OnUserConnected"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_OnUserDisconnected
						{
							displayName="OnUserDisconnected";
							property="ENH_MissionEventHandlers_OnUserDisconnected";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN && isServer) then {ENH_MissionEventHandlers_OnUserDisconnected_ID = addMissionEventHandler [""OnUserDisconnected"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_OnUserClientStateChanged
						{
							displayName="OnUserClientStateChanged";
							property="ENH_MissionEventHandlers_OnUserClientStateChanged";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN && isServer) then {ENH_MissionEventHandlers_OnUserClientStateChanged_ID = addMissionEventHandler [""OnUserClientStateChanged"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_OnUserAdminStateChanged
						{
							displayName="OnUserAdminStateChanged";
							property="ENH_MissionEventHandlers_OnUserAdminStateChanged";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN && isServer) then {ENH_MissionEventHandlers_OnUserAdminStateChanged_ID = addMissionEventHandler [""OnUserAdminStateChanged"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_OnUserSelectedPlayer
						{
							displayName="OnUserSelectedPlayer";
							property="ENH_MissionEventHandlers_OnUserSelectedPlayer";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN && isServer) then {ENH_MissionEventHandlers_OnUserSelectedPlayer_ID = addMissionEventHandler [""OnUserSelectedPlayer"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_OnUserKicked
						{
							displayName="OnUserKicked";
							property="ENH_MissionEventHandlers_OnUserKicked";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN && isServer) then {ENH_MissionEventHandlers_OnUserKicked_ID = addMissionEventHandler [""OnUserKicked"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_PlayerConnected
						{
							displayName="PlayerConnected";
							property="ENH_MissionEventHandlers_PlayerConnected";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN && isServer) then {ENH_MissionEventHandlers_PlayerConnected_ID = addMissionEventHandler [""PlayerConnected"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MissionEventHandlers_PlayerDisconnected
						{
							displayName="PlayerDisconnected";
							property="ENH_MissionEventHandlers_PlayerDisconnected";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN && isServer) then {ENH_MissionEventHandlers_PlayerDisconnected_ID = addMissionEventHandler [""PlayerDisconnected"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
					};
				};
				class ENH_MusicEventHandlers_Global
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_MUSIC_GLOBAL_DISPLAYNAME";
					class Attributes
					{
						class ENH_MusicEventHandlers_Server_Subcategory
						{
							description="$STR_ENH_MAIN_MISSION_ATTRIBUTES_EVENT_HANDLERS_MUSIC_GLOBAL_DESCRIPTION";
							property="ENH_MusicEventHandlers_Server_Subcategory";
							control="ENH_SubCategoryNoHeader3_Fixed";
						};
						class ENH_MusicEventHandlers_MusicStart
						{
							displayName="MusicStart";
							property="ENH_MusicEventHandlers_MusicStart";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN && hasInterface) then {ENH_MusicEventHandlers_MusicStart_ID = addMusicEventHandler [""MusicStart"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
						class ENH_MusicEventHandlers_MusicStop
						{
							displayName="MusicStop";
							property="ENH_MusicEventHandlers_MusicStop";
							control="EditCodeMulti5";
							expression="(if (_value != '' && !is3DEN && hasInterface) then {ENH_MusicEventHandlers_MusicStop_ID = addMusicEventHandler [""MusicStop"", compile _value]})";
							condition=1;
							defaultValue="''";
							validate="expression";
						};
					};
				};
				class Misc
				{
					class Attributes
					{
						class ENH_BackupMissionSQMDisable
						{
							displayName="$STR_ENH_MAIN_BACKUPMISSIONSQM_DISABLE_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_BACKUPMISSIONSQM_DISABLE_TOOLTIP";
							property="ENH_BackupMissionSQMDisable";
							control="Checkbox";
							expression="";
							defaultValue="false";
						};
						class ENH_AddObjectsToZeus
						{
							displayName="$STR_ENH_MAIN_EDITABLEOBJZEUS_DISPLAYNAME";
							property="ENH_AddObjectsToZeus";
							control="Combo";
							expression="        if (_value isEqualType true) then {_value = 2};        if (!is3DEN && isServer && _value > 0) then        {            _value spawn" \n "            {" \n "                params ['_value'];" \n "                waitUntil {sleep 1; allCurators isNotEqualTo []};" \n "                if (_value == 1 || _value == 2) then                {                    allCurators apply {_x addCuratorEditableObjects [allMissionObjects '', true]};                };                if (_value == 2) then                {                    addMissionEventHandler ['EntityCreated',                    {                        params ['_entity'];                        allCurators apply {_x addCuratorEditableObjects [[_entity], true]};                    }];                };            };        }";
							defaultValue=0;
							typeName="NUMBER";
							class Values
							{
								class Disabled
								{
									name="$STR_DISABLED";
									value=0;
								};
								class EditorPlacedOnly
								{
									name="$STR_ENH_MAIN_EDITABLEOBJZEUS_EDITORPLACEONLY_DISPLAYNAME";
									tooltip="$STR_ENH_MAIN_EDITABLEOBJZEUS_EDITORPLACEONLY_TOOLTIP";
									value=1;
								};
								class All
								{
									name="$STR_ENH_MAIN_EDITABLEOBJZEUS_ALL_DISPLAYNAME";
									tooltip="$STR_ENH_MAIN_EDITABLEOBJZEUS_ALL_TOOLTIP";
									value=2;
								};
							};
						};
						class ENH_MapIndicators
						{
							displayName="$STR_ENH_MAIN_ATTRIBUTECATEGORY_MAPINDICATORS";
							property="ENH_mapIndicators";
							control="ENH_MapIndicators";
							expression="if (!is3DEN && (_value isNotEqualTo [false, false, false, false]) && hasInterface) then {disableMapIndicators _value}";
							defaultValue="[false, false, false, false]";
						};
					};
				};
			};
		};
		class Multiplayer
		{
			class AttributeCategories
			{
				class ENH_DynamicGroups
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_DYNAMICGROUPS_DISPLAYNAME";
					class Attributes
					{
						class ENH_EnableDynamicGroups
						{
							displayName="$STR_ENH_MAIN_ENABLE";
							tooltip="$STR_ENH_MAIN_DYNAMICGROUPS_TOOLTIP";
							property="ENH_dynamicGroups";
							control="Checkbox";
							expression="                if (!is3DEN && isMultiplayer && _value) then                {                    if (isServer) then {['Initialize'] call BIS_fnc_dynamicGroups};                    if (hasInterface) then                    {                        0 spawn                        {                            scriptName 'ENH_Attribute_DynamicGroups';                            waitUntil {!isNull player};                            ['InitializePlayer', [player]] call BIS_fnc_dynamicGroups;                        };                    };                };            ";
							defaultValue="false";
						};
					};
				};
				class ENH_DynamicSkill
				{
					collapsed=1;
					displayName="$STR_ENH_MAIN_ATTRIBUTECATEGORY_DYNAMICSKILL";
					class Attributes
					{
						class ENH_DynamicSkill_Subcategory
						{
							description="$STR_ENH_MAIN_DYNAMICSKILL_DESCRIPTION";
							property="ENH_DynamicSkill_Subcategory";
							control="ENH_SubCategoryNoHeader2_Fixed";
						};
						class ENH_DynamicSkill_Enable
						{
							displayName="$STR_ENH_MAIN_ATTRIBUTECATEGORY_DYNAMICSKILL";
							property="ENH_dynamicSkill";
							control="ENH_DynamicSkill";
							expression="if (!is3DEN && _value # 0 && isServer) then            {                _value params                [                    '_enable',                    '_skillMinBLUFOR',                    '_skillAimMinBLUFOR',                    '_skillMaxBLUFOR',                    '_skillAimMaxBlUFOR',                    '_skillMinOPFOR',                    '_skillAimMinOPFOR',                    '_skillMaxOPFOR',                    '_skillAimMaxOPFOR',                    '_skillMinIndependent',                    '_skillAimMinIndependent',                    '_skillMaxIndependent',                    '_skillAimMaxIndependent'                ];                [                    true,                    [                        [WEST, _skillMinBLUFOR, _skillAimMinBLUFOR, _skillMaxBLUFOR, _skillAimMaxBlUFOR],                        [EAST, _skillMinOPFOR, _skillAimMinOPFOR, _skillMaxOPFOR, _skillAimMaxOPFOR],                        [INDEPENDENT, _skillMinIndependent, _skillAimMinIndependent, _skillMaxIndependent, _skillAimMaxIndependent]                    ]                ] call BIS_fnc_EXP_camp_dynamicAISkill;            }";
							defaultValue="[false, 0.5, 0.3, 0.8, 0.5, 0.5, 0.3, 0.8, 0.5, 0.5, 0.3, 0.8, 0.5]";
						};
					};
				};
				class Respawn
				{
					class Attributes
					{
						class ENH_TicketsBLUFOR
						{
							displayName="$STR_ENH_MAIN_RESPAWNTICKETS_BLUFOR_DISPLAYNAME";
							tooltip="";
							property="ENH_respawnTickets_west";
							control="Edit";
							expression="if (!is3DEN && isMultiplayer && isServer) then {[west, _value] call BIS_fnc_respawnTickets}";
							defaultValue=0;
							typeName="NUMBER";
						};
						class ENH_TicketsOPFOR: ENH_TicketsBLUFOR
						{
							displayName="$STR_ENH_MAIN_RESPAWNTICKETS_OPFOR_DISPLAYNAME";
							property="ENH_respawnTickets_east";
							expression="if (!is3DEN && isMultiplayer && isServer) then {[east, _value] call BIS_fnc_respawnTickets}";
						};
						class ENH_TicketsIndependent: ENH_TicketsBLUFOR
						{
							displayName="$STR_ENH_MAIN_RESPAWNTICKETS_INDEPENDENT_DISPLAYNAME";
							property="ENH_respawnTickets_independent";
							expression="if (!is3DEN && isMultiplayer && isServer) then {[independent, _value] call BIS_fnc_respawnTickets}";
						};
						class ENH_TicketsCivilian: ENH_TicketsBLUFOR
						{
							displayName="$STR_ENH_MAIN_RESPAWNTICKETS_CIVILIAN_DISPLAYNAME";
							property="ENH_respawnTickets_civilian";
							expression="if (!is3DEN && isMultiplayer && isServer) then {[civilian, _value] call BIS_fnc_respawnTickets}";
						};
						class ENH_SaveLoadout
						{
							displayName="$STR_ENH_MAIN_SAVELOADOUT_DISPLAYNAME";
							tooltip="$STR_ENH_MAIN_SAVELOADOUT_TOOLTIP";
							property="ENH_saveLoadout";
							control="Checkbox";
							expression="if (!isMultiplayer || !_value || is3DEN || !hasInterface) exitWith {};        0 spawn        {            waitUntil {sleep 1; !isNull player};            player setVariable ['ENH_savedLoadout', getUnitloadout player];            player addMPEventHandler ['MPRespawn',            {                params ['_unit'];                private _loadout = _unit getVariable ['ENH_savedLoadout', []];                if (_loadout isNotEqualTo []) then {_unit setUnitLoadout _loadout};            }];        };";
							defaultValue="false";
						};
					};
				};
			};
		};
	};
	class Group
	{
		class AttributeCategories
		{
			class ENH_GroupMarker
			{
				displayName="$STR_ENH_MAIN_GROUPMARKER_DISPLAYNAME";
				collapsed=1;
				class Attributes
				{
					class ENH_GroupMarker_Subcategory
					{
						description="$STR_ENH_MAIN_GROUPMARKER_DESCRIPTION";
						property="ENH_GroupMarker_Subcategory";
						control="ENH_SubCategoryNoHeader3_Fixed";
					};
					class ENH_GroupMarker
					{
						displayName="$STR_ENH_MAIN_GROUPMARKER_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_GROUPMARKER_DESCRIPTION";
						property="ENH_groupMarker";
						control="ENH_GroupMarker";
						expression="            if (!is3DEN && (_value # 0 != '')) then            {                [_this, _value] spawn {                    scriptName 'ENH_Attribute_GroupMarker';                    params ['_group', '_parameters'];                    _parameters params [['_type', ''], ['_color', 'Default'], ['_text', groupID _group], ['_showGroupSize', true], ['_showVehicle', true]];                    private _marker = createMarkerLocal [                        'ENH_GroupMarker_' + str _group,                        [0, 0]                    ];                    _marker setMarkerTypeLocal _type;                    _marker setMarkerColorLocal _color;                    _marker setMarkerTextLocal (_text call BIS_fnc_localize);                    private _groupString = _text call BIS_fnc_localize;                    while {true} do                    {                        sleep 1;                        if (isNull _group) exitWith {deleteMarker _marker};                        if (_group getVariable ['ENH_GroupMarker_Update', true]) then                        {                            private _leader = leader _group;                            _marker setMarkerPos _leader;                            private _sizeString = (' (' + str count units _group + ')');                            if (_showGroupSize && {vehicle _leader != _leader}) then                            {                                private _vehicleName = getText (configOf vehicle _leader >> 'displayName');                                private _vehicleString = (' [' + _vehicleName + ']');                                if _showGroupSize then                                {                                    _marker setMarkerTextLocal (_groupString + _vehicleString + _sizeString);                                }                                else                                {                                    _marker setMarkerTextLocal (_groupString + _vehicleString);                                };                            }                            else                            {                                if _showGroupSize then                                {                                    _marker setMarkerTextLocal (_groupString + _sizeString);                                };                            };                        };                    };                };            };";
						defaultValue="['', 'Default', '', true, true]";
					};
				};
			};
			class ENH_EventHandlers
			{
				collapsed=1;
				displayName="$STR_ENH_MAIN_ATTRIBUTES_EVENT_HANDLERS_DISPLAYNAME";
				class Attributes
				{
					class ENH_EventHandlers_Subcategory
					{
						description="$STR_ENH_MAIN_GROUP_ATTRIBUTES_EVENT_HANDLERS_DESCRIPTION";
						property="ENH_EventHandlers_Subcategory";
						control="ENH_SubCategoryNoHeader3_Fixed";
					};
					class ENH_EventHandlers_CombatModeChanged
					{
						displayName="CombatModeChanged";
						property="ENH_EventHandlers_CombatModeChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""CombatModeChanged"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_CommandChanged
					{
						displayName="CommandChanged";
						property="ENH_EventHandlers_CommandChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""CommandChanged"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Deleted
					{
						displayName="Deleted";
						property="ENH_EventHandlers_Deleted";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Deleted"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Empty
					{
						displayName="Empty";
						property="ENH_EventHandlers_Empty";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Empty"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_EnableAttackChanged
					{
						displayName="EnableAttackChanged";
						property="ENH_EventHandlers_EnableAttackChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""EnableAttackChanged"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_EnemyDetected
					{
						displayName="EnemyDetected";
						property="ENH_EventHandlers_EnemyDetected";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""EnemyDetected"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Fleeing
					{
						displayName="Fleeing";
						property="ENH_EventHandlers_Fleeing";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Fleeing"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_FormationChanged
					{
						displayName="FormationChanged";
						property="ENH_EventHandlers_FormationChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""FormationChanged"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_GroupIdChanged
					{
						displayName="GroupIdChanged";
						property="ENH_EventHandlers_GroupIdChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""GroupIdChanged"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_KnowsAboutChanged
					{
						displayName="KnowsAboutChanged";
						property="ENH_EventHandlers_KnowsAboutChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""KnowsAboutChanged"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_LeaderChanged
					{
						displayName="LeaderChanged";
						property="ENH_EventHandlers_LeaderChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""LeaderChanged"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Local
					{
						displayName="Local";
						property="ENH_EventHandlers_Local";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Local"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_SpeedModeChanged
					{
						displayName="SpeedModeChanged";
						property="ENH_EventHandlers_SpeedModeChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""SpeedModeChanged"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_UnitJoined
					{
						displayName="UnitJoined";
						property="ENH_EventHandlers_UnitJoined";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""UnitJoined"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_UnitKilled
					{
						displayName="UnitKilled";
						property="ENH_EventHandlers_UnitKilled";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""UnitKilled"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_UnitLeft
					{
						displayName="UnitLeft";
						property="ENH_EventHandlers_UnitLeft";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""UnitLeft"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_VehicleAdded
					{
						displayName="VehicleAdded";
						property="ENH_EventHandlers_VehicleAdded";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""VehicleAdded"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_VehicleRemoved
					{
						displayName="VehicleRemoved";
						property="ENH_EventHandlers_VehicleRemoved";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""VehicleRemoved"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_WaypointComplete
					{
						displayName="WaypointComplete";
						property="ENH_EventHandlers_WaypointComplete";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""WaypointComplete"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
				};
			};
			class State
			{
				class Attributes
				{
					class ENH_TaskPatrol
					{
						displayName="$STR_ENH_MAIN_PATROL_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_PATROL_TOOLTIP";
						property="ENH_TaskPatrol";
						control="EditShort";
						expression="if (!is3DEN && _value > 0) then {[_this, getPosATL (leader _this), _value] call BIS_fnc_taskPatrol}";
						defaultValue=0;
						typeName="NUMBER";
					};
				};
			};
		};
	};
	class Object
	{
		class AttributeCategories
		{
			class ENH_AdvancedDamage
			{
				displayName="$STR_ENH_MAIN_ATTRIBUTECATEGORY_ADVANCEDDAMAGE";
				collapsed=1;
				class Attributes
				{
					class ENH_AdvancedDamage_Subcategory
					{
						description="$STR_ENH_MAIN_ADVANCEDDAMAGE_DESCRIPTION";
						data="AttributeSystemSubcategory";
						control="ENH_SubCategoryNoHeader2_Fixed";
					};
					class ENH_AdvancedDamage
					{
						displayName="$STR_ENH_MAIN_ATTRIBUTECATEGORY_ADVANCEDDAMAGE";
						tooltip="$STR_ENH_MAIN_ADVANCEDDAMAGE_DESCRIPTION";
						property="ENH_AdvancedDamage";
						expression="if (local _this) then {parseSimpleArray _value params ['_hitpoints', '_damage']; {if ((_damage # _forEachIndex) == 0) then {continue}; _this setHitPointDamage [_x, _damage # _forEachIndex, false]} forEach _hitpoints}";
						control="ENH_AdvancedDamage";
						defaultValue="if (getAllHitPointsDamage _this isNotEqualTo []) then {str [getAllHitPointsDamage _this # 0, getAllHitPointsDamage _this # 2]} else {str [[], []]}";
						typeName="STRING";
						condition="objectVehicle + objectBrain";
					};
				};
			};
			class ENH_AmbientAnimations
			{
				collapsed=1;
				displayName="$STR_ENH_MAIN_AMBIENTANIMATIONS_DISPLAYNAME";
				class Attributes
				{
					class ENH_AmbientAnimations_Subcategory
					{
						description="$STR_ENH_MAIN_AMBIENTANIMATIONS_DESCRIPTION";
						data="AttributeSystemSubcategory";
						control="ENH_SubCategoryNoHeader1_Fixed";
					};
					class ENH_AmbientAnimations
					{
						displayName="$STR_ENH_MAIN_AMBIENTANIMATIONS_DISPLAYNAME";
						control="ENH_AmbientAnimations";
						property="ENH_AmbientAnimations";
						expression="            if (_value # 0 != '') then            {                _value params ['_animSet', '_anims', '_canExit', '_attach'];                                _this setVariable ['ENH_ambientAnimations_anims', _anims];                _this disableAI 'ANIM';                if (_attach && !is3DEN) then                {                    private _logic = group _this createUnit ['Logic', getPosATL _this, [], 0, 'NONE'];                    _this setVariable ['ENH_ambientAnimations_logic', _logic];                    [_this, _logic] call BIS_fnc_attachToRelative;                };                                ENH_fnc_ambientAnimations_play =                {                    params ['_unit'];                    private _anim = selectRandom (_unit getVariable ['ENH_ambientAnimations_anims', []]);                    [_unit, _anim] remoteExec ['switchMove', 0];                };                                ENH_fnc_ambientAnimations_exit =                {                    params ['_unit'];                    if !(_unit getVariable ['ENH_ambientAnimations_exit', true]) exitWith {false};                    _unit setVariable ['ENH_ambientAnimations_exit', true];                    detach _unit;                    deleteVehicle (_unit getVariable ['ENH_ambientAnimations_logic', objNull]);                    if (alive _unit) then                    {                        [_unit, ''] remoteExec ['switchMove', 0];                        _unit enableAI 'ANIM';                    };                    _unit removeEventHandler ['Killed', _unit getVariable ['ENH_EHKilled',-1]];                    _unit removeEventHandler ['Dammaged', _unit getVariable ['ENH_EHDammaged',-1]];                    _unit removeEventHandler ['AnimDone', _unit getVariable ['ENH_EHAnimDone',-1]];                };                                private _EHAnimDone = _this addEventHandler ['AnimDone',                    {                        params ['_unit'];                        if (alive _unit) then                        {                            _unit call ENH_fnc_ambientAnimations_play;                        }                        else                        {                            _unit call ENH_fnc_ambientAnimations_exit;                        };                    }                ];                _this setVariable ['ENH_EHAnimDone', _EHAnimDone];                                if (_canExit && !is3DEN) then                {                    private _EHKilled = _this addEventHandler ['Killed',                    {                        (_this select 0) call ENH_fnc_ambientAnimations_exit;                    }];                    _this setVariable ['ENH_EHKilled', _EHKilled];                    private _EHDammaged = _this addEventHandler ['Dammaged',                    {                        (_this select 0) call ENH_fnc_ambientAnimations_exit;                    }];                    _this setVariable ['ENH_EHDammaged', _EHDammaged];                    _this spawn                    {                        scriptName 'ENH_Attribute_AmbientAnimations';                        params ['_unit'];                        waitUntil                        {                            sleep 1; (_unit getVariable ['ENH_ambientAnimations_exit', false]) || {behaviour _unit == 'COMBAT'}                        };                        _unit call ENH_fnc_ambientAnimations_exit;                    };                };                _this call ENH_fnc_ambientAnimations_play;            };";
						condition="objectBrain";
						defaultValue="['', [], false, false]";
					};
				};
			};
			class ENH_AI
			{
				displayName="$STR_ENH_MAIN_AI_CATEGORY";
				collapsed=1;
				class Attributes
				{
					class ENH_AI_Skill_Subcategory
					{
						description="$STR_A3_RSCDISPLAYGAMEOPTIONS_TEXTAISKILL";
						data="AttributeSystemSubcategory";
						control="ENH_SubCategoryNoHeader1_Fixed";
					};
					class ENH_AimingShake
					{
						displayName="$STR_ENH_MAIN_AIMINGSHAKE_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_AIMINGSHAKE_TOOLTIP";
						property="ENH_aimingShake";
						expression="if (_value != 0.5) then {[_this, ['aimingShake', _value]] remoteExec ['setSkill', _this]}";
						control="Slider";
						defaultValue=0.5;
						condition="objectBrain";
					};
					class ENH_AimingSpeed: ENH_AimingShake
					{
						displayName="$STR_ENH_MAIN_AIMINGSPEED_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_AIMINGSPEED_TOOLTIP";
						property="ENH_aimingSpeed";
						expression="if (_value != 0.5) then {[_this, ['aimingSpeed', _value]] remoteExec ['setSkill', _this]}";
					};
					class ENH_AimingAccuracy: ENH_AimingShake
					{
						displayName="$STR_ENH_MAIN_AIMINGACCURACY_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_AIMINGACCURACY_TOOLTIP";
						property="ENH_aimingAccuracy";
						expression="if (_value != 0.5) then {[_this, ['aimingAccuracy', _value]] remoteExec ['setSkill', _this]}";
					};
					class ENH_Commanding: ENH_AimingShake
					{
						displayName="$STR_ENH_MAIN_COMMANDING_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_COMMANDING_TOOLTIP";
						property="ENH_commanding";
						expression="if (_value != 0.5) then {[_this, ['commanding', _value]] remoteExec ['setSkill', _this]}";
					};
					class ENH_Courage: ENH_AimingShake
					{
						displayName="$STR_ENH_MAIN_COURAGE_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_COURAGE_TOOLTIP";
						property="ENH_courage";
						expression="if (_value != 0.5) then {[_this, ['courage', _value]] remoteExec ['setSkill', _this]}";
					};
					class ENH_General: ENH_AimingShake
					{
						displayName="$STR_ENH_MAIN_GENERAL_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_GENERAL_TOOLTIP";
						property="enh_general";
						expression="if (_value != 0.5) then {[_this, ['general', _value]] remoteExec ['setSkill', _this]}";
					};
					class ENH_ReloadSpeed: ENH_AimingShake
					{
						displayName="$STR_ENH_MAIN_RELOADSPEED_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_RELOADSPEED_TOOLTIP";
						property="ENH_reloadingSpeed";
						expression="if (_value != 0.5) then {[_this, ['reloadSpeed', _value]] remoteExec ['setSkill', _this]}";
					};
					class ENH_SpotDistance: ENH_AimingShake
					{
						displayName="$STR_ENH_MAIN_SPOTDISTANCE_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_SPOTDISTANCE_TOOLTIP";
						property="ENH_spotDistance";
						expression="if (_value != 0.5) then {[_this, ['spotDistance', _value]] remoteExec ['setSkill', _this]}";
					};
					class ENH_SpotTime: ENH_AimingShake
					{
						displayName="$STR_ENH_MAIN_SPOTTIME_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_SPOTTIME_TOOLTIP";
						property="ENH_spotTime";
						expression="if (_value != 0.5) then {[_this, ['spotTime', _value]] remoteExec ['setSkill', _this]}";
					};
					class ENH_AllowFleeing: ENH_AimingShake
					{
						displayName="$STR_ENH_MAIN_ALLOWFLEEING_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_ALLOWFLEEING_TOOLTIP";
						property="ENH_allowFleeing";
						expression="if (_value != 0.5) then {[_this, _value] remoteExec ['allowFleeing', _this]}";
					};
					class ENH_AI_Features_Subcategory: ENH_AI_Skill_Subcategory
					{
						description="$STR_ENH_MAIN_DISABLEAI_SUBCATEGORY";
						property="ENH_AI_Features_Subcategory";
					};
					class ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_ALL_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_ALL_TOOLTIP";
						property="ENH_disableAI_all";
						control="Checkbox";
						expression="if (_value && local _this) then {[_this, 'all'] remoteExec ['disableAI', 0]}";
						defaultValue="false";
						condition="objectBrain";
					};
					class ENH_Move: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_MOVE_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_MOVE_TOOLTIP";
						property="ENH_disableAI_move";
						expression="if (_value && local _this) then {[_this, 'MOVE'] remoteExec ['disableAI', 0]}";
					};
					class ENH_Target: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_TARGET_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_TARGET_TOOLTIP";
						property="ENH_disableAI_target";
						expression="if (_value && local _this) then {[_this, 'TARGET'] remoteExec ['disableAI', 0]}";
					};
					class ENH_Cover: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_COVER_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_COVER_TOOLTIP";
						property="ENH_disableAI_cover";
						expression="if (_value && local _this) then {[_this, 'COVER'] remoteExec ['disableAI', 0]}";
					};
					class ENH_Autotarget: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_AUTOTARGET_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_AUTOTARGET_TOOLTIP";
						property="ENH_disableAI_autotarget";
						expression="if (_value && local _this) then {[_this, 'AUTOTARGET'] remoteExec ['disableAI', 0]}";
					};
					class ENH_Animation: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_ANIM_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_ANIM_TOOLTIP";
						property="ENH_disableAI_anim";
						expression="if (_value && local _this) then {[_this, 'ANIM'] remoteExec ['disableAI', 0]}";
					};
					class ENH_FSM: ENH_All
					{
						displayName="FSM";
						tooltip="$STR_ENH_MAIN_DISABLEAI_FSM_TOOLTIP";
						property="ENH_disableAI_FSM";
						expression="if (_value && local _this) then {[_this, 'FSM'] remoteExec ['disableAI', 0]}";
					};
					class ENH_AimingError: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_AIMINGERROR_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_AIMINGERROR_TOOLTIP";
						property="ENH_disableAI_aimingError";
						expression="if (_value && local _this) then {[_this, 'AIMINGERROR'] remoteExec ['disableAI', 0]}";
					};
					class ENH_TeamSwitch: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_TEAMSWITCH_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_TEAMSWITCH_TOOLTIP";
						property="ENH_disableAI_teamswitch";
						expression="if (_value && local _this) then {[_this, 'TEAMSWITCH'] remoteExec ['disableAI', 0]}";
					};
					class ENH_Suppression: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_SUPPRESSION_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_SUPPRESSION_TOOLTIP";
						property="ENH_disableAI_suppression";
						expression="if (_value && local _this) then {[_this, 'SUPPRESSION'] remoteExec ['disableAI', 0]}";
					};
					class ENH_CheckVisible: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_RAYCASTS_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_RAYCASTS_TOOLTIP";
						property="ENH_disableAI_checkVisible";
						expression="if (_value && local _this) then {[_this, 'CHECKVISIBLE'] remoteExec ['disableAI', 0]}";
					};
					class ENH_Autocombat: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_AUTOCOMBAT_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_AUTOCOMBAT_TOOLTIP";
						property="ENH_disableAI_autocombat";
						expression="if (_value && local _this) then {[_this, 'AUTOCOMBAT'] remoteExec ['disableAI', 0]}";
					};
					class ENH_Path: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_PATH_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_PATH_TOOLTIP";
						property="ENH_disableAI_path";
						expression="if (_value && local _this) then {[_this, 'PATH'] remoteExec ['disableAI', 0]}";
					};
					class ENH_MineDetection: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_MINEDETECTION_DISPLAYNAME";
						tooltip="";
						property="ENH_disableAI_mineDetection";
						expression="if (_value && local _this) then {[_this, 'MINEDETECTION'] remoteExec ['disableAI', 0]}";
					};
					class ENH_WeaponAim: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_WEAPONAIM_DISPLAYNAME";
						tooltip="";
						property="ENH_disableAI_weaponAim";
						expression="if (_value && local _this) then {[_this, 'WEAPONAIM'] remoteExec ['disableAI', 0]}";
					};
					class ENH_NVG: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_NVG_DISPLAYNAME";
						tooltip="";
						property="ENH_disableAI_NVG";
						expression="if (_value && local _this) then {[_this, 'NVG'] remoteExec ['disableAI', 0]}";
					};
					class ENH_Lights: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_LIGHTS_DISPLAYNAME";
						tooltip="";
						property="ENH_disableAI_lights";
						expression="if (_value && local _this) then {[_this, 'LIGHTS'] remoteExec ['disableAI', 0]}";
					};
					class ENH_RadioProtocol: ENH_All
					{
						displayName="$STR_ENH_MAIN_DISABLEAI_RADIOPROTOCOL_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLEAI_RADIOPROTOCOL_TOOLTIP";
						property="ENH_disableAI_radioProtocol";
						expression="if (_value && local _this) then {[_this, 'RADIOPROTOCOL'] remoteExec ['disableAI', 0]}";
					};
				};
			};
			class ENH_UnitTraits
			{
				collapsed=1;
				displayName="$STR_ENH_MAIN_ATTRIBUTECATEGORY_UNITTRAITS";
				class Attributes
				{
					class ENH_UnitTraits_Subcategory
					{
						description="$STR_ENH_MAIN_UNITTRAITS_SUBCATEGORY";
						data="AttributeSystemSubcategory";
						control="ENH_SubCategoryNoHeader1_Fixed";
					};
					class ENH_Medic
					{
						displayName="$STR_ENH_MAIN_UNITTRAITS_MEDIC_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_UNITTRAITS_MEDIC_TOOLTIP";
						property="ENH_unitTraits_medic";
						control="Checkbox";
						expression="if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['Medic', _value]] remoteExec ['setUnitTrait', _this]}";
						condition="objectBrain";
						defaultValue="_this getUnitTrait 'Medic'";
					};
					class ENH_Engineer: ENH_Medic
					{
						displayName="$STR_ENH_MAIN_UNITTRAITS_ENGINEER_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_UNITTRAITS_ENGINEER_TOOLTIP";
						property="ENH_unitTraits_engineer";
						expression="if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['Engineer', _value]] remoteExec ['setUnitTrait', _this]}";
						defaultValue="_this getUnitTrait 'Engineer'";
					};
					class ENH_ExplosiveSpecialist: ENH_Medic
					{
						displayName="$STR_ENH_MAIN_UNITTRAITS_EXPLOSIVESPECIALIST_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_UNITTRAITS_EXPLOSIVESPECIALIST_TOOLTIP";
						property="ENH_unitTrait_explosiveSpecialist";
						expression="if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['ExplosiveSpecialist', _value]] remoteExec ['setUnitTrait', _this]}";
						defaultValue="_this getUnitTrait 'ExplosiveSpecialist'";
					};
					class ENH_UAVHacker: ENH_Medic
					{
						displayName="$STR_ENH_MAIN_UNITTRAITS_UAVHACKER_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_UNITTRAITS_UAVHACKER_TOOLTIP";
						property="ENH_unitTrait_UAVHacker";
						expression="[_this, ['UAVHacker', _value]] remoteExec ['setUnitTrait', _this]";
						defaultValue="_this getUnitTrait 'UAVHacker'";
					};
					class ENH_Camouflage: ENH_Medic
					{
						displayName="$STR_ENH_MAIN_CAMOUFLAGECOEF_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_CAMOUFLAGECOEF_TOOLTIP";
						property="ENH_unitTraits_camouflage";
						control="ENH_SliderMultiZero";
						expression="if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['CamouflageCoef', _value]] remoteExec ['setUnitTrait', _this]}";
						defaultValue=1;
					};
					class ENH_AudibleCoef: ENH_Camouflage
					{
						displayName="$STR_ENH_MAIN_AUDIBLECOEF_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_AUDIBLECOEF_TOOLTIP";
						property="ENH_unitTraits_audibleCoef";
						expression="if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['AudibleCoef', _value]] remoteExec ['setUnitTrait', _this]}";
					};
					class ENH_LoadCoef: ENH_Camouflage
					{
						displayName="$STR_ENH_MAIN_LOADCOEF_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_LOADCOEF_TOOLTIP";
						property="ENH_unitTraits_loadCoef";
						expression="if !(isClass (configFile >> 'CfgPatches' >> 'ace_common')) then {[_this, ['LoadCoef', _value]] remoteExec ['setUnitTrait', _this]}";
					};
				};
			};
			class ENH_HoldAction
			{
				collapsed=1;
				displayName="$STR_ENH_MAIN_HOLDACTION_DISPLAYNAME";
				class Attributes
				{
					class ENH_HoldAction_Subcategory
					{
						description="$STR_ENH_MAIN_HOLDACTION_DESCRIPTION";
						data="AttributeSystemSubcategory";
						control="ENH_SubCategoryNoHeader1_Fixed";
					};
					class ENH_HoldAction
					{
						displayName="$STR_ENH_MAIN_HOLDACTION_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_HOLDACTION_DESCRIPTION";
						property="ENH_HoldAction";
						control="ENH_HoldAction";
						expression="            _value params ['_name', '_iconIdle', '_iconProgress', '_conditionShow', '_conditionProgress', '_codeStart', '_codeProgress', '_codeCompletion', '_codeInterrupt', '_duration', '_priority', '_showUnconscious', '_showWindow', '_removeAfterUse'];            if (!is3DEN && (_name != '')) then            {                if _removeAfterUse then                {                    _codeCompletion = format ['%1 %2', '[_this select 0, _this select 2] remoteExecCall [''removeAction'', 0]; remoteExecCall ['''', _this select 0];', _codeCompletion];                };                [                    _this,                    _name,                    _iconIdle,                    _iconProgress,                    _conditionShow,                    _conditionProgress,                    compile _codeStart,                    compile _codeProgress,                    compile _codeCompletion,                    compile _codeInterrupt,                    nil,                    _duration,                    _priority,                    _removeAfterUse,                    _showUnconscious,                    _showWindow                ] remoteExecCall ['BIS_fnc_holdActionAdd', 0, _this];            };";
						condition="1 - logicModule";
						defaultValue="['', '\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa', '\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa', 'true', 'true', '', '', '', '', 10, 1000, false, true, true]";
					};
				};
			};
			class ENH_EventHandlers
			{
				collapsed=1;
				displayName="$STR_ENH_MAIN_ATTRIBUTES_EVENT_HANDLERS_DISPLAYNAME";
				class Attributes
				{
					class ENH_EventHandlers_Subcategory
					{
						description="$STR_ENH_MAIN_OBJECT_ATTRIBUTES_EVENT_HANDLERS_DESCRIPTION";
						property="ENH_EventHandlers_Subcategory";
						control="ENH_SubCategoryNoHeader3_Fixed";
					};
					class ENH_EventHandlers_AnimChanged
					{
						displayName="AnimChanged";
						property="ENH_EventHandlers_AnimChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""AnimChanged"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_AnimDone
					{
						displayName="AnimDone";
						property="ENH_EventHandlers_AnimDone";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""AnimDone"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_AnimStateChanged
					{
						displayName="AnimStateChanged";
						property="ENH_EventHandlers_AnimStateChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""AnimStateChanged"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Assembled
					{
						displayName="Assembled";
						property="ENH_EventHandlers_Assembled";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Assembled"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Attached
					{
						displayName="Attached";
						property="ENH_EventHandlers_Attached";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Attached"", compile _value]})";
						condition="objectControllable + objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_CargoLoaded
					{
						displayName="CargoLoaded";
						property="ENH_EventHandlers_CargoLoaded";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""CargoLoaded"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_CargoUnloaded
					{
						displayName="CargoUnloaded";
						property="ENH_EventHandlers_CargoUnloaded";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""CargoUnloaded"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_ContainerClosed
					{
						displayName="ContainerClosed";
						property="ENH_EventHandlers_ContainerClosed";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""ContainerClosed"", compile _value]})";
						condition="objectHasInventoryCargo";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_ContainerOpened
					{
						displayName="ContainerOpened";
						property="ENH_EventHandlers_ContainerOpened";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""ContainerOpened"", compile _value]})";
						condition="objectHasInventoryCargo";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_ControlsShifted
					{
						displayName="ControlsShifted";
						property="ENH_EventHandlers_ControlsShifted";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""ControlsShifted"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Dammaged
					{
						displayName="Dammaged";
						property="ENH_EventHandlers_Dammaged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Dammaged"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Deleted
					{
						displayName="Deleted";
						property="ENH_EventHandlers_Deleted";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Deleted"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Detached
					{
						displayName="Detached";
						property="ENH_EventHandlers_Detached";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Detached"", compile _value]})";
						condition="objectControllable + objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Disassembled
					{
						displayName="Disassembled";
						property="ENH_EventHandlers_Disassembled";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Disassembled"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Engine
					{
						displayName="Engine";
						property="ENH_EventHandlers_Engine";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Engine"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_EpeContact
					{
						displayName="EpeContact";
						property="ENH_EventHandlers_EpeContact";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""EpeContact"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_EpeContactEnd
					{
						displayName="EpeContactEnd";
						property="ENH_EventHandlers_EpeContactEnd";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""EpeContactEnd"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_EpeContactStart
					{
						displayName="EpeContactStart";
						property="ENH_EventHandlers_EpeContactStart";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""EpeContactStart"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Explosion
					{
						displayName="Explosion";
						property="ENH_EventHandlers_Explosion";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Explosion"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Fired
					{
						displayName="Fired";
						property="ENH_EventHandlers_Fired";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Fired"", compile _value]})";
						condition="objectControllable + objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_FiredMan
					{
						displayName="FiredMan";
						property="ENH_EventHandlers_FiredMan";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""FiredMan"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_FiredNear
					{
						displayName="FiredNear";
						property="ENH_EventHandlers_FiredNear";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""FiredNear"", compile _value]})";
						condition="objectControllable + objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Fuel
					{
						displayName="Fuel";
						property="ENH_EventHandlers_Fuel";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Fuel"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Gear
					{
						displayName="Gear";
						property="ENH_EventHandlers_Gear";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Gear"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_GestureChanged
					{
						displayName="GestureChanged";
						property="ENH_EventHandlers_GestureChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""GestureChanged"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_GestureDone
					{
						displayName="GestureDone";
						property="ENH_EventHandlers_GestureDone";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""GestureDone"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_GetIn
					{
						displayName="GetIn";
						property="ENH_EventHandlers_GetIn";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""GetIn"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_GetInMan
					{
						displayName="GetInMan";
						property="ENH_EventHandlers_GetInMan";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""GetInMan"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_GetOut
					{
						displayName="GetOut";
						property="ENH_EventHandlers_GetOut";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""GetOut"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_GetOutMan
					{
						displayName="GetOutMan";
						property="ENH_EventHandlers_GetOutMan";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""GetOutMan"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_HandleDamage
					{
						displayName="HandleDamage";
						property="ENH_EventHandlers_HandleDamage";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""HandleDamage"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_HandleHeal
					{
						displayName="HandleHeal";
						property="ENH_EventHandlers_HandleHeal";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""HandleHeal"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_HandleIdentity
					{
						displayName="HandleIdentity";
						property="ENH_EventHandlers_HandleIdentity";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""HandleIdentity"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_HandleRating
					{
						displayName="HandleRating";
						property="ENH_EventHandlers_HandleRating";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""HandleRating"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_HandleScore
					{
						displayName="HandleScore";
						property="ENH_EventHandlers_HandleScore";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""HandleScore"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Hit
					{
						displayName="Hit";
						property="ENH_EventHandlers_Hit";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Hit"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_HitPart
					{
						displayName="HitPart";
						property="ENH_EventHandlers_HitPart";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""HitPart"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_IncomingMissile
					{
						displayName="IncomingMissile";
						property="ENH_EventHandlers_IncomingMissile";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""IncomingMissile"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_InventoryClosed
					{
						displayName="InventoryClosed";
						property="ENH_EventHandlers_InventoryClosed";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""InventoryClosed"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_InventoryOpened
					{
						displayName="InventoryOpened";
						property="ENH_EventHandlers_InventoryOpened";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""InventoryOpened"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Killed
					{
						displayName="Killed";
						property="ENH_EventHandlers_Killed";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Killed"", compile _value]})";
						condition="objectControllable + objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_LandedStopped
					{
						displayName="LandedStopped";
						property="ENH_EventHandlers_LandedStopped";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""LandedStopped"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_LandedTouchDown
					{
						displayName="LandedTouchDown";
						property="ENH_EventHandlers_LandedTouchDown";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""LandedTouchDown"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Landing
					{
						displayName="Landing";
						property="ENH_EventHandlers_Landing";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Landing"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_LandingCanceled
					{
						displayName="LandingCanceled";
						property="ENH_EventHandlers_LandingCanceled";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""LandingCanceled"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_LeaningChanged
					{
						displayName="LeaningChanged";
						property="ENH_EventHandlers_LeaningChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""LeaningChanged"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Local
					{
						displayName="Local";
						property="ENH_EventHandlers_Local";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Local"", compile _value]})";
						condition="1";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_MagazineUnloaded
					{
						displayName="MagazineUnloaded";
						property="ENH_EventHandlers_MagazineUnloaded";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""MagazineUnloaded"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_OpticsModeChanged
					{
						displayName="OpticsModeChanged";
						property="ENH_EventHandlers_OpticsModeChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""OpticsModeChanged"", compile _value]})";
						condition="objectControllable + objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_OpticsSwitch
					{
						displayName="OpticsSwitch";
						property="ENH_EventHandlers_OpticsSwitch";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""OpticsSwitch"", compile _value]})";
						condition="objectControllable + objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_PeriscopeElevationChanged
					{
						displayName="PeriscopeElevationChanged";
						property="ENH_EventHandlers_PeriscopeElevationChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""PeriscopeElevationChanged"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Put
					{
						displayName="Put";
						property="ENH_EventHandlers_Put";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Put"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Reloaded
					{
						displayName="Reloaded";
						property="ENH_EventHandlers_Reloaded";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Reloaded"", compile _value]})";
						condition="objectControllable + objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Respawn
					{
						displayName="Respawn";
						property="ENH_EventHandlers_Respawn";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Respawn"", compile _value]})";
						condition="objectControllable + objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_RopeAttach
					{
						displayName="RopeAttach";
						property="ENH_EventHandlers_RopeAttach";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""RopeAttach"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_RopeBreak
					{
						displayName="RopeBreak";
						property="ENH_EventHandlers_RopeBreak";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""RopeBreak"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_SeatSwitched
					{
						displayName="SeatSwitched";
						property="ENH_EventHandlers_SeatSwitched";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""SeatSwitched"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_SeatSwitchedMan
					{
						displayName="SeatSwitchedMan";
						property="ENH_EventHandlers_SeatSwitchedMan";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""SeatSwitchedMan"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_SlotItemChanged
					{
						displayName="SlotItemChanged";
						property="ENH_EventHandlers_SlotItemChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""SlotItemChanged"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_SoundPlayed
					{
						displayName="SoundPlayed";
						property="ENH_EventHandlers_SoundPlayed";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""SoundPlayed"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Suppressed
					{
						displayName="Suppressed";
						property="ENH_EventHandlers_Suppressed";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Suppressed"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_Take
					{
						displayName="Take";
						property="ENH_EventHandlers_Take";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""Take"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_TaskSetAsCurrent
					{
						displayName="TaskSetAsCurrent";
						property="ENH_EventHandlers_TaskSetAsCurrent";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""TaskSetAsCurrent"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_TurnIn
					{
						displayName="TurnIn";
						property="ENH_EventHandlers_TurnIn";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""TurnIn"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_TurnOut
					{
						displayName="TurnOut";
						property="ENH_EventHandlers_TurnOut";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""TurnOut"", compile _value]})";
						condition="objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_VisionModeChanged
					{
						displayName="VisionModeChanged";
						property="ENH_EventHandlers_VisionModeChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""VisionModeChanged"", compile _value]})";
						condition="objectControllable + objectVehicle";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_WeaponAssembled
					{
						displayName="WeaponAssembled";
						property="ENH_EventHandlers_WeaponAssembled";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""WeaponAssembled"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_WeaponChanged
					{
						displayName="WeaponChanged";
						property="ENH_EventHandlers_WeaponChanged";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""WeaponChanged"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_WeaponDeployed
					{
						displayName="WeaponDeployed";
						property="ENH_EventHandlers_WeaponDeployed";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""WeaponDeployed"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_WeaponDisassembled
					{
						displayName="WeaponDisassembled";
						property="ENH_EventHandlers_WeaponDisassembled";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""WeaponDisassembled"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
					class ENH_EventHandlers_WeaponRested
					{
						displayName="WeaponRested";
						property="ENH_EventHandlers_WeaponRested";
						control="EditCodeMulti5";
						expression="(if (_value != '' && {!is3DEN && local _this}) then {_this addEventHandler [""WeaponRested"", compile _value]})";
						condition="objectControllable";
						defaultValue="''";
						validate="expression";
					};
				};
			};
			class StateSpecial
			{
				class Attributes
				{
					class ENH_SetCaptive
					{
						displayName="$STR_ENH_MAIN_CAPTIVE_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_CAPTIVE_TOOLTIP";
						property="ENH_setCaptive";
						control="Checkbox";
						expression="[_this, _value] remoteExec ['setCaptive', _this]";
						condition="objectBrain";
						defaultValue="false";
					};
					class ENH_AllowSprint
					{
						displayName="$STR_ENH_MAIN_ALLOWSPRINTING_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_ALLOWSPRINTING_TOOLTIP";
						control="Checkbox";
						property="ENH_allowSprint";
						expression="[_this, _value] remoteExec ['allowSprint', _this]";
						defaultValue="true";
						condition="objectBrain";
					};
					class ENH_ForceWalk
					{
						displayName="$STR_ENH_MAIN_FORCEWALK_DISPLAYNAME";
						tooltip="";
						property="ENH_forceWalk";
						control="Checkbox";
						expression="[_this, _value] remoteExec ['forceWalk', _this]";
						condition="objectBrain";
						defaultValue="false";
					};
					class ENH_MakeHostage
					{
						displayName="$STR_ENH_MAIN_MAKEHOSTAGE_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_MAKEHOSTAGE_TOOLTIP";
						control="Checkbox";
						property="ENH_makeHostage";
						expression="    if (isServer && _value) then    {        ENH_fnc_makeHostage =        {            if (_this getVariable ['ENH_isHostage', true]) then            {                _this switchMove 'Acts_AidlPsitMstpSsurWnonDnon04';                [                _this,                localize 'STR_A3_OM_SYSTEM_QUEST_HOSTAGEHOLDACTION',                'A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_unbind_ca.paa',                'A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_unbind_ca.paa',                '_target getVariable [''ENH_IsHostage'', true] && {_this distance _target < 2 && {alive _target && {_target != _this}}}',                'alive _target',                {},                {},                {                    params ['_target', '_caller', '_actionId'];                    [_target, 'AmovPercMstpSnonWnonDnon'] remoteExec ['playMoveNow', 0];                    [_target, _actionId] remoteExec ['BIS_fnc_holdActionRemove', 0];                    _target setVariable ['ENH_IsHostage', false, true];                    _target setVariable ['ENH_WasFreedBy', _caller, true];                }                ] call BIS_fnc_holdActionAdd;            };        };        [_this, ENH_fnc_makeHostage] remoteExec ['call', 0, true];    };    ";
						condition="ObjectBrain";
						defaultValue="false";
					};
					class ENH_Parachute
					{
						displayName="$STR_ENH_MAIN_PARACHUTE_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_PARACHUTE_TOOLTIP";
						property="ENH_parachute";
						control="Checkbox";
						expression="    if (!is3DEN && _value) then    {        if (local _this) then        {            private _parachute = createVehicle ['Steerable_Parachute_F', getPosATL _this, [], 0, 'FLY'];            _this moveInDriver _parachute;        };    }";
						condition="objectBrain";
						defaultValue="false";
					};
					class ENH_EnableHeadlights
					{
						displayName="$STR_ENH_MAIN_ENABLEHEADLIGHTS_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_ENABLEHEADLIGHTS_TOOLTIP";
						control="Checkbox";
						property="ENH_enableHeadlights";
						expression="[_this, _value] remoteExec ['setPilotLight', _this]";
						condition="objectVehicle";
						defaultValue="false";
					};
					class ENH_AllowCrewInImmobile
					{
						displayName="$STR_ENH_MAIN_ALLOWCREWIMMOBILE_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_ALLOWCREWIMMOBILE_TOOLTIP";
						property="ENH_allowCrewInImmobile";
						control="Checkbox";
						expression="    [_this, _value] remoteExec ['allowCrewInImmobile', _this];    {        [_x, 'FSM'] remoteExec ['disableAI', _x];        [_x, 'CARELESS'] remoteExec ['setBehaviour', _x];    } forEach crew _this;    ";
						condition="objectVehicle";
						defaultValue="false";
					};
					class ENH_EngineOn
					{
						displayName="$STR_ENH_MAIN_ENGINEON_DISPLAYNAME";
						tooltip="";
						control="Checkbox";
						property="ENH_engineOn";
						expression="[_this, _value] remoteExec ['engineOn', _this]";
						condition="objectVehicle";
						defaultValue="false";
					};
					class ENH_DisableNVGE
					{
						displayName="$STR_ENH_MAIN_DISABLENVGEQUIPMENT_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLENVGEQUIPMENT_TOOLTIP";
						control="Checkbox";
						property="ENH_disableNVGEquipment";
						expression="if (isServer) then {_this disableNVGEquipment _value}";
						condition="objectVehicle";
						defaultValue="false";
					};
					class ENH_DisableTIE
					{
						displayName="$STR_ENH_MAIN_DISABLETIEQUIPMENT_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DISABLETIEQUIPMENT_TOOLTIP";
						control="Checkbox";
						property="ENH_disableTIEquipment";
						expression="if (isServer) then {_this disableTIEquipment _value}";
						condition="objectVehicle";
						defaultValue="false";
					};
					class ENH_DoStop
					{
						displayName="$STR_ENH_MAIN_DOSTOP_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_DOSTOP_TOOLTIP";
						control="Checkbox";
						property="ENH_doStop";
						expression="if (!is3DEN && _value) then {doStop _this}";
						condition="objectBrain + objectVehicle";
						defaultValue="false";
					};
					class ENH_RemoveFromRemainsCollector
					{
						displayName="$STR_ENH_MAIN_REMOVEFROMREMAINSCOLLECTOR_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_REMOVEFROMREMAINSCOLLECTOR_TOOLTIP";
						control="Checkbox";
						property="ENH_removeFromRemainsCollector";
						expression="if (!is3DEN && _value) then {removeFromRemainsCollector [_this]}";
						defaultValue="false";
						condition="objectSimulated";
					};
					class ENH_SPR_Tickets
					{
						displayName="$STR_ENH_MAIN_SPR_RESPAWNTICKETS_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_RESPAWNTICKETS_TOOLTIP";
						property="ENH_SPR_Tickets";
						control="EditShort";
						expression="if (!is3DEN && !isMultiplayer) then {_this setVariable ['ENH_SPR_Tickets', _value]}";
						condition="objectBrain";
						typeName="NUMBER";
						defaultValue=0;
					};
				};
			};
			class Transformation
			{
				class Attributes
				{
					class ENH_ObjectScaling
					{
						displayName="$STR_ENH_MAIN_OBJECTSCALING_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_OBJECTSCALING_TOOLTIP";
						property="ENH_objectScaling";
						control="EditCodeShort";
						expression="    if (is3DEN) then    {        _this addEventHandler ['AttributesChanged3DEN',        {            params ['_object'];            _object setObjectScale ((_object get3DENAttribute 'ENH_objectScaling') # 0);        }];        _this addEventHandler ['Dragged3DEN',        {            params ['_object'];            _object setObjectScale ((_object get3DENAttribute 'ENH_objectScaling') # 0);        }];    };    if (!isMultiplayer && _value != 1) then {[_this, _value] spawn {sleep 0.5; (_this select 0) setObjectScale (_this select 1)}};";
						condition="1 - objectSimulated";
						defaultValue=1;
						typeName="NUMBER";
						validate="NUMBER";
					};
				};
			};
			class Inventory
			{
				class Attributes
				{
					class ENH_AddGunLight
					{
						displayName="$STR_ENH_MAIN_ADDGUNLIGHT_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_ADDGUNLIGHT_TOOLTIP";
						property="ENH_addGunLight";
						control="Checkbox";
						expression="        if (!is3DEN && _value) then        {            if (primaryWeaponItems _this select 1 isEqualTo '') then            {                [_this, 'acc_flashlight'] remoteExec ['addPrimaryWeaponItem', _this];            };            [_this, 'forceOn'] remoteExec ['enableGunLights', _this];        }";
						condition="objectBrain";
						defaultValue="false";
					};
					class ENH_VirtualArsenal
					{
						displayName="$STR_ENH_MAIN_ARSENAL_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_ARSENAL_TOOLTIP";
						property="ENH_virtualArsenal";
						control="Checkbox";
						expression="if (!is3DEN && _value) then {['AmmoboxInit', [_this, true]] spawn BIS_fnc_arsenal}";
						condition="1";
						defaultValue="false";
					};
				};
			};
			class State
			{
				class Attributes
				{
					class ENH_FeatureType
					{
						control="Combo";
						property="ENH_featureTypeNew";
						displayName="$STR_ENH_MAIN_FEATURETYPE_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_FEATURETYPE_TOOLTIP";
						expression="[_this, _value] remoteExec ['setFeatureType', 0, _this]";
						defaultValue=0;
						typeName="NUMBER";
						class Values
						{
							class Unchanged
							{
								name="$STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TEXT";
								tooltip="$STR_3DEN_ATTRIBUTES_DEFAULT_UNCHANGED_TOOLTIP";
								value=0;
							};
							class ObjectViewDistance
							{
								name="$STR_ENH_MAIN_FEATURETYPE_OBJECTVIEWDISTANCE_TEXT";
								tooltip="$STR_ENH_MAIN_FEATURETYPE_OBJECTVIEWDISTANCE_TOOLTIP";
								value=1;
							};
							class TerrainViewDistance
							{
								name="$STR_ENH_MAIN_FEATURETYPE_TERRAINVIEWDISTANCE_TEXT";
								tooltip="$STR_ENH_MAIN_FEATURETYPE_TERRAINVIEWDISTANCE_TOOLTIP";
								value=2;
							};
						};
					};
					class ENH_ForceFlag
					{
						displayName="$STR_ENH_MAIN_FORCEFLAG_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_FORCEFLAG_TOOLTIP";
						property="ENH_forceFlag";
						control="Edit";
						expression="if (_value != '') then {_this forceFlagTexture _value}";
						condition="objectBrain + objectVehicle";
						defaultValue="''";
					};
					class ENH_SetMass
					{
						displayName="$STR_ENH_MAIN_SETMASS_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_SETMASS_TOOLTIP";
						property="ENH_setMass";
						control="Slider";
						expression="if (!is3DEN) then {[_this, (getMass _this * _value)] remoteExec ['setMass', _this]}";
						condition="objectVehicle";
						defaultValue="1";
					};
					class ENH_WaterLeakiness
					{
						displayName="$STR_ENH_MAIN_WATERLEAKINESS_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_WATERLEAKINESS_TOOLTIP";
						property="ENH_WaterLeakiness";
						control="EditShort";
						expression="if (!is3DEN && {_value != getWaterLeakiness _this}) then {[_this, _value] remoteExec ['setWaterLeakiness', _this]}";
						condition="objectVehicle";
						typeName="NUMBER";
						defaultValue="getWaterLeakiness _this";
					};
					class ENH_LimitSpeed
					{
						displayName="$STR_ENH_MAIN_LIMITSPEED_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_LIMITSPEED_TOOLTIP";
						property="ENH_limitSpeed";
						control="EditShort";
						expression="[_this, _value] remoteExec ['limitSpeed', _this]";
						condition="objectVehicle";
						typeName="NUMBER";
						defaultValue=-1;
					};
					class ENH_FuelConsumptionCoef
					{
						displayName="$STR_ENH_MAIN_FUELCONSUMPTIONCOEF_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_FUELCONSUMPTIONCOEF_TOOLTIP";
						property="ENH_FuelConsumptionCoef";
						control="EditShort";
						expression="[_this, _value] remoteExec ['setFuelConsumptionCoef', _this]";
						condition="objectVehicle";
						typeName="NUMBER";
						defaultValue=1;
					};
				};
			};
		};
	};
	class Marker
	{
		class AttributeCategories
		{
			class Transformation
			{
				class Attributes
				{
					class Position
					{
						tooltip="$STR_3DEN_OBJECT_ATTRIBUTE_POSITION_TOOLTIP";
						control="EditXYZ";
					};
					class ENH_MarkerDrawPriority
					{
						displayName="$STR_ENH_MAIN_MARKERDRAWPRIORITY_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_MARKERDRAWPRIORITY_TOOLTIP";
						property="ENH_markerDrawPriority";
						control="EditShort";
						expression="if (_value != 0 && isServer) then {[_this, _value] remoteExec ['setMarkerDrawPriority', 0, true]}";
						defaultValue=0;
						typeName="NUMBER";
						validate="NUMBER";
					};
				};
			};
			class Style
			{
				class Attributes
				{
					class ENH_MarkerColor
					{
						displayName="$STR_ENH_MAIN_CUSTOM_MARKER_COLOR_DISPLAYNAME";
						tooltip="";
						property="ENH_markerColor";
						control="ENH_MarkerColor";
						expression="if (_value#0 && isServer) then {_this setMarkerColor _value#1}";
						defaultValue="[false, '#(1,1,1)']";
						typeName="ARRAY";
						validate="ARRAY";
					};
					class ENH_MarkerShape
					{
						displayName="$STR_ENH_MAIN_MARKER_SHAPE_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_MARKER_SHAPE_TOOLTIP";
						property="ENH_markerShape";
						control="ENH_MarkerShape";
						expression="if (_value != 'NONE' && isServer) then {_this setMarkerShape _value}";
						defaultValue="NONE";
						typeName="STRING";
						validate="STRING";
					};
				};
			};
			class ENH_MarkerHideOnStart
			{
				displayName="$STR_ENH_MAIN_MARKERHIDEONSTART_DISPLAYNAME";
				class Attributes
				{
					class ENH_MarkerHideOnStart
					{
						displayName="$STR_ENH_MAIN_MARKERHIDEONSTART_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_MARKERHIDEONSTART_TOOLTIP";
						property="ENH_markerHideOnStart";
						control="Checkbox";
						expression="                if (!isServer || is3DEN || !_value) exitWith {};                missionNamespace setVariable [format ['ENH_attributesMarker_%1_initAlpha', _this], markerAlpha _this];                _this setMarkerAlpha 0";
						defaultValue="false";
					};
					class ENH_MarkerShowOnCondition
					{
						displayName="$STR_ENH_MAIN_MARKERSHOWONCONDITION_DISPLAYNAME";
						tooltip="$STR_ENH_MAIN_MARKERSHOWONCONDITION_TOOLTIP";
						property="ENH_markerShowOnCondition";
						control="EditCodeMulti3";
						expression="                if (!isServer || is3DEN || _value == 'false' || _value == '') exitWith {};                [_this, compile _value] spawn                {                    params ['_marker', '_compiledValue'];                    scriptName 'ENH_MarkerShowOnCondition';                    waitUntil {sleep 0.5; call _compiledValue};                    private _newAlpha = missionNamespace getVariable [format ['ENH_attributesMarker_%1_initAlpha', _marker], 1];                    _marker setMarkerAlpha _newAlpha;                }";
						validate="expression";
						defaultValue="''";
					};
				};
			};
		};
	};
	class ENH_3DENCommandPalette_Commands
	{
		class ENH_Command_Base
		{
			action="";
			description="";
			opensNewWindow=0;
			picture="";
			text="";
			copyToClipboard=0;
		};
	};
};
class CfgFunctions
{
	class 3denEnhanced
	{
		tag="ENH";
		class 3DENCommandPalette
		{
			file="\x\enh\addons\main\functions\GUI\3DENCommandPalette";
			class 3DENCommandPalette_addCommand
			{
			};
			class 3DENCommandPalette_collectCommands
			{
			};
			class 3DENCommandPalette_execCommand
			{
			};
			class 3DENCommandPalette_init
			{
			};
			class 3DENCommandPalette_readJSONFile
			{
			};
			class 3DENCommandPalette_search
			{
			};
		};
		class 3DENEventHandlers
		{
			file="\x\enh\addons\main\functions\3DENEventHandlers";
			class EH_init
			{
			};
			class EH_onMissionLoad
			{
			};
			class EH_onMissionNew
			{
			};
			class EH_onMissionPreview
			{
			};
			class EH_onMissionPreviewEnd
			{
			};
			class EH_onTerrainNew
			{
			};
		};
		class 3DENInterface
		{
			file="\x\enh\addons\main\functions\3DENInterface";
			class 3DENMinimap
			{
			};
			class 3DENShowCustomMarkerColorAndShape
			{
			};
			class adjustTitleTextWidth
			{
			};
			class assetBrowser_collapse
			{
			};
			class assetBrowser_modFilter
			{
			};
			class entityList_addTooltips
			{
			};
			class favoritesList
			{
			};
			class locationList_enhanced
			{
			};
		};
		class 3DENRadio
		{
			file="\x\enh\addons\main\functions\GUI\3DENRadio";
			class 3DENRadio_exportClassname
			{
			};
			class 3DENRadio_handlePlaylist
			{
			};
			class 3DENRadio_onLoad
			{
			};
			class 3DENRadio_playNewSong
			{
			};
			class 3DENRadio_searchList
			{
			};
			class 3DENRadio_timelineControl
			{
			};
			class 3DENRadio_toggleRadio
			{
			};
		};
		class Attributes
		{
			file="\x\enh\addons\main\functions\attributes";
			class markerColor_onAttributeLoad
			{
			};
			class markerColor_onAttributeSave
			{
			};
			class markerShape_onAttributeLoad
			{
			};
			class markerShape_onAttributeSave
			{
			};
			class advancedDamage_onAttributeLoad
			{
			};
			class advancedDamage_onAttributeSave
			{
			};
			class airdrop_onAttributeLoad
			{
			};
			class airdrop_onAttributeSave
			{
			};
			class ambientAnimations_initInEditor
			{
			};
			class ambientAnimations_onAttributeLoad
			{
			};
			class ambientAnimations_onAttributeSave
			{
			};
			class ambientFlyby_onAttributeLoad
			{
			};
			class ambientFlyby_onAttributeSave
			{
			};
			class cfgMusic_onAttributeLoad
			{
			};
			class cfgMusic_onAttributeSave
			{
			};
			class debugOptions_init
			{
			};
			class dynamicSkill_onAttributeLoad
			{
			};
			class dynamicSkill_onAttributeSave
			{
			};
			class dynamicSkill_toggleControlsState
			{
			};
			class establishingShot_onAttributeLoad
			{
			};
			class establishingShot_onAttributeSave
			{
			};
			class groupMarker_onAttributeLoad
			{
			};
			class groupMarker_onAttributeSave
			{
			};
			class groupMarker_onLoad
			{
			};
			class holdAction_onAttributeLoad
			{
			};
			class holdAction_onAttributeSave
			{
			};
			class inputList_add
			{
			};
			class inputList_onAttributeLoad
			{
			};
			class inputList_onAttributeSave
			{
			};
			class inputList_remove
			{
			};
			class introText_onAttributeLoad
			{
			};
			class introText_onAttributeSave
			{
			};
			class mapIndicators_onAttributeLoad
			{
			};
			class mapIndicators_onAttributeSave
			{
			};
			class missionEndingCasualties_initDebriefingCombo
			{
			};
			class missionEndingCasualties_onAttributeLoad
			{
			};
			class missionEndingCasualties_onAttributeSave
			{
			};
			class slider_onAttributeLoad
			{
			};
			class slider_onAttributeSave
			{
			};
			class SPR_onAttributeLoad
			{
			};
			class SPR_onAttributeSave
			{
			};
		};
		class AttributeSearch
		{
			file="\x\enh\addons\main\functions\GUI\attributeSearch";
			class attributeSearch_onLoad
			{
			};
		};
		class BriefingEditor
		{
			file="\x\enh\addons\main\functions\GUI\briefingEditor";
			class briefingEditor
			{
			};
		};
		class CfgSentencesBrowser
		{
			file="\x\enh\addons\main\functions\GUI\CFGS";
			class CFGS_changeFilter
			{
			};
			class CFGS_changePage
			{
			};
			class CFGS_getCfgSentences
			{
			};
			class CFGS_getSentenceDataFromConfig
			{
			};
			class CFGS_handleFavorites
			{
			};
			class CFGS_onLoad
			{
			};
			class CFGS_playOrCopy
			{
			};
		};
		class Common
		{
			file="\x\enh\addons\main\functions\common";
			class all3DENSelected
			{
			};
			class array3FromClipboard
			{
			};
			class createHashValue
			{
			};
			class floatToTime
			{
			};
			class formatInteger
			{
			};
			class getAllItems
			{
			};
			class getConfigSourceAddon
			{
			};
			class hasStorage
			{
			};
			class initSearchControls
			{
			};
			class parseShortcut
			{
			};
			class systemTimeFormatted
			{
			};
		};
		class Debug
		{
			file="\x\enh\addons\main\functions\debug";
			class productInfo
			{
			};
		};
		class ESE
		{
			file="\x\enh\addons\main\functions\GUI\ESE";
			class ESE_addItem
			{
			};
			class ESE_applyAttribute
			{
			};
			class ESE_changeFilter
			{
			};
			class ESE_clearInventory
			{
			};
			class ESE_close
			{
			};
			class ESE_export
			{
			};
			class ESE_fullArsenal
			{
			};
			class ESE_getConfigValues
			{
			};
			class ESE_handleTemplates
			{
			};
			class ESE_importToFilter
			{
			};
			class ESE_lbAdd
			{
			};
			class ESE_lnbAdd
			{
			};
			class ESE_loadAttributeValue
			{
			};
			class ESE_onModFilterChanged
			{
			};
			class ESE_open
			{
			};
			class ESE_parseClipboardValues
			{
			};
			class ESE_removeItem
			{
			};
			class ESE_resetSearch
			{
			};
			class ESE_resetStorage
			{
			};
			class ESE_search
			{
			};
			class ESE_sort
			{
			};
			class ESE_toggleVirtual
			{
			};
		};
		class FunctionsViewer
		{
			file="\x\enh\addons\main\functions\GUI\functionsViewer";
			class functionsViewer_copy
			{
			};
			class functionsViewer_fillCtrlTV
			{
			};
			class functionsViewer_getFunctionsData
			{
			};
			class functionsViewer_incrementKey
			{
			};
			class functionsViewer_onLoad
			{
			};
			class functionsViewer_onTreeSelChanged
			{
			};
			class functionsViewer_recompileSelected
			{
			};
			class functionsViewer_searchkey
			{
			};
			class functionsViewer_setUpMenuStrip
			{
			};
			class functionsViewer_togglePanel
			{
			};
		};
		class Garrison
		{
			file="\x\enh\addons\main\functions\GUI\garrison";
			class garrison_onLoad
			{
			};
			class garrison_draw
			{
			};
			class garrison_fillBuildings
			{
			};
			class garrison_onUnload
			{
			};
			class garrison_updateValues
			{
			};
		};
		class Garrison2
		{
			file="\x\enh\addons\main\functions\garrison2";
			class garrison2_draw3D
			{
			};
			class garrison2_exit
			{
			};
			class garrison2_fillBuildingPositions
			{
			};
			class garrison2_main
			{
			};
			class garrison2_onEntityDragged
			{
			};
			class garrison2_onMouseButtonUp
			{
			};
			class garrison2_positionInBoundingBox
			{
			};
			class garrison2_isBuildingPositionEmpty
			{
			};
		};
		class Log
		{
			file="\x\enh\addons\main\functions\log";
			class 3DENLog
			{
			};
			class exportGUIDefines
			{
			};
			class exportLoadout
			{
			};
			class exportWithLB
			{
			};
		};
		class Misc
		{
			file="\x\enh\addons\main\functions\misc";
			class alignEntities
			{
			};
			class centerMapOnSelection
			{
			};
			class createBackupMissionSQM
			{
			};
			class deleteCrew
			{
			};
			class deleteEmptyLayers
			{
			};
			class iconPicker
			{
			};
			class loadoutTool
			{
			};
			class measureDistance
			{
			};
			class pylonTools
			{
			};
			class removeGear
			{
			};
			class setOrientation
			{
			};
			class spaceEqually
			{
			};
			class switchTime
			{
			};
			class toggleAttributes
			{
			};
			class toggleGrass
			{
			};
			class VHCTools
			{
			};
		};
		class ModuleInformation
		{
			file="\x\enh\addons\main\functions\GUI\moduleInformation";
			class moduleInformation_onLoad
			{
			};
		};
		class MoveToLayer
		{
			file="\x\enh\addons\main\functions\GUI\moveTolayer";
			class moveToLayer_onLoad
			{
			};
			class moveToLayer_move
			{
			};
		};
		class NameObjects
		{
			file="\x\enh\addons\main\functions\GUI\nameObjects";
			class nameObjects
			{
			};
		};
		class PlacementTools
		{
			file="\x\enh\addons\main\functions\GUI\placementTools";
			class placementTools
			{
			};
		};
		class RPTViewer
		{
			file="\x\enh\addons\main\functions\GUI\RPTViewer";
			class RPTViewer
			{
			};
		};
		class SAM
		{
			file="\x\enh\addons\main\functions\GUI\SAM";
			class SAM
			{
			};
		};
		class SelectionFilter
		{
			file="\x\enh\addons\main\functions\GUI\selectionFilter";
			class selectionFilter_init
			{
			};
		};
		class TextureFinder
		{
			file="\x\enh\addons\main\functions\GUI\TextureFinder";
			class textureFinder_fillList
			{
			};
			class textureFinder_findTextures
			{
			};
			class textureFinder_updatePreview
			{
			};
		};
		class VariableViewer
		{
			file="\x\enh\addons\main\functions\GUI\variableViewer";
			class variableViewer_delete
			{
			};
			class variableViewer_fillLNB
			{
			};
			class variableViewer_getNamespace
			{
			};
			class variableViewer_messageConfirm
			{
			};
			class variableViewer_onFilterChanged
			{
			};
			class variableViewer_onLNBSelChanged
			{
			};
			class variableViewer_onLoad
			{
			};
			class variableViewer_setOrCreate
			{
			};
		};
		class ZeusAddons
		{
			file="\x\enh\addons\main\functions\GUI\ZeusAddons";
			class zeusAddons
			{
			};
		};
	};
};
class Display3DEN
{
	class ContextMenu: ctrlMenu
	{
		class Items
		{
			items[]+=
			{
				"Separator",
				"ENH_OtherTools",
				"ENH_AddToFavorites"
			};
			class Log
			{
				items[]+=
				{
					"ENH_LogClassesString",
					"SeparatorSelected",
					"ENH_LogVarNames",
					"ENH_LogFactions",
					"SeparatorSelected",
					"ENH_LogPositions3D",
					"ENH_LogPositions2D",
					"ENH_LogGridPositon",
					"SeparatorSelected",
					"ENH_Log3DENID",
					"ENH_LogObjectInfo"
				};
			};
			class Edit
			{
				items[]+=
				{
					"ENH_DeleteCrew"
				};
			};
			class ConnectParent
			{
				items[]+=
				{
					"ENH_TriggerOwnerPlayer"
				};
			};
			class Select
			{
				items[]+=
				{
					"ENH_SelectionFilter"
				};
			};
			class ENH_OtherTools
			{
				text="$STR_ENH_MAIN_CONTEXTMENU_OTHERTOOLS";
				items[]+=
				{
					"ENH_MeasureDistance",
					"ENH_ShowModuleInformation",
					"ENH_Garrison",
					"ENH_MoveToLayer"
				};
				value=0;
			};
			class ENH_LogFactions
			{
				text="$STR_ENH_MAIN_CONTEXTMENU_LOGFACTION";
				action="'FACTIONS' call ENH_fnc_3DENLog";
				conditionShow="hoverObject";
				wikiDescription="Logs all unique factions of all selected entities.";
			};
			class ENH_LogClassesString
			{
				action="'CLASSES' call ENH_fnc_3DENLog";
				text="$STR_ENH_MAIN_CONTEXTMENU_LOGCLASSESSTRING";
				conditionShow="selectedObject + selectedWaypoint + selectedLogic + selectedMarker";
				wikiDescription="Logs all unique classes of all selected entities.";
			};
			class ENH_LogPositions3D
			{
				action="'3D' call ENH_fnc_3DENLog";
				text="$STR_ENH_MAIN_CONTEXTMENU_LOGPOSITIONS3D";
				conditionShow="selected - selectedMarker";
				wikiDescription="Logs all 3D positions of all selected entities.";
			};
			class ENH_LogPositions2D
			{
				action="'2D' call ENH_fnc_3DENLog";
				text="$STR_ENH_MAIN_CONTEXTMENU_LOGPOSITIONS2D";
				conditionShow="selected";
				wikiDescription="Logs all 2D positions of all selected entities.";
			};
			class ENH_LogGridPositon
			{
				action="'GRIDPOS' call ENH_fnc_3DENLog";
				text="$STR_ENH_MAIN_CONTEXTMENU_LOGGRIDPOSITION";
				conditionShow="1";
				wikiDescription="Logs all grid positions of all selected entities.";
			};
			class ENH_Log3DENID
			{
				action="'IDS' call ENH_fnc_3DENLog";
				text="$STR_ENH_MAIN_CONTEXTMENU_LOG3DENIDS";
				conditionShow="selected";
				wikiDescription="Logs all entity ids of all selected entities.";
			};
			class ENH_LogVarNames
			{
				action="'VARNAMES' call ENH_fnc_3DENLog";
				text="$STR_ENH_MAIN_CONTEXTMENU_LOGVARNAMES";
				conditionShow="selected";
				wikiDescription="Logs all variable names of all selected entities.";
			};
			class ENH_LogObjectInfo: ENH_LogFactions
			{
				action="'OBJECTINFO' call ENH_fnc_3DENLog";
				text="$STR_ENH_MAIN_CONTEXTMENU_LOGOBJECTINFO";
				wikiDescription="Logs various information about each selected entity.";
			};
			class ENH_MeasureDistance
			{
				action="0 spawn ENH_fnc_measureDistance";
				text="$STR_ENH_MAIN_CONTEXTMENU_MEASUREDISTANCE";
				picture="\x\enh\addons\main\data\ruler_ca.paa";
				conditionShow="1";
				wikiDescription="Allows the measuring between two points, both in 2D and 3D.";
			};
			class ENH_ShowModuleInformation
			{
				action="findDisplay 313 createDisplay 'ENH_ModuleInformation'";
				text="$STR_ENH_MAIN_CONTEXTMENU_GETMODULEINFORMATION";
				conditionShow="hoverLogic";
				opensNewWindow=1;
				wikiDescription="Shows informationa about selected system entity. Useful for modules that have no eden editor description.";
			};
			class ENH_Garrison
			{
				action="findDisplay 313 ctrlCreate ['ENH_Garrison', 20100]";
				text="$STR_ENH_MAIN_CONTEXTMENU_GARRISON";
				picture="\A3\ui_f\data\igui\cfg\simpleTasks\types\getin_ca.paa";
				conditionShow="selected";
				opensNewWindow=1;
				wikiDescription="Opens a UI that allows for quick garrison of selected entities.";
			};
			class ENH_TriggerOwnerPlayer
			{
				action="add3DENConnection ['TriggerOwner', get3DENSelected 'Trigger', player]";
				text="$STR_ENH_MAIN_CONTEXTMENU_SETTRIGGEROWNERPLAYER";
				conditionShow="hoverTrigger";
				wikiDescription="Sets the player as trigger of selected trigger.";
			};
			class ENH_DeleteCrew
			{
				action="call ENH_fnc_deleteCrew";
				text="$STR_ENH_MAIN_CONTEXTMENU_DELETECREW";
				conditionShow="hoverObjectVehicle";
				wikiDescription="Deletes the crew of all selected vehicles.";
			};
			class ENH_AddToFavorites
			{
				action="['contextMenu'] call ENH_fnc_favoritesList";
				text="$STR_ENH_MAIN_CONTEXTMENU_FAVORITES";
				picture="\a3\ui_f_curator\data\displays\rscdisplaycurator\moderecent_ca.paa";
				conditionShow="hoverObject + hoverLogic + hoverMarker";
				wikiDescription="Adds all selected entities to the favorites tab.";
				value=0;
			};
			class ENH_MoveToLayer
			{
				action="findDisplay 313 createDisplay 'ENH_MoveToLayer'";
				text="$STR_ENH_MAIN_SELECTLAYER_MOVETOLAYER";
				picture="a3\3den\data\displays\display3den\panelleft\entitylist_layer_ca.paa";
				conditionShow="selected";
				wikiDescription="Opens a UI that allows to quickly change the layer of all selected entities.";
			};
			class ENH_SelectionFilter
			{
				action="findDisplay 313 createDisplay 'ENH_SelectionFilter'";
				text="$STR_ENH_MAIN_SELECTIONFILTER";
				conditionShow="selected";
				opensNewWindow=1;
				wikiDescription="Opens a UI that allows to adjust current selection based on various filters.";
			};
			class MoveCamera
			{
				action="0 spawn ENH_fnc_centerMapOnSelection";
			};
		};
	};
	class Controls
	{
		class ENH_FavoritesPreviewBackground: ctrlStatic
		{
			idc=15001;
			colorBackground[]={0.2,0.2,0.2,0.87};
		};
		class ENH_FavoritesPreviewPicture: ctrlStaticPictureKeepAspect
		{
			idc=15002;
		};
		class StatusBar: ctrlControlsGroupNoScrollbars
		{
			class Controls
			{
				class TextX: ctrlStaticPicture
				{
					colorText[]={0.76999998,0.18000001,0.1,1};
				};
				class ValueX: ctrlEdit
				{
					w="19 * (pixelW * pixelGrid * 0.50)";
				};
				class Version: ValueX
				{
					idc=-1;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 15 * (pixelW * pixelGrid * 0.50) - (2 * pixelW)";
					y="2 * pixelH";
					w="4 * (pixelW * pixelGrid * 0.50) - 4 * pixelW";
					h="4 * (pixelH * pixelGrid * 0.50) - 4 * pixelH";
					onButtonClick="call ENH_fnc_productInfo";
					onLoad="_this # 0 ctrlSetToolTip format ['%1.%2', (productVersion select 2) * 0.01 toFixed 2, productVersion select 3]";
					access=0;
					blinkingPeriod=0;
					borderSize=0;
					colorBackground[]={0,0,0,0.5};
					colorBackgroundActive[]=
					{
						"(profilenamespace getvariable ['GUI_BCG_RGB_R', 0.77])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_G', 0.51])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_B', 0.08])",
						1
					};
					colorBackgroundDisabled[]={0,0,0,0.5};
					colorBorder[]={0,0,0,0};
					colorDisabled[]={1,1,1,0.25};
					colorFocused[]=
					{
						"(profilenamespace getvariable ['GUI_BCG_RGB_R', 0.77])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_G', 0.51])",
						"(profilenamespace getvariable ['GUI_BCG_RGB_B', 0.08])",
						1
					};
					colorShadow[]={0,0,0,0};
					colorText[]={1,1,1,1};
					default=0;
					deletable=0;
					fade=0;
					font="PuristaLight";
					offsetPressedX="pixelW";
					offsetPressedY="pixelH";
					offsetX=0;
					offsetY=0;
					period=0;
					periodFocus=2;
					periodOver=0.5;
					shadow=1;
					show=1;
					sizeEx="4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
					soundClick[]=
					{
						"\A3\ui_f\data\sound\RscButton\soundClick",
						0.090000004,
						1
					};
					soundEnter[]=
					{
						"\A3\ui_f\data\sound\RscButton\soundEnter",
						0.090000004,
						1
					};
					soundEscape[]=
					{
						"\A3\ui_f\data\sound\RscButton\soundEscape",
						0.090000004,
						1
					};
					soundPush[]=
					{
						"\A3\ui_f\data\sound\RscButton\soundPush",
						0.090000004,
						1
					};
					style="0x02 + 0xC0";
					text="V";
					tooltip="";
					type=1;
				};
				class TextY: TextX
				{
					x="22 * (pixelW * pixelGrid * 0.50)";
					colorText[]={0.57999998,0.81999999,0.22,1};
				};
				class ValueY: ValueX
				{
					x="25 * (pixelW * pixelGrid * 0.50)";
				};
				class TextZ: TextX
				{
					x="44 * (pixelW * pixelGrid * 0.50)";
					colorText[]={0.25999999,0.51999998,0.92000002,1};
				};
				class ValueZ: ValueX
				{
					x="47 * (pixelW * pixelGrid * 0.50)";
				};
				class TextDis: TextX
				{
					x="66 * (pixelW * pixelGrid * 0.50)";
					colorText[]={1,1,1,1};
				};
				class ValueDis: ValueX
				{
					x="69 * (pixelW * pixelGrid * 0.50)";
				};
				class ENH_TextDir: TextX
				{
					idc=682;
					x="99 * (pixelW * pixelGrid * 0.50)";
					text="\a3\3den\data\attributes\loiterdirection\ccw_ca.paa";
					colorText[]={1,1,1,1};
				};
				class ENH_ValueDir: ValueX
				{
					idc=681;
					x="102 * (pixelW * pixelGrid * 0.50)";
					w="9 * (pixelW * pixelGrid * 0.50)";
					onLoad="(_this # 0) ctrlEnable false";
					style=514;
				};
				class ENH_SessionTime: ENH_TextDir
				{
					idc=668;
					text="a3\modules_f_curator\data\portraitskiptime_ca.paa";
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 11 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
					y="2 * pixelH";
				};
				class ENH_NumberMarkers: ValueY
				{
					idc=669;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 22 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
					w="7 * (pixelW * pixelGrid * 0.50)";
					onLoad="(_this # 0) ctrlShow false; (_this # 0) ctrlEnable false";
					style=514;
				};
				class ENH_IconMarkers: ENH_TextDir
				{
					idc=670;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 25 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
					onLoad="(_this # 0) ctrlShow false";
					text="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeMarkers_ca.paa";
				};
				class ENH_NumberSystems: ENH_NumberMarkers
				{
					idc=671;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 32 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
				};
				class ENH_IconSystems: ENH_IconMarkers
				{
					idc=672;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 35 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
					text="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeModules_ca.paa";
				};
				class ENH_NumberWaypoints: ENH_NumberMarkers
				{
					idc=673;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 42 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
				};
				class ENH_IconWaypoints: ENH_IconMarkers
				{
					idc=674;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 45 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
					text="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeWaypoints_ca.paa";
				};
				class ENH_NumberTriggers: ENH_NumberMarkers
				{
					idc=675;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 52 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
				};
				class ENH_IconTriggers: ENH_IconMarkers
				{
					idc=676;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 55 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
					text="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeTriggers_ca.paa";
				};
				class ENH_NumberGroups: ENH_NumberMarkers
				{
					idc=677;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 62 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
				};
				class ENH_IconGroups: ENH_IconMarkers
				{
					idc=678;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 65 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
					text="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeGroups_ca.paa";
				};
				class ENH_NumberObjects: ENH_NumberMarkers
				{
					idc=679;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 72 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
				};
				class ENH_IconObjects: ENH_IconMarkers
				{
					idc=680;
					x="(safeZoneW - 60 * (pixelW * pixelGrid * 0.50)) - 75 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW)";
					text="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeObjects_ca.paa";
				};
			};
		};
		class MenuStrip: ctrlMenuStrip
		{
			class Items
			{
				items[]+=
				{
					"ENH_About"
				};
				class ENH_About
				{
					text="$STR_ENH_MAIN_FOLDER_ABOUT";
					items[]+=
					{
						"ENH_Changelog",
						"ENH_Steam",
						"ENH_Contributing",
						"ENH_Documentation",
						"ENH_Credits",
						"ENH_BugReport"
					};
				};
				class ENH_Changelog
				{
					text="$STR_ENH_MAIN_CHANGELOG";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://github.com/R3voA3/3den-Enhanced/blob/master/CHANGELOG.md";
					opensNewWindow=1;
					wikiDescription="Opens the changelog.";
				};
				class ENH_Steam: ENH_Changelog
				{
					text="$STR_ENH_MAIN_STEAM";
					weblink="https://steamcommunity.com/sharedfiles/filedetails/?id=623475643";
					wikiDescription="Open 3den Enhanced Steam page.";
				};
				class ENH_Contributing: ENH_Changelog
				{
					text="$STR_ENH_MAIN_CONTRIBUTE";
					weblink="https://github.com/R3voA3/3den-Enhanced/blob/master/.github/CONTRIBUTING.md";
					wikiDescription="Explains how to contribute.";
				};
				class ENH_Documentation: ENH_Changelog
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
					weblink="https://github.com/R3voA3/3den-Enhanced/wiki";
					wikiDescription="Opens the 3den Enhanced documentation.";
				};
				class ENH_Credits: ENH_Changelog
				{
					text="$STR_ENH_MAIN_CREDITS";
					weblink="https://github.com/R3voA3/3den-Enhanced/blob/master/CONTRIBUTORS.md";
					wikiDescription="Shows all contributors.";
				};
				class ENH_BugReport: ENH_Changelog
				{
					text="$STR_ENH_MAIN_REPORT";
					weblink="https://github.com/R3voA3/3den-Enhanced/issues/new/choose";
					wikiDescription="Open a bug report on GitHub.";
				};
				class Tools
				{
					items[]+=
					{
						"ENH_Folder_Utilities",
						"ENH_Folder_Placement",
						"ENH_Folder_Loadout",
						"ENH_Folder_VHC",
						"ENH_Folder_Debug",
						"ENH_Folder_Miscellaneous",
						"ENH_Folder_Layer"
					};
				};
				class ENH_Folder_Utilities
				{
					text="$STR_ENH_MAIN_FOLDER_UTILITIES";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[]+=
					{
						"ENH_CfgDisabledCommands",
						"ENH_Jukebox",
						"ENH_MoonPhases",
						"ENH_PrintConfig",
						"ENH_ScriptCommands",
						"Separator",
						"ENH_3DENRadio",
						"ENH_SAM",
						"ENH_CfgSentencesBrowser",
						"ENH_TextureFinder",
						"Separator",
						"ENH_BriefingEditor",
						"ENH_AttributeSearch",
						"ENH_NameObjects",
						"ENH_ZeusAddons",
						"Separator",
						"ENH_CommandPalette",
						"ENH_CommandPalette_Reset_Priority"
					};
				};
				class ENH_MoonPhases
				{
					text="$STR_ENH_MAIN_TOOLS_MOONPHASES";
					action="[] spawn compileScript ['A3\Functions_F\Debug\Utilities\utility_moonPhases.sqf']";
					opensNewWindow=1;
					wikiDescription="See [Arma 3: Utilities](https://community.bistudio.com/wiki/Arma_3:_Utilities).";
				};
				class ENH_Jukebox
				{
					text="$STR_ENH_MAIN_TOOLS_JUKEBOX";
					action="0 spawn compileScript ['A3\Functions_F\Debug\Utilities\utility_jukebox.sqf']";
					opensNewWindow=1;
					wikiDescription="See [Arma 3: Utilities](https://community.bistudio.com/wiki/Arma_3:_Utilities).";
				};
				class ENH_PrintConfig
				{
					text="$STR_ENH_MAIN_TOOLS_PRINTCONFIG";
					action="configNull spawn compileScript ['A3\Functions_F\Debug\Utilities\utility_printConfig.sqf']";
					opensNewWindow=1;
					wikiDescription="See [Arma 3: Utilities](https://community.bistudio.com/wiki/Arma_3:_Utilities).";
				};
				class ENH_CfgDisabledCommands
				{
					text="$STR_ENH_MAIN_TOOLS_CFGDISABLEDCOMMANDS";
					action="0 spawn compileScript ['A3\Functions_F\Debug\Utilities\utility_cfgDisabledCommands.sqf']";
					opensNewWindow=1;
					wikiDescription="See [Arma 3: Utilities](https://community.bistudio.com/wiki/Arma_3:_Utilities).";
				};
				class ENH_ScriptCommands
				{
					text="$STR_ENH_MAIN_TOOLS_SCRIPTCOMMANDS";
					action="0 spawn compileScript ['A3\Functions_F\Debug\Utilities\utility_scriptCommands.sqf']";
					opensNewWindow=1;
					wikiDescription="See [Arma 3: Utilities](https://community.bistudio.com/wiki/Arma_3:_Utilities).";
				};
				class ENH_BriefingEditor
				{
					text="$STR_ENH_MAIN_TOOLS_BRIEFINGEDITOR";
					picture="\A3\ui_f\data\igui\cfg\simpleTasks\types\whiteboard_ca.paa";
					action="findDisplay 313 createDisplay 'ENH_briefingEditor'";
					shortcuts[]={2096};
					opensNewWindow=1;
					wikiDescription="Opens the Briefing Editor. See GUI documentation for detailed information.";
				};
				class ENH_3DENRadio
				{
					text="$STR_ENH_MAIN_TOOLS_3DENRADIO";
					picture="\A3\ui_f\data\igui\cfg\simpleTasks\types\radio_ca.paa";
					action="findDisplay 313 createDisplay 'ENH_3DENRadio'";
					shortcuts[]={2098};
					opensNewWindow=1;
					wikiDescription="Opens 3DEN Radio. See GUI documentation for detailed information.";
				};
				class ENH_SAM
				{
					text="$STR_ENH_MAIN_TOOLS_SAM";
					action="findDisplay 313 createDisplay 'ENH_SAM'";
					opensNewWindow=1;
					wikiDescription="Opens the Scenario Attributes Manager. See GUI documentation for detailed information.";
				};
				class ENH_NameObjects
				{
					text="$STR_ENH_MAIN_TOOLS_BATCHNAMING";
					action="call ENH_fnc_nameObjects";
					shortcuts[]={2097};
					opensNewWindow=1;
					wikiDescription="Opens the Name Objects GUI. See GUI documentation for detailed information.";
				};
				class ENH_TextureFinder
				{
					text="$STR_ENH_MAIN_TOOLS_TEXTUREFINDER";
					picture="\A3\ui_f\data\igui\cfg\simpleTasks\types\search_ca.paa";
					action="findDisplay 313 createDisplay 'ENH_TextureFinder'";
					shortcuts[]={2068};
					opensNewWindow=1;
					wikiDescription="Opens the Texture Finder. See GUI documentation for detailed information.";
				};
				class ENH_CfgSentencesBrowser
				{
					text="$STR_ENH_MAIN_TOOLS_CFGSENTENCESBROWSER";
					action="findDisplay 313 createDisplay 'ENH_CfgSentencesBrowser'";
					opensNewWindow=1;
					wikiDescription="Opens the CfgSentences Browser. See GUI documentation for detailed information.";
				};
				class ENH_ZeusAddons
				{
					text="$STR_ENH_MAIN_ZEUSADDONS_HEADER";
					action="call ENH_fnc_zeusAddons";
					opensNewWindow=1;
					wikiDescription="Opens the Mange Zeus Addons GUI. See GUI documentation for detailed information.";
				};
				class ENH_AttributeSearch
				{
					text="$STR_ENH_MAIN_SEARCHATTRIBUTES_HEADER";
					action="findDisplay 313 createDisplay 'ENH_AttributeSearch'";
					opensNewWindow=1;
					wikiDescription="Quickly search through the the text attributes such as 'ini' or 'condition' of all entities.";
				};
				class ENH_CommandPalette
				{
					text="$STR_ENH_MAIN_3DEN_COMMAND_PALETTE_OPEN";
					shortcuts[]={2105};
					action="call ENH_fnc_3DENCommandPalette_init";
					picture="\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
				};
				class ENH_CommandPalette_Reset_Priority
				{
					text="$STR_ENH_MAIN_3DEN_COMMAND_PALETTE_RESET_PRIORITY";
					shortcuts[]={};
					action="profileNamespace setVariable ['ENH_3DENCommandPalette_PriorityMap', nil]";
				};
				class ENH_Folder_Placement
				{
					text="$STR_ENH_MAIN_FOLDER_PLACEMENTTOOLS";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[]+=
					{
						"ENH_PlacementTools",
						"Separator",
						"ENH_Folder_Orient",
						"ENH_Folder_Align",
						"ENH_Folder_Space",
						"Separator",
						"ENH_SnapToSurface",
						"Separator",
						"ENH_QuickGarrison"
					};
				};
				class ENH_PlacementTools
				{
					text="$STR_ENH_MAIN_TOOLS_PLACEMENTTOOL";
					action="[nil, 'createUI'] call ENH_fnc_placementTools";
					shortcuts[]={2598};
					opensNewWindow=1;
					wikiDescription="Opens Placement Tool GUI. See GUI documentation for detailed information.";
				};
				class ENH_SnapToSurface
				{
					text="$STR_3DEN_DISPLAY3DEN_ENTITYMENU_MOVESURFACE_TEXT";
					action="do3DENAction 'SnapToSurface'";
					shortcuts[]={569};
					picture="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\moveSurface_ca.paa";
					wikiDescription="Snaps all selected entities to the surface.";
				};
				class ENH_QuickGarrison
				{
					text="Garrison";
					action="call ENH_fnc_garrison2_main";
					shortcuts[]={34};
					picture="a3\modules_f\data\editterrainobject\texturedoor_opened_ca.paa";
					wikiDescription="Allows garrisoning of buildings by dragging entities.";
				};
				class ENH_Folder_Orient
				{
					text="$STR_ENH_MAIN_FOLDER_ORIENT";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[]+=
					{
						"ENH_SetRandomDir",
						"ENH_ReverseDirection",
						"Separator",
						"ENH_OrientateNorth",
						"ENH_OrientateEast",
						"ENH_OrientateSouth",
						"ENH_OrientateWest"
					};
				};
				class ENH_SetRandomDir
				{
					Text="$STR_ENH_MAIN_TOOLS_RANDOMDIR";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\widget_rotation_off_ca.paa";
					action="-1 call ENH_fnc_setOrientation";
					conditionShow="selectedObject + selectedWaypoint + selectedLogic + selectedMarker";
					shortcuts[]={593};
					wikiDescription="Randomises direction of all selected entities.";
				};
				class ENH_ReverseDirection
				{
					text="$STR_ENH_MAIN_TOOLS_REVERSEDIRECTION";
					picture="\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa";
					action="-2 call ENH_fnc_setOrientation";
					shortcuts[]={583};
					wikiDescription="Reverses direction of all selected entities.";
				};
				class ENH_OrientateNorth
				{
					text="$STR_ENH_MAIN_TOOLS_ORIENTATENORTH";
					picture="\A3\ui_f\data\igui\cfg\simpleTasks\letters\N_ca.paa";
					action="0 call ENH_fnc_setOrientation";
					shortcuts[]={584};
					wikiDescription="Orients all selected entities to north.";
				};
				class ENH_OrientateEast: ENH_OrientateNorth
				{
					text="$STR_ENH_MAIN_TOOLS_ORIENTATEEAST";
					picture="\A3\ui_f\data\igui\cfg\simpleTasks\letters\E_ca.paa";
					action="90 call ENH_fnc_setOrientation";
					shortcuts[]={589};
					wikiDescription="Orients all selected entities to east.";
				};
				class ENH_OrientateSouth: ENH_OrientateNorth
				{
					text="$STR_ENH_MAIN_TOOLS_ORIENTATESOUTH";
					picture="\A3\ui_f\data\igui\cfg\simpleTasks\letters\S_ca.paa";
					action="180 call ENH_fnc_setOrientation";
					shortcuts[]={592};
					wikiDescription="Orients all selected entities to south.";
				};
				class ENH_OrientateWest: ENH_OrientateNorth
				{
					text="$STR_ENH_MAIN_TOOLS_ORIENTATEWEST";
					picture="\A3\ui_f\data\igui\cfg\simpleTasks\letters\W_ca.paa";
					action="270 call ENH_fnc_setOrientation";
					shortcuts[]={587};
					wikiDescription="Orients all selected entities to west.";
				};
				class ENH_Folder_Align
				{
					text="$STR_ENH_MAIN_FOLDER_ALIGN";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[]+=
					{
						"ENH_AlignXMax",
						"ENH_AlignXMin",
						"ENH_AlignYMax",
						"ENH_AlignYMin",
						"ENH_AlignZMax",
						"ENH_AlignZMin"
					};
				};
				class ENH_AlignXMax
				{
					text="$STR_ENH_MAIN_TOOLS_ALIGN_X_MAX";
					action="[0] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
					shortcuts[]={2637};
					wikiDescription="Aligns all selected entities with the farthest east entity.";
				};
				class ENH_AlignXMin
				{
					text="$STR_ENH_MAIN_TOOLS_ALIGN_X_MIN";
					action="[0, false] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
					shortcuts[]={2635};
					wikiDescription="Aligns all selected entities with the farthest west entity.";
				};
				class ENH_AlignYMax
				{
					text="$STR_ENH_MAIN_TOOLS_ALIGN_Y_MAX";
					action="[1] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
					shortcuts[]={2632};
					wikiDescription="Aligns all selected entities with the farthest north entity.";
				};
				class ENH_AlignYMin
				{
					text="$STR_ENH_MAIN_TOOLS_ALIGN_Y_MIN";
					action="[1, false] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
					shortcuts[]={2640};
					wikiDescription="Aligns all selected entities with the farthest south entity.";
				};
				class ENH_AlignZMax
				{
					text="$STR_ENH_MAIN_TOOLS_ALIGN_Z_MAX";
					action="[2] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
					shortcuts[]={2633};
					wikiDescription="Aligns all selected entities with the highest entity.";
				};
				class ENH_AlignZMin
				{
					text="$STR_ENH_MAIN_TOOLS_ALIGN_Z_MIN";
					action="[2, false] call (uiNamespace getVariable 'ENH_fnc_alignEntities')";
					shortcuts[]={2639};
					wikiDescription="Aligns all selected entities with the lowest entity.";
				};
				class ENH_Folder_Space
				{
					text="$STR_ENH_MAIN_FOLDER_SPACE";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[]+=
					{
						"ENH_SpaceEquallyX",
						"ENH_SpaceEquallyY",
						"ENH_SpaceEquallyZ"
					};
				};
				class ENH_SpaceEquallyX
				{
					text="$STR_ENH_MAIN_TOOLS_SPACEEQUALLY_X";
					action="0 call (uiNamespace getVariable 'ENH_fnc_spaceEqually')";
					wikiDescription="Spaces all selected entities equally along the X-axis.";
				};
				class ENH_SpaceEquallyY
				{
					text="$STR_ENH_MAIN_TOOLS_SPACEEQUALLY_Y";
					action="1 call (uiNamespace getVariable 'ENH_fnc_spaceEqually')";
					wikiDescription="Spaces all selected entities equally along the y-axis.";
				};
				class ENH_SpaceEquallyZ
				{
					text="$STR_ENH_MAIN_TOOLS_SPACEEQUALLY_Z";
					action="2 call (uiNamespace getVariable 'ENH_fnc_spaceEqually')";
					wikiDescription="Spaces all selected entities equally along the z-axis.";
				};
				class ENH_Folder_Loadout
				{
					text="$STR_ENH_MAIN_FOLDER_LOADOUTTOOLS";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[]+=
					{
						"ENH_ESE",
						"ENH_CopyLoadout",
						"ENH_ApplyLoadout",
						"ENH_ExportLoadoutConfig",
						"ENH_ExportLoadoutCfgRespawnInventory",
						"Separator",
						"ENH_RemoveNVGs",
						"ENH_RemoveVests",
						"ENH_RemoveGoggles",
						"ENH_RemoveHeadgear",
						"ENH_RemoveWeapons",
						"ENH_RemoveGear"
					};
				};
				class ENH_CopyLoadout
				{
					text="$STR_ENH_MAIN_TOOLS_COPYLOADOUTS";
					action="'copy' call ENH_fnc_loadoutTool";
					shortcuts[]={1582};
					wikiDescription="Copies loadout of all selected entities.";
				};
				class ENH_ApplyLoadout
				{
					text="$STR_ENH_MAIN_TOOLS_APPLYLOADOUTS";
					action="'apply' call ENH_fnc_loadoutTool";
					shortcuts[]={1566};
					wikiDescription="Applies copied loadouts to all selected entities. If multiple loadouts were copied a random one for each selected entity is choosen.";
				};
				class ENH_ExportLoadoutCfgRespawnInventory
				{
					text="$STR_ENH_MAIN_TOOLS_EXPORTLOADOUT_CFGRESPAWNINVENTORY";
					action="false call ENH_fnc_exportLoadout";
					wikiDescription="Exports loadout in CfgRespawnInventory format.";
				};
				class ENH_ExportLoadoutConfig
				{
					text="$STR_ENH_MAIN_TOOLS_EXPORTLOADOUT_CONFIG";
					action="true call ENH_fnc_exportLoadout";
					wikiDescription="Exports loadout in config format.";
				};
				class ENH_RemoveNVGs
				{
					text="$STR_ENH_MAIN_TOOLS_REMOVENVGS";
					action="2 call ENH_fnc_removeGear";
					shortcuts[]={1585};
					wikiDescription="Removes NVG of all selected entities.";
				};
				class ENH_RemoveVests
				{
					text="$STR_ENH_MAIN_TOOLS_REMOVEVESTS";
					action="3 call ENH_fnc_removeGear";
					wikiDescription="Removes vest of all selected entities.";
				};
				class ENH_RemoveGoggles
				{
					text="$STR_ENH_MAIN_TOOLS_REMOVEGOGGLES";
					action="0 call ENH_fnc_removeGear";
					shortcuts[]={1570};
					wikiDescription="Removes goggles of all selected entities.";
				};
				class ENH_RemoveHeadgear
				{
					text="$STR_ENH_MAIN_TOOLS_REMOVEHEADGEAR";
					action="1 call ENH_fnc_removeGear";
					shortcuts[]={1571};
					wikiDescription="Removes headgear of all selected entities.";
				};
				class ENH_RemoveWeapons
				{
					text="$STR_ENH_MAIN_TOOLS_REMOVEWEAPONS";
					action="4 call ENH_fnc_removeGear";
					shortcuts[]={1553};
					wikiDescription="Removes weapons of all selected entities.";
				};
				class ENH_RemoveGear
				{
					text="$STR_ENH_MAIN_TOOLS_REMOVEGEAR";
					action="7 call ENH_fnc_removeGear";
					shortcuts[]={1568};
					wikiDescription="Clear inventory of all selected entities.";
				};
				class ENH_ESE
				{
					text="$STR_ENH_MAIN_TOOLS_ESE";
					action="call ENH_fnc_ESE_open";
					opensNewWindow=1;
					shortcuts[]={1559};
					wikiDescription="Opes the Vehicle Inventory Manager. See GUI documentation for detailed information.";
				};
				class ENH_Folder_VHC
				{
					text="$STR_ENH_MAIN_FOLDER_VHC";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[]+=
					{
						"ENH_CopyVHC",
						"ENH_ApplyVHC",
						"ENH_RandomVHC",
						"Separator",
						"ENH_CopyPylonSettings",
						"ENH_ApplyPylonSettings",
						"ENH_ExportPylonsToSQF"
					};
				};
				class ENH_CopyVHC
				{
					text="$STR_ENH_MAIN_TOOLS_COPYVHC";
					action="'copy' call (uiNamespace getVariable 'ENH_fnc_VHCTools')";
					wikiDescription="Copies vehicle appearance.";
				};
				class ENH_ApplyVHC
				{
					text="$STR_ENH_MAIN_TOOLS_APPLYVHC";
					action="'apply' call (uiNamespace getVariable 'ENH_fnc_VHCTools')";
					wikiDescription="Applies previously copied vehicle appearance. If multiple appearances were copied a random one is selected for each entity.";
				};
				class ENH_RandomVHC
				{
					text="$STR_ENH_MAIN_TOOLS_RANDOMIZEVHC";
					action="'random' call (uiNamespace getVariable 'ENH_fnc_VHCTools')";
					wikiDescription="Randomizes vehicle appearance.";
				};
				class ENH_CopyPylonSettings
				{
					text="$STR_ENH_MAIN_TOOLS_COPYPYLONS";
					action="'copy' call (uiNamespace getVariable 'ENH_fnc_pylonTools')";
					wikiDescription="Copies pylon settings of selected entities.";
				};
				class ENH_ApplyPylonSettings
				{
					text="$STR_ENH_MAIN_TOOLS_APPLYPYLONS";
					action="'apply' call (uiNamespace getVariable 'ENH_fnc_pylonTools')";
					wikiDescription="Applies random pylon setting that from previously copied settings.";
				};
				class ENH_ExportPylonsToSQF
				{
					text="$STR_ENH_MAIN_TOOLS_EXPORTPYLONSTOSQF";
					action="'exportToSQF' call (uiNamespace getVariable 'ENH_fnc_pylonTools')";
					wikiDescription="Exports pylon settings as sqf script for later execution.";
				};
				class ENH_Folder_Debug
				{
					text="$STR_ENH_MAIN_FOLDER_DEBUGTOOLS";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[]+=
					{
						"ENH_VariableViewer",
						"ENH_RPTViewer",
						"Separator",
						"ENH_ProductInfo",
						"ENH_ClearChat",
						"Separator",
						"ENH_ExportGUIBaseClasses",
						"ENH_GUITestGrids"
					};
				};
				class ENH_VariableViewer
				{
					text="$STR_ENH_MAIN_TOOLS_VARIABLEVIEWER";
					action="findDisplay 313 createDisplay 'ENH_VariableViewer'";
					opensNewWindow=1;
					wikiDescription="Opens the Variable Viewer. See GUI documentation for detailed information.";
				};
				class ENH_RPTViewer
				{
					text="$STR_ENH_MAIN_TOOLS_RPTVIEWER";
					action="'open' call ENH_fnc_RPTViewer";
					opensNewWindow=1;
					shortcuts[]={2607};
					wikiDescription="Opens the RPT Viewer. See GUI documentation for detailed information.";
				};
				class ENH_ProductInfo
				{
					text="$STR_ENH_MAIN_TOOLS_PRODUCTINFO";
					action="call ENH_fnc_productInfo";
					wikiDescription="Logs various information about the game.";
				};
				class ENH_ClearChat
				{
					text="$STR_ENH_MAIN_TOOLS_CLEARCHAT";
					action="clearRadio";
					shortcuts[]={2606};
					wikiDescription="Clears all system messages from the chat window.";
				};
				class ENH_ExportGUIBaseClasses
				{
					text="$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES";
					action="findDisplay 313 createDisplay 'ENH_ExportGUIDefines'";
					wikiDescription="Open a GUI to export GUI base classes. See GUI documentation for detailed information.";
				};
				class ENH_GUITestGrids
				{
					text="$STR_ENH_MAIN_TOOLS_GUITESTGRIDS";
					action="findDisplay 313 createDisplay 'RscTestGrids'";
					opensNewWindow=1;
					wikiDescription="Opens a GUI for testing different UI grids.";
				};
				class ENH_Folder_Miscellaneous
				{
					text="$STR_ENH_MAIN_FOLDER_MISCELLANEOUS";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[]+=
					{
						"ENH_CreateTrigger",
						"Separator",
						"ENH_SwitchTime",
						"ENH_ToggleGrass",
						"Separator",
						"ENH_ToggleSimpleObject",
						"ENH_ToggleSimulation",
						"ENH_ToggleDynamicSimulation",
						"ENH_TogglePlayable",
						"ENH_ToggleIsLocalOnly",
						"ENH_ToggleAIFeatures"
					};
				};
				class ENH_CreateTrigger
				{
					text="$STR_ENH_MAIN_TOOLS_CREATETRIGGER";
					picture="\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
					action="private _trigger = create3DENEntity ['Trigger', 'EmptyDetectorArea10x10', [worldSize / 2, worldSize / 2, 0]]; _trigger set3DENAttribute ['size3', [worldSize / 2, worldSize / 2, 0]]; ['ENH_ActionPerformed'] call BIS_fnc_3DENNotification";
					wikiDescription="Creates a trigger which covers exactly the whole map.";
				};
				class ENH_SwitchTime
				{
					text="$STR_ENH_MAIN_TOOLS_SWITCHTIME";
					picture="\A3\ui_f\data\igui\cfg\actions\settimer_ca.paa";
					action="call ENH_fnc_switchTime";
					shortcuts[]={2248};
					wikiDescription="Switches the time and weather in Eden Editor so editing can be done with best visibility. Changes are not applied to the scenario. Press again to revert.";
				};
				class ENH_ToggleGrass
				{
					text="$STR_ENH_MAIN_TOOLS_TOGGLEGRASS";
					action="0 spawn ENH_fnc_toggleGrass";
					shortcuts[]={2256};
					wikiDescription="Hides grass in Eden Editor.";
				};
				class ENH_ToggleSimpleObject
				{
					text="$STR_ENH_MAIN_TOOLS_TOGGLESIMPLEOBJECT";
					picture="";
					action="[['Object'], ['objectIsSimple']] call ENH_fnc_toggleAttributes";
					shortcuts[]={2079};
					wikiDescription="Toggles simple object state of all selected entities.";
				};
				class ENH_ToggleSimulation
				{
					text="$STR_ENH_MAIN_TOOLS_TOGGLESIMULATION";
					picture="";
					action="[['Object'], ['enableSimulation']] call ENH_fnc_toggleAttributes";
					shortcuts[]={2066};
					wikiDescription="Toggles simulation of all selected entities.";
				};
				class ENH_ToggleDynamicSimulation
				{
					text="$STR_ENH_MAIN_TOOLS_TOGGLEDYNAMICSIMULATION";
					picture="";
					action="[['Object', 'Group'], ['dynamicSimulation']] call ENH_fnc_toggleAttributes";
					shortcuts[]={2080};
					wikiDescription="Toggles dynamic simulation of all selected entities.";
				};
				class ENH_ToggleIsLocalOnly
				{
					text="$STR_ENH_MAIN_TOOLS_TOGGLEISLOCALONLY";
					picture="";
					action="[['Object'], ['isLocalOnly']] call ENH_fnc_toggleAttributes";
					shortcuts[]={2086};
					wikiDescription="Toggles the local only attribute of all selected entities.";
				};
				class ENH_ToggleAIFeatures
				{
					text="$STR_ENH_MAIN_TOOLS_TOGGLEAIFEATURES";
					action="[['object'], ['ENH_disableAI_all']] call ENH_fnc_toggleAttributes";
					wikiDescription="Will toggle all AI features (Inverse their state).";
				};
				class ENH_TogglePlayable
				{
					text="$STR_ENH_MAIN_TOOLS_PLAYABLE";
					action="[['Object'], ['ControlMP']] call ENH_fnc_toggleAttributes";
					picture="\a3\3den\data\cfg3den\object\iconplayer_ca.paa";
					shortcuts[]={2073};
					wikiDescription="Toggles playable state of all selected entities.";
				};
				class ENH_Folder_Layer
				{
					text="$STR_3DEN_LAYER_TEXTPLURAL";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[]+=
					{
						"ENH_SelectAllLayers",
						"Separator",
						"ENH_DeleteEmptyLayers",
						"Separator",
						"ENH_EnableLayer",
						"ENH_ShowLayer"
					};
				};
				class ENH_SelectAllLayers
				{
					action="set3DENSelected (all3DENEntities # 6)";
					picture="\x\enh\addons\main\data\selectAllLayers_ca.paa";
					text="$STR_ENH_MAIN_TOOLS_SELECTALLLAYERS";
				};
				class ENH_DeleteEmptyLayers
				{
					action="call ENH_fnc_deleteEmptyLayers";
					picture="\x\enh\addons\main\data\trash_ca.paa";
					text="$STR_ENH_MAIN_TOOLS_DELETEEMPTYLAYERS";
				};
				class ENH_EnableLayer
				{
					action="'EnableLayer' call bis_fnc_3DENInterface";
					picture="\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_layerEnable_ca.paa";
					text="$STR_3DEN_DISPLAY3DEN_ENABLELAYER_TOOLTIP";
				};
				class ENH_ShowLayer
				{
					action="'ShowLayer' call bis_fnc_3DENInterface";
					picture="\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_layerShow_ca.paa";
					text="$STR_3DEN_DISPLAY3DEN_SHOWLAYER_TOOLTIP";
				};
				class FunctionsViewer
				{
					action="findDisplay 313 createDisplay 'ENH_FunctionsViewer'";
					shortcuts[]={2081};
				};
				class ConfigViewer
				{
					shortcuts[]={2094};
				};
				class DebugConsole
				{
					shortcuts[]={544};
				};
				class MissionFolder
				{
					shortcuts[]={2072};
				};
				class Help
				{
					items[]+=
					{
						"ENH_GetExtensions",
						"ENH_AICompilationList",
						"ENH_Folder_Wiki"
					};
				};
				class ENH_Folder_Wiki
				{
					text="$STR_ENH_MAIN_FOLDER_WIKI";
					picture="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
					items[]+=
					{
						"ENH_CommandsList",
						"ENH_FunctionsList",
						"ENH_MissionPresentation",
						"ENH_DescriptionExt",
						"ENH_CodeOptimisation",
						"ENH_MissionOptimisation",
						"ENH_MultiplayerScripting"
					};
				};
				class ENH_GetExtensions
				{
					text="$STR_ENH_MAIN_GETEXTENSIONS";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://steamcommunity.com/sharedfiles/filedetails/?id=1774491737";
					opensNewWindow=1;
					wikiDescription="Shows a collection of other editor extensions.";
				};
				class ENH_AICompilationList: ENH_GetExtensions
				{
					text="$STR_ENH_MAIN_AICOMPILATION";
					weblink="https://forums.bistudio.com/topic/165560-ai-compilation-list-of-addonsmodsscripts-misc/";
					wikiDescription="Shows a list of useful AI modifications.";
				};
				class ENH_CommandsList: ENH_GetExtensions
				{
					text="$STR_ENH_MAIN_COMMANDSOVERVIEW";
					weblink="https://community.bistudio.com/wiki/Category:Scripting_Commands_by_Functionality";
					wikiDescription="Open commmunity wiki page about commands.";
				};
				class ENH_FunctionsList: ENH_GetExtensions
				{
					text="$STR_ENH_MAIN_FUNCTIONSOVERVIEW";
					weblink="https://community.bistudio.com/wiki/Category:Functions_by_Functionality";
					wikiDescription="Open commmunity wiki page about functions.";
				};
				class ENH_MissionPresentation: ENH_GetExtensions
				{
					text="$STR_ENH_MAIN_MISSIONPRESENTATION";
					weblink="https://community.bistudio.com/wiki/Mission_Presentation";
					wikiDescription="Open commmunity wiki page about mission presentation.";
				};
				class ENH_DescriptionExt: ENH_GetExtensions
				{
					text="$STR_ENH_MAIN_DESCRIPTIONEXT";
					weblink="https://community.bistudio.com/wiki/Description.ext";
					wikiDescription="Open commmunity wiki page about code description.ext.";
				};
				class ENH_CodeOptimisation: ENH_GetExtensions
				{
					text="$STR_ENH_MAIN_CODEOPTIMISATION";
					weblink="https://community.bistudio.com/wiki/Code_Optimisation";
					wikiDescription="Open commmunity wiki page about code optimisation.";
				};
				class ENH_MissionOptimisation: ENH_GetExtensions
				{
					text="$STR_ENH_MAIN_MISSIONOPTIMISATION";
					weblink="https://community.bistudio.com/wiki/Mission_Optimisation";
					wikiDescription="Open commmunity wiki page about mission optimisation.";
				};
				class ENH_MultiplayerScripting: ENH_GetExtensions
				{
					text="$STR_ENH_MAIN_MULTIPLAYERSCRIPTING";
					weblink="https://community.bistudio.com/wiki/Multiplayer_Scripting";
					wikiDescription="Open commmunity wiki page about multiplayer scripting.";
				};
			};
		};
		class PanelRight: ctrlControlsGroupNoScrollbars
		{
			class Controls
			{
				class PanelRightHistory;
				class ENH_PanelRightFavorites: PanelRightHistory
				{
					idc=15000;
					class Controls
					{
						class ENH_Footer: ctrlStaticFooter
						{
							y="safeZoneH - (28 + 7) * (pixelH * pixelGrid * 0.50)";
							w="60 * (pixelW * pixelGrid * 0.50)";
							h="7 * (pixelH * pixelGrid * 0.50)";
						};
						class ENH_PanelRightFavorites_Search: ctrlEdit
						{
							idc=15003;
							x="(pixelW * pixelGrid * 0.50)";
							y="(pixelH * pixelGrid * 0.50)";
							w="43 * (pixelW * pixelGrid * 0.50)";
							h="(5 * (pixelH * pixelGrid * 0.50))";
						};
						class ENH_PanelRightFavorites_SearchButton: ctrlButtonSearch
						{
							idc=15004;
							x="44 * (pixelW * pixelGrid * 0.50)";
							y="(pixelH * pixelGrid * 0.50)";
							w="5 * (pixelW * pixelGrid * 0.50)";
							h="(5 * (pixelH * pixelGrid * 0.50))";
						};
						class ENH_PanelRightFavorites_CollapseButton: ctrlButtonCollapseAll
						{
							idc=15008;
							x="49 * (pixelW * pixelGrid * 0.50)";
							y="(pixelH * pixelGrid * 0.50)";
							w="5 * (pixelW * pixelGrid * 0.50)";
							h="(5 * (pixelH * pixelGrid * 0.50))";
						};
						class ENH_PanelRightFavorites_ExpandButton: ctrlButtonExpandAll
						{
							idc=15007;
							x="54 * (pixelW * pixelGrid * 0.50)";
							y="(pixelH * pixelGrid * 0.50)";
							w="5 * (pixelW * pixelGrid * 0.50)";
							h="(5 * (pixelH * pixelGrid * 0.50))";
						};
						class ENH_PanelRightFavorites_Tree: ctrlTree
						{
							idc=15005;
							idcSearch=15003;
							x="0";
							y="7 * (pixelH * pixelGrid * 0.50)";
							w="60 * (pixelW * pixelGrid * 0.50)";
							h="safeZoneH - (28 + 21) * (pixelH * pixelGrid * 0.50)";
							borderSize=0;
							colorBorder[]={0,0,0,0};
							multiselectEnabled=1;
						};
						class ENH_PanelRightFavorites_Delete: ctrlButton
						{
							idc=15006;
							text="$STR_DISP_DELETE";
							x="(pixelW * pixelGrid * 0.50)";
							y="safeZoneH - (28 + 6) * (pixelH * pixelGrid * 0.50)";
							w="58 * (pixelW * pixelGrid * 0.50)";
							h="(5 * (pixelH * pixelGrid * 0.50))";
						};
					};
				};
				class TabRightSections: ctrlToolbox
				{
					columns=3;
					strings[]=
					{
						"$STR_3DEN_DISPLAY3DEN_ASSETS",
						"$STR_3DEN_DISPLAY3DEN_HISTORY",
						"$STR_3DEN_FAVORITE_TEXTPLURAL"
					};
					values[]={1039,1040,15000};
				};
			};
		};
		class PanelLeft: ctrlControlsGroupNoScrollbars
		{
			class Controls
			{
				class PanelLeftEdit: ctrlControlsGroupNoScrollbars
				{
					class Controls
					{
						class EditPanel: ctrlControlsGroupNoScrollbars
						{
							class Controls
							{
								class Delete;
								class ENH_DeleteEmptyLayers: Delete
								{
									idc=-1;
									text="\x\enh\addons\main\data\trash_ca.paa";
									x="7 * (pixelW * pixelGrid * 0.50)";
									tooltip="$STR_ENH_MAIN_TOOLS_DELETEEMPTYLAYERS";
									onButtonClick="call ENH_fnc_deleteEmptyLayers";
								};
								class ENH_SelectLayers: Delete
								{
									idc=-1;
									text="\x\enh\addons\main\data\selectAllLayers_ca.paa";
									x="29 * (pixelW * pixelGrid * 0.50)";
									tooltip="$STR_ENH_MAIN_TOOLS_SELECTALLLAYERS";
									onButtonClick="set3DENSelected (all3DENEntities # 6)";
								};
							};
						};
					};
				};
				class PanelLeftLocations: ctrlControlsGroupNoScrollbars
				{
					class Controls
					{
						class Locations: ctrlTree
						{
							idc=820;
							x="0";
							y="7 * (pixelH * pixelGrid * 0.50)";
							w="60 * (pixelW * pixelGrid * 0.50)";
							h="safeZoneH - 35 * (pixelH * pixelGrid * 0.50)";
							onTreeDblClick="['select', _this] call bis_fnc_3DENListLocations; ['view'] call ENH_fnc_locationList_enhanced";
							disableKeyboardSearch=1;
							expandOnDoubleclick=0;
							idcSearch=800;
						};
						class EditPanel: ctrlControlsGroupNoScrollbars
						{
							y="safeZoneH - 29 * (pixelH * pixelGrid * 0.50)";
							w="60 * (pixelW * pixelGrid * 0.50)";
							h="7 * (pixelH * pixelGrid * 0.50)";
							class Controls
							{
								class EditPanelBackground: ctrlStatic
								{
									w="60 * (pixelW * pixelGrid * 0.50)";
									h="7 * (pixelH * pixelGrid * 0.50)";
									colorBackground[]={0.2,0.2,0.2,1};
								};
								class Delete: ctrlButtonToolbar
								{
									idc=101;
									text="\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
									x="(pixelW * pixelGrid * 0.50)";
									y="(pixelH * pixelGrid * 0.50)";
									w="5 * (pixelW * pixelGrid * 0.50)";
									h="5 * (pixelH * pixelGrid * 0.50)";
									tooltip="$STR_DISP_DELETE";
									onButtonClick="['delete'] call ENH_fnc_locationList_enhanced";
								};
								class Add: Delete
								{
									idc=102;
									text="\x\enh\addons\main\data\plus_ca.paa";
									x="54 * (pixelW * pixelGrid * 0.50)";
									tooltip="$STR_A3_CFGVEHICLES_MODULECURATORADDEDITABLEOBJECTS_ARGUMENTS_ADDCREW_VALUES_YES";
									onButtonClick="['add'] spawn ENH_fnc_locationList_enhanced";
								};
							};
						};
					};
				};
			};
		};
	};
};
class CfgFontFamilies
{
	class ENH_BlankFont
	{
		fonts[]=
		{
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro9",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light6"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro10",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light7"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro11",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light8"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro12",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light9"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro13",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light10"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro14",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light11"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro15",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light12"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro16",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light13"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro17",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light14"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro18",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light15"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro19",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light16"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro20",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light17"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro21",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light18"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro22",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light19"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro23",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light20"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro24",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light21"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro25",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light22"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro26",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light23"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro27",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light24"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro28",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light25"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro29",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light26"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro30",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light27"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro31",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light28"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro34",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light29"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro35",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light30"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro37",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light31"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro46",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light34"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro46",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light35"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro46",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light37"
			},
			
			{
				"\x\enh\addons\main\data\fonts\EtelkaMonospacePro\EtelkaMonospacePro46",
				"\x\enh\addons\main\data\fonts\NotoSansCJK-Light\NotoSansCJK-Light46"
			}
		};
		credit="Leopard20 ;)";
	};
};
class CfgCommands
{
	allowedHTMLLoadURIs[]+=
	{
		"https://github.com/R3voA3/3den-Enhanced/*",
		"https://steamcommunity.com/sharedfiles/*"
	};
};
class ENH_3DENRadio
{
	idd=60000;
	onLoad="_this spawn ENH_fnc_3DENRadio_onLoad";
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Header: ctrlStaticTitle
		{
			text="3DEN Radio";
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 4 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="7 * (pixelH * pixelGrid * 0.50)";
		};
		class BackgroundFilter: Background
		{
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			colorBackground[]={0,0,0,1};
		};
		class CurrentSongText: ctrlStaticFooter
		{
			text="$STR_ENH_MAIN_3DENRADIO_SONG";
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 4 * (5 * (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			w="10 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class CurrentSong: CurrentSongText
		{
			idc=700;
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50) + 10 * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) - 10) * (pixelW * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class Filter: ctrlListNBox
		{
			idc=200;
			idcLeft=-1;
			idcRight=-1;
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Songlist: Filter
		{
			idc=100;
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50))";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 7 * (5 * (pixelH * pixelGrid * 0.50))";
			disableOverflow=1;
		};
		class ToggleRadio: ctrlButtonPictureKeepAspect
		{
			idc=300;
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class VolumeIcon: ctrlStaticPictureKeepAspect
		{
			text="\a3\Modules_F_Curator\Data\portraitSound_ca.paa";
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50) + 7 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Volume: ctrlXSliderH
		{
			idc=400;
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50) + 13 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="30 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			sliderRange[]={0,1.5};
		};
		class Help: VolumeIcon
		{
			text="\A3\ui_f\data\igui\cfg\simpleTasks\types\unknown_ca.paa";
			tooltip="$STR_ENH_MAIN_3DENRADIO_HELP_DESCRIPTION";
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50) + 44 * (pixelW * pixelGrid * 0.50)";
			tooltipMaxWidth=1;
		};
		class SearchEdit: ctrlEdit
		{
			idc=600;
			tooltip=@"format [""%1+%2"", toUpper localize ""STR_DIK_CONTROL"", ""F""]";
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50) + 50 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="30 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class ButtonSearch: ctrlButtonSearch
		{
			idc=1000;
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50) + 80 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Group: ctrlControlsGroup
		{
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50) + 86 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="80 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			class Controls
			{
				class Time: ctrlStatic
				{
					idc=900;
					text="00:00";
					x="24 * (pixelW * pixelGrid * 0.50)";
					y="0";
					w="10 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class Position: ctrlXSliderH
				{
					idc=800;
					x="0 * (pixelW * pixelGrid * 0.50)";
					y="0";
					w="58 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					sliderRange[]={0,1.5};
					colorActive[]={1,1,1,0.60000002};
				};
			};
		};
		class Close: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) - 26 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_AttributeSearch
{
	idd=800;
	onLoad="_this call ENH_fnc_attributeSearch_onLoad";
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_SEARCHATTRIBUTES_HEADER";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
		class Counter: ctrlStatic
		{
			idc=610;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 46 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
	class Controls
	{
		class TreeView: ctrlTree
		{
			idc=640;
			idcSearch=620;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 5 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			borderSize=0;
			colorBorder[]={0,0,0,0};
			colorBackground[]={0.1,0.1,0.1,1};
		};
		class Search: ctrlEdit
		{
			idc=620;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="40 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class ButtonSearch: ctrlButtonSearch
		{
			idc=630;
			TEXT="\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 41 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class EditAttributes: ctrlButton
		{
			idc=650;
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * 140 * (pixelW * pixelGrid * 0.50) - (36 + 26) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="35 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class ButtonClose: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * 140 * (pixelW * pixelGrid * 0.50) - 26 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_BriefingEditor
{
	idd=-1;
	onLoad="[_this#0, 'onLoad'] call ENH_fnc_BriefingEditor";
	onUnload="[_this#0, 'onUnload'] call ENH_fnc_BriefingEditor";
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_BRIEFINGEDITOR";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 4 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class FirstParamText: ctrlStatic
		{
			idc=200;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (25 + 40 + 1) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 3 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class SecondParamText: FirstParamText
		{
			idc=220;
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 4 * (5 * (pixelH * pixelGrid * 0.50)) + 3 * (pixelH * pixelGrid * 0.50)";
		};
		class ThirdParamText: FirstParamText
		{
			idc=240;
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 5 * (5 * (pixelH * pixelGrid * 0.50)) + 4 * (pixelH * pixelGrid * 0.50)";
		};
		class Subject: ctrlStatic
		{
			text="$STR_ENH_MAIN_BRIEFINGEDITOR_SUBJECT";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50)) + 1 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Title: Subject
		{
			text="$STR_ENH_MAIN_BRIEFINGEDITOR_BRIEFINGTITLE";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 3 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
		class Templates: Subject
		{
			text="$STR_ENH_MAIN_BRIEFINGEDITOR_TEMPLATES";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (25 + 40 + 1) * (pixelW * pixelGrid * 0.50)";
		};
		class ShowTitle: Subject
		{
			text="$STR_ENH_MAIN_BRIEFINGEDITOR_SHOWTITLE";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 4 * (5 * (pixelH * pixelGrid * 0.50)) + 3 * (pixelH * pixelGrid * 0.50)";
		};
		class BriefingText: Subject
		{
			text="$STR_ENH_MAIN_BRIEFINGEDITOR_TEXT";
			tooltip="$STR_ENH_MAIN_BRIEFINGEDITOR_TEXT_TOOLTIP";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 5 * (5 * (pixelH * pixelGrid * 0.50)) + 4 * (pixelH * pixelGrid * 0.50)";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class MenuStrip: ctrlMenuStrip
		{
			idc=-1;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			class Items
			{
				items[]=
				{
					"FolderExport",
					"FolderFormatting",
					"FolderTemplates",
					"FolderHelp"
				};
				class FolderExport
				{
					text="Export";
					items[]=
					{
						"Export"
					};
				};
				class FolderFormatting
				{
					text="Formatting";
					items[]=
					{
						"Linebreak",
						"Marker",
						"Image",
						"Font",
						"Separator",
						"Execute",
						"ExecuteClose",
						"Separator",
						"AddTAG"
					};
				};
				class FolderTemplates
				{
					text="$STR_ENH_MAIN_BRIEFINGEDITOR_TEMPLATES";
					items[]=
					{
						"CreateTemplate",
						"Separator",
						"ApplyTemplate",
						"DeleteTemplate"
					};
				};
				class FolderHelp
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_HELP_TEXT";
					items[]=
					{
						"3denEnhancedDocumentation",
						"BikiDocumentation"
					};
				};
				class Export
				{
					text="$STR_ENH_MAIN_BRIEFINGEDITOR_EXPORT";
					action="[nil, 'export'] call ENH_fnc_BriefingEditor";
					shortcuts[]={530};
					opensNewWindow=1;
				};
				class Linebreak
				{
					text="Linebreak";
					action="[nil, 'switchTAG', 'Linebreak'] call ENH_fnc_BriefingEditor";
					shortcuts[]={514};
				};
				class Marker
				{
					text="Marker";
					action="[nil, 'switchTAG', 'Marker'] call ENH_fnc_BriefingEditor";
					shortcuts[]={515};
				};
				class Image
				{
					text="Image";
					action="[nil, 'switchTAG', 'Image'] call ENH_fnc_BriefingEditor";
					shortcuts[]={516};
				};
				class Font
				{
					text="Font";
					action="[nil, 'switchTAG', 'Font'] call ENH_fnc_BriefingEditor";
					shortcuts[]={517};
				};
				class Execute
				{
					text="Execute";
					action="[nil, 'switchTAG', 'Execute'] call ENH_fnc_BriefingEditor";
					shortcuts[]={518};
				};
				class ExecuteClose
				{
					text="Execute Close";
					action="[nil, 'switchTAG', 'ExecuteClose'] call ENH_fnc_BriefingEditor";
					shortcuts[]={519};
				};
				class AddTAG
				{
					text="$STR_ENH_MAIN_BRIEFINGEDITOR_ADDTAG";
					action="[nil, 'addTAG'] call ENH_fnc_BriefingEditor";
					shortcuts[]={540};
				};
				class ApplyTemplate
				{
					text="$STR_ENH_MAIN_BRIEFINGEDITOR_APPLYTEMPLATE";
					action="[nil, 'handleTemplates', 'apply'] call ENH_fnc_BriefingEditor";
				};
				class CreateTemplate
				{
					text="$STR_ENH_MAIN_BRIEFINGEDITOR_CREATETEMPLATE";
					action="[nil, 'handleTemplates', 'create'] call ENH_fnc_BriefingEditor";
				};
				class DeleteTemplate
				{
					text="$STR_ENH_MAIN_BRIEFINGEDITOR_DELETETEMPLATE";
					action="[nil, 'handleTemplates', 'delete'] call ENH_fnc_BriefingEditor";
				};
				class 3denEnhancedDocumentation
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#briefing-editor";
					opensNewWindow=1;
				};
				class BikiDocumentation: 3denEnhancedDocumentation
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPBIKI_TEXT";
					weblink="https://community.bistudio.com/wiki/Arma_3:_Briefing";
				};
				class Default
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_DEFAULT_TEXT";
					enable=0;
				};
				class Separator
				{
					value=0;
				};
			};
		};
		class SubjectValue: ctrlEdit
		{
			idc=20;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 25 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50)) + 6 * (pixelH * pixelGrid * 0.50)";
			w="40 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class TitleValue: SubjectValue
		{
			idc=30;
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 3 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
		class ShowTitleValue: ctrlToolbox
		{
			idc=40;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 25 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 4 * (5 * (pixelH * pixelGrid * 0.50)) + 3 * (pixelH * pixelGrid * 0.50)";
			w="40 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			rows=1;
			columns=2;
			strings[]=
			{
				"$STR_ENH_MAIN_YES",
				"$STR_ENH_MAIN_NO"
			};
			values[]={0,1};
		};
		class Group: ctrlControlsGroup
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * (140 - 2) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 6 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * (pixelH * pixelGrid * 0.50)";
			w="(140 - 2) * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 10 * (5 * (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			class Controls
			{
				class BriefingTextValue: ctrlEditMulti
				{
					idc=10;
					w="(140 - 2) * (pixelW * pixelGrid * 0.50)";
					h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 10 * (5 * (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
					font="ENH_BlankFont";
					colorBackground[]={0,0,0,0};
					colorText[]={1,1,1,1};
					forceDrawCaret=1;
					colorSelection[]=
					{
						"profilenamespace getvariable ['GUI_BCG_RGB_R', 0.13]",
						"profilenamespace getvariable ['GUI_BCG_RGB_G', 0.54]",
						"profilenamespace getvariable ['GUI_BCG_RGB_B', 0.21]",
						0.30000001
					};
				};
				class BriefingTextSyntaxHighligthingValue: ctrlStructuredText
				{
					idc=50;
					w="(140 - 2) * (pixelW * pixelGrid * 0.50)";
					h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 10 * (5 * (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
					colorBackground[]={0.1,0.1,0.1,1};
					class Attributes
					{
						font="EtelkaMonospacePro";
						align="left";
					};
				};
			};
		};
		class FirstParamValue: ctrlEdit
		{
			idc=210;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (25 + 40 + 1 + 25 + 1) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 3 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
			w="47 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class SecondParamValue: FirstParamValue
		{
			idc=230;
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 4 * (5 * (pixelH * pixelGrid * 0.50)) + 3 * (pixelH * pixelGrid * 0.50)";
		};
		class ThirdParamValue: FirstParamValue
		{
			idc=250;
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 5 * (5 * (pixelH * pixelGrid * 0.50)) + 4 * (pixelH * pixelGrid * 0.50)";
		};
		class MarkerList: ctrlCombo
		{
			idc=60;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (25 + 40 + 1 + 25 + 1) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 3 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
			w="47 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class ColorList: MarkerList
		{
			idc=100;
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 4 * (5 * (pixelH * pixelGrid * 0.50)) + 3 * (pixelH * pixelGrid * 0.50)";
		};
		class FontsList: MarkerList
		{
			idc=70;
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 5 * (5 * (pixelH * pixelGrid * 0.50)) + 4 * (pixelH * pixelGrid * 0.50)";
		};
		class TemplateList: MarkerList
		{
			idc=80;
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50)) + 1 * (pixelH * pixelGrid * 0.50)";
		};
		class Close: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * 140 * (pixelW * pixelGrid * 0.50) - 26 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_CfgSentencesBrowser
{
	idd=-1;
	onLoad="_this call ENH_fnc_CFGS_onLoad";
	onUnload="profileNamespace setVariable ['ENH_CFGS_Favorites', ENH_CFGS_Favorites];";
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_TOOLS_CFGSENTENCESBROWSER";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
		class Count: ctrlStatic
		{
			idc=3000;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 140 * (pixelW * pixelGrid * 0.50) - 11 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="11 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
	class Controls
	{
		class Pages: ctrlToolbox
		{
			idc=1000;
			columns=2;
			rows=1;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			strings[]=
			{
				"$STR_A3_WL_PARAM19_TITLE",
				"$STR_3DEN_FAVORITE_TEXTPLURAL"
			};
			colorSelectedBg[]={0.2,0.2,0.2,1};
			onToolBoxSelChanged="_this call ENH_fnc_CFGS_changePage";
		};
		class List: ctrlTree
		{
			idc=2000;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 11 * (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 6 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			colorBorder[]={0,0,0,0};
			idcSearch=10000;
			onTreeDblClick="'play' call ENH_fnc_CFGS_playOrCopy";
		};
		class ListFavorites: List
		{
			idc=4000;
			onTreeDblClick="'play' call ENH_fnc_CFGS_playOrCopy";
		};
		class Search: ctrlEdit
		{
			idc=10000;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 45 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class ButtonSearch: ctrlButtonSearch
		{
			idc=6000;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 70 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Filter: ctrlCombo
		{
			idc=5000;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 76 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="22 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onLBselChanged="_this call ENH_fnc_CFGS_changeFilter";
			class Items
			{
				class All
				{
					text="All";
					data="ALL";
					default=1;
				};
				class A
				{
					text="Episode A";
					data="A_";
				};
				class B
				{
					text="Episode B";
					data="B_";
				};
				class C
				{
					text="Episode C";
					data="C_";
				};
				class Boot
				{
					text="Bootcamp";
					data="BOOT_";
				};
				class Apex
				{
					text="Apex Protocol";
					data="EXP_";
				};
				class Faction
				{
					text="Factions";
					data="FACTION_";
				};
				class Orange
				{
					text="Laws of War";
					data="ORANGE_";
				};
				class Showcases
				{
					text="Showcases";
					data="SHOWCASE_";
				};
				class Tanks
				{
					text="Tanks";
					data="TA_";
				};
				class TacOps
				{
					text="Tac Ops";
					data="TO_";
				};
			};
		};
		class Play: ctrlButtonPictureKeepAspect
		{
			text="\a3\3DEN\Data\Attributes\ComboPreview\play_ca.paa";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="'play' call ENH_fnc_CFGS_playOrCopy";
		};
		class Copy: ctrlButton
		{
			text="$STR_3DEN_DISPLAY3DEN_MENUBAR_ENTITYCOPY_TEXT";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 7 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="'copy' call ENH_fnc_CFGS_playOrCopy";
		};
		class HandleFavorite: ctrlButtonPictureKeepAspect
		{
			text="\a3\3den\data\displays\display3den\panelright\modefavorites_ca.paa";
			tooltip="$STR_ENH_MAIN_CFGS_HANDLEFAVORITES_TOOLTIP";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 33 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="'' call ENH_fnc_CFGS_handleFavorites";
		};
		class Biki: ENH_ctrlButtonHelp
		{
			url="https://community.bistudio.com/wiki/Conversations";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 39 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
		};
		class Close: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * 140 * (pixelW * pixelGrid * 0.50) - 26 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_ESE
{
	idd=-1;
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_TOOLS_ESE";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 4 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class BackgroundInventoryItemsList: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 2/4) * (pixelW * pixelGrid * 0.50) + 2 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 3 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 7 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			colorBackground[]={0,0,0,0.30000001};
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
		class AvailableItems: ctrlStatic
		{
			idc=-1;
			text="$STR_ENH_MAIN_ESE_AVAILABLEITEMS";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			font="RobotoCondensedBold";
			sizeEx="4.86 * ((1 / (getResolution select 3)) * pixelGrid * 0.5)";
			style=2;
		};
		class CompatibleItems: AvailableItems
		{
			text="$STR_ENH_MAIN_ESE_COMPATIBLE_ITEMS";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50) + 2 * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50) - (pixelW * pixelGrid * 0.50)";
		};
		class InventoryItems: AvailableItems
		{
			text="$STR_ENH_MAIN_ESE_ITEMSININVENTORY";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 2/4) * (pixelW * pixelGrid * 0.50) + 2 * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
		};
		class Templates: AvailableItems
		{
			text="$STR_ENH_MAIN_ESE_TEMPLATES";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 3/4) * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class MenuStrip: ctrlMenuStrip
		{
			idc=4000;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			class Items
			{
				items[]=
				{
					"FolderExport",
					"FolderInventory",
					"FolderFilter",
					"FolderTemplates",
					"FolderHelp"
				};
				class FolderExport
				{
					text="Export";
					items[]=
					{
						"ExportToSQF",
						"ExportToACEArsenal",
						"ExportArsenal"
					};
				};
				class FolderInventory
				{
					text="Inventory";
					items[]=
					{
						"IsVirtual",
						"Separator",
						"ResetInventory",
						"Separator",
						"AddOne",
						"RemoveOne",
						"RemoveAll",
						"Separator",
						"Arsenal",
						"Separator",
						"SortbyName",
						"SortbyClass",
						"SortbyCount",
						"SortbyMod",
						"SortbyType"
					};
				};
				class FolderFilter
				{
					text="Filter";
					items[]=
					{
						"ARs",
						"MGs",
						"Snipers",
						"Shotguns",
						"SMGs",
						"Launchers",
						"Pistols",
						"Separator",
						"Grenades",
						"Magazines",
						"Explosives",
						"InventoryItems",
						"Separator",
						"Bipods",
						"Supressors",
						"Pointers",
						"Scopes",
						"Separator",
						"Uniforms",
						"Vests",
						"Backpacks",
						"Headgear",
						"Goggles",
						"NVGs"
					};
				};
				class FolderHelp
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_HELP_TEXT";
					items[]=
					{
						"Documentation"
					};
				};
				class ExportToSQF
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_MISSIONEXPORTSQF_TEXT";
					action="'sqf' call ENH_fnc_ESE_export";
					opensNewWindow=1;
				};
				class ExportToACEArsenal: ExportToSQF
				{
					text="$STR_ENH_MAIN_ESE_EXPORTTOSACEARSENAL";
					action="'ace' call ENH_fnc_ESE_export";
				};
				class ExportArsenal: ExportToSQF
				{
					text="$STR_ENH_MAIN_ESE_EXPORTTOARSENAL";
					action="'arsenal' call ENH_fnc_ESE_export";
				};
				class FolderTemplates
				{
					text="$STR_ENH_MAIN_ESE_TEMPLATES";
					items[]=
					{
						"CreateTemplate",
						"DeleteTemplate",
						"Separator",
						"PreviewTemplate"
					};
				};
				class CreateTemplate
				{
					text="$STR_ENH_MAIN_ESE_CREATETEMPLATE";
					action="'create' call ENH_fnc_ESE_handleTemplates";
					opensNewWindow=1;
				};
				class DeleteTemplate
				{
					text="$STR_3DEN_DISPLAY3DEN_ENTITYMENU_DELETE_TEXT";
					action="'delete' call ENH_fnc_ESE_handleTemplates";
					shortcuts[]={211};
				};
				class PreviewTemplate
				{
					text="$STR_3DEN_TUTORIALS_SCENARIO_SECTIONS_PREVIEW_TEXT";
					action="'preview' call ENH_fnc_ESE_handleTemplates";
				};
				class Documentation
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#equipment-storage-editor";
					opensNewWindow=1;
				};
				class IsVirtual
				{
					text="$STR_3DEN_ATTRIBUTES_AMMOBOX_TYPE_VIRTUAL";
					picture="\x\enh\addons\main\data\infinity_ca.paa";
					action="-1 call ENH_fnc_ESE_toggleVirtual";
				};
				class ResetInventory
				{
					text="$STR_3DEN_DISPLAY3DEN_ENTITYMENU_ARSENALRESET_TEXT";
					picture="\A3\ui_f\data\igui\rsctitles\mpprogress\respawn_ca.paa";
					action="call ENH_fnc_ESE_resetStorage";
				};
				class AddOne
				{
					text="+1";
					picture="\x\enh\addons\main\data\plus_ca.paa";
					action="1 call ENH_fnc_ESE_addItem";
					shortcuts[]={205};
				};
				class RemoveOne
				{
					text="-1";
					picture="\x\enh\addons\main\data\minus_ca.paa";
					action="1 call ENH_fnc_ESE_removeItem";
					shortcuts[]={203};
				};
				class RemoveAll
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_DEFAULT_TEXT";
					picture="\a3\3den\data\displays\display3den\panelleft\entitylist_delete_ca.paa";
					action="call ENH_fnc_ESE_clearInventory";
					shortcuts[]={2763};
				};
				class Arsenal
				{
					text="$STR_A3_RSCDISPLAYMAIN_BUTTONVIRTUALARSENAL";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\spacearsenal_ca.paa";
					action="call ENH_fnc_ESE_fullArsenal";
					shortcuts[]={2590};
				};
				class SortbyName
				{
					text="$STR_ENH_MAIN_ESE_SORTBYNAME";
					picture="\A3\ui_f\data\igui\cfg\simpleTasks\letters\A_ca.paa";
					action="'name' call ENH_fnc_ESE_sort";
					shortcuts[]={2};
				};
				class SortbyClass
				{
					text="$STR_ENH_MAIN_ESE_SORTBYCLASS";
					action="'class' call ENH_fnc_ESE_sort";
					shortcuts[]={3};
				};
				class SortbyCount
				{
					text="$STR_ENH_MAIN_ESE_SORTBYCOUNT";
					action="'count' call ENH_fnc_ESE_sort";
					shortcuts[]={4};
				};
				class SortbyMod
				{
					text="$STR_ENH_MAIN_ESE_SORTBYMOD";
					picture="\a3\ui_f\data\logos\arma3_bundle_logo_ca.paa";
					action="'mod' call ENH_fnc_ESE_sort";
					shortcuts[]={5};
				};
				class SortbyType
				{
					text="$STR_ENH_MAIN_ESE_SORTBYTYPE";
					action="'type' call ENH_fnc_ESE_sort";
					shortcuts[]={6};
				};
				class ImportFromClipboard
				{
					text="$STR_ENH_MAIN_ESE_IMPORTFROMCLIPBOARD";
					action="[false, [], true] call ENH_fnc_ESE_loadAttributeValue";
					picture="\a3\ui_f\data\igui\cfg\actions\loadvehicle_ca.paa";
					shortcuts[]={7};
				};
				class ARs
				{
					text="$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_ASSAULTRIFLES0";
					picture="\x\enh\addons\main\data\weapons\assaultRifle_ca.paa";
					action="_this call ENH_fnc_ESE_changeFilter";
					data="AssaultRifle";
				};
				class MGs: ARs
				{
					text="$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_MACHINEGUNS0";
					picture="\x\enh\addons\main\data\weapons\machineGun_ca.paa";
					data="MachineGun";
				};
				class Snipers: ARs
				{
					text="$STR_A3_SNIPER1";
					picture="\x\enh\addons\main\data\weapons\marksmanRifle_ca.paa";
					data="SniperRifle";
				};
				class Shotguns: ARs
				{
					text="$STR_ENH_MAIN_ESE_SHOTGUNS";
					picture="\x\enh\addons\main\data\weapons\shotgun_ca.paa";
					data="Shotgun";
				};
				class SMGs: ARs
				{
					text="$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_SUBMACHINEGUNS0";
					picture="\x\enh\addons\main\data\weapons\subMachineGun_ca.paa";
					data="SubmachineGun";
				};
				class Launchers: ARs
				{
					text="$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_LAUNCHERS0";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\secondaryweapon_ca.paa";
					data="RocketLauncher";
				};
				class Pistols: ARs
				{
					text="$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_PISTOLS0";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\handgun_ca.paa";
					data="Handgun";
				};
				class Grenades: ARs
				{
					text="$STR_A3_GRENADES1";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\cargothrow_ca.paa";
					data="Grenade";
				};
				class Magazines: ARs
				{
					text="$STR_GEAR_MAGAZINES";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\cargomagall_ca.paa";
					data="Magazine";
				};
				class Explosives: ARs
				{
					text="$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_EXPLOSIVES0";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\cargoput_ca.paa";
					data="Mine";
				};
				class Bipods: ARs
				{
					text="$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_BOTTOMSLOT0";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\itembipod_ca.paa";
					data="AccessoryBipod";
				};
				class Supressors: ARs
				{
					text="$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_FRONTSLOT0";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\itemmuzzle_ca.paa";
					data="AccessoryMuzzle";
				};
				class Pointers: ARs
				{
					text="$STR_A3_POINTERS1";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\itemacc_ca.paa";
					data="AccessoryPointer";
				};
				class Scopes: ARs
				{
					text="$STR_A3_SCOPES1";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\itemoptic_ca.paa";
					data="AccessorySights";
				};
				class Uniforms: ARs
				{
					text="$STR_A3_CFGVEHICLECLASSES_UNIFORMS0";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\uniform_ca.paa";
					data="Uniform";
				};
				class Vests: ARs
				{
					text="$STR_A3_CFGEDITORSUBCATEGORIES_EDSUBCAT_VESTS0";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\vest_ca.paa";
					data="Vest";
				};
				class Backpacks: ARs
				{
					text="$STR_A3_CFGVEHICLECLASSES_BACKPACKS0";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\backpack_ca.paa";
					data="Backpack";
				};
				class Headgear: ARs
				{
					text="$STR_A3_RSCDISPLAYARSENAL_TAB_HEADGEAR";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\headgear_ca.paa";
					data="Headgear";
				};
				class Goggles: ARs
				{
					text="$STR_A3_RSCDISPLAYARSENAL_TAB_GOGGLES";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\goggles_ca.paa";
					data="Glasses";
				};
				class NVGs: ARs
				{
					text="$STR_A3_RSCDISPLAYARSENAL_TAB_NVGS";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\nvgs_ca.paa";
					data="NVGoggles";
				};
				class ImportToFilter
				{
					text="$STR_ENH_MAIN_ESE_IMPORTFROMCLIPBOARD";
					picture="\a3\ui_f\data\igui\cfg\actions\loadvehicle_ca.paa";
					action="[] call ENH_fnc_ESE_importToFilter";
				};
				class InventoryItems: ARs
				{
					text="$STR_A3_CFGVEHICLECLASSES_ITEMS0";
					picture="\a3\ui_f\data\gui\rsc\rscdisplayarsenal\watch_ca.paa";
					data="Item";
				};
				class Default
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_DEFAULT_TEXT";
					enable=0;
				};
				class Separator
				{
					value=0;
				};
			};
		};
		class AvailableItemsList: ctrlListbox
		{
			idc=2200;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 3 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 7 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			colorBackground[]={0,0,0,0.30000001};
		};
		class CompatibleItemsList: AvailableItemsList
		{
			idc=4100;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50) + 2 * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50) - (pixelW * pixelGrid * 0.50)";
		};
		class InventoryItemsList: ctrlListNBox
		{
			idc=2300;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 2/4) * (pixelW * pixelGrid * 0.50) + 2 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 3 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 7 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			columns[]={0,0.12,0.80000001,0.88};
			disableOverflow=1;
		};
		class TemplatesList: AvailableItemsList
		{
			idc=4200;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 3/4) * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
		};
		class FilterSearch: ctrlCombo
		{
			idc=3300;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onLBSelChanged="_this call ENH_fnc_ESE_onModFilterChanged";
		};
		class Search: ctrlEdit
		{
			idc=3400;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 6 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="40 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onKeyUp="_this call ENH_fnc_ESE_search";
		};
		class ButtonSearch: ctrlButtonSearch
		{
			idc=3500;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 46 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="_this call ENH_fnc_ESE_resetSearch";
		};
		class Save: ctrlButton
		{
			idc=3900;
			text="$STR_DISP_INT_SAVE";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50) + ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) - 47 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="22 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="[] call ENH_fnc_ESE_applyAttribute";
		};
		class Close: ctrlButtonClose
		{
			idc=-1;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50) + ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) - 24 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="22 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="0 spawn ENH_fnc_ESE_close";
		};
	};
};
class ENH_ExportGUIDefines
{
	idd=14000;
	onLoad="";
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="53 * (pixelW * pixelGrid * 0.50)";
			h="21 * (pixelH * pixelGrid * 0.50)";
		};
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="53 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 19 * (pixelH * pixelGrid * 0.50)";
			w="53 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class Target: ctrlStatic
		{
			text="$STR_WATCH_TARGET";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 6 * (pixelH * pixelGrid * 0.50)";
			w="15 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class TargetValue: ctrlCombo
		{
			idc=10;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50) + 12 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 6 * (pixelH * pixelGrid * 0.50)";
			w="(53 - 13) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			class Items
			{
				class Mod
				{
					text="$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_ADDON";
					tooltip="$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_ADDON_TOOLTIP";
					default=1;
				};
				class Scenario
				{
					text="$STR_A3_CFGUIGRIDS_IGUI_VARIABLES_GRID_MISSION_0";
					tooltip="$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_SCENARIO_TOOLTIP";
				};
			};
		};
		class Types: Target
		{
			text="$STR_A3_TO_BASICCIVILIANPRESENCE12";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 13 * (pixelH * pixelGrid * 0.50)";
		};
		class TypesValue: TargetValue
		{
			idc=20;
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 13 * (pixelH * pixelGrid * 0.50)";
			class Items
			{
				class Classic
				{
					text="$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_CLASSIC";
					tooltip="$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_CLASSIC_TOOLTIP";
					data="classic";
					default=1;
				};
				class Eden
				{
					text="$STR_A3_CFGMODS_APEX_FEATURE_EDEN_NAME";
					tooltip="$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_EDEN_TOOLTIP";
					data="3DEN";
				};
				class All
				{
					text="$STR_GEAR_ALL";
					tooltip="$STR_ENH_MAIN_TOOLS_EXPORTGUIBASECLASSES_ALL_TOOLTIP";
					data="";
				};
			};
		};
		class Cancel: ctrlButtonCancel
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50) + (53 - 26) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 20 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Ok: ctrlButtonOK
		{
			idc=-1;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50) + (53 - 52) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 20 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="private _display = ctrlParent (_this # 0); [lbCurSel (_display displayCtrl 10), lbCurSel (_display displayCtrl 20)] call ENH_fnc_exportGUIDefines";
		};
	};
};
class ENH_FunctionsViewer
{
	idd=-1;
	onLoad="_this call ENH_fnc_functionsViewer_onLoad";
	class ControlsBackground
	{
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_FUNCTIONSVIEWER_HEADER";
			x="safeZoneX";
			y="safeZoneY";
			w="safeZoneW";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			colorBackground[]=
			{
				"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
				"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
				1
			};
			moving=0;
		};
		class Background: ctrlStaticBackground
		{
			x="safeZoneX";
			y="safeZoneY + (5 * (pixelH * pixelGrid * 0.50))";
			w="safeZoneW";
			h="safeZoneH - (5 * (pixelH * pixelGrid * 0.50))";
		};
		class NumFunctions: ctrlStatic
		{
			idc=1405;
			tooltip="$STR_ENH_MAIN_FUNCTIONSVIEWER_NUMFUNCTIONS_TOOLTIP";
			x="safeZoneX + (pixelW * pixelGrid * 0.50)";
			y="safeZoneY + safeZoneH - 6 * (pixelH * pixelGrid * 0.50)";
			w="10 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Footer: ctrlStaticFooter
		{
			x="safeZoneX";
			y="safeZoneY + safeZoneH - 7 * (pixelH * pixelGrid * 0.50)";
			w="safeZoneW";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class MenuStrip: ctrlMenuStrip
		{
			idc=2200;
			x="safeZoneX";
			y="safeZoneY + (5 * (pixelH * pixelGrid * 0.50))";
			w="safeZoneW";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			class Items
			{
				items[]=
				{
					"FolderFilter",
					"FolderEdit",
					"FolderHelp"
				};
				class FolderFilter
				{
					text="Filter";
					items[]=
					{
						"ConfigFile",
						"MissionConfigFile",
						"CampaignConfigFile",
						"OtherFiles",
						"Separator",
						"Full",
						"Categories",
						"Functions",
						"Separator",
						"LoadFile",
						"PreprocessFile",
						"PreprocessFileLineNumbers"
					};
				};
				class FolderEdit
				{
					text="Edit";
					items[]=
					{
						"ToggleSidebar",
						"CollapseAll",
						"ExpandAll",
						"Separator",
						"RecompileSelected",
						"RecompileAll",
						"Separator",
						"Copy",
						"Separator",
						"LegacyFunctionsViewer"
					};
				};
				class FolderHelp
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_HELP_TEXT";
					items[]=
					{
						"Documentation",
						"ShowOnBiki"
					};
				};
				class ToggleSidebar
				{
					text="$STR_USRACT_CURATOR_COLLAPSE_PARENT";
					shortcuts[]={560};
					action="_this call ENH_fnc_functionsViewer_togglePanel";
					picture="\a3\ui_f_orange\data\igui\rscingameui\elevationarrow_ca.paa";
				};
				class CollapseAll
				{
					text="$STR_3DEN_CTRLBUTTONCOLLAPSEALL_TEXT";
					shortcuts[]={2248};
					action="tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
					picture="\a3\3den\data\displays\display3den\tree_expand_ca.paa";
				};
				class ExpandAll
				{
					text="$STR_3DEN_CTRLBUTTONEXPANDALL_TEXT";
					shortcuts[]={2256};
					action="tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
					picture="\a3\3den\data\displays\display3den\tree_collapse_ca.paa";
				};
				class RecompileSelected
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_RECOMPILESELETECTED_TEXT";
					tooltip="$STR_ENH_MAIN_FUNCTIONSVIEWER_RECOMPILESELETECTED_TOOLTIP";
					shortcuts[]={2067};
					picture="\a3\3den\data\displays\display3den\entitymenu\functions_ca.paa";
					action="[] call ENH_fnc_functionsViewer_recompileSelected";
				};
				class RecompileAll: RecompileSelected
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_RECOMPILEALL_TEXT";
					tooltip="$STR_ENH_MAIN_FUNCTIONSVIEWER_RECOMPILEALL_TOOLTIP";
					shortcuts[]={2078};
					action="[1] call BIS_fnc_recompile";
				};
				class Copy
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_COPYFUNCTION_TEXT";
					shortcuts[]={558};
					action="_this call ENH_fnc_functionsViewer_copy";
				};
				class LegacyFunctionsViewer
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_LEGACY";
					action="[ctrlParent (_this # 0)] call BIS_fnc_help";
				};
				class ConfigFile
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_GLOBALCONFIG";
					action="profileNamespace setVariable ['ENH_FunctionsViewer_ConfigIndex', 0]; profileNamespace setVariable ['ENH_FunctionsViewer_ShowOtherFiles', false]; call ENH_fnc_functionsViewer_fillCtrlTV";
					shortcuts[]={2};
				};
				class MissionConfigFile: ConfigFile
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_MISSIONCONFIG";
					shortcuts[]={3};
					action="profileNamespace setVariable ['ENH_FunctionsViewer_ConfigIndex', 1]; profileNamespace setVariable ['ENH_FunctionsViewer_ShowOtherFiles', false]; call ENH_fnc_functionsViewer_fillCtrlTV";
				};
				class CampaignConfigFile: ConfigFile
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_CAMPAIGNCONFIG";
					shortcuts[]={4};
					action="profileNamespace setVariable ['ENH_FunctionsViewer_ConfigIndex', 2]; profileNamespace setVariable ['ENH_FunctionsViewer_ShowOtherFiles', false]; call ENH_fnc_functionsViewer_fillCtrlTV";
				};
				class OtherFiles
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_OTHERFILES";
					action="profileNamespace setVariable ['ENH_FunctionsViewer_ShowOtherFiles', true]; call ENH_fnc_functionsViewer_fillCtrlTV";
					shortcuts[]={5};
				};
				class Full
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_ADDONS";
					action="profileNamespace setVariable ['ENH_FunctionsViewer_ModeIndex', 0]; call ENH_fnc_functionsViewer_fillCtrlTV";
					shortcuts[]={2050};
				};
				class Categories
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_CATEGORIES";
					action="profileNamespace setVariable ['ENH_FunctionsViewer_ModeIndex', 1]; call ENH_fnc_functionsViewer_fillCtrlTV";
					shortcuts[]={2051};
				};
				class Functions
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_FUNCTIONS";
					action="profileNamespace setVariable ['ENH_FunctionsViewer_ModeIndex', 2]; call ENH_fnc_functionsViewer_fillCtrlTV";
					shortcuts[]={2052};
				};
				class LoadFile
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_LOADFILE";
					action="profileNamespace setVariable ['ENH_FunctionsViewer_LoadFileIndex', 0]; call ENH_fnc_functionsViewer_setUpMenuStrip; [] call ENH_fnc_functionsViewer_onTreeSelChanged";
					shortcuts[]={2562};
				};
				class PreprocessFile
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_PREPROCESSFILE";
					action="profileNamespace setVariable ['ENH_FunctionsViewer_LoadFileIndex', 1]; call ENH_fnc_functionsViewer_setUpMenuStrip; [] call ENH_fnc_functionsViewer_onTreeSelChanged";
					shortcuts[]={2563};
				};
				class PreprocessFileLineNumbers
				{
					text="$STR_ENH_MAIN_FUNCTIONSVIEWER_PREPROCESSFILEWITHLINES";
					action="profileNamespace setVariable ['ENH_FunctionsViewer_LoadFileIndex', 2]; call ENH_fnc_functionsViewer_setUpMenuStrip; [] call ENH_fnc_functionsViewer_onTreeSelChanged";
					shortcuts[]={2564};
				};
				class Documentation
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPDOC_TEXT";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					weblink="https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#functions-viewer";
					opensNewWindow=1;
				};
				class ShowOnBiki
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_HELPBIKI_TEXT";
					picture="\a3\3DEN\Data\Controls\ctrlMenu\link_ca.paa";
					opensNewWindow=1;
				};
				class Default
				{
					text="$STR_3DEN_DISPLAY3DEN_MENUBAR_DEFAULT_TEXT";
					enable=0;
				};
				class Separator
				{
					value=0;
				};
			};
		};
		class List: ctrlTree
		{
			idc=1500;
			idcSearch=1400;
			x="safeZoneX + (pixelW * pixelGrid * 0.50)";
			y="safeZoneY + 2 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="70 * (pixelW * pixelGrid * 0.50)";
			h="safeZoneH - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			colorLines[]={1,1,1,1};
			borderSize=0;
			colorBorder[]={0,0,0,0};
		};
		class Search: ctrlEdit
		{
			idc=1400;
			tooltip=@"format [""%1+%2"", toUpper localize ""STR_DIK_CONTROL"", ""F""]";
			x="safeZoneX + 12 * (pixelW * pixelGrid * 0.50)";
			y="safeZoneY + safeZoneH - 6 * (pixelH * pixelGrid * 0.50)";
			w="53 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class ButtonSearch: ctrlButtonSearch
		{
			idc=2300;
			x="safeZoneX + 65 * (pixelW * pixelGrid * 0.50)";
			y="safeZoneY + safeZoneH - 6 * (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Name: ctrlEdit
		{
			idc=1402;
			tooltip="$STR_ENH_MAIN_FUNCTIONSVIEWER_FUNCTIONNAME_TOOLTIP";
			canModify=0;
			x="safeZoneX + 72 * (pixelW * pixelGrid * 0.50)";
			y="safeZoneY + 2 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="70 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Path: Name
		{
			idc=1403;
			tooltip="$STR_ENH_MAIN_FUNCTIONSVIEWER_FUNCTIONPATH_TOOLTIP";
			x="safeZoneX + 143 * (pixelW * pixelGrid * 0.50)";
			w="safeZoneW - (143 + 1) * (pixelW * pixelGrid * 0.50)";
		};
		class SearchCode: ctrlEdit
		{
			idc=2000;
			tooltip=@"toUpper format [""%1+%2+%3"", localize ""STR_DIK_CONTROL"", localize ""STR_VK_SHIFT"", ""F""]";
			x="safeZoneX + 72 * (pixelW * pixelGrid * 0.50)";
			y="safeZoneY + safeZoneH - 6 * (pixelH * pixelGrid * 0.50)";
			w="40 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onKeyUp="_this call ENH_fnc_functionsViewer_searchKey";
		};
		class SearchText: ctrlStatic
		{
			idc=2100;
			x="safeZoneX + 113 * (pixelW * pixelGrid * 0.50)";
			y="safeZoneY + safeZoneH - 6 * (pixelH * pixelGrid * 0.50)";
			w="30 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class SearchButtonUp: ctrlButtonPictureKeepAspect
		{
			text="\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\arrow_up_ca.paa";
			x="safeZoneX + 135 * (pixelW * pixelGrid * 0.50)";
			y="safeZoneY + safeZoneH - 6 * (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="[_this # 0, -1] call ENH_fnc_FunctionsViewer_IncrementKey";
		};
		class SearchButtonDown: SearchButtonUp
		{
			text="\a3\ui_f\data\gui\rsc\rscdisplaymultiplayer\arrow_down_ca.paa";
			x="safeZoneX + 129 * (pixelW * pixelGrid * 0.50)";
			onButtonClick="[_this # 0, 1] call ENH_fnc_functionsViewer_incrementKey";
		};
		class Preview: ctrlControlsGroup
		{
			idc=5000;
			x="safeZoneX + 72 * (pixelW * pixelGrid * 0.50)";
			y="safeZoneY + 3 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
			w="safeZoneW - 73 * (pixelW * pixelGrid * 0.50)";
			h="safeZoneH - 4 * (5 * (pixelH * pixelGrid * 0.50)) - 4 * (pixelH * pixelGrid * 0.50)";
			class Controls
			{
				class Lines: ctrlStructuredText
				{
					idc=1404;
					canModify=0;
					x="0";
					y="0";
					w="0.070";
					h="2";
					font="EtelkaMonospacePro";
					shadow=0;
					colorBackground[]={0,0,0,0.5};
				};
				class Code: ctrlEditMulti
				{
					idc=1401;
					canModify=0;
					x="0.075";
					w="4";
					h="2";
					font="EtelkaMonospacePro";
					shadow=0;
					style=528;
				};
			};
		};
		class Close: ctrlButtonClose
		{
			x="safeZoneX + safeZoneW - 26 * (pixelW * pixelGrid * 0.50)";
			y="safeZoneY + safeZoneH - 6 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_Garrison: ctrlControlsGroupNoScrollbars
{
	idc=20100;
	onLoad="call ENH_fnc_garrison_onLoad";
	x="0.5 - 0.5 * 60 * (pixelW * pixelGrid * 0.50)";
	y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
	w="60 * (pixelW * pixelGrid * 0.50)";
	h="68 * (pixelH * pixelGrid * 0.50)";
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_GARRISON_HEADER";
			x="0";
			y="0";
			w="60 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="0";
			y="(5 * (pixelH * pixelGrid * 0.50))";
			w="60 * (pixelW * pixelGrid * 0.50)";
			h="68 * (pixelH * pixelGrid * 0.50) - (5 * (pixelH * pixelGrid * 0.50))";
		};
		class BlacklistToggle: ctrlToolbox
		{
			idc=20000;
			x="(pixelW * pixelGrid * 0.50)";
			y="(5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="60 * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			rows=1;
			columns=2;
			strings[]=
			{
				"$STR_ENH_MAIN_GARRISON_BLACKLIST",
				"$STR_ENH_MAIN_GARRISON_WHITELIST"
			};
			values[]={0,1};
		};
		class Blacklist: ctrlStatic
		{
			idc=-1;
			text="$STR_ENH_MAIN_AIRDROP_CLASSES_DISPLAYNAME";
			y="2 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50))";
			w="20 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class BlacklistValue: ctrlEditMulti
		{
			idc=20002;
			x="16 * (pixelW * pixelGrid * 0.50)";
			y="2 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50))";
			w="43 * (pixelW * pixelGrid * 0.50)";
			h="14 * (pixelH * pixelGrid * 0.50)";
		};
		class Coverage: Blacklist
		{
			text="$STR_ENH_MAIN_GARRISON_COVERAGE";
			y="5 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
		};
		class CoverageValue: ctrlToolbox
		{
			idc=20003;
			x="16 * (pixelW * pixelGrid * 0.50)";
			y="5 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			w="43 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			rows=1;
			columns=4;
			strings[]=
			{
				"$STR_ENH_MAIN_GARRISON_10PERCENT",
				"$STR_ENH_MAIN_GARRISON_25PERCENT",
				"$STR_ENH_MAIN_GARRISON_50PERCENT",
				"$STR_ENH_MAIN_GARRISON_100PERCENT"
			};
		};
		class Stance: Blacklist
		{
			text="$STR_ENH_MAIN_GARRISON_STANCE";
			y="6 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
		};
		class StanceValue: ctrlToolbox
		{
			idc=20007;
			x="16 * (pixelW * pixelGrid * 0.50)";
			y="6 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			w="43 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			rows=1;
			columns=5;
			strings[]=
			{
				"\a3\3DEN\Data\Attributes\Stance\up_ca.paa",
				"\a3\3DEN\Data\Attributes\Stance\middle_ca.paa",
				"\a3\3DEN\Data\Attributes\Stance\down_ca.paa",
				"\a3\3DEN\Data\Attributes\default_ca.paa",
				"\a3\ui_f\data\igui\cfg\simpletasks\types\unknown_ca.paa"
			};
			tooltips[]=
			{
				"$STR_3DEN_ATTRIBUTES_STANCE_UP",
				"$STR_3DEN_ATTRIBUTES_STANCE_MIDDLE",
				"$STR_3DEN_ATTRIBUTES_STANCE_DOWN",
				"$STR_3DEN_ATTRIBUTES_STANCE_DEFAULT",
				"$STR_A3_RSCDISPLAYARSENAL_BUTTONRANDOM"
			};
			style="0x02 + 0x30 + 0x800";
		};
		class Mode: Blacklist
		{
			text="$STR_ENH_MAIN_GARRISON_MODE";
			y="7 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
		};
		class ModeValue: ctrlCombo
		{
			idc=20004;
			x="16 * (pixelW * pixelGrid * 0.50)";
			y="7 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			w="43 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class PathFinding: Blacklist
		{
			text="$STR_ENH_MAIN_DISABLEAI_PATH_DISPLAYNAME";
			tooltip="$STR_ENH_MAIN_DISABLEAI_PATH_TOOLTIP";
			y="8 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
		};
		class PathFindingValue: ctrlToolbox
		{
			idc=20005;
			x="16 * (pixelW * pixelGrid * 0.50)";
			y="8 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			w="43 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			rows=1;
			columns=2;
			strings[]=
			{
				"$STR_DISABLED",
				"$STR_ENABLED"
			};
		};
		class Info: ctrlStructuredText
		{
			idc=20006;
			y="9 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			w="60 * (pixelW * pixelGrid * 0.50) - (pixelW * pixelGrid * 0.50)";
			h="2 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class BackgroundButton: ctrlStaticFooter
		{
			y="68 * (pixelH * pixelGrid * 0.50) - (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="60 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
		class Cancel: ctrlButtonCancel
		{
			idc=20009;
			x="60 * (pixelW * pixelGrid * 0.50) - 26 * (pixelW * pixelGrid * 0.50)";
			y="68 * (pixelH * pixelGrid * 0.50) - (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Ok: ctrlButtonOK
		{
			idc=20010;
			x="(pixelW * pixelGrid * 0.50)";
			y="68 * (pixelH * pixelGrid * 0.50) - (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_ModuleInformation
{
	idd=-1;
	onLoad="_this call ENH_fnc_moduleInformation_onLoad";
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_MODULEINFORMATION";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (65 * (pixelH * pixelGrid * 0.50)))";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 2 * (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="7 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class DescriptionValue: ctrlStructuredText
		{
			idc=1400;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 6 * (pixelH * pixelGrid * 0.50)";
			w="(140 - 2) * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - 9 * (pixelH * pixelGrid * 0.50)";
			colorBackground[]={0,0,0,0.5};
		};
		class Close: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (140 - 26) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (65 * (pixelH * pixelGrid * 0.50))) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_MoveToLayer
{
	idd=900;
	onLoad="_this call ENH_fnc_moveToLayer_onLoad";
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_SELECTLAYER_MOVETOLAYER";
			x="((getResolution select 2) * 0.5 * pixelW) - 140 * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 140 * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 140 * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class LayerList: ctrlTree
		{
			idc=930;
			idcSearch=910;
			x="((getResolution select 2) * 0.5 * pixelW) - 140 * 0.5 * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 24 * (pixelH * pixelGrid * 0.50)";
			borderSize=0;
			colorBorder[]={0,0,0,0};
			colorBackground[]={0.1,0.1,0.1,1};
		};
		class Search: ctrlEdit
		{
			idc=910;
			x="((getResolution select 2) * 0.5 * pixelW) - 140 * 0.5 * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="35 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="_this call ENH_fnc_moveToLayer_move";
		};
		class ButtonSearch: ctrlButtonSearch
		{
			idc=920;
			TEXT="\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			tooltip="";
			x="((getResolution select 2) * 0.5 * pixelW) - 140 * 0.5 * (pixelW * pixelGrid * 0.50) + 36 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class ButtonMove: ctrlButtonOK
		{
			idc=-1;
			text="$STR_A3_BOOT_M02_BIS_SIGN_MARKER";
			x="((getResolution select 2) * 0.5 * pixelW) + 140 * 0.5 * (pixelW * pixelGrid * 0.50) - 52 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="_this call ENH_fnc_moveToLayer_move";
		};
		class ButtonClose: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 140 * 0.5 * (pixelW * pixelGrid * 0.50) - 26 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_NameObjects
{
	idd=80000;
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_NAMEOBJECTS";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="53 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="53 * (pixelW * pixelGrid * 0.50)";
			h="37 * (pixelH * pixelGrid * 0.50)";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 29 * (pixelH * pixelGrid * 0.50)";
			w="53 * (pixelW * pixelGrid * 0.50)";
			h="2 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class VariableName: ctrlStatic
		{
			text="$STR_ENH_MAIN_NAMEOBJECTS_NAME";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 6 * (pixelH * pixelGrid * 0.50)";
			w="53 * (pixelW * pixelGrid * 0.50) - 4 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class VariableNameValue: ctrlEdit
		{
			idc=1000;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 12 * (pixelH * pixelGrid * 0.50)";
			w="53 * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class IndexStart: ctrlStatic
		{
			text="$STR_ENH_MAIN_NAMEOBJECTS_STARTINDEX";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 17 * (pixelH * pixelGrid * 0.50)";
			w="53 * (pixelW * pixelGrid * 0.50) - 4 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class IndexStartValue: ctrlEdit
		{
			idc=1100;
			text="0";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 23 * (pixelH * pixelGrid * 0.50)";
			w="53 * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class RemoveName: ctrlButton
		{
			idc=1300;
			text="$STR_ENH_MAIN_NAMEOBJECTS_REMOVENAMES";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 30 * (pixelH * pixelGrid * 0.50)";
			w="(53 - 2) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class SetName: ctrlButtonOK
		{
			idc=1200;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 53 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 36 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Cancel: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * 53 * (pixelW * pixelGrid * 0.50) - 26 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 36 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_PlacementToolsGroup: ctrlControlsGroup
{
	idc=-5;
	onLoad="[ctrlParent (_this#0), 'onLoad'] call ENH_fnc_placementTools";
	onUnload="[ctrlParent (_this#0), 'onUnload'] call ENH_fnc_placementTools";
	x="safeZoneX + 2 * (pixelW * pixelGrid * 0.50)";
	y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50)) + 3 * (pixelH * pixelGrid * 0.50)";
	w="58 * (pixelW * pixelGrid * 0.50)";
	h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 5 * (5 * (pixelH * pixelGrid * 0.50))";
	class Controls
	{
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_FOLDER_PLACEMENTTOOLS";
			x="0";
			y="0";
			w="58 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="0";
			y="(5 * (pixelH * pixelGrid * 0.50))";
			w="58 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 6 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class Footer: ctrlStaticFooter
		{
			x="0";
			y="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 6 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="58 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
		class Close: ctrlButtonClose
		{
			x="32 * (pixelW * pixelGrid * 0.50)";
			y="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 6 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="ctrlDelete ctrlParentControlsGroup (_this#0)";
		};
		class Tools: ctrlControlsGroup
		{
			idc=-1;
			onLoad="[ctrlParent (_this#0), 'onLoad'] call ENH_fnc_placementTools";
			onUnload="[ctrlParent (_this#0), 'onUnload'] call ENH_fnc_placementTools";
			x="0";
			y="(5 * (pixelH * pixelGrid * 0.50))";
			w="58 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 7 * (5 * (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			class Controls
			{
				class CircularHeader: ctrlStaticFooter
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_CIRCULAR_HEADER";
					x="(pixelW * pixelGrid * 0.50)";
					y="(pixelH * pixelGrid * 0.50)";
					w="56 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class Radius: ctrlStatic
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_RADIUS";
					x="(pixelW * pixelGrid * 0.50)";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
					w="23 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class RadiusValue: ctrlEdit
				{
					idc=13110;
					x="32 * (pixelW * pixelGrid * 0.50)";
					y="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
					w="25 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class InitialAngle: Radius
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_INITIALANGLE";
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 3 * (pixelH * pixelGrid * 0.50)";
				};
				class InitialAngleValue: RadiusValue
				{
					idc=13080;
					y="2 * (5 * (pixelH * pixelGrid * 0.50)) + 3 * (pixelH * pixelGrid * 0.50)";
				};
				class CentralAngle: Radius
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_CENTRALANGLE";
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 4 * (pixelH * pixelGrid * 0.50)";
				};
				class CentralAngleValue: RadiusValue
				{
					idc=13050;
					y="3 * (5 * (pixelH * pixelGrid * 0.50)) + 4 * (pixelH * pixelGrid * 0.50)";
				};
				class LineHeader: CircularHeader
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_LINEPATTERN_HEADER";
					y="4 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * (pixelH * pixelGrid * 0.50)";
				};
				class Spacing: Radius
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_SPACING";
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 6 * (pixelH * pixelGrid * 0.50)";
				};
				class SpacingValue: RadiusValue
				{
					idc=13160;
					y="5 * (5 * (pixelH * pixelGrid * 0.50)) + 6 * (pixelH * pixelGrid * 0.50)";
				};
				class SpacingDirection: Radius
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_DIRECTION";
					y="6 * (5 * (pixelH * pixelGrid * 0.50)) + 7 * (pixelH * pixelGrid * 0.50)";
				};
				class SpacingDirectionValue: RadiusValue
				{
					idc=13170;
					y="6 * (5 * (pixelH * pixelGrid * 0.50)) + 7 * (pixelH * pixelGrid * 0.50)";
				};
				class GridHeader: CircularHeader
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_GRID_HEADER";
					y="7 * (5 * (pixelH * pixelGrid * 0.50)) + 8 * (pixelH * pixelGrid * 0.50)";
				};
				class NumColumns: Radius
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_NUMCOLUMNS";
					y="8 * (5 * (pixelH * pixelGrid * 0.50)) + 9 * (pixelH * pixelGrid * 0.50)";
				};
				class NumColumsValue: RadiusValue
				{
					idc=13090;
					y="8 * (5 * (pixelH * pixelGrid * 0.50)) + 9 * (pixelH * pixelGrid * 0.50)";
				};
				class SpaceX: Radius
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_SPACINGX";
					y="9 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * (pixelH * pixelGrid * 0.50)";
				};
				class SpaceXValue: RadiusValue
				{
					idc=13140;
					y="9 * (5 * (pixelH * pixelGrid * 0.50)) + 10 * (pixelH * pixelGrid * 0.50)";
				};
				class SpaceY: Radius
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_SPACINGY";
					y="10 * (5 * (pixelH * pixelGrid * 0.50)) + 11 * (pixelH * pixelGrid * 0.50)";
				};
				class SpaceYValue: RadiusValue
				{
					idc=13150;
					y="10 * (5 * (pixelH * pixelGrid * 0.50)) + 11 * (pixelH * pixelGrid * 0.50)";
				};
				class FillAreaHeader: CircularHeader
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_FILLAREA_HEADER";
					y="11 * (5 * (pixelH * pixelGrid * 0.50)) + 12 * (pixelH * pixelGrid * 0.50)";
				};
				class A: Radius
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_A";
					y="12 * (5 * (pixelH * pixelGrid * 0.50)) + 13 * (pixelH * pixelGrid * 0.50)";
				};
				class AValue: RadiusValue
				{
					idc=13010;
					y="12 * (5 * (pixelH * pixelGrid * 0.50)) + 13 * (pixelH * pixelGrid * 0.50)";
				};
				class B: Radius
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_B";
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 14 * (pixelH * pixelGrid * 0.50)";
				};
				class BValue: RadiusValue
				{
					idc=13020;
					y="13 * (5 * (pixelH * pixelGrid * 0.50)) + 14 * (pixelH * pixelGrid * 0.50)";
				};
				class OrientationHeader: CircularHeader
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_ORIENTATION";
					y="14 * (5 * (pixelH * pixelGrid * 0.50)) + 15 * (pixelH * pixelGrid * 0.50)";
				};
				class Direction: Radius
				{
					text="$STR_ENH_MAIN_PLACEMENTTOOLS_DIRECTION";
					y="15 * (5 * (pixelH * pixelGrid * 0.50)) + 16 * (pixelH * pixelGrid * 0.50)";
				};
				class DirectionValue: RadiusValue
				{
					idc=13100;
					y="15 * (5 * (pixelH * pixelGrid * 0.50)) + 16 * (pixelH * pixelGrid * 0.50)";
				};
				class RandomOrientaton: ctrlButton
				{
					idc=13120;
					text="$STR_ENH_MAIN_TOOLS_PLACEMENTTOOLS_RANDOM";
					x="32 * (pixelW * pixelGrid * 0.50)";
					y="16 * (5 * (pixelH * pixelGrid * 0.50)) + 17 * (pixelH * pixelGrid * 0.50)";
					w="25 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
				class ReverseOrientation: RandomOrientaton
				{
					idc=13130;
					text="$STR_ENH_MAIN_TOOLS_PLACEMENTTOOLS_REVERSE";
					x="(pixelW * pixelGrid * 0.50)";
					y="16 * (5 * (pixelH * pixelGrid * 0.50)) + 17 * (pixelH * pixelGrid * 0.50)";
				};
			};
		};
	};
};
class ENH_RPTViewer
{
	idd=-1;
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Header: ctrlStaticTitle
		{
			idc=200;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class Group: ctrlControlsGroup
		{
			idc=201;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 4 * (5 * (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			class Controls
			{
				class Edit: ctrlEditMulti
				{
					idc=202;
					w="400 * (pixelW * pixelGrid * 0.50)";
					h="400 * (pixelH * pixelGrid * 0.50)";
					sizeEx="2.945 * ((1 / (getResolution select 3)) * pixelGrid * 0.5)";
					font="EtelkaMonospacePro";
					canModify=0;
				};
			};
		};
		class LinesText: ctrlStatic
		{
			text="$STR_ENH_MAIN_RPTVIEWER_NUMBEROFLINES";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Lines: ctrlEdit
		{
			idc=203;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 27 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="12 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			maxChars=4;
		};
		class ButtonHelp: ENH_ctrlButtonHelp
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) - 58 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			url="https://community.bistudio.com/wiki/Crash_Files";
		};
		class ButtonUpdate: ctrlButton
		{
			text="$STR_A3_RSCDISPLAYPUBLISHMISSION_BUTTONDOUPDATE";
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) - 52 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="'update' call ENH_fnc_RPTViewer";
		};
		class ButtonClose: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) - 26 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_SAM
{
	idd=160000;
	onLoad="_this call ENH_fnc_SAM";
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_TOOLS_SAM";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class Templates: ctrlStatic
		{
			text="$STR_ENH_MAIN_SAM_TEMPLATES";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 6 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Attributes: ctrlStatic
		{
			text="$STR_ENH_MAIN_SAM_ATTRIBUTES";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 51 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 6 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class TemplateList: ctrlListbox
		{
			idc=1501;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 12 * (pixelH * pixelGrid * 0.50)";
			w="50 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 11 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			onLBSelChanged="[nil, 'loadTemplate'] call ENH_fnc_SAM";
		};
		class AttributeList: ctrlTree
		{
			idc=1500;
			idcSearch=1400;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 52 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
			w="(140 - 53) * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 6 * (5 * (pixelH * pixelGrid * 0.50))";
			borderSize=0;
			colorBorder[]={0,0,0,0};
			colorBackground[]={0.1,0.1,0.1,1};
		};
		class Search: ctrlEdit
		{
			idc=1400;
			tooltip=@"format [""%1+%2"", toUpper localize ""STR_DIK_CONTROL"", ""F""]";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 52 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="35 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class ButtonSearch: ctrlButtonSearch
		{
			idc=1502;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 87 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Collapse: ctrlButtonCollapseAll
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 92 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="tvCollapseAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class Expand: ctrlButtonExpandAll
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 97 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="tvExpandAll (ctrlParent (_this # 0) displayCtrl 1500)";
		};
		class CreateTemplate: ctrlButton
		{
			text="$STR_ENH_MAIN_ESE_CREATETEMPLATE";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 7 * (5 * (pixelH * pixelGrid * 0.50)) - 6 * (pixelH * pixelGrid * 0.50)";
			w="50 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="[nil, 'createTemplate'] call ENH_fnc_SAM";
		};
		class DeleteTemplate: CreateTemplate
		{
			text="$STR_ENH_MAIN_SAM_DELETETEMPLATE";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 6 * (5 * (pixelH * pixelGrid * 0.50)) - 5 * (pixelH * pixelGrid * 0.50)";
			onButtonClick="[nil, 'deleteTemplate'] call ENH_fnc_SAM";
		};
		class ApplyTemplate: CreateTemplate
		{
			text="$STR_ENH_MAIN_SAM_APPLYTEMPLATE";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 5 * (5 * (pixelH * pixelGrid * 0.50)) - 4 * (pixelH * pixelGrid * 0.50)";
			onButtonClick="[nil, 'applyTemplate'] call ENH_fnc_SAM";
		};
		class ApplyAttribute: CreateTemplate
		{
			text="$STR_ENH_MAIN_SAM_APPLYATTRIBUTE";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 4 * (5 * (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			onButtonClick="[nil, 'applyAttribute'] call ENH_fnc_SAM";
		};
		class Close: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * 140 * (pixelW * pixelGrid * 0.50) - 26 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_SelectionFilter
{
	idd=-1;
	onLoad="_this call ENH_fnc_selectionFilter_init";
	class ControlsBackground
	{
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_SELECTIONFILTER";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50))";
			w="68 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 3 * (5 * (pixelH * pixelGrid * 0.50))";
			w="68 * (pixelW * pixelGrid * 0.50)";
			h="7 * (pixelH * pixelGrid * 0.50)";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 49 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50)) + 5 * (pixelH * pixelGrid * 0.50)";
			w="19 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class FilterObjects: ctrlCheckboxToolbar
		{
			idc=10;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50)) + 6 * (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			textureChecked="\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa";
			textureUnchecked="\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa";
			textureFocusedChecked="\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa";
			textureFocusedUnchecked="\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa";
			textureHoverChecked="\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa";
			textureHoverUnchecked="\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa";
			texturePressedChecked="\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa";
			texturePressedUnchecked="\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa";
			textureDisabledChecked="\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa";
			textureDisabledUnchecked="\a3\3den\data\displays\display3den\panelright\modeobjects_ca.paa";
			checked=1;
			onCheckedChanged="_this call ENH_fnc_selectionFilter_onCheckedChanged";
			tooltip="$STR_3DEN_OBJECT_TEXTPLURAL";
		};
		class FilterGroups: FilterObjects
		{
			idc=11;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 7 * (pixelW * pixelGrid * 0.50)";
			textureChecked="\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa";
			textureUnchecked="\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa";
			textureFocusedChecked="\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa";
			textureFocusedUnchecked="\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa";
			textureHoverChecked="\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa";
			textureHoverUnchecked="\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa";
			texturePressedChecked="\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa";
			texturePressedUnchecked="\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa";
			textureDisabledChecked="\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa";
			textureDisabledUnchecked="\a3\3den\data\displays\display3den\panelright\modegroups_ca.paa";
			tooltip="$STR_3DEN_GROUP_TEXTPLURAL";
		};
		class FilterTriggers: FilterObjects
		{
			idc=12;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 13 * (pixelW * pixelGrid * 0.50)";
			textureChecked="\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
			textureUnchecked="\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
			textureFocusedChecked="\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
			textureFocusedUnchecked="\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
			textureHoverChecked="\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
			textureHoverUnchecked="\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
			texturePressedChecked="\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
			texturePressedUnchecked="\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
			textureDisabledChecked="\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
			textureDisabledUnchecked="\a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa";
			tooltip="$STR_3DEN_TRIGGER_TEXTPLURAL";
		};
		class FilterSystems: FilterObjects
		{
			idc=13;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 19 * (pixelW * pixelGrid * 0.50)";
			textureChecked="\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa";
			textureUnchecked="\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa";
			textureFocusedChecked="\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa";
			textureFocusedUnchecked="\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa";
			textureHoverChecked="\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa";
			textureHoverUnchecked="\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa";
			texturePressedChecked="\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa";
			texturePressedUnchecked="\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa";
			textureDisabledChecked="\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa";
			textureDisabledUnchecked="\a3\ui_f_curator\data\displays\rscdisplaycurator\modemodules_ca.paa";
			tooltip="$STR_3DEN_LOGIC_TEXTPLURAL";
		};
		class FilterWaypoints: FilterObjects
		{
			idc=14;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 25 * (pixelW * pixelGrid * 0.50)";
			textureChecked="\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa";
			textureUnchecked="\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa";
			textureFocusedChecked="\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa";
			textureFocusedUnchecked="\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa";
			textureHoverChecked="\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa";
			textureHoverUnchecked="\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa";
			texturePressedChecked="\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa";
			texturePressedUnchecked="\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa";
			textureDisabledChecked="\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa";
			textureDisabledUnchecked="\a3\3den\data\displays\display3den\panelright\modewaypoints_ca.paa";
			tooltip="$STR_3DEN_WAYPOINT_TEXTPLURAL";
		};
		class FilterMarkers: FilterObjects
		{
			idc=15;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 31 * (pixelW * pixelGrid * 0.50)";
			textureChecked="\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa";
			textureUnchecked="\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa";
			textureFocusedChecked="\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa";
			textureFocusedUnchecked="\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa";
			textureHoverChecked="\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa";
			textureHoverUnchecked="\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa";
			texturePressedChecked="\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa";
			texturePressedUnchecked="\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa";
			textureDisabledChecked="\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa";
			textureDisabledUnchecked="\a3\3den\data\displays\display3den\panelright\modemarkers_ca.paa";
			tooltip="$STR_3DEN_MARKER_TEXTPLURAL";
		};
		class FilterComments: FilterObjects
		{
			idc=16;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 37 * (pixelW * pixelGrid * 0.50)";
			textureChecked="\a3\3den\data\cfg3den\comment\texture_ca.paa";
			textureUnchecked="\a3\3den\data\cfg3den\comment\texture_ca.paa";
			textureFocusedChecked="\a3\3den\data\cfg3den\comment\texture_ca.paa";
			textureFocusedUnchecked="\a3\3den\data\cfg3den\comment\texture_ca.paa";
			textureHoverChecked="\a3\3den\data\cfg3den\comment\texture_ca.paa";
			textureHoverUnchecked="\a3\3den\data\cfg3den\comment\texture_ca.paa";
			texturePressedChecked="\a3\3den\data\cfg3den\comment\texture_ca.paa";
			texturePressedUnchecked="\a3\3den\data\cfg3den\comment\texture_ca.paa";
			textureDisabledChecked="\a3\3den\data\cfg3den\comment\texture_ca.paa";
			textureDisabledUnchecked="\a3\3den\data\cfg3den\comment\texture_ca.paa";
			tooltip="$STR_3DEN_COMMENT_TEXTPLURAL";
		};
		class FilterLayers: FilterObjects
		{
			idc=17;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 43 * (pixelW * pixelGrid * 0.50)";
			textureChecked="\a3\3den\data\cfg3den\layer\icon_ca.paa";
			textureUnchecked="\a3\3den\data\cfg3den\layer\icon_ca.paa";
			textureFocusedChecked="\a3\3den\data\cfg3den\layer\icon_ca.paa";
			textureFocusedUnchecked="\a3\3den\data\cfg3den\layer\icon_ca.paa";
			textureHoverChecked="\a3\3den\data\cfg3den\layer\icon_ca.paa";
			textureHoverUnchecked="\a3\3den\data\cfg3den\layer\icon_ca.paa";
			texturePressedChecked="\a3\3den\data\cfg3den\layer\icon_ca.paa";
			texturePressedUnchecked="\a3\3den\data\cfg3den\layer\icon_ca.paa";
			textureDisabledChecked="\a3\3den\data\cfg3den\layer\icon_ca.paa";
			textureDisabledUnchecked="\a3\3den\data\cfg3den\layer\icon_ca.paa";
			tooltip="$STR_3DEN_LAYER_TEXTPLURAL";
		};
		class EditAttribute: ctrlButtonPictureKeepAspect
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 50 * (pixelW * pixelGrid * 0.50)";
			text="\a3\3den\data\displays\display3den\panelright\customcomposition_edit_ca.paa";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50)) + 6 * (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="_this spawn ENH_fnc_selectionFilter_editAttributes";
			tooltip="$STR_3DEN_DISPLAY3DEN_MENUBAR_ATTRIBUTES_TEXT";
		};
		class Ok: EditAttribute
		{
			idc=1;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 56 * (pixelW * pixelGrid * 0.50)";
			text="\a3\modules_f\data\iconsavegame_ca.paa";
			colorBackground[]={0,0.40000001,0,1};
			onButtonClick="";
			tooltip="$STR_ENH_MAIN_SELECTIONFILTER_CONFIRMSELECTION";
		};
		class Cancel: Ok
		{
			idc=-1;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 68 * (pixelW * pixelGrid * 0.50) + 62 * (pixelW * pixelGrid * 0.50)";
			text="\a3\ui_f\data\gui\rsc\rscdisplayarcademap\icon_exit_cross_ca.paa";
			colorBackground[]={0.69999999,0,0,1};
			onButtonClick="_this call ENH_fnc_selectionFilter_cancel";
			tooltip="$STR_ENH_MAIN_SELECTIONFILTER_RESTORESELECTION";
		};
	};
};
class ENH_TemplateData
{
	idd=500;
	onLoad="uiNamespace setVariable ['ENH_TitleValue', nil]; uiNamespace setVariable ['ENH_DescriptionValue', nil];";
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Header: ctrlStaticTitle
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 60 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="60 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 60 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="60 * (pixelW * pixelGrid * 0.50)";
			h="51 * (pixelH * pixelGrid * 0.50)";
		};
		class Title: ctrlStatic
		{
			text="$STR_ENH_MAIN_TEMPLATE_DATA_TITLE";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 60 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="58 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Description: ctrlStatic
		{
			text="$STR_ENH_MAIN_TEMPLATE_DATA_DESCRIPTION";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 60 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 3 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="58 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 60 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 49 * (pixelH * pixelGrid * 0.50)";
			w="60 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class TitleValue: ctrlEdit
		{
			idc=30700;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 60 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="58 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class DescriptionValue: ctrlEditMulti
		{
			idc=30800;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 60 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 4 * (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="58 * (pixelW * pixelGrid * 0.50)";
			h="25 * (pixelH * pixelGrid * 0.50)";
		};
		class ButtonCancel: ctrlButtonCancel
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 60 * (pixelW * pixelGrid * 0.50) + 34 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 50 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class ButtonOK: ctrlButtonOK
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 60 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 50 * (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="uiNamespace setVariable ['ENH_TitleValue', ctrlText (ctrlParent (_this#0) displayCtrl 30700)]; uiNamespace setVariable ['ENH_DescriptionValue', ctrlText (ctrlParent (_this#0) displayCtrl 30800)]";
		};
	};
};
class ENH_TextureFinder
{
	idd=140000;
	onLoad="0 spawn ENH_fnc_textureFinder_findTextures";
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_TEXTUREFINDER";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			moving=0;
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class BackgroundPreview: ctrlStaticBackgroundDisableTiles
		{
			idc=105;
			x="0";
			y="0";
			w="0";
			h="0";
			tileH="4 / (32 * pixelH) * 32";
			tileW="8 / (32 * pixelW) * 32";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class TextureList: ctrlTree
		{
			idc=100;
			idcSearch=104;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="(140 - 2) * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 80 * (pixelH * pixelGrid * 0.50) + (5 * (pixelH * pixelGrid * 0.50))";
			borderSize=0;
			colorBorder[]={0,0,0,0};
			colorBackground[]={0.1,0.1,0.1,1};
		};
		class Preview: ctrlStaticPictureKeepAspect
		{
			idc=102;
			x="0";
			y="0";
			w="0";
			h="0";
			colorBackground[]={1,1,1,1};
		};
		class Search: ctrlEdit
		{
			idc=104;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 1 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="30 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			tooltip=@"format [""%1+%2"", toUpper localize ""STR_DIK_CONTROL"", ""F""]";
		};
		class ButtonSearch: ctrlButtonSearch
		{
			idc=108;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 31 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="5 * (pixelH * pixelGrid * 0.50)";
		};
		class CollapseAll: ctrlButtonCollapseAll
		{
			idc=106;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 36 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="5 * (pixelH * pixelGrid * 0.50)";
		};
		class ExpandAll: ctrlButtonExpandAll
		{
			idc=107;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 41 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="5 * (pixelH * pixelGrid * 0.50)";
		};
		class ProgessText: ctrlStructuredText
		{
			idc=103;
			style=0;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 46 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="80 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Close: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (140 - 25 - 1) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_VariableViewer
{
	idd=500;
	onLoad="_this call ENH_fnc_variableViewer_onLoad";
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Header: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_VARIABLEVIEWER_HEADER";
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class BackgroundFilter: Background
		{
			h="(5 * (pixelH * pixelGrid * 0.50))";
			colorBackground[]={0,0,0,1};
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
		class FooterInputFields: Footer
		{
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 4 * (5 * (pixelH * pixelGrid * 0.50)) - 4 * (pixelH * pixelGrid * 0.50)";
			w="127 * (pixelW * pixelGrid * 0.50)";
		};
		class HideFunctionsText: ctrlStatic
		{
			text="$STR_ENH_MAIN_VARIABLEVIEWER_HIDEFUNCTIONS";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 35 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="28 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class VariableNameText: ctrlStatic
		{
			text="$STR_ENH_MAIN_VARIABLEVIEWER_VARIABLENAME";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 4 * (5 * (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			w="10 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class VariableValueText: VariableNameText
		{
			text="$STR_ENH_MAIN_VARIABLEVIEWER_VARIABLEVALUE";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 57 * (pixelW * pixelGrid * 0.50)";
		};
		class VariableCount: ctrlStatic
		{
			idc=509;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 100 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="20 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
	class Controls
	{
		class List: ctrlListNBox
		{
			idc=503;
			x="((getResolution select 2) * 0.5 * pixelW) - ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * (5 * (pixelH * pixelGrid * 0.50))";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 7 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			disableOverflow=1;
			columns[]={0,0.40000001,0.85000002};
		};
		class Filter: List
		{
			idc=501;
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Namespace: ctrlCombo
		{
			idc=504;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 55 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="45 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class SearchEdit: ctrlEdit
		{
			idc=505;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class SearchButton: ctrlButtonSearch
		{
			idc=506;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 26 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class HideFunctions: ctrlCheckbox
		{
			idc=502;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 31 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="5 * (pixelH * pixelGrid * 0.50)";
		};
		class VariableName: ctrlEdit
		{
			idc=510;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 12 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 4 * (5 * (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			w="45 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class VariableValue: VariableName
		{
			idc=511;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 69 * (pixelW * pixelGrid * 0.50)";
		};
		class Delete: ctrlButtonPictureKeepAspect
		{
			idc=508;
			text="a3\3den\data\displays\display3den\panelleft\entitylist_delete_ca.paa";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 115 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 4 * (5 * (pixelH * pixelGrid * 0.50)) - 3 * (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			onButtonClick="_this spawn ENH_fnc_variableViewer_delete";
		};
		class Set: Delete
		{
			idc=507;
			text="a3\3den\data\displays\display3den\toolbar\save_ca.paa";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) + 121 * (pixelW * pixelGrid * 0.50)";
			onButtonClick="_this spawn ENH_fnc_variableViewer_setOrCreate";
		};
		class Close: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50) - 26 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class ENH_ZeusAddons
{
	idd=-1;
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Title: ctrlStaticTitle
		{
			text="$STR_ENH_MAIN_ZEUSADDONS_HEADER";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50)))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50))";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class Footer: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - 2 * (pixelH * pixelGrid * 0.50)";
			w="140 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50)) + 2 * (pixelH * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class CfgPatchesLabel: ctrlStatic
		{
			text="$STR_ENH_MAIN_ZEUSADDONS_CFGPATCHES";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50)";
			w="80 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
			font="RobotoCondensedBold";
			sizeEx="4.86 * ((1 / (getResolution select 3)) * pixelGrid * 0.5)";
		};
		class CfgPatches: ctrlTree
		{
			idc=10;
			idcSearch=50;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50))";
			w="140 / 2 * (pixelW * pixelGrid * 0.50) - 2 * (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 6 * (5 * (pixelH * pixelGrid * 0.50))";
			borderSize=0;
			colorBorder[]={0,0,0,0};
			colorBackground[]={0.1,0.1,0.1,1};
		};
		class UnitsLabel: CfgPatchesLabel
		{
			text="$STR_ENH_MAIN_ZEUSADDONS_CONTENT";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 140 / 2 * (pixelW * pixelGrid * 0.50) - (pixelW * pixelGrid * 0.50)";
		};
		class Units: ctrlListbox
		{
			idc=20;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 140 / 2 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + 2 * ((5 * (pixelH * pixelGrid * 0.50)) + (pixelH * pixelGrid * 0.50))";
			w="140 / 2 * (pixelW * pixelGrid * 0.50) - (pixelW * pixelGrid * 0.50)";
			h="(safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 6 * (5 * (pixelH * pixelGrid * 0.50))";
			rowHeight="2 * (5 * (pixelH * pixelGrid * 0.50))";
		};
		class Copy: ctrlButton
		{
			idc=30;
			text="$STR_CA_COPY";
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * 140 * (pixelW * pixelGrid * 0.50) - 52 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Wiki: ENH_ctrlButtonHelp
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * 140 * (pixelW * pixelGrid * 0.50) - 58 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			url="https://github.com/R3voA3/3den-Enhanced/wiki/Custom-GUIs#zeus-addons";
		};
		class Close: ctrlButtonClose
		{
			x="((getResolution select 2) * 0.5 * pixelW) + 0.5 * 140 * (pixelW * pixelGrid * 0.50) - 26 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="25 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class InvertSelection: Copy
		{
			idc=40;
			text="$STR_ENH_MAIN_ZEUSADDONS_INVERT";
			tooltip="";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + (pixelW * pixelGrid * 0.50)";
		};
		class Search: ctrlEdit
		{
			idc=50;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 27 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="30 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class ButtonSearch: ctrlButtonSearch
		{
			idc=80;
			TEXT="\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa";
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 57 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Collapse: ctrlButtonCollapseAll
		{
			idc=60;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 62 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
		class Expand: ctrlButtonExpandAll
		{
			idc=70;
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * 140 * (pixelW * pixelGrid * 0.50) + 67 * (pixelW * pixelGrid * 0.50)";
			y="(0.5 - (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) * 0.5 + (5 * (pixelH * pixelGrid * 0.50))) + (safeZoneH min (180 * (pixelH * pixelGrid * 0.50))) - 3 * (5 * (pixelH * pixelGrid * 0.50)) - (pixelH * pixelGrid * 0.50)";
			w="5 * (pixelW * pixelGrid * 0.50)";
			h="(5 * (pixelH * pixelGrid * 0.50))";
		};
	};
};
class RscControlsGroupNoScrollbars;
class RscButtonMenu;
class RscDebugConsole: RscControlsGroupNoScrollbars
{
	class Controls
	{
		class ButtonFunctions: RscButtonMenu
		{
			idc=-1;
			onLoad="_this # 0 ctrlSetText ('ENH_' + localize 'STR_A3_RSCDEBUGCONSOLE_BUTTONFUNCTIONS'); if (isClass (configFile >> 'RscDisplayDebugPublic' >> 'Controls' >> 'DebugConsole' >> 'controls' >> 'CAU_xFuncViewer')) then {_this # 0 ctrlSetPosition [7.5 * (((safeZoneW / safeZoneH) min 1.2) / 40), 21.6 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)]; _this # 0 ctrlCommit 0;}";
			x="7.5 * (((safeZoneW / safeZoneH) min 1.2) / 40)";
			y="19.4 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)";
			w="7.4 * (((safeZoneW / safeZoneH) min 1.2) / 40)";
			h="1 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)";
			onButtonClick="ctrlParent (_this # 0) createDisplay 'ENH_FunctionsViewer'";
		};
	};
};
class Display3DENSave
{
	class ControlsBackground
	{
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5) * (pixelW * pixelGrid * 0.50)";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
		};
		class BackgroundFilter: ctrlStatic
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 3/4 - 2) * (pixelW * pixelGrid * 0.50)";
		};
		class BackgroundFiles: ctrlStaticOverlay
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 3/4 - 2) * (pixelW * pixelGrid * 0.50)";
		};
		class BackgroundButtons: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5) * (pixelW * pixelGrid * 0.50)";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class Title: ctrlStaticTitle
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5) * (pixelW * pixelGrid * 0.50)";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
		};
		class Search: ctrlEdit
		{
			x="((getResolution select 2) * 0.5 * pixelW) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 5 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) / 4) * (pixelW * pixelGrid * 0.50)";
		};
		class SearchButton: ctrlButtonSearch
		{
			x="((getResolution select 2) * 0.5 * pixelW) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/2 - 5 - 1) * (pixelW * pixelGrid * 0.50)";
		};
		class Folders: ctrlTree
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
		};
		class Files: ctrlListNBox
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 3/4 - 2) * (pixelW * pixelGrid * 0.50)";
		};
		class Filter: ctrlListNBox
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 3/4 - 2) * (pixelW * pixelGrid * 0.50)";
		};
		class NameText: ctrlStatic
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
		};
		class Name: ctrlEdit
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 3/4 - 2) * (pixelW * pixelGrid * 0.50)";
		};
		class BinarizeText: ctrlStatic
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
		};
		class Binarize: ctrlCheckbox
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4) * (pixelW * pixelGrid * 0.50)";
		};
		class ButtonOK: ctrlButtonOK
		{
			x="((getResolution select 2) * 0.5 * pixelW) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 - 50 - 2) * (pixelW * pixelGrid * 0.50)";
		};
		class ButtonPurchase: ctrlShortcutButtonSteam
		{
			x="((getResolution select 2) * 0.5 * pixelW) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 - 60 - 2) * (pixelW * pixelGrid * 0.50)";
		};
		class ButtonCancel: ctrlButtonCancel
		{
			x="((getResolution select 2) * 0.5 * pixelW) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 - 25 - 1) * (pixelW * pixelGrid * 0.50)";
		};
	};
};
class Display3DENPublishMissionSelectImage
{
	class ControlsBackground
	{
		class BackgroundDisable: ctrlStaticBackgroundDisable
		{
		};
		class BackgroundDisableTiles: ctrlStaticBackgroundDisableTiles
		{
		};
		class Background: ctrlStaticBackground
		{
			x="((getResolution select 2) * 0.5 * pixelW) - 0.5 * ((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
		};
		class BackgroundPreview: ctrlStatic
		{
			x="((getResolution select 2) * 0.5 * pixelW) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
		};
		class BackgroundButtons: ctrlStaticFooter
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5) * (pixelW * pixelGrid * 0.50)";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
		};
	};
	class Controls
	{
		class Title: ctrlStaticTitle
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5) * (pixelW * pixelGrid * 0.50)";
			w="((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * (pixelW * pixelGrid * 0.50)";
		};
		class Folders: ctrlTree
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
		};
		class Files: ctrlListbox
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 2/4 - 2) * (pixelW * pixelGrid * 0.50)";
		};
		class Preview: ctrlStaticPictureKeepAspect
		{
			x="((getResolution select 2) * 0.5 * pixelW) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 1/4 - 1) * (pixelW * pixelGrid * 0.50)";
		};
		class Name: ctrlStaticMulti
		{
			x="((getResolution select 2) * 0.5 * pixelW) - (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 - 1) * (pixelW * pixelGrid * 0.50)";
			w="(((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) - 2) * (pixelW * pixelGrid * 0.50)";
		};
		class ButtonOK: ctrlButtonOK
		{
			x="((getResolution select 2) * 0.5 * pixelW) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 - 50 - 2) * (pixelW * pixelGrid * 0.50)";
		};
		class ButtonCancel: ctrlButtonCancel
		{
			x="((getResolution select 2) * 0.5 * pixelW) + (((safeZoneW / (pixelW * pixelGrid * 0.50) - 10) min 400) * 0.5 - 25 - 1) * (pixelW * pixelGrid * 0.50)";
		};
	};
};
class DisplaySimulated;
class Display3DENPlace: DisplaySimulated
{
	class ControlsBackground
	{
		class PanelRightCreate: ctrlControlsGroupNoScrollbars
		{
			class Controls
			{
				class Create: ctrlControlsGroupNoScrollbars
				{
					class Controls
					{
						class ModsButton: ctrlCombo
						{
							onLoad="[_this#0] call ENH_fnc_assetBrowser_modFilter";
						};
					};
				};
			};
		};
	};
};
class ENH_DisplayEmpty
{
	idd=-1;
	class ControlsBackground
	{
	};
	class Controls
	{
	};
};
