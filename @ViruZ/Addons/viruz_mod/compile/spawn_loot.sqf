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
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
	};
	
	case "item": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
	};
	// end of basic class
	
	/////////////////////////////////////////////////////////////////////////////////
	//Lixo
	case "Trash": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	
	////////////////////////////////////////////////////////////////////////////////
	//Bebidas
	case "Drink": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	
	////////////////////////////////////////////////////////////////////////////////
	//Comidas
	case "Food": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
		
	////////////////////////////////////////////////////////////////////////////////
	//Loot básico casas
	case "Basic_Items": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	////////////////////////////////////////////////////////////////////////////////
	//Loot casas
	case "Houseware_Items": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Eletronic_Items": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};	
	////////////////////////////////////////////////////////////////////////////////
	//Loot escritório/escola
	case "Office_Items": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};

	////////////////////////////////////////////////////////////////////////////////
	//Loot básico de sobrevivência
	case "Basic_Survival": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};

	////////////////////////////////////////////////////////////////////////////////
	//Loot itens de sobrevivência
	case "Survival_Items": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};

	////////////////////////////////////////////////////////////////////////////////
	//Materiais
	case "Materials": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
				
	////////////////////////////////////////////////////////////////////////////////
	//Ferramentas
	case "Tools": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
		
	////////////////////////////////////////////////////////////////////////////////
	//Peças veículos
	case "CarParts": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "HeliParts": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
/*	case "BikeParts": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
*/		
	////////////////////////////////////////////////////////////////////////////////
	//Médicos
	
	case "Medical_Lite": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Medical_Special": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
		
	////////////////////////////////////////////////////////////////////////////////
	//Mochilas
	
	case "Boat_Backpacks": {
		_item addBackpackCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Light_Backpacks": {
		_item addBackpackCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Medium_Backpacks": {
		_item addBackpackCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Heavy_Backpacks": {
		_item addBackpackCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	
	////////////////////////////////////////////////////////////////////////////////
	//Roupas
	
	case "Civilian_Glasses": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Civilian_Clothes": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Civilian_Vests": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Civilian_Special": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Civilian_Headgear": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Military_Glasses": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Military_Clothes": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Military_Vests": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Military_Armor": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Military_Headgear": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Military_Helmet": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Military_Gear_Special": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	
	////////////////////////////////////////////////////////////////////////////////
	//Granadas de Mão
	
	case "Offensive_Grenades": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};	
	case "Smoke_Grenades": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Flare_Grenades": {
		//Item is one magazine
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};		
	////////////////////////////////////////////////////////////////////////////////
	//Lanternas
	case "Flashlights": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};

	////////////////////////////////////////////////////////////////////////////////
	//Pistolas e Munições
	case "Pistols_Low": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "Mag_Pistols_Low": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Attach_Pistols_Low": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Pistols_Low_Special": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "Pistols_High": {
		[_item, _iClass] call _fnc_SpawnWeapon;
		_item setVariable ["looted",_dateNow,true];
		};
	case "Mag_Pistols_High": {
		_item addMagazineCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Attach_Pistols_High": {
		_item addItemCargoGlobal [(_iClass call _fnc_SelectType),1];
		_item setVariable ["looted",_dateNow,true];
		};
	case "Pistols_High_Special": {
		[_item, _iClass] call _fnc_SpawnWeapon;
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
	//objetos
	case "object": {
		_item = createVehicle [_iItem, _iPos, [], _radius, "CAN_COLLIDE"];
		};
};

if (_zPos) then {
	_item setPosATL _iPos;
};
