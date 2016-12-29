/*
	ViruZ Mod for Arma 3
	vzserver_spawnVehicles.sqf
	Autor: SigWar
	Load database entryes and trow vehicles in world.
	http://www.viruzmod.com
*/
private ["_myArray","_allVehicles","_debugLoadInventory","_Civilian","_Military","_Ships","_VZvehicles","_countr","_idKey","_idKey","_type","_ownerID","_worldspace",
"_intentory","_hitPoints","_fuel","_damage","_objectID","_OwnerUID","_Locked","_LastFix","_Worldprecision","_deletado","_deletado","_dir","_pos","_centerMap","_wsDone",
"_mapaatual","_object","_precise","_objWpnTypes","_objWpnQty","_isOK","_block","_classMag","_ammoCount","_selection","_dam"];

_myArray = _this select 0;
_allVehicles = [];
/// Debug load inventory in vehicles
_debugLoadInventory = (missionConfigFile >> "cfgGame" >> "DebugVehicleLoadInventory") call BIS_fnc_getCfgData;
if (isNil "_debugLoadInventory") then {_debugLoadInventory = true;};
if (typename _debugLoadInventory == typename "") then {_debugLoadInventory = call compile _debugLoadInventory;};

_Civilian = [];
{
	_Civilian SET [count _Civilian,_x select 0];
}forEach (getArray(missionConfigFile >> "cfgVehiclesSpawner" >> "Civilian"));

_Military = [];
{
	_Military SET [count _Military,_x select 0];
}forEach (getArray(missionConfigFile >> "cfgVehiclesSpawner" >> "Military"));

_Ships = [];
{
	_Ships SET [count _Ships,_x select 0];
}forEach (getArray(missionConfigFile >> "cfgVehiclesSpawner" >> "Ships"));

