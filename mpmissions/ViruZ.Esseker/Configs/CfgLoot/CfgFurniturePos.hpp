class Furniture : Default {
	lootChance = 0.2;
	isBuildingPos = 0;
	zombieChance = 0;
	itemType[] = {};
	itemChance[] = {};
	lootPos[] = {};
	zombieClass[] = {};
};

class Furniture_Supermarket: Furniture {
	itemType[] =	{
		{"","furniture_food"},
		{"ItemMatchbox","magazine"},
		{"Battery_mag","magazine"},
		{"","melee_lite"},
		{"FMradio_Mag","magazine"},
		{"itemCampingLight","magazine"}
	};
	itemChance[] =	{
		0.06,	//	comida e bebida
		0.04,	//	ItemMatchbox
		0.03,	//	Battery_mag
		0.04,	//	lanterna e faca
		0.03,	//	FMradio_Mag
		0.03	//	itemCampingLight
	};	
};

//esseker
class CUP_A2_shelf : Furniture {
	lootPos[] = {
		{0.206055,-0.773438,1.2709},{0.206055,-0.0136719,1.2709},{0.206055,0.794922,1.2709},
		{0.206055,-0.773438,0.919653},{0.206055,-0.0136719,0.919653},{0.206055,0.794922,0.919653},
		{0.206055,-0.773438,0.56},{0.206055,-0.0136719,0.56},{0.206055,0.794922,0.56},
		{0.206055,-0.773438,0.21},{0.206055,-0.0136719,0.21},{0.206055,0.794922,0.21},		
		{-0.206055,-0.773438,1.2709},{-0.206055,-0.0136719,1.2709},{-0.206055,0.794922,1.2709},
		{-0.206055,-0.773438,0.919653},{-0.206055,-0.0136719,0.919653},{-0.206055,0.794922,0.919653},
		{-0.206055,-0.773438,0.56},{-0.206055,-0.0136719,0.56},{-0.206055,0.794922,0.56},
		{-0.206055,-0.773438,0.21},{-0.206055,-0.0136719,0.21},{-0.206055,0.794922,0.21}
	};
	itemType[] =	{
		{"","furniture_food"},
		{"ItemMatchbox","magazine"},
		{"Battery_mag","magazine"},
		{"","melee_lite"},
		{"FMradio_Mag","magazine"},
		{"itemCampingLight","magazine"}
	};
	itemChance[] =	{
		0.06,	//	comida e bebida
		0.04,	//	ItemMatchbox
		0.03,	//	Battery_mag
		0.04,	//	lanterna e faca
		0.03,	//	FMradio_Mag
		0.03	//	itemCampingLight
	};
};

class Land_ShelvesMetal_F_Supermarket : Furniture {
	lootPos[] = {
		{0.206055,-0.773438,1.2709},{0.206055,-0.0136719,1.2709},{0.206055,0.794922,1.2709},
		{0.206055,-0.773438,0.919653},{0.206055,-0.0136719,0.919653},{0.206055,0.794922,0.919653},
		{0.206055,-0.773438,0.56},{0.206055,-0.0136719,0.56},{0.206055,0.794922,0.56},
		{0.206055,-0.773438,0.21},{0.206055,-0.0136719,0.21},{0.206055,0.794922,0.21},		
		{-0.206055,-0.773438,1.2709},{-0.206055,-0.0136719,1.2709},{-0.206055,0.794922,1.2709},
		{-0.206055,-0.773438,0.919653},{-0.206055,-0.0136719,0.919653},{-0.206055,0.794922,0.919653},
		{-0.206055,-0.773438,0.56},{-0.206055,-0.0136719,0.56},{-0.206055,0.794922,0.56},
		{-0.206055,-0.773438,0.21},{-0.206055,-0.0136719,0.21},{-0.206055,0.794922,0.21}
	};	
	itemType[] =	{
		{"","furniture_food"},
		{"ItemMatchbox","magazine"},
		{"Battery_mag","magazine"},
		{"","melee_lite"},
		{"FMradio_Mag","magazine"},
		{"itemCampingLight","magazine"}
	};
	itemChance[] =	{
		0.06,	//	comida e bebida
		0.04,	//	ItemMatchbox
		0.03,	//	Battery_mag
		0.04,	//	lanterna e faca
		0.03,	//	FMradio_Mag
		0.03	//	itemCampingLight
	};
};

