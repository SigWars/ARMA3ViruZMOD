class SUV_01_Bardo_SRV : SUV_01_base_F {
	author = "$STR_A3_Bohemia_Interactive";
	_generalMacro = C_SUV_01_F;
	scope = public;
	crew = "C_man_1";
	typicalCargo[] = {"C_man_1"};
	side = TCivilian;
	faction = CIV_F;
	accuracy = 1.25;	// accuracy needed to recognize type of this target
	hiddenSelectionsTextures[] = {"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_CO.paa"};
	
	class EventHandlers : EventHandlers {
		init = "(_this select 0) execVM ""\A3\soft_f_gamma\SUV_01\scripts\clock.sqf""";
	};
};

class SUV_01_Black_SRV : SUV_01_Bardo_SRV {
	hiddenSelectionsTextures[] = {"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_02_CO.paa"};
};

class SUV_01_Gray_SRV : SUV_01_Bardo_SRV {
	hiddenSelectionsTextures[] = {"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_03_CO.paa"};
};

class SUV_01_Orange_SRV : SUV_01_Bardo_SRV {
	hiddenSelectionsTextures[] = {"\A3\Soft_F_Gamma\SUV_01\Data\SUV_01_ext_04_CO.paa"};
};