_building = _this select 3 select 0;
_act = _this select 3 select 1;
_DoorNumber = _this select 3 select 2;
_objectID = _building getVariable ["ObjectID","0"];
_objectUID = _building getVariable ["ObjectUID","0"];
_count = 6;

if (_act == "lock") then {

	_building setVariable [format["bis_disabled_Door_%1", _DoorNumber], 1, true];
	_building setVariable [format["Door_%1_Lock", _DoorNumber], "1", true];
	//_building setVariable ["Locked", "1", true];
	
	//Remove player menu
	player setVariable ["current_door", 0];
	player removeAction s_player_lockbuild;
	s_player_lockbuild = -1;
	
	//UPDATE DATABASE
	if ( (_building getVariable ["Door_1_Lock", "1"] == "1") and (_building getVariable ["Door_2_Lock", "1"] == "1") and (_building getVariable ["Door_3_Lock", "1"] == "1") and (_building getVariable ["Door_4_Lock", "1"] == "1") and (_building getVariable ["Door_5_Lock", "1"] == "1") and (_building getVariable ["Door_6_Lock", "1"] == "1")) then {
	viruzUpdateBuild = ["Lock",_objectID,_objectUID,"","",""];
	publicVariable "viruzUpdateBuild";
	};
	
    cutText ["LOCKED", "PLAIN DOWN",1];
} else {

	_building setVariable [format["bis_disabled_Door_%1", _DoorNumber], 0, true];
	_building setVariable [format["Door_%1_Lock", _DoorNumber], "0", true];
	//_building setVariable ["Locked", "0", true];
	
	//Remove player menu
	player setVariable ["current_door", 0];
	player removeAction s_player_unlockbuild;
    s_player_unlockbuild = -1;
	
	//UPDATE DATABASE
	if ( (_building getVariable ["Door_1_Lock", "0"] == "0") and (_building getVariable ["Door_2_Lock", "0"] == "0") and (_building getVariable ["Door_3_Lock", "0"] == "0") and (_building getVariable ["Door_4_Lock", "0"] == "0") and (_building getVariable ["Door_5_Lock", "0"] == "0") and (_building getVariable ["Door_6_Lock", "0"] == "0")) then {
	viruzUpdateBuild = ["Unlock",_objectID,_objectUID,"","",""];
	publicVariable "viruzUpdateBuild";
	};
	cutText ["UNLOCKED", "PLAIN DOWN",1];
};
