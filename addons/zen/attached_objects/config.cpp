class CfgPatches
{
	class zen_attached_objects
	{
		name="ZEN - Attached Objects";
		units[]=
		{
			"zen_attached_objects_module"
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
				"zen_attached_objects"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_attached_objects
	{
		init="call compile preprocessFileLineNumbers '\x\zen\addons\attached_objects\XEH_preStart.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_attached_objects
	{
		init="call compile preprocessFileLineNumbers '\x\zen\addons\attached_objects\XEH_preInit.sqf'";
	};
};
class CfgVehicles
{
	class zen_modules_moduleBase;
	class zen_attached_objects_module: zen_modules_moduleBase
	{
		curatorCanAttach=1;
		category="zen_modules_Objects";
		displayName="$STR_zen_attached_objects_AttachTo";
		function="zen_attached_objects_fnc_module";
	};
};
