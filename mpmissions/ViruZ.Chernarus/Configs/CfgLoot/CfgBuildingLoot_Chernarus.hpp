//////////////////////////////////////////////////
//
//     ViruZ Mod BuildingLoot Chernarus
//     Version 1.0.1
//	   Author: ViruZModTeam
//
//////////////////////////////////////////////////

#include "CfgLoot.hpp"

class CfgBuildingLoot {
	
	class Default {
		zombieChance = 0.3;
		minRoaming = 0;
		maxRoaming = 2;
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_Priest","VZ_Policeman","VZ_Doctor","VZ_Assistant",
			"VZ_SchoolTeacher","VZ_boomer"
		};
		lootChance = 0;
		maxSpawns = 5;
		lootPos[] = {};
		itemType[] = {};
		itemChance[] = {};
		hangPos[] = {};
		vehPos[] = {};
		isObjectHolder = 0;
		isBuildingPos = 0;
	};
	
	////////////////////////////////////////////////////////////////////////////////
	class Church: Default {
		zombieClass[] = {
			"VZ_Priest"
		};
		maxRoaming = 1;
		lootChance = 0.3;
		maxSpawns = 2;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Flashlights"},
			{"","Basic_Items"}

		};
		itemChance[] =	{
			0.04,	//Trash
			0.04,	//Food
			0.04,	//Drink
			0.03,	//Flashlights
			0.02	//Basic items

		};
	};
	////////////////////////////////////////////////////////////////////////////////
	class Restaurant: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer","VZ_Policeman"
		};
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Flashlights"},
			{"","Basic_Items"},
			{"","Mag_ArmasCivis"},
			{"","ArmasCivis"}

		};
		itemChance[] =	{
			0.04,	//Trash
			0.04,	//Food
			0.04,	//Drink
			0.03,	//Flashlights
			0.02,	//Basic items
			0.02,	//MAg_ArmasCivis
			0.02	//Armas Civis

		};
	};
		
	////////////////////////////////////////////////////////////////////////////////
	class Basic_Residence: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer"
		};
		maxRoaming = 1;
		lootChance = 0.3;
		maxSpawns = 2;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Light_Backpacks"},
			{"","Houseware_Items"},
			{"","Eletronic_Items"},
			{"","Flashlights"},
			{"","Medical_Lite"},
			{"","Civilian_Glasses"},
			{"","Civilian_Headgears"},
			{"","Civilian_Clothes"},
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},
			{"ItemKnife","magazine"},
			{"","Mag_ArmasCivis"},
			{"","ArmasCivis"}
			
		};
		itemChance[] =	{
			0.06,	//Trash
			0.08,	//Food
			0.08,	//Drink
			0.04,	//Light backpacks
			0.06,	//Houseware items
			0.03,	//Eletronic items
			0.06,	//Flashlights
			0.04,	//Medical Lite
			0.05,	//Civilian glasses
			0.05,   //Civilian headgears
			0.05,   //Civilian clothes
			0.02,   //Pistols Low
			0.02,   //Mag_Pistols Low
			0.04,	//Knife
			0.02,	//Mag_armasCivis
			0.02	//Armas Civis

		};
	};

	////////////////////////////////////////////////////////////////////////////////
	class Special_Residence: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer"
		};
		lootChance = 0.3;
		maxSpawns = 3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Flashlights"},
			{"","Light_Backpacks"},
			{"","Houseware_Items"},
			{"","Eletronic_Items"},
			{"","Medical_Lite"},								
			{"","Civilian_Glasses"},
			{"","Civilian_Headgears"},
			{"","Civilian_Clothes"},
			{"","Civilian_Vests"},
			{"","Tools"},
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},
			{"","ArmasCivis"},
			{"","Mag_ArmasCivis"},
			{"ItemKnife","magazine"}
			
		};
		itemChance[] =	{
			0.04,	//Trash
			0.07,	//Food
			0.07,	//Drink
			0.05,	//Flashlights
			0.05,	//Light backpacks
			0.06,	//Houseware items
			0.04,	//Eletronic items
			0.05,	//Medical lite
			0.05,	//Civilian glasses
			0.05,   //Civilian headgears
			0.05,   //Civilian clothes
			0.05,   //Civilian vests
			0.05,	//Tools
			0.04,   //Pistols low
			0.04,   //Mag pistols low
			0.02,	//Armas civis
			0.02,	//Mag armas civis
			0.05	//Knife
		};
	};
	
	////////////////////////////////////////////////////////////////////////////////
	class Market: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer","VZ_Policeman"
		};
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Flashlights"},						
			{"","Houseware_Items"},								
			{"","Medical_Lite"},
			{"","Light_Backpacks"},
			{"","Medium_Backpacks"},
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},
			{"","Tools"},
			{"ItemKnife","magazine"},
			{"Viruz_CardBoardBox","magazine"},
			{"","Mag_ArmasCivis"},
			{"","ArmasCivis"}
			
			
		};
		itemChance[] =	{
			0.03,	//Trash
			0.08,	//Food
			0.08,	//Drink
			0.04,	//Flashlights
			0.06,	//Houseware items
			0.05,	//Medical Lite
			0.03,   //Light backpacks
			0.01,   //Medium backpacks
			0.03,   //Pistols Low
			0.03,   //Mag pistols low
			0.03,	//Tools
			0.05,	//Knife
			0.01,	//Cardboard box
			0.01,	//Mag_Armascivis
			0.01	//Armas civis
		};
	};

	////////////////////////////////////////////////////////////////////////////////
	class Basic_Store: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer","VZ_Policeman"
		};
		maxRoaming = 1;
		lootChance = 0.3;
		maxSpawns = 3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Light_Backpacks"},
			{"","Medical_Lite"},
			{"","Tools"},
			{"","Mag_ArmasCivis"},
			{"","ArmasCivis"}
			
		};
		itemChance[] =	{
			0.04,	//Trash
			0.06,	//Food
			0.06,	//Drink
			0.03,	//Light backpacks
			0.06,	//Medical Lite
			0.03,	//Tools
			0.01,	//Mag_armascivis
			0.01	//ArmasCivis

		};
	};
	
	////////////////////////////////////////////////////////////////////////////////
	class Military_Store: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer","VZ_Policeman"
		};
		maxRoaming = 1;
		lootChance = 0.3;
		maxSpawns = 3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Light_Backpacks"},
			{"","Medium_Backpacks"},
			{"","Basic_Survival"},								
			{"","Military_Glasses"},
			{"","Military_Clothes"},
			{"","Military_Headgear"},			
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},
			{"","ArmasCivis"},
			{"","Mag_ArmasCivis"}
			
		};
		itemChance[] =	{
			0.05,	//Trash
			0.05,	//Light_Backpacks
			0.03,	//Medium backpacks
			0.07,	//Basic_Survival
			0.07,	//Military_Glasses
			0.05,	//Military_Clothes
			0.07,	//Military_Headgear
			0.05,	//Pistols low
			0.05,   //Mag pistols low
			0.03,   //Armas civis
			0.03	//Mag armas civis
		};
	};
	
	////////////////////////////////////////////////////////////////////////////////
	class Fire_Department: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer","VZ_Policeman"
		};
		minRoaming = 1;
		maxRoaming = 3;
		lootChance = 0.3;
		maxSpawns = 4;
		lootPos[] = {};
		itemType[] =	{
			//{"","Trash"},	
			{"","Pistols_High"},
			{"","Mag_Pistols_High"},			
			{"","Military_Glasses"},
			{"","Military_Clothes"},
			{"","Military_Vests"},
			{"","Military_Headgear"},
			{"","ArmasCivis"},
			{"","Mag_ArmasCivis"},
			{"","Tools"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","magazine"},
			{"","Flashlights"}
			
			
		};
		itemChance[] =	{
			//0.04,	//Trash
			0.05,   //Pistols high
			0.05,   //Mag pistols high
			0.07,   //Military glasses
			0.07,   //Military clothes
			0.05,   //Military vests
			0.07,   //Military headgear
			0.04,   //Armas civis
			0.04,   //Mag armas civis
			0.06,   //Tools
			0.06,   //Hatchet
			0.06,   //Knife
			0.05    //Flashlights
		};
	};

	////////////////////////////////////////////////////////////////////////////////
	class Office: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer","VZ_SchoolTeacher","VZ_Policeman"
		};
		maxRoaming = 1;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Drink"},
			{"","Light_Backpacks"},
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},			
			{"","Office_Items"},
			{"","Flashlights"}

		};
		itemChance[] =	{
			0.05,	//Trash
			0.05,	//Drink
			0.03,	//Light backpacks
			0.02,	//Pistolas low
			0.02,	//Mag pistolas Low
			0.06,	//Office items
			0.05	//Flashlights

		};
	};

	////////////////////////////////////////////////////////////////////////////////
	class Barn: Default {
		zombieClass[] = {
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4"
		};
		maxRoaming = 1;
		lootChance = 0.3;
		maxSpawns = 2;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","ArmasCivis"},
			{"","Mag_ArmasCivis"},
			{"","Tools"},
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","magazine"},
			{"","Flashlights"},
			{"","Basic_Items"},
			{"","Materials"},
			{"ItemJerrycan","magazine"}

		};
		itemChance[] =	{
			0.03,	//Trash
			0.02,   //ArmasCivis
			0.02,   //Mag_ArmasCivis
			0.03,   //Tools 
			0.03,   //PistolasLow
			0.03,   //Mag_PistolasLow
			0.06,   //Hatchet
			0.06,   //Knife
			0.04,   //Flashlights
			0.04,   //Basic items
			0.04,   //Materials
			0.04	//Jerrycan
			
		};
	};

	////////////////////////////////////////////////////////////////////////////////
	class Factory: Default {
		maxRoaming = 1;
		lootChance = 0.2;
		maxSpawns = 3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","CarParts"},
			{"","Materials"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","magazine"},
			{"","Flashlights"},
			{"","Tools"}

		};
		itemChance[] =	{
			0.03,	//Trash
			0.05,   //Car parts
			0.05,   //Materials
			0.04,   //Hatchet
			0.04,   //Knife
			0.04,	//Flashlights
			0.05	//Tools

		};
	};
	
	////////////////////////////////////////////////////////////////////////////////
	class Construction: Default {
		maxRoaming = 3;
		lootChance = 0.3;
		maxSpawns = 7;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","CarParts"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","magazine"},
			{"","Flashlights"},
			{"","Materials"},
			{"","Tools"}

		};
		itemChance[] =	{
			0.03,	//Trash
			0.03,   //Car parts
			0.03,   //Hatchet
			0.03,   //Knife
			0.03,   //Flashlights
			0.07,   //Materials
			0.05	//Tools

		};
	};

	////////////////////////////////////////////////////////////////////////////////
	class Pharmacy: Default {
		zombieClass[] = { "VZ_Doctor", "VZ_Assistant","VZ_Policeman"};
		maxRoaming = 1;
		maxSpawns = 2;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Medical_Lite"},
			{"","Medical_Special"}
		};
		itemChance[] =	{
			0.03,	//lixo
			0.08,	//Medical_Lite
			0.04	//Medical_Especial
		};
	};

	class Hospital: Default {
		zombieClass[] = { "VZ_Doctor", "VZ_Assistant","VZ_Policeman"};
		lootChance = 0.4;
		maxSpawns = 4;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Medical_Lite"},
			{"","Medical_Special"}
		};
		itemChance[] =	{
			0.03,	//lixo
			0.08,	//Medical_Lite
			0.06	//Medical_Especial
		};
	};

	/////////////////////////////////////////////////////////////////////////////
	class Hangar: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
		lootChance = 0.3;
		maxSpawns = 3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","CarParts"},
			{"","Heliparts"}

		};
		itemChance[] =	{
			0.02,	//Trash
			0.03,	//Car parts
			0.04	//Heli parts

		};
	};
	
	/////////////////////////////////////////////////////////////////////////////
	class Basic_Military: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			//{"","Trash"},
			{"","Pistols_High"},
			{"","Mag_Pistols_High"},
			{"","ArmasMedias"},
			{"","Mag_ArmasMedias"},
			{"","Military_Clothes"},
			{"","Military_Vests"},
			{"","Military_Headgear"},
			{"","Smoke_Grenades"},
			{"","Medium_Backpacks"},
			{"","Basic_Survival"},
			{"","Survival_Items"},
			{"FoodMRE","magazine"}
			
		};
		itemChance[] =	{
			//0.04,	//Trash
			0.05,	//PistolasMedias
			0.05,	//Mag_PistolasMedias
			0.03,	//ArmasMedias
			0.03,	//Mag_ArmasMedias
			0.06, 	//Military_Clothes
			0.04,	//Military_Vests
			0.06,	//Military_Headgear
			0.03,	//Smoke_Grenades
			0.04,	//Medium_Backpacks
			0.08,	//Basic_Survival
			0.08,	//Survival_Items
			0.04	//FoodMRE
			
		};
	};

	/////////////////////////////////////////////////////////////////////////////
	class Medium_Military: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
		lootChance = 0.3;
		maxSpawns = 3;
		lootPos[] = {};
		itemType[] =	{
			//{"","Trash"},
			{"","Pistols_High"},
			{"","Mag_Pistols_High"},
			{"","ArmasMedias"},
			{"","Mag_ArmasMedias"},
			{"","Acessorios_Optic"},
			{"","Military_Clothes"},
			{"","Military_Vests"},
			{"","Military_Headgear"},
			{"","Smoke_Grenades"},
			{"","Offensive_Grenades"},
			{"","Medium_Backpacks"},
			{"","Basic_Survival"},
			{"","Survival_Items"},
			{"FoodMRE","magazine"}
			
		};
		itemChance[] =	{
			//0.04,	//Trash
			0.06,	//PistolasMedias
			0.06,	//Mag_PistolasMedias
			0.05,	//ArmasMedias
			0.05,	//Mag_ArmasMedias
			0.04,	//Acessorios_Optic
			0.05, 	//Military_Clothes
			0.05,	//Military_Vests
			0.05,	//Military_Headgear
			0.04,	//Smoke_Grenades
			0.02,	//Offensive_Grenades
			0.05,	//Medium_Backpacks
			0.07,	//Basic_Survival
			0.07,	//Survival_Items
			0.05	//FoodMRE
			
		};
	};

	/////////////////////////////////////////////////////////////////////////////
	class Special_Military: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 1;
		maxRoaming = 2;
		lootChance = 0.3;
		maxSpawns = 3;
		lootPos[] = {};
		itemType[] =	{
			//{"","Trash"},
			{"","Pistols_High"},
			{"","Mag_Pistols_High"},
			{"","ArmasHigh"},
			{"","Mag_ArmasHigh"},
			{"","Acessorios_Optic"},
			{"","Military_Clothes"},
			{"","Military_Vests"},
			{"","Military_Headgear"},
			{"","Heavy_Backpacks"},
			{"","Smoke_Grenades"},
			{"","Offensive_Grenades"},
			{"","Medium_Backpacks"},
			{"","Basic_Survival"},
			{"","Survival_Items"},
			{"FoodMRE","magazine"}

		};
		itemChance[] =	{
		//	0.03,	//Trash
			0.05,	//PistolasHigh
			0.05,	//Mag_PistolasHigh
			0.03,	//ArmasHigh
			0.03,	//Mag_ArmasHigh
			0.04,	//Acessorios_Optic
			0.05, 	//Military_Clothes
			0.05,	//Military_Vests
			0.05,	//Military_Headgear
			0.03,	//Heavy_Backpacks
			0.04,	//Smoke_Grenades
			0.03,	//Offensive_Grenades
			0.05,	//Medium_Backpacks
			0.06,	//Basic_Survival
			0.06,	//Survival_Items
			0.05	//FoodMRE
			
		};
	};
	
////////////////////////////////////////////////////////////////////
//BuildingPos Chernarus
#include "CfgBuildingPos_Chernarus.hpp"
////////////////////////////////////////////////////////////////////	
#include "CfgHelicrash_ViruZ.hpp" // ViruZ HeliCrash Holder
	
};