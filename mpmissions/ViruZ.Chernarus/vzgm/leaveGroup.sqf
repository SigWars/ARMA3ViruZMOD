private ["_playerUID","_clanLeader","_changeLeader","_newleaderArray","_gmembers","_groupID","_groupName","_groupOwner","_groupRank","_toremove","_oldGroup","_ok","_targerPerm",
"_targetName","_newLeader","_allgroupUID","_find"];

_playerUID = getPlayerUID player;
_clanLeader = player getVariable ["ClanLeader","0"];
_changeLeader = false;
_newleaderArray = [];

if (_playerUID == _clanLeader)then{_changeLeader = true;};

//Check group array
{  
	_gmembers = _x select 4; 
	{   
		if (_playerUID isEqualto (_x select 0)) exitWith 
		{	
			_targerPerm = _x select 1;
			_targetName = _x select 2;
			_ok = true; 
		};  
	} forEach _gmembers; 
  
	if (_ok) exitWith 
	{ 
		_groupID = _x select 0;  
		_groupName = _x select 1;  
		_groupOwner = _x select 2;  
		_groupRank = _x select 3;  
		_oldGroup = _x select 4; 
		_toremove = _x;
	}; 
}forEach ViruZGroupsArray;

if (_ok) then {
	
	//Remove member from group array
	_oldGroup = _oldGroup - [[_playerUID,_targerPerm,_targetName]];
	
	//Get Random online player to set new leader!
	{
		if !((getPlayerUID _x) isEqualto _playerUID)then{_newleaderArray pushback getPlayerUID _x;};
	} forEach units group player;
	
	
	_newLeader = selectRandom _newleaderArray;

	
	//check if var return a value else set random from database members
	if (count _newleaderArray < 1) then {
		_newleaderArray = [];
		{
			_allgroupUID = _x select 0;
			_newleaderArray pushback _allgroupUID;
		} forEach _oldGroup;
		
		_newLeader = selectRandom _newleaderArray;
		
	};
	
	//Sets permission of new leader
	{
		if (_x select 0 isEqualto _newLeader) then
		{
			_find = _oldGroup find _x;
			(_oldGroup select _find) set [1, 3];
		}; 
	} forEach _oldGroup;
	
	//Remove from global array
	ViruZGroupsArray = ViruZGroupsArray - [_toremove];
	
	if (_changeLeader)then
	{
		//Add group to array again
		ViruZGroupsArray pushback [_newLeader,_groupName,_newLeader,_groupRank,_oldGroup];
		publicVariableServer "ViruZGroupsArray";
		
		//update database
		viruzupdateGroupFull = [_groupID,_groupName,_newLeader,_groupRank,_oldGroup,_newLeader];
		publicVariable "viruzupdateGroupFull";
	}
	else
	{
		//Add group to array again
		ViruZGroupsArray pushback [_groupID,_groupName,_groupOwner,_groupRank,_oldGroup];
		publicVariableServer "ViruZGroupsArray";
		
		//update database
		viruzupdateGroup = [_groupID,_oldGroup];
		publicVariable "viruzupdateGroup";
	
	};
	
	[player] join grpNull;
	player setVariable ["ClanID",name player,true];
	player setVariable ["ClanLeader",_playerUID,true];
	
	systemChat "You have left the Clan";
}
else
{
	systemChat "You are not a member of a clan.";
};
