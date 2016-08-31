class CfgVehicles {
	class Civilian;	// External class reference
	
	class zZombie_BaseD : Civilian {
		class HitPoints {
			class HitHead;	// External class reference
			class HitBody;	// External class reference
			class HitHands;	// External class reference
			class HitLegs;	// External class reference
		};
	};
	
	class zZombie_Base : zZombie_BaseD {
		_generalMacro = "zZombie_Base";
		scope = private;
		expansion = 1;
		glassesEnabled = 0;
		identityTypes[] = {"zombie1"};
		faceType = "Zombie1";
		moves = "CfgMovesZombie";
		zombieLoot = "civilian";
//		genericNames = "Zombie";
		vehicleClass = "Zombie";
		displayName = "Zombie";
		weapons[] = {};
		magazines[] = {};
		portrait = "";
		picture = "";
		sensitivity = 5;	// sensor sensitivity
		sensitivityEar = 3; 
		
		threat[] = {0.1, 0.1, 0.1}; // боязнь техники?
		
		class TalkTopics {};
		languages[] = {};
		
		class Eventhandlers {
			init = "_this call zombie_initialize;";
			local = "diag_log ('Locality Event');if(_this select 1) then {[(position (_this select 0)),(_this select 0),true] execFSM '\z\AddOns\viruz_mod\system\zombie_agent.fsm'};";
		};
		
		class Wounds {
			tex[] = {};
			mat[] = {"A3\Characters_F\Civil\Data\c_cloth1.rvmat", "A3\Characters_F\Civil\Data\c_cloth1_injury.rvmat", "A3\Characters_F\Civil\Data\c_cloth1_injury.rvmat", "A3\Characters_F\Civil\Data\c_cloth2.rvmat", "A3\Characters_F\Civil\Data\c_cloth2_injury.rvmat", "A3\Characters_F\Civil\Data\c_cloth2_injury.rvmat", "A3\Characters_F\Civil\Data\c_cloth3.rvmat", "A3\Characters_F\Civil\Data\c_cloth3_injury.rvmat", "A3\Characters_F\Civil\Data\c_cloth3_injury.rvmat", "A3\Characters_F\Civil\Data\c_cloth4.rvmat", "A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat", "A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat", "A3\characters_f\civil\data\c_poloshirt.rvmat", "A3\Characters_F\Civil\Data\c_poloshirt_injury.rvmat", "A3\Characters_F\Civil\Data\c_poloshirt_injury.rvmat", "A3\characters_f\common\data\coveralls.rvmat", "A3\Characters_F\Common\Data\coveralls_injury.rvmat", "A3\Characters_F\Common\Data\coveralls_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_old.rvmat", "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat", "A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"};
		};
		
		class HitPoints : HitPoints {
			class HitHead : HitHead {
				armor = 0.3*3;
			};
			
			class HitBody : HitBody {
				armor = 0.4*10;
			};
			
			class HitHands : HitHands {
				armor = 0.3*5;
			};
			
			class HitLegs : HitLegs {
				armor = 0.4*5;
			};
		};
		model = "\A3\Characters_F\Civil\c_poloshirt";
		modelSides[] = {0, 3};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_1_co.paa"};
	};
	
	/*class z_policeman : zZombie_Base {
		_generalMacro = "z_policeman";
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_2_co.paa"};
	};*/
	
	class z_suit1 : zZombie_Base {
		_generalMacro = "z_suit1";
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_3_co.paa"};
	};
	
	class z_suit2 : zZombie_Base {
		_generalMacro = "z_suit2";
		moves = "CfgMovesZombieCrouch";
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_4_co.paa"};
	};
	
	class z_suit3 : zZombie_Base {
		_generalMacro = "z_suit1";
		moves = "CfgMovesZombieCrouch";
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_3_co.paa"};
	};
	
	class z_worker1 : zZombie_Base {
		_generalMacro = "z_worker1";
		moves = "CfgMovesZombieCrouch";
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_5_co.paa"};
	};
	
	class z_worker2 : zZombie_Base {
		_generalMacro = "z_worker2";
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_6_co.paa"};
	};
	
	class z_worker3 : zZombie_Base {
		_generalMacro = "z_worker3";
		model = "\A3\Characters_F\Civil\c_citizen1";
		modelSides[] = {0, 3};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_cloth1_v2_co.paa"};
	};
	
	class z_soldier : zZombie_Base {
		_generalMacro = "z_soldier";
		displayName = "Zombie Soldier";
		class Wounds {
			tex[] = {};
			mat[] = {"A3\Characters_F\BLUFOR\Data\clothing1.rvmat", "A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat", "A3\Characters_F\BLUFOR\Data\clothing1_injury.rvmat", "A3\Characters_F\Common\Data\basicbody.rvmat", "A3\Characters_F\Common\Data\basicbody_injury.rvmat", "A3\Characters_F\Common\Data\basicbody_injury.rvmat", "A3\characters_f\common\data\coveralls.rvmat", "A3\Characters_F\Common\Data\coveralls_injury.rvmat", "A3\Characters_F\Common\Data\coveralls_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_old.rvmat", "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat", "A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"};
		};
		
		modelSides[] = {3, 1};
		nakedUniform = "U_BasicBody";
		linkedItems[] = {"V_Chestrig_khk"};
		respawnLinkedItems[] = {"V_Chestrig_khk"};
		model = "\A3\characters_F\BLUFOR\b_soldier_01.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\BLUFOR\Data\clothing1_co.paa"};
		
		class HitPoints : HitPoints {
			class HitHead : HitHead {
				armor = 0.3*3;
			};
			
			class HitBody : HitBody {
				armor = 0.5*10;
			};
			
			class HitHands : HitHands {
				armor = 0.8*5;
			};
			
			class HitLegs : HitLegs {
				armor = 0.8*5;
			};
		};
	};
	
	class z_soldier_heavy : z_soldier {
		_generalMacro = "z_soldier_heavy";
		displayName = "Zombie Soldier (Heavy)";
		linkedItems[] = {"V_Chestrig_khk", "H_HelmetB"};
		respawnLinkedItems[] = {"V_Chestrig_khk", "H_HelmetB"};
		model = "\A3\characters_F\BLUFOR\b_soldier_03.p3d";
	};
	
		class z_soldier_heavy2 : z_soldier {
		_generalMacro = "z_soldier_heavy";
		displayName = "Zombie Soldier (Heavy)";
		linkedItems[] = {"V_Chestrig_khk", "H_HelmetB"};
		respawnLinkedItems[] = {"V_Chestrig_khk", "H_HelmetB"};
		model = "\A3\characters_F\BLUFOR\b_soldier_03.p3d";
		moves = "CfgMovesZombieCrouch";
	};
	
	class z_soldier_pilot : z_soldier {
		_generalMacro = "z_soldier_pilot";
		displayName = "Zombie Soldier (Pilot)";
		model = "\A3\Characters_F\Common\coveralls.p3d";
		modelSides[] = {3, 1};
		
		class HitPoints : HitPoints {
			class HitHead : HitHead {
				armor = 0.3*3;
			};
			
			class HitBody : HitBody {
				armor = 0.7*10;
			};
			
			class HitHands : HitHands {
				armor = 0.7*5;
			};
			
			class HitLegs : HitLegs {
				armor = 0.7*5;
			};
		};
		linkedItems[] = {"H_PilotHelmetHeli_B", "V_TacVest_oli"};
		respawnLinkedItems[] = {"H_PilotHelmetHeli_B", "V_TacVest_oli"};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\pilot_suit_rus_co.paa"};
		
		class Wounds {
			tex[] = {};
			mat[] = {"A3\characters_f\common\data\pilot_suit.rvmat", "A3\Characters_F\Common\Data\W1_pilot_suit.rvmat", "A3\Characters_F\Common\Data\W1_pilot_suit.rvmat", "A3\characters_f\common\data\coveralls.rvmat", "A3\Characters_F\Common\Data\coveralls_injury.rvmat", "A3\Characters_F\Common\Data\coveralls_injury.rvmat"};
		};
	};
	
	
	class z_hunter : zZombie_Base {
		_generalMacro = "z_hunter";
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_3_co.paa"};
	};
	class z_villager3 : zZombie_Base {
		_generalMacro = "z_villager3";
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_3_co.paa"};
	};
	class z_villager1 : zZombie_Base {
		_generalMacro = "z_villager1";
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_3_co.paa"};
	};
	class z_villager2 : zZombie_Base {
		_generalMacro = "z_villager1";
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_3_co.paa"};
	};
	class z_teacher : zZombie_Base {
		_generalMacro = "z_teacher";
		hiddenSelectionsTextures[] = {"\A3\characters_f\civil\data\c_poloshirt_3_co.paa"};
	};
	
	//************************************************************************ RDS *********************************************************
	#define Standard_Items 'ItemMap','ItemCompass','ItemWatch','ItemRadio'
