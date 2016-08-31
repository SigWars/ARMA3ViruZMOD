/*
	Althor: SteelRat
	Modified by: SigWar
*/

Private ["_class","_unit","_magazinesAmmo","_return"];

_class			= _this select 0;
_unit			= _this select 1;
_magazinesAmmo	= magazinesAmmo _unit;
_return			= [];

{
	if (_class == _x select 0) then {
		_return SET [count _return, _x];
	};
} forEach _magazinesAmmo;

// Учёт пустых магазинов
{
	if (_x select 0 == _class) then {
		_return set [count _return, _x];
	};
} forEach (_unit call PTm_fnc_getMagazinesEmpty);

_return