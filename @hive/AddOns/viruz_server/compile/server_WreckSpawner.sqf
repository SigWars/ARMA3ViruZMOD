private ["_config","_location","_locationPosition","_locationRadiusA","_wreckTypeModel","_nearRoads","_civilian","_military","_mixed","_genDist","_active","_wreckObjects"];

if (ViruzDebugMode > 2 or ViruzDebugType == "VEHICLES") then {
	diag_log (format["WRECKSPAWNER: Spawn wreck objects. Location : %1", text _this]);
};	

_location = _this;
_locationPosition = locationPosition _location;
_locationRadiusA = getNumber (configFile >> "cfgWorlds" >> worldName >> "Names" >> className _location >> "RadiusA");
if (isNil "_locationRadiusA") then {_locationRadiusA = 300;};
_wreckObjects = [];

_config = configFile >> "CfgWreckSpawner";
_civilian =	getArray (_config >> "civilian");
_military = getArray (_config >> "military");
_mixed = 	getArray (_config >> "mixed");
_wreckTypeModel = "";
	
switch (text _location) do {
	default				{_wreckTypeModel = _civilian;};
	case "military":	{_wreckTypeModel = _military;};
	case "factory":		{_wreckTypeModel = _mixed;};
};
	
_nearRoads = _locationPosition nearRoads _locationRadiusA;

{
	private ["_road","_roadPos","_dirObject","_wreckModel","_wreckObject","_roadsConnected","_listPos","_dir","_dist","_roadsDist"];
	_road = _x;
	_roadPos = getPosATL _road;
	_roadsConnected = roadsConnectedTo _road;
	_listPos = [];	
	_roadsDist = [];

	if ((count _roadsConnected) > 0) then {
		{
			_roadsDist SET [count _roadsDist, _road distance _x];
		} forEach _roadsConnected;
		_dist = ([_roadsDist,1] call BIS_fnc_findExtreme) / 2;
	} else {
		_dist = 16;
	};
	
	while {_dist > 0} do {
		_dir = 360;
		while {_dir != 0} do {
			private ["_Pos"];
			_Pos = [ _x, _dist, _dir] call BIS_fnc_relPos;
			if ((isOnRoad _Pos) and ((surfaceType _Pos) == "#GdtConcrete")) then {
				_listPos SET [count _listPos, _Pos];
			};
			_dir = _dir - 72;
		};
		_dist = _dist - 2;
	};

	{
		private ["_pos","_isNoHouse","_wreckModel","_nearObj","_wreckDir"];
		_wreckModel = _wreckTypeModel call BIS_fnc_selectRandom;
		_pos = _x;
//		_isNoHouse = true;
//		_nearObj = nearestObject [_pos,"NonStrategic"];
//		_isNoHouse = ((sizeOf typeOf(_nearObj)) + (sizeOf _wreckModel)) < (_pos distance _nearObj);
			
		
//		if (_isNoHouse) then {
			if (count(nearestObjects [_pos, ["Car","Motorcycle","Wreck_Base","CarWreck","Wall_F"], ((sizeOf _wreckModel) * 2)]) == 0) then {

				if ((count _roadsConnected) > 0) then {
					_wreckDir = [_roadPos, getPos (_roadsConnected call BIS_fnc_selectRandom)] call BIS_fnc_dirTo;
				} else {
					_wreckDir = random 360;
				};
				
				_wreckObject = createVehicle [_wreckModel,_pos, [], 0, "CAN_COLLIDE"];
				_wreckObject setPosATL _pos;
				_wreckObject setDir (_wreckDir + ([(random 30),(random -30)] call BIS_fnc_selectRandom));
				_wreckObject setVectorUp surfaceNormal position _wreckObject;
				_wreckObject setVariable ["isBuilding", false, true];
				
				_wreckObjects SET [count _wreckObjects, _wreckObject];
			};
//		};
	} forEach _listPos;
} forEach _nearRoads;

_wreckObjects