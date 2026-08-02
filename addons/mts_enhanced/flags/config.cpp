class CfgPatches
{
	class mts_flags
	{
		name="mts - Flags";
		units[]={};
		weapons[]=
		{
			"mts_flags_white",
			"mts_flags_red",
			"mts_flags_blue",
			"mts_flags_green",
			"mts_flags_yellow",
			"mts_flags_orange",
			"mts_flags_purple",
			"mts_flags_black"
		};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main",
			"ace_flags"
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
class CfgWeapons
{
	class CBA_MiscItem_ItemInfo;
	class ace_flags_white;
	class mts_flags_white: ace_flags_white
	{
		scope=1;
		scopeCurator=0;
		scopeArsenal=0;
		author="$STR_mts_main_authors";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=3;
		};
	};
	class ace_flags_red;
	class mts_flags_red: ace_flags_red
	{
		scope=1;
		scopeCurator=0;
		scopeArsenal=0;
		author="$STR_mts_main_authors";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=3;
		};
	};
	class ace_flags_blue;
	class mts_flags_blue: ace_flags_blue
	{
		scope=1;
		scopeCurator=0;
		scopeArsenal=0;
		author="$STR_mts_main_authors";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=3;
		};
	};
	class ace_flags_green;
	class mts_flags_green: ace_flags_green
	{
		scope=1;
		scopeCurator=0;
		scopeArsenal=0;
		author="$STR_mts_main_authors";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=3;
		};
	};
	class ace_flags_yellow;
	class mts_flags_yellow: ace_flags_yellow
	{
		scope=1;
		scopeCurator=0;
		scopeArsenal=0;
		author="$STR_mts_main_authors";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=3;
		};
	};
	class ace_flags_orange;
	class mts_flags_orange: ace_flags_orange
	{
		scope=1;
		scopeCurator=0;
		scopeArsenal=0;
		author="$STR_mts_main_authors";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=3;
		};
	};
	class ace_flags_purple;
	class mts_flags_purple: ace_flags_purple
	{
		scope=1;
		scopeCurator=0;
		scopeArsenal=0;
		author="$STR_mts_main_authors";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=3;
		};
	};
	class ace_flags_black;
	class mts_flags_black: ace_flags_black
	{
		scope=1;
		scopeCurator=0;
		scopeArsenal=0;
		author="$STR_mts_main_authors";
		class ItemInfo: CBA_MiscItem_ItemInfo
		{
			mass=3;
		};
	};
};
