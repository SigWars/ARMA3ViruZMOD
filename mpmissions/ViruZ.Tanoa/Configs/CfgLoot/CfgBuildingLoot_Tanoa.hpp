//////////////////////////////////////////////////
//
//     ViruZ Mod BuildingLoot Tanoa
//     Version 1.0.1
//	   Author: Mateus "Mateuus" Rodrigues
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
		lootChance = 0.4;
		maxSpawns = 6;
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
		maxSpawns = 5;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Basic_Items"}

		};
		itemChance[] =	{
			0.04,	//Trash
			0.02,	//Food
			0.04,	//Drink
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
		MaxSpawns = 4;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Flashlights"},
			{"","Basic_Items"},
			{"","Mag_Pistols_Low"},
			{"","Pistols_Low"}

		};
		itemChance[] =	{
			0.05,	//Trash
			0.02,	//Food
			0.05,	//Drink
			0.03,	//Flashlights
			0.03,	//Basic items
			0.02,	//MAg_ArmasCivis
			0.01	//Armas Civis

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
		maxSpawns = 4;
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
			{"CUP_sgun_M1014","weapon"},
			{"CUP_8Rnd_B_Beneli_74Pellets","magazine"}
		};
		itemChance[] =	{
			0.06,	//Trash
			0.06,	//Food
			0.08,	//Drink
			0.04,	//Light backpacks
			0.06,	//Houseware items
			0.02,	//Eletronic items
			0.04,	//Flashlights
			0.04,	//Medical Lite
			0.05,	//Civilian glasses
			0.05,   //Civilian headgears
			0.05,   //Civilian clothes
			0.03,   //Pistols Low
			0.02,   //Mag_Pistols Low
			0.04,	//Knife
			0.02,	//M1014
			0.01	//Mag M1014
		};
	};

////////////////////////////////////////////////////////////////////////////////
	class Rustic_Residence: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer"
		};
		maxSpawns = 4;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Flashlights"},
			{"","Light_Backpacks"},
			{"","Houseware_Items"},
			{"","Medical_Lite"},								
			{"","Civilian_Glasses"},
			{"","Civilian_Headgears"},
			{"","Civilian_Clothes"},
			{"","Civilian_Vests"},
			{"","Tools"},
			{"CUP_srifle_LeeEnfield_rail","weapon"},
			{"CUP_10x_303_M","magazine"},
			{"","Survival_Items"}
		};
		itemChance[] =	{
			0.04,	//Trash
			0.05,	//Food
			0.07,	//Drink
			0.05,	//Flashlights
			0.05,	//Light backpacks
			0.05,	//Houseware items
			0.05,	//Medical lite
			0.05,	//Civilian glasses
			0.05,   //Civilian headgears
			0.05,   //Civilian clothes
			0.05,   //Civilian vests
			0.04,	//Tools
			0.03,	//Lee Enfield
			0.02,	//Mag Lee Enfield
			0.05	//Survival items
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
		maxSpawns = 5;
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
			{"CUP_sgun_M1014","weapon"},
			{"CUP_8Rnd_B_Beneli_74Pellets","magazine"},
			{"ItemKnife","magazine"}
		};
		itemChance[] =	{
			0.04,	//Trash
			0.05,	//Food
			0.07,	//Drink
			0.04,	//Flashlights
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
			0.03,   //Mag pistols low
			0.02,	//Shotgun M1014
			0.01,	//Mag M1014
			0.05	//Knife
		};
	};
	
////////////////////////////////////////////////////////////////////////////////
	class Big_Market: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer","VZ_Policeman"
		};
		lootChance = 0.8;
		MaxSpawns = 9;
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
			{"CUP_sgun_M1014","weapon"},
			{"CUP_8Rnd_B_Beneli_74Pellets","magazine"}
		};
		itemChance[] =	{
			0.03,	//Trash
			0.06,	//Food
			0.08,	//Drink
			0.04,	//Flashlights
			0.06,	//Houseware items
			0.05,	//Medical Lite
			0.03,   //Light backpacks
			0.01,   //Medium backpacks
			0.03,   //Pistols Low
			0.02,   //Mag pistols low
			0.03,	//Tools
			0.05,	//Knife
			0.01,	//Cardboard box
			0.01,	//Shotgun M1014
			0.01	//Mag M1014
		};
	};

