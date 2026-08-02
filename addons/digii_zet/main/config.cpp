class ctrlEdit;
class ctrlXSliderH;
class CfgPatches
{
	class digii_zet_main
	{
		name="digii_zet - Main";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"A3_Data_F_Tank_Loadorder",
			"cba_main",
			"zen_main"
		};
		author="DiGii";
		url="";
		version=1.3;
		versionStr="1.3.1";
		versionAr[]={1,3,1};
	};
};
class CfgMods
{
	class digii_zet
	{
		dir="@digii_zet";
		name="Zeus Enhanced Targeting (ZET)";
		picture="A3\Ui_f\data\Logos\arma3_expansion_alpha_ca.paa";
		hidePicture="true";
		hideName="true";
		actionName="Website";
		action="";
		description="";
	};
};
class Extended_PreInit_EventHandlers
{
	class digii_zet_main
	{
		init="call compile preProcessFileLineNumbers '\z\digii_zet\addons\main\XEH_preInit.sqf'";
		disableModuload="true";
	};
};
class Extended_PostInit_EventHandlers
{
	class digii_zet_main
	{
		init="call compile preProcessFileLineNumbers '\z\digii_zet\addons\main\XEH_postInit.sqf'";
	};
};
class CfgSettings
{
	class CBA
	{
		class Versioning
		{
			class digii_zet
			{
				class dependencies
				{
					CBA[]=
					{
						"cba_main",
						{3,18,0},
						"(true)"
					};
					ZEN[]=
					{
						"zen_main",
						{1,0,0},
						"(true)"
					};
				};
			};
		};
	};
};
class Cfg3DEN
{
	class Attributes
	{
		class Title;
		class Controls;
		class ZET_NumberSlider: Title
		{
			attributeLoad="[_this, _value] call digii_zet_main_fnc_slider_onAttributeLoad";
			attributeSave="_this call digii_zet_main_fnc_slider_onAttributeSave";
			class Controls: Controls
			{
				class Title: Title
				{
				};
				class Value: ctrlXSliderH
				{
					idc=4720100;
					x="48 * (pixelW * pixelGrid * 0.50)";
					w="(82 - 10) * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
					sliderPosition=10000;
					sliderRange[]={100,10000};
					sliderStep=100;
					lineSize=100;
				};
				class Edit: ctrlEdit
				{
					idc=4720101;
					x="(48 + 82 - 10) * (pixelW * pixelGrid * 0.50)";
					w="10 * (pixelW * pixelGrid * 0.50)";
					h="(5 * (pixelH * pixelGrid * 0.50))";
				};
			};
		};
	};
	class Object
	{
		class AttributeCategories
		{
			class digii_zet_main
			{
				displayName="Zeus Enhanced Targeting";
				collapsed=1;
				class Attributes
				{
					class digii_zet_main_targetFilter
					{
						displayName="$STR_digii_zet_main_SetFilterTitle";
						tooltip="$STR_digii_zet_main_SetFilterTooltip";
						property="digii_zet_main_targetFilter";
						control="Combo";
						expression="_this setVariable ['digii_zet_main_FilterValue', _value]; if (!is3DEN) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
						typeName="NUMBER";
						defaultValue="0";
						condition="objectBrain + objectVehicle";
						class values
						{
							class ALL
							{
								name="$STR_digii_zet_main_Filter_All";
								value=0;
								default=1;
							};
							class AIR
							{
								name="$STR_digii_zet_main_Filter_Air";
								value=1;
							};
							class GROUND
							{
								name="$STR_digii_zet_main_Filter_Ground";
								value=2;
							};
							class ARMOR
							{
								name="$STR_digii_zet_main_Filter_Armor";
								value=3;
							};
							class INFANTRY
							{
								name="$STR_digii_zet_main_Filter_Infantry";
								value=4;
							};
							class CUSTOM
							{
								name="$STR_digii_zet_main_Filter_Custom";
								value=5;
							};
						};
					};
					class digii_zet_main_customAir
					{
						displayName="$STR_digii_zet_main_CustomAir";
						tooltip="$STR_digii_zet_main_CustomFilterTooltip";
						property="digii_zet_main_customAir";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_CustomAir', _value]";
						defaultValue="1";
						condition="objectBrain + objectVehicle";
					};
					class digii_zet_main_customArmor
					{
						displayName="$STR_digii_zet_main_CustomArmor";
						tooltip="$STR_digii_zet_main_CustomFilterTooltip";
						property="digii_zet_main_customArmor";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_CustomArmor', _value]";
						defaultValue="1";
						condition="objectBrain + objectVehicle";
					};
					class digii_zet_main_customVehicles
					{
						displayName="$STR_digii_zet_main_CustomVehicles";
						tooltip="$STR_digii_zet_main_CustomFilterTooltip";
						property="digii_zet_main_customVehicles";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_CustomVehicles', _value]";
						defaultValue="1";
						condition="objectBrain + objectVehicle";
					};
					class digii_zet_main_customInfantry
					{
						displayName="$STR_digii_zet_main_CustomInfantry";
						tooltip="$STR_digii_zet_main_CustomFilterTooltip";
						property="digii_zet_main_customInfantry";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_CustomInfantry', _value]";
						defaultValue="1";
						condition="objectBrain + objectVehicle";
					};
					class digii_zet_main_customNaval
					{
						displayName="$STR_digii_zet_main_CustomNaval";
						tooltip="$STR_digii_zet_main_CustomFilterTooltip";
						property="digii_zet_main_customNaval";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_CustomNaval', _value]";
						defaultValue="1";
						condition="objectBrain + objectVehicle";
					};
					class digii_zet_main_overrideMaxEngageRange
					{
						displayName="$STR_digii_zet_main_OverrideRangeCheckbox";
						tooltip="$STR_digii_zet_main_OverrideRangeCheckboxTooltip";
						property="digii_zet_main_overrideMaxEngageRange";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_OverrideMaxEngageRange', _value]; if (!is3DEN) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
						defaultValue="0";
						condition="objectBrain + objectVehicle";
					};
					class digii_zet_main_maxEngageRange
					{
						displayName="$STR_digii_zet_main_MaxEngageRangeTitle";
						tooltip="$STR_digii_zet_main_MaxEngageRangeTooltip";
						property="digii_zet_main_maxEngageRange";
						control="ZET_NumberSlider";
						expression="_this setVariable ['digii_zet_main_MaxEngageRange', _value]; if (!is3DEN) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
						typeName="NUMBER";
						defaultValue="10000";
						condition="objectBrain + objectVehicle";
					};
				};
			};
		};
	};
	class Group
	{
		class AttributeCategories
		{
			class digii_zet_main
			{
				displayName="Zeus Enhanced Targeting";
				collapsed=1;
				class Attributes
				{
					class digii_zet_main_groupTargetFilter
					{
						displayName="$STR_digii_zet_main_SetFilterTitle";
						tooltip="$STR_digii_zet_main_SetFilterTooltip";
						property="digii_zet_main_groupTargetFilter";
						control="Combo";
						expression="_this setVariable ['digii_zet_main_grpFilterValue', _value]; if (!is3DEN && {count units _this > 0}) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
						typeName="NUMBER";
						defaultValue="0";
						class values
						{
							class ALL
							{
								name="$STR_digii_zet_main_Filter_All";
								value=0;
								default=1;
							};
							class AIR
							{
								name="$STR_digii_zet_main_Filter_Air";
								value=1;
							};
							class GROUND
							{
								name="$STR_digii_zet_main_Filter_Ground";
								value=2;
							};
							class ARMOR
							{
								name="$STR_digii_zet_main_Filter_Armor";
								value=3;
							};
							class INFANTRY
							{
								name="$STR_digii_zet_main_Filter_Infantry";
								value=4;
							};
							class CUSTOM
							{
								name="$STR_digii_zet_main_Filter_Custom";
								value=5;
							};
						};
					};
					class digii_zet_main_grpCustomAir
					{
						displayName="$STR_digii_zet_main_CustomAir";
						tooltip="$STR_digii_zet_main_CustomFilterTooltip";
						property="digii_zet_main_grpCustomAir";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_grpCustomAir', _value]";
						defaultValue="1";
					};
					class digii_zet_main_grpCustomArmor
					{
						displayName="$STR_digii_zet_main_CustomArmor";
						tooltip="$STR_digii_zet_main_CustomFilterTooltip";
						property="digii_zet_main_grpCustomArmor";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_grpCustomArmor', _value]";
						defaultValue="1";
					};
					class digii_zet_main_grpCustomVehicles
					{
						displayName="$STR_digii_zet_main_CustomVehicles";
						tooltip="$STR_digii_zet_main_CustomFilterTooltip";
						property="digii_zet_main_grpCustomVehicles";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_grpCustomVehicles', _value]";
						defaultValue="1";
					};
					class digii_zet_main_grpCustomInfantry
					{
						displayName="$STR_digii_zet_main_CustomInfantry";
						tooltip="$STR_digii_zet_main_CustomFilterTooltip";
						property="digii_zet_main_grpCustomInfantry";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_grpCustomInfantry', _value]";
						defaultValue="1";
					};
					class digii_zet_main_grpCustomNaval
					{
						displayName="$STR_digii_zet_main_CustomNaval";
						tooltip="$STR_digii_zet_main_CustomFilterTooltip";
						property="digii_zet_main_grpCustomNaval";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_grpCustomNaval', _value]";
						defaultValue="1";
					};
					class digii_zet_main_grpOverrideMaxEngageRange
					{
						displayName="$STR_digii_zet_main_OverrideRangeCheckbox";
						tooltip="$STR_digii_zet_main_OverrideRangeCheckboxTooltip";
						property="digii_zet_main_grpOverrideMaxEngageRange";
						control="CheckboxNumber";
						expression="_this setVariable ['digii_zet_main_grpOverrideMaxEngageRange', _value]; if (!is3DEN && {count units _this > 0}) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
						defaultValue="0";
					};
					class digii_zet_main_grpMaxEngageRange
					{
						displayName="$STR_digii_zet_main_MaxEngageRangeTitle";
						tooltip="$STR_digii_zet_main_MaxEngageRangeTooltip";
						property="digii_zet_main_grpMaxEngageRange";
						control="ZET_NumberSlider";
						expression="_this setVariable ['digii_zet_main_grpMaxEngageRange', _value]; if (!is3DEN && {count units _this > 0}) then { [{ [_this] call digii_zet_main_fnc_applyEditorFilter }, _this] call CBA_fnc_execNextFrame }";
						typeName="NUMBER";
						defaultValue="10000";
					};
				};
			};
		};
	};
};
