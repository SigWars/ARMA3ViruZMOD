scriptName "Functions\misc\fn_selfActions.sqf";
/*
ViruZ Mod for Arma 3
Update Object Position, Owner etc by type
Autor: SigWar

ADD ACTIONS FOR SELF
	- Function
	- [] call fnc_usec_selfActions;
	
*/

private["_menClose","_hasBandage","_hasEpi","_hasMorphine","_hasBlood","_vehicle","_inVehicle","_color","_part"];

_vehicle = vehicle player;
_inVehicle = (_vehicle != player);
_bag = unitBackpack player;
_classbag = typeOf _bag;
_isWater = 		(surfaceIsWater (position player)) or viruz_isSwimming;
_hasAntiB = 	"ItemAntibiotic" in magazines player;
_hasFuelE = 	count (["ItemJerrycan", player] call PTm_fnc_filterGear) > 0;
//boiled Water
_hasbottleitem = "ItemWaterbottle" in magazines player;
_hastinitem = false;
{
    if (_x in magazines player) then {
        _hastinitem = true;
    };

} forEach boil_tin_cans;


_hasKnife = 	"ItemKnife" in items player;
_hasToolbox = 	"ItemToolbox" in items player;
_hasTent = 		"ItemTent" in items player;
_onLadder =		(getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
//_nearLight = 	nearestObject [player,"LitObject"];
_nearLight = 	nearestObject [player,"SmokeShell"];
_canPickLight = false;

if (!isNull _nearLight) then {
	if (_nearLight distance player < 4) then {
		_canPickLight = isNull (_nearLight getVariable ["owner",objNull]);
	};
};
_canDo = (!r_drag_sqf and !r_player_unconscious and !_onLadder);

//Grab Flare
if (_canPickLight and !viruz_hasLight) then {
	if (s_player_grabflare < 0) then {
//		_text = getText (configFile >> "CfgAmmo" >> (typeOf _nearLight) >> "displayName");
		_text = "Chemlight";
		s_player_grabflare = player addAction [format[localize "str_actions_medical_15",_text], "\z\addons\viruz_mod\actions\flare_pickup.sqf",_nearLight, 1, false, true, "", ""];
		s_player_removeflare = player addAction [format[localize "str_actions_medical_17",_text], "\z\addons\viruz_mod\actions\flare_remove.sqf",_nearLight, 1, false, true, "", ""];
	};
} else {
	player removeAction s_player_grabflare;
	player removeAction s_player_removeflare;
	s_player_grabflare = -1;
	s_player_removeflare = -1;
};

//	Disassemble structures
_Structures = nearestObjects [player,["Shelter_base_F","TentStorage_base"],5];
if((count _Structures > 0) and !_inVehicle and _canDo) then {
	if !(s_player_packtent select 1 == typeOf(_Structures select 0)) then {
		if (s_player_packtent select 0 < 0) then {
			s_player_packtent = [player addAction [format[localize "str_actions_Pack",getText(configFile >> "CfgVehicles" >> typeOf (_Structures select 0) >> "displayName")], "\z\addons\viruz_mod\actions\tent_pack.sqf",_Structures select 0, 0, false, true],typeOf(_Structures select 0)];
		} else {
			player removeAction (s_player_packtent select 0);
			s_player_packtent = [player addAction [format[localize "str_actions_Pack",getText(configFile >> "CfgVehicles" >> typeOf (_Structures select 0) >> "displayName")], "\z\addons\viruz_mod\actions\tent_pack.sqf",_Structures select 0, 0, false, true],typeOf(_Structures select 0)];
		};
	};
} else {
	if !(s_player_packtent select 0 == -1) then {
		player removeAction (s_player_packtent select 0);
		s_player_packtent = [-1,""];
	};
};

//	Assemble vehicles
	//fishing
	if (_vehicle == player and _isWater) then {
	if (s_player_fishing < 0) then {
		s_player_fishing = player addAction [localize "STR_ACTION_CAST", "\z\addons\viruz_mod\actions\player_goFishing.sqf",player, 0.5, false, true];
	};
	} else {
	player removeAction s_player_fishing;
	s_player_fishing = -1;
	};
	if (_inVehicle and (driver _vehicle != player)) then {
		if (s_player_fishing_veh < 0) then {
			s_player_fishing_veh = _vehicle addAction [localize "STR_ACTION_CAST", "\z\addons\viruz_mod\actions\player_goFishing.sqf",_vehicle, 0.5, false, true];
		};
	} else {
	_vehicle removeAction s_player_fishing_veh;
	s_player_fishing_veh = -1;
	};

if((unitBackpack player isKindOf "B_VehicleBag_base") and !_inVehicle and _canDo) then {
	if !(s_player_assembleVehicle select 1 == typeOf(unitBackpack player)) then {	
		if (s_player_assembleVehicle  select 0 < 0) then {
			s_player_assembleVehicle = [player addAction [format[localize "str_actions_Assemble",getText(configFile >> "CfgVehicles" >> typeOf(unitBackpack player) >> "displayName")], "\z\addons\viruz_mod\actions\assemble_vehicle.sqf",typeOf(unitBackpack player), 0, false, true],typeOf(unitBackpack player)];
		} else {
			player removeAction (s_player_assembleVehicle select 0);
			s_player_assembleVehicle = [player addAction [format[localize "str_actions_Assemble",getText(configFile >> "CfgVehicles" >> typeOf(unitBackpack player) >> "displayName")], "\z\addons\viruz_mod\actions\assemble_vehicle.sqf",typeOf(unitBackpack player), 0, false, true],typeOf(unitBackpack player)];
		};
	};
} else {
	if !(s_player_assembleVehicle select 0 == -1) then {
		player removeAction (s_player_assembleVehicle select 0);
		s_player_assembleVehicle = [-1,""];
	};
};

//	Disassemble vehicles
_vehicles = nearestObjects [player,["Rubber_duck_base_F"],5];
if((count _vehicles > 0) and !_inVehicle and _canDo) then {
	if !(s_player_disassembleVehicle select 1 == typeOf(_vehicles select 0)) then {	
		if (s_player_disassembleVehicle select 0 < 0) then {
			s_player_disassembleVehicle = [player addAction [format[localize "str_actions_Disassemble",getText(configFile >> "CfgVehicles" >> typeOf (_vehicles select 0) >> "displayName")], "\z\addons\viruz_mod\actions\disassemble_vehicle.sqf",_vehicles select 0, 0, false, true],typeOf (_vehicles select 0)];
		} else {
			player removeAction (s_player_disassembleVehicle select 0);
			s_player_disassembleVehicle = [player addAction [format[localize "str_actions_Disassemble",getText(configFile >> "CfgVehicles" >> typeOf (_vehicles select 0) >> "displayName")], "\z\addons\viruz_mod\actions\disassemble_vehicle.sqf",_vehicles select 0, 0, false, true],typeOf (_vehicles select 0)];
		};
	};	
} else {
	if !(s_player_disassembleVehicle select 0 == -1) then {
		player removeAction (s_player_disassembleVehicle select 0);
		s_player_disassembleVehicle = [-1,""];
	};
};

//Allow player lock and unlock builds
if (!isNull cursorTarget and !_inVehicle and (player distance cursorTarget < 15) and (typeOf cursorTarget in VIRUZ_BUILDS + VIRUZ_GATES)) then {
	private["_building","_locked","_LockerUID","_UIDdono","_savedGroup","_sameGroup","_numDoors","_doorPos","_dist","_doorNum","_maxDist"];
	_building = cursorTarget;
	_casaName = typeOf _building in VIRUZ_BUILDS + VIRUZ_GATES;
		
	if (_casaName) then {
		_sameGroup = false;
		_locked = "";
		_UIDdono = "";
		_UIDdono = _building getVariable ["OwnerUID","0"];
		_locked = _building getVariable ["Locked","0"];
		_LockerUID = getPlayerUID player;
		_savedGroup = profileNamespace getVariable["savedGroup",[]];
		
		
		if (count _savedGroup > 1) then {
			
			if (_UIDdono in _savedGroup and _LockerUID in _savedGroup ) then {
					_sameGroup = true;
			};
			
		};
		
		if ((typeOf _building == "VIRUZ_WoodGate_new") or (typeOf _building == "Land_i_Shed_Ind_F")) then {
			_maxDist = 4;
		}else{
			_maxDist = 2.5;
		};
			
		_numDoors = getNumber (configFile >> "CFGVehicles" >> typeOf _building >> "numberOfDoors");
		if (_numDoors < 1) then {
			_numDoors = 6;
		};
		
		for "_doorNum" from 1 to _numDoors do {

			_doorPos = _building selectionPosition (format ["Door_%1_trigger", _doorNum]);
			_dist = (getPosATL player) distance (_building modelToWorld _doorPos);
			
		
		if ( _locked != "" and _UIDdono != "" and _dist < _maxDist and (player getVariable ["current_door",0] == 0)) then {

		player setVariable ["current_door", _doorNum];
		
			if (s_player_lockbuild < 0 and _LockerUID == _UIDdono and (_building getVariable [format ["Door_%1_Lock", _doorNum], "0"] == "0"))  then {
				s_player_lockbuild = player addAction ["<t color='#FF0000'>Lock</t>", "\z\addons\viruz_mod\actions\door.sqf", [_building,"lock",_doorNum], 6, false, true, "", ""];
			} else {
				if (s_player_lockbuild < 0 and _LockerUID != _UIDdono and _sameGroup and (_building getVariable [format ["Door_%1_Lock", _doorNum], "0"] == "0"))  then {
					s_player_lockbuild = player addAction ["<t color='#FF6600'>Lock</t>", "\z\addons\viruz_mod\actions\door.sqf", [_building,"lock",_doorNum], 6, false, true, "", ""];
				};
			};
			
			if (s_player_unlockbuild < 0 and _LockerUID == _UIDdono and (_building getVariable [format ["Door_%1_Lock", _doorNum], "0"] == "1"))  then {
					s_player_unlockbuild = player addAction ["<t color='#00FF00'>Unlock</t>", "\z\addons\viruz_mod\actions\door.sqf", [_building,"unlock",_doorNum], 6, false, true, "", ""];
			} else {
				if (s_player_unlockbuild < 0 and _LockerUID != _UIDdono and _sameGroup and (_building getVariable [format ["Door_%1_Lock", _doorNum], "0"] == "1"))  then {
					s_player_unlockbuild = player addAction ["<t color='#3399FF'>Unlock</t>", "\z\addons\viruz_mod\actions\door.sqf", [_building,"unlock",_doorNum], 6, false, true, "", ""];
				};
			};
		}else{
				if (_dist > _maxDist and (player getVariable ["current_door",0] == _doorNum)) then {
					player setVariable ["current_door", 0];
					player removeAction s_player_lockbuild;
					s_player_lockbuild = -1;
					player removeAction s_player_unlockbuild;
					s_player_unlockbuild = -1;
				};	
			};
		
		};
		
	};
} else {
		player setVariable ["current_door", 0];
		player removeAction s_player_lockbuild;
		s_player_lockbuild = -1;
		player removeAction s_player_unlockbuild;
		s_player_unlockbuild = -1;
};	
		
		
		
if (!isNull cursorTarget and !_inVehicle and (player distance cursorTarget < 6)) then {	//Has some kind of target
	_isHarvested = cursorTarget getVariable["meatHarvested",false];
	_isVehicle = cursorTarget isKindOf "AllVehicles";
	//_isVehicletype = typeOf cursorTarget in ["ATV_US_EP1","ATV_CZ_EP1"];
	_isVehicletype = typeOf cursorTarget in ["Quadbike_SRV_BLACK", "Quadbike_SRV_BLUE", "Quadbike_SRV_RED","Quadbike_SRV_WHITE","dbo_CIV_ol_bike","dbo_CIV_new_bike"];
	_isMan = cursorTarget isKindOf "Man";
	_ownerID = cursorTarget getVariable ["characterID","0"];
	_isAnimal = typeOf cursorTarget in ["Fowl_Base_F","Hen_random_F","Cock_random_F","Rabbit_F","Goat_random_F","Goat_small_random_F","Sheep_random_F"];
	//_isAnimal = cursorTarget isKindOf "Animal_Base_F";
	_isDog =  (cursorTarget isKindOf "DZ_Pastor" || cursorTarget isKindOf "DZ_Fin");
	_isZombie = cursorTarget isKindOf "zZombie_Base";
	_isDestructable = cursorTarget isKindOf "BuiltItems";
	_isTent = cursorTarget isKindOf "TentStorage";
	_isFuel = false;
	_isAlive = alive cursorTarget;
	_isManiken = cursorTarget isKindOf "Maniken_Base";
	_canmove = canmove cursorTarget;
	_text = getText (configFile >> "CfgVehicles" >> typeOf cursorTarget >> "displayName");
	
	_rawmeat = meatraw;
	_hasRawMeat = false;
		{
			if (_x in magazines player) then {
				_hasRawMeat = true;
			};
		} forEach _rawmeat; 
	
	
	if (_hasFuelE) then {
		_isFuel = (cursorTarget isKindOf "Land_Tank_rust_F") or (cursorTarget isKindOf "Land_fs_feed_F") or (cursorTarget isKindOf "Land_FuelStation_Feed_F");
	};
	//diag_log ("OWNERID = " + _ownerID + " CHARID = " + viruz_characterID + " " + str(_ownerID == viruz_characterID));
	
	//Allow player to gear objects
	if (_isManiken and _canDo) then {
		private ["_Object"];
		_Object = cursorTarget;
		if ((player distance _Object) < 3) then {
			if (s_player_Gear < 0) then {
				s_player_Gear = player addAction [actionName "Gear", {player action ["Gear", _this select 3]}, _Object, 1, true, true];
			};
		} else {
			player removeAction s_player_Gear;
			s_player_Gear = -1;
		};
	} else {
		player removeAction s_player_Gear;
		s_player_Gear = -1;
	};
	
	//Allow player to delete objects
	if(_isDestructable and _hasToolbox and _canDo) then {
		if (s_player_deleteBuild < 0) then {
			s_player_deleteBuild = player addAction [format[localize "str_actions_delete",_text], "\z\addons\viruz_mod\actions\remove.sqf",cursorTarget, 1, true, true, "", ""];
		};
	} else {
		player removeAction s_player_deleteBuild;
		s_player_deleteBuild = -1;
	};
	
	//Maintain Build
	if (!_isMan and (typeOf cursorTarget == "ViruZ_WorkStand") and (player distance cursorTarget <= 3)) then {
	
		if (s_player_maintain < 0) then {
			s_player_maintain = player addAction ["<t color='#FF0000'>Maintain Build</t>", "\z\addons\viruz_mod\actions\vz_MaintainBuild.sqf", cursorTarget, 6, false, true, "", ""];
		};
	} else {
		player removeAction s_player_maintain;
		s_player_maintain = -1;
	};	
	
	/*
	//Allow player to force save
	if((_isVehicle or _isTent) and _canDo and !_isMan) then {
		if (s_player_forceSave < 0) then {
			s_player_forceSave = player addAction [format[localize "str_actions_save",_text], "\z\addons\viruz_mod\actions\forcesave.sqf",cursorTarget, 1, true, true, "", ""];
		};
	} else {
		player removeAction s_player_forceSave;
		s_player_forceSave = -1;
	};
	*/
	//flip vehicle
	if ((_isVehicletype) and !_canmove and _isAlive and (player distance cursorTarget >= 2) and (count (crew cursorTarget))== 0 and ((vectorUp cursorTarget) select 2) < 0.5) then {
		if (s_player_flipveh  < 0) then {
			s_player_flipveh = player addAction [format[localize "str_actions_flipveh",_text], "\z\addons\viruz_mod\actions\player_flipvehicle.sqf",cursorTarget, 1, true, true, "", ""];		
		};	
	} else {
		player removeAction s_player_flipveh;
		s_player_flipveh = -1;
	};
	
	//Allow player to fill jerrycan
	if(_hasFuelE and _isFuel and _canDo) then {
		if (s_player_fillfuel < 0) then {
			s_player_fillfuel = player addAction [localize "str_actions_self_10", "\z\addons\viruz_mod\actions\jerry_fill.sqf",[], 1, false, true, "", ""];
		};
	} else {
		player removeAction s_player_fillfuel;
		s_player_fillfuel = -1;
	};
	
	if (!alive cursorTarget and _isAnimal and _hasKnife and !_isHarvested and _canDo) then {
		if (s_player_butcher < 0) then {
			s_player_butcher = player addAction [localize "str_actions_self_04", "\z\addons\viruz_mod\actions\gather_meat.sqf",cursorTarget, 3, true, true, "", ""];
		};
	} else {
		player removeAction s_player_butcher;
		s_player_butcher = -1;
	};
	
	//Fireplace Actions check
	if (inflamed cursorTarget and _hasRawMeat and _canDo) then {
		if (s_player_cook < 0) then {
			s_player_cook = player addAction [localize "str_actions_self_05", "\z\addons\viruz_mod\actions\cook.sqf",cursorTarget, 3, true, true, "", ""];
		};
	} else {
		player removeAction s_player_cook;
		s_player_cook = -1;
	};
	if (inflamed cursorTarget and (_hasbottleitem and _hastinitem) and _canDo) then {
		if (s_player_boil < 0) then {
			s_player_boil = player addAction [localize "str_actions_boilwater", "\z\addons\viruz_mod\actions\boil.sqf",cursorTarget, 3, true, true, "", ""];
		};
	} else {
		player removeAction s_player_boil;
		s_player_boil = -1;
	};
	
	if(cursorTarget == viruz_hasFire and _canDo) then {
		if ((s_player_fireout < 0) and !(inflamed cursorTarget) and (player distance cursorTarget < 3)) then {
			s_player_fireout = player addAction [localize "str_actions_self_06", "\z\addons\viruz_mod\actions\fire_pack.sqf",cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_fireout;
		s_player_fireout = -1;
	};

	/*
	if(cursorTarget isKindOf "TentStorage_base" and _canDo) then {
		if ((s_player_packtent < 0) and (player distance cursorTarget < 3)) then {
			//s_player_packtent = player addAction [localize "str_actions_self_07", "\z\addons\viruz_mod\actions\tent_pack.sqf",cursorTarget, 0, false, true, "",""];
			s_player_packtent = player addAction [format[localize "str_actions_Pack",getText(configFile >> "CfgVehicles" >> typeOf cursorTarget >> "displayName")], "\z\addons\viruz_mod\actions\tent_pack.sqf",cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_packtent;
		s_player_packtent = -1;
	};
	*/
	
	//Sleep
	if(cursorTarget isKindOf "TentStorage" and _canDo and _ownerID == viruz_characterID) then {
		if ((s_player_sleep < 0) and (player distance cursorTarget < 5)) then {
			s_player_sleep = player addAction [localize "str_actions_self_sleep", "\z\addons\viruz_mod\actions\player_sleep.sqf",cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_sleep;
		s_player_sleep = -1;
	};
	
	//Repairing Vehicles
	if ((viruz_myCursorTarget != cursorTarget) and _isVehicle and !_isMan and _hasToolbox and (damage cursorTarget < 1)) then {
		_vehicle = cursorTarget;
		{viruz_myCursorTarget removeAction _x} forEach s_player_repairActions;s_player_repairActions = [];
		viruz_myCursorTarget = _vehicle;

		_allFixed = true;
		_hitpoints = _vehicle call vehicle_getHitpoints;
		
		{
			_damage = [_vehicle,_x] call object_getHit;
			_part = "PartGeneric";
			
			//change "HitPart" to " - Part" rather than complicated string replace
			_cmpt = toArray (_x);
			_cmpt set [0,20];
			_cmpt set [1,toArray ("-") select 0];
			_cmpt set [2,20];
			_cmpt = toString _cmpt;
				
			if(["Engine",_x,false] call fnc_inString) then {
				_part = "PartEngine";
			};
					
			if(["HRotor",_x,false] call fnc_inString) then {
				_part = "PartVRotor"; //yes you need PartVRotor to fix HRotor LOL
			};

			if(["Fuel",_x,false] call fnc_inString) then {
				_part = "PartFueltank";
			};
			
			if(["Wheel",_x,false] call fnc_inString) then {
				_part = "PartWheel";

			};
					
			if(["Glass",_x,false] call fnc_inString) then {
				_part = "PartGlass";
			};

			// get every damaged part no matter how tiny damage is!
			if (_damage > 0) then {
				
				_allFixed = false;
				_color = "color='#ffff00'"; //yellow
				if (_damage >= 0.5) then {_color = "color='#ff8800'";}; //orange
				if (_damage >= 0.9) then {_color = "color='#ff0000'";}; //red

				_string = format["<t %2>Repair%1</t>",_cmpt,_color]; //Repair - Part
				_handle = viruz_myCursorTarget addAction [_string, "\z\addons\viruz_mod\actions\repair.sqf",[_vehicle,_part,_x], 0, false, true, "",""];
				s_player_repairActions set [count s_player_repairActions,_handle];

			};
					
		} forEach _hitpoints;
		if (_allFixed) then {
			_vehicle setDamage 0;
		};
	};
	
	if (_isMan and !_isAlive and !_isZombie) then {
		if (s_player_studybody < 0) then {
			s_player_studybody = player addAction [localize "str_action_studybody", "\z\addons\viruz_mod\actions\study_body.sqf",cursorTarget, 0, false, true, "",""];
		};
	} else {
		player removeAction s_player_studybody;
		s_player_studybody = -1;
	};

	//Dog
	if (_isDog and _isAlive and (_hasRawMeat) and _canDo and _ownerID == "0" and player getVariable ["dogID", 0] == 0) then {
		if (s_player_tamedog < 0) then {
			s_player_tamedog = player addAction [localize "str_actions_tamedog", "\z\addons\viruz_mod\actions\tame_dog.sqf", cursorTarget, 1, false, true, "", ""];
		};
	} else {
		player removeAction s_player_tamedog;
		s_player_tamedog = -1;
	};
	
	if (_isDog and _ownerID == viruz_characterID and _isAlive and _canDo) then {
		_dogHandle = player getVariable ["dogID", 0];
		if (s_player_feeddog < 0 and _hasRawMeat) then {
			s_player_feeddog = player addAction [localize "str_actions_feeddog","\z\addons\viruz_mod\actions\dog\feed.sqf",[_dogHandle,0], 0, false, true,"",""];
		};
		if (s_player_waterdog < 0 and "ItemWaterbottle" in magazines player) then {
			s_player_waterdog = player addAction [localize "str_actions_waterdog","\z\addons\viruz_mod\actions\dog\feed.sqf",[_dogHandle,1], 0, false, true,"",""];
		};
		if (s_player_staydog < 0) then {
			_lieDown = _dogHandle getFSMVariable "_actionLieDown";
			if (_lieDown) then { _text = "str_actions_liedog"; } else { _text = "str_actions_sitdog"; };
			s_player_staydog = player addAction [localize _text,"\z\addons\viruz_mod\actions\dog\stay.sqf", _dogHandle, 5, false, true,"",""];
		};
		if (s_player_trackdog < 0) then {
			s_player_trackdog = player addAction [localize "str_actions_trackdog","\z\addons\viruz_mod\actions\dog\track.sqf", _dogHandle, 4, false, true,"",""];
		};
		if (s_player_barkdog < 0) then {
			s_player_barkdog = player addAction [localize "str_actions_barkdog","\z\addons\viruz_mod\actions\dog\speak.sqf", cursorTarget, 3, false, true,"",""];
		};
		if (s_player_warndog < 0) then {
			_warn = _dogHandle getFSMVariable "_watchDog";
			if (_warn) then { _text = "Quiet"; _warn = false; } else { _text = "Alert"; _warn = true; };
			s_player_warndog = player addAction [format[localize "str_actions_warndog",_text],"\z\addons\viruz_mod\actions\dog\warn.sqf",[_dogHandle, _warn], 2, false, true,"",""];		
		};
		if (s_player_followdog < 0) then {
			s_player_followdog = player addAction [localize "str_actions_followdog","\z\addons\viruz_mod\actions\dog\follow.sqf",[_dogHandle,true], 6, false, true,"",""];
		};
	} else {
		player removeAction s_player_feeddog;
		s_player_feeddog = -1;
		player removeAction s_player_waterdog;
		s_player_waterdog = -1;
		player removeAction s_player_staydog;
		s_player_staydog = -1;
		player removeAction s_player_trackdog;
		s_player_trackdog = -1;
		player removeAction s_player_barkdog;
		s_player_barkdog = -1;
		player removeAction s_player_warndog;
		s_player_warndog = -1;
		player removeAction s_player_followdog;
		s_player_followdog = -1;
	};
} else {
	//Engineering
	{viruz_myCursorTarget removeAction _x} forEach s_player_repairActions;s_player_repairActions = [];
	viruz_myCursorTarget = objNull;
	//Others
	player removeAction s_player_forceSave;
	s_player_forceSave = -1;
	player removeAction s_player_flipveh;
	s_player_flipveh = -1;
	player removeAction s_player_sleep;
	s_player_sleep = -1;
	player removeAction s_player_deleteBuild;
	s_player_deleteBuild = -1;
	player removeAction s_player_maintain;
	s_player_maintain = -1;
	player removeAction s_player_butcher;
	s_player_butcher = -1;
	player removeAction s_player_cook;
	s_player_cook = -1;
	player removeAction s_player_boil;
	s_player_boil = -1;
	player removeAction s_player_fireout;
	s_player_fireout = -1;
//	player removeAction s_player_packtent;
//	s_player_packtent = -1;
//	player removeAction s_player_fishing;
//	s_player_fishing = -1;
//	_vehicle removeAction s_player_fishing_veh;
//	s_player_fishing_veh = -1;
	player removeAction s_player_fillfuel;
	s_player_fillfuel = -1;
	player removeAction s_player_studybody;
	s_player_studybody = -1;
	//Dog
	player removeAction s_player_tamedog;
	s_player_tamedog = -1;
	player removeAction s_player_feeddog;
	s_player_feeddog = -1;
	player removeAction s_player_waterdog;
	s_player_waterdog = -1;
	player removeAction s_player_staydog;
	s_player_staydog = -1;
	player removeAction s_player_trackdog;
	s_player_trackdog = -1;
	player removeAction s_player_barkdog;
	s_player_barkdog = -1;
	player removeAction s_player_warndog;
	s_player_warndog = -1;
	player removeAction s_player_followdog;
	s_player_followdog = -1;
};

//Dog actions on player self
_dogHandle = player getVariable ["dogID", 0];
if (_dogHandle > 0) then {
	_dog = _dogHandle getFSMVariable "_dog";
	_ownerID = "0";
	if (!isNull cursorTarget) then { _ownerID = cursorTarget getVariable ["characterID","0"]; };
	if (_canDo and !_inVehicle and alive _dog and _ownerID != viruz_characterID) then {
		if (s_player_movedog < 0) then {
			s_player_movedog = player addAction [localize "str_actions_movedog", "\z\addons\viruz_mod\actions\dog\move.sqf", player getVariable ["dogID", 0], 1, false, true, "", ""];
		};
		if (s_player_speeddog < 0) then {
			_text = "Walk";
			_speed = 0;
			if (_dog getVariable ["currentSpeed",1] == 0) then { _speed = 1; _text = "Run"; };
			s_player_speeddog = player addAction [format[localize "str_actions_speeddog", _text], "\z\addons\viruz_mod\actions\dog\speed.sqf",[player getVariable ["dogID", 0],_speed], 0, false, true, "", ""];
		};
		if (s_player_calldog < 0) then {
			s_player_calldog = player addAction [localize "str_actions_calldog", "\z\addons\viruz_mod\actions\dog\follow.sqf", [player getVariable ["dogID", 0], true], 2, false, true, "", ""];
		};
	};
} else {
	player removeAction s_player_movedog;		
	s_player_movedog =		-1;
	player removeAction s_player_speeddog;
	s_player_speeddog =		-1;
	player removeAction s_player_calldog;
	s_player_calldog = 		-1;
};