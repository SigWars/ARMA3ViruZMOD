
class cfgVehiclesSpawner {
	
	frequency = (1* 60);		// Especifica o tempo em segundos. neste caso, (50 min) para gerar outro exemplo da tecnologia, o valor deste parametro nao e alterado na forma funcional
	variance = (0);		// Tambem na segunda. neste caso, (15 min), a configuracao e adotada para o calculo do tempo de aleatoriedade e adicionado ao valor do parametro acima
	spawnChance = 1;			// Possibilidade gerar outro exemplo de tecnologia, escala de 0 a 1

	/// То есть в функционале расчёт выглядит подобным образом
	/// _frequency	= getNumber (missionConfigFile >> "CfgVehiclesSpawner" >> "frequency");
	/// _variance	= getNumber (missionConfigFile >> "CfgVehiclesSpawner" >> "variance");
	/// _timeAdjust = round(random(_variance * 2) - _variance);									// Расчёт рандомной составляющей
	/// _timeToSpawn = time + _frequency + _timeAdjust;											// Конечный результат расчётов
	
	Civilian[] = {
	//{"RDS_Ikarus_Civ_01",1},
    //{"RDS_Ikarus_Civ_02",1},
    {"RDS_Lada_Civ_01",1},
    {"RDS_Lada_Civ_02",1},
    {"RDS_Lada_Civ_03",1},
    {"RDS_Lada_Civ_04",1},
    {"RDS_Lada_Civ_05",1},
    {"RDS_S1203_Civ_01",1},
    {"RDS_S1203_Civ_02",1},	
	{"RDS_S1203_Civ_03",1},
    {"RDS_Gaz24_Civ_01",1},
    {"RDS_Gaz24_Civ_02",1},
    {"RDS_Gaz24_Civ_03",1},
    //{"RDS_Golf4_Civ_01",1},
    {"RDS_Octavia_Civ_01",3},
    {"RDS_Hatchback_01_F",3},
	{"RDS_Van_01_transport_F",5},
	//{"RDS_Van_01_fuel_F",5},
    {"RDS_Van_01_box_F",5},
	//{"SUV_01_Bardo_SRV",1},
	//{"SUV_01_Black_SRV",1},
	//{"SUV_01_Gray_SRV",1},
	//{"SUV_01_Orange_SRV",1},
	{"Civilian_Offroad_01_white",1},
	{"LandRover_TK_CIV_EP1",1}, 	//landhover do mod
	{"BAF_Offroad_D", 1},
	{"BAF_Offroad_W", 1},
	{"LandRover_CZ_EP1", 1},
	{"LandRover_ACR", 1},
	{"ACR_LandRover_AMB", 1},
	{"B_Heli_Light_01_F",1}, 				//Helis
	{"C_Heli_light_01_ion_F",1},
	{"C_Heli_light_01_wasp_F",1},
	{"C_Heli_light_01_sheriff_F",1},
	{"C_Heli_light_01_speedy_F",1},
	{"dbo_CIV_ol_bike",10}, //BIKES
	{"dbo_CIV_new_bike",10}
	};
	Military[] = {
	{"B_Heli_Light_01_F", 1}, //Helis
	{"I_Heli_light_03_unarmed_F", 1},
	{"O_Heli_Transport_04_F", 1}
	};
	Ships[] = {
	{"C_Boat_Civil_01_F", 3},
	{"C_Boat_Civil_01_police_F", 3},
	{"C_Boat_Civil_01_rescue_F", 3},
	{"O_Boat_Armed_01_hmg_F", 1},
	{"I_Boat_Armed_01_minigun_F", 1},
	{"B_Boat_Armed_01_minigun_F", 1}
	};
};