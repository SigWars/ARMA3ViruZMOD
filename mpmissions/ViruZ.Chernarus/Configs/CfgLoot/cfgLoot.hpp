//////////////////////////////////////////////////
//
//     ViruZ Mod Loot
//     Version 1.0.1
//	   Author: ViruZModTeam
//
///////////////////////////////////////////////////


class CfgLoot {
///////////////////////////////////////////////////
//Lixo

	Trash[] = {
		{
			"FoodCanWBBeansEmpty",
			"FoodCanMHBeansEmpty",
			"FoodCanCGBeansEmpty",
			"FoodCanBeefChunksEmpty",
			"FoodCanChickenChunksEmpty",
			"FoodCanChickenNoodleEmpty",
			"FoodCanFruitcocktailEmpty",
			"FoodCanOrangesEmpty",
			"FoodCanPeachesEmpty",
			"FoodCanPearsEmpty",
			"FoodCanEsardinesEmpty",
			"FoodCanPsardinesEmpty",
			"FoodCanChickenSoupEmpty",
			"FoodCanPotatoSoupEmpty",
			"FoodCanPeaSoupEmpty",
			"FoodCanCCCornSoupEmpty",
			"FoodCanHCCornSoupEmpty",
			"FoodCanTRSoupEmpty",
			"FoodCanCRiceSoupEmpty",
			"FoodCanSpaghetti1Empty",
			"FoodCanSpaghetti2Empty",
			"ItemSodaOriginalEmpty", 
			"ItemSodaDarthEmpty",
			"ItemSodaDietEmpty",
			"ItemSodaGrapeEmpty",
			"ItemSodaHamEmpty",
			"ItemSodaOrangeEmpty",
			"ItemSodaLemonEmpty",
			"ItemSodaYodaEmpty", 
			"ItemSodaBeergoldenEmpty"	
		},
		{
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05,
			0.05			
		}
	};
	
	
///////////////////////////////////////////////////
//Bebidas

	Drink[] = {
		{
			"ItemSodaOriginal",  
			"ItemSodaDarth",
			"ItemSodaDiet",
			"ItemSodaGrape",
			"ItemSodaHam",
			"ItemSodaOrange",
			"ItemSodaLemon",
			"ItemSodaYoda", 
			"ItemSodaBeergolden"

		},
		{
			0.05,	//ItemSodaOriginal
			0.05,	//ItemSodaDarth
			0.05,	//ItemSodaDiet
			0.05,	//ItemSodaGrape
			0.05,	//ItemSodaHam
			0.05,	//ItemSodaOrange
			0.05,	//ItemSodaLemon
			0.05,	//ItemSodaYoda
			0.05	//ItemSodaBeergolden

		}
	};
	
///////////////////////////////////////////////////
//Comidas
	
	Food[] = {
		{
			"FoodCanWBBeans",
			"FoodCanMHBeans",
			"FoodCanCGBeans",
			"FoodCanBeefChunks",
			"FoodCanChickenChunks",
			"FoodCanChickenNoodle",
			"FoodCanFruitcocktail",
			"FoodCanOranges",
			"FoodCanPeaches",
			"FoodCanPears",
			"FoodCanEsardines",
			"FoodCanPsardines",
			"FoodCanChickenSoup",
			"FoodCanPotatoSoup",
			"FoodCanPeaSoup",
			"FoodCanCCCornSoup",
			"FoodCanHCCornSoup",
			"FoodCanTRSoup",
			"FoodCanCRiceSoup",
			"FoodCanSpaghetti1",
			"FoodCanSpaghetti2"
		},
		{
			0.03,	//FoodCanWBBeans
			0.03,	//FoodCanMHBeans
			0.03,	//FoodCanCGBeans
			0.03,	//FoodCanBeefChunks
			0.03,	//FoodCanChickenChunks
			0.03,	//FoodCanChickenNoodle
			0.03,	//FoodCanFruitcocktail
			0.03,	//FoodCanOranges
			0.03,	//FoodCanPeaches
			0.03,	//FoodCanPears
			0.03,	//FoodCanEsardines
			0.03,	//FoodCanPsardines
			0.03,	//FoodCanChickenSoup
			0.03,	//FoodCanPotatoSoup
			0.03,	//FoodCanPeaSoup
			0.03,	//FoodCanCCCornSoup
			0.03,	//FoodCanHCCornSoup
			0.03,	//FoodCanTRSoup
			0.03,	//FoodCanCRiceSoup
			0.03,	//FoodCanSpaghetti1
			0.03	//FoodCanSpaghetti2
		}
	};

///////////////////////////////////////////////////
//Loot básico e de residências

	Basic_Items[] = {
		{
			"ItemMatchbox",
			"Viruz_CardBoardBox"
		},
		{
			0.04, 	//Matchbox
			0.01	//Cardboard box

		}
	};


	Houseware_Items[] = {
		{
			"Viruz_Saucepan",
			"ItemMatchbox",
			"ItemCanOpener",
			"Viruz_Suitcase",
			"Viruz_CardBoardBox"

		},
		{
			0.06,	//Saucepan
			0.06,	//Matchbox
			0.06,	//Can opener
			0.04,	//Suitcase
			0.02	//Cardboard box
		}
	};

	Eletronic_Items[] = {
		{	
			"Viruz_HandyCam",
			"Viruz_MobilePhone",
			"Viruz_SmartPhone"
//			"Viruz_Laptop"
		},
		{
			0.02, 	//Handycam
			0.04, 	//Mobilephone
			0.03	//Smartphone
//			0.02	//Laptop
		}
	};

///////////////////////////////////////////////////
//Loot escritório/escola //addMagazineCargoGlobal

	Office_Items[] = {
		{
			"Viruz_MobilePhone",
			"Viruz_SmartPhone",
//			"Viruz_Laptop",
			"Viruz_Suitcase",
			"Viruz_CardBoardBox"

		},
		{
			0.03,	//Mobilephone
			0.04,	//Smartphone
//			0.04,	//Laptop
			0.04,	//Suitcase
			0.02	//Cardboard box
		}
	};

///////////////////////////////////////////////////
//Loot militar/sobrevivência

	Basic_Survival[] = {	//addItemCargoGlobal
		{
			"ItemCompass",
			"Binocular",
			"ItemWatch",
			"ItemMap",
			"ItemKnife",
			"ItemGPS"
			
		},
		{
			0.04,	//Compass
			0.04,	//Binocular
			0.04,	//Watch
			0.04,	//Map
			0.04,	//Knife
			0.01	//GPS
		}
	};

	Survival_Items[] = {	//addMagazineCargoGlobal
		{
			"ItemTent",
			"ItemWaterBottle",
			"Chemlight_blue",
			"Chemlight_green",
			"Chemlight_red",
			"Chemlight_yellow"
		},
		{
			0.03,	//Tent
			0.05,	//Canteen
			0.04,	//Chemlight blue
			0.04,	//Chemlight green
			0.04,	//Chemlight red
			0.04	//Chemlight yellow
		}
	};
		
///////////////////////////////////////////////////
//Materiais //addMagazineCargoGlobal

