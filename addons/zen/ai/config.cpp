class CfgPatches
{
	class zen_ai
	{
		name="ZEN - AI";
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
				"zen_ai"
			};
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class zen_ai
	{
		init="call compileScript ['\x\zen\addons\ai\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class zen_ai
	{
		init="call compileScript ['\x\zen\addons\ai\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class zen_ai
	{
		init="call compileScript ['\x\zen\addons\ai\XEH_postInit.sqf']";
	};
};
class ZEN_WaypointTypes
{
	class Move
	{
		displayName="$STR_ac_move";
		type="MOVE";
	};
	class Cycle
	{
		displayName="$STR_ac_cycle";
		type="CYCLE";
	};
	class SeekAndDestroy
	{
		displayName="$STR_ac_seekanddestroy";
		type="SAD";
	};
	class Hold
	{
		displayName="$STR_ac_hold";
		type="HOLD";
	};
	class Sentry
	{
		displayName="$STR_ac_sentry";
		type="SENTRY";
	};
	class GetOut
	{
		displayName="$STR_ac_getout";
		type="GETOUT";
	};
	class Unload
	{
		displayName="$STR_ac_unload";
		type="UNLOAD";
	};
	class TransportUnload
	{
		displayName="$STR_ac_transportunload";
		type="TR UNLOAD";
	};
	class Land
	{
		displayName="$STR_A3_CfgWaypoints_Land";
		type="SCRIPTED";
		script="\x\zen\addons\ai\functions\fnc_waypointLand.sqf";
	};
	class Hook
	{
		displayName="$STR_ac_hook";
		type="HOOK";
	};
	class Unhook
	{
		displayName="$STR_ac_unhook";
		type="UNHOOK";
	};
	class Loiter
	{
		displayName="$STR_ac_loiter";
		type="LOITER";
	};
	class Demine
	{
		displayName="$STR_A3_Functions_F_Orange_Demine";
		type="SCRIPTED";
		script="\a3\functions_f_orange\waypoints\fn_wpDemine.sqf";
	};
	class Paradrop
	{
		displayName="$STR_zen_ai_Paradrop";
		type="SCRIPTED";
		script="\x\zen\addons\ai\functions\fnc_waypointParadrop.sqf";
	};
	class SearchBuilding
	{
		displayName="$STR_zen_ai_SearchBuilding";
		type="SCRIPTED";
		script="\x\zen\addons\ai\functions\fnc_waypointSearchBuilding.sqf";
	};
};
