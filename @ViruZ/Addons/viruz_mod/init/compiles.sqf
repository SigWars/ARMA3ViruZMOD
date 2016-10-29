//Player only
if (!isDedicated) then {
	_config = 	missionConfigfile >> "CfgLoot";
	_config1 = 	configFile >> "CfgMagazines" >> "FoodEdible";
	_config2 = 	configFile >> "CfgWeapons" >> "Loot";

//	"filmic" setToneMappingParams [0.07, 0.31, 0.23, 0.37, 0.011, 3.750, 6, 4]; setToneMapping "Filmic";
//	player_ReammoMagazines =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_ReammoMagazines.sqf";
	vz_playerAutorun =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_autorun.sqf";
	ptm_fnc_getInventory =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_getInventory.sqf";
	PTm_fnc_filterGear =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_filterGear.sqf";
	PTm_fnc_getMagazinesEmpty = compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_getMagazinesEmpty.sqf";
	HandFlashLight_monitor =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\HandFlashLight_monitor.sqf";
	maniken_gearSync =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\maniken_gearSync.sqf";
	player_addEventHandlers =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\init\player_addEventHandlers.sqf";
//	player_ObjectInBuildingCheck = compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_ObjectInBuildingCheck.sqf";
	MP_say =					compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\say.sqf";
	MP_SwitchMove =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\switchmove.sqf";
	MP_PlayMove =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\PlayMove.sqf";
//	BIS_Effects_Burn = 			compile preprocessFile "\ca\Data\ParticleEffects\SCRIPTS\destruction\burn.sqf"; 
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
	player_spawnLootCheck =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_spawnlootCheck.sqf";
	player_spawnZedCheck =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_spawnzedCheck.sqf";
	building_spawnLoot =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\building_spawnLoot.sqf";
	player_taskHint =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_taskHint.sqf";
	building_spawnZombies =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\building_spawnZombies.sqf";
	//animal_monitor =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\animal_monitor.sqf";
	building_monitor =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\building_monitor.sqf";
	player_fired =				compileFinal preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_fired.sqf";			//Runs when player fires. Alerts nearby Zeds depending on calibre and audial rating
	player_packTent =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_packTent.sqf";
	//control_zombieAgent = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\control_zombieAgent.sqf";
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
	//player_chopWood =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_chopWood.sqf";
	player_build =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_build.sqf";
	player_wearClothes =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_wearClothes.sqf";
	player_dropWeapon =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_dropWeapon.sqf";
	player_setTrap =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_setTrap.sqf";
	object_pickup = 			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\object_pickup.sqf";
	player_flipvehicle = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_flipvehicle.sqf";
	player_sleep = 				compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_sleep.sqf";
	electronics_build =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\Electronics_build.sqf";
	
	//ui
	player_selectSlot =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\ui_selectSlot.sqf";
	player_gearSync	=			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_gearSync.sqf";
	player_gearSet	=			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_gearSet.sqf";
	ui_changeDisplay = 			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\ui_changeDisplay.sqf";
	
	//playerstats
	horde_epeen_fnc_fill_page = compile preProcessFile "\z\addons\viruz_mod\actions\playerstats\fill_page_fnc.sqf";
	horde_epeen_determine_humanity_fnc = compile preProcessFile "\z\addons\viruz_mod\actions\playerstats\determine_humanity_fnc.sqf";
	horde_epeen_setText_journal_fnc = compile preProcessFile "\z\addons\viruz_mod\actions\playerstats\epeen_setText_journal.sqf";
	horde_epeen_setText_humanity_fnc = compile preProcessFile "\z\addons\viruz_mod\actions\playerstats\epeen_setText_humanity.sqf";
	horde_epeen_setText_stats_fnc = compile preProcessFile "\z\addons\viruz_mod\actions\playerstats\epeen_setText_stats.sqf";
	horde_epeen_show_humanity_fnc = compile preProcessFile "\z\addons\viruz_mod\actions\playerstats\show_humanity_fnc.sqf";
	
	//System
	player_monitor =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\player_monitor.sqf";
	player_spawn_1 =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\player_spawn_1.sqf";
	player_spawn_2 =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\system\player_spawn_2.sqf";
//	onPreloadStarted 			"viruz_preloadFinished = false;";
//	onPreloadFinished 			"viruz_preloadFinished = true;";
	
	//Test
	SelectedInventoryItem = nil;
	VZClient_object_item_craft = 								compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_object_item_craft.sqf";
	VZClient_item_getCrafting = 								compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_item_getCrafting.sqf";
	VZClient_item_getCrafting =									compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_item_getCrafting.sqf";
	VZClient_gui_itemDescription_event_onTabelaButton = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_gui_itemDescription_event_onTabelaButton.sqf";
	VZClient_gui_itemDescription_event_onCraftingDoubleClick =  compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_gui_itemDescription_event_onCraftingDoubleClick.sqf";
	VZClient_gui_crafting_show = 								compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\VZClient_gui_crafting_show.sqf";
	ViruZClient_gui_itemDescription_show =						compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZClient_gui_itemDescription_show.sqf";
	ViruZClient_gui_inventory_event_onItemDoubleClick =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZClient_gui_inventory_event_onItemDoubleClick.sqf";
	ViruZClient_gear_getConfigNameByClassName =					compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZClient_gear_getConfigNameByClassName.sqf";
	ViruZClient_gear_getConfigEntryByDisplayName =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\ViruZClient_gear_getConfigEntryByDisplayName.sqf";
	
	
	//Crafting
	fn_updateCraftUI = compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_updateCraftUI.sqf";
	player_craftItem = compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_craftItem.sqf";
	player_checkRecipe = compile preprocessFileLineNumbers "\z\addons\viruz_mod\actions\player_checkRecipe.sqf";
	
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
		private ["_dikCode", "_handled"];
		_dikCode = 	_this select 1;
		_handled = false;
		if (_dikCode in (actionKeys "GetOver")) then {
			if (!r_fracture_legs and (time - viruz_lastCheckBit > 4)) then {
				_inBuilding = [player] call fnc_isInsideBuilding;
				_nearbyObjects = nearestObjects[getPosATL player, getArray (configFile >> "CfgObjectCheck" >> "objects"), 8];
				if (!_inBuilding and (count _nearbyObjects == 0)) then {
					viruz_lastCheckBit = time;
					call player_CombatRoll;
				};
			};
		};
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
		
		if ((_dikCode == 0x3E or _dikCode == 0x0F or _dikCode == 0xD3) and (time - viruz_lastCheckBit > 10)) then {
			viruz_lastCheckBit = time;
			call viruz_forceSave;
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
		/*
		if (_dikCode in actionKeys "IngamePause") then {
			_idOnPause = [] spawn viruz_onPause;
		};
		*/
		//Hide Command menu by SigWar
		if (_dikCode == 0x02 or _dikCode == 0x03 or _dikCode == 0x04 or _dikCode == 0x05 or _dikCode == 0x06) then {
			showCommandingMenu "";
			_handled = true;
		};
		//Autorun
		if (_dikCode == 0xD2) then {
			if (vzautoRun > 0 and !(surfaceisWater position player)) then {r_interrupt = false; vzautoRun = -1; player switchmove "";} else {vzautoRun = 1; []spawn vz_playerAutorun;};
			_handled = true;
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
	
	player_CombatRoll = {
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
	};
	
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
				playSound "heartbeat_1";
				sleep _delay;
			};
			viruz_heartBeat = false;
		};
	};
