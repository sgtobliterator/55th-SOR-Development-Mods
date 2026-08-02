class CfgPatches
{
	class digii_ambient_main
	{
		name="digii_ambient - Main";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"A3_Data_F_Tank_Loadorder",
			"cba_main"
		};
		author="DiGii";
		url="";
		version=0.1;
		versionStr="0.1.0";
		versionAr[]={0,1,0};
	};
};
class CfgMods
{
	class digii_ambient
	{
		dir="@digii_ambient";
		name="$STR_digii_ambient_main_modName";
		picture="A3\Ui_f\data\Logos\arma3_expansion_alpha_ca.paa";
		hidePicture="true";
		hideName="true";
		actionName="Website";
		action="";
		description="$STR_digii_ambient_main_modDescription";
	};
};
class Extended_PreInit_EventHandlers
{
	class digii_ambient_main
	{
		init="call compile preProcessFileLineNumbers '\z\digii_ambient\addons\main\XEH_preInit.sqf'";
		disableModuload="true";
	};
};
class Extended_PostInit_EventHandlers
{
	class digii_ambient_main
	{
		init="call compile preProcessFileLineNumbers '\z\digii_ambient\addons\main\XEH_postInit.sqf'";
	};
};
class CfgSettings
{
	class CBA
	{
		class Versioning
		{
			class digii_ambient
			{
				class dependencies
				{
					CBA[]=
					{
						"cba_main",
						{3,18,0},
						"(true)"
					};
				};
			};
		};
	};
};
