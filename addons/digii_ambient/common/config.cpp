class CfgPatches
{
	class digii_ambient_common
	{
		name="digii_ambient - Common";
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
	class digii_ambient_common
	{
		init="call compile preProcessFileLineNumbers '\z\digii_ambient\addons\common\XEH_preInit.sqf'";
		disableModuload="true";
	};
};
