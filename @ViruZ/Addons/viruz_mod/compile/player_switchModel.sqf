private["_class","_position","_dir","_group","_oldUnit","_newUnit","_currentWpn","_muzzles","_currentAnim","_currentCamera"];
_class 			= _this;

_position 		= getPosATL player;
_dir 			= getDir player;
_currentAnim 	= animationState player;
//_currentCamera	= cameraView;


//Get PlayerID
private ["_playerUID"];
	_playerUID = "";
	if (count allUnits == 0 and isServer) then {
		//In Single Player
		isSinglePlayer = true;
		player sidechat "Single player Mode detected!";
		//_id = [42,"SinglePlayer"] spawn server_onPlayerConnect;
		_playerUID = "42";
	} else {
		_playerUID = getPlayerUID player;
	};


//Debug Message
	diag_log "Attempting to switch model";

//Secure Player for Transformation
	player setPosATL viruz_spawnPos;

//BackUp Player Object
	_oldUnit = player;
/***********************************/
//DONT USE player AFTER THIS POINT
/***********************************/

//Create New Character
	_group 		= createGroup west;
	_newUnit 	= _group createUnit [_class,viruz_spawnPos,[],0,"NONE"];

	_newUnit 	setPosATL _position;
	_newUnit 	setDir _dir;

//Debug Message
	diag_log "Swichtable Unit Created.";

//Make New Unit Playable
	addSwitchableUnit _newUnit;
	//setPlayable _newUnit;
	selectPlayer _newUnit;

	
//Clear and delete old Unit
	deleteVehicle _oldUnit;

//Move player inside
[[player, _currentAnim],"MP_SwitchMove"] spawn BIS_fnc_MP;
player disableConversation true;
enableRadio false;
enableSentences false;

player setVariable ["bodyName",viruz_playerName,true];

_playerUID=getPlayerUID player;
_playerObjName = format["player%1",_playerUID];
call compile format["%1 = player;",_playerObjName];
publicVariable _playerObjName;

	