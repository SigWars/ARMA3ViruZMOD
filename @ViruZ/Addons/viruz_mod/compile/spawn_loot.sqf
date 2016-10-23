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

_fnc_CheckHolder = {
	private ["_item","_iClass","_weaponsInside","_magsInside","_itemsInside","_weaponCount","_magsCount","_itemsCount","_minLoot"];
	_item = _this select 0;
	_iClass = _this select 1;
	_full = false;
	
	_weaponsInside = weaponCargo _item;
	if (isNil {_weaponsInside select 0}) then {_weaponCount = 0; } else {_weaponCount = Count _weaponsInside;};
	//if (_weaponCount >= 2 and _iClass in ["weapon","melee_lite","melee_especial","pistol_lite","pistol_especial","weapons_lmg","weapons_smg","weapons_rifle","snipe_drm","snipe_especial"]) then { _full = true; };

	_magsInside = magazineCargo _item;
	if (isNil {_magsInside select 0}) then {_magsCount = 0; } else {_magsCount = Count _magsInside;};
	//if (_magsCount >= 5 and _iClass in ["magazine","furniture_food","furniture_medical","medical_lite","medical_especial","mag_pistol_lite","mag_pistol_especial","magazine_lmg","magazine_smg","magazine_rifle","magazine_dmr","magazine_sniper"]) then { _full = true; };

	_itemsInside = itemCargo _item;
	if (isNil {_itemsInside select 0}) then {_itemsCount = 0; } else {_itemsCount = Count _itemsInside;};
	//if (_itemsCount >= 3 and _iClass in ["item","items_lite","uniform_civilian","uniform_military","headgear_civilian","headgear_military","glasses_civilian","glasses_military"]) then { _full = true; };
	_minLoot = + _weaponCount + _magsCount + _itemsCount;
	if (_minLoot >= 3 ) then { _full = true; };
	
	_full
};

// timestamp for later clearing
_dateNow = (DateToNumber date);

_iItem = 	_this select 0; //PRIMEIRA "PRIMEIRA"," " DA ItemTypes - Classe do Item
_iClass = 	_this select 1;	//SEGUNDA " ","SEGUNDA"	DA ItemTypes - Typo de Item - Weapon - MagaZine - Item - Mochila - Object - Ou classes especificas
_iPos =	(_this select 2) select 0; // Posição onde Spawnar
_zPos =	(_this select 2) select 1; // Confirma se a posição e em um holder e seta o posição
_radius =	_this select 3; // Distancia
_full = false;

switch (_this select 4) do { 
	case "GroundWeaponHolder": { //Cria um holder para spawnar se nao existir
		if !(_iClass == "object") then {
			_item = createVehicle ["GroundWeaponHolder", _iPos, [], _radius, "CAN_COLLIDE"];
			_full = false;
		};
	};
	case "objectHolder": { //Checa se é um Holder e usa ele para spawnar os items
		// WeaponBox
		_item = _this select 5;
		_full = [_item,_iClass] call _fnc_CheckHolder;
	};
	//default {};
};


