class CfgPatches
{
	class mts_remove_snakes
	{
		name="mts - Remove_Snakes";
		units[]={};
		weapons[]={};
		requiredVersion=2.1800001;
		requiredAddons[]=
		{
			"mts_main"
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
class CfgWorlds
{
	class CAWorld;
	class Altis: CAWorld
	{
		class AmbientA3
		{
			class Radius40_60
			{
				class Species
				{
					class Snake_random_F
					{
						maxWorldCount=0;
					};
				};
			};
		};
	};
	class Stratis: CAWorld
	{
		class AmbientA3
		{
			class Radius40_60
			{
				class Species
				{
					class Snake_random_F
					{
						maxWorldCount=0;
					};
				};
			};
		};
	};
	class Malden: CAWorld
	{
		class AmbientA3
		{
			class Radius40_60
			{
				class Species
				{
					class Snake_random_F
					{
						maxWorldCount=0;
					};
				};
			};
		};
	};
};
class CfgVehicles
{
	class Animal;
	class Animal_Base_F: Animal
	{
		class EventHandlers;
	};
	class Snake_random_F: Animal_Base_F
	{
		class EventHandlers: EventHandlers
		{
			init="deleteVehicle (_this select 0);";
		};
	};
};
