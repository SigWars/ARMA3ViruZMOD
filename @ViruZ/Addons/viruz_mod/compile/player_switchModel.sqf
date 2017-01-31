/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_class","_position","_dir","_group","_oldUnit","_newUnit","_currentWpn","_muzzles","_currentAnim","_playerID","_currentCamera","_playerName","_havegrp","_clanID","_groupName",
"_groupLeader","_permission","_groupMembers","_groupExist","_groupRank","_clanMembers","_newGroup","_isOk","_memberUID"];

_class 			= _this;

_position 		= getPosATL player;
_dir 			= getDir player;
_currentAnim 	= animationState player;
_playerID	 	= getPlayerUID player;
_playerName 	= name player;
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

/*
NEW VIRUZ GROUP SYSTEM 
*/
_havegrp = false;
_clanID = -1;
_groupName = "";
_groupLeader = "";
_permission = "";
_groupExist = false;
_groupRank = 0;
_clanMembers = [];
_isOk = false;
_memberUID = "";

{
	//diag_log format ["GROUP %1", _x ];
	_groupMembers = _x select 4;
	{
		if (_x select 0 == _playerID) then { _havegrp = true; _permission = _x select 1;}; 
	}forEach _groupMembers;
	if (_havegrp) exitWith { _groupName = _x select 1; _groupLeader = _x select 2; _clanID = _x select 0; _groupRank = _x select 3; _clanMembers = _x select 4;};

}forEach ViruZGroupsArray;

if (_havegrp) then
{
	//join player in group
	{
		_memberUID = _x select 0;
		{
			if ((_memberUID isEqualto (getPlayerUID _x)) and (_groupName isEqualto groupID (group _x))) exitWith { _isOk = true; [_newUnit] join (group _x); }; 
		
		}forEach allUnits;
		if (_isOk)exitWith{_groupExist = true;};
	}forEach _clanMembers;
	
	//Recreate arma fuck group if not alive in server
	if (!_groupExist)then{
		_group setGroupIdGlobal [_groupName];
	};
	
	
	_newUnit setVariable ["ClanID",_clanID,true];
	_newUnit setVariable ["ClanLeader",_groupLeader,true];
	_newUnit setVariable ["LvL",_permission,true];
	_newUnit setVariable ["clanName",_groupName,true];
	_newUnit setVariable ["haveClan",true,true];
	_newUnit setVariable ["groupRank",_groupRank,true];

}
else
{ 
	[_newUnit] joinSilent grpNull; 
	_newUnit setVariable ["ClanID",_playerName,true];// if ClanID == playername, it will enable clan creation
	_newUnit setVariable ["ClanLeader",_playerID,true];
	_newUnit setVariable ["LvL",3,true];
	_newUnit setVariable ["clanName",_playerName,true];
	_newUnit setVariable ["haveClan",false,true];
	_newUnit setVariable ["groupRank",_groupRank,true];
};
/*
END OF GROUP SYSTEM
*/
		
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

	