/**************************ViruZ Build*******************************************************************************************************/
	
	ON_fnc_getSpotPosition = {
	    private ["_closest_test_spot_position","_closest_test_distance","_closest_test_spot","_spot_test_position","_test_distance","_on_water","_test_object","_test_position"];
	    _closest_test_spot_position = [];
	    _test_object = _this select 0;
	    _test_position = _this select 1;
	    _on_water = _this select 2;
	    _closest_test_distance = 0;
	    {
    		_spot_test_position = _test_object modelToWorld (_x select 0);
		    _test_distance = _test_position distance _spot_test_position;
		    if (_on_water) then {
    			_spot_test_position = [(_spot_test_position) select 0, (_spot_test_position) select 1, (getPosASL _test_object) select 2];
	    	};
		    if ((_closest_test_distance == 0 or _test_distance < _closest_test_distance or _test_distance == 0) && (SnappingDir == (_x select 1) || (_x select 1) == 90 || (_x select 1) == 270)) then {
			    _closest_test_spot_position = _spot_test_position;
			    _closest_test_distance = _test_distance;
			    _closest_test_spot = _x;
		    };
	    } forEach _target_spots;
	    [_closest_test_spot_position, _closest_test_spot];
    };
	
	VIRUZ_precisionPos = compileFinal '
	private["_low", "_high"];
	_low = [
		(_this select 0) - ((_this select 0) % 1),
		(_this select 1) - ((_this select 1) % 1),
		(_this select 2) - ((_this select 2) % 1)
	];
	_high = _this vectorDiff _low;
	[_low, _high]';

	/*VZ_update_objectdb = {
		private ["_objeto","_direcao","_posicao","_ownerTODB","_objectID","_objectUID"];
		_objeto		 = _this select 0;
		_direcao	 = _this select 1;
		_posicao	 = _this select 2;
		_ownerTODB	 = _this select 3;
		sleep 3;
		_objectID 	= _objeto getVariable ["ObjectID","0"];
		_objectUID	= _objeto getVariable ["ObjectUID","0"];
		if (_objectID == "0" and _objectUID == "0" ) then {
			hint parseText format["<t size='1' font='Zeppelin33' color='#ff0000'>WARNING! CANT SAVE OBJECT, PLEASE REMOVE AND REBUILD!</t>", 0];
			vz_cant_Build = false;	
			sleep 5.0;
			hintSilent "";
		} else {
			viruzUpdateBuild = ["UPDposition",_objectID,_objectUID,_ownerTODB,[_direcao,_posicao]];
			publicVariable "viruzUpdateBuild";
			hintSilent parseText format["<t size='1' font='Zeppelin33' color='#00FF04'>Object successfully moved!</t>", 0];
			vz_cant_Build = false;
			sleep 1.5;
			hintSilent "";
		};
	};*/
		
