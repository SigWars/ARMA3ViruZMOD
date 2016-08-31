#define Standard_Items 'ItemMap','ItemCompass','ItemWatch','ItemRadio'
class RDS_Citizen:RDS_Civilian_Base // base class
{
	displayName=$STR_RDS_DN_CIV_CITIZEN;
	model= "\rds_a2port_cman\citizen\citizen";
	scope=0;
	accuracy=3.9; //Rg 0.7;

	uniformClass = "rds_uniform_citizen1";

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
	rarityUrban=0.5;
	hiddenSelections[] =
	{
		"Camo"
	};
};
class RDS_Citizen1:RDS_Citizen
{

	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_CITIZEN1;
	Author_Macro

	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\citizen\data\citizen_co.paa
	};
};
class RDS_Citizen2: RDS_Citizen
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_CITIZEN2;
	Author_Macro
	uniformClass = "rds_uniform_Citizen2";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\citizen\data\Citizen_v2_co.paa
	};
};
class RDS_Citizen3: RDS_Citizen
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_CITIZEN3;
	Author_Macro
	uniformClass = "rds_uniform_Citizen3";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\citizen\data\Citizen_v3_co.paa
	};
};
class RDS_Citizen4: RDS_Citizen
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_CITIZEN4;
	Author_Macro
	uniformClass = "rds_uniform_Citizen4";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\citizen\data\Citizen_v4_co.paa
	};
};

class RDS_Worker: RDS_Civilian_Base // base class
{
	scope=0;
	accuracy=3.9; //Rg 0.7;
	displayName=$STR_RDS_DN_CIV_WORKER;
	Author_Macro
	model= "\rds_a2port_cman\Worker\Worker";
	uniformClass = "rds_uniform_worker1";
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
	rarityUrban=0.4;
};
class RDS_Worker1: RDS_Worker
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_WORKER1;
	Author_Macro
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\worker\data\worker_co.paa
	};
	rarityUrban=0.4;

	linkedItems[] = {"rds_worker_cap1",Standard_Items};
	respawnLinkedItems[] = {"rds_worker_cap1",Standard_Items};
};
class RDS_Worker2: RDS_Worker
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_WORKER2;
	Author_Macro
	uniformClass = "rds_uniform_Worker2";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\worker\data\Worker_v2_CO.paa
	};
	rarityUrban=0.5;
	linkedItems[] = {"rds_worker_cap2",Standard_Items};
	respawnLinkedItems[] = {"rds_worker_cap2",Standard_Items};
};
class RDS_Worker3: RDS_Worker
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_WORKER3;
	Author_Macro
	uniformClass = "rds_uniform_Worker3";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\worker\data\Worker_v3_CO.paa
	};
	linkedItems[] = {"rds_worker_cap3",Standard_Items};
	respawnLinkedItems[] = {"rds_worker_cap3",Standard_Items};
};
class RDS_Worker4: RDS_Worker
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_WORKER4;
	Author_Macro
	uniformClass = "rds_uniform_Worker4";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\worker\data\Worker_v4_CO.paa
	};
	linkedItems[] = {"rds_worker_cap4",Standard_Items};
	respawnLinkedItems[] = {"rds_worker_cap4",Standard_Items};
};


class RDS_Profiteer:RDS_Civilian_Base //base class
{
	scope=0;
	accuracy=3.9; //Rg 0.7;
	displayName=$STR_RDS_DN_CIV_PROFITEER;
	Author_Macro
	model= "\rds_a2port_cman\profiteer\profiteer";
	uniformClass = "rds_uniform_profiteer1";

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
	rarityUrban=0.6;
};
class RDS_Profiteer1: RDS_Profiteer
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_PROFITEER1;
	Author_Macro
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\profiteer\data\profiteer_co.paa
	};
	linkedItems[] = {"rds_Profiteer_cap1",Standard_Items};
	respawnLinkedItems[] = {"rds_Profiteer_cap1",Standard_Items};
};
class RDS_Profiteer2: RDS_Profiteer
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_PROFITEER2;
	Author_Macro
	uniformClass = "rds_uniform_Profiteer2";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\profiteer\data\profiteer_v2_co.paa
	};
	linkedItems[] = {"rds_Profiteer_cap2",Standard_Items};
	respawnLinkedItems[] = {"rds_Profiteer_cap2",Standard_Items};
};
class RDS_Profiteer3: RDS_Profiteer
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_PROFITEER3;
	Author_Macro
	uniformClass = "rds_uniform_Profiteer3";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\profiteer\data\profiteer_v3_co.paa
	};
	linkedItems[] = {"rds_Profiteer_cap3",Standard_Items};
	respawnLinkedItems[] = {"rds_Profiteer_cap3",Standard_Items};
};
class RDS_Profiteer4: RDS_Profiteer
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_PROFITEER4;
	Author_Macro
	uniformClass = "rds_uniform_Profiteer4";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\profiteer\data\profiteer_v4_co.paa
	};
	linkedItems[] = {"rds_Profiteer_cap4",Standard_Items};
	respawnLinkedItems[] = {"rds_Profiteer_cap4",Standard_Items};
};


