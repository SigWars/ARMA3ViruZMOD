class TentStorage_base: Camping_base_F {
	vehicleClass = "Survival";
};

class TentStorage : TentStorage_base {
	mapSize = 4.8;
	author = "$STR_A3_Bohemia_Interactive";
	_generalMacro = "Land_TentA_F";
	scope = public;
	displayName = "$STR_A3_CfgVehicles_Land_TentA_F0";
	model = "\A3\Structures_F\Civ\Camping\TentA_F.p3d";
	icon = "iconObject_2x3";
	destrType = "DestructTent";
	cost = 1000;
	
	transportMaxMagazines = 25;
	transportMaxWeapons = 8;
	transportMaxBackpacks = 3;
};
	
class TentStorageDome : TentStorage_base {
	author = "$STR_A3_Bohemia_Interactive";
	_generalMacro = "Land_TentDome_F";
	scope = public;
	displayName = "$STR_A3_CfgVehicles_Land_TentDome_F0";
	model = "\A3\Structures_F\Civ\Camping\TentDome_F.p3d";
	icon = "iconObject_circle";
	destrType = "DestructTent";
	cost = 1000;
	
	transportMaxMagazines = 50;
	transportMaxWeapons = 15;
	transportMaxBackpacks = 5;
};
