class CfgPatches
{
	class zen_tasks
	{
		name="ZEN - Tasks";
		units[]=
		{
			"zen_tasks_module"
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
				"zen_tasks"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_tasks
	{
		init="call compileScript ['\x\zen\addons\tasks\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_tasks
	{
		init="call compileScript ['\x\zen\addons\tasks\XEH_preInit.sqf']";
	};
};
class CfgTaskTypes
{
	class Default
	{
		displayName="$STR_zen_tasks_Default";
	};
	class airdrop
	{
		displayName="$STR_zen_tasks_Airdrop";
	};
	class armor
	{
		displayName="$STR_A3_cfggroups_west_blu_f_armored0";
	};
	class attack
	{
		displayName="$STR_A3_om_system_restui_tasktooltip";
	};
	class backpack
	{
		displayName="$STR_A3_requiredgear_listitem_backpack";
	};
	class boat
	{
		displayName="$STR_A3_cfgvehicles_abandonedboats_base_f0";
	};
	class box
	{
		displayName="$STR_zen_tasks_Box";
	};
	class car
	{
		displayName="$STR_DN_car";
	};
	class container
	{
		displayName="$STR_zen_tasks_Container";
	};
	class danger
	{
		displayName="$STR_zen_tasks_Danger";
	};
	class defend
	{
		displayName="$STR_A3_modulemptypedefense";
	};
	class destroy
	{
		displayName="$STR_cfg_markers_destroy";
	};
	class documents
	{
		displayName="$STR_A3_cfgvehicles_intel_file1_f";
	};
	class download
	{
		displayName="$STR_A3_endgame_misc_download";
	};
	class exit
	{
		displayName="$STR_zen_tasks_Exit";
	};
	class getin
	{
		displayName="$STR_rscMenu.hppRscGroupRootMenu_Items_GetIn1";
	};
	class getout
	{
		displayName="$STR_action_getout";
	};
	class heal
	{
		displayName="$STR_state_healsoldier";
	};
	class heli
	{
		displayName="$STR_DN_helicopter";
	};
	class help
	{
		displayName="$STR_3den_display3den_menubar_help_text";
	};
	class intel
	{
		displayName="$STR_A3_cfgvehicleclasses_intel0";
	};
	class interact
	{
		displayName="$STR_rscmenu.hpprscgrouprootmenu_items_empty1";
	};
	class kill
	{
		displayName="$STR_zen_tasks_Kill";
	};
	class land
	{
		displayName="$STR_A3_showcase_jets_bis_tskland_title";
	};
	class listen
	{
		displayName="$STR_zen_tasks_Listen";
	};
	class map
	{
		displayName="$STR_A3_cfghints_curator_map_displayname";
	};
	class meet
	{
		displayName="$STR_zen_tasks_Meet";
	};
	class mine
	{
		displayName="$STR_A3_MP_GS_SC_03_Sector_Mine";
	};
	class move
	{
		displayName="$STR_A3_cfgvehicles_moduleobjectivemove_f";
	};
	class move1
	{
		displayName="$STR_zen_tasks_Move1";
	};
	class move2
	{
		displayName="$STR_zen_tasks_Move2";
	};
	class move3
	{
		displayName="$STR_zen_tasks_Move3";
	};
	class move4
	{
		displayName="$STR_zen_tasks_Move4";
	};
	class move5
	{
		displayName="$STR_zen_tasks_Move5";
	};
	class navigate
	{
		displayName="$STR_zen_tasks_Navigate";
	};
	class plane
	{
		displayName="$STR_DN_plane";
	};
	class radio
	{
		displayName="$STR_radio";
	};
	class rearm
	{
		displayName="$STR_rearm";
	};
	class refuel
	{
		displayName="$STR_refuel";
	};
	class repair
	{
		displayName="$STR_repair";
	};
	class rifle
	{
		displayName="$STR_DN_rifle";
	};
	class run
	{
		displayName="$STR_zen_tasks_Run";
	};
	class scout
	{
		displayName="$STR_zen_tasks_Scout";
	};
	class search
	{
		displayName="$STR_zen_tasks_Search";
	};
	class takeoff
	{
		displayName="$STR_A3_showcase_jets_bis_tsktakeoff_title";
	};
	class talk
	{
		displayName="$STR_zen_tasks_Talk";
	};
	class talk1
	{
		displayName="$STR_zen_tasks_Talk1";
	};
	class talk2
	{
		displayName="$STR_zen_tasks_Talk2";
	};
	class talk3
	{
		displayName="$STR_zen_tasks_Talk3";
	};
	class talk4
	{
		displayName="$STR_zen_tasks_Talk4";
	};
	class talk5
	{
		displayName="$STR_zen_tasks_Talk5";
	};
	class target
	{
		displayName="$STR_DN_target";
	};
	class truck
	{
		displayName="$STR_DN_truck";
	};
	class unknown
	{
		displayName="$STR_DN_unknowns";
	};
	class upload
	{
		displayName="$STR_zen_tasks_Upload";
	};
	class use
	{
		displayName="$STR_zen_tasks_Use";
	};
	class wait
	{
		displayName="$STR_state_expect";
	};
	class walk
	{
		displayName="$STR_usract_walk";
	};
	class whiteboard
	{
		displayName="$STR_zen_tasks_Whiteboard";
	};
};
class CfgVehicles
{
	class Module_F;
	class ModuleObjective_F: Module_F
	{
		scopeCurator=1;
	};
	class ModuleObjectiveMove_F: ModuleObjective_F
	{
		scopeCurator=2;
	};
	class ModuleObjectiveSector_F: ModuleObjective_F
	{
		scopeCurator=2;
	};
	class ModuleObjectiveAttackDefend_F: ModuleObjective_F
	{
		scopeCurator=2;
	};
	class ModuleObjectiveNeutralize_F: ModuleObjective_F
	{
		scopeCurator=2;
	};
	class ModuleObjectiveProtect_F: ModuleObjective_F
	{
		scopeCurator=2;
	};
	class ModuleObjectiveGetIn_F: ModuleObjective_F
	{
		scopeCurator=2;
	};
	class ModuleObjectiveRaceStart_F: ModuleObjective_F
	{
		scopeCurator=2;
	};
	class ModuleObjectiveRaceCP_F: ModuleObjective_F
	{
		scopeCurator=2;
	};
	class ModuleObjectiveRaceFinish_F: ModuleObjective_F
	{
		scopeCurator=2;
	};
	class zen_modules_moduleBase;
	class zen_tasks_module: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="Objectives";
		displayName="$STR_A3_CfgVehicles_ModuleObjective_F";
		curatorInfoType="zen_tasks_RscTasks";
		icon="\a3\modules_f_curator\data\portraitobjective_ca.paa";
		portrait="\a3\modules_f_curator\data\portraitobjective_ca.paa";
	};
};
class ctrlCombo;
class ctrlToolbox;
class ctrlToolboxPictureKeepAspect;
class zen_common_RscLabel;
class zen_common_RscEdit;
class zen_common_RscOwners;
class zen_common_RscDisplay
{
	class controls;
};
class zen_modules_RscDisplay: zen_common_RscDisplay
{
	class controls: controls
	{
		class Title;
		class Background;
		class Content;
		class ButtonOK;
		class ButtonCancel;
	};
};
class zen_tasks_RscTasks: zen_modules_RscDisplay
{
	function="zen_tasks_fnc_init";
	checkLogic=1;
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
			h="((24.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class OwnersLabel: zen_common_RscLabel
				{
					text="$STR_A3_RscAttributeOwners_Title";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class Owners: zen_common_RscOwners
				{
					idc=900;
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class StateLabel: zen_common_RscLabel
				{
					text="$STR_A3_RscAttributeTaskState_Title";
					y="((11.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class State: ctrlToolboxPictureKeepAspect
				{
					idc=910;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((11.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((15.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					rows=1;
					columns=5;
					strings[]=
					{
						"\a3\3DEN\Data\Attributes\TaskStates\created_ca.paa",
						"\a3\3DEN\Data\Attributes\TaskStates\assigned_ca.paa",
						"\a3\3DEN\Data\Attributes\TaskStates\succeeded_ca.paa",
						"\a3\3DEN\Data\Attributes\TaskStates\failed_ca.paa",
						"\a3\3DEN\Data\Attributes\TaskStates\canceled_ca.paa"
					};
					tooltips[]=
					{
						"$STR_A3_CfgVehicles_ModuleTaskSetState_F_Arguments_State_Values_Created_0",
						"$STR_A3_CfgVehicles_ModuleTaskSetState_F_Arguments_State_Values_Assigned_0",
						"$STR_A3_CfgVehicles_ModuleTaskSetState_F_Arguments_State_Values_Succeeded_0",
						"$STR_A3_CfgVehicles_ModuleTaskSetState_F_Arguments_State_Values_Failed_0",
						"$STR_A3_CfgVehicles_ModuleTaskSetState_F_Arguments_State_Values_Canceled_0"
					};
				};
				class DestinationLabel: zen_common_RscLabel
				{
					text="$STR_A3_CfgVehicles_ModuleTaskSetDestination_F_Arguments_Destination_0";
					y="((13.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Destination: ctrlToolbox
				{
					idc=920;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((13.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((15.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					rows=1;
					columns=2;
					strings[]=
					{
						"$STR_zen_common_Disabled",
						"$STR_zen_tasks_ModulePosition"
					};
					tooltips[]=
					{
						"$STR_zen_tasks_DestinationDisabled_Tooltip",
						"$STR_zen_tasks_ModulePosition_Tooltip"
					};
				};
				class TypeLabel: zen_common_RscLabel
				{
					text="$STR_A3_cfgvehicles_moduletaskcreate_f_arguments_type_0";
					tooltip="$STR_zen_tasks_Type_Tooltip";
					y="((14.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Type: ctrlCombo
				{
					idc=930;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((14.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((15.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class TitleDescriptionLabel: zen_common_RscLabel
				{
					text="$STR_zen_tasks_TitleDescription";
					tooltip="$STR_zen_tasks_TitleDescription_Tooltip";
					y="((15.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class History: Type
				{
					idc=940;
					y="((15.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Title: zen_common_RscEdit
				{
					idc=950;
					x="pixelW";
					y="((16.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40)) - pixelW";
				};
				class Description: zen_common_RscEdit
				{
					idc=960;
					style=16;
					x="pixelW";
					y="((17.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40)) - pixelW";
					h="((7.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					sizeEx="((0.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
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
