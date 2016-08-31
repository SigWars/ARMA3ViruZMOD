/*
	Author: SigWar
*/

private ["_objects","_magazineArray","_max","_val","_item","_magazinesEmpty","_index"];

_magazines = magazinesAmmoFull player;
_magazineArray = [];
{
	_max = 	getNumber (configFile >> "CfgMagazines" >> (_x select 0) >> "count");
	_val = _x select 1;
	
	if (_val != _max) then {
		_magazineArray set [count _magazineArray,[_x select 0, _x select 1]];
	} else {
		_magazineArray set [count _magazineArray, _x select 0];
	};	
} forEach _magazines;

_items = (uniformItems player) + (vestItems player) + (backpackItems player);
{
	_isOK = isClass(configFile >> "CfgMagazines" >> _x); 
	if (!_isOK) then {
		_magazineArray set [count _magazineArray, _x];
	};
} forEach _items;

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
		_magazineArray set [count _magazineArray, [_x, 0]];
	};
} forEach _magazinesEmpty;

viruz_Magazines=_magazineArray;
_magazineArray