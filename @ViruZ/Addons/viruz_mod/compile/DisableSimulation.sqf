/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private ["_objectS","_object"];

_objectS = _this select 0;

for "_i" from 0 to ((count _objectS) - 1) do {

	_object = _objectS select _i;
	_object allowDammage false;
	_object disableAI "FSM";
	_object disableAI "ANIM";
	_object disableAI "MOVE";
	_object enableSimulation false;

};
