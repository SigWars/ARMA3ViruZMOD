/*	
	INITILIZATION
*/

enableSaving [false, false];
//player setVariable ["BIS_noCoreConversations", true];
//disable radio messages to be heard and shown in the left lower corner of the screen
//enableRadio false;
//enableSentences false;
//=========== Sem Voz
0 fadeRadio 0;
enableRadio false;
enableSentences false;

if (!isDedicated) then {
	onPreloadFinished {PTm_IsPreloadFinished = true; onPreloadFinished {};};
	waitUntil {!isNil "PTm_IsPreloadFinished"};
	["PTm_loadingScreen"] call BIS_fnc_startLoadingScreen;
};

//REALLY IMPORTANT VALUES
viruZ_instance =	1;					//The instance
viruzHiveRequest = [];
initialized = false;
viruz_previousID = 0;

// No Fatigue
[] spawn {
	// No fatigue
	while {true} do {
		player setFatigue 0;
		player enableStamina false;
		player enableAimPrecision false;
		uiSleep 10;
	};
};



//Load in compiled functions
call compile preprocessFileLineNumbers "\z\addons\viruz_mod\init\variables.sqf";				//Initilize the Variables (IMPORTANT: Must happen very early)
progressLoadingScreen 0.1;
call compile preprocessFileLineNumbers "\z\addons\viruz_mod\init\publicEH.sqf";				//Initilize the publicVariable event handlers
progressLoadingScreen 0.2;
call compile preprocessFileLineNumbers "\z\addons\viruz_mod\medical\setup_functions_med.sqf";	//Functions used by CLIENT for medical
progressLoadingScreen 0.4;
call compile preprocessFileLineNumbers "\z\addons\viruz_mod\init\compiles.sqf";				//Compile regular functions

progressLoadingScreen 1.0;

//////////////////////////////////////////////////////////////////////////
//cmEARPLUGS CODE START

call compile preProcessFileLineNumbers "cmEarplugs\config.sqf";

//cmEARPLUGS CODE END
//////////////////////////////////////////////////////////////////////////

//BUILD REPLACEMENT
#include "buildingReplacement.sqf"


if (isServer) then {
	_serverMonitor = 	[] execVM "\z\addons\viruz_mod\system\server_monitor.sqf";
};

if (!isDedicated) then {
	
	//Conduct map operations
	waitUntil {!isNil "viruz_loadScreenMsg"};
	viruz_loadScreenMsg = (localize "STR_AUTHENTICATING");
	
	//Run the player monitor
	_id = player addEventHandler ["Respawn", {_id = [] spawn player_death;}];
	_playerMonitor = 	[] execVM "\z\addons\viruz_mod\system\player_monitor.sqf";
	execVM "\z\addons\viruz_mod\external\vzgm\init.sqf";
};
execFSM "fn_ASM.fsm";
waitUntil {time > 0}; 
