/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_unit"];
_unit = _this select 0;
if (isServer) then {
	_unit addEventHandler ["local", {_this call zombie_findOwner}];
} else {
	_position = getPosATL _unit;
	_unit addEventHandler ["local", {_this call eh_zombieInit}];
};