	Materials[] = {
		{
			"ItemSandbag",
			"ItemWire",
			"equip_nails",
			"Viruz_CementBag",
			"Viruz_CardBoardBox"

		},
		{
			0.04, 	//Sandbag
			0.06,	//Metal wire
			0.06,	//Box of nails
			0.02,	//Cement bag
			0.04	//Cardboard box

		}
	};
	
///////////////////////////////////////////////////
//Ferramentas //addMagazineCargoGlobal

	Tools[] = {
		{
			"Viruz_Hammer",
			"Viruz_Saw",
			"Viruz_Wrench",
			"Viruz_Screwdriver",
			"Viruz_Phillips",
			"Viruz_Pliers",
			"ItemEtool"

		},
		{
			0.05,	//Hammer
			0.05,	//Saw
			0.05,	//Wrench
			0.05,	//Scredriver
			0.05,	//Phillips screwdriver
			0.05,	//Pliers
			0.04	//Shovel

		}
	};

///////////////////////////////////////////////////
//Peças reparo veículos //addMagazineCargoGlobal

	CarParts[] = {
		{
			"PartWheel",
			"PartFueltank",
			"PartEngine",
			"PartGlass",
			"ItemJerrycan"

		},
		{
			0.07,	//PartWheel
			0.06,	//PartFueltank
			0.05,	//PartEngine
			0.05,	//PartGlass
			0.05	//ItemJerrycan
		}
	};

	HeliParts[] = {
		{
			"PartGlass",
			"PartVRotor",
			"ItemJerrycan"

		},
		{
			0.04,	//PartGlass
			0.04,	//PartVRotor
			0.05	//ItemJerrycan

		}
	};
/*
	BikeParts[] = {
		{
			"PartWheel",
			"PartBody",
			"PartHandlebar"

		},
		{
			0.07,
			0.05,
			0.05

		}
	};
*/	
///////////////////////////////////////////////////
//Medical //addMagazineCargoGlobal

	Medical_Lite[] = {
		{
			"ItemBandage",
			"ItemPainkiller",
			"ItemAntibiotic",
			"ItemHeatPack"

		},
		{
			0.05,
			0.04,
			0.04,
			0.03
		}
	};
	
	Medical_Special[] = {
		{
			"ItemBandage",
			"ItemPainkiller",
			"ItemAntibiotic",
			"ItemHeatPack",
			"ItemBloodbag",
			"ItemEpinephrine",
			"ItemMorphine"

		},
		{
			0.04,
			0.04,
			0.04,
			0.04,
			0.03,
			0.03,
			0.03
		}
	};
	
	
///////////////////////////////////////////////////
//Mochilas //addVehicleCargoGlobal

	Boat_Backpacks[] = {
		{
			"Boat_rescue_backpack_4",
			"Boat_transport_backpack_1",
			"Boat_transport_backpack_2",
			"Boat_transport_backpack_3",
			"Boat_transport_backpack_5"
		},
		{
			0.01,
			0.04,
			0.03,
			0.02,
			0.01
		}
	};
	
	Light_Backpacks[] = {
		{
			"CUP_B_ACRScout_m95",			// 60
			"CUP_B_AssaultPack_ACU",		// 150
			"CUP_B_AssaultPack_Black",		// 150
			"CUP_B_AssaultPack_Coyote",		// 150
			"CUP_B_MedicPack_ACU",			// 150
			"B_AssaultPack_khk",			// 160
			"B_AssaultPack_Kerry"			// 160

		},
		{
			0.06,	//CUP_B_ACRScout_m95
			0.03,	//CUP_B_AssaultPack_ACU
			0.03,	//CUP_B_AssaultPack_Black
			0.03,	//CUP_B_AssaultPack_Coyote
			0.03,	//CUP_B_MedicPack_ACU
			0.02,	//B_AssaultPack_khk
			0.02	//B_AssaultPack_Kerry

		}
	};
	
	Medium_Backpacks[] = {
		{
			"CUP_B_RPGPack_Khaki",			// 180
			"CUP_B_GER_Medic_FLecktarn",	// 200
			"CUP_B_USMC_AssaultPack",		// 200
			"B_Kitbag_cbr",					// 280
			"B_Kitbag_sgg",					// 280
			"CUP_B_SLA_Medicbag",			// 280
			"CUP_B_CivPack_WDL",			// 280
			"CUP_B_GER_Pack_Flecktarn",		// 280
			"CUP_B_GER_Pack_Tropentarn",	// 280
			"CUP_B_USPack_Black",			// 280
			"CUP_B_USPack_Coyote"			// 280

		},
		{
			0.06,	// CUP_B_RPGPack_Khaki
			0.05,	// CUP_B_GER_Medic_FLecktarn
			0.05,	// CUP_B_USMC_AssaultPack
			0.03,	// B_Kitbag_cbr
			0.03,	// B_Kitbag_sgg
			0.03,	// CUP_B_SLA_Medicbag
			0.03,	// CUP_B_CivPack_WDL
			0.03,	// CUP_B_GER_Pack_Flecktarn
			0.03,	// CUP_B_GER_Pack_Tropentarn
			0.03,	// CUP_B_USPack_Black
			0.03	// CUP_B_USPack_Coyote

		}
	};
	
	Heavy_Backpacks[] = {
		{
			"CUP_B_AlicePack_Khaki",	// 300
			"CUP_B_ACRPara_m95",		// 300
			"CUP_B_HikingPack_Civ",		// 300
			"CUP_B_USMC_MOLLE",			// 300
			"CUP_B_USMC_MOLLE_WDL",		// 300
			"B_Carryall_khk",			// 320
			"B_Carryall_ocamo"			// 320

		},
		{
			0.05,	// "CUP_B_AlicePack_Khaki"
			0.04,	// "CUP_B_ACRPara_m95"
			0.03,	// "CUP_B_HikingPack_Civ"
			0.02,	// "CUP_B_USMC_MOLLE"
			0.02,	// "CUP_B_USMC_MOLLE_WDL"
			0.01,	// "B_Carryall_khk"
			0.01	// "B_Carryall_ocamo"
		}
	};
	
////////////////////////////////////////////////////
////Roupas //addMagazineCargoGlobal
///////////////
////Civis

	Civilian_Glasses[] = {
		{
			"G_Diving",
			"G_Shades_Black",
			"G_Shades_Blue",
			"G_Sport_Blackred",
			"G_Spectacles",
			"G_Spectacles_Tinted",
			"G_Lowprofile",
			"G_Shades_Green",
			"G_Shades_Red",
			"G_Squares",
			"G_Squares_Tinted",
			"G_Sport_BlackWhite",
			"G_Sport_Blackyellow",
			"G_Sport_Greenblack",
			"G_Sport_Checkered",
			"G_Sport_Red"

		},
		{
			0.04,	//G_Diving
			0.05,	//G_Shades_Black
			0.05,	//G_Shades_Blue
			0.05,	//G_Sport_Blackred
			0.05,	//G_Spectacles
			0.05,	//G_Spectacles_Tinted
			0.05,	//G_Lowprofile
			0.05,	//G_Shades_Green
			0.05,	//G_Shades_Red
			0.05,	//G_Squares
			0.05,	//G_Squares_Tinted
			0.05,	//G_Sport_BlackWhite
			0.05,	//G_Sport_Blackyellow
			0.05,	//G_Sport_Greenblack
			0.05,	//G_Sport_Checkered
			0.05	//G_Sport_Red

		}
	};
	
