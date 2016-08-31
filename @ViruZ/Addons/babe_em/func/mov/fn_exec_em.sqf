private ["_pos"];

	_pos = _this select 0;

	_over = _this select 1;
	

	
	_help = babe_em_help;

	_help setposASL _pos;

	_help setdir getdir player;

	_poswt = player worldtomodel (asltoagl _pos);

	if (_over) then
	{ 
		player setposASL (agltoasl (player modeltoworld [_posWT select 0, _posWT select 1, (_posWT select 2) + 0.1]));
	} else
	{
		player setposASL (agltoasl (player modeltoworld [_posWT select 0, (_posWT select 1)+0.1, (_posWT select 2) + 0.1]));
	};