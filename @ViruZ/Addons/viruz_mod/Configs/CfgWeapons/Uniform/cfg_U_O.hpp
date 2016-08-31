class U_O_CombatUniform_ocamo_srv : Uniform_Base {
	scope = public;
	displayName = "$STR_A3_Iran_Fatigues_hex";
	picture = "\A3\characters_f\data\ui\icon_U_OI_CombatUniform_ocamo_ca.paa";
	model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		
	class ItemInfo : UniformItem {
		uniformModel = "-";
		uniformClass = "O_Soldier_F_srv";
		containerClass = "Supply40";
		mass = 60;
	};
};
class U_O_GhillieSuit_srv : Uniform_Base {
	scope = public;
	displayName = "$STR_A3_Ghillie_suit_Iran";
	picture = "\A3\characters_f\data\ui\icon_U_ghillie_oucamo_ca.paa";
	model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		
	class ItemInfo : UniformItem {
		uniformModel = "-";
		uniformClass = "O_sniper_F_srv";
		containerClass = "Supply60";
		mass = 60;
	};
};
class U_O_Wetsuit_srv : Uniform_Base {
	scope = public;
	displayName = "$STR_A3_U_OI_Wetsuit0";
	picture = "\A3\characters_f\data\ui\icon_U_OI_Wetsuit_CA.paa";
	model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		
	class ItemInfo : UniformItem {
		uniformModel = "-";
		uniformClass = "O_diver_f_srv";
		containerClass = "Supply90";
		uniformType = "Neopren";
		mass = 80;
	};
};