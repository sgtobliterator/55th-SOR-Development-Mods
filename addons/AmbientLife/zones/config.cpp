class CfgPatches
{
	class digii_ambient_zones
	{
		name="digii_ambient - Zones";
		units[]=
		{
			"digii_ambient_module_zone",
			"digii_ambient_module_zone_civilian"
		};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"digii_ambient_main",
			"digii_ambient_common",
			"digii_ambient_factions",
			"digii_ambient_agents"
		};
		author="DiGii";
		version=0.1;
		versionStr="0.1.0";
		versionAr[]={0,1,0};
	};
};
class CfgFactionClasses
{
	class NO_CATEGORY;
	class digii_ambient_modules: NO_CATEGORY
	{
		displayName="$STR_digii_ambient_zones_module_categoryName";
		priority=1;
		side=7;
	};
};
class Cfg3DEN
{
	class EventHandlers
	{
		class digii_ambient_zones
		{
			onMissionLoad="[] call digii_ambient_zones_fnc_registerDraw3D;";
			onMissionNew="[] call digii_ambient_zones_fnc_registerDraw3D;";
		};
	};
};
class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class ModuleDescription;
	};
	class digii_ambient_module_zone: Module_F
	{
		scope=2;
		scopeCurator=2;
		displayName="$STR_digii_ambient_zones_module_displayName";
		category="digii_ambient_modules";
		function="digii_ambient_zones_fnc_moduleZone";
		functionPriority=1;
		isGlobal=1;
		isTriggerActivated=0;
		is3DEN=1;
		is3DENOnly=0;
		icon="iconModule";
		class ModuleDescription: ModuleDescription
		{
			description="$STR_digii_ambient_zones_module_description";
			sync[]={};
		};
	};
	class digii_ambient_module_zone_civilian: Module_F
	{
		scope=2;
		scopeCurator=2;
		displayName="$STR_digii_ambient_zones_module_displayName_civilian";
		category="digii_ambient_modules";
		function="digii_ambient_zones_fnc_moduleZoneCivilian";
		functionPriority=1;
		isGlobal=1;
		isTriggerActivated=0;
		is3DEN=1;
		is3DENOnly=0;
		icon="iconModule";
		class ModuleDescription: ModuleDescription
		{
			description="$STR_digii_ambient_zones_module_description_civilian";
			sync[]={};
		};
	};
};
class digii_ambient_RscText
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
	x=0;
	y=0;
	h=0.037;
	w=0.30000001;
	style=0;
	shadow=1;
	font="RobotoCondensed";
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	linespacing=1;
};
class digii_ambient_RscEdit
{
	deletable=0;
	fade=0;
	access=0;
	type=2;
	x=0;
	y=0;
	h=0.039999999;
	w=0.2;
	colorBackground[]={0,0,0,0.40000001};
	colorText[]={0.94999999,0.94999999,0.94999999,1};
	colorDisabled[]={1,1,1,0.25};
	colorSelection[]={0.13,0.54000002,0.20999999,1};
	autocomplete="";
	text="";
	size=0.2;
	style="0x00 + 0x40";
	font="RobotoCondensed";
	shadow=2;
	sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	canModify=1;
};
class digii_ambient_RscCombo
{
	deletable=0;
	fade=0;
	access=0;
	type=4;
	colorSelect[]={0,0,0,1};
	colorText[]={1,1,1,1};
	colorBackground[]={0,0,0,0.69999999};
	colorScrollbar[]={0.5,0.5,0.5,1};
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
	colorSelectBackground[]={1,1,1,0.5};
	colorActive[]={1,1,1,1};
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
class digii_ambient_RscCheckBox
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
	x=0;
	y=0;
	w=0.025;
	h=0.039999999;
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
class digii_ambient_RscButton
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
class digii_ambient_IGUIBack
{
	colorText[]={0,0,0,0};
	colorbackground[]={0,0,0,0.85000002};
	type=0;
	idc=-1;
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
class digii_ambient_RscFrame
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
class digii_ambient_RscSlider
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
class digii_ambient_RscDisplayZoneSettings
{
	idd=70000;
	movingEnable=1;
	enableSimulation=1;
	onLoad="_this spawn digii_ambient_zones_fnc_initZoneDialog;";
	onUnload="uiNamespace setVariable ['digii_ambient_RscDisplayZoneSettings', displayNull]";
	controlsBackground[]=
	{
		"Background",
		"Frame",
		"TitleBar"
	};
	controls[]=
	{
		"GeneralSettingsHeader",
		"RadiusLabel",
		"RadiusEdit",
		"SubFactionLabel",
		"SubFactionCombo",
		"DensityLabel",
		"DensityEdit",
		"UseBuildingsLabel",
		"UseBuildingsCheck",
		"UseRoadsLabel",
		"UseRoadsCheck",
		"SkillCapLabel",
		"SkillCapEdit",
		"IncludeOfficerLabel",
		"IncludeOfficerCheck",
		"RoleMixHeader",
		"GuardsLabel",
		"GuardsSlider",
		"PatrolsLabel",
		"PatrolsSlider",
		"IdlersLabel",
		"IdlersSlider",
		"WanderersLabel",
		"WanderersSlider",
		"TotalSeparator",
		"TotalLabel",
		"FeedbackText",
		"ApplyButton",
		"CancelButton"
	};
	class Background: digii_ambient_IGUIBack
	{
		idc=-1;
		x="0.20 * safezoneW + safezoneX";
		y="0.22 * safezoneH + safezoneY";
		w="0.60 * safezoneW";
		h="0.51 * safezoneH";
	};
	class Frame: digii_ambient_RscFrame
	{
		idc=-1;
		x="0.20 * safezoneW + safezoneX";
		y="0.22 * safezoneH + safezoneY";
		w="0.60 * safezoneW";
		h="0.51 * safezoneH";
	};
	class TitleBar: digii_ambient_RscText
	{
		idc=70001;
		text="$STR_digii_ambient_zones_dialog_title";
		x="0.20 * safezoneW + safezoneX";
		y="0.22 * safezoneH + safezoneY";
		w="0.60 * safezoneW";
		h="0.04 * safezoneH";
		colorBackground[]={0.15000001,0.15000001,0.15000001,1};
		style=2;
		sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 22) * 1)";
	};
	class GeneralSettingsHeader: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_generalSettingsHeader";
		x="0.22 * safezoneW + safezoneX";
		y="0.28 * safezoneH + safezoneY";
		w="0.26 * safezoneW";
		h="0.03 * safezoneH";
		style=2;
		colorBackground[]={0.1,0.1,0.1,0.80000001};
	};
	class RoleMixHeader: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_roleMixHeader";
		x="0.52 * safezoneW + safezoneX";
		y="0.28 * safezoneH + safezoneY";
		w="0.26 * safezoneW";
		h="0.03 * safezoneH";
		style=2;
		colorBackground[]={0.1,0.1,0.1,0.80000001};
	};
	class RadiusLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_radius";
		x="0.22 * safezoneW + safezoneX";
		y="0.32 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_radius_tooltip";
	};
	class RadiusEdit: digii_ambient_RscEdit
	{
		idc=70010;
		x="0.36 * safezoneW + safezoneX";
		y="0.32 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		text="75";
	};
	class SubFactionLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_subFaction";
		x="0.22 * safezoneW + safezoneX";
		y="0.36 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_subFaction_tooltip";
	};
	class SubFactionCombo: digii_ambient_RscCombo
	{
		idc=70011;
		x="0.36 * safezoneW + safezoneX";
		y="0.36 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
	};
	class DensityLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_density";
		x="0.22 * safezoneW + safezoneX";
		y="0.40 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_density_tooltip";
	};
	class DensityEdit: digii_ambient_RscEdit
	{
		idc=70013;
		x="0.36 * safezoneW + safezoneX";
		y="0.40 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		text="5";
	};
	class UseBuildingsLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_useBuildings";
		x="0.22 * safezoneW + safezoneX";
		y="0.44 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_useBuildings_tooltip";
	};
	class UseBuildingsCheck: digii_ambient_RscCheckBox
	{
		idc=70014;
		x="0.36 * safezoneW + safezoneX";
		y="0.44 * safezoneH + safezoneY";
		w="0.025 * safezoneW";
		h="0.03 * safezoneH";
	};
	class UseRoadsLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_useRoads";
		x="0.22 * safezoneW + safezoneX";
		y="0.48 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_useRoads_tooltip";
	};
	class UseRoadsCheck: digii_ambient_RscCheckBox
	{
		idc=70015;
		x="0.36 * safezoneW + safezoneX";
		y="0.48 * safezoneH + safezoneY";
		w="0.025 * safezoneW";
		h="0.03 * safezoneH";
	};
	class SkillCapLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_skillCap";
		x="0.22 * safezoneW + safezoneX";
		y="0.52 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_skillCap_tooltip";
	};
	class SkillCapEdit: digii_ambient_RscEdit
	{
		idc=70016;
		x="0.36 * safezoneW + safezoneX";
		y="0.52 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		text="0.2";
	};
	class IncludeOfficerLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_includeOfficer";
		x="0.22 * safezoneW + safezoneX";
		y="0.56 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_includeOfficer_tooltip";
	};
	class IncludeOfficerCheck: digii_ambient_RscCheckBox
	{
		idc=70017;
		x="0.36 * safezoneW + safezoneX";
		y="0.56 * safezoneH + safezoneY";
		w="0.025 * safezoneW";
		h="0.03 * safezoneH";
	};
	class GuardsLabel: digii_ambient_RscText
	{
		idc=70031;
		text="Guards: 25%";
		x="0.52 * safezoneW + safezoneX";
		y="0.32 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_role_guards_tooltip";
	};
	class GuardsSlider: digii_ambient_RscSlider
	{
		idc=70030;
		x="0.65 * safezoneW + safezoneX";
		y="0.325 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.025 * safezoneH";
		onSliderPosChanged="_this call digii_ambient_zones_fnc_updateRoleMixDisplay;";
	};
	class PatrolsLabel: digii_ambient_RscText
	{
		idc=70033;
		text="Patrols: 25%";
		x="0.52 * safezoneW + safezoneX";
		y="0.36 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_role_patrols_tooltip";
	};
	class PatrolsSlider: digii_ambient_RscSlider
	{
		idc=70032;
		x="0.65 * safezoneW + safezoneX";
		y="0.365 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.025 * safezoneH";
		onSliderPosChanged="_this call digii_ambient_zones_fnc_updateRoleMixDisplay;";
	};
	class IdlersLabel: digii_ambient_RscText
	{
		idc=70035;
		text="Idlers: 20%";
		x="0.52 * safezoneW + safezoneX";
		y="0.40 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_role_idlers_tooltip";
	};
	class IdlersSlider: digii_ambient_RscSlider
	{
		idc=70034;
		x="0.65 * safezoneW + safezoneX";
		y="0.405 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.025 * safezoneH";
		onSliderPosChanged="_this call digii_ambient_zones_fnc_updateRoleMixDisplay;";
	};
	class WanderersLabel: digii_ambient_RscText
	{
		idc=70037;
		text="Wanderers: 10%";
		x="0.52 * safezoneW + safezoneX";
		y="0.44 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_role_wanderers_tooltip";
	};
	class WanderersSlider: digii_ambient_RscSlider
	{
		idc=70036;
		x="0.65 * safezoneW + safezoneX";
		y="0.445 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.025 * safezoneH";
		onSliderPosChanged="_this call digii_ambient_zones_fnc_updateRoleMixDisplay;";
	};
	class TotalSeparator: digii_ambient_RscText
	{
		idc=-1;
		text="";
		x="0.52 * safezoneW + safezoneX";
		y="0.49 * safezoneH + safezoneY";
		w="0.26 * safezoneW";
		h="0.002 * safezoneH";
		colorBackground[]={0.5,0.5,0.5,0.5};
	};
	class TotalLabel: digii_ambient_RscText
	{
		idc=70040;
		text="Total: 100%";
		x="0.52 * safezoneW + safezoneX";
		y="0.50 * safezoneH + safezoneY";
		w="0.26 * safezoneW";
		h="0.03 * safezoneH";
		style=2;
		tooltip="$STR_digii_ambient_zones_dialog_total_tooltip";
	};
	class FeedbackText: digii_ambient_RscText
	{
		idc=70080;
		text="";
		x="0.22 * safezoneW + safezoneX";
		y="0.61 * safezoneH + safezoneY";
		w="0.56 * safezoneW";
		h="0.04 * safezoneH";
		colorText[]={1,0.34999999,0.34999999,1};
		style=2;
		sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 22) * 1)";
	};
	class ApplyButton: digii_ambient_RscButton
	{
		idc=70090;
		text="$STR_digii_ambient_zones_dialog_apply";
		x="0.41 * safezoneW + safezoneX";
		y="0.67 * safezoneH + safezoneY";
		w="0.08 * safezoneW";
		h="0.04 * safezoneH";
		onButtonClick="[] call digii_ambient_zones_fnc_applyZoneDialog;";
	};
	class CancelButton: digii_ambient_RscButton
	{
		idc=70091;
		text="$STR_digii_ambient_zones_dialog_cancel";
		x="0.51 * safezoneW + safezoneX";
		y="0.67 * safezoneH + safezoneY";
		w="0.08 * safezoneW";
		h="0.04 * safezoneH";
		onButtonClick="[] call digii_ambient_zones_fnc_cancelZoneDialog;";
	};
};
class digii_ambient_RscDisplayZoneSettingsCivilian
{
	idd=70100;
	movingEnable=1;
	enableSimulation=1;
	onLoad="_this spawn digii_ambient_zones_fnc_initZoneDialogCivilian;";
	onUnload="uiNamespace setVariable ['digii_ambient_RscDisplayZoneSettingsCivilian', displayNull]";
	controlsBackground[]=
	{
		"Background",
		"Frame",
		"TitleBar"
	};
	controls[]=
	{
		"GeneralSettingsHeader",
		"RadiusLabel",
		"RadiusEdit",
		"SubFactionLabel",
		"SubFactionCombo",
		"DensityLabel",
		"DensityEdit",
		"UseBuildingsLabel",
		"UseBuildingsCheck",
		"UseRoadsLabel",
		"UseRoadsCheck",
		"RoleMixHeader",
		"ResidentsLabel",
		"ResidentsSlider",
		"IdlersLabel",
		"IdlersSlider",
		"WanderersLabel",
		"WanderersSlider",
		"TotalSeparator",
		"TotalLabel",
		"FeedbackText",
		"ApplyButton",
		"CancelButton"
	};
	class Background: digii_ambient_IGUIBack
	{
		idc=-1;
		x="0.20 * safezoneW + safezoneX";
		y="0.22 * safezoneH + safezoneY";
		w="0.60 * safezoneW";
		h="0.43 * safezoneH";
	};
	class Frame: digii_ambient_RscFrame
	{
		idc=-1;
		x="0.20 * safezoneW + safezoneX";
		y="0.22 * safezoneH + safezoneY";
		w="0.60 * safezoneW";
		h="0.43 * safezoneH";
	};
	class TitleBar: digii_ambient_RscText
	{
		idc=70101;
		text="$STR_digii_ambient_zones_dialog_civilian_title";
		x="0.20 * safezoneW + safezoneX";
		y="0.22 * safezoneH + safezoneY";
		w="0.60 * safezoneW";
		h="0.04 * safezoneH";
		colorBackground[]={0.15000001,0.15000001,0.15000001,1};
		style=2;
		sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 22) * 1)";
	};
	class GeneralSettingsHeader: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_generalSettingsHeader";
		x="0.22 * safezoneW + safezoneX";
		y="0.28 * safezoneH + safezoneY";
		w="0.26 * safezoneW";
		h="0.03 * safezoneH";
		style=2;
		colorBackground[]={0.1,0.1,0.1,0.80000001};
	};
	class RoleMixHeader: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_roleMixHeader";
		x="0.52 * safezoneW + safezoneX";
		y="0.28 * safezoneH + safezoneY";
		w="0.26 * safezoneW";
		h="0.03 * safezoneH";
		style=2;
		colorBackground[]={0.1,0.1,0.1,0.80000001};
	};
	class RadiusLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_radius";
		x="0.22 * safezoneW + safezoneX";
		y="0.32 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_radius_tooltip";
	};
	class RadiusEdit: digii_ambient_RscEdit
	{
		idc=70110;
		x="0.36 * safezoneW + safezoneX";
		y="0.32 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		text="75";
	};
	class SubFactionLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_subFaction";
		x="0.22 * safezoneW + safezoneX";
		y="0.36 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_subFaction_tooltip";
	};
	class SubFactionCombo: digii_ambient_RscCombo
	{
		idc=70111;
		x="0.36 * safezoneW + safezoneX";
		y="0.36 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
	};
	class DensityLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_density";
		x="0.22 * safezoneW + safezoneX";
		y="0.40 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_density_tooltip";
	};
	class DensityEdit: digii_ambient_RscEdit
	{
		idc=70113;
		x="0.36 * safezoneW + safezoneX";
		y="0.40 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		text="5";
	};
	class UseBuildingsLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_useBuildings";
		x="0.22 * safezoneW + safezoneX";
		y="0.44 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_useBuildings_tooltip";
	};
	class UseBuildingsCheck: digii_ambient_RscCheckBox
	{
		idc=70114;
		x="0.36 * safezoneW + safezoneX";
		y="0.44 * safezoneH + safezoneY";
		w="0.025 * safezoneW";
		h="0.03 * safezoneH";
	};
	class UseRoadsLabel: digii_ambient_RscText
	{
		idc=-1;
		text="$STR_digii_ambient_zones_dialog_useRoads";
		x="0.22 * safezoneW + safezoneX";
		y="0.48 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_dialog_useRoads_tooltip";
	};
	class UseRoadsCheck: digii_ambient_RscCheckBox
	{
		idc=70115;
		x="0.36 * safezoneW + safezoneX";
		y="0.48 * safezoneH + safezoneY";
		w="0.025 * safezoneW";
		h="0.03 * safezoneH";
	};
	class ResidentsLabel: digii_ambient_RscText
	{
		idc=70131;
		text="Residents: 34%";
		x="0.52 * safezoneW + safezoneX";
		y="0.32 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_role_residents_tooltip";
	};
	class ResidentsSlider: digii_ambient_RscSlider
	{
		idc=70130;
		x="0.65 * safezoneW + safezoneX";
		y="0.325 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.025 * safezoneH";
		onSliderPosChanged="_this call digii_ambient_zones_fnc_updateRoleMixDisplayCivilian;";
	};
	class IdlersLabel: digii_ambient_RscText
	{
		idc=70133;
		text="Idlers: 33%";
		x="0.52 * safezoneW + safezoneX";
		y="0.36 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_role_idlers_tooltip";
	};
	class IdlersSlider: digii_ambient_RscSlider
	{
		idc=70132;
		x="0.65 * safezoneW + safezoneX";
		y="0.365 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.025 * safezoneH";
		onSliderPosChanged="_this call digii_ambient_zones_fnc_updateRoleMixDisplayCivilian;";
	};
	class WanderersLabel: digii_ambient_RscText
	{
		idc=70135;
		text="Wanderers: 33%";
		x="0.52 * safezoneW + safezoneX";
		y="0.40 * safezoneH + safezoneY";
		w="0.12 * safezoneW";
		h="0.03 * safezoneH";
		tooltip="$STR_digii_ambient_zones_role_wanderers_tooltip";
	};
	class WanderersSlider: digii_ambient_RscSlider
	{
		idc=70134;
		x="0.65 * safezoneW + safezoneX";
		y="0.405 * safezoneH + safezoneY";
		w="0.13 * safezoneW";
		h="0.025 * safezoneH";
		onSliderPosChanged="_this call digii_ambient_zones_fnc_updateRoleMixDisplayCivilian;";
	};
	class TotalSeparator: digii_ambient_RscText
	{
		idc=-1;
		text="";
		x="0.52 * safezoneW + safezoneX";
		y="0.47 * safezoneH + safezoneY";
		w="0.26 * safezoneW";
		h="0.002 * safezoneH";
		colorBackground[]={0.5,0.5,0.5,0.5};
	};
	class TotalLabel: digii_ambient_RscText
	{
		idc=70140;
		text="Total: 100%";
		x="0.52 * safezoneW + safezoneX";
		y="0.48 * safezoneH + safezoneY";
		w="0.26 * safezoneW";
		h="0.03 * safezoneH";
		style=2;
		tooltip="$STR_digii_ambient_zones_dialog_total_tooltip";
	};
	class FeedbackText: digii_ambient_RscText
	{
		idc=70180;
		text="";
		x="0.22 * safezoneW + safezoneX";
		y="0.53 * safezoneH + safezoneY";
		w="0.56 * safezoneW";
		h="0.04 * safezoneH";
		colorText[]={1,0.34999999,0.34999999,1};
		style=2;
		sizeEx="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 22) * 1)";
	};
	class ApplyButton: digii_ambient_RscButton
	{
		idc=70190;
		text="$STR_digii_ambient_zones_dialog_apply";
		x="0.41 * safezoneW + safezoneX";
		y="0.59 * safezoneH + safezoneY";
		w="0.08 * safezoneW";
		h="0.04 * safezoneH";
		onButtonClick="[] call digii_ambient_zones_fnc_applyZoneDialogCivilian;";
	};
	class CancelButton: digii_ambient_RscButton
	{
		idc=70191;
		text="$STR_digii_ambient_zones_dialog_cancel";
		x="0.51 * safezoneW + safezoneX";
		y="0.59 * safezoneH + safezoneY";
		w="0.08 * safezoneW";
		h="0.04 * safezoneH";
		onButtonClick="[] call digii_ambient_zones_fnc_cancelZoneDialogCivilian;";
	};
};
class Extended_PreInit_EventHandlers
{
	class digii_ambient_zones
	{
		init="call compile preProcessFileLineNumbers '\z\digii_ambient\addons\zones\XEH_preInit.sqf'";
		disableModuload="true";
	};
};
class Extended_PostInit_EventHandlers
{
	class digii_ambient_zones
	{
		init="call compile preProcessFileLineNumbers '\z\digii_ambient\addons\zones\XEH_postInit.sqf'";
	};
};