class VZ_Citizen:zZombie_Base // base class
{
	_generalMacro = "VZ_Citizen";
	displayName=$STR_RDS_DN_CIV_CITIZEN;
	model= "\rds_a2port_cman\citizen\citizen";
	moves= "CfgMovesZombie";

	headgearList[] = {rds_worker_cap1,0.25,rds_worker_cap2,0.25,rds_worker_cap3,0.25,rds_worker_cap4,0.25, "", 1,"H_Cap_tan", 0.25, "H_Cap_blk", 0.25, "H_Cap_blk_CMMG", 0.25, "H_Cap_brn_SPECOPS", 0.25, "H_Cap_tan_specops_US", 0.25, "H_Cap_khaki_specops_UK", 0.25, "H_Cap_red", 0.25, "H_Cap_grn", 0.25, "H_Cap_blu", 0.25, "H_Cap_grn_BI", 0.25, "H_Cap_blk_Raven", 0.25,
	 "H_Cap_blk_ION", 0.25,  "H_Beret_blk", 0.25, "H_Beret_red", 0.25, "", 1, "H_Beret_grn", 0.25, "H_TurbanO_blk",
	 0.25, "H_StrawHat", 0.25, "H_StrawHat_dark", 0.25, "H_Hat_blue", 0.25, "H_Hat_brown", 0.25, "H_Hat_camo", 0.25, "H_Hat_grey", 0.25, "H_Hat_checker", 0.25, "H_Hat_tan", 0.25, "", 1};

