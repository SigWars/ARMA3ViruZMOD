private["_type","_isAir","_inVehicle","_dateNow","_maxZombies","_maxWildZombies","_age","_nearbyBuildings","_radius","_locationstypes","_nearestCity","_position",
"_nearbytype","_posLoot","_index","_checkPos","_result","_isOk","_isLootGroundSpawn","_players","_spawnZombies","_nearBy","_nearbyCount","_config","_canLoot","_dis","_nearPlayer",
"_looted","_cleared","_nearByObj","_zombied"];
//_type = _this select 0;
//_Keepspawning = _this select 1;
_isAir = vehicle player iskindof "Air";
_inVehicle = (vehicle player != player);
_dateNow = time;
_maxZombies = viruz_maxLocalZombies;
_maxWildZombies = viruz_maxWildZombies;
_age = 0;

_nearbyBuildings = [];
_radius = 200; 
_position = getPosATL player;

if (_inVehicle) then {
	_maxZombies = _maxZombies / 2;
};
if (_isAir) then {
	_maxZombies = 5
};


_players = _position nearEntities [["AllPlayers_2", "Survivor2_DZ"], _radius+200];
viruz_maxGlobalZombies = viruz_maxLocalZombies;
{
	viruz_maxGlobalZombies = viruz_maxGlobalZombies + 1;
} foreach _players;

_spawnZombies = _position nearEntities ["zZombie_Base",_radius+100];
viruz_spawnZombies = 0;
{
	if (local _x) then 
	{
		//diag_log ("Local");
		viruz_spawnZombies = viruz_spawnZombies + 1;
	};
}foreach _spawnZombies;

viruz_CurrentZombies = count (_position nearEntities ["zZombie_Base",_radius+200]);

_nearBy = nearestObjects [_position, ["building","Maniken_Base"]+VIRUZ_LOOTHOLDER, _radius];
_nearbyCount = count _nearBy;
if (_nearbyCount < 1) exitwith 
{
	if ((viruz_spawnZombies < _maxWildZombies) and !_inVehicle)  then {
		[_position] call wild_spawnZombies;
	};
};

{
	_type = typeOf _x;
	_config = 		missionConfigfile >> "CfgBuildingLoot" >> _type;
	_canLoot = 		isClass (_config);
	_dis = _x distance player;
	
	//Loot
	if ((_dis < 120) and (_dis > 0) and _canLoot and !_inVehicle) then {
		_nearPlayer = (position _x) nearEntities [["Survivor2_DZ"],((sizeOf _type)+1)];
		_looted = _x getVariable ["looted",0];
		_cleared = _x getVariable ["cleared",true];
		_dateNow = time + lootDelaytime;
		//diag_log ("SPAWN LOOT: " + _type + " Building is " + str(_age) + " old" );
		if ((time > _looted) and (count _nearPlayer < 1) and !_cleared) then {
			_nearByObj = nearestObjects [(getPosATL _x), VIRUZ_LOOTHOLDER,((sizeOf _type)+5)];
			{deleteVehicle _x} forEach _nearByObj;
			_x setVariable ["cleared",true,true];
			_x setVariable ["looted",0,true];
			_x setVariable ["spawnCount",0,true];
		};
		if ((time > _looted) and _cleared) then {
			//Register
			_x setVariable ["looted",_dateNow,true];
			//cleanup
			_handle = [_x] spawn building_spawnLoot;
			waitUntil{scriptDone _handle};
		};
	};
	//Zeds
	if ((time - viruz_spawnWait) > viruz_spawnDelay) then {
		if (viruz_maxCurrentZeds < viruz_maxZeds) then {
			if (viruz_CurrentZombies < viruz_maxGlobalZombies) then {
				if (viruz_spawnZombies < viruz_maxLocalZombies) then {
						_zombied = (_x getVariable ["zombieSpawn",0]);
						_dateNow = time + viruz_zedsRespawnDelay;
						//if (_age > 3) then {
						if (time > _zombied) then {
							_x setVariable ["zombieSpawn",_dateNow,true];
							[_x] call building_spawnZombies;
						};
				} else {
					viruz_spawnWait = time;
				};
			};
		};
	};
} forEach _nearBy;