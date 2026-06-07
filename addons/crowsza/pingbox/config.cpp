class CfgPatches
{
	class crowsza_pingbox
	{
		name="pingbox";
		units[]={};
		weapons[]={};
		requiredVersion=2.0999999;
		requiredAddons[]=
		{
			"crowsza_main"
		};
		author="Crowdedlight";
		version=2.2;
		versionStr="2.2";
		versionAr[]={2,2,2};
	};
};
class Extended_PreInit_EventHandlers
{
	class crowsza_pingbox
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\pingbox\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class crowsza_pingbox
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\pingbox\XEH_postInit.sqf'";
	};
};
class Extended_PreStart_EventHandlers
{
	class crowsza_pingbox
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\pingbox\XEH_preStart.sqf'";
	};
};
class ctrlListNBox;
class RscText;
class RscTitles
{
	class Default
	{
		idd=-1;
		fadein=0;
		fadeout=0;
		duration=0;
	};
	class crowsza_pingbox_hud
	{
		idd=-1;
		fadein=0.050000001;
		fadeout=0;
		duration=9999999;
		name="crowsza_pingbox_hud";
		onLoad="uiNamespace setVariable ['crowsza_pingbox_hud', _this select 0];";
		onUnLoad="uinamespace setVariable ['crowsza_pingbox_hud', nil]";
		class Controls
		{
			class list: ctrlListNBox
			{
				idc=1730;
				x="0.139062 * safezoneW + safezoneX";
				y="0.929 * safezoneH + safezoneY";
				w="0.108281 * safezoneW";
				h="3 * 0.020 * safezoneH";
				drawSideArrows=0;
				disableOverflow=1;
				tooltipPerColumn=0;
				columns[]={0,0.80000001};
				colorBackground[]={1,1,1,0.2};
			};
			class title: RscText
			{
				idc=1740;
				text="PingBox";
				style="ST_CENTER";
				x="0.139062 * safezoneW + safezoneX";
				y="(0.929 - 0.020) * safezoneH + safezoneY";
				w="0.108281 * safezoneW";
				h="0.020 * safezoneH";
				colorBackground[]=
				{
					"(profileNamespace getVariable ['GUI_BCG_RGB_R',0.13])",
					"(profileNamespace getVariable ['GUI_BCG_RGB_G',0.54])",
					"(profileNamespace getVariable ['GUI_BCG_RGB_B',0.21])",
					"(profileNamespace getVariable ['GUI_BCG_RGB_A',0.8])"
				};
			};
			class ListBackground: RscText
			{
				idc=1750;
				style="ST_CENTER";
				x="0.139062 * safezoneW + safezoneX";
				y="0.929 * safezoneH + safezoneY";
				w="0.108281 * safezoneW";
				h="3 * 0.020 * safezoneH";
				colorText[]={1,1,1,0.5};
				colorBackground[]={0,0,0,0.5};
			};
		};
	};
};
