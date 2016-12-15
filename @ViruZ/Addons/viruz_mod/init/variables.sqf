disableSerialization;

viruzCanConnect = false;

ViruzDebugMode = call {
		_ViruzDebugMode = (missionConfigFile >> "cfgGame" >> "ViruzDebugMode") call BIS_fnc_getCfgData;
		if (isNil "_ViruzDebugMode") then {0} else {_ViruzDebugMode}
	};

ViruzDebugType = call {
		_ViruzDebugType = (missionConfigFile >> "cfgGame" >> "ViruzDebugType") call BIS_fnc_getCfgData;
		if (isNil "_ViruzDebugType") then {"NONE"} else {_ViruzDebugType}
	};	

config_VehiclesCheck =		getArray(configFile >> "CfgObjectCheck" >> "vehicles");
config_ObjectIgnore =		getArray(configFile >> "CfgObjectCheck" >> "ignore");
playerSpawnPositions = 		getArray(missionconfigFile >> "cfgGame" >> "SpawnPositions");

//Model Variables
Bandit1_DZ = 	"Bandit1_DZ";
BanditW1_DZ = "Bandit1_DZ";
Survivor1_DZ = 	"Survivor2_DZ";
Survivor2_DZ = 	"Survivor2_DZ";
//Survivor3_DZ = 	"Survivor2_DZ";

AllPlayersVehicles = ["Bandit1_DZ","Bandit1_DZ","Survivor2_DZ","AllVehicles"];

//Cooking
meatraw = [
    "FoodSteakRaw",
    "FoodmeatRaw",
    "FoodbeefRaw",
    "FoodmuttonRaw",
    "FoodchickenRaw",
    "FoodrabbitRaw",
    "FoodbaconRaw",
	"FishRawTrout",
	"FishRawSeaBass",
	"FishRawTuna"
];
meatcooked = [
    "FoodSteakCooked",
    "FoodmeatCooked",
    "FoodbeefCooked",
    "FoodmuttonCooked",
    "FoodchickenCooked",
    "FoodrabbitCooked",
    "FoodbaconCooked",
	"FishCookedTrout",
	"FishCookedSeaBass",
	"FishCookedTuna"
];
//Eating
no_output_food = ["FoodMRE", "FoodPistachio", "FoodNutmix"]+meatcooked+meatraw;
food_with_output=[
    "FoodCanWBBeans",
    "FoodCanMHBeans",
    "FoodCanCGBeans",
    "FoodCanBeefChunks",
	"FoodCanChickenChunks",
	"FoodCanChickenNoodle",
	"FoodCanFruitcocktail",
	"FoodCanOranges",
	"FoodCanPeaches",
	"FoodCanPears",
	"FoodCanEsardines",
	"FoodCanPsardines",
	"FoodCanChickenSoup",
	"FoodCanPotatoSoup",
	"FoodCanPeaSoup",
	"FoodCanCCCornSoup",
	"FoodCanHCCornSoup",
	"FoodCanTRSoup",
	"FoodCanCRiceSoup",
	"FoodCanSpaghetti1",
	"FoodCanSpaghetti2"
];