	class Wounds
	{
		tex[]={};
		mat[]={
			"rds_a2port_cman\citizen\data\citizen.rvmat",
			"rds_a2port_cman\citizen\data\W1_citizen.rvmat",
			"rds_a2port_cman\citizen\data\W2_citizen.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
		};
	};
	modelSides[] = {3, 1};
	hiddenSelections[] =
	{
		"Camo"
	};
};
class VZ_Citizen1:VZ_Citizen
{
	_generalMacro = "VZ_Citizen1";
	displayName=$STR_RDS_DN_CIV_CITIZEN1;
	

	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\citizen\data\citizen_co.paa
	};
};
class VZ_Citizen2: VZ_Citizen
{
	_generalMacro = "VZ_Citizen2";
	moves = "CfgMovesZombieCrouch";
	displayName=$STR_RDS_DN_CIV_CITIZEN2;
	
	//uniformClass = "rds_uniform_Citizen2";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\citizen\data\Citizen_v2_co.paa
	};
};
class VZ_Citizen3: VZ_Citizen
{
	
	_generalMacro = "VZ_Citizen3";
	displayName=$STR_RDS_DN_CIV_CITIZEN3;
	
	//uniformClass = "rds_uniform_Citizen3";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\citizen\data\Citizen_v3_co.paa
	};
};
class VZ_Citizen4: VZ_Citizen
{
	_generalMacro = "VZ_Citizen4";
	moves = "CfgMovesZombieCrouch";
	displayName=$STR_RDS_DN_CIV_CITIZEN4;
	
	//uniformClass = "rds_uniform_Citizen4";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\citizen\data\Citizen_v4_co.paa
	};
};

class VZ_Worker: zZombie_Base // base class
{
	_generalMacro = "VZ_Worker";
	displayName=$STR_RDS_DN_CIV_WORKER;
	
	model= "\rds_a2port_cman\Worker\Worker";
	//uniformClass = "rds_uniform_worker1";
	moves = "CfgMovesZombie";
	hiddenSelections[] =
	{
		"Camo"
	};


	headgearList[] = {rds_worker_cap1,0.25,rds_worker_cap2,0.25,rds_worker_cap3,0.25,rds_worker_cap4,0.25,"H_Cap_tan", 0.25, "H_Cap_blk", 0.25, "H_Cap_blk_CMMG", 0.25, "H_Cap_brn_SPECOPS", 0.25, "H_Cap_tan_specops_US", 0.25, "H_Cap_khaki_specops_UK", 0.25, "H_Cap_red", 0.25, "H_Cap_grn", 0.25, "H_Cap_blu", 0.25, "H_Cap_grn_BI", 0.25, "H_Cap_blk_Raven", 0.25,
	 "H_Cap_blk_ION", 0.25,  "H_Beret_blk", 0.25, "H_Beret_red", 0.25, "H_Beret_grn", 0.25,  "", 1};



