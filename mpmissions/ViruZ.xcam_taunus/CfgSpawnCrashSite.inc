class CfgSpawnCrashSite {
	frequency = (20 * 60); 	// Time in muntes to try respawn another Heli
	variance = (5 * 60);	// Time in minutes to ad variance on "minutes"
	spawnChance = 1;		// Spawn chance. 0.1 = 10% 1 = 100%
	useStatic = false;		// if you use static cords you will need add coods 2d in "staticcoords"
	crashDamage = 0.30;		// Amount of damage need do to turn heli down 0.1 = 10% 1 = 100%
	staticcoords[]= {[16011.9,9426.54,0.00134277],[2253.34,9997.69,0.00158691]};
};