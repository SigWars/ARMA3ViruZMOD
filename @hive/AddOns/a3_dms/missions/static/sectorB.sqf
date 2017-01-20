/*
	Sector B ViruZ Mod Desenvolvimento
	Created by Mateus "Mateuus" Rodrigues
	"SectorB" static mission for Taunus
*/
private["_num","_side","_pos","_missionName","_msgStart","_msgWIN","_msgLOSE","_difficulty","_AISoldierSpawnLocations","_AICount","_group","_staticGuns","_crateClasses_and_Positions","_count","_i","_crate0","_crate1","_missionAIUnits","_groupReinforcementsInfo","_missionObjs","_markers","_circle","_time","_added"];

//MONITOR: contagem de unidades
_num = DMS_MissionCount;

//Definir o side da missão (apenas "bandit" é suportado por enquanto).
_side = "bandit";

switch (toLower worldName) do
{
	case "xcam_taunus":
	{
		_pos = [20821.9,-161.617,0];
		_missionName = "Salvation City (Sector B)";
		_msgStart = ['#FFFF00', "Salvation City, also known as (Sector B) the last human standing city where the elites and the rich still live, far away from the infected, protected by high walls and the worlds top trained elite mercenaries..."];
		_msgWIN = ['#0080ff',"Look for their LootBox filled with guns, ammo, and supplies!"];
		_msgLOSE = ['#FF0000',"The Sector Security managed to contain the invasion..."];
	};
	
	default
	{
	    diag_log format["DMS ERROR :: Attempting to run occupation with unsupported map: %1",worldName];
	};
};

if (isNil "_pos") exitWith {};

if ([_pos,DMS_StaticMinPlayerDistance] call DMS_fnc_IsPlayerNearby) exitWith {"delay"};

diag_log text "[DMS]: Salvation City (Sector B) Mission Started";

// Set general mission difficulty
_difficulty = "hardcore";

_AISoldierSpawnLocations =
[
	_pos,
	_pos,
	_pos,
	//Cidade Static
	[20761.6,-293.54,0],//
	[20768.1,-246.483,0],//
	[20768,-213.009,0], //
	[20715.2,-213.147,0], //
	[20701.6,-353.206,0], //
	[20736.1,-359.325,0], //
	[20719.3,-377.774,0], //

	//Cidade
	[20741.3,-343.567,3], //
	[20642.8,-337.583,0], //
	[20664.5,-329.179,0], //
	[20556.4,-292.748,0], //
	[20610.6,-272.239,0], //
	[20678.7,-273.152,0], //
	[20794.2,-253.171,0], //
	[20798,-264.533,0], //
	[20795.6,-271.671,4], //
	[20796.1,-272.827,7], //
	[20795.6,-301.798,7], //
	[20799,-234.481,0], //
	[20796.4,-223.062,0], //
	[20859.4,-305.991,0],
	
	//Muro
	[20169.5,59.6299,0],//
	[20238.9,314.668,0],//
	[20477.7,429.098,0], //
	[20755.3,453.451,0],//
	[21416.1,465.313,0],//
	//Garitas
	[21515.5,402.863,17],//
	[21227.5,464.027,18],//
	[20812.6,463.979,18],//
	[20485.8,450.521,17], //
	[20165.4,282.13,17], //
	
	//Pista do Aeroporto pra <----- Pista  -------> Cidade
	/*[20719.3,-377.774,0],
	[20719.3,-377.774,0],
	[20719.3,-377.774,0],
	
	//Torre Areporto
	[20719.3,-377.774,0],
	[20719.3,-377.774,0],
	
	//Tonel atras dos angares
	[20719.3,-377.774,0],
	[20719.3,-377.774,0],
	[20719.3,-377.774,0],
	[20719.3,-377.774,0],*/
	
	
	//Factor Area
	[20442.2,-116.926,0], //
	[20450.4,-145.973,0],//
	[20479.8,-140.038,0],//
	[20482.6,-118.775,0],//
	[20528.6,-109.846,0], //
	[20528.6,-135.004,0], //
	[20529.3,-173.83,0], //
	[20521,-186.858,0], //
	[20526.2,-208.954,0],//
	[20427.3,-116.845,0]//
];

// Create AI
_AICount = 53 + (round (random 5));

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Get AI to defend the position
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
_group =
[
	_AISoldierSpawnLocations, // Passe os locais de desova regulares, bem como as 3x centro pos
	_AICount,				// Number of AI
	_difficulty,			// "random","hardcore","difficult","moderate", or "easy"
	"random", 				// "random","assault","MG","sniper" or "unarmed" OR [_type,_launcher]
	_side 					// "bandit","hero", etc.
] call DMS_fnc_SpawnAIGroup_MultiPos;


