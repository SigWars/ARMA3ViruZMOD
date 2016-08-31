private ["_pos", "_toppos"];

	_st = stance player;
	_stnope = ["PRONE", "UNDEFINED"];

	if (EM_climbing or (damage player) > 0.85 or (getStamina player) < 1 or _st in _stnope or vehicle player != player) exitwith {};

	EM_busy = true;

	_pos = _this select 0;
	_top = _this select 1;
	_toppos = _this select 2;


	_anm = "";
	
	_stmpn = 2;

	if (str _pos == "[0,0,0]") exitwith
	{
		if (isTouchingGround player && !EM_climbing && (getstamina player > 8)) then
		{
			call babe_em_fnc_jump
		};
	};

	_h = ((player worldToModel asltoagl _pos) select 2) max 0;

	_stepa = EM_heightsOn select 0;
	_stepb = EM_heightsOn select 1;

	_ona = EM_heightsOn select 1;
	_onb = EM_heightsOn select 2;

	_onha = EM_heightsOn select 2;
	_onhb = EM_heightsOn select 3;

	_onhera = EM_heightsOn select 3;
	_onherb = EM_heightsOn select 4;


	_vaulta = EM_heightsOver select 0;
	_vaultb = EM_heightsOver select 1;

	_overa = EM_heightsOver select 1;
	_overb = EM_heightsOver select 2;

	_overha = EM_heightsOver select 2;
	_overhb = EM_heightsOver select 3;

	_overhera = EM_heightsOver select 3;
	_overherb = EM_heightsOver select 4;

	_wl1 = EM_weightlimits select 0;

	_wl2 = EM_weightlimits select 1;

	_wl3 = EM_weightlimits select 2;


	_over = false;

	if (_top) then
	{

		switch (true) do
		{
			case (_h > _onhera && _h <= _onherb):
			{
				_stmpn = 10;
				switch (currentWeapon player) do
				{
					case (""):
					{
						_anm = "babe_climbonHer_ua";
					};
					case (primaryWeapon player):
					{
						_anm = "babe_climbonHer_rfl";
					};
					case (handgunWeapon player):
					{
						_anm = "babe_climbonHer_pst";
					};
				};
			};
			case (_h > _onha && _h < _onhb):
			{
				_stmpn = 8;
				switch (currentWeapon player) do
				{
					case (""):
					{
						_anm = "babe_climbonH_ua";
					};
					case (primaryWeapon player):
					{
						_anm = "babe_climbonH_rfl";
					};
					case (handgunWeapon player):
					{
						_anm = "babe_climbonH_pst";
					};
				};
			};
			case (_h > _ona && _h <= _onb):
			{
				_stmpn = 6;
				switch (currentWeapon player) do
				{
					case (""):
					{
						_anm = "babe_climbon_ua";
					};
					case (primaryWeapon player):
					{
						_anm = "babe_climbon_rfl";
					};
					case (handgunWeapon player):
					{
						_anm = "babe_climbon_pst";
					};
				};
			};
			case (_h > _stepa && _h <= _stepb):
			{
				_stmpn = 2;
				switch (currentWeapon player) do
				{
					case (""):
					{
						_anm = "babe_stepon_ua";
					};
					case (primaryWeapon player):
					{
						_anm = "babe_stepon_rfl";
					};
					case (handgunWeapon player):
					{
						_anm = "babe_stepon_pst";
					};
				};
			};
		};
	} else
	{
		switch (true) do
		{
			case (_h > _overhera && _h <= _overherb):
			{
				_stmpn = 10;
				switch (currentWeapon player) do
				{
					case (""):
					{
						_anm = "babe_climboverHer_ua";
					};
					case (primaryWeapon player):
					{
						_anm = "babe_climboverHer_rfl";
					};
					case (handgunWeapon player):
					{
						_anm = "babe_climboverHer_pst";
					};
				};
			};
			case (_h > _overha && _h <= _overhb):
			{
				_stmpn = 8;
				switch (currentWeapon player) do
				{
					case (""):
					{
						_anm = "babe_climboverH_ua";
					};
					case (primaryWeapon player):
					{
						_anm = "babe_climboverH_rfl";
					};
					case (handgunWeapon player):
					{
						_anm = "babe_climboverH_pst";
					};
				};
			};
			case (_h > _overa && _h < _overb):
			{
				_stmpn = 6;
				switch (currentWeapon player) do
				{
					case (""):
					{
						_anm = "babe_climbover_ua";
					};
					case (primaryWeapon player):
					{
						_anm = "babe_climbover_rfl";
					};
					case (handgunWeapon player):
					{
						_anm = "babe_climbover_pst";
					};
				};
			};
			case (_h > _vaulta && _h <= _vaultb):
			{
				_stmpn = 4;
				switch (currentWeapon player) do
				{
					case (""):
					{
						_anm = "babe_vaultover_ua";
					};
					case (primaryWeapon player):
					{
						_anm = "babe_vaultover_rfl";
					};
					case (handgunWeapon player):
					{
						_anm = "babe_vaultover_pst";
					};
				};
			};
		};
	_over = true;	
	};
	if (_anm == "") exitwith 
	{
		if (isTouchingGround player && !EM_climbing && (getstamina player > 8)) then
		{
			call babe_em_fnc_jump			
		};
	};
	EM_climbing = true;

	["EH_em", "animationState player == " + str _anm, [], "babe_em_fnc_exec_em", [_pos, _over], true, "babe_em_fnc_finish_em", [_toppos, _over, _stmpn], -1] call babe_core_fnc_addEH;
	player setAnimSpeedCoef 1-(load player)*0.3;
	player playMove _anm;
