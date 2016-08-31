private["_unit","_targets","_move","_damage","_wound","_index","_cnt","_sound","_local","_dir","_hpList","_hp","_strH","_dam","_total","_vehicle","_tPos","_zPos","_cantSee","_inAngle"];
_unit = _this select 0;
_type = _this select 1;
_vehicle = (vehicle player);

private["_cfgUnit", "_zIdleAnims", "_zAttackAnims", "_zAggraAnims"];
_cfgUnit = configFile >> "CfgVehicles" >> (typeOf _unit);
_zIdleAnims = [_unit, "idle"] call ptm_fnc_zGetAnims;
_zAttackAnims = [_unit, "attack"] call ptm_fnc_zGetAnims;
_zAggraAnims = [_unit, "aggra"] call ptm_fnc_zGetAnims;

//function
_viruz_zmb_Attack = {
	private ["_vehicle","_VZ_hitchance","_unit"];
	_vehicle = _this select 0;
	_unit = _this select 1;
	_VZ_hitchance = round(random 10);

if (_vehicle != player) then {
	_hpList = 	_vehicle call vehicle_getHitpoints;
	_hp = 		_hpList call BIS_fnc_selectRandom;
	_wound = 	getText(configFile >> "cfgVehicles" >> (typeOf _vehicle) >> "HitPoints" >> _hp >> "name");
	_damage = 	random 0.08;
	_chance =	round(random 12);
	
	if ((_chance % 4) == 0) then {
		_openVehicles = ["Quadbike_01_base_F", "Motorcycle", "Bicycle"];
		{
			if (_vehicle isKindOf _x) exitWith {
				player action ["eject", _vehicle];
			};
		} forEach _openVehicles;
	};

	if ((_wound == "Glass1") or (_wound == "Glass2") or (_wound == "Glass3") or (_wound == "Glass4") or (_wound == "Glass5") or (_wound == "Glass6")) then {
		[_unit,"hit",4,false] call viruz_zombieSpeak;
		_strH = "hit_" + (_wound);
		_dam = _vehicle getVariable [_strH,0];
		_total = (_dam + _damage);

		//diag_log ("Hitpoints " +str(_wound) +str(_total));

		if (_total >= 1) then {
			if (r_player_blood < (r_player_bloodTotal * 0.8)) then {
				_cnt = count (VIRUZ_woundHit select 1);
				_index = floor (random _cnt);
				_index = (VIRUZ_woundHit select 1) select _index;
				_wound = (VIRUZ_woundHit select 0) select _index; 
			} else {
				_cnt = count (VIRUZ_woundHit_ok select 1);
				_index = floor (random _cnt);
				_index = (VIRUZ_woundHit_ok select 1) select _index;
				_wound = (VIRUZ_woundHit_ok select 0) select _index; 
			};
			_damage = 1.0 + random (1.2);
			//diag_log ("START DAM: Player Hit on " + _wound + " for " + str(_damage));
			[player, _wound, _damage, _unit,"zombie"] call fnc_usec_damageHandler;
			[_unit,"hit",2,false] call viruz_zombieSpeak;	
		} else {
			viruzHitV =	[_vehicle, _wound, _total, _unit,"zombie"];
			publicVariable "viruzHitV";
		};
	};
} else {
	//Did he hit?
	
	if ((_unit distance player) <= 3 and _VZ_hitchance < zombie_hitchance) then {
		//check LOS // <= 3
		private[];
		_tPos = (getPosASL _vehicle);
		_zPos = (getPosASL _unit);
		_inAngle = [_zPos,(getdir _unit),50,_tPos] call BIS_fnc_inAngleSector;
		if (_inAngle) then {
			//LOS check
			_cantSee = [_unit,_vehicle] call viruz_losCheck;
			if (!_cantSee) then {
				if (r_player_blood < (r_player_bloodTotal * 0.8)) then {
					_cnt = count (VIRUZ_woundHit select 1);
					_index = floor (random _cnt);
					_index = (VIRUZ_woundHit select 1) select _index;
					_wound = (VIRUZ_woundHit select 0) select _index; 
				} else {
					_cnt = count (VIRUZ_woundHit_ok select 1);
					_index = floor (random _cnt);
					_index = (VIRUZ_woundHit_ok select 1) select _index;
					_wound = (VIRUZ_woundHit_ok select 0) select _index; 
				};
				_damage = zombie_mindamage + random (zombie_adddamage);
					
				//diag_log ("START DAM: Player Hit on " + _wound + " for " + str(_damage));
				[player, _wound, _damage, _unit,"zombie"] call fnc_usec_damageHandler;
				[_unit,"hit",2,false] call viruz_zombieSpeak;
			};
		};
	};
};
};


//Do the attack
if (r_player_unconscious && _vehicle == player && _type == "zombie") then {
	_move = "AfedPcroMstp_v1";
} else {
	if (_type == "zombie" or _type == "zZombie_Base") then {
		_move = _zAttackAnims call BIS_fnc_selectRandom;
	} else {
		_move = "Dog_Attack";
	};
};

_dir = [_unit,player] call BIS_Fnc_dirTo;
_unit setDir _dir;

if (local _unit) then {
	_unit playMove _move;
} else {
	//[[_unit, _move],"playMove", _unit] call BIS_fnc_MP;
	[_unit, _move] remoteExec ["playMove", _unit];
};

_unit setVariable ["attacked", true, true];
waitUntil {sleep 0.01; (animationState _unit) == _move};
[_vehicle,_unit] call _viruz_zmb_Attack;
_debugTimer = diag_tickTime + 3;
waitUntil {sleep 0.01; ((animationState _unit) in _zIdleAnims) || (diag_tickTime > _debugTimer)};

_unit setVariable ["attacked", false, true];

/*if (random 1 <= 0.1) then { //0.1 ori
	// aggravated action
	_handler = [_unit, _move, _zIdleAnims, _zAggraAnims] spawn {
		params["_unit", "_move", "_zIdleAnims", "_zAggraAnims"];
	
		_unit setDir ([_unit, player] call BIS_Fnc_dirTo);
		_move = _zAggraAnims call BIS_fnc_selectRandom;
		
		if (local _unit) then {
			_unit playMove _move;
		} else {
			//[[_unit, _move],"playMove", _unit] call BIS_fnc_MP;
			[_unit, _move] remoteExec ["playMove", _unit];
		};

		waitUntil {sleep 0.01; (animationState _unit) == _move};
		_debugTimer = diag_tickTime + 3.5;
		waitUntil {sleep 0.01; ((animationState _unit) in _zIdleAnims) || (diag_tickTime > _debugTimer)};
	
		_unit setVariable ["attacked", false, true];
	};
} else {
	_unit setVariable ["attacked", false, true];
};*/

//Wait
//sleep 0.5;
