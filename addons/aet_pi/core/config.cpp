class CfgPatches
{
	class AET_PI_core
	{
		name="AET Plan Importer Plan Importer";
		author="$STR_aet_plan_importer_author";
		authors[]=
		{
			"Nomas / Redwan S. [AET]",
			"OverlordZorn [CVO]"
		};
		url="$STR_aet_plan_importer_URL";
		version=2.5999999;
		versionStr="2.6.0.699";
		versionAr[]={2,6,0,699};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"AET_PI_main",
			"cba_main",
			"CAU_UserInputMenus"
		};
		skipWhenMissingDependencies=1;
		units[]={};
		weapons[]={};
	};
};
class CfgFunctions
{
	class AET_PI_core
	{
		class core
		{
			file="\z\AET_PI\addons\core\functions";
			class postInit
			{
				postInit=1;
			};
			class preInit
			{
				preInit=1;
			};
			class useActionCondition
			{
			};
			class selectChannel
			{
			};
			class importPlan
			{
			};
			class createMarkers
			{
			};
			class deletePlan
			{
			};
			class notifyAdmin
			{
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class AET_PI_core
	{
		init="call compile preprocessFileLineNumbers '\z\AET_PI\addons\core\XEH\XEH_preInit.sqf'";
	};
};
