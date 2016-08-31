/*
	Author: SigWar
	
	Description:
	This function return all available positions of a building defined in model, if any
	
	Parameter(s):
	_this select 0:	OBJECT	- The building object
	_this select 1:	NUMBER	- The maximum number of positions to return
	
	Returns:
	ARRAY - List of all available positions within building
*/

params[
	["_building", objNull, [objNull]],
	["_max", 99, [0]]
];

private["_checkPos", "_buildingPos"];

_checkPos = [];
_buildingPos = [];

for "_i" from 0 to (_max - 1) do {
	_checkPos = _building BuildingPos _i;
	if (str(_checkPos) == "[0,0,0]") exitWith {};
	_buildingPos pushBack _checkPos;
};
	
_buildingPos