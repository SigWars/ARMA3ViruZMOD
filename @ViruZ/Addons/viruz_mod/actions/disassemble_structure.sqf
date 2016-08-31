private["_objectID","_objectUID","_obj","_ownerID","_dir","_pos","_bag","_holder","_weapons","_magazines","_backpacks","_objWpnTypes","_objWpnQty","_countr","_item","_structures","_items"];
_obj = _this;
_ownerID 	= _obj getVariable["CharacterID","0"];
_objectID 	= _obj getVariable["ObjectID","0"];
_objectUID	= _obj getVariable["ObjectUID","0"];
_structures = [];
_items = [];

{
	_items SET [count _items,_x select 0];
	_structures SET [count _structures,_x select 1];
}forEach (getArray(configFile >> "CfgConstruction" >> "Structures"));

_item = _items select (_structures find (typeOf _obj));

player playActionNow "Medic";

player removeAction s_player_disassemble;
s_player_disassemble = -1;

_alreadyPacking = _obj getVariable["packing",0];

if (_alreadyPacking == 1) exitWith {cutText [format[(localize "str_player_beingdisassemble")] , "PLAIN DOWN"]};

_obj setVariable["packing",1];

_dir = direction _obj;
_pos = getposATL _obj;
	
_dis=20;
_sfx = "tentpack";
[player,_sfx,0,false,_dis] call viruz_zombieSpeak;  
[player,_dis,true,(getPosATL player)] spawn player_alertZombies;
	
sleep 3;


if (isClass (configFile >> "CfgMagazines" >> _item)) then {
	_holder = "GroundWeaponHolder" createVehicle _pos; 
	_holder addmagazinecargoGlobal [_item, 1];
} else {
	_item createVehicle _pos;
};


viruzDeleteObj = [_objectID,_objectUID];
publicVariable "viruzDeleteObj";
if (isServer) then {
	viruzDeleteObj call server_deleteObj;
};
deleteVehicle _obj;

cutText [format[localize "str_success_Disassemble",getText(configFile >> "CfgVehicles" >> typeOf _obj >> "displayName")], "PLAIN DOWN"];