	Civilian_Clothes[] = {
		{	//ARMA3
			"U_Rangemaster",
			"U_Competitor",
			//RDS
			"rds_uniform_citizen1",
			"rds_uniform_citizen2",
			"rds_uniform_citizen3",
			"rds_uniform_citizen4",
			"rds_uniform_Profiteer1",
			"rds_uniform_Profiteer2",
			"rds_uniform_Profiteer3",
			"rds_uniform_Profiteer4",
			"rds_uniform_Woodlander1",
			"rds_uniform_Woodlander2",
			"rds_uniform_Woodlander3",
			"rds_uniform_Woodlander4",
			"rds_uniform_Villager1",
			"rds_uniform_Villager2",
			"rds_uniform_Villager3",
			"rds_uniform_Villager4",
			"rds_uniform_Rocker1",
			"rds_uniform_Rocker2",
			"rds_uniform_Rocker3",
			"rds_uniform_Rocker4",
			"rds_uniform_Functionary1",
			"rds_uniform_Functionary2"

		},
		{
			//ARMA3
			0.05,	//U_Rangemaster",
			0.03,	//U_Competitor",
			//RDS
			0.05,	//rds_uniform_citizen1
			0.05,	//rds_uniform_citizen2
			0.05,	//rds_uniform_citizen3
			0.05,	//rds_uniform_citizen4
			0.05,	//rds_uniform_Profiteer1
			0.05,	//rds_uniform_Profiteer2
			0.05,	//rds_uniform_Profiteer3
			0.05,	//rds_uniform_Profiteer4
			0.05,	//rds_uniform_Woodlander1
			0.05,	//rds_uniform_Woodlander2
			0.05,	//rds_uniform_Woodlander3
			0.05,	//rds_uniform_Woodlander4
			0.05,	//rds_uniform_Villager1
			0.05,	//rds_uniform_Villager2
			0.05,	//rds_uniform_Villager3
			0.05,	//rds_uniform_Villager4
			0.05,	//rds_uniform_Rocker1
			0.05,	//rds_uniform_Rocker2
			0.05,	//rds_uniform_Rocker3
			0.05,	//rds_uniform_Rocker4
			0.05,	//rds_uniform_Functionary1
			0.05	//rds_uniform_Functionary2

		}
	};

	Civilian_Vests[] = {
		{
			"V_Rangemaster_belt",
			"V_BandollierB_khk",
			"V_BandollierB_cbr",
			"V_BandollierB_rgr",
			"V_BandollierB_blk",
			"V_BandollierB_oli"

		},
		{
			0.06,	//V_Rangemaster_belt
			0.03,	//V_BandollierB_khk
			0.03,	//V_BandollierB_cbr
			0.03,	//V_BandollierB_rgr
			0.03,	//V_BandollierB_blk
			0.03	//V_BandollierB_oli

		}
	};
	
	Civilian_Special[] = {
		{
			"V_Press_F",
			"V_TacVest_blk_POLICE"
			
		},
		{
			0.04,	//V_Press_F
			0.01	//V_TacVest_blk_POLICE
			
		}
	};

	Civilian_Headgear[] = {
		{	
			//ARMA3
			"H_Cap_red",
			"H_Cap_blu",
			"H_Cap_oli",
			"H_Cap_tan",
			"H_Cap_blk",
			"H_Cap_grn",
			"H_Cap_grn_BI",
			"H_Cap_blk_ION",
			"H_Cap_press",
			"H_Cap_police",
			"H_Bandanna_surfer",
			"H_Bandanna_gry",
			"H_Bandanna_sgg",
			"H_Shemag_olive",
			"H_ShemagOpen_khk",
			"H_ShemagOpen_tan",
			"H_StrawHat",
			"H_StrawHat_dark",
			"H_Hat_blue",
			"H_Hat_brown",
			"H_Hat_camo",
			"H_Hat_grey",
			"H_Hat_checker",
			"H_Hat_tan",
			//RDS
			"rds_worker_cap1",
			"rds_worker_cap2",
			"rds_worker_cap3",
			"rds_worker_cap4",
			"rds_Villager_cap1",
			"rds_Villager_cap2",
			"rds_Villager_cap3",
			"rds_Villager_cap4",
			"rds_Profiteer_cap1",
			"rds_Profiteer_cap2",
			"rds_Profiteer_cap3",
			"rds_Profiteer_cap4",
			"rds_Woodlander_cap1",
			"rds_Woodlander_cap2",
			"rds_Woodlander_cap3",
			"rds_Woodlander_cap4"

		},
		{
			//ARMA3
			0.05,	//H_Cap_red
			0.05,	//H_Cap_blu
			0.05,	//H_Cap_oli
			0.05,	//H_Cap_tan
			0.05,	//H_Cap_blk
			0.05,	//H_Cap_grn
			0.05,	//H_Cap_grn_BI
			0.05,	//H_Cap_blk_ION
			0.05,	//H_Cap_press
			0.05,	//H_Cap_police			
			0.05,	//H_Bandanna_surfer
			0.05,	//H_Bandanna_gry
			0.05,	//H_Bandanna_sgg
			0.05,	//H_Shemag_olive
			0.05,	//H_ShemagOpen_khk
			0.05,	//H_ShemagOpen_tan			
			0.05,	//H_StrawHat
			0.05,	//H_StrawHat_dark
			0.05,	//H_Hat_blue
			0.05,	//H_Hat_brown
			0.05,	//H_Hat_camo
			0.05,	//H_Hat_grey
			0.05,	//H_Hat_checker
			0.05,	//H_Hat_tan
			//RDS
			0.05,	//rds_worker_cap1
			0.05,	//rds_worker_cap2
			0.05,	//rds_worker_cap3
			0.05,	//rds_worker_cap4
			0.05,	//rds_Villager_cap1
			0.05,	//rds_Villager_cap2
			0.05,	//rds_Villager_cap3
			0.05,	//rds_Villager_cap4
			0.05,	//rds_Profiteer_cap1
			0.05,	//rds_Profiteer_cap2
			0.05,	//rds_Profiteer_cap3
			0.05,	//rds_Profiteer_cap4
			0.05,	//rds_Woodlander_cap1
			0.05,	//rds_Woodlander_cap2
			0.05,	//rds_Woodlander_cap3
			0.05	//rds_Woodlander_cap4

		}
	};

	Military_Glasses[] = {
		{
			"G_Tactical_Clear",
			"G_Tactical_Black",
			"G_Combat",
			"G_Aviator"

		},
		{
			0.05,	//G_Tactical_Clear
			0.05,	//G_Tactical_Black
			0.05,	//G_Combat
			0.05	//G_Aviator

		}
	};
	
