private ["_pos", "_posa", "_posb", "_toppos", "_testpos", "_poses", "_posWT", "_int", "_int2", "_int3"];


_v1 = (asltoagl(atltoasl(player modeltoworld (player selectionPosition "Head"))) vectorfromto (positioncameratoworld [0,0,5]));

_v2 = (player modeltoworld [0,0,0]) vectorfromto (player modeltoworld [0,0,-5]);

_cos = _v1 vectorCos _v2;

_dpos = [0,0,0];

if (_cos > 0.8) exitwith
{

	for "_i" from 0 to 20 do   
	{ 
		_intcount = 0;
	
		_posa = player modeltoWorld [0, (_i*0.05), 0.5];   

		_posb = player modeltoWorld [0, (_i*0.05), -1.7];  

		_int = lineintersectsSurfaces [agltoasl _posa, agltoasl _posb, player, objNull, true, 1, "GEOM", "FIRE"]; 
		
		_intcount = (count _int)+_intcount;
		
		
		
		_posa = player modeltoWorld [0, 0, (_i*0.05)];   

		_posb = player modeltoWorld [0, 1.5, (_i*0.05)];  		
		
		_int2 = lineintersectsSurfaces [agltoasl _posa, agltoasl _posb, player, objNull, true, 1, "GEOM", "FIRE"]; 
		
		_intcount = (count _int2)+_intcount;		

		
		
		if (_intcount == 0) then
		{


			_anm = "";

			switch (currentWeapon player) do
			{
				case (""):
				{
					_anm = "babe_drop_ua";
				};
				case (primaryWeapon player):
				{
					_anm = "babe_drop_rfl";
				};
				case (handgunWeapon player):
				{
					_anm = "babe_drop_pst";
				};
			};

			if (_anm != "" && str _dpos != "[0,0,0]") then
			{
			
				EM_climbing = true;

				["EH_em_drop", "animationState player == " + str _anm, [], "babe_em_fnc_exec_drop", [_dpos], true, "babe_em_fnc_finish_drop", [], -1] call babe_core_fnc_addEH;

				player playMove _anm;
			};
		} else
		{
			_dpos = (_int select 0) select 0;

		};
	};
};


	_pos = [0,0,0];

	_posa = [0,0,0];

	_posb = [0,0,0];

	_toppos = [0,0,0];

	_goodZ = [];

	_blocked = false;

	_top = false;

	_poses = [];

	_int = [];

	_obj = player;

	for "_i" from 0 to 60 do   
	{ 
		_posa = player modeltoWorld [0, 0, (_i*0.05)];   

		_posb = player modeltoWorld [0, 1.5, (_i*0.05)+ 0.1];   

		_int = lineintersectsSurfaces [agltoasl _posa, agltoasl _posb, player, objNull, true, 1, "GEOM", "FIRE"]; 


		_respos = (_int select 0) select 0;

		_succ = count _int > 0;


		if (_succ) then
		{
			_obj = (_int select 0) select 3;

			if (EM_debug) then
			{
				drawLine3D [_posa, _posb, [1,0,0,1]];
			};

			_testpos = (_int select 0) select 0;

			_posWT = player worldToModel (asltoagl _testpos);

			if (_posWT select 2 > 0.5) then
			{
				_pos = _testpos;
				_goodZ pushback (_posWT select 1);
			};
		} else
		{
			if (str _pos != "[0,0,0]") then
			{
				_ppWT = (player worldtomodel (asltoagl _pos)) select 2;
				_tpWT = (_i*0.05)+ 0.1;

				_dst = (_ppWT max _tpWT) - (_ppWT min _tpWT);
	
				if (EM_debug) then
				{	
					drawLine3D [_posa, _posb, [0,1,1,1]];
				};

				_posWT = player worldToModel (asltoagl _pos);

				if (!(_pos in _poses) && _posWT select 2 > 0.5 && _dst > 0.5) then
				{
					_poses pushback _pos;
				};

			};
		};
	};




	if (count _poses > 0) then
	{
		_pos = _poses select 0;
	};




	_posWT = player worldToModel (asltoagl _pos);

	_posa = player modeltoWorld [_posWT select 0, (_posWT select 1) + 0.75, (_posWT select 2) + 0.5];

	_posb = player modeltoWorld [_posWT select 0, (_posWT select 1) + 0.75, (_posWT select 2) - 5];

	_toptest = lineintersectsSurfaces [agltoasl _posa, agltoasl _posb, player, objNull, true, 1, "GEOM", "FIRE"];
	_toppos = (_toptest select 0)select 0;

	_postopos = ((_toptest select 0)select 3);

	_top = !isNil "_postopos";

	if (!_top) then 
	{
		_toppos = agltoasl(player modeltoworld [0,2,0]);
	}else
	{		
		_a = abs (_pos select 2);
		_b = abs (_toppos select 2);

		_max = _a max _b;

		if (_max == _a) then 
		{
			if (_a - _b > 0.6) then
			{
				_top = false;
				if (_a-_b > 1.8) then
				{
					_toppos = agltoasl(player modeltoworld [0,2,0]);
				};
			} else
			{
				_top = true
			};
		}else
		{
			_top = true;
		};
	};

	if (str _pos != "[0,0,0]" && _top) then
	{
		_avZ = 0;
		_min = 999;
		_max = 0;
		for "_i" from 0 to (count _goodZ)-1 do   
		{ 
			_z = _goodZ select _i;

			if (_i > 0) then
			{
				_min = _min min _z;	
				_max = _max max _z;
			};

			_avZ = _avZ + _z;
		};

		if (_max - _min > 0.5) then
		{
			_avZ = _avZ/(count _goodZ);

			_pos = agltoasl (player modeltoworld [_posWT select 0, _avZ, _posWT select 2]);
		};
	};


	_posWT = player worldToModel (asltoagl _pos);


	_bone = player selectionPosition "Spine3";

	_posa = player modeltoWorld _bone;

	_posb = player modeltoWorld [_bone select 0, _bone select 1, (_posWT select 2)+0.5];

	_int2 = lineintersectsSurfaces [agltoasl _posa, agltoasl _posb, player, objNull, true, 1, "GEOM", "FIRE"];



	_posa = player modeltoworld [0,0, (_posWT select 2) + 0.2];

	_posb = player modeltoworld [_posWT select 0, (_posWT select 1)+ 0.2, (_posWT select 2) + 0.2];

	_int3 = lineintersectsSurfaces [agltoasl _posa, agltoasl _posb, player, objNull, true, 1, "GEOM", "FIRE"];


	_blocked = ((count _int2) + (count _int3) > 0);


	if (_blocked) then
	{
		_pos = [0,0,0];
	};

	if (!_top && _obj != player && _obj isKindOf "CaManBase") then 
	{
		_pos = [0,0,0];
	};

	_wide = true;

	if (!_top) then
	{
		_posWT = player worldToModel asltoagl _pos;

		_a = agltoasl (player modeltoworld [(_posWT select 0) + 0.3, _posWT select 1, (_posWT select 2)+0.2]);

		_b = agltoasl (player modeltoworld [(_posWT select 0) - 0.3, _posWT select 1, (_posWT select 2)+0.2]);

		_c = agltoasl (player modeltoworld [(_posWT select 0) + 0.3, (_posWT select 1) + 0.1, (_posWT select 2)+0.2]);

		_d = agltoasl (player modeltoworld [(_posWT select 0) - 0.3, (_posWT select 1) - 0.1, (_posWT select 2)+0.2]);

		_e = agltoasl (player modeltoworld [(_posWT select 0) + 0.3, (_posWT select 1) - 0.1, (_posWT select 2)+0.2]);

		_f = agltoasl (player modeltoworld [(_posWT select 0) - 0.3, (_posWT select 1) + 0.1, (_posWT select 2)+0.2]);

		_int1 = lineintersectsSurfaces [_a, _b, player, objNull, true, 1, "GEOM", "FIRE"]; 

		_int2 = lineintersectsSurfaces [_c, _d, player, objNull, true, 1, "GEOM", "FIRE"]; 

		_int3 = lineintersectsSurfaces [_e, _f, player, objNull, true, 1, "GEOM", "FIRE"]; 

		_wide = (count _int1) + (count _int2) + (count _int3) == 0;

	};
	if (EM_debug) then
	{
		systemchat str [(count _int2), (count _int3), _wide, _top, _pos];
		babe_em_debug_a setposasl (_poses select 0);
	};
	if !_wide then 
	{
		_pos = [0,0,0];
	};

	[_pos, _top, _toppos] call babe_em_fnc_em;







