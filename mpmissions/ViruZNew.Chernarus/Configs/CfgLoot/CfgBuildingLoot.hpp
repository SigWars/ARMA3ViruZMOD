//////////////////////////////////////////////
// Building Loot Class Separado Por Função
// By ViruZTeam
//////////////////////////////////////////////
class Default {
		zombieChance = 0.2;
		minRoaming = 0;
		maxRoaming = 1;
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

/* Loot Residencial */

/* Loot Mercados/ Restaurante */

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
			{"","trash"}, //Lixos
			{"","backpack_leves"},
			{"","food"},
			{"","drink"},
			{"","items_magazine"},			//MatchBox - Nail - Wire
			{"","melee_lite"},
			{"Battery_mag","magazine"}
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.03,	//mochilas
			0.04,	//comidas
			0.04,	//bebidas
			0.03,	//MatchBox etc...
			0.02,	//Melees Lite
			0.03	//Baterry
																		
		};
	};
	
	class Restaurante: Default {
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
			{"","trash"}, //Lixos
			{"","backpack_leves"},
			{"","food"},
			{"","drink"},
			{"","items_magazine"},			//MatchBox - Nail - Wire
			{"","melee_lite"},
			{"Battery_mag","magazine"},
			{"CUP_sgun_M1014","weapon"},
			{"CUP_8Rnd_B_Beneli_74Slug","magazine"},	//M1014 mag
			{"CUP_8Rnd_B_Beneli_74Pellets","magazine"},	//M1014 mag
			{"CUP_srifle_LeeEnfield_rail","weapon"},
			{"CUP_10x_303_M","magazine"}			//lee enfield mag
			
			
		};
		itemChance[] =	{
			0.02,	//lixo
			0.04,	//mochilas
			0.05,	//comidas
			0.05,	//bebidas
			0.04,	//MatchBox etc...
			0.03,	//Melees Lite
			0.03,	//Baterry
			0.02,	//CUP_sgun_M1014
			0.03,	//M1014 mag
			0.03,	//M1014 mag
			0.02,	//CUP_srifle_LeeEnfield_rail
			0.03	//Le enfield mag
																		
		};
	};

/* Loot Celeros/Fazendas/Rural */

/* Loot Hospital/Barracas Medicas/Etc... */

	class Hospital: Default {
			zombieChance = 0.3;
			minRoaming = 0;
			maxRoaming = 3;
			zombieClass[] = {
				"VZ_Doctor",
				"VZ_Assistant"
			};
			lootChance = 0.3;
			lootPos[] = {};
			itemType[] =	{
				{"","trash"},                               //Lixos
				{"","medical_lite"},						//"ItemBandage""ItemPainkiller","ItemAntibiotic","ItemHeatPack"
				{"","medical_especial"}                     //"ItemBandage""ItemPainkiller","ItemAntibiotic","ItemHeatPack","ItemBloodbag","ItemEpinephrine","ItemMorphine"
			};
			itemChance[] =	{
				0.03,	//lixo
				0.07,	//medical_lite
				0.04	//medical_especial
			};
		};

/* Loot Militares */

/* Loot Militares */

#include "CfgBuildingPos.hpp" // Casas Chernarus