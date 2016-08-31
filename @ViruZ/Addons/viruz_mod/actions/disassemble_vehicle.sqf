private["_objectID","_objectUID","_obj","_dir","_pos","_bag","_holder","_weapons","_magazines","_backpacks","_objWpnTypes","_objWpnQty","_countr","_item","_vehicles","_items"];
_obj = _this select 3;
_objectID 	= _obj getVariable["ObjectID","0"];
_objectUID	= _obj getVariable["ObjectUID","0"];
_vehicles = [];
_items = [];

{
	_items SET [count _items,_x select 0];
	_vehicles SET [count _vehicles,_x select 1];
}forEach (getArray(configFile >> "CfgConstruction" >> "Vehicles"));

_item = _items select (_vehicles find (typeOf _obj));

player playActionNow "Medic";

player removeAction (s_player_disassembleVehicle select 0);
s_player_disassembleVehicle = [-1,""];

_alreadyPacking = _obj getVariable["packing",0];

if (_alreadyPacking == 1) exitWith {cutText [format[(localize "str_player_beingDisassembled")] , "PLAIN DOWN"]};

_obj setVariable["packing",1];

_pos = getposATL _obj;
	
_dis=20;
_sfx = "tentpack";
[player,_sfx,0,false,_dis] call viruz_zombieSpeak;  
[player,_dis,true,(getPosATL player)] spawn player_alertZombies;
	
sleep 3;

_holder = "GroundWeaponHolder" createVehicle _pos; 
_holder addBackpackCargoGlobal [_item, 1];
_holder setPosATL _pos;

viruzDeleteObj = [_objectID,_objectUID];
publicVariable "viruzDeleteObj";
if (isServer) then {
	viruzDeleteObj call server_deleteObj;
};

cutText [format[localize "str_success_Disassemble",getText(configFile >> "CfgVehicles" >> typeOf _obj >> "displayName")], "PLAIN DOWN"];

deleteVehicle _obj;