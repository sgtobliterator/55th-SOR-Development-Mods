class CfgPatches
{
	class zen_editor_previews
	{
		name="ZEN - Editor Previews";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_editor"
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
				"zen_editor_previews"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_editor_previews
	{
		init="call compileScript ['\x\zen\addons\editor_previews\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_editor_previews
	{
		init="call compileScript ['\x\zen\addons\editor_previews\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_editor_previews
	{
		init="call compileScript ['\x\zen\addons\editor_previews\XEH_postInit.sqf']";
	};
};
class ctrlStatic;
class ctrlStaticPictureKeepAspect;
class ctrlControlsGroupNoScrollbars;
class zen_editor_previews_control: ctrlControlsGroupNoScrollbars
{
	idc=98470;
	x=0;
	y=0;
	w=0;
	h="((5.2 + 2 * 0.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls
	{
		class Background: ctrlStatic
		{
			idc=-1;
			x=0;
			y=0;
			w=1;
			h=1;
			colorBackground[]={0.1,0.1,0.1,0.5};
		};
		class Image: ctrlStaticPictureKeepAspect
		{
			idc=98480;
			x="((0.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y="((0.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w=0;
			h="((5.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
};
