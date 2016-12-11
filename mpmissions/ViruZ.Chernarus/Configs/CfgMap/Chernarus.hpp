class Chernarus {
	
	spawnChanceWood = 0.40;  //    0.30 = 30% / 1 = 100%
	maxQtyWood = 3;
	spawnChanceRocks = 0.40;  //    0.20 = 20% / 1 = 100%
	maxQtyRocks = 2;
	spawnChanceClinquer = 0.20;  //    0.20 = 20% / 1 = 100%
	maxQtyClinquer = 2;
	spawnChanceScrap = 0.40;  //    0.20 = 20% / 1 = 100%
	maxQtyScrap = 2;
	

	class FuelSource
	{
		name = "Fuel pumps, stations or barrels";
		models[] = 
		{
			//Chernarus
			"Land_Fuel_tank_big",
			"Land_Fuel_tank_big.p3d",
			"Land_A_FuelStation_Feed",
			"Land_A_FuelStation_Feed.p3d",
			"Land_A_FuelStation_Shed",
			"Land_A_FuelStation_Shed.p3d",
			"fuelstation_feed_f",
			"fuelstation_feed_f.p3d",
			"metalbarrel_f",
			"metalbarrel_f.p3d",
			"flexibletank_01_f",
			"flexibletank_01_f.p3d",
			//Tanoa
			"fuelstation_01_pump_f.p3d",
			"fuelstation_02_pump_f.p3d"
		};	
	};
	
	blockedArea[] = {
			/*
			{ { 1433, 8071, 0 }, 250 }, //Roenne NorthEast
			{ { 1939, 7788, 0 }, 250 }, //Roenne East
			{ { 1553, 7103, 0 }, 400 }, //Roenne South
			{ { 3052, 5412, 0 }, 400 }, //Main Airport
			{ { 3676, 5148, 0 }, 300 }, //Airport addons
			{ { 9547, 5541, 0 }, 600 }, //Aakirkeby
			{ { 17433, 5106, 0 }, 600 }, //Nexoe
			{ { 17989, 9844, 0 }, 600 }, //Svaneke
			{ { 11600, 14723, 0 }, 500 }, //Gudhjem
			{ { 5010, 19132, 0 }, 250 }, //Allinge
			{ { 5291, 12450, 0 }, 450 }, //Klemensker
			{ { 3386, 10088, 0 }, 350 }, //Nyker
			{ { 14560, 5130, 0 }, 300 }, //South Airport
			{ { 148786, 5024, 0 }, 300 }, //South Airport Base
			{ { 12993, 10197, 0 }, 250 }, //Oestermarie
			{ { 13867, 10672, 0 }, 300 }, //East Airport
			{ { 8564, 15015, 0 }, 350 }, //Roe
			{ { 6554, 5866, 0 }, 400 }, //Lobbaek
			{ { 5350, 5724, 0 }, 300 }, //Nylars
			{ { 12438, 2980, 0 }, 400 }, //Pedersker
			{ { 14121, 11331, 0 }, 200 }, //Central Spawn
			{ { 1322, 8733, 0 }, 200 }, //West Spawn
			{ { 15639, 191, 0 }, 200 } //East Spawn */
	};

ClinquerRocks[] = {
	"bo_r2_boulder1.p3d",
	"bo_r2_boulder2.p3d",
	"r2_boulder1.p3d",
	"r2_boulder2.p3d",
	"r_tk_boulder_01_ep1.p3d",
	"r_tk_boulder_02_ep1.p3d"
};

Rocks[] = {
			"sharpstone_03_lc.p3d",
			"sharpstone_02_lc.p3d",
			"sharpstone_01_lc.p3d",
			"sharpstone_02.p3d",
			"sharpstone_03.p3d",
			"sharprock_monolith.p3d",
			"sharprock_apart.p3d",
			"sharpstones_erosion.p3d",
			"bluntstone_01_lc.p3d",
			"bluntstone_02_lc.p3d",
			"bluntstone_03_lc.p3d",
			"bluntstones_erosion.p3d",
			"bluntstone_01.p3d",
			"bluntstone_03.p3d",
			"sharprock_spike.p3d",
			"sharprock_wallh.p3d",
			"w_sharpstone_03.p3d",
			"w_sharpstone_02.p3d",
			"w_sharpstone_01.p3d",
			"bluntrock_apart.p3d",
			"bluntstone_02.p3d",
			"bluntrock_monolith.p3d",
			"bluntrock_wallh.p3d",
			"sharprock_wallv.p3d",
			"stonesharp_medium.p3d",
			"stone_medium_f.p3d",
			"stonesharp_big.p3d",
			"stonesharp_small.p3d",
			"small_stone_02_f.p3d",
			"stone_small_f.p3d",
			"stone_big_f.p3d",
			"bluntrock_spike.p3d",
			"r2_rock1.p3d",
			"r2_rocktower.p3d",
			"r2_rockwall.p3d",
			"r_rock_02_ep1.p3d",
			"brownrock2.p3d",
			"brownrock3.p3d",
			"desertrock.p3d",
			"desertrock2.p3d",
			"desertrock3.p3d",
			"r_stone_01_ep1.p3d",
			"brownrock.p3d",
			"rockn_02.p3d",
			"sharpstone_01.p3d",
			"r_rock_03_ep1.p3d",
			"rocks_02.p3d",
			"skala3_5.p3d",
			"skala3_4.p3d",
			"skala1_4.p3d",
			"bo_r2_rock1.p3d",
			"bo_r2_rocktower.p3d",
			"bo_r2_rockwall.p3d",
			"w_sharpstones_erosion.p3d",
			"decal_rock_dark.p3d",
			"r_stone_01_pmc.p3d",
			"r_stone_02_pmc.p3d",
			"stone4.p3d",
			"stone3.p3d",
			"stone4_invert.p3d",
			"rocks_01.p3d",
			"stone4a.p3d",
			"stone3a.p3d",
			"rockn_01.p3d",
			"r_tk_stone_01_ep1.p3d",
			"r_tk_stone_02_ep1.p3d",
			"r_tk_rock_03_ep1.p3d",
			"r_tk_boulder_03_ep1.p3d",
			"r_tk_rock_02_ep1.p3d",
			"r_tk_rock_01_ep1.p3d",
			"cliff_stone_big_lc_f.p3d",
			"cliff_wall_long_f.p3d",
			"cliff_stone_medium_lc_f.p3d",
			"cliff_stone_small_lc_f.p3d",
			"cliff_boulder_f.p3d",
			"cliff_peak_f.p3d",
			"cliff_wall_round_f.p3d",
			"cliff_stonecluster_f.p3d",
			"cliff_wall_tall_f.p3d",
			"lavaboulder_03_f.p3d",
			"lavastone_small_lc_f.p3d",
			"lavaboulder_02_f.p3d",
			"lavaboulder_01_f.p3d",
			"lavastone_big_lc_f.p3d",
			"lavastonecluster_large_f.p3d",
			"lavaboulder_04_f.p3d",
			"lavastonecluster_small_f.p3d",
			"cliff_stone_medium_f.p3d",
			"lavastone_big_f.p3d",
			"lavastone_small_f.p3d",
			"cliff_surfacemine_f.p3d",
			"stone_medium_f.p3d",
			"sharpstone_03_lc.p3d",
			"sharpstone_02.p3d",
			"sharpstone_erosion.p3d",
			"sharpstones_erosion.p3d",
			"sharprock_wallh.p3d",
			"sharprock_wallv.p3d",
			"stonesharp_wall",
			"sharprock_monolith.p3d",
			"clutter_md_stonesmall.p3d"
	};

	Water[] = {
		"misc_well.p3d",
		"misc_wellpump.p3d",
		"kasna_new.p3d"
	};	

	// main config 
	TrashVehicle[] = {
	};
	
	Trash[] = {
		"misc_postbox.p3d",
		"popelnice.p3d",
		"garbage_misc.p3d",
		"paletyc.p3d",
		"junkpile.p3d",
		"kontejner.p3d",
		"misc_chickencoop.p3d",
		"misc_boogieman.p3d",
		"misc_hutch.p3d",
		"garbage_paleta.p3d",
		"misc_cargo1a.p3d",
		"misc_cargo2a.p3d",
		"misc_greenhouse.p3d",
		"zastavka_stojan.p3d",
		"p_helianthus.p3d",
		"junkpile_f.p3d",
		"bricks_v2_f.p3d",
		"woodenbox_f.p3d"
	};
	Trees[] = {
		"t_ficusb1s_f.p3d",
"t_oleae1s_f.p3d",
"t_ficusb2s_f.p3d",
"t_broussonetiap1s_f.p3d",
"t_pinuss2s_f.p3d",
"t_pinuss2s_b_f.p3d",
"t_pinuss1s_f.p3d",
"t_oleae2s_f.p3d",
"t_fraxinusav2s_f.p3d",
"t_pinusp3s_f.p3d",
"t_poplar2f_dead_f.p3d",
"t_populusn3s_f.p3d",
"t_phoenixc1s_f.p3d",
"t_populus3s.p3d",
"t_fagus2w.p3d",
"t_betula2s.p3d",
"t_fagus2s.p3d",
"t_fagus2f.p3d",
"t_sorbus2s.p3d",
"t_fraxinus2w.p3d",
"t_salix2s.p3d",
"t_malus1s.p3d",
"t_betula1f.p3d",
"t_pinusn2s.p3d",
"t_picea2s.p3d",
"t_larix3s.p3d",
"t_picea3f.p3d",
"t_picea1s.p3d",
"misc_fallentree2.p3d",
"misc_stub2.p3d",
"t_fraxinus2s.p3d",
"t_quercus2f.p3d",
"misc_trunk_water.p3d",
"misc_trunk_torzo.p3d",
"t_alnus2s.p3d",
"misc_fallentree1.p3d",
"t_betula2f.p3d",
"t_pinusn1s.p3d",
"t_pinuss2f.p3d",
"t_quercus3s.p3d",
"t_carpinus2s.p3d",
"misc_fallenspruce.p3d",
"t_stub_picea.p3d",
"misc_stub1.p3d",
"t_acer2s.p3d",
"t_betula2w.p3d",
"t_pyrus2s.p3d",
"t_pinuss3s_ep1.p3d",
"t_pinuse2s_ep1.p3d",
"t_populusf2s_ep1.p3d",
"str_topol.p3d",
"les_singlestrom_b.p3d",
"banana_3.p3d",
"jablon.p3d",
"str_pinie.p3d",
"t_ficusb2s_ep1.p3d",
"palm_01.p3d",
"vysilac_budova.p3d",
"palm_10.p3d",
"palm_03.p3d",
"palm_04.p3d",
"t_pistacial2s_ep1.p3d",
"panelak.p3d",
"str_kastan.p3d",
"a_hospital.p3d",
"i_barracks_v1_f.p3d",
"dum_istan3_hromada.p3d",
"dum_istan3_hromada2.p3d",
"dum_istan4_big_inverse.p3d",
"panelak2.p3d",
"podesta_1_mid.p3d",
"podesta_1_cornl.p3d",
"t_prunuss2s_ep1.p3d",
"dum_istan2_02.p3d",
"dum_istan4_inverse.p3d",
"podesta_1_stairs2.p3d",
"podesta_1_mid_cornl.p3d",
"hrusen2.p3d",
"zed_kamenna.p3d",
"str_dub.p3d",
"str_dub_jiny.p3d",
"smrk_siroky.p3d",
"smrk_maly.p3d",
"les_singlestrom.p3d",
"palm_02.p3d",
"brg_banana_3.p3d",
"banana_2.p3d",
"oliva.p3d",
"brg_umbrella_acacia02b.p3d",
"brg_umbrella_acacia01b.p3d",
"brg_umbrella_acacia04b.p3d",
"brg_umbrella_acacia03b.p3d",
"str_buk.p3d",
"les_dub.p3d",
"b_pinusm1s_ep1.p3d",
"krovi_long.p3d",
"str_lipa.p3d",
"str_javor.p3d",
"str_trnka.p3d",
"t_poplar2f_dead_pmc.p3d",
"t_quercusir2s_f.p3d",
"dd_bush01.p3d",
"t_fagus2f_summer.p3d",
"akat02s.p3d",
"t_amygdalusc2s_ep1.p3d",
"str_osika.p3d",
"palm_09.p3d",
"dd_borovice.p3d",
"dd_borovice02.p3d",
"str_topol2.p3d",
"brg_umbrella_acacia_shrub02.p3d",
"t_populusb2s_ep1.p3d",
"les_dub_jiny.p3d",
"les_buk.p3d",
"str_fikovnik.p3d",
"str_briza_rovna.p3d",
"str_jerabina.p3d",
"str_habr.p3d",
"les_fikovnik2.p3d",
"bo_t_populus3s.p3d",
"bo_t_fagus2w.p3d",
"bo_t_betula2s.p3d",
"bo_t_fagus2s.p3d",
"bo_t_fagus2f.p3d",
"bo_t_sorbus2s.p3d",
"bo_t_fraxinus2w.p3d",
"bo_t_salix2s.p3d",
"bo_t_malus1s.p3d",
"bo_t_betula1f.p3d",
"bo_t_pinusn2s.p3d",
"bo_t_picea2s.p3d",
"bo_t_larix3s.p3d",
"bo_t_picea3f.p3d",
"bo_t_picea1s.p3d",
"bo_misc_fallentree2.p3d",
"bo_misc_stub2.p3d",
"bo_t_fraxinus2s.p3d",
"bo_t_quercus2f.p3d",
"bo_misc_trunk_water.p3d",
"bo_misc_trunk_torzo.p3d",
"bo_t_alnus2s.p3d",
"bo_misc_fallentree1.p3d",
"bo_t_betula2f.p3d",
"bo_t_pinusn1s.p3d",
"bo_t_pinuss2f.p3d",
"bo_t_quercus3s.p3d",
"bo_t_carpinus2s.p3d",
"bo_t_stub_picea.p3d",
"bo_t_acer2s.p3d",
"bo_t_betula2w.p3d",
"bo_t_pyrus2s.p3d",
"bo_b_corylus.p3d",
"t_fagus2s_summer.p3d",
"t_betula2s_summer.p3d",
"cwr2_a2_t_sorbus2s.p3d",
"cwr2_a2_t_fagus2w.p3d",
"cwr2_a2_t_alnus2s.p3d",
"mb_t_ulmus_large.p3d",
"cwr_aleppopine.p3d",
"cwr2_a2_t_quercus3s.p3d",
"cwr2_a2_t_fraxinus2s.p3d",
"misc_torzotree_pmc.p3d",
"misc_brokenspruce_pmc.p3d",
"misc_stubleafs_pmc.p3d",
"str_fikovnik2.p3d",
"str_fikovnik_ker.p3d",
"str_briza_kriva.p3d",
"smrk_velky.p3d",
"str_briza.p3d",
"misc_trunk_torzo_ep1.p3d",
"t_juniperusc2s_ep1.p3d",
"misc_trunk_water_ep1.p3d",
"t_cocosnucifera3s_tall_f.p3d",
"t_leucaena_f.p3d",
"t_ficus_medium_f.p3d",
"t_cyathea_f.p3d",
"t_ficus_small_f.p3d",
"t_cocosnucifera2s_small_f.p3d",
"t_millettia_f.p3d",
"t_inocarpus_f.p3d",
"t_cocosnucifera3s_bend_f.p3d",
"t_agathis_wide_f.p3d",
"d_treestump_cut_small_f.p3d",
"d_treestump_natural_small_f.p3d",
"d_treestump_natural_large_f.p3d",
"t_albizia_f.p3d",
"t_agathis_tall_f.p3d",
"t_palaquium_f.p3d",
"t_ficus_big_f.p3d",
"t_rhizophora_f.p3d",
"t_cacao_ripe_f.p3d",
"d_treestump_cut_large_f.p3d",
		//big
		"cwr2_a2_t_quercus3s.p3d",
		"mb_EnglishElm.p3d",
		"mb_t_ulmus_forest.p3d",
		"mb_t_ulmus_forestIvy.p3d",
		"mb_t_ulmus_large.p3d",
		"mb_t_ulmus_large_w.p3d",
		"mb_t_ulmus_largeIvy.p3d",
		"t_fagus2f.p3d",
		"t_fagus2f_summer.p3d",
		"t_FraxinusAV2s_F.p3d",
		"t_QuercusIR2s_F.p3d",
		//medium
		"cwr_robinia1.p3d",
		"cwr2_a2_t_alnus2s.p3d",
		"cwr2_a2_t_betula2f.p3d",
		"cwr2_a2_t_fraxinus2s.p3d",
		"cwr2_a2_t_sorbus2s.p3d",
		"Elm_small_vertNormalsProjOut.p3d",
		"javor_posed.p3d",
		"les_dub_jiny.p3d",
		"mb_t_ulmus_small.p3d",
		"mb_t_ulmus_small_w.p3d",
		"mb_t_ulmus_smallIvy.p3d",
		"str buk.p3d",
		"str dub.p3d",
		"str kastan.p3d",
		"str lipa.p3d",
		"str vrba.p3d",
		"t_betula2s.p3d",
		"t_carpinus2s.p3d",
		"t_fagus2s.p3d",
		"t_FicusB2s_EP1.p3d",
		"t_pyrus2s.p3d",
		"t_quercus2f.p3d",
		"str_topol.p3d",
		"str_topol2.p3d",
		"t_populus3s.p3d",
		"t_PopulusB2s_EP1.p3d",
		"t_PopulusF2s_EP1.p3d",
		"t_PopulusN3s_F.p3d",
		"cwr_aleppopine.p3d",
		"cwr_seapine.p3d",
		"str jalovec.p3d",
		"str_pinie.p3d",
		"t_PinusE2s_EP1.p3d",
		"t_pinusN1s.p3d",
		"t_pinusN2s.p3d",
		"t_PinusS1s_F.p3d",
		"t_pinusS2f.p3d",
		"t_pinuss2f.p3d",
		"t_PinusS2s_b_F.p3d",
		"t_PinusS2s_F.p3d",
		"t_PinusS3s_EP1.p3d",
		"cwr_silverspruce_p.p3d",
		"cwr_silverspruce2.p3d",
		"cwr2_a2_t_larix3s.p3d",
		"dd_borovice02.p3d",
		"les_singlestrom.p3d",
		"les_singlestrom_b.p3d",
		"Smrk_maly.p3d",
		"Smrk_siroky.p3d",
		"Smrk_velky.p3d",
		"t_JuniperusC2s_EP1.p3d",
		"t_picea1s.p3d",
		"t_picea2s.p3d",
		"t_picea3f.p3d"
	};
	Bushes[] = {
		"bo_b_craet1.p3d",
		"bo_b_craet2.p3d",
		"bo_b_corylus.p3d",
		"bo_b_corylus2s.p3d",
		"bo_b_betulahumilis.p3d",
		"bo_b_sambucus.p3d",
		"salix2s.p3d",
		"bo_b_canina2s.p3d",
		"bo_b_pmugo.p3d",
		"bo_b_prunus.p3d"
	};
	Cinder[] = {
		"cinderblocks_f.p3d"
	};
	Wrecks[] = {
		
		//todos
		"wall_tin_4_2.p3d",
"mil_wiredfence_f.p3d",
"cages_f.p3d",
"wreck_car_f.p3d",
"pipes_small_f.p3d",
"pipe_fence_4m_f.p3d",
"spp_tower_f.p3d",
"wreck_ural_f.p3d",
"wreck_car3_f.p3d",
"ironpipes_f.p3d",
"pipes_large_f.p3d",
"coil_f.p3d",
"wreck_offroad_f.p3d",
"wreck_offroad2_f.p3d",
"crabcages_f.p3d",
"metalbarrel_empty_f.p3d",
"net_fenced_8m_f.p3d",
"net_fence_8m_f.p3d",
"wavepowerplantbroken_f.p3d",
"wreck_truck_dropside_f.p3d",
"wavepowerplant_f.p3d",
"wreck_traw_f.p3d",
"wreck_slammer_f.p3d",
"maroula_f.p3d",
"indfnc_9_f.p3d",
"indfnc_3_f.p3d",
"indfnc_3_d_f.p3d",
"wreck_car2_f.p3d",
"net_fence_4m_f.p3d",
"wreck_truck_f.p3d",
"wreck_hunter_f.p3d",
"wreck_slammer_hull_f.p3d",
"wall_fen1_5_pole.p3d",
"wall_fen1_5_2.p3d",
"wall_fen1_5.p3d",
"wall_indfnc_3.p3d",
"wall_indfnc_9.p3d",
"wall_indfnc_corner.p3d",
"misc_concrete_high.p3d",
"plot_vlnplech2.p3d",
"misc_g_pipes.p3d",
"wall_tincom_9.p3d",
"wall_tin_4.p3d",
"plot_vlnplech1.p3d",
"wall_tincom_9_2.p3d",
"wall_tincom_3.p3d",
"wall_tincom_pole.p3d",
"datsun01t.p3d",
"datsun02t.p3d",
"skodovka_wrecked.p3d",
"lada_wrecked.p3d",
"hiluxt.p3d",
"uaz_wrecked.p3d",
"ural_wrecked.p3d",
"rubble_metal_plates_04.p3d",
"rubble_metal_plates_02.p3d",
"rubble_metal_plates_01.p3d",
"wreck_brdm2_f.p3d",
"wreck_bmp2_f.p3d",
"wreck_heli_attack_01_f.p3d",
"bmp_break.p3d",
"wreck_t72_hull_f.p3d",
"wreck_t72_turret_f.p3d",
"wreck_hmmwv_f.p3d",
"kamaz_bort.p3d",
"wreck_van_f.p3d",
"kamaz_awtobas.p3d",
"maz.p3d",
"wreck_skodovka_f.p3d",
"wreck_cardismantled_f.p3d",
"kamaz_pozarka.p3d",
"zaporosez.p3d",
"kamaz_tent.p3d",
"budova5.p3d",
"pletivo_dira.p3d",
"pletivo.p3d",
"wall_indfnc_pole.p3d",
"wall_indfnc_3_d.p3d",
"t72_wrecked.p3d",
"t72_wrecked_turret.p3d",
"parkingmeter_01_f.p3d",
"pipefence_01_m_d_f.p3d",
"pipefence_01_m_8m_f.p3d",
"pipefence_01_m_gate_v2_f.p3d",
"fuelstation_02_prices_f.p3d",
"tinwall_01_m_4m_v2_f.p3d",
"pipefence_01_m_pole_f.p3d",
"wiredfence_01_16m_f.p3d",
"wiredfence_01_8m_d_f.p3d",
"wiredfence_01_8m_f.p3d",
"netfence_01_m_8m_f.p3d",
"netfence_01_m_d_f.p3d",
"netfence_01_m_4m_f.p3d",
"tinwall_02_l_4m_f.p3d",
"tinwall_02_l_8m_f.p3d",
"bulldozer_01_wreck_f.p3d",
"excavator_01_wreck_f.p3d",
"railwaycar_01_tank_f.p3d",
"railwaycar_01_passenger_f.p3d",
"locomotive_01_v3_f.p3d",
"bulldozer_01_abandoned_f.p3d",
"locomotive_01_v1_f.p3d",
"locomotive_01_v2_f.p3d",
"excavator_01_abandoned_f.p3d",
		//esseker
		"zaporosez.p3d",
		"wreck_car3_f.p3d",
		"wreck_car2_f.p3d",
		"wreck_car_f.p3d",
		"Land_Wreck_Offroad_F.p3d",
		"wreck_van_f.p3d",
		"wreck_offroad_f.p3d",
		"wreck_ural_f.p3d",
		"wreck_uaz_f.p3d",
		"wreck_truck_f.p3d",
		"wreck_truck_dropside_f.p3d",
		"maz.p3d",
		"wreck_offroad2_f.p3d",
		"kamaz_awtobas.p3d",
		"junkpile_f.p3d",
		"zastavka_server.p3d",
		"wreck_skodovka_f.p3d",
		"kamaz_bort.p3d",
		"wreck_brdm2_f.p3d",
		"wreck_bmp2_f.p3d",
		//end esseker
	};
};