private["_refObj","_size","_vel","_speed","_hunger","_thirst","_array","_unsaved","_timeOut","_result","_lastSave"];
disableSerialization;

_timeOut = 	0;
_messTimer = 0;
_healtime = 0;
_lastSave = 0;
_lastTemp = viruz_temperatur;
_debug = getMarkerpos "respawn_west";
_isBandit = false;
_isHero = false;
_mylastPos = getPosATL player;

player setVariable ["temperature",viruz_temperatur,true];

viruz_myLoad = loadAbs player;

	//player addMagazine "Hatchet_swing";
	//player addWeapon "MeleeHatchet";

while {true} do {
	//Initialize
	_refObj = 	vehicle player;
	_size = 	(sizeOf typeOf _refObj) * 0.6; //.6
	_vel = 		velocity player;
	_speed = 	round((_vel distance [0,0,0]) * 3.5);
	_saveTime = (playersNumber west * 2) + 10;
		
	//reset position
	_randomSpot = true;
	_tempPos = getPosATL player;
	_distance = _debug distance _tempPos;
	if (_distance < 2000) then {
		_randomSpot = false;
	};	
	_distance = [0,0,0] distance _tempPos;
	if (_distance < 500) then {
		_randomSpot = false;
	};
	/*
	if (!isNil "_mylastPos") then {
		_distance = _mylastPos distance _tempPos;
		if (_distance > 400) then {
			_randomSpot = false;
		};
	};
	*/
	if (_randomSpot) then {
		_mylastPos = _tempPos;
	};
	
	if (!isNil "_mylastPos") then {
		viruz_mylastPos = _mylastPos;
	};
	viruz_areaAffect = _size;
	
	//CheckVehicle
	/*
	if (_refObj != player) then {
		_isSync =_refObj getVariable ["ObjectID",0] > 0;
		if (!_isSync) then {
			_veh allowDamage true;
			_veh setDamage 1;
			player setDamage 1;			
		};
	};
	*/
	
	if (_speed > 0.1) then {
		_timeOut = _timeOut + 1;
	};
	
	_humanity = player getVariable ["humanity",0];
	if (_timeOut > 150) then {
		_timeOut = 0;
		if (_humanity < 2500) then {
			_humanity = _humanity + 150;
			_humanity = _humanity min 2500;
			player setVariable ["humanity",_humanity,true];
		};
	};
	/*
	if (_humanity < -2000 and !_isBandit) then {
		_isBandit = true;
		_model = typeOf player;
		if (_model == "Survivor2_DZ") then {
			[viruz_playerUID,viruz_characterID,"Bandit1_DZ"] spawn player_humanityMorph;
		};
		if (_model == "SurvivorW2_DZ") then {
			[viruz_playerUID,viruz_characterID,"BanditW1_DZ"] spawn player_humanityMorph;
		};
	};
	
	if (_humanity > 0 and _isBandit) then {
		_isBandit = false;
		_model = typeOf player;
		if (_model == "Bandit1_DZ") then {
			[viruz_playerUID,viruz_characterID,"Survivor2_DZ"] spawn player_humanityMorph;
		};
		if (_model == "BanditW1_DZ") then {
			[viruz_playerUID,viruz_characterID,"SurvivorW2_DZ"] spawn player_humanityMorph;
		};
	};
	
	if (_humanity > 5000 and !_isHero) then {
		_isBandit = false;
		_model = typeOf player;
		if (_model == "Survivor2_DZ") then {
			[viruz_playerUID,viruz_characterID,"Survivor3_DZ"] spawn player_humanityMorph;
		};
	};
	*/
	//Has infection?
	//if (r_player_infected) then {
	//	[player,"cough",8,false] call viruz_zombieSpeak;
	//};

	//Record Check
	_lastUpdate = 	time - viruZ_lastPlayerUpdate;
	if (_lastUpdate > 20) then { //orinal valor 8
		//POSITION?
		_distance = viruz_myPosition distance player;
		if (_distance > 10) then {
			//Player has moved
			viruz_myPosition = getPosATL player;
			player setVariable["posForceUpdate",true,true];
			viruz_unsaved = true;
			viruZ_lastPlayerUpdate = time;
		};
	};

	//Hunger
	//_hunger = +((((r_player_bloodTotal - r_player_blood) / r_player_bloodTotal) * 5) + _speed + viruz_myLoad) * 3;
	if ( _refObj == player ) then {
		_hunger = +(((r_player_bloodTotal - r_player_blood) / r_player_bloodTotal) * 5) + (_speed * 2);
	} else {
		_hunger = +(((r_player_bloodTotal - r_player_blood) / r_player_bloodTotal) * 5);
	};
	
	if (time - viruz_panicCooldown < 120) then {
		_hunger = _hunger * 2;
	};
	viruz_hunger = viruz_hunger + (_hunger / 37); //360 Default
	
	if (viruz_hunger > 2250) then {
		viruz_hunger = 2250;
	};

	//Thirst
	_thirst = 2;
	if (_refObj == player) then {
		_thirst = (_speed + 4) * 3;
	};
	viruz_thirst = viruz_thirst + (_thirst / 60) * (viruz_temperatur / viruz_temperaturnormal);	//TeeChange Temperatur effects added Max Effects: -25% and + 16.6% waterloss
	
	if (viruz_thirst > 1550) then {
		viruz_thirst = 1550;
	};
	
	//Temperatur
	2 call player_temp_calculation; //2 = sleep time of this loop		//TeeChange
	if ((_lastTemp - viruz_temperatur) > 0.75 or (_lastTemp - viruz_temperatur) < -0.75 ) then {
		player setVariable ["temperature",viruz_temperatur,true];
		_lastTemp = viruz_temperatur;
	};
	
	//can get nearby infection
	if (!r_player_infected) then {
		//	Infectionriskstart
		if (viruz_temperatur < ((80 / 100) * (viruz_temperaturnormal - viruz_temperaturmin) + viruz_temperaturmin)) then {	//TeeChange
			_listTalk = _mylastPos nearEntities ["CAManBase",8];
			{
				if (_x getVariable["USEC_infected",false]) then {
					_rnd = (random 1) * (((viruz_temperaturnormal - viruz_temperatur) * (100 /(viruz_temperaturnormal - viruz_temperaturmin)))/ 50);	//TeeChange
					if (_rnd < 0.1) then {
						_rnd = random 1;
						if (_rnd > 0.7) then {
							r_player_infected = true;
							//player setVariable["USEC_infected",true];
						};
					};
				};
			} forEach _listTalk;
			if (viruz_temperatur < ((50 / 100) * (viruz_temperaturnormal - viruz_temperaturmin) + viruz_temperaturmin)) then {	//TeeChange
				_rnd = (random 1) * (((viruz_temperaturnormal - viruz_temperatur) * (100 /(viruz_temperaturnormal - viruz_temperaturmin)))/ 25);	//TeeChange
				if (_rnd < 0.05) then {
					_rnd = random 1;
					if (_rnd > 0.95) then {
						r_player_infected = true;
						//player setVariable["USEC_infected",true];
					};
				};
			};
		};
	};
	
	//If has infection reduce blood cough and add shake
	if (r_player_infected) then {
		if !(player getVariable["USEC_infected",false]) then { 
			player setVariable["USEC_infected",true,true];  
		};
		
		_rnd = ceil (random 8);
		[player,"cough",_rnd,false,9] call viruz_zombieSpeak;
		
		if (_rnd < 3) then {
			addCamShake [2, 1, 25];
		};
		if (r_player_blood > 3000) then {
			r_player_blood = r_player_blood - 3;
			player setVariable["USEC_BloodQty",r_player_blood];
		};
	};
	
	//auto regen life
	if (!r_player_infected and r_player_blood < 8000 and viruz_combat == 0 and _speed < 0.1 and viruz_hunger < 1500 and viruz_thirst < 1499 ) then {
		_healtime = _healtime + 1;
		if (_healtime > 5) then {
			_healtime = 0;
			r_player_blood = r_player_blood + 100;
			player setVariable["USEC_BloodQty",r_player_blood];
			[
				"<t color='#FF0000' size = '0.5'>HEALING!</t>", 
				0.24 * safezoneW + safezoneX,
				0.01 * safezoneH + safezoneY,
				1,
				1,
				0,
				0
			] spawn bis_fnc_dynamicText;
		};
	};
	
	//Pain Shake Effects
	if (r_player_inpain and !r_player_unconscious) then {
		playSound "breath_1";
		addCamShake [2, 1, 25];
	};
	
	//Hunger Effect
	_foodVal = 		viruz_statusArray select 0;
	_thirstVal = 	viruz_statusArray select 1;
	if (_thirstVal <= 0) then {
		_result = r_player_blood - 10;
		if (_result < 0) then {
			_id = [player,"dehyd"] spawn player_death;
		} else {
			r_player_blood = _result;
		};
	};
	if (_foodVal <= 0) then {
		_result = r_player_blood - 10;
		if (_result < 0) then {
			_id = [player,"starve"] spawn player_death;
		} else {
			r_player_blood = _result;
		};
	};
	
	//Record low bloow
	_lowBlood = player getVariable ["USEC_lowBlood", false];
	if ((r_player_blood < r_player_bloodTotal) and !_lowBlood) then {
		player setVariable["USEC_lowBlood",true,true];
	};
	
	//Broadcast Hunger/Thirst
	_messTimer = _messTimer + 1;
	if (_messTimer > 15) then {
		_messTimer = 0;
		player setVariable ["messing",[viruz_hunger,viruz_thirst],true];
	};
	
	//check if can disconnect
	if (!viruz_canDisconnect) then {
		if ((time - viruz_damageCounter) > 180) then {
			if (!r_player_unconscious) then {
				viruz_canDisconnect = true;
				//["viruzDiscoRem",getPlayerUID player] call callRpcProcedure;
				//viruzDiscoRem = getPlayerUID player;
				//publicVariable "viruzDiscoRem";
				
				//Ensure Control is hidden
				_display = uiNamespace getVariable 'VIRUZ_GUI_display';
				_control = 	_display displayCtrl 1204;
				_control ctrlShow false;
			};
		};
	};

	//Save Checker

	if (viruz_unsaved) then {		
		if ((time - viruz_lastSave) > _saveTime) then {
			//["viruzPlayerSave",[player,viruz_Magazines,false]] call callRpcProcedure;
			
			viruzPlayerSave = [player,viruz_Magazines,false];
			publicVariableServer "viruzPlayerSave";
			if (isServer) then {
				viruzPlayerSave call server_playerSync;
			};
						
			viruz_lastSave = time;
			viruz_Magazines = [];
		};
		_lastSave = _lastSave + 2;
	} else {
		viruz_lastSave = time;
		_lastSave = 0;
	};

	if (!viruz_unsaved) then {
		viruz_lastSave = time;
	};

	//Attach Trigger Current Object
	//viruz_playerTrigger attachTo [_refObj,[0,0,0]];
	//viruz_playerTrigger setTriggerArea [_size,_size,0,false];

	// If in combat, display counter and restrict logout
	_startcombattimer      = player getVariable["startcombattimer",0];
	if (_startcombattimer == 1) then {
		player setVariable["combattimeout", time + 30, true];
		player setVariable["startcombattimer", 0, true];
		viruz_combat = 1;
	};

	_combattimeout = player getVariable["combattimeout",0];
	if (_combattimeout > 0) then {
		_timeleft = _combattimeout - time;
		if (_timeleft > 0) then {
			//hintSilent format["In Combat: %1",round(_timeleft)];
		} else {
			//hintSilent "Not in Combat";
			player setVariable["combattimeout", 0, true];
			viruz_combat = 0;
			_combatdisplay = uiNamespace getVariable 'VIRUZ_GUI_display';
			_combatcontrol = 	_combatdisplay displayCtrl 1307;
			_combatcontrol ctrlShow true;
		};
	} else {
		//hintSilent "Not in Combat";
		viruz_combat = 0;
		_combatdisplay = uiNamespace getVariable 'VIRUZ_GUI_display';
		_combatcontrol = 	_combatdisplay displayCtrl 1307;
		_combatcontrol ctrlShow true;
	};
	
	/*
	setGroupIconsVisible [false,false];
	clearGroupIcons group player;
	*/
	//"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, (r_player_blood/r_player_bloodTotal)],  [1, 1, 1, 0.0]];
	//"colorCorrections" ppEffectCommit 0;
	sleep 2;
	/*
	_myPos = player getVariable["lastPos",[]];
	if (count _myPos > 0) then {
		player setVariable["lastPos",_mylastPos, true];
		player setVariable["lastPos",[]];
	};
	
	_lastPos = getPosATL player;	
	if (player == vehicle player) then {
		if (_mylastPos distance _lastPos > 200) then {
			if (alive player) then {
				player setPosATL _mylastPos;
			};
		};
	} else {
		if (_mylastPos distance _lastPos > 800) then {
			if (alive player) then {
				player setPosATL _mylastPos;
			};
		};
	};
	*/
	//Hatchet ammo fix	
	//"MeleeHatchet" call viruz_meleeMagazineCheck;
	
	//Crowbar ammo fix	
	//"MeleeCrowbar" call viruz_meleeMagazineCheck;
};