	//headgearList[] = {"H_Cap_tan", 0.25, "H_Cap_blk", 0.25, "H_Cap_blk_CMMG", 0.25, "H_Cap_brn_SPECOPS", 0.25, "H_Cap_tan_specops_US", 0.25, "H_Cap_khaki_specops_UK", 0.25, "H_Cap_red", 0.25, "H_Cap_grn", 0.25, "H_Cap_blu", 0.25, "H_Cap_grn_BI", 0.25, "H_Cap_blk_Raven", 0.25, "H_Cap_blk_ION", 0.25, "H_Bandanna_khk", 0.25, "H_Bandanna_sgg", 0.25, "H_Bandanna_cbr", 0.25, "H_Bandanna_gry", 0.25, "H_Bandanna_camo", 0.25, "H_Bandanna_mcamo", 0.25, "H_Bandanna_surfer", 0.25, "H_Beret_blk", 0.25, "H_Beret_red", 0.25, "H_Beret_grn", 0.25, "H_TurbanO_blk", 0.25, "H_StrawHat", 0.25, "H_StrawHat_dark", 0.25, "H_Hat_blue", 0.25, "H_Hat_brown", 0.25, "H_Hat_camo", 0.25, "H_Hat_grey", 0.25, "H_Hat_checker", 0.25, "H_Hat_tan", 0.25, "", 1};

	//headgearList[] = {rds_worker_cap1,0.25,rds_worker_cap2,0.25,rds_worker_cap3,0.25,rds_worker_cap4,0.25};
	class Wounds
	{
		tex[]={};
		mat[]={
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",

			"rds_a2port_cman\worker\data\worker.rvmat",
			"rds_a2port_cman\worker\data\W1_worker.rvmat",
			"rds_a2port_cman\worker\data\W2_worker.rvmat"
			};
	};
};
class VZ_Worker1: VZ_Worker
{
	_generalMacro = "VZ_Worker1";
	displayName=$STR_RDS_DN_CIV_WORKER1;
	
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\worker\data\worker_co.paa
	};

	linkedItems[] = {"rds_worker_cap1",Standard_Items};
	respawnLinkedItems[] = {"rds_worker_cap1",Standard_Items};
};
class VZ_Worker2: VZ_Worker
{
	_generalMacro = "VZ_Worker2";
	moves = "CfgMovesZombieCrouch";
	displayName=$STR_RDS_DN_CIV_WORKER2;
	
	//uniformClass = "rds_uniform_Worker2";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\worker\data\Worker_v2_CO.paa
	};
	linkedItems[] = {"rds_worker_cap2",Standard_Items};
	respawnLinkedItems[] = {"rds_worker_cap2",Standard_Items};
};
class VZ_Worker3: VZ_Worker
{
	_generalMacro = "VZ_Worker3";
	displayName=$STR_RDS_DN_CIV_WORKER3;
	
	//uniformClass = "rds_uniform_Worker3";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\worker\data\Worker_v3_CO.paa
	};
	linkedItems[] = {"rds_worker_cap3",Standard_Items};
	respawnLinkedItems[] = {"rds_worker_cap3",Standard_Items};
};
class VZ_Worker4: VZ_Worker
{
	_generalMacro = "VZ_Worker4";
	moves = "CfgMovesZombieCrouch";
	displayName=$STR_RDS_DN_CIV_WORKER4;
	
	//uniformClass = "rds_uniform_Worker4";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\worker\data\Worker_v4_CO.paa
	};
	linkedItems[] = {"rds_worker_cap4",Standard_Items};
	respawnLinkedItems[] = {"rds_worker_cap4",Standard_Items};
};


class VZ_Profiteer:zZombie_Base //base class
{
	_generalMacro = "VZ_Profiteer";
	displayName=$STR_RDS_DN_CIV_PROFITEER;
	
	model= "\rds_a2port_cman\profiteer\profiteer";
	//uniformClass = "rds_uniform_profiteer1";
	moves = "CfgMovesZombie";

	headgearList[] = {rds_Profiteer_cap1,0.25,rds_Profiteer_cap2,0.25,rds_Profiteer_cap3,0.25,rds_Profiteer_cap4,0.25,"H_Cap_tan", 0.25, "H_Cap_blk", 0.25, "H_Cap_blk_CMMG", 0.25, "H_Cap_brn_SPECOPS", 0.25, "H_Cap_tan_specops_US", 0.25, "H_Cap_khaki_specops_UK", 0.25, "H_Cap_red", 0.25, "H_Cap_grn", 0.25, "H_Cap_blu", 0.25, "H_Cap_grn_BI", 0.25, "H_Cap_blk_Raven", 0.25,
	 "H_Cap_blk_ION", 0.25,  "H_Beret_blk", 0.25, "H_Beret_red", 0.25, "H_Beret_grn", 0.25,  "", 1};

