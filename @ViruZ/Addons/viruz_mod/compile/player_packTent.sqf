/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

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

player removeAction (s_player_packtent select 0);
s_player_packtent = [-1,""];

//if(_ownerID == viruz_characterID) then {
	_alreadyPacking = _obj getVariable["packing",0];

	if (_alreadyPacking == 1) exitWith {cutText [format[(localize "str_player_beingpacked")] , "PLAIN DOWN"]};

	_obj setVariable["packing",1];

	_dir = direction _obj;
	_pos = getposATL _obj;
	
	_dis=20;
	_sfx = "tentpack";
	[player,_sfx,0,false,_dis] call viruz_zombieSpeak;  
	[player,_dis,true,(getPosATL player)] spawn player_alertZombies;
	
	sleep 3;

	//place tent (local)
	
/*
	_bag = createVehicle ["WeaponHolder_ItemTent",_pos,[], 0, "CAN_COLLIDE"];
	_bag setdir _dir;
	player reveal _bag;
*/
	
	_holder = "GroundWeaponHolder" createVehicle _pos; 
	_holder addmagazinecargoGlobal [_item, 1];
	
	_weapons = 	getWeaponCargo _obj;
	_magazines = 	getMagazineCargo _obj;
	_backpacks = 	getBackpackCargo _obj;
	_items = getItemCargo _obj;
	
	//["viruzDeleteObj",[_objectID,_objectUID]] call callRpcProcedure;	
	viruzDeleteObj = [_objectID,_objectUID];
	publicVariable "viruzDeleteObj";
	if (isServer) then {
		viruzDeleteObj call server_deleteObj;
	};
	deleteVehicle _obj;
	
	//Add weapons
	_objWpnTypes = 	_weapons select 0;
	_objWpnQty = 	_weapons select 1;
	_countr = 0;
	{
		_holder addweaponcargoGlobal [_x,(_objWpnQty select _countr)];
		_countr = _countr + 1;
	} forEach _objWpnTypes;
	
	//Add Magazines
	_objWpnTypes = _magazines select 0;
	_objWpnQty = _magazines select 1;
	_countr = 0;
	{
		_holder addmagazinecargoGlobal [_x,(_objWpnQty select _countr)];
		_countr = _countr + 1;
	} forEach _objWpnTypes;

	//Add Backpacks
	_objWpnTypes = _backpacks select 0;
	_objWpnQty = _backpacks select 1;
	_countr = 0;
	{
		_holder addbackpackcargoGlobal [_x,(_objWpnQty select _countr)];
		_countr = _countr + 1;
	} forEach _objWpnTypes;
	
	//Add Items
	_objWpnTypes = _items select 0;
	_objWpnQty = _items select 1;
	_countr = 0;
	{
		_holder addItemCargoGlobal [_x,(_objWpnQty select _countr)];
		_countr = _countr + 1;
	} forEach _objWpnTypes;
	
	_cutText = format["%1 : %2",localize "str_success_pack",getText(configFile >> "CfgVehicles" >> typeOf _obj >> "displayName")];
	cutText [_cutText, "PLAIN DOWN"];
//	cutText [localize "str_success_tent_pack", "PLAIN DOWN"];
/*
} else {
	cutText [localize "str_fail_tent_pack", "PLAIN DOWN"];
};
*/