	Military_Clothes[] = {
		{
			"U_BG_Guerilla1_1",					//6 cinders
			"U_BG_Guerilla2_1",					//6 cinders
			"U_BG_Guerilla2_2",					//6 cinders
			"U_BG_Guerilla2_3",					//6 cinders
			"U_B_GEN_Commander_F",				//6 cinders
			"U_B_CombatUniform_mcam",			//8 cinders
			"U_B_CombatUniform_mcam_tshirt",	//8 cinders
			"U_B_CombatUniform_mcam_vest",		//8 cinders
			"U_BG_leader",						//8 cinders
			"U_B_HeliPilotCoveralls",			//8 cinders
			"U_B_CTRG1",						//8 cinders
			"U_B_CTRG2",						//8 cinders
			"U_B_CTRG3",						//8 cinders
			"U_I_G_Story_Protagonist_F",		//8 cinders
			"U_I_G_resistanceLeader_F",			//8 cinders
			"U_B_GEN_Soldier_F",				//8 cinders
			"U_B_Guerilla1_1_srv",				//10 cinders
			"U_B_Guerilla2_2_srv",				//10 cinders
			"U_B_Guerilla2_3_srv",				//10 cinders
			"U_B_Guerilla3_1_srv",				//10 cinders
			"U_B_Guerilla3_2_srv",				//10 cinders
			"U_B_Learder_srv"					//10 cinders

		},
		{
			0.08,	//U_BG_Guerilla1_1
			0.08,	//U_BG_Guerilla2_1
			0.08,	//U_BG_Guerilla2_2
			0.08,	//U_BG_Guerilla2_3
			0.08,	//U_B_GEN_Commander_F
			0.06,	//U_B_CombatUniform_mcam
			0.06,	//U_B_CombatUniform_mcam_tshirt
			0.06,	//U_B_CombatUniform_mcam_vest
			0.06,	//U_BG_leader
			0.06,	//U_B_HeliPilotCoveralls
			0.06,	//U_B_CTRG1
			0.06,	//U_B_CTRG2
			0.06,	//U_B_CTRG3
			0.06,	//U_I_G_Story_Protagonist_F
			0.06,	//U_I_G_resistanceLeader_F
			0.06,	//U_B_GEN_Soldier_F
			0.04,	//U_B_Guerilla1_1_srv
			0.04,	//U_B_Guerilla2_2_srv
			0.04,	//U_B_Guerilla2_3_srv
			0.04,	//U_B_Guerilla3_1_srv
			0.04,	//U_B_Guerilla3_2_srv
			0.04	//U_B_Learder_srv

		}
	};

	Military_Vests[] = {
		{
			"V_HarnessOGL_brn",
			"V_HarnessOGL_gry",
			"V_Chestrig_khk",
			"V_Chestrig_rgr",
			"V_Chestrig_blk",
			"V_Chestrig_oli",
			"V_HarnessO_brn"

		},
		{
			0.08,	//V_HarnessOGL_brn
			0.08,	//V_HarnessOGL_gry
			0.05,	//V_Chestrig_khk
			0.05,	//V_Chestrig_rgr
			0.05,	//V_Chestrig_blk
			0.05,	//V_Chestrig_oli
			0.02	//V_HarnessO_brn

		}
	};
	
	Military_Armor[] = {
		{
			"V_RebreatherB",
			"V_RebreatherIR",
			"V_RebreatherIA",
			"V_TacVest_khk",
			"V_TacVest_brn",
			"V_TacVest_oli",
			"V_TacVest_blk",
			"V_TacVest_camo",
			"V_TacVestIR_blk",
			"V_TacVest_gen_F"

		},
		{
			0.08,	//V_RebreatherB
			0.08,	//V_RebreatherIR
			0.08,	//V_RebreatherIA
			0.06,	//V_TacVest_khk
			0.06,	//V_TacVest_brn
			0.06,	//V_TacVest_oli
			0.06,	//V_TacVest_blk
			0.06,	//V_TacVest_camo
			0.04,	//V_TacVestIR_blk
			0.02	//V_TacVest_gen_F

		}
	};
	
	Military_Headgear[] = {
		{
			"H_Cap_blk_CMMG",
			"H_Cap_blk_Raven",
			"H_Cap_brn_SPECOPS",
			"H_Cap_tan_specops_US",
			"H_Cap_khaki_specops_UK",
			"H_Cap_usblack",
			"H_Beret_blk",
			"H_Beret_grn",
			"H_Beret_brn_SF",
			"H_Beret_grn_SF",
			"H_Beret_ocamo",
			"H_Beret_02",
			"H_Beret_Colonel",
			"H_Booniehat_khk",
			"H_Booniehat_oli",
			"H_Booniehat_mcamo",
			"H_Booniehat_tan",
			"H_Booniehat_dgtl"

		},
		{
			0.05,	//H_Cap_blk_CMMG
			0.05,	//H_Cap_blk_Raven
			0.05,	//H_Cap_brn_SPECOPS
			0.05,	//H_Cap_tan_specops_US
			0.05,	//H_Cap_khaki_specops_UK
			0.05,	//H_Cap_usblack
			0.05,	//H_Beret_blk
			0.05,	//H_Beret_grn
			0.05,	//H_Beret_brn_SF
			0.05,	//H_Beret_grn_SF
			0.05,	//H_Beret_ocamo
			0.05,	//H_Beret_02
			0.05,	//H_Beret_Colonel
			0.05,	//H_Booniehat_khk
			0.05,	//H_Booniehat_oli
			0.05,	//H_Booniehat_mcamo
			0.05,	//H_Booniehat_tan
			0.05	//H_Booniehat_dgtl

		}
	};
	
	Military_Helmet[] = {
		{
			"H_HelmetB_light_grass",
			"H_HelmetB_light_snakeskin",
			"H_HelmetB_light_desert",
			"H_HelmetB_light_black",
			"H_HelmetB_light_sand",
			"H_HelmetB_light_camo",
			"H_HelmetB_grass",
			"H_HelmetB_snakeskin",
			"H_HelmetB_desert",
			"H_HelmetB_black",
			"H_HelmetB_sand",
			"H_HelmetB_camo"

		},
		{
			0.07,	//H_HelmetB_light_grass
			0.07,	//H_HelmetB_light_snakeskin
			0.07,	//H_HelmetB_light_desert
			0.07,	//H_HelmetB_light_black
			0.07,	//H_HelmetB_light_sand
			0.07,	//H_HelmetB_light_camo
			0.03,	//H_HelmetB_grass
			0.03,	//H_HelmetB_snakeskin
			0.03,	//H_HelmetB_desert
			0.03,	//H_HelmetB_black
			0.03,	//H_HelmetB_sand
			0.03	//H_HelmetB_camo
		}
	};