////////////////////////////////////////////////////////////////////////////////
	class Small_Market: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4"
		};
		MaxSpawns = 6;
		lootPos[] = {};
		itemType[] =	{
			{"","Trash"},
			{"","Food"},
			{"","Drink"},
			{"","Houseware_Items"},								
			{"","Medical_Lite"},
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},
			{"ItemKnife","magazine"},
			{"Viruz_CardBoardBox","magazine"}
		};
		itemChance[] =	{
			0.03,	//Trash
			0.06,	//Food
			0.08,	//Drink
			0.06,	//Houseware items
			0.05,	//Medical Lite
			0.03,   //Pistols Low
			0.02,   //Mag pistols low
			0.05,	//Knife
			0.01	//Cardboard box
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
		maxSpawns = 5;
		lootPos[] = {};
		itemType[] =	{
			{"","Light_Backpacks"},
			{"","Medical_Lite"},
			{"","Eletronic_Items"},
			{"","Tools"},
			{"","Mag_Pistols_Low"},
			{"","Pistols_Low"}			
		};
		itemChance[] =	{
			0.05,	//Light backpacks
			0.06,	//Medical Lite
			0.03,	//Eletronic Items
			0.04,	//Tools
			0.02,	//Mag_Pistols_Low
			0.01	//Pistols_Low
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
		maxSpawns = 5;
		lootPos[] = {};
		itemType[] =	{
			{"","Light_Backpacks"},
			{"","Medium_Backpacks"},
			{"","Survival_Items"},
			{"","Military_Glasses"},
			{"","Military_Clothes"},
			{"","Military_Headgears"},
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},
			{"","Attach_Pistols_Low"},
			{"CUP_sgun_M1014","weapon"},
			{"CUP_8Rnd_B_Beneli_74Pellets","magazine"},
			{"CUP_8Rnd_B_Beneli_74Slug","magazine"},
			{"","SMG"},
			{"","Mag_SMG"},
			{"","Attach_SMG"}
		};
		itemChance[] =	{
			0.05,		//Light Backpacks
			0.03,		//Medium backpacks
			0.06,		//Survival_Items
			0.06,		//Military Glasses
			0.05,		//Military Clothes
			0.06,		//Military Headgears
			0.05,		//Pistols low
			0.05,		//Mag pistols low
			0.03,		//Attach pistols low
			0.03,		//Shotgun M1014
			0.02,		//Mag Shotgun M1014 Pellets
			0.02,		//Mag Shotgun M1014 Slug
			0.01,		//SMG
			0.01,		//Mag SMG
			0.01		//Attach SMG
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
		maxSpawns = 6;
		lootPos[] = {};
		itemType[] =	{
			{"","Pistols_High"},
			{"","Mag_Pistols_High"},
			{"","Attach_Pistols_High"},			
			{"","Military_Glasses"},
			{"","Military_Clothes"},
			{"","Military_Vests"},
			{"","Military_Headgears"},
			{"CUP_sgun_M1014","weapon"},
			{"CUP_8Rnd_B_Beneli_74Pellets","magazine"},
			{"CUP_8Rnd_B_Beneli_74Slug","magazine"},
			{"","Tools"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","magazine"},
			{"","Flashlights"}
		};
		itemChance[] =	{
			0.05,   //Pistols high
			0.04,   //Mag pistols high
			0.03,	//Attach Pistols High
			0.07,   //Military glasses
			0.07,   //Military clothes
			0.05,   //Military vests
			0.07,   //Military headgears
			0.04,	//Shotgun M1014
			0.02,	//Mag Shotgun M1014 Pellets
			0.02,	//Mag Shotgun M1014 Slug
			0.06,   //Tools
			0.06,   //Hatchet
			0.06,   //Knife
			0.05    //Flashlights
		};
	};

////////////////////////////////////////////////////////////////////////////////
	class Small_Office: Default {
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
		maxSpawns = 5;
		lootPos[] = {};
		itemType[] =	{
			{"","Empty_Drink"},
			{"","Drink"},
			{"","Light_Backpacks"},
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},			
			{"","Office_Items"},
			{"","Flashlights"}
		};
		itemChance[] =	{
			0.03,	//Empty Drink
			0.05,	//Drink
			0.03,	//Light backpacks
			0.02,	//Pistolas low
			0.01,	//Mag pistolas Low
			0.06,	//Office items
			0.03	//Flashlights
		};
	};

////////////////////////////////////////////////////////////////////////////////
	class Big_Office: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer","VZ_SchoolTeacher","VZ_Policeman"
		};
		maxRoaming = 3;
		lootPos[] = {};
		itemType[] =	{
			{"","Empty_Drink"},
			{"","Drink"},
			{"","Light_Backpacks"},
			{"","Pistols_Low"},
			{"","Mag_Pistols_Low"},			
			{"","Office_Items"},
			{"","Flashlights"}
		};
		itemChance[] =	{
			0.03,	//Empty Drink
			0.05,	//Drink
			0.03,	//Light backpacks
			0.02,	//Pistolas low
			0.01,	//Mag pistolas Low
			0.06,	//Office items
			0.03	//Flashlights
		};
	};
	
