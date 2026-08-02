class CfgPatches
{
	class digii_ambient_factions
	{
		name="digii_ambient - Factions";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"digii_ambient_main"
		};
		author="DiGii";
		version=0.1;
		versionStr="0.1.0";
		versionAr[]={0,1,0};
	};
};
class Extended_PreInit_EventHandlers
{
	class digii_ambient_factions
	{
		init="call compile preProcessFileLineNumbers '\z\digii_ambient\addons\factions\XEH_preInit.sqf'";
		disableModuload="true";
	};
};