_VZvehicles = + _Civilian + _Military + _Ships;

	
	_countr = 0;		
		{
				
			//Parse Array
			_countr = _countr + 1;
			_idKey = 		_x select 1;
			_type =			_x select 2;
			_ownerID = 		_x select 3;
			_worldspace =	_x select 4;
			_intentory =	_x select 5;
			_hitpoints =	_x select 6;
			_fuel =			_x select 7;
			_damage = 		_x select 8;
			_objectID = 	_x select 9;
			_OwnerUID =		_x select 10;
			_Locked =		_x select 11;
			_LastFix = 		_x select 12;
			_Worldprecision = _x select 13;
			
			if (_damage < 1 and (_type in _VZvehicles)) then {
			
										
				_dir = 0;
				_pos = [0,0,0];
				_centerMap = [];
				_wsDone = false;
				if (count _worldspace >= 2) then
				{
					_dir = _worldspace select 0;
					if (count (_worldspace select 1) == 3) then {
						_pos = _worldspace select 1;
						_wsDone = true;
					};
				};			
				if (!_wsDone) then {
					if (count _worldspace >= 1) then { _dir = _worldspace select 0; };
					
					//Fix for Multimaps suport anchor By SigWar
					//Need add "center" mark on center of the map in editor
					_mapaatual = worldName;
					switch (_mapaatual) do {
						
						/*default { _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };*/
						case "Stratis": { _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };		
						case "Bornholm": { _centerMap = getMarkerPos "center"; _nearestRadius = 10000; };
						case "Esseker": { _centerMap = getMarkerPos "center";  _nearestRadius = 6000; };
						case "Altis": { _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };
						case "Chernarus": { _centerMap = getMarkerPos "center";  _nearestRadius = 7000; };
						case "Tanoa": {  _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };
						case "xcam_taunus": { _centerMap = getMarkerPos "center";  _nearestRadius = 10000; };
					};	
					
					_pos = [_centerMap,0,4000,10,0,2000,0] call BIS_fnc_findSafePos;
					if (count _pos < 3) then { _pos = [_pos select 0,_pos select 1,0]; };
					diag_log ("MOVED OBJ: " + str(_idKey) + " of class " + _type + " to pos: " + str(_pos));
				};
				
				
					diag_log format["OBJ: %1 - %2", _idKey,_type];
					
					//Create it
					_object = createVehicle [_type, [_pos select 0, _pos select 1, (_pos select 2) + 0.7], [], 0, "CAN_COLLIDE"];
					_object enableSimulationGlobal false;
					_object allowDamage false;
					_object setposATL [_pos select 0, _pos select 1, (_pos select 2) + 0.7];
					_object setdir _dir;
					
					/*_precise = call compile _Worldprecision;
					if (count _precise >= 2) then {
						if (count (_precise select 1) == 3) then {
							_object setVectorDirAndUp _precise;
						};
					};*/
					
					_allVehicles pushBack [_object,_damage,_hitpoints,_fuel];
												
					_object setVariable ["lastUpdate",time];
					_object setVariable ["ObjectID", _idKey, true];
					_object setVariable ["CharacterID", _ownerID, true];
					_object setVariable["ViruZMod",1];
					
					clearWeaponCargoGlobal  _object;
					clearMagazineCargoGlobal  _object;
					clearItemCargoGlobal _object;
					clearBackpackCargoGlobal _object;
					
					// Debug clear inventory in database
					if !(_debugLoadInventory) then {[_object, "gear"] spawn server_updateObject;};
					
					// Load inventory
					if ((count _intentory > 0) && _debugLoadInventory) then {
						//Add weapons
						_objWpnTypes = (_intentory select 0) select 0;
						_objWpnQty = (_intentory select 0) select 1;
						_countr = 0;					
						{
	//						if (_x == "Crossbow") then { _x = "Crossbow_DZ" }; // Convert Crossbow to Crossbow_DZ
							_isOK = 	isClass(configFile >> "CfgWeapons" >> _x);
							if (_isOK) then {
								_block = 	getNumber(configFile >> "CfgWeapons" >> _x >> "stopThis") == 1;
								if (!_block) then {
									_object addWeaponCargoGlobal [_x,(_objWpnQty select _countr)];
								};
							};
							_countr = _countr + 1;
						} forEach _objWpnTypes; 
						
						//Add Magazines
						/*
						_objWpnTypes = (_intentory select 1) select 0;
						_objWpnQty = (_intentory select 1) select 1;
						_countr = 0;
						{
	//						if (_x == "BoltSteel") then { _x = "WoodenArrow" }; // Convert BoltSteel to WoodenArrow
							_isOK = 	isClass(configFile >> "CfgMagazines" >> _x);
							if (_isOK) then {
								_block = 	getNumber(configFile >> "CfgMagazines" >> _x >> "stopThis") == 1;
								if (!_block) then {
									_object addMagazineCargoGlobal [_x,(_objWpnQty select _countr)];
								};
							};
							_countr = _countr + 1;
						} forEach _objWpnTypes;
						*/
						{
							_classMag	= _x select 0;
							_ammoCount	= _x select 1;
							_isOK		= isClass(configFile >> "CfgMagazines" >> _classMag);
							
							if (_isOK) then {
								_block = 	getNumber(configFile >> "CfgMagazines" >> _classMag >> "stopThis") == 1;
								if (!_block) then {
									_object addMagazineAmmoCargo [_classMag, 1, _ammoCount];
								};
							};
						} forEach (_intentory select 1);
						
						//Add Items
						_objWpnTypes = (_intentory select 2) select 0;
						_objWpnQty = (_intentory select 2) select 1;
						_countr = 0;					
						{
							_isOK = 	isClass(configFile >> "CfgWeapons" >> _x);
							if (_isOK) then {
								_block = 	getNumber(configFile >> "CfgWeapons" >> _x >> "stopThis") == 1;
								if (!_block) then {
									_object addItemCargoGlobal [_x,(_objWpnQty select _countr)];
								};
							};
							_countr = _countr + 1;
						} forEach _objWpnTypes; 

						//Add Backpacks
						_objWpnTypes = (_intentory select 3) select 0;
						_objWpnQty = (_intentory select 3) select 1;
						_countr = 0;
						{
							_isOK = 	isClass(configFile >> "CfgVehicles" >> _x);
							if (_isOK) then {
								_block = 	getNumber(configFile >> "CfgVehicles" >> _x >> "stopThis") == 1;
								if (!_block) then {
									_object addBackpackCargoGlobal [_x,(_objWpnQty select _countr)];
								};
							};
							_countr = _countr + 1;
						} forEach _objWpnTypes;
					};	
				};
				if !(parseNumber _idKey in arrayObjectID) then {
					arrayObjectID set [count arrayObjectID, parseNumber _idKey];
				};
		
		} forEach _myArray;
		sleep 60;

		{
			_object = _x select 0;
			_damage = _x select 1;
			_hitpoints = _x select 2;
			_fuel = _x select 3;
			
			_object enableSimulationGlobal true;
			_object allowDamage true;
			_object setDamage _damage;
			
			{
				_selection = _x select 0;
				_dam = _x select 1;
				if (_dam > 0.7) then {_dam = 0.7};
				[_object,_selection,_dam] call object_setFixServer;
			} forEach _hitpoints;
			
			//_object setvelocity [0,0,1];
			_object setFuel _fuel;
			_object call fnc_vehicleEventHandler;
			
		}forEach _allVehicles;
		
		//allowConnection = true;
		//"susenha" serverCommand "#unlock";