////////////////////////////////////////////////////////////////////////////////
	class Small_School: Default {
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
		maxSpawns = 5;
		lootPos[] = {};
		itemType[] =	{
			{"","School_Trash"},
			{"","Empty_Drink"},
			{"","Drink"},
			{"","Light_Backpacks"},
			{"","Office_Items"},
			{"","Flashlights"}
		};
		itemChance[] =	{
			0.03,	//School trash
			0.03,	//Empty Drink
			0.05,	//Drink
			0.05,	//Light backpacks
			0.05,	//Office items
			0.03	//Flashlights
		};
	};
	
////////////////////////////////////////////////////////////////////////////////
	class Big_School: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_boomer","VZ_SchoolTeacher","VZ_Policeman"
		};
		maxRoaming = 3;
		lootPos[] = {};
		itemType[] =	{
			{"","School_Trash"},
			{"","Empty_Drink"},
			{"","Drink"},
			{"","Light_Backpacks"},
			{"","Office_Items"},
			{"","Flashlights"}
		};
		itemChance[] =	{
			0.03,	//School trash
			0.03,	//Empty Drink
			0.05,	//Drink
			0.05,	//Light backpacks
			0.05,	//Office items
			0.03	//Flashlights
		};
	};
	
////////////////////////////////////////////////////////////////////////////////
	class Barn: Default {
		zombieClass[] = {
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4"
		};
		maxRoaming = 1;
		maxSpawns = 4;
		lootPos[] = {};
		itemType[] =	{
			{"CUP_srifle_LeeEnfield_rail","weapon"},
			{"CUP_10x_303_M","magazine"},
			{"","Tools"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","magazine"},
			{"","Flashlights"},
			{"","Basic_Items"},
			{"","Materials"},
			{"ItemJerrycan","magazine"}
		};
		itemChance[] =	{
			0.02,   //Lee Enfield
			0.01,   //Mag Lee Enfield
			0.03,   //Tools 
			0.06,   //Hatchet
			0.06,   //Knife
			0.04,   //Flashlights
			0.04,   //Basic items
			0.04,   //Materials
			0.04	//Jerrycan
		};
	};

////////////////////////////////////////////////////////////////////////////////
	class Tools_Shed: Default {
		maxRoaming = 1;
		lootChance = 0.4;
		maxSpawns = 3;
		lootPos[] = {};
		itemType[] =	{
			{"MeleeHatchet","weapon"},
			{"ItemWire","magazine"},
			{"","Tools"},
			{"ItemToolbox","magazine"}
		};
		itemChance[] =	{
			0.06,   //Hatchet
			0.06,   //Metal wire
			0.06,	//Tools
			0.01	//Tool box
		};
	};
	
////////////////////////////////////////////////////////////////////////////////
	class Workshop: Default {
		maxRoaming = 1;
		maxSpawns = 4;
		lootPos[] = {};
		itemType[] =	{
			{"","CarParts"},
			{"","Flashlights"},
			{"","Tools"},
			{"ItemToolbox","magazine"}
		};
		itemChance[] =	{
			0.06,   //Car parts
			0.04,	//Flashlights
			0.06,	//Tools
			0.01	//Tool box
		};
	};
	
////////////////////////////////////////////////////////////////////////////////
	class Factory: Default {
		maxRoaming = 2;
		maxSpawns = 4;
		lootPos[] = {};
		itemType[] =	{
			{"PartEngine","magazine"},
			{"ItemWire","magazine"},
			{"","Tools"}
		};
		itemChance[] =	{
			0.04,   //Engine
			0.05,   //Wire roll
			0.05	//Tools
		};
	};

////////////////////////////////////////////////////////////////////////////////
	class Hunt_Tower: Default {
		maxRoaming = 0;
		maxSpawns = 4;
		lootPos[] = {};
		itemType[] =	{
			{"ItemSodaBeergolden","magazine"},
			{"ItemWaterBottle","magazine"},
			{"ItemSodaBeergoldenEmpty","magazine"},
			{"ItemWaterbottleUnfilled","magazine"},
			{"FoodCanWBBeans","magazine"},
			{"FoodCanMHBeans","magazine"},
			{"FoodCanWBBeansEmpty","magazine"},
			{"FoodCanMHBeansEmpty","magazine"},
			{"ItemKnife","magazine"},
			{"CUP_srifle_LeeEnfield_rail","weapon"},
			{"CUP_10x_303_M","magazine"},
			{"Binocular","magazine"},
			{"HandFlashlight","weapon"},
			{"CUP_B_ACRScout_m95","backpack"}
		};
		itemChance[] =	{
			0.07,   //Beer can
			0.07,   //Canteen
			0.07,   //Empty beer can
			0.07,   //Empty canteen
			0.06,   //Can of beans
			0.06,   //Can of beans
			0.06,   //Empty can of beans
			0.06,   //Empty can of beans
			0.07,   //Knife
			0.03,   //Lee Enfield
			0.02,   //Mag Lee Enfield
			0.05,	//Binocular
			0.05,	//Viruz flashlight
			0.05	//Backpack
		};
	};
	
////////////////////////////////////////////////////////////////////////////////
	class Watch_Tower: Default {
		maxRoaming = 0;
		maxSpawns = 3;
		lootPos[] = {};
		itemType[] =	{
			{"ItemWaterBottle","magazine"},
			{"ItemWaterbottleUnfilled","magazine"},
			{"FoodMRE","magazine"},
			{"","Assault_Low"},
			{"","Mag_Assault_Low"},
			{"Binocular","magazine"}
		};
		itemChance[] =	{
			0.08,   //Canteen
			0.08,   //Empty canteen
			0.05,   //MRE
			0.03,   //Assault rifles low
			0.02,   //Mag assault rifles low
			0.07	//Binocular
		};
	};
	
////////////////////////////////////////////////////////////////////////////////
	class Construction: Default {
		maxRoaming = 3;
		maxSpawns = 9;
		lootPos[] = {};
		itemType[] =	{
			{"MeleeHatchet","weapon"},
			{"","Materials"},
			{"","Tools"}
		};
		itemChance[] =	{
			0.03,   //Hatchet
			0.08,   //Materials
			0.05	//Tools
		};
	};

////////////////////////////////////////////////////////////////////////////////
	class Pharmacy: Default {
		zombieClass[] = { "VZ_Doctor", "VZ_Assistant","VZ_Policeman"};
		maxRoaming = 1;
		maxSpawns = 4;
		lootPos[] = {};
		itemType[] =	{
			{"","Medical_Lite"},
			{"","Medical_Special"}
		};
		itemChance[] =	{
			0.08,	//Medical_Lite
			0.04	//Medical_Especial
		};
	};

////////////////////////////////////////////////////////////////////////////////
	class Hospital: Default {
		zombieClass[] = { "VZ_Doctor", "VZ_Assistant","VZ_Policeman"};
		lootChance = 0.4;
		maxSpawns = 5;
		lootPos[] = {};
		itemType[] =	{
			{"","Medical_Lite"},
			{"","Medical_Special"}
		};
		itemChance[] =	{
			0.08,	//Medical_Lite
			0.06	//Medical_Especial
		};
	};

/////////////////////////////////////////////////////////////////////////////
	class Hangar: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
		lootChance = 0.2;
		maxSpawns = 6;
		lootPos[] = {};
		itemType[] =	{
			{"","CarParts"},
			{"","Heliparts"}
		};
		itemChance[] =	{
			0.03,	//Car parts
			0.04	//Heli parts
		};
	};
	