	hiddenSelections[] =
	{
		"Camo"
	};
	class Wounds
	{
		tex[]={};
		mat[]={
			"rds_a2port_cman\profiteer\data\profiteer.rvmat",
			"rds_a2port_cman\profiteer\data\W1_profiteer.rvmat",
			"rds_a2port_cman\profiteer\data\W2_profiteer.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
		};
	};
};
class VZ_Profiteer1: VZ_Profiteer
{
	_generalMacro = "VZ_Profiteer1";
	displayName=$STR_RDS_DN_CIV_PROFITEER1;
	
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\profiteer\data\profiteer_co.paa
	};
	linkedItems[] = {"rds_Profiteer_cap1",Standard_Items};
	respawnLinkedItems[] = {"rds_Profiteer_cap1",Standard_Items};
};
class VZ_Profiteer2: VZ_Profiteer
{
	_generalMacro = "VZ_Profiteer2";
	moves = "CfgMovesZombieCrouch";
	displayName=$STR_RDS_DN_CIV_PROFITEER2;
	
	//uniformClass = "rds_uniform_Profiteer2";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\profiteer\data\profiteer_v2_co.paa
	};
	linkedItems[] = {"rds_Profiteer_cap2",Standard_Items};
	respawnLinkedItems[] = {"rds_Profiteer_cap2",Standard_Items};
};
class VZ_Profiteer3: VZ_Profiteer
{
	_generalMacro = "VZ_Profiteer3";
	displayName=$STR_RDS_DN_CIV_PROFITEER3;
	
	//uniformClass = "rds_uniform_Profiteer3";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\profiteer\data\profiteer_v3_co.paa
	};
	linkedItems[] = {"rds_Profiteer_cap3",Standard_Items};
	respawnLinkedItems[] = {"rds_Profiteer_cap3",Standard_Items};
};
class VZ_Profiteer4: VZ_Profiteer
{
	_generalMacro = "VZ_Profiteer4";
	moves = "CfgMovesZombieCrouch";
	displayName=$STR_RDS_DN_CIV_PROFITEER4;
	
	//uniformClass = "rds_uniform_Profiteer4";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\profiteer\data\profiteer_v4_co.paa
	};
	linkedItems[] = {"rds_Profiteer_cap4",Standard_Items};
	respawnLinkedItems[] = {"rds_Profiteer_cap4",Standard_Items};
};


class VZ_Woodlander:zZombie_Base
{
	_generalMacro = "VZ_Woodlander";
	displayName=$STR_RDS_DN_CIV_Woodlander;
	
	model= "\rds_a2port_cman\Woodlander\Woodlander";
	//uniformClass = "rds_uniform_woodlander1";
	moves = "CfgMovesZombie";
	hiddenSelections[] =
	{
		"Camo"
	};

	headgearList[] = {rds_woodlander_cap1,0.25,rds_woodlander_cap2,0.25,rds_woodlander_cap3,0.25,rds_woodlander_cap4,0.25,rds_worker_cap1,0.25,rds_worker_cap2,0.25,rds_worker_cap3,0.25,rds_worker_cap4, 0.25,"H_Cap_tan", 0.25, "H_Cap_blk", 0.25, "H_Cap_blk_CMMG", 0.25, "H_Cap_brn_SPECOPS", 0.25, "H_Cap_tan_specops_US", 0.25, "H_Cap_khaki_specops_UK", 0.25, "H_Cap_red", 0.25, "H_Cap_grn", 0.25, "H_Cap_blu", 0.25, "H_Cap_grn_BI", 0.25, "H_Cap_blk_Raven", 0.25,
	 "H_Cap_blk_ION", 0.25,  "H_Beret_blk", 0.25, "H_Beret_red", 0.25, "H_Beret_grn", 0.25,  "", 1};
	class Wounds
	{
		tex[]={};
		mat[]={
			"rds_a2port_cman\Woodlander\data\Woodlander.rvmat",
			"rds_a2port_cman\Woodlander\data\W1_Woodlander.rvmat",
			"rds_a2port_cman\Woodlander\data\W2_Woodlander.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
		};
	};
	linkedItems[] = {"rds_Woodlander_cap1",Standard_Items};
	respawnLinkedItems[] = {"rds_Woodlander_cap1",Standard_Items};
};
class VZ_Woodlander1:VZ_Woodlander
{
	_generalMacro = "VZ_Woodlander1";
	displayName=$STR_RDS_DN_CIV_Woodlander1;
	
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\Woodlander\data\Woodlander_co.paa
	};
};
class VZ_Woodlander2:VZ_Woodlander
{
	_generalMacro = "VZ_Woodlander2";
	moves = "CfgMovesZombieCrouch";
	displayName=$STR_RDS_DN_CIV_Woodlander2;
	
