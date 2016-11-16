private["_array","_source","_kills","_killsV","_humanity","_wait","_myKills"];
if (deathHandled) exitWith {};

deathHandled = true;
//Death

_body =		player;
_playerID =	getPlayerUID player;

//Send Death Notice
//["viruzDeath",[viruz_characterID,0,_body,_playerID,viruz_playerName]] call callRpcProcedure;
		viruzDeath = [viruz_characterID,0,_body,_playerID,viruz_playerName];
		publicVariable "viruzDeath";

_id = [player,20,true,getPosATL player] spawn player_alertZombies;

sleep 0.5;

player setDamage 1;
0.1 fadeSound 0;

player setVariable ["NORRN_unconscious", false, true];
player setVariable ["unconsciousTime", 0, true];
player setVariable ["USEC_isCardiac",false,true];
player setVariable ["medForceUpdate",true,true];
//remove combat timer on death
player setVariable ["startcombattimer", 0, true];
r_player_unconscious = false;
r_player_cardiac = false;

_id = player spawn spawn_flies;

_humanity =		0;
_wait = 		0;

_array = _this;
if (count _array > 0) then {
	_source = _array select 0;
	_method = _array select 1;
//	_method = "temp";
    if (isNil "_method") then {
        _method = "unknown";
    };
	if (!isNull _source) then {
		if (_source != player) then {
			_canHitFree = 	player getVariable ["freeTarget",false];
			_isBandit = (["Bandit",typeOf player,false] call fnc_inString);
			_myKills = 		((player getVariable ["humanKills",0]) / 30) * 1000;
			if (!_canHitFree and !_isBandit) then {
				//Process Morality Hit
				_humanity = -(2000 - _myKills);
				_kills = 		_source getVariable ["humanKills",0];
				_source setVariable ["humanKills",(_kills + 1),true];
				_wait = 300;
			} else {
				//Process Morality Hit
				//_humanity = _myKills * 100;
				_killsV = 		_source getVariable ["banditKills",0];
				_source setVariable ["banditKills",(_killsV + 1),true];
				_wait = 0;
			};
			if (_humanity < 0) then {
				_wait = 0;
			};
			if (!_canHitFree and !_isBandit) then {
				
				viruzHumanity = [_source,_humanity,_wait];
				publicVariable "viruzHumanity";
			};
		};
	};
	_body setVariable ["deathType",_method,true];
};

terminate viruz_musicH;
//terminate viruz_lootCheck;
terminate viruz_slowCheck;
terminate viruz_animalCheck;
terminate viruz_monitor1;
terminate viruz_medicalH;
terminate viruz_gui;
//terminate viruz_zedCheck;
//terminate viruz_locationCheck;
//terminate viruz_combatCheck;
terminate viruz_spawnCheck;

//Reset (just in case)
//deleteVehicle viruz_playerTrigger;
disableUserInput false;
r_player_dead = true;

"dynamicBlur" ppEffectEnable true;"dynamicBlur" ppEffectAdjust [4]; "dynamicBlur" ppEffectCommit 0.2;

"colorCorrections" ppEffectEnable true;
"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.01],  [1, 1, 1, 0.0]];
"colorCorrections" ppEffectCommit 1;

//Player is Dead!
3 fadeSound 0;
0 cutText ["", "BLACK",10];
viruz_DeathActioned = true;
sleep 1;

TitleText[localize "str_player_12","PLAIN DOWN",5];

viruz_originalPlayer enableSimulation true;

addSwitchableUnit viruz_originalPlayer;
setPlayable viruz_originalPlayer;
selectPlayer viruz_originalPlayer;

_myGroup = group _body;
[_body] joinSilent viruz_firstGroup;
deleteGroup _myGroup;

3 cutRsc ["default", "PLAIN",3];
4 cutRsc ["default", "PLAIN",3];
/*
if (count _array > 0) then {
	_body setVariable ["deathType",_method,true];
};
*/
_body setVariable["combattimeout", 0, true];

//["viruzFlies",player] call broadcastRpcCallAll;
sleep 2;

1 cutRsc ["DeathScreen","BLACK OUT",3];


playMusic "viruz_track_death_1";

"dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 1],  [1, 1, 1, 1]];"colorCorrections" ppEffectCommit 5;