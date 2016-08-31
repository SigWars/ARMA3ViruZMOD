private["_hasFood","_item","_text","_qty"];

call gear_ui_init;

_playerPos = 	getPosATL player;
_waterSources = ["water"];
_canFill = false;
_near = nearestObjects [_playerPos, [], 4];
for "_i" from 0 to (count _near) - 1 do {
	_obj = _near select _i;
	for "_j" from 0 to (count _waterSources) - 1 do {
		_canFill = [(_waterSources select _j), format["%1", _obj], false] call BIS_fnc_inString;
		if (_canFill) exitWith {};
	};
	if (_canFill) exitWith {};
};
_isPond = 		false;
_isWell = 		false;
_pondPos = 		[];
_objectsWell = 	[];

_onLadder =		(getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {cutText [(localize "str_player_21") , "PLAIN DOWN"]};

_hasbottleitem = _this in magazines player;

_config = configFile >> "CfgMagazines" >> _item;
_text = getText (_config >> "displayName");

if (!_hasbottleitem) exitWith {cutText [format[(localize "str_player_31"),_text,"fill"] , "PLAIN DOWN"]};

if (!viruz_isSwimming) then {
	player playActionNow "PutDown";
};

if (!_canFill) then {
	_objectsWell = 	nearestObjects [_playerPos, [], 4];
	{
		//Check for Well
		_isWell = ["_well",str(_x),false] call fnc_inString;
		if (_isWell) then {_canFill = true};
	} forEach _objectsWell;
};

if (!_canFill) then {
	_eagua = (surfaceIsWater (position player)) or viruz_isSwimming;
	if (_eagua) then {_canFill = true;};
};

if (!_canFill) then {
	_objectsPond = 		nearestObjects [_playerPos, [], 50];
	{
		//Check for pond
		_isPond = ["Land_Barrel_water",str(_x),false] call fnc_inString;
		if (_isPond) then {
			_pondPos = (_x worldToModel _playerPos) select 2;
			if (_pondPos < 0) then {
				_canFill = true;
			};
		};
	} forEach _objectsPond;
};

if (_canFill) then {
	_qty = {_x == "ItemWaterbottleUnfilled"} count magazines player;

	if ("ItemWaterbottleUnfilled" in magazines player) then {
		for "_x" from 1 to _qty do {
			player removeMagazine "ItemWaterbottleUnfilled";
			player addMagazine "ItemWaterbottle";
		};

		_dis=5;
		_sfx = "fillwater";
		[player,_sfx,0,false,_dis] call viruz_zombieSpeak;  
		[player,_dis,true,(getPosATL player)] spawn player_alertZombies;
		
		cutText [format[(localize  "str_player_01"),_qty], "PLAIN DOWN"];
	} else {
		cutText [(localize "str_player_02") , "PLAIN DOWN"];
	};
} else {
	cutText [(localize "str_player_20") , "PLAIN DOWN"];
};