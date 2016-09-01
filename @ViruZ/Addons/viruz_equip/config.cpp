#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define VSoft		0
#define VArmor		1
#define VAir		2

#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

class CfgPatches {
	class viruz_equip {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

class CfgVehicleClasses {
	class Survival {
		displayName = "Survival";
	};
};

class CfgWeapons {
	
	class Default;	// External class reference
	class ItemCore;	// External class reference
	class ItemInfo;
	//class InventoryItem_Base_F; //viruz_build
	
	class Loot : Default {
		scope = public;
		value = 0;
		type = VSoft;
		displayName = "Use";
		canDrop = false;
		muzzles[] = {this};
		magazines[] = {"ItemBandage", "ItemHeatPack", "PartFueltank", "PartWheel", "PartGeneric", "PartEngine", "PartVRotor", "PartGlass", "ItemWaterbottle", "ItemWaterbottleUnfilled", "ItemEpinephrine", "ItemMorphine", "ItemBloodbag", "ItemAntibiotic", "ItemPainkiller", "ItemJerrycan", "ItemGenerator", "ItemSandbag", "ItemTankTrap", "ItemWire", "FoodDrink", "ItemSodaOriginal", "ItemSodaOriginalEmpty", "FoodEdible", "FoodCanWBBeans", "FoodCanWBBeansEmpty", "FoodSteakRaw", "FoodmeatRaw", "FoodSteakCooked", "FoodmeatCooked"};
		modes[] = {this};
		useAction = false;
		useActionTitle = "";
		enableAttack = false;
		showToPlayer = false;
	};
	
	class ItemToolbox : ItemCore {
		scope = public;
		displayName="$STR_A3_cfgWeapons_ToolKit0";
		descriptionShort="$STR_A3_cfgWeapons_ToolKit1";
		picture="\A3\Weapons_F\Items\data\UI\gear_Toolkit_CA.paa";
		model="\A3\Weapons_F\Items\Toolkit";
		
		class ItemInfo {
			type = 620;
			allowedSlots[] = {701,801,901}; //only 901
			mass = 10;
			uniformModel = "\A3\Weapons_F\Items\Toolkit";
		};
	};
	
	class ItemEtool : ItemCore {
		scope = public;
		displayName = "Shovel";
		model="\A3\Structures_F_EPA\Items\Tools\Shovel_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_shovel.paa";
		descriptionShort = $STR_EQUIP_DESC_1;
		
		class ItemInfo {
			type = 620;
			allowedSlots[] = {701,801,901};
			mass = 10;
		};
	};
	class ItemKnife : ItemCore {
		scope = public;
		displayName = "Military Knife";
		model = "\viruz_equip\items\viruz_mknife.p3d";
		picture = "\viruz_equip\viruzico\mkinife.paa";
		descriptionShort = $STR_EQUIP_DESC_4;
		
		class ItemInfo {
			type = 620;
			allowedSlots[] = {701,801,901};
			mass = 10;
		};
	};
	
};

class CfgMagazines {
	class CA_Magazine;	// External class reference
	class HandGrenade;

	/*class ItemTankTrap : CA_Magazine { // ёж
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_22;
		model = "\viruz_equip\models\tank_trap_kit.p3d";
		picture = "\viruz_equip\textures\equip_tanktrap_kit_CA.paa";
		descriptionShort = $STR_EQUIP_DESC_22;
		mass = 50;
		
		class ItemActions {
			class Build {
				text = $STR_ACTIONS_BUILD;
				script = "spawn player_build;";
				require = "ItemToolbox";
				create = "Hedgehog_DZ";
			};
		};
	};*/
	
	class ItemWire : CA_Magazine { 
		scope = public;
		count = 1;
		type = 256;
		displayName = "Wire Roll";
		model="\A3\Structures_F_EPA\Items\Tools\MetalWire_F.p3d";
		picture = "\viruz_equip\viruzico\metalwire.paa";
		descriptionShort = $STR_EQUIP_DESC_23;
		mass = 10;
		
		class ItemActions {
			class Build {
				text = $STR_ACTIONS_BUILD;
				script = "spawn player_build;";
				require = "ItemToolbox";
				create = "Wire_cat1";
			};
		};
	};
	
	class ItemMatchbox : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_3;
		model = "\A3\Structures_F_EPA\Items\Tools\Matches_F.p3d";
		picture = "\viruz_equip\viruzico\matchbox.paa";
		descriptionShort = $STR_EQUIP_DESC_3;
		mass = 4;
		
		class ItemActions {
			class Use {
				text = $STR_ACTIONS_LIGHTFIRE;
				script = "spawn player_makeFire;";
				use[] = {"PartWoodPile"};
			};
		};
	};
	
	class equip_nails : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Box of Nails";
		model = "\A3\Structures_F_EPA\Items\Tools\Matches_F.p3d";
		picture = "\viruz_equip\viruzico\nail_box_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_3;
		mass = 4;
	};
	
	class ItemTent : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_A3_CfgVehicles_Land_TentA_F0;
		model="\A3\Structures_F\Civ\Camping\Sleeping_bag_folded_F.p3d";
		picture = "\viruz_equip\viruzico\tentbag.paa";
		descriptionShort = $STR_EQUIP_DESC_20;
		mass = 60;
		
