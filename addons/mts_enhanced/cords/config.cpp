class CfgPatches
{
	class mts_cords
	{
		name="mts - Cords";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"ace_common",
			"ace_interact_menu"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"PhILoX",
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
	class mts_cords
	{
		init="call compileScript ['\z\mts_enhanced\addons\cords\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_cords
	{
		init="call compileScript ['\z\mts_enhanced\addons\cords\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_cords
	{
		init="call compileScript ['\z\mts_enhanced\addons\cords\XEH_postInit.sqf']";
	};
};
class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class ACE_SelfActions
		{
			class ACE_Equipment
			{
				class mts_cords_cords
				{
					displayName="$STR_mts_cords_cords";
					icon="\z\mts_enhanced\addons\cords\data\ui\mts_cords_ui_co.paa";
					statement="";
					condition="mts_cords_PBWLoaded && {mts_cords_enabled} && {[_player] call mts_cords_fnc_hasPBWUniform}";
					exceptions[]=
					{
						"isNotSwimming",
						"isNotInside",
						"isNotSitting",
						"isNotOnLadder",
						"isNotRefueling"
					};
					class mts_cords_cordsInf
					{
						displayName="$STR_mts_cords_inf";
						icon="\z\mts_enhanced\addons\cords\data\ui\mts_cords_ui_inf_co.paa";
						statement="[_player, 'inf'] call mts_cords_fnc_placeCordOnUniform";
						condition="true";
						exceptions[]=
						{
							"isNotSwimming",
							"isNotInside",
							"isNotSitting",
							"isNotOnLadder",
							"isNotRefueling"
						};
						class mts_cords_cordsInfFA
						{
							displayName="$STR_mts_cords_fa";
							icon="\z\mts_enhanced\addons\cords\data\ui\mts_cords_ui_fa_co.paa";
							statement="[_player, 'inf_fa'] call mts_cords_fnc_placeCordOnUniform";
							condition="true";
							exceptions[]=
							{
								"isNotSwimming",
								"isNotInside",
								"isNotSitting",
								"isNotOnLadder",
								"isNotRefueling"
							};
						};
						class mts_cords_cordsInfOA
						{
							displayName="$STR_mts_cords_oa";
							icon="\z\mts_enhanced\addons\cords\data\ui\mts_cords_ui_oa_co.paa";
							statement="[_player, 'inf_oa'] call mts_cords_fnc_placeCordOnUniform";
							condition="true";
							exceptions[]=
							{
								"isNotSwimming",
								"isNotInside",
								"isNotSitting",
								"isNotOnLadder",
								"isNotRefueling"
							};
						};
					};
					class mts_cords_cordsPz
					{
						displayName="$STR_mts_cords_pz";
						icon="\z\mts_enhanced\addons\cords\data\ui\mts_cords_ui_pz_co.paa";
						statement="[_player, 'pz'] call mts_cords_fnc_placeCordOnUniform";
						condition="true";
						exceptions[]=
						{
							"isNotSwimming",
							"isNotInside",
							"isNotSitting",
							"isNotOnLadder",
							"isNotRefueling"
						};
						class mts_cords_cordsInfFA
						{
							displayName="$STR_mts_cords_fa";
							icon="\z\mts_enhanced\addons\cords\data\ui\mts_cords_ui_fa_co.paa";
							statement="[_player, 'pz_fa'] call mts_cords_fnc_placeCordOnUniform";
							condition="true";
							exceptions[]=
							{
								"isNotSwimming",
								"isNotInside",
								"isNotSitting",
								"isNotOnLadder",
								"isNotRefueling"
							};
						};
						class mts_cords_cordsInfOA
						{
							displayName="$STR_mts_cords_oa";
							icon="\z\mts_enhanced\addons\cords\data\ui\mts_cords_ui_oa_co.paa";
							statement="[_player, 'pz_oa'] call mts_cords_fnc_placeCordOnUniform";
							condition="true";
							exceptions[]=
							{
								"isNotSwimming",
								"isNotInside",
								"isNotSitting",
								"isNotOnLadder",
								"isNotRefueling"
							};
						};
					};
				};
			};
		};
	};
};