food_output = [
    "FoodCanWBBeansEmpty",
    "FoodCanMHBeansEmpty",
    "FoodCanCGBeansEmpty",
    "FoodCanBeefChunksEmpty",
	"FoodCanChickenChunksEmpty",
	"FoodCanChickenNoodleEmpty",
	"FoodCanFruitcocktailEmpty",
	"FoodCanOrangesEmpty",
	"FoodCanPeachesEmpty",
	"FoodCanPearsEmpty",
	"FoodCanEsardinesEmpty",
	"FoodCanPsardinesEmpty",
	"FoodCanChickenSoupEmpty",
	"FoodCanPotatoSoupEmpty",
	"FoodCanPeaSoupEmpty",
	"FoodCanCCCornSoupEmpty",
	"FoodCanHCCornSoupEmpty",
	"FoodCanTRSoupEmpty",
	"FoodCanCRiceSoupEmpty",
	"FoodCanSpaghetti1Empty",
	"FoodCanSpaghetti2Empty"
];
//Drinking
no_output_drink = ["ItemWaterbottle", "ItemWaterbottleBoiled"];
drink_with_output = [
    "ItemSodaOriginal",  
    "ItemSodaDarth",
    "ItemSodaDiet",
    "ItemSodaGrape",
    "ItemSodaHam",
    "ItemSodaLaranja",
    "ItemSodaLimao",
    "ItemSodaYoda", 
    "ItemSodaBeergolden"
];
drink_output = [
    "ItemSodaOriginalEmpty", 
    "ItemSodaDarthEmpty",
    "ItemSodaDietEmpty",
    "ItemSodaGrapeEmpty",
    "ItemSodaHamEmpty",
    "ItemSodaLaranjaEmpty",
    "ItemSodaLimaoEmpty",
    "ItemSodaYodaEmpty", 
    "ItemSodaBeergoldenEmpty"
];
boil_tin_cans = [
    "ItemSodaOriginalEmpty", 
    "ItemSodaDarthEmpty",
    "ItemSodaDietEmpty",
    "ItemSodaGrapeEmpty",
    "ItemSodaHamEmpty",
    "ItemSodaLaranjaEmpty",
    "ItemSodaLimaoEmpty",
    "ItemSodaYodaEmpty", 
    "ItemSodaBeergoldenEmpty",
	"FoodCanWBBeansEmpty",
    "FoodCanMHBeansEmpty",
    "FoodCanCGBeansEmpty",
    "FoodCanBeefChunksEmpty",
	"FoodCanChickenChunksEmpty",
	"FoodCanChickenNoodleEmpty",
	"FoodCanFruitcocktailEmpty",
	"FoodCanOrangesEmpty",
	"FoodCanPeachesEmpty",
	"FoodCanPearsEmpty",
	"FoodCanEsardinesEmpty",
	"FoodCanPsardinesEmpty",
	"FoodCanChickenSoupEmpty",
	"FoodCanPotatoSoupEmpty",
	"FoodCanPeaSoupEmpty",
	"FoodCanCCCornSoupEmpty",
	"FoodCanHCCornSoupEmpty",
	"FoodCanTRSoupEmpty",
	"FoodCanCRiceSoupEmpty",
	"FoodCanSpaghetti1Empty",
	"FoodCanSpaghetti2Empty"
	
];

//viruz_combatLog = "";
canRoll = true;


//Hunting Variables
viruZ_partClasses = [
	"PartFueltank",
	"PartWheel",
	//"PartGeneric",	//No need to add, it is default for everything
	"PartEngine"
];
viruZ_explosiveParts = [
	"palivo",
	"motor"
];

// ********************************************** Builds variable used in vz_MaintainBuild.sqf *********************************
Maintain_MatWood =[
	"Land_Slum_House02_F",
	"Land_Slum_House01_F",
	"VIRUZ_Woodfloor_New",
	"VIRUZ_Woodstair_New",
	"VIRUZ_WoodRamp_New",
	"VIRUZ_WoodWall_New",
	"VIRUZ_WoodDoor_new",
	"VIRUZ_WoodWindow_new",
	"VIRUZ_WoodGate_new",
	"Land_BarrelWater_grey_F",
	"Land_BarrelWater_F",
	"ViruZHolder_base",
	"Rack_Madeira",
	"Stante_Madeira"
];

