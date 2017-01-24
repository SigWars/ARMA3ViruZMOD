/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private ["_config","_typeBox","_arrayAmmoBox","_arrayMagazines","_resultMagazines","_resultAmmoBox","_countReammoMagazines","_maxMag","_valMag","_typeMag","_ammoMag","_typeAmmoBox","_ammoAmmoBox","_valAmmoBox","_diff","_flag","_text","_item","_magazinesEmpty","_index"];

_config = configFile >> "cfgMagazines";
_typeBox = getText(_config >> _this >> "typeBox");
_arrayAmmoBox = [];
_arrayMagazines = [];
_resultMagazines = [];
_resultAmmoBox = [];
_countReammoMagazines = 0;

switch _typeBox do {
	default {
		systemChat format["%1", "Magazine"];
	};
	case "AmmoBox": {
	// Снарядить патронами все магазины в инвенторе		
		{
			if (getText(_config >> (_x select 0) >> "typeBox") == "AmmoBox") then {
				_arrayAmmoBox SET [count _arrayAmmoBox, _x];
			} else {
				_arrayMagazines SET [count _arrayMagazines, _x];
			};
		} forEach (magazinesAmmoFull player);
		
		// Добавить в массив _arrayMagazines пустые магазины
		_items = (uniformItems player) + (vestItems player) + (backpackItems player);
		_magazinesEmpty = [];
		{
			_isOK = isClass(configFile >> "CfgMagazines" >> _x);
			if (_isOK) then {
				_magazinesEmpty set [count _magazinesEmpty, _x];
			};
		} forEach _items;
		{
			if (typeName _x == "ARRAY") then {
				_item = _x select 0;
			} else {
				_item = _x;
			};
			_index = _magazinesEmpty find _item;
			if (_index != -1) then {
				_magazinesEmpty SET [_index, ""];
			};
		} forEach magazines player;
		{
			if (_x != "") then {
				_arrayMagazines set [count _arrayMagazines, [_x, 0]];
			};
		} forEach _magazinesEmpty;
		
		if (count _arrayAmmoBox > 0) then {
		
			{
				_resultAmmoBox SET [count _resultAmmoBox,[_x select 0, _x select 1]];
			} forEach _arrayAmmoBox;
		
			{
			
				_typeMag = _x select 0;
				_ammoMag = getText (_config >> _typeMag >> "ammo");
				_maxMag = 	getNumber (_config >> _typeMag >> "count");
				_valMag = _x select 1;
				_flag = true;
			
				if (_valMag != _maxMag) then {
					_diff = _maxMag - _valMag;
					
					for "_i" from 0 to ((count _resultAmmoBox) - 1) do {
						if (_flag) then {
							_valAmmoBox = (_resultAmmoBox select _i) select 1;
							if (_valAmmoBox > 0) then {
								_typeAmmoBox = (_resultAmmoBox select _i) select 0;
								_ammoAmmoBox = getText (_config >> _typeAmmoBox >> "ammo");							
								if (_ammoMag == _ammoAmmoBox) then {
									if ((_valAmmoBox - _diff) < 0) then {
										_diff = _diff - abs(_valAmmoBox - _diff);
									};
									_resultMagazines SET [count _resultMagazines, [_typeMag, (_valMag +_diff)]];
									_resultAmmoBox SET [_i,[_typeAmmoBox,(_valAmmoBox - _diff)]];
									_countReammoMagazines = _countReammoMagazines + 1;
									_flag = false;
								};
							};
						};
					};
					
					if (_flag) then {
						_resultMagazines SET [count _resultMagazines, [_typeMag, _valMag]];
					};
					
				} else {
				
					_resultMagazines SET [count _resultMagazines, [_typeMag, _maxMag]];
					
				};
			
			} forEach _arrayMagazines;
			
			if (_countReammoMagazines > 0) then {
			
				{player removeMagazine (_x select 0);} forEach  _arrayMagazines;
				{player removeMagazine (_x select 0);} forEach  _arrayAmmoBox;
				{player addMagazine [_x select 0,_x select 1];} forEach  _resultMagazines;
				{player addMagazine [_x select 0,_x select 1];} forEach  _resultAmmoBox;
				
				_text = format["%1: %2", "You add ammo in magazines", _countReammoMagazines];
//				_text = format["%1: %2", localize "Вы снарядили магазинов патронами", _countReammoMagazines];
				cutText [_text, "PLAIN DOWN"];	
			};
			
		} else {
			_text = format["%1", "You no ammo"];
//			_text = format["%1", localize "У вас нет патронов, что бы снарядить магазины"];
			cutText [_text, "PLAIN DOWN"];
		};
	};
};