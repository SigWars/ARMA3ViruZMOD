/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_unit","_ammo","_audible","_distance","_listTalk","_weapon","_projectile","_vUp","_endPos","_dir","_height","_bolt","_hitArray","_hitObject","_hitSelection","_config","_hitMemoryPt","_variation","_val","_doLoop","_countr"];
_unit = 		_this select 0;
_weapon = 		_this select 1;
_ammo = 		_this select 4;
_projectile = 	_this select 6;

_projectile = nearestObject [_unit, _ammo];
_endPos = getPosATL _projectile;
_dir = 0;

_doWait = true;
while {_doWait} do {
	_vel = (velocity _projectile) distance [0,0,0];
	if (!(alive _projectile)) then {_doWait = false};	
	if (_vel < 0.1) then {_doWait = false};
	_endPos = getPosATL _projectile;
	sleep 0.01;
};

_distance = parseNumber format["%1",(getArray (configFile >> "CfgAmmo" >> _ammo >> "soundHit") select 3)];

if (_ammo isKindOf "ChemLight") then {
	_distance = 10;
};
if (_ammo isKindOf "RoadFlare") then {
	if (call world_isDay) then {
		_distance = 30;
	} else {
		_distance = 60;
	};
};

_id = [_unit,_distance,false,_endPos] spawn player_alertZombies;