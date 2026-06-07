class CfgPatches
{
	class zen_remote_control
	{
		name="ZEN - Remote Control";
		units[]=
		{
			"zen_remote_control_module"
		};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_modules"
		};
		author="$STR_zen_main_Author";
		authors[]=
		{
			"mharis001"
		};
		url="$STR_zen_main_URL";
		version=1.15;
		versionStr="1.15.1.36";
		versionAr[]={1,15,1,36};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class zen
		{
			list[]+=
			{
				"zen_remote_control"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_remote_control
	{
		init="call compileScript ['\x\zen\addons\remote_control\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_remote_control
	{
		init="call compileScript ['\x\zen\addons\remote_control\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_remote_control
	{
		init="call compileScript ['\x\zen\addons\remote_control\XEH_postInit.sqf']";
	};
};
class CfgVehicles
{
	class Module_F;
	class ModuleRemoteControl_F: Module_F
	{
		scopeCurator=1;
	};
	class zen_modules_moduleBase;
	class zen_remote_control_module: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="Curator";
		displayName="$STR_A3_CfgVehicles_ModuleRemoteControl_F";
		icon="\a3\modules_f_curator\data\portraitremotecontrol_ca.paa";
		function="zen_remote_control_fnc_module";
	};
};
