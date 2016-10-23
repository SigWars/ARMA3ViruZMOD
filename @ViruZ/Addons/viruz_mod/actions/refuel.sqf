private["_vehicle","_curFuel","_newFuel","_timeLeft","_cansGear","_capacity","_canSize"];

//_vehicle = 		_this;
_vehicle = 		cursorTarget;
_cansGear = ["ItemJerrycan", player] call PTm_fnc_filterGear;

_canSize = 		getNumber(configFile >> "cfgMagazines" >> "ItemJerrycan" >> "fuelQuantity");
_configVeh = 	configFile >> "cfgVehicles" >> TypeOf(_vehicle);
_capacity = 	getNumber(_configVeh >> "fuelCapacity");
_nameType = 	getText(_configVeh >> "displayName");
_curFuel = 		((fuel _vehicle) * _capacity);

for "_i" from 0 to (count _cansGear) - 1 do {
	
	if ((_cansGear select _i) select 1 > 0) exitWith {
		_newFuel = _curFuel + ((_cansGear select _i) select 1);

		if (_newFuel > _capacity) then {
			_newSize = round(_newFuel - _capacity);
			_canSize = ((_cansGear select _i) select 1) - _newSize;
			(_cansGear select _i) SET [1, _newSize];
			_newFuel = _capacity;
		} else {
			_canSize = (_cansGear select _i) select 1;
			(_cansGear select _i) SET [1, 0];
		};
		
		_newFuel = (_newFuel / _capacity);

		{
			player removeMagazine (_x select 0);
		} forEach _cansGear;
		
		{
			player addMagazine [_x select 0,_x select 1];
		} forEach _cansGear;
		
		player playActionNow "Medic";
		_dis=10;
		_sfx = "refuel";
		[player,_sfx,0,false,_dis] call viruz_zombieSpeak;  
		[player,_dis,true,(getPosATL player)] spawn player_alertZombies;

		sleep 6;

		viruzSetFuel = [_vehicle,_newFuel];
		viruzSetFuel spawn local_setFuel;
		publicVariable "viruzSetFuel";

		cutText [format[localize "str_player_05",_nameType,_canSize], "PLAIN DOWN"];
		sleep 1;

		call fnc_usec_medic_removeActions;
		r_action = false;
	};
	
};