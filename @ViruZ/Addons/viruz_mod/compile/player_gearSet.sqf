/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_unit","_inventory"];

_unit		= _this select 0;
_inventory	= _this select 1;
_debug		= false;

if (count _inventory < 10) then {
	_inventory = [
		["", []],
		["", []],
		["", []],
		"",
		"",
		"",
		["", [], ""],
		["", [], ""],
		["", [], ""],
		[]
	];
};

if (_debug) then {
	diag_log format ["DEBUG: player_gearSet: %1: %2", _unit, _inventory];
};

[_unit, [_inventory]] call PTm_fnc_loadInventory; //working
//[_unit, [_inventory]] call BIS_fnc_loadInventory;