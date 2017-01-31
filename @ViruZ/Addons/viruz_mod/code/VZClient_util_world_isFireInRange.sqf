/*
    File: VZClient_util_world_isFireInRange.sqf
    Atuthor: Mateus "Mateuus" Rodrigues
	
	Licence: 
	ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
	
    Description:
	Verificar se a fogueira está ativa
*/

private["_position","_range","_isInRange"];
_position = _this select 0;
_range = _this select 1;
_isInRange = false;
{
	if (inflamed _x) exitWith
	{
		_isInRange = true;
	};
}
forEach (_position nearObjects _range);
_isInRange