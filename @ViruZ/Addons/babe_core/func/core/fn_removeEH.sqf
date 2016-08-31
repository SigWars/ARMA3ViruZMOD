        _EHid = _this select 0;

	for [{_i=0}, {_i < count babe_core_EHs}, {_i=_i+1}] do
	{
                _EH = babe_core_EHs select _i;
                _id = _EH select 0;

        	if (_EHid == _id) then
		{
			babe_core_EHs deleteAt _i;
                        missionNameSpace setvariable [_EHid, nil];
		};
	};      