	//uniformClass = "rds_uniform_Woodlander2";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\Woodlander\data\Woodlander_v2_co.paa
	};
	linkedItems[] = {"rds_Woodlander_cap2",Standard_Items};
	respawnLinkedItems[] = {"rds_Woodlander_cap2",Standard_Items};
};
class VZ_Woodlander3:VZ_Woodlander
{
	_generalMacro = "VZ_Woodlander3";
	displayName=$STR_RDS_DN_CIV_Woodlander3;
	
	//uniformClass = "rds_uniform_Woodlander3";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\Woodlander\data\Woodlander_v3_co.paa
	};
	linkedItems[] = {"rds_Woodlander_cap3",Standard_Items};
	respawnLinkedItems[] = {"rds_Woodlander_cap3",Standard_Items};
};
class VZ_Woodlander4:VZ_Woodlander
{
	_generalMacro = "VZ_Woodlander4";
	moves = "CfgMovesZombieCrouch";
	displayName=$STR_RDS_DN_CIV_Woodlander4;
	
	//uniformClass = "rds_uniform_Woodlander4";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\Woodlander\data\Woodlander_v4_co.paa
	};
	linkedItems[] = {"rds_Woodlander_cap4",Standard_Items};
	respawnLinkedItems[] = {"rds_Woodlander_cap4",Standard_Items};
};
class VZ_Functionary:zZombie_Base
{
	_generalMacro = "VZ_Functionary";
	displayName=$STR_RDS_DN_CIV_FUNCTIONARY;
	
	model= "\rds_a2port_cman\Functionary\Functionary";
	hiddenSelections[] =
	{
		"Camo"
	};
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\functionary\data\functionary_co.paa
	};
	headgearList[] = {};
	//uniformClass = "rds_uniform_Functionary1";
	moves = "CfgMovesZombie";
	class Wounds
	{
		tex[]={};
		mat[]={
			"rds_a2port_cman\Functionary\data\Functionary.rvmat",
			"rds_a2port_cman\Functionary\data\W1_Functionary.rvmat",
			"rds_a2port_cman\Functionary\data\W2_Functionary.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
		};
	};
};
class VZ_Functionary1:VZ_Functionary
{
	_generalMacro = "VZ_Functionary1";
	displayName=$STR_RDS_DN_CIV_FUNCTIONARY1;
	
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\functionary\data\functionary_co.paa
	};
};
class VZ_Functionary2:VZ_Functionary
{
	_generalMacro = "VZ_Functionary2";
	moves = "CfgMovesZombieCrouch";
	displayName=$STR_RDS_DN_CIV_FUNCTIONARY2;
	
	//uniformClass = "rds_uniform_Functionary2";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\functionary\data\functionary2_co.paa
	};
};

class VZ_Villager:zZombie_Base
{
	_generalMacro = "VZ_Villager";
	displayName=$STR_RDS_DN_CIV_VILLAGER;
	
	model= "\rds_a2port_cman\Villager\Villager";
	//uniformClass = "rds_uniform_villager1";
	moves = "CfgMovesZombie";
	hiddenSelections[] =
	{
		"Camo"
	};
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\villager\data\villager_co.paa
	};

	headgearList[] = {rds_villager_cap1,0.25,rds_villager_cap2,0.25,rds_villager_cap3,0.25,rds_villager_cap4,0.25,rds_woodlander_cap1,0.25,rds_woodlander_cap2,0.25,rds_woodlander_cap3,0.25,rds_woodlander_cap4,0.25,rds_worker_cap1,0.25,rds_worker_cap2,0.25,rds_worker_cap3,0.25,rds_worker_cap4, 0.25,"H_Cap_tan", 0.25, "H_Cap_blk", 0.25, "H_Cap_blk_CMMG", 0.25, "H_Cap_brn_SPECOPS", 0.25, "H_Cap_tan_specops_US", 0.25, "H_Cap_khaki_specops_UK", 0.25, "H_Cap_red", 0.25, "H_Cap_grn", 0.25, "H_Cap_blu", 0.25, "H_Cap_grn_BI", 0.25, "H_Cap_blk_Raven", 0.25,
	 "H_Cap_blk_ION", 0.25,  "H_Beret_blk", 0.25, "H_Beret_red", 0.25, "H_Beret_grn", 0.25,  "", 1};
	// TODO Wounds
	class Wounds
	{
		tex[]={};
		mat[]={
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",

			"rds_a2port_cman\Villager\Data\villager.RVmat",
			"rds_a2port_cman\Villager\Data\villager_w1.RVmat",
			"rds_a2port_cman\Villager\Data\villager_w2.RVmat"
		};
	};
};
class VZ_Villager1:VZ_Villager
	{
		_generalMacro = "VZ_Villager1";
		displayName=$STR_RDS_DN_CIV_VILLAGER1;
	
		hiddenSelectionsTextures[] =
		{
			\rds_a2port_cman\villager\data\villager_co.paa
		};
		linkedItems[] = {"rds_Villager_cap1",Standard_Items};
		respawnLinkedItems[] = {"rds_Villager_cap1",Standard_Items};
	};
