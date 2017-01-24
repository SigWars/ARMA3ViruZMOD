/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_iItem","_iClass","_iPos","_zPos","_radius","_itemTypes","_index","_item","_qty","_max","_tQty","_canType","_weights","_cntWeights","_dateNow"];

_fnc_SpawnWeapon = {
	_Weapon = (_this select 1) call _fnc_SelectType;
	(_this select 0)  addWeaponCargoGlobal [_Weapon, 1];
	_mags = [] + getArray (configFile >> "cfgWeapons" >> _Weapon >> "magazines");
	if ((count _mags) > 0) then {
		(_this select 0) addMagazineCargoGlobal [(_mags select 0), (round(random 2))];
	};
};
_fnc_SelectType = {
	_itemTypes = [] + ((getArray (missionConfigfile >> "cfgLoot" >> _this)) select 0);
	_index = viruz_CLBase find _iClass;
	_weights = viruz_CLChances select _index;
	_cntWeights = count _weights;
	_index = floor(random _cntWeights);
	_index = _weights select _index;
	_canType = _itemTypes select _index;
	_canType
};

// timestamp for later clearing
_dateNow = time;

_iItem = 	_this select 0; 
_iClass = 	_this select 1;	
_iPos =	(_this select 2) select 0;
_zPos =	(_this select 2) select 1;
_radius =	_this select 3; // Distancia
_full = false;

switch (_this select 4) do { 
	case "GroundWeaponHolder": { //Cria um holder para spawnar se nao existir
		if !(_iClass == "object") then {
			_item = createVehicle ["GroundWeaponHolder", _iPos, [], _radius, "CAN_COLLIDE"];
		};
	};
	case "objectHolder": { //Checa se é um Holder e usa ele para spawnar os items
		// WeaponBox
		_item = _this select 5;
	};
};


switch (_iClass) do {
	diag_log format ["_iClass = %1",_iClass];
	////////////////////////////////////////////////////////////////////////////////
	//  VIRUZ NEW SPAWN LOOT
	//  Descrição: Cada loot vai ter sua regiação certa de Spawn
	//
	////////////////////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////////////////////
	// basic class dont touch here
	case "weapon": {
		//Item is a weapon, add it and a random quantity of magazines
		_item addWeaponCargoGlobal [_iItem,1];
		_mags = [] + getArray (configFile >> "cfgWeapons" >> _iItem >> "magazines");
		if ((count _mags) > 0) then {
			_item addMagazineCargoGlobal [(_mags select 0), (round(random 2))];
		};
		_item setVariable ["looted",_dateNow,true];
	};
	
	case "magazine": {
		//Item is one magazine
		_item addMagazineCargoGlobal [_iItem,1];
		_item setVariable ["looted",_dateNow,true];
	};
	
	case "item": {
		_item addItemCargoGlobal [_iItem,1];
		_item setVariable ["looted",_dateNow,true];
	};
	case "backpack": {
		_item addBackpackCargoGlobal [_iItem ,1];
		_item setVariable ["looted",_dateNow,true];
	};
		//objetos
	case "object": {
		_item = createVehicle [_iItem, _iPos, [], _radius, "CAN_COLLIDE"];
	};
	
	case default {
		//featch item atributes and sets variables
		private _cfglootItem =  _iClass call _fnc_SelectType;
					
		if ( isClass (configFile >> "cfgWeapons" >> _cfglootItem)) then 
		{
			private _details = [_cfglootItem] call viruz_featchcfgDetails;
			private _type = _details select 4;
			
			if (_type in [131072,4096,4] ) then 
			{
				_item addItemCargoGlobal [_cfglootItem,1];
				_item setVariable ["looted",_dateNow,true];
			}
			else
			{
				
				_item addWeaponCargoGlobal [_cfglootItem,1];
				_mags = [] + getArray (configFile >> "cfgWeapons" >> _cfglootItem >> "magazines");
				
				if ((count _mags) > 0) then {
					_item addMagazineCargoGlobal [(_mags select 0), (round(random 2))];
				};
				_item setVariable ["looted",_dateNow,true];
			};
				
		}
		else
		{
			
			if ( isClass (configFile >> "cfgMagazines" >> _cfglootItem)) then 
			{
				_item addMagazineCargoGlobal [_cfglootItem,1];
				_item setVariable ["looted",_dateNow,true];
			}
			else
			{
				_BackPack = getText(configfile >> "CfgVehicles" >> _cfglootItem >> "vehicleClass") == "BackPacks";
				if (_BackPack) then 
				{
					_item addBackpackCargoGlobal [_cfglootItem ,1];
					_item setVariable ["looted",_dateNow,true];
				}
				else
				{
					_item addItemCargoGlobal [_cfglootItem,1];
					_item setVariable ["looted",_dateNow,true];
				};
			};
		};
			
	};
	// end of basic class
};

if (_zPos) then {
	_item setPosATL _iPos;
};
