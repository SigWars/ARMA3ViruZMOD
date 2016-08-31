/*
	Author: SteelRat
*/

params["_zmb"];

if !(local _zmb) exitWith {false};

_class = typeOf _zmb;
_equip = if (isClass (configFile >> "CfgZombieEquip" >> _class)) then {configFile >> "CfgZombieEquip" >> _class} else {configFile >> "CfgVehicles" >> _class >> "Equip"};
_equipData = [];

_uniform = (_equip >> "uniform") call BIS_fnc_getCfgData;
_uniform set [0, ((configFile >> "CfgVehicles" >> _class >> "uniformClass") call BIS_fnc_getCfgData)];
_equipData pushBack  _uniform;

{
	_equipData pushBack ((_equip >> _x) call BIS_fnc_getCfgData);
} forEach ["vest", "backpack", "headgear", "goggles", "binocular", "primaryWeapon", "secondaryWeapon", "handgunWeapon", "linkedItems"];

[
	_zmb,
	[_equipData],
	(_equip >> "ignored") call BIS_fnc_getCfgData
] call BIS_fnc_loadInventory;

//_zmb setDamage 0.4;