/////////////////////////////////////////////////////////////////////////////
	class Basic_Military: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
		lootChance = 0.5;
		MaxSpawns = 5;
		lootPos[] = {};
		itemType[] =	{
			{"","Pistols_High"},
			{"","Mag_Pistols_High"},
			{"","Attach_Pistols_High"},
			{"","SMG"},
			{"","Mag_SMG"},
			{"","Attach_SMG"},
			{"","LMG_Low"},
			{"","Mag_LMG_Low"},
			{"","Attach_LMG_Low"},
			{"","Assault_Low"},
			{"","Mag_Assault_Low"},
			{"","Attach_Assault_Low"},
			{"","Sniper_Low"},
			{"","Mag_Sniper_Low"},
			{"","Attach_Sniper_Low"},
			{"","Military_Clothes"},
			{"","Military_Vests"},
			{"","Military_Headgears"},
			{"","Smoke_Grenades"},
			{"","Medium_Backpacks"},
			{"","Survival_Items"},
			{"FoodMRE","magazine"}
		};
		itemChance[] =	{
			0.08,	//Pistols High
			0.06,	//Mag Pistols High
			0.05,	//Attach Pistols High
			0.06,	//SMG
			0.04,	//Mag SMG
			0.03,	//Attach SMG
			0.04,	//LMG low
			0.02,	//Mag LMG low
			0.01,	//Attach LMG low
			0.03,	//Assault low
			0.02,	//Mag Assault low
			0.01,	//Attach Assault low
			0.02,	//Sniper low
			0.01,	//Mag Sniper low
			0.01,	//Attach Sniper low
			0.06, 	//Military Clothes
			0.04,	//Military Vests
			0.06,	//Military Headgears
			0.03,	//Smoke Grenades
			0.04,	//Medium Backpacks
			0.08,	//Survival Items
			0.04	//FoodMRE
		};
	};

