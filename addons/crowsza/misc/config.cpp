class CfgPatches
{
	class crowsza_misc
	{
		name="misc";
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
	class crowsza_misc
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\misc\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class crowsza_misc
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\misc\XEH_postInit.sqf'";
	};
};
class Extended_PreStart_EventHandlers
{
	class crowsza_misc
	{
		init="call compile preprocessFileLineNumbers '\z\crowsza\addons\misc\XEH_preStart.sqf'";
	};
};
class RscText;
class ctrlListNBox;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscControlsGroupNoScrollbars;
class crowsza_loadout_display
{
	idd=-1;
	movingEnable=1;
	onLoad="uiNamespace setVariable ['crowsza_loadout_display',_this select 0];";
	class controls
	{
		class Title: RscText
		{
			idc=10;
			x="((6.5) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			w="((27) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorBackground[]=
			{
				"(profileNamespace getVariable ['GUI_BCG_RGB_R',0.13])",
				"(profileNamespace getVariable ['GUI_BCG_RGB_G',0.54])",
				"(profileNamespace getVariable ['GUI_BCG_RGB_B',0.21])",
				"(profileNamespace getVariable ['GUI_BCG_RGB_A',0.8])"
			};
			moving=1;
			text="test";
		};
		class Background: RscText
		{
			idc=20;
			x="((6.5) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			w="((27) * (((safezoneW / safezoneH) min 1.2) / 40))";
			colorBackground[]={0,0,0,0.69999999};
		};
		class Content: RscControlsGroupNoScrollbars
		{
			idc=30;
			h="((15.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			x="((7) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
			class controls
			{
				class HeadlineBackground: RscText
				{
					idc=-1;
					style="ST_CENTER";
					x=0;
					y=0;
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0.5};
				};
				class TitleName: RscText
				{
					idc=-1;
					x="((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y=0;
					w="((4) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					text="Name";
				};
				class TitleAmount: RscText
				{
					idc=-1;
					x="((20.8) * (((safezoneW / safezoneH) min 1.2) / 40))";
					w="((4) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					text="Amount";
				};
				class ListBackground: RscText
				{
					idc=-1;
					style="ST_CENTER";
					x=0;
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((13) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorText[]={1,1,1,0.5};
					colorBackground[]={1,1,1,0.2};
				};
				class List: ctrlListNBox
				{
					idc=1543;
					x=0;
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((26) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((13) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					drawSideArrows=0;
					disableOverflow=1;
					tooltipPerColumn=0;
					columns[]={0.050000001,0.15000001,0.80000001};
				};
				class TitleGroup: RscText
				{
					idc=1540;
					x=0;
					y="((14.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((10) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class TitleGroupLeader: RscText
				{
					idc=1541;
					style="ST_CENTER";
					x="((8) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((14.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((10) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class weightNumber: RscText
				{
					idc=1548;
					x="((21) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((14.3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((6) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
			};
		};
		class ButtonOK: RscButtonMenuOK
		{
			x="((28.5) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			w="((5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			x="((6.5) * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2))";
			w="((5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
	};
};
