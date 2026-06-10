class CfgPatches
{
	class digii_ambient_agents
	{
		name="digii_ambient - Agents";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"digii_ambient_main",
			"digii_ambient_factions"
		};
		author="DiGii";
		version=0.1;
		versionStr="0.1.0";
		versionAr[]={0,1,0};
	};
};
class Extended_PreInit_EventHandlers
{
	class digii_ambient_agents
	{
		init="call compile preProcessFileLineNumbers '\z\digii_ambient\addons\agents\XEH_preInit.sqf'";
		disableModuload="true";
	};
};
