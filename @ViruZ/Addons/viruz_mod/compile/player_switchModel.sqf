private["_class","_position","_dir","_group","_oldUnit","_newUnit","_currentWpn","_muzzles","_currentAnim","_currentCamera"];
_class 			= _this;

_position 		= getPosATL player;
_dir 			= getDir player;
_currentAnim 	= animationState player;
//_currentCamera	= cameraView;


//Get PlayerID
private ["_playerUID"];
	_playerUID = "";
	if (count playableUnits == 0 and isServer) then {
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
	_oldGroup = group player; //VZgroup
/***********************************/
//DONT USE player AFTER THIS POINT
/***********************************/

//Create New Character
	//[player] joinSilent grpNull;
	_group 		= createGroup west;
	_newUnit 	= _group createUnit [_class,viruz_spawnPos,[],0,"NONE"];

	_newUnit 	setPosATL _position;
	_newUnit 	setDir _dir;

//Clear New Character
//	{_newUnit removeMagazine _x;} forEach  magazines _newUnit;
//	removeAllWeapons _newUnit;	

//Debug Message
	diag_log "Swichtable Unit Created.";

//Make New Unit Playable
	addSwitchableUnit _newUnit;
	setPlayable _newUnit;
	selectPlayer _newUnit;
	//VZgroup
	if ((count units _oldGroup > 1) && {!isNil "viruzLoginRecord"}) then {
		[_newUnit] join _oldGroup;
		if (count units _group <= 1) then {deleteGroup _group;};
	} else {
		[_newUnit] joinSilent grpNull;
	};
	
//Clear and delete old Unit
//	removeAllWeapons _oldUnit;
//	{_oldUnit removeMagazine _x;} forEach  magazines _oldUnit;
		
	deleteVehicle _oldUnit;

//Move player inside

//	player switchCamera = _currentCamera;
//	if(_currentWpn != "") then {_newUnit selectWeapon _currentWpn;};
//	[objNull, player, rSwitchMove,_currentAnim] call RE;
	[[player, _currentAnim],"MP_SwitchMove"] spawn BIS_fnc_MP;
	//viruz_originalPlayer attachTo [_newUnit];
	player disableConversation true;
	enableRadio false;
	enableSentences false;
	
	player setVariable ["bodyName",viruz_playerName,true];

	_playerUID=getPlayerUID player;
	_playerObjName = format["player%1",_playerUID];
	call compile format["%1 = player;",_playerObjName];
	publicVariable _playerObjName;
	
	//VZgroup pega o grupo novamente ao relogar
	_savedGroup = profileNamespace getVariable["savedGroup",[]];
	player setVariable ["savedGroup",_savedGroup,true];
	player setVariable ["purgeGroup",0,true];
	