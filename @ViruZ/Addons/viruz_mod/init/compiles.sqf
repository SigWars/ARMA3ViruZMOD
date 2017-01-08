
//**************************************************************** PLAYER ONLY COMPILES ************************************************
if (!isDedicated) then {
	_config = 	missionConfigfile >> "CfgLoot";
	_config1 = 	configFile >> "CfgMagazines" >> "FoodEdible";
	_config2 = 	configFile >> "CfgWeapons" >> "Loot";

//	player_ReammoMagazines =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_ReammoMagazines.sqf";
	vz_playerAutorun =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_autorun.sqf";
	PTm_fnc_filterGear =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_filterGear.sqf";
	PTm_fnc_getMagazinesEmpty = compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_getMagazinesEmpty.sqf";
	HandFlashLight_monitor =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\HandFlashLight_monitor.sqf";
	maniken_gearSync =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\maniken_gearSync.sqf";
	player_addEventHandlers =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\init\player_addEventHandlers.sqf";
	MP_say =					compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\say.sqf";
	MP_SwitchMove =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\switchmove.sqf";
	MP_PlayMove =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\PlayMove.sqf";
	player_zombieCheck = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_zombieCheck.sqf";	//Run on a players computer, checks if the player is near a zombie
	player_zombieAttack = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_zombieAttack.sqf";	//Run on a players computer, causes a nearby zombie to attack them
	fnc_buildingPositions = 	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_buildingPositions.sqf"; //check build locations to spawn zombie
	fnc_inEyeAngleSector = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_inEyeAngleSector.sqf";	// check locations in build to move inside
	fnc_usec_damageActions =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_damageActions.sqf";		//Checks which actions for nearby casualty
	fnc_inAngleSector =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_inAngleSector.sqf";		//Checks which actions for nearby casualty
	fnc_usec_selfActions =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_selfActions.sqf";		//Checks which actions for self
	fnc_usec_unconscious =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_unconscious.sqf";
	player_temp_calculation	=	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_temperatur.sqf";		//Temperatur System	//TeeChange
	player_weaponFiredNear =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_weaponFiredNear.sqf";
	player_animalCheck =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_animalCheck.sqf";
	player_spawnCheck = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_spawnCheck.sqf";
	ViruZClient_antiGlitch =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZClient_antiGlitch.sqf";
	player_spawnZedCheck =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_spawnzedCheck.sqf";
	building_spawnLoot =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\building_spawnLoot.sqf";
	player_taskHint =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_taskHint.sqf";
	building_spawnZombies =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\building_spawnZombies.sqf";
	building_monitor =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\building_monitor.sqf";
	player_fired =				compileFinal preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_fired.sqf";			//Runs when player fires. Alerts nearby Zeds depending on calibre and audial rating
	player_packTent =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_packTent.sqf";
	player_updateGui =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_updateGui.sqf";
	player_crossbowBolt =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_crossbowBolt.sqf";
	spawn_flies = 				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\spawn_flies.sqf";
	stream_locationFill = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\stream_locationFill.sqf";
	stream_locationDel = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\stream_locationDel.sqf";
	stream_locationCheck = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\stream_locationCheck.sqf";
	player_music = 				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_music.sqf";			//Used to generate ambient music
	player_login = 				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_login.sqf";			//Used to generate ambient music
	player_death =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_death.sqf";
	player_switchModel =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_switchModel.sqf";
	player_checkStealth =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_checkStealth.sqf";
	world_sunRise =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_sunRise.sqf";
	world_surfaceNoise =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_surfaceNoise.sqf";
	player_humanityMorph =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_humanityMorph.sqf";
	player_throwObject = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_throwObject.sqf";
	player_alertZombies = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_alertZombies.sqf";
	player_fireMonitor = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\fire_monitor.sqf";
	zombie_CheckBuild = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\zombieCheckBuild.sqf";

	//Objects
	object_roadFlare = 			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_roadFlare.sqf";
	object_setpitchbank	=		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_setpitchbank.sqf";
	
	//Zombies
	zombie_findTargetAgent = 	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\zombie_findTargetAgent.sqf";
	zombie_loiter = 			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\zombie_loiter.sqf";			//Server compile, used for loiter behaviour
	zombie_generate = 			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\zombie_generate.sqf";			//Server compile, used for loiter behaviour
	wild_spawnZombies = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\wild_spawnZombies.sqf";			//Server compile, used for loiter behaviour
	
	//
	dog_findTargetAgent =   compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\dog_findTargetAgent.sqf";
	
	// Vehicle damage fix
	vehicle_handleDamage    = compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\vehicle_handleDamage.sqf";
	vehicle_handleKilled    = compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\vehicle_handleKilled.sqf";

	//actions
	player_countmagazines =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_countmagazines.sqf";
	player_addToolbelt =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_addToolbelt.sqf";
	player_reloadMag =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_reloadMags.sqf";
	player_tentPitch =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\tent_pitch.sqf";
	player_drink =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_drink.sqf";
	player_eat =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_eat.sqf";
	player_useMeds =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_useMeds.sqf";
	player_fillWater = 			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\water_fill.sqf";
	player_makeFire =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_makefire.sqf";
	player_build =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_build.sqf";
	player_wearClothes =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_wearClothes.sqf";
	player_dropWeapon =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_dropWeapon.sqf";
	player_setTrap =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_setTrap.sqf";
	object_pickup = 			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\object_pickup.sqf";
	player_flipvehicle = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_flipvehicle.sqf";
	player_sleep = 				compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_sleep.sqf";
	electronics_build =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\Electronics_build.sqf";
	jerry_fill =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\jerry_fill.sqf";
	
	//ui
	player_gearSync	=			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_gearSync.sqf";
	player_gearSet	=			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_gearSet.sqf";
	ui_changeDisplay = 			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\ui_changeDisplay.sqf";
	player_bakckTolobby = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_BacktoLobby.sqf";
	viruz_onPause =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_onPause.sqf";
	
	//System
	player_monitor =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\player_monitor.sqf";
	player_spawn_1 =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\player_spawn_1.sqf";
	player_spawn_2 =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\player_spawn_2.sqf";
//	onPreloadStarted 			"viruz_preloadFinished = false;";
//	onPreloadFinished 			"viruz_preloadFinished = true;";
	
	//ViruZ Inventory craft system
	VZClient_util_world_isFireInRange = 						compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_util_world_isFireInRange.sqf";
	VZClient_util_model_isNearby =								compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_util_model_isNearby.sqf";
	VZClient_object_item_craft = 								compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_object_item_craft.sqf";
	VZClient_item_getCrafting =									compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_item_getCrafting.sqf";
	VZClient_gui_itemDescription_event_onTabelaButton = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_gui_itemDescription_event_onTabelaButton.sqf";
	VZClient_gui_itemDescription_event_onCraftingDoubleClick =  compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_gui_itemDescription_event_onCraftingDoubleClick.sqf";
	VZClient_gui_crafting_show = 								compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_gui_crafting_show.sqf";
	ViruZClient_gui_itemDescription_show =						compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZClient_gui_itemDescription_show.sqf";
	ViruZClient_gui_inventory_event_onItemDoubleClick =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZClient_gui_inventory_event_onItemDoubleClick.sqf";
	ViruZClient_gear_getConfigNameByClassName =					compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZClient_gear_getConfigNameByClassName.sqf";
	ViruZClient_gear_getConfigEntryByDisplayName =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZClient_gear_getConfigEntryByDisplayName.sqf";
	
	//Viruz new Build system
	ViruZClient_move_object =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZClient_move_object.sqf";
	ViruZClient_getSpotPosition = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZClient_getSpotPosition.sqf";
	
	//ViruZ
	player_goFishing =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_goFishing.sqf"; //fishing
	vz_player_choopWood = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\viruz\vz_player_choopWood.sqf";
	//snap_object	= compile preprocessFileLineNumbers  "\viruz_build\snap\snap_object.sqf";
	// TODO: need move it in player_monitor.fsm
	// allow player disconnect from server, if loading hang, kicked by BE etc.
	
	[] spawn {
		private["_timeOut","_display","_control1","_control2","_ctrlText"];
		disableSerialization;
		_timeOut = 0;		
		viruz_loadScreenMsg = localize "STR_InitializingVIRUZMOD";
		_ctrlText = "";
		diag_log "DEBUG: loadscreen guard started.";

		_display = uiNameSpace getVariable "RscDisplayLoading";	
		if (!isNil "_display") then {
			_control1 = _display displayctrl 1102;
		};
		
	// 120 sec timeout
		while { _timeOut < 12000 && !viruz_clientPreload } do {
			if (!isNil "_display") then {
				if ( isNull _display ) then {
					["PTm_loadingScreen"] call BIS_fnc_startLoadingScreen;
					_display = uiNameSpace getVariable "RscDisplayLoading";
					_control1 = _display displayctrl 1102;
				};
				if ( viruz_loadScreenMsg != "" ) then {
					_ctrlText = viruz_loadScreenMsg;
					viruz_loadScreenMsg = "";
				};
				_control1 ctrlSetText format["%1 : %2",_ctrlText,round(_timeOut*0.1)];
			};
			_timeOut = _timeOut + 1;
			sleep 0.1;
		};
		
		if ( !viruz_clientPreload ) then {

			diag_log "DEBUG: loadscreen guard ended with timeout.";
			disableUserInput false;
			1 cutText ["Something went wrong! disconnect and try again!", "PLAIN"];
			player enableSimulation false;
			sleep 10;
			"end1" call BIS_fnc_endMission;
		} else { 
			
			viruz_preloadFinished = true;
			_control1 ctrlSetText format["%1",localize "STR_InitializingVIRUZMODEND"];
			diag_log "DEBUG: loadscreen guard ended.";
		};
	};
	
	viruz_losChance = {
		private["_agent","_maxDis","_dis","_val","_maxExp","_myExp"];
		_agent = 	_this select 0;
		_dis =		_this select 1;
		_maxDis = 	_this select 2;
	//diag_log ("VAL:  " + str(_this));
		_val = 		(_maxDis - _dis) max 0;
		_maxExp = 	((exp 2) * _maxDis);
		_myExp = 	((exp 2) * (_val)) / _maxExp;
		_myExp = _myExp * 0.7;
		_myExp
	};
	
	ui_initDisplay = {
		private["_control","_ctrlBleed","_display","_ctrlFracture","_ctrlDogFood","_ctrlDogWater","_ctrlDogWaterBorder", "_ctrlDogFoodBorder"];
		disableSerialization;
		_display = uiNamespace getVariable 'VIRUZ_GUI_display';
		_control = 	_display displayCtrl 1204;
		_control ctrlShow false;
		if (!r_player_injured) then {
			_ctrlBleed = 	_display displayCtrl 1303;
			_ctrlBleed ctrlShow false;
		};
		if (!r_fracture_legs and !r_fracture_arms) then {
			_ctrlFracture = 	_display displayCtrl 1203;
			_ctrlFracture ctrlShow false;
		};
		_ctrlDogFoodBorder = _display displayCtrl 1501;
		_ctrlDogFoodBorder ctrlShow false;
		_ctrlDogFood = _display displayCtrl 1701;
		_ctrlDogFood ctrlShow false;
		
		_ctrlDogWaterBorder = _display displayCtrl 1502;
		_ctrlDogWaterBorder ctrlShow false;
		_ctrlDogWater = _display displayCtrl 1702;
		_ctrlDogWater ctrlShow false
	};
	
	viruz_losCheck = {
		private["_target","_agent","_cantSee"];
		_target = _this select 0;
		_agent = _this select 1;
		_cantSee = true;
		if (!isNull _target) then {
			_tPos = eyePos _target;	//(getPosASL _target);
			_zPos = eyePos _agent;	//(getPosASL _agent);
			if ((count _tPos > 0) and (count _zPos > 0)) then {
				_cantSee = terrainIntersectASL [_tPos, _zPos];
				//diag_log ("terrainIntersectASL: " + str(_cantSee));
				if (!_cantSee) then {
					_cantSee = lineIntersects [_tPos, _zPos];
					//diag_log ("lineIntersects: " + str(_cantSee));
				};
			};
		};
		_cantSee
	};
	
	eh_zombieInit = 	{
		private["_unit","_pos"];
		_unit = 	_this select 0;
		_pos =		getPosATL _unit;
		_id = [_pos,_unit] execFSM "\z\AddOns\viruz_mod\system\zombie_agent.fsm";
	};
	
	viruz_equipCheck = {
		private ["_empty", "_needed","_diff","_success"];
		_config = _this;
		_empty = [player] call BIS_fnc_invSlotsEmpty;
		_needed = [_config] call BIS_fnc_invSlotType;
		_diff = [_empty,_needed] call BIS_fnc_vectorDiff;
		
		_success = true;
		{
			if (_x > 0) then {_success = false};
		} forEach _diff;
		hint format["Config: %5\nEmpty: %1\nNeeded: %2\nDiff: %3\nSuccess: %4",_empty,_needed,_diff,_success,_config];
		_success
	};
		
	viruz_spaceInterrupt = {
		private ["_dikCode", "_handled", "_handWeapon","_animation"];
		_dikCode = 	_this select 1;
		_handled = false;
		if (_dikCode in actionKeys "GetOver" and viruz_glitchArea > 0) then {
			/*_animation = animationState player;
			if (_animation == "aovrpercmstpsraswrfldf") then {
				player switchMove "ActsPercMrunSlowWrflDf_FlipFlopPara";
			};*/
			
			hint "You are close to an enemy base.";
			_handled = true;
		};		
		if (_dikCode in actionKeys "moveDown" and viruz_glitchArea > 0) then {
			/*_animation = animationState player;
			if (_animation == "amovppnemstpsraswrfldnon") then {
				player switchMove "ActsPercMrunSlowWrflDf_FlipFlopPara";
			};*/
			hint "You are close to an enemy base.";
			_handled = true;
		};	
		/*if (_dikCode in (actionKeys "GetOver")) then {
			if (!r_fracture_legs and (time - viruz_lastCheckBit > 4)) then {
				_inBuilding = [player] call fnc_isInsideBuilding;
				_nearbyObjects = nearestObjects[getPosATL player, getArray (configFile >> "CfgObjectCheck" >> "objects"), 8];
				if (!_inBuilding and (count _nearbyObjects == 0)) then {
					viruz_lastCheckBit = time;
					call player_CombatRoll;
				};
			};
		};*/
		//if (_dikCode == 57) then {_handled = true}; // space
		//if (_dikCode in actionKeys 'MoveForward' or _dikCode in actionKeys 'MoveBack') then {r_interrupt = true};
		/*if (_dikCode == 210) then //SCROLL LOCK
		{
			_nill = execvm "\z\addons\viruz_mod\actions\playerstats.sqf";
		};*/
		/*if ((_dikCode in actionKeys "Gear") and (vehicle player != player) && !dialog) then {
			createGearDialog [player, "RscDisplayGear"];
			_handled = true;
		};*/
		if (_dikCode in actionKeys "MoveLeft") then {r_interrupt = true};
		if (_dikCode in actionKeys "MoveRight") then {r_interrupt = true};
		if (_dikCode in actionKeys "MoveForward") then {r_interrupt = true};
		if (_dikCode in actionKeys "MoveBack") then {r_interrupt = true};
		if (_dikCode in actionKeys "ForceCommandingMode") then {_handled = true};
		if (_dikCode in actionKeys "PushToTalk" and (time - viruz_lastCheckBit > 10)) then {
			viruz_lastCheckBit = time;
			[player,50,true,(getPosATL player)] spawn player_alertZombies;
		};
		if (_dikCode in actionKeys "VoiceOverNet" and (time - viruz_lastCheckBit > 10)) then {
			viruz_lastCheckBit = time;
			[player,50,true,(getPosATL player)] spawn player_alertZombies;
		};
		if (_dikCode in actionKeys "PushToTalkDirect" and (time - viruz_lastCheckBit > 10)) then {
			viruz_lastCheckBit = time;
			[player,15,false,(getPosATL player)] spawn player_alertZombies;
		};
		if (_dikCode in actionKeys "Chat" and (time - viruz_lastCheckBit > 10)) then {
			viruz_lastCheckBit = time;
			[player,15,false,(getPosATL player)] spawn player_alertZombies;
		};
		/*if (_dikCode in actionKeys "User20" and (time - viruz_lastCheckBit > 5)) then {
			viruz_lastCheckBit = time;
			_nill = execvm "\z\addons\viruz_mod\actions\playerstats.sqf";
		};*/
		
		//Open Craft Menu "0"
		/*if (_dikCode == 0x0B) then {
			if (craftOpen == 1) then {
				craftOpen = 0;
				closeDialog 0;
			} else {
				createDialog "RscDisplayCraftingMenu";
			};

		};*/
		
		//Home help Menu
		if (_dikCode == 0xC7) then {
			if (helpMenu == 1 ) then {
				helpMenu = 0;
				hint "";
			} else {
				execVM "\z\addons\viruz_mod\viruz\playerhelp.sqf";
				helpMenu = 1;
			};			
		};
		
		if (_dikCode in actionKeys "Headlights") then {
			if (currentWeapon player == "HandFlashlight") then {
				if !(player isFlashlightOn (currentWeapon player)) then {
					[] spawn HandFlashLight_monitor;
				};
			};
		};
		//holster
		if (_dikCode == dazy_keyWeapon) then {
		if (currentweapon player != "") then{
		viruz_Holster = currentweapon player;
		player action["switchWeapon", player, player, 100];
		} else {
		if (viruz_Holster != "") then{
			player selectWeapon viruz_Holster;
				};
			};
		};
		if (_dikCode in actionKeys "IngamePause") then {
			_idOnPause = [] spawn viruz_onPause;
		};
				//Hide Command and switch Primary weapon
		if (_dikCode == 0x02) then {
			showCommandingMenu "";
			_handWeapon = currentweapon player;
			if (_handWeapon != (primaryWeapon player) ) then {
				player selectWeapon (primaryWeapon player);
				_handWeapon = (primaryWeapon player);
			};
			_handled = true;
		};
		//Hide Command and switch handgun weapon
		if (_dikCode == 0x03) then {
			showCommandingMenu "";
			_handWeapon = currentweapon player;
			if (_handWeapon != (handgunWeapon player) ) then {
				player selectWeapon (handgunWeapon player);
				_handWeapon = (handgunWeapon player);
			};
			_handled = true;
		};
		
		//Hide Command and switch melee weapon
		if (_dikCode == 0x04) then {
			showCommandingMenu "";
			_handWeapon = currentweapon player;
			if (_handWeapon != (secondaryWeapon player) ) then {
				player selectWeapon (secondaryWeapon player);
				_handWeapon = (secondaryWeapon player);
			};
			_handled = true;
		};
		
		//Hide Command 4 and 5
		if (_dikCode == 0x05 or _dikCode == 0x06) then {
			showCommandingMenu "";
			_handled = true;
		};
		
		//Autorun
		if (_dikCode == 0xD2) then {
			if (viruz_glitchArea < 1) then
			{
				if (vzautoRun > 0 and !(surfaceisWater position player)) then 
				{
					r_interrupt = false; 
					vzautoRun = -1; 
					player switchmove ""; 
					player selectWeapon viruz_Holster; 
				}
				else
				{
					vzautoRun = 1; []spawn vz_playerAutorun;
				};
				_handled = true;
			};
		};
		//VZgroup
		if (_dikCode == 0xDB) then {
		if (tagName) then {tagName = false;titleText ["Group name tags OFF","PLAIN DOWN"];titleFadeOut 4;} else {tagName = true;titleText ["Group name tags ON","PLAIN DOWN"];titleFadeOut 4;};
			_handled = true;
		};
		if (_dikCode in actionKeys "TacticalView") then {
			_handled = true;
		};
		//0xDC right windows
		if (_dikCode == 0x16) then {
		if (dialog) then {closeDialog 0;groupManagementActive = false;} else {execVM "\z\addons\viruz_mod\external\vzgm\loadGroupManagement.sqf";};
			_handled = true;
		};
		//VZgroup end
		_handled
	};
	
	/*player_CombatRoll = {
		DoRE = ({isPlayer _x} count (player nearEntities ["AllVehicles",100]) > 1);
		if (canRoll && animationState player in ["amovpercmrunslowwrfldf","amovpercmrunsraswrfldf","amovpercmevaslowwrfldf","amovpercmevasraswrfldf"]) then {
			canRoll = false;
			null = [] spawn {
				if (DoRE) then {
//					[nil, player, rSWITCHMOVE, "ActsPercMrunSlowWrflDf_FlipFlopPara"] call RE;
					[[player,"ActsPercMrunSlowWrflDf_FlipFlopPara"],"MP_SwitchMove"] spawn BIS_fnc_MP;
				} else {
					player switchMove "ActsPercMrunSlowWrflDf_FlipFlopPara";
				};
				sleep 0.3;
				player setVelocity [(velocity player select 0) + 1.5 * sin direction player, (velocity player select 1) + 1.5 * cos direction player, (velocity player select 2) + 4];
				sleep 1;
				canRoll = true;
			};
			_handled = true;
		};
	};*/
	
	player_serverModelChange = {
		private["_object","_model"];
		_object = _this select 0;
		_model = _this select 1;
		if (_object == player) then {
			_model call player_switchModel;
		};
	};
	
	player_guiControlFlash = 	{
		private["_control"];
		_control = _this;
		if (ctrlShown _control) then {
			_control ctrlShow false;
		} else {
			_control ctrlShow true;
		};
	};
	
	gear_ui_offMenu = {
		private["_control","_parent","_menu"];
		disableSerialization;
		_control = 	_this select 0;
		_parent = 	findDisplay 602;
		if (!(_this select 3)) then {
			for "_i" from 0 to 9 do {
				_menu = _parent displayCtrl (1600 + _i);
				_menu ctrlShow false;
			};
			_grpPos = ctrlPosition _control;
			_grpPos set [3,0];
			_control ctrlSetPosition _grpPos;
			_control ctrlShow false;
			_control ctrlCommit 0;
		};
	}; 
	

	gear_ui_init = {
		private["_control","_parent","_menu","_dspl","_grpPos"];
		disableSerialization;
		_parent = findDisplay 602;
		_control = 	_parent displayCtrl 6902;
		for "_i" from 0 to 9 do {
			_menu = _parent displayCtrl (1600 + _i);
			_menu ctrlShow false;
		};
		_grpPos = ctrlPosition _control;
		_grpPos set [3,0];
		_control ctrlSetPosition _grpPos;
		_control ctrlShow false;
		_control ctrlCommit 0;
	};
	
	viruz_eyeDir = {
		private["_vval","_vdir"];
		_vval = (eyeDirection _this);
		_vdir = (_vval select 0) atan2 (_vval select 1);
		if (_vdir < 0) then {_vdir = 360 + _vdir};
		_vdir
	};
	
	viruz_lowHumanity = {
		private["_unit","_humanity","_delay"];
		_unit = _this;
		if ((_unit distance player) < 15) then {
			_humanity = _unit getVariable["humanity",0];
			viruz_heartBeat = true;
			if (_humanity < -3000) then {
				_delay = ((10000 + _humanity) / 5500) + 0.3;
				playSound "z_heartbeat_1";
				sleep _delay;
			};
			viruz_heartBeat = false;
		};
	};

/*VIRUZ_publishObj = {
	private ["_objeto","_direcao","_posicao","_tipoObj","_ownerTODB","_worldprecision"];
	_objeto		 = _this select 0;
	_direcao	 = _this select 1;
	_posicao	 = _this select 2;
	_tipoObj	 = _this select 3;
	_ownerTODB	 = _this select 4;
	_worldprecision = _this select 5;
		
		viruzUpdateBuild = ["VZPublishBuild",_objeto,_tipoObj,[_direcao,_posicao],_worldprecision,viruz_characterID,_ownerTODB,currentDate];
		//diag_log format["PUBLISH ACTION %1-%2-%3-%4-%5-%6-%7-%8","VZPublishBuild",_objeto,_tipoObj,[_direcao,_posicao],_worldprecision,viruz_characterID,_ownerTODB,currentDate];
		publicVariable "viruzUpdateBuild";
		sleep 5.0;
		hintSilent parseText format["<t size='1' font='Zeppelin33' color='#00FF04'>Build successfully!</t>", 0];
		sleep 1.5;
		hintSilent "";
		vz_cant_Build = false;
		//cutText ["You successfully Build!", "PLAIN DOWN",2];
};
*/
	vz_RemoveItemCargoGlobal = {
		private ["_container","_count","_type"];
			_container = _this select 0;
			_count = _this select 1;
			_type = _this select 2;


			_originalOldItems = itemCargo _container;
			_oldItems = + _originalOldItems;

			clearItemCargoGlobal _container;

			{
				if (_x == _type and _count > 0) then {
				_count = _count - 1;
				} else {
					_container addItemCargoGlobal [_x, 1];
				};
			}foreach _oldItems;
	};

	vz_RemoveMagazineCargoGlobal = {
		private ["_container","_count","_type"];
		_container = _this select 0;
		_count = _this select 1;
		_type = _this select 2;

		_originalOldMags = magazineCargo _container;
		_oldMags = + _originalOldMags;

		clearMagazineCargoGlobal  _container;

		{
			if (_x == _type and _count > 0) then {
			_count = _count - 1;
			} else {
				_container addMagazineCargoGlobal [_x, 1];
			};
		}foreach _oldMags;
	};

	//client
	VIRUZ_Client_fnc_spawnDynamicText = {
		if (isNil 'VIRUZ_DynamicText_inProgress') then
		{
			VIRUZ_DynamicText_inProgress = true;
			_this spawn
			{
				[
					_this,
					0,
					safeZoneY,
					5,
					1.5,
					0,
					24358
				] call BIS_fnc_dynamicText;
				VIRUZ_DynamicText_inProgress = nil;
			};
		};
	};
	
	VIRUZ_Client_fnc_spawnTextTiles = {
		if (isNil 'VIRUZ_Client_TextTiles_inProgress') then
		{
			VIRUZ_Client_TextTiles_inProgress = true;
			_this spawn
			{
				[
					parseText _this,
					[
						0,
						safeZoneY,
						1,
						1
					],
					[10,10],
					7,
					1.5,
					0
				] call BIS_fnc_textTiles;
				VIRUZ_Client_TextTiles_inProgress = nil;
			};
		}
	};

	VIRUZ_Client_fnc_hintSilent = compileFinal "hintSilent parsetext format['%1',_this];";
	
	/*
	viruz_meleeMagazineCheck = {
		private["_meleeNum","_magType","_wpnType"];
		_wpnType = _this;
		_magType = 	([] + getArray (configFile >> "CfgWeapons" >> _wpnType >> "magazines")) select 0;
		_meleeNum = ({_x == _magType} count magazines player);
		if (_meleeNum > 1) then {
			if (player hasWeapon _wpnType) then {
				_meleeNum = _meleeNum - 1;
			};
			for "_i" from 1 to _meleeNum do {
				player removeMagazine _magType;
			};
		};
	};
	*/
	
	viruz_originalPlayer =		player;
};

	progressLoadingScreen 0.8;
	

