class CfgPatches
{
	class zen_editor
	{
		name="ZEN - Editor";
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
				"zen_editor"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_editor
	{
		init="call compileScript ['\x\zen\addons\editor\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_editor
	{
		init="call compileScript ['\x\zen\addons\editor\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_editor
	{
		init="call compileScript ['\x\zen\addons\editor\XEH_postInit.sqf']";
	};
};
class CfgFunctions
{
	class A3_Functions_F_Curator
	{
		class Curator
		{
			class curatorObjectEdited
			{
				file="\x\zen\addons\editor\functions\fnc_bi_curatorObjectEdited.sqf";
			};
			class curatorObjectPlaced
			{
				file="\x\zen\addons\editor\functions\fnc_bi_curatorObjectPlaced.sqf";
			};
			class curatorWaypointPlaced
			{
				file="\x\zen\addons\editor\functions\fnc_bi_curatorWaypointPlaced.sqf";
			};
		};
	};
};
class CfgCurator
{
	class DrawWaypoint
	{
		class 3D
		{
			texture="\a3\3den\data\cfgwaypoints\move_ca.paa";
			textureCycle="\a3\3den\data\cfgwaypoints\cycle_ca.paa";
			texturePreview="\a3\3den\data\cfgwaypoints\move_ca.paa";
		};
		class 2D
		{
			texture="\a3\3den\data\cfgwaypoints\move_ca.paa";
			textureCycle="\a3\3den\data\cfgwaypoints\cycle_ca.paa";
			texturePreview="\a3\3den\data\cfgwaypoints\move_ca.paa";
		};
	};
};
class RscText;
class RscEdit;
class RscLine;
class RscFrame;
class RscPicture;
class RscButtonSearch;
class RscControlsGroupNoScrollbars;
class RscTree
{
	class ScrollBar;
};
class zen_common_RscCheckbox;
class RscDisplayCurator
{
	class Controls
	{
		class Main: RscControlsGroupNoScrollbars
		{
			x="safeZoneX + ([12.5, 11] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)";
			y="safeZoneY + ([0.5, 0] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="safeZoneW - ([25, 22] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)";
			class controls
			{
				class PointsBackground: RscText
				{
					w="safeZoneW - ([25, 22] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)";
				};
				class Points: RscText
				{
					w="safeZoneW - ([25, 22] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)";
				};
				class PointsPreview: RscText
				{
					x="([7, 8] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)";
				};
				class PointsFrame: RscFrame
				{
					w="safeZoneW - ([25, 22] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)";
				};
				class Logo: RscPicture
				{
					x="(safeZoneW - ([25, 22] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)) / 2 - 0.5 * (((safezoneW / safezoneH) min 1.2) / 40)";
				};
				class FeedbackMessage: RscText
				{
					w="safeZoneW - ([25, 22] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)";
				};
			};
		};
		class AddBar: RscControlsGroupNoScrollbars
		{
			x="safeZoneX + safeZoneW - ([12.5, 11] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)";
			y="safeZoneY + ([0.5, 0] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Add: RscControlsGroupNoScrollbars
		{
			x="safeZoneX + safeZoneW - ([12.5, 11] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)";
			y="safeZoneY + ([1.5, 1] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			h="safeZoneH - ([2, 1] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class CreateBackground: RscText
				{
					h="safeZoneH - ([2, 1] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CreateClassesBackground: RscText
				{
					h="safeZoneH - ([6, 5] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CreateFrame: RscFrame
				{
					h="safeZoneH - ([6, 5] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CreateSearch: RscEdit
				{
					x="0.15 * (((safezoneW / safezoneH) min 1.2) / 40)";
					w="7.7 * (((safezoneW / safezoneH) min 1.2) / 40)";
				};
				class CreateSearchButton: RscButtonSearch
				{
					x="7.9 * (((safezoneW / safezoneH) min 1.2) / 40)";
				};
				class CollapseAll: CreateSearchButton
				{
					idc=25480;
					text="\a3\3DEN\Data\Displays\Display3DEN\tree_collapse_ca.paa";
					tooltip="$STR_3DEN_ctrlButtonCollapseAll_text";
					x="8.9 * (((safezoneW / safezoneH) min 1.2) / 40)";
				};
				class ExpandAll: CollapseAll
				{
					idc=25490;
					text="\x\zen\addons\editor\ui\tree_expand_ca.paa";
					tooltip="$STR_3DEN_ctrlButtonExpandAll_text";
					x="9.9 * (((safezoneW / safezoneH) min 1.2) / 40)";
				};
				class CreateUnitsWest: RscTree
				{
					h="safeZoneH - ([8.1, 7.1] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					class ScrollBar: ScrollBar
					{
						thumb="\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
						border="\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
						arrowFull="\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
						arrowEmpty="\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
					};
				};
				class VehicleCrew: RscControlsGroupNoScrollbars
				{
					x=0;
					y="safeZoneH - ([3, 2] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="11 * (((safezoneW / safezoneH) min 1.2) / 40)";
					h="((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					class controls
					{
						class Background: RscText
						{
							x=0;
							y=0;
							w="11 * (((safezoneW / safezoneH) min 1.2) / 40)";
							h="((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							colorBackground[]={0,0,0,0.2};
						};
						class Line: RscLine
						{
							x=0;
							y="pixelH";
							w="11 * (((safezoneW / safezoneH) min 1.2) / 40)";
							h=0;
							colorText[]={0,0,0,1};
						};
						class Label: RscText
						{
							text="$STR_3DEN_Display3DEN_VehiclePanel_TextEmpty_text";
							x="(((safezoneW / safezoneH) min 1.2) / 40)";
							y=0;
							w="10 * (((safezoneW / safezoneH) min 1.2) / 40)";
							h="((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							sizeEx="0.9 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
							shadow=0;
						};
						class Toggle: zen_common_RscCheckbox
						{
							idc=25460;
							onLoad="(_this select 0) cbSetChecked zen_editor_includeCrew";
							onCheckedChanged="zen_editor_includeCrew = !zen_editor_includeCrew";
							x="0.1 * (((safezoneW / safezoneH) min 1.2) / 40)";
							y=0;
							w="(((safezoneW / safezoneH) min 1.2) / 40)";
							h="((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
						};
					};
				};
			};
		};
		class MissionBar: RscControlsGroupNoScrollbars
		{
			x="safeZoneX + ([1.5, 0] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)";
			y="safeZoneY + ([0.5, 0] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class Mission: RscControlsGroupNoScrollbars
		{
			x="safeZoneX + ([1.5, 0] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * (((safezoneW / safezoneH) min 1.2) / 40)";
			y="safeZoneY + ([1.5, 1] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			h="safeZoneH - ([2, 1] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class controls
			{
				class EntitiesBackground: RscText
				{
					h="safeZoneH - ([2, 1] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class EntitiesFrame: RscFrame
				{
					h="safeZoneH - ([2, 1] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Entities: RscTree
				{
					h="safeZoneH - ([2, 1] select (missionNamespace getVariable [""zen_editor_moveDisplayToEdge"", false])) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					class ScrollBar: ScrollBar
					{
						thumb="\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
						border="\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
						arrowFull="\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
						arrowEmpty="\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
					};
				};
			};
		};
	};
};
