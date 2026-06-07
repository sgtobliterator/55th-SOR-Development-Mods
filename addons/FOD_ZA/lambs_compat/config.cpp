class CfgPatches
{
	class FOD_ZA_LAMBS_Waypoints
	{
		name="[Forges of Dorn] Zeus Additions (LAMBS Waypoints)";
		author="Phenosi";
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"FOD_ZA",
			"lambs_wp"
		};
		units[]={};
		weapons[]={};
		skipWhenMissingDependencies=1;
	};
};
class ZEN_WaypointTypes
{
	class fod_za_Ambush
	{
		displayName="Setup Ambush";
		type="SCRIPTED";
		script="\FOD_ZA\scripts\fod_wpAmbush.sqf";
	};
	class fod_za_Reserve
	{
		displayName="Reserve/QRF";
		type="SCRIPTED";
		script="\FOD_ZA\scripts\fod_wpReserve.sqf";
	};
	class fod_za_HitAndRun
	{
		displayName="Hit & Run";
		type="SCRIPTED";
		script="\FOD_ZA\scripts\fod_wpHitAndRun.sqf";
	};
};
class ZEN_context_menu_actions
{
	class lambs_wp
	{
		class SetupAmbush
		{
			displayName="Setup Ambush";
			statement="{ [_x, _position, 100, [], false, 0, true, false] spawn FOD_ZA_fnc_taskEntrench } forEach _groups;";
			icon="\a3\3DEN\Data\CfgWaypoints\Sentry_ca.paa";
		};
		class HitAndRun
		{
			displayName="Hit & Run";
			statement="{ [_x, _position, 200] spawn FOD_ZA_fnc_taskHitAndRun } forEach _groups;";
			icon="\a3\3DEN\Data\CfgWaypoints\Sentry_ca.paa";
		};
		class Reserve
		{
			displayName="Reserve/QRF";
			statement="{ [_x, 100] spawn FOD_ZA_fnc_taskReserve } forEach _groups;";
			icon="\a3\3DEN\Data\CfgWaypoints\Guard_ca.paa";
		};
	};
};
class cfgMods
{
	author="Phenosi";
	timepacked="1775756665";
};
