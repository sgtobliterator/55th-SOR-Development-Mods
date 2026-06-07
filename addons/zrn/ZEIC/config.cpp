class CfgPatches
{
	class ADDON
	{
		name="Zeus/Eden Interiors Community Version - ZEI Core Mod";
		author="$STR_mod_author";
		authors[]=
		{
			"LSD",
			"shukari",
			"OverlordZorn [CVO]"
		};
		url="$STR_mod_URL";
		version=1;
		versionStr="1.0.1.18";
		versionAr[]={1,0,1,18};
		requiredVersion=2.02;
		requiredAddons[]=
		{
			"A3_Modules_F",
			"A3_Modules_F_Curator"
		};
		skipWhenMissingDependencies=1;
		units[]=
		{
			"ZEIC_ListBuildings",
			"ZEIC_GarrisonBuilding",
			"ZEIC_InteriorFill",
			"ZEIC_ObjectSwitch",
			"ZEIC_ObjectFill",
			"ZEIC_FindBPos",
			"ZEIC_SaveBuildingScheme"
		};
		weapons[]={};
	};
};
class CfgFunctions
{
	class ZEIC
	{
		class common
		{
			file="\zrn\ZEIC\addons\ZEIC\functions\common";
			class init_preStart
			{
				preStart=1;
			};
			class init
			{
				postInit=1;
			};
			class mod_findBPos
			{
			};
			class addCustomHouse
			{
			};
			class addCustomTemplate
			{
			};
			class misc_Vector2Eden
			{
			};
			class misc_logMsg
			{
			};
			class zeus_addModules
			{
			};
		};
		class garrisonBuilding
		{
			file="\zrn\ZEIC\addons\ZEIC\functions\garrisonBuilding";
			class garrisonUnit
			{
			};
			class mod_garrisonBuilding
			{
			};
			class ui_garrisonBuilding
			{
			};
			class ui_garrisonCombo
			{
			};
		};
		class InteriorFill
		{
			file="\zrn\ZEIC\addons\ZEIC\functions\InteriorFill";
			class addInteriorFillCategories
			{
			};
			class checkDetailLevel
			{
			};
			class createTemplate
			{
			};
			class findTemplates
			{
			};
			class mod_interiorFill
			{
			};
			class randomiseObject
			{
			};
			class templateCanSpawn
			{
			};
			class ui_interiorFill
			{
			};
		};
		class listBuildings
		{
			file="\zrn\ZEIC\addons\ZEIC\functions\listBuildings";
			class mod_listBuildings
			{
			};
			class ui_listBuildings
			{
			};
		};
		class objectFill
		{
			file="\zrn\ZEIC\addons\ZEIC\functions\objectFill";
			class mod_objectFill
			{
			};
			class ui_objectFill
			{
			};
		};
		class objectSwitch
		{
			file="\zrn\ZEIC\addons\ZEIC\functions\objectSwitch";
			class mod_objectSwitch
			{
			};
			class ui_objectSwitch
			{
			};
		};
		class rotation
		{
			file="\zrn\ZEIC\addons\ZEIC\functions\rotation";
			class misc_rotateAroundOwnAxisX
			{
			};
			class misc_rotateAroundOwnAxisY
			{
			};
			class misc_rotateAroundOwnAxisZ
			{
			};
		};
		class saveBuildingScheme
		{
			file="\zrn\ZEIC\addons\ZEIC\functions\saveBuildingScheme";
			class isVanillaObject
			{
			};
			class mod_saveBuildingScheme
			{
			};
		};
	};
};
class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
	};
	class ZEIC_ListBuildings: Module_F
	{
		scope=2;
		scopeCurator=1;
		displayName="List Buildings";
		category="ZEIC_interiors_dev";
		function="ZEIC_fnc_mod_listBuildings";
		functionPriority=1;
		icon="\A3\ui_f\data\igui\cfg\simpleTasks\types\intel_ca.paa";
		isGlobal=1;
		isTriggerActivated=0;
		is3DEN=1;
	};
	class ZEIC_GarrisonBuilding: Module_F
	{
		scope=2;
		scopeCurator=2;
		displayName="Garrison Building";
		category="ZEIC_interiors";
		function="ZEIC_fnc_mod_garrisonBuilding";
		functionPriority=1;
		icon="\A3\ui_f\data\igui\cfg\simpleTasks\types\rifle_ca.paa";
		isGlobal=1;
		isTriggerActivated=0;
		is3DEN=1;
	};
	class ZEIC_ObjectFill: Module_F
	{
		scope=2;
		scopeCurator=2;
		displayName="Object Fill";
		category="ZEIC_interiors";
		function="ZEIC_fnc_mod_objectFill";
		functionPriority=1;
		icon="\A3\ui_f\data\igui\cfg\simpleTasks\types\box_ca.paa";
		isGlobal=1;
		isTriggerActivated=0;
		is3DEN=1;
	};
	class ZEIC_ObjectSwitch: Module_F
	{
		scope=2;
		scopeCurator=2;
		displayName="Object Switch";
		category="ZEIC_interiors";
		function="ZEIC_fnc_mod_objectSwitch";
		functionPriority=1;
		icon="\A3\Modules_f\data\portraitRespawn_ca.paa";
		isGlobal=1;
		isTriggerActivated=0;
		is3DEN=1;
	};
	class ZEIC_InteriorFill: Module_F
	{
		scope=2;
		scopeCurator=2;
		displayName="Interior Fill";
		category="ZEIC_interiors";
		function="ZEIC_fnc_mod_interiorFill";
		functionPriority=1;
		icon="\A3\modules_f\data\portraitModule_ca.paa";
		isGlobal=1;
		isTriggerActivated=0;
		is3DEN=1;
	};
	class ZEIC_FindBPos: Module_F
	{
		scope=2;
		displayName="Mark Positions";
		category="ZEIC_interiors_dev";
		function="ZEIC_fnc_mod_findBPos";
		functionPriority=1;
		icon="\A3\modules_f\data\portraitStrategicMapMission_ca.paa";
		isGlobal=1;
		isTriggerActivated=0;
		is3DEN=1;
	};
	class ZEIC_SaveBuildingScheme: Module_F
	{
		scope=2;
		displayName="Save Building Scheme";
		category="ZEIC_interiors_dev";
		function="ZEIC_fnc_mod_saveBuildingScheme";
		functionPriority=1;
		icon="\a3\Modules_F\Data\iconSavegame_ca.paa";
		isGlobal=1;
		isTriggerActivated=0;
		is3DEN=1;
	};
};
class CfgFactionClasses
{
	class NO_CATEGORY;
	class ZEIC_interiors: NO_CATEGORY
	{
		displayName="ZEIC - Interiors";
	};
	class ZEIC_interiors_dev: NO_CATEGORY
	{
		displayName="ZEIC - Interiors Development";
	};
};
class ZEIC_RscText
{
	deletable=0;
	fade=0;
	access=0;
	type=0;
	idc=-1;
	colorBackground[]={0,0,0,0};
	colorText[]={1,1,1,1};
	text="";
	fixedWidth=0;
	colorShadow[]={0,0,0,0.5};
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={1,1,1,1};
	tooltipColorShade[]={0,0,0,0.64999998};
	x=0;
	y=0;
	h=0.037;
	w=0.30000001;
	style=0;
	shadow=1;
	font="RobotoCondensed";
	SizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	linespacing=1;
};
class ZEIC_RscStructuredText
{
	deletable=0;
	fade=0;
	access=0;
	type=13;
	idc=-1;
	style=0;
	colorText[]={1,1,1,1};
	class Attributes
	{
		font="RobotoCondensed";
		color="#ffffff";
		colorLink="#D09B43";
		align="left";
		shadow=1;
	};
	x=0;
	y=0;
	h=0.035;
	w=0.1;
	text="";
	size="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow=1;
};
class ZEIC_RscPicture
{
	deletable=0;
	fade=0;
	access=0;
	type=0;
	idc=-1;
	style=48;
	colorBackground[]={0,0,0,0};
	colorText[]={1,1,1,1};
	font="TahomaB";
	sizeEx=0;
	lineSpacing=0;
	text="";
	fixedWidth=0;
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={1,1,1,1};
	tooltipColorShade[]={0,0,0,0.64999998};
	shadow=0;
	x=0;
	y=0;
	w=0.2;
	h=0.15000001;
};
class ZEIC_RscEdit
{
	deletable=0;
	fade=0;
	access=0;
	type=2;
	x=0;
	y=0;
	h=0.039999999;
	w=0.2;
	colorBackground[]={0,0,0,0};
	colorText[]={0.94999999,0.94999999,0.94999999,1};
	colorDisabled[]={1,1,1,0.25};
	colorSelection[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		1
	};
	autocomplete="";
	text="";
	size=0.2;
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={1,1,1,1};
	tooltipColorShade[]={0,0,0,0.64999998};
	style="0x00 + 0x40";
	font="RobotoCondensed";
	shadow=2;
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	canModify=1;
};
class ZEIC_RscCombo
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
	class ComboScrollBar
	{
		color[]={1,1,1,1};
	};
	colorSelectBackground[]={1,1,1,0.69999999};
	colorActive[]={1,0,0,1};
	style="0x10 + 0x200";
	font="RobotoCondensed";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow=0;
	x=0;
	y=0;
	w=0.12;
	h=0.035;
	arrowEmpty="\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa";
	arrowFull="\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa";
	wholeHeight=0.44999999;
};
class ZEIC_RscListBox
{
	deletable=0;
	fade=0;
	access=0;
	type=5;
	rowHeight=0;
	colorText[]={1,1,1,1};
	colorDisabled[]={1,1,1,0.25};
	colorScrollbar[]={1,0,0,0};
	colorSelect[]={0,0,0,1};
	colorSelect2[]={0,0,0,1};
	colorSelectBackground[]={0.94999999,0.94999999,0.94999999,1};
	colorSelectBackground2[]={1,1,1,0.5};
	colorBackground[]={0,0,0,0.30000001};
	soundSelect[]=
	{
		"\A3\ui_f\data\sound\RscListbox\soundSelect",
		0.090000004,
		1
	};
	autoScrollSpeed=-1;
	autoScrollDelay=5;
	autoScrollRewind=0;
	arrowEmpty="#(argb,8,8,3)color(1,1,1,1)";
	arrowFull="#(argb,8,8,3)color(1,1,1,1)";
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
	class ListScrollBar
	{
		color[]={1,1,1,1};
		autoScrollEnabled=1;
	};
	colorShadow[]={0,0,0,0.5};
	x=0;
	y=0;
	w=0.30000001;
	h=0.30000001;
	style=16;
	font="RobotoCondensed";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow=0;
	period=1.2;
	maxHistoryDelay=1;
};
class ZEIC_RscButton
{
	deletable=0;
	fade=0;
	access=0;
	type=1;
	text="";
	colorText[]={1,1,1,1};
	colorDisabled[]={1,1,1,0.25};
	colorBackground[]={0,0,0,0.5};
	colorBackgroundDisabled[]={0,0,0,0.5};
	colorBackgroundActive[]={0,0,0,1};
	colorFocused[]={0,0,0,1};
	colorShadow[]={0,0,0,0};
	colorBorder[]={0,0,0,1};
	soundEnter[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.090000004,
		1
	};
	soundPush[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.090000004,
		1
	};
	soundClick[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundClick",
		0.090000004,
		1
	};
	soundEscape[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.090000004,
		1
	};
	idc=-1;
	style=2;
	x=0;
	y=0;
	w=0.095588997;
	h=0.039216001;
	shadow=2;
	font="RobotoCondensed";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	url="";
	offsetX=0;
	offsetY=0;
	offsetPressedX=0;
	offsetPressedY=0;
	borderSize=0;
};
class ZEIC_RscShortcutButton
{
	deletable=0;
	fade=0;
	type=16;
	x=0.1;
	y=0.1;
	class HitZone
	{
		left=0;
		top=0;
		right=0;
		bottom=0;
	};
	class ShortcutPos
	{
		left=0;
		top="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		w="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
		h="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	};
	class TextPos
	{
		left="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1) * (3/4)";
		top="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		right=0.0049999999;
		bottom=0;
	};
	shortcuts[]={};
	textureNoShortcut="#(argb,8,8,3)color(0,0,0,0)";
	color[]={1,1,1,1};
	colorFocused[]={1,1,1,1};
	color2[]={0.94999999,0.94999999,0.94999999,1};
	colorDisabled[]={1,1,1,0.25};
	colorBackground[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		1
	};
	colorBackgroundFocused[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		1
	};
	colorBackground2[]={1,1,1,1};
	soundEnter[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEnter",
		0.090000004,
		1
	};
	soundPush[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundPush",
		0.090000004,
		1
	};
	soundClick[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundClick",
		0.090000004,
		1
	};
	soundEscape[]=
	{
		"\A3\ui_f\data\sound\RscButton\soundEscape",
		0.090000004,
		1
	};
	class Attributes
	{
		font="RobotoCondensed";
		color="#E5E5E5";
		align="left";
		shadow="true";
	};
	colorSecondary[]={1,1,1,1};
	colorFocusedSecondary[]={1,1,1,1};
	color2Secondary[]={0.94999999,0.94999999,0.94999999,1};
	colorDisabledSecondary[]={1,1,1,0.25};
	class AttributesImage
	{
		font="RobotoCondensed";
		color="#E5E5E5";
		align="left";
	};
	idc=-1;
	style=0;
	default=0;
	shadow=1;
	w=0.183825;
	h="((((safezoneW / safezoneH) min 1.2) / 1.2) / 20)";
	textSecondary="";
	sizeExSecondary="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	fontSecondary="RobotoCondensed";
	animTextureDefault="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureNormal="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureDisabled="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\normal_ca.paa";
	animTextureOver="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\over_ca.paa";
	animTextureFocused="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\focus_ca.paa";
	animTexturePressed="\A3\ui_f\data\GUI\RscCommon\RscShortcutButton\down_ca.paa";
	periodFocus=1.2;
	periodOver=0.80000001;
	period=0.40000001;
	font="RobotoCondensed";
	size="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	text="";
	url="";
	action="";
};
class ZEIC_RscShortcutButtonMain
{
	color[]={1,1,1,1};
	colorDisabled[]={1,1,1,0.25};
	class HitZone
	{
		left=0;
		top=0;
		right=0;
		bottom=0;
	};
	class ShortcutPos
	{
		left=0.0145;
		top="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)) / 2";
		w="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2) * (3/4)";
		h="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
	};
	class TextPos
	{
		left="(((safezoneW / safezoneH) min 1.2) / 32) * 1.5";
		top="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 20)*2 - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)) / 2";
		right=0.0049999999;
		bottom=0;
	};
	class Attributes
	{
		font="RobotoCondensed";
		color="#E5E5E5";
		align="left";
		shadow="false";
	};
	class AttributesImage
	{
		font="RobotoCondensed";
		color="#E5E5E5";
		align="false";
	};
	idc=-1;
	style=0;
	default=0;
	w=0.31372601;
	h=0.104575;
	animTextureNormal="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
	animTextureDisabled="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\disabled_ca.paa";
	animTextureOver="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\over_ca.paa";
	animTextureFocused="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\focus_ca.paa";
	animTexturePressed="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\down_ca.paa";
	animTextureDefault="\A3\ui_f\data\GUI\RscCommon\RscShortcutButtonMain\normal_ca.paa";
	period=0.5;
	font="RobotoCondensed";
	size="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.2)";
	text="";
	action="";
};
class ZEIC_RscFrame
{
	colorBackground[]={0,0,0,0};
	colorText[]={1,1,1,1};
	type=0;
	idc=-1;
	deletable=0;
	style=64;
	shadow=2;
	font="RobotoCondensed";
	sizeEx=0.02;
	text="";
	x=0;
	y=0;
	w=0.30000001;
	h=0.30000001;
};
class ZEIC_RscSlider
{
	deletable=0;
	fade=0;
	access=0;
	type=3;
	style=1024;
	color[]={1,1,1,0.80000001};
	colorActive[]={1,1,1,1};
	shadow=0;
	x=0;
	y=0;
	w=0.30000001;
	h=0.025;
};
class ZEIC_IGUIBack
{
	colorText[]={0,0,0,0};
	colorbackground[]=
	{
		"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])",
		"(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])",
		"(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])",
		"(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"
	};
	type=0;
	idc=124;
	style=128;
	text="";
	font="RobotoCondensed";
	sizeEx=0;
	shadow=0;
	x=0.1;
	y=0.1;
	w=0.1;
	h=0.1;
};
class ZEIC_RscCheckBox
{
	color[]={1,1,1,0.69999999};
	colorFocused[]={1,1,1,1};
	colorHover[]={1,1,1,1};
	colorPressed[]={1,1,1,1};
	colorDisabled[]={1,1,1,0.2};
	colorBackground[]={0,0,0,0};
	colorBackgroundFocused[]={0,0,0,0};
	colorBackgroundHover[]={0,0,0,0};
	colorBackgroundPressed[]={0,0,0,0};
	colorBackgroundDisabled[]={0,0,0,0};
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={1,1,1,1};
	tooltipColorShade[]={0,0,0,0.64999998};
	soundEnter[]=
	{
		"",
		0.1,
		1
	};
	soundPush[]=
	{
		"",
		0.1,
		1
	};
	soundClick[]=
	{
		"",
		0.1,
		1
	};
	soundEscape[]=
	{
		"",
		0.1,
		1
	};
	idc=-1;
	type=77;
	deletable=0;
	style=0;
	checked=0;
	x="0.375 * safezoneW + safezoneX";
	y="0.36 * safezoneH + safezoneY";
	w="0.025 * safezoneW";
	h="0.04 * safezoneH";
	textureChecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureUnchecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureFocusedChecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureFocusedUnchecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureHoverChecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureHoverUnchecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	texturePressedChecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	texturePressedUnchecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
	textureDisabledChecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_checked_ca.paa";
	textureDisabledUnchecked="A3\Ui_f\data\GUI\RscCommon\RscCheckBox\CheckBox_unchecked_ca.paa";
};
class ZEIC_RscTextCheckBox
{
	colorText[]={1,0,0,1};
	color[]={0,0,0,0};
	colorBackground[]={0,0,0,0};
	colorTextSelect[]={0,0.80000001,0,1};
	colorSelectedBg[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		1
	};
	colorSelect[]={0,0,0,1};
	colorTextDisable[]={0.40000001,0.40000001,0.40000001,1};
	colorDisable[]={0.40000001,0.40000001,0.40000001,1};
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={1,1,1,1};
	tooltipColorShade[]={0,0,0,0.64999998};
	strings[]=
	{
		"UNCHECKED"
	};
	checked_strings[]=
	{
		"CHECKED"
	};
	idc=-1;
	type=7;
	style=0;
	x="0.375 * safezoneW + safezoneX";
	y="0.36 * safezoneH + safezoneY";
	w="0.025 * safezoneW";
	h="0.04 * safezoneH";
	font="RobotoCondensed";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
	rows=1;
	columns=1;
};
class ZEIC_RscButtonMenu
{
	colorBackground[]={0,0,0,0.80000001};
	colorBackgroundFocused[]={1,1,1,1};
	colorBackground2[]={0.75,0.75,0.75,1};
	color[]={1,1,1,1};
	colorFocused[]={0,0,0,1};
	color2[]={0,0,0,1};
	colorText[]={1,1,1,1};
	colorDisabled[]={1,1,1,0.25};
	colorSecondary[]={1,1,1,1};
	colorFocusedSecondary[]={0,0,0,1};
	color2Secondary[]={0,0,0,1};
	colorDisabledSecondary[]={1,1,1,0.25};
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={1,1,1,1};
	tooltipColorShade[]={0,0,0,0.64999998};
	class TextPos
	{
		left="0.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
		top="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
		right=0.0049999999;
		bottom=0;
	};
	class Attributes
	{
		font="PuristaLight";
		color="#E5E5E5";
		align="left";
		shadow="false";
	};
	class ShortcutPos
	{
		left="5.25 * (((safezoneW / safezoneH) min 1.2) / 40)";
		top=0;
		w="1 * (((safezoneW / safezoneH) min 1.2) / 40)";
		h="1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	};
	soundEnter[]=
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundEnter",
		0.090000004,
		1
	};
	soundPush[]=
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundPush",
		0.090000004,
		1
	};
	soundClick[]=
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundClick",
		0.090000004,
		1
	};
	soundEscape[]=
	{
		"\A3\ui_f\data\sound\RscButtonMenu\soundEscape",
		0.090000004,
		1
	};
	idc=-1;
	type=16;
	style="0x02 + 0xC0";
	default=0;
	shadow=0;
	x=0;
	y=0;
	w=0.095588997;
	h=0.039216001;
	animTextureNormal="#(argb,8,8,3)color(1,1,1,1)";
	animTextureDisabled="#(argb,8,8,3)color(1,1,1,1)";
	animTextureOver="#(argb,8,8,3)color(1,1,1,1)";
	animTextureFocused="#(argb,8,8,3)color(1,1,1,1)";
	animTexturePressed="#(argb,8,8,3)color(1,1,1,1)";
	animTextureDefault="#(argb,8,8,3)color(1,1,1,1)";
	textSecondary="";
	sizeExSecondary="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	fontSecondary="PuristaLight";
	period=1.2;
	periodFocus=1.2;
	periodOver=1.2;
	size="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
};
class ZEIC_RscButtonMenuOK
{
	shortcuts[]=
	{
		"0x00050000 + 0",
		28,
		57,
		156
	};
	soundPush[]=
	{
		"\A3\ui_f\data\sound\RscButtonMenuOK\soundPush",
		0.090000004,
		1
	};
	idc=1;
	default=1;
	text="OK";
};
class ZEIC_RscButtonMenuCancel
{
	shortcuts[]=
	{
		"0x00050000 + 1"
	};
	idc=2;
	text="Cancel";
};
class ZEIC_RscControlsGroup
{
	deletable=0;
	fade=0;
	class VScrollbar
	{
		color[]={1,1,1,1};
		width=0.021;
		autoScrollEnabled=1;
	};
	class HScrollbar
	{
		color[]={1,1,1,1};
		height=0.028000001;
	};
	class Controls
	{
	};
	type=15;
	idc=-1;
	x=0;
	y=0;
	w=1;
	h=1;
	shadow=0;
	style=16;
};
class Rsc_ZEIC_GarrisonBuilding
{
	idd=1702;
	controlsBackground[]=
	{
		"ZEIC_GB_Background",
		"ZEIC_GB_Frame",
		"ZEIC_GB_Text_Title",
		"ZEIC_GB_Text_Type",
		"ZEIC_GB_Text_Units",
		"ZEIC_GB_Text_DSEnabled",
		"ZEIC_GB_Text_TREnabled"
	};
	controls[]=
	{
		"ZEIC_GB_Combo_Type",
		"ZEIC_GB_Slider_Units",
		"ZEIC_GB_CheckBox_DSEnabled",
		"ZEIC_GB_CheckBox_TREnabled",
		"ZEIC_GB_Button_OK",
		"ZEIC_GB_Button_Cancel"
	};
	class ZEIC_GB_Background: ZEIC_IGUIBack
	{
		idc=-1;
		x="0.335 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.2475 * safezoneW";
		h="0.252 * safezoneH";
	};
	class ZEIC_GB_Frame: ZEIC_RscFrame
	{
		idc=-1;
		x="0.335 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.2475 * safezoneW";
		h="0.252 * safezoneH";
	};
	class ZEIC_GB_Text_Title: ZEIC_RscText
	{
		idc=1;
		text="Garrison Building";
		x="0.340156 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.19 * safezoneW";
		h="0.033 * safezoneH";
		onLoad="_this spawn { waitUntil { !isNull (_this select 0) }; (findDisplay 1702 displayCtrl 1) ctrlSetText format['Garrison Building - %1 (%2m)', getText(configFile >> 'CfgVehicles' >> typeOf (missionNamespace getVariable ['ZEIC_UiLastBuilding',objNull]) >> 'displayName'), round ((screenToWorld getMousePosition) distance2D (missionNamespace getVariable ['ZEIC_UiLastBuilding',objNull]))]; };";
	};
	class ZEIC_GB_Combo_Type: ZEIC_RscCombo
	{
		idc=10;
		x="0.432969 * safezoneW + safezoneX";
		y="0.368 * safezoneH + safezoneY";
		w="0.139219 * safezoneW";
		h="0.022 * safezoneH";
		tooltip="Choose the faction you wish to spawn.";
		onLoad="_this spawn zeic_fnc_ui_garrisonCombo;";
	};
	class ZEIC_GB_Text_Type: ZEIC_RscText
	{
		idc=-1;
		text="Faction";
		x="0.340156 * safezoneW + safezoneX";
		y="0.368 * safezoneH + safezoneY";
		w="0.0567187 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_GB_Text_Units: ZEIC_RscText
	{
		idc=2;
		text="No. of Units";
		x="0.340156 * safezoneW + safezoneX";
		y="0.412 * safezoneH + safezoneY";
		w="0.0825 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_GB_Slider_Units: ZEIC_RscSlider
	{
		idc=20;
		x="0.427812 * safezoneW + safezoneX";
		y="0.412 * safezoneH + safezoneY";
		w="0.144375 * safezoneW";
		h="0.033 * safezoneH";
		tooltip="Change the number of the units.";
		onSliderPosChanged="(findDisplay 1702 displayCtrl 2) ctrlSetText format['No. of Units (%1)', round (_this select 1)];";
		onLoad="_this spawn {			waitUntil { !isNull (_this select 0) };			(findDisplay 1702 displayCtrl 20) sliderSetRange [ 1, (count ((missionNamespace getVariable ['ZEIC_UiLastBuilding',objNull]) buildingPos -1)) ];			(findDisplay 1702 displayCtrl 20) sliderSetPosition round ((count ((missionNamespace getVariable ['ZEIC_UiLastBuilding',objNull]) buildingPos -1)) / 3);			(findDisplay 1702 displayCtrl 2) ctrlSetText format['No. of Units (%1)', round ((count ((missionNamespace getVariable ['ZEIC_UiLastBuilding',objNull]) buildingPos -1)) / 3)];		};";
	};
	class ZEIC_GB_Text_DSEnabled: ZEIC_RscText
	{
		idc=-1;
		text="Dynamic Simulation";
		x="0.340156 * safezoneW + safezoneX";
		y="0.456 * safezoneH + safezoneY";
		w="0.0825 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_GB_CheckBox_DSEnabled: ZEIC_RscCheckBox
	{
		idc=30;
		x="0.422656 * safezoneW + safezoneX";
		y="0.456 * safezoneH + safezoneY";
		w="0.020625 * safezoneW";
		h="0.033 * safezoneH";
		tooltip="Enables Dynamic Simulation for units\nDO NOT use when AI can easily be seen (e.g. outside or top of buildings).";
		onLoad="_this spawn {			waitUntil { !isNull (_this select 0) };			(findDisplay 1702 displayCtrl 30) cbSetChecked (missionNamespace getVariable ['ZEIC_UiGarrisonDynamic', false]);		};";
	};
	class ZEIC_GB_Text_TREnabled: ZEIC_RscText
	{
		idc=-1;
		text="Move AI Trigger";
		x="0.340156 * safezoneW + safezoneX";
		y="0.486 * safezoneH + safezoneY";
		w="0.0825 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_GB_CheckBox_TREnabled: ZEIC_RscCheckBox
	{
		idc=40;
		x="0.422656 * safezoneW + safezoneX";
		y="0.486 * safezoneH + safezoneY";
		w="0.020625 * safezoneW";
		h="0.033 * safezoneH";
		tooltip="Creates a Trigger to allow AI movement when a player is near.";
		onLoad="_this spawn {			waitUntil { !isNull (_this select 0) };			(findDisplay 1702 displayCtrl 40) cbSetChecked (missionNamespace getVariable ['ZEIC_UiCreateTrigger', false]);		};";
	};
	class ZEIC_GB_Button_OK: ZEIC_RscButton
	{
		idc=-1;
		text="OK";
		x="0.360781 * safezoneW + safezoneX";
		y="0.522 * safezoneH + safezoneY";
		w="0.04125 * safezoneW";
		h="0.022 * safezoneH";
		onButtonClick="[			(findDisplay 1702 displayCtrl 10) lbData (lbCurSel (findDisplay 1702 displayCtrl 10)),			round (sliderPosition (findDisplay 1702 displayCtrl 20)),			cbChecked (findDisplay 1702 displayCtrl 30),			cbChecked (findDisplay 1702 displayCtrl 40)			] spawn zeic_fnc_ui_garrisonBuilding; (findDisplay 1702) closeDisplay 1;";
	};
	class ZEIC_GB_Button_Cancel: ZEIC_RscButton
	{
		idc=-1;
		text="Cancel";
		x="0.494844 * safezoneW + safezoneX";
		y="0.522 * safezoneH + safezoneY";
		w="0.04125 * safezoneW";
		h="0.022 * safezoneH";
		onButtonClick="(findDisplay 1702) closeDisplay 2;";
	};
};
class Rsc_ZEIC_InteriorFill
{
	idd=1705;
	controlsBackground[]=
	{
		"ZEIC_IF_Background",
		"ZEIC_IF_Frame",
		"ZEIC_IF_Text_Title",
		"ZEIC_IF_Text_Type",
		"ZEIC_IF_Text_Items",
		"ZEIC_IF_Text_Detail",
		"ZEIC_IF_Text_EditObject",
		"ZEIC_IF_Text_AllowDamage"
	};
	controls[]=
	{
		"ZEIC_IF_Combo_Type",
		"ZEIC_IF_Slider_Items",
		"ZEIC_IF_Combo_Detail",
		"ZEIC_IF_CheckBox_EditObject",
		"ZEIC_IF_CheckBox_AllowDamage",
		"ZEIC_IF_Button_OK",
		"ZEIC_IF_Button_Cancel"
	};
	class ZEIC_IF_Background: ZEIC_IGUIBack
	{
		idc=-1;
		x="0.335 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.2475 * safezoneW";
		h="0.252 * safezoneH";
	};
	class ZEIC_IF_Frame: ZEIC_RscFrame
	{
		idc=-1;
		x="0.335 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.2475 * safezoneW";
		h="0.252 * safezoneH";
	};
	class ZEIC_IF_Text_Title: ZEIC_RscText
	{
		idc=1;
		text="Interior Fill";
		x="0.340156 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.19 * safezoneW";
		h="0.033 * safezoneH";
		onLoad="_this spawn { waitUntil { !isNull (_this select 0) }; (findDisplay 1705 displayCtrl 1) ctrlSetText format['Interior Fill - %1 (%2m)', getText(configFile >> 'CfgVehicles' >> typeOf (missionNamespace getVariable ['ZEIC_UiLastBuilding',objNull]) >> 'displayName'), round ((screenToWorld getMousePosition) distance2D (missionNamespace getVariable ['ZEIC_UiLastBuilding',objNull]))]; };";
	};
	class ZEIC_IF_Combo_Type: ZEIC_RscCombo
	{
		idc=10;
		x="0.432969 * safezoneW + safezoneX";
		y="0.368 * safezoneH + safezoneY";
		w="0.139219 * safezoneW";
		h="0.022 * safezoneH";
		tooltip="Type of interior to fill";
		onLoad="_this spawn {			waitUntil { !isNull (_this select 0) };			call ZEIC_fnc_addInteriorFillCategories;			(findDisplay 1705 displayCtrl 10) lbSetCurSel (missionNamespace getVariable ['ZEIC_UiInteriorType', 0]);		}";
	};
	class ZEIC_IF_Text_Type: ZEIC_RscText
	{
		idc=-1;
		text="Object Type";
		x="0.340156 * safezoneW + safezoneX";
		y="0.368 * safezoneH + safezoneY";
		w="0.0567187 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_IF_Text_Items: ZEIC_RscText
	{
		idc=2;
		text="Radius: Nearest";
		x="0.340156 * safezoneW + safezoneX";
		y="0.412 * safezoneH + safezoneY";
		w="0.0825 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_IF_Slider_Items: ZEIC_RscSlider
	{
		idc=20;
		x="0.427812 * safezoneW + safezoneX";
		y="0.412 * safezoneH + safezoneY";
		w="0.144375 * safezoneW";
		h="0.033 * safezoneH";
		tooltip="Radius of buildings to fill";
		onSliderPosChanged="if (round (_this select 1) > 0) then { (findDisplay 1705 displayCtrl 2) ctrlSetText format['Radius: %1 Meters', round (_this select 1)]; } else { (findDisplay 1705 displayCtrl 2) ctrlSetText 'Radius: Nearest'; };";
		onLoad="_this spawn {			waitUntil { !isNull (_this select 0) };			(findDisplay 1705 displayCtrl 20) sliderSetRange [ 0, 250 ];			(findDisplay 1705 displayCtrl 20) sliderSetPosition 0;		};";
	};
	class ZEIC_IF_Text_Detail: ZEIC_RscText
	{
		idc=5;
		text="Level of Detail";
		x="0.340156 * safezoneW + safezoneX";
		y="0.457 * safezoneH + safezoneY";
		w="0.0567187 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_IF_Combo_Detail: ZEIC_RscCombo
	{
		idc=50;
		x="0.432969 * safezoneW + safezoneX";
		y="0.457 * safezoneH + safezoneY";
		w="0.139219 * safezoneW";
		h="0.022 * safezoneH";
		tooltip="Level of complexity for interiors";
		onLoad="_this spawn {			waitUntil { !isNull (_this select 0) };			{ (findDisplay 1705 displayCtrl 50) lbAdd _x } forEach ['Defences Only', 'Full'];			(findDisplay 1705 displayCtrl 50) lbSetCurSel (missionNamespace getVariable ['ZEIC_UiInteriorDetail', 1]);		}";
	};
	class ZEIC_IF_Text_EditObject: ZEIC_RscText
	{
		idc=3;
		text="Edit Objects";
		x="0.340156 * safezoneW + safezoneX";
		y="0.501 * safezoneH + safezoneY";
		w="0.0845 * safezoneW";
		h="0.022 * safezoneH";
		onLoad="_this spawn { waitUntil { !isNull (_this select 0) };			if is3DEN then { (findDisplay 1705 displayCtrl 3) ctrlShow false; };		}";
	};
	class ZEIC_IF_CheckBox_EditObject: ZEIC_RscCheckBox
	{
		idc=30;
		x="0.422656 * safezoneW + safezoneX";
		y="0.501 * safezoneH + safezoneY";
		w="0.020625 * safezoneW";
		h="0.033 * safezoneH";
		tooltip="Add the spawned objects to Curator\nIf disabled, they cannot be moved or edited by Zeus.";
		checked=1;
		onLoad="_this spawn { waitUntil { !isNull (_this select 0) };			(findDisplay 1705 displayCtrl 30) cbSetChecked (missionNamespace getVariable ['ZEIC_UiInteriorEdit', true]);			if is3DEN then { (findDisplay 1705 displayCtrl 30) ctrlShow false; };		}";
	};
	class ZEIC_IF_Text_AllowDamage: ZEIC_RscText
	{
		idc=4;
		text="Allow Damage";
		x="0.340156 * safezoneW + safezoneX";
		y="0.545 * safezoneH + safezoneY";
		w="0.0845 * safezoneW";
		h="0.022 * safezoneH";
		onLoad="_this spawn { waitUntil { !isNull (_this select 0) };			if is3DEN then { (findDisplay 1705 displayCtrl 4) ctrlShow false; };		}";
	};
	class ZEIC_IF_CheckBox_AllowDamage: ZEIC_RscCheckBox
	{
		idc=40;
		x="0.422656 * safezoneW + safezoneX";
		y="0.545 * safezoneH + safezoneY";
		w="0.020625 * safezoneW";
		h="0.033 * safezoneH";
		tooltip="Allow the building to be damaged.\nIf enabled, all objects inside the building may be left 'floating' when damaged/destroyed.";
		onLoad="_this spawn { waitUntil { !isNull (_this select 0) };			(findDisplay 1705 displayCtrl 40) cbSetChecked (missionNamespace getVariable ['ZEIC_UiInteriorDamage', false]);			if is3DEN then { (findDisplay 1705 displayCtrl 40) ctrlShow false; };		}";
	};
	class ZEIC_IF_Button_OK: ZEIC_RscButton
	{
		idc=-1;
		text="OK";
		x="0.360781 * safezoneW + safezoneX";
		y="0.599 * safezoneH + safezoneY";
		w="0.04125 * safezoneW";
		h="0.022 * safezoneH";
		onButtonClick="[ lbCurSel (findDisplay 1705 displayCtrl 10), round (sliderPosition (findDisplay 1705 displayCtrl 20)), cbChecked (findDisplay 1705 displayCtrl 30), cbChecked (findDisplay 1705 displayCtrl 40), lbCurSel (findDisplay 1705 displayCtrl 50) ] spawn ZEIC_fnc_ui_interiorFill; (findDisplay 1705) closeDisplay 1;";
	};
	class ZEIC_IF_Button_Cancel: ZEIC_RscButton
	{
		idc=-1;
		text="Cancel";
		x="0.494844 * safezoneW + safezoneX";
		y="0.599 * safezoneH + safezoneY";
		w="0.04125 * safezoneW";
		h="0.022 * safezoneH";
		onButtonClick="(findDisplay 1705) closeDisplay 2;";
	};
};
class Rsc_ZEIC_ListBuildings
{
	idd=1703;
	controlsBackground[]=
	{
		"ZEIC_LB_Background",
		"ZEIC_LB_Frame",
		"ZEIC_LB_Text_Title",
		"ZEIC_LB_Text_Matching",
		"ZEIC_LB_Text_MinTemplates",
		"ZEIC_LB_Text_MinTemplatesCount",
		"ZEIC_LB_Text_ShowPositions"
	};
	controls[]=
	{
		"ZEIC_LB_Combo_Matching",
		"ZEIC_LB_Slider_MinTemplates",
		"ZEIC_LB_CheckBox_ShowPositions",
		"ZEIC_LB_Button_OK",
		"ZEIC_LB_Button_Cancel"
	};
	class ZEIC_LB_Background: ZEIC_IGUIBack
	{
		idc=-1;
		x="0.335 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.2475 * safezoneW";
		h="0.242 * safezoneH";
	};
	class ZEIC_LB_Frame: ZEIC_RscFrame
	{
		idc=-1;
		x="0.335 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.2475 * safezoneW";
		h="0.242 * safezoneH";
	};
	class ZEIC_LB_Text_Title: ZEIC_RscText
	{
		idc=-1;
		text="List Template Buildings";
		x="0.340156 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.19 * safezoneW";
		h="0.033 * safezoneH";
	};
	class ZEIC_LB_Combo_Matching: ZEIC_RscCombo
	{
		idc=10;
		x="0.432969 * safezoneW + safezoneX";
		y="0.368 * safezoneH + safezoneY";
		w="0.139219 * safezoneW";
		h="0.022 * safezoneH";
		onLoad="_this spawn {			waitUntil { !isNull (_this select 0) };			{ (findDisplay 1703 displayCtrl 10) lbAdd _x } forEach ['All','Military','Civilian','CBRN','OPTRE Civilian[CAN CRASH GAME]','OPTRE Military[CAN CRASH GAME]'];			(findDisplay 1703 displayCtrl 10) lbSetCurSel 0;		}";
	};
	class ZEIC_LB_Text_Matching: ZEIC_RscText
	{
		idc=-1;
		text="Template Filter";
		x="0.340156 * safezoneW + safezoneX";
		y="0.368 * safezoneH + safezoneY";
		w="0.0567187 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_LB_Text_MinTemplates: ZEIC_RscText
	{
		idc=-1;
		text="Number of Templates";
		x="0.340156 * safezoneW + safezoneX";
		y="0.412 * safezoneH + safezoneY";
		w="0.0825 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_LB_Text_MinTemplatesCount: ZEIC_RscText
	{
		idc=2;
		text="(15 or less)";
		x="0.340156 * safezoneW + safezoneX";
		y="0.436 * safezoneH + safezoneY";
		w="0.0825 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_LB_Slider_MinTemplates: ZEIC_RscSlider
	{
		idc=20;
		x="0.427812 * safezoneW + safezoneX";
		y="0.412 * safezoneH + safezoneY";
		w="0.144375 * safezoneW";
		h="0.033 * safezoneH";
		onSliderPosChanged="if (round (_this select 1) > 0) then { (findDisplay 1703 displayCtrl 2) ctrlSetText format['(%1 or less)', round (_this select 1)]; } else { (findDisplay 1703 displayCtrl 2) ctrlSetText '(No Template)'; };";
		onLoad="_this spawn {			waitUntil { !isNull (_this select 0) };			(findDisplay 1703 displayCtrl 20) sliderSetRange [ 0, 15 ];			(findDisplay 1703 displayCtrl 20) sliderSetPosition 15;			};";
	};
	class ZEIC_LB_Text_ShowPositions: ZEIC_RscText
	{
		idc=-1;
		text="Mark Positions";
		x="0.340156 * safezoneW + safezoneX";
		y="0.467 * safezoneH + safezoneY";
		w="0.0825 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_LB_CheckBox_ShowPositions: ZEIC_RscCheckBox
	{
		idc=30;
		x="0.422656 * safezoneW + safezoneX";
		y="0.467 * safezoneH + safezoneY";
		w="0.020625 * safezoneW";
		h="0.033 * safezoneH";
	};
	class ZEIC_LB_Button_OK: ZEIC_RscButton
	{
		idc=-1;
		text="OK";
		x="0.360781 * safezoneW + safezoneX";
		y="0.522 * safezoneH + safezoneY";
		w="0.04125 * safezoneW";
		h="0.022 * safezoneH";
		onButtonClick="[ lbCurSel (findDisplay 1703 displayCtrl 10), round (sliderPosition (findDisplay 1703 displayCtrl 20)), cbChecked (findDisplay 1703 displayCtrl 30) ] spawn zeic_fnc_ui_listBuildings; (findDisplay 1703) closeDisplay 1;";
	};
	class ZEIC_LB_Button_Cancel: ZEIC_RscButton
	{
		idc=-1;
		text="Cancel";
		x="0.494844 * safezoneW + safezoneX";
		y="0.522 * safezoneH + safezoneY";
		w="0.04125 * safezoneW";
		h="0.022 * safezoneH";
		onButtonClick="(findDisplay 1703) closeDisplay 2;";
	};
};
class Rsc_ZEIC_ObjectFill
{
	idd=1704;
	controlsBackground[]=
	{
		"ZEIC_OF_Background",
		"ZEIC_OF_Frame",
		"ZEIC_OF_Text_Title",
		"ZEIC_OF_Text_Type",
		"ZEIC_OF_Text_Items",
		"ZEIC_OF_Text_EditObject"
	};
	controls[]=
	{
		"ZEIC_OF_Combo_Type",
		"ZEIC_OF_Slider_Items",
		"ZEIC_OF_CheckBox_EditObject",
		"ZEIC_OF_Button_OK",
		"ZEIC_OF_Button_Cancel"
	};
	class ZEIC_OF_Background: ZEIC_IGUIBack
	{
		idc=-1;
		x="0.335 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.2475 * safezoneW";
		h="0.242 * safezoneH";
	};
	class ZEIC_OF_Frame: ZEIC_RscFrame
	{
		idc=-1;
		x="0.335 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.2475 * safezoneW";
		h="0.242 * safezoneH";
	};
	class ZEIC_OF_Text_Title: ZEIC_RscText
	{
		idc=1;
		text="Object Fill";
		x="0.340156 * safezoneW + safezoneX";
		y="0.324 * safezoneH + safezoneY";
		w="0.19 * safezoneW";
		h="0.033 * safezoneH";
		onLoad="_this spawn { waitUntil { !isNull (_this select 0) }; (findDisplay 1704 displayCtrl 1) ctrlSetText format['Object Fill (%1)', getText(configFile >> 'CfgVehicles' >> typeOf (missionNamespace getVariable ['ZEIC_UiLastObject',objNull]) >> 'displayName')]; };";
	};
	class ZEIC_OF_Combo_Type: ZEIC_RscCombo
	{
		idc=10;
		x="0.432969 * safezoneW + safezoneX";
		y="0.368 * safezoneH + safezoneY";
		w="0.139219 * safezoneW";
		h="0.022 * safezoneH";
		onLoad="_this spawn {			waitUntil { !isNull (_this select 0) };			{ (findDisplay 1704 displayCtrl 10) lbAdd _x } forEach ['Random', 'Food', 'Medical', 'Office', 'Tools', 'Electric', 'CBRN Cleaning'];			(findDisplay 1704 displayCtrl 10) lbSetCurSel 0;		}";
	};
	class ZEIC_OF_Text_Type: ZEIC_RscText
	{
		idc=-1;
		text="Object Type";
		x="0.340156 * safezoneW + safezoneX";
		y="0.368 * safezoneH + safezoneY";
		w="0.0567187 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_OF_Text_Items: ZEIC_RscText
	{
		idc=2;
		text="Fill Percent (30)";
		x="0.340156 * safezoneW + safezoneX";
		y="0.412 * safezoneH + safezoneY";
		w="0.0825 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_OF_Slider_Items: ZEIC_RscSlider
	{
		idc=20;
		x="0.427812 * safezoneW + safezoneX";
		y="0.412 * safezoneH + safezoneY";
		w="0.144375 * safezoneW";
		h="0.033 * safezoneH";
		tooltip="Chance to spawn an object";
		onSliderPosChanged="(findDisplay 1704 displayCtrl 2) ctrlSetText format['Fill Percent (%1)', round (_this select 1) * 10];";
		onLoad="_this spawn {			waitUntil { !isNull (_this select 0) };			(findDisplay 1704 displayCtrl 20) sliderSetRange [ 1, 10 ];			(findDisplay 1704 displayCtrl 20) sliderSetPosition 3;			};";
	};
	class ZEIC_OF_Text_EditObject: ZEIC_RscText
	{
		idc=3;
		text="Edit Object";
		x="0.340156 * safezoneW + safezoneX";
		y="0.467 * safezoneH + safezoneY";
		w="0.0845 * safezoneW";
		h="0.022 * safezoneH";
		onLoad="_this spawn { waitUntil { !isNull (_this select 0) };			if is3DEN then { (findDisplay 1704 displayCtrl 3) ctrlShow false; };		}";
	};
	class ZEIC_OF_CheckBox_EditObject: ZEIC_RscCheckBox
	{
		idc=30;
		x="0.422656 * safezoneW + safezoneX";
		y="0.467 * safezoneH + safezoneY";
		w="0.020625 * safezoneW";
		h="0.033 * safezoneH";
		tooltip="Allow Zeus to Move/Edit Objects";
		checked=1;
		onLoad="_this spawn { waitUntil { !isNull (_this select 0) };			if is3DEN then { (findDisplay 1704 displayCtrl 30) ctrlShow false; };		}";
	};
	class ZEIC_OF_Button_OK: ZEIC_RscButton
	{
		idc=-1;
		text="OK";
		x="0.360781 * safezoneW + safezoneX";
		y="0.522 * safezoneH + safezoneY";
		w="0.04125 * safezoneW";
		h="0.022 * safezoneH";
		onButtonClick="[ lbCurSel (findDisplay 1704 displayCtrl 10), round (sliderPosition (findDisplay 1704 displayCtrl 20)) * 10, cbChecked (findDisplay 1704 displayCtrl 30) ] spawn zeic_fnc_ui_objectFill; (findDisplay 1704) closeDisplay 1;";
	};
	class ZEIC_OF_Button_Cancel: ZEIC_RscButton
	{
		idc=-1;
		text="Cancel";
		x="0.494844 * safezoneW + safezoneX";
		y="0.522 * safezoneH + safezoneY";
		w="0.04125 * safezoneW";
		h="0.022 * safezoneH";
		onButtonClick="(findDisplay 1704) closeDisplay 2;";
	};
};
class Rsc_ZEIC_ObjectSwitch
{
	idd=1701;
	controlsBackground[]=
	{
		"ZEIC_OS_Background",
		"ZEIC_OS_Frame",
		"ZEIC_OS_Text_Title",
		"ZEIC_OS_Text_Radius",
		"ZEIC_OS_Text_RadiusMeters",
		"ZEIC_OS_Text_Type"
	};
	controls[]=
	{
		"ZEIC_OS_Combo_Type",
		"ZEIC_OS_Slider_Radius",
		"ZEIC_OS_Button_OK",
		"ZEIC_OS_Button_Cancel"
	};
	class ZEIC_OS_Background: ZEIC_IGUIBack
	{
		idc=-1;
		x="0.350468 * safezoneW + safezoneX";
		y="0.357 * safezoneH + safezoneY";
		w="0.242344 * safezoneW";
		h="0.209 * safezoneH";
	};
	class ZEIC_OS_Frame: ZEIC_RscFrame
	{
		idc=-1;
		x="0.350468 * safezoneW + safezoneX";
		y="0.357 * safezoneH + safezoneY";
		w="0.242344 * safezoneW";
		h="0.209 * safezoneH";
	};
	class ZEIC_OS_Text_Title: ZEIC_RscText
	{
		idc=-1;
		text="Object Switcher";
		x="0.355625 * safezoneW + safezoneX";
		y="0.357 * safezoneH + safezoneY";
		w="0.0773437 * safezoneW";
		h="0.033 * safezoneH";
	};
	class ZEIC_OS_Text_Radius: ZEIC_RscText
	{
		idc=-1;
		text="Radius";
		x="0.355625 * safezoneW + safezoneX";
		y="0.456 * safezoneH + safezoneY";
		w="0.0360937 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_OS_Text_RadiusMeters: ZEIC_RscText
	{
		idc=1;
		text="50m";
		x="0.355625 * safezoneW + safezoneX";
		y="0.476 * safezoneH + safezoneY";
		w="0.0360937 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_OS_Text_Type: ZEIC_RscText
	{
		idc=-1;
		text="Convert To";
		x="0.355625 * safezoneW + safezoneX";
		y="0.412 * safezoneH + safezoneY";
		w="0.0464063 * safezoneW";
		h="0.022 * safezoneH";
	};
	class ZEIC_OS_Combo_Type: ZEIC_RscCombo
	{
		idc=10;
		x="0.407187 * safezoneW + safezoneX";
		y="0.412 * safezoneH + safezoneY";
		w="0.103125 * safezoneW";
		h="0.022 * safezoneH";
		tooltip="Choose the type of object to convert to.";
		onLoad="_this spawn {			waitUntil { !isNull (_this select 0) };			{ (findDisplay 1701 displayCtrl 10) lbAdd _x } forEach ['Desert (Vanilla)', 'Jungle (Apex)', 'Woodland (Contact)'];			if (isClass(configFile >> 'CfgPatches' >> 'CUP_Core')) then {				{(findDisplay 1701 displayCtrl 10) lbAdd _x } forEach [ 'Desert (CUP)', 'Woodland (CUP)' ];				if (isClass(configFile >> 'CfgPatches' >> 'vn_data_f')) then {					{(findDisplay 1701 displayCtrl 10) lbAdd _x } forEach [ 'SOG (Brown)', 'SOG (Green)' ];				};			} else {				if (isClass(configFile >> 'CfgPatches' >> 'vn_data_f')) then {					{(findDisplay 1701 displayCtrl 10) lbAdd _x } forEach [ 'Invalid (CUP)', 'Invalid (CUP)', 'SOG (Brown)', 'SOG (Green)' ];				};			};			(findDisplay 1701 displayCtrl 10) lbSetCurSel (missionNamespace getVariable ['ZEIC_UiSwitchCombo', 0]);		}";
	};
	class ZEIC_OS_Slider_Radius: ZEIC_RscSlider
	{
		idc=20;
		x="0.407187 * safezoneW + safezoneX";
		y="0.456 * safezoneH + safezoneY";
		w="0.154687 * safezoneW";
		h="0.022 * safezoneH";
		tooltip="Change the radius of the affected area.";
		onSliderPosChanged="(findDisplay 1701 displayCtrl 1) ctrlSetText format['%1m', round (_this select 1)];";
		onLoad="_this spawn { waitUntil { !isNull (_this select 0) }; (findDisplay 1701 displayCtrl 20) sliderSetRange [ 1, 250 ]; (findDisplay 1701 displayCtrl 20) sliderSetPosition 50; };";
	};
	class ZEIC_OS_Button_OK: ZEIC_RscButton
	{
		idc=-1;
		text="OK";
		x="0.463906 * safezoneW + safezoneX";
		y="0.533 * safezoneH + safezoneY";
		w="0.0567187 * safezoneW";
		h="0.022 * safezoneH";
		onButtonClick="[ lbCurSel (findDisplay 1701 displayCtrl 10), sliderPosition (findDisplay 1701 displayCtrl 20) ] spawn zeic_fnc_ui_objectSwitch; findDisplay 1701 closeDisplay 1;";
	};
	class ZEIC_OS_Button_Cancel: ZEIC_RscButton
	{
		idc=-1;
		text="Cancel";
		x="0.530937 * safezoneW + safezoneX";
		y="0.533 * safezoneH + safezoneY";
		w="0.0567187 * safezoneW";
		h="0.022 * safezoneH";
		onButtonClick="findDisplay 1701 closeDisplay 2;";
	};
};