VZ_move_object = {
    private ["_distance","_direction","_high","_currentDistanceDiff","_distanceDiff","_search_range","_spot_positionA","_spot_positionB","_object", "_config", "_type", "_attachToPlayer", "_object_types", "_target_spots","_height_diff","_object_height","_target_height","_distance_diff","_object_pos","_target_pos","_best_distance_object","_best_height_object","_position", "_nearest_objects", "_closest_spot", "_closest_distance","_spot_marker","_target_object","_pos","_offsetDir","_possible_targets","_current_distance_diff","_current_height_diff","_spot_position","_calculated_pos","_best_spot_position","_best_spot","_location","_dir","_VecDir","_VecNormal","_novadir","_vectorOffset","_bbr","_maxSize","_offset","_isWater","_ownerTODB","_ownerUID","_objectID","_objectUID","_hasGenerator","_findObject","_metros","_cansave","_AttchPosition","_direcao","_positionASL","_positionATL","_worldvectorDirUp","_posicao","_posicao_final","_storageObj"];
	
    VIRUZ_Build_object = _this select 0;
    VIRUZ_Build_action = _this select 1;
	_hasGenerator = _this select 2;
	VIRUZ_Build_type = typeOf VIRUZ_Build_object;
	_cansave = true;
	_AttchPosition = getPos Player;
	
	if (VIRUZ_Build_action == "MoveObject") then {
		private ["_hasmags", "_hasitems", "_hasweapons", "_totalcount"];
		
		_hasmags = MagazineCargo VIRUZ_Build_object;
		_hasitems = ItemCargo VIRUZ_Build_object;
		_hasweapons = WeaponCargo VIRUZ_Build_object;
		
		_totalcount = + count _hasmags + count _hasitems + count _hasweapons;
		
		if (_totalcount > 0) exitWith { 
			cutText ["You cant move objects with itens inside", "PLAIN DOWN"];
			_cansave = false;
			vz_cant_Build = false;
		};
	};
	
	if (_hasGenerator) then {
		
		_findObject = nearestObjects [player, ["Land_Portable_generator_F"], viruz_maxBuildDistance+30];
			
			if (count _findObject > 0 ) then {
				ViruZ_Generator = _findObject select 0;
				_GeneratorUID = ViruZ_Generator getVariable ["OwnerUID","0"];
				_ownerTODB = str( 'B'+ _GeneratorUID );
				_ownerUID = _GeneratorUID;
				//cuttext [format ["Generator Detected! and Owner is %1 and to DB is %2",_GeneratorUID,_ownerTODB],"PLAIN DOWN",1];
			} else {
				//doubkle check to prevent crash!!
				_ownerTODB = str( 'B'+ getPlayerUID player );
				_ownerUID = getPlayerUID player;
			};
			
	} else {
			_ownerTODB = str( 'B'+ getPlayerUID player );
			_ownerUID = getPlayerUID player;
	};
	
    //hint format ["ObjetoNovo = %1 ", novoObjeto];

    _bbr = boundingBoxReal VIRUZ_Build_object;
    _p1 = _bbr select 0;
    _p2 = _bbr select 1;
    _maxWidth = abs ((_p2 select 0) - (_p1 select 0));
    _maxLength = abs ((_p2 select 1) - (_p1 select 1));
    _maxHeight = abs ((_p2 select 2) - (_p1 select 2));
    _maxSize = 0;
    if (_maxWidth >= _maxLength) then {_maxSize = _maxWidth} else {_maxSize = _maxLength};
	_distance = (_maxSize / 2) + 1;
	
	//snap function parms
    _offset = 	getArray (configFile >> "CfgVehicles" >> VIRUZ_Build_type >> "offset");
    if((count _offset) <= 0) then {
    	_offset = [0, _distance,1.7];
    };

    SnappingOffset = _offset;
    SnappingDir = 0;
	ManualDir = false;
    SnappingSpotMarkers = [];
    SnappingEnabled = false;
    SnappedOffsetZ = 0;
    SnappingResetPos = false;

    //Disable all Collisions with the Object
    [[VIRUZ_Build_object,"Disable"],"viruz_fnc_updateCollisions",true,false,true] call BIS_fnc_MP;

    //Attach the new Object to the player. The distance to the player is calculated with the Object sizes
    VIRUZ_Build_object attachTo [player,[0, _distance,1.7]];
    VIRUZ_Build_object setVariable ["viruz_build_distance",_distance,true];
    VIRUZ_Build_object setVariable ["viruz_build_additionalDistance",0,true];
    VIRUZ_Build_object setVariable ["viruz_build_objectDir",0,true];
	_eRack = VIRUZ_Build_type in VIRUZ_RACKS;
	if (_eRack) then {
		VIRUZ_Build_object allowDamage false;
	};

    //add Action for snap object, detach object and break the while loop
    s_build_detach =  player addAction ["Build Object",{Movendo = 2; detach (_this select 3);  player removeAction (_this select 2)},VIRUZ_Build_object];
	s_buil_manualdir = player addAction ["<t color=""#01DF01"">Toggle Direction Mode</t>", "\viruz_build\functions\player_manualdir.sqf",VIRUZ_Build_type, 3, true, false, "",""];
    if (isClass (missionConfigFile >> "SnapPoints" >> VIRUZ_Build_type)) then {
		    s_building_snapping = player addAction ["<t color=""#0000ff"">Toggle Snapping</t>", "\viruz_build\functions\player_toggleSnapping.sqf",VIRUZ_Build_type, 4, true, false, "",""];
	};
	
    // Private
    
    	Movendo = 0;
    	_direction = 0;
    	_high = 1.7;
	
	    _VecDir = [0,1,0];
	    _VecNormal = [0,0,1];
	
    	_config = (missionConfigFile >> "SnapPoints" >> VIRUZ_Build_type);
    	SnappingAttachedToPlayer = true;

    _object_types = getArray(_config >> "snap");
    _target_spots = getArray(_config >> "points");

    if ((count _target_spots) > 0) then {
    	_currentDistanceDiff = 0;
    	_search_range = 0;
	    {
		    _distanceDiff = [0,0,0] distance [(_x select 0) select 0, (_x select 0) select 1, 0];
		    if ((_distanceDiff) > 0 && (_distanceDiff) > _currentDistanceDiff) then {
    			_currentDistanceDiff = _distanceDiff;
			    _search_range = ((_distanceDiff) + 2);
		    };
	    } forEach _target_spots;
    }
    else
    {_search_range = 10;}; //10

    diag_log format["Building Object: %1", VIRUZ_Build_object];
    diag_log format["TAMANHO = %1", _bbr];
	vz_cant_Build = true;
		
    while {Movendo < 1} do 
	{
		
		//******************************************************************************************
		if (SnappingAttachedToPlayer) then {
			
			_distance = (VIRUZ_Build_object getVariable "viruz_build_distance") + (VIRUZ_Build_object getVariable "viruz_build_additionalDistance");
			_direction = ((acos ((ATLtoASL positionCameraToWorld [0, 0, 1] select 2) - (ATLtoASL positionCameraToWorld [0, 0, 0] select 2)) - 90)* -1);	
			if (!freeLook) then {_high = ((tan _direction) * _distance) + 1.7 + ((getPos Player) select 2);};
		
			if (_high > (6 + ((getPos Player) select 2))) then { _high = ((getPos Player) select 2) + 6};
			if (_high < (-6 + ((getPos Player) select 2))) then { _high = ((getPos Player) select 2) + -6};
			
			VIRUZ_Build_object attachTo [player,[0, _distance,_high]];
			/*SnappingAttachedToPlayer = true;*/			
		};	

		//******************************************************************************************
						
		if (VIRUZ_Build_alignToGround) then	{
			
			_VecNormal = surfaceNormal (getPos VIRUZ_Build_object);
			_VecNormal = (player worldToModel ASLtoATL (_VecNormal vectorAdd getPosASL player)) vectorDiff (player worldToModel ASLtoATL (getPosASL player));
			_dir = VIRUZ_Build_object getVariable "viruz_build_objectDir";
			_VecDir = [-cos _dir, sin _dir, 0] vectorCrossProduct _VecNormal;
			
		} else {
			
			_VecNormal = [0,0,1];
			_dir = VIRUZ_Build_object getVariable "viruz_build_objectDir";
			_VecDir = [-cos _dir, sin _dir, 0] vectorCrossProduct _VecNormal;
			
		};
	
		_isWater = (surfaceIsWater position VIRUZ_Build_object);
		if (isClass _config and SnappingEnabled) then {
				_position = player modelToWorld SnappingOffset;
				if (!_isWater) then {
					_position = [(_position) select 0, (_position) select 1, (getPosATL VIRUZ_Build_object) select 2];
				} else {
					_position = [(_position) select 0, (_position) select 1, (getPosASL VIRUZ_Build_object) select 2];
				};	

				_nearest_objects = nearestObjects [_position, _object_types, _search_range] - [VIRUZ_Build_object];
				_current_distance_diff = 20;
				_best_distance_object = objNull;
				_target_object = objNull;
				_possible_targets = [];
				{
					if (_x != VIRUZ_Build_object) then {
						_object_pos = _position;
						_spot_position_array = [];
						_closest_spot_position = [];
						_closest_spot = [];
						_spot_position_array = [_x, _object_pos, _isWater] call ON_fnc_getSpotPosition;
						_closest_spot_position = _spot_position_array select 0;
						_closest_spot = _spot_position_array select 1;
						_distance_diff = _closest_spot_position distance _object_pos;
						if (_distance_diff < _current_distance_diff && _distance_diff < _search_range) then {
							_current_distance_diff = _distance_diff;
							_best_distance_object = _x;
							_closest_spot_position_array = [_best_distance_object, _object_pos, _isWater] call ON_fnc_getSpotPosition;
							_best_spot_position = _closest_spot_position_array select 0;
							_best_spot = _closest_spot_position_array select 1;
						};
					};
				} forEach _nearest_objects;
				if (!isNull _best_distance_object) then {
					_possible_targets set [(count _possible_targets), _best_distance_object];
				};
				if (count _possible_targets > 0) then {
					_target_object = _possible_targets select 0;
				};
				if (!isNull _target_object) then {
					_closest_distance = 0;
					_distance = (_position distance _best_spot_position);
					if (_closest_distance == 0 or _distance < _closest_distance) then {
						_closest_distance = _distance;
					};
					if (_closest_distance <= 2) then {
						if (SnappingAttachedToPlayer) then {
							detach VIRUZ_Build_object;
							if !(ManualDir) then {
							if ((_best_spot select 1) != 90 && (_best_spot select 1) != 270) then {
								_offsetDir = (getDir _target_object) + (_best_spot select 1);
								if (SnappingDir == 180) then {
									_offsetDir = (getDir _target_object) + SnappingDir; 
								};
								if ((getDir player - getDir _target_object) >= 50 || (getDir player - getDir _target_object) <= -50) then {
									_offsetDir = _offsetDir - 180;
								};
							} else {
								_offsetDir = (getDir _target_object) + (_best_spot select 1);
								if ((_best_spot select 1) == 90) then {
									if (SnappingDir == 180) then {
										_offsetDir = _offsetDir + 180;
									};
								} else {
									_offsetDir = _offsetDir - 180;
									if (SnappingDir == 180) then {
										_offsetDir = _offsetDir + 180;
									};
								};
								if ((getDir player - getDir _target_object - 90)  >= 90 || (getDir player - getDir _target_object - 90) <= -90) then {
									_offsetDir = _offsetDir -180;
								};
							};
							} else { _offsetDir = ( (VIRUZ_Build_object getVariable "viruz_build_objectDir") + getDir _target_object)};
							_offsetDir = if (_offsetDir > 360) then { _offsetDir - 360 } else { _offsetDir };
							_offsetDir = if (_offsetDir < 0) then { _offsetDir + 360 } else { _offsetDir };
							VIRUZ_Build_object setDir _offsetDir;
							
							SnappingAttachedToPlayer = false;
							SnappingResetPos = true;
						};	
						if (SnappingResetPos) then {
							if (_isWater) then {
								VIRUZ_Build_object setPosASL _best_spot_position;
							} else {
								VIRUZ_Build_object setPosATL _best_spot_position;
							};
							SnappingResetPos = false;
						};
					} else { 
							SnappingAttachedToPlayer = true;
					};
				} else { 
						SnappingAttachedToPlayer = true;
				};
		} else { 
				SnappingAttachedToPlayer = true;
		};
	
		if !(SnappingEnabled) then {	
			VIRUZ_Build_object setVectorDirAndUp [_VecDir, _VecNormal];
		};
		
		
		//Check move generator is near other player bases
		_distMoved = VIRUZ_Build_object distance _AttchPosition;
		if (_distMoved > 20 and (TypeOf VIRUZ_Build_object == "Land_Portable_generator_F") ) then {
			_cansave = false;
			hintSilent parseText format["<t size='1' font='Zeppelin33' color='#ff0000'>You can not move the Generator more than 20 meters. it will be removed if you keep moving apart. back to safezone</t>", 0];
		} else {
			_cansave = true;
			hint "";
		};
		
		if (_distMoved > 30 and (TypeOf VIRUZ_Build_object == "Land_Portable_generator_F") ) then {
			Movendo = 2;
			_cansave = false;
			player removeAction s_build_detach;
			
			if (isClass (missionConfigFile >> "SnapPoints" >> VIRUZ_Build_type)) then {
				player removeAction s_building_snapping;
			};
			player removeAction s_buil_manualdir;
			
			_objectID 	= VIRUZ_Build_object getVariable ["ObjectID","0"];
			_objectUID	= VIRUZ_Build_object getVariable ["ObjectUID","0"];
			if !(_objectID == "0" and _objectUID == "0") then {
				viruzDeleteObj = [_objectID,_objectUID];
				publicVariable "viruzDeleteObj";
			};
			
			deleteVehicle VIRUZ_Build_object;
		};
		
		
		//check if is far from generator
		if (_hasGenerator and !(TypeOf VIRUZ_Build_object == "Land_Portable_generator_F")) then {
			
			_metros =  VIRUZ_Build_object distance ViruZ_Generator;
			if (_metros > viruz_maxBuildDistance) then {
				hintSilent parseText format["<t size='1' font='Zeppelin33' color='#ff0000'>Object is far from the Generator. it will be removed if you keep moving apart. back to safezone!</t>", 0];
				_cansave = false;
			} else {
				_cansave = true;
				hint "";
			};
			
			if (_metros > viruz_maxBuildDistance + 10) then {
				Movendo = 2;
				_cansave = false;
				player removeAction s_build_detach;
				
				if (isClass (missionConfigFile >> "SnapPoints" >> VIRUZ_Build_type)) then {
					player removeAction s_building_snapping;
				};
				player removeAction s_buil_manualdir;
				
				_objectID 	= VIRUZ_Build_object getVariable ["ObjectID","0"];
				_objectUID	= VIRUZ_Build_object getVariable ["ObjectUID","0"];
				if !(_objectID == "0" and _objectUID == "0") then {
					viruzDeleteObj = [_objectID,_objectUID];
					publicVariable "viruzDeleteObj";
				};
				
				deleteVehicle VIRUZ_Build_object;
			};
		};
		
		
		sleep 0.01;
	};
		
	player playActionNow "Medic";
	_sfx = "repair";
	[player,_sfx,0,false,20] call viruz_zombieSpeak;  
	[player,20,true,(getPosATL player)] spawn player_alertZombies;
	
	if (isClass (missionConfigFile >> "SnapPoints" >> VIRUZ_Build_type)) then {
		player removeAction s_building_snapping;
	};
	player removeAction s_buil_manualdir;
	
	//Calculate precision locate to save in DB
	if (_isWater) then {
		_positionASL =  getPosASL VIRUZ_Build_object;
		_positionATL = ASLtoATL _positionASL;
		_posicao = [(_positionATL call VIRUZ_precisionPos), vectordir VIRUZ_Build_object, vectorup VIRUZ_Build_object];
	} else {
		_posicao = [(getposATL VIRUZ_Build_object call VIRUZ_precisionPos), vectordir VIRUZ_Build_object, vectorup VIRUZ_Build_object];
	};
	_worldvectorDirUp = [_posicao select 1,_posicao select 2];
	_posicao_calc = _posicao deleteAt 0;
	_posicao_final = (_posicao_calc select 0) vectorAdd (_posicao_calc select 1);
	
	//Check Action Type
	if (VIRUZ_Build_action == "CreateObject" and _cansave) then {
		deleteVehicle VIRUZ_Build_object;
		
	} else {
			
		if (VIRUZ_Build_action == "MoveObject" and _cansave) then {
			_objectID 	= VIRUZ_Build_object getVariable ["ObjectID","0"];
			_objectUID	= VIRUZ_Build_object getVariable ["ObjectUID","0"];
	
			if (_objectID == "0" && _objectUID == "0") exitWith { 
				cutText ["Não foi possivel remover o objeto,tente novamente em alguns segundos", "PLAIN DOWN"];
				vz_cant_Build = false;
			};

			viruzDeleteObj = [_objectID,_objectUID];
			publicVariable "viruzDeleteObj";
			deleteVehicle VIRUZ_Build_object;
		};
	};
	
	//Recreate and Save to Database
	if (_cansave) then {
		_storageObj = createVehicle[VIRUZ_Build_type, _posicao_final, [], 0, "CAN_COLLIDE"];
		if (_storageObj in VIRUZ_RACKS) then {
			_storageObj allowDamage false;
		};
		_storageObj setVectorDirAndUp _worldvectorDirUp;
		_storageObj setposATL _posicao_final;
		_direcao = getDir _storageObj;
	
		_storageObj setVariable ["characterID",viruz_characterID,true];
		_storageObj setVariable ["OwnerUID",	_ownerUID, true];
		if (_storageObj in VIRUZ_BUILDS + VIRUZ_GATES) then {
			_storageObj setVariable ["Locked", "0", true];
			_storageObj setVariable ["Door_1_Lock", "0", true];
			_storageObj setVariable ["Door_2_Lock", "0", true];
			_storageObj setVariable ["Door_3_Lock", "0", true];
			_storageObj setVariable ["Door_4_Lock", "0", true];
			_storageObj setVariable ["Door_5_Lock", "0", true];
			_storageObj setVariable ["Door_6_Lock", "0", true];
		};
		
		[_storageObj,_direcao,_posicao_final,VIRUZ_Build_type,_ownerTODB,_posicao] spawn VIRUZ_publishObj;
	};
	
	VIRUZ_Build_object setVariable ["viruz_build_distance",Nil,false];
	VIRUZ_Build_object setVariable ["viruz_build_objectDir",Nil,false];
	VIRUZ_Build_object setVariable ["viruz_build_additionalDistance",Nil,false];
	
	VIRUZ_Build_object = Nil;
	VIRUZ_Build_action = Nil;
	VIRUZ_Build_type = Nil;
	SnappingDir = 0;
    SnappingSpotMarkers = [];
    SnappingEnabled = false;
    SnappedOffsetZ = 0;
    SnappingResetPos = false;
	SnappingOffset = 0;
  	
};

