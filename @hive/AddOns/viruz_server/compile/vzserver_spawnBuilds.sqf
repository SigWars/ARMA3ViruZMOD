/*
	ViruZ Mod for Arma 3
	vzserver_spawnBuilds.sqf
	Autor: SigWar
	Load database entryes and trow Builds in world.
	http://www.viruzmod.com
*/
private ["_myArray","_debugLoadInventory","_countr","_idKey","_type","_ownerID","_worldspace","_inventory","_hitPoints","_fuel","_damage","_objectID","_OwnerUID","_Locked",
"_LastFix","_Worldprecision","_dateNow","_dateFix","_passedDays","_dir","_pos","_centerMap","_wsDone","_mapaatual","_object","_objWpnTypes","_objWpnQty","_isOK","_block","_classMag","_ammoCount","_selection","_dam"];

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
			_inventory =	_x select 5;
			_hitPoints =	_x select 6;
			_fuel =			_x select 7;
			_damage = 		_x select 8;
			_objectID = 	_x select 9;
			_OwnerUID =		_x select 10;
			_Locked =		_x select 11;
			_LastFix = 		_x select 12;
			_Worldprecision = _x select 13;
						
			if (_damage < 1 and (_type in _Structures)) then {
				
				_passedDays = 0;
				if ( _type in _Structures and _LastFix != "[]" ) then {
					_dateNow = call compile ("real_date" callExtension ""); //need real_date.dll to work THX to KillzoneKid
					_dateFix = call compile _LastFix;
					_passedDays = [_dateFix,_dateNow] call VZ_func_subDate;
					
					if (ViruzDebugMode > 2 or ViruzDebugType == "MAINTAIN" or ViruzDebugType == "BUILD") then 
					{
						diag_log format["OBJ: %1 DATEFIX %2 DATENOW %3 PASSEDDAYS %4", _type,_dateFix,_dateNow,_passedDays];
					};	
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
					switch (toLower _mapaatual) do {
						
						/*default { _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };*/
						case "stratis": { _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };		
						case "bornholm": { _centerMap = getMarkerPos "center"; _nearestRadius = 10000; };
						case "esseker": { _centerMap = getMarkerPos "center";  _nearestRadius = 6000; };
						case "altis": { _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };
						case "chernarus": { _centerMap = getMarkerPos "center";  _nearestRadius = 7000; };
						case "tanoa": { _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5;  };
						case "xcam_taunus": { _centerMap = getMarkerPos "center";  _nearestRadius = 20000; };
						default { _centerMap = getMarkerPos "center";  _nearestRadius = 20000; };
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
							if (_type == "Land_Portable_generator_F") then {
								_object setVariable ["lastFix", _dateFix, true];
							};
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
					if ((count _inventory > 0) && _debugLoadInventory) then {
						
						//Adds weapons and their attachments in holder
						private _weaponArray = _inventory select 0;
						_countr = 0;
						{ 
							private _wpType = _x select 0; 
							if !(isNil "_wpType") then
							{ 
								_isOK = isClass(configFile >> "CfgWeapons" >> _wpType);
								if (_isOK) then 
								{
									_object addWeaponCargoGlobal [_wpType,1];
								};
							};	
								 
							private _wpSupressor = _x select 1; 
							if !(isNil "_wpSupressor") then
							{  
								_object addItemCargoGlobal [_wpSupressor,1]; 
							}; 
								
							private _wpLaser = _x select 2; 
							if !(isNil "_wpLaser") then
							{ 
								_object addItemCargoGlobal [_wpLaser,1]; 
							}; 
								
							private _wpOptic = _x select 3; 
							if !(isNil "_wpOptic") then
							{ 
								_object addItemCargoGlobal [_wpOptic,1]; 
							}; 
								
							//Magazine attached on Weapon
							private _wpnAttachmag = _x select 4;
							if (count _wpnAttachmag > 1) then 
							{
								private _wpnMag = _wpnAttachmag select 0;
								private _wpnAmmo = _wpnAttachmag select 1;
								if !(isNil "_wpnMag") then  
								{
									_object addMagazineAmmoCargo [_wpnMag,1,_wpnAmmo]; 
								};
							};
														
							//Bipod & blow ammo attached on Weapon
							private _wpBipod = _x select 5;
							if (count _wpBipod > 0) then 
							{ 
								if (typeName _wpBipod == "STRING") then 
								{
									_object addItemCargoGlobal [_wpBipod,1];
								};
								
								if (typeName _wpBipod == "ARRAY") then 
								{
									private _wpMag2 = _wpBipod select 0;
									private _wpAmmo2 = _wpBipod select 1;
									if !(isNil "_wpMag2") then  
									{
										_object addMagazineAmmoCargo [_wpMag2,1,_wpAmmo2]; 
									};
								};
							};
							_countr = _countr + 1;
						} forEach _weaponArray;
												
						//Add Others Magazines	in holder				
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
						} forEach (_inventory select 1);
						
						//Add Others Items in holder
						_objWpnTypes = (_inventory select 2) select 0;
						_objWpnQty = (_inventory select 2) select 1;
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

						/*********************************************************
						* PROCESS BACKPACKS AND THEIR CONTENTS STORED IN HOLDERS *
						**********************************************************/
						private _backpackArrayRaiz = _inventory select 3;
						{
							//_x = Mochila
							
							//Esta parte somente adiciona a Mochila/Vest/Uniform
							private _bpType = _x select 0;
							if !(isNil "_bpType") then
							{ 
								
								private _isBackPack = getText(configfile >> "CfgVehicles" >> _bpType >> "vehicleClass") == "BackPacks";
								if (_isBackPack) then {
									_isOK = 	isClass(configFile >> "CfgVehicles" >> _bpType);
									if (_isOK) then 
									{
										_object addBackpackCargoGlobal [_bpType,1];
									};
								};
							};
							
							//Esta parte somente adiciona as armas e os os ataches que estavam nela!
							private _bpWeaponArray = _x select 1; //Array com todas as armas dentro da backpack e seus ataches
							{
								//_x = Arma
								private _wpType = _x select 0;
								if !(isNil "_wpType") then 
								{ 
									_isOK = isClass(configFile >> "CfgWeapons" >> _wpType);
									if (_isOK) then 
									{
										_object addWeaponCargoGlobal [_wpType,1];
									};
								};
								
								//Supressor attached on Weapon
								private _wpSupressor = _x select 1;
								if !(isNil "_wpSupressor") then 
								{ 
									_object addItemCargoGlobal [_wpSupressor,1]; 
								};
								
								//Laser,Flashlight attached on Weapon
								private _wpLaser = _x select 2;
								if !(isNil "_wpLaser") then 
								{ 
									_object addItemCargoGlobal [_wpLaser,1]; 
								};
								
								//optic attached on Weapon
								private _wpOptic = _x select 3;
								if !(isNil "_wpOptic") then  
								{ 
									_object addItemCargoGlobal [_wpOptic,1]; 
								};
								
								//Magazine attached on Weapon
								private _weaponAttachmag = _x select 4;
								if (count _weaponAttachmag > 1) then 
								{
									private _wpMag = _weaponAttachmag select 0;
									private _wpAmmo = _weaponAttachmag select 1;
									if !(isNil "_wpMag") then  
									{
										_object addMagazineAmmoCargo [_wpMag,1,_wpAmmo]; 
									};
								};
								
								//Bipod & blow ammo attached on Weapon
								private _wpBipod = _x select 5;
								if (count _wpBipod > 0) then 
								{ 
									if (typeName _wpBipod == "STRING") then 
									{
										_object addItemCargoGlobal [_wpBipod,1];
									};
									
									if (typeName _wpBipod == "ARRAY") then 
									{
										private _wpMag2 = _wpBipod select 0;
										private _wpAmmo2 = _wpBipod select 1;
										if !(isNil "_wpMag2") then  
										{
											_object addMagazineAmmoCargo [_wpMag2,1,_wpAmmo2]; 
										};
									};
								};
								
							}forEach _bpWeaponArray;
							
							//Esta parte somente adiciona todos os magazines que não estvam atachados na arma mas estavam dentro da mochila
							private _bpMagsArray = _x select 2;
							{
								//_x = Magazine
								_classMag	= _x select 0;
								_ammoCount	= _x select 1;
								_isOK		= isClass(configFile >> "CfgMagazines" >> _classMag);
								
								if (_isOK) then {
									_block = 	getNumber(configFile >> "CfgMagazines" >> _classMag >> "stopThis") == 1;
									if (!_block) then {
										_object addMagazineAmmoCargo [_classMag, 1, _ammoCount];
									};
								};
							
							}forEach _bpMagsArray;
							
							//Esta parte somente adiciona todos os items que não estavam atachados na arma mas estavam dentro da mochila
							private _bpItemsArray = _x select 3;
							_objWpnTypes = _bpItemsArray select 0; 
							_objWpnQty = _bpItemsArray select 1; 
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
												
						} forEach _backpackArrayRaiz;
						
					};	
				
				//viruz_serverObjectMonitor set [count viruz_serverObjectMonitor,_object];
			};
			
			arrayObjectID set [count arrayObjectID, parseNumber _idKey];
		} forEach _myArray;