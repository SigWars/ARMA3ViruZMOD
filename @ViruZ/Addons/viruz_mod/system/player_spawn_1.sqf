private["_handle","_body","_cursor","_delMe"];
while {true} do {
	
	_handle = [] spawn player_animalCheck;
	waitUntil{scriptDone _handle};
/*	
	//check fly objects
	{
		_body = _x getVariable["body",objNull];
		if (isNull _body) then {
			viruz_flyMonitor = viruz_flyMonitor - [_x];
			deleteVehicle _x;
		};
	} forEach viruz_flyMonitor;
	*/
	
	//check monitored buildings
	_cursor = 0;
	_delMe = false;
	{
		private["_bPos","_isNoone"];
		_bPos = getPosATL _x;
		_isNoone = {isPlayer _x} count (_bPos nearEntities ["Man",200]) == 0;
		if (_isNoone) then {
			_x setVariable ["zombied",objNull,true];
			viruz_buildingMonitor set [_cursor,"DEL"];
			_delMe = true;
		};
		_cursor = _cursor + 1;
	} forEach viruz_buildingMonitor;
	if (_delMe) then {
		viruz_buildingMonitor = viruz_buildingMonitor - ["DEL"];
	};
	/*
	//check bodies
	_cursor = 0;
	_delMe = false;
	{
		private["_bPos","_isNoone"];
		_bPos = getPosATL _x;
		_isNoone = {isPlayer _x} count (_bPos nearEntities ["Man",50]) == 0;
		if (_isNoone) then {
			deleteVehicle _x;
			viruz_bodyMonitor set [_cursor,"DEL"];
			_delMe = true;
		};
		_cursor = _cursor + 1;
	} forEach viruz_bodyMonitor;
	if (_delMe) then {
		viruz_bodyMonitor = viruz_bodyMonitor - ["DEL"];
	};
	*/
	//Check if new day
	_day = round(360 * (dateToNumber date));
	if(viruz_currentDay != _day) then {
		viruz_sunRise = call world_sunRise;
		viruz_currentDay = _day;
	};

	//wait
	sleep 5;
};