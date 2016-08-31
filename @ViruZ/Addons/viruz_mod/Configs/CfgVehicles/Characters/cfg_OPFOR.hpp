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