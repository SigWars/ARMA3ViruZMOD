private ["_firstinvite","_groupExists","_playerUID","_pName","_groupID","_groupName","_groupOwner","_groupRank","_inviterUID","_inviter","_newGroup","_gmembers","_ok","_toremove","_ClanID"];

_firstinvite = false;
_groupExists = false;
_playerUID = getPlayerUID player;
_pName = name player;
_groupID = _playerUID;  
_groupName = _playerUID;  
_groupOwner = _playerUID;  
_groupRank = 0;
_toremove = []; 
_ok = false;

//pega uid de quem invitou e remove da currentinvites
{
	if (_playerUID == _x select 1) then {
    	_inviterUID = _x select 0;
        currentInvites set [_forEachIndex,"REMOVETHISCRAP"];
        currentInvites = currentInvites - ["REMOVETHISCRAP"];
        publicVariableServer "currentInvites";
	};
} forEach currentInvites;

//confere se grupo ainda existe e seleciona o player objeto
{
	if ((!isNull _x) && {getPlayerUID _x == _inviterUID}) exitWith {
		_inviter = _x;
		_ClanID = _x getVariable ["ClanID","0"];
		_groupExists = true;
	};
} forEach allUnits;

//check if group exist in global group array or if is firts invite to create a group
_newGroup = [];
if (_groupExists) then 
{
	{  
		_gmembers = _x select 4; 
		{   
			if (_inviterUID == _x select 0) exitWith 
			{	
				_ok = true; 
			};  
		} forEach _gmembers; 
	  
		if (_ok) exitWith 
		{ 
			_groupID = _x select 0;  
			_groupName = _x select 1;  
			_groupOwner = _x select 2;  
			_groupRank = _x select 3;  
			_newGroup = _x select 4; 
			hint str _newGroup; 
			_toremove = _x;
			diag_log format ["REMOVER %1", _loarray ];
		}; 
	}forEach ViruZGroupsArray;
};

if (_ok) then {
	//Remove from global array
	ViruZGroupsArray = ViruZGroupsArray - [_toremove];
	
	//add group in array with new member
	_newGroup pushback [_playerUID,0,_pName];
	ViruZGroupsArray pushback [_groupID,_groupName,_groupOwner,_groupRank,_newGroup];
	publicVariableServer "ViruZGroupsArray";
	//update database
	viruzupdateGroup = [_groupID,_newGroup];
	publicVariable "viruzupdateGroup";
}
else
{
	_groupExists = false;
};

//adiciona player no grupo
if (_groupExists) then {
	[player] join (group _inviter);
	systemChat "You have accepted the invite. Press left windows key to toggle group name tags";
	player setVariable ["ClanID",_ClanID,true];
	player setVariable ["ClanLeader",getPlayerUID _inviter,true];
} else {
	systemChat "The group no longer exists";    
};