class VZ_Villager2:VZ_Villager
	{
		_generalMacro = "VZ_Villager2";
		moves = "CfgMovesZombieCrouch";
		displayName=$STR_RDS_DN_CIV_VILLAGER2;
	
		//uniformClass = "rds_uniform_villager2";
		hiddenSelectionsTextures[] =
		{
			\rds_a2port_cman\villager\data\villager_v2_co.paa
		};
		linkedItems[] = {"rds_Villager_cap2",Standard_Items};
		respawnLinkedItems[] = {"rds_Villager_cap2",Standard_Items};
	};
class VZ_Villager3:VZ_Villager
	{
		_generalMacro = "VZ_Villager3";
		displayName=$STR_RDS_DN_CIV_VILLAGER3;
	
		//uniformClass = "rds_uniform_villager3";
		hiddenSelectionsTextures[] =
		{
			\rds_a2port_cman\villager\data\villager_v3_co.paa
		};
		linkedItems[] = {"rds_Villager_cap3",Standard_Items};
		respawnLinkedItems[] = {"rds_Villager_cap3",Standard_Items};
	};
class VZ_Villager4:VZ_Villager
	{
		_generalMacro = "VZ_Villager4";
		moves = "CfgMovesZombieCrouch";
		displayName=$STR_RDS_DN_CIV_VILLAGER4;
	
		//uniformClass = "rds_uniform_villager4";
		hiddenSelectionsTextures[] =
		{
			\rds_a2port_cman\villager\data\villager_v4_co.paa
		};
		linkedItems[] = {"rds_Villager_cap4",Standard_Items};
		respawnLinkedItems[] = {"rds_Villager_cap4",Standard_Items};
	};

class VZ_Priest: zZombie_Base
	{
		_generalMacro = "VZ_Priest";
		displayName=$STR_RDS_DN_CIV_PRIEST;
	
		model= "\rds_a2port_cman\Priest\Priest";
		//uniformClass = "rds_uniform_Priest";
		moves = "CfgMovesZombie";
		headgearList[] = {};
		// TODO Wounds
		class Wounds
		{
			tex[]={};
			mat[]={
				"rds_a2port_cman\priest\data\priest.rvmat",
				"rds_a2port_cman\priest\data\W1_priest.rvmat",
				"rds_a2port_cman\priest\data\W2_priest.rvmat",

				"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",

				"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",

				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",

				"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",

				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
			};
		};
	};
class VZ_Policeman : zZombie_Base
{
	_generalMacro = "VZ_Policeman";
	displayName=$STR_RDS_DN_CIV_POLICEMAN;
	
	model= "\rds_a2port_cman\Policeman\Policeman";
	//uniformClass = "rds_uniform_Policeman";
	moves = "CfgMovesZombie";
	linkedItems[] = {"rds_police_cap","rds_police_holster",Standard_Items};
	respawnLinkedItems[] = {"rds_police_cap","rds_police_holster",Standard_Items};
	headgearList[] = {};
	class Wounds
	{
		tex[]={};
		mat[]={
			"rds_a2port_cman\policeman\data\policeman.rvmat",
			"rds_a2port_cman\policeman\data\w1_policeman.rvmat",
			"rds_a2port_cman\policeman\data\w2_policeman.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_black_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_black_bald_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_white_old.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat",

			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat",
			"A3\Characters_F\Heads\Data\hl_asian_bald_muscular_injury.rvmat"
		};
	};
};

class VZ_Doctor_base: zZombie_Base
	{
		_generalMacro = "VZ_Doctor_base";
		model= "\rds_a2port_cman\Doctor\Doctor";
		hiddenSelections[] =
		{
			"Camo"
		};
		hiddenSelectionsTextures[] =
		{
			\rds_a2port_cman\doctor\data\doctor_co.paa
		};
		headgearList[] = {};

		class Wounds
		{
			tex[]={};
			mat[]={
				"rds_a2port_cman\doctor\data\doctor.rvmat",
				"rds_a2port_cman\doctor\data\W1_doctor.rvmat",
				"rds_a2port_cman\doctor\data\W2_doctor.rvmat",

				"A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat",
				"A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat"
			};
		};
	};

