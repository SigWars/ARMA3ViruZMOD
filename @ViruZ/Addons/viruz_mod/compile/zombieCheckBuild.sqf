/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private ["_buildings","_agent","_build","_i"];
_buildings = objNull;
_agent = _this;
_i = 0;
_buildings = nearestObjects [_agent,["House_F","House"],15];

if (_i > ((count _buildings) - 1)) exitWith {
		_isInside = false;
};

_build = _buildings select 0;
_isInside = [_agent,_build] call fnc_isInsideBuilding;

_isInside