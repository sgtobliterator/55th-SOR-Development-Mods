class CfgPatches
{
	class mts_zeus_plotting
	{
		name="mts - Zeus Plotting";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"zen_common",
			"zen_context_menu"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"Timi007"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.1.260719";
		versionAr[]={1,10,1,260719};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_zeus_plotting
	{
		init="call compileScript ['\z\mts_enhanced\addons\zeus_plotting\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_zeus_plotting
	{
		init="call compileScript ['\z\mts_enhanced\addons\zeus_plotting\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_zeus_plotting
	{
		init="call compileScript ['\z\mts_enhanced\addons\zeus_plotting\XEH_postInit.sqf']";
	};
};
class zen_context_menu_actions
{
	class Plots
	{
		displayName="$STR_mts_zeus_plotting_DisplayName";
		icon="\z\mts_enhanced\addons\zeus_plotting\ui\ruler.paa";
		statement="call mts_zeus_plotting_fnc_selectPosition";
		args="LINE";
		priority=15;
		class MeasureDistance
		{
			displayName="$STR_mts_zeus_plotting_MeasureDistance";
			icon="\z\mts_enhanced\addons\zeus_plotting\ui\ruler.paa";
			statement="call mts_zeus_plotting_fnc_selectPosition";
			args="LINE";
		};
		class MeasureDistanceFromCamera
		{
			displayName="$STR_mts_zeus_plotting_MeasureDistanceFromCamera";
			icon="\z\mts_enhanced\addons\zeus_plotting\ui\ruler.paa";
			statement="[_args, curatorCamera] call mts_zeus_plotting_fnc_setActivePlot";
			args="LINE";
		};
		class MeasureRadius
		{
			displayName="$STR_mts_zeus_plotting_MeasureRadius";
			icon="\z\mts_enhanced\addons\zeus_plotting\ui\radius.paa";
			statement="call mts_zeus_plotting_fnc_selectPosition";
			args="RADIUS";
		};
		class MeasureOffset
		{
			displayName="$STR_mts_zeus_plotting_MeasureOffset";
			icon="\z\mts_enhanced\addons\zeus_plotting\ui\cuboid.paa";
			statement="call mts_zeus_plotting_fnc_selectPosition";
			args="RECTANGLE";
		};
		class ClearPlots
		{
			displayName="$STR_mts_zeus_plotting_ClearPlots";
			icon="A3\3den\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
			statement="[""mts_zeus_plotting_plotsCleared""] call CBA_fnc_localEvent";
		};
	};
};
class mts_zeus_plotting_formatters
{
	class Distance
	{
		class Meter
		{
			formatter="format['%1 m', [_this, 1, parseNumber (abs _this < 100)] call CBA_fnc_formatNumber]";
			priority=100;
		};
		class Feet
		{
			formatter="format['%1 ft', [_this * 3.281, 1, 0] call CBA_fnc_formatNumber]";
			priority=90;
		};
	};
	class Speed
	{
		class kmh
		{
			formatter="call mts_zeus_plotting_fnc_formatSpeedKmh";
			priority=100;
			speeds[]={3.3329999,8.3330002,13.889,27.778,69.444,166.66701};
		};
	};
	class Azimuth
	{
		class Degree
		{
			formatter="format['%1°', _this toFixed 0]";
			priority=100;
		};
		class NATOMil
		{
			formatter="format['%1 mil', (_this * 17.7778) toFixed 0]";
			priority=90;
		};
	};
};