//**************************************************************** SERVER AND CLIENT COMPILES ************************************************
	
//	fnc_ManikenAddItems =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_ManikenAddItems.sqf";
//	maniken_gearSyncMP =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\maniken_gearSyncMP.sqf";
//	BIS_fnc_selectRandom =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_selectRandom.sqf";		//Checks which actions for nearby casualty
	ptm_fnc_getInventory =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_getInventory.sqf";		//get player inventory client/server
	fnc_buildWeightedArray = 	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_buildWeightedArray.sqf";		//Checks which actions for nearby casualty
	fnc_usec_damageVehicle =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_damageHandlerVehicle.sqf";		//Event handler run on damage
	zombie_initialize = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\init\zombie_init.sqf";
	object_vehicleKilled =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_vehicleKilled.sqf";		//Event handler run on damage
	object_setHitServer =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_setHitServer.sqf";	//process the hit as a NORMAL damage (useful for persistent vehicles)
	object_setFixServer =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_setFixServer.sqf";	//process the hit as a NORMAL damage (useful for persistent vehicles)
	object_getHit =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_getHit.sqf";			//gets the hit value for a HitPoint (i.e. HitLegs) against the selection (i.e. "legs"), returns the value
	object_setHit =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_setHit.sqf";			//process the hit as a NORMAL damage (useful for persistent vehicles)
	object_processHit =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_processHit.sqf";		//process the hit in the REVO damage system (records and sets hit)
	//object_delLocal =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_delLocal.sqf";		//cleaning 1
	object_cargoCheck =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_cargoCheck.sqf";		//Run by the player or server to monitor changes in cargo contents
	fnc_usec_damageHandler =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_damageHandler.sqf";		//Event handler run on damage
	// Vehicle damage fix
	vehicle_handleDamage    = compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\vehicle_handleDamage.sqf";
	vehicle_handleKilled    = compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\vehicle_handleKilled.sqf";
	fnc_vehicleEventHandler = 	compile preprocessFileLineNumbers "\z\addons\viruz_mod\init\vehicle_init.sqf";			//Initialize vehicle
	fnc_inString = 				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_inString.sqf";	
	fnc_isInsideBuilding = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_isInsideBuilding.sqf";	//_isInside = [_unit,_building] call fnc_isInsideBuilding;
	viruz_zombieSpeak = 			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_speak.sqf";			//Used to generate random speech for a unit
	vehicle_getHitpoints =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\vehicle_getHitpoints.sqf";
	local_gutObject =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\local_gutObject.sqf";		//Generated on the server (or local to unit) when gutting an object
	local_zombieDamage = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_damageHandlerZ.sqf";		//Generated by the client who created a zombie to track damage
	local_setFuel =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\local_setFuel.sqf";			//Generated when someone refuels a vehicle
	local_eventKill = 			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\local_eventKill.sqf";		//Generated when something is killed
	//player_weaponCheck =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_weaponCheck.sqf";	//Run by the player or server to monitor whether they have picked up a new weapon
	curTimeStr =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_curTimeStr.sqf";
	player_medBandage =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\medical\publicEH\medBandaged.sqf";
	player_medInject =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\medical\publicEH\medInject.sqf";
	player_medEpi =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\medical\publicEH\medEpi.sqf";
	player_medTransfuse =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\medical\publicEH\medTransfuse.sqf";
	player_medMorphine =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\medical\publicEH\medMorphine.sqf";
	player_medPainkiller =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\medical\publicEH\medPainkiller.sqf";
	world_isDay = 				{if ((daytime < (24 - viruz_sunRise)) and (daytime > viruz_sunRise)) then {true} else {false}};
	player_humanityChange =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_humanityChange.sqf";
	spawn_loot =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\spawn_loot.sqf";
	player_projectileNear = 	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_projectileNear.sqf";
	viruz_featchcfgDetails = 	compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZ_featchcfgDetails.sqf";
	
	VIRUZ_getOutVehicle = {
		private ["_dirTo","_end","_start"];

		params ["_unit","_position","_vehicle"];
		if (_unit == player) then {
			_start = getPosWorld _vehicle;

			_dirTo = _vehicle getDir player;
			_end = _vehicle getPos [(_vehicle distance player) + 1, _dirTo];
			{
				if (viruz_glitchArea > 0 ) then {
					//if (_x isKindOf "Wall_F" or _x isKindOf "VIRUZ_Modules") exitWith{
						player moveInAny _vehicle;
						hint "You cannot leave vehicles near build walls!";
					//};
				};
			} forEach lineintersectsobjs[_start, AGLToASL _end, player, _vehicle, true, 2];
		};
	};
	
	viruz_preciseposcalc = {
		private["_low", "_high"];
		_low = [
			(_this select 0) - ((_this select 0) % 1),
			(_this select 1) - ((_this select 1) % 1),
			(_this select 2) - ((_this select 2) % 1)
		];
		_high = _this vectorDiff _low;
		[_low, _high]
	};
	
	player_sumMedical = {
		private["_character","_wounds","_legs","_arms","_medical"];
		_character = 	_this;
		_wounds =		[];
		if (_character getVariable["USEC_injured",false]) then {
			{
				if (_character getVariable[_x,false]) then {
					_wounds set [count _wounds,_x];
				};
			} forEach USEC_typeOfWounds;
		};
		_legs = _character getVariable ["hit_legs",0];
		_arms = _character getVariable ["hit_arms",0];
		_medical = [
			_character getVariable["USEC_isDead",false],
			_character getVariable["NORRN_unconscious", false],
			_character getVariable["USEC_infected",false],
			_character getVariable["USEC_injured",false],
			_character getVariable["USEC_inPain",false],
			_character getVariable["USEC_isCardiac",false],
			_character getVariable["USEC_lowBlood",false],
			_character getVariable["USEC_BloodQty",12000],
			_wounds,
			[_legs,_arms],
			_character getVariable["unconsciousTime",0],
			_character getVariable["messing",[0,0]]
		];
		_medical
	};
	
	VZ_fnc_substr = {
		//substring = [string] call VZ_fnc_substr;
		private "_arr";
		_arr = toArray (_this select 0);
		_ElementsToErase = [66,34];  
		_Newarray = _arr - _ElementsToErase;
		toString _Newarray  
	};


	//**************************************************************** SERVER ONLY COMPILES ************************************************
	if (isServer) then {
		call compile preprocessFileLineNumbers "\z\addons\viruz_server\init\server_functions.sqf";
	} else {
		eh_localCleanup = {};
	};
	

	//Start Dynamic Weather
	execVM "\z\addons\viruz_mod\external\DynamicWeatherEffects.sqf";
	initialized = true;