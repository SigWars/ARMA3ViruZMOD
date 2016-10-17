#include "CfgLoot.hpp"

class CfgBuildingLoot {
	class Default {
		zombieChance = 0.2;
		minRoaming = 0;
		maxRoaming = 2;
		//zombieClass[] = {"zZombie_Base","z_hunter","z_teacher","z_suit1","z_suit2","z_worker1","z_worker2","z_worker3","z_villager1","z_villager2","z_villager3","VZ_zed","VZ_woman","VZ_boomer","VZ_officer","VZ_zedwoman","VZ_zedmalebig"};
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
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
//************************Viruz Loot***********************************************************************************
	class Ruins: Default {
		zombieClass[] = {
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
		};
		lootChance = 0.1;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","medical_lite"},
			{"","food"},
			{"","drink"}
		};
		itemChance[] =	{
			0.07,	//trash
			0.03,	//medical_lite
			0.05,	//food
			0.05	//drink
		};		
	};

	class Residential: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig"
		};
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","pistol_lite"},
			{"CUP_sgun_M1014","weapon"},
			{"CUP_srifle_LeeEnfield_rail","weapon"},
			{"","mag_pistol_lite"},
			{"CUP_8Rnd_B_Beneli_74Slug","magazine"},	//benelli
			{"CUP_8Rnd_B_Beneli_74Pellets","magazine"},	//benelli
			{"CUP_10x_303_M","magazine"},				//lee enfield mag
			{"","melee_lite"},
			{"","medical_lite"},						//Bandagem - Painkiller - Antibiotico
			{"","food"},								//Comidas
			{"","drink"},								//Bebidas
			{"","items_magazine"}, 						//prego e fosforo
			{"","uniform_civilian"},					//Roupas
			{"","glasses_civilian"}, 					//Oculos 
			{"","headgear_civilian"},					//Mascaras - Tocas
			{"","backpack_leves"},						// mochilas pequenas
			{"Battery_mag","magazine"}		
			
		};
		itemChance[] =	{
			0.03,	//lixo
			0.03,	//pistolas
			0.03,	//benelli
			0.03,	//lee enfield
			0.02,	//pistolas mag
			0.02,	//benelli mag
			0.02,	//benelli mag
			0.02,	//lee enfield mag
			0.05,	//lanterna e faca
			0.05,	//Bandagem - Painkiller - Antibiotico
			0.05,	//Comidas			
			0.07,	//Bebidas
			0.04,	//prego e fosforo	
			0.03,	//Roupas
			0.03,	//Oculos 
			0.03,	//Mascaras - Tocas
			0.02,	//backpack
			0.02	//Battery_mag
			
		};
		
		
	};
	class Office: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Functionary1","VZ_Functionary2"
		};
		minRoaming = 1;
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","pistol_lite"},
			{"","mag_pistol_lite"},
			{"CUP_sgun_M1014","weapon"},
			{"CUP_srifle_LeeEnfield_rail","weapon"},
			{"CUP_8Rnd_B_Beneli_74Slug","magazine"},	//benelli
			{"CUP_8Rnd_B_Beneli_74Pellets","magazine"},	//benelli
			{"CUP_10x_303_M","magazine"},				//lee enfield mag			
			{"","medical_lite"},
			{"","food"},
			{"","drink"},
			{"","items_magazine"},
			{"","backpack_leves"}

		};
		itemChance[] =	{
			0.02,	//lixo
			0.02,	//pistolas
			0.01,	//pistolas mag
			0.02,	//benelli
			0.02,	//lee enfield
			0.01,	//benelli mag
			0.01,	//benelli mag
			0.01,	//lee enfield mag
			0.03,	//Bandagem - Painkiller - Antibiotico
			0.02,	//Comidas			
			0.04,	//Bebidas
			0.02,	//prego e fosforo	
			0.01	//mochilas pequenas


		};
		
		
	};
	class Industrial: Default {
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4"
		};
		zombieChance = 0.3;
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","pistol_lite"},
			{"","mag_pistol_lite"},
			{"","Parts"},
			{"","melee_lite"},
			{"","ferramentas"},
			{"ItemETool","item"},
			{"","melee_especial"},
			{"Battery_mag","magazine"},
			{"ItemSandbag","item"},
			{"ItemJerrycan","item"}
		};
		itemChance[] =	{
			0.02,	//lixo
			0.01,	//pistolas
			0.01,	//munição pistolas
			0.08,	//Parts
			0.02,	//melee_lite
			0.06,	//ferramentas
			0.06,	//pa
			0.01,	//melee_especial
			0.02,	//Battery_mag
			0.03,	//ItemSandbag
			0.02	//jerrycan full
		};
	};
	class Instrumental: Default {
		zombieClass[] = {
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4"
		};
		zombieChance = 0;
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","ferramentas"},
			{"","Parts"}
		};
		itemChance[] =	{
			0.03,	//lixo
			0.08,	//ferramentas
			0.05	//Parts
		};
	};
	class Farm: Default {
		zombieClass[] = {
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4"
		};
		zombieChance = 0.2;
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"CUP_sgun_M1014","weapon"},
			{"CUP_srifle_LeeEnfield_rail","weapon"},
			{"CUP_8Rnd_B_Beneli_74Slug","magazine"},	//benelli
			{"CUP_8Rnd_B_Beneli_74Pellets","magazine"},	//benelli
			{"CUP_10x_303_M","magazine"},				//lee enfield mag
			{"","medical_lite"},
			{"","ferramentas"},
			{"ItemETool","item"},
			{"","melee_lite"},
			{"","items_magazine"},						//MatchBox
			{"","melee_especial"},
			{"","Parts"},
			{"ItemSandbag","item"}
			
		};
		itemChance[] =	{
			0.03,	//lixo
			0.02,	//M1014
			0.04,	//LeeEnfield
			0.01,	//Slug
			0.02,	//Pellets
			0.03,	//LeeEnfield mag
			0.04,	//medical_lite
			0.07,	//ferramentas
			0.07,	//pa
			0.04,	//melee_lite
			0.03,	//items_magazine 
			0.07,	//melee_especial
			0.03,	//Parts
			0.03	//sandbag

		};
	};
	class Boutique: Default {
		lootChance = 0.3;
		zombieChance = 0.2;
		minRoaming = 0;
		maxRoaming = 1;
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4"
		};
		itemType[] = {
			{"","trash"},
			{"","backpack_leves"},
			{"","uniform_civilian"},
			{"","headgear_civilian"},
			{"","glasses_civilian"},
			{"ItemWatch","item"}
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.03,	//mochilas pequenas
			0.02,	//uniform_civilian
			0.02,	//headgear_civilian
			0.02,	//glasses_civilian
			0.04	//relogio

		};
	};
	class Supermarket: Default {
		lootChance = 0.2;
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
			"VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig"
		};
		itemType[] = {
			{"","trash"},
			{"","pistol_lite"},
			{"","mag_pistol_lite"},
			{"","backpack_leves"},
			{"","food"},
			{"","drink"},
			{"","items_magazine"},			//MatchBox - Nail - Wire
			{"","medical_lite"},
			{"","ferramentas"},
			{"","melee_lite"},
			{"Battery_mag","magazine"}
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.02,	//pistolas
			0.01,	//pistolas mag
			0.01,	//backpack_leves
			0.06,	//food
			0.08,	//drink
			0.05,	//items_magazine
			0.04,	//medical_lite
			0.03,	//ferramentas
			0.04,	//melee_lite
			0.02	//Battery_mag

		};
	};
	class MilitaryShop: Default {
		lootChance = 0.2;
		zombieChance = 0.2;
		minRoaming = 1;
		maxRoaming = 2;
		zombieClass[] = {
			"z_soldier","z_soldier_heavy","z_soldier_pilot"
		};
		itemType[] = {
			{"","trash"},
			{"","pistol_especial"},
			{"","mag_pistol_especial"},
			{"","weapons_smg"},
			{"","magazine_smg"},
			{"U_B_CombatUniform_mcam","item"},
			{"U_I_CombatUniform","item"},
			{"U_O_OfficerUniform_ocamo","item"},
			{"U_I_OfficerUniform","item"},
			{"H_HelmetB_plain_mcamo","item"},
			{"H_HelmetIA_camo","item"},
			{"H_MilCap_ocamo","item"},
			{"H_MilCap_mcamo","item"},
			{"H_MilCap_rucamo","item"},
			{"ItemCompass","item"},
			{"Binocular","item"},
			{"","glasses_military"},
			{"FoodMRE","magazine"},
			{"ItemWaterBottleEmpty","magazine"}
		};
		itemChance[] =	{
			0.03,	//lixo
			0.02,	//pistolas
			0.01,	//pistolas mag
			0.03,	//weapons_rifle
			0.02,	//magazine_rifle
			0.02,	//{"U_B_CombatUniform_mcam","item"},
			0.02,	//{"U_I_CombatUniform","item"},
			0.02,	//{"U_O_OfficerUniform_ocamo","item"},
			0.02,	//{"U_I_OfficerUniform","item"},
			0.02,	//{"H_HelmetB_plain_mcamo","item"},
			0.02,	//{"H_HelmetIA_camo","item"},
			0.02,	//{"H_MilCap_ocamo","item"},
			0.02,	//{"H_MilCap_mcamo","item"},
			0.02,	//{"H_MilCap_rucamo","item"},
			0.04,	//{"ItemCompass","item"}
			0.04,	//{"Binocular","item"}
			0.02,	//{"","glasses_military"},
			0.01,	//{"FoodMRE","magazine"},
			0.03	//{"ItemWaterBottleEmpty","magazine"}

		};
	};
	class Hospital: Default {
		zombieChance = 0.3;
		minRoaming = 0;
		maxRoaming = 3;
		//zombieClass[] = {"z_doctor","z_doctor","z_doctor","VZ_zed","VZ_woman","VZ_officer","VZ_zedwoman","VZ_zedmalebig"};
		zombieClass[] = {
			"VZ_Doctor",
			"VZ_Assistant"
		};
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","pistol_lite"},
			{"","weapons_smg"},
			{"","mag_pistol_lite"},
			{"","magazine_smg"},
			{"","medical_especial"},
			{"","drink"},
			{"","food"},
			{"","melee_especial"}
		};
		itemChance[] =	{
			0.03,	//lixo
			0.02,	//pistolas
			0.02,	//smg
			0.01,	//pistolas mag
			0.01,	//smg mag
			0.07,	//medical_especial
			0.05,	//drink
			0.03,	//food
			0.03	//melee_especial
		};
	};
	class Military: Default {
		zombieChance = 0.3;
		maxRoaming = 3;
		zombieClass[] = {"z_soldier","z_soldier_heavy","z_soldier_pilot"};
		lootChance = 0.3;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","weapons_rifle"},
			{"","weapons_lmg"},
			{"","magazine_lmg"},
			{"","items_item"},
			{"","magazine_rifle"},
			{"","medical_especial"},
			{"","pistol_especial"},
			{"","mag_pistol_especial"},
			{"","backpack"},
			{"ItemWaterBottle","magazine"},
			{"FoodMRE","magazine"},
			{"ItemTent","magazine"},
			{"ItemCompass","item"},
			{"Binocular","item"},
			{"","glasses_military"},
			{"","uniform_military"},
			{"ItemTentDome","magazine"},
			{"ItemCamoNetBig","magazine"},
			{"ItemCamoNet","magazine"},
			{"ItemCamoNetOpen","magazine"}
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.05,	//weapons_rifle,
			0.02,	//weapons_lmg
			0.01,	//magazine_lmg
			0.03,	//items_item
			0.04,	//magazine_rifle
			0.02,	//medical_especial
			0.02, 	//pistol_especial
			0.01,	//mag_pistol_especial
			0.02,	//backpack
			0.02,	//ItemWaterBottle
			0.02,	//FoodMRE
			0.01,	//{"ItemTent","magazine"},
			0.03,	//Bussola
			0.03,	//Binoculo
			0.03,	//Oculos
			0.03,	//Uniforme militar
			0.01,	//{"ItemTentDome","magazine"},
			0.01,	//{"ItemCamoNetBig","magazine"},
			0.01,	//{"ItemCamoNet","magazine"},
			0.01	//{"ItemCamoNetOpen","magazine"}
			
		};
	};
	class MilitarySpecial: Default {
		zombieChance = 0.4;
		minRoaming = 2;
		maxRoaming = 4;
		zombieClass[] = {"z_soldier_heavy","z_soldier","z_soldier_pilot"};
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"","weapons_rifle"},
			{"","weapons_lmg"},
			{"","items_item"},
			{"","magazine_rifle"},
			{"","magazine_lmg"},
			{"","medical_especial"},
			{"","snipe_drm"},
			{"","magazine_drm"},
			{"","pistol_especial"},
			{"","mag_pistol_especial"},
			{"","backpack"},
			{"ItemWaterBottle","magazine"},
			{"ItemTent","magazine"},
			{"FoodMRE","magazine"},
			{"ItemCompass","item"},
			{"Binocular","item"},
			{"","glasses_military"},
			{"","uniform_military"}
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.07,	//rifles
			0.03,	//weapons_lmg
			0.05,	//items_item
			0.06,	//magazine_rifle
			0.02,	//lmg mag
			0.03,	//medical_especial
			0.04,	//snipe_drm
			0.02,	//drm mag
			0.02, 	//pistol_especial
			0.01,	//pistol mag
			0.04,	//backpack
			0.03,	//ItemWaterBottle
			0.01,	//ItemTent
			0.03,	//FoodMRE
			0.02,	//Bussola
			0.02,	//Binoculo
			0.02,	//Oculos
			0.02	//Uniforme
	
		};
	};
	class HelicrashViruZ: Default {
		zombieChance = 0.4;
		minRoaming = 2;
		maxRoaming = 4;
		zombieClass[] = {"z_soldier_heavy","z_soldier_pilot","z_soldier"};
		lootChance = 0.5;
		lootPos[] = {};
		itemType[] =	{
			{"","snipe_special"},
			{"","magazine_sniper"},
			{"","weapons_lmg"},
			{"","magazine_lmg"},
			{"","weapons_rifle"},
			{"","magazine_rifle"},
			{"","items_item"}
		};
		itemChance[] =	{
			0.02,	//snipe_special
			0.01,	//sniper mag
			0.04,	//weapons_lmg
			0.02,	//magazine_lmg
			0.06,	//weapons_rifle
			0.04,	//magazine_rifle
			0.04	//miras
		};
	};
	class Hunting: Default { //EDITAR
		zombieClass[] = {
			"VZ_Citizen1","VZ_Citizen2","VZ_Citizen3","VZ_Citizen4",
			"VZ_Worker1","VZ_Worker2","VZ_Worker3","VZ_Worker4",
			"VZ_Profiteer1","VZ_Profiteer2","VZ_Profiteer3","VZ_Profiteer4",
			"VZ_Woodlander1","VZ_Woodlander2","VZ_Woodlander3","VZ_Woodlander4",
			"VZ_Functionary1","VZ_Functionary2",
			"VZ_Villager1","VZ_Villager2","VZ_Villager3","VZ_Villager4",
		};
		zombieChance = 0.3;
		minRoaming = 1;
		maxRoaming = 3;
		lootChance = 0.2;
		lootPos[] = {};
		itemType[] =	{
			{"","trash"},
			{"ItemKnife","weapon"},
			{"handFlashlight","weapon"},
			{"ItemMatchbox","magazine"},
			{"CUP_sgun_M1014","weapon"},
			{"CUP_srifle_LeeEnfield_rail","weapon"},
			{"CUP_8Rnd_B_Beneli_74Slug","magazine"},	//benelli
			{"CUP_8Rnd_B_Beneli_74Pellets","magazine"},	//benelli
			{"CUP_10x_303_M","magazine"},				//lee enfield mag
			{"FMradio_Mag","magazine"},
			{"Chemlight_green","magazine"},
			{"Chemlight_red","magazine"},
			{"Chemlight_yellow","magazine"},
			{"Chemlight_blue","magazine"}
			
		};
		itemChance[] =	{
			0.03,	//lixo
			0.04,	// ItemKnife
			0.04,	// handFlashlight
			0.04,	// ItemMatchbox
			0.03,	// benelli
			0.03,	// LeeEnfield
			0.02,	// Slug
			0.02,	// Pellets
			0.02,	// LeeEnfield mag
			0.02,	// Radio FM
			0.02,	// Chemlight_green
			0.02,	// Chemlight_red
			0.02,	// Chemlight_yellow
			0.02	// Chemlight_blue
		};
	};
	class Church: Default{
		zombieChance = 0.3;
		zombieClass[] = {
			"VZ_Priest",
			"VZ_boomer"
		};
		maxRoaming = 1;
		lootChance = 0.2;
		itemType[] =	{
			{"","trash"},
			{"","melee_lite"},
			{"","medical_lite"},
			{"","drink"},
			{"","food"},
			{"Battery_mag","magazine"}
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.02,	//lanterna e faca
			0.02,	//medical_lite
			0.03,	//bebida
			0.03,	//comida
			0.01	//bateria
		};
	};
	
