class CfgPatches
{
	class zen_context_actions
	{
		name="ZEN - Context Actions";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_context_menu",
			"zen_garage",
			"zen_inventory",
			"zen_remote_control"
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
				"zen_context_actions"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_context_actions
	{
		init="call compileScript ['\x\zen\addons\context_actions\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_context_actions
	{
		init="call compileScript ['\x\zen\addons\context_actions\XEH_preInit.sqf']";
	};
};
class zen_context_menu_actions
{
	class FireArtillery
	{
		displayName="$STR_zen_context_actions_FireArtillery";
		icon="\a3\ui_f\data\gui\cfg\communicationmenu\artillery_ca.paa";
		insertChildren="_objects call zen_context_actions_fnc_getArtilleryActions";
		priority=70;
	};
	class ThrowGrenade
	{
		displayName="$STR_zen_context_actions_ThrowGrenade";
		icon="\x\zen\addons\context_actions\ui\grenade_ca.paa";
		insertChildren="_objects call zen_context_actions_fnc_getGrenadeActions";
		priority=70;
	};
	class Formation
	{
		displayName="$STR_3DEN_Group_Attribute_Formation_displayName";
		condition="_groups findIf {units _x findIf {!isPlayer _x} != -1} != -1";
		icon="\a3\3den\data\displays\display3den\entitymenu\movetoformation_ca.paa";
		priority=60;
		class Wedge
		{
			displayName="$STR_wedge";
			statement="[_groups, _args] call zen_context_actions_fnc_setFormation";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\wedge_ca.paa";
			args="WEDGE";
		};
		class Vee: Wedge
		{
			displayName="$STR_vee";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\vee_ca.paa";
			args="VEE";
		};
		class Line: Wedge
		{
			displayName="$STR_line";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\line_ca.paa";
			args="LINE";
		};
		class Column: Wedge
		{
			displayName="$STR_column";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\column_ca.paa";
			args="COLUMN";
		};
		class File: Wedge
		{
			displayName="$STR_file";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\file_ca.paa";
			args="FILE";
		};
		class StagColumn: Wedge
		{
			displayName="$STR_staggered";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\stag_column_ca.paa";
			args="STAG COLUMN";
		};
		class EchLeft: Wedge
		{
			displayName="$STR_echl";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\ech_left_ca.paa";
			args="ECH LEFT";
		};
		class EchRight: Wedge
		{
			displayName="$STR_echr";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\ech_right_ca.paa";
			args="ECH RIGHT";
		};
		class Diamond: Wedge
		{
			displayName="$STR_diamond";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeFormation\diamond_ca.paa";
			args="DIAMOND";
		};
	};
	class Behaviour
	{
		displayName="$STR_3DEN_Group_Attribute_Behaviour_displayName";
		condition="_groups findIf {units _x findIf {!isPlayer _x} != -1} != -1";
		icon="\x\zen\addons\context_actions\ui\careless_ca.paa";
		priority=59;
		class Safe
		{
			displayName="$STR_safe";
			statement="[_groups, _args] call zen_context_actions_fnc_setBehaviour";
			icon="\x\zen\addons\context_actions\ui\safe_ca.paa";
			iconColor[]={0,1,0,1};
			args="SAFE";
		};
		class Aware: Safe
		{
			displayName="$STR_aware";
			icon="\x\zen\addons\context_actions\ui\aware_ca.paa";
			iconColor[]={1,1,0,1};
			args="AWARE";
		};
		class Combat: Safe
		{
			displayName="$STR_combat";
			icon="\x\zen\addons\context_actions\ui\combat_ca.paa";
			iconColor[]={1,0,0,1};
			args="COMBAT";
		};
		class Stealth: Safe
		{
			displayName="$STR_stealth";
			icon="\x\zen\addons\context_actions\ui\stealth_ca.paa";
			iconColor[]={0,1,1,1};
			args="STEALTH";
		};
		class Careless: Safe
		{
			displayName="$STR_3DEN_Attributes_Behaviour_Careless_text";
			icon="\x\zen\addons\context_actions\ui\careless_ca.paa";
			iconColor[]={1,1,1,1};
			args="CARELESS";
		};
	};
	class CombatMode
	{
		displayName="$STR_3DEN_Group_Attribute_CombatMode_displayName";
		condition="_groups findIf {units _x findIf {!isPlayer _x} != -1} != -1";
		icon="\x\zen\addons\context_actions\ui\attack_ca.paa";
		priority=58;
		class Blue
		{
			displayName="$STR_zen_context_actions_HoldFire";
			statement="[_groups, _args] call zen_context_actions_fnc_setCombatMode";
			icon="\x\zen\addons\context_actions\ui\hold_ca.paa";
			iconColor[]={1,0,0,1};
			args="BLUE";
		};
		class Green: Blue
		{
			displayName="$STR_zen_context_actions_HoldFireDefend";
			icon="\x\zen\addons\context_actions\ui\defend_ca.paa";
			args="GREEN";
		};
		class White: Blue
		{
			displayName="$STR_zen_context_actions_HoldFireEngage";
			icon="\x\zen\addons\context_actions\ui\engage_ca.paa";
			args="WHITE";
		};
		class Yellow: Blue
		{
			displayName="$STR_zen_context_actions_FireAtWill";
			icon="\x\zen\addons\context_actions\ui\hold_ca.paa";
			iconColor[]={1,1,1,1};
			args="YELLOW";
		};
		class Red: Blue
		{
			displayName="$STR_zen_context_actions_FireAtWillEngage";
			icon="\x\zen\addons\context_actions\ui\engage_ca.paa";
			iconColor[]={1,1,1,1};
			args="RED";
		};
	};
	class SpeedMode
	{
		displayName="$STR_HC_Menu_Speed";
		condition="_groups findIf {units _x findIf {!isPlayer _x} != -1} != -1";
		icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeSpeedMode\normal_ca.paa";
		priority=57;
		class Limited
		{
			displayName="$STR_speed_limited";
			statement="[_groups, _args] call zen_context_actions_fnc_setSpeedMode";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeSpeedMode\limited_ca.paa";
			args="LIMITED";
		};
		class Normal: Limited
		{
			displayName="$STR_speed_normal";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeSpeedMode\normal_ca.paa";
			args="NORMAL";
		};
		class Full: Limited
		{
			displayName="$STR_speed_full";
			icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeSpeedMode\full_ca.paa";
			args="FULL";
		};
	};
	class Stance
	{
		displayName="$STR_A3_RscAttributeUnitPos_Title";
		condition="_objects findIf {alive _x && {_x isKindOf 'CAManBase'} && {!isPlayer _x}} != -1";
		icon="\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_stand_ca.paa";
		priority=56;
		class Up
		{
			displayName="$STR_A3_RscAttributeUnitPos_Up_tooltip";
			statement="[_objects, _args] call zen_context_actions_fnc_setStance";
			icon="\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_stand_ca.paa";
			args="UP";
		};
		class Middle: Up
		{
			displayName="$STR_A3_RscAttributeUnitPos_Crouch_tooltip";
			icon="\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_crouch_ca.paa";
			args="MIDDLE";
		};
		class Down: Up
		{
			displayName="$STR_A3_RscAttributeUnitPos_Down_tooltip";
			icon="\a3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\SI_prone_ca.paa";
			args="DOWN";
		};
		class Auto: Up
		{
			displayName="$STR_A3_RscAttributeUnitPos_Auto_tooltip";
			icon="\x\zen\addons\context_actions\ui\default_ca.paa";
			args="AUTO";
		};
	};
	class HealUnits
	{
		displayName="$STR_State_Heal";
		icon="\x\zen\addons\context_actions\ui\medical_cross_ca.paa";
		priority=50;
		class All
		{
			displayName="$STR_zen_common_All";
			condition="[_objects, _args] call zen_context_actions_fnc_canHealUnits";
			statement="[_objects, _args] call zen_context_actions_fnc_healUnits";
			icon="\x\zen\addons\context_actions\ui\medical_cross_ca.paa";
			args=0;
		};
		class Players: All
		{
			displayName="$STR_zen_modules_Players";
			args=1;
		};
		class AI: All
		{
			displayName="$STR_Team_Switch_AI";
			args=2;
		};
	};
	class Captives
	{
		displayName="$STR_zen_context_actions_Captives";
		condition="isClass (configFile >> 'CfgPatches' >> 'ace_captives')";
		icon="\z\ace\addons\captives\UI\handcuff_ca.paa";
		priority=50;
		class ToggleCaptive
		{
			displayName="$STR_zen_context_actions_ToggleCaptive";
			condition="_objects findIf {alive _x && {_x isKindOf 'CAManBase'}} != -1";
			statement="_objects call zen_context_actions_fnc_toggleCaptive";
			icon="\z\ace\addons\captives\UI\handcuff_ca.paa";
		};
		class ToggleSurrender
		{
			displayName="$STR_zen_context_actions_ToggleSurrender";
			condition="_objects call zen_context_actions_fnc_canToggleSurrender";
			statement="_objects call zen_context_actions_fnc_toggleSurrender";
			icon="\z\ace\addons\captives\UI\Surrender_ca.paa";
		};
	};
	class Loadout
	{
		displayName="$STR_A3_VR_Stamina_01_Loadout";
		condition="_hoveredEntity call zen_context_actions_fnc_canEditLoadout";
		statement="_hoveredEntity call zen_common_fnc_openArsenal";
		icon="\a3\3den\data\displays\display3den\entitymenu\arsenal_ca.paa";
		priority=40;
		class Edit
		{
			displayName="$STR_3DEN_Display3DEN_MenUBar_Edit_text";
			condition="_hoveredEntity call zen_context_actions_fnc_canEditLoadout";
			statement="_hoveredEntity call zen_common_fnc_openArsenal";
			icon="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\customcomposition_edit_ca.paa";
		};
		class Copy
		{
			displayName="$STR_3DEN_Display3DEN_MenuBar_EntityCopy_text";
			statement="zen_context_actions_loadout = _hoveredEntity call CBA_fnc_getLoadout";
			icon="\x\zen\addons\context_actions\ui\copy_ca.paa";
		};
		class Paste
		{
			displayName="$STR_3DEN_Display3DEN_MenuBar_EntityPaste_text";
			condition="!isNil ""zen_context_actions_loadout""";
			statement="[_hoveredEntity, zen_context_actions_loadout] call CBA_fnc_setLoadout";
			icon="\x\zen\addons\context_actions\ui\paste_ca.paa";
		};
		class Reset
		{
			displayName="$STR_A3_RscDisplayCampaignLobby_Reset";
			statement="_hoveredEntity setUnitLoadout configOf _hoveredEntity";
			icon="\a3\3den\Data\Displays\Display3DEN\ToolBar\undo_ca.paa";
		};
		class SwitchWeapon
		{
			displayName="$STR_A3_Switch1";
			icon="\a3\ui_f\data\IGUI\Cfg\Actions\reammo_ca.paa";
			class Primary
			{
				displayName="$STR_A3_RSCDisplayArsenal_Tab_PrimaryWeapon";
				condition="[_hoveredEntity, _args] call zen_context_actions_fnc_canSwitchWeapon";
				statement="[_hoveredEntity, _args] call zen_context_actions_fnc_switchWeapon";
				modifierFunction="call zen_context_actions_fnc_switchWeaponModifier";
				icon="\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\primaryWeapon_ca.paa";
				args=0;
			};
			class Handgun: Primary
			{
				displayName="$STR_A3_RSCDisplayArsenal_Tab_Handgun";
				icon="\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\handgun_ca.paa";
				args=1;
			};
			class Binoculars: Primary
			{
				displayName="$STR_A3_RSCDisplayArsenal_Tab_Binoculars";
				icon="\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\binoculars_ca.paa";
				args=2;
			};
		};
	};
	class Inventory
	{
		displayName="$STR_A3_Gear1";
		condition="_hoveredEntity call zen_context_actions_fnc_canEditInventory";
		statement="_hoveredEntity call zen_inventory_fnc_configure";
		icon="\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_0_ca.paa";
		priority=39;
		class Edit
		{
			displayName="$STR_3DEN_Display3DEN_MenUBar_Edit_text";
			condition="_hoveredEntity call zen_context_actions_fnc_canEditInventory";
			statement="_hoveredEntity call zen_inventory_fnc_configure";
			icon="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\customcomposition_edit_ca.paa";
		};
		class Copy
		{
			displayName="$STR_3DEN_Display3DEN_MenuBar_EntityCopy_text";
			statement="zen_context_actions_inventory = _hoveredEntity call zen_common_fnc_serializeInventory";
			icon="\x\zen\addons\context_actions\ui\copy_ca.paa";
		};
		class Paste
		{
			displayName="$STR_3DEN_Display3DEN_MenuBar_EntityPaste_text";
			condition="!isNil ""zen_context_actions_inventory""";
			statement="[_hoveredEntity, zen_context_actions_inventory] call zen_common_fnc_deserializeInventory";
			icon="\x\zen\addons\context_actions\ui\paste_ca.paa";
		};
	};
	class VehicleAppearance
	{
		displayName="$STR_zen_context_actions_VehicleAppearance";
		condition="_hoveredEntity call zen_context_actions_fnc_canEditVehicleAppearance";
		statement="_hoveredEntity call zen_garage_fnc_openGarage";
		icon="\a3\3den\data\displays\display3den\entitymenu\garage_ca.paa";
		priority=38;
		class Edit
		{
			displayName="$STR_3DEN_Display3DEN_MenUBar_Edit_text";
			condition="_hoveredEntity call zen_context_actions_fnc_canEditVehicleAppearance";
			statement="_hoveredEntity call zen_garage_fnc_openGarage";
			icon="\a3\3DEN\Data\Displays\Display3DEN\PanelRight\customcomposition_edit_ca.paa";
		};
		class Copy
		{
			displayName="$STR_3DEN_Display3DEN_MenuBar_EntityCopy_text";
			statement="_hoveredEntity call zen_context_actions_fnc_copyVehicleAppearance";
			icon="\x\zen\addons\context_actions\ui\copy_ca.paa";
		};
		class Paste
		{
			displayName="$STR_3DEN_Display3DEN_MenuBar_EntityPaste_text";
			condition="_hoveredEntity call zen_context_actions_fnc_canPasteVehicleAppearance";
			statement="_hoveredEntity call zen_context_actions_fnc_pasteVehicleAppearance";
			icon="\x\zen\addons\context_actions\ui\paste_ca.paa";
		};
	};
	class VehicleLogistics
	{
		displayName="$STR_zen_context_actions_VehicleLogistics";
		icon="\a3\ui_f\data\igui\cfg\simpleTasks\types\truck_ca.paa";
		priority=37;
		class Repair
		{
			displayName="$STR_Repair";
			condition="_objects call zen_context_actions_fnc_canRepairVehicles";
			statement="_objects call zen_context_actions_fnc_repairVehicles";
			icon="\a3\ui_f\data\igui\cfg\simpleTasks\types\repair_ca.paa";
		};
		class Rearm
		{
			displayName="$STR_Rearm";
			condition="_objects call zen_context_actions_fnc_canRearmVehicles";
			statement="_objects call zen_context_actions_fnc_rearmVehicles";
			icon="\a3\ui_f\data\igui\cfg\simpleTasks\types\rearm_ca.paa";
		};
		class Refuel
		{
			displayName="$STR_Refuel";
			condition="_objects call zen_context_actions_fnc_canRefuelVehicles";
			statement="_objects call zen_context_actions_fnc_refuelVehicles";
			icon="\a3\ui_f\data\igui\cfg\simpleTasks\types\refuel_ca.paa";
		};
		class SwitchWeapon
		{
			displayName="$STR_A3_Switch1";
			icon="\a3\ui_f\data\GUI\Cfg\Hints\VehicleAmmo_CA.paa";
			insertChildren="_hoveredEntity call zen_context_actions_fnc_getVehicleWeaponActions";
		};
		class UnloadViV
		{
			displayName="$STR_A3_ModuleDepot_Unload";
			condition="_objects call zen_context_actions_fnc_canUnloadViV";
			statement="_objects call zen_context_actions_fnc_unloadViV";
			icon="\a3\ui_f\data\IGUI\Cfg\Actions\unloadVehicle_ca.paa";
		};
	};
	class EditableObjects
	{
		displayName="$STR_zen_context_actions_EditableObjects";
		statement="call zen_context_actions_fnc_openEditableObjectsDialog";
		icon="\x\zen\addons\modules\ui\edit_obj_ca.paa";
		priority=30;
		class Add
		{
			displayName="$STR_zen_common_Add";
			icon="\x\zen\addons\context_actions\ui\add_ca.paa";
			class 10m
			{
				displayName="$STR_zen_context_actions_10m";
				statement="[true, _position, _args] call zen_context_actions_fnc_updateEditableObjects";
				icon="\x\zen\addons\context_actions\ui\add_ca.paa";
				args=10;
			};
			class 50m: 10m
			{
				displayName="$STR_zen_context_actions_50m";
				args=50;
			};
			class 100m: 10m
			{
				displayName="$STR_zen_context_actions_100m";
				args=100;
			};
			class 250m: 10m
			{
				displayName="$STR_zen_context_actions_250m";
				args=250;
			};
		};
		class Remove
		{
			displayName="$STR_zen_common_Remove";
			icon="\x\zen\addons\context_actions\ui\remove_ca.paa";
			class Selected
			{
				displayName="$STR_zen_context_actions_Selected";
				statement="[(curatorSelected select 0), false, getAssignedCuratorLogic player] call zen_common_fnc_updateEditableObjects";
				icon="\x\zen\addons\context_actions\ui\remove_ca.paa";
			};
			class 10m: Selected
			{
				displayName="$STR_zen_context_actions_10m";
				statement="[false, _position, _args] call zen_context_actions_fnc_updateEditableObjects";
				args=10;
			};
			class 50m: 10m
			{
				displayName="$STR_zen_context_actions_50m";
				args=50;
			};
			class 100m: 10m
			{
				displayName="$STR_zen_context_actions_100m";
				args=100;
			};
			class 250m: 10m
			{
				displayName="$STR_zen_context_actions_250m";
				args=250;
			};
		};
	};
	class RemoteControl
	{
		displayName="$STR_A3_CfgVehicles_ModuleRemoteControl_F";
		condition="_hoveredEntity call zen_remote_control_fnc_canControl";
		statement="_hoveredEntity call zen_remote_control_fnc_start";
		icon="\a3\modules_f_curator\data\portraitremotecontrol_ca.paa";
		priority=20;
	};
	class TeleportPlayers
	{
		displayName="$STR_zen_context_actions_TeleportPlayers";
		condition="_objects findIf {isPlayer _x} != -1";
		statement="_objects call zen_context_actions_fnc_teleportPlayers";
		icon="\x\zen\addons\context_actions\ui\marker_ca.paa";
		priority=10;
	};
	class TeleportZeus
	{
		displayName="$STR_zen_context_actions_TeleportZeus";
		statement="call zen_context_actions_fnc_teleportZeus";
		icon="\a3\Ui_F_Curator\Data\Logos\arma3_curator_eye_256_ca.paa";
		priority=10;
	};
};
