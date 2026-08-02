class CfgPatches
{
	class jac_zeus_target_position
	{
		name="jac_zeus_target_position";
		author="JACKTHEVIPER";
		url="";
		requiredVersion=1;
		requiredAddons[]=
		{
			"A3_Data_F",
			"A3_Functions_F",
			"A3_UI_F"
		};
		units[]={};
		weapons[]={};
	};
};
class Extended_preInit_EventHandlers
{
	class jac_zeus_target_position_mission_preinit_class
	{
		init="[] execVM '\jac_zeus_target_position\data\scripts\target_position.sqf';";
	};
};
class cfgMods
{
	author="Jacktheviper";
	timepacked="1661893259";
};
