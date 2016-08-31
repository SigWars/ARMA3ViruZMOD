fnc_code = {
	
	private ["_pos","_dir","_type","_CampingLight","_newCampingLight","_isBattery","_battery"];

	_CampingLight = _this select 0;
	_pos = getPosATL _CampingLight;
	_dir = getDir _CampingLight;
	_battery = _CampingLight getVariable ["Battery", 0];

	if ((typeOf _CampingLight) == "Land_Camping_Light_F") then {
		_type = "Land_Camping_Light_off_F";
	} else {
		_type = "Land_Camping_Light_F";
	};
	
	if (count _this > 1) then {
		_this select 1 playActionNow "PutDown";
		sleep 1;
	};
	
	deleteVehicle _CampingLight;
	_newCampingLight = createVehicle [_type, _pos, [], 0, "CAN_COLLIDE"];
	_newCampingLight setVariable ["isBattery", true, true];
	_newCampingLight setVariable ["Battery", _battery, true];
	_newCampingLight setPosATL _pos;
	_newCampingLight setDir _dir;
	
};

fnc_code_BatteryLow = {
	private ["_pos","_dir","_CampingLight","_newCampingLight"];
	
	_CampingLight = _this select 0;
	_pos = getPosATL _CampingLight;
	_dir = getDir _CampingLight;
	
	deleteVehicle _CampingLight;
	_newCampingLight = createVehicle ["Land_Camping_Light_off_F", _pos, [], 0, "CAN_COLLIDE"];
	_newCampingLight setPosATL _pos;
	_newCampingLight setDir _dir;
};

fnc_code_take = {
	_this select 1 playActionNow "PutDown";
	sleep 1;
//	[_this select 1, "itemCampingLight"] call BIS_fnc_invAdd;
	(_this select 1) addMagazine "itemCampingLight";
	if ((_this select 0) getVariable ["isBattery", false]) then {
		(_this select 1) addMagazine ["Battery_mag", (_this select 0) getVariable ["Battery", 0]];
	};
	deleteVehicle (_this select 0);
};

fnc_code_linkBattery = {
	private ["_batterys","_newBatterys","_text"];
	
	_text = getText (configFile >> "CfgMagazines" >> "Battery_mag" >> "displayName");
	_newBatterys = [];

	if ("Battery_mag" in magazines (_this select 1)) then {
		_batterys = ["Battery_mag",_this select 1] call PTm_fnc_filterGear;
		{
			if !((_this select 0) getVariable ["isBattery", false]) then {
				(_this select 0) setVariable ["isBattery", true, true];
				(_this select 0) setVariable ["Battery", _x select 1, true];
			} else {
				_newBatterys set [count _newBatterys, _x];
			};
			(_this select 1) removeMagazine (_x select 0);
		} forEach _batterys;
		
		{
			(_this select 1) addMagazine [_x select 0, _x select 1];
		} forEach _newBatterys;
		
		{
			(_this select 0) removeAction _x;
		} forEach ((_this select 0) getVariable ["actions",[]]);
		(_this select 0) setVariable ["actions", [], true];
		
		_this select 1 playActionNow "PutDown";
		sleep 1;
		
	} else {
		cutText [format[localize "str_player_noGear",_text], "PLAIN DOWN"];
	};
};

private ["_players","_action","_action_2"];

sleep 0.5;

//_this setVariable ["isBattery", false, true];
//_this setVariable ["isGenerator", false, true];
_this setVariable ["actions", [], true];

_players = [];
_action = -1;
_action_2 = -1;

while {true} do {
	
	if (isNull _this) exitWith {};
	
	{
		if (alive _x) then {
			_players SET [count _players, _x];
		};	
	} forEach (nearestObjects [_this, ["SoldierWB"], 1.5]);	

	if (count _players > 0 ) then {
	
		if (count(_this getVariable ["actions",[]]) == 0) then { 
			
			if (typeOf _this == "Land_Camping_Light_F") then {
				_action = _this addAction [getText (configFile >> "CfgVehicles" >> "Land_Camping_Light_F" >> "displayName") + " " + localize "str_actions_Electronics_ON_OFF", {[_this select 0,_this select 1] call (_this select 3)}, fnc_code, 1, true, true];
				_this setVariable ["actions", [_action], true];
			} else {
				if ((_this getVariable ["isBattery", false]) or (_this getVariable ["isGenerator", false])) then {
					_action = _this addAction [getText (configFile >> "CfgVehicles" >> "Land_Camping_Light_off_F" >> "displayName") + " " + localize "str_actions_Electronics_ON_OFF", {[_this select 0,_this select 1] call (_this select 3)}, fnc_code, 1, true, true];
					_action_2 = _this addAction [format[localize "STR_VIRUZ_MOD_1",getText (configFile >> "CfgVehicles" >> "Land_Camping_Light_off_F" >> "displayName")], {[_this select 0,_this select 1] call (_this select 3)}, fnc_code_take, 1, true, true];
				} else {	
					_action = _this addAction [format[localize "str_actions_Electronics_Link_Battery",getText (configFile >> "CfgVehicles" >> "Land_Camping_Light_off_F" >> "displayName")], {[_this select 0,_this select 1] call (_this select 3)}, fnc_code_linkBattery, 1, true, true];
					_action_2 = _this addAction [format[localize "STR_VIRUZ_MOD_1",getText (configFile >> "CfgVehicles" >> "Land_Camping_Light_off_F" >> "displayName")], {[_this select 0,_this select 1] call (_this select 3)}, fnc_code_take, 1, true, true];
				};
				_this setVariable ["actions", [_action,_action_2], true];
			};
		};
		_action = -1;
		_action_2 = -1;
	} else {
	
		if (count(_this getVariable ["actions",[]]) > 0) then {
		
			{
				_this removeAction _x;
			} forEach (_this getVariable ["actions",[]]);
			_this setVariable ["actions", [], true];
			_action = -1;
			_action_2 = -1;
		};
	};
	
	if (typeOf _this == "Land_Camping_Light_F") then {
		if (_this getVariable ["isBattery", false]) then {
			_this setVariable ["Battery", (_this getVariable ["Battery", 0]) - 10, true];
			if ((_this getVariable ["Battery", 0]) < 0) exitWith {
				[_this] call fnc_code_BatteryLow;
			};
		} else {
			if (_this getVariable ["isGenerator", false]) then {
			
			};
		};
	};
	
	_players = [];
	sleep 1;
};
//systemChat format["%1", "STOP script CampingLight_init"];