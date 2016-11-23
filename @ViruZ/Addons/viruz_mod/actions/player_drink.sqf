private["_onLadder","_itemorignal","_hasdrinkitem","_hasoutput","_drinkValue","_config","_text","_sfx","_dis","_id","_itemtodrop","_nearByPile","_item","_display"];

disableserialization;
call gear_ui_init;

_onLadder =     (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {cutText [(localize "str_player_21") , "PLAIN DOWN"]};

if (vehicle player != player) exitWith {cutText ["You may not drink while in a vehicle", "PLAIN DOWN"]};

//Force players to wait 3 mins to drink again
//if (viruz_lastDrink < 180) exitWith {cutText ["You may not drink, your not thirsty", "PLAIN DOWN"]};
if (viruz_thirst < 100) exitWith {cutText ["You may not drink, your not thirsty", "PLAIN DOWN"]};

_itemorignal = _this;
_hasdrinkitem = _itemorignal in magazines player;
_hasoutput = _itemorignal in drink_with_output;
_drinkValue = 200;

_config = configFile >> "CfgMagazines" >> _itemorignal;
_text = getText (_config >> "displayName");

//getting type of sfx (now just drink od soda open and drink)
_sfx =  "drinksoda"

if (!_hasdrinkitem) exitWith {cutText [format[(localize "str_player_31"),_text,"drink"] , "PLAIN DOWN"]};

player playActionNow "PutDown";
player removeMagazine _itemorignal;
sleep 1;

if (_hasoutput) then{

	_drinkValue = 250;
    // Selecting output
    _itemtodrop = drink_output select (drink_with_output find _itemorignal);
	
//    sleep 3;
	sleep 0.3;
	_nearByPile= nearestObjects [(position player), ["GroundWeaponHolder"],2];
    if (count _nearByPile ==0) then {
		_pos = getPosATL player;
		_item = createVehicle ["GroundWeaponHolder", _pos, [], 0.0, "CAN_COLLIDE"];
		_item setPosATL _pos;
    } else {
        _item = _nearByPile select 0;
    };
    _item addMagazineCargoGlobal [_itemtodrop,1];
};

if (["ItemWaterbottle",_itemorignal] call fnc_inString) then {
    //low alert and sound radius
	_drinkValue = 800;
    _dis=5;
    [player,_sfx,0,false,_dis] call viruz_zombieSpeak;
    [player,_dis,true,(getPosATL player)] spawn player_alertZombies;
    player addMagazine "ItemWaterbottleUnfilled";
};
if (["ItemSoda",_itemorignal] call fnc_inString) then {
    //higher alert and sound radius
    _dis=10;
    [player,_sfx,0,false,_dis] call viruz_zombieSpeak;
    _id = [player,_dis,true,(getPosATL player)] spawn player_alertZombies;
};  

//add infection chance for "ItemWaterbottle", 
if ((random 10 < 4) and (_itemorignal == "ItemWaterbottle")) then {
    r_player_infected = true;
    player setVariable["USEC_infected",true,true];
};

player setVariable ["messing",[viruz_hunger,viruz_thirst],true];

viruz_lastDrink = time;
viruz_thirst = viruz_thirst - _drinkValue;

if (viruz_thirst < 0) then { viruz_thirst = 0; }; 

//Ensure Control is visible
_display = uiNamespace getVariable 'VIRUZ_GUI_display';
(_display displayCtrl 1302) ctrlShow true;

cutText [format[(localize  "str_player_consumed"),_text], "PLAIN DOWN"];