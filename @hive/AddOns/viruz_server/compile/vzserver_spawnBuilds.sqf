/*
	ViruZ Mod for Arma 3
	vzserver_spawnBuilds.sqf
	Autor: SigWar
	Load database entryes and trow Builds in world.
	http://www.viruzmod.com
*/
private ["_myArray","_debugLoadInventory","_countr","_idKey","_idKey","_type","_ownerID","_worldspace","_intentory","_hitPoints","_fuel","_damage","_objectID","_OwnerUID","_Locked","_LastFix","_Worldprecision","_deletado","_deletado","_dir","_pos","_centerMap","_wsDone","_mapaatual","_object","_objWpnTypes","_objWpnQty","_isOK","_block","_classMag","_ammoCount","_selection","_dam"];

//Array com os dados da database
_myArray = _this select 0;

//Revisar
_construction = 		getArray(configFile >> "CfgHiveObjects" >> "Construction");

//Tendas ignoradas na worldprecision
_tendas = ["TentStorage","TentStorageDome","CamoNet_BLUFOR_big_F","CamoNet_BLUFOR_F","CamoNet_BLUFOR_open_F","Sandbag1_DZ"];

/// Debug load inventory in vehicles
_debugLoadInventory = (missionConfigFile >> "cfgGame" >> "DebugVehicleLoadInventory") call BIS_fnc_getCfgData;
if (isNil "_debugLoadInventory") then {_debugLoadInventory = true;};
if (typename _debugLoadInventory == typename "") then {_debugLoadInventory = call compile _debugLoadInventory;};

//Viruz Build system
_Structures = [];
{
	_Structures SET [count _Structures,_x select 1];
}forEach (getArray(configFile >> "CfgConstruction" >> "Structures"));

	_countr = 0;		
		{
				
			//Parse Array
			_countr = _countr + 1;
			_idKey = 		_x select 1;
			_type =			_x select 2;
			_ownerID = 		_x select 3;
			_worldspace =	_x select 4;
			_intentory =	_x select 5;
			_hitPoints =	_x select 6;
			_fuel =			_x select 7;
			_damage = 		_x select 8;
			_objectID = 	_x select 9;
			_OwnerUID =		_x select 10;
			_Locked =		_x select 11;
			_LastFix = 		_x select 12;
			_Worldprecision = _x select 13;
			_deletado = 	false;
						
			if (_damage < 1 and (_type in _Structures)) then {
				
				_passedDays = 0;
				if ( _type in _Structures and _LastFix != "[]" ) then {
					_dateNow = call compile ("real_date" callExtension ""); //need real_date.dll to work THX to KillzoneKid
					_dateFix = call compile _LastFix;
					_passedDays = [_dateFix,_dateNow] call VZ_func_subDate;
					
					//diag_log format["OBJ: %1 DATEFIX %2 DATENOW %3 PASSEDDAYS %4", _type,_dateFix,_dateNow,_passedDays];
				};
				
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
						case "Tanoa": { _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5;  };
						case "xcam_taunus": { _centerMap = getMarkerPos "center";  _nearestRadius = 10000; };
					};	
					
					_pos = [_centerMap,0,4000,10,0,2000,0] call BIS_fnc_findSafePos;
					if (count _pos < 3) then { _pos = [_pos select 0,_pos select 1,0]; };
					if (ViruzDebugMode > 2 or ViruzDebugType == "BUILD") then {
						diag_log ("MOVED OBJ: " + str(_idKey) + " of class " + _type + " to pos: " + str(_pos));
					};	
				};
				
					if (ViruzDebugMode > 2 or ViruzDebugType == "BUILD") then {
						diag_log format["OBJ: %1 - %2", _idKey,_type];
					};
					
					//Create it
					_object = createVehicle [_type, _pos, [], 0, "CAN_COLLIDE"];
					_object setVariable ["lastUpdate",time];
					_object setVariable ["ObjectID", _idKey, true];
					_object setVariable ["CharacterID", _ownerID, true];
					_object setVariable ["canDelete",true, true];
					
					clearWeaponCargoGlobal  _object;
					clearMagazineCargoGlobal  _object;
					clearItemCargoGlobal _object;
					clearBackpackCargoGlobal _object;
					
					//ViruZ Build System
					if (_type in _Structures and _passedDays > 7) then {
						if !(_type in _tendas) then {
							//[_idKey,0] call server_deleteObj;
							_object setDamage 1;
							deleteVehicle _object;
						};
					};
					
					if (_type in _Structures and _passedDays <= 7) then {
						if !(_type in _tendas) then {
						//_object setVectorDirAndUp (call compile _Worldprecision);
							_precise = call compile _Worldprecision;
							if (count _precise >= 2) then {
								if (count (_precise select 1) == 3) then {
									_object setVectorDirAndUp _precise;
								};
							};
						};
						_object setPosATL _pos;
										
						//Define variables
						if !(_ownerUID == "B" ) then {
						_ownerUID = [_ownerUID]call VZ_fnc_substr;
						_object setVariable ["OwnerUID", _ownerUID, true];
						//_object setVariable ["ViruZMod", 1, true];
						};
						
						//Check and Define locked builds
						if (_Locked == 1) then {
							_count = 6;
							for "_i" from 1 to _count do
							{
							_object setVariable [format["bis_disabled_Door_%1", _i], 1, true];
							_object setVariable [format["Door_%1_Lock", _i], "1", true];
							};
							_object setVariable ["Locked", "1", true];
						} else {
							_count2 = 6;
							for "_i" from 1 to _count2 do
							{
								_object setVariable [format["Door_%1_Lock", _i], "0", true];
							};
							_object setVariable ["Locked", "0", true]; 
						};
										
						_object setVariable["ViruZMod",1];			
					};
					
					if (_type in _construction) then {
						_pos set [2,0];
						_object setpos _pos;
						_object addMPEventHandler ["MPKilled",{_this call vehicle_handleServerKilled;}];
					};
					
					//set direction of objects are not structures
					if !(_type in _Structures) then {
						_object setdir _dir;
					};
					
					//set damage for objects
					_object setDamage _damage;
									
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
				
				//viruz_serverObjectMonitor set [count viruz_serverObjectMonitor,_object];
			};
			
			arrayObjectID set [count arrayObjectID, parseNumber _idKey];
		} forEach _myArray;