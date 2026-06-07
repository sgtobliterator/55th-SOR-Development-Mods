class CfgPatches
{
	class mts_armory
	{
		name="mts - Armory";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"mts_database"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"PhILoX"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.0.251012";
		versionAr[]={1,10,0,251012};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_armory
	{
		init="call compileScript ['\z\mts_enhanced\addons\armory\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_armory
	{
		init="call compileScript ['\z\mts_enhanced\addons\armory\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_armory
	{
		init="call compileScript ['\z\mts_enhanced\addons\armory\XEH_postInit.sqf']";
	};
};
class RscText;
class RscButton;
class RscListBox;
class IGUIBack;
class RscPicture;
class RscEdit;
class RscCheckBox;
class mts_armory_dialog
{
	idd=520600;
	class Button: RscButton
	{
		period=0;
	};
	class Button_Image: Button
	{
		colorBackground[]={0,0,0,0};
		colorBackgroundActive[]={0,0,0,0};
	};
	class Text: RscText
	{
		style=2;
		colorBackground[]={0,0,0,0.5};
	};
	class Background_Image: IGUIBack
	{
		colorBackground[]={0,0,0,0.5};
	};
	class ListBox: RscListBox
	{
		period=0;
		colorSelectBackground2[]={0.94999999,0.94999999,0.94999999,1};
	};
	class controls
	{
		class Button_Arsenal: Button
		{
			idc=3;
			text="Arsenal";
			x="SafeZoneX + (700 / 1920) * SafeZoneW";
			y="SafeZoneY + (180 / 1080) * safeZoneH";
			w="(70 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="_this call mts_armory_fnc_openArsenal";
		};
		class Checkbox_Arsenal_Toggle: RscCheckBox
		{
			idc=12;
			tooltip="$STR_mts_Armory_checkbox_arsenalToggle_tooltip";
			x="SafeZoneX + (780 / 1920) * SafeZoneW";
			y="SafeZoneY + (180 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onCheckedChanged="[""mts_armory_updateArsenal"", [ctrlText 4, (cbChecked (_this select 0))]] call CBA_fnc_globalEvent";
		};
		class Text_Title: Text
		{
			idc=4;
			x="SafeZoneX + (820 / 1920) * SafeZoneW";
			y="SafeZoneY + (180 / 1080) * safeZoneH";
			w="(280 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Button_New_Equipment: Button_Image
		{
			idc=5;
			tooltip="$STR_mts_armory_button_createEquipmentCategory_tooltip";
			x="SafeZoneX + (1110 / 1920) * SafeZoneW";
			y="SafeZoneY + (180 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[_this select 0] call mts_armory_fnc_openNewEquipmentDialog";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 6) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 6) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_settings: Button_Image
		{
			idc=8;
			tooltip="$STR_mts_armory_button_toggleSettings_tooltip";
			x="SafeZoneX + (1150 / 1920) * SafeZoneW";
			y="SafeZoneY + (180 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[false] call mts_armory_fnc_toggleSettings";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 9) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 9) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Exit: Button_Image
		{
			idc=-1;
			tooltip="$STR_mts_armory_button_exitDialog_tooltip";
			x="SafeZoneX + (1190 / 1920) * SafeZoneW";
			y="SafeZoneY + (180 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="(ctrlParent (_this select 0)) closeDisplay 1";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 11) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 11) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Text_Loadouts: Text
		{
			idc=-1;
			text="$STR_mts_armory_text_loadout_title";
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (260 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Text_Backpacks: Text
		{
			idc=-1;
			text="$STR_mts_armory_text_backpack_title";
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (260 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Button_Loadout_1: Button
		{
			idc=101;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (310 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_2: Button
		{
			idc=102;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (350 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_3: Button
		{
			idc=103;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (390 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_4: Button
		{
			idc=104;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (430 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_5: Button
		{
			idc=105;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (470 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_6: Button
		{
			idc=106;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (510 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_7: Button
		{
			idc=107;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (550 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_8: Button
		{
			idc=108;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (590 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_9: Button
		{
			idc=109;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (630 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_10: Button
		{
			idc=110;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (670 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_11: Button
		{
			idc=111;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (710 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_12: Button
		{
			idc=112;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (750 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipLoadout";
		};
		class Button_Loadout_Edit_1: Button_Image
		{
			idc=121;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (310 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[101, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 141) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 141) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Loadout_Edit_2: Button_Image
		{
			idc=122;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (350 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[102, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 142) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 142) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Loadout_Edit_3: Button_Image
		{
			idc=123;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (390 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[103, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 143) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 143) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Loadout_Edit_4: Button_Image
		{
			idc=124;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (430 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[104, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 144) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 144) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Loadout_Edit_5: Button_Image
		{
			idc=125;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (470 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[105, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 145) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 145) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Loadout_Edit_6: Button_Image
		{
			idc=126;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (510 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[106, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 146) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 146) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Loadout_Edit_7: Button_Image
		{
			idc=127;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (550 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[107, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 147) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 147) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Loadout_Edit_8: Button_Image
		{
			idc=128;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (590 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[108, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 148) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 148) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Loadout_Edit_9: Button_Image
		{
			idc=129;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (630 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[109, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 149) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 149) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Loadout_Edit_10: Button_Image
		{
			idc=130;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (670 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[110, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 150) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 150) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Loadout_Edit_11: Button_Image
		{
			idc=131;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (710 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[111, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 151) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 151) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Loadout_Edit_12: Button_Image
		{
			idc=132;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (750 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[112, 1] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 152) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 152) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_1: Button
		{
			idc=201;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (310 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_2: Button
		{
			idc=202;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (350 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_3: Button
		{
			idc=203;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (390 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_4: Button
		{
			idc=204;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (430 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_5: Button
		{
			idc=205;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (470 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_6: Button
		{
			idc=206;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (510 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_7: Button
		{
			idc=207;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (550 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_8: Button
		{
			idc=208;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (590 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_9: Button
		{
			idc=209;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (630 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_10: Button
		{
			idc=210;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (670 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_11: Button
		{
			idc=211;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (710 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_12: Button
		{
			idc=212;
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (750 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[ctrlText 4, ctrlText (_this select 0)] call mts_armory_fnc_equipBackpack";
		};
		class Button_Backpack_Edit_1: Button_Image
		{
			idc=221;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (310 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[201, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 241) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 241) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_Edit_2: Button_Image
		{
			idc=222;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (350 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[202, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 242) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 242) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_Edit_3: Button_Image
		{
			idc=223;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (390 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[203, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 243) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 243) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_Edit_4: Button_Image
		{
			idc=224;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (430 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[204, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 244) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 244) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_Edit_5: Button_Image
		{
			idc=225;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (470 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[205, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 245) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 245) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_Edit_6: Button_Image
		{
			idc=226;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (510 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[206, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 246) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 246) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_Edit_7: Button_Image
		{
			idc=227;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (550 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[207, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 247) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 247) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_Edit_8: Button_Image
		{
			idc=228;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (590 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[208, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 248) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 248) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_Edit_9: Button_Image
		{
			idc=229;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (630 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[209, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 249) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 249) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_Edit_10: Button_Image
		{
			idc=230;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (670 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[210, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 250) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 250) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_Edit_11: Button_Image
		{
			idc=231;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (710 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[211, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 251) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 251) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Button_Backpack_Edit_12: Button_Image
		{
			idc=232;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (750 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[212, 2] call mts_armory_fnc_setEditArea";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 252) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 252) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Editbox_Equipment_Name: RscEdit
		{
			idc=20;
			tooltip="$STR_mts_armory_editbox_equipmentName_tooltip";
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (800 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Button_Save_Equipment: Button
		{
			idc=23;
			text="$STR_mts_armory_button_save_displayName";
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (800 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[(_this select 0)] call mts_armory_fnc_saveEquipment";
		};
		class Button_Delete_Equipment: Button_Image
		{
			idc=24;
			tooltip="$STR_mts_armory_button_deleteEquipment_tooltip";
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (800 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[((ctrlParent (_this select 0)) displayCtrl 23), true] call mts_armory_fnc_saveEquipment";
			onMouseEnter="((ctrlParent (_this select 0)) displayCtrl 25) ctrlSetBackgroundColor [0, 0, 0, 1]";
			onMouseExit="((ctrlParent (_this select 0)) displayCtrl 25) ctrlSetBackgroundColor [0, 0, 0, 0.5]";
		};
		class Dropdown_Medic: ListBox
		{
			idc=21;
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (840 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(75 / 1080) * safeZoneH";
		};
		class Dropdown_Engineer: ListBox
		{
			idc=22;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (840 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(75 / 1080) * safeZoneH";
		};
		class Editbox_Editors: RscEdit
		{
			idc=27;
			tooltip="$STR_mts_armory_editbox_editors";
			x="SafeZoneX + (775 / 1920) * SafeZoneW";
			y="SafeZoneY + (925 / 1080) * safeZoneH";
			w="(370 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Button_Save_Editors: Button
		{
			idc=28;
			text="$STR_mts_armory_button_save_displayName";
			x="SafeZoneX + (995 / 1920) * SafeZoneW";
			y="SafeZoneY + (965 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[""mts_armory_updateEditors"", [ctrlText 4, ctrlText 27]] call CBA_fnc_serverEvent";
		};
	};
	class controlsBackground
	{
		class Background_1: IGUIBack
		{
			idc=13;
			x="SafeZoneX + (680 / 1920) * SafeZoneW";
			y="SafeZoneY + (160 / 1080) * safeZoneH";
			w="(560 / 1920) * SafeZoneW";
			h="(670 / 1080) * safeZoneH";
		};
		class Background_2: IGUIBack
		{
			idc=14;
			x="SafeZoneX + (690 / 1920) * SafeZoneW";
			y="SafeZoneY + (170 / 1080) * safeZoneH";
			w="(540 / 1920) * SafeZoneW";
			h="(650 / 1080) * safeZoneH";
		};
		class Background_New_Equipment: Background_Image
		{
			idc=6;
			x="SafeZoneX + (1110 / 1920) * SafeZoneW";
			y="SafeZoneY + (180 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Icon_New_Equipment: RscPicture
		{
			idc=7;
			text="\z\mts_enhanced\addons\armory\data\newCategory.paa";
			x="SafeZoneX + (1114 / 1920) * SafeZoneW";
			y="SafeZoneY + (184 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Background_settings: Background_Image
		{
			idc=9;
			x="SafeZoneX + (1150 / 1920) * SafeZoneW";
			y="SafeZoneY + (180 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Icon_Settings: RscPicture
		{
			idc=10;
			text="\z\mts_enhanced\addons\armory\data\settings.paa";
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (185 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Background_Exit: Background_Image
		{
			idc=11;
			x="SafeZoneX + (1190 / 1920) * SafeZoneW";
			y="SafeZoneY + (180 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Icon_Exit: RscPicture
		{
			idc=-1;
			text="\z\mts_enhanced\addons\armory\data\exit.paa";
			x="SafeZoneX + (1195 / 1920) * SafeZoneW";
			y="SafeZoneY + (185 / 1080) * safeZoneH";
			w="(20 / 1920) * SafeZoneW";
			h="(20 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_1: Background_Image
		{
			idc=141;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (310 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_2: Background_Image
		{
			idc=142;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (350 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_3: Background_Image
		{
			idc=143;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (390 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_4: Background_Image
		{
			idc=144;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (430 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_5: Background_Image
		{
			idc=145;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (470 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_6: Background_Image
		{
			idc=146;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (510 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_7: Background_Image
		{
			idc=147;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (550 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_8: Background_Image
		{
			idc=148;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (590 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_9: Background_Image
		{
			idc=149;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (630 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_10: Background_Image
		{
			idc=150;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (670 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_11: Background_Image
		{
			idc=151;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (710 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Loadout_Edit_12: Background_Image
		{
			idc=152;
			x="SafeZoneX + (935 / 1920) * SafeZoneW";
			y="SafeZoneY + (750 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_1: RscPicture
		{
			idc=161;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (314 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_2: RscPicture
		{
			idc=162;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (354 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_3: RscPicture
		{
			idc=163;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (394 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_4: RscPicture
		{
			idc=164;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (434 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_5: RscPicture
		{
			idc=165;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (474 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_6: RscPicture
		{
			idc=166;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (514 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_7: RscPicture
		{
			idc=167;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (554 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_8: RscPicture
		{
			idc=168;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (594 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_9: RscPicture
		{
			idc=169;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (634 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_10: RscPicture
		{
			idc=170;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (674 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_11: RscPicture
		{
			idc=171;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (714 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Loadout_Edit_12: RscPicture
		{
			idc=172;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (939 / 1920) * SafeZoneW";
			y="SafeZoneY + (754 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_1: Background_Image
		{
			idc=241;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (310 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_2: Background_Image
		{
			idc=242;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (350 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_3: Background_Image
		{
			idc=243;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (390 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_4: Background_Image
		{
			idc=244;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (430 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_5: Background_Image
		{
			idc=245;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (470 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_6: Background_Image
		{
			idc=246;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (510 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_7: Background_Image
		{
			idc=247;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (550 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_8: Background_Image
		{
			idc=248;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (590 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_9: Background_Image
		{
			idc=249;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (630 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_10: Background_Image
		{
			idc=250;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (670 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_11: Background_Image
		{
			idc=251;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (710 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Background_Backpack_Edit_12: Background_Image
		{
			idc=252;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (750 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_1: RscPicture
		{
			idc=261;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (314 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_2: RscPicture
		{
			idc=262;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (354 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_3: RscPicture
		{
			idc=263;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (394 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_4: RscPicture
		{
			idc=264;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (434 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_5: RscPicture
		{
			idc=265;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (474 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_6: RscPicture
		{
			idc=266;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (514 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_7: RscPicture
		{
			idc=267;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (554 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_8: RscPicture
		{
			idc=268;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (594 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_9: RscPicture
		{
			idc=269;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (634 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_10: RscPicture
		{
			idc=270;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (674 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_11: RscPicture
		{
			idc=271;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (714 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Icon_Backpack_Edit_12: RscPicture
		{
			idc=272;
			text="\z\mts_enhanced\addons\armory\data\edit.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (754 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
		class Background_Delete_Equipment: Background_Image
		{
			idc=25;
			x="SafeZoneX + (1155 / 1920) * SafeZoneW";
			y="SafeZoneY + (800 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Icon_Delete_Equipment: RscPicture
		{
			idc=26;
			text="\z\mts_enhanced\addons\armory\data\delete.paa";
			x="SafeZoneX + (1159 / 1920) * SafeZoneW";
			y="SafeZoneY + (804 / 1080) * safeZoneH";
			w="(22 / 1920) * SafeZoneW";
			h="(22 / 1080) * safeZoneH";
		};
	};
};
class mts_armory_newEquipment
{
	idd=520800;
	class Button: RscButton
	{
		period=0;
	};
	class controls
	{
		class Editbox_Equipment_Name: RscEdit
		{
			idc=3;
			tooltip="$STR_mts_armory_editbox_equipmentName_tooltip";
			x="SafeZoneX + (720 / 1920) * SafeZoneW";
			y="SafeZoneY + (525 / 1080) * safeZoneH";
			w="(280 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Checkbox_Initialize_Equipment: RscCheckBox
		{
			idc=4;
			tooltip="$STR_mts_armory_checkbox_initializeEquipmentCategory_tooltip";
			x="SafeZoneX + (1010 / 1920) * SafeZoneW";
			y="SafeZoneY + (525 / 1080) * safeZoneH";
			w="(30 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
		};
		class Button_Create_Equipment: Button
		{
			idc=5;
			text="$STR_mts_armory_button_createEquipmentCategory_displayName";
			x="SafeZoneX + (1050 / 1920) * SafeZoneW";
			y="SafeZoneY + (525 / 1080) * safeZoneH";
			w="(150 / 1920) * SafeZoneW";
			h="(30 / 1080) * safeZoneH";
			onButtonClick="[_this select 0] call mts_armory_fnc_buttonCreateEquipment";
		};
	};
	class controlsBackground
	{
		class Background: IGUIBack
		{
			idc=-1;
			x="SafeZoneX + (710 / 1920) * SafeZoneW";
			y="SafeZoneY + (515 / 1080) * safeZoneH";
			w="(500 / 1920) * SafeZoneW";
			h="(50 / 1080) * safeZoneH";
		};
	};
};
