//////////////////////////////////////////////////
//
//     ViruZ Mod HeliCrash Loot ViruZ
//     Version 1.0.1
//	   Author: ViruZModTeam
//
///////////////////////////////////////////////////

class HelicrashViruZ: Default {
		zombieChance = 1;
		minRoaming = 3;
		maxRoaming = 4;
		zombieClass[] = {"z_soldier_heavy","z_soldier_pilot","z_soldier"};
		lootChance = 0.5;
		maxSpawns = 3;
		lootPos[] = {};
		itemType[] =	{
			{"","Rifles_Flashlights"},
			{"","Assault_Low"},
			{"","Mag_Assault_Low"},
			{"ItemBloodbag","magazine"},
			{"ItemEpinephrine","magazine"},
			{"ItemMorphine","magazine"},
			{"FoodMRE","magazine"}
		};
		itemChance[] =	{
			0.04,	//Rifles Flashlights
			0.08,	//Assault Low
			0.06,	//Mag Assault Low
			0.03,	//Bloodbag
			0.01,	//Epipen
			0.03,	//Morphine
			0.04	//MRE
		};
	};
	
//holders
	
class VZBox_MediaV: HelicrashViruZ { //HELICRASH BOX
		lootChance = 0.7;
		isObjectHolder = 1;
		isBuildingPos = 0;
};