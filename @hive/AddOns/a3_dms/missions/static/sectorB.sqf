/*
	Sector B ViruZ Mod Desenvolvimento
	Created by Mateus "Mateuus" Rodrigues
*/

// For logging purposes
private _num = DMS_MissionCount;


// Set mission side (only "bandit" is supported for now)
_side = "bandit";

_pos = [20821.9,-161.617,0.00144196];

if ([_pos,DMS_StaticMinPlayerDistance] call DMS_fnc_IsPlayerNearby) exitWith {"delay"};


// Set general mission difficulty
_difficulty = "hardcore";

// Definir locais de desova para Ai Soldados. Estes serão utilizados para a desova inicial da IA, bem como reforços.
// A localização no centro da desova é adicionado 3 vezes por isso, pelo menos, 3 AI vai gerar inicialmente à localização no centro, e assim que os reforços futuros são mais propensos a gerar no centro.
_AISoldierSpawnLocations =
[
	//Cidade Static
	[20761.6,-293.54,0.102043],//
	[20768.1,-246.483,0.00144196],//
	[20768,-213.009,0.00144196], //
	[20715.2,-213.147,0.00144196], //
	[20701.6,-353.206,0.00144196], //
	[20736.1,-359.325,0.140953], //
	[20719.3,-377.774,0.00144196], //

	//Cidade
	[20741.3,-343.567,3.85947], //
	[20642.8,-337.583,0.00144196], //
	[20664.5,-329.179,0.00144196], //
	[20556.4,-292.748,0.00144196], //
	[20610.6,-272.239,0.00144196], //
	[20678.7,-273.152,0.00144196], //
	[20794.2,-253.171,0.326447], //
	[20798,-264.533,0.00144196], //
	[20795.6,-271.671,4.75911], //
	[20796.1,-272.827,7.44301], //
	[20795.6,-301.798,7.44301], //
	[20799,-234.481,0.00144196], //
	[20796.4,-223.062,0.326431], //
	[20859.4,-305.991,0.00144196],
	
	//Muro
	[20169.5,59.6299,0.00154877],//
	[20238.9,314.668,0.00143433],//
	[20477.7,429.098,0.0314941], //
	[20755.3,453.451,0.00134277],//
	[21416.1,465.313,0.00137329],//
	//Garitas
	[21515.5,402.863,17.9338],//
	[21227.5,464.027,18.0436],//
	[20812.6,463.979,18.0449],//
	[20485.8,450.521,17.7586], //
	[20165.4,282.13,17.6944], //
	
	//Pista do Aeroporto pra <----- Pista  -------> Cidade
	[20719.3,-377.774,0.00144196],
	[20719.3,-377.774,0.00144196],
	[20719.3,-377.774,0.00144196],
	
	//Torre Areporto
	[20719.3,-377.774,0.00144196],
	[20719.3,-377.774,0.00144196],
	
	//Tonel atras dos angares
	[20719.3,-377.774,0.00144196],
	[20719.3,-377.774,0.00144196],
	[20719.3,-377.774,0.00144196],
	[20719.3,-377.774,0.00144196],
	
	
	//Factor Area
	[20442.2,-116.926,0.0014267], //
	[20450.4,-145.973,0.142197],//
	[20479.8,-140.038,0.0545731],//
	[20482.6,-118.775,0.0947189],//
	[20528.6,-109.846,0.109329], //
	[20528.6,-135.004,0.113281], //
	[20529.3,-173.83,0.0687256], //
	[20521,-186.858,0.0590286], //
	[20526.2,-208.954,0.0711212],//
	[20427.3,-116.845,0.00147247]//
];

// Create AI
_AICount = 53 + (round (random 5));


_group =
[
	_AISoldierSpawnLocations+[_pos,_pos,_pos],			// Passe os locais de desova regulares, bem como as 3x centro pos
	_AICount,
	_difficulty,
	"random",
	_side
] call DMS_fnc_SpawnAIGroup_MultiPos;