		class ItemActions {
			class Pitch {
				text = $STR_PITCH_TENT;
				script = "spawn player_tentPitch;";
			};
		};
	};
	class ItemTentDome : ItemTent {
		displayName = $STR_A3_CfgVehicles_Land_TentDome_F0;
	};
	
	class ItemSandbag : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_21;
		model="\A3\Structures_F\Civ\Camping\Pillow_old_F.p3d";
		picture = "\viruz_equip\viruzico\sandbag.paa";
		descriptionShort = $STR_EQUIP_DESC_21;
		mass = 10;
		
		class ItemActions {
			class Build {
				text = $STR_ACTIONS_BUILD;
				script = "spawn player_build;";
				require = "ItemEtool";
				create = "Sandbag1_DZ";
			};
		};
	};

	class ItemBandage : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Bandage";
		model="\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";
		picture = "\viruz_equip\viruzico\bandage.paa";
		descriptionShort = $STR_A3_cfgWeapons_FirstAidKit1;
		mass = 8;
		
		class ItemActions {
			class Use {
				text = $STR_BANDAGE_SELF;
				script = "spawn player_useMeds;";
			};
		};
	};
	
	class PartFueltank : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 4);
		displayName = $STR_EQUIP_NAME_8;
		model = "\viruz_equip\items\viruz_fueltank.p3d";
		picture = "\viruz_equip\viruzico\fuel_tank_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_8;
		mass = 80;
	};
	
	class PartWheel : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 6);
		displayName = $STR_EQUIP_NAME_9;
		model="\A3\Structures_F\Civ\Garbage\Tyre_F.p3d";
		picture = "\viruz_equip\viruzico\whell.paa";
		descriptionShort = $STR_EQUIP_DESC_9;
		mass = 80;
	};
	
	class PartGeneric : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 3);
		displayName = $STR_EQUIP_NAME_10;
		model = "\viruz_equip\items\viruz_scrap.p3d";
		picture = "\viruz_equip\viruzico\scrap.paa";
		descriptionShort = $STR_EQUIP_DESC_10;
		mass = 20;
	};
	
	class PartEngine : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 6);
		displayName = $STR_EQUIP_NAME_11;
		model = "\viruz_equip\items\viruz_engine.p3d";
		picture = "\viruz_equip\viruzico\viruz_engine_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_11;
		mass = 60;
	};
	
	class PartWoodPile : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 2);
		displayName = $STR_EQUIP_NAME_40;
		model = "\A3\Structures_F_EPA\Civ\Camping\WoodenLog_F.p3d";
		picture = "\viruz_equip\viruzico\woodpile_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_40;
		mass = 20;
	};
	
	class PartVRotor : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 6);
		displayName = $STR_EQUIP_NAME_32;
		model = "\viruz_equip\items\viruz_rotor.p3d";
		picture = "\viruz_equip\viruzico\vz_rotor.paa";
		descriptionShort = $STR_EQUIP_DESC_32;
		mass = 60;
	};
	
	class PartGlass : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 2);
		displayName = $STR_EQUIP_NAME_30;
		model = "\viruz_equip\items\viruz_carglass.p3d";
		picture = "\viruz_equip\viruzico\papelao_full_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_30;
		mass = 30;
	};
	//? same model of free net models
	/*class TrapBear : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Bear Trap";
		model = "\viruz_equip\items\viruz_bear_trap.p3d";
		picture = "\viruz_equip\viruzico\equip_bear_trap_ca.paa";
		descriptionShort = "Place to add a bear trap";
		mass = 20;
		
		class ItemActions {
			class Build {
				text = "Place Trap";
				script = "spawn player_setTrap;";
				create = "BearTrap_DZ";
			};
		};
	};*/
	
	class ItemEpinephrine : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_14;
		model = "\viruz_equip\items\viruz_epipen.p3d";
		picture = "\viruz_equip\viruzico\viruz_epipen_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_14;
		mass = 4;
		
	};
	
	class ItemMorphine : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_15;
		model = "\viruz_equip\items\viruz_morphine.p3d";
		picture = "\viruz_equip\viruzico\viruz_morphine_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_15;
		mass = 4;
		
		class ItemActions {
			class Use {
				text = $STR_TAKE_MORPHINE;
				script = "spawn player_useMeds;";
			};
		};
	};
	
	class ItemHeatPack : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_42;
		model = "\A3\Structures_F_EPA\Items\Medical\HeatPack_F.p3d";
		picture = "\viruz_equip\viruzico\heatpack_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_42;
		mass = 4;
		
		class ItemActions {
			class Use {
				text = $STR_ACTIONS_HEATPACK;
				script = "spawn player_useMeds;";
			};
		};
	};
	
	class ItemBloodbag : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_16;
		model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_bloodbag_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_16;
		mass = 7;
	};
	
	class ItemAntibiotic : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_17;
		model = "\A3\Structures_F_EPA\Items\Medical\Antibiotic_F.p3d";
		picture = "\viruz_equip\viruzico\antibiotic_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_17;
		mass = 4;
		
		class ItemActions {
			class Use {
				text = $STR_TAKE_ANTIBIOTIC;
				script = "spawn player_useMeds;";
			};
		};
	};
	
	class ItemPainkiller : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_18;
		model = "\A3\Structures_F_EPA\Items\Medical\PainKillers_F.p3d";
		picture = "\viruz_equip\viruzico\painkiller_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_18;
		mass = 4;
		
		class ItemActions {
			class Use {
				text = $STR_TAKE_PAINKILLER;
				script = "spawn player_useMeds;";
			};
		};
	};
	class Viruz_Maleta : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Suitcase";
		model="\A3\structures_f\items\luggage\Suitcase_F.p3d";
		picture = "\viruz_equip\viruzico\Suitcase.paa";
		descriptionShort = "ViruZ";
		mass=80;
	};
	class Viruz_Hammer : CA_Magazine {
	
		scope = public;
		count = 1;
		type = 256;
		displayName = "Hammer";
		model="\A3\Structures_F\Items\Tools\Hammer_F.p3d";
		picture = "\viruz_equip\viruzico\hammer.paa";
		descriptionShort = "ViruZ";
		mass=15;
	};
	
	class Viruz_Serrote : CA_Magazine {

		scope = public;
		type = 256;
		count = 1;
		displayName = "Saw";
		model="\A3\Structures_F\Items\Tools\Saw_F.p3d";
		picture = "\viruz_equip\viruzico\saw.paa";
		descriptionShort = "ViruZ";
		mass=15;
	};
	class Viruz_Wrench : CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName = "Wrench";
		model="\A3\Structures_F\Items\Tools\Wrench_F.p3d";
		picture = "\viruz_equip\viruzico\Wrench.paa";
		descriptionShort = "ViruZ";
		mass=8;
	};
	class Viruz_HandCan : CA_Magazine {
	
		scope = public;
		type = 256;
		count = 1;
		displayName="Handycam";
		model="\A3\structures_f\Items\electronics\HandyCam_F.p3d";
		picture = "\viruz_equip\viruzico\handycam.paa";
		descriptionShort = "ViruZ";
		mass=10;
	};
	class Viruz_Laptop: CA_Magazine
	{
		
		scope = public;
		type = 256;
		count = 1;
		displayName="Laptop";
		model="\A3\structures_f\Items\electronics\laptop_unfolded_F.p3d";
		picture = "\viruz_equip\viruzico\laptop.paa";
		descriptionShort = "ViruZ";
		mass=50;
	};
	class Viruz_MobilePhone: CA_Magazine
	{
		scope = public;
		type = 256;
		count = 1;
		displayName="MobilePhone";
		model="\A3\structures_f\Items\electronics\mobilephone_old_F.p3d";
		picture = "\viruz_equip\viruzico\Mobilephone.paa";
		descriptionShort = "ViruZ";
		mass=5;
	};
	class Viruz_SmartPhone: CA_Magazine
	{
		scope = public;
		type = 256;
		count = 1;
		displayName="SmartPhone";
		model="\A3\structures_f\Items\electronics\mobilephone_smart_F.p3d";
		picture = "\viruz_equip\viruzico\smartphone.paa";
		descriptionShort = "ViruZ";
		mass=5;
	};
	class Viruz_CinderBlock: CA_Magazine
	{
		scope = public;
		type = 256;
		count = 1;
		displayName="CinderBlock";
		model="\viruz_equip\items\viruz_cinderblock.p3d";
		picture = "\viruz_equip\viruzico\cinderblock.paa";
		descriptionShort = "ViruZ";
		mass=5;
	};
	class Viruz_Woodboard: CA_Magazine
	{
		scope = public;
		type = 256;
		count = 10;
		displayName="WoodBoard";
		model="\viruz_equip\items\viruz_woodboard.p3d";
		picture = "\viruz_equip\viruzico\woodboard_ca.paa";
		descriptionShort = "ViruZ";
		mass=10;
	};
	
	class ItemJerrycan : CA_Magazine {
		scope = public;
		count = 20;
		fuelQuantity = 20;
		type = (256 * 3);
		displayName = $STR_EQUIP_NAME_19;
		model = "\A3\Structures_F\Items\Vessels\CanisterFuel_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_jerrycan_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_19;
		mass = 100;
		allowedSlots[] = {901};
	};
	
	class ItemJerrycanEmpty : ItemJerrycan {
		count = 1;
		fuelQuantity = 0;
		type = (256 * 3);
		displayName = $STR_EQUIP_NAME_39;
		picture = "\viruz_equip\viruzico\viruz_jerrycan_e_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_39;
		mass = 40;
		allowedSlots[] = {901};
	};
	
	class ItemGenerator : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 6);
		displayName = $STR_EQUIP_NAME_31;
		model="\A3\Structures_F\Items\Electronics\Portable_generator_F.p3d";
		picture = "\viruz_equip\viruzico\vz_generator_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_31;
		mass = 100;
	};
	

	class ItemCamoNetBig : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_A3_cfgVehicles_CamoNet_big_F0;
		model = "\a3\structures_f\Civ\Camping\Sleeping_bag_folded_F.p3d";
		picture = "\A3\Weapons_F\data\UI\icon_unarmed_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_50;
		mass = 60;
		
		class ItemActions {
			class Pitch {
				text = $STR_PITCH_CamoNet;
				script = "spawn player_tentPitch;";
			};
		};
	};
	class ItemCamoNet : ItemCamoNetBig {
		displayName = $STR_A3_cfgVehicles_CamoNet_F0;
	};
	class ItemCamoNetOpen : ItemCamoNetBig {
		displayName = $STR_A3_cfgVehicles_CamoNet_open_F0;
	};
	
	class itemCampingLight : CA_Magazine {
		scope = public;
		displayName = "Camping light";
		model = "\A3\Structures_F\Civ\Camping\Camping_Light_off_F.p3d";
		picture = "\A3\Weapons_F\data\UI\icon_unarmed_ca.paa";
		count = 1;
		mass = 15;
		type = 256;
	
		class ItemActions {
			class Build {
				text = "$STR_USE";
				script = "spawn electronics_build";
				create = "Land_Camping_Light_off_F";
			};
		};
	};
	
	class itemCanOpener: CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "$STR_A3_can_opener";
		model = "\A3\Structures_F_EPA\Items\Tools\CanOpener_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_canopener_ca.paa";
		/*
		class ItemActions {
			class Open {
				text = "";
				script = "";
			};
		};
		*/
	};
	
	class FMradio_Mag : CA_Magazine {
		scope = public;
		displayName = "$STR_A3_cfgVehicles_Land_FMradio_F0";
		picture = "\viruz_equip\viruzico\radio_ca.paa";
		model = "\A3\Structures_F\Items\Electronics\FMradio_F";
		descriptionShort = "$STR_A3_cfgVehicles_Land_FMradio_F0";
		descriptionUse = "$STR_A3_cfgVehicles_Land_FMradio_F0";
		type = 2*		256;
	//	ammo = "FMradio_Ammo";
		mass = 20;
		count = 1;
		class ItemActions {
			class Build {
				text = "$STR_USE";
				script = "spawn electronics_build";
				create = "Land_FMradio_F";
			};
		};
	};

	class Battery_mag : CA_Magazine {
		author = "SigWar";
		scope = public;
		displayName = "$STR_A3_batteries";
		descriptionShort = $STR_EQUIP_DESC_48;
		model = "\A3\Structures_F_EPA\Items\Electronics\Battery_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_battery_ca.paa";
		ammo = "";	//ammo = "Battery";
		count = 7200;
		mass = 7;
		type = 256;
	};
	
	//***********************************************************************DRINKS*****************************************************************************
	class FoodDrink : CA_Magazine {
		isWater = 1;
		count = 1;
		type = 256;
		mass = 7;
		
		class ItemActions {
			class Drink {
				text = $STR_ACTIONS_DRINK;
				script = "spawn player_drink;";
			};
		};
	};
	
	class ItemWaterbottle : FoodDrink {
		scope = public;
		refillable = 1;
		sfx = "drink";
		displayName = $STR_EQUIP_NAME_12;
		model="\A3\Structures_F_EPA\Items\Food\Canteen_F.p3d";
		picture = "\viruz_equip\viruzico\canteen.paa";
		descriptionShort = $STR_EQUIP_DESC_12;
		mass = 25;
	};
	
	class ItemWaterbottleUnfilled : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_13;
		model="\A3\Structures_F_EPA\Items\Food\Canteen_F.p3d";
		picture = "\viruz_equip\viruzico\canteen_empty.paa";
		descriptionShort = $STR_EQUIP_DESC_13;
		mass = 7;
		
		class ItemActions {
			class Fill {
				text = $STR_ACTIONS_FILL_W;
				script = "spawn player_fillWater;";
			};
		};
	};

	class ItemWaterbottleBoiled : ItemWaterbottle {
		displayName = $STR_ITEMWATERBOTTLEBOILED_CODE_NAME;
		descriptionShort = $STR_ITEMWATERBOTTLEBOILED_CODE_DESC;
	};
	
	class ItemSodaOriginal : FoodDrink {
		scope = public;
		sfx = "soda";
		displayName = "Soda Original";
		model = "\viruz_equip\items\sodaoriginal.p3d";
		picture = "\viruz_equip\viruzico\sodaoriginal_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaOriginalEmpty : HandGrenade{
		scope = public;
		displayName = "Empty Soda Can";
		model = "\viruz_equip\items\sodaoriginalE.p3d";
		picture = "\viruz_equip\viruzico\sodaoriginalE_ca.paa";
		descriptionShort = "";
		mass = 2;
	};
	
	class ItemSodaDarth : ItemSodaOriginal {
		displayName = "$Soda Darth";
		model = "\viruz_equip\items\sodadarth.p3d";
		picture = "\viruz_equip\viruzico\sodadarth_ca.paa";
		descriptionShort = "Come to the dark side of the force";
	};
	
	class ItemSodaDarthEmpty : ItemSodaOriginalEmpty{
		model = "\viruz_equip\items\sodadarthE.p3d";
		picture = "\viruz_equip\viruzico\sodadarthE_ca.paa";
	};
	
	class ItemSodaDiet : ItemSodaOriginal {
		displayName = "Soda Diet";
		model = "\viruz_equip\items\sodadiet.p3d";
		picture = "\viruz_equip\viruzico\sodadiet_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaDietEmpty : ItemSodaOriginalEmpty{
		model = "\viruz_equip\items\sodadietE.p3d";
		picture = "\viruz_equip\viruzico\sodadietE_ca.paa";
	};
	
	class ItemSodaGrape : ItemSodaOriginal {
		displayName = "Soda Grape";
		model = "\viruz_equip\items\sodagrape.p3d";
		picture = "\viruz_equip\viruzico\sodagrape_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaGrapeEmpty : ItemSodaOriginalEmpty{
		model = "\viruz_equip\items\sodagrapeE.p3d";
		picture = "\viruz_equip\viruzico\sodagrapeE_ca.paa";
	};
	
	class ItemSodaHam : ItemSodaOriginal {
		displayName = "Soda Ham";
		model = "\viruz_equip\items\sodaham.p3d";
		picture = "\viruz_equip\viruzico\sodaham_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaHamEmpty : ItemSodaOriginalEmpty{
		model = "\viruz_equip\items\sodahamE.p3d";
		picture = "\viruz_equip\viruzico\sodahamE_ca.paa";
	};
	
	class ItemSodaLaranja : ItemSodaOriginal {
		displayName = "Soda Laranja";
		model = "\viruz_equip\items\sodalaranja.p3d";
		picture = "\viruz_equip\viruzico\sodalaranja_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaLaranjaEmpty : ItemSodaOriginalEmpty{
		model = "\viruz_equip\items\sodalaranjaE.p3d";
		picture = "\viruz_equip\viruzico\sodalaranjaE_ca.paa";
	};
	
	class ItemSodaLimao : ItemSodaOriginal {
		displayName = "Soda Limao";
		model = "\viruz_equip\items\sodalimao.p3d";
		picture = "\viruz_equip\viruzico\sodalimao_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaLimaoEmpty : ItemSodaOriginalEmpty{
		model = "\viruz_equip\items\sodalimaoE.p3d";
		picture = "\viruz_equip\viruzico\sodalimaoE_ca.paa";
	};
	
	class ItemSodaYoda : ItemSodaOriginal {
		displayName = "Soda Yoda";
		model = "\viruz_equip\items\sodayoda.p3d";
		picture = "\viruz_equip\viruzico\sodayoda_ca.paa";
		descriptionShort = "May the force be with you";
	};
	
	class ItemSodaYodaEmpty : ItemSodaOriginalEmpty{
		model = "\viruz_equip\items\sodayodaE.p3d";
		picture = "\viruz_equip\viruzico\sodayodaE_ca.paa";
	};
	
	class ItemSodaBeergolden : ItemSodaOriginal {
		displayName = "Beer Golden Juice";
		model = "\viruz_equip\items\beergoldenjuice.p3d";
		picture = "\viruz_equip\viruzico\beergoldenjuice_ca.paa";
		descriptionShort = "May the force be with you";
	};
	
	class ItemSodaBeergoldenEmpty : ItemSodaOriginalEmpty{
		model = "\viruz_equip\items\beergoldenjuiceE.p3d";
		picture = "\viruz_equip\viruzico\beergoldenjuiceE_ca.paa";
	};
	
	//***************************************************************FOODS*************************************************************
	class FoodEdible : CA_Magazine {
		isFood = 1;
		count = 1;
		type = 256;
		bloodRegen = 200;
		mass = 10;
		
		class ItemActions {
			class Eat {
				text = $STR_EAT_FOOD;
				script = "spawn player_eat;";
			};
		};
	};
	//Base class
	class FoodCanWBBeans : FoodEdible {
		scope = public;
		displayName = "WT Baked Beans";
		model = "\viruz_equip\items\canbeans1.p3d";
		picture = "\viruz_equip\viruzico\canbeans1_ca.paa";
		descriptionShort = "Baked beans in tomato sauce flavored with pork";
		bloodRegen = 300;
	};
	//Base Class empty
	class FoodCanWBBeansEmpty : HandGrenade {
		scope = public;
		displayName = "WT Baked Beans Empty";
		model = "\viruz_equip\items\canbeans1E.p3d";
		picture = "\viruz_equip\viruzico\canbeans1E_ca.paa";
		descriptionShort = "";
		mass = 2;
	};

	class FoodCanMHBeans : FoodEdible {
		scope = public;
		displayName = "MH Baked Beans";
		model = "\viruz_equip\items\canbeans2.p3d";
		picture = "\viruz_equip\viruzico\canbeans2_ca.paa";
		descriptionShort = "Oven baked beans in tomato sauce";
		bloodRegen = 300;
	};

	class FoodCanMHBeansEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "MH Baked Beans Empty";
		model = "\viruz_equip\items\canbeans2E.p3d";
		picture = "\viruz_equip\viruzico\canbeans2E_ca.paa";
	};
	
	class FoodCanCGBeans : FoodEdible {
		scope = public;
		displayName = "CG Baked Beans";
		model = "\viruz_equip\items\canbeans3.p3d";
		picture = "\viruz_equip\viruzico\canbeans3_ca.paa";
		descriptionShort = "Vegetarian baked beans in tomato sauce";
		bloodRegen = 300;
	};

	class FoodCanCGBeansEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "CG Baked Beans Empty";
		model = "\viruz_equip\items\canbeans3E.p3d";
		picture = "\viruz_equip\viruzico\canbeans3E_ca.paa";
		bloodRegen = 300;
	};
	
	class FoodCanBeefChunks : FoodEdible {
		scope = public;
		displayName = "Beef Chunks";
		model = "\viruz_equip\items\canbeef.p3d";
		picture = "\viruz_equip\viruzico\canbeef_ca.paa";
		descriptionShort = "Beef chunks enriched with juices";
	};

	class FoodCanBeefChunksEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Beef Chunks Empty";
		model = "\viruz_equip\items\canbeefE.p3d";
		picture = "\viruz_equip\viruzico\canbeefE_ca.paa";
	};
	
	class FoodCanChickenChunks : FoodEdible {
		scope = public;
		displayName = "Chicken Chunks";
		model = "\viruz_equip\items\canchicken.p3d";
		picture = "\viruz_equip\viruzico\canchicken_ca.paa";
		descriptionShort = "Chicken chunks with broth";
	};

	class FoodCanChickenChunksEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Chicken Chunks Empty";
		model = "\viruz_equip\items\canchickenE.p3d";
		picture = "\viruz_equip\viruzico\canchickenE_ca.paa";
	};
	
	class FoodCanChickenNoodle : FoodEdible {
		scope = public;
		displayName = "Chicken Noodle";
		model = "\viruz_equip\items\cancnoodle.p3d";
		picture = "\viruz_equip\viruzico\cancnoodle_ca.paa";
		descriptionShort = "Chicken noodle condensed soup";
	};

	class FoodCanChickenNoodleEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Chicken Noodle Empty";
		model = "\viruz_equip\items\cancnoodleE.p3d";
		picture = "\viruz_equip\viruzico\cancnoodleE_ca.paa";
	};
	
	class FoodCanFruitcocktail : FoodEdible {
		scope = public;
		displayName = "Tropical Fruit Cocktail";
		model = "\viruz_equip\items\canfruitcocktail.p3d";
		picture = "\viruz_equip\viruzico\canfruitcocktail_ca.paa";
		descriptionShort = "Tropical fruit cocktail in light syrup";
	};

	class FoodCanFruitcocktailEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Tropical Fruit Cocktail Empty";
		model = "\viruz_equip\items\canfruitcocktailE.p3d";
		picture = "\viruz_equip\viruzico\canfruitcocktailE_ca.paa";
	};
	
	class FoodCanOranges : FoodEdible {
		scope = public;
		displayName = "Mandarin Oranges";
		model = "\viruz_equip\items\canoranges.p3d";
		picture = "\viruz_equip\viruzico\canoranges_ca.paa";
		descriptionShort = "Slices of orange with no sugar added and no preservatives";
	};

	class FoodCanOrangesEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Mandarin Oranges Empty";
		model = "\viruz_equip\items\canorangesE.p3d";
		picture = "\viruz_equip\viruzico\canorangesE_ca.paa";
	};
	
	class FoodCanPeaches : FoodEdible {
		scope = public;
		displayName = "Sliced Peaches";
		model = "\viruz_equip\items\canpeaches.p3d";
		picture = "\viruz_equip\viruzico\canpeaches_ca.paa";
		descriptionShort = "Slices of peaches preserved in syrup";
	};

	class FoodCanPeachesEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Sliced Peaches Empty";
		model = "\viruz_equip\items\canpeachesE.p3d";
		picture = "\viruz_equip\viruzico\canpeachesE_ca.paa";
	};
	
	class FoodCanPears : FoodEdible {
		scope = public;
		displayName = "Sliced Pears";
		model = "\viruz_equip\items\canpears.p3d";
		picture = "\viruz_equip\viruzico\canpears_ca.paa";
		descriptionShort = "Mixed pieces of pears in light syrup";
	};

	class FoodCanPearsEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Sliced Pears Empty";
		model = "\viruz_equip\items\canpearsE.p3d";
		picture = "\viruz_equip\viruzico\canpearsE_ca.paa";
	};
	
	class FoodCanEsardines : FoodEdible {
		scope = public;
		displayName = "EM Sardines";
		model = "\viruz_equip\items\cansardines1.p3d";
		picture = "\viruz_equip\viruzico\cansardines1_ca.paa";
		descriptionShort = "Sardines in tomato sauce";
	};

	class FoodCanEsardinesEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "EM Sardines Empty";
		model = "\viruz_equip\items\cansardines1E.p3d";
		picture = "\viruz_equip\viruzico\cansardines1E_ca.paa";
	};
	
	/*class FoodCanPsardines : FoodEdible {
		scope = public;
		displayName = "PL Sardines";
		model = "\viruz_equip\items\cansardines2.p3d";
		picture = "\viruz_equip\viruzico\cansardines2_ca.paa";
		descriptionShort = "Sardines seasoned with salt";
	};

	class FoodCanPsardinesEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "PL Sardines Empty";
		model = "\viruz_equip\items\cansardines2E.p3d";
		picture = "\viruz_equip\viruzico\cansardines2E_ca.paa";
	};*/
	
	class FoodCanChickenSoup : FoodEdible {
		scope = public;
		displayName = "Chicken Soup";
		model = "\viruz_equip\items\cansoup1.p3d";
		picture = "\viruz_equip\viruzico\cansoup1_ca.paa";
		descriptionShort = "Creamy chicken soup";
	};

	class FoodCanChickenSoupEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Chicken Soup Empty";
		model = "\viruz_equip\items\cansoup1E.p3d";
		picture = "\viruz_equip\viruzico\cansoup1E_ca.paa";
	};
	
	class FoodCanPotatoSoup : FoodEdible {
		scope = public;
		displayName = "Potato Soup";
		model = "\viruz_equip\items\cansoup2.p3d";
		picture = "\viruz_equip\viruzico\cansoup2_ca.paa";
		descriptionShort = "Baked potato soup with cheddar and bacon bits";
	};

	class FoodCanPotatoSoupEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Potato Soup Empty";
		model = "\viruz_equip\items\cansoup2E.p3d";
		picture = "\viruz_equip\viruzico\cansoup2E_ca.paa";
	};
	
	class FoodCanPeaSoup : FoodEdible {
		scope = public;
		displayName = "Split Pea Soup";
		model = "\viruz_equip\items\cansoup3.p3d";
		picture = "\viruz_equip\viruzico\cansoup3_ca.paa";
		descriptionShort = "Pea soup with vegetables";
	};

	class FoodCanPeaSoupEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Split Pea Soup Empty";
		model = "\viruz_equip\items\cansoup3E.p3d";
		picture = "\viruz_equip\viruzico\cansoup3E_ca.paa";
	};
	
	class FoodCanCCCornSoup : FoodEdible {
		scope = public;
		displayName = "CC Chicken Corn Soup";
		model = "\viruz_equip\items\cansoup4.p3d";
		picture = "\viruz_equip\viruzico\cansoup4_ca.paa";
		descriptionShort = "Corn soup with chicken and vegetables";
	};

	class FoodCanCCCornSoupEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "CC Chicken Corn Soup Empty";
		model = "\viruz_equip\items\cansoup4E.p3d";
		picture = "\viruz_equip\viruzico\cansoup4E_ca.paa";
	};
	
	class FoodCanHCCornSoup : FoodEdible {
		scope = public;
		displayName = "HC Chicken Corn Soup";
		model = "\viruz_equip\items\cansoup5.p3d";
		picture = "\viruz_equip\viruzico\cansoup5_ca.paa";
		descriptionShort = "Corn soup with chicken and vegetables";
	};

	class FoodCanHCCornSoupEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "HC Chicken Corn Soup Empty";
		model = "\viruz_equip\items\cansoup5E.p3d";
		picture = "\viruz_equip\viruzico\cansoup5E_ca.paa";
	};
	
	class FoodCanTRSoup : FoodEdible {
		scope = public;
		displayName = "Tyke Rice Soup";
		model = "\viruz_equip\items\cansoup6.p3d";
		picture = "\viruz_equip\viruzico\cansoup6_ca.paa";
		descriptionShort = "Condensed rice soup with cheese";
	};

	class FoodCanTRSoupEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Tyke Rice Soup Empty";
		model = "\viruz_equip\items\cansoup6E.p3d";
		picture = "\viruz_equip\viruzico\cansoup6E_ca.paa";
	};
	
	class FoodCanCRiceSoup : FoodEdible {
		scope = public;
		displayName = "Chicken and Rice Soup";
		model = "\viruz_equip\items\cansoup7.p3d";
		picture = "\viruz_equip\viruzico\cansoup7_ca.paa";
		descriptionShort = "Condensed chicken and rice soup with vegetables";
	};

	class FoodCanCRiceSoupEmpty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "Chicken and Rice Soup Empty";
		model = "\viruz_equip\items\cansoup7E.p3d";
		picture = "\viruz_equip\viruzico\cansoup7E_ca.paa";
	};
	
	class FoodCanSpaghetti1 : FoodEdible {
		scope = public;
		displayName = "FL Spaghetti";
		model = "\viruz_equip\items\canspaghetti1.p3d";
		picture = "\viruz_equip\viruzico\canspaghetti1_ca.paa";
		descriptionShort = "Spaghetti in tomato sauce flavoured with cheese";
		bloodRegen = 300;
	};

	class FoodCanSpaghetti1Empty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "FL Spaghetti Empty";
		model = "\viruz_equip\items\canspaghetti1E.p3d";
		picture = "\viruz_equip\viruzico\canspaghetti1E_ca.paa";
	};
	
		class FoodCanSpaghetti2 : FoodEdible {
		scope = public;
		displayName = "WT Spaghetti";
		model = "\viruz_equip\items\canspaghetti2.p3d";
		picture = "\viruz_equip\viruzico\canspaghetti2_ca.paa";
		descriptionShort = "Spaghetti in tomato sauce flavoured with cheese";
		bloodRegen = 300;
	};

	class FoodCanSpaghetti2Empty : FoodCanWBBeansEmpty {
		scope = public;
		displayName = "WT Spaghetti Empty";
		model = "\viruz_equip\items\canspaghetti2E.p3d";
		picture = "\viruz_equip\viruzico\canspaghetti2E_ca.paa";
	};
	
	//********************************************************************************MEAT RAW********************************************************************************************
	class FoodSteakRaw : FoodEdible {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_24;
		model = "\viruz_equip\items\viruz_rawsteak.p3d";
		picture = "\viruz_equip\viruzico\raw_meat_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_24;
		bloodRegen = 200;
	};
	
	class FoodmeatRaw : FoodSteakRaw {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_FOOD_EQIP_CODE_NAME_0;
		descriptionShort = $STR_FOOD_EQUIP_CODE_DESC_0;
		bloodRegen = 100;
	};
	
	class FishRawTrout : FoodmeatRaw {
		displayName = $STR_FOOD_NAME_TROUT_RAW;
		descriptionShort = $STR_FOOD_EQUIP_TROUT_RAW;
		model = "\viruz_equip\items\trout.p3d";
		picture = "\viruz_equip\viruzico\trout_ca.paa";	
		bloodRegen = 200;
	};
	
	class FishRawSeaBass : FoodmeatRaw {
		displayName = $STR_FOOD_NAME_SEABASS_RAW;
		descriptionShort = $STR_FOOD_EQUIP_SEABASS_RAW;
		model = "\viruz_equip\items\seabass.p3d";
		picture = "\viruz_equip\viruzico\seabass_ca.paa";	
		bloodRegen = 400;
	};
	
	class FishRawTuna : FoodmeatRaw {
		displayName = $STR_FOOD_NAME_TUNA_RAW;
		descriptionShort = $STR_FOOD_EQUIP_TUNA_RAW;
		model = "\viruz_equip\items\tuna.p3d";
		picture = "\viruz_equip\viruzico\tuna_ca.paa";	
		bloodRegen = 500;
	};
	
	class FoodmuttonRaw : FoodmeatRaw {
		displayName = $STR_FOOD_EQIP_CODE_NAME_1;
		descriptionShort = $STR_FOOD_EQUIP_CODE_DESC_1;
		bloodRegen = 100;
	};
	
	class FoodchickenRaw : FoodmeatRaw {
		displayName = $STR_FOOD_EQIP_CODE_NAME_2;
		descriptionShort = $STR_FOOD_EQUIP_CODE_DESC_2;
		bloodRegen = 100;
	};
	
	class FoodrabbitRaw : FoodmeatRaw {
		displayName = $STR_FOOD_EQIP_CODE_NAME_3;
		descriptionShort = $STR_FOOD_EQUIP_CODE_DESC_3;
		bloodRegen = 400;
	};
	
	class FoodbaconRaw : FoodmeatRaw {
		displayName = $STR_FOOD_EQIP_CODE_NAME_4;
		descriptionShort = $STR_FOOD_EQUIP_CODE_DESC_4;
		bloodRegen = 150;
	};
	class FoodbeefRaw : FoodmeatRaw {
		displayName = $STR_FOOD_EQIP_CODE_NAME_6;
		descriptionShort = $STR_FOOD_EQUIP_CODE_DESC_6;
		bloodRegen = 100;
	};
	
	//************************************************************************COOCKED MEAT********************************************************************
	
	class FoodSteakCooked : FoodEdible {
		scope = public;
		displayName = $STR_EQUIP_NAME_25;
		model = "\viruz_equip\items\viruz_coocksteak.p3d";
		picture = "\viruz_equip\viruzico\cooked_steak_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_25;
		bloodRegen = 300;
	};
	
	class FoodmeatCooked : FoodSteakCooked {
		scope = public;
		count = 1;
		displayName = $STR_FOODCOOKED_EQIP_CODE_NAME_0;
		descriptionShort = $STR_FOODCOOKED_EQUIP_CODE_DESC_0;
		bloodRegen = 800;
	};
	
	//fishs
	class FishCookedTrout : FoodmeatCooked {
		displayName = $STR_FOOD_NAME_TROUT_COOKED;
		descriptionShort = $STR_FOOD_EQUIP_TROUT_COOKED;
		model = "\viruz_equip\items\coocked_trout.p3d";
		picture = "\viruz_equip\viruzico\coocked_trout_ca.paa";
		bloodRegen = 1000;
	};
	
	class FishCookedSeaBass : FoodmeatCooked {
		displayName = $STR_FOOD_NAME_SEABASS_COOKED;
		descriptionShort = $STR_FOOD_EQUIP_SEABASS_COOKED;
		model = "\viruz_equip\items\coocked_seabass.p3d";
		picture = "\viruz_equip\viruzico\coocked_seabass_ca.paa";
		bloodRegen = 1400;
	};
	
	class FishCookedTuna : FoodmeatCooked {
		displayName = $STR_FOOD_NAME_TUNA_COOKED;
		descriptionShort = $STR_FOOD_EQUIP_TUNA_COOKED;
		model = "\viruz_equip\items\coocked_tuna.p3d";
		picture = "\viruz_equip\viruzico\coocked_tuna_ca.paa";
		bloodRegen = 2000;
	};

	class FoodmuttonCooked : FoodmeatCooked {
		displayName = $STR_FOODCOOKED_EQIP_CODE_NAME_1;
		descriptionShort = $STR_FOODCOOKED_EQUIP_CODE_DESC_1;
		bloodRegen = 400;
	};
	
	class FoodchickenCooked : FoodmeatCooked {
		displayName = $STR_FOODCOOKED_EQIP_CODE_NAME_2;
		descriptionShort = $STR_FOODCOOKED_EQUIP_CODE_DESC_2;
		bloodRegen = 400;
	};
	
	class FoodbaconCooked : FoodmeatCooked {
		displayName = $STR_FOODCOOKED_EQIP_CODE_NAME_4;
		descriptionShort = $STR_FOODCOOKED_EQUIP_CODE_DESC_4;
		bloodRegen = 400;
	};
	class FoodrabbitCooked : FoodmeatCooked {
		displayName = $STR_FOODCOOKED_EQIP_CODE_NAME_3;
		descriptionShort = $STR_FOODCOOKED_EQUIP_CODE_DESC_3;
		bloodRegen = 1600;
	};
	class FoodbeefCooked : FoodmeatCooked {
		displayName = $STR_FOODCOOKED_EQIP_CODE_NAME_6;
		descriptionShort = $STR_FOODCOOKED_EQUIP_CODE_DESC_6;
		bloodRegen = 600;
	};
	
	class FoodMRE : FoodEdible {
		scope = public;
		count = 1;
		bloodRegen = 1500;
		displayName = $STR_FOOD_NAME_MRE;
		descriptionShort = $STR_FOOD_DESC_MRE;
		model = "\viruz_equip\items\mre.p3d";
		picture = "\viruz_equip\viruzico\mre_ca.paa";
	};
	
};