/////////////////////////////////////////////////////////////////////////////
	class Medium_Military: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
		lootChance = 0.4;
		maxSpawns = 4;
		lootPos[] = {};
		itemType[] =	{
			{"","Pistols_High"},
			{"","Mag_Pistols_High"},
			{"","Attach_Pistols_High"},
			{"","LMG_Medium"},
			{"","Mag_LMG_Medium"},
			{"","Attach_LMG_Medium"},
			{"","Assault_Medium"},
			{"","Mag_Assault_Medium"},
			{"","Attach_Assault_Medium"},
			{"","Sniper_Medium"},
			{"","Mag_Sniper_Medium"},
			{"","Attach_Sniper_Medium"},
			{"","Military_Clothes"},
			{"","Military_Vests"},
			{"","Military_Headgears"},
			{"","Smoke_Grenades"},
			{"","Offensive_Grenades"},
			{"","Medium_Backpacks"},
			{"","Survival_Items"},
			{"FoodMRE","magazine"}
		};
		itemChance[] =	{
			0.09,	//Pistols High
			0.07,	//Mag Pistols High
			0.06,	//Attach Pistols High
			0.07,	//LMG Medium
			0.05,	//Mag LMG Medium
			0.04,	//Attach LMG Medium
			0.05,	//Assault Medium
			0.03,	//Mag Assault Medium
			0.02,	//Attach Assault Medium
			0.03,	//Sniper Medium
			0.01,	//Mag Sniper Medium
			0.01,	//Attach Sniper Medium
			0.05, 	//Military_Clothes
			0.05,	//Military_Vests
			0.05,	//Military_Headgears
			0.04,	//Smoke_Grenades
			0.02,	//Offensive_Grenades
			0.05,	//Medium_Backpacks
			0.07,	//Survival_Items
			0.05	//FoodMRE
		};
	};