if !(_full) then {

	switch (_iClass) do {

	
	
	/*default {
		
//		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
	
		//Item is food, add random quantity of cans along with an item (if exists)
		_itemTypes = [] + ((getArray (missionConfigfile >> "cfgLoot" >> _iClass)) select 0);
		_index = viruz_CLBase find _iClass;
		_weights = viruz_CLChances select _index;
		_cntWeights = count _weights;
		_qty = 0;
		_max = round(random 1) + 1;
		while {_qty < _max} do {
			_tQty = round(random 1) + 1;
			_index = floor(random _cntWeights);
			_index = _weights select _index;
			_canType = _itemTypes select _index;
			_item addMagazineCargoGlobal [_canType, _tQty];
			_qty = _qty + _tQty;
		};
		if (_iItem != "") then {
			_item addWeaponCargoGlobal [_iItem,1];
		};
		
	};*/
	//Varejo
	
	////////////////////////////////////////////////////////////////////////////////
	//  VIRUZ NEW SPAWN LOOT
	//  Descrição: Cada loot vai ter sua regiação certa de Spawn
	//
	////////////////////////////////////////////////////////////////////////////////
	
	/////////////////////////////////////////////////////////////////////////////////
	//
	case "weapon": {
		//Item is a weapon, add it and a random quantity of magazines
		_item addWeaponCargoGlobal [_iItem,1];
		_mags = [] + getArray (configFile >> "cfgWeapons" >> _iItem >> "magazines");
		if ((count _mags) > 0) then {
			_item addMagazineCargoGlobal [(_mags select 0), (round(random 2))];
		};
		_item setVariable ["looted",_dateNow,true];
		};
	
	/////////////////////////////////////////////////////////////////////////////////
	//Lixo
	case "trash": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	
	////////////////////////////////////////////////////////////////////////////////
	//Bebidas
	case "Bebidas": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	
	////////////////////////////////////////////////////////////////////////////////
	//Comidas
	case "Comidas": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
		
	////////////////////////////////////////////////////////////////////////////////
	//CraftItens
	case "CraftItens": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	////////////////////////////////////////////////////////////////////////////////
	//CraftBuildItens
	case "CraftBuildItens": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	
	////////////////////////////////////////////////////////////////////////////////
	//Items_Magazine
	case "Items_Magazine": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
		
	////////////////////////////////////////////////////////////////////////////////
	//Ferramentas
	case "Ferramentas": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
		
	////////////////////////////////////////////////////////////////////////////////
	//Perças para Carros e Heli (Futuro = Separado os 2 Carro e Heli)
	case "CarParts": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	
	////////////////////////////////////////////////////////////////////////////////
	//Medical
	
	case "Medical_Lite": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Medical_Especial": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
		
	////////////////////////////////////////////////////////////////////////////////
	//Mochilas Classe
	
	case "Boat_Backpack": {
		_item addBackpackCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "MochilasLow": {
		_item addBackpackCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "MochilasMedias": {
		_item addBackpackCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "MochilasHigh": {
		_item addBackpackCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	
	////////////////////////////////////////////////////////////////////////////////
	//Roupas Classes
	
	case "RoupasLow": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "RoupasUpper": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "RoupasMilitares": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	
	
	////////////////////////////////////////////////////////////////////////////////
	//Granadas de Mão
	
	case "trow": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};	
		
	////////////////////////////////////////////////////////////////////////////////
	//Pistolas Classes e Munições
	case "PistolasLow": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "Mag_PistolasLow": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
		
	case "PistolasMedias": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "Mag_PistolasMedias": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
		
	case "PistolasHigh": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	
	case "Mag_PistolasHigh": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};

	////////////////////////////////////////////////////////////////////////////////
	//Armas Civis e Munições
	case "ArmasCivis": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "Mag_ArmasCivis": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};

	
	////////////////////////////////////////////////////////////////////////////////
	//ArmasLow e Munições
	case "ArmasLow": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "Mag_ArmasLow": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	////////////////////////////////////////////////////////////////////////////////
	//ArmasMedias e Munições
	case "ArmasMedias": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "Mag_ArmasMedias": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	////////////////////////////////////////////////////////////////////////////////
	//ArmasHigh e Munições
	case "ArmasMedias": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "Mag_ArmasHigh": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	////////////////////////////////////////////////////////////////////////////////
	//Miras e Acessorios
	case "Acessorios_Optic": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};		
	
	/*
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
		
	case "trash": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Parts": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "trow": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};	
	case "ferramentas": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	//Furniture
	case "furniture_food": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "food": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "drink": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "furniture_medical": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	//Medical
	case "medical_lite": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "medical_especial": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "melee_lite": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "melee_especial": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "pistol_lite": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "pistol_especial": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "weapons_lmg": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	//Weapons
	case "weapons_smg": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "weapons_rifle": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "snipe_drm": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "snipe_especial": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	//magazines
	case "mag_pistol_lite": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "mag_pistol_especial": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "magazine_lmg": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "magazine_smg": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "magazine_rifle": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "magazine_dmr": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "magazine_sniper": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	//items
	case "items_item": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "items_magazine": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "backpack": {
		_item addBackpackCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "backpack_leves": {
		_item addBackpackCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "boat_backpack": {
		_item addBackpackCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	//roupas
	case "uniform_civilian": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "uniform_military": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "headgear_civilian": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "headgear_military": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "glasses_civilian": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "glasses_military": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};*/
	//objetos
	case "object": {
		_item = createVehicle [_iItem, _iPos, [], _radius, "CAN_COLLIDE"];
		};
	};

if (_zPos) then {
	_item setPosATL _iPos;
};

};//checka se esta full