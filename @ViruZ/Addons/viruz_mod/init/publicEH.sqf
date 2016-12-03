//Medical Event Handlers
"norrnRaLW"   		addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\viruz_mod\medical\publicEH\load_wounded.sqf"};
"norrnRLact"		addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\viruz_mod\medical\load\load_wounded.sqf"};
"norrnRDead"   		addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\viruz_mod\medical\publicEH\deadState.sqf"};

//fn_damageHandler.sqf /player_humanityMorph.sqf
"usecBleed"			addPublicVariableEventHandler {_id = (_this select 1) spawn fnc_usec_damageBleed};

//bandage.sqf
"usecBandage"		addPublicVariableEventHandler {(_this select 1) call player_medBandage};

//"usecInject"		addPublicVariableEventHandler {(_this select 1) call player_medInject};

//epinephrine.sqf
"usecEpi"			addPublicVariableEventHandler {(_this select 1) call player_medEpi};

//transfusion.sqf
"usecTransfuse"		addPublicVariableEventHandler {(_this select 1) call player_medTransfuse};

//morphine.sqf
"usecMorphine"		addPublicVariableEventHandler {(_this select 1) call player_medMorphine};

//painkiller.sqf
"usecPainK"			addPublicVariableEventHandler {(_this select 1) call player_medPainkiller};

//player_zombieAttack
"viruzHit" 			addPublicVariableEventHandler {(_this select 1) call fnc_usec_damageHandler};

//player_zombieAttack.sqf hit in vehicles
"viruzHitV" 			addPublicVariableEventHandler {(_this select 1) call fnc_usec_damageVehicle};

//local_gutObject.sqf
"viruzHideBody"		addPublicVariableEventHandler {hideBody (_this select 1)};

//gather_meat.sqf local_gut
"viruzGutBody"		addPublicVariableEventHandler {(_this select 1) spawn local_gutObject};

//"viruzDelLocal"		addPublicVariableEventHandler {(_this select 1) call object_delLocal};

//"viruzVehicleInit"	addPublicVariableEventHandler {(_this select 1) call fnc_vehicleEventHandler};

//fn_damageHandler.sqf /player_death.sqf /bandage.sqf /morphine.sqf /painkiller.sqf /transfusion.sqf
"viruzHumanity"		addPublicVariableEventHandler {(_this select 1) spawn player_humanityChange};

//server side server_publishObject.sqf /server_VehiclesSpawner.sqf  NEED CHNAGE IN /vzserver_Helicrash.sqf /vzserver_spawnBuilds.sqf /vzserver_updateBuild.sqf /server_cleanup.fsm TO NEW PERMANENT VAR
"viruz_serverObjectMonitor"		addPublicVariableEventHandler {viruz_serverObjectMonitor = viruz_safety};

//Both

//Server only
if (isServer) then {
	//called on player die
	"viruzDeath"			addPublicVariableEventHandler {_id = (_this select 1) spawn server_playerDied}; 
	
	//called for save players	/player_eat /player_monitor.fsm /player_spawn_2.sqf
	"viruzPlayerSave"	addPublicVariableEventHandler {_id = (_this select 1) spawn server_playerSync;}; 
	
	//assemble_structure.sqf /assemble_vehicle.sqf /build.sqf /player_build.sqf /tent_pitch.sqf
	"viruzPublishObj"	addPublicVariableEventHandler {(_this select 1) call server_publishObj};
	
	//called for new group system (DEV)
	"viruzSaveGroup"	addPublicVariableEventHandler {(_this select 1) call server_saveGroup};
	
	//called for /door.sqf /vz_MaintainBuild.sqf /VIRUZ_publishObj
	"viruzUpdateBuild"	addPublicVariableEventHandler {(_this select 1) call server_UpdateBuild};

	//called for /forcesave.sqf /object_setFixServer.sqf /object_setHitServer.sqf /player_gearSync.sqf /vehicle_handleDamage.sqf /vehicle_handleKilled.sqf
	"viruzUpdateVehicle" addPublicVariableEventHandler {_id = (_this select 1) spawn server_updateObject}; 
	
	//called for /player_monitor.fsm when player join server
	"viruzLogin"			addPublicVariableEventHandler {_id = (_this select 1) spawn server_playerLogin};
	//called for /player_monitor.fsm to setup player
	"viruzLogin2"		addPublicVariableEventHandler {(_this select 1) call server_playerSetup};
	
	//called for /player_humanityMorph.sqf to set kill stats, but need make server side code to store
	"viruzPlayerMorph"	addPublicVariableEventHandler {(_this select 1) call server_playerMorph};
	
	//called for /player_switchModel.sqf /player_monitor.fsm
	"viruzLoginRecord"	addPublicVariableEventHandler {_id = (_this select 1) spawn viruz_recordLogin};
	
	//called for /assemble_vehicle.sqf /refuel.sqf
	"viruzSetFuel"		addPublicVariableEventHandler {(_this select 1) spawn local_setFuel};
	
	//called for /repair.sqf
	"viruzSetFix"		addPublicVariableEventHandler {(_this select 1) call object_setFixServer};
	
	//called for viruz_buil/fn_removeObject.sqf /disassemble_structure.sqf /disassemble_vehicle.sqf
	"viruzDeleteObj"		addPublicVariableEventHandler {(_this select 1) spawn server_deleteObj};
	
	//called for antihack.sqf
	"atp"				addPublicVariableEventHandler { _array = _this select 1; diag_log format["TELEPORT REVERT: %1 (%2) from %3 to %4 now at %5", _array select 0, _array select 1, _array select 2, _array select 3, _array select 4];};
	
	//"viruzCanConnect" addPublicVariableEventHandler { _id = owner (_this select 1 select 0);  viruzCanConnect = allowConnection; _id publicVariableClient "viruzCanConnect";};
};

//Client only
if (!isDedicated) then {
	//server_cleanup.fsm //server_monitor.sqf
	"viruzSetDate"		addPublicVariableEventHandler {setDate (_this select 1)};
	
	//player_fired.sqf
	"viruzRoadFlare"		addPublicVariableEventHandler {(_this select 1) spawn object_roadFlare};
	
	//drag.sqf
	"norrnRaDrag"   	addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\viruz_mod\medical\publicEH\animDrag.sqf"};
	
	//medical\publicEH\noAnim.sqf
	"norrnRnoAnim"  	addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\viruz_mod\medical\publicEH\noAnim.sqf"};
	
	//"changeCharacter"	addPublicVariableEventHandler {(_this select 1) call player_serverModelChange};

	//"viruzSwitch"		addPublicVariableEventHandler {(_this select 1) call server_switchPlayer};
	
	//"viruzFire"			addPublicVariableEventHandler {nul=(_this select 1) spawn BIS_Effects_Burn};
	
	//new connection system
	//"viruzCanConnect" addPublicVariableEventHandler {viruzCanConnect = _this select 1;};
};