	Military_Gear_Special[] = {
		{
			//Clothes
			"U_B_Pilot_Coveralls",
			"U_B_Wetsuit",
			"U_B_GhillieSuit",
			"U_B_FullGhillie_lsh",
			"U_B_FullGhillie_sard",
			"U_B_FullGhillie_ard",
			//Armor
			"V_PlateCarrierIA1_dgtl",
			"V_PlateCarrier1_rgr",
			"V_PlateCarrier_Kerry",
			//Helmet
			"H_HelmetCrew_B",
			"H_HelmetCrew_O",
			"H_HelmetCrew_I",
			"H_HelmetO_ocamo"

		},
		{
			//Clothes
			0.08,	//U_B_Pilot_Coveralls
			0.06,	//U_B_Wetsuit
			0.04,	//U_B_GhillieSuit
			0.02,	//U_B_FullGhillie_lsh
			0.02,	//U_B_FullGhillie_sard
			0.02,	//U_B_FullGhillie_ard
			//Armor
			0.01,	//V_PlateCarrierIA1_dgtl
			0.01,	//V_PlateCarrier1_rgr
			0.01,	//V_PlateCarrier_Kerry
			//Helmet
			0.01,	//"H_HelmetCrew_B",
			0.01,	//"H_HelmetCrew_O",
			0.01,	//"H_HelmetCrew_I",
			0.01	//"H_HelmetO_ocamo"
		}
	};
			
			
///////////////////////////////////////////////////
//Granadas //addWeaponCargoGlobal
	Offensive_Grenades[] = {
		{
			"HandGrenade",
			"MiniGrenade"
		},
		{
			0.02,	//HandGrenade
			0.02	//MiniGrenade

		}
	};
	
	Smoke_Grenades[] = {
		{
			"SmokeShell",
			"SmokeShellOrange",
			"SmokeShellBlue",
			"SmokeShellPurple",
			"SmokeShellYellow",
			"SmokeShellGreen",
			"SmokeShellRed"
		},
		{
			0.05,	//SmokeShell
			0.05,	//SmokeShell
			0.05,	//SmokeShell
			0.05,	//SmokeShell
			0.05,	//SmokeShell
			0.05,	//SmokeShell
			0.05	//SmokeShell

		}
	};	

	Flare_Grenades[] = {
		{
			"FlareWhite_F",
			"FlareGreen_F",
			"FlareRed_F",
			"FlareYellow_F"
		},
		{
			0.05,	//FlareWhite_F
			0.05,	//FlareGreen_F
			0.05,	//FlareRed_F
			0.05	//FlareYellow_F

		}
	};
	
///////////////////////////////////////////////////
//Flashlights //addWeaponCargoGlobal

	Flashlights[] = {
		{
			"rds_weap_latarka_janta",
			"rds_weap_latarka_lts1"

		},
		{
			0.05,	//Flashlight janta
			0.05	//Flashlight lts1

		}
	};

///////////////////////////////////////////////////
//Pistols //addWeaponCargoGlobal

	Pistols_Low[] = {
		{
			"CUP_hgun_SA61",					//hit: 3
			"CUP_hgun_Duty",					//hit: 4
			"hgun_P07_khk_F",					//hit: 4
			"hgun_P07_F",						//hit: 4
			"hgun_Rook40_F",					//hit: 4
			"CUP_hgun_TaurusTracker455",		//hit: 4
			"CUP_hgun_TaurusTracker455_gold",	//hit: 4
			"CUP_hgun_Colt1911",				//hit: 4
			"hgun_ACPC2_F",						//hit: 4
			"hgun_Pistol_heavy_02_F",			//hit: 4
			"hgun_Pistol_heavy_01_F"			//hit: 4

		},
		{
			0.09,	//SA61
			0.08,	//Duty
			0.06,	//P07
			0.06,	//P07
			0.06,	//Rook40		
			0.05,	//Taurus
			0.04,	//Taurus gold
			0.05,	//Colt1911
			0.05,	//ACPC2
			0.04,	//Pistol heavy 02
			0.03	//Pistol heavy 01

		}
	};

	Mag_Pistols_Low[] = {
		{
			"CUP_20Rnd_B_765x17_Ball_M",	//SA61
			"16Rnd_9x21_Mag",				//Duty,P07,Rook40
			"30Rnd_9x21_Mag",				//P07,Rook40
			"CUP_6Rnd_45ACP_M",				//Taurus
			"CUP_7Rnd_45ACP_1911",			//Colt1911
			"9Rnd_45ACP_Mag",				//ACPC2
			"6Rnd_45ACP_Cylinder",			//Pistol Heavy 02
			"11Rnd_45ACP_Mag"				//Pistol Heavy 01

		},
		{
			0.07,	//SA61
			0.07,	//Duty,P07,Rook40
			0.05,	//P07,Rook40
			0.04,	//Taurus
			0.04,	//Colt1911		
			0.03,	//ACPC2
			0.03,	//Pistol Heavy 02
			0.03	//Pistol Heavy 01

		}
	};		

	Attach_Pistols_Low[] = {
		{
			"CUP_acc_CZ_M3X",	//Duty
			"muzzle_snds_L",	//P07,Rook40
			"muzzle_snds_acp",	//Colt1911,ACPC2,Pistol Heavy 01
			"optic_Yorris",		//Pistol Heavy 02
			"optic_MRD"			//Pistol Heavy 01

		},
		{
			0.05,	//Duty
			0.04,	//P07,Rook40
			0.04,	//Colt1911,ACPC2,Pistol Heavy 01		
			0.03,	//Pistol Heavy 02
			0.03	//Pistol Heavy 01	

		}
	};
		
	Pistols_Low_Special[] = {
		{
			"CUP_hgun_Duty_M3X",				//Duty w/flashlight
			"hgun_P07_snds_F",					//P07 w/sound supressor
			"hgun_Rook40_snds_F",				//Rook40 w/sound supressor
			"CUP_hgun_Colt1911_snds",			//Colt1911 w/sound supressor
			"hgun_ACPC2_snds_F",				//ACPC2 w/sound supressor
			"hgun_Pistol_heavy_02_Yorris_F",	//Pistol Heavy 02 w/optic
			"hgun_Pistol_heavy_01_snds_F",		//Pistol Heavy 01 w/sound supressor
			"hgun_Pistol_heavy_01_MRD_F"		//Pistol Heavy 01 w/optic

		},
		{		
			0.07,	//Duty w/flashlight
			0.07,	//P07 w/sound supressor
			0.07,	//Rook40 w/sound supressor
			0.05,	//Colt1911 w/sound supressor
			0.05,	//ACPC2 w/sound supressor
			0.03,	//Pistol Heavy 02 w/optic
			0.03,	//Pistol Heavy 01 w/sound supressor
			0.03	//Pistol Heavy 01 w/optic
//			0.03	//Pistol Heavy 01 w/optic&sound supressor
		}
	};
		
	Pistols_High[] = {
		{
			"CUP_hgun_Makarov",	//hit: 6
			"CUP_hgun_PB6P9",	//hit: 6
			"CUP_hgun_Compact",	//hit: 6
			"CUP_hgun_M9",		//hit: 6
			"CUP_hgun_Glock17",	//hit: 6
			"CUP_hgun_Phantom",	//hit: 6
			"CUP_hgun_MicroUzi"	//hit: 6

		},
		{
			0.07,	//Makarov
			0.07,	//PB6P9
			0.05,	//Compact
			0.04,	//M9
			0.03,	//Glock17		
			0.03,	//Phantom
			0.02	//MicroUzi	

		}
	};		

