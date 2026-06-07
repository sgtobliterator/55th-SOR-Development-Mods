class CfgPatches
{
	class zen_markers_tree
	{
		name="ZEN - Markers Tree";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_area_markers",
			"zen_editor"
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
				"zen_markers_tree"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_markers_tree
	{
		init="call compileScript ['\x\zen\addons\markers_tree\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_markers_tree
	{
		init="call compileScript ['\x\zen\addons\markers_tree\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_markers_tree
	{
		init="call compileScript ['\x\zen\addons\markers_tree\XEH_postInit.sqf']";
	};
};
class RscActivePicture;
class RscControlsGroupNoScrollbars;
class RscDisplayCurator
{
	class Controls
	{
		class Add: RscControlsGroupNoScrollbars
		{
			class controls
			{
				class zen_markers_tree_modeIcons: RscActivePicture
				{
					idc=92800;
					text="\a3\3den\data\displays\display3den\panelright\submode_marker_icon_ca.paa";
					tooltip="$STR_3DEN_Marker_Mode_Icon";
					x="((7.4/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((2.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((1.8) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class zen_markers_tree_modeAreas: zen_markers_tree_modeIcons
				{
					idc=92810;
					text="\a3\3den\data\displays\display3den\panelright\submode_marker_area_ca.paa";
					tooltip="$STR_3DEN_Marker_Mode_Area";
					x="((1.8 + 2 * 7.4/3) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class CreateUnitsWest;
				class CreateMarkers: CreateUnitsWest
				{
					idcSearch=-1;
					x=0;
					y=0;
					w=0;
					h=0;
				};
				class zen_markers_tree_treeIcons: CreateUnitsWest
				{
					idc=92820;
					idcSearch=283;
					colorPictureSelected[]={1,1,1,1};
				};
				class zen_markers_tree_treeAreas: zen_markers_tree_treeIcons
				{
					idc=92830;
					colorPictureSelected[]={0,0,0,1};
				};
			};
		};
	};
};
