/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_isCans","_onLadder","_itemorignal","_hasfooditem","_rawfood","_cookedfood","_hasoutput","_eatvalue","_config","_text","_regen","_dis","_sfx","_Cookedtime","_itemtodrop","_nearByPile","_item","_display"];
disableserialization;
call gear_ui_init;
_onLadder =     (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {cutText [(localize "str_player_21") , "PLAIN DOWN"]};

if (vehicle player != player) exitWith {cutText ["You may not eat while in a vehicle", "PLAIN DOWN"]};

//Force players to wait 3 mins to eat again
//if (viruz_lastMeal < 180) exitWith {cutText ["You may not eat, you're already full", "PLAIN DOWN"]};
if (viruz_hunger < 100) exitWith {cutText ["You may not eat, you're already full", "PLAIN DOWN"]};

_itemorignal = _this;

if ((["FoodCan",_itemorignal] call BIS_fnc_inString) and !("itemCanOpener" in magazines player)) exitWith {cutText ["You may not eat. In your inventore is missing can opener", "PLAIN DOWN"]};

_hasfooditem = _itemorignal in magazines player;

_rawfood = _itemorignal in meatraw;
_cookedfood = _itemorignal in meatcooked;
_hasoutput = _itemorignal in food_with_output;
_eatvalue = 300;

_config =   configFile >> "CfgMagazines" >> _itemorignal;
_text =     getText (_config >> "displayName");
_regen =    getNumber (_config >> "bloodRegen");

if (!_hasfooditem) exitWith {cutText [format[(localize "str_player_31"),_text,"consume"] , "PLAIN DOWN"]};

player playActionNow "PutDown";
player removeMagazine _itemorignal;
sleep 1;

_dis=6;
_sfx = "eat";
[player,_sfx,0,false,_dis] call viruz_zombieSpeak;
[player,_dis,true,(getPosATL player)] spawn player_alertZombies;



if (viruz_lastMeal < 3600) then { 
    if (_itemorignal == "FoodSteakCooked") then {
        //_regen = _regen * (10 - (10 max ((time - _Cookedtime) / 3600)));
    };
};

if (_hasoutput) then{
    // Selecting output
	_eatvalue = 300;
    _itemtodrop = food_output select (food_with_output find _itemorignal);

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

if ( _rawfood and (random 10 < 3)) then {
    r_player_infected = true;
    player setVariable["USEC_infected",true,true];
};

if (_rawfood) then {
	_eatvalue = 300;
};

if (_cookedfood) then {
	_eatvalue = 500;
};

if (_itemorignal == "FoodMRE") then {
	_eatvalue = 800;
};

r_player_blood = r_player_blood + _regen;
if (r_player_blood > r_player_bloodTotal) then {
    r_player_blood = r_player_bloodTotal;
};

player setVariable ["messing",[viruz_hunger,viruz_thirst],true];
player setVariable["USEC_BloodQty",r_player_blood,true];
player setVariable["medForceUpdate",true];

viruzPlayerSave = [player,[],true];
publicVariable "viruzPlayerSave";

viruz_lastMeal = time;
viruz_hunger = viruz_hunger - _eatvalue;

if (viruz_hunger < 0) then {viruz_hunger = 0;};



//Ensure Control is visible
_display = uiNamespace getVariable 'VIRUZ_GUI_display';
(_display displayCtrl 1301) ctrlShow true;

if (r_player_blood / r_player_bloodTotal >= 0.2) then {
    (_display displayCtrl 1300) ctrlShow true;
};
cutText [format[(localize  "str_player_consumed"),_text], "PLAIN DOWN"];