//*************** Viruz Holders ******************************************************
	//Medical lite
	class VZ_MedBox_lite{
		lootChance = 0.9;
		isObjectHolder = 2;
		isBuildingPos = 0;
		itemType[] =	{
			{"","medical_lite"}
		};
		itemChance[] =	{
			0.07
		};
	};
	//Medical Especial
	class VZ_MedBox_especial{
		lootChance = 0.9;
		isObjectHolder = 2;
		isBuildingPos = 0;
		itemType[] =	{
			{"","medical_especial"}
		};
		itemChance[] =	{
			0.07
		};
	};
	//Drink
	class Crate_Plastic{
		lootChance = 0.9;
		isObjectHolder = 2;
		isBuildingPos = 0;
		itemType[] =	{
			{"","drink"}

		};
		itemChance[] =	{
			0.09
		};
	};	
	//Food
	class VZ_Cesta{
		lootChance = 0.9;
		isObjectHolder = 2;
		isBuildingPos = 0;
		itemType[] =	{
			{"","food"}
		};
		itemChance[] =	{
			0.09
		};
	};
	//Weapons Lite
	class VZ_weaponbox_lite{
		lootChance = 0.9;
		isObjectHolder = 2;
		isBuildingPos = 0;
		itemType[] = {
			{"","pistol_especial"},
			{"","weapons_smg"},
			{"","items_item"},
			{"","magazine_smg"}
			
		};
		itemChance[] =	{
			0.06,
			0.04,
			0.01,
			0.02
		};
	};
	//Weapons Gold
	class VZ_weaponbox_gold{
		lootChance = 0.9;
		isObjectHolder = 2;
		isBuildingPos = 0;
		itemType[] = {
			{"","weapons_rifle"},
			{"","weapons_lmg"},
			{"","items_item"},
			{"","magazine_rifle"}
		};
		itemChance[] =	{
			0.06,
			0.01,
			0.02,
			0.03
		};
	};	
