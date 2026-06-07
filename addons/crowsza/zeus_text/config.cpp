class CfgPatches
{
	class crowsza_zeus_text
	{
		name="zeus_text";
		units[]={};
		weapons[]={};
		requiredVersion=2.0999999;
		requiredAddons[]=
		{
			"crowsza_main"
		};
		author="Crowdedlight";
		version=2.2;
		versionStr="2.2";
		versionAr[]={2,2,2};
	};
};
class Extended_PreInit_EventHandlers
{
	class crowsza_zeus_text
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\zeus_text\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class crowsza_zeus_text
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\zeus_text\XEH_postInit.sqf'";
	};
};
class Extended_PreStart_EventHandlers
{
	class crowsza_zeus_text
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\zeus_text\XEH_preStart.sqf'";
	};
};
