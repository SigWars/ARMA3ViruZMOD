/*
[_object,_type] spawn server_updateObject;
*/
private ["_object","_type","_objectID","_uid","_lastUpdate","_needUpdate","_object_position","_isNotOk","_persistantObj"];

_object = 	_this select 0;

if ((typeOf _object) in config_ObjectIgnore) exitWith {};

_type = 	_this select 1;
_parachuteWest = typeOf _object == "ParachuteWest";
_isNotOk = false;
_eRack = typeOf _object in VIRUZ_RACKS;

_objectID =	_object getVariable ["ObjectID","0"];
_uid = 		_object getVariable ["ObjectUID","0"];
_persistantObj = (_object getVariable ["ViruZMod",1] == 1);


if ((typeName _objectID != "string") || (typeName _uid != "string")) then
{ 
    if (ViruzDebugMode > 2 or ViruzDebugType == "MONITOR") then {
		diag_log(format["Non-string Object: ID %1 UID %2", _objectID, _uid]);
	};
    //force fail
    _objectID = "0";
    _uid = "0";
};

if !(_parachuteWest or _eRack or _persistantObj) then {
	if (_objectID == "0" && _uid == "0") then
	{
		_object_position = getPosATL _object;
    	_isNotOk = true;
		
		if (ViruzDebugMode > 2 or ViruzDebugType == "MONITOR") then {
			diag_log(format["Deleting object %1 with invalid ID at pos [%2,%3,%4]",typeOf _object,_object_position select 0,_object_position select 1,_object_position select 2]);
		};
	};
};

if (_isNotOk) exitWith { deleteVehicle _object; };

_lastUpdate = _object getVariable ["lastUpdate",time];
_needUpdate = _object in needUpdate_objects;

_object setVariable ["lastUpdate",time,true];

switch (_type) do {
	case "all": {

		if (!([_object,"monitorSaveAll"] in needUpdate_objects)) then {
			if (ViruzDebugMode > 2 or ViruzDebugType == "MONITOR") then {
				diag_log format["DEBUG ALL: Added to NeedUpdate=%1",_object];
			};	
			needUpdate_objects set [count needUpdate_objects, [_object,"monitorSaveAll"]];
		};

	};
	case "position": {
		if ( (time - _lastUpdate) > 10) then {
			[_object,_objectID,_uid] call vzserver_object_position;
			[_object,_objectID,_uid] call vzserver_object_precisepos;
		} else {	
			if (!([_object,"monitorSavePos"] in needUpdate_objects)) then {
				if (ViruzDebugMode > 2 or ViruzDebugType == "MONITOR") then {
					diag_log format["DEBUG POSITION: Added to NeedUpdate=%1",_object];
				};
				needUpdate_objects set [count needUpdate_objects, [_object,"monitorSavePos"]];
			};
		};
	};	
	case "gear": {

		if (!([_object,"monitorSaveGear"] in needUpdate_objects)) then {
			if (ViruzDebugMode > 2 or ViruzDebugType == "MONITOR") then {
				diag_log format["DEBUG GEAR: Added to NeedUpdate=%1",_object];
			};
			needUpdate_objects set [count needUpdate_objects, [_object,"monitorSaveGear"]];
		};

	};
	case "damage": {
		if ( (time - _lastUpdate) > 15) then {
			[_object,_objectID,_uid] call vzserver_object_damage;
		} else {
			if (!([_object,"monitorSaveDamage"] in needUpdate_objects)) then {
				if (ViruzDebugMode > 2 or ViruzDebugType == "MONITOR") then {
					diag_log format["DEBUG DAMAGE: Added to NeedUpdate=%1",_object];
				};	
				needUpdate_objects set [count needUpdate_objects, [_object,"monitorSaveDamage"]];
			};
		};
	};
	case "killed": {
		[_object,_objectID,_uid] call vzserver_object_killed;
	};
	case "repair": {
		if ( (time - _lastUpdate) > 15) then {
			[_object,_objectID,_uid] call vzserver_object_damage;
		} else {
			if (!([_object,_type] in needUpdate_objects)) then {
				if (ViruzDebugMode > 2 or ViruzDebugType == "MONITOR") then {
					diag_log format["DEBUG REPAIR: Added to NeedUpdate=%1",_object];
				};
				needUpdate_objects set [count needUpdate_objects, [_object,"monitorSaveDamage"]];
			};
		};
	};
	
	case "PublishBuild": {
		vzserver_objecsTotupdate set [count vzserver_objecsTotupdate, [_object,"monitorPublishBuild"]];
		if (ViruzDebugMode > 2 or ViruzDebugType == "MONITOR") then {
			diag_log format["DEBUG PUBLISH: Added to vzserver_objecsTotupdate=%1",_object];
		};	
	};
	
	case "DelObject": {
		_object hideObjectGlobal true;
		vzserver_objecsTotupdate set [count vzserver_objecsTotupdate, [_object,"monitorDelObject"]];
		if (ViruzDebugMode > 2 or ViruzDebugType == "MONITOR") then {
			diag_log format["DEBUG DELETE: Added to vzserver_objecsTotupdate=%1",_object];
		};	
	};
	case "doorAction": {
		if (!([_object,_type] in vzserver_objecsTotupdate)) then {
			if (!([_object,"monitorDoorAction"] in vzserver_objecsTotupdate)) then {
				vzserver_objecsTotupdate set [count vzserver_objecsTotupdate, [_object,"monitorDoorAction"]];
				if (ViruzDebugMode > 2 or ViruzDebugType == "MONITOR") then {
					diag_log format["DEBUG DOORS: Added to vzserver_objecsTotupdate=%1",_object];
				};
			};
		};
	};
	case "maintainBuild": {
		if (!([_object,_type] in vzserver_objecsTotupdate)) then {
			if (!([_object,"monitorBuildMaintain"] in vzserver_objecsTotupdate)) then {
				vzserver_objecsTotupdate set [count vzserver_objecsTotupdate, [_object,"monitorBuildMaintain"]];
				if (ViruzDebugMode > 2 or ViruzDebugType == "MONITOR") then {
					diag_log format["DEBUG MAINTAIN: Added to vzserver_objecsTotupdate=%1",_object];
				};	
			};
		};
	};

	/*
		Monitor executions saves server_UpdateBuild
	*/
	case "monitorSavePos": {
		[_object,_objectID,_uid] call vzserver_object_position;
		[_object,_objectID,_uid] call vzserver_object_precisepos;
	};
	case "monitorSaveDamage": {
		[_object,_objectID,_uid] call vzserver_object_damage;
	};
	case "monitorSaveGear": {
		[_object,_objectID,_uid] call vzserver_object_inventory;
	};
	case "monitorSaveAll": {
		[_object,_objectID,_uid] call vzserver_object_position;;
		[_object,_objectID,_uid] call vzserver_object_inventory;
		[_object,_objectID,_uid] call vzserver_object_damage;
		[_object,_objectID,_uid] call vzserver_object_precisepos;
	};
	case "monitorPublishBuild": {
		["VZPublishBuild",_object] call server_UpdateBuild;
	};
	case "monitorDelObject": {
		[_objectID,_uid] call server_deleteObj;
		deleteVehicle _object;
	};
	case "monitorDoorAction": {
		[_object,_objectID,_uid] call vzserver_object_door;
	};
	case "monitorBuildMaintain": {
		[_object,_objectID,_uid] call vzserver_object_maintenance;
	};
};