class CfgPatches
{
	class mts_zeus_comments
	{
		name="mts - Zeus Comments";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"zen_dialog"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"Timi007"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.0.251012";
		versionAr[]={1,10,0,251012};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_zeus_comments
	{
		init="call compileScript ['\z\mts_enhanced\addons\zeus_comments\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_zeus_comments
	{
		init="call compileScript ['\z\mts_enhanced\addons\zeus_comments\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_zeus_comments
	{
		init="call compileScript ['\z\mts_enhanced\addons\zeus_comments\XEH_postInit.sqf']";
	};
};
class Cfg3DEN
{
	class Attributes
	{
		class Default;
		class mts_zeus_comments_hiddenAttribute: Default
		{
			onLoad="(ctrlParentControlsGroup ctrlParentControlsGroup (_this select 0)) ctrlShow false";
		};
	};
	class Mission
	{
		class Scenario
		{
			class AttributeCategories
			{
				class mts_zeus_comments
				{
					displayName="$STR_3DEN_Comment_textPlural";
					collapsed=1;
					class Attributes
					{
						class mts_zeus_comments_3DENComments
						{
							displayName="$STR_3DEN_Comment_textPlural";
							property="mts_zeus_comments_3DENComments";
							control="mts_zeus_comments_hiddenAttribute";
							tooltip="";
							defaultValue="[]";
							expression="";
							wikiType="[[Array]]";
						};
					};
				};
			};
		};
	};
	class EventHandlers
	{
		class mts_zeus_comments
		{
			onMissionSave="['onMissionSave'] call mts_zeus_comments_fnc_save3DENComments";
			onMissionAutosave="['onMissionAutosave'] call mts_zeus_comments_fnc_save3DENComments";
			onBeforeMissionPreview="['onBeforeMissionPreview'] call mts_zeus_comments_fnc_save3DENComments";
		};
	};
	class Comment
	{
		class AttributeCategories
		{
			class mts_zeus_comments
			{
				displayName="$STR_mts_main_category";
				collapsed=0;
				class Attributes
				{
					class mts_zeus_comments_showComment
					{
						displayName="$STR_mts_zeus_comments_ShowCommentInZeus";
						tooltip="$STR_mts_zeus_comments_ShowCommentInZeus_Description";
						property="mts_zeus_comments_showComment";
						control="CheckboxState";
						defaultValue="true";
						expression="";
						wikiType="[[Bool]]";
					};
				};
			};
		};
	};
};
class zen_context_menu_actions
{
	class mts_zeus_comments_createComment
	{
		displayName="$STR_3den_display3den_entitymenu_createcomment_text";
		icon="a3\3den\Data\Cfg3DEN\Comment\texture_ca.paa";
		condition="mts_zeus_comments_enabled";
		statement="[_position] call mts_zeus_comments_fnc_openDialog";
		priority=35;
	};
};
class RscActivePicture;
class mts_zeus_comments_RscActiveCommentIcon: RscActivePicture
{
	onMouseEnter="(_this select 0) setVariable [""mts_zeus_comments_isActive"", true]; ctrlSetFocus (_this select 0)";
	onMouseExit="(_this select 0) setVariable [""mts_zeus_comments_isActive"", false]";
	onKeyDown="call mts_zeus_comments_fnc_onKeyDown";
	onMouseButtonDblClick="call mts_zeus_comments_fnc_onMouseDblClick";
	onMouseButtonDown="call mts_zeus_comments_fnc_onMouseButtonDown";
	onMouseButtonUp="call mts_zeus_comments_fnc_onMouseButtonUp";
	onMouseMoving="call mts_zeus_comments_fnc_onMouseMoving";
	shadow=1;
	text="a3\3den\Data\Cfg3DEN\Comment\texture_ca.paa";
	tooltipMaxWidth="((15) * (((safezoneW / safezoneH) min 1.2) / 40))";
};
