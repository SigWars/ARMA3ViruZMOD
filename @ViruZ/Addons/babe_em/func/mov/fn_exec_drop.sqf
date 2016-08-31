	_pos = _this select 0;

	_endpos = [_pos select 0, _pos select 1, (_pos select 2)-1.9];

	_help = babe_em_help;

	_help setposASL _endpos;

	_help setdir getdir player;

	_poswt = player worldtomodel (asltoagl _endpos);

	player setposASL (agltoasl (player modeltoworld [_posWT select 0, (_posWT select 1)+0.1, (_posWT select 2) + 0.1]));