Maintain_MatCinder = [
	"Land_i_House_Big_01_V1_F",
	"Land_i_House_Big_01_V2_F",
	"Land_i_House_Big_01_V3_F",
	"Land_i_House_Big_02_V2_F",
	"Land_i_House_Big_02_V3_F",
	"Land_i_Shop_02_V1_F",
	"Land_i_House_Small_01_V1_F",
	"Land_i_House_Small_01_V2_F",
	"Land_i_House_Small_01_V3_F",
	"Land_i_House_Small_02_V1_F",
	"Land_i_House_Small_02_V2_F",
	"Land_i_House_Small_02_V3_F",
	"Land_i_House_Small_03_V1_F",
	"VIRUZ_GH_Stairs_F",
	"Land_CncWall1_F",
	"Land_CncWall4_F",
	"Land_Canal_Wall_10m_F",
	"Land_Canal_WallSmall_10m_F",
	"Land_City_4m_F",
	"Land_City_8m_F",
	"Land_City2_4m_F",
	"Land_City2_8m_F",
	"VIRUZ_City_Gate_F"
];

Maintain_MatMetal = [
	"Land_i_Shed_Ind_F",
	"Land_Cargo_House_V1_F",
	"Land_Cargo_House_V3_F",
	"Land_Cargo_HQ_V1_F",
	"Land_Cargo_HQ_V2_F",
	"ViruZ_PierLadder_F",
	"Land_Wall_Tin_4",
	"Land_Wall_Tin_4_2",
	"Land_Wall_Tin_Pole",
	"Land_Net_Fence_4m_F",
	"Land_Net_Fence_8m_F",
	"Land_New_WiredFence_5m_F",
	"Land_New_WiredFence_10m_F",
	"Land_New_WiredFence_pole_F",
	"Land_Slums01_8m",
	"Land_Slums01_pole",
	"Land_Slums02_4m",
	"Land_Mil_WiredFence_F",
	"Land_Slums02_pole",
	"Land_SportGround_fence_F",
	"Land_Wall_Tin_4",
	"Land_Wall_Tin_4_2",
	"Land_Wall_Tin_Pole",
	"Land_Wired_Fence_4m_F",
	"Land_Wired_Fence_8m_F",
	"Land_SportGround_fence_noLC_F",
	"MetalBarrel_burning_F",
	"Land_PortableLight_single_F",
	"Land_FloodLight_F",
	"Land_CampingChair_V1_F",
	"Land_CampingChair_V2_F",
	"Land_CampingTable_F",
	"Land_CampingTable_small_F",
	"Land_Camping_Light_off_F",
	"VIRUZ_Net_Fence_Gate_F",
	"Rack_Ferro",
	"Stante_Ferro",
	"Land_Portable_generator_F"
];

Maintain_MatBag = [
	"Land_BagFence_Long_F",
	"Land_BagFence_Corner_F",
	"Land_BagFence_Round_F",
	"Land_BagFence_Short_F"

];

// *********** end of maintain build variables *************
// ****************** VIRUZ_BUILDS and VIRUZ_GATES ised in fn_SelfActions To Detect objects with door ******************
VIRUZ_BUILDS = [
		/*"Land_Slum_House02_F",
		"Land_Slum_House01_F",
		"Land_i_House_Big_01_V1_F",
		"Land_i_House_Big_01_V2_F",
		"Land_i_House_Big_01_V3_F",
		"Land_i_House_Big_02_V2_F",
		"Land_i_House_Big_02_V3_F",
		"Land_i_Shop_02_V1_F",
		"Land_i_House_Small_01_V1_F",
		"Land_i_House_Small_01_V2_F",
		"Land_i_House_Small_01_V3_F",
		"Land_i_House_Small_02_V1_F",
		"Land_i_House_Small_02_V2_F",
		"Land_i_House_Small_02_V3_F",
		"Land_i_House_Small_03_V1_F",
		"Land_i_Shed_Ind_F",
		"Land_Cargo_House_V1_F",
		"Land_Cargo_House_V3_F",
		"Land_Cargo_HQ_V1_F",
		"Land_Cargo_HQ_V2_F",
		//Escadas
		"ViruZ_PierLadder_F",
		"VIRUZ_GH_Stairs_F"*/
	];

