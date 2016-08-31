private ["_sound"];

fnc_code = {
	
	// FM radio ON/OFF
	if !((_this select 0) getVariable ["FMradio_ON", false]) then {
		
		// FM radio ON_timer
		if (count _this > 1) then {
			sleep (_this select 1);
		};

		//playSound3D ["viruz_sound\tracks\evil_main.ogg", (_this select 0), true, getPos (_this select 0), 5, 1, 100];
		
		_sound = createSoundSource ["Sound_FMradio_static", getPos (_this select 0), [], 0];
		(_this select 0) setVariable ["FMradio_ON", true, true];
		(_this select 0) setVariable ["FMradio_SoundSource", _sound, true];
		
		//Alert Zed's to FM radio
		[_this select 0, _sound] spawn {
			while {(_this select 0) getVariable ["FMradio_ON", false]} do {
				_projectile = _this select 1;
				_listTalk = (getPosATL _projectile) nearEntities ["zZombie_Base",100];
				{
					_group = group _x;
					if (isNull group _x) then {
						_group = _x;
					};
					_x reveal [_projectile,4];
					_targets = _group getVariable ["targets",[]];
					if (!(_projectile in _targets)) then {
						_targets set [count _targets,_projectile];
						_group setVariable ["targets",_targets,true];
					};
				} forEach _listTalk;
				sleep 5;
			};
		};
		
		//	FM radio OFF_timer 120 sec
		(_this select 0) spawn {
			sleep 120;
			if (_this getVariable ["FMradio_ON", false]) then {
				deleteVehicle (_this getVariable ["FMradio_SoundSource", nil]);
				_this setVariable ["FMradio_SoundSource", nil, true];
				_this setVariable ["FMradio_ON", false, true];
			};
		};
		
	} else {
		deleteVehicle ((_this select 0) getVariable ["FMradio_SoundSource", nil]);
		(_this select 0) setVariable ["FMradio_SoundSource", nil, true];
		(_this select 0) setVariable ["FMradio_ON", false, true];
	};
};
	
_this addAction [localize "STR_A3_cfgVehicles_Land_FMradio_F0" + " " + localize "str_actions_Electronics_ON_OFF", {[_this select 0] call (_this select 3)}, fnc_code, 1, true, true];
_this addAction [localize "STR_A3_cfgVehicles_Land_FMradio_F0" + " " + localize "str_actions_Electronics_ON_TIMER" + " 30", {if !((_this select 0) getVariable ["FMradio_ON", false]) then {[(_this select 0), 30] call (_this select 3);}}, fnc_code, 1, true, true];
_this addAction [localize "str_actions_TAKE" + " " + localize "STR_A3_cfgVehicles_Land_FMradio_F0", {player playActionNow "PutDown";sleep 1;deleteVehicle ((_this select 0) getVariable ["FMradio_SoundSource", nil]);deleteVehicle (_this select 0); player addItem "FMradio_Mag"}, nil, 1, true, true];