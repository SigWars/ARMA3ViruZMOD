/***********************************************************
ViruZ Mod Hlicrash Script
File: vzserver_Helicrash.sql
Author: SigWar
Description: 
Spawn Helicopers to fly at random position based on "center" mark and explod making helicrash loot.

************************************************************/

private["_useStatic","_crashDamage","_lootRadius","_preWaypoints","_preWaypointPos","_endTime","_startTime","_safetyPoint","_heliStart","_deadBody","_exploRange","_heliModel","_lootPos","_list","_craters","_dummy","_wp2","_wp3","_landingzone","_aigroup","_wp","_helipilot","_crash","_crashwreck","_smokerand","_staticcoords","_pos","_dir","_position","_num","_config","_itemType","_itemChance","_weights","_index","_iArray","_crashModel","_lootTable","_frequency","_variance","_spawnChance","_spawnRadius","_permanentFire","_crashName"];

_frequency	= getNumber (missionConfigFile >> "CfgSpawnCrashSite" >> "frequency");
_variance	= getNumber (missionConfigFile >> "CfgSpawnCrashSite" >> "variance");
_spawnChance = getNumber (missionConfigFile >> "CfgSpawnCrashSite" >> "spawnChance");
_crashDamage = getNumber (missionConfigFile >> "CfgSpawnCrashSite" >> "crashDamage");
_staticcoords = getArray (missionConfigFile >> "CfgSpawnCrashSite" >> "staticcoords");
if (getNumber (missionConfigFile >> "CfgSpawnCrashSite" >> "useStatic") == 1) then {_useStatic=true;} else {_useStatic=false;};


