class CfgPatches
{
	class zen_context_menu
	{
		name="ZEN - Context Menu";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_common"
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
				"zen_context_menu"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_context_menu
	{
		init="call compileScript ['\x\zen\addons\context_menu\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_context_menu
	{
		init="call compileScript ['\x\zen\addons\context_menu\XEH_preInit.sqf']";
	};
};
class RscText;
class RscPicture;
class RscControlsGroupNoScrollbars;
class zen_context_menu_group: RscControlsGroupNoScrollbars
{
	idc=185000;
	x=0;
	y=0;
	w="((8) * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls
	{
		class Background: RscText
		{
			idc=185010;
			x=0;
			y=0;
			w="((8) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorBackground[]={0.1,0.1,0.1,0.5};
		};
	};
};
class zen_context_menu_row: RscControlsGroupNoScrollbars
{
	idc=185020;
	x=0;
	y=0;
	w="((8) * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
	class controls
	{
		class Highlight: RscText
		{
			idc=185030;
			x=0;
			y=0;
			w="((8) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Name: RscText
		{
			idc=185040;
			x="((1.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y=0;
			w="((5.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			sizeEx="((0.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			shadow=0;
		};
		class Icon: RscPicture
		{
			idc=185050;
			x="((0.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y="((0.05) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((0.9) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((0.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class Expandable: RscPicture
		{
			idc=185060;
			text="\x\zen\addons\context_menu\ui\arrow_ca.paa";
			x="((7) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y=0;
			w="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class MouseArea: RscText
		{
			idc=185070;
			style=16;
			x=0;
			y=0;
			w="((8) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
};
