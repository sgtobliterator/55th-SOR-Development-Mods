class CfgPatches
{
	class zen_doors
	{
		name="ZEN - Doors";
		units[]=
		{
			"zen_doors_module"
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
				"zen_doors"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_doors
	{
		init="call compileScript ['\x\zen\addons\doors\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_doors
	{
		init="call compileScript ['\x\zen\addons\doors\XEH_preInit.sqf']";
	};
};
class CfgVehicles
{
	class zen_modules_moduleBase;
	class zen_doors_module: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Buildings";
		displayName="$STR_zen_doors_Configure";
		icon="\a3\ui_f\data\igui\cfg\actions\open_door_ca.paa";
		function="zen_doors_fnc_module";
	};
};
class zen_context_menu_actions
{
	class zen_doors_state
	{
		displayName="$STR_zen_doors_DoorState";
		icon="\a3\ui_f\data\igui\cfg\actions\open_door_ca.paa";
		insertChildren="call zen_doors_fnc_getActions";
		priority=100;
	};
};
class RscActivePicture;
class zen_doors_RscActivePicture: RscActivePicture
{
	shadow=2;
};