_mapaatual = worldName;
switch (tolower _mapaatual) do {
	
	case "stratis": { _spawnRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };
	case "bornholm": { _spawnRadius = 10000; };
	case "esseker": { _spawnRadius = 6000; };
	case "altis": { _spawnRadius = (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };
	case "chernarus": { _spawnRadius = 7000; };
	case "tanoa": { _spawnRadius = 8000; };
	case "xcam_taunus": { _spawnRadius = 20000; };
	default {  _spawnRadius = 20000; };
	};

if (ViruzDebugMode > 2 or ViruzDebugType == "HELICRASH") then {
	diag_log(format["VIRUZHELICRASH: Iniciada Logica dos helicrashs [STATIC:%1||CRASHDAMAGE:%2|]", str(_useStatic), _crashDamage]);
};

while {true} do {
	private["_timeAdjust","_timeToSpawn","_spawnRoll","_crash","_hasAdjustment","_newHeight","_adjustedPos"];
	// Allows the variance to act as +/- from the spawn frequency timer
	_timeAdjust = round(random(_variance * 2) - _variance);
	_timeToSpawn = time + _frequency + _timeAdjust;

	//Random Heli-Type
	_heliModel = "B_Heli_Attack_01_F"; //AH99_SRV

	//Random-Startpositions, Adjust this moving marks in editor
	_HeliMarker1 = getMarkerPos "HeliMarker1";
	_HeliMarker2 = getMarkerPos "HeliMarker2";
	_HeliMarker3 = getMarkerPos "HeliMarker3";
	_heliStart = [_HeliMarker1,_HeliMarker2,_HeliMarker3] call BIS_fnc_selectRandom;
	//_heliStart = [[3461.92,5021.77,0],[8582.35,14077.7,0]] call BIS_fnc_selectRandom;
	
	//A Backup Waypoint, if not Bornholm, set some Coordinates far up in the north (behind all possible Crashsites)
	_safetyPoint = getMarkerPos "center";
	//_safetyPoint = [8450.08,20240,0];

	//Settings for the Standard
	_crashModel = "Land_Wreck_Heli_Attack_01_F";
	_exploRange = 195;
	_lootRadius = 0.35;

	//Adjust Wreck and Range of Explosion if its a Mi17_DZ
	if(_heliModel == "Mi17_DZ") then {
		_crashModel = "Mi8Wreck";
		_exploRange = 285;
		_lootRadius = 0.3;
	};

	//Crash loot just uncomment the one you wish to use by default with 50cals is enabled.
    //Table including 50 cals
    //_lootTable = ["Military"] call BIS_fnc_selectRandom;
    //_lootTable = ["HeliCrashWEST","HeliCrashEAST","MilitarySpecial"] call BIS_fnc_selectRandom;

	_crashName	= getText (configFile >> "CfgVehicles" >> _heliModel >> "displayName");

	if (ViruzDebugMode > 2 or ViruzDebugType == "HELICRASH") then {
		diag_log(format["VIRUZHELICRASH: %1%2 chance to start a crashing %3 at %4", round(_spawnChance * 100), '%', _crashName, _timeToSpawn]);
	};	

	// Apprehensive about using one giant long sleep here given server time variances over the life of the server daemon
	while {time < _timeToSpawn} do {
		sleep 5;
	};

	_spawnRoll = random 1;

	// Percentage roll
	if (_spawnRoll <= _spawnChance) then {

/*
==================================================================================================
		_staticcoords give you the possibility to organize your crashsites!
		Crashsites close to cherno or electro would be possible with that.
		Use the editor for your map, create some vehicles or triggers at points where you
		want your crashside (aprox), save it and extract all coordinates and put them in this
		2D-Array. If you dont know how to do this, dont use _staticcoords.
		I would advise you to create at least 100 positions, otherwise its too easy for your players
		to find the crash-locations after some time of playing on your server.
		!!!!!After you put in the coordinates you have to set _useStatic to true inside
		your server_monitor.sqf, default is false!!!!!
==================================================================================================
*/

		if(_useStatic) then {
			_position = _staticcoords call BIS_fnc_selectRandom;
		} else {
			_position = [getMarkerPos "center",0,_spawnRadius,1,0,0,0] call BIS_fnc_findSafePos;
		};
		//DEFAULT: GET COORDS FROM BIS_fnc_findSafePos, COMMENT OUT IF YOU USE _STATICCOORDS
		
		if (ViruzDebugMode > 2 or ViruzDebugType == "HELICRASH") then {
			diag_log(format["VIRUZCRASH: %1 started flying from %2 to %3 NOW!(TIME:%4)", _crashName,  str(_heliStart), str(_position), round(time)]);
		};	

		//Spawn the AI-Heli flying in the air
		_startTime = time;
		_trandom = selectRandom [30,40,60];
		_explotime = time + _trandom;
		_crashwreck = createVehicle [_heliModel,_heliStart, [], 0, "FLY"];

		//Make sure its not destroyed by the Hacker-Killing-Cleanup (Thanks to Sarge for the hint)
		_crashwreck setVariable["ViruZMod",1];

		_crashwreck engineOn true;
		_crashwreck flyInHeight 60;
		_crashwreck forceSpeed 90;
		_crashwreck setspeedmode "LIMITED";

		//Create an Invisibile Landingpad at the Crashside-Coordinates
		_landingzone = createVehicle ["Land_HelipadEmpty_F", [_position select 0, _position select 1,0], [], 0, "CAN_COLLIDE"];
		_landingzone setVariable["ViruZMod",1];

		//CreW...
		_aigroup = creategroup civilian;
		_helipilot = _aigroup createUnit ["Survivor2_DZ",getPos _crashwreck,[],0,"FORM"];
		_helipilot moveindriver _crashwreck;
		_helipilot assignAsDriver _crashwreck;

		sleep 0.5;

		_wp2 = _aigroup addWaypoint [position _landingzone, 0];
		_wp2 setWaypointType "MOVE";
		_wp2 setWaypointBehaviour "CARELESS";

		//Even when the Heli flys to high, it will burn when reaching its Waypoint
		_wp2 setWaypointStatements ["true", "_crashwreck setdamage 1;"];

		//Adding a last Waypoint up in the North, so the Heli doesnt Hover at WP1 (OR2)
		//and would also come back to WP1 if somehow it doesnt explode.
		_wp3 = _aigroup addWaypoint [_safetyPoint, 0];
		_wp3 setWaypointType "CYCLE";
		_wp3 setWaypointBehaviour "CARELESS";

		//Get some more Speed when close to the Crashpoint and go on even if Heli died or hit the ground
		waituntil {(_crashwreck distance _position) <= 1000 || not alive _crashwreck || (getPosATL _crashwreck select 2) < 5 || (damage _crashwreck) >= _crashDamage};
			_crashwreck flyInHeight 60;
			_crashwreck forceSpeed 40;
			_crashwreck setspeedmode "NORMAL";

		//BOOOOOOM!
		waituntil {(_crashwreck distance _position) <= _exploRange || not alive _crashwreck || (getPosATL _crashwreck select 2) < 5 || (damage _crashwreck) >= _crashDamage || time > _explotime };
			//Taking out the Tailrotor would be more realistic, but makes the POC not controllable
			//_crashwreck setHit ["mala vrtule", 1];
			_crashwreck setdamage 0.80;
			_crashwreck setfuel 0.25;
			
			if (ViruzDebugMode > 2 or ViruzDebugType == "HELICRASH") then {
				diag_log(format["VIRUZCRASH: %1 just exploded at %2!, ", _crashName, str(getPosATL _crashwreck)]);
			};

			//She cant survive this :(
			_helipilot setdamage 1;

			//Giving the crashed Heli some time to find its "Parkingposition"
			sleep 13;

		//Get position of the helis wreck, but make sure its on the ground;
		_pos = [getpos _crashwreck select 0, getpos _crashwreck select 1,0];

		//saving the direction of the wreck(not used right now)
		_dir = getdir _crashwreck; 

		//Send Public Variable so every client can delete the craters around the new Wreck (musst be added in init.sqf)
		heliCrash = _pos;
		publicVariable "heliCrash";
		
		//Clean Up the Crashsite
		deletevehicle _crashwreck;
		deletevehicle _helipilot;
		deletevehicle _landingzone;

		//Animation is done, lets create the actual Crashside
		_crash = createVehicle [_crashModel, _pos, [], 0, "CAN_COLLIDE"];
		_burnthefucker = "test_EmptyObjectForFireBig" createVehicle (position _crash);
		_burnthefucker attachto [_crash, [0,0,-1]];
		
		_crash setVariable["ViruZMod",1];

		//If you want all Grass around the crashsite to be cutted: Uncomment the next Line (Noobmode)
		//_crashcleaner = createVehicle ["ClutterCutter_EP1", _pos, [], 0, "CAN_COLLIDE"];

		//Setting the Direction would add realism, but it sucks because of the bugged model when not on plane ground.
		//If you want it anyways, just uncomment the next line
		//_crash setDir _dir;

		viruz_serverObjectMonitor set [count viruz_serverObjectMonitor,_crash];

		_crash setVariable ["ObjectID",1,true];
		
		//Adiciona Caixas de loot
		for "_i" from 0 to 2 do
		{
			_crate = createVehicle ["VZBox_MediaV", _crash modelToWorld [(random 35) - 10, (random 35) - 10, 0], [], 0, "CAN_COLLIDE"];
			_crate setPos [(getPos _crate) select 0, (getPos _crate) select 1, 0];
			_crate setVariable["ViruZMod",1];
		};
		
		_endTime = time - _startTime;
		if (ViruzDebugMode > 2 or ViruzDebugType == "HELICRASH") then {
			diag_log(format["VIRUZCRASH: Crash completed! Wreck at: %2 - Runtime: %1 Seconds || Distance from calculated POC: %3 meters", round(_endTime), str(getPos _crash), round(_position distance _crash)]); 
		};	
	};
};