VIRUZ_GATES = [
		//"Land_Gate_IndVar2_5",
		"VIRUZ_City_Gate_F",
		"VIRUZ_Net_Fence_Gate_F",
		"VIRUZ_WoodDoor_new",
		"VIRUZ_WoodWindow_new",
		"VIRUZ_WoodGate_new"
		];

VIRUZ_WALLS = [

		"VIRUZ_Woodfloor_New",
		"VIRUZ_Woodstair_New",
		"VIRUZ_WoodRamp_New",
		"VIRUZ_WoodWall_New",
		"Land_BagFence_Long_F",
		"Land_BagFence_Corner_F",
		"Land_BagFence_Round_F",
		"Land_BagFence_Short_F",
		"Land_CncWall1_F",
		"Land_CncWall4_F",
		"Land_Canal_Wall_10m_F",
		"Land_Canal_WallSmall_10m_F",
		"Land_City_4m_F",
		"Land_City_8m_F",
		"Land_City2_4m_F",
		"Land_City2_8m_F",
		"Land_Net_Fence_4m_F",
		"Land_Net_Fence_8m_F",
		"Land_New_WiredFence_5m_F",
		"Land_New_WiredFence_10m_F",
		"Land_New_WiredFence_pole_F",
		"Land_Slums01_8m",
		"Land_Slums01_pole",
		"Land_Slums02_4m",
		"Land_Mil_WiredFence_F",
		"Land_Slums02_pole",
		"Land_SportGround_fence_F",
		"Land_Wall_Tin_4",
		"Land_Wall_Tin_4_2",
		"Land_Wall_Tin_Pole",
		"Land_Wired_Fence_4m_F",
		"Land_Wired_Fence_8m_F",
		"Land_SportGround_fence_noLC_F"
		
	];

VIRUZ_SUPPLYES = [
		"Land_BarrelWater_grey_F",
		"Land_BarrelWater_F",
		"MetalBarrel_burning_F",
		"Land_Canal_Wall_Stairs_F",
		"Land_PortableLight_single_F",
		"Land_FloodLight_F",
		"Land_Camping_Light_off_F",
		"Land_CampingChair_V1_F",
		"Land_CampingChair_V2_F",
		"Land_CampingTable_F",
		"Land_CampingTable_small_F"
	];
// *********** VIRUZ_LOOTHOLDER used in LOOT scripts to detect Holders and respawn items ****************************
VIRUZ_LOOTHOLDER = [
		"GroundWeaponHolder",
		"VZ_MedBox_lite",
		"VZ_MedBox_especial",
		"VZ_Cesta",
		"Crate_Plastic",
		"VZ_weaponbox_lite",
		"VZ_weaponbox_gold",
		"VZBox_MediaV" //HELICRASH BOX
];

// ************* VIRUZ_RACKS used in build script to detect if object is holder and set correct variables ***********
VIRUZ_RACKS = [
	"ViruZHolder_base",
	"Rack_Madeira",
	"Stante_Madeira",
	"Rack_Ferro",
	"Stante_Ferro",
	"Land_Portable_generator_F"
];
  	
//Survival Variables
SleepFood =				2160; //minutes (48 hours) default = 2160
SleepWater =			1440; //minutes (24 hours) default = 1440
SleepTemperatur	= 		90 / 100;	//Firs Value = Minutes untill Player reaches the coldest Point at night (without other effects! night factor expected to be -1)			//TeeChange
SleepText=				0;
//Server Variables
isSinglePlayer =		false;
viruz_serverObjectMonitor = [];
arrayObjectID = [];

//Streaming Variables (player only)
viruz_Locations = [];
viruz_locationsActive = [];

//GUI
Viruz_GUI_R = 0.38; // 0.7
Viruz_GUI_G = 0.63; // -0.63
Viruz_GUI_B = 0.26; // -0.26

