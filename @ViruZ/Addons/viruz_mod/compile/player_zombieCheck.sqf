/*
VirZ Mod
Atuhor: SigWar

spawned by player_monitor.fsm
*/
private ["_refObj",  "_listTalk",  "_pHeight",  "_attacked",  "_multiplier",  "_attackMinTimer", "_attackRndTimer", "_type",  "_dist",  "_chance",  "_last",  "_targets",  "_cantSee",  "_tPos",  "_zPos",  "_eyeDir",  "_inAngle",  "_lowBlood",  "_attackResult", "_near", "_eagua"];

_refObj = vehicle player;
_listTalk = (position _refObj) nearEntities [["Zombie","zZombie_Base"], 200];
_pHeight = (getPosATL _refObj) select 2;
_attacked = false; // at least 1 Z attacked the player
_near = false;
_multiplier = 1;
_attackMinTimer = 5; 
_attackRndTimer = 3; 

{
	_type = "zombie";
	if (alive _x) then {
		private["_dist"];
		_dist = (_x distance _refObj);
		_group = _x;
		_chance = 10 / viruz_monitorPeriod; // Z verbosity
		_attackDist = getNumber(configFile >> "CfgZombieAnims" >> (getText( configFile >> "CfgVehicles" >> (typeOf _x) >> "moves")) >> "attackDist");
		
		if ((_dist <= _attackDist) and !(animationState _x == "AfedPcroMstp_v1")) then {	
			//perform an attack
			
			if !(_x getVariable ["attacked", false]) then {
				_cantSee = [ _refObj,_x] call viruz_losCheck;
				
				if (!_cantSee) then {
					_attackResult = [_x,  _type] spawn player_zombieAttack;
				};
				
				if (!isNil "_attackResult") then {
					_attacked = true;
				} else {
					if (speed _x < 0.2) then {
						if(isNull group _x) then {
							_x moveTo (getPosATL player);
						} else {
							_x doMove (getPosATL player);		
						};
					};
 				};
			};
		} else {
			if (speed _x < 4) then {
				[_x,"idle",(_chance + 4),true] call viruz_zombieSpeak;
			} else {
				[_x,"chase",(_chance + 3),true] call viruz_zombieSpeak;
			};
		};
		
		//Noise Activation
		_targets = _group getVariable ["targets", []];
		if (!(_refObj in _targets)) then {
			if (_dist < VIRUZ_disAudial) then {
				if (VIRUZ_disAudial > 80) then { //65 Orignal: 80
					_targets set [count _targets,  driver _refObj];
					_group setVariable ["targets", _targets, true];				
				} else {
					_chance = [_x, _dist, VIRUZ_disAudial] call viruz_losChance;
					//diag_log ("Visual Detection: " + str([_x, _dist]) + " " + str(_chance));
					if ((random 1) < _chance) then {
						_cantSee = [ _refObj,_x] call viruz_losCheck;
						if (!_cantSee) then {
							_targets set [count _targets,  driver _refObj];
							_group setVariable ["targets", _targets, true];
						} else {
							if (_dist < (VIRUZ_disAudial / 2)) then {
								_targets set [count _targets,  driver _refObj];
								_group setVariable ["targets", _targets, true];
							};
						};
					};
				};
			};
		};
		//Sight Activation
		_targets = _group getVariable ["targets", []];
		if (_dist < 100) then {
			if (!(_refObj in _targets)) then {
				if (_dist < (VIRUZ_disVisual / 2)) then {
					_chance = [_x, _dist, VIRUZ_disVisual] call viruz_losChance;
					//diag_log ("Visual Detection: m" + str([_x, _dist]) + " " + str(_chance));
					if ((random 1) < _chance) then {
						//diag_log ("Chance Detection");
						_tPos = (getPosASL _refObj);
						_zPos = (getPosASL _x);
						
						//_eyeDir = _x call viruz_eyeDir;
						//_eyeDir = direction _x;
						//_inAngle = [_zPos, _eyeDir, 30, _tPos] call fnc_inAngleSector;
						_inAngle = [_x, _refObj, 45] call fnc_inEyeAngleSector;
						
						if (_inAngle) then {
							//LOS check
							_cantSee = [ _refObj, _x] call viruz_losCheck;
							//diag_log ("LOS Check: " + str(_cantSee));
							if (!_cantSee) then {
								//diag_log ("Within LOS! Target");
								_targets set [count _targets,  driver _refObj];
								_group setVariable ["targets", _targets, true];
							};
						};
					};
				};
			};
		};	
	};
} forEach _listTalk;



if (_attacked) then {
	if (r_player_unconscious) then {
		[_refObj, "scream", 6, false] call viruz_zombieSpeak;
	} else {
		_lowBlood = (r_player_blood / r_player_bloodTotal) < 0.4;
		if (_lowBlood) then {
			viruz_panicCooldown = time;
			[_refObj, "panic", 6, false] call viruz_zombieSpeak;
		};
	};
};

// return true if attacked or near. if so,  player_monitor will perform its ridiculous 'while true' loop faster.
(_attacked OR _near)