class CfgVehicles {
	class NonStrategic;	// External class reference
	
	class BuiltItems : NonStrategic {};
	
	class TrapItems : NonStrategic {};
	
	class Land_BagFence_Long_F;
	class Sandbag1_DZ :Land_BagFence_Long_F {
		destrType = "DestructNo";
	};
	
	class Land_Razorwire_F;
	class Wire_cat1 : Land_Razorwire_F {
		scope = public;
		displayName = "Wire (CAT1)";
		destrType = "DestructNo";
	};
	
	/*class BearTrap_DZ : TrapItems {
		scope = public;
		destrType = "DestructNo";
		displayName = "Bear Trap";
		model = "\viruz_equip\items\viruz_bear_trap.p3d";
		
		class Eventhandlers {
			init = "_this execFSM '\z\addons\viruz_mod\system\trap_monitor.fsm';";
		};
		
		class AnimationSources {
			class LeftShutter {
				source = "user";
				animPeriod = 0.1;
				initPhase = 1;
			};
			
			class RightShutter {
				source = "user";
				animPeriod = 0.1;
				initPhase = 1;
			};
		};
		
		class UserActions {
			class OpenTrap {
				position = "";
				displayName = "Reset Trap";
				radius = 1.5;
				onlyForPlayer = 0;
				condition = "this animationPhase 'LeftShutter' == 1";
				statement = "this animate ['LeftShutter', 0];this animate ['RightShutter', 0];";
			};
			
			class CloseTrap {
				position = "";
				displayName = "Activate Trap";
				radius = 1.5;
				onlyForPlayer = 0;
				condition = "this animationPhase 'LeftShutter' == 0";
				statement = "this animate ['LeftShutter', 1];this animate ['RightShutter', 1];";
			};
			
			class CollectTrap {
				position = "";
				displayName = "Take Trap";
				radius = 1.5;
				onlyForPlayer = 0;
				condition = "this animationPhase 'LeftShutter' == 1";
				statement = "[0,0,0,['cfgMagazines','TrapBear',this]] call object_pickup;";
			};
		};
	};*/
	class ReammoBox;	// External class reference