/////////////////////////////////////////////////////////////////////////////
	class High_Military: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 1;
		maxRoaming = 2;
		lootChance = 0.3;
		maxSpawns = 6;
		lootPos[] = {};
		itemType[] =	{
			{"","Pistols_High"},
			{"","Mag_Pistols_High"},
			{"","Attach_Pistols_High"},
			{"","LMG_High"},
			{"","Mag_LMG_High"},
			{"","Attach_LMG_High"},
			{"","Assault_High"},
			{"","Mag_Assault_High"},
			{"","Attach_Assault_High"},
			{"","Sniper_High"},
			{"","Mag_Sniper_High"},
			{"","Attach_Sniper_High"},
			{"","Military_Clothes"},
			{"","Military_Vests"},
			{"","Military_Headgears"},
			{"","Heavy_Backpacks"},
			{"","Smoke_Grenades"},
			{"","Offensive_Grenades"},
			{"","Medium_Backpacks"},
			{"","Survival_Items"},
			{"FoodMRE","magazine"}
		};
		itemChance[] =	{
			0.09,	//Pistols High
			0.08,	//Mag Pistols High
			0.07,	//Attach Pistols High
			0.06,	//LMG High
			0.05,	//Mag LMG High
			0.04,	//Attach LMG High
			0.04,	//Assault High
			0.03,	//Mag Assault High
			0.02,	//Attach Assault High
			0.02,	//Sniper High
			0.01,	//Mag Sniper High
			0.01,	//Attach Sniper High
			0.05, 	//Military_Clothes
			0.05,	//Military_Vests
			0.05,	//Military_Headgears
			0.04,	//Heavy_Backpacks
			0.04,	//Smoke_Grenades
			0.03,	//Offensive_Grenades
			0.05,	//Medium_Backpacks
			0.06,	//Survival_Items
			0.05	//FoodMRE
		};
	};

/////////////////////////////////////////////////////////////////////////////
	class Military_Tower: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 1;
		maxRoaming = 2;
		lootChance = 0.4;
		maxSpawns = 4;
		lootPos[] = {};
		itemType[] =	{
			{"","Pistols_High"},
			{"","Mag_Pistols_High"},
			{"","Attach_Pistols_High"},
			{"","Sniper_Low"},
			{"","Mag_Sniper_Low"},
			{"","Attach_Sniper_Low"},
			{"","Sniper_Medium"},
			{"","Mag_Sniper_Medium"},
			{"","Attach_Sniper_Medium"},
			{"","Sniper_High"},
			{"","Mag_Sniper_High"},
			{"","Attach_Sniper_High"},
			{"Binocular","magazine"},
			{"ItemWaterBottle","magazine"},
			{"FoodMRE","magazine"}
		};
		itemChance[] =	{
			0.07,	//Pistols High
			0.06,	//Mag Pistols High
			0.04,	//Attach Pistols High
			0.05,	//Sniper Low
			0.04,	//Mag Sniper Low
			0.03,	//Attach Sniper Low
			0.04,	//Sniper Medium
			0.03,	//Mag Sniper Medium
			0.02,	//Attach Sniper Medium
			0.02,	//Sniper High
			0.01,	//Mag Sniper High
			0.01,	//Attach Sniper High
			0.08,	//Binocular
			0.08,	//Canteen
			0.08	//MRE
		};
	};
	
/////////////////////////////////////////////////////////////////////////////
	class Special_Military: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 1;
		maxRoaming = 2;
		lootChance = 0.3;
		maxSpawns = 5;
		lootPos[] = {};
		itemType[] =	{
			{"","Assault_High"},
			{"","Mag_Assault_High"},
			{"","Attach_Assault_High"},
			{"","MMG"},
			{"","Mag_MMG"},
			{"","Attach_MMG"},
			{"","Sniper_High"},
			{"","Mag_Sniper_High"},
			{"","Attach_Sniper_High"},
			{"","Heavy_Backpacks"},
			{"","Offensive_Grenades"}
		};
		itemChance[] =	{
			0.08,	//Assault High
			0.08,	//Mag Assault High
			0.06,	//Attach Assault High
			0.04,	//MMG
			0.04,	//Mag MMG
			0.02,	//Attach MMG
			0.02,	//Sniper High
			0.02,	//Mag Sniper High
			0.01,	//Attach Sniper High
			0.05,	//Heavy_Backpacks
			0.04	//Offensive_Grenades
		};
	};
////////////////////////////////////////////////////////////////////
//BuildingPos Chernarus
#include "CfgBuildingPos_Tanoa.hpp"
////////////////////////////////////////////////////////////////////	
#include "CfgHelicrash_ViruZ.hpp" // ViruZ HeliCrash Holder
	
};