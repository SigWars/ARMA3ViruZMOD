class WeaponsBox_SRV : ThingX {
	animated = false;
	scope = public;
	hiddenSelections[] = {"Camo_Signs", "Camo"};
	hiddenSelectionsTextures[] = {"A3\Weapons_F\Ammoboxes\data\AmmoBox_signs_CA.paa", "A3\Weapons_F\Ammoboxes\data\AmmoBox_CO.paa"};
	icon = "iconCrateWpns";
	model = "\A3\weapons_F\AmmoBoxes\WpnsBox_F";
	displayName = "$STR_A3_CfgVehicles_Box_NATO_Wps0";
	accuracy = 1000;	// accuracy needed to recognize type of this target
	typicalCargo[] = {};
	vehicleClass = "Ammo";
	destrType = "";
	explosionEffect = "";
	maximumLoad = 9999;
	transportMaxWeapons = 2;
	transportMaxMagazines = 15;
	transportMaxBackpacks = 1;
	transportMaxItems = 5;
	transportAmmo = 0;
	transportRepair = 0;
	transportFuel = 0;
	supplyRadius = 1.4;
	cost = 0;
	armor = 200;
	mapSize = 2;
	waterLinearDampingCoefY = 1.0;
	waterAngularDampingCoef = 0.1;
		
	class TransportMagazines {};
	class TransportWeapons {};
	class TransportItems {};
};

class VZBox_MediaV : NATO_Box_Base //media deitada verde --- USADA NO HELICRASH
	{
		//helicrash box
		mapSize = 1.81;
		animated = false;
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Box_NATO_Wps0";
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_F";
		icon = "iconCrateWpns";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	};

class VZBox_GrandeV : NATO_Box_Base //grande verde
	{
		mapSize = 2.34;
		scope = 2;
		animated = false;
		displayName = "$STR_A3_CfgVehicles_Box_NATO_WpsSpecial0";
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_large_F";
		icon = "iconCrateLarge";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	};

class VZBox_GrandeA : EAST_Box_Base //grande amarela
	{
		scope = 2;
		animated = false;
		mapSize = 2.34;
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_large_F";
		icon = "iconCrateLarge";
		displayName = "$STR_A3_CfgVehicles_Box_East_WpsSpecial_F0";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	};
class VZBox_pequenaA : EAST_Box_Base //pequena amarela
	{
		scope = 2;
		animated = false;
		mapSize = 2.34;
		model = "\A3\weapons_F\AmmoBoxes\AmmoBox_F";
		icon = "iconCrateGrenades";
		displayName = "$STR_A3_CfgVehicles_Box_East_Grenades_F0";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	class AnimationSources{};
	};
class VZBox_MediaA : EAST_Box_Base //media deitada amarela
	{
		mapSize = 1.81;
		scope = 2;
		animated = false;
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_F";
		icon = "iconCrateWpns";
		displayName = "$STR_A3_CfgVehicles_Box_East_Wps_F0";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	};
class VZBox_PequenaC : IND_Box_Base //deitada cinza pqna
	{
		mapSize = 1.81;
		scope = 2;
		animated = false;
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_F";
		icon = "iconCrateWpns";
		displayName = "$STR_A3_CfgVehicles_Box_IND_Wps_F0";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	};
class VZBox_PqnaC: IND_Box_Base //pqna em pe cinza
	{
		scope = 2;
		animated = false;
		mapSize = 1.81;
		model = "\A3\weapons_F\AmmoBoxes\AmmoBox_F";
		icon = "iconCrateGrenades";
		displayName = "$STR_A3_CfgVehicles_Box_IND_Grenades_F0";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	class AnimationSources{};
	};
class VZBox_GrandeC: IND_Box_Base //grande deitada cinza
	{
		mapSize = 2.34;
		animated = false;
		scope = 2;
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_large_F";
		icon = "iconCrateLarge";
		displayName = "$STR_A3_CfgVehicles_Box_IND_WpsSpecial_F0";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	};

//ViruZ Loot Holders
class VZ_MedBox_lite : IND_Box_Base
	{
		mapSize=0.44;
		animated = false;
		scope = 2;
		displayName = $STR_VIRUZ_OBJ_2;
		//model = "\viruz_equip\models\medicalbox_1.p3d";
		icon="iconObject_circle";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
		
		
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	};
class VZ_MedBox_especial : IND_Box_Base
	{
		mapSize=0.44;
		animated = false;
		scope = 2;
		displayName = $STR_VIRUZ_OBJ_2;
		//model = "\viruz_equip\models\medicalbox_1.p3d";
		icon="iconObject_circle";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
		
		
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	};	

class VZ_Cesta : IND_Box_Base
	{
		mapSize=0.44;
		animated = false;
		scope = 2;
		displayName="$STR_A3_CfgVehicles_Land_Basket_F0";
		model="\A3\Structures_F\Civ\Market\Basket_F.p3d";
		icon="iconObject_circle";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;

	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	};
	
