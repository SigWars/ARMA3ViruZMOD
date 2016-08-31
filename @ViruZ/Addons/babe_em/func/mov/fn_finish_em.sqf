private ["_toppos"];

	["EH_em"] call babe_core_fnc_removeEH;

	_toppos = _this select 0;

	_over = _this select 1;
	
	_stmpn = _this select 2;
	

	
	player setStamina (getStamina player)-_stmpn;

	_help = babe_em_help;

	if (_over) then
	{ 
		player setposASL _toppos;
	};

	_help setpos [0,0,0];

	EM_busy = false;
	EM_climbing = false;
	player setAnimSpeedCoef 1;