class CfgMagazines {
	class CA_Magazine;	// External class reference
	class HandGrenade;
	
	
	///////////////////////////////////FERRAMENTAS///////////////////////////////////////////
	
	class Viruz_Hammer : CA_Magazine {
	
		scope = public;
		count = 1;
		type = 256;
		displayName = "Hammer";
		model="\A3\Structures_F\Items\Tools\Hammer_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_hammer_ca.paa";
		descriptionShort = "";
		mass=13;
	};
	
	class Viruz_Saw : CA_Magazine {

		scope = public;
		type = 256;
		count = 1;
		displayName = "Saw";
		model="\A3\Structures_F\Items\Tools\Saw_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_saw_ca.paa";
		descriptionShort = "";
		mass=10;
	};
	
	class Viruz_Wrench : CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName = "Wrench";
		model="\A3\Structures_F\Items\Tools\Wrench_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_wrench_ca.paa";
		descriptionShort = "";
		mass=10;
	};
	
	class Viruz_Pliers : CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName = "Pliers";
		model="\A3\Structures_F\Items\Tools\Pliers_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_pliers.paa";
		descriptionShort = "";
		mass=10;
	};
	
	class Viruz_File : CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName = "File (tools)";
		model="\A3\Structures_F\Items\Tools\File_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_file.paa";
		descriptionShort = "";
		mass=8;
	};
	
	class Viruz_Grinder : CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName = "Grinder";
		model="\A3\Structures_F\Items\Tools\Grinder_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_grinder.paa";
		descriptionShort = "ViruZ";
		mass=25;
	};
	
	class Viruz_Screwdriver : CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName = "Screwdriver";
		model="\A3\Structures_F\Items\Tools\Screwdriver_V1_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_screwdriver_ca.paa";
		descriptionShort = "ViruZ";
		mass=7;
	};
	
	class Viruz_Phillips : CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName = "Phillips Screwdriver";
		model="\A3\Structures_F\Items\Tools\Screwdriver_V2_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_phillips_ca.paa";
		descriptionShort = "ViruZ";
		mass=7;
	};
	
	
	class Viruz_Gloves : CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName = "Gloves";
		model="\A3\Structures_F\Items\Tools\Gloves_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_gloves.paa";
		descriptionShort = "ViruZ";
		mass=5;
	};
	
	class Viruz_Drill : CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName = "Drill";
		model="\A3\Structures_F\Items\Tools\DrillAku_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_drill.paa";
		descriptionShort = "ViruZ";
		mass=20;
	};
	
	class Viruz_CanisterOil : CA_Magazine {
		scope = public;
		type = 256;
		count = 10;
		displayName = "Canister (Oil)";
		model="\A3\Structures_F\Items\Vessels\CanisterOil_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_canisteroil.paa";
		descriptionShort = "ViruZ";
		mass=15;
	};
	
	class Viruz_DuctTape : CA_Magazine {
		scope = public;
		type = 256;
		count = 10;
		displayName = "DuctTape";
		model="\A3\Structures_F_EPA\Items\Tools\DuctTape_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_ducttape.paa";
		descriptionShort = "ViruZ";
		mass=8;
	};
	
	///////////////////////////////////RESOURCES////////////////////////////////////////////	
	class Viruz_Rock: CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName="Rock";
		model="\viruz_equip\items\viruz_rock.p3d";
		picture = "\viruz_equip\viruzico\viruz_rock_ca.paa";
		descriptionShort = "Piece of rock, perfect for construction!!!";
		mass=10;
	};
	class Viruz_Clinquer: CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName="Clinker";
		model="\viruz_equip\items\viruz_clinquer.p3d";
		picture = "\viruz_equip\viruzico\viruz_clinquer_ca.paa";
		descriptionShort = "Upon treatment with water, clinker reacts to form a hydrate called cement paste. Upon standing the paste polymerizes as indicated by its hardening.";
		mass=10;
	};
	///////////////////////////////////BUILD ITENS/////////////////////////////////////
	class Viruz_CinderBlock: CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName="CinderBlock";
		model="\viruz_equip\items\viruz_cinderblock.p3d";
		picture = "\viruz_equip\viruzico\cinderblock.paa";
		descriptionShort = "ViruZ";
		mass=15;
	};
	
	class Viruz_Woodboard: CA_Magazine {
		scope = public;
		type = 256;
		count = 10;
		displayName="WoodBoard";
		model="\viruz_equip\items\viruz_woodboard.p3d";
		picture = "\viruz_equip\viruzico\viruz_woodboard_ca.paa";
		descriptionShort = "ViruZ";
		mass=15;
	};
	
	class Viruz_IronBar: CA_Magazine
	{
		scope = public;
		type = 256;
		count = 1;
		displayName="IronBar";
		model="\viruz_equip\items\viruz_ironbar.p3d";
		picture = "\viruz_equip\viruzico\viruz_ironbar.paa";
		descriptionShort = "ViruZ";
		mass=100;
	};
	
	class equip_nails : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Box of Nails";
		model = "\A3\Structures_F_EPA\Items\Tools\Matches_F.p3d";
		picture = "\viruz_equip\viruzico\nail_box_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_3;
		mass = 6;
	};
	
	class Viruz_CementBag: CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName="Cement Bag";
		model="\viruz_equip\items\viruz_cementbag.p3d";
		picture = "\viruz_equip\viruzico\viruz_cementbag_ca.paa";
		descriptionShort = "A cement is a binder, a substance used in construction that sets and hardens and can bind other materials together.";
		mass=40;
	};
	
	class Viruz_CardBoardBox: CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName="CardBoard Box";
		model="\viruz_equip\items\viruz_cardboardbox.p3d";
		picture = "\viruz_equip\viruzico\viruz_cardboardbox_ca.paa";
		descriptionShort = "Cardboard is a generic term for a heavy-duty paper of various strengths, ranging from a simple arrangement of a single thick sheet of paper to complex configurations featuring multiple corrugated and uncorrugated layers.";
		mass=5;
	};
	
	class Viruz_CinderBlockMold: CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName="CinderBlock Mold";
		model="\viruz_equip\items\viruz_cinderblockmold.p3d";
		picture = "\viruz_equip\viruzico\viruz_cinderblockmold_ca.paa";
		descriptionShort = "Mold to create cinder blocks.";
		mass=15;
	};
	
	//////////////////////////////////COSTRUÇÃO/////////////////////////////////////////////
	class ItemTent : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_A3_CfgVehicles_Land_TentA_F0;
		model="\A3\Structures_F\Civ\Camping\Sleeping_bag_folded_F.p3d";
		picture = "\viruz_equip\viruzico\tentbag.paa";
		descriptionShort = $STR_EQUIP_DESC_20;
		mass = 35;
		
		class ItemActions {
			class Buildable {
				text = $STR_PITCH_TENT;
				script = "spawn player_tentPitch;";
			};
		};
	};

	class ItemTentDome : ItemTent {
		displayName = $STR_A3_CfgVehicles_Land_TentDome_F0;
	};