VIRUZ_publishObj = {
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
/************************************************************************************************************************************/
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

	//Both
	
//	fnc_ManikenAddItems =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_ManikenAddItems.sqf";
//	maniken_gearSyncMP =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\maniken_gearSyncMP.sqf";
//	BIS_fnc_selectRandom =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_selectRandom.sqf";		//Checks which actions for nearby casualty
	fnc_buildWeightedArray = 	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_buildWeightedArray.sqf";		//Checks which actions for nearby casualty
	fnc_usec_damageVehicle =	compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\fn_damageHandlerVehicle.sqf";		//Event handler run on damage
	zombie_initialize = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\init\zombie_init.sqf";
	object_vehicleKilled =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_vehicleKilled.sqf";		//Event handler run on damage
	object_setHitServer =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_setHitServer.sqf";	//process the hit as a NORMAL damage (useful for persistent vehicles)
	object_setFixServer =		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_setFixServer.sqf";	//process the hit as a NORMAL damage (useful for persistent vehicles)
	object_getHit =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_getHit.sqf";			//gets the hit value for a HitPoint (i.e. HitLegs) against the selection (i.e. "legs"), returns the value
	object_setHit =				compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_setHit.sqf";			//process the hit as a NORMAL damage (useful for persistent vehicles)
	object_processHit =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_processHit.sqf";		//process the hit in the REVO damage system (records and sets hit)
	object_delLocal =			compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\object_delLocal.sqf";
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
	player_projectileNear = 		compile preprocessFileLineNumbers "\z\addons\viruz_mod\compile\player_projectileNear.sqf";
	
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

	//Server Only
	if (isServer) then {
		call compile preprocessFileLineNumbers "\z\addons\viruz_server\init\server_functions.sqf";
	} else {
		eh_localCleanup = {};
	};
	
	
	//Start Dynamic Weather
	execVM "\z\addons\viruz_mod\external\DynamicWeatherEffects.sqf";
	initialized = true;