//Player self-action handles
viruz_resetSelfActions = {
	s_player_fire =			-1;
	s_player_cook =			-1;
	s_player_boil =			-1;
	s_player_fireout =		-1;
	s_player_butcher =		-1;
	s_player_packtent = 	[-1,""];
	s_player_fillwater =	-1;
	s_player_fillwater2 = 	-1;
	s_player_fillfuel = 	-1;
	s_player_grabflare = 	-1;
	s_player_removeflare = 	-1;
	s_player_painkiller =	-1;
	s_player_studybody = 	-1;
	s_build_Sandbag1_DZ = 	-1;
	s_build_Hedgehog_DZ =	-1;
	s_build_Wire_cat1 =		-1;
	s_player_deleteBuild =	-1;
	s_player_forceSave = 	-1;
	s_player_flipveh = 		-1;
	s_player_stats =		-1;
	s_player_sleep =		-1;
	s_player_movedog =		-1;
	s_player_speeddog =		-1;
	s_player_calldog = 		-1;
	s_player_feeddog = 		-1;
	s_player_waterdog = 	-1;
	s_player_staydog = 		-1;
	s_player_trackdog = 	-1;
	s_player_barkdog = 		-1;
	s_player_warndog = 		-1;
	s_player_followdog = 	-1;
	s_player_tamedog =		-1;
	s_player_Gear = 		-1;
	s_player_disassembleVehicle = [-1,""];
	s_player_assembleVehicle = [-1,""];
	s_player_fishing =       -1; //fishing
	s_player_fishing_veh =   -1; //fishing
	s_player_lockbuild = 	 -1; //lock structures
	s_player_unlockbuild = 	 -1; //lock structuires
	s_player_maintain =		 -1; //Used to maintain build

};
call viruz_resetSelfActions;

s_player_repairActions = [];

//Initialize Medical Variables
r_interrupt = 			false;
r_doLoop = 				false;
r_self = 				false;
r_self_actions = 		[];
r_drag_sqf = 			false;
r_action = 				false;
r_action_unload = 		false;
r_player_handler = 		false;
r_player_handler1 = 	false;
r_player_dead = 		false;
r_player_unconscious = 	false;
r_player_infected =		false;
r_player_injured = 		false;
r_player_inpain = 		false;
r_player_loaded = 		false;
r_player_cardiac = 		false;
r_fracture_legs =		false;
r_fracture_arms =		false;
r_player_vehicle =		player;
r_player_blood = 		12000;
r_player_lowblood = 	false;
r_player_timeout =		0;
r_player_bloodTotal = 	r_player_blood;
r_public_blood =		r_player_blood;
r_player_bloodDanger =	r_player_bloodTotal * 0.2;
r_player_actions = 		[];
r_handlerCount = 		0;
r_action_repair = 		false;
r_action_targets = 		[];
r_pitchWhine = 			false;
r_isBandit =			false;
vz_cant_Build = 		false;
vzautoRun = 			-1;

//ammo routine
r_player_actions2 = [];
r_action2 = false;
r_player_lastVehicle = objNull;
r_player_lastSeat = [];
r_player_removeActions2 = {
	if (!isNull r_player_lastVehicle) then {
		{
			r_player_lastVehicle removeAction _x;
		} forEach r_player_actions2;
		r_player_actions2 = [];
		r_action2 = false;
	};
};

