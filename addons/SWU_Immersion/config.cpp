class CfgPatches
{
	class SWU_Immersion_Pack
	{
		units[]=
		{
			"Zombie_Sound_Doors",
			"Sound_WarMisc_Zone",
			"Sound_WarMisc_LastPost",
			"Sound_Alarm_Ship",
			"Sound_Alarm_Facility",
			"Jihad_Sound_Allah1",
			"Jihad_Sound_Allah2",
			"Jihad_Sound_Radio1",
			"SW_Sound_Amb",
			"SW_Sound_Vader",
			"SW_Sound_Saber",
			"SW_Sound_Roger",
			"Veh_Sound_Abrams",
			"Veh_Sound_AbramsStart",
			"Veh_Sound_Train",
			"Sound_Misc_Airport",
			"Sound_Misc_ATC",
			"Sound_Misc_Docks",
			"Sound_Misc_Dog",
			"Sound_Misc_Keyboard",
			"Sound_Misc_Police",
			"Sound_Misc_Underwater",
			"Afghanradio1_veh",
			"Afghanradio2_veh",
			"Afghanradio3_veh",
			"GenerationKill1_veh",
			"GenerationKill2_veh",
			"GenerationKill3_veh",
			"Vietnam1_veh",
			"Vietnam2_veh",
			"Vietnam3_veh",
			"VietnamOpSoul_veh",
			"VietnamHannah_veh",
			"MosqueCall_veh",
			"MosqueCall2_veh",
			"IraqBombing_veh",
			"CloseUSFirefight_veh",
			"AfghanCitySounds_veh",
			"SAWGunner_veh",
			"CODAmbience_veh",
			"JakkuBattle_veh",
			"JungleWar_veh",
			"WW2Ambience_veh",
			"WW2Ambience2_veh",
			"WW2AirSiren_veh",
			"WW2Churchill_veh",
			"WW2SoS_veh",
			"WW2French_veh",
			"WW2USRadio_veh",
			"WW2Eisenhower_veh",
			"RUSRadio1",
			"RUSRadio2",
			"RUSVoices1",
			"UKRCombat",
			"CheekiBreekiSFX"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Functions_F"
		};
	};
};
class CfgMusicClasses
{
	class SWU_Imm_Nam
	{
		displayName="[SWU] Vietnam";
	};
	class SWU_Imm_WW2
	{
		displayName="[SWU] WW2";
	};
	class SWU_Imm_Iraq
	{
		displayName="[SWU] Modern";
	};
	class SWU_Imm_Misc
	{
		displayName="[SWU] Misc";
	};
	class SWU_Imm_SW
	{
		displayName="[SWU] SW";
	};
};
class CfgMusic
{
	class BOBTheme
	{
		name="[SWU] Band Of Brothers - Main Theme";
		sound[]=
		{
			"SWU_Immersion\music\ww2\BoB.ogg",
			1,
			1
		};
		theme="Music";
		duration="134";
		musicClass="SWU_Imm_WW2";
	};
	class AtonementDun
	{
		name="[SWU] Atonement - Dunkirk Music";
		sound[]=
		{
			"SWU_Immersion\music\ww2\dunkirkatonement.ogg",
			1,
			1
		};
		theme="Music";
		duration="300";
		musicClass="SWU_Imm_WW2";
	};
	class ErikaWehr
	{
		name="[SWU] Erika";
		sound[]=
		{
			"SWU_Immersion\music\ww2\erika.ogg",
			1,
			1
		};
		theme="Music";
		duration="120";
		musicClass="SWU_Imm_WW2";
	};
	class Panzerliedwehr
	{
		name="[SWU] Panzerlied";
		sound[]=
		{
			"SWU_Immersion\music\ww2\Panzerlied.ogg",
			1,
			1
		};
		theme="Music";
		duration="78";
		musicClass="SWU_Imm_WW2";
	};
	class RommelWehr
	{
		name="[SWU] Deutsches Afrika Korps - Uncer Rommel";
		sound[]=
		{
			"SWU_Immersion\music\ww2\rommel.ogg",
			1,
			1
		};
		theme="Music";
		duration="136";
		musicClass="SWU_Imm_WW2";
	};
	class SovietMarch1
	{
		name="[SWU] Soviet March 1";
		sound[]=
		{
			"SWU_Immersion\music\ww2\sovmarch1.ogg",
			1,
			1
		};
		theme="Music";
		duration="148";
		musicClass="SWU_Imm_WW2";
	};
	class SovietMarch2
	{
		name="[SWU] Soviet March 2";
		sound[]=
		{
			"SWU_Immersion\music\ww2\sovmarch2.ogg",
			1,
			1
		};
		theme="Music";
		duration="148";
		musicClass="SWU_Imm_WW2";
	};
	class ABTrailerMusic
	{
		name="[SWU] Mount Legend";
		sound[]=
		{
			"SWU_Immersion\music\ww2\mountlegend.ogg",
			1,
			1
		};
		theme="Music";
		duration="145";
		musicClass="SWU_Imm_WW2";
	};
	class SPRMain
	{
		name="[SWU] Saving Private Ryan - Main Theme";
		sound[]=
		{
			"SWU_Immersion\music\ww2\SavingRyanMain.ogg",
			1,
			1
		};
		theme="Music";
		duration="360";
		musicClass="SWU_Imm_WW2";
	};
	class RiverKwai
	{
		name="[SWU] Bridge Over The River Kwai";
		sound[]=
		{
			"SWU_Immersion\music\ww2\riverkwai.ogg",
			1,
			1
		};
		theme="Music";
		duration="62";
		musicClass="SWU_Imm_WW2";
	};
	class TheLastPost
	{
		name="[SWU] The Last Post";
		sound[]=
		{
			"SWU_Immersion\sounds\misc_war\lastpost.ogg",
			1,
			1
		};
		theme="Music";
		duration="62";
		musicClass="SWU_Imm_WW2";
	};
	class Badmoonrising
	{
		name="[SWU] Creedence - Bad Moon Rising";
		sound[]=
		{
			"SWU_Immersion\music\nam\badmoon.ogg",
			1,
			1
		};
		theme="Music";
		duration="120";
		musicClass="SWU_Imm_Nam";
	};
	class BettaRunThrough
	{
		name="[SWU] Creedence - Run Through The Jungle";
		sound[]=
		{
			"SWU_Immersion\music\nam\runthroughjungle.ogg",
			1,
			1
		};
		theme="Music";
		duration="78";
		musicClass="SWU_Imm_Nam";
	};
	class CreedenceRain
	{
		name="[SWU] Creedence - Have You Ever Seen The Rain";
		sound[]=
		{
			"SWU_Immersion\music\nam\seentherain.ogg",
			1,
			1
		};
		theme="Music";
		duration="136";
		musicClass="SWU_Imm_Nam";
	};
	class SomebodyToLove
	{
		name="[SWU] Jefferson Airplane - Need Somebody To Love";
		sound[]=
		{
			"SWU_Immersion\music\nam\somebodytoluv.ogg",
			1,
			1
		};
		theme="Music";
		duration="148";
		musicClass="SWU_Imm_Nam";
	};
	class RamboMain
	{
		name="[SWU] Rambo 4 - Main Theme";
		sound[]=
		{
			"SWU_Immersion\music\nam\rambo4.ogg",
			1,
			1
		};
		theme="Music";
		duration="210";
		musicClass="SWU_Imm_Nam";
	};
	class RamboAfter
	{
		name="[SWU] Rambo 4 - Aftermath";
		sound[]=
		{
			"SWU_Immersion\music\nam\ramboaftermath.ogg",
			1,
			1
		};
		theme="Music";
		duration="210";
		musicClass="SWU_Imm_Nam";
	};
	class RamboCall
	{
		name="[SWU] Rambo 4 - Call To Arms";
		sound[]=
		{
			"SWU_Immersion\music\nam\rambocalltowar.ogg",
			1,
			1
		};
		theme="Music";
		duration="139";
		musicClass="SWU_Imm_Nam";
	};
	class WeWereSoldiers
	{
		name="[SWU] We Were Soldiers - Sgt. MacKenzie";
		sound[]=
		{
			"SWU_Immersion\music\nam\weweresoldiers.ogg",
			1,
			1
		};
		theme="Music";
		duration="150";
		musicClass="SWU_Imm_Nam";
	};
	class PlatoonTheme
	{
		name="[SWU] Platoon Theme";
		sound[]=
		{
			"SWU_Immersion\music\nam\platoontheme.ogg",
			1,
			1
		};
		theme="Music";
		duration="140";
		musicClass="SWU_Imm_Nam";
	};
	class BHD1
	{
		name="[SWU] Black Hawk Down - Gortoz A Ran";
		sound[]=
		{
			"SWU_Immersion\music\Iraq\BHDMain.ogg",
			1,
			1
		};
		theme="Music";
		duration="240";
		musicClass="SWU_Imm_Iraq";
	};
	class BHD2
	{
		name="[SWU] Black Hawk Down - Never Leave A Man Behind";
		sound[]=
		{
			"SWU_Immersion\music\Iraq\BHDNever.ogg",
			1,
			1
		};
		theme="Music";
		duration="364";
		musicClass="SWU_Imm_Iraq";
	};
	class BHD3
	{
		name="[SWU] Black Hawk Down - He's Dead";
		sound[]=
		{
			"SWU_Immersion\music\Iraq\BHDDead.ogg",
			1,
			1
		};
		theme="Music";
		duration="360";
		musicClass="SWU_Imm_Iraq";
	};
	class CashComesAround
	{
		name="[SWU] Johnny Cash - When The Man Comes Around";
		sound[]=
		{
			"SWU_Immersion\music\Iraq\ComesAround.ogg",
			1,
			1
		};
		theme="Music";
		duration="210";
		musicClass="SWU_Imm_Iraq";
	};
	class CashHurt
	{
		name="[SWU] Johnny Cash - Hurt";
		sound[]=
		{
			"SWU_Immersion\music\Iraq\hurt.ogg",
			1,
			1
		};
		theme="Music";
		duration="255";
		musicClass="SWU_Imm_Iraq";
	};
	class LoneSurvivor
	{
		name="[SWU] Lone Survivor - Never Give Up";
		sound[]=
		{
			"SWU_Immersion\music\Iraq\LoneNeverGive.ogg",
			1,
			1
		};
		theme="Music";
		duration="94";
		musicClass="SWU_Imm_Iraq";
	};
	class WalkTheLine
	{
		name="[SWU] Johnny Cash - I Walk The Line";
		sound[]=
		{
			"SWU_Immersion\music\Iraq\WalkLine.ogg",
			1,
			1
		};
		theme="Music";
		duration="149";
		musicClass="SWU_Imm_Iraq";
	};
	class GenWar1
	{
		name="[SWU] Generation War - Main Theme";
		sound[]=
		{
			"SWU_Immersion\music\ww2\genwarmain.ogg",
			1,
			1
		};
		theme="Music";
		duration="121";
		musicClass="SWU_Imm_ww2";
	};
	class GenWar2
	{
		name="[SWU] Generation War - Zukunft";
		sound[]=
		{
			"SWU_Immersion\music\ww2\genwarzukunft.ogg",
			1,
			1
		};
		theme="Music";
		duration="195";
		musicClass="SWU_Imm_ww2";
	};
	class GenWar3
	{
		name="[SWU] Generation War - Hinterhilt";
		sound[]=
		{
			"SWU_Immersion\music\ww2\genwarhinterhilt.ogg",
			1,
			1
		};
		theme="Music";
		duration="128";
		musicClass="SWU_Imm_ww2";
	};
	class KonigMarch
	{
		name="[SWU] Koniggratzer March";
		sound[]=
		{
			"SWU_Immersion\music\ww2\Konig.ogg",
			1,
			1
		};
		theme="Music";
		duration="135";
		musicClass="SWU_Imm_ww2";
	};
	class CheekiBreekiMUS
	{
		name="[SWU] Meet The Bandits";
		sound[]=
		{
			"SWU_Immersion\music\misc\cheeki.ogg",
			1,
			1
		};
		theme="Music";
		duration="142";
		musicClass="SWU_Imm_Misc";
	};
	class CrimsonTideTheme
	{
		name="[SWU] Crimson Tide Theme";
		sound[]=
		{
			"SWU_Immersion\music\iraq\crimsontide.ogg",
			1,
			1
		};
		theme="Music";
		duration="142";
		musicClass="SWU_Imm_Misc";
	};
	class VikingSnake
	{
		name="[SWU] Vikings Soundtrack - Snake Pit";
		sound[]=
		{
			"SWU_Immersion\music\misc\snakepit.ogg",
			1,
			1
		};
		theme="Music";
		duration="137";
		musicClass="SWU_Imm_Misc";
	};
	class FluteIntro
	{
		name="[SWU] Flute Intro";
		sound[]=
		{
			"SWU_Immersion\music\misc\fluteintro.ogg",
			1,
			1
		};
		theme="Music";
		duration="21";
		musicClass="SWU_Imm_Misc";
	};
	class BeachBoys
	{
		name="[SWU] Beach Boys - I get Around";
		sound[]=
		{
			"SWU_Immersion\music\misc\beachboys.ogg",
			1,
			1
		};
		theme="Music";
		duration="21";
		musicClass="SWU_Imm_Misc";
	};
	class EastGermanyAnthem
	{
		name="[SWU] West Germany Anthem";
		sound[]=
		{
			"SWU_Immersion\sounds\misc_war\westgermanyanthem.ogg",
			1,
			1
		};
		theme="Music";
		duration="110";
		musicClass="SWU_Imm_Misc";
	};
	class WestGermanyAnthem
	{
		name="[SWU] East Germany Anthem";
		sound[]=
		{
			"SWU_Immersion\sounds\misc_war\eastgermanyanthem.ogg",
			1,
			1
		};
		theme="Music";
		duration="67";
		musicClass="SWU_Imm_Misc";
	};
	class SWForceHigh
	{
		name="[SWU] Force Theme (High)";
		sound[]=
		{
			"SWU_Immersion\music\sw\forcehigh.ogg",
			1,
			1
		};
		theme="Music";
		duration="21";
		musicClass="SWU_Imm_SW";
	};
	class SWForceLow
	{
		name="[SWU] Force Theme (Low)";
		sound[]=
		{
			"SWU_Immersion\music\sw\forcelow.ogg",
			1,
			1
		};
		theme="Music";
		duration="62";
		musicClass="SWU_Imm_SW";
	};
	class SWKorribanAmb
	{
		name="[SWU] Korriban Ambient Track";
		sound[]=
		{
			"SWU_Immersion\music\sw\swkorriban.ogg",
			1,
			1
		};
		theme="Music";
		duration="62";
		musicClass="SWU_Imm_SW";
	};
	class SWAlderaanAmb
	{
		name="[SWU] Alderaan Ambient Track";
		sound[]=
		{
			"SWU_Immersion\music\sw\swalderaan.ogg",
			1,
			1
		};
		theme="Music";
		duration="128";
		musicClass="SWU_Imm_SW";
	};
};
class CfgSFX
{
	class Afghanradio1
	{
		name="Afghanradio1";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\BBCNews1.ogg",
			10,
			1,
			17,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Afghanradio2
	{
		name="Afghanradio2";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\BBCNews2.ogg",
			15,
			1,
			17,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Afghanradio3
	{
		name="Afghanradio3";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\bbcafghan1.ogg",
			15,
			1,
			17,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class GenerationKill1
	{
		name="GenerationKill1";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\gen1.ogg",
			15,
			1,
			20,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class GenerationKill2
	{
		name="GenerationKill2";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\gen2.ogg",
			15,
			1,
			20,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class GenerationKill3
	{
		name="GenerationKill3";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\gen3.ogg",
			15,
			1,
			20,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Vietnam1
	{
		name="VietnamChatter1";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\vietnam.ogg",
			15,
			1,
			18,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Vietnam2
	{
		name="VietnamChatter2";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\vietnam2.ogg",
			15,
			1,
			18,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Vietnam3
	{
		name="VietnamChatter3";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\vietnam3.ogg",
			15,
			1,
			18,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class VietnamOpSoul
	{
		name="OpWanderingSoul";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\vietnam\wanderingsoul.ogg",
			15,
			1,
			1400,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class VietnamHannoi
	{
		name="VietnamHannoi";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\vietnam\hannoihannah.ogg",
			15,
			1,
			500,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class MosqueCall
	{
		name="MosqueCall";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\bluemosque.ogg",
			15,
			1,
			400,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class MosqueCall2
	{
		name="MosqueCall2";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\narazethcall.ogg",
			15,
			1,
			400,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class IraqBombing
	{
		name="IraqBombing";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\iraqwar.ogg",
			15,
			1,
			2300,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class CloseUSFirefight
	{
		name="CloseUSFirefight";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\firefight1.ogg",
			15,
			1,
			800,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class AfghanCitySounds
	{
		name="AfghanCitySounds";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\afghancity.ogg",
			15,
			1,
			800,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class SAWGunner
	{
		name="SAWGunner";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\afghansaw.ogg",
			15,
			1,
			800,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class JakkuBattle
	{
		name="JakkuBattle";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\jakku.ogg",
			15,
			1,
			2000,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class JungleWar
	{
		name="JungleWar";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\junglefirefight.ogg",
			15,
			1,
			2000,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class CODAmbience
	{
		name="CoD4Ambience";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\codfirefight.ogg",
			15,
			1,
			2000,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class WW2Ambience
	{
		name="WW2Ambience";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\ww2Arty.ogg",
			15,
			1,
			2000,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class WW2Ambience2
	{
		name="WW2Ambience";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\ww2firefight.ogg",
			15,
			1,
			2000,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class WW2AirSiren
	{
		name="WW2Ambience";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\airsiren.ogg",
			15,
			1,
			2000,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class WW2Churchill
	{
		name="WW2ChurchillSpeech";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\churchillnever.ogg",
			15,
			1,
			20,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class WW2SoS
	{
		name="S.O.S Sound";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\SOS.ogg",
			15,
			1,
			13,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class WW2French
	{
		name="S.O.S Sound";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\savingfrench.ogg",
			15,
			1,
			20,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class WW2USRadio
	{
		name="US Radio WW2";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\MusicUS3.ogg",
			15,
			1,
			20,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class WW2Eisenhower
	{
		name="Eisenhower Speech D-Day";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\radio\Eisenhower.ogg",
			15,
			1,
			20,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class UkraineCombat
	{
		name="Ukraine War Combat Sounds w/Voices";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\RU\rus_cqb1.ogg",
			15,
			1,
			1000,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class RURadioChatter
	{
		name="RU Radio Chatter 1";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\RU\rusradio1.ogg",
			15,
			1,
			18,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class RURadioChatter2
	{
		name="RU Radio Chatter 2";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\RU\rusradio2.ogg",
			15,
			1,
			18,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class RUVoices
	{
		name="Russian Voices";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\RU\rusvoices1.ogg",
			15,
			1,
			30,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class CheekiBreeki
	{
		name="Cheeki Breeki";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\music\misc\cheeki.ogg",
			15,
			1,
			30,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class SWRoger
	{
		name="SWRoger";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\sw\roger.ogg",
			15,
			1,
			18,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class SWSaber
	{
		name="SWSaber";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\sw\sabersound.ogg",
			15,
			1,
			13,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class SWHangar
	{
		name="SWAlderaan";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\sw\swambience1.ogg",
			15,
			1,
			2000,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class SWVader
	{
		name="SWVader";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\sw\vaderbreath.ogg",
			15,
			1,
			5,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class VSound_Abrams
	{
		name="VSound_Abrams";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\veh\abramsengine.ogg",
			15,
			1,
			100,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class VSound_AbramsStart
	{
		name="VSound_AbramsStart";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\veh\abramsenginestart.ogg",
			15,
			1,
			100,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class VSound_Train
	{
		name="VSound_Train";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\veh\insidetrain.ogg",
			15,
			1,
			20,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Jihad_Akbar_1
	{
		name="Akbar_1";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\jihad\allah1.ogg",
			15,
			1,
			35,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Jihad_Akbar_2
	{
		name="Akbar_2";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\jihad\allah2.ogg",
			15,
			1,
			20,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Jihad_Radio_1
	{
		name="Jihad_Radio_1";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\jihad\arabradio.ogg",
			15,
			1,
			17,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Alarms_Ship
	{
		name="Alarm_Ship";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\alarms\shipalarm.ogg",
			15,
			1,
			100,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Alarms_Facility
	{
		name="Alarm_Ship";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\alarms\facilityalarm.ogg",
			15,
			1,
			200,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Misc_AirportSounds
	{
		name="Misc_Airport";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\misc\airport1.ogg",
			15,
			1,
			350,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Misc_ATCSounds
	{
		name="Misc_ATCSounds";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\misc\ATC1.ogg",
			15,
			1,
			14,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Misc_DockyardSounds
	{
		name="Misc_DockyardSounds";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\misc\dockyard.ogg",
			15,
			1,
			20,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Misc_DogBark
	{
		name="Misc_DogBark";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\misc\dogbark1.ogg",
			15,
			1,
			200,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Misc_ComputerWorker
	{
		name="Misc_ComputerWorker";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\misc\keyboardworker.ogg",
			15,
			1,
			4,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Misc_PoliceUS
	{
		name="Misc_PoliceUS";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\misc\policeUS.ogg",
			15,
			1,
			350,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Misc_UnderwaterSound
	{
		name="Misc_UnderwaterSound";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\misc\underwater.ogg",
			15,
			1,
			50,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Misc_Warzone
	{
		name="Misc_Warzone";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\misc_war\distantwarzone.ogg",
			15,
			1,
			2500,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Misc_LastPost
	{
		name="Misc_LastPost";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\misc_war\lastpost.ogg",
			15,
			1,
			60,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
	class Zom_ZombieDoor
	{
		name="Misc_LastPost";
		sounds[]=
		{
			"sfxsound"
		};
		sfxsound[]=
		{
			"SWU_Immersion\sounds\zombie\zombiedoor.ogg",
			15,
			1,
			50,
			1,
			1,
			1,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			0,
			0,
			0
		};
	};
};
class CfgVehicles
{
	class All;
	class Sound: All
	{
		author="swurvin";
		mapSize=10;
		_generalMacro="Sound";
		scope=0;
		side=-1;
		animated=0;
		vehicleClass="Sounds";
		icon="iconSound";
		faction="none";
		editorCategory="EdCat_Sounds";
		editorSubcategory="EdSubcat_Sounds";
	};
	class Zombie_Sound_Doors: Sound
	{
		author="Swurvin";
		_generalMacro="Zombie_Sound_Doors";
		scope=2;
		sound="Zom_ZombieDoor";
		displayName="[SWU] Zombies At Doors";
	};
	class Sound_WarMisc_Zone: Sound
	{
		author="Swurvin";
		_generalMacro="Sound_WarMisc_Zone";
		scope=2;
		sound="Misc_Warzone";
		displayName="[SWU] Distant Warzone";
	};
	class Sound_WarMisc_LastPost: Sound
	{
		author="Swurvin";
		_generalMacro="Sound_WarMisc_LastPost";
		scope=2;
		sound="Misc_LastPost";
		displayName="[SWU] The Last Post";
	};
	class Sound_Alarm_Ship: Sound
	{
		author="Swurvin";
		_generalMacro="Sound_Alarm_Ship";
		scope=2;
		sound="Alarms_Ship";
		displayName="[SWU] Ship Alarm";
	};
	class Sound_Alarm_Facility: Sound
	{
		author="Swurvin";
		_generalMacro="Sound_Alarm_Facility";
		scope=2;
		sound="Alarms_Facilty";
		displayName="[SWU] Facility Alarm";
	};
	class Jihad_Sound_Allah1: Sound
	{
		author="Swurvin";
		_generalMacro="Jihad_Sound_Allah1";
		scope=2;
		sound="Jihad_Akbar_1";
		displayName="[SWU] Allahu Akbar 1";
	};
	class Jihad_Sound_Allah2: Sound
	{
		author="Swurvin";
		_generalMacro="Jihad_Sound_Allah2";
		scope=2;
		sound="Jihad_Akbar_2";
		displayName="[SWU] Allahu Akbar 2 (low)";
	};
	class Jihad_Sound_Radio1: Sound
	{
		author="Swurvin";
		_generalMacro="Jihad_Sound_Allah2";
		scope=2;
		sound="Jihad_Radio_1";
		displayName="[SWU] Jihad Music";
	};
	class SW_Sound_Amb: Sound
	{
		author="Swurvin";
		_generalMacro="SW_Sound_Amb";
		scope=2;
		sound="SWHangar";
		displayName="[SWU] SW - Hangar Ambience";
	};
	class SW_Sound_Vader: Sound
	{
		author="Swurvin";
		_generalMacro="SW_Sound_Vader";
		scope=2;
		sound="SWVader";
		displayName="[SWU] SW - Vader Breath";
	};
	class SW_Sound_Saber: Sound
	{
		author="Swurvin";
		_generalMacro="SW_Sound_Saber";
		scope=2;
		sound="SWSaber";
		displayName="[SWU] SW - Saber Sound";
	};
	class SW_Sound_Roger: Sound
	{
		author="Swurvin";
		_generalMacro="SW_Sound_Roger";
		scope=2;
		sound="SWRoger";
		displayName="[SWU] SW - Roger Roger";
	};
	class Veh_Sound_Abrams: Sound
	{
		author="Swurvin";
		_generalMacro="Veh_Sound_Abrams";
		scope=2;
		sound="VSound_Abrams";
		displayName="[SWU] M1A1 Abrams Engine";
	};
	class Veh_Sound_AbramsStart: Sound
	{
		author="Swurvin";
		_generalMacro="Veh_Sound_AbramsStart";
		scope=2;
		sound="VSound_AbramsStart";
		displayName="[SWU] M1A1 Abrams Engine Start-Up";
	};
	class Veh_Sound_Train: Sound
	{
		author="Swurvin";
		_generalMacro="Veh_Sound_Train";
		scope=2;
		sound="VSound_Train";
		displayName="[SWU] Inside Train Sound";
	};
	class Sound_Misc_Airport: Sound
	{
		author="Swurvin";
		_generalMacro="Sound_Misc_Airport";
		scope=2;
		sound="Misc_AirportSounds";
		displayName="[SWU] Airport Ambience";
	};
	class Sound_Misc_ATC: Sound
	{
		author="Swurvin";
		_generalMacro="Sound_Misc_Airport";
		scope=2;
		sound="Misc_ATCSounds";
		displayName="[SWU] ATC Chatter";
	};
	class Sound_Misc_Docks: Sound
	{
		author="Swurvin";
		_generalMacro="Sound_Misc_Airport";
		scope=2;
		sound="Misc_DockyardSounds";
		displayName="[SWU] Dockyard Ambience";
	};
	class Sound_Misc_Dog: Sound
	{
		author="Swurvin";
		_generalMacro="Sound_Misc_Airport";
		scope=2;
		sound="Misc_DogBark";
		displayName="[SWU] Distant Dog Barking";
	};
	class Sound_Misc_Keyboard: Sound
	{
		author="Swurvin";
		_generalMacro="Sound_Misc_Airport";
		scope=2;
		sound="Misc_ComputerWorker";
		displayName="[SWU] Keyboard Sound";
	};
	class Sound_Misc_Police: Sound
	{
		author="Swurvin";
		_generalMacro="Sound_Misc_Airport";
		scope=2;
		sound="Misc_PoliceUS";
		displayName="[SWU] Police Sirens";
	};
	class Sound_Misc_Underwater: Sound
	{
		author="Swurvin";
		_generalMacro="Sound_Misc_Airport";
		scope=2;
		sound="Misc_UnderwaterSound";
		displayName="[SWU] Underwater Ambience";
	};
	class Afghanradio1_veh: Sound
	{
		author="Swurvin";
		_generalMacro="Afghanradio1_veh";
		scope=2;
		sound="Afghanradio1";
		displayName="[SWU] BBC News - Black Watch Reg Afghanistan";
	};
	class Afghanradio2_veh: Sound
	{
		author="Swurvin";
		_generalMacro="Afghanradio2_veh";
		scope=2;
		sound="Afghanradio2";
		displayName="[SWU] BBC News - Royal Marines Afghanistan";
	};
	class Afghanradio3_veh: Sound
	{
		author="Swurvin";
		_generalMacro="Afghanradio3_veh";
		scope=2;
		sound="Afghanradio3";
		displayName="[SWU] BBC News - Suicide Bombing Report (radio)";
	};
	class GenerationKill1_veh: Sound
	{
		author="Swurvin";
		_generalMacro="GenerationKill1_veh";
		scope=2;
		sound="GenerationKill1";
		displayName="[SWU] Generation Kill - Chatter";
	};
	class GenerationKill2_veh: Sound
	{
		author="Swurvin";
		_generalMacro="GenerationKill2_veh";
		scope=2;
		sound="GenerationKill2";
		displayName="[SWU] Generation Kill - Chatter 2";
	};
	class GenerationKill3_veh: Sound
	{
		author="Swurvin";
		_generalMacro="GenerationKill3_veh";
		scope=2;
		sound="GenerationKill3";
		displayName="[SWU] Generation Kill - Chatter 3";
	};
	class Vietnam1_veh: Sound
	{
		author="Swurvin";
		_generalMacro="Vietnam1_veh";
		scope=2;
		sound="Vietnam1";
		displayName="[SWU] Vietnam Chatter 1";
	};
	class Vietnam2_veh: Sound
	{
		author="Swurvin";
		_generalMacro="Vietnam2_veh";
		scope=2;
		sound="Vietnam2";
		displayName="[SWU] Vietnam Chatter 2";
	};
	class Vietnam3_veh: Sound
	{
		author="Swurvin";
		_generalMacro="Vietnam3_veh";
		scope=2;
		sound="Vietnam3";
		displayName="[SWU] Vietnam Chatter 3";
	};
	class VietnamOpSoul_veh: Sound
	{
		author="Swurvin";
		_generalMacro="VietnamOpSoul_veh";
		scope=2;
		sound="VietnamOpSoul";
		displayName="[SWU] Operation Wandering Soul";
	};
	class VietnamHannah_veh: Sound
	{
		author="Swurvin";
		_generalMacro="VietnamHannah_vehh";
		scope=2;
		sound="VietnamHannoi";
		displayName="[SWU] Hannoi Hannah";
	};
	class MosqueCall_veh: Sound
	{
		author="Swurvin";
		_generalMacro="MosqueCall1_veh";
		scope=2;
		sound="MosqueCall";
		displayName="[SWU] Call to Prayer";
	};
	class MosqueCall2_veh: Sound
	{
		author="Swurvin";
		_generalMacro="MosqueCall2_veh";
		scope=2;
		sound="MosqueCall2";
		displayName="[SWU] Call to Prayer 2";
	};
	class IraqBombing_veh: Sound
	{
		author="Swurvin";
		_generalMacro="IraqBombing_veh";
		scope=2;
		sound="IraqBombing";
		displayName="[SWU] Iraq Night Bombing w/ Megaphone";
	};
	class CloseUSFirefight_veh: Sound
	{
		author="Swurvin";
		_generalMacro="CloseUSFirefight_veh";
		scope=2;
		sound="CloseUSFirefight";
		displayName="[SWU] US Forces Close Firefight";
	};
	class AfghanCitySounds_veh: Sound
	{
		author="Swurvin";
		_generalMacro="AfghanCitySounds_veh";
		scope=2;
		sound="AfghanCitySounds";
		displayName="[SWU] Afghan City Sounds";
	};
	class SAWGunner_veh: Sound
	{
		author="Swurvin";
		_generalMacro="SAWGunner_veh";
		scope=2;
		sound="SAWGunner";
		displayName="[SWU] US Saw Gunner w/voices";
	};
	class CODAmbience_veh: Sound
	{
		author="Swurvin";
		_generalMacro="CODAmbience_veh";
		scope=2;
		sound="CODAmbience";
		displayName="[SWU] Close Firefight Ambience";
	};
	class JakkuBattle_veh: Sound
	{
		author="Swurvin";
		_generalMacro="JakkuBattle_veh";
		scope=2;
		sound="JakkuBattle";
		displayName="[SWU] Star Wars - Jakku Ambience";
	};
	class JungleWar_veh: Sound
	{
		author="Swurvin";
		_generalMacro="JungleWar_veh";
		scope=2;
		sound="JungleWar";
		displayName="[SWU] Jungle Firefight";
	};
	class WW2Ambience_veh: Sound
	{
		author="Swurvin";
		_generalMacro="WW2Ambience_veh";
		scope=2;
		sound="WW2Ambience";
		displayName="[SWU] WW2 Early Morning Artillery";
	};
	class WW2Ambience2_veh: Sound
	{
		author="Swurvin";
		_generalMacro="WW2Ambience_veh";
		scope=2;
		sound="WW2Ambience2";
		displayName="[SWU] WW2 Distant Firefight Effects";
	};
	class WW2AirSiren_veh: Sound
	{
		author="Swurvin";
		_generalMacro="WW2AirSiren_veh";
		scope=2;
		sound="WW2AirSiren";
		displayName="[SWU] WW2 Air Raid Siren";
	};
	class WW2Churchill_veh: Sound
	{
		author="Swurvin";
		_generalMacro="WW2Ambience_veh";
		scope=2;
		sound="WW2Churchill";
		displayName="[SWU] Winston Churchill - We Will Never Surrender";
	};
	class WW2SoS_veh: Sound
	{
		author="Swurvin";
		_generalMacro="WW2SoS_veh";
		scope=2;
		sound="WW2SoS";
		displayName="[SWU] WW2 S.O.S Sound";
	};
	class WW2French_veh: Sound
	{
		author="Swurvin";
		_generalMacro="WW2French_veh";
		scope=2;
		sound="WW2French";
		displayName="[SWU] Saving Private Ryan - French Song (Edith Piaf)";
	};
	class WW2USRadio_veh: Sound
	{
		author="Swurvin";
		_generalMacro="WW2USRadio_veh";
		scope=2;
		sound="WW2USRadio";
		displayName="[SWU] WW2 US Radio Channel (low volume)";
	};
	class WW2Eisenhower_veh: Sound
	{
		author="Swurvin";
		_generalMacro="WW2Eisenhower_veh";
		scope=2;
		sound="WW2Eisenhower";
		displayName="[SWU] General Eisenhower - D-Day Speech";
	};
	class RUSRadio1: Sound
	{
		author="Swurvin";
		_generalMacro="RUSRadio1";
		scope=2;
		sound="RURadioChatter1";
		displayName="[SWU] Russian Radio Chatter (радиосвязь)";
	};
	class RUSRadio2: Sound
	{
		author="Swurvin";
		_generalMacro="RUSRadio2";
		scope=2;
		sound="RURadioChatter2";
		displayName="[SWU] Russian Radio Chatter 2 (радиосвязь)";
	};
	class RUSVoices1: Sound
	{
		author="Swurvin";
		_generalMacro="RUSVoices1";
		scope=2;
		sound="RUVoices";
		displayName="[SWU] Russian Voices (голоса)";
	};
	class UKRCombat: Sound
	{
		author="Swurvin";
		_generalMacro="UKRCombat";
		scope=2;
		sound="UkraineCombat";
		displayName="[SWU] Ukraine War Combat w/voices (военный бой Украины)";
	};
	class CheekiBreekiSFX: Sound
	{
		author="Swurvin";
		_generalMacro="CheekiBreekiSFX";
		scope=2;
		sound="CheekiBreeki";
		displayName="[SWU] Meet The Bandits";
	};
};
