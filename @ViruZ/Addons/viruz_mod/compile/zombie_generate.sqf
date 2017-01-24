﻿/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_position","_doLoiter","_unitTypes","_isNoone","_loot","_array","_agent","_type","_radius","_method","_nearByPlayer","_attempt","_myDest","_newDest","_lootType"];
_position = 	_this select 0;
_doLoiter = 	_this select 1;
_unitTypes = 	_this select 2;

if (viruz_maxCurrentZeds > viruz_maxZeds) exitwith {};
if (viruz_CurrentZombies > viruz_maxGlobalZombies) exitwith {}; 
if (viruz_spawnZombies > viruz_maxLocalZombies) exitwith {}; 

_isNoone = 	{isPlayer _x} count (_position nearEntities [["AllVehicles","CAManBase"],30]) == 0;
_loot = 	"";
_array = 	[];
_agent = 	objNull;

//Exit if a player is nearby
if (!_isNoone) exitWith {};

if (count _unitTypes == 0) then {
	_unitTypes = 	[]+ getArray (missionConfigfile >> "CfgBuildingLoot" >> "Default" >> "zombieClass");
};
_type = _unitTypes call BIS_fnc_selectRandom;

//Create the Group and populate it
//diag_log ("Spawned: " + _type);
_radius = 0;
_method = "CAN_COLLIDE";
if (_doLoiter) then {
	//_radius = 40;
	_method = "NONE";
};

// randomizer
if (count(getArray(configFile >> "CfgVehicles" >> _type >> "randomizer")) > 0) then {
	_type = getArray(configFile >> "CfgVehicles" >> _type >> "randomizer") call BIS_fnc_selectRandom;
};

//diag_log ("Spawned: " + str([_type, _position, [], _radius, _method]));
_agent = createAgent [_type, _position, [], _radius, _method];

if (_doLoiter) then {
	_agent setVariable ["doLoiter",true,true];
} else {
	_agent setPosATL _position;
	_agent setVariable ["doLoiter",true,true];
};

viruz_spawnZombies = viruz_spawnZombies + 1;

//diag_log ("CREATE INFECTED: " + str(_this));

_position = getPosATL _agent;
_nearByPlayer = ({isPlayer _x} count (_position nearEntities [["AllVehicles","CAManBase"],30]) > 0);

// начиная с версии 007 не используется
/*
if (random 1 > 0.7) then {
	_agent setUnitPos "Middle";
};
*/

//diag_log ("CREATED: "  + str(_agent));
if (_nearByPlayer) then {
	deleteVehicle _agent;
};

if (isNull _agent) exitWith {
	viruz_spawnZombies = viruz_spawnZombies - 1;
};

_isAlive = alive _agent;

_myDest = getPosATL _agent;
_newDest = getPosATL _agent;
_agent setVariable ["myDest",_myDest];
_agent setVariable ["newDest",_newDest];

//Add some loot
_rnd = random 1;
if (_rnd > 0.3) then {
	_lootType = 		configFile >> "CfgVehicles" >> _type >> "zombieLoot";
	if (isText _lootType) then {
		_array = []+ getArray (missionConfigfile >> "cfgLoot" >> getText(_lootType));
		if (count _array > 0) then {
			_loot = _array call BIS_fnc_selectRandomWeighted;
			if(!isNil "_array") then {
				_agent addMagazine _loot;
			};
		};
	};
};

//Start behavior
_id = [_position,_agent] execFSM "\z\AddOns\viruz_mod\system\zombie_agent.fsm";