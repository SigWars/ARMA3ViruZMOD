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
			{"","ArmasHigh"},
			{"","Mag_ArmasHigh"},
			{"","ArmasMedias"},
			{"","Mag_ArmasMedias"},
			{"","ArmasLow"},
			{"","Mag_ArmasLow"},
			{"","Acessorios_Optic"}
		};
		itemChance[] =	{
			0.02,	//ArmasHigh
			0.02,	//Mag_ArmasHigh
			0.04,	//ArmasMedias
			0.04,	//Mag_ArmasMedias
			0.06,	//ArmasLow
			0.06,	//Mag_ArmasLow
			0.05	//Acessorios_Optic
		};
	};
	
//holders
	
class VZBox_MediaV: HelicrashViruZ { //HELICRASH BOX
		lootChance = 0.7;
		isObjectHolder = 1;
		isBuildingPos = 0;
};