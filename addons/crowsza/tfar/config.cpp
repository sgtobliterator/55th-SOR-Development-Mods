class CfgPatches
{
	class crowsza_tfar
	{
		name="tfar";
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
	class crowsza_tfar
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\tfar\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class crowsza_tfar
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\tfar\XEH_postInit.sqf'";
	};
};
class Extended_PreStart_EventHandlers
{
	class crowsza_tfar
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\tfar\XEH_preStart.sqf'";
	};
};
