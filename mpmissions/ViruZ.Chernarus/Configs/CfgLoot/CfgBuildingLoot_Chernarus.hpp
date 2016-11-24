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
			"VZ_Citizen1",
			"VZ_Citizen2",
			"VZ_Citizen3",
			"VZ_Citizen4",
			"VZ_Worker1",
			"VZ_Worker2",
			"VZ_Worker3",
			"VZ_Worker4",
			"VZ_Profiteer1",
			"VZ_Profiteer2",
			"VZ_Profiteer3",
			"VZ_Profiteer4",
			"VZ_Woodlander1",
			"VZ_Woodlander2",
			"VZ_Woodlander3",
			"VZ_Woodlander4",
			"VZ_Functionary1",
			"VZ_Functionary2",
			"VZ_Villager1",
			"VZ_Villager2",
			"VZ_Villager3",
			"VZ_Villager4",
			"VZ_Priest",
			"VZ_Policeman",
			"VZ_Doctor",
			"VZ_Assistant",
			"VZ_SchoolTeacher"
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
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.3;
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
			"VZ_Citizen1",
			"VZ_Citizen2",
			"VZ_Citizen3",
			"VZ_Citizen4",
			"VZ_Worker1",
			"VZ_Worker2",
			"VZ_Worker3",
			"VZ_Worker4",
			"VZ_Profiteer1",
			"VZ_Profiteer2",
			"VZ_Profiteer3",
			"VZ_Profiteer4",
			"VZ_Woodlander1",
			"VZ_Woodlander2",
			"VZ_Woodlander3",
			"VZ_Woodlander4",
			"VZ_Functionary1",
			"VZ_Functionary2",
			"VZ_Villager1",
			"VZ_Villager2",
			"VZ_Villager3",
			"VZ_Villager4"
		};
		minRoaming = 0;
		maxRoaming = 2;
		lootChance = 0.3;
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
	class Basic_Residence: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Light_Backpacks"},
			{"","Basic_Items"},						
			{"","Flashlights"},								
			{"","Medical_Lite"},	
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},
			{"ItemKnife","weapon"},
			{"","Residence_Items"}
			
		};
		itemChance[] =	{
			0.06,	//Trash
			0.08,	//Food
			0.08,	//Drink
			0.04,	//Light backpacks
			0.06,	//Basic items
			0.06,	//Flashlights
			0.04,	//Medical Lite
			0.02,   //PistolasLow
			0.02,   //Mag_PistolasLow
			0.06,	//Knife
			0.04	//Residence Items
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
			"VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Light_Backpacks"},
			{"","Residence_Items"},						
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
			{"ItemKnife","weapon"}			
			
		};
		itemChance[] =	{
			0.04,	//Trash
			0.08,	//Food
			0.08,	//Drink
			0.05,	//Light backpacks
			0.06,	//Residence items
			0.05,	//Medical lite
			0.05,	//Civilian glasses
			0.05,   //Civilian headgears
			0.05,   //Civilian clothes
			0.05,   //Civilian vests
			0.05,	//Tools
			0.04,   //Pistolas low
			0.04,   //Mag pistolas low
			0.03,	//Armas civis
			0.03,	//Mag armas civis
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
			"VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.3;
		lootPos[] = {};
		maxSpawns = 7;
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Basic_Items"},
			{"","Flashlights"},						
			{"","Residence_Items"},								
			{"","Medical_Lite"},
			{"","Light_Backpacks"},
			{"","Medium_Backpacks"},
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},
			{"","Basic_Survival"},
			{"","Survival_Items"},
			{"","Tools"},
			{"ItemKnife","weapon"}
			
		};
		itemChance[] =	{
			0.03,	//Trash
			0.08,	//Food
			0.08,	//Drink
			0.06,	//Basic items
			0.06,	//Flashlights
			0.05,	//Residence items
			0.05,	//Medical Lite
			0.04,   //Light backpacks
			0.02,   //Medium backpacks
			0.03,   //PistolasLow
			0.03,   //Mag pistolas low
			0.04,   //Basic survival
			0.03,	//Survival items
			0.03,	//Tools
			0.05	//Knife
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
			"VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Light_Backpacks"},
			{"","Basic_Items"},
			{"","Medical_Lite"},
			{"","Tools"},
			{"","Basic_Survival"}
			
		};
		itemChance[] =	{
			0.04,	//Trash
			0.06,	//Food
			0.06,	//Drink
			0.04,	//Light backpacks
			0.06,	//Basic items
			0.06,	//Medical Lite
			0.06,	//Tools
			0.04	//Basic Survival

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
			"VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Light_Backpacks"},
			{"","Basic_Items"},						
			{"","Basic_Survival"},								
			{"","Military_Glasses"},
			{"","Military_Clothes"},
			{"","Military_Headgear"},			
			{"","Civilian_Special"},
			{"","ArmasCivis"},
			{"","Mag_ArmasCivis"},
			{"ItemKnife","weapon"},
			{"","Medium_Backpacks"}
			
		};
		itemChance[] =	{
			0.04,	//Trash
			0.07,	//Light_Backpacks
			0.08,	//Basic_Items
			0.03,	//Basic_Survival
			0.06,	//Military_Glasses
			0.07,	//Military_Clothes
			0.04,	//Military_Headgear
			0.02,   //Civilian_Special
			0.03,   //Mag_Pistolas low
			0.02,   //Armas civis
			0.02,   //Mag_armas civis
			0.06    //Knife 
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
			"VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},	
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
			{"ItemKnife","weapon"},
			{"","Flashlights"}
			
			
		};
		itemChance[] =	{
			0.04,	//Trash
			0.05,   //PistolasMedias
			0.05,   //Mag_PistolasMedias
			0.07,   //Military_Glasses
			0.07,   //Military_Clothes
			0.07,   //Military_Vests
			0.07,   //Military_Headgear
			0.04,   //ArmasCivis
			0.04,   //Mag_ArmasCivis
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
			"VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig","VZ_Priest",
			"VZ_boomer","VZ_SchoolTeacher"
		};
		minRoaming = 0;
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
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4","VZ_Priest"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","ArmasCivis"},
			{"","Mag_ArmasCivis"},
			{"","Tools"},
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},			
			{"MeleeHatchet","weapon"},
			{"ItemKnife","weapon"},
			{"","Flashlights"},
			{"","Basic_Items"},
			{"","Materials"},
			{"ItemJerrycan","magazine"}
			
			
		};
		itemChance[] =	{
			0.03,	//Trash
			0.03,   //ArmasCivis
			0.03,   //Mag_ArmasCivis
			0.03,   //Tools 
			0.03,   //PistolasLow
			0.03,   //Mag_PistolasLow
			0.06,   //Hatchet
			0.06,   //Knife
			0.04,   //Flashlights
			0.04,   //Basic items
			0.04,   //Materials
			0.04   //Jerrycan
			
		};
	};

	////////////////////////////////////////////////////////////////////////////////
	class Factory: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig","VZ_Priest",
			"VZ_boomer","VZ_SchoolTeacher"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},		
			{"","CarParts"},
			{"","Materials"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","weapon"},
			{"","Flashlights"},
			{"","Tools"},
			{"","Basic_Items"}
			
		};
		itemChance[] =	{
			0.03,	//Trash
			0.05,   //Car parts
			0.05,   //Materials
			0.04,   //Hatchet
			0.04,   //Knife
			0.04,	//Flashlights
			0.05,	//Tools
			0.04	//Basic items

		};
	};
	
	////////////////////////////////////////////////////////////////////////////////
	class Construction: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig","VZ_Priest",
			"VZ_boomer","VZ_SchoolTeacher"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},		
			{"","CarParts"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","weapon"},
			{"","Flashlights"},
			{"","Basic_Items"},
			{"","Materials"},
			{"","Tools"}
						
		};
		itemChance[] =	{
			0.03,	//Trash
			0.05,   //Car parts
			0.05,   //Hatchet
			0.05,   //Knife
			0.03,   //Flashlights
			0.03,   //Basic items
			0.07,   //Materials
			0.05	//Tools
		
		};
	};


	////////////////////////////////////////////////////////////////////////////////
	class Hospital: Default {
		zombieChance = 0.3;
		zombieClass[] = { "VZ_Doctor", "VZ_Assistant"};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.4;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Medical_Lite"},
			{"","Medical_Special"}
		};
		itemChance[] =	{
			0.03,	//lixo
			0.08,	//Medical_Lite
			0.05	//Medical_Especial
		};
	};

	/////////////////////////////////////////////////////////////////////////////
	class Hangar: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 0;
		maxRoaming = 2;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","CarParts"},
			{"","Pistols_High"},
			{"","Mag_Pistols_High"},
			{"","ArmasMedias"},
			{"","Mag_ArmasMedias"}

			
		};
		itemChance[] =	{
			0.02,	//Trash
			0.05,	//Car parts
			0.04,	//PistolasMedias
			0.03,	//Mag_PistolasMedias
			0.03,	//ArmasMedias
			0.04	//Mag_ArmasMedias
			
		};
	};
	
	/////////////////////////////////////////////////////////////////////////////
	class Basic_Military: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 0;
		maxRoaming = 2;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
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
			0.03,	//Trash
			0.04,	//PistolasMedias
			0.04,	//Mag_PistolasMedias
			0.03,	//ArmasMedias
			0.03,	//Mag_ArmasMedias
			0.06, 	//Military_Clothes
			0.06,	//Military_Vests
			0.06,	//Military_Headgear
			0.03,	//Smoke_Grenades
			0.04,	//Medium_Backpacks
			0.08,	//Basic_Survival
			0.08,	//Survival_Items
			0.03	//FoodMRE
			
		};
	};

	/////////////////////////////////////////////////////////////////////////////
	class Medium_Military: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 0;
		maxRoaming = 2;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
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
			0.02,	//Trash
			0.06,	//PistolasMedias
			0.06,	//Mag_PistolasMedias
			0.05,	//ArmasMedias
			0.05,	//Mag_ArmasMedias
			0.04,	//Acessorios_Optic
			0.05, 	//Military_Clothes
			0.05,	//Military_Vests
			0.05,	//Military_Headgear
			0.03,	//Smoke_Grenades
			0.03,	//Offensive_Grenades
			0.05,	//Medium_Backpacks
			0.08,	//Basic_Survival
			0.08,	//Survival_Items
			0.03	//FoodMRE
			
		};
	};

	/////////////////////////////////////////////////////////////////////////////
	class Special_Military: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 0;
		maxRoaming = 2;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
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
			0.03,	//Trash
			0.04,	//PistolasHigh
			0.04,	//Mag_PistolasHigh
			0.03,	//ArmasHigh
			0.03,	//Mag_ArmasHigh
			0.03,	//Acessorios_Optic
			0.05, 	//Military_Clothes
			0.05,	//Military_Vests
			0.05,	//Military_Headgear
			0.03,	//Heavy_Backpacks
			0.04,	//Smoke_Grenades
			0.03,	//Offensive_Grenades
			0.05,	//Medium_Backpacks
			0.06,	//Basic_Survival
			0.06,	//Survival_Items
			0.03	//FoodMRE
			
		};
	};
	
////////////////////////////////////////////////////////////////////
//BuildingPos Chernarus
#include "CfgBuildingPos_Chernarus.hpp"
////////////////////////////////////////////////////////////////////	
#include "CfgHelicrash_ViruZ.hpp" // ViruZ HeliCrash Holder
	
};