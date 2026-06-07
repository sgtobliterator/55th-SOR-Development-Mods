class CfgPatches
{
	class zen_music
	{
		name="ZEN - Music";
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
			"CreepPork"
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
				"zen_music"
			};
		};
	};
};
class CfgMusic
{
	class LeadTrack01a_F
	{
		musicClass="Lead";
		name="$STR_zen_music_ThisIsWarPartOne";
	};
	class LeadTrack01b_F
	{
		musicClass="Lead";
		name="$STR_zen_music_ThisIsWarPartTwo";
	};
	class LeadTrack01_F_Bootcamp
	{
		musicClass="Lead";
	};
	class LeadTrack01_F_EXP
	{
		musicClass="Lead";
	};
	class LeadTrack01a_F_EXP
	{
		musicClass="Lead";
	};
	class LeadTrack01b_F_EXP
	{
		musicClass="Lead";
	};
	class LeadTrack01c_F_EXP
	{
		musicClass="Lead";
	};
	class LeadTrack02a_F_EPA
	{
		musicClass="Action";
	};
	class LeadTrack04a_F
	{
		musicClass="Action";
	};
	class LeadTrack03_F_EPA
	{
		musicClass="Action";
	};
	class LeadTrack02a_F_EPB
	{
		musicClass="Action";
	};
	class LeadTrack01a_F_EPB
	{
		musicClass="Action";
	};
	class LeadTrack02b_F_EPA
	{
		musicClass="Action";
	};
	class AmbientTrack04a_F
	{
		musicClass="Stealth";
	};
	class EventTrack01a_F_Tacops
	{
		musicClass="Action";
	};
	class EventTrack01b_F_Tacops
	{
		musicClass="Action";
	};
	class EventTrack02a_F_Tacops
	{
		musicClass="Action";
	};
	class EventTrack02b_F_Tacops
	{
		musicClass="Action";
	};
	class EventTrack03a_F_Tacops
	{
		musicClass="Action";
	};
	class EventTrack03b_F_Tacops
	{
		musicClass="Action";
	};
	class Defcon
	{
		musicClass="Stealth";
		name="$STR_zen_music_EagleWing_Defcon";
	};
	class Fallout
	{
		musicClass="Stealth";
		name="$STR_zen_music_EagleWing_Fallout";
	};
	class MAD
	{
		musicClass="Stealth";
		name="$STR_zen_music_EagleWing_MAD";
	};
	class SkyNet
	{
		musicClass="Stealth";
		name="$STR_zen_music_EagleWing_SkyNet";
	};
	class Wasteland
	{
		musicClass="Stealth";
		name="$STR_zen_music_EagleWing_Wasteland";
	};
	class Track_O_06
	{
		musicClass="Action";
		name="$STR_zen_music_EagleWing_AllHellBreaksLoose";
	};
	class Track_C_02
	{
		musicClass="Stealth";
		name="$STR_zen_music_A2PMC_NoMansLand";
	};
	class Track_O_01
	{
		musicClass="Lead";
		name="$STR_zen_music_A2OA_Arrowhead";
	};
	class Track_C_18
	{
		musicClass="Calm";
		name="$STR_zen_music_A2OA_IronMountain";
	};
	class Track_C_19
	{
		musicClass="Calm";
		name="$STR_zen_music_A2OA_ConcreteCell";
	};
	class Track_P_05
	{
		musicClass="Calm";
		name="$STR_zen_music_A2OA_Arrival";
	};
	class Track_P_07
	{
		musicClass="Calm";
		name="$STR_zen_music_A2OA_ZargabadMarket";
	};
	class Track_P_09
	{
		musicClass="Calm";
		name="$STR_zen_music_A2OA_Nightlife";
	};
	class Track_P_13
	{
		musicClass="Calm";
		name="$STR_zen_music_A2OA_RevolverJam";
	};
	class Track_P_17
	{
		musicClass="Action";
		name="$STR_zen_music_A2BAF_Jackals";
	};
	class Track_P_18
	{
		musicClass="Action";
		name="$STR_zen_music_A2BAF_ThroughTheValley";
	};
	class Track_O_08
	{
		musicClass="Calm";
		name="$STR_zen_music_A2_RiseOfTheFallen";
	};
	class Track_O_07
	{
		musicClass="Lead";
		name="$STR_zen_music_A2_GhostWaltz";
	};
	class Track_O_12
	{
		musicClass="Action";
		name="$STR_zen_music_A2_DefconThree";
	};
	class Track_O_16
	{
		musicClass="Calm";
		name="$STR_zen_music_A2_Badlands";
	};
	class Track_P_15
	{
		musicClass="Calm";
		name="$STR_zen_music_A2_Reforger";
	};
	class Track_M_01
	{
		musicClass="Action";
		name="$STR_zen_music_A2_CQC";
	};
	class Track_R_01
	{
		musicClass="Action";
		name="$STR_zen_music_A2_Manhattan";
	};
	class Track_R_09
	{
		musicClass="Action";
		name="$STR_zen_music_A2_Logistics";
	};
	class Track_R_11
	{
		musicClass="Action";
		name="$STR_zen_music_A2_SharpingKnives";
	};
	class Track_R_17
	{
		musicClass="Action";
		name="$STR_zen_music_A2_Insertion";
	};
	class Track_O_04
	{
		musicClass="Calm";
		name="$STR_zen_music_OFPCWC_Heroes";
	};
	class Track_C_04
	{
		musicClass="Stealth";
		name="$STR_zen_music_OldMan_Stealth";
	};
	class Track_P_14
	{
		musicClass="Calm";
		name="$STR_zen_music_OldMan_ThisIsWar";
	};
};