	/*class CardboardBox : ReammoBox {
		accuracy = 1000;	// accuracy needed to recognize type of this target
		vehicleClass = "Survival";
		isGround = 0;
	};
	
	class FoodBox0 : CardboardBox {
		scope = public;
		displayName = $STR_VIRUZ_OBJ_1;
		model = "\viruz_equip\items\boxmre.p3d";
		
		class Eventhandlers {
			//init = "private ['_foods'];_foods = getArray (missionConfigfile >> 'CfgLoot' >> 'food') select 0;for '_i' from 1 to 5 do {(_this select 0) addMagazineCargoGlobal [_foods call BIS_fnc_selectRandom, round(random 5) + 1];};";
		};
	};*/
	
	class Land_FirePlace_F;	// External class reference	
	class Land_Fire_DZ : Land_FirePlace_F {
		transportMaxMagazines = 8;
		transportMaxWeapons = 0;
		transportMaxBackpacks = 0;
		
		class TransportMagazines {
			class _xx_PartWoodPile {
				magazine = "PartWoodPile";
				count = "1";
			};
		};
		
		class Eventhandlers {
			init = "_this call eh_localCleanup;";
		};
	};
	
};

//import viruzmod
class CfgAmmo {	

	class GrenadeHand;
	class BulletCore;
	class PipeBombBase;
	class SmokeShell;
	
	
	class UV_lamp_Base: SmokeShell {
		timeToLive = 60;
		typicalspeed = 14;
		grenadeFireSound[] = {};
		grenadeBurningSound[] = {};
	};
	
