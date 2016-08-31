//diag_log "running location check...";
{
	private ["_location","_distCfg","_configClass","_distAct","_config","_position"];
	_location = 	_x select 0;
	_distCfg = 		(_x select 2) + 200;
	_configClass =  _x select 1;
	_distAct = player distance position _location;
	
	if ((_distAct < _distCfg) and !(_location in viruz_locationsActive)) then {
		//Record Active Location
		//diag_log "Load!";
		viruz_locationsActive set [count viruz_locationsActive,_location];
		
		//Get Town Details
		_config = 	configFile >> "CfgTownGenerator" >> _configClass;
		_locHdr = 	configName _config;
		_position = []+ getArray	(_config >> "position");
		
		_config call stream_locationFill;
		//player sidechat (_locHdr + " " + str(count _config));
	} else {
		if ((_distAct > _distCfg) and (_location in viruz_locationsActive)) then {
			//Delete Town Objects
			_config = 	configFile >> "CfgTownGenerator" >> _configClass;
			_config call stream_locationDel;
			viruz_locationsActive = viruz_locationsActive - [_location];
		};
	};
} forEach viruz_Locations;