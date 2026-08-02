class CfgPatches
{
	class PHEN_ZFM_core
	{
		name="AET Zeus FPS Monitor Core";
		author="$STR_PHEN_ZFM_author";
		authors[]=
		{
			"Nomas / Redwan S. [AET]",
			"OverlordZorn [CVO]"
		};
		url="$STR_github_PHEN_ZFM_URL";
		version=3.0999999;
		versionStr="3.1.0.78";
		versionAr[]={3,1,0,78};
		requiredVersion=2.0599999;
		requiredAddons[]=
		{
			"PHEN_ZFM_main",
			"cba_main"
		};
		skipWhenMissingDependencies=1;
		units[]={};
		weapons[]={};
	};
};
class CfgFunctions
{
	class PHEN_ZFM_core
	{
		class core
		{
			file="\z\PHEN_ZFM\addons\core\functions";
			class handleDataServer
			{
			};
			class registerZeus
			{
			};
			class unregisterZeus
			{
			};
			class startClientStatMonitor
			{
			};
			class displayMonitor
			{
			};
			class postInit
			{
				postInit=1;
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class PHEN_ZFM_core
	{
		init="call compile preprocessFileLineNumbers '\z\PHEN_ZFM\addons\core\XEH\XEH_preInit.sqf'";
	};
};
class CfgNotifications
{
	class Default
	{
		title="";
		iconPicture="";
		iconText="";
		description="";
		color[]={1,1,1,1};
		duration=5;
		priority=0;
		difficulty[]={};
	};
	class PHEN_ZFM_core_DesyncMild
	{
		title="MILD DESYNC";
		iconPicture="\A3\ui_f\data\gui\rsc\rscpendinginvitation\desynclow_ca.paa";
		description="%1";
		color[]={1,0.85000002,0,1};
		duration=5;
		priority=6;
	};
	class PHEN_ZFM_core_DesyncSevere
	{
		title="SEVERE DESYNC";
		iconPicture="\A3\ui_f\data\gui\rsc\rscpendinginvitation\desynchigh_ca.paa";
		description="%1";
		color[]={1,0,0,1};
		duration=6;
		priority=9;
	};
	class PHEN_ZFM_core_DesyncResolved
	{
		title="CONNECTION STABLE";
		iconPicture="\A3\ui_f\data\igui\rsctitles\rschvtphase\jac_a3_signal_4_ca.paa";
		description="%1";
		color[]={0,1,0.30000001,1};
		duration=4;
		priority=4;
	};
};
