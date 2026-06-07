class CfgPatches
{
	class mts_presentation
	{
		name="mts - Presentation";
		units[]={};
		weapons[]={};
		requiredVersion=2.0599999;
		requiredAddons[]=
		{
			"cba_main"
		};
		author="$STR_mts_presentation_authors";
		url="$STR_mts_presentation_URL";
		version=1;
		versionStr="1.0.3.230924";
		versionAr[]={1,0,3,230924};
	};
};
class CfgSettings
{
	class CBA
	{
		class Versioning
		{
			class mts_presentation
			{
				main_addon="mts_presentation";
				class dependencies
				{
					CBA[]=
					{
						"cba_main",
						{3,15,6},
						"true"
					};
				};
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_presentation
	{
		init="call compileScript ['\z\mts_presentation\addons\presentation\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_presentation
	{
		init="call compileScript ['\z\mts_presentation\addons\presentation\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_presentation
	{
		init="call compileScript ['\z\mts_presentation\addons\presentation\XEH_postInit.sqf']";
	};
};
class RscPicture;
class RscCombo;
class RscShortcutButton;
class RscText;
class RscListBox;
class IGUIBack;
class mts_presentation_dialog
{
	idd=850210;
	movingEnable=0;
	OnLoad="((_this select 0) displayctrl 4) ctrlAddEventHandler ['LBSelChanged', {_this call mts_presentation_fnc_fillSlidesCombo; _this call mts_presentation_fnc_toggleContinueButton}];";
	class Button: RscShortcutButton
	{
		type=16;
		class HitZone;
		class ShortcutPos;
		class TextPos
		{
			left=0;
			top=0.0125;
			right=0;
			bottom=0;
		};
		class Attributes
		{
			font="RobotoCondensed";
			color="#E5E5E5";
			align="center";
			shadow="true";
		};
		class AttributesImage;
		colorBackground[]={1,1,1,1};
		colorBackgroundFocused[]={1,1,1,1};
		animTextureDefault="\z\mts_presentation\addons\presentation\data\Button_np.paa";
		animTextureNormal="\z\mts_presentation\addons\presentation\data\Button_np.paa";
		animTextureDisabled="\z\mts_presentation\addons\presentation\data\Button_p.paa";
		animTextureOver="\z\mts_presentation\addons\presentation\data\Button_h.paa";
		animTextureFocused="\z\mts_presentation\addons\presentation\data\Button_h.paa";
		animTexturePressed="\z\mts_presentation\addons\presentation\data\Button_p.paa";
	};
	class Listbox: RscListBox
	{
		class ComboScrollBar;
		colorBackground[]={0.23100001,0.23100001,0.23100001,1};
		colorPictureRight[]={0,0,0,1};
		colorTextRight[]={0,0,0,1};
		arrowEmpty="\A3\ui_f\data\GUI\Cfg\Scrollbar\arrowEmpty_ca.paa";
		arrowFull="\A3\ui_f\data\GUI\Cfg\Scrollbar\arrowFull_ca.paa";
		thumb="\A3\ui_f\data\GUI\Cfg\Scrollbar\thumb_ca.paa";
		border="\A3\ui_f\data\GUI\Cfg\Scrollbar\border_ca.paa";
		color[]={1,1,1,0.60000002};
	};
	class ControlsBackground
	{
		class logo: RscPicture
		{
			idc=-1;
			x="SafeZoneX + (704 / 1920) * SafeZoneW";
			y="SafeZoneY + (400 / 1080) * SafeZoneH";
			w="(64 / 1920) * SafeZoneW";
			h="(64 / 1080) * SafeZoneH";
			text="\z\mts_presentation\addons\presentation\data\Logo.paa";
		};
		class background_nav: RscPicture
		{
			idc=-1;
			x="SafeZoneX + (768 / 1920) * SafeZoneW";
			y="SafeZoneY + (400 / 1080) * SafeZoneH";
			w="(448 / 1920) * SafeZoneW";
			h="(64 / 1080) * SafeZoneH";
			text="\z\mts_presentation\addons\presentation\data\Background_nav.paa";
		};
		class background_selection: RscPicture
		{
			idc=-1;
			x="SafeZoneX + (704 / 1920) * SafeZoneW";
			y="SafeZoneY + (464 / 1080) * SafeZoneH";
			w="(512 / 1920) * SafeZoneW";
			h="(216 / 1080) * SafeZoneH";
			text="\z\mts_presentation\addons\presentation\data\Background_selection.paa";
		};
	};
	class controls
	{
		class combo_slides: RscCombo
		{
			idc=1;
			style="16";
			x="SafeZoneX + (1034 / 1920) * SafeZoneW";
			y="SafeZoneY + (528 / 1080) * SafeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(33 / 1080) * SafeZoneH";
			class ComboScrollBar: RscCombo
			{
			};
		};
		class button_start: Button
		{
			idc=2;
			text="$STR_mts_presentation_dialog_btn_start";
			x="SafeZoneX + (1034 / 1920) * SafeZoneW";
			y="SafeZoneY + (629 / 1080) * SafeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(40 / 1080) * SafeZoneH";
			onButtonClick="false call mts_presentation_fnc_startPresentation";
		};
		class button_continue: Button
		{
			idc=3;
			text="$STR_mts_presentation_dialog_btn_continue";
			x="SafeZoneX + (1034 / 1920) * SafeZoneW";
			y="SafeZoneY + (575 / 1080) * SafeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(40 / 1080) * SafeZoneH";
			onButtonClick="true call mts_presentation_fnc_startPresentation";
		};
		class title: RscText
		{
			idc=-1;
			style=2;
			x="SafeZoneX + (768 / 1920) * SafeZoneW";
			y="SafeZoneY + (400 / 1080) * SafeZoneH";
			w="(384 / 1920) * SafeZoneW";
			h="(57 / 1080) * SafeZoneH";
			text="Presentation Selection";
		};
		class listbox_backgorund: RscPicture
		{
			idc=-1;
			x="SafeZoneX + (736 / 1920) * SafeZoneW";
			y="SafeZoneY + (473 / 1080) * SafeZoneH";
			w="(266 / 1920) * SafeZoneW";
			h="(196 / 1080) * SafeZoneH";
			text="\z\mts_presentation\addons\presentation\data\lb_bg.paa";
		};
		class listbox: Listbox
		{
			idc=4;
			style="16";
			x="SafeZoneX + (736 / 1920) * SafeZoneW";
			y="SafeZoneY + (475 / 1080) * SafeZoneH";
			w="(264 / 1920) * SafeZoneW";
			h="(192 / 1080) * SafeZoneH";
		};
	};
};
class RscTitles
{
	class mts_presentation_curSlideDisplay
	{
		idd=880210;
		OnLoad="uiNamespace setVariable [""mts_presentation_curSlideDisplay"", _this select 0]";
		duration="1e+011";
		class controls
		{
			class background: IGUIBack
			{
				idc=1;
			};
			class slide: RscPicture
			{
				idc=2;
			};
		};
	};
	class mts_presentation_previewNextSlideDisp
	{
		idd=890210;
		OnLoad="uiNamespace setVariable [""mts_presentation_previewNextSlideDisp"", _this select 0]";
		duration="1e+011";
		class controls
		{
			class background: IGUIBack
			{
				idc=1;
				w="(532 / 1920) * SafeZoneW";
				h="(276 / 1080) * SafeZoneH";
			};
			class slide: RscPicture
			{
				idc=2;
				w="(512 / 1920) * SafeZoneW";
				h="(256 / 1080) * SafeZoneH";
			};
			class preview_label_background: IGUIBack
			{
				idc=4;
				w="(512 / 1920) * SafeZoneW";
				h="(40 / 1080) * SafeZoneH";
			};
			class preview_label: RscText
			{
				idc=3;
				text="$STR_mts_presentation_display_preview";
				w="(512 / 1920) * SafeZoneW";
				h="(40 / 1080) * SafeZoneH";
			};
		};
	};
};
