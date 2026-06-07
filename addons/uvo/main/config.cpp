class CfgPatches
{
	class uvo_main
	{
		name="$STR_uvo_main_UnitVoiceOvers";
		author="Simplex Team";
		url="";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"cba_main",
			"cba_common",
			"cba_events",
			"cba_keybinding",
			"cba_settings",
			"cba_statemachine",
			"cba_xeh"
		};
		version=20.700001;
		versionStr="2.0.7.000000";
		versionAr[]={2,0,7,0};
	};
	class UVO
	{
		name="main";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"A3_data_f"
		};
		author="Simplex Team";
		version=20.700001;
		versionStr="2.0.7.000000";
		versionAr[]={2,0,7,0};
	};
};
class Extended_PreStart_EventHandlers
{
	class uvo_main
	{
		init="call compile preprocessFileLineNumbers '\z\uvo\addons\main\XEH_preStart.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class uvo_main
	{
		init="call compile preprocessFileLineNumbers '\z\uvo\addons\main\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class uvo_main
	{
		init="call compile preprocessFileLineNumbers '\z\uvo\addons\main\XEH_postInit.sqf'";
	};
};
class CfgFunctions
{
	class UVO
	{
		class Custom
		{
			class register
			{
				file="\z\uvo\addons\main\functions\fnc_register.sqf";
			};
			class addThrowableTypes
			{
				file="\z\uvo\addons\main\functions\fnc_addThrowableTypes.sqf";
			};
		};
		class Deprecated
		{
			class createNationality
			{
				file="\z\uvo\addons\main\deprecated\fnc_createNationality.sqf";
			};
			class createNationalityFromConfig
			{
				file="\z\uvo\addons\main\deprecated\fnc_createNationalityFromConfig.sqf";
			};
			class setNationality
			{
				file="\z\uvo\addons\main\deprecated\fnc_setNationality.sqf";
			};
		};
	};
};
