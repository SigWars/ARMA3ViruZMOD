private["_position","_location","_isOk","_backpack","_key","_vehicle","_vehicles","_items","_item","_cansGear","_newFuel","_capacity","_canSize"];

_item = _this select 3;
_playerPos = 	getPosATL player;
_location = player modeltoworld [0,4,0];
_location set [2,0];
_building = nearestObject [(vehicle player), "HouseBase"];
_isOk = [(vehicle player),_building] call fnc_isInsideBuilding;
_vehicles = [];
_items = [];

{
	_items SET [count _items,_x select 0];
	_vehicles SET [count _vehicles,_x select 1];
}forEach (getArray(configFile >> "CfgConstruction" >> "Vehicles"));

_vehicle = _vehicles select (_items find _item);

if (!_isOk) then {
	
	_cansGear = ["ItemJerrycan", player] call PTm_fnc_filterGear;
	
	removeBackpack player;
	_dir = round(direction player);	
	
	//wait a bit
	player playActionNow "Medic";
	sleep 1;
	
	_dis=20;
	_sfx = "tentunpack";
	[player,_sfx,0,false,_dis] call viruz_zombieSpeak;  
	[player,_dis,true,(getPosATL player)] spawn player_alertZombies;
	
	sleep 5;
	_veh = createVehicle [_vehicle, _location, [], 0, "CAN_COLLIDE"];
	_veh setdir _dir;
	_veh setpos _location;
	player reveal _veh;
	_location = getPosATL _veh;
	
	_configVeh = 	configFile >> "cfgVehicles" >> TypeOf(_veh);
	_capacity = 	getNumber(_configVeh >> "fuelCapacity");
	_newFuel = 0;
	
	if (count _cansGear > 0) then {
		{
			if (_x select 1 > 0) then {
				_newFuel = _newFuel + (_x select 1);
			};
		} forEach _cansGear;
	};
	
	_newFuel = (_newFuel / _capacity);
	viruzSetFuel = [_veh,_newFuel];
	viruzSetFuel spawn local_setFuel;
	
	_veh setVariable ["characterID","0",true];

	viruzPublishObj = ["0",_veh,[_dir,_location],_vehicle];
	publicVariable "viruzPublishObj";
	publicVariable "viruzSetFuel";
	
	cutText [format[localize "str_success_Assemble",getText(configFile >> "CfgVehicles" >> typeOf _veh >> "displayName")], "PLAIN DOWN"];
	
	call player_gearSync;
	
} else {
	cutText [localize "str_fail_Assemble", "PLAIN DOWN"];
};