class RDS_Woodlander:RDS_Civilian_Base
{
	scope=0;
	accuracy=3.9; //Rg 0.7;
	displayName=$STR_RDS_DN_CIV_Woodlander;
	Author_Macro
	model= "\rds_a2port_cman\Woodlander\Woodlander";
	uniformClass = "rds_uniform_woodlander1";
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
	rarityUrban=0.4;
	linkedItems[] = {"rds_Woodlander_cap1",Standard_Items};
	respawnLinkedItems[] = {"rds_Woodlander_cap1",Standard_Items};
};
class RDS_Woodlander1:RDS_Woodlander
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_Woodlander1;
	Author_Macro
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\Woodlander\data\Woodlander_co.paa
	};
};
class RDS_Woodlander2:RDS_Woodlander
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_Woodlander2;
	Author_Macro
	uniformClass = "rds_uniform_Woodlander2";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\Woodlander\data\Woodlander_v2_co.paa
	};
	linkedItems[] = {"rds_Woodlander_cap2",Standard_Items};
	respawnLinkedItems[] = {"rds_Woodlander_cap2",Standard_Items};
};
class RDS_Woodlander3:RDS_Woodlander
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_Woodlander3;
	Author_Macro
	uniformClass = "rds_uniform_Woodlander3";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\Woodlander\data\Woodlander_v3_co.paa
	};
	linkedItems[] = {"rds_Woodlander_cap3",Standard_Items};
	respawnLinkedItems[] = {"rds_Woodlander_cap3",Standard_Items};
};
class RDS_Woodlander4:RDS_Woodlander
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_Woodlander4;
	Author_Macro
	uniformClass = "rds_uniform_Woodlander4";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\Woodlander\data\Woodlander_v4_co.paa
	};
	linkedItems[] = {"rds_Woodlander_cap4",Standard_Items};
	respawnLinkedItems[] = {"rds_Woodlander_cap4",Standard_Items};
};
class RDS_Functionary:RDS_Civilian_Base
{
	scope=0;
	accuracy=3.9; //Rg 0.7;
	displayName=$STR_RDS_DN_CIV_FUNCTIONARY;
	Author_Macro
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
	uniformClass = "rds_uniform_Functionary1";
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
	rarityUrban=0.8;
};
class RDS_Functionary1:RDS_Functionary
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_FUNCTIONARY1;
	Author_Macro
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\functionary\data\functionary_co.paa
	};
};
class RDS_Functionary2:RDS_Functionary
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_FUNCTIONARY2;
	Author_Macro
	uniformClass = "rds_uniform_Functionary2";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\functionary\data\functionary2_co.paa
	};
	rarityUrban=0.7;
};

class RDS_Villager:RDS_Civilian_Base
{
	scope=0;
	accuracy=3.9; //Rg 0.7;
	displayName=$STR_RDS_DN_CIV_VILLAGER;
	Author_Macro
	model= "\rds_a2port_cman\Villager\Villager";
	uniformClass = "rds_uniform_villager1";
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
	rarityUrban=0.2;
};
class RDS_Villager1:RDS_Villager
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_VILLAGER1;
	Author_Macro
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\villager\data\villager_co.paa
	};
	linkedItems[] = {"rds_Villager_cap1",Standard_Items};
	respawnLinkedItems[] = {"rds_Villager_cap1",Standard_Items};
};
class RDS_Villager2:RDS_Villager
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_VILLAGER2;
	Author_Macro
	uniformClass = "rds_uniform_villager2";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\villager\data\villager_v2_co.paa
	};
	linkedItems[] = {"rds_Villager_cap2",Standard_Items};
	respawnLinkedItems[] = {"rds_Villager_cap2",Standard_Items};
};
class RDS_Villager3:RDS_Villager
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_VILLAGER3;
	Author_Macro
	uniformClass = "rds_uniform_villager3";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\villager\data\villager_v3_co.paa
	};
	linkedItems[] = {"rds_Villager_cap3",Standard_Items};
	respawnLinkedItems[] = {"rds_Villager_cap3",Standard_Items};
};
class RDS_Villager4:RDS_Villager
{
	scope=2;
	accuracy=1000;
	displayName=$STR_RDS_DN_CIV_VILLAGER4;
	Author_Macro
	uniformClass = "rds_uniform_villager4";
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\villager\data\villager_v4_co.paa
	};
	linkedItems[] = {"rds_Villager_cap4",Standard_Items};
	respawnLinkedItems[] = {"rds_Villager_cap4",Standard_Items};
};

class RDS_Priest: RDS_Civilian_Base
{
	scope=2;
	accuracy=3.9; //Rg 0.7;
	displayName=$STR_RDS_DN_CIV_PRIEST;
	Author_Macro
	model= "\rds_a2port_cman\Priest\Priest";
	uniformClass = "rds_uniform_Priest";
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
class RDS_Policeman : RDS_Civilian_Base
{
	scope=2;
	accuracy=3.9; //Rg 0.7;
	displayName=$STR_RDS_DN_CIV_POLICEMAN;
	Author_Macro
	model= "\rds_a2port_cman\Policeman\Policeman";
	uniformClass = "rds_uniform_Policeman";
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




class RDS_Doctor_base: RDS_Civilian_Base
{
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

class RDS_Doctor: RDS_Doctor_base
{
	scope=2;
	accuracy=3.9; //Rg 0.7;
	displayName=$STR_RDS_DN_CIV_DOCTOR;
	Author_Macro
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\doctor\data\doctor_co.paa
	};
	attendant = 1;
	uniformClass = "rds_uniform_doctor";
};


class RDS_SchoolTeacher: RDS_Doctor_base
{
	scope=2;
	accuracy=3.9; //Rg 0.7;
	displayName=$STR_RDS_DN_CIV_SCHOOLTEACHER;
	Author_Macro
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\doctor\data\doctor2_co.paa
	};
	rarityUrban=0.5;
	uniformClass = "rds_uniform_schoolteacher";
};



class RDS_Assistant: RDS_Doctor_base
{
	scope=2;
	accuracy=3.9; //Rg 0.7;
	displayName=$STR_RDS_DN_CIV_ASSISTANT;
	Author_Macro
	hiddenSelectionsTextures[] =
	{
		\rds_a2port_cman\doctor\data\doctor_3_co.paa
	};
	rarityUrban=0.5;
	uniformClass = "rds_uniform_assistant";
};

