private["_hasFood","_item","_text","_cansGear"];

player removeAction s_player_fillfuel;
s_player_fillfuel = -1;

_cansGear = ["ItemJerrycanEmpty", player] call PTm_fnc_filterGear;
_maxFuelInCan = getNumber (configFile >> "CfgMagazines" >> "ItemJerrycan" >> "count");
_qtyEmptyCans = {(_x select 1) < _maxFuelInCan} count _cansGear;


if (_qtyEmptyCans > 0) then {

	_dis=5;
	_sfx = "refuel";
	_MassOnePercent = (getNumber (configFile >> "CfgVehicles" >> backpack player >> "maximumLoad")) / 100; // Вычисляется масса 1% из максимальной загрузки вещьмешка
	_MassItemJerrycanInPercentage = ((getNumber (configFile >> "CfgMagazines" >> "ItemJerrycan" >> "mass")) / _MassOnePercent) / 100; // Вычислить массу ItemJerrycan в процентах, и привести значение к формату извлекаемому из loadBackpack player
	_mypos = getpos player;
	_dir = getdir player;
	_mypos = [(_mypos select 0)-1*sin(_dir),(_mypos select 1)-1*cos(_dir), (_mypos select 2)];
	
	[player,_sfx,0,false,_dis] call viruz_zombieSpeak;
	[player,_dis,true,(getPosATL player)] spawn player_alertZombies;
	player playActionNow "Medic";
	r_doLoop = true;
	_started = false;
	_finished = false;
	while {r_doLoop} do {
		_animState = animationState player;
		_isRefuel = ["medic",_animState] call fnc_inString;
		if (_isRefuel) then {
			_started = true;
		};
		if (_started and !_isRefuel) then {
			r_doLoop = false;
			_finished = true;
		};
		sleep 0.1;
	};

	r_doLoop = false;
	
	if (_finished) then {

		{player removeMagazine (_x select 0);} forEach _cansGear;
		
		{
			if ((loadBackpack player + _MassItemJerrycanInPercentage) <= 1) then {
				player addMagazine "ItemJerrycan";
			} else {
				_Holders = nearestObjects [_mypos, ["groundWeaponHolder"], 1];
				if (count _Holders == 0) then {
					_Holder = createVehicle ["groundWeaponHolder", _mypos, [], 0, "CAN_COLLIDE"];
					_Holder addMagazineCargoGlobal ["ItemJerrycan",1];
				} else {
					_Holder = _Holders select 0;
					_Holder addMagazineCargoGlobal ["ItemJerrycan",1];
				};
			};
		} forEach _cansGear;
	};

	cutText [format[(localize  "str_player_09"),_qtyEmptyCans], "PLAIN DOWN"];
} else {
	cutText [(localize "str_player_10") , "PLAIN DOWN"];
};
