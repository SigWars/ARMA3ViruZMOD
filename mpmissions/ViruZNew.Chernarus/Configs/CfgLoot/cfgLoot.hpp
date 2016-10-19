class CfgLoot {
	trash[] = {
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
			"ItemSodaLaranjaEmpty",
			"ItemSodaLimaoEmpty",
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
	Parts[] = {
		{
			"PartWheel",
			"PartFueltank",
			"PartEngine",
			"PartGlass",
			"PartVRotor",
			"ItemJerrycan"

		},
		{
			0.09,
			0.07,
			0.05,
			0.06,
			0.03,
			0.04
			
		}
	};
	ferramentas[] = {
		{
			"Viruz_Hammer",
			"Viruz_Serrote",
			"Viruz_Wrench",
			"ItemSandbag",
			"ItemWire",
			"equip_nails"
			
		},
		{
			0.05,	//martelo
			0.05,	//serrote
			0.05,	//chave de boca
			0.02,	//saco de areia
			0.04,	//cabo de metal
			0.04	//pregos
				
		}
	};
	medical_lite[] = {
		{
			"ItemBandage",
			"ItemPainkiller",
			"ItemAntibiotic",
			"ItemHeatPack"
			
		},
		{
			0.05,
			0.05,
			0.04,
			0.03
		}
	};
	medical_especial[] = {
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
	melee_lite[] = {
		//addWeaponCargoGlobal
		{
			"ItemKnife",
			"HandFlashlight"
						
		},
		{
			0.04,	//ItemKnife
			0.07	//HandFlashlight
		}
	};
	melee_especial[] = {
		//addWeaponCargoGlobal
		{
			"MeleeHatchet",
			"HandFlashlight",
			"ItemKnife"
			
		},
		{
			0.07,	//MeleeHatchet
			0.02,	//HandFlashlight
			0.04	//faca
		}
	};
	pistol_lite[] = {
		//addWeaponCargoGlobal
		{
			"hgun_P07_F", 					//p07
			"hgun_P07_snds_F", 				//p07 c silence
			"hgun_Rook40_F",				//Rook 40
			"hgun_Rook40_snds_F", 			//Rook com silence
			"hgun_Pistol_heavy_02_F",		//Pistola de tambor 45
			"hgun_Pistol_heavy_02_Yorris_F" //Pistola de tambor com mira
									
		},
		{
			0.07,	//p07
			0.02,	//p07 c silence
			0.07,	//Rook 40
			0.02,	//Rook com silence
			0.03, 	//Pistola de tambor 45
			0.01	//Pistola de tambor com mira
						
		}
	};
	pistol_especial[] = {
		//addWeaponCargoGlobal
		{
			"hgun_ACPC2_F", 				//acp 45
			"hgun_ACPC2_snds_F", 			//acp 45 com silence
			"hgun_Pistol_heavy_01_F", 		//4-five 45
			"hgun_Pistol_heavy_01_snds_F",	//4-five 45 c silence
			"hgun_Pistol_heavy_01_MRD_F",	//4-five 45 silence e mira
			"CUP_hgun_Colt1911",
			"CUP_hgun_Compact",
			"CUP_hgun_Makarov",
			"CUP_hgun_MicroUzi",
			"CUP_hgun_TaurusTracker455",
			"CUP_hgun_M9",
			"CUP_hgun_SA61",
			"CUP_hgun_Duty",
			"CUP_hgun_Phantom",
			"CUP_hgun_PB6P9",
			"CUP_hgun_Glock17"
			
		},
		{
			0.04, // "hgun_ACPC2_F", 				//acp 45
			0.03, // "hgun_ACPC2_snds_F", 			//acp 45 com silence
			0.04, // "hgun_Pistol_heavy_01_F", 		//4-five 45
			0.03, //"hgun_Pistol_heavy_01_snds_F",	//4-five 45 c silence
			0.03, //"hgun_Pistol_heavy_01_MRD_F",	//4-five 45 silence e mira
			0.04, //"CUP_hgun_Colt1911",
			0.04, //"CUP_hgun_Compact",
			0.04, //0.04, //"CUP_hgun_Makarov",
			0.02, //"CUP_hgun_MicroUzi",
			0.04, //"CUP_hgun_TaurusTracker455",
			0.04, //"CUP_hgun_M9",
			0.04, //"CUP_hgun_SA61",
			0.04, //"CUP_hgun_Duty",
			0.04, //"CUP_hgun_Phantom",
			0.03, //"CUP_hgun_PB6P9",
			0.04 //"CUP_hgun_Glock17"
			
			
		}
	};
	weapons_lmg[] = {	//large machine gun
		//addWeaponCargoGlobal
		{
			"CUP_lmg_Mk48_wdl",
			"CUP_lmg_L110A1",
			"CUP_lmg_Pecheneg",
			"CUP_lmg_UK59",
			"CUP_lmg_L7A2",
			"CUP_lmg_M240",
			"CUP_lmg_M249",
			"CUP_lmg_PKM"		
			
		},
		{
			0.04, //"CUP_lmg_Mk48_wdl",
			0.09, //"CUP_lmg_L110A1",
			0.04, //"CUP_lmg_Pecheneg",
			0.01, //"CUP_lmg_UK59",
			0.04, //"CUP_lmg_L7A2",
			0.04, //"CUP_lmg_M240",
			0.09, //"CUP_lmg_M249",
			0.01 //"CUP_lmg_PKM"
			
		}
	};
	weapons_smg[] = {	//small machine gun
		//addWeaponCargoGlobal
		{
			"CUP_smg_MP5SD6",
			"CUP_smg_EVO",
			"CUP_smg_bizon",
			"CUP_arifle_M16A2"
			
		},
		{
			0.06,  //"CUP_smg_MP5SD6",
			0.06,  //"CUP_smg_EVO",
			0.06,  //"CUP_smg_bizon",
			0.05	//"CUP_arifle_M16A2"
		}
	};
	weapons_rifle[] = {
		//addWeaponCargoGlobal
		{
		"CUP_arifle_AKS",
		"CUP_arifle_AK74",
		"CUP_arifle_AKS74U",
		"CUP_arifle_AK107",
		"CUP_arifle_AKM",
		"CUP_arifle_CZ805_A1",
		"CUP_arifle_CZ805_A2",
		"CUP_arifle_FNFAL_railed",
		"CUP_arifle_G36A_camo",
		"CUP_arifle_G36C",
		"CUP_arifle_L85A2",
		"CUP_arifle_M16A2",
		"CUP_arifle_M4A1_camo",
		"CUP_arifle_Sa58V",
		"CUP_arifle_Sa58RIS2",
		"CUP_arifle_Mk16_STD_FG",
		"CUP_arifle_Mk17_CQC",
		"CUP_arifle_Mk20",
		"CUP_arifle_XM8_Carbine"
		},
		
		{
		0.03, //"CUP_arifle_AKS",
		0.03, //"CUP_arifle_AK74",
		0.03, //"CUP_arifle_AKS74U",
		0.03, //"CUP_arifle_AK107",
		0.03, //"CUP_arifle_AKM",
		0.05, //"CUP_arifle_CZ805_A1",
		0.05, //"CUP_arifle_CZ805_A2",
		0.02, //"CUP_arifle_FNFAL_railed",
		0.03, //"CUP_arifle_G36A_camo",
		0.03, //"CUP_arifle_G36C",
		0.05, //"CUP_arifle_L85A2",
		0.05, //"CUP_arifle_M16A2",
		0.05, //"CUP_arifle_M4A1_camo",
		0.03, //"CUP_arifle_Sa58V",
		0.03, //"CUP_arifle_Sa58RIS2",
		0.03, //"CUP_arifle_Mk16_STD_FG",
		0.02, //"CUP_arifle_Mk17_CQC",
		0.02, //"CUP_arifle_Mk20",
		0.03 //"CUP_arifle_XM8_Carbine"
		}
	};
	snipe_drm[] = {
		//addWeaponCargoGlobal
		{
		"CUP_srifle_AWM_wdl",
		"CUP_srifle_CZ550",
		"CUP_srifle_CZ750",
		"CUP_srifle_DMR",
		"CUP_srifle_M40A3",
		"CUP_srifle_M110",
		"CUP_srifle_VSSVintorez",
		"CUP_srifle_ksvk"
			
		},
		{
		0.03, //"CUP_srifle_AWM_wdl",
		0.03, //"CUP_srifle_CZ550",
		0.03, //"CUP_srifle_CZ750",
		0.03, //"CUP_srifle_DMR",
		0.03, //"CUP_srifle_M40A3",
		0.05, //"CUP_srifle_M110",
		0.07, //"CUP_srifle_VSSVintorez",
		0.01 //"CUP_srifle_ksvk"
			
		}
	};
	snipe_especial[] = {
		//addWeaponCargoGlobal
		{
		"CUP_srifle_SVD_wdl_ghillie",
		"CUP_srifle_M24_ghillie"
			
			
		},
		{
		0.01, //"CUP_srifle_SVD_wdl_ghillie",
		0.02 //"CUP_srifle_M24_ghillie"
		}
	};
	mag_pistol_lite[] = {
		{
		"16Rnd_9x21_Mag",
		"30Rnd_9x21_Mag",
		"16Rnd_9x21_Mag",
		"30Rnd_9x21_Mag",
		"6Rnd_45ACP_Cylinder"
			
		},
		{
		0.03, //"16Rnd_9x21_Mag",
		0.02, //"30Rnd_9x21_Mag",
		0.03, //"16Rnd_9x21_Mag",
		0.02, //"30Rnd_9x21_Mag",
		0.02 //"6Rnd_45ACP_Cylinder"
		}
	};
	mag_pistol_especial[] = {
		{
			"9Rnd_45ACP_Mag",
			"11Rnd_45ACP_Mag",
			"11Rnd_45ACP_Mag",
			"CUP_7Rnd_45ACP_1911",
			"CUP_10Rnd_9x19_Compact",
			"CUP_8Rnd_9x18_Makarov_M",
			"CUP_8Rnd_9x18_MakarovSD_M",
			"CUP_30Rnd_9x19_UZI",
			"CUP_6Rnd_45ACP_M",
			"CUP_15Rnd_9x19_M9",
			"CUP_20Rnd_B_765x17_Ball_M",
			"CUP_20Rnd_B_765x17_Ball_M",
			"16Rnd_9x21_Mag",
			"CUP_18Rnd_9x19_Phantom",
			"CUP_17Rnd_9x19_glock17"
			
		},
		{
			0.04, // "9Rnd_45ACP_Mag",
			0.04, // "11Rnd_45ACP_Mag",
			0.04, // "11Rnd_45ACP_Mag",
			0.04, // "CUP_7Rnd_45ACP_1911",
			0.04, // "CUP_10Rnd_9x19_Compact",
			0.04, // "CUP_8Rnd_9x18_Makarov_M",
			0.04, // "CUP_8Rnd_9x18_MakarovSD_M",
			0.04, // "CUP_30Rnd_9x19_UZI",
			0.04, // "CUP_6Rnd_45ACP_M",
			0.04, // "CUP_15Rnd_9x19_M9",
			0.04, // "CUP_20Rnd_B_765x17_Ball_M",
			0.04, // "CUP_20Rnd_B_765x17_Ball_M",
			0.04, // "16Rnd_9x21_Mag",
			0.04, // "CUP_18Rnd_9x19_Phantom",
			0.04 // "CUP_17Rnd_9x19_glock17"
		}
	};
	magazine_lmg[] = { //large machine gun
		{
			"CUP_200Rnd_TE1_Red_Tracer_556x45_M249",
			"CUP_100Rnd_TE4_Green_Tracer_556x45_M249",
			"CUP_50Rnd_UK59_762x54R_Tracer",
			"CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
			"CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M",
			"CUP_200Rnd_TE4_Red_Tracer_556x45_L110A1",
			"CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M"
			
		},
		{
			0.04, // "CUP_200Rnd_TE1_Red_Tracer_556x45_M249",
			0.06, // "CUP_100Rnd_TE4_Green_Tracer_556x45_M249",
			0.02, // "CUP_50Rnd_UK59_762x54R_Tracer",
			0.03, // "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
			0.03, // "CUP_100Rnd_TE4_LRT4_White_Tracer_762x51_Belt_M",
			0.04, // "CUP_200Rnd_TE4_Red_Tracer_556x45_L110A1",
			0.02 // "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M"
		}
	};
	magazine_smg[] = {	//small machine gun
		{
			"CUP_30Rnd_9x19_MP5",	//
			"CUP_30Rnd_9x19_EVO", //mp5 9mm
			"CUP_64Rnd_9x19_Bizon_M",
			"CUP_30Rnd_556x45_Stanag" //m16 mags
		},
		{
			0.03, //"CUP_smg_MP5SD6",
			0.03, //"CUP_smg_EVO",
			0.03, //"CUP_smg_bizon",
			0.02  //m16
		}
	};
	magazine_rifle[] = {
		{
		"CUP_30Rnd_762x39_AK47_M",
		"CUP_30Rnd_TE1_Yellow_Tracer_545x39_AK_M",
		"CUP_30Rnd_545x39_AK_M",
		"CUP_30Rnd_TE1_Red_Tracer_556x45_G36",
		"CUP_20Rnd_762x51_FNFAL_M",
		"30Rnd_556x45_Stanag",
		"CUP_30Rnd_556x45_Stanag",
		"CUP_30Rnd_556x45_G36",
		"CUP_30Rnd_Sa58_M",
		"CUP_20Rnd_762x51_B_SCAR"

		},
		{
		0.05, // "CUP_30Rnd_762x39_AK47_M",
		0.07, // "CUP_30Rnd_TE1_Yellow_Tracer_545x39_AK_M",
		0.07, // "CUP_30Rnd_545x39_AK_M",
		0.09, // "CUP_30Rnd_TE1_Red_Tracer_556x45_G36",
		0.03, // "CUP_20Rnd_762x51_FNFAL_M",
		0.09, // "30Rnd_556x45_Stanag",
		0.09, // "CUP_30Rnd_556x45_Stanag",
		0.09, // "CUP_30Rnd_556x45_G36",
		0.05, // "CUP_30Rnd_Sa58_M",
		0.03 // "CUP_20Rnd_762x51_B_SCAR"

		}
	};
	magazine_dmr[] = {
		{
			"CUP_5Rnd_86x70_L115A1",
			"CUP_5x_22_LR_17_HMR_M",
			"CUP_10Rnd_762x51_CZ750_Tracer",
			"CUP_20Rnd_762x51_DMR",
			"CUP_5Rnd_762x51_M24",
			"CUP_20Rnd_762x51_B_M110",
			"CUP_10Rnd_9x39_SP5_VSS_M"
			
		},
		{
			0.02,	// "CUP_5Rnd_86x70_L115A1"
			0.01,	// "CUP_5x_22_LR_17_HMR_M"
			0.02,	// "CUP_10Rnd_762x51_CZ750_Tracer"
			0.01,	// "CUP_20Rnd_762x51_DMR"
			0.01,	// "CUP_5Rnd_762x51_M24"
			0.03,	// "CUP_20Rnd_762x51_B_M110"
			0.04	// "CUP_10Rnd_9x39_SP5_VSS_M"
		}
	};
	magazine_sniper[] = {
		{
			"CUP_10Rnd_762x54_SVD_M",
			"CUP_5Rnd_762x51_M24"
			
		},
		{
			0.02, // "CUP_10Rnd_762x54_SVD_M",
			0.02 // "CUP_5Rnd_762x51_M24"
		}
	};
	items_item[] = {
		//addItemCargoGlobal
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
	items_magazine[] = {
		//addItemCargoGlobal
		{
			"ItemMatchbox",
			"equip_nails",
			"Viruz_Hammer",
			"Viruz_Serrote",
			"Viruz_Wrench",
			"Viruz_HandCan",
			"Viruz_Laptop",
			"Viruz_MobilePhone",
			"Viruz_SmartPhone",
			"FMradio_Mag",
			"Chemlight_green",
			"Chemlight_red",
			"Chemlight_yellow",
			"Chemlight_blue"

	
		},
		{
			0.08, 	//ItemMatchbox
			0.02, 	//equip_nails
			0.02,	//Martelo
			0.02,	//Serrote
			0.02,	//Chave de porca
			0.02, 	//HandCam
			0.04, 	//Laptop
			0.04, 	//MobilePhone
			0.04, 	//SmartPhone
			0.04,	//Radio FM
			0.02,	//Chemlight_green
			0.02,	//Chemlight_red
			0.02,	//Chemlight_yellow
			0.02	//Chemlight_blue	

		}
	};
	backpack_leves[] = {
		{
			"CUP_B_ACRScout_m95", // 60
			"CUP_B_AssaultPack_ACU", // 150
			"CUP_B_AssaultPack_Black", // 150
			"CUP_B_AssaultPack_Coyote", // 150
			"B_AssaultPack_khk", // 160
			"B_AssaultPack_Kerry", // 160
			"CUP_B_MedicPack_ACU" // 150
			
		},
		{
			0.06, //"CUP_B_ACRScout_m95",
			0.03, //"CUP_B_AssaultPack_ACU",
			0.03, //"CUP_B_AssaultPack_Black",
			0.03, //"CUP_B_AssaultPack_Coyote",
			0.02, //"B_AssaultPack_khk",
			0.02, //"B_AssaultPack_Kerry",
			0.03 //"CUP_B_MedicPack_ACU"
		}
	};
	drink[] = {
		{
			"ItemSodaOriginal",  
			"ItemSodaDarth",
			"ItemSodaDiet",
			"ItemSodaGrape",
			"ItemSodaHam",
			"ItemSodaLaranja",
			"ItemSodaLimao",
			"ItemSodaYoda", 
			"ItemSodaBeergolden"

		},
		{
			0.05,	//ItemSodaOriginal
			0.05,	//ItemSodaDarth
			0.05,	//ItemSodaDiet
			0.05,	//ItemSodaGrape
			0.05,	//ItemSodaHam
			0.05,	//"ItemSodaLaranja
			0.05,	//ItemSodaLimao
			0.05,	//ItemSodaYoda
			0.05	//ItemSodaBeergolden

		}
	};
	food[] = {
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
	furniture_food[] = {
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
			"FoodCanSpaghetti2",
			"ItemSodaOriginal",  
			"ItemSodaDarth",
			"ItemSodaDiet",
			"ItemSodaGrape",
			"ItemSodaHam",
			"ItemSodaLaranja",
			"ItemSodaLimao",
			"ItemSodaYoda", 
			"ItemSodaBeergolden"
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
			0.03,	//FoodCanSpaghetti2
			0.03,	//ItemSodaOriginal
			0.03,	//ItemSodaDarth
			0.03,	//ItemSodaDiet
			0.03,	//ItemSodaGrape
			0.03,	//ItemSodaHam
			0.03,	//ItemSodaLaranja
			0.03,	//ItemSodaLimao
			0.03,	//ItemSodaYoda
			0.03	//ItemSodaBeergolden
		}
	};
	policeman[] = {
		{
			"ItemBandage",
			"16Rnd_9x21_Mag"
		},
		{
			0.8,
			0.8
		}
	};
	boat_backpack[] = {
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
	backpack[] = {
		{
			"B_Kitbag_cbr", // 280
			"B_Kitbag_sgg", // 280
			"CUP_B_GER_Medic_FLecktarn", // 200
			"CUP_B_SLA_Medicbag", // 280
			"CUP_B_RPGPack_Khaki", // 180
			"CUP_B_AlicePack_Khaki", // 300
			"CUP_B_CivPack_WDL", // 280
			"CUP_B_ACRPara_m95", // 300
			"CUP_B_GER_Pack_Flecktarn", // 280
			"CUP_B_GER_Pack_Tropentarn", // 280
			"CUP_B_HikingPack_Civ", // 300
			"CUP_B_USPack_Black", // 280
			"CUP_B_USPack_Coyote", // 280
			"CUP_B_USMC_AssaultPack", // 200
			"CUP_B_USMC_MOLLE", // 300
			"CUP_B_USMC_MOLLE_WDL", // 300
			"B_Carryall_khk", // 320
			"B_Carryall_ocamo" // 320
			
			
		},
		{
			0.03, // "B_Kitbag_cbr"
			0.03, // "B_Kitbag_sgg"
			0.05, // "CUP_B_GER_Medic_FLecktarn"
			0.03, // "CUP_B_SLA_Medicbag"
			0.06, // "CUP_B_RPGPack_Khaki"
			0.02, // "CUP_B_AlicePack_Khaki"
			0.03, // "CUP_B_CivPack_WDL"
			0.02, // "CUP_B_ACRPara_m95"
			0.03, // "CUP_B_GER_Pack_Flecktarn"
			0.03, // "CUP_B_GER_Pack_Tropentarn"
			0.02, // "CUP_B_HikingPack_Civ"
			0.03, // "CUP_B_USPack_Black"
			0.03, // "CUP_B_USPack_Coyote"
			0.05, // "CUP_B_USMC_AssaultPack"
			0.02, // "CUP_B_USMC_MOLLE"
			0.02, // "CUP_B_USMC_MOLLE_WDL"
			0.01, // "B_Carryall_khk"
			0.01 // "B_Carryall_ocamo"
		}
	};
	vest[] = {
		{
			"V_Rangemaster_belt",
			"V_BandollierB_khk",
			"V_BandollierB_cbr",
			"V_BandollierB_rgr",
			"V_BandollierB_blk",
			"V_BandollierB_oli",
			"V_Chestrig_khk",
			"V_Chestrig_rgr",
			"V_Chestrig_blk",
			"V_Chestrig_oli",
			"V_TacVest_khk",
			"V_TacVest_brn",
			"V_TacVest_oli",
			"V_TacVest_blk",
			"V_TacVest_camo",
			"V_TacVest_blk_POLICE",
			"V_TacVestIR_blk",
			"V_TacVestCamo_khk",
			"V_HarnessO_brn",
			"V_HarnessOGL_brn",
			"V_HarnessO_gry",
			"V_HarnessOGL_gry",
			"V_HarnessOSpec_brn",
			"V_HarnessOSpec_gry",
			"V_RebreatherB",
			"V_RebreatherIR",
			"V_RebreatherIA"			
		},
		{
			0.05,	// V_Rangemaster_belt
			0.05,	// V_BandollierB_khk
			0.05,	// V_BandollierB_cbr
			0.05,	// V_BandollierB_rgr
			0.05,	// V_BandollierB_blk
			0.05,	// V_BandollierB_oli
			0.03,	// V_Chestrig_khk
			0.03,	// V_Chestrig_rgr
			0.03,	// V_Chestrig_blk
			0.03,	// V_Chestrig_oli
			0.02,	// V_TacVest_khk
			0.02,	// V_TacVest_brn
			0.02,	// V_TacVest_oli
			0.02,	// V_TacVest_blk
			0.02,	// V_TacVest_camo
			0.02,	// V_TacVest_blk_POLICE
			0.02,	// V_TacVestIR_blk
			0.02,	// V_TacVestCamo_khk
			0.04,	// V_HarnessO_brn
			0.04,	// V_HarnessOGL_brn
			0.04,	// V_HarnessO_gry
			0.04,	// V_HarnessOGL_gry
			0.04,	// V_HarnessOSpec_brn
			0.04,	// V_HarnessOSpec_gry
			0.01,	// V_RebreatherB
			0.01,	// V_RebreatherIR
			0.01	// V_RebreatherIA			
		}
	};
	trow[] = {
		{
			"HandGrenade",
			"MiniGrenade",
			"SmokeShell",
			"SmokeShellOrange",
			"SmokeShellBlue",
			"SmokeShellPurple",
			"SmokeShellYellow",
			"SmokeShellGreen",
			"SmokeShellRed",
			"FlareWhite_F",
			"FlareGreen_F",
			"FlareRed_F",
			"FlareYellow_F"
		},
		{
			0.02,	//HandGrenade
			0.02,	//MiniGrenade
			0.05,	//SmokeShell
			0.05,	//SmokeShell
			0.05,	//SmokeShell
			0.05,	//SmokeShell
			0.05,	//SmokeShell
			0.05,	//SmokeShell
			0.05,	//SmokeShell
			0.05,	//FlareWhite_F
			0.05,	//FlareGreen_F
			0.05,	//FlareRed_F
			0.05	//FlareYellow_F
		}
	};
	glasses_civilian[] = {
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
	glasses_military[] = {
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
	uniform_civilian[] = {
		{	//ARMA 3 ROUPAS CIVIS by LeoHN
			"U_C_Poloshirt_blue",
			"U_C_Poloshirt_burgundy",
			"U_C_Poloshirt_stripped",
			"U_C_Poloshirt_tricolour",
			"U_C_Poloshirt_salmon",
			"U_C_Poloshirt_redwhite",
			"U_C_Poor_1",
			"U_C_HunterBody_grn",
			"U_I_G_Story_Protagonist_F",
			"U_I_G_resistanceLeader_F",
			"U_BG_Guerrilla_6_1",
			"U_Marshal",
			"U_Competitor",
			//ROUPAS CIVIS DO MOD
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
			"rds_uniform_Functionary1",
			"rds_uniform_Functionary2",
			"rds_uniform_Policeman",
			//COLETES CIVIS
			"V_Rangemaster_belt",
			"V_BandollierB_khk",
			"V_BandollierB_cbr",
			"V_BandollierB_rgr",
			"V_BandollierB_blk",
			"V_BandollierB_oli",
			"V_Chestrig_khk",
			"V_Chestrig_rgr",
			"V_Chestrig_blk",
			"V_Chestrig_oli",
			"V_TacVest_khk",
			"V_TacVest_brn",
			"V_TacVest_oli",
			"V_TacVest_blk",
			"V_TacVest_camo",
			"V_TacVest_blk_POLICE",
			"V_TacVestIR_blk",
			"V_TacVestCamo_khk"
		},
		{
			//ARMA 3 ROUPAS CIVIS by LeoHN
			0.03,	//U_C_Poloshirt_blue",
			0.03,	//U_C_Poloshirt_burgundy",
			0.03,	//U_C_Poloshirt_stripped",
			0.03,	//U_C_Poloshirt_tricolour",
			0.03,	//U_C_Poloshirt_salmon",
			0.03,	//U_C_Poloshirt_redwhite",
			0.03,	//U_C_Poor_1",
			0.03,	//U_C_HunterBody_grn",
			0.03,	//U_I_G_Story_Protagonist_F",
			0.03,	//U_I_G_resistanceLeader_F",
			0.03,	//U_BG_Guerrilla_6_1",
			0.03,	//U_Marshal",
			0.03,	//U_Competitor",
			//ROUPAS CIVIS DO MOD
			0.05,	//rds_uniform_citizen1",
			0.05,	//rds_uniform_citizen2",
			0.05,	//rds_uniform_citizen3",
			0.05,	//rds_uniform_citizen4",
			0.05,	//rds_uniform_Profiteer1",
			0.05,	//rds_uniform_Profiteer2",
			0.05,	//rds_uniform_Profiteer3",
			0.05,	//rds_uniform_Profiteer4",
			0.05,	//rds_uniform_Woodlander1",
			0.05,	//rds_uniform_Woodlander2",
			0.05,	//rds_uniform_Woodlander3",
			0.05,	//rds_uniform_Woodlander4",
			0.05,	//rds_uniform_Functionary1",
			0.05,	//rds_uniform_Functionary2",
			0.05,	//rds_uniform_Policeman",
			//COLETES CIVIS
			0.05,	//V_Rangemaster_belt",
			0.05,	//V_BandollierB_khk",
			0.05,	//V_BandollierB_cbr",
			0.05,	//V_BandollierB_rgr",
			0.05,	//V_BandollierB_blk",
			0.05,	//V_BandollierB_oli",
			0.03,	//V_Chestrig_khk",
			0.03,	//V_Chestrig_rgr",
			0.03,	//V_Chestrig_blk",
			0.03,	//V_Chestrig_oli",
			0.02,	//V_TacVest_khk",
			0.02,	//V_TacVest_brn",
			0.02,	//V_TacVest_oli",
			0.02,	//V_TacVest_blk",
			0.02,	//V_TacVest_camo",
			0.02,	//V_TacVest_blk_POLICE",
			0.02,	//V_TacVestIR_blk",
			0.02	//V_TacVestCamo_khk"
		}
	};
	uniform_military[] = {
		{
			"U_B_CombatUniform_mcam",
			"U_B_CombatUniform_mcam_tshirt",
			"U_B_GhillieSuit",
			"U_B_Wetsuit",
			"U_O_CombatUniform_ocamo_srv",
			"U_O_GhillieSuit_srv",
			"U_O_Wetsuit_srv",
			"U_B_Guerilla1_1_srv",
			"U_B_leader_srv",
			"U_gorka_e",
			"U_gorka2_e",
			"U_gorka3_e",
			"U_gorka4_e",
			"U_gorka5_e",
			"U_gorka6_e",
			"U_gorka7_e",
			"U_gorka8_e",
			"Item_U_B_FullGhillie_sard",
			"german_feldbluse_fleck",
			"german_feldbluse_tropen",
			"german_feldbluse_fleck_kurz",
			"german_feldbluse_tropen_kurz"
		},
		{
			0.01,	//U_B_CombatUniform_mcam
			0.01,	//U_B_CombatUniform_mcam_tshirt
			0.01,	//U_B_GhillieSuit
			0.01,	//U_B_Wetsuit
			0.01,	//U_O_CombatUniform_ocamo_srv
			0.01,	//U_O_GhillieSuit_srv
			0.01,	//U_O_Wetsuit_srv
			0.01,	//U_B_Guerilla1_1_srv
			0.01,	//U_B_leader_srv
			0.01,	//U_gorka_e
			0.01,	//U_gorka2_e
			0.01,	//U_gorka3_e
			0.01,	//U_gorka4_e
			0.01,	//U_gorka5_e
			0.01,	//U_gorka6_e
			0.01,	//U_gorka7_e
			0.01,	//U_gorka8_e
			0.01,	//Item_U_B_FullGhillie_sard
			0.01,	//german_feldbluse_fleck
			0.01,	//german_feldbluse_tropen
			0.01,	//german_feldbluse_fleck_kurz
			0.01	//german_feldbluse_tropen_kurz
		}
	};
	headgear_civilian[] = {
		{
			"H_Cap_red",
			"H_Cap_blu",
			"H_Cap_oli",
			"H_Cap_tan",
			"H_Cap_blk",
			"H_Cap_grn",
			"H_Cap_grn_BI",
			"H_Cap_blk_ION",
			"H_Bandanna_surfer",
			"H_Bandanna_gry",
			"H_Bandanna_sgg",
			"H_TurbanO_blk",
			"H_StrawHat",
			"H_StrawHat_dark",
			"H_Hat_blue",
			"H_Hat_brown",
			"H_Hat_grey",
			"H_Hat_checker",
			"H_Hat_tan"
		},
		{
			0.05,	//H_Cap_red
			0.05,	//H_Cap_blu
			0.05,	//H_Cap_oli
			0.05,	//H_Cap_tan
			0.05,	//H_Cap_blk
			0.05,	//H_Cap_grn
			0.05,	//H_Cap_grn_BI
			0.05,	//H_Cap_blk_ION
			0.05,	//H_Bandanna_surfer
			0.05,	//H_Bandanna_gry
			0.05,	//H_Bandanna_sgg
			0.05,	//H_TurbanO_blk
			0.05,	//H_StrawHat
			0.05,	//H_StrawHat_dark
			0.05,	//H_Hat_blue
			0.05,	//H_Hat_brown
			0.05,	//H_Hat_grey
			0.05,	//H_Hat_checker
			0.05	//H_Hat_tan
		}
	};
	headgear_military[] = {
		{	
			"H_Shemag_khk",
			"H_Shemag_tan",
			"H_Shemag_olive",
			"H_Shemag_olive_hs",
			"H_ShemagOpen_khk",
			"H_ShemagOpen_tan",
			"H_Watchcap_blk",
			"H_Watchcap_cbr",
			"H_Watchcap_camo",
			"H_Watchcap_khk",
			"H_HelmetB_grass",
			"H_HelmetB_snakeskin",
			"H_HelmetB_desert",
			"H_HelmetB_black",
			"H_HelmetB_sand",
			"H_HelmetB_camo",
			"H_Beret_blk",
			"H_Beret_grn",
			"H_Beret_brn_SF",
			"H_Beret_grn_SF",
			"H_Beret_ocamo",
			"Balaclava_GRY",
			"Balaclava_Black",
			"L_Shemagh_Tan",
			"LBG_Shemagh_Tan",
			"PU_shemagh_White",
			"booniehat_fleck",
			"feldmuetze_fleck",
			"feldmuetze_fleck_helmet",
			"m92_gras_fleck",
			"m92_fleck_gt",
			"m92_gras_fleck_h",
			"m92_tropen_h",
			"bwk_goggles_tropen"
		},
		{
			0.04,	//H_Shemag_khk
			0.04,	//H_Shemag_tan
			0.04,	//H_Shemag_olive
			0.04,	//H_Shemag_olive_hs
			0.04,	//H_ShemagOpen_khk
			0.04,	//H_ShemagOpen_tan
			0.05,	//H_Watchcap_blk
			0.05,	//H_Watchcap_cbr
			0.05,	//H_Watchcap_camo
			0.05,	//H_Watchcap_khk
			0.05,	//H_HelmetB_grass
			0.05,	//H_HelmetB_snakeskin
			0.05,	//H_HelmetB_desert
			0.05,	//H_HelmetB_black
			0.05,	//H_HelmetB_sand
			0.05,	//H_HelmetB_camo
			0.05,	//H_Beret_blk
			0.05,	//H_Beret_grn
			0.05,	//H_Beret_brn_SF
			0.05,	//H_Beret_grn_SF
			0.05,	//H_Beret_ocamo
			0.03,	//Balaclava_GRY
			0.03,	//Balaclava_Black
			0.04,	//L_Shemagh_Tan
			0.04,	//LBG_Shemagh_Tan
			0.04,	//PU_shemagh_White
			0.01,	//booniehat_fleck
			0.01,	//feldmuetze_fleck
			0.01,	//feldmuetze_fleck_helmet
			0.01,	//m92_gras_fleck
			0.01,	//m92_fleck_gt
			0.01,	//m92_gras_fleck_h
			0.01,	//m92_tropen_h
			0.01	//bwk_goggles_tropen			
		}
	};
};