class CfgPatches
{
	class zen_modules
	{
		name="ZEN - Modules";
		units[]=
		{
			"zen_modules_moduleAddFullArsenal",
			"zen_modules_moduleAmbientAnim",
			"zen_modules_moduleAmbientFlyby",
			"zen_modules_moduleAnimationViewer",
			"zen_modules_moduleArsenal",
			"zen_modules_moduleAssignZeus",
			"zen_modules_moduleAttachEffect",
			"zen_modules_moduleAttachFlag",
			"zen_modules_moduleBindVariable",
			"zen_modules_moduleCASGun",
			"zen_modules_moduleCASMissile",
			"zen_modules_moduleCASGunMissile",
			"zen_modules_moduleCASBomb",
			"zen_modules_moduleChangeHeight",
			"zen_modules_moduleChatter",
			"zen_modules_moduleConvoyParameters",
			"zen_modules_moduleCreateIED",
			"zen_modules_moduleCreateIntel",
			"zen_modules_moduleCreateLZ",
			"zen_modules_moduleCreateMinefield",
			"zen_modules_moduleCreateRP",
			"zen_modules_moduleCreateTarget",
			"zen_modules_moduleCreateTeleporter",
			"zen_modules_moduleCrewToGunner",
			"zen_modules_moduleDamageBuildings",
			"zen_modules_moduleEarthquake",
			"zen_modules_moduleEditableObjects",
			"zen_modules_moduleEffectFire",
			"zen_modules_moduleEquipWithECM",
			"zen_modules_moduleExportMissionSQF",
			"zen_modules_moduleExecuteCode",
			"zen_modules_moduleFireMission",
			"zen_modules_moduleFlyHeight",
			"zen_modules_moduleFunctionsViewer",
			"zen_modules_moduleGarrison",
			"zen_modules_moduleGlobalAISkill",
			"zen_modules_moduleGlobalHint",
			"zen_modules_moduleGroupSide",
			"zen_modules_moduleHeal",
			"zen_modules_moduleHideTerrainObjects",
			"zen_modules_moduleHideZeus",
			"zen_modules_moduleLightSource",
			"zen_modules_moduleMakeInvincible",
			"zen_modules_moduleNuke",
			"zen_modules_modulePatrolArea",
			"zen_modules_moduleRemoveArsenal",
			"zen_modules_moduleRotateObject",
			"zen_modules_moduleScaleObject",
			"zen_modules_moduleSearchBuilding",
			"zen_modules_moduleSetDate",
			"zen_modules_moduleShowInConfig",
			"zen_modules_moduleSideRelations",
			"zen_modules_moduleSimulation",
			"zen_modules_moduleSitOnChair",
			"zen_modules_moduleSmokePillar",
			"zen_modules_moduleSpawnCarrier",
			"zen_modules_moduleSpawnDestroyer",
			"zen_modules_moduleSpawnReinforcements",
			"zen_modules_moduleSuicideBomber",
			"zen_modules_moduleSuppressiveFire",
			"zen_modules_moduleTeleportPlayers",
			"zen_modules_moduleToggleFlashlights",
			"zen_modules_moduleToggleIRLasers",
			"zen_modules_moduleToggleLamps",
			"zen_modules_moduleTracers",
			"zen_modules_moduleTurretOptics",
			"zen_modules_moduleUnGarrison",
			"zen_modules_moduleVisibility",
			"zen_modules_moduleWeather"
		};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_attributes"
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
				"zen_modules"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_modules
	{
		init="call compileScript ['\x\zen\addons\modules\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_modules
	{
		init="call compileScript ['\x\zen\addons\modules\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_modules
	{
		init="call compileScript ['\x\zen\addons\modules\XEH_postInit.sqf']";
	};
};
class CfgFactionClasses
{
	class Chemlights
	{
		displayName="$STR_A3_Chemlights1";
	};
	class zen_modules_AI
	{
		displayName="$STR_Team_Switch_AI";
		priority=2;
		side=7;
	};
	class zen_modules_Buildings
	{
		displayName="$STR_zen_modules_Buildings";
		priority=2;
		side=7;
	};
	class zen_modules_DevTools
	{
		displayName="$STR_zen_modules_DevTools";
		priority=2;
		side=7;
	};
	class zen_modules_Equipment
	{
		displayName="$STR_zen_modules_Equipment";
		priority=2;
		side=7;
	};
	class zen_modules_Inventory
	{
		displayName="$STR_A3_Gear1";
		priority=2;
		side=7;
	};
	class zen_modules_Objects
	{
		displayName="$STR_zen_modules_Objects";
		priority=2;
		side=7;
	};
	class zen_modules_Players
	{
		displayName="$STR_zen_modules_Players";
		priority=2;
		side=7;
	};
	class zen_modules_Reinforcements
	{
		displayName="$STR_zen_modules_Reinforcements";
		priority=2;
		side=7;
	};
	class zen_modules_Spawn
	{
		displayName="$STR_zen_modules_Spawn";
		priority=2;
		side=7;
	};
};
class CBA_Extended_EventHandlers_base;
class CfgVehicles
{
	class Module_F;
	class zen_modules_moduleBase: Module_F
	{
		author="$STR_zen_main_Author";
		category="NO_CATEGORY";
		function="";
		scope=1;
		scopeCurator=2;
		class EventHandlers
		{
			init="_this call zen_modules_fnc_initModule";
			class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
			{
			};
		};
	};
	class ModuleCurator_F: Module_F
	{
		function="zen_modules_fnc_bi_moduleCurator";
	};
	class ModuleArsenal_F: Module_F
	{
		scopeCurator=1;
	};
	class ModuleTracers_F: Module_F
	{
		scopeCurator=1;
	};
	class ModuleCAS_F;
	class ModuleCASGun_F: ModuleCAS_F
	{
		scopeCurator=1;
	};
	class ModuleCASBomb_F: ModuleCASGun_F
	{
		scopeCurator=1;
	};
	class ModuleEmpty_F;
	class ModuleMine_F: ModuleEmpty_F
	{
		function="zen_modules_fnc_bi_moduleMine";
	};
	class zen_modules_moduleAddFullArsenal: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Inventory";
		displayName="$STR_zen_modules_ModuleAddFullArsenal";
		function="zen_modules_fnc_moduleAddFullArsenal";
		icon="\a3\ui_f\data\logos\a_64_ca.paa";
	};
	class zen_modules_moduleAmbientAnim: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_modules_ModuleAmbientAnim";
		function="zen_modules_fnc_moduleAmbientAnim";
	};
	class zen_modules_moduleAmbientFlyby: zen_modules_moduleBase
	{
		category="zen_modules_AI";
		displayName="$STR_zen_modules_ModuleAmbientFlyby";
		curatorInfoType="zen_modules_RscAmbientFlyby";
		icon="\x\zen\addons\modules\ui\heli_ca.paa";
	};
	class zen_modules_moduleAnimationViewer: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_DevTools";
		displayName="$STR_zen_modules_ModuleAnimationViewer";
		function="zen_modules_fnc_moduleAnimationViewer";
	};
	class zen_modules_moduleArsenal: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="Curator";
		displayName="$STR_A3_Arsenal";
		function="zen_modules_fnc_moduleArsenal";
		icon="\a3\ui_f\data\logos\a_64_ca.paa";
	};
	class zen_modules_moduleAssignZeus: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="Curator";
		displayName="$STR_zen_modules_ModuleAssignZeus";
		function="zen_modules_fnc_moduleAssignZeus";
		icon="\a3\Ui_F_Curator\Data\Logos\arma3_curator_eye_256_ca.paa";
	};
	class zen_modules_moduleAttachEffect: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Equipment";
		displayName="$STR_zen_modules_AttachEffect";
		function="zen_modules_fnc_moduleAttachEffect";
	};
	class zen_modules_moduleAttachFlag: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Objects";
		displayName="$STR_zen_modules_ModuleAttachFlag";
		function="zen_modules_fnc_moduleAttachFlag";
		icon="\x\zen\addons\modules\ui\flag_ca.paa";
	};
	class zen_modules_moduleBindVariable: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_DevTools";
		displayName="$STR_zen_modules_BindVariable";
		function="zen_modules_fnc_moduleBindVariable";
	};
	class zen_modules_moduleCASGun: zen_modules_moduleBase
	{
		category="Ordnance";
		displayName="$STR_A3_CfgVehicles_ModuleCAS_F_Arguments_Type_values_Gun";
		curatorInfoType="zen_modules_RscCAS";
		icon="\a3\Modules_F_Curator\Data\portraitCASGun_ca.paa";
		portrait="\a3\Modules_F_Curator\Data\portraitCASGun_ca.paa";
		model="\a3\Modules_F_Curator\CAS\surfaceGun.p3d";
		simulation="house";
		zen_modules_casType=0;
	};
	class zen_modules_moduleCASMissile: zen_modules_moduleCASGun
	{
		displayName="$STR_A3_CfgVehicles_ModuleCAS_F_Arguments_Type_values_Missiles";
		icon="\a3\Modules_F_Curator\Data\portraitCASMissile_ca.paa";
		portrait="\a3\Modules_F_Curator\Data\portraitCASMissile_ca.paa";
		model="\a3\Modules_F_Curator\CAS\surfaceMissile.p3d";
		zen_modules_casType=1;
	};
	class zen_modules_moduleCASGunMissile: zen_modules_moduleCASGun
	{
		displayName="$STR_A3_CfgVehicles_ModuleCAS_F_Arguments_Type_values_GunMissiles";
		icon="\a3\Modules_F_Curator\Data\portraitCASGunMissile_ca.paa";
		portrait="\a3\Modules_F_Curator\Data\portraitCASGunMissile_ca.paa";
		model="\a3\Modules_F_Curator\CAS\surfaceGunMissile.p3d";
		zen_modules_casType=2;
	};
	class zen_modules_moduleCASBomb: zen_modules_moduleCASGun
	{
		displayName="$STR_zen_modules_ModuleCAS_Bomb";
		icon="\a3\Modules_F_Curator\Data\portraitCASBomb_ca.paa";
		portrait="\a3\Modules_F_Curator\Data\portraitCASBomb_ca.paa";
		model="\a3\Modules_F_Curator\CAS\surfaceMissile.p3d";
		zen_modules_casType=3;
	};
	class zen_modules_moduleChangeHeight: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Objects";
		displayName="$STR_zen_modules_ChangeHeight";
		function="zen_modules_fnc_moduleChangeHeight";
	};
	class zen_modules_moduleChatter: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_modules_ModuleChatter";
		function="zen_modules_fnc_moduleChatter";
		icon="\x\zen\addons\modules\ui\chat_ca.paa";
	};
	class zen_modules_moduleConvoyParameters: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_modules_ModuleConvoyParameters";
		function="zen_modules_fnc_moduleConvoyParameters";
		icon="\x\zen\addons\modules\ui\truck_ca.paa";
	};
	class zen_modules_moduleCreateIED: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Objects";
		displayName="$STR_zen_modules_CreateIED";
		function="zen_modules_fnc_moduleCreateIED";
		icon="\x\zen\addons\modules\ui\explosion_ca.paa";
	};
	class zen_modules_moduleCreateIntel: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		displayName="$STR_zen_modules_ModuleCreateIntel";
		function="zen_modules_fnc_moduleCreateIntel";
		icon="\a3\ui_f\data\igui\cfg\simpletasks\types\documents_ca.paa";
	};
	class zen_modules_moduleCreateLZ: zen_modules_moduleBase
	{
		category="zen_modules_Reinforcements";
		displayName="$STR_zen_modules_ModuleCreateLZ";
		function="zen_modules_fnc_moduleCreateLZ";
		icon="\a3\modules_f\data\portraitsector_ca.paa";
		portrait="\a3\modules_f\data\portraitsector_ca.paa";
	};
	class zen_modules_moduleCreateMinefield: zen_modules_moduleBase
	{
		category="zen_modules_Objects";
		displayName="$STR_zen_modules_ModuleCreateMinefield";
		function="zen_modules_fnc_moduleCreateMinefield";
	};
	class zen_modules_moduleCreateRP: zen_modules_moduleBase
	{
		category="zen_modules_Reinforcements";
		displayName="$STR_zen_modules_ModuleCreateRP";
		function="zen_modules_fnc_moduleCreateRP";
		icon="\x\zen\addons\modules\ui\rp_ca.paa";
		portrait="\x\zen\addons\modules\ui\rp_ca.paa";
	};
	class zen_modules_moduleCreateTarget: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="Ordnance";
		displayName="$STR_zen_modules_ModuleCreateTarget";
		function="zen_modules_fnc_moduleCreateTarget";
		icon="\x\zen\addons\modules\ui\target_ca.paa";
		portrait="\x\zen\addons\modules\ui\target_ca.paa";
	};
	class zen_modules_moduleCreateTeleporter: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Players";
		displayName="$STR_zen_modules_ModuleCreateTeleporter";
		function="zen_modules_fnc_moduleCreateTeleporter";
		icon="\a3\3den\data\displays\display3den\panelleft\entitylist_location_ca.paa";
	};
	class zen_modules_moduleCrewToGunner: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_modules_ModuleCrewToGunner";
		function="zen_modules_fnc_moduleCrewToGunner";
		icon="\a3\ui_f\data\IGUI\Cfg\Actions\getingunner_ca.paa";
	};
	class zen_modules_moduleDamageBuildings: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Buildings";
		displayName="$STR_zen_modules_ModuleDamageBuildings";
		curatorInfoType="zen_modules_RscDamageBuildings";
		icon="\a3\modules_f\data\editterrainobject\icon_ca.paa";
	};
	class zen_modules_moduleEarthquake: zen_modules_moduleBase
	{
		category="Environment";
		displayName="$STR_zen_modules_ModuleEarthquake";
		function="zen_modules_fnc_moduleEarthquake";
	};
	class zen_modules_moduleEditableObjects: zen_modules_moduleBase
	{
		category="Curator";
		displayName="$STR_zen_modules_ModuleEditableObjects";
		curatorInfoType="zen_modules_RscEditableObjects";
		icon="\x\zen\addons\modules\ui\edit_obj_ca.paa";
	};
	class zen_modules_moduleEffectFire: zen_modules_moduleBase
	{
		category="Effects";
		displayName="$STR_zen_modules_CustomFire";
		curatorInfoType="zen_modules_RscEffectFireHelper";
		icon="\x\zen\addons\modules\ui\fire_ca.paa";
		portrait="\x\zen\addons\modules\ui\fire_ca.paa";
	};
	class zen_modules_moduleEquipWithECM: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Objects";
		displayName="$STR_zen_modules_ModuleEquipWithECM";
		function="zen_modules_fnc_moduleEquipWithECM";
	};
	class zen_modules_moduleExportMissionSQF: zen_modules_moduleBase
	{
		category="zen_modules_DevTools";
		displayName="$STR_zen_modules_ExportMissionSQF";
		function="zen_modules_fnc_moduleExportMissionSQF";
	};
	class zen_modules_moduleExecuteCode: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_DevTools";
		displayName="$STR_zen_modules_ModuleExecuteCode";
		curatorInfoType="zen_modules_RscExecuteCode";
		icon="\x\zen\addons\modules\ui\code_ca.paa";
		portrait="\x\zen\addons\modules\ui\code_ca.paa";
	};
	class zen_modules_moduleFireMission: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="Ordnance";
		displayName="$STR_zen_modules_ModuleFireMission";
		curatorInfoType="zen_modules_RscFireMission";
	};
	class zen_modules_moduleFlyHeight: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_modules_ModuleFlyHeight";
		function="zen_modules_fnc_moduleFlyHeight";
	};
	class zen_modules_moduleFunctionsViewer: zen_modules_moduleBase
	{
		category="zen_modules_DevTools";
		displayName="$STR_A3_RscFunctionsViewer_Caption";
		function="zen_modules_fnc_moduleFunctionsViewer";
		icon="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\functions_ca.paa";
	};
	class zen_modules_moduleGarrison: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_modules_ModuleGarrison";
		function="zen_modules_fnc_moduleGarrison";
	};
	class zen_modules_moduleGlobalAISkill: zen_modules_moduleBase
	{
		category="zen_modules_AI";
		displayName="$STR_zen_modules_GlobalAISkill";
		function="zen_modules_fnc_moduleGlobalAISkill";
	};
	class zen_modules_moduleGlobalHint: zen_modules_moduleBase
	{
		category="Curator";
		displayName="$STR_zen_modules_ModuleGlobalHint";
		curatorInfoType="zen_modules_RscGlobalHint";
	};
	class zen_modules_moduleGroupSide: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		displayName="$STR_zen_modules_GroupSide";
		function="zen_modules_fnc_moduleGroupSide";
	};
	class zen_modules_moduleHeal: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		displayName="$STR_zen_modules_ModuleHeal";
		function="zen_modules_fnc_moduleHeal";
		icon="\x\zen\addons\modules\ui\heal_ca.paa";
	};
	class zen_modules_moduleHideTerrainObjects: zen_modules_moduleBase
	{
		category="Environment";
		displayName="$STR_a3_to_hideTerrainObjects1";
		function="zen_modules_fnc_moduleHideTerrainObjects";
		icon="\a3\modules_f\data\hideterrainobjects\icon32_ca.paa";
	};
	class zen_modules_moduleHideZeus: zen_modules_moduleBase
	{
		category="Curator";
		displayName="$STR_zen_modules_ModuleHideZeus";
		function="zen_modules_fnc_moduleHideZeus";
	};
	class zen_modules_moduleLightSource: zen_modules_moduleBase
	{
		category="Effects";
		displayName="$STR_zen_modules_ModuleLightSource";
		curatorInfoType="zen_modules_RscLightSourceHelper";
		icon="\x\zen\addons\modules\ui\light_ca.paa";
		portrait="\x\zen\addons\modules\ui\light_ca.paa";
	};
	class zen_modules_moduleMakeInvincible: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Objects";
		displayName="$STR_zen_modules_ModuleMakeInvincible";
		function="zen_modules_fnc_moduleMakeInvincible";
	};
	class zen_modules_moduleNuke: zen_modules_moduleBase
	{
		category="Ordnance";
		displayName="$STR_zen_modules_AtomicBomb";
		function="zen_modules_fnc_moduleNuke";
		icon="\x\zen\addons\modules\ui\nuke_ca.paa";
	};
	class zen_modules_modulePatrolArea: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_modules_ModulePatrolArea";
		function="zen_modules_fnc_modulePatrolArea";
	};
	class zen_modules_moduleRemoveArsenal: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Inventory";
		displayName="$STR_zen_modules_ModuleRemoveArsenal";
		function="zen_modules_fnc_moduleRemoveArsenal";
		icon="\a3\ui_f\data\logos\a_64_ca.paa";
	};
	class zen_modules_moduleRotateObject: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Objects";
		displayName="$STR_zen_modules_RotateObject";
		function="zen_modules_fnc_moduleRotateObject";
		icon="\x\zen\addons\modules\ui\rotate_ca.paa";
	};
	class zen_modules_moduleScaleObject: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Objects";
		displayName="$STR_zen_modules_ScaleObject";
		function="zen_modules_fnc_moduleScaleObject";
		icon="\a3\3den\Data\Cfg3DEN\History\scaleItems_ca.paa";
	};
	class zen_modules_moduleSearchBuilding: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_ai_SearchBuilding";
		function="zen_modules_fnc_moduleSearchBuilding";
	};
	class zen_modules_moduleSetDate: zen_modules_moduleBase
	{
		category="Environment";
		displayName="$STR_zen_modules_ModuleSetDate";
		curatorInfoType="zen_modules_RscSetDate";
	};
	class zen_modules_moduleShowInConfig: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_DevTools";
		displayName="$STR_zen_modules_ShowInConfig";
		function="zen_modules_fnc_moduleShowInConfig";
		icon="\a3\3DEN\Data\Displays\Display3DEN\EntityMenu\findConfig_ca.paa";
	};
	class zen_modules_moduleSideRelations: zen_modules_moduleBase
	{
		category="MissionFlow";
		displayName="$STR_zen_modules_ModuleSideRelations";
		curatorInfoType="zen_modules_RscSideRelations";
		icon="\a3\ui_f\data\igui\cfg\simpletasks\types\help_ca.paa";
	};
	class zen_modules_moduleSimulation: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Objects";
		displayName="$STR_zen_modules_ModuleSimulation";
		function="zen_modules_fnc_moduleSimulation";
	};
	class zen_modules_moduleSitOnChair: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_modules_ModuleSitOnChair";
		function="zen_modules_fnc_moduleSitOnChair";
		icon="\x\zen\addons\modules\ui\chair_ca.paa";
	};
	class zen_modules_moduleSmokePillar: zen_modules_moduleBase
	{
		category="Effects";
		displayName="$STR_zen_modules_ModuleSmokePillar";
		function="zen_modules_fnc_moduleSmokePillar";
		icon="\x\zen\addons\modules\ui\smoke_pillar_ca.paa";
		portrait="\x\zen\addons\modules\ui\smoke_pillar_ca.paa";
	};
	class zen_modules_moduleSpawnCarrier: zen_modules_moduleBase
	{
		category="zen_modules_Spawn";
		displayName="$STR_zen_modules_ModuleSpawnCarrier";
		function="zen_modules_fnc_moduleSpawnCarrier";
	};
	class zen_modules_moduleSpawnDestroyer: zen_modules_moduleBase
	{
		category="zen_modules_Spawn";
		displayName="$STR_zen_modules_ModuleSpawnDestroyer";
		function="zen_modules_fnc_moduleSpawnDestroyer";
	};
	class zen_modules_moduleSpawnReinforcements: zen_modules_moduleBase
	{
		category="zen_modules_Reinforcements";
		displayName="$STR_zen_modules_SpawnReinforcements";
		curatorInfoType="zen_modules_RscSpawnReinforcements";
	};
	class zen_modules_moduleSuicideBomber: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_modules_ModuleSuicideBomber";
		function="zen_modules_fnc_moduleSuicideBomber";
	};
	class zen_modules_moduleSuppressiveFire: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_ai_SuppressiveFire";
		function="zen_modules_fnc_moduleSuppressiveFire";
	};
	class zen_modules_moduleTeleportPlayers: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Players";
		displayName="$STR_zen_modules_ModuleTeleportPlayers";
		function="zen_modules_fnc_moduleTeleportPlayers";
	};
	class zen_modules_moduleToggleFlashlights: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Equipment";
		displayName="$STR_zen_modules_ModuleToggleFlashlights";
		function="zen_modules_fnc_moduleToggleFlashlights";
		icon="\x\zen\addons\modules\ui\flashlight_ca.paa";
	};
	class zen_modules_moduleToggleIRLasers: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Equipment";
		displayName="$STR_zen_modules_ModuleToggleIRLasers";
		function="zen_modules_fnc_moduleToggleIRLasers";
		icon="\a3\ui_f_curator\data\cfgcurator\laser_ca.paa";
	};
	class zen_modules_moduleToggleLamps: zen_modules_moduleBase
	{
		category="zen_modules_Buildings";
		displayName="$STR_zen_modules_ToggleLamps";
		function="zen_modules_fnc_moduleToggleLamps";
		icon="\x\zen\addons\modules\ui\street_lamp_ca.paa";
	};
	class zen_modules_moduleTracers: zen_modules_moduleBase
	{
		category="Effects";
		displayName="$STR_a3_cfgvehicles_moduletracers_f_0";
		curatorInfoType="zen_modules_RscTracers";
		icon="\a3\modules_f_curator\Data\iconTracers_ca.paa";
		portrait="\a3\modules_f_curator\Data\portraitTracers_ca.paa";
	};
	class zen_modules_moduleTurretOptics: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Equipment";
		displayName="$STR_zen_modules_ModuleTurretOptics";
		function="zen_modules_fnc_moduleTurretOptics";
	};
	class zen_modules_moduleUnGarrison: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_AI";
		displayName="$STR_zen_modules_ModuleUnGarrison";
		function="zen_modules_fnc_moduleUnGarrison";
	};
	class zen_modules_moduleVisibility: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Objects";
		displayName="$STR_zen_modules_ModuleVisibility";
		function="zen_modules_fnc_moduleVisibility";
	};
	class zen_modules_moduleWeather: zen_modules_moduleBase
	{
		category="Environment";
		displayName="$STR_zen_modules_ModuleWeather";
		function="zen_modules_fnc_moduleWeather";
		icon="\a3\3DEN\Data\Displays\Display3DEN\ToolBar\intel_ca.paa";
	};
};
class RscText;
class RscEdit;
class RscCombo;
class RscPicture;
class RscListBox;
class RscEditMulti;
class RscStructuredText;
class RscControlsGroup;
class RscControlsGroupNoScrollbars;
class ctrlTree;
class ctrlListbox;
class ctrlToolbox;
class ctrlCheckbox;
class ctrlXSliderH;
class ctrlListNBox;
class ctrlButtonPictureKeepAspect;
class zen_common_RscLabel;
class zen_common_RscBackground;
class zen_common_RscEdit;
class zen_common_RscCheckbox;
class zen_common_RscCombo;
class zen_common_RscControlsGroup;
class zen_common_RscDisplay
{
	class controls
	{
		class Title;
		class Background;
		class Content;
		class ButtonOK;
		class ButtonCancel;
	};
};
class zen_modules_RscDisplay: zen_common_RscDisplay
{
	onLoad="call zen_modules_fnc_initDisplay";
	function="";
	checkLogic=0;
};
class zen_modules_RscToolboxYesNo: ctrlToolbox
{
	idc=-1;
	x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
	y=0;
	w="((15.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	rows=1;
	columns=2;
	strings[]=
	{
		"$STR_zen_common_No",
		"$STR_zen_common_Yes"
	};
};
class zen_modules_RscSidesCombo: zen_common_RscCombo
{
	class Items
	{
		class BLUFOR
		{
			text="$STR_West";
			picture="\x\zen\addons\common\ui\icon_blufor_ca.paa";
		};
		class OPFOR
		{
			text="$STR_East";
			picture="\x\zen\addons\common\ui\icon_opfor_ca.paa";
		};
		class Independent
		{
			text="$STR_Guerrila";
			picture="\x\zen\addons\common\ui\icon_independent_ca.paa";
		};
		class Civilian
		{
			text="$STR_Civilian";
			picture="\x\zen\addons\common\ui\icon_civilian_ca.paa";
		};
	};
};
class zen_modules_RscEffectFireHelper
{
	idd=-1;
	onLoad="call zen_modules_fnc_moduleEffectFire";
};
class zen_modules_RscLightSourceHelper
{
	idd=-1;
	onLoad="call zen_modules_fnc_moduleLightSource";
};
class zen_modules_RscAmbientFlyby: zen_modules_RscDisplay
{
	function="zen_modules_fnc_gui_ambientFlyby";
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
			h="((11) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class AircraftSelect: RscControlsGroupNoScrollbars
				{
					idc=-1;
					x=0;
					y=0;
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((4.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					class controls
					{
						class Title: zen_common_RscLabel
						{
							text="$STR_zen_modules_ModuleAmbientFlyby_AircraftSelect";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
						class Background: zen_common_RscBackground
						{
							x=0;
							y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((3.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class SideLabel: zen_common_RscLabel
						{
							text="$STR_zen_common_Side";
							x="((3) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((8.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
							colorBackground[]={0,0,0,0.69999999};
						};
						class SideCombo: zen_modules_RscSidesCombo
						{
							idc=61701;
							x="((12) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((11) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
						class FactionLabel: SideLabel
						{
							text="$STR_zen_common_Faction";
							y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class FactionCombo: SideCombo
						{
							idc=61702;
							y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							wholeHeight="((6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							class Items
							{
							};
						};
						class AircraftLabel: FactionLabel
						{
							text="$STR_zen_common_Aircraft";
							y="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class AircraftCombo: FactionCombo
						{
							idc=61704;
							y="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							wholeHeight="((5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
					};
				};
				class DirectionLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_ModuleAmbientFlyby_FlyTowards";
					tooltip="$STR_zen_modules_ModuleAmbientFlyby_FlyTowards_Tooltip";
					y="((4.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Direction: ctrlToolbox
				{
					idc=61703;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((4.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((15.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					rows=1;
					columns=8;
					strings[]=
					{
						"N",
						"NE",
						"E",
						"SE",
						"S",
						"SW",
						"W",
						"NW"
					};
				};
				class HeightLabel: zen_common_RscLabel
				{
					text="$STR_zen_common_Height";
					tooltip="$STR_zen_modules_ModuleAmbientFlyby_Height_Tooltip";
					y="((5.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					h="((2.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class HeightMode: Direction
				{
					idc=61705;
					y="((5.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					columns=2;
					strings[]=
					{
						"$STR_zen_modules_ModuleAmbientFlyby_Height_Mode_AGL",
						"$STR_zen_modules_ModuleAmbientFlyby_Height_Mode_ASL"
					};
					tooltips[]=
					{
						"$STR_zen_modules_ModuleAmbientFlyby_Height_Mode_AGL_Tooltip",
						"$STR_zen_modules_ModuleAmbientFlyby_Height_Mode_ASL_Tooltip"
					};
				};
				class HeightSlider: ctrlXSliderH
				{
					idc=61706;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((6.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((13.4) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class HeightEdit: zen_common_RscEdit
				{
					idc=61707;
					x="((23.6) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((6.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((2.4) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class DistanceLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_ModuleAmbientFlyby_Distance";
					tooltip="$STR_zen_modules_ModuleAmbientFlyby_Distance_Tooltip";
					y="((7.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class DistanceSlider: HeightSlider
				{
					idc=61708;
					y="((7.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class DistanceEdit: HeightEdit
				{
					idc=61709;
					y="((7.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class SpeedLabel: zen_common_RscLabel
				{
					text="$STR_zen_common_Speed";
					tooltip="$STR_zen_modules_ModuleAmbientFlyby_Speed_Tooltip";
					y="((8.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Speed: Direction
				{
					idc=61710;
					y="((8.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					columns=3;
					strings[]=
					{
						"$STR_A3_Slow",
						"$STR_A3_Normal",
						"$STR_A3_Fast"
					};
				};
				class AmountLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_ModuleAmbientFlyby_Amount";
					tooltip="$STR_zen_modules_ModuleAmbientFlyby_Amount_Tooltip";
					y="((10) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Amount: Direction
				{
					idc=61711;
					y="((10) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					columns=6;
					strings[]={"1","2","3","4","5","6"};
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
class zen_modules_RscCAS: zen_modules_RscDisplay
{
	function="zen_modules_fnc_gui_cas";
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
			h="((8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class Label: zen_common_RscLabel
				{
					text="$STR_DN_Plane";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class Background: zen_common_RscBackground
				{
					x=0;
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class List: ctrlListNBox
				{
					idc=61801;
					x=0;
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					columns[]={0,0.1,0.25};
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
class zen_modules_RscDamageBuildings: zen_modules_RscDisplay
{
	function="zen_modules_fnc_gui_damageBuildings";
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
			h="((4.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class SelectionLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_BuildingSelection";
				};
				class SelectionMode: ctrlToolbox
				{
					idc=61301;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y=0;
					w="((13.8) * (((safezoneW / safezoneH) min 1.2) / 40)) - pixelW";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					rows=1;
					columns=2;
					strings[]=
					{
						"$STR_zen_common_Nearest",
						"$STR_zen_common_Radius"
					};
				};
				class SelectionRadius: zen_common_RscEdit
				{
					idc=61302;
					x="((24) * (((safezoneW / safezoneH) min 1.2) / 40))";
					w="((2) * (((safezoneW / safezoneH) min 1.2) / 40))";
					maxChars=4;
				};
				class DamageLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_DamageState";
					tooltip="$STR_zen_modules_DamageState_Tooltip";
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class DamageBlockLeft: RscText
				{
					idc=-1;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((10) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0.5};
				};
				class DamageblockRight: DamageBlockLeft
				{
					x="((20.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
					w="((5.8) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class Undamaged: zen_common_RscCheckbox
				{
					idc=61303;
					tooltip="$STR_a3_to_editTerrainObject15";
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((2) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					color[]={1,1,1,1};
					colorBackground[]={0,0,0,0};
					colorBackgroundHover[]={0,0,0,0};
					colorBackgroundFocused[]={0,0,0,0};
					colorBackgroundPressed[]={0,0,0,0};
					colorBackgroundDisabled[]={0,0,0,0};
					textureChecked="\a3\modules_f\data\editterrainobject\texturechecked_undamaged_ca.paa";
					textureHoverChecked="\a3\modules_f\data\editterrainobject\texturechecked_undamaged_ca.paa";
					textureFocusedChecked="\a3\modules_f\data\editterrainobject\texturechecked_undamaged_ca.paa";
					texturePressedChecked="\a3\modules_f\data\editterrainobject\texturechecked_undamaged_ca.paa";
					textureDisabledChecked="\a3\modules_f\data\editterrainobject\texturechecked_undamaged_ca.paa";
					textureUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_undamaged_ca.paa";
					textureHoverUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_undamaged_ca.paa";
					textureFocusedUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_undamaged_ca.paa";
					texturePressedUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_undamaged_ca.paa";
					textureDisabledUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_undamaged_ca.paa";
				};
				class Damaged_1: Undamaged
				{
					idc=61304;
					tooltip="$STR_a3_to_editTerrainObject16";
					x="((12.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					textureChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged1_ca.paa";
					textureHoverChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged1_ca.paa";
					textureFocusedChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged1_ca.paa";
					texturePressedChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged1_ca.paa";
					textureDisabledChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged1_ca.paa";
					textureUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged1_ca.paa";
					textureHoverUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged1_ca.paa";
					textureFocusedUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged1_ca.paa";
					texturePressedUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged1_ca.paa";
					textureDisabledUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged1_ca.paa";
				};
				class Damaged_2: Undamaged
				{
					idc=61305;
					tooltip="$STR_a3_to_editTerrainObject17";
					x="((14.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					textureChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged2_ca.paa";
					textureHoverChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged2_ca.paa";
					textureFocusedChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged2_ca.paa";
					texturePressedChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged2_ca.paa";
					textureDisabledChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged2_ca.paa";
					textureUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged2_ca.paa";
					textureHoverUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged2_ca.paa";
					textureFocusedUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged2_ca.paa";
					texturePressedUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged2_ca.paa";
					textureDisabledUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged2_ca.paa";
				};
				class Damaged_3: Undamaged
				{
					idc=61306;
					tooltip="$STR_a3_to_editTerrainObject18";
					x="((16.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					textureChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged12_ca.paa";
					textureHoverChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged12_ca.paa";
					textureFocusedChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged12_ca.paa";
					texturePressedChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged12_ca.paa";
					textureDisabledChecked="\a3\modules_f\data\editterrainobject\texturechecked_damaged12_ca.paa";
					textureUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged12_ca.paa";
					textureHoverUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged12_ca.paa";
					textureFocusedUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged12_ca.paa";
					texturePressedUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged12_ca.paa";
					textureDisabledUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_damaged12_ca.paa";
				};
				class Destroyed: Undamaged
				{
					idc=61307;
					tooltip="$STR_a3_to_editTerrainObject19";
					x="((18.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					textureChecked="\a3\modules_f\data\editterrainobject\texturechecked_destroyed_ca.paa";
					textureHoverChecked="\a3\modules_f\data\editterrainobject\texturechecked_destroyed_ca.paa";
					textureFocusedChecked="\a3\modules_f\data\editterrainobject\texturechecked_destroyed_ca.paa";
					texturePressedChecked="\a3\modules_f\data\editterrainobject\texturechecked_destroyed_ca.paa";
					textureDisabledChecked="\a3\modules_f\data\editterrainobject\texturechecked_destroyed_ca.paa";
					textureUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_destroyed_ca.paa";
					textureHoverUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_destroyed_ca.paa";
					textureFocusedUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_destroyed_ca.paa";
					texturePressedUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_destroyed_ca.paa";
					textureDisabledUnchecked="\a3\modules_f\data\editterrainobject\textureunchecked_destroyed_ca.paa";
				};
				class EffectsLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_DestructionEffects";
					tooltip="$STR_zen_modules_DestructionEffects_Tooltip";
					y="((3.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Effects: zen_modules_RscToolboxYesNo
				{
					idc=61308;
					y="((3.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
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
class zen_modules_RscEditableObjects: zen_modules_RscDisplay
{
	function="zen_modules_fnc_gui_editableObjects";
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
			h="((8.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class EditingModeLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_ModuleEditableObjects_EditingMode";
					tooltip="$STR_zen_modules_ModuleEditableObjects_EditingMode_Tooltip";
				};
				class EditingMode: ctrlToolbox
				{
					idc=61901;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y=0;
					w="((15.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					rows=1;
					columns=2;
					strings[]=
					{
						"$STR_zen_modules_ModuleEditableObjects_RemoveObjects",
						"$STR_zen_modules_ModuleEditableObjects_AddObjects"
					};
				};
				class AllCuratorsLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_ModuleEditableObjects_AllCurators";
					tooltip="$STR_zen_modules_ModuleEditableObjects_AllCurators_Tooltip";
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class AllCurators: zen_modules_RscToolboxYesNo
				{
					idc=61902;
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class RangeLabel: zen_common_RscLabel
				{
					text="$STR_zen_common_Range";
					y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					h="((2.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class RangeMode: EditingMode
				{
					idc=61903;
					y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					strings[]=
					{
						"$STR_zen_common_Radius",
						"$STR_zen_modules_ModuleEditableObjects_AllMissionObjects"
					};
				};
				class RangeSlider: ctrlXSliderH
				{
					idc=61904;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((13.4) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class RangeEdit: zen_common_RscEdit
				{
					idc=61905;
					x="((23.6) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((2.4) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class FilterLabel: zen_common_RscLabel
				{
					text="$STR_zen_common_Filter";
					y="((4.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					h="((3.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class FilterBackground: zen_common_RscBackground
				{
					y="((4.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					h="((3.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class FilterAll: ctrlCheckbox
				{
					idc=61906;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((4.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((0.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((0.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class FilterAllText: RscText
				{
					idc=-1;
					text="$STR_zen_common_All";
					x="((11) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((4.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((10) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((0.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					sizeEx="((0.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					shadow=0;
				};
				class FilterUnits: FilterAll
				{
					idc=61907;
					y="((5.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class FilterUnitsText: FilterAllText
				{
					text="$STR_zen_common_Units";
					y="((5.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class FilterVehicles: FilterAll
				{
					idc=61908;
					y="((6.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class FilterVehiclesText: FilterAllText
				{
					text="$STR_zen_common_Vehicles";
					y="((6.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class FilterStatic: FilterAll
				{
					idc=61909;
					y="((7.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class FilterStaticText: FilterAllText
				{
					text="$STR_zen_common_Static";
					y="((7.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
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
class zen_modules_RscExecuteCode: zen_modules_RscDisplay
{
	function="zen_modules_fnc_gui_executeCode";
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
			h="((15.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class History: zen_common_RscCombo
				{
					idc=62101;
					font="EtelkaMonospacePro";
					x=0;
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					sizeEx="((0.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Edit: zen_common_RscEdit
				{
					idc=62102;
					style=16;
					font="EtelkaMonospacePro";
					tooltip="$STR_zen_modules_ModuleExecuteCode_Args_Tooltip";
					x="pixelW";
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40)) - pixelW";
					h="((13) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					sizeEx="((0.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					autocomplete="scripting";
					default=1;
				};
				class Mode: ctrlToolbox
				{
					idc=62103;
					x=0;
					y="((14.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					rows=1;
					columns=4;
					strings[]=
					{
						"$STR_zen_modules_ModuleExecuteCode_Local",
						"$STR_zen_modules_ModuleExecuteCode_Server",
						"$STR_zen_modules_ModuleExecuteCode_Global",
						"$STR_zen_modules_ModuleExecuteCode_GlobalAndJIP"
					};
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
class zen_modules_RscFireMission: zen_modules_RscDisplay
{
	function="zen_modules_fnc_gui_fireMission";
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
			h="((8.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class TargetingLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_ModuleFireMission_Targetting";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class TargetingBackground: RscText
				{
					idc=-1;
					x=0;
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((3.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={1,1,1,0.1};
				};
				class ModeLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_ModuleFireMission_Mode";
					x="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((8) * (((safezoneW / safezoneH) min 1.2) / 40))";
					colorBackground[]={0,0,0,0.60000002};
				};
				class Mode: ctrlToolbox
				{
					idc=62001;
					x="((9.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((15.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					rows=1;
					columns=2;
					strings[]=
					{
						"$STR_zen_modules_ModuleFireMission_MapGrid",
						"$STR_zen_modules_ModuleFireMission_TargetModule"
					};
				};
				class TargetLabel: ModeLabel
				{
					idc=62002;
					text="$STR_3den_display3den_menubar_grid_text";
					y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class TargetGrid: zen_common_RscEdit
				{
					idc=62003;
					x="((9.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + pixelH";
					colorBackground[]={0,0,0,0.30000001};
				};
				class TargetLogic: zen_common_RscCombo
				{
					idc=62004;
					x="((9.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class SpreadLabel: ModeLabel
				{
					text="$STR_zen_modules_ModuleFireMission_Spread";
					tooltip="$STR_zen_modules_ModuleFireMission_Spread_Tooltip";
					y="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class SpreadSlider: ctrlXSliderH
				{
					idc=62005;
					x="((9.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((13.4) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class SpreadEdit: zen_common_RscEdit
				{
					idc=62006;
					x="((22.6) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((2.4) * (((safezoneW / safezoneH) min 1.2) / 40))";
					colorBackground[]={0,0,0,0.30000001};
				};
				class FireParamsLabel: TargetingLabel
				{
					text="$STR_zen_modules_ModuleFireMission_FireParameters";
					y="((4.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class FireParamsBackground: TargetingBackground
				{
					y="((5.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class UnitsLabel: ModeLabel
				{
					text="$STR_zen_modules_ModuleFireMission_Units";
					tooltip="$STR_zen_modules_ModuleFireMission_Units_Tooltip";
					y="((5.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Units: TargetLogic
				{
					idc=62007;
					y="((5.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class AmmoLabel: ModeLabel
				{
					text="$STR_zen_modules_ModuleFireMission_Ammo";
					y="((6.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Ammo: Units
				{
					idc=62008;
					y="((6.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class RoundsLabel: ModeLabel
				{
					text="$STR_zen_modules_ModuleFireMission_Rounds";
					tooltip="$STR_zen_modules_ModuleFireMission_Rounds_Tooltip";
					y="((7.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Rounds: TargetGrid
				{
					idc=62009;
					y="((7.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + pixelH";
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
class zen_modules_RscGlobalHint: zen_modules_RscDisplay
{
	function="zen_modules_fnc_gui_globalHint";
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
			h="((10) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class Edit: RscEditMulti
				{
					idc=60601;
					x="pixelW";
					y="pixelH";
					w="((13.2) * (((safezoneW / safezoneH) min 1.2) / 40)) - pixelW";
					h="((10) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) - pixelH";
					colorBackground[]={0.25,0.25,0.25,0.1};
				};
				class Container: zen_common_RscControlsGroup
				{
					idc=-1;
					x="((13.3) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y=0;
					w="((12.7) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((10) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					class controls
					{
						class Preview: RscStructuredText
						{
							idc=60602;
							x=0;
							y=0;
							w="((12.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h=1;
							size="((0.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							colorBackground[]={0,0,0,0.60000002};
							class Attributes
							{
								font="RobotoCondensed";
								color="#FFFFFF";
								colorLink="#D09B43";
								align="center";
								shadow=1;
							};
						};
					};
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
class zen_modules_RscSetDate: zen_modules_RscDisplay
{
	function="zen_modules_fnc_gui_setDate";
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
			h="((6.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class DateLabel: zen_common_RscLabel
				{
					text="$STR_3DEN_Environment_Attribute_Date_displayName";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class DateBackground: zen_common_RscBackground
				{
					x=0;
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Year: zen_common_RscCombo
				{
					idc=61601;
					font="RobotoCondensedLight";
					x="((3.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((1.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((6) * (((safezoneW / safezoneH) min 1.2) / 40))";
					sizeEx="((0.85) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Month: Year
				{
					idc=61602;
					x="((10) * (((safezoneW / safezoneH) min 1.2) / 40))";
					class Items
					{
						class Month1
						{
							text="$STR_3DEN_Attributes_Date_Month1_text";
							value=1;
						};
						class Month2
						{
							text="$STR_3DEN_Attributes_Date_Month2_text";
							value=2;
						};
						class Month3
						{
							text="$STR_3DEN_Attributes_Date_Month3_text";
							value=3;
						};
						class Month4
						{
							text="$STR_3DEN_Attributes_Date_Month4_text";
							value=4;
						};
						class Month5
						{
							text="$STR_3DEN_Attributes_Date_Month5_text";
							value=5;
						};
						class Month6
						{
							text="$STR_3DEN_Attributes_Date_Month6_text";
							value=6;
						};
						class Month7
						{
							text="$STR_3DEN_Attributes_Date_Month7_text";
							value=7;
						};
						class Month8
						{
							text="$STR_3DEN_Attributes_Date_Month8_text";
							value=8;
						};
						class Month9
						{
							text="$STR_3DEN_Attributes_Date_Month9_text";
							value=9;
						};
						class Month10
						{
							text="$STR_3DEN_Attributes_Date_Month10_text";
							value=10;
						};
						class Month11
						{
							text="$STR_3DEN_Attributes_Date_Month11_text";
							value=11;
						};
						class Month12
						{
							text="$STR_3DEN_Attributes_Date_Month12_text";
							value=12;
						};
					};
				};
				class Day: Year
				{
					idc=61603;
					x="((16.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class TimeLabel: DateLabel
				{
					text="$STR_3DEN_Environment_Attribute_Daytime_displayName";
					y="((3.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class TimeBackground: DateBackground
				{
					y="((4.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class TimePreview: RscControlsGroupNoScrollbars
				{
					idc=61604;
					x="((5.05) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((4.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((9.8) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					class controls
					{
						class Night1: RscPicture
						{
							idc=61605;
							text="\a3\3DEN\Data\Attributes\SliderTimeDay\night_ca.paa";
							x=0;
							y=0;
							w="((0.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							colorText[]={1,1,1,0.60000002};
						};
						class Night2: Night1
						{
							idc=61606;
						};
						class Daytime: Night1
						{
							idc=61607;
							text="\a3\3DEN\Data\Attributes\SliderTimeDay\day_ca.paa";
						};
						class Sunrise: Night1
						{
							idc=61608;
							text="\a3\3DEN\Data\Attributes\SliderTimeDay\sunrise_ca.paa";
						};
						class Sunset: Night1
						{
							idc=61609;
							text="\a3\3DEN\Data\Attributes\SliderTimeDay\sunset_ca.paa";
						};
						class Sun: Night1
						{
							idc=61610;
							text="\a3\3DEN\Data\Attributes\SliderTimeDay\sun_ca.paa";
							x="((4.4) * (((safezoneW / safezoneH) min 1.2) / 40))";
							w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
					};
				};
				class Slider: ctrlXSliderH
				{
					idc=61611;
					x="((3.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((4.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((12.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					sliderRange[]={0,86399};
					sliderPosition=0;
					lineSize=3600;
					pageSize=3600;
					border="\a3\3DEN\Data\Attributes\SliderTimeDay\border_ca.paa";
					thumb="\a3\3DEN\Data\Attributes\SliderTimeDay\thumb_ca.paa";
				};
				class Separator: RscText
				{
					idc=-1;
					style=2;
					text=":   :";
					font="EtelkaMonospacePro";
					x="((16.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((4.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((6) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0.5};
				};
				class Hour: zen_common_RscEdit
				{
					idc=61612;
					style=514;
					text="00";
					tooltip="$STR_3DEN_Attributes_SliderTime_Hour_tooltip";
					font="EtelkaMonospacePro";
					x="((16.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((4.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((2) * (((safezoneW / safezoneH) min 1.2) / 40))";
					sizeEx="((0.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0};
					maxChars=2;
				};
				class Minute: Hour
				{
					idc=61613;
					tooltip="$STR_3DEN_Attributes_SliderTime_Minute_tooltip";
					x="((18.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class Second: Hour
				{
					idc=61614;
					tooltip="$STR_3DEN_Attributes_SliderTime_Second_tooltip";
					x="((20.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
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
class zen_modules_RscSideRelations: zen_modules_RscDisplay
{
	function="zen_modules_fnc_gui_sideRelations";
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
			h="((2.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class RelationLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_RelationToChange";
				};
				class RelationToggle: ctrlButtonPictureKeepAspect
				{
					idc=60201;
					text="\a3\ui_f\data\igui\cfg\simpletasks\types\help_ca.paa";
					tooltip="$STR_zen_modules_FriendlyTo";
					x="((17.55) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y=0;
					w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0.69999999};
					tooltipColorBox[]={1,1,1,1};
					tooltipColorShade[]={0,0,0,0.64999998};
					offsetPressedX=0;
					offsetPressedY=0;
				};
				class RelationSide_1: zen_common_RscCombo
				{
					idc=60202;
					x="((10.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y=0;
					w="((7.35) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					class Items
					{
						class BLUFOR
						{
							text="$STR_WEST";
							picture="\x\zen\addons\common\ui\icon_blufor_ca.paa";
							value=1;
						};
						class OPFOR
						{
							text="$STR_EAST";
							picture="\x\zen\addons\common\ui\icon_opfor_ca.paa";
							value=0;
						};
						class Independent
						{
							text="$STR_guerrila";
							picture="\x\zen\addons\common\ui\icon_independent_ca.paa";
							value=2;
						};
					};
				};
				class RelationSide_2: RelationSide_1
				{
					idc=60203;
					x="((18.65) * (((safezoneW / safezoneH) min 1.2) / 40))";
					class Items
					{
					};
				};
				class RadioLabel: zen_common_RscLabel
				{
					text="$STR_zen_modules_PlayRadioMessage";
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Radio: zen_modules_RscToolboxYesNo
				{
					idc=60204;
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
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
class zen_modules_RscSpawnReinforcements: zen_modules_RscDisplay
{
	function="zen_modules_fnc_gui_spawnReinforcements";
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
			h="((27.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class SideLabel: zen_common_RscLabel
				{
					text="$STR_eval_typeside";
				};
				class Side: zen_modules_RscSidesCombo
				{
					idc=62301;
				};
				class VehicleSelect: RscControlsGroupNoScrollbars
				{
					idc=-1;
					x=0;
					y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((4.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					class controls
					{
						class Title: zen_common_RscLabel
						{
							text="$STR_zen_modules_VehicleSelect";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
						class Background: zen_common_RscBackground
						{
							x=0;
							y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((3.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class FactionLabel: zen_common_RscLabel
						{
							text="$STR_zen_common_Faction";
							x="((3) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((8.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
							colorBackground[]={0,0,0,0.69999999};
						};
						class FactionCombo: zen_common_RscCombo
						{
							idc=62302;
							x="((12) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((11) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
						class CategoryLabel: FactionLabel
						{
							text="$STR_zen_modules_Category";
							y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class CategoryCombo: FactionCombo
						{
							idc=62303;
							y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class VehicleLabel: FactionLabel
						{
							text="$STR_zen_common_Vehicle";
							y="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class VehicleCombo: FactionCombo
						{
							idc=62304;
							y="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
					};
				};
				class GroupSelect: RscControlsGroupNoScrollbars
				{
					idc=-1;
					x=0;
					y="((5.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((14.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					class controls
					{
						class Title: zen_common_RscLabel
						{
							text="$STR_zen_modules_GroupSelect";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
						class Background: zen_common_RscBackground
						{
							x=0;
							y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((13.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class TreeMode: ctrlToolbox
						{
							idc=62305;
							x="((0.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((13) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							rows=1;
							columns=2;
							strings[]=
							{
								"$STR_zen_common_Premade",
								"$STR_Radio_Custom"
							};
							colorBackground[]={0,0,0,0.69999999};
						};
						class TreeGroups: ctrlTree
						{
							idc=62306;
							x="((0.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((2.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) - pixelH";
							w="((13) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((12) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							sizeEx="3.96 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
							colorBackground[]={0,0,0,0.30000001};
							colorBorder[]={0,0,0,0};
							disableKeyboardSearch=1;
						};
						class TreeUnits: TreeGroups
						{
							idc=62307;
						};
						class Label: zen_common_RscLabel
						{
							text="$STR_zen_modules_CurrentGroup";
							x="((13.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((12.7) * (((safezoneW / safezoneH) min 1.2) / 40))";
							colorBackground[]={0,0,0,0.69999999};
						};
						class UnitCount: Label
						{
							idc=62309;
							style=1;
							text="0";
							w="((11.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
							colorBackground[]={0,0,0,0};
						};
						class UnitList: ctrlListbox
						{
							idc=62308;
							x="((13.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((2.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) - pixelH";
							w="((12.7) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((12) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							colorBackground[]={0,0,0,0.30000001};
						};
						class UnitIcon: RscPicture
						{
							idc=-1;
							text="\x\zen\addons\modules\ui\person_ca.paa";
							x="((24) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class UnitClear: ctrlButtonPictureKeepAspect
						{
							idc=62310;
							text="\a3\3den\data\cfg3den\history\deleteitems_ca.paa";
							x="((24.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							colorBackground[]={0,0,0,0};
							offsetPressedX=0;
							offsetPressedY=0;
						};
					};
				};
				class Properties: RscControlsGroupNoScrollbars
				{
					idc=-1;
					x=0;
					y="((19.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((7.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					class controls
					{
						class Title: zen_common_RscLabel
						{
							text="$STR_A3_RscDisplayLogin_Properties";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
						class Background: zen_common_RscBackground
						{
							x=0;
							y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((6.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class VehicleLZLabel: zen_common_RscLabel
						{
							text="$STR_zen_modules_VehicleLZ";
							x="((3) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((8.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
							colorBackground[]={0,0,0,0.69999999};
						};
						class VehicleLZ: zen_common_RscCombo
						{
							idc=62311;
							x="((12) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((1.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((11) * (((safezoneW / safezoneH) min 1.2) / 40))";
						};
						class VehicleBehaviourLabel: VehicleLZLabel
						{
							text="Vehicle Behaviour";
							y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class VehicleBehaviour: ctrlToolbox
						{
							idc=62312;
							x="((12) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((2.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((11) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							rows=1;
							columns=2;
							strings[]=
							{
								"$STR_zen_modules_StayAtLZ",
								"$STR_zen_modules_RTBAndDespawn"
							};
							colorBackground[]={0,0,0,0.69999999};
						};
						class InsertionLabel: VehicleLZLabel
						{
							text="$STR_zen_modules_InsertionMethod";
							y="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class Insertion: VehicleLZ
						{
							idc=62313;
							y="((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class FlyHeightLabel: VehicleLZLabel
						{
							text="$STR_zen_modules_ModuleFlyHeight";
							y="((4.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class FlyHeight: zen_common_RscEdit
						{
							idc=62314;
							x="((12) * (((safezoneW / safezoneH) min 1.2) / 40))";
							y="((4.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							w="((11) * (((safezoneW / safezoneH) min 1.2) / 40))";
							h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							colorBackground[]={0,0,0,0.30000001};
						};
						class UnitRPLabel: VehicleLZLabel
						{
							text="$STR_zen_modules_UnitRP";
							y="((5.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class UnitRP: VehicleLZ
						{
							idc=62315;
							y="((5.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class UnitBehaviourLabel: VehicleLZLabel
						{
							text="$STR_zen_modules_UnitBehaviour";
							y="((6.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
						};
						class UnitBehaviour: VehicleBehaviour
						{
							idc=62316;
							y="((6.6) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
							columns=4;
							strings[]=
							{
								"$STR_Disp_Default",
								"$STR_zen_common_Relaxed",
								"$STR_zen_common_Cautious",
								"$STR_Combat"
							};
						};
					};
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
class zen_modules_RscTracers: zen_modules_RscDisplay
{
	function="zen_modules_fnc_gui_tracers";
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
			h="((19.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class WeaponLabel: zen_common_RscLabel
				{
					text="$STR_zen_common_Weapon";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class WeaponBackground: zen_common_RscBackground
				{
					x=0;
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Weapon: ctrlListNBox
				{
					idc=62400;
					x=0;
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					rowHeight="((1.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					columns[]={0.050000001,0.15000001,0.89999998};
					tooltipPerColumn=0;
				};
				class MagazineLabel: WeaponLabel
				{
					text="$STR_zen_common_Magazine";
					y="((6.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class MagazineBackground: WeaponBackground
				{
					y="((7.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Magazine: Weapon
				{
					idc=62401;
					y="((7.1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class DelayLabel: WeaponLabel
				{
					text="$STR_zen_modules_Tracers_BurstDelay";
					tooltip="$STR_zen_modules_Tracers_BurstDelay_Tooltip";
					y="((12.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class DelayBackground: WeaponBackground
				{
					y="((13.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class DelayMinLabel: RscText
				{
					style=1;
					text="$STR_3DEN_Attributes_Timeout_TitleMin_text";
					font="RobotoCondensedLight";
					x="((4) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((13.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((2) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					shadow=0;
				};
				class DelayMin: zen_common_RscEdit
				{
					idc=62402;
					font="EtelkaMonospacePro";
					x="((6) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((13.7) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((4) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					sizeEx="((0.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class DelayMidLabel: DelayMinLabel
				{
					text="$STR_3DEN_Attributes_Timeout_TitleMid_text";
					x="((10) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class DelayMid: DelayMin
				{
					idc=62403;
					x="((12) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class DelayMaxLabel: DelayMinLabel
				{
					text="$STR_3DEN_Attributes_Timeout_TitleMax_text";
					x="((16) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class DelayMax: DelayMin
				{
					idc=62404;
					x="((18) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
				class DispersionLabel: WeaponLabel
				{
					text="$STR_zen_modules_Tracers_Dispersion";
					tooltip="$STR_zen_modules_Tracers_Dispersion_Tooltip";
					y="((15.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Dispersion: ctrlToolbox
				{
					idc=62405;
					x=0;
					y="((16.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					rows=1;
					columns=5;
					strings[]=
					{
						"$STR_zen_common_VeryLow",
						"$STR_zen_common_Low",
						"$STR_zen_common_Medium",
						"$STR_zen_common_High",
						"$STR_zen_common_VeryHigh"
					};
				};
				class TargetLabel: WeaponLabel
				{
					text="$STR_A3_CfgVehicles_ModuleAI_F_Arguments_Target_0";
					y="((17.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class Target: Dispersion
				{
					idc=62406;
					y="((18.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					columns=3;
					strings[]=
					{
						"$STR_A3_RscDisplayArsenal_ButtonRandom",
						"$STR_3DEN_Camera_textSingular",
						"$STR_zen_common_Cursor"
					};
					tooltips[]=
					{
						"$STR_zen_modules_Tracers_Random_Tooltip",
						"$STR_zen_modules_Tracers_Camera_Tooltip",
						"$STR_zen_modules_Tracers_Cursor_Tooltip"
					};
				};
				class Change: ctrlCheckbox
				{
					idc=62407;
					x="((25) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((17.4) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
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