_staticGuns =
[
	[	//Quantidade de .50 = 10;
	
		// .50 Prédio da Construção
		[20551.4,279.029,14.2793], //
		// .50 Atras do Prédio da Construção no Tanque
		[20943.5,318.914,0.00138855],//
		// .50 No Banque atras do Aeroporto
		[21247.7,-302.844,0.00144196],//
		// .50 No Fim do Aeroporto atras do mato
		[20442.2,-116.926,0.0014267],
		// .50 Em cima da Casa Amarela
		[21134.5,273.655,17.0531],
		// .50 No Banque em baixo da casa Amarela na parte da frente
		[21162,280.512,6.06858],
		// .50 No Predios Grandes
		[20876.6,-208.045,26.5242],//
		// .50 No Predios Grandes
		[20854.8,-209.592,26.5242],//
		// .50 Em cima da Casa Do Prefeito
		[20742.6,-355.505,10.1006]//
	],
	_group,
	"assault",
	_difficulty,
	"bandit",
	"random"
] call DMS_fnc_SpawnAIStaticMG;



// Definir os nomes de classes e locais onde as caixas podem desovar (pelo menos 2, uma vez que estamos gerando 2 caixas)
_crateClasses_and_Positions =
[
	[[21181.3,294.02,0.00148773],"I_CargoNet_01_ammo_F"],
	[[20731.5,-293.55,0.0382309],"I_CargoNet_01_ammo_F"]
	//[[22562.777,19717.54,0],"I_CargoNet_01_ammo_F"], //POR ENQUANTO DESATIVADO ExileClient_util_array_shuffle
	//[[22690.197,19717.54,0],"I_CargoNet_01_ammo_F"],//POR ENQUANTO DESATIVADO ExileClient_util_array_shuffle
	//[[22456.406,19477.318,0],"I_CargoNet_01_ammo_F"]//POR ENQUANTO DESATIVADO ExileClient_util_array_shuffle
];

{
	deleteVehicle (nearestObject _x);		// Make sure to remove any previous crates.
} forEach _crateClasses_and_Positions;

// Shuffle the list
//_crateClasses_and_Positions = _crateClasses_and_Positions call ExileClient_util_array_shuffle;


// Create Crates
_crate0 = [_crateClasses_and_Positions select 0 select 1, _crateClasses_and_Positions select 0 select 0] call DMS_fnc_SpawnCrate;
_crate1 = [_crateClasses_and_Positions select 1 select 1, _crateClasses_and_Positions select 1 select 0] call DMS_fnc_SpawnCrate;

// Disable smoke on the crates so that the players have to search for them >:D
{
	_x setVariable ["DMS_AllowSmoke", true];
} forEach [_crate0,_crate1];


// Don't think an armed AI vehicle fit the idea behind the mission. You're welcome to uncomment this if you want.
_veh =
[
	[
		[_pos,100,random 360] call DMS_fnc_SelectOffsetPos,
		_pos
	],
	_group,
	"assault",
	_difficulty,
	_side
] call DMS_fnc_SpawnAIVehicle;


// Define mission-spawned AI Units
_missionAIUnits =
[
	_group 		// We only spawned the single group for this mission
];

// Define the group reinforcements
_groupReinforcementsInfo =
[
	[
		_group,			// pass the group
		[
			[
				-1,		// Let's limit number of units instead...
				0
			],
			[
				100,	// Maximum 100 units can be given as reinforcements.
				0
			]
		],
		[
			240,		// About a 4 minute delay between reinforcements.
			diag_tickTime
		],
		_AISoldierSpawnLocations,
		"random",
		_difficulty,
		_side,
		"reinforce",
		[
			10,			// Reinforcements will only trigger if there's fewer than 10 members left in the group
			7			// 7 reinforcement units per wave.
		]
	]
];

// Define mission-spawned objects and loot values
_missionObjs =
[
	_staticGuns,			// static gun(s). Note, we don't add the base itself because it already spawns on server start.
	[],
	[[_crate0,[50,100,2]],[_crate1,[3,150,15]]]
];

// Define Mission Start message
_msgStart = ['#FFFF00', "Salvation City, also known as (Sector B) the last human standing city where the elites and the rich still live, far away from the infected, protected by high walls and the worlds top trained elite mercenaries..."];

// Define Mission Win message
_msgWIN = ['#0080ff',"Look for their LootBox filled with guns, ammo, and supplies!"];

// Define Mission Lose message
_msgLOSE = ['#FF0000',"The Sector Security managed to contain the invasion..."];

// Define mission name (for map marker and logging)
_missionName = "Salvation City (Sector B)";

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
	[]
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