	Mag_Pistols_High[] = {
		{
			"CUP_8Rnd_9x18_Makarov_M",		//Makarov,PB6P9
			"CUP_8Rnd_9x18_MakarovSD_M",	//Makarov,PB6P9
			"CUP_10Rnd_9x19_Compact",		//Compact
			"CUP_15Rnd_9x19_M9",			//M9
			"CUP_17Rnd_9x19_glock17",		//Glock17
			"CUP_18Rnd_9x19_Phantom",		//Phantom
			"CUP_30Rnd_9x19_UZI"			//MicroUzi

		},
		{
			0.07,	//Makarov,PB6P9
			0.07,	//Makarov,PB6P9
			0.06,	//Compact
			0.05,	//M9
			0.05,	//Glock17		
			0.05,	//Phantom
			0.03	//MicroUzi		

		}
	};		

	Attach_Pistols_High[] = {
		{
			"CUP_muzzle_PB6P9",				//PB6P9
			"CUP_muzzle_snds_M9",			//M9
			"muzzle_snds_L",				//Glock17,Phantom
			"CUP_acc_CZ_M3X",				//Phantom
			"CUP_acc_Glock17_Flashlight",	//Glock17
			"CUP_muzzle_snds_MicroUzi"		//MicroUzi

		},
		{
			0.07,	//PB6P9
			0.07,	//M9
			0.06,	//Glock17,Phantom
			0.05,	//Phantom
			0.05,	//Glock17		
			0.04	//MicroUzi	

		}
	};		

	Pistols_High_Special[] = {
		{
			"CUP_hgun_PB6P9_snds",				//PB6P9 w/sound supressor
			"CUP_hgun_M9_snds",					//M9 w/sound supressor
			"CUP_hgun_glock17_snds",			//Glock17 w/sound supressor
			"CUP_hgun_glock17_flashlight",		//Glock17 w/flashlight
			"CUP_hgun_glock17_flashlight_snds",	//Glock17 w/flashlight&sound supressor
			"CUP_hgun_Phantom_snds",			//Phantom w/sound supressor
			"CUP_hgun_Phantom_Flashlight",		//Phantom w/flashlight
			"CUP_hgun_Phantom_Flashlight_snds",	//Phantom w/flashlight&sound supressor
			"CUP_hgun_MicroUzi_snds"			//MicroUzi w/sound supressor

		},
		{
			0.07,	//PB6P9 w/sound supressor
			0.07,	//M9 w/sound supressor
			0.06,	//Glock17 w/sound supressor
			0.05,	//Glock17 w/flashlight
			0.04,	//Glock17 w/flashlight&sound supressor
			0.06,	//Phantom w/sound supressor
			0.05,	//Phantom w/flashlight
			0.04,	//Phantom w/flashlight&sound supressor
			0.03	//MicroUzi w/sound supressor

		}
	};		

///////////////////////////////////////////////////
//Rifles //addWeaponCargoGlobal

	ArmasCivis[] = {
		{
			"CUP_srifle_LeeEnfield",		//hit: 14
			"CUP_srifle_LeeEnfield_rail",	//hit: 14
			"CUP_sgun_M1014"				//hit: 25
		},
		{
			0.06,	//CUP_srifle_LeeEnfield
			0.06,	//CUP_srifle_LeeEnfield_rail	
			0.04	//CUP_sgun_M1014				
		}
	};
	
	Mag_ArmasCivis[] = {
		{
			"CUP_15Rnd_9x19_M9",
			"CUP_8Rnd_B_Beneli_74Slug",
			"CUP_8Rnd_B_Beneli_74Pellets"

		},
		{
			0.03,	//CUP_15Rnd_9x19_M9
			0.02,	//CUP_8Rnd_B_Beneli_74Slug
			0.05	//CUP_8Rnd_B_Beneli_74Pellets

		}
	};

///////////////////////////////////////////////////
//ArmasLow e Munições //addWeaponCargoGlobal

//			"hgun_PDW2000_F",
//			"hgun_PDW2000_Holo_F",
//			"hgun_PDW2000_Holo_snds_F",
//			"hgun_PDW2000_snds_F",


	ArmasLow[] = {
		{
			"CUP_smg_MP5SD6",
			"CUP_smg_EVO",
			"CUP_smg_bizon",
			"CUP_smg_bizon_snds",
			"CUP_arifle_M16A2",
			"arifle_Mk20_ACO_F"

		},
		{
			0.06,  //CUP_smg_MP5SD6
			0.06,  //CUP_smg_EVO
			0.06,  //CUP_smg_bizon
			0.02,  //CUP_smg_bizon_snds
			0.05,  //CUP_arifle_M16A2
			0.05   //arifle_Mk20_ACO_F
		}
	};
	
	Mag_ArmasLow[] = {
		{
			"CUP_30Rnd_9x19_MP5",
			"CUP_30Rnd_9x19_EVO",
			"CUP_64Rnd_9x19_Bizon_M",
			"30Rnd_556x45_Stanag"

		},
		{
			0.03,	//CUP_30Rnd_9x19_MP5
			0.02,	//CUP_30Rnd_9x19_EVO
			0.05,	//CUP_64Rnd_9x19_Bizon_M
			0.06    //30Rnd_556x45_Stanag

		}
	};	
///////////////////////////////////////////////////
//ArmasMedias e Munições //addWeaponCargoGlobal

	ArmasMedias[] = {
		{
			"CUP_arifle_AK74",
			"CUP_arifle_AKS74U",
			"CUP_arifle_AK107",
			"CUP_arifle_CZ805_A1",
			"CUP_arifle_CZ805_A2",
			"CUP_arifle_G36A_camo",
			"CUP_arifle_G36C",
			"CUP_arifle_L85A2",
			"CUP_arifle_M16A2",
			"CUP_arifle_M4A1_camo",
			"CUP_arifle_Mk16_STD_FG",
			"CUP_arifle_Mk20",
			"CUP_arifle_XM8_Carbine",
			"CUP_arifle_RPK74_45",
			"CUP_arifle_RPK74M",
			"CUP_srifle_CZ550",
			"CUP_srifle_CZ550_rail",
			"CUP_srifle_Mk12SPR_LeupoldM3LR",
			"CUP_srifle_M14"
		},
		
		{
			0.03, //"CUP_arifle_AK74",
			0.03, //"CUP_arifle_AKS74U",
			0.03, //"CUP_arifle_AK107",
			0.05, //"CUP_arifle_CZ805_A1",
			0.05, //"CUP_arifle_CZ805_A2",
			0.03, //"CUP_arifle_G36A_camo",
			0.03, //"CUP_arifle_G36C",
			0.05, //"CUP_arifle_L85A2",
			0.05, //"CUP_arifle_M16A2",
			0.05, //"CUP_arifle_M4A1_camo",
			0.03, //"CUP_arifle_Mk16_STD_FG",
			0.02, //"CUP_arifle_Mk20",
			0.03, //"CUP_arifle_XM8_Carbine"
			0.04,  //"CUP_arifle_RPK74_45"
			0.04,  //"CUP_arifle_RPK74_45"
			0.02,   //"CUP_srifle_CZ550"
			0.02,   //"CUP_srifle_CZ550_rail"
			0.02,   //"CUP_srifle_Mk12SPR_LeupoldM3LR"
			0.04    //"CUP_srifle_M14"
		}
	};
	