_staticGuns =
[
	[	//Quantidade de .50 = 10;
		_pos vectorAdd [5,0,0],			// 5 meters East of center pos
		_pos vectorAdd [-5,0,0],		// 5 meters West of center pos
		_pos vectorAdd [0,5,0],			// 5 meters North of center pos
		_pos vectorAdd [0,-5,0]	/*	// 5 meters South of center pos
		// .50 Prédio da Construção
		[20551.4,279.029,14], //
		// .50 Atras do Prédio da Construção no Tanque
		[20943.5,318.914,0],//
		// .50 No Banque atras do Aeroporto
		[21247.7,-302.844,0],//
		// .50 No Fim do Aeroporto atras do mato
		[20442.2,-116.926,0],
		// .50 Em cima da Casa Amarela
		[21134.5,273.655,17],
		// .50 No Banque em baixo da casa Amarela na parte da frente
		[21162,280.512,6],
		// .50 No Predios Grandes
		[20876.6,-208.045,26],//
		// .50 No Predios Grandes
		[20854.8,-209.592,26],//
		// .50 Em cima da Casa Do Prefeito
		[20742.6,-355.505,10]//*/
	],
	_group,
	"assault",
	"static",
	"bandit"
] call DMS_fnc_SpawnAIStaticMG;


_crateClasses_and_Positions =
[
	[[23216.3,18863.6,20.5],"I_CargoNet_01_ammo_F"],
	[[23497.9,18483.8,20.5],"I_CargoNet_01_ammo_F"],
	[[22562.777,19717.54,0],"I_CargoNet_01_ammo_F"],
	[[22690.197,19717.54,0],"I_CargoNet_01_ammo_F"],
	[[23509.7,18788.1,22.52],"I_CargoNet_01_ammo_F"]
];

{
	deleteVehicle (nearestObject _x);		// Make sure to remove any previous crates.
} forEach _crateClasses_and_Positions;

_count = count _crateClasses_and_Positions;

for "_i" from 1 to _count do 
{
    _crateClasses_and_Positions pushBack (_crateClasses_and_Positions deleteAt (floor (random _count)));
};

// Create Crates
_crate0 = [_crateClasses_and_Positions select 0 select 1, _crateClasses_and_Positions select 0 select 0] call DMS_fnc_SpawnCrate;
_crate1 = [_crateClasses_and_Positions select 1 select 1, _crateClasses_and_Positions select 1 select 0] call DMS_fnc_SpawnCrate;

// Disable smoke on the crates so that the players have to search for them >:D
{
	_x setVariable ["DMS_AllowSmoke", true];
} forEach [_crate0,_crate1];

// Define mission-spawned AI Units
_missionAIUnits =
[
	_group 		// We only spawned the single group for this mission
];

// Define the group reinforcements
_groupReinforcementsInfo = [];

// Define mission-spawned objects and loot values
_missionObjs =
[
	_staticGuns,			// static gun(s). Note, we don't add the base itself because it already spawns on server start.
	[],
	[[_crate0,[50,100,2]],[_crate1,[3,150,15]]]
];


// Create Markers
_markers =
[
	_pos,
	_missionName,
	_difficulty
] call DMS_fnc_CreateMarker;

_circle = _markers select 1;
_circle setMarkerDir 20;
_circle setMarkerSize [150,50];



_time = diag_tickTime;

// Parse and add mission info to missions monitor
_added =
[
	_pos,
	[
		[
			"kill",
			_group
		],
		[
			"playerNear",
			[_pos,100]
		]
	],
	_groupReinforcementsInfo,
	[
		_time,
		DMS_StaticMissionTimeOut call DMS_fnc_SelectRandomVal
	],
	_missionAIUnits,
	_missionObjs,
	[_missionName,_msgWIN,_msgLOSE],
	_markers,
	_side,
	_difficulty,
	[[],[]]
] call DMS_fnc_AddMissionToMonitor_Static;

// Check to see if it was added correctly, otherwise delete the stuff
if !(_added) exitWith
{
	diag_log format ["DMS ERROR :: Attempt to set up mission %1 with invalid parameters for DMS_fnc_AddMissionToMonitor_Static! Deleting mission objects and resetting DMS_MissionCount.",_missionName];

	_cleanup = [];
	{
		_cleanup pushBack _x;
	} forEach _missionAIUnits;

	_cleanup pushBack ((_missionObjs select 0)+(_missionObjs select 1));

	{
		_cleanup pushBack (_x select 0);
	} foreach (_missionObjs select 2);

	_cleanup call DMS_fnc_CleanUp;


	// Delete the markers directly
	{deleteMarker _x;} forEach _markers;


	// Reset the mission count
	DMS_MissionCount = DMS_MissionCount - 1;
};

// Notify players
[_missionName,_msgStart] call DMS_fnc_BroadcastMissionStatus;

if (DMS_DEBUG) then
{
	(format ["MISSION: (%1) :: Mission #%2 started at %3 with %4 AI units and %5 difficulty at time %6",_missionName,_num,_pos,_AICount,_difficulty,_time]) call DMS_fnc_DebugLog;
};
