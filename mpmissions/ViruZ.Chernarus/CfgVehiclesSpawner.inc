
class cfgVehiclesSpawner {
	
	frequency = (10* 60);		// Especifica o tempo em segundos. neste caso, (1 * 60 = 1 minuto) para gerar outro exemplo da tecnologia, o valor deste parametro nao e alterado na forma funcional
	variance = (5* 60);		// Tambem na segunda. neste caso, (15 min), a configuracao e adotada para o calculo do tempo de aleatoriedade e adicionado ao valor do parametro acima
	spawnChance = 1;			// Possibilidade gerar outro exemplo de tecnologia, escala de 0 a 1

	Civilian[] = {
	{"I_C_Van_01_transport_brown_F",2},		//van aberta
	{"C_Van_01_box_red_F",2},				//van fechada
	{"C_Van_01_transport_F",2},				//van aberta
    {"RDS_tt650_Civ_01",5},					//yamaha tt 650
	{"RDS_JAWA353_Civ_01",4},				//moto titan
	{"I_Heli_light_03_unarmed_F",3},		//Hellcat desarmado
	{"O_T_LSV_02_unarmed_viper_F",3},
	{"C_Offroad_02_unarmed_black_F",2},
	{"LandRover_TK_CIV_EP1",3}, 	//landhover do mod
	{"BAF_Offroad_D", 5},
	{"BAF_Offroad_W", 1},
	{"LandRover_CZ_EP1", 1},
	{"LandRover_ACR", 1},
	{"ACR_LandRover_AMB", 1},
	{"B_Heli_Light_01_F",5}, 				//Humminbird com prancha lateral pilotagem civil
	{"B_Heli_Light_01_stripped_F",5},
	{"O_Heli_Light_02_unarmed_F",3},
	{"I_Heli_Transport_02_F",5},
	{"C_Heli_light_01_speedy_F",1}
	};
	Military[] = {
	{"B_Heli_Light_01_F", 2}, //Helis
	{"I_Heli_light_03_unarmed_F", 2}
	};
	Ships[] = {
	{"C_Boat_Civil_01_F", 1},
	{"C_Boat_Civil_01_police_F", 1},
	{"C_Boat_Civil_01_rescue_F", 1}
	};
};