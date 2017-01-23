//////////////////////////////////////////////////
//
//     ViruZ Mod HeliCrash Loot ViruZ
//     Version 1.0.1
//	   Author: ViruZModTeam
//
///////////////////////////////////////////////////

class HelicrashViruZ: Default {
		zombieChance = 0.4;
		minRoaming = 3;
		maxRoaming = 4;
		zombieClass[] = {"z_soldier_heavy","z_soldier_pilot","z_soldier"};
		lootChance = 0.5;
		lootPos[] = {};
		itemType[] =	{
			{"","Rifles_Flashlights"},
			{"","Lasers"},
			{"","Bipods"},
			{"","Suppressors_Low"},
			{"","Optics_Low"},
			{"","Assault_Low"},
			{"","Mag_Assault_Low"}
		};
		itemChance[] =	{
			0.05,	//Rifles Flashlights
			0.05,	//Lasers
			0.05,	//Bipods
			0.04,	//Suppressors Low
			0.04,	//Optics Low
			0.04,	//Assault Low
			0.04	//Mag Assault Low
		};
	};
	
//holders
	
class VZBox_MediaV: HelicrashViruZ { //HELICRASH BOX
		lootChance = 0.7;
		isObjectHolder = 1;
		isBuildingPos = 0;
};