/*	
	class ItemTankTrap : CA_Magazine { // ёж
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
	};
*/	
	class ItemSandbag : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_21;
		model="\A3\Structures_F\Civ\Camping\Pillow_old_F.p3d";
		picture = "\viruz_equip\viruzico\sandbag.paa";
		descriptionShort = $STR_EQUIP_DESC_21;
		mass = 40;
		
		class ItemActions {
			class Buildable {
				text = $STR_ACTIONS_BUILD;
				script = "spawn player_build;";
				require = "ItemEtool";
				create = "Sandbag1_DZ";
			};
		};
	};
	
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
			class Buildable {
				text = $STR_ACTIONS_BUILD;
				script = "spawn player_build;";
				require = "ItemToolbox";
				create = "Wire_cat1";
			};
		};
	};
	////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////TOOLS///////////////////////////////////////////
	
	class Viruz_Saucepan: CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName="Saucepan";
		model="\viruz_equip\items\viruz_saucepan.p3d";
		picture = "\viruz_equip\viruzico\viruz_saucepan_ca.paa";
		descriptionShort = "";
		mass=10;
	};
	
	class itemCanOpener: CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "$STR_A3_can_opener";
		model = "\A3\Structures_F_EPA\Items\Tools\CanOpener_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_canopener_ca.paa";
		descriptionShort = "";
		mass=5;		
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
	///////////////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////MEDICAL//////////////////////////////////////////////
	
	class Viruz_Antiseptic: CA_Magazine	{
		scope = public;
		type = 256;
		count = 10;
		RetiredSize = 2;
		ammo = "Antiseptic";
		displayName="Antiseptic";
		model="\A3\Structures_F_EPA\Items\Medical\DisinfectantSpray_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_antiseptic_ca.paa";
		descriptionShort = "They are substances used to disinfect wounds, avoiding or reducing the risk of infection by bacteria or germs.";
		mass=5;
	};
	
	class ItemBandage : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Bandage";
		model="\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_bandage_ca.paa";
		descriptionShort = $STR_A3_cfgWeapons_FirstAidKit1;
		mass = 4;
		
		class ItemActions {
			class Use {
				text = $STR_BANDAGE_SELF;
				script = "spawn player_useMeds;";
			};
		};
	};
	
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
		picture = "\viruz_equip\viruzico\viruz_heatpack_ca.paa";
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
		mass = 8;
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
		picture = "\viruz_equip\viruzico\viruz_painkiller_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_18;
		mass = 4;
		
		class ItemActions {
			class Use {
				text = $STR_TAKE_PAINKILLER;
				script = "spawn player_useMeds;";
			};
		};
	};
	
	///////////////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////VIRUZ ITEMS//////////////////////////////////////////
	
	
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
	
	
	class ItemEtool : CA_Magazine {
		scope = public;
		displayName = "Shovel";
		model="\A3\Structures_F_EPA\Items\Tools\Shovel_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_shovel_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_1;
		mass=20;
		
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
		mass = 12;
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
		mass = 5;
		type = 256;
	};
	
	class Viruz_Suitcase : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = "Suitcase";
		model="\A3\structures_f\items\luggage\Suitcase_F.p3d";
		picture = "\viruz_equip\viruzico\Suitcase.paa";
		descriptionShort = "ViruZ";
		mass=12;
	};
	
	class Viruz_HandyCam : CA_Magazine {
	
		scope = public;
		type = 256;
		count = 1;
		displayName="Handycam";
		model="\A3\structures_f\Items\electronics\HandyCam_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_handycam_ca.paa";
		descriptionShort = "ViruZ";
		mass=10;
	};
	
	class Viruz_Laptop: CA_Magazine	{
		
		scope = public;
		type = 256;
		count = 1;
		displayName="Laptop";
		model="\A3\structures_f\Items\electronics\laptop_unfolded_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_laptop_ca.paa";
		descriptionShort = "ViruZ";
		mass=15;
	};
	
	class Viruz_MobilePhone: CA_Magazine {
		scope = public;
		type = 256;
		count = 1;
		displayName="MobilePhone";
		model="\A3\structures_f\Items\electronics\mobilephone_old_F.p3d";
		picture = "\viruz_equip\viruzico\Mobilephone.paa";
		descriptionShort = "ViruZ";
		mass=5;
	};
	
	class Viruz_SmartPhone: CA_Magazine	{
		scope = public;
		type = 256;
		count = 1;
		displayName="SmartPhone";
		model="\A3\structures_f\Items\electronics\mobilephone_smart_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_smartphone_ca.paa";
		descriptionShort = "ViruZ";
		mass=5;
	};
	///////////////////////////////////////////////////////////////////////////////////////
	
	
	///////////////////////////////VEHICLES PARTS/////////////////////////////////////////
	
	class ItemJerrycan : CA_Magazine {
		scope = public;
		count = 20;
		fuelQuantity = 20;
		type = (256 * 3);
		displayName = $STR_EQUIP_NAME_19;
		model = "\A3\Structures_F\Items\Vessels\CanisterFuel_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_jerrycan_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_19;
		mass = 25;
		allowedSlots[] = {901};
	};
	
	class ItemJerrycanEmpty : ItemJerrycan {
		count = 1;
		fuelQuantity = 0;
		type = (256 * 3);
		displayName = $STR_EQUIP_NAME_39;
		picture = "\viruz_equip\viruzico\viruz_jerrycan_e_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_39;
		mass = 15;
		allowedSlots[] = {901};
	};
	
	class PartFueltank : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 4);
		displayName = $STR_EQUIP_NAME_8;
		model = "\viruz_equip\items\viruz_fueltank.p3d";
		picture = "\viruz_equip\viruzico\fuel_tank_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_8;
		mass = 70;
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
		mass = 15;
	};
	
	class PartEngine : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 6);
		displayName = $STR_EQUIP_NAME_11;
		model = "\viruz_equip\items\viruz_engine.p3d";
		picture = "\viruz_equip\viruzico\viruz_engine_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_11;
		mass = 100;
	};
	
	class PartWoodPile : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 2);
		displayName = $STR_EQUIP_NAME_40;
		model = "\A3\Structures_F_EPA\Civ\Camping\WoodenLog_F.p3d";
		picture = "\viruz_equip\viruzico\viruz_log_ca.paa";
		descriptionShort = $STR_EQUIP_DESC_40;
		mass = 30;
	};
	
	class PartVRotor : CA_Magazine {
		scope = public;
		count = 1;
		type = (256 * 6);
		displayName = $STR_EQUIP_NAME_32;
		model = "\viruz_equip\items\viruz_rotor.p3d";
		picture = "\viruz_equip\viruzico\vz_rotor.paa";
		descriptionShort = $STR_EQUIP_DESC_32;
		mass = 120;
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
	
	///////////////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////BUILD ITENS///////////////////////////////////////////
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
			class Buildable {
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
		type = 256;
		descriptionShort = "";
		mass=12;
	
		class ItemActions {
			class Buildable {
				text = "$STR_USE";
				script = "spawn electronics_build";
				create = "Land_Camping_Light_off_F";
			};
		};
	};
	
	///////////////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////BEBIDAS//////////////////////////////////////////////
	
	class FoodDrink : CA_Magazine {
		isWater = 1;
		count = 1;
		type = 256;
		mass = 8;
		
		class ItemActions {
			class Consumivel {
				text = $STR_ACTIONS_DRINK;
				script = "spawn player_drink;";
				Ferramentas[] = {};
			};
		};
	};
	
	class ToolsFoodDrink : FoodDrink {
			Ferramentas[] = {};
		};
	
		class ItemWaterbottle : FoodDrink {
		scope = public;
		refillable = 1;
		displayName = $STR_EQUIP_NAME_12;
		model="\A3\Structures_F_EPA\Items\Food\Canteen_F.p3d";
		picture = "\viruz_equip\viruzico\canteen.paa";
		descriptionShort = $STR_EQUIP_DESC_12;
		mass = 15;
	};
	
	class ItemWaterbottleUnfilled : CA_Magazine {
		scope = public;
		count = 1;
		type = 256;
		displayName = $STR_EQUIP_NAME_13;
		model="\A3\Structures_F_EPA\Items\Food\Canteen_F.p3d";
		picture = "\viruz_equip\viruzico\canteen_empty.paa";
		descriptionShort = $STR_EQUIP_DESC	_13;
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
		displayName = "Soda Original";
		model = "\viruz_equip\items\sodaoriginal.p3d";
		picture = "\viruz_equip\viruzico\sodaoriginal_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaOriginalEmpty : HandGrenade {
		scope = public;
		displayName = "Empty Soda Can";
		model = "\viruz_equip\items\sodaoriginalE.p3d";
		picture = "\viruz_equip\viruzico\sodaoriginalE_ca.paa";
		descriptionShort = "";
		mass = 2;
	};
	
	class ItemSodaDarth : ItemSodaOriginal {
		displayName = "Soda Darth";
		model = "\viruz_equip\items\sodadarth.p3d";
		picture = "\viruz_equip\viruzico\sodadarth_ca.paa";
		descriptionShort = "Come to the dark side of the force";
	};
	
	class ItemSodaDarthEmpty : ItemSodaOriginalEmpty {
		model = "\viruz_equip\items\sodadarthE.p3d";
		picture = "\viruz_equip\viruzico\sodadarthE_ca.paa";
	};
	
	class ItemSodaDiet : ItemSodaOriginal {
		displayName = "Soda Diet";
		model = "\viruz_equip\items\sodadiet.p3d";
		picture = "\viruz_equip\viruzico\sodadiet_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaDietEmpty : ItemSodaOriginalEmpty {
		model = "\viruz_equip\items\sodadietE.p3d";
		picture = "\viruz_equip\viruzico\sodadietE_ca.paa";
	};
	
	class ItemSodaGrape : ItemSodaOriginal {
		displayName = "Soda Grape";
		model = "\viruz_equip\items\sodagrape.p3d";
		picture = "\viruz_equip\viruzico\sodagrape_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaGrapeEmpty : ItemSodaOriginalEmpty {
		model = "\viruz_equip\items\sodagrapeE.p3d";
		picture = "\viruz_equip\viruzico\sodagrapeE_ca.paa";
	};
	
	class ItemSodaHam : ItemSodaOriginal {
		displayName = "Soda Ham";
		model = "\viruz_equip\items\sodaham.p3d";
		picture = "\viruz_equip\viruzico\sodaham_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaHamEmpty : ItemSodaOriginalEmpty {
		model = "\viruz_equip\items\sodahamE.p3d";
		picture = "\viruz_equip\viruzico\sodahamE_ca.paa";
	};
	
	class ItemSodaOrange : ItemSodaOriginal {
		displayName = "Soda Orange";
		model = "\viruz_equip\items\sodalaranja.p3d";
		picture = "\viruz_equip\viruzico\sodalaranja_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaOrangeEmpty : ItemSodaOriginalEmpty {
		model = "\viruz_equip\items\sodalaranjaE.p3d";
		picture = "\viruz_equip\viruzico\sodalaranjaE_ca.paa";
	};
	
	class ItemSodaLemon : ItemSodaOriginal {
		displayName = "Soda Lemon";
		model = "\viruz_equip\items\sodalimao.p3d";
		picture = "\viruz_equip\viruzico\sodalimao_ca.paa";
		descriptionShort = "";
	};
	
	class ItemSodaLemonEmpty : ItemSodaOriginalEmpty {
		model = "\viruz_equip\items\sodalimaoE.p3d";
		picture = "\viruz_equip\viruzico\sodalimaoE_ca.paa";
	};
	
	class ItemSodaYoda : ItemSodaOriginal {
		displayName = "Soda Yoda";
		model = "\viruz_equip\items\sodayoda.p3d";
		picture = "\viruz_equip\viruzico\sodayoda_ca.paa";
		descriptionShort = "May the force be with you";
	};
	
	class ItemSodaYodaEmpty : ItemSodaOriginalEmpty {
		model = "\viruz_equip\items\sodayodaE.p3d";
		picture = "\viruz_equip\viruzico\sodayodaE_ca.paa";
	};
	
	class ItemSodaBeergolden : ItemSodaOriginal {
		displayName = "Beer Golden Juice";
		model = "\viruz_equip\items\beergoldenjuice.p3d";
		picture = "\viruz_equip\viruzico\beergoldenjuice_ca.paa";
		descriptionShort = "May the force be with you";
	};
	
	class ItemSodaBeergoldenEmpty : ItemSodaOriginalEmpty {
		model = "\viruz_equip\items\beergoldenjuiceE.p3d";
		picture = "\viruz_equip\viruzico\beergoldenjuiceE_ca.paa";
	};
	
	
	///////////////////////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////COMIDAS//////////////////////////////////////////////
	
	class FoodEdible : CA_Magazine {
		isFood = 1;
		count = 1;
		type = 256;
		bloodRegen = 200;
		mass = 10;
		
		class ItemActions {
			class Consumivel {
				text = $STR_EAT_FOOD;
				script = "spawn player_eat;";
			};
		};
	};
	
	class Open_FoodEdible : FoodEdible {
		Ferramentas[] = {"itemCanOpener"};
	};
	
	//Base class
	class FoodCanWBBeans : Open_FoodEdible {
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

	class FoodCanMHBeans : Open_FoodEdible {
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
	
	class FoodCanCGBeans : Open_FoodEdible {
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
	
	class FoodCanBeefChunks : Open_FoodEdible {
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
	
	class FoodCanChickenChunks : Open_FoodEdible {
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
	
	class FoodCanChickenNoodle : Open_FoodEdible {
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
	
	class FoodCanFruitcocktail : Open_FoodEdible {
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
	
	class FoodCanOranges : Open_FoodEdible {
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
	
	class FoodCanPeaches : Open_FoodEdible {
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
	
	class FoodCanPears : Open_FoodEdible {
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
	
	class FoodCanEsardines : Open_FoodEdible {
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
	
	/*class FoodCanPsardines : Open_FoodEdible {
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
	
	class FoodCanChickenSoup : Open_FoodEdible {
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
	
	class FoodCanPotatoSoup : Open_FoodEdible {
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
	
	class FoodCanPeaSoup : Open_FoodEdible {
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
	
	class FoodCanCCCornSoup : Open_FoodEdible {
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
	
	class FoodCanHCCornSoup : Open_FoodEdible {
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
	
	class FoodCanTRSoup : Open_FoodEdible {
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
	
	class FoodCanCRiceSoup : Open_FoodEdible {
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
	
	class FoodCanSpaghetti1 : Open_FoodEdible {
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
	
		class FoodCanSpaghetti2 : Open_FoodEdible {
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
	
	///////////////////////////////////////////////////////////////////////////////////////
	
	////////////////////////////////CARNES/////////////////////////////////////////////////
	
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
	
	///////////////////////////////////////////////////////////////////////////////////////
	
	////////////////////////////////CARNES FRITAS//////////////////////////////////////////
	
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
	
	///////////////////////////////////////////////////////////////////////////////////////
	
	
	
	
};