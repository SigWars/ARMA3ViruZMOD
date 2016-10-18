private["_position","_num","_config","_itemType","_itemChance","_weights","_index","_iArray","_vehicleModel","_lootTable","_guaranteedLoot","_randomizedLoot","_frequency","_variance","_spawnChance","_spawnMarker","_nearestRadius","_spawnFire","_permanentFire","_vehicleName"];

_frequency		= getNumber (missionConfigFile >> "CfgVehiclesSpawner" >> "frequency");
_variance		= getNumber (missionConfigFile >> "CfgVehiclesSpawner" >> "variance");
_spawnChance	= getNumber (missionConfigFile >> "CfgVehiclesSpawner" >> "spawnChance");

//Fix for Multimaps suport anchor By SigWar
//Need add "center" mark on center of the map in editor
_mapaatual = worldName;
switch (_mapaatual) do {
	
	case "Stratis": { _spawnMarker	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };
	case "Bornholm": { _spawnMarker = getMarkerPos "center"; _nearestRadius = 10000; };
	case "Esseker": { _spawnMarker = getMarkerPos "center"; _nearestRadius = 6000; };
	case "Altis": { _spawnMarker = getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius = (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };
	case "Chernarus": { _spawnMarker = getMarkerPos "center"; _nearestRadius = 7000; };
	
	};

_nearestCity 	= nearestLocations [_spawnMarker, ["NameCityCapital","NameCity","NameVillage","NameLocal","NameMarine"],_nearestRadius];

/// Debug param
_vehicleForceSpawn = (missionConfigFile >> "cfgGame" >> "DebugVehicleForceSpawn") call BIS_fnc_getCfgData;
if (isNil "_vehicleForceSpawn") then {_vehicleForceSpawn = false;};
if (typename _vehicleForceSpawn == typename "") then {_vehicleForceSpawn = call compile _vehicleForceSpawn;};
#define VEH_FORCE_SPAWN (({_x  isKindOf "AllVehicles"} count viruz_serverObjectMonitor < 40) && _vehicleForceSpawn)
//diag_log format ["VEHICLESSPAWNER DEBUG: DebugVehicleForceSpawn = %1 : VEH_FORCE_SPAWN = %2", _vehicleForceSpawn, VEH_FORCE_SPAWN];

diag_log("VEHICLESSPAWNER: Starting spawn logic for Vehicles Spawner");

while {true} do {
	private["_timeAdjust","_timeToSpawn","_spawnRoll","_vehicle","_hasAdjustment","_newHeight","_adjustedPos"];
	// Allows the variance to act as +/- from the spawn frequency timer
	_timeAdjust = round(random(_variance * 2) - _variance);
	_timeToSpawn = time + _frequency + _timeAdjust;
	
	//_nearestCity = nearestLocations [_spawnMarker, ["NameCityCapital","NameCity","NameVillage","NameLocal","NameMarine"],_nearestRadius];
	_City = _nearestCity call BIS_fnc_selectRandom;
	_spawnPosition = locationPosition _City;
	_locationRadiusA = getNumber (configFile >> "cfgWorlds" >> worldName >> "Names" >> className _City >> "RadiusA");
	_vehicleTypeModel = "";
	
	if (type _City == "NameMarine") then {
		_vehicleTypeModel = "Ships";
	} else {
		switch (text _City) do {
			default				{_vehicleTypeModel = "Civilian";};
			case "military":	{_vehicleTypeModel = "Military";};
			case "factory":		{_vehicleTypeModel = "Military";};
		};
	};
	_arrayVehiclesModel = getArray (missionConfigFile >> "CfgVehiclesSpawner" >> _vehicleTypeModel);
	
	//Adding some Random systems
	_vehicleModel = _arrayVehiclesModel call BIS_fnc_selectRandom;
	
	_vehicleName	= getText (configFile >> "CfgVehicles" >> _vehicleModel select 0 >> "displayName");

	diag_log(format["VEHICLESSPAWNER: %1%2 chance to spawn '%3' at %4 : %5 location pos %6", round(_spawnChance * 100), '%', _vehicleName, _timeToSpawn, className _City, _spawnPosition]);

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
				_position = [_spawnPosition,0,_locationRadiusA,10,0,2000,0] call BIS_fnc_findSafePos;
			};

			diag_log(format["VEHICLESSPAWNER: Spawning '%1' NOW! (%2) at: %3", _vehicleName, time, str(_position)]);

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
				_Hit = [0, 0.2, 0.4, 0.6, 0.8, 1] call BIS_fnc_selectRandom;
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
			
			_Fuel = random 1;
			_vehicle setFuel _Fuel;

			//Send request
			_key = format["CHILD:308:%1:%2:%3:%4:%5:%6:%7:%8:%9:",viruZ_instance, (typeOf _vehicle), 0 , _charID, _worldspace, [], _array, _Fuel,_uid];
			diag_log ("HIVE: WRITE: "+ str(_key));
			_key call server_hiveWrite;
			
			_vehicle setVariable ["lastUpdate",time];
//			needUpdate_objects set [count needUpdate_objects,_vehicle];
			viruz_serverObjectMonitor set [count viruz_serverObjectMonitor,_vehicle];
			_vehicle call fnc_vehicleEventHandler;
		};
	};
};