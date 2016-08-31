	_id = _this select 0;
	_cond = _this select 1;
	_condpars = _this select 2;
	_fnc = _this select 3;
	_pars = _this select 4;
	_switch = _this select 5;
	_switchfnc = _this select 6;
	_switchpars = _this select 7;
	_delay = _this select 8;

	if (count babe_core_EHs > 0) then
	{
		for "_i" from 0 to (count babe_core_EHs)-1 do
		{
			if ((babe_core_EHs select _i) select 0 == _id) then
			{
				[_id] call babe_core_fnc_removeEH;
			};
		};
	};

        babe_core_EHs pushback [_id, _cond, _condpars, _fnc, _pars, _switch, _switchfnc, _switchpars, _delay];   

	call compile ( _id + "_timer = diag_tickTime;");