class VZ_Doctor: VZ_Doctor_base
	{
		_generalMacro = "VZ_Doctor";
		displayName=$STR_RDS_DN_CIV_DOCTOR;
	
		hiddenSelectionsTextures[] =
		{
			\rds_a2port_cman\doctor\data\doctor_co.paa
		};
		attendant = 1;
		linkedItems[] = {""}; /// items directly in inventory slots
		respawnLinkedItems[] = {""};
		//uniformClass = "rds_uniform_doctor";
	};


class VZ_SchoolTeacher: VZ_Doctor_base
	{
		_generalMacro = "VZ_SchoolTeacher";
		displayName=$STR_RDS_DN_CIV_SCHOOLTEACHER;
	
		hiddenSelectionsTextures[] =
		{
			\rds_a2port_cman\doctor\data\doctor2_co.paa
		};
		//uniformClass = "rds_uniform_schoolteacher";
	};



class VZ_Assistant: VZ_Doctor_base
	{
		_generalMacro = "VZ_Assistant";
		moves = "CfgMovesZombieCrouch";
		displayName=$STR_RDS_DN_CIV_ASSISTANT;
	
		hiddenSelectionsTextures[] =
		{
			\rds_a2port_cman\doctor\data\doctor_3_co.paa
		};
		linkedItems[] = {""}; /// items directly in inventory slots
		respawnLinkedItems[] = {""};
		//uniformClass = "rds_uniform_assistant";
	};
	//New SigWar
class VZ_zed: zZombie_Base /// class visible in editor
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName = "VIRUZ zombie Policeman"; /// what's displayed in editor or on cursor over
		model = "\viruz_zombie\models\zed.p3d"; /// path to model
		uniformClass = "U_zed_uniform";
		moves = "CfgMovesZombie";
		backpack = "";
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {""}; /// items directly in inventory slots
		respawnLinkedItems[] = {""};
	};
	/*class VZ_woman: zZombie_Base /// class visible in editor
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName = "VIRUZ Woman survivor"; /// what's displayed in editor or on cursor over
		model = "\viruz_zombie\models\woman.p3d"; /// path to model
		uniformClass = "U_woman_uniform";
		moves = "CfgMovesZombie";
		backpack = "";
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {}; /// items directly in inventory slots
		respawnLinkedItems[] = {};
	};*/
	class VZ_boomer: zZombie_Base /// class visible in editor
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName = "VIRUZ Fat zombie"; /// what's displayed in editor or on cursor over
		model = "\viruz_zombie\models\boomer.p3d"; /// path to model
		uniformClass = "U_boomer_uniform";
		moves = "CfgMovesZombie";
		backpack = "";
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {}; /// items directly in inventory slots
		respawnLinkedItems[] = {};
		armor = 50;
		cost = 1000000;
	
	};
	/*class VZ_officer: zZombie_Base /// class visible in editor
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName = "VIRUZ Officer zombie"; /// what's displayed in editor or on cursor over
		model = "\viruz_zombie\models\zedofficer.p3d"; /// path to model
		uniformClass = "U_officer_uniform";
		moves = "CfgMovesZombie";
		backpack = "";
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {"VZ_hatofficer"}; /// items directly in inventory slots
		respawnLinkedItems[] = {"VZ_hatofficer"};
	};
	/*class VZ_zedwoman: zZombie_Base /// class visible in editor
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName = "VIRUZ Woman zombie"; /// what's displayed in editor or on cursor over
		model = "\viruz_zombie\models\zedwoman.p3d"; /// path to model
		uniformClass = "U_zedwoman_uniform";
		moves = "CfgMovesZombie";
		backpack = "";
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {}; /// items directly in inventory slots
		respawnLinkedItems[] = {};
	};*/
	class VZ_zedmalebig: zZombie_Base /// class visible in editor
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName = "VIRUZ Big zombie"; /// what's displayed in editor or on cursor over
		model = "\viruz_zombie\models\zedmalebig.p3d"; /// path to model
		uniformClass = "U_zedmalebig_uniform";
		moves = "CfgMovesZombie";
		backpack = "";
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {}; /// items directly in inventory slots
		respawnLinkedItems[] = {};
	};
	class VZ_medic: zZombie_Base /// class visible in editor
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName = "VIRUZ Medic zombie"; /// what's displayed in editor or on cursor over
		model = "\viruz_zombie\models\test.p3d"; /// path to model
		uniformClass = "U_zedmedic_uniform";
		moves = "CfgMovesZombie";
		backpack = "";
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {""}; /// items directly in inventory slots
		respawnLinkedItems[] = {""};
	};
};
