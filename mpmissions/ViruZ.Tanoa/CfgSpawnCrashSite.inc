class CfgSpawnCrashSite {
	frequency = (20 * 60); 	// Time in muntes to try respawn another Heli
	variance = (5 * 60);	// Time in minutes to ad variance on "minutes"
	spawnChance = 1;		// Spawn chance. 0.1 = 10% 1 = 100%
	useStatic = 0;			// 0 = DISABLE 1 = ENABLE if you use static cords you will need add coods 2d in "staticcoords"
	crashDamage = 0.30;		// Amount of damage need do to turn heli down 0.1 = 10% 1 = 100%
	staticcoords[]= {[1119.5856,2477.1587,0],[6994.6992,14189.774,0]};
};