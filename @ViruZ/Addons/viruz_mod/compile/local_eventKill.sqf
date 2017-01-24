//[unit, selectionName, damage, source, projectile]
/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_zed","_killer","_kills","_array","_type"];

_array = 		_this select 0;
_zed = 			_array select 0;
_killer = 		_array select 1;
_type = 		_this select 1;

if (local _zed) then {
	_kills = _killer getVariable[_type,0];
	_killer setVariable[_type,(_kills + 1),true];
};