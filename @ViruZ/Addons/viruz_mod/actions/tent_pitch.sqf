private["_position","_tent","_location","_isOk","_backpack","_tentType","_trg","_key","_vehicle","_structures","_items"];
//check if can pitch here
call gear_ui_init;
_playerPos = 	getPosATL player;
_item = _this;
_hastentitem = _this in magazines player;
_location = player modeltoworld [0,2.5,0];
_location set [2,0];
_building = nearestObject [(vehicle player), "HouseBase"];
_isOk = [(vehicle player),_building] call fnc_isInsideBuilding;
_structures = [];
_items = [];

{
	_items SET [count _items,_x select 0];
	_structures SET [count _structures,_x select 1];
}forEach (getArray(configFile >> "CfgConstruction" >> "Structures"));

_vehicle = _structures select (_items find _item);

//_isOk = true;

//diag_log ("Pitch Tent: " + str(_isok) );

_config = configFile >> "CfgMagazines" >> _item;
_text = getText (_config >> "displayName");

if (!_hastentitem) exitWith {cutText [format[(localize "str_player_31"),_text,"pitch"] , "PLAIN DOWN"]};

//blocked
if (["concrete",viruz_surfaceType] call fnc_inString) then { _isOk = true; diag_log ("surface concrete"); };
//Block Tents in pounds
_objectsPond = 		nearestObjects [_playerPos, [], 10];
	{
		_isPond = ["pond",str(_x),false] call fnc_inString;
		if (_isPond) then {
			_pondPos = (_x worldToModel _playerPos) select 2;
			if (_pondPos < 0) then {
				_isOk = true;
			};
		};
	} forEach _objectsPond;

//diag_log ("Pitch Tent: " + str(_isok) );

if (!_isOk) then {
	//remove tentbag
	player removeMagazine _item;
	_dir = round(direction player);	
	
	//wait a bit
	player playActionNow "Medic";
	sleep 1;
	
	_dis=20;
	_sfx = "tentunpack";
	[player,_sfx,0,false,_dis] call viruz_zombieSpeak;  
	[player,_dis,true,(getPosATL player)] spawn player_alertZombies;
	
	sleep 5;
	//place tent (local)
	_tent = createVehicle [_vehicle, _location, [], 0, "CAN_COLLIDE"];
	_tent setdir _dir;
	_tent setpos _location;
	player reveal _tent;
	_location = getPosATL _tent;
	
	//hint format ["Direçao %1", _tent ];
	
	_tent setVariable ["characterID",viruz_characterID,true];

	viruzPublishObj = [viruz_characterID,_tent,[_dir,_location],_vehicle];
	publicVariable "viruzPublishObj";
	_text = "Structure"
	cutText [format[localize "str_success_pitch",_text], "PLAIN DOWN"];
	//cutText [localize "str_success_tent_pitch", "PLAIN DOWN"];
} else {
	cutText [localize "str_fail_pitch", "PLAIN DOWN"];
};

