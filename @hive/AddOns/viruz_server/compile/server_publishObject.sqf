private ["_class","_uid","_charID","_object","_worldspace","_key","_structures","_vehicles"];
//[viruz_characterID,_tent,[_dir,_location],"TentStorage"]
_charID =		_this select 0;
_object = 		_this select 1;
_worldspace = 	_this select 2;
_class = 		_this select 3;

_structures = [];
{
	_structures set [count _structures,_x select 1];
} forEach (getArray(configFile >> "CfgConstruction" >> "Structures"));

_vehicles = [];
{
	_vehicles set [count _vehicles,_x select 1];
} forEach (getArray(configFile >> "CfgConstruction" >> "Vehicles"));

if !((_class in _structures) or (_class in _vehicles)) exitWith {
	deleteVehicle _object;
};


/*
if (!(_object isKindOf "Building")) exitWith {
	deleteVehicle _object;
};
_allowed = [_object, "Server"] call check_publishobject;
if (!_allowed) exitWith { };
*/

//diag_log ("PUBLISH: Attempt " + str(_object));

//get UID
_uid = _worldspace call viruz_objectUID2;

//Send request
_key = format["CHILD:308:%1:%2:%3:%4:%5:%6:%7:%8:%9:",viruZ_instance, _class, 0 , _charID, _worldspace, [], [], 0,_uid];
//diag_log ("HIVE: WRITE: "+ str(_key));
_key call server_hiveWrite;

_object setVariable ["ObjectUID", _uid,true];

_idKey = ([arrayObjectID,1] call BIS_fnc_findExtreme) + 1;
arrayObjectID set [count arrayObjectID, _idKey];

if (_class in _vehicles) then {
	_object setVariable ["ObjectID", str(_idKey), true];
	_vehicle setVariable ["lastUpdate",time];
	_object call fnc_vehicleEventHandler;
};

if (_class in _structures) then {
	_object addMPEventHandler ["MPKilled",{_this call vehicle_handleServerKilled;}];
};

viruz_serverObjectMonitor set [count viruz_serverObjectMonitor,_object];



//diag_log ("PUBLISH: Created " + (_class) + " with ID " + _uid);