class Crate_Plastic : IND_Box_Base
	{
		mapSize=0.94999999;
		animated = false;
		scope = 2;
		displayName="$STR_A3_CfgVehicles_Land_CratesPlastic_F0";
		model="\A3\Structures_F\Civ\Market\CratesPlastic_F.p3d";
		icon="iconObject_3x2";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;

	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	};

class VZ_weaponbox_lite : IND_Box_Base //pqna em pe cinza
	{
		scope = 2;
		animated = false;
		mapSize = 1.81;
		model = "\A3\weapons_F\AmmoBoxes\AmmoBox_F";
		icon = "iconCrateGrenades";
		displayName = "$STR_A3_CfgVehicles_Box_IND_Grenades_F0";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	class AnimationSources{};
	};

class VZ_weaponbox_gold : EAST_Box_Base //pequena amarela
	{
		scope = 2;
		animated = false;
		mapSize = 2.34;
		model = "\A3\weapons_F\AmmoBoxes\WpnsBox_F";
		icon = "iconCrateGrenades";
		displayName = "$STR_A3_CfgVehicles_Box_East_Grenades_F0";
		maximumLoad = 9999;
		transportMaxWeapons = 20;
		transportMaxMagazines = 300;
		transportMaxBackpacks = 20;
		transportMaxItems = 300;
		transportAmmo = 20;
		transportRepair = 20;
		transportFuel = 0;
		cost = 0;
		armor = 200;
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	class AnimationSources{};
	};	
	
//ViruZ Racks holders
class ViruZ_WorkStand : IND_Box_Base
{
		scope = 2;
		//vehicleClass = "ViruZHolders";
		displayName="$STR_A3_CfgVehicles_Land_WorkStand_F0";
		model="\A3\Structures_F\Civ\Constructions\WorkStand_F.p3d";
		icon="iconObject_5x1";
		destrType = "DestructBuilding";
		maximumLoad = 9999;
		cost = 0;
		armor = 50000;
		
		transportMaxWeapons = 50;
		transportMaxMagazines = 50;
		transportMaxItems = 50;	
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
	
};	
class ViruZHolder_base : IND_Box_Base
{	//DestructNo
	scope = 2;
	//vehicleClass = "ViruZHolders";
	model = "\A3\weapons_F\AmmoBoxes\WpnsBox_F";
	icon = "iconCrateGrenades";
	displayName = "$STR_A3_CfgVehicles_Box_East_Grenades_F0";
	destrType = "DestructNo";
	maximumLoad = 9999;
	cost = 0;
	armor = 50000;
		
	transportMaxWeapons = 50;
	transportMaxMagazines = 50;
	transportMaxItems = 50;	
	class TransportMagazines{};
	class TransportWeapons{};
	class TransportItems{};
};
	
class Rack_Madeira : ViruZHolder_base
{
	scope = 2;
	//vehicleClass = "ViruZHolders";
	model = "\A3\Structures_F\Furniture\Rack_F.p3d";
	icon = "iconObject_1x3";
	displayName = "$STR_A3_CfgVehicles_Land_Rack_F0";
	maximumLoad = 360;
	
	transportMaxMagazines = 25;
	transportMaxWeapons = 8;
	transportMaxBackpacks = 3;
		
	cost = 0;
	armor = 50000;

};

class Stante_Madeira : ViruZHolder_base
{
	scope = 2;
	//vehicleClass = "ViruZHolders";
	displayName="$STR_A3_CfgVehicles_Land_ShelvesWooden_blue_F0";
	model="\A3\Structures_F\Furniture\ShelvesWooden_blue_F.p3d";
	icon="iconObject_1x2";
	maximumLoad = 700;
	
	transportMaxMagazines = 50;
	transportMaxWeapons = 15;
	transportMaxBackpacks = 5;
		
	cost = 0;
	armor = 50000;

};

class Rack_Ferro : ViruZHolder_base
{
	scope = 2;
	//vehicleClass = "ViruZHolders";
	model="\A3\Structures_F\Furniture\Metal_rack_F.p3d";
	icon="iconObject_4x1";
	displayName="$STR_A3_CfgVehicles_Land_Metal_rack_F0";
	maximumLoad = 360;
	
	transportMaxMagazines = 25;
	transportMaxWeapons = 8;
	transportMaxBackpacks = 3;
		
	cost = 0;
	armor = 50000;

};

class Stante_Ferro : ViruZHolder_base
{
	scope = 2;
	//vehicleClass = "ViruZHolders";
	displayName="$STR_A3_CfgVehicles_Land_Metal_rack_Tall_F0";
	model="\A3\Structures_F\Furniture\Metal_rack_Tall_F.p3d";
	icon="iconObject_5x2";
	maximumLoad = 700;
	
	transportMaxMagazines = 50;
	transportMaxWeapons = 15;
	transportMaxBackpacks = 5;
		
	cost = 0;
	armor = 50000;

};