//*******************************************************************************************
	
	class Maniken_Civilian: Default { //Маникен
		zombieChance = 0;
		isBuildingPos = 0;
		lootChance = 0.3;
		itemType[] =	{
			{"","uniform_civilian"},
			{"","headgear_civilian"},
			{"","glasses_civilian"}
		};
		itemChance[] =	{
			0.05, //uniform_civilian
			0.05, //headgear_civilian
			0.05  //glasses_civilian
		};		
	};

	class Maniken_Military: Default { //Маникен
		zombieChance = 0;
		isBuildingPos = 0;
		lootChance = 0.3;
		itemType[] =	{
			{"","uniform_military"},
			{"","headgear_military"},
			{"","glasses_military"},
			{"","vest"}
		};
		itemChance[] =	{
			0.03,	//uniform_military
			0.05, 	//headgear_military
			0.05,  	//glasses_military
			0.01		// vest
		};		
	};
		
	//holders
	
	class VZBox_MediaV: HelicrashViruZ{ //HELICRASH BOX
		lootChance = 0.9;
		isObjectHolder = 1;
		isBuildingPos = 0;
	};
	
	
	#include "CfgBuildingPos.hpp" // Casas Esseker
	#include "CfgBuildingPos_dos.hpp"
	#include "CfgFurniturePos.hpp"
	#include "CfgChernarus.hpp"
};