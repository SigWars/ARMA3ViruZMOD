private["_location","_isOk","_dir","_classname","_item"];
_location = player modeltoworld [0,1,0];
//_location set [2,0];
_onLadder =		(getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
_isWater = 		(surfaceIsWater _location) or viruz_isSwimming;

call gear_ui_init;

if(_isWater) exitWith {cutText [localize "str_player_26", "PLAIN DOWN"];};
if(_onLadder) exitWith {cutText [localize "str_player_21", "PLAIN DOWN"];};

_item =			_this;
_classname = 	getText (configFile >> "CfgMagazines" >> _item >> "ItemActions" >> "Build" >> "create");
_text = 		getText (configFile >> "CfgVehicles" >> _classname >> "displayName");

_hasbuilditem = _this in magazines player;

if (!_hasbuilditem) exitWith {cutText [format[(localize "str_player_31"),_text,"build"] , "PLAIN DOWN"]};

_dir = getDir player;
player removeMagazine _item;

player playActionNow "PutDown";
sleep 1;

/*	
_dis=20;
_sfx = "repair";
[player,_sfx,0,false,_dis] call viruz_zombieSpeak;  
[player,_dis,true,(getPosATL player)] spawn player_alertZombies;
	
sleep 5;
*/
		
player allowDamage false;
_object = createVehicle [_classname, _location, [], 0, "CAN_COLLIDE"];
_object setDir _dir;
_object setPosATL _location;
player reveal _object;

cutText [format[localize "str_build_Electronics",_text], "PLAIN DOWN"];

sleep 2;
player allowDamage true;