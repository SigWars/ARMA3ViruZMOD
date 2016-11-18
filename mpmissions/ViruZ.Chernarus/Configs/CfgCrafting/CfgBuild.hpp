class cfgViruzBuilds 
{
	//So pode colocar no maximo 4 componentes como requerimento para cada item, e todos os componentes precisam ser da cfgMagazines
	BuildsReq[] = {

		{"ViruZ Modular",
		{"VIRUZ_Woodfloor_New",{{"Viruz_Woodboard",4}}},
		{"VIRUZ_WoodWall_New",{{"Viruz_Woodboard",4}}},
		{"VIRUZ_WoodDoor_new",{{"Viruz_Woodboard",4}}},
		{"VIRUZ_Woodstair_New",{{"Viruz_Woodboard",4}}},
		{"VIRUZ_WoodGate_new",{{"Viruz_Woodboard",4}}},
		{"VIRUZ_WoodWindow_new",{{"Viruz_Woodboard",4}}},
		{"VIRUZ_WoodRamp_New",{{"Viruz_Woodboard",4}}}
		},

		{"Arma Builds",
		{"Land_Slum_House02_F",{{"Viruz_Woodboard",10},{"Viruz_CinderBlock",2}}},
		{"Land_i_House_Big_01_V1_F",{{"Viruz_CinderBlock",20},{"Viruz_Woodboard",5},{"PartGeneric",5}}},
		{"Land_i_House_Big_01_V2_F",{{"Viruz_CinderBlock",20},{"Viruz_Woodboard",5},{"PartGeneric",5}}},
		{"Land_i_House_Big_01_V3_F",{{"Viruz_CinderBlock",20},{"Viruz_Woodboard",5},{"PartGeneric",5}}},
		{"Land_i_House_Big_02_V2_F",{{"Viruz_CinderBlock",20},{"Viruz_Woodboard",5},{"PartGeneric",5}}},
		{"Land_i_House_Big_02_V3_F",{{"Viruz_CinderBlock",20},{"Viruz_Woodboard",5},{"PartGeneric",5}}},
		{"Land_i_House_Small_01_V1_F",{{"Viruz_CinderBlock",15},{"Viruz_Woodboard",10},{"PartGeneric",5}}},
		{"Land_i_House_Small_01_V2_F",{{"Viruz_CinderBlock",15},{"Viruz_Woodboard",10},{"PartGeneric",5}}},
		{"Land_i_House_Small_01_V3_F",{{"Viruz_CinderBlock",15},{"Viruz_Woodboard",10},{"PartGeneric",5}}},
		{"Land_i_House_Small_02_V1_F",{{"Viruz_CinderBlock",15},{"Viruz_Woodboard",10},{"PartGeneric",5}}},
		{"Land_i_House_Small_02_V2_F",{{"Viruz_CinderBlock",15},{"Viruz_Woodboard",10},{"PartGeneric",5}}},
		{"Land_i_House_Small_02_V3_F",{{"Viruz_CinderBlock",15},{"Viruz_Woodboard",10},{"PartGeneric",5}}},
		{"Land_i_House_Small_03_V1_F",{{"Viruz_CinderBlock",15},{"Viruz_Woodboard",10},{"PartGeneric",5}}},
		{"Land_i_Shed_Ind_F",{{"PartGeneric",15},{"Viruz_CinderBlock",10}}},
		{"Land_Cargo_House_V1_F",{{"PartGeneric",10}}},
		{"Land_Cargo_House_V3_F",{{"PartGeneric",10}}},
		{"Land_Cargo_HQ_V1_F",{{"PartGeneric",20}}},
		{"Land_Cargo_HQ_V2_F",{{"PartGeneric",20}}}
		},

		{"Generators and Maintain",
		{"ViruZ_WorkStand",{{"Viruz_Woodboard",3}}},
		{"Land_Portable_generator_F",{{"PartGeneric",3},{"Viruz_Laptop",1}}}
		},

		{"Floor",
		{"BlockConcrete_F",{{"Viruz_CinderBlock",5}}},
		{"Land_Pier_F",{{"Viruz_CinderBlock",20}}}
		},

		{"Walls",
		{"Land_Canal_WallSmall_10m_F",{{"Viruz_CinderBlock",5}}},
		{"Land_City2_4m_F",{{"Viruz_CinderBlock",3}}},
		{"Land_City2_8m_F",{{"Viruz_CinderBlock",3}}},
		{"Land_Mil_WiredFence_F",{{"ItemWire",3}}},
		{"Land_SportGround_fence_noLC_F",{{"ItemWire",3}}}
		//{"Land_Gate_IndVar2_5",{{"Viruz_Woodboard",5}}}
		},

		{"Gates",
		{"VIRUZ_Net_Fence_Gate_F",{{"ItemWire",3}}},
		{"VIRUZ_City_Gate_F",{{"Viruz_CinderBlock",3},{"PartGeneric",3}}}
		},

		{"Barricades",
		{"Land_BagFence_Long_F",{{"ItemSandbag",2}}},
		{"Land_BagFence_Short_F",{{"ItemSandbag",1}}},
		{"Land_BagFence_End_F",{{"ItemSandbag",1}}},
		{"Land_BagFence_Round_F",{{"ItemSandbag",1}}},
		{"Land_BagFence_Corner_F",{{"ItemSandbag",1}}}
		},

		{"Internal Suplyes",
		{"Land_Camping_Light_off_F",{{"Viruz_HandCan",1}}},
		{"Land_BarrelWater_grey_F",{{"Viruz_Maleta",1}}},
		{"Land_BarrelWater_F",{{"Viruz_Maleta",1}}},
		{"MetalBarrel_burning_F",{{"PartGeneric",1},{"PartWoodPile",2}}},
		{"Saco_de_Dormir",{{"ItemSandbag",5}}}
		},

		{"Racks",
		{"Rack_Madeira",{{"Viruz_Woodboard",3}}},
		{"Stante_Madeira",{{"Viruz_Woodboard",3}}},
		{"Rack_Ferro",{{"PartGeneric",3}}},
		{"Stante_Ferro",{{"PartGeneric",3}}}
		},

		{"Stairs",
		{"Land_Canal_Wall_Stairs_F",{{"Viruz_CinderBlock",5},{"PartGeneric",2}}},
		{"ViruZ_PierLadder_F",{{"PartGeneric",2}}},
		{"VIRUZ_GH_Stairs_F",{{"Viruz_CinderBlock",5}}}
		},

		{"Lighting",
		{"Land_PortableLight_single_F",{{"PartGeneric",2}}}
		},

		{"Cosmetics",
		{"Land_CampingChair_V1_F",{{"PartGeneric",2}}},
		{"Land_CampingChair_V2_F",{{"PartGeneric",2}}},
		{"Land_CampingTable_F",{{"PartGeneric",3}}},
		{"Land_CampingTable_small_F",{{"PartGeneric",1}}}
		}

	};
};