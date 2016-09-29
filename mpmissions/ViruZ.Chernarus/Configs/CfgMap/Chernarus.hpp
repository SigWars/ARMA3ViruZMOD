class Chernarus {
	
	spawnChanceWood = 1;  //    0.30 = 30% / 1 = 100%
	maxQtyWood = 3;
	spawnChanceCinder = 1;  //    0.20 = 20% / 1 = 100%
	maxQtyCinder = 2;
	
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
	Rocks[] = {
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
		
		//Chernarus
		
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