class Land_ShelvesMetal_F_Pharmacy : Furniture {
	itemType[] =	{
		{"","medical_lite"}
	};
	itemChance[] =	{
		0.04	//	medical_lite
	};
};
class Land_Metal_rack_F_Supermarket : Furniture {
	lootChance = 0.3;
	lootPos[] = {
//				{-0.365234,0,0.549997},{0,0,0.549997},{0.365234,0,0.549997},
				{-0.365234,0,0.1},{0,0,0.1},{0.365234,0,0.1},
				{-0.365234,0,-0.35},{0,0,-0.35},{0.365234,0,-0.35},
				{-0.365234,0,-0.79},{0,0,-0.79},{0.365234,0,-0.79}
	};
	itemType[] =	{
		{"","furniture_food"},
		{"ItemMatchbox","magazine"},
		{"Battery_mag","magazine"},
		{"","melee_lite"},
		{"FMradio_Mag","magazine"},
		{"itemCampingLight","magazine"}
	};
	itemChance[] =	{
		0.06,	//	comida e bebida
		0.04,	//	ItemMatchbox
		0.03,	//	Battery_mag
		0.04,	//	lanterna e faca
		0.03,	//	FMradio_Mag
		0.03	//	itemCampingLight
	};
};

class CUP_A2_case_d : Furniture {
	lootChance = 0.3;
	lootPos[] = {
//				{-0.365234,0,0.549997},{0,0,0.549997},{0.365234,0,0.549997},
				{-0.365234,0,0.1},{0,0,0.1},{0.365234,0,0.1},
				{-0.365234,0,-0.35},{0,0,-0.35},{0.365234,0,-0.35},
				{-0.365234,0,-0.79},{0,0,-0.79},{0.365234,0,-0.79}
	};
};

class Land_Icebox_F_Supermarket : Furniture {
	lootPos[] = {
				{-0.550781,-0.107422,0.0167103},{-0.0449219,-0.163086,0.0167103},
				{0.535156,-0.105469,0.0167103}
	};
	itemType[] =	{
		{"","food"},
		{"FoodSteakRaw","magazine"},
		{"FoodmeatRaw","magazine"},
		{"FoodbeefRaw","magazine"},
		{"FoodmuttonRaw","magazine"},
		{"FoodchickenRaw","magazine"},
		{"FoodrabbitRaw","magazine"},
		{"FoodbaconRaw","magazine"},
		{"FishRawTrout","magazine"},
		{"FishRawSeaBass","magazine"},
		{"FishRawTuna","magazine"}
	};
	itemChance[] =	{
		0.08,	//	food
		0.01,	// steak
		0.01,	// steak
		0.01,	// steak
		0.01,	// steak
		0.01,	// steak
		0.01,	// steak
		0.01,	// steak
		0.01,	// fish
		0.01,	// fish
		0.01	// fish
	};	

};
//eseker
class CUP_A2_icebox : Furniture {
	lootPos[] = {
				{-0.550781,-0.107422,0.0167103},{-0.0449219,-0.163086,0.0167103},
				{0.535156,-0.105469,0.0167103}
	};
	itemType[] =	{
		{"","food"},
		{"FoodSteakRaw","magazine"},
		{"FoodmeatRaw","magazine"},
		{"FoodbeefRaw","magazine"},
		{"FoodmuttonRaw","magazine"},
		{"FoodchickenRaw","magazine"},
		{"FoodrabbitRaw","magazine"},
		{"FoodbaconRaw","magazine"},
		{"FishRawTrout","magazine"},
		{"FishRawSeaBass","magazine"},
		{"FishRawTuna","magazine"}
	};
	itemChance[] =	{
		0.08,	//	food
		0.01,	// steak
		0.01,	// steak
		0.01,	// steak
		0.01,	// steak
		0.01,	// steak
		0.01,	// steak
		0.01,	// steak
		0.01,	// fish
		0.01,	// fish
		0.01	// fish		
	};	

};

class Land_CashDesk_F_Supermarket : Furniture {
	lootPos[] = {
		{-0.03125,0.368164,0.05}
	};
	itemType[] =	{
		{"hgun_P07_F","weapon"},
		{"hgun_Rook40_F","weapon"},
		{"16Rnd_9x21_Mag","magazine"}
	};
	itemChance[] =	{
		0.03,	// hgun_P07_F
		0.03,	// hgun_Rook40_F
		0.02	// 9Rnd_45ACP_Mag
	};	

};
//essker
class CUP_A2_pultskasou : Furniture {
	lootPos[] = {
		{-0.03125,0.368164,0.05}
	};
	itemType[] =	{
		{"","pistol_lite"},
		{"","mag_pistol_lite"}
	};
	itemChance[] =	{
		0.04,
		0.03
	};
};

