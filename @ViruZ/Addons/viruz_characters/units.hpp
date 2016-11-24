class B_Guerilla1_1_srv : B_Soldier_F {
	scope = public;
	displayName = "$STR_A3_CfgVehicles_B_Soldier_F0";
	uniformClass = "U_B_Guerilla1_1_srv";
	model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla1_1.p3d";
};
class B_Guerilla2_1_srv : B_Soldier_F {
	scope = public;
	displayName = "$STR_A3_CfgVehicles_B_Soldier_F0";
	uniformClass = "U_B_Guerilla2_1_srv";
	model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
};
class B_Guerilla2_2_srv : B_Soldier_F {
	scope = public;
	displayName = "$STR_A3_CfgVehicles_B_Soldier_F0";
	uniformClass = "U_B_Guerilla2_2_srv";
	model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
	hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla2_2_co.paa"};
};
class B_Guerilla2_3_srv : B_Soldier_F {
	scope = public;
	displayName = "$STR_A3_CfgVehicles_B_Soldier_F0";
	uniformClass = "U_B_Guerilla2_3_srv";
	model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla2_1.p3d";
	hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla2_3_co.paa"};
};
class B_Guerilla3_1_srv : B_Soldier_F {
	scope = public;
	displayName = "$STR_A3_CfgVehicles_B_Soldier_F0";
	uniformClass = "U_B_Guerilla3_1_srv";
	model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla3_1.p3d";
	hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla3_1_co.paa"};
};
class B_Guerilla3_2_srv : B_Soldier_F {
	scope = public;
	displayName = "$STR_A3_CfgVehicles_B_Soldier_F0";
	uniformClass = "U_B_Guerilla3_2_srv";
	model = "\A3\characters_F_gamma\Guerrilla\ig_guerrilla3_1.p3d";
	hiddenSelectionsTextures[] = {"\A3\Characters_F_Gamma\Guerrilla\Data\ig_guerrilla3_2_co.paa"};
};
class B_leader_srv : B_Soldier_F {
	scope = public;
	displayName = "$STR_A3_CfgVehicles_B_Soldier_F0";
	uniformClass = "U_B_leader_srv";
	model = "\A3\characters_F_gamma\Guerrilla\ig_leader.p3d";
};

class O_Soldier_F_srv : B_Soldier_F {
	scope = public;
	displayName = "$STR_A3_CfgVehicles_B_Soldier_F0";
	uniformClass = "U_O_CombatUniform_ocamo_srv";
	model = "\A3\characters_F\OPFOR\o_soldier_01.p3d";
};
class B_sniper_F;
class O_sniper_F_srv : B_sniper_F {
	scope = public;
	displayName = "$STR_B_sniper_F0";
	uniformClass = "U_O_GhillieSuit_srv";
	model = "A3\Characters_F\OPFOR\o_sniper.p3d";
};
class B_diver_F;
class O_diver_F_srv : B_diver_F {
	scope = public;
	displayName = "$STR_B_diver_F0";
	uniformClass = "U_O_Wetsuit_srv";
	model = "\A3\characters_F\Common\diver_slotable";
};