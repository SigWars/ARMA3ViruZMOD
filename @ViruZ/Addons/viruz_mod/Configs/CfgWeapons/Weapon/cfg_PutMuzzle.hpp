class Put : Default {
	muzzles[] = {"FMradioMuzzle","DemoChargeMuzzle", "PipeBombMuzzle", "MineMuzzle", "DirectionalMineRemoteMuzzle", "ClassicMineRangeMuzzle", "BoundingMineRangeMuzzle", "DirectionalMineRangeMuzzle", "ClassicMineWireMuzzle"};
//	displayName = "$STR_A3_CfgWeapons_Put0";
	class PutMuzzle;
	
	class FMradioMuzzle : PutMuzzle {
		autoreload = false;
		displayName = "$STR_A3_cfgVehicles_Land_FMradio_F0";
		magazines[] = {"FMradio_Mag"};
		enableAttack = false;	//enableAttack = true;
		showToPlayer = false;
	};
};