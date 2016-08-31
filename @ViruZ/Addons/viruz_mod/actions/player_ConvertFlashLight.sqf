private["_item","_config","_onLadder","_create","_isOk","_config2","_consume"];
systemChat format["%1", "Convert - start"];
_item = 	_this;
_config =	configFile >> "cfgWeapons" >> _item;

_onLadder =		(getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {cutText [(localize "str_player_21") , "PLAIN DOWN"]};

_hastoolweapon = _this in weapons player;
_text = getText (_config >> "displayName");
if (!_hastoolweapon) exitWith {cutText [format[(localize "str_player_30"),_text] , "PLAIN DOWN"]};

call gear_ui_init;

//Add new item
_create = 	getArray (_config >> "ItemActions" >> "Toolbelt" >> "output") select 0;
_config2 = 	configFile >> "cfgWeapons" >> _create;

_isOk = [player,_config2] call BIS_fnc_invAdd;

if (_isOk) then {
	//Remove item
	player removeWeapon _item;
} else {
	cutText [localize "STR_VIRUZ_MOD_2", "PLAIN DOWN"];
};
systemChat format["%1", "Convert - end"];