/*
	Author: SteelRat
*/

private["_ret", "_moves"];
params["_unit", "_type"];
	
_ret	= [];
_moves	= getText(configFile >> "CfgVehicles" >> (typeOf _unit) >> "moves");
{_ret pushBack toLower(_x);} foreach (getArray(configFile >> "CfgZombieAnims" >> _moves >> _type));
_ret