class BagBoat_Base: B_VehicleBag_base{
	scope = protected;
	picture = "\A3\Drones_F\Weapons_F_Gamma\ammoboxes\bags\data\ui\icon_B_C_UAV_rgr_ca";
	displayName = "$STR_A3_CfgVehicles_Rubber_duck_base0";
	model = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
	hiddenSelectionsTextures[] = {"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\data\UAV_backpack_rgr_co.paa"};
	maximumLoad = 100;
	mass = 600;
};

class B_Boat_Transport_01_F_backpack : BagBoat_Base {
	scope = public;	
};
class O_Boat_Transport_01_F_backpack : BagBoat_Base {
	scope = public;	
};
class I_Boat_Transport_01_F_backpack : BagBoat_Base {
	scope = public;	
};
class B_Lifeboat_backpack : BagBoat_Base {
	scope = public;
	displayName = "$STR_A3_CfgVehicles_Rescue_duck_base0";
};
class C_Rubberboat_backpack : BagBoat_Base {
	scope = public;	
};

/*
class Boat_transport_backpack_1 : Weapon_Bag_Base {
	side = TWest;
	faction = BLU_F;
	mapSize = 0.6;
	author = "$STR_A3_Bohemia_Interactive";
	_generalMacro = "B_UAV_01_backpack_F";
	scope = public;
	picture = "\A3\Drones_F\Weapons_F_Gamma\ammoboxes\bags\data\ui\icon_B_C_UAV_rgr_ca";
	displayName = "Boat transport backpack";
	model = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
	hiddenSelectionsTextures[] = {"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\data\UAV_backpack_rgr_co.paa"};
	maximumLoad = 0;
	mass = 300;
		
	class assembleInfo : assembleInfo {
		base = "";
		displayName = "Boat transport";
		assembleTo = B_Boat_Transport_01_F_SRV;
	};
};

class Boat_transport_backpack_2 : Boat_transport_backpack_1 {
	side = TEast;
	faction = OPF_F;
	class assembleInfo : assembleInfo {
		base = "";
		displayName = "Boat transport";
		assembleTo = O_Boat_Transport_01_F_SRV;
	};
};

class Boat_transport_backpack_3 : Boat_transport_backpack_1 {
	side = TGuerrila;
	faction = IND_F;
	class assembleInfo : assembleInfo {
		base = "";
		displayName = "Boat transport";
		assembleTo = I_Boat_Transport_01_F_SRV;
	};
};

class Boat_rescue_backpack_4 : Boat_transport_backpack_1 {
	side = TWest;
	faction = BLU_F;
	displayName = "Boat rescue backpack";
	class assembleInfo : assembleInfo {
		base = "";
		displayName = "Boat rescue";
		assembleTo = B_Lifeboat_SRV;
	};
};

class Boat_transport_backpack_5 : Boat_transport_backpack_1 {
	side = TCivilian;
	faction = CIV_F;
	class assembleInfo : assembleInfo {
		base = "";
		displayName = "Boat transport";
		assembleTo = C_Rubberboat_SRV;
	};
};
*/