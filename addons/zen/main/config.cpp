class CfgPatches
{
	class zen_main
	{
		name="ZEN - Main";
		units[]={};
		weapons[]={};
		requiredVersion=2.1400001;
		requiredAddons[]=
		{
			"cba_main"
		};
		author="$STR_zen_main_Author";
		authors[]=
		{
			"mharis001"
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
				"zen_main"
			};
		};
	};
};
class CfgSettings
{
	class CBA
	{
		class Versioning
		{
			class zen
			{
				class dependencies
				{
					CBA[]=
					{
						"cba_main",
						{3,16,0},
						"(true)"
					};
					ACE[]=
					{
						"zen_compat_ace",
						{1,15,1,36},
						"isClass (configFile >> 'CfgPatches' >> 'ace_main')"
					};
				};
			};
		};
	};
};
