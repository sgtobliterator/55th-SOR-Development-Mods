class CfgPatches
{
	class BHL_AI
	{
		name="BHL AI";
		author="p_rodrig";
		url="";
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"cba_xeh"
		};
		units[]={};
		weapons[]={};
	};
};
class CfgFunctions
{
	class BHL
	{
		class CustomLanding
		{
			file="\bhl_ai\functions";
			class initTracker
			{
			};
			class landingLogic
			{
			};
		};
	};
};
class Extended_InitPost_EventHandlers
{
	class Helicopter_Base_F
	{
		class BHL_Attach_Tracker
		{
			init="if (getNumber (configOf (_this select 0) >> 'isUav') == 0) then { [_this select 0] spawn BHL_fnc_initTracker; };";
		};
	};
};
class cfgMods
{
	author="p_rodrig";
	timepacked="1785631575";
};
