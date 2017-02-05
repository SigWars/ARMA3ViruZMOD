private["_position","_num","_config","_itemType","_itemChance","_weights","_index","_iArray","_vehicleModel","_lootTable","_guaranteedLoot","_randomizedLoot","_frequency","_variance","_spawnChance","_spawnMarker","_nearestRadius","_spawnFire","_permanentFire","_vehicleName"];

_frequency		= getNumber (missionConfigFile >> "CfgVehiclesSpawner" >> "frequency");
_variance		= getNumber (missionConfigFile >> "CfgVehiclesSpawner" >> "variance");
_spawnChance	= getNumber (missionConfigFile >> "CfgVehiclesSpawner" >> "spawnChance");

//Fix for Multimaps suport anchor By SigWar
//Need add "center" mark on center of the map in editor
_mapaatual = worldName;
switch (tolower _mapaatual) do {
	
	case "stratis": { _spawnMarker	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };
	case "bornholm": { _spawnMarker = getMarkerPos "center"; _nearestRadius = 10000; };
	case "esseker": { _spawnMarker = getMarkerPos "center"; _nearestRadius = 6000; };
	case "altis": { _spawnMarker = getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius = (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };
	case "chernarus": { _spawnMarker = getMarkerPos "center"; _nearestRadius = 7000; };
	case "tanoa": {  _spawnMarker = getMarkerPos "center"; _nearestRadius = 8000; };
	case "xcam_taunus": { _spawnMarker = getMarkerPos "center"; _nearestRadius = 15000; };
	default { _spawnMarker = getMarkerPos "center"; _nearestRadius = 15000; };
	};

_nearestCity 	= nearestLocations [_spawnMarker, ["NameVillage","NameCity","NameLocal","Airport","Hill","NameMarine","NameCityCapital"],_nearestRadius];

/// Debug param
_vehicleForceSpawn = (missionConfigFile >> "cfgGame" >> "DebugVehicleForceSpawn") call BIS_fnc_getCfgData;
if (isNil "_vehicleForceSpawn") then {_vehicleForceSpawn = false;};
if (typename _vehicleForceSpawn == typename "") then {_vehicleForceSpawn = call compile _vehicleForceSpawn;};
#define VEH_FORCE_SPAWN (({_x  isKindOf "AllVehicles"} count viruz_serverObjectMonitor < 40) && _vehicleForceSpawn)
//diag_log format ["VEHICLESSPAWNER DEBUG: DebugVehicleForceSpawn = %1 : VEH_FORCE_SPAWN = %2", _vehicleForceSpawn, VEH_FORCE_SPAWN];

if (ViruzDebugMode > 2 or ViruzDebugType == "VEHICLES") then {
	diag_log("VEHICLESSPAWNER: Starting spawn logic for Vehicles Spawner");
};

while {true} do {
	private["_timeAdjust","_timeToSpawn","_spawnRoll","_vehicle","_hasAdjustment","_newHeight","_adjustedPos"];
	// Allows the variance to act as +/- from the spawn frequency timer
	_timeAdjust = round(random(_variance * 2) - _variance);
	_timeToSpawn = time + _frequency + _timeAdjust;
	
	//_nearestCity = nearestLocations [_spawnMarker, ["NameCityCapital","NameCity","NameVillage","NameLocal","NameMarine"],_nearestRadius];
	_City = _nearestCity call BIS_fnc_selectRandom;
	_spawnPosition = locationPosition _City;
	_locationRadiusA = getNumber (configFile >> "cfgWorlds" >> worldName >> "Names" >> className _City >> "RadiusA");
	if (isNil "_locationRadiusA") then {_locationRadiusA = 400;};
	_vehicleTypeModel = "";
	
	if (type _City == "NameMarine") then {
		_vehicleTypeModel = "Ships";
	} else {
		switch (text _City) do {
			default				{_vehicleTypeModel = "Civilian";};
			case "Airport":		{_vehicleTypeModel = "Military";};
			case "military":	{_vehicleTypeModel = "Military";};
			case "factory":		{_vehicleTypeModel = "Military";};
		};
	};
	_arrayVehiclesModel = getArray (missionConfigFile >> "CfgVehiclesSpawner" >> _vehicleTypeModel);
	
	//Adding some Random systems
	_vehicleModel = _arrayVehiclesModel call BIS_fnc_selectRandom;
	
	_vehicleName	= getText (configFile >> "CfgVehicles" >> _vehicleModel select 0 >> "displayName");

	if (ViruzDebugMode > 2 or ViruzDebugType == "VEHICLES") then {
		diag_log(format["VEHICLESSPAWNER: %1%2 chance to spawn '%3' at %4 : %5 location pos %6", round(_spawnChance * 100), '%', _vehicleName, _timeToSpawn, className _City, _spawnPosition]);
	};	

	// Apprehensive about using one giant long sleep here given server time variances over the life of the server daemon
	while {time < _timeToSpawn && !VEH_FORCE_SPAWN} do {
		sleep 5;
	};

	_spawnRoll = random 1;

	// Percentage roll
	if (_spawnRoll <= _spawnChance || VEH_FORCE_SPAWN) then {
		if ((count (allMissionObjects (_vehicleModel select 0))) <  (_vehicleModel select 1)) then {
			if (_vehicleTypeModel == "Ships") then {
				_position = [_spawnPosition,0,(_locationRadiusA * 10),10,2,2000,1] call BIS_fnc_findSafePos;
			} else {
				_position = [_spawnPosition,0,_locationRadiusA,1,0,0,0] call BIS_fnc_findSafePos;
			};

			if (ViruzDebugMode > 2 or ViruzDebugType == "VEHICLES") then {
				diag_log(format["VEHICLESSPAWNER: Spawning '%1' NOW! (%2) at: %3", _vehicleName, time, str(_position)]);
			};	

			_vehicle = createVehicle [_vehicleModel select 0,_position, [], 0, "CAN_COLLIDE"];
			// Randomize the direction the vehicle is facing
			_vehicle setDir round(random 360);
			
			clearWeaponCargoGlobal _vehicle;
			clearMagazineCargoGlobal _vehicle;
			clearItemCargoGlobal _vehicle;
			
			_idKey = ([arrayObjectID,1] call BIS_fnc_findExtreme) + 1;
			arrayObjectID set [count arrayObjectID, _idKey];
			_vehicle setVariable ["ObjectID", str(_idKey), true];
			
			_worldspace = [getDir _vehicle ,getPosATL _vehicle];
			_uid = _worldspace  call viruz_objectUID2;
			
			_charID = 0;
			_vehicle setVariable ["CharacterID", str(_charID), true];
			
			
			_HitPoints = _vehicle call vehicle_getHitpoints;
			_array = [];
			{
				_selection = getText (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "HitPoints" >> _x >> "name");
				_Hit = [0, 0.2, 0.4] call BIS_fnc_selectRandom;
				if (_hit > 0) then {_array set [count _array,[_selection,_hit]]};
				if (_selection != "" and local _vehicle) then {
					_strH = "hit_" + (_selection);
					_vehicle setHit[_selection, _Hit];
					_vehicle setVariable [_strH,_Hit,true];
				} else {
					if (_selection != "") then {
						[_vehicle,_selection,_Hit] call object_setFixServer;
					};
				};
			} forEach _HitPoints;
			
			_Fuel = [0.4, 0.6, 0.8] call BIS_fnc_selectRandom;
			_vehicle setFuel _Fuel;

			_query = format["INSERT INTO object_data (ObjectID, ObjectUID, Instance, Classname, Datestamp, CharacterID, Worldspace, Inventory, Hitpoints, Fuel) VALUES (%1, %2, %3, '%4', now(), %5, '%6', '%7', '%8', %9)",str(_idKey),_uid,viruZ_instance,(typeOf _vehicle),_charID,_worldspace,[],_array,_Fuel];
			[_query,1] call viruz_asyncCall;
						
			_vehicle setVariable ["lastUpdate",time];
			viruz_serverObjectMonitor set [count viruz_serverObjectMonitor,_vehicle];
			_vehicle call fnc_vehicleEventHandler;
		};
	};
};