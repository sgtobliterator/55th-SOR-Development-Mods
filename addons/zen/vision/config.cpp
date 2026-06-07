class CfgPatches
{
	class zen_vision
	{
		name="ZEN - Vision";
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
				"zen_vision"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_vision
	{
		init="call compileScript ['\x\zen\addons\vision\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_vision
	{
		init="call compileScript ['\x\zen\addons\vision\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_vision
	{
		init="call compileScript ['\x\zen\addons\vision\XEH_postInit.sqf']";
	};
};
class CfgFunctions
{
	class A3_Functions_F_Curator
	{
		class Curator
		{
			class toggleCuratorVisionMode
			{
				file="\x\zen\addons\vision\functions\fnc_bi_toggleCuratorVisionMode.sqf";
			};
		};
	};
};
class RscText;
class RscTitles
{
	class zen_vision_RscVisionModes
	{
		idd=-1;
		fadeIn=0;
		duration=2;
		onLoad="_this call zen_vision_fnc_showHint";
		class controls
		{
			class Mode_0: RscText
			{
				idc=840;
				style=2;
				x=0;
				y="safeZoneY + ((3.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				w="((safeZoneW - ((26) * (((safezoneW / safezoneH) min 1.2) / 40))) / 10)";
				h="((0.9) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				sizeEx="((0.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				shadow=0;
			};
			class Mode_1: Mode_0
			{
				idc=841;
			};
			class Mode_2: Mode_0
			{
				idc=842;
			};
			class Mode_3: Mode_0
			{
				idc=843;
			};
			class Mode_4: Mode_0
			{
				idc=844;
			};
			class Mode_5: Mode_0
			{
				idc=845;
			};
			class Mode_6: Mode_0
			{
				idc=846;
			};
			class Mode_7: Mode_0
			{
				idc=847;
			};
			class Mode_8: Mode_0
			{
				idc=848;
			};
			class Mode_9: Mode_0
			{
				idc=849;
			};
		};
	};
};
