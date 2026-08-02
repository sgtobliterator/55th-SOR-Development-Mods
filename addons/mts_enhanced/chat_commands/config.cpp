class CfgPatches
{
	class mts_chat_commands
	{
		name="mts - Chat Commands";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"mts_common"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"Timi007"
		};
		version=1.1;
		versionStr="1.10.1.260719";
		versionAr[]={1,10,1,260719};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_chat_commands
	{
		init="call compileScript ['\z\mts_enhanced\addons\chat_commands\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_chat_commands
	{
		init="call compileScript ['\z\mts_enhanced\addons\chat_commands\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_chat_commands
	{
		init="call compileScript ['\z\mts_enhanced\addons\chat_commands\XEH_postInit.sqf']";
	};
};
class mts_chat_commands
{
	class medic
	{
		statement="call mts_chat_commands_fnc_promoteToMedic";
		args=1;
	};
	class doctor
	{
		statement="call mts_chat_commands_fnc_promoteToMedic";
		args=2;
	};
	class eng
	{
		statement="call mts_chat_commands_fnc_promoteToEng";
		args=1;
	};
	class adveng
	{
		statement="call mts_chat_commands_fnc_promoteToEng";
		args=2;
	};
	class healall
	{
		statement="call mts_chat_commands_fnc_healAll";
	};
	class heal
	{
		statement="call mts_chat_commands_fnc_heal";
	};
	class markers
	{
		statement="call mts_chat_commands_fnc_markers";
	};
	class zeus
	{
		statement="call mts_chat_commands_fnc_promoteToZeus";
	};
	class teleport
	{
		statement="call mts_chat_commands_fnc_teleport";
	};
	class repair
	{
		statement="call mts_chat_commands_fnc_repair";
	};
};