USEC_woundHit 	= [
	"",
	"face_hub",	// Face 
	"neck",		// Neck
	"head",		// Head
	"pelvis",	// Pelvis 
	"spine1",	// Abdomen
	"spine2",	// Diafragma
	"spine3",	// Chest
	"body",		// HitPelvis max HitAbdomen max HitDiaphragm max HitChest
	"arms",		// Arms	
	"hands",	// Hands
	"legs",		// Legs
	
	"rightlegroll", //Right Leg
	"rightuplegroll", //Right Leg
	"rightupleg",	//Right Leg
	
	"leftlegroll", //left Leg
	"leftuplegroll",	//left Leg
	"leftupleg",	//left Leg
	
	"leftforearm",	//left arm
	"leftarmroll",	//left arm
	
	"rightforearm",
	"rightarmroll"
	
	
];
USEC_woundPoint	= [
	["neck"],
	["neck"],
	["neck"],
	["neck"],
	["pelvis"],
	["pelvis"],
	["pelvis"],
	["pelvis"],
	["lelbow","relbow"],
	["lelbow","relbow"], // Left/Right Arm Points
	["LeftHandMiddle1","rightHandMiddle1"], // Left/Right Hands Points
	["lfemur","rfemur"], // Left/Right Legs Points
	["rfemur"],
	["rfemur"],
	["rfemur"],
	["lfemur"],
	["lfemur"],
	["lfemur"],
	["lelbow"],
	["lelbow"],
	["relbow"],
	["relbow"]
	
	
	
	
	/*["Pelvis","aimpoint"],	//""
	["Pelvis","aimpoint"],	//body
	["Pelvis","aimpoint"],	//arms
	["Pelvis","aimpoint"],	//pelvis
	["neck","pilot"], 		//neck 
	["lelbow","relbow"],	//hands
	["RightFoot","LeftFoot"], //legs 
	["neck","pilot"],		//head_hit
	["RightFoot","LeftFoot"], //spine2 
	["RightFoot","LeftFoot"], //spine3 
	["Pelvis","aimpoint"]*/
];
USEC_HeadParts 	= [
	"face_hub",
	"head",
	"head_hit"
];
USEC_MinorWounds 	= [
	"hands",
	"legs"
];

USEC_typeOfWounds = [
	"neck",
	"pelvis",
	"LeftShoulder",
	"lelbow",
	"rightShoulder",
	"relbow",
	"LeftShoulder",
	"lelbow",
	"rightShoulder",
	"relbow",
	"LeftHandMiddle1",
	"rightHandMiddle1",
	"lfemur",
	"rfemur"
	
	/*"Pelvis",
	"aimpoint",
	"lelbow","relbow",
	"RightFoot","LeftFoot",
	"neck","pilot"*/
];
VIRUZ_woundHit 	= [
	[
		"body",
		"hands",
		"legs",
		"head_hit"
	],
	[ 0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,2,2,3]
];
VIRUZ_woundHit_ok = [
	[
		"body",
		"hands",
		"legs"
	],
	[0,0,0,0,0,1,1,1,2,2]
];
VIRUZ_woundHit_dog = [
	[
		"body",
		"hands",
		"legs"
	],
	[0,0,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2]
];


viruzHit = [];
viruzPublishObj = [];		//used for eventhandler to spawn a mirror of players tent
viruzSaveGroup = []; 		//use to save group in DB
viruzUpdateBuild = []; 		//Viruz build system use to update objects
viruzHideBody = objNull;
//holster
dazy_keyWeapon = profileNamespace getVariable["viruz_Holster", 35]; // 35 = H

viruz_animalDistance = 300; //used in player_animal.check to set max spawn distance to animals
viruz_zSpawnDistance = 500; //used by server to set trigger distance to spawn zombies


viruz_maxAnimals = call {
	_maxAnimals = (missionConfigFile >> "cfgGame" >> "maxAnimals") call BIS_fnc_getCfgData;
	if (isNil "_maxAnimals") then {5} else {_maxAnimals}
};
//viruz_maxLocalZombies = 30;
viruz_maxLocalZombies = call {
	_maxLocalZombies = (missionConfigFile >> "cfgGame" >> "maxLocalZombies") call BIS_fnc_getCfgData;
	if (isNil "_maxLocalZombies") then {30} else {_maxLocalZombies}
};
viruz_maxGlobalZombies = viruz_maxLocalZombies;
viruz_maxWildZombies = call {
	_maxWildZombies = (missionConfigFile >> "cfgGame" >> "maxWildZombies") call BIS_fnc_getCfgData;
	if (isNil "_maxWildZombies") then {3} else {_maxWildZombies}
};
//viruz_maxZeds = 500;
viruz_maxZeds = call {
	_maxZeds = (missionConfigFile >> "cfgGame" >> "maxZeds") call BIS_fnc_getCfgData;
	if (isNil "_maxZeds") then {500} else {_maxZeds}
};
viruz_spawnPos = getPosATL player;

