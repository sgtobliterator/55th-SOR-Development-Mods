class CfgPatches
{
	class mts_engineer_compat_gm
	{
		name="mts - Engineer";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_engineer",
			"gm_vehicles_land_tracked_bpz2"
		};
		skipWhenMissingDependencies=1;
		author="$STR_mts_main_authors";
		authors[]=
		{
			"Timi007"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.1.260719";
		versionAr[]={1,10,1,260719};
		addonRootClass="mts_engineer";
	};
};
class CfgVehicles
{
	class gm_tracked_Tank_base;
	class gm_Leopard1_base: gm_tracked_Tank_base
	{
		class Attributes;
	};
	class gm_BPz2_base: gm_Leopard1_base
	{
		class Attributes: Attributes
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