	class UV_lamp: UV_lamp_Base {
		model = "\A3\Weapons_f\chemlight\chemlight_blue_lit";
		effectsSmoke = "ChemlightLight_blue";
	};

	class Battery: BulletCore {
		visibleFire = 0;	// how much is visible when this weapon is fired
		audibleFire = 0;
		visibleFireTime = 0;	// how long is it visible
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		model = "\A3\Weapons_f\ammo\shell";
		caliber = 0;
		cartridge = "";
		cost = 1;
		timeToLive = 0;
		deflecting = 0;
		tracerStartTime = -1;
		muzzleEffect = "";
		waterEffectOffset = 0;
		effectFly = "0";
	};
	
	class ThrownObjects : GrenadeHand {
		hit = 0.5;
		indirectHit = 0.2;
		indirectHitRange = 1;
		cost = 1;
		whistleDist = 0;
		fuseDistance = 0;
		initTime = 0;
		explosive = true;
	};
	
	class SodaCan : ThrownObjects {
		model = "\viruz_equip\items\sodaoriginalE.p3d";
		CraterEffects = "NoCrater";
		explosionEffects = "NoExplosion";
		soundHit[] = {"viruz_equip\sound\can_hit_0", 0.5, 1, 60};
	};
	
	class TinCan : ThrownObjects {
		model = "\viruz_equip\items\canspaghetti1E.p3d";
		CraterEffects = "NoCrater";
		explosionEffects = "NoExplosion";
		soundHit[] = {"viruz_equip\sound\can_hit_1", 0.5, 1, 60};
	};
	
};

class CfgSounds {
	/*class trap_bear_0 {
		name = "";
		sound[] = {"\viruz_equip\sound\trap_bear_0", 1, 1, 100};
		titles[] = {};
	};*/
};
