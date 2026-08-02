class CfgPatches
{
	class mts_engineer
	{
		name="mts - Engineer";
		units[]=
		{
			"mts_engineer_miclic"
		};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"ace_cargo",
			"ace_dragging"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"Timi007",
			"Mishkar",
			"Lemonberries"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.1.260719";
		versionAr[]={1,10,1,260719};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_engineer
	{
		init="call compileScript ['\z\mts_enhanced\addons\engineer\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_engineer
	{
		init="call compileScript ['\z\mts_enhanced\addons\engineer\XEH_preInit.sqf']";
	};
};
class Extended_InitPost_EventHandlers
{
	class mts_engineer_miclic
	{
		class mts_engineer_miclic_addIgniteAction
		{
			clientInit="_this call mts_engineer_fnc_addIgniteMiclicAction";
		};
	};
};
class CfgVehicles
{
	class ThingX;
	class mts_engineer_miclic_base: ThingX
	{
		author="$STR_mts_engineer_authors";
		mapSize=5.1799998;
		animated=0;
		icon="iconCrateOrd";
		accuracy=0.2;
		editorCategory="EdCat_Weapons";
		editorSubcategory="EdSubcat_Explosives";
		vehicleClass="Ammo";
		destrType="DestructBuilding";
		explosionEffect="BasicAmmoExplosion";
		class DestructionEffects
		{
			class Smoke2
			{
				simulation="particles";
				type="AmmoSmokeParticles2";
				position="";
				intensity=1;
				interval=1;
				lifeTime=2;
			};
			class Bullets
			{
				simulation="particles";
				type="AmmoBulletCore";
				position="";
				intensity=1;
				interval=1;
				lifeTime=1.2;
			};
			class HouseDestr
			{
				simulation="destroy";
				type="DelayedDestructionAmmoBox";
				position="";
				intensity=1;
				interval=1;
				lifeTime=10;
			};
		};
		cost=0;
		armor=200;
		waterLinearDampingCoefY=1;
		waterAngularDampingCoef=0.1;
		scope=1;
	};
	class mts_engineer_miclic: mts_engineer_miclic_base
	{
		displayName="$STR_mts_engineer_miclicDisplayName";
		editorPreview="\A3\EditorPreviews_F_Exp\Data\CfgVehicles\Box_IED_Exp_F.jpg";
		scope=2;
		scopeCurator=2;
		model="\A3\Weapons_F\Ammoboxes\Proxy_UsBasicExplosives.p3d";
		ace_cargo_canLoad=1;
		ace_cargo_size=4;
		ace_dragging_canCarry=1;
		ace_dragging_carryPosition[]={0,1.2,1};
		ace_dragging_canDrag=1;
		ace_dragging_dragPosition[]={0,1.2,0};
	};
	class B_APC_Tracked_01_base_F;
	class B_APC_Tracked_01_CRV_F: B_APC_Tracked_01_base_F
	{
		class Attributes
		{
			class mts_engineer_mineClearing
			{
				displayName="$STR_mts_engineer_mineClearingDisplayName";
				tooltip="$STR_mts_engineer_mineClearingTooltip";
				property="mts_engineer_enableMineClearing";
				control="Checkbox";
				defaultValue="true";
				typeName="BOOL";
				expression="_this setVariable [""mts_engineer_enableMineClearing"", _value, true];";
			};
		};
	};
};
