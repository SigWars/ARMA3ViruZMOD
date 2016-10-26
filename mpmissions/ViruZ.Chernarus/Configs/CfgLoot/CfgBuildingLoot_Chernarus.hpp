//////////////////////////////////////////////////
//
//     ViruZ Mod BuildingLoot Chernarus
//     Version 1.0.1
//	   Author: ViruZModTeam
//
///////////////////////////////////////////////////

#include "CfgLoot.hpp"

class CfgBuildingLoot {
	
	class Default {
		zombieChance = 0.2;
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
		lootPos[] = {};
		itemType[] = {};
		itemChance[] = {};
		hangPos[] = {};
		vehPos[] = {};
		isObjectHolder = 0;
		isBuildingPos = 1;
	};
	
	class Master {
		weapons[] = {
			"launch_NLAW_F",
			"launch_RPG32_F"
		};
	};
	////////////////////////////////////////////////////////////////////////////////
	class Igrejas: Default {
		zombieClass[] = {
			"VZ_Priest"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","Comidas"},
			{"","Bebidas"},
			{"","MochilasLow"},
			{"","CraftItens"},						
			{"","Items_Magazine"},								
			{"","Medical_Lite"},	
			{"","PistolasLow"},
			{"","Mag_PistolasLow"},			
			{"","RoupasLow"}	
			
		};
		itemChance[] =	{
			0.05,	//Lixos
			0.03,	//Comidas
			0.04,	//Bebidas
			0.03,	//MochilasLow
			0.03,	//CraftItens
			0.03,	//Itens
			0.02,	//Medical Lite
			0.02,   //PistolasLow
			0.02,   //Mag_PistolasLow
			0.06    //RoupasLow	
		};
	};
	
