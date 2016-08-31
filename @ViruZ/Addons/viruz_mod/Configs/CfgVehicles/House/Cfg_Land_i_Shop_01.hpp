class Land_i_Shop_01_V1_F : House_F {
	_generalMacro = "Land_i_Shop_01_V1_dam_F";
	model = "\A3\Structures_f\Households\House_Shop01\i_Shop_01_V1_dam_F.p3d";
	/*
	class Eventhandlers {
		init = "if !(isServer) then {(_this select 0) setDamage 0.5;};";
	};
	*/
};

class Land_i_Shop_01_V2_F : Land_i_Shop_01_V1_F {
	_generalMacro = "Land_i_Shop_01_V2_dam_F";
	model = "\A3\Structures_F\Households\House_Shop01\i_Shop_01_V2_dam_F.p3d";
};

class Land_i_Shop_01_V3_F : Land_i_Shop_01_V1_F {
	_generalMacro = "Land_i_Shop_01_V3_dam_F";
	model = "\A3\Structures_F\Households\House_Shop01\i_Shop_01_V3_dam_F.p3d";
};