	Mag_ArmasMedias[] = {
		{
			"CUP_30Rnd_762x39_AK47_M",
			"CUP_30Rnd_TE1_Yellow_Tracer_545x39_AK_M",
			"CUP_30Rnd_545x39_AK_M",
			"CUP_30Rnd_TE1_Red_Tracer_556x45_G36",
			"30Rnd_556x45_Stanag",
			"CUP_30Rnd_556x45_Stanag",
			"CUP_30Rnd_556x45_G36",
			"CUP_5x_22_LR_17_HMR_M"

		},
		{
			0.05, // "CUP_30Rnd_762x39_AK47_M",
			0.07, // "CUP_30Rnd_TE1_Yellow_Tracer_545x39_AK_M",
			0.07, // "CUP_30Rnd_545x39_AK_M",
			0.09, // "CUP_30Rnd_TE1_Red_Tracer_556x45_G36",
			0.09, // "30Rnd_556x45_Stanag",
			0.09, // "CUP_30Rnd_556x45_Stanag",
			0.09, // "CUP_30Rnd_556x45_G36"
			0.04  // "CUP_5x_22_LR_17_HMR_M"

		}
	};	
///////////////////////////////////////////////////
//ArmasHigh e Munições //addWeaponCargoGlobal

	ArmasHigh[] = {
		{
			//7.62
			"CUP_arifle_AK47",	
			"CUP_arifle_AKM",
			"CUP_arifle_AKS",
			"CUP_arifle_Sa58P",
			"CUP_arifle_Sa58RIS1",
			"CUP_arifle_Sa58RIS2_camo",
			"CUP_arifle_Sa58V",
			"CUP_arifle_FNFAL_railed",
			"CUP_arifle_Mk17_CQC",

			//LMG
			"CUP_srifle_L129A1",
			"CUP_lmg_Mk48_wdl",
			"CUP_lmg_L110A1",
			"CUP_lmg_Pecheneg",
			"CUP_lmg_UK59",
			"CUP_lmg_L7A2",
			"CUP_lmg_M240",
			"CUP_lmg_M249",
			"CUP_lmg_PKM",

			//Sniper
			"CUP_srifle_SVD_wdl_ghillie",
			"CUP_srifle_M24_ghillie",
			"CUP_srifle_VSSVintorez",
			"CUP_srifle_M107_Base", //M107
			"CUP_srifle_AWM_des", //Lapua Magnum
			"CUP_srifle_CZ550",
			"CUP_srifle_M14"
		},
		{
			//7.62
			0.06,	//CUP_arifle_AK47	
			0.04,	//CUP_arifle_AKM	
			0.04,	//CUP_arifle_AKS
			0.04,	//CUP_arifle_Sa58P
			0.04,	//CUP_arifle_Sa58RIS1
			0.04,	//CUP_arifle_Sa58RIS2_camo
			0.04,	//CUP_arifle_Sa58V
			0.03,	//CUP_arifle_FNFAL_railed
			0.03,	//CUP_arifle_Mk17_CQC

			//LMG
			0.03,	//CUP_srifle_L129A1
			0.03,	//CUP_lmg_Mk48_wdl
			0.03,	//CUP_lmg_L110A1
			0.03,	//CUP_lmg_Pecheneg
			0.03,	//CUP_lmg_UK59
			0.03,	//CUP_lmg_L7A2
			0.03,	//CUP_lmg_M240
			0.03,	//CUP_lmg_M249
			0.03,	//CUP_lmg_PKM

			//Sniper
			0.02,	//CUP_srifle_SVD_wdl_ghillie
			0.02,	//CUP_srifle_M24_ghillie
			0.02,	//CUP_srifle_VSSVintorez
			0.01,	//CUP_srifle_M107_Base //M107
			0.01,	//CUP_srifle_AWM_des
			0.04,	//CUP_srifle_CZ550
			0.04	//CUP_srifle_M14
		}
	};
	
	Mag_ArmasHigh[] = {
		{
			//7.62
			"CUP_30Rnd_762x39_AK47_M",	
			"CUP_30Rnd_Sa58_M",
			"CUP_30Rnd_Sa58_M_TracerG",
			"CUP_20Rnd_762x51_FNFAL_M",
			"CUP_20Rnd_762x51_B_SCAR",
			"20Rnd_762x51_Mag",

			//LMG
			"CUP_200Rnd_TE1_Red_Tracer_556x45_M249",
			"CUP_100Rnd_TE4_Green_Tracer_556x45_M249",
			"CUP_50Rnd_UK59_762x54R_Tracer",
			"CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
			"CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M",
			"CUP_200Rnd_TE4_Red_Tracer_556x45_L110A1",
			"CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M",

			//Sniper
			"CUP_10Rnd_762x54_SVD_M",
			"CUP_5Rnd_762x51_M24",
			"CUP_10Rnd_9x39_SP5_VSS_M",
			"CUP_20Rnd_9x39_SP5_VSS_M",
			"CUP_10Rnd_127x99_m107", //M107
			"CUP_5Rnd_86x70_L115A1", //Lapua Magnum
			"CUP_20Rnd_762x51_DMR"
		},
		{
			//7.62
			0.07,	//CUP_30Rnd_762x39_AK47_M	
			0.06,   //CUP_30Rnd_Sa58_M
			0.05,	//CUP_30Rnd_Sa58_M_TracerG
			0.04,	//CUP_20Rnd_762x51_FNFAL_M
			0.05,   //CUP_20Rnd_762x51_B_SCAR
			0.05,	//20Rnd_762x51_Mag

			//LMG
			0.04,	//CUP_200Rnd_TE1_Red_Tracer_556x45_M249
			0.04,	//CUP_100Rnd_TE4_Green_Tracer_556x45_M249
			0.04,	//CUP_50Rnd_UK59_762x54R_Tracer
			0.04,	//CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M
			0.04,	//CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M
			0.04,	//CUP_200Rnd_TE4_Red_Tracer_556x45_L110A1
			0.04,	//CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M

			//Sniper
			0.04,	//CUP_10Rnd_762x54_SVD_M
			0.04,	//CUP_5Rnd_762x51_M24
			0.03,	//CUP_10Rnd_9x39_SP5_VSS_M
			0.02,	//CUP_20Rnd_9x39_SP5_VSS_M
			0.01,	//CUP_10Rnd_127x99_m107 //M107
			0.01,	//CUP_5Rnd_86x70_L115A1 //Lapua Magnum
			0.05	//CUP_20Rnd_762x51_DMR

		}
	};		
///////////////////////////////////////////////////
//"AcessoriosLow"
//"AcessoriosMedias"
//"AcessoriosHigh"
//Acessorios //addItemCargoGlobal