viruz_maxBuildDistance = call {
	_maxBuildDistance = (missionConfigFile >> "cfgGame" >> "maxBuildDistance") call BIS_fnc_getCfgData;
	if (isNil "_maxBuildDistance") then {50} else {_maxBuildDistance}
};
viruz_maxBuildCount = call {
	_maxBuildCount = (missionConfigFile >> "cfgGame" >> "maxBuildCount") call BIS_fnc_getCfgData;
	if (isNil "_maxBuildCount") then {80} else {_maxBuildCount}
};	

//init global arrays for Loot Chances
call compile preprocessFileLineNumbers "\z\addons\viruz_mod\init\loot_init.sqf";

if(isServer) then {
	viruz_players = [];
	dead_bodyCleanup = [];
	needUpdate_objects = [];
};

if(!isDedicated) then {
	//Establish Location Streaming
	_funcGetLocation = 
	{
		for "_i" from 0 to ((count _this) - 1) do 
		{
			private ["_location","_config","_locHdr","_position","_size","_type"];
			//Get Location Data from config
			_config = 	(_this select _i);
			_locHdr = 	configName _config;
			_position = getArray	(_config >> "position");
			_size = 	getNumber	(_config >> "size");
			_type = 	getText		(_config >> "type");
			
			//Find the Location
			_location = nearestLocation [_position, _type];
			
			//Record details
			viruz_Locations set [count viruz_Locations, [_location,_locHdr,_size]]; 
		};
	};
	_cfgLocation = configFile >> "CfgTownGenerator";
	_cfgLocation call _funcGetLocation;
	
	viruz_buildingMonitor = [];	//Buildings to check
	viruz_bodyMonitor = [];
	viruz_flyMonitor = [];		//used for monitor flies
	
	viruz_baseTypes = 		getArray (missionConfigfile >> "CfgBuildingLoot" >> "Default" >> "zombieClass");
	
	//temperature variables
	viruz_temperatur 		= 	36;		//TeeChange
	viruz_temperaturnormal 	= 	36;		//TeeChange
	viruz_temperaturmax 		= 	42;		//TeeChange
	viruz_temperaturmin 		= 	27;		//TeeChange
	
	//player special variables
	viruz_spawnselection =   1; //Spawn selection
	viruZ_lastPlayerUpdate = 0;
	viruZ_everyonesTents =	[];
	viruz_hunger	=			0;
	viruz_thirst = 			0;
	viruz_combat =			0;
	viruz_preloadFinished = 	false;
	viruz_statusArray =		[1,1];
	viruz_disAudial =		0;
	viruz_disVisual =		0;
	viruz_firedCooldown = 	0;
	viruz_DeathActioned =	false;
	viruz_canDisconnect = 	true;
	viruz_damageCounter =	time;
	viruz_lastSave =			time;
	lastSpawned = 			time;
	viruz_isSwimming	=		true;
	viruz_currentDay = 		0;
	viruz_hasLight = 		false;
	viruz_surfaceNoise =		0;
	viruz_surfaceType =		"None";
	viruz_noPenalty = 		[];
	viruz_heavenCooldown =	0;
	deathHandled = 			false;
	viruz_lastHumanity =		0;
	viruz_guiHumanity =		-90000;
	viruz_firstGroup = 		group player;
	viruz_originalPlayer = 	player;
	viruz_playerName =		"Unknown";
	viruz_sourceBleeding =	objNull;
	viruz_clientPreload = 	false;
	viruz_panicCooldown = 	0;
	viruz_areaAffect =		2;
	viruz_monitorPeriod = 	0.6; // number of seconds between each player_zombieCheck calls
	viruz_heartBeat = 		false;
	viruzClickTime =			0;
	viruz_glitchArea = 		-1;
	
	viruz_spawnDelay = call { //Tempo de Respawn de Zumbis baseado no player
		_viruz_spawnDelay = (missionConfigFile >> "cfgGame" >> "viruzZedspawnDelay") call BIS_fnc_getCfgData;
		if (isNil "_viruz_spawnDelay") then {120} else {_viruz_spawnDelay}
	};
	viruz_zedsRespawnDelay = call { //Depreciado
		_zedsRespawnDelay = (missionConfigFile >> "cfgGame" >> "zedsRespawnDelay") call BIS_fnc_getCfgData;
		if (isNil "_zedsRespawnDelay") then {3} else {_zedsRespawnDelay}
	};
	lootDelaytime = call { //Depreciado
		_lootDelaytime = (missionConfigFile >> "cfgGame" >> "lootDelaytime") call BIS_fnc_getCfgData;
		if (isNil "_lootDelaytime") then {900} else {_lootDelaytime}
	};
	
	viruz_spawnWait =		-120;
	viruz_spawnZombies =		0;
	//used to count global zeds around players
	viruz_CurrentZombies = 0;
	//Used to limit overall zed counts
	viruz_maxCurrentZeds = 0;
	viruz_inVehicle =		false;
	viruz_Magazines = 		[];
	viruzGearSave = 			false;
	viruz_unsaved =			false;
	viruz_scaleLight = 		0;
	viruzState = -1;
	helpMenu = 0;
	craftOpen = 0;
	
	zombie_hitchance = call {
		_zombie_hitchance = (missionConfigFile >> "cfgGame" >> "zombie_hitchance") call BIS_fnc_getCfgData;
		if (isNil "_zombie_hitchance") then {8} else {_zombie_hitchance}
	};
	zombie_mindamage = call {
		_zombie_mindamage = (missionConfigFile >> "cfgGame" >> "zombie_mindamage") call BIS_fnc_getCfgData;
		if (isNil "_zombie_mindamage") then {0.8} else {_zombie_mindamage}
	};
	zombie_adddamage = call {
		_zombie_adddamage = (missionConfigFile >> "cfgGame" >> "zombie_adddamage") call BIS_fnc_getCfgData;
		if (isNil "_zombie_adddamage") then {1.2} else {_zombie_adddamage}
	};
	viruz_hitmod5 = call {
		_viruz_hitmod5 = (missionConfigFile >> "cfgGame" >> "viruz_hitmod5") call BIS_fnc_getCfgData;
		if (isNil "_viruz_hitmod5") then {900} else {_viruz_hitmod5}
	};
	viruz_hitmod6 = call {
		_viruz_hitmod6 = (missionConfigFile >> "cfgGame" >> "viruz_hitmod6") call BIS_fnc_getCfgData;
		if (isNil "_viruz_hitmod6") then {1300} else {_viruz_hitmod6}
	};
	viruz_hitmod7 = call {
		_viruz_hitmod7 = (missionConfigFile >> "cfgGame" >> "viruz_hitmod7") call BIS_fnc_getCfgData;
		if (isNil "_viruz_hitmod7") then {1200} else {_viruz_hitmod7}
	};
	viruz_pvpmod = call {
		_viruz_pvpmod = (missionConfigFile >> "cfgGame" >> "viruz_pvpmod") call BIS_fnc_getCfgData;
		if (isNil "_viruz_pvpmod") then {800} else {_viruz_pvpmod}
	};
	viruz_zmbmod = call {
		_viruz_zmbmod = (missionConfigFile >> "cfgGame" >> "viruz_zmbmod") call BIS_fnc_getCfgData;
		if (isNil "_viruz_zmbmod") then {0} else {_viruz_zmbmod}
	};

};