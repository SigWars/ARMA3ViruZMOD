/*
	Created by SigWar for ViruZ Mod.
*/

private["_config","_input","_output","_required","_failChance","_hasInput","_availabeSpace"];
disableSerialization;
["close"] call fn_updateCraftUI;

_config = _this select 0;
_overwrite = _this select 1;
_tipo = _this select 2;

_input = getArray (_config >> "input");
_output = getArray (_config >> "output");
_required = getArray (_config >> "required");
_failChance = getNumber (_config >> "failChance");

if (count _overwrite > 0) then {
	{
		_index = _x select 0;
		_entry = _x select 1;
		_input set [_index, _entry];
	}forEach _overwrite;
};

_hasInput = true;

{
	private ["_avail"];
	_selection = _x select 1;
	_item = _x select 0;
	_amount = _x select 2;

	switch (_selection) do {
		case "CfgWeapons":
		{
			_avail = {_x == _item} count weapons player;
		};
		case "CfgMagazines":
		{
			_avail = {_x == _item} count magazines player;
		};
	};

	if (_avail < _amount) exitWith {
		_hasInput = false;
		_itemName = getText(configFile >> _selection >> _item >> "displayName");
		cutText[format[(localize "str_crafting_missing"),(_amount - _avail),_itemName], "PLAIN DOWN"];
	};
}forEach (_input + _required);

if (_hasInput) then {
	_freeSlots = [player] call BIS_fnc_invSlotsEmpty;
	{
		_item = _x select 0;
		_amount = _x select 2;
		_slotType = [_item] call BIS_fnc_invSlotType;
		for "_i" from 1 to _amount do {
			for "_j" from 1 to (count _slotType) do {
				if ((_slotType select _j) > 0) then {
					_freeSlots set[_j, ((_freeSlots select _j) + (_slotType select _j))];
				};
			};
		};
	}forEach _input;

	_availabeSpace = true;
	{

		_item = _x select 0;
		_amount = _x select 2;
		_slotType = [_item] call BIS_fnc_invSlotType;
		for "_i" from 1 to _amount do {
			for "_j" from 1 to (count _slotType) do {
				if ((_slotType select _j) > 0) then {
					_freeSlots set[_j, ((_freeSlots select _j) - (_slotType select _j))];
					if (_freeSlots select _j < 0) exitWith {
						_availabeSpace = false;
						cutText[(localize "str_crafting_space"), "PLAIN DOWN"];
					};
				};
			};
		};
	}forEach _output;
	sleep 1;

	//if (_availabeSpace) then {
		player playActionNow "PutDown";
		if (dialog) then { closeDialog 0 };
		{
			_item = _x select 0;
			_amount = _x select 2;
			for "_i" from 1 to _amount do {
				_selection = _x select 1;
				switch (_selection) do {
					case "CfgWeapons":
					{
						player removeWeapon _item;
					};
					case "CfgMagazines":
					{
						player removeMagazine _item;
					};
				};
				sleep 0.1;
			};
		}forEach _input;

			{
				_item = _x select 0;
				_selection = _x select 1;
				_amount = _x select 2;
				_obj = objNull;
		        _itemName = getText(configFile >> _selection >> _item >> "displayName");
				
				_nearByPile= nearestObjects [getPosATL player, ["GroundWeaponHolder"],2];
				if (count _nearByPile == 0) then {
					_obj = createVehicle ["GroundWeaponHolder", getPosATL player, [], 1, "CAN_COLLIDE"];
				} else { _obj = _nearByPile select 0;};
				
				for "_i" from 1 to _amount do {
					if (random 1 > _failChance) then {
						switch (_selection) do {
						
						
							case "CfgWeapons":
							{
								_obj addWeaponCargoGlobal [_item,1];
				                _mags = getArray (configFile >> "cfgWeapons" >> _item >> "magazines");
				                if (count _mags > 0) then {
					            _obj addMagazineCargoGlobal [(_mags select 0),1];
				                };
							};
							case "CfgMagazines":
							{
								_obj = createVehicle ["GroundWeaponHolder", getPosATL player, [], 1, "CAN_COLLIDE"];
 								_obj addMagazineCargoGlobal [_item,1];
								//player addMagazine _item;
							};
						};
						cutText[format[(localize "str_crafting_success"),_itemName], "PLAIN DOWN"];
						//sleep 2;
					} else {
						cutText[format[(localize "str_crafting_failed"),_itemName], "PLAIN DOWN"];
						//sleep 2;
					};
				};

			}forEach _output;
	//};
};