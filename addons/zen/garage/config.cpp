class CfgPatches
{
	class zen_garage
	{
		name="ZEN - Garage";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"zen_attributes"
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
				"zen_garage"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_garage
	{
		init="call compileScript ['\x\zen\addons\garage\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_garage
	{
		init="call compileScript ['\x\zen\addons\garage\XEH_preInit.sqf']";
	};
};
class RscText;
class RscFrame;
class RscListBox;
class RscButtonMenu;
class RscButtonArsenal;
class RscActivePicture;
class RscControlsGroupNoScrollbars;
class zen_garage_display
{
	idd=10500;
	onKeyDown="_this call zen_garage_fnc_onKeyDown";
	onMouseButtonDown="_this call zen_garage_fnc_onMouseButtonDown";
	onMouseButtonUp="_this call zen_garage_fnc_onMouseButtonUp";
	class controlsBackground
	{
		class BlackLeft: RscText
		{
			idc=-1;
			x="safeZoneXAbs";
			y="safeZoneY";
			w="safeZoneXAbs - safeZoneX";
			h="safeZoneH";
			colorBackground[]={0,0,0,1};
		};
		class BlackRight: BlackLeft
		{
			x="safeZoneX + safeZoneW";
		};
		class MouseArea: RscText
		{
			idc=300;
			onMouseMoving="_this call zen_garage_fnc_handleMouse";
			onMouseHolding="_this call zen_garage_fnc_handleMouse";
			onMouseZChanged="_this call zen_garage_fnc_onMouseZChanged";
			onMouseButtonClick="_this call zen_garage_fnc_onMouseButtonClick";
			style=16;
			x="safeZoneX";
			y="safeZoneY";
			w="safeZoneW";
			h="safeZoneH";
		};
	};
	class controls
	{
		class MenuBar: RscControlsGroupNoScrollbars
		{
			idc=340;
			x="safeZoneX + ((0.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y="safeZoneY + safezoneH - ((1.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="safeZoneW - ((1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class ButtonClose: RscButtonMenu
				{
					onButtonClick="_this call zen_garage_fnc_closeGarage";
					text="$STR_DISP_CLOSE";
					tooltip="$STR_zen_garage_Close_Tooltip";
					x=0;
					y=0;
					w="(safeZoneW - ((1) * (((safezoneW / safezoneH) min 1.2) / 40))) / 5";
					h="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class ButtonHide: ButtonClose
				{
					onButtonClick="_this call zen_garage_fnc_toggleInterface";
					text="$STR_CA_HIDE";
					tooltip="$STR_zen_garage_Hide_Tooltip";
					x="(safeZoneW - ((1) * (((safezoneW / safezoneH) min 1.2) / 40))) / 5 + ((0.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
					w="(safeZoneW - ((1) * (((safezoneW / safezoneH) min 1.2) / 40))) / 8";
				};
				class ButtonApply: ButtonHide
				{
					idc=341;
					onButtonClick="_this call zen_garage_fnc_applyToAll";
					text="$STR_zen_garage_ApplyToAll";
					tooltip="$STR_zen_garage_ApplyToAll_Tooltip";
					x="(safeZoneW - ((1) * (((safezoneW / safezoneH) min 1.2) / 40))) / 5 + (safeZoneW - ((1) * (((safezoneW / safezoneH) min 1.2) / 40))) / 8 + ((0.2) * (((safezoneW / safezoneH) min 1.2) / 40))";
				};
			};
		};
		class InfoGroup: RscControlsGroupNoScrollbars
		{
			idc=350;
			x="safeZoneX + safeZoneW - ((20.1) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y="safeZoneY + safeZoneH - ((4.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((17.6) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((3) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			class controls
			{
				class Background: RscText
				{
					idc=-1;
					x="((2.6) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y=0;
					w="((15) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((2.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0.80000001};
				};
				class InfoName: RscText
				{
					idc=351;
					x="((2.6) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((0) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((15) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					sizeEx="((1.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				};
				class InfoAuthor: RscText
				{
					idc=352;
					x="((2.6) * (((safezoneW / safezoneH) min 1.2) / 40))";
					y="((1) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					w="((15) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((1.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					sizeEx="((0.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorText[]={1,1,1,0.5};
				};
				class DLCBackground: RscText
				{
					idc=353;
					x=0;
					y=0;
					w="((2.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((2.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					colorBackground[]={0,0,0,0.5};
				};
				class DLCIcon: RscActivePicture
				{
					idc=354;
					x=0;
					y=0;
					w="((2.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
					h="((2.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
					color[]={1,1,1,1};
					colorActive[]={1,1,1,1};
				};
			};
		};
		class BackgroundAnimations: RscText
		{
			idc=310;
			x="safeZoneX";
			y="safeZoneY + ((0.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((3.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorBackground[]={0,0,0,1};
		};
		class ButtonAnimations: RscButtonArsenal
		{
			idc=311;
			onButtonClick="0 call zen_garage_fnc_onTabSelect";
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\AnimationSources_ca.paa";
			tooltip="$STR_A3_RscDisplayGarage_tab_AnimationSources";
			x="safeZoneX + ((0.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y="safeZoneY + ((0.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((2) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorBackground[]={0,0,0,0.5};
		};
		class BackgroundTextures: BackgroundAnimations
		{
			idc=320;
			y="safeZoneY + ((2.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class ButtonTextures: ButtonAnimations
		{
			idc=321;
			onButtonClick="1 call zen_garage_fnc_onTabSelect";
			text="\A3\Ui_f\data\GUI\Rsc\RscDisplayGarage\TextureSources_ca.paa";
			tooltip="$STR_A3_RscDisplayGarage_tab_TextureSources";
			y="safeZoneY + ((2.8) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
		};
		class ListBackground: RscText
		{
			idc=330;
			x="safeZoneX + ((3.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y="safeZoneY + ((0.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((13) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="safeZoneH - ((2.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorBackground[]={0,0,0,0.5};
		};
		class ListFrame: RscFrame
		{
			idc=331;
			x="safeZoneX + ((3.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y="safeZoneY + ((0.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((13) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="safeZoneH - ((2.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorText[]={0,0,0,1};
		};
		class ListAnimations: RscListBox
		{
			idc=312;
			onLBSelChanged="_this call zen_garage_fnc_onAnimationSelect";
			x="safeZoneX + ((3.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y="safeZoneY + ((0.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((13) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="safeZoneH - ((2.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			sizeEx="((1.2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorSelect[]={1,1,1,1};
			colorSelect2[]={1,1,1,1};
			colorBackground[]={0,0,0,0};
			colorSelectBackground[]={1,1,1,0.5};
			colorSelectBackground2[]={1,1,1,0.5};
			colorPictureSelected[]={1,1,1,1};
			colorPictureRightSelected[]={1,1,1,1};
		};
		class ListTextures: ListAnimations
		{
			idc=322;
			onLBSelChanged="_this call zen_garage_fnc_onTextureSelect";
		};
		class ListEmpty: RscText
		{
			idc=332;
			style=2;
			text="$STR_lib_info_na";
			x="safeZoneX + ((3.5) * (((safezoneW / safezoneH) min 1.2) / 40))";
			y="safeZoneY + ((0.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			w="((13) * (((safezoneW / safezoneH) min 1.2) / 40))";
			h="safeZoneH - ((2.5) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			sizeEx="((2) * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
			colorText[]={1,1,1,0.15000001};
			shadow=0;
		};
	};
};
