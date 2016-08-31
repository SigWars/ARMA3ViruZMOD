
if (isServer) then {
	_this spawn {
	
		private ["_location","_locationRadiusA","_genDist","_active","_wreckObjects","_inBuildingsObjects","_buildingPosters","_checkWindow"];
		
		_location = _this;
		_locationRadiusA = getNumber (configFile >> "cfgWorlds" >> worldName >> "Names" >> className _location >> "RadiusA");
		_genDist = 400;
		_active = false;
//		_checkWindow = false;
		_wreckObjects = [];
		_inBuildingsObjects = [];
		//_buildingPosters = [];
		
		while {!(isNull _location)} do {
			_dist = 10000;
			{
				if (isPlayer _x) then {
					_checkDist = (getPos _x distance _location) - _locationRadiusA;
					if (_dist > _checkDist) then {_dist = _checkDist};
				};
			} forEach allUnits;

			if !(_active) then {
				if (_dist < _genDist) then {					
					_wreckObjects = _location call server_WreckSpawner;
					_inBuildingsObjects = _location call server_ObjectInBuildingSpawner;
					//_buildingPosters = [_locationRadiusA, 10, 0.5, locationPosition _location] call PTm_fnc_modulePoster;
					/*
					if !(_checkWindow) then {
						[_locationRadiusA, locationPosition _location] call PTm_fnc_windowsAreBroke;
						_checkWindow = true;
					};
					*/
					_active = true;
				};
			} else {
				if (_dist > (_genDist + _genDist/10)) then {
				
					{deleteVehicle _x} forEach _wreckObjects;
					_wreckObjects = [];
					
					{deleteVehicle _x} forEach (_inBuildingsObjects select 1);
					{_x setVariable ["ObjectInBuilding", false, true]} forEach (_inBuildingsObjects select 0);
					_inBuildingsObjects = [];
					
					//{deleteVehicle _x} forEach (_buildingPosters select 1);
					//{_x setVariable ["checkPoster", false, true]} forEach (_buildingPosters select 0);
					//_buildingPosters = [];
					
					diag_log (format["OBJECTSPAWNERMONITOR: groundWeaponHolder_2 objects : %1 : %2", (text _this), count (nearestObjects [(locationPosition _location),["groundWeaponHolder_2"],_locationRadiusA])]);
					{
						deleteVehicle _x;
					} forEach (nearestObjects [(locationPosition _location),["groundWeaponHolder_2"],_locationRadiusA]);
					
					_active = false;
					
					//diag_log (format["OBJECTSPAWNERMONITOR: Delete objects. Location : %1", text _this]);
				};
			};

			sleep 2;
		};
	};
};