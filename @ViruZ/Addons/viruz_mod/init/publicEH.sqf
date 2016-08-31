//Medical Event Handlers
"norrnRaLW"   		addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\viruz_mod\medical\publicEH\load_wounded.sqf"};
"norrnRLact"		addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\viruz_mod\medical\load\load_wounded.sqf"};
"norrnRDead"   		addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\viruz_mod\medical\publicEH\deadState.sqf"};
"usecBleed"			addPublicVariableEventHandler {_id = (_this select 1) spawn fnc_usec_damageBleed};
"usecBandage"		addPublicVariableEventHandler {(_this select 1) call player_medBandage};
"usecInject"		addPublicVariableEventHandler {(_this select 1) call player_medInject};
"usecEpi"			addPublicVariableEventHandler {(_this select 1) call player_medEpi};
"usecTransfuse"		addPublicVariableEventHandler {(_this select 1) call player_medTransfuse};
"usecMorphine"		addPublicVariableEventHandler {(_this select 1) call player_medMorphine};
"usecPainK"			addPublicVariableEventHandler {(_this select 1) call player_medPainkiller};
"viruzHit" 			addPublicVariableEventHandler {(_this select 1) call fnc_usec_damageHandler};
"viruzHitV" 			addPublicVariableEventHandler {(_this select 1) call fnc_usec_damageVehicle};
"viruzHideBody"		addPublicVariableEventHandler {hideBody (_this select 1)};
"viruzGutBody"		addPublicVariableEventHandler {(_this select 1) spawn local_gutObject};
"viruzDelLocal"		addPublicVariableEventHandler {(_this select 1) call object_delLocal};
"viruzVehicleInit"	addPublicVariableEventHandler {(_this select 1) call fnc_vehicleEventHandler};
"viruzHumanity"		addPublicVariableEventHandler {(_this select 1) spawn player_humanityChange};
"viruz_serverObjectMonitor"		addPublicVariableEventHandler {viruz_serverObjectMonitor = viruz_safety};

//Both

//Server only
if (isServer) then {
	"viruzDeath"			addPublicVariableEventHandler {_id = (_this select 1) spawn server_playerDied};
	"viruzDiscoAdd"		addPublicVariableEventHandler {viruz_disco set [count viruz_disco,(_this select 1)];};
	"viruzDiscoRem"		addPublicVariableEventHandler {viruz_disco = viruz_disco - [(_this select 1)];};
	"viruzPlayerSave"	addPublicVariableEventHandler {_id = (_this select 1) spawn server_playerSync;};
	"viruzPublishObj"	addPublicVariableEventHandler {(_this select 1) call server_publishObj};
	"viruzSaveGroup"	addPublicVariableEventHandler {(_this select 1) call server_saveGroup};
	"viruzUpdateBuild"	addPublicVariableEventHandler {(_this select 1) call server_UpdateBuild};
	"viruzUpdateVehicle" addPublicVariableEventHandler {_id = (_this select 1) spawn server_updateObject};
	"viruzLogin"			addPublicVariableEventHandler {_id = (_this select 1) spawn server_playerLogin};
	"viruzLogin2"		addPublicVariableEventHandler {(_this select 1) call server_playerSetup};
	"viruzPlayerMorph"	addPublicVariableEventHandler {(_this select 1) call server_playerMorph};
	"viruzUpdate"		addPublicVariableEventHandler {_id = (_this select 1) spawn viruz_processUpdate};
	"viruzLoginRecord"	addPublicVariableEventHandler {_id = (_this select 1) spawn viruz_recordLogin};
	"viruzCharSave"		addPublicVariableEventHandler {_id = (_this select 1) spawn server_playerSync};
	//Checking
	"viruzSetFuel"		addPublicVariableEventHandler {(_this select 1) spawn local_setFuel};
	"viruzSetFix"		addPublicVariableEventHandler {(_this select 1) call object_setFixServer};
	"viruzDeleteObj"		addPublicVariableEventHandler {(_this select 1) spawn server_deleteObj};
	"atp"				addPublicVariableEventHandler { _array = _this select 1; diag_log format["TELEPORT REVERT: %1 (%2) from %3 to %4 now at %5", _array select 0, _array select 1, _array select 2, _array select 3, _array select 4];};
};

//Client only
if (!isDedicated) then {
	"viruzSetDate"		addPublicVariableEventHandler {setDate (_this select 1)};
	//"viruzFlies"			addPublicVariableEventHandler {(_this select 1) call spawn_flies};
	"viruzRoadFlare"		addPublicVariableEventHandler {(_this select 1) spawn object_roadFlare};
	"norrnRaDrag"   	addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\viruz_mod\medical\publicEH\animDrag.sqf"};
	"norrnRnoAnim"  	addPublicVariableEventHandler {[_this select 1] execVM "\z\addons\viruz_mod\medical\publicEH\noAnim.sqf"};
	"changeCharacter"	addPublicVariableEventHandler {(_this select 1) call player_serverModelChange};
	"viruzSwitch"		addPublicVariableEventHandler {(_this select 1) call server_switchPlayer};
	"viruzFire"			addPublicVariableEventHandler {nul=(_this select 1) spawn BIS_Effects_Burn};
};