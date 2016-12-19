[]execVM "\z\addons\viruz_server\system\s_fps.sqf"; //server monitor FPS (writes each ~181s diag_fps+181s diag_fpsmin*)
/*
	ViruZ Mod for Arma 3
	server_monitor.sqf
	Autor: SigWar
	Start load database entryes and load objects and vehicles in world.
	http://www.viruzmod.com
*/

viruz_versionNo = 		getText(configFile >> "CfgMods" >> "ViruZ" >> "version");
viruz_hiveVersionNo = 	getNumber(configFile >> "CfgMods" >> "ViruZ" >> "hiveVersion");
_script = 				getText(missionConfigFile >> "onPauseScript");

allowConnection = false;
//publicVariable "allowConnection";

if ((count allUnits == 0) and !isDedicated) then {
	isSinglePlayer = true;
};

waitUntil{initialized}; //means all the functions are now defined

diag_log "HIVE: Starting";

if (_script != "") then
{
	diag_log "MISSION: File Updated";
} else {
	while {true} do
	{
		diag_log "MISSION: File Needs Updating";
		sleep 1;
	};
};

	//Stream in objects
	/* STREAM OBJECTS */
		//Send the key
		_key = format["CHILD:302:%1:",viruZ_instance];
		_result = _key call server_hiveReadWrite;

		diag_log "HIVE: Request sent";
		
		//Process result
		_status = _result select 0;
		
		
		_key2 = format["CHILD:999:SELECT ObjectID, OwnerUID, Locked, LastFix, Worldprecision FROM object_data :[]:"];
		_result2 = _key2 call server_hiveReadWrite;
		diag_log "HIVE: Request sent";
		
		//Process result
		_status2 = _result2 select 0;
		
		_myArray = [];
		if (_status == "ObjectStreamStart") then {
			_val = _result select 1;
			//Stream Objects
			diag_log ("HIVE: Commence Object Streaming...");
			for "_i" from 1 to _val do {
				_result = _key call server_hiveReadWrite;
				_result2 = _key2 call server_hiveReadWrite;
				//diag_log format["RESULT =  %1 RESULT2 = %2",_result,_result2];
				_string = format ["%1",_result2 select 0];
				//_status = _result select 0;
				if (_result select 1 == _string) then {
					_myArray set [count _myArray,_result+_result2];
				}else {
					_result2 = _key2 call server_hiveReadWrite;
				};
			};
			//diag_log ("HIVE: Streamed " + str(_val) + " objects");
		};
	
		handle_server_spawn_builds = [_myArray] spawn server_StartSpawnBulds;
		
		waitUntil { sleep 60; scriptDone handle_server_spawn_builds };
		
		handle_server_spawn_vehicles = [_myArray] spawn server_StartSpawnVehicles;
		
		waitUntil { /*sleep 60;*/ scriptDone handle_server_spawn_vehicles };
		
		if ((count arrayObjectID) == 0) then {arrayObjectID = [0]};
		// # END OF STREAMING #

		
//Set the Time
	//Send request
	/*_key = "CHILD:307:";
	_result = _key call server_hiveReadWrite;
	_outcome = _result select 0;
	if(_outcome == "PASS") then {
		_date = _result select 1; 
		if(isDedicated) then {
			//["viruzSetDate",_date] call broadcastRpcCallAll;
			setDate _date;
			viruzSetDate = _date;
			publicVariable "viruzSetDate";
		};

		diag_log ("HIVE: Local Time set to " + str(_date));
	};*/
	_viuruzStartSetDate = getArray (missionConfigFile >> "cfgGame" >> "viuruzStartSetDate");
		
	setDate _viuruzStartSetDate;
	createCenter civilian;

	if (isDedicated) then {
	endLoadingScreen;
	_id = [] execFSM "\z\addons\viruz_server\system\server_cleanup.fsm";
	};


handler_spawnCrashSite = [] spawn server_spawnCrashSite; // Start spawn heli crash logic
handler_VehiclesSpawner = [] spawn server_VehiclesSpawner; // Start spawn vehicle logic
handler_objectSpawner = [] spawn server_objectSpawner; //Start spawn object in map

allowConnection = true;
[] spawn server_autorestart;