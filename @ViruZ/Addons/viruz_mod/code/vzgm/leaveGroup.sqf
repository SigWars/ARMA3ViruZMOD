private ["_playerUID","_clanLeader","_changeLeader","_newleaderArray","_gmembers","_groupID","_groupName","_groupOwner","_groupRank","_ok","_targerPerm","_oldGroup","_toremove",
"_toaddData","_removeData","_targetName","_newLeader","_allgroupUID","_find"];

_playerUID = getPlayerUID player;
_clanLeader = player getVariable ["ClanLeader","0"];
_changeLeader = false;
_newleaderArray = [];
_ok = false;


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
	
	//Remove from global array
	_removeData = +_toremove;
	
	//Remove member from group array
	_oldGroup = _oldGroup - [[_playerUID,_targerPerm,_targetName]];
	
	if (_changeLeader)then{
		_gUnits = count units group player;
		//Get Random online player to set new leader!
		{
			_memberOfgroup = false;
			_memberOfgroup = (_x getVariable ["ClanID","0"] == _groupID);
			if (!((getPlayerUID _x) isEqualto _playerUID) and _memberOfgroup)then{_newleaderArray pushback getPlayerUID _x;};
			if (!_memberOfgroup and _gUnits == 2) then {[_x] joinSilent grpNull; };
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
		
		if (count _newleaderArray > 0) then {
			//Sets permission of new leader
			{
				if (_x select 0 isEqualto _newLeader) then
				{
					_find = _oldGroup find _x;
					(_oldGroup select _find) set [1, 3];
				}; 
			} forEach _oldGroup;
			
			//Sets new clan leader in all online groupmembers
			{
				_memberOfgroup = false;
				_memberOfgroup = (_x getVariable ["ClanID","0"] == _groupID);
				if(_memberOfgroup)then
				{
					_x setVariable ["ClanID",_newLeader,true];
					_x setVariable ["ClanLeader",_newLeader,true];
					_x setVariable ["haveClan",true,true];
					if((getPlayerUID _x) isEqualto _newLeader)then{_x setVariable ["LvL",3,true];};
				};
			} forEach units group player;
			
			_toaddData = [_newLeader,_groupName,_newLeader,_groupRank,_oldGroup];
			
			//update full clan in database with new leader
			viruzupdateGroup = [_removeData,_toaddData,"FULL",_groupID];
			publicVariableServer "viruzupdateGroup";

		}
		else
		{
			
			//Delete group if no more memebers online/offline
			viruzupdateGroup = [_removeData,"NOTHING","DELETE",_groupID];
			diag_log ["REMOVEDATA deletegroup=%1",_removeData];
			publicVariableServer "viruzupdateGroup";
		};
		
		[player] join grpNull;
		player setVariable ["ClanID",name player,true];
		player setVariable ["ClanLeader",_playerUID,true];
		player setVariable ["LvL",3,true];
		player setVariable ["clanName",name player,true];
		player setVariable ["haveClan",false,true];
		player setVariable ["groupRank",0,true];
		
		systemChat "You have left the Clan";
	}
	else
	{
		
		
		//only update group memebers
		_toaddData = [_groupID,_groupName,_groupOwner,_groupRank,_oldGroup];
		
		//update database
		viruzupdateGroup = [_removeData,_toaddData,"UPDATE",[_groupID,_oldGroup]];
		publicVariableServer "viruzupdateGroup";
			
		[player] join grpNull;
		player setVariable ["ClanID",name player,true];
		player setVariable ["ClanLeader",_playerUID,true];
		player setVariable ["LvL",3,true];
		player setVariable ["clanName",name player,true];
		player setVariable ["haveClan",false,true];
		player setVariable ["groupRank",0,true];
		
		systemChat "You left the clan and it was deleted because there are no more members";
	};
	
}
else
{
	systemChat "You are not a member of a clan.";
};