class Land_Metal_wooden_rack_F_MilitaryShop : Furniture {
	lootChance = 0.3;
	lootPos[] = {
		{0,0,-0.903646},{0,0,-0.403646},{0,0,0.0963535}
	};	
	itemType[] =	{
			{"","pistol_lite"},
			{"","mag_pistol_lite"},
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
			{"ItemWaterBottleEmpty","magazine"}
	};
	itemChance[] =	{
			0.05,	//pistolas
			0.04,	//pistolas mag
			0.03,	//weapons_rifle
			0.02,	//magazine_rifle
			0.05,	//{"U_B_CombatUniform_mcam","item"},
			0.05,	//{"U_I_CombatUniform","item"},
			0.05,	//{"U_O_OfficerUniform_ocamo","item"},
			0.05,	//{"U_I_OfficerUniform","item"},
			0.05,	//{"H_HelmetB_plain_mcamo","item"},
			0.05,	//{"H_HelmetIA_camo","item"},
			0.05,	//{"H_MilCap_ocamo","item"},
			0.05,	//{"H_MilCap_mcamo","item"},
			0.05,	//{"H_MilCap_rucamo","item"},
			0.04,	//{"ItemCompass","item"},
			0.04,	//{"Binocular","item"},
			0.05,	//{"","glasses_military"},
			0.04	//{"ItemWaterBottleEmpty","magazine"}
	};	
};
class Land_Metal_wooden_rack_F_Warehouse : Furniture {
	lootPos[] = {
		{0,0,-0.903646},{0,0,-0.403646},{0,0,0.0963535}
	};
	itemType[] =	{
		{"","ferramentas"},
		{"","items_magazine"}
	};
	itemChance[] =	{
		0.05,	// ferramentas
		0.04	// items_magazine
	};	
};
class Land_Metal_wooden_rack_F_Garage : Furniture {
	lootChance = 0.3;
	lootPos[] = {
		{0,0,-0.903646},{0,0,-0.403646},{0,0,0.0963535}
	};
	itemType[] =	{
		{"","ferramentas"},
		{"","items_magazine"}
	};
	itemChance[] =	{
		0.05,	// ferramentas
		0.04	// items_magazine
	};	
};
class Land_Metal_wooden_rack_F_Supermarket : Furniture {
	lootPos[] = {
		{0,0,-0.903646},{0,0,-0.403646},{0,0,0.0963535}
	};
	itemType[] =	{
		{"","furniture_food"}
	};
	itemChance[] =	{
		0.03	// comida e bebida
	};	
};
class Land_Metal_wooden_rack_F_Pharmacy : Furniture {
	lootPos[] = {
		{0,0,-0.903646},{0,0,-0.403646},{0,0,0.0963535}
	};
	itemType[] =	{
		{"","medical_lite"}
	};
	itemChance[] =	{
		0.03	// medical_lite
	};	
};
class Land_CampingTable_F_MilitaryShop : Furniture {
	lootChance = 0.3;
	lootPos[] = {
		{-0.573486,0,0.426605},{0.573486,0,0.426605}
	};
	itemType[] =	{
			{"","pistol_lite"},
			{"","mag_pistol_lite"},
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
			{"ItemWaterBottleEmpty","magazine"}
	};
	itemChance[] =	{
			0.05,	//pistolas
			0.04,	//pistolas mag
			0.03,	//weapons_rifle
			0.02,	//magazine_rifle
			0.05,	//{"U_B_CombatUniform_mcam","item"},
			0.05,	//{"U_I_CombatUniform","item"},
			0.05,	//{"U_O_OfficerUniform_ocamo","item"},
			0.05,	//{"U_I_OfficerUniform","item"},
			0.05,	//{"H_HelmetB_plain_mcamo","item"},
			0.05,	//{"H_HelmetIA_camo","item"},
			0.05,	//{"H_MilCap_ocamo","item"},
			0.05,	//{"H_MilCap_mcamo","item"},
			0.05,	//{"H_MilCap_rucamo","item"},
			0.04,	//{"ItemCompass","item"},
			0.04,	//{"Binocular","item"},
			0.05,	//{"","glasses_military"},
			0.04	//{"ItemWaterBottleEmpty","magazine"}
	};	
};