	Acessorios_Optic[] = {
		{
			"optic_MRCO",	//MRCO ARMA 3
			"optic_SOS",	//SOS ARMA
			"optic_DMS",	//DMS ARMA
			"optic_LRPS",	//LRPS ARMA
			"CUP_optic_Kobra",
			"CUP_optic_HoloBlack",
			"CUP_optic_HoloWdl",
			"CUP_optic_HoloDesert",
			"CUP_optic_Eotech533",
			"CUP_optic_Eotech533Grey",
			"CUP_optic_CompM4",
			"CUP_optic_CompM2_Black",
			"CUP_optic_CompM2_Woodland",
			"CUP_optic_CompM2_Woodland2",
			"CUP_optic_CompM2_Desert",
			"CUP_optic_TrijiconRx01_desert",
			"CUP_optic_TrijiconRx01_black",
			"CUP_optic_SB_11_4x20_PM",
			"CUP_optic_ZDDot",
			"CUP_optic_MRad",
			"CUP_optic_RCO",
			"CUP_optic_RCO_desert",
			"CUP_optic_ACOG",
			"CUP_optic_SUSAT",
			"CUP_optic_ElcanM145",
			"CUP_optic_ELCAN_SpecterDR",
			"CUP_optic_PSO_1",
			"CUP_optic_PSO_3",
			"CUP_optic_SB_3_12x50_PMII",
			"CUP_optic_LeupoldMk4",
			"CUP_optic_Leupold_VX3",
			"CUP_optic_LeupoldM3LR",
			"CUP_optic_LeupoldMk4_10x40_LRT_Desert",
			"CUP_optic_LeupoldMk4_10x40_LRT_Woodland",
			"CUP_optic_LeupoldMk4_CQ_T",
			"CUP_optic_LeupoldMk4_MRT_tan",
			"CUP_optic_PechenegScope",
			"CUP_muzzle_snds_AWM",
			"CUP_muzzle_PBS4",
			"CUP_muzzle_PB6P9",
			"CUP_muzzle_Bizon",
			"CUP_muzzle_snds_G36_black",
			"CUP_muzzle_snds_G36_desert",
			"CUP_muzzle_snds_L85",
			"CUP_muzzle_snds_M110",
			"CUP_muzzle_snds_M14",
			"CUP_muzzle_snds_M16_camo",
			"CUP_muzzle_snds_M16",
			"CUP_muzzle_snds_M9",
			"CUP_muzzle_snds_MicroUzi",
			"CUP_muzzle_snds_XM8",
			"CUP_muzzle_snds_SCAR_L",
			"CUP_muzzle_snds_SCAR_H",
			"CUP_muzzleFlash2SCAR_L",
			"CUP_muzzle_mfsup_SCAR_L",
			"CUP_muzzle_mfsup_SCAR_H",
			"CUP_acc_ANPEQ_15",
			"CUP_acc_ANPEQ_2",
			"CUP_acc_ANPEQ_2_camo",
			"CUP_acc_ANPEQ_2_desert",
			"CUP_acc_ANPEQ_2_grey",
			"CUP_acc_Flashlight",
			"CUP_acc_Flashlight_wdl",
			"CUP_acc_Flashlight_desert",
			"CUP_acc_XM8_light_module",
			"CUP_acc_CZ_M3X",
			"CUP_acc_Glock17_Flashlight"

		},
		{
			0.03, // "optic_MRCO",	//MRCO ARMA 3
			0.02, // "optic_SOS",	//SOS ARMA
			0.02, // "optic_DMS",	//DMS ARMA
			0.02, // "optic_LRPS",	//LRPS ARMA
			0.05, // "CUP_optic_Kobra",
			0.05, // "CUP_optic_HoloBlack",
			0.05, // "CUP_optic_HoloWdl",
			0.05, // "CUP_optic_HoloDesert",
			0.03, // "CUP_optic_Eotech533",
			0.03, // "CUP_optic_Eotech533Grey",
			0.05, // "CUP_optic_CompM4",
			0.05, // "CUP_optic_CompM2_Black",
			0.05, // "CUP_optic_CompM2_Woodland",
			0.05, // "CUP_optic_CompM2_Woodland2",
			0.05, // "CUP_optic_CompM2_Desert",
			0.04, // "CUP_optic_TrijiconRx01_desert",
			0.04, // "CUP_optic_TrijiconRx01_black",
			0.03, // "CUP_optic_SB_11_4x20_PM",
			0.05, // "CUP_optic_ZDDot",
			0.03, // "CUP_optic_MRad",
			0.05, // "CUP_optic_RCO",
			0.05, // "CUP_optic_RCO_desert",
			0.04, // "CUP_optic_ACOG",
			0.03, // "CUP_optic_SUSAT",
			0.03, // "CUP_optic_ElcanM145",
			0.03, // "CUP_optic_ELCAN_SpecterDR",
			0.04, // "CUP_optic_PSO_1",
			0.04, // "CUP_optic_PSO_3",
			0.02, // "CUP_optic_SB_3_12x50_PMII",
			0.02, // "CUP_optic_LeupoldMk4",
			0.02, // "CUP_optic_Leupold_VX3",
			0.02, // "CUP_optic_LeupoldM3LR",
			0.02, // "CUP_optic_LeupoldMk4_10x40_LRT_Desert",
			0.02, // "CUP_optic_LeupoldMk4_10x40_LRT_Woodland",
			0.02, // "CUP_optic_LeupoldMk4_CQ_T",
			0.02, // "CUP_optic_LeupoldMk4_MRT_tan",
			0.02, // "CUP_optic_PechenegScope",
			0.02, // "CUP_muzzle_snds_AWM",
			0.02, // "CUP_muzzle_PBS4",
			0.02, // "CUP_muzzle_PB6P9",
			0.02, // "CUP_muzzle_Bizon",
			0.02, // "CUP_muzzle_snds_G36_black",
			0.02, // "CUP_muzzle_snds_G36_desert",
			0.02, // "CUP_muzzle_snds_L85",
			0.02, // "CUP_muzzle_snds_M110",
			0.02, // "CUP_muzzle_snds_M14",
			0.02, // "CUP_muzzle_snds_M16_camo",
			0.02, // "CUP_muzzle_snds_M16",
			0.02, // "CUP_muzzle_snds_M9",
			0.02, // "CUP_muzzle_snds_MicroUzi",
			0.02, // "CUP_muzzle_snds_XM8",
			0.02, // "CUP_muzzle_snds_SCAR_L",
			0.02, // "CUP_muzzle_snds_SCAR_H",
			0.02, // "CUP_muzzleFlash2SCAR_L",
			0.02, // "CUP_muzzle_mfsup_SCAR_L",
			0.02, // "CUP_muzzle_mfsup_SCAR_H",
			0.03, // "CUP_acc_ANPEQ_15",
			0.03, // "CUP_acc_ANPEQ_2",
			0.03, // "CUP_acc_ANPEQ_2_camo",
			0.03, // "CUP_acc_ANPEQ_2_desert",
			0.03, // "CUP_acc_ANPEQ_2_grey",
			0.03, // "CUP_acc_Flashlight",
			0.03, // "CUP_acc_Flashlight_wdl",
			0.03, // "CUP_acc_Flashlight_desert",
			0.03, // "CUP_acc_XM8_light_module",
			0.03, // "CUP_acc_CZ_M3X",
			0.03 // "CUP_acc_Glock17_Flashlight"

		}
	};
};	
