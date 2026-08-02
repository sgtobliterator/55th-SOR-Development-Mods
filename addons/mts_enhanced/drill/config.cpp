class CfgPatches
{
	class mts_drill
	{
		name="mts - Drill";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"ace_common"
		};
		author="$STR_mts_main_authors";
		authors[]=
		{
			"Bix",
			"PhILoX",
			"Timi007",
			"Toma"
		};
		url="$STR_mts_main_URL";
		version=1.1;
		versionStr="1.10.1.260719";
		versionAr[]={1,10,1,260719};
	};
};
class CfgMovesBasic
{
	class Actions
	{
		class NoActions;
		class mts_drill_StandStillActions: NoActions
		{
			turnL="";
			turnR="";
			stop="mts_drill_StandStill";
			StopRelaxed="mts_drill_StandStill";
			default="mts_drill_StandStill";
			PutDown="";
			getOver="";
			throwPrepare="";
			throwGrenade[]=
			{
				"",
				"Gesture"
			};
		};
		class mts_drill_AtEaseActions: NoActions
		{
			turnL="";
			turnR="";
			stop="mts_drill_AtEase";
			StopRelaxed="mts_drill_AtEase";
			default="mts_drill_AtEase";
			PutDown="";
			getOver="";
			throwPrepare="";
			throwGrenade[]=
			{
				"",
				"Gesture"
			};
		};
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class StandBase;
	class States
	{
		class AmovPercMstpSnonWnonDnon: StandBase
		{
			ConnectTo[]+=
			{
				"mts_drill_AmovPercMstpSnonWnonDnon_StandStill",
				0.1,
				"mts_drill_AmovPercMstpSnonWnonDnon_AtEase",
				0.1
			};
		};
		class mts_drill_Normal: AmovPercMstpSnonWnonDnon
		{
			file="\z\mts_enhanced\addons\drill\data\mts_Normal.rtm";
			speed=0;
			ConnectTo[]={};
			InterpolateTo[]=
			{
				"Unconscious",
				0.0099999998
			};
			looped=1;
			head="headDefault";
			aimingBody="aimingNo";
			forceAim=1;
			static=1;
		};
		class mts_drill_AmovPercMstpSnonWnonDnon_StandStill: AmovPercMstpSnonWnonDnon
		{
			actions="mts_drill_StandStillActions";
			file="\z\mts_enhanced\addons\drill\data\mts_Normal_StandStill.rtm";
			speed=1;
			ConnectTo[]=
			{
				"mts_drill_StandStill",
				0.1
			};
			InterpolateTo[]=
			{
				"Unconscious",
				0.0099999998
			};
			looped=0;
		};
		class mts_drill_StandStill_AmovPercMstpSnonWnonDnon: mts_drill_AmovPercMstpSnonWnonDnon_StandStill
		{
			actions="CivilStandActions";
			file="\z\mts_enhanced\addons\drill\data\mts_StandStill_Normal.rtm";
			ConnectTo[]=
			{
				"AmovPercMstpSnonWnonDnon",
				0.1
			};
			InterpolateTo[]=
			{
				"Unconscious",
				0.0099999998
			};
		};
		class mts_drill_AmovPercMstpSnonWnonDnon_AtEase: AmovPercMstpSnonWnonDnon
		{
			actions="mts_drill_AtEaseActions";
			file="\z\mts_enhanced\addons\drill\data\mts_Normal_AtEase.rtm";
			speed=1;
			ConnectTo[]=
			{
				"mts_drill_AtEase",
				0.1
			};
			InterpolateTo[]=
			{
				"Unconscious",
				0.0099999998
			};
			looped=0;
		};
		class mts_drill_AtEase_AmovPercMstpSnonWnonDnon: mts_drill_AmovPercMstpSnonWnonDnon_AtEase
		{
			actions="CivilStandActions";
			file="\z\mts_enhanced\addons\drill\data\mts_AtEase_Normal.rtm";
			ConnectTo[]=
			{
				"AmovPercMstpSnonWnonDnon",
				0.1
			};
			InterpolateTo[]=
			{
				"Unconscious",
				0.0099999998
			};
		};
		class mts_drill_StandStill: AmovPercMstpSnonWnonDnon
		{
			actions="mts_drill_StandStillActions";
			file="\z\mts_enhanced\addons\drill\data\mts_StandStill.rtm";
			speed=0;
			ConnectTo[]=
			{
				"mts_drill_StandStill_AmovPercMstpSnonWnonDnon",
				0.1,
				"mts_drill_StandStill_AtEase",
				0.1
			};
			InterpolateTo[]=
			{
				"Unconscious",
				0.0099999998
			};
			looped=1;
			head="headDefault";
			aimingBody="aimingNo";
			forceAim=1;
			static=1;
		};
		class mts_drill_FY: AmovPercMstpSnonWnonDnon
		{
			actions="CivilStandActions";
			file="\z\mts_enhanced\addons\drill\data\mts_FY.rtm";
			ConnectTo[]=
			{
				"AmovPercMstpSnonWnonDnon",
				0.1
			};
			InterpolateTo[]=
			{
				"Unconscious",
				0.0099999998
			};
			speed=1;
		};
		class mts_drill_AtEase: AmovPercMstpSnonWnonDnon
		{
			actions="mts_drill_AtEaseActions";
			file="\z\mts_enhanced\addons\drill\data\mts_AtEase.rtm";
			speed=0;
			ConnectTo[]=
			{
				"mts_drill_AtEase_StandStill",
				0.1,
				"mts_drill_AtEase_AmovPercMstpSnonWnonDnon",
				0.1
			};
			InterpolateTo[]=
			{
				"Unconscious",
				0.0099999998
			};
			looped=1;
			head="headDefault";
			aimingBody="aimingNo";
			forceAim=1;
			static=1;
		};
		class mts_drill_AtEase_StandStill: AmovPercMstpSnonWnonDnon
		{
			actions="mts_drill_StandStillActions";
			file="\z\mts_enhanced\addons\drill\data\mts_AtEase_StandStill.rtm";
			speed=1;
			ConnectTo[]=
			{
				"mts_drill_StandStill",
				0.1
			};
			InterpolateTo[]=
			{
				"Unconscious",
				0.0099999998
			};
			looped=0;
		};
		class mts_drill_StandStill_AtEase: AmovPercMstpSnonWnonDnon
		{
			actions="mts_drill_AtEaseActions";
			file="\z\mts_enhanced\addons\drill\data\mts_StandStill_AtEase.rtm";
			speed=1;
			ConnectTo[]=
			{
				"mts_drill_AtEase",
				0.1
			};
			InterpolateTo[]=
			{
				"Unconscious",
				0.0099999998
			};
			looped=0;
		};
	};
};
class Extended_PreStart_EventHandlers
{
	class mts_drill
	{
		init="call compileScript ['\z\mts_enhanced\addons\drill\XEH_preStart.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class mts_drill
	{
		init="call compileScript ['\z\mts_enhanced\addons\drill\XEH_preInit.sqf']";
	};
};
class Extended_PostInit_EventHandlers
{
	class mts_drill
	{
		init="call compileScript ['\z\mts_enhanced\addons\drill\XEH_postInit.sqf']";
	};
};
class RscPicture;
class IGUIBack;
class RscTitles
{
	class mts_drill_StandStill
	{
		idd=800520;
		duration=999999;
		class controls
		{
			class mts_drill_StandStill_Picture: RscPicture
			{
				idc=-1;
				text="\z\mts_enhanced\addons\drill\ui\mts_StandStill.paa";
				x="SafeZoneX + (1792 / 1920) * SafeZoneW";
				y="SafeZoneY + (952 / 1080) * safeZoneH";
				w="(128 / 1920) * SafeZoneW";
				h="(128 / 1080) * safeZoneH";
			};
		};
		class controlsBackground
		{
			class mts_drill_StandStill_Background: IGUIBack
			{
				idc=-1;
				colorBackground[]={0,0,0,0.30000001};
				x="SafeZoneX + (1792 / 1920) * SafeZoneW";
				y="SafeZoneY + (952 / 1080) * safeZoneH";
				w="(128 / 1920) * SafeZoneW";
				h="(128 / 1080) * safeZoneH";
			};
		};
	};
	class mts_drill_AtEase
	{
		idd=800521;
		duration=999999;
		class controls
		{
			class mts_drill_AtEase_Picture: RscPicture
			{
				idc=-1;
				text="\z\mts_enhanced\addons\drill\ui\mts_AtEase.paa";
				x="SafeZoneX + (1792 / 1920) * SafeZoneW";
				y="SafeZoneY + (952 / 1080) * safeZoneH";
				w="(128 / 1920) * SafeZoneW";
				h="(128 / 1080) * safeZoneH";
			};
		};
		class controlsBackground
		{
			class mts_drill_AtEase_Background: IGUIBack
			{
				idc=-1;
				colorBackground[]={0,0,0,0.30000001};
				x="SafeZoneX + (1792 / 1920) * SafeZoneW";
				y="SafeZoneY + (952 / 1080) * safeZoneH";
				w="(128 / 1920) * SafeZoneW";
				h="(128 / 1080) * safeZoneH";
			};
		};
	};
};