	////////////////////////////////////////////////////////////////////////////////
	class CasaCivilsLow: Default {
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
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","Comidas"},
			{"","Bebidas"},
			{"","MochilasLow"},
			{"","CraftItens"},						
			{"","Items_Magazine"},								
			{"","Medical_Lite"},	
			{"","PistolasLow"},
			{"","Mag_PistolasLow"},			
			{"","RoupasLow"}	
			
		};
		itemChance[] =	{
			0.05,	//Lixos
			0.03,	//Comidas
			0.04,	//Bebidas
			0.03,	//MochilasLow
			0.03,	//CraftItens
			0.03,	//Itens
			0.02,	//Medical Lite
			0.02,   //PistolasLow
			0.02,   //Mag_PistolasLow
			0.06    //RoupasLow	
		};
	};
	////////////////////////////////////////////////////////////////////////////////
	class CasaCivilUpper: Default {
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
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","Comidas"},
			{"","Bebidas"},
			{"","MochilasMedias"},
			{"","CraftItens"},						
			{"","Items_Magazine"},								
			{"","Medical_Lite"},	
			{"","PistolasMedias"},
			{"","Mag_PistolasMedias"},			
			{"","RoupasUpper"},
			{"","ArmasCivis"},
			{"","Mag_ArmasCivis"}
			
			
		};
		itemChance[] =	{
			0.05,	//Lixos
			0.03,	//Comidas
			0.04,	//Bebidas
			0.03,	//MochilasMedias
			0.03,	//CraftItens
			0.03,	//Itens
			0.02,	//Medical Lite
			0.03,   //PistolasMedias
			0.03,   //Mag_PistolasMedias
			0.06,   //RoupasUpper	
			0.03,    //ArmasCivis
			0.04     //Mag_ArmasCivis
		};
	};
	
	////////////////////////////////////////////////////////////////////////////////
	class Mercados: Default {
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
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","Comidas"},
			{"","Bebidas"},
			{"","MochilasMedias"},
			{"","CraftItens"},						
			{"","Items_Magazine"},								
			{"","Medical_Lite"},	
			{"","PistolasLow"},
			{"","Mag_PistolasLow"},	
			{"ItemCompass","item"},
			{"Binocular","item"},			
			{"","RoupasUpper"}	
			
		};
		itemChance[] =	{
			0.05,	//Lixos
			0.03,	//Comidas
			0.04,	//Bebidas
			0.03,	//MochilasMedias
			0.03,	//CraftItens
			0.03,	//Itens
			0.02,	//Medical Lite
			0.02,   //PistolasLow
			0.02,   //Mag_PistolasLow
			0.04,   //ItemCompass
			0.04,   //Binocular
			0.06    //RoupasUpper	
		};
	};
	////////////////////////////////////////////////////////////////////////////////
	class Restaurantes: Default {
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
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","Comidas"},
			{"","Bebidas"},
			{"","MochilasMedias"},
			{"","CraftItens"},						
			{"","Items_Magazine"},								
			{"","Medical_Lite"},	
			{"","PistolasMedias"},
			{"","Mag_PistolasMedias"},			
			{"","RoupasUpper"},
			{"","ArmasCivis"},
			{"","Mag_ArmasCivis"},
			{"ItemCompass","item"},
			{"Binocular","item"},
			{"","Ferramentas"}
			
		};
		itemChance[] =	{
			0.05,	//Lixos
			0.03,	//Comidas
			0.04,	//Bebidas
			0.03,	//MochilasMedias
			0.03,	//CraftItens
			0.03,	//Itens
			0.02,	//Medical Lite
			0.02,   //PistolasMedias
			0.02,   //Mag_PistolasMedias
			0.06,   //RoupasUpper
			0.02,   //ArmasCivis
			0.03,   //Mag_ArmasCivis
			0.04,   //ItemCompass
			0.04,   //Binocular
			0.03    //Ferramentas 
		};
	};
	////////////////////////////////////////////////////////////////////////////////
	class Bombeiros: Default {
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
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},	
			{"","PistolasMedias"},
			{"","Mag_PistolasMedias"},			
			{"","RoupasUpper"},
			{"","ArmasCivis"},
			{"","Mag_ArmasCivis"},
			{"","Ferramentas"},
			{"ItemETool","item"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","weapon"},
			{"HandFlashlight","weapon"}
			
			
		};
		itemChance[] =	{
			0.05,	//Lixos
			0.02,   //PistolasMedias
			0.02,   //Mag_PistolasMedias
			0.06,   //RoupasUpper
			0.02,   //ArmasCivis
			0.03,   //Mag_ArmasCivis
			0.03,   //Ferramentas 
			0.04,   //ItemETool 
			0.05,   //Machado
			0.06,   //Faca
			0.04    //Lanterna
		};
	};
	////////////////////////////////////////////////////////////////////////////////
	class Escolas: Default {
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
			{"","trash"},	
			{"","MochilasMedias"},
			{"","PistolasLow"},
			{"","Mag_PistolasLow"},			
			{"","RoupasUpper"},
			{"ItemKnife","weapon"},
			{"HandFlashlight","weapon"}
			
			
		};
		itemChance[] =	{
			0.05,	//Lixos
			0.03,	//MochilasMedias
			0.02,   //PistolasLow
			0.02,   //Mag_PistolasLow
			0.06,   //RoupasUpper
			0.06,   //Faca
			0.04    //Lanterna
		};
	};
	////////////////////////////////////////////////////////////////////////////////
	class Celeiros: Default {
		zombieClass[] = {
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4","VZ_Priest"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},	
			{"","Comidas"},
			{"","Bebidas"},
			{"","ArmasCivis"},
			{"","Mag_ArmasCivis"},
			{"","Ferramentas"},
			{"","PistolasLow"},
			{"","Mag_PistolasLow"},			
			{"","RoupasUpper"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","weapon"},
			{"HandFlashlight","weapon"},
			{"","CraftBuildItens"},
			{"","Items_Magazine"},
			{"","CraftItens"},
			{"ItemTent","magazine"},
			{"ItemSandbag","item"},
			{"ItemJerrycan","magazine"}
			
			
		};
		itemChance[] =	{
			0.05,	//Lixos
			0.03,	//Comidas
			0.04,	//Bebidas
			0.02,   //ArmasCivis
			0.03,   //Mag_ArmasCivis
			0.03,   //Ferramentas 
			0.02,   //PistolasLow
			0.02,   //Mag_PistolasLow
			0.06,   //RoupasUpper
			0.05,   //Machado
			0.06,   //Faca
			0.04,   //Lanterna
			0.03,   //CraftBuildItens
			0.04,   //Items_Magazine
			0.04,   //CraftItens
			0.03,   //ItemTent
			0.04,   //ItemSandbag
			0.05    //ItemJerrycan
		};
	};
	////////////////////////////////////////////////////////////////////////////////
	class CeleirosBig: Default {
		zombieClass[] = {
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4","VZ_Priest"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},	
			{"","Comidas"},
			{"","Bebidas"},
			{"","MochilasLow"},
			{"","ArmasCivis"},
			{"","Mag_ArmasCivis"},
			{"","PistolasLow"},
			{"","Mag_PistolasLow"},			
			{"","RoupasLow"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","weapon"},
			{"HandFlashlight","weapon"},
			{"","CraftBuildItens"},
			{"","Items_Magazine"},
			{"","CraftItens"},
			{"ItemTent","magazine"},
			{"ItemETool","item"},
			{"ItemSandbag","item"},
			{"ItemJerrycan","magazine"}
			
			
		};
		itemChance[] =	{
			0.05,	//Lixos
			0.03,	//Comidas
			0.04,	//Bebidas
			0.03,   //MochilasLow
			0.02,   //ArmasCivis
			0.03,   //Mag_ArmasCivis
			0.02,   //PistolasLow
			0.02,   //Mag_PistolasLow
			0.06,   //RoupasLow
			0.05,   //Machado
			0.06,   //Faca
			0.04,   //Lanterna
			0.03,   //CraftBuildItens
			0.04,   //Items_Magazine
			0.04,   //CraftItens
			0.03,   //ItemTent
			0.04,   //ItemETool
			0.04,   //ItemSandbag
			0.05    //ItemJerrycan
		};
	};
	
	////////////////////////////////////////////////////////////////////////////////
	class Industriais: Default {
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
			{"","trash"},		
			{"","CarParts"},
			{"","Boat_Backpack"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","weapon"},
			{"HandFlashlight","weapon"},
			{"","Items_Magazine"},
			{"","CraftItens"}
			
		};
		itemChance[] =	{
			0.06,	//Lixos
			0.05,   //CarParts
			0.02,   //Boat_Backpack
			0.04,   //Machado
			0.06,   //Faca
			0.04,   //Lanterna
			0.04,   //Items_Magazine
			0.04    //CraftItens
		};
	};
	
	////////////////////////////////////////////////////////////////////////////////
	class Fabricas: Default {
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
			{"","trash"},		
			{"","CarParts"},
			{"","Boat_Backpack"},
			{"MeleeHatchet","weapon"},
			{"ItemKnife","weapon"},
			{"HandFlashlight","weapon"},
			{"","Items_Magazine"},
			{"","CraftBuildItens"},
			{"","Ferramentas"},
			{"","CraftItens"}
			
		};
		itemChance[] =	{
			0.06,	//Lixos
			0.05,   //CarParts
			0.02,   //Boat_Backpack
			0.04,   //Machado
			0.06,   //Faca
			0.04,   //Lanterna
			0.04,   //Items_Magazine
			0.02,   //CraftBuildItens
			0.04,   //Ferramentas
			0.04    //CraftItens
		};
	};
	/////////////////////////////////////////////////////////////////////////////////
	class Church: Default{
		zombieChance = 0.3;
		zombieClass[] = {
			"VZ_Priest",
			"VZ_boomer"
		};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.2;
		itemType[] =	{
			{"","trash"},
			{"","Items_Magazine"},
			{"","Medical_Lite"},
			{"","RoupasLow"},
			{"","MochilasLow"},
			{"","Comidas"},
			{"","Bebidas"}
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.04,	//Items_Magazine
			0.02,	//Medical_Lite
			0.04,	//RoupasLow
			0.03,	//MochilasLow
			0.02,	//Comidas
			0.02	//Bebidas
		};
	};
	
	////////////////////////////////////////////////////////////////////////////////
	class Hospital: Default {
		zombieChance = 0.3;
		zombieClass[] = { "VZ_Doctor", "VZ_Assistant"};
		minRoaming = 0;
		maxRoaming = 1;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","Medical_Lite"},
			{"","Medical_Especial"}
		};
		itemChance[] =	{
			0.03,	//lixo
			0.07,	//Medical_Lite
			0.04	//Medical_Especial
		};
	};

	/////////////////////////////////////////////////////////////////////////////
	class Hangares: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 0;
		maxRoaming = 2;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","CarParts"},
			{"","PistolasMedias"},
			{"","Mag_PistolasMedias"},
			{"","ArmasMedias"},
			{"","Mag_ArmasMedias"},
			{"","Acessorios_Optic"},
			{"","RoupasUpper"},
			{"","trow"},
			{"","MochilasMedias"},
			{"ItemWaterBottle","magazine"},
			{"FoodMRE","magazine"},
			{"ItemTent","magazine"},
			{"ItemCompass","item"},
			{"Binocular","item"},
			{"ItemTentDome","magazine"},
			{"ItemCamoNetBig","magazine"},
			{"ItemCamoNet","magazine"},
			{"ItemCamoNetOpen","magazine"}
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.05,	//CarParts
			0.04,	//PistolasMedias
			0.03,	//Mag_PistolasMedias
			0.03,	//ArmasMedias
			0.04,	//Mag_ArmasMedias
			0.03,	//Acessorios_Optic
			0.04, 	//RoupasUpper
			0.05,	//trow
			0.02,	//MochilasMedias
			0.02,	//ItemWaterBottle
			0.02,	//FoodMRE
			0.01,	//{"ItemTent","magazine"},
			0.03,	//Bussola
			0.03,	//Binoculo
			0.01,	//{"ItemTentDome","magazine"},
			0.01,	//{"ItemCamoNetBig","magazine"},
			0.01,	//{"ItemCamoNet","magazine"},
			0.01	//{"ItemCamoNetOpen","magazine"}
			
		};
	};
	
	/////////////////////////////////////////////////////////////////////////////
	class MilitaresLow: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 0;
		maxRoaming = 2;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","PistolasMedias"},
			{"","Mag_PistolasMedias"},
			{"","ArmasMedias"},
			{"","Mag_ArmasMedias"},
			{"","Acessorios_Optic"},
			{"","RoupasUpper"},
			{"","trow"},
			{"","MochilasMedias"},
			{"ItemWaterBottle","magazine"},
			{"FoodMRE","magazine"},
			{"ItemTent","magazine"},
			{"ItemCompass","item"},
			{"Binocular","item"},
			{"ItemTentDome","magazine"},
			{"ItemCamoNetBig","magazine"},
			{"ItemCamoNet","magazine"},
			{"ItemCamoNetOpen","magazine"}
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.04,	//PistolasMedias
			0.03,	//Mag_PistolasMedias
			0.03,	//ArmasMedias
			0.04,	//Mag_ArmasMedias
			0.03,	//Acessorios_Optic
			0.04, 	//RoupasUpper
			0.05,	//trow
			0.02,	//MochilasMedias
			0.02,	//ItemWaterBottle
			0.02,	//FoodMRE
			0.01,	//{"ItemTent","magazine"},
			0.03,	//Bussola
			0.03,	//Binoculo
			0.01,	//{"ItemTentDome","magazine"},
			0.01,	//{"ItemCamoNetBig","magazine"},
			0.01,	//{"ItemCamoNet","magazine"},
			0.01	//{"ItemCamoNetOpen","magazine"}
			
		};
	};
	/////////////////////////////////////////////////////////////////////////////
	class MilitaresMedios: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 0;
		maxRoaming = 2;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","PistolasMedias"},
			{"","Mag_PistolasMedias"},
			{"","ArmasMedias"},
			{"","Mag_ArmasMedias"},
			{"","Acessorios_Optic"},
			{"","RoupasMilitares"},
			{"","trow"},
			{"","MochilasMedias"},
			{"ItemWaterBottle","magazine"},
			{"FoodMRE","magazine"},
			{"ItemTent","magazine"},
			{"ItemCompass","item"},
			{"Binocular","item"},
			{"ItemTentDome","magazine"},
			{"ItemCamoNetBig","magazine"},
			{"ItemCamoNet","magazine"},
			{"ItemCamoNetOpen","magazine"}
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.04,	//PistolasMedias
			0.03,	//Mag_PistolasMedias
			0.03,	//ArmasMedias
			0.04,	//Mag_ArmasMedias
			0.03,	//Acessorios_Optic
			0.04, 	//RoupasMilitares
			0.05,	//trow
			0.02,	//MochilasMedias
			0.02,	//ItemWaterBottle
			0.02,	//FoodMRE
			0.01,	//{"ItemTent","magazine"},
			0.03,	//Bussola
			0.03,	//Binoculo
			0.01,	//{"ItemTentDome","magazine"},
			0.01,	//{"ItemCamoNetBig","magazine"},
			0.01,	//{"ItemCamoNet","magazine"},
			0.01	//{"ItemCamoNetOpen","magazine"}
			
		};
	};
	/////////////////////////////////////////////////////////////////////////////
	class MilitaresHigh: Default {
		zombieChance = 0.3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
	    minRoaming = 0;
		maxRoaming = 2;
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","PistolasMedias"},
			{"","Mag_PistolasMedias"},
			{"","ArmasHigh"},
			{"","Mag_ArmasHigh"},
			{"","Acessorios_Optic"},
			{"","RoupasMilitares"},
			{"","trow"},
			{"","MochilasHigh"},
			{"ItemWaterBottle","magazine"},
			{"FoodMRE","magazine"},
			{"ItemTent","magazine"},
			{"ItemCompass","item"},
			{"Binocular","item"},
			{"ItemTentDome","magazine"},
			{"ItemCamoNetBig","magazine"},
			{"ItemCamoNet","magazine"},
			{"ItemCamoNetOpen","magazine"}
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.04,	//PistolasMedias
			0.03,	//Mag_PistolasMedias
			0.03,	//ArmasHigh
			0.04,	//Mag_ArmasHigh
			0.03,	//Acessorios_Optic
			0.04, 	//RoupasMilitares
			0.05,	//trow
			0.03,	//MochilasHigh
			0.02,	//ItemWaterBottle
			0.02,	//FoodMRE
			0.01,	//{"ItemTent","magazine"},
			0.03,	//Bussola
			0.03,	//Binoculo
			0.01,	//{"ItemTentDome","magazine"},
			0.01,	//{"ItemCamoNetBig","magazine"},
			0.01,	//{"ItemCamoNet","magazine"},
			0.01	//{"ItemCamoNetOpen","magazine"}
			
		};
	};
	
////////////////////////////////////////////////////////////////////
//BuildingPos Chernarus
#include "CfgBuildingPos_Chernarus.hpp"
////////////////////////////////////////////////////////////////////	
#include "CfgHelicrash_ViruZ.hpp" // ViruZ HeliCrash Holder
	
};