private ["_pUnits","_playerIDC","_groupLeaderC","_clanName","_actualGroupName","_playerhaveClan","_canInvite"];
//_savedGroup = [];
while {true} do {

	_pUnits = units group player;
	_playerIDC = getPlayerUID player; 
	_groupLeaderC = player getVariable ["ClanLeader",_playerIDC];
	_clanName = player getVariable ["clanName",name player];
	_playerhaveClan = player getVariable ["haveClan",false];
	_canInvite = player getVariable ["canInivite",time];
	
	//foce player to join clan group if not in temp group
	if ((count _pUnits == 1) and _playerhaveClan and _canInvite < time )then{
	
		{
			if (_clanName == groupID _x) exitWith { [player] join _x;};
		}forEach allGroups;
	};

	//Set Clan owner leader of group if online
	if ((_groupLeaderC isEqualTo _playerIDC) and (_clanName isEqualTo groupID (group player))) then 
	{
	
		if !(player == leader group player) then 
		{ 
			group player selectLeader player;
			[group player, player] remoteExec ["selectLeader", groupOwner group player]; 
		};
	};
	
	//#include "mapMarkers.sqf"
	/*
	_ClanID = player getVariable ["ClanID",0];
	{
	   diag_log format ["GROUP %1", _x ];
	   if (_x select 0 == _ClanID) exitWith { _savedGroup = _x select 4;}; 
	}forEach ViruZGroupsArray;
	
	
	
	_updateGroup = false;
	_groupUIDs = [];
	{_puid = getPlayerUID _x;if (_puid != "") then {_groupUIDs set [count _groupUIDs,_puid];};} count units group player;
	//_savedGroup = profileNamespace getVariable["savedGroup",[]];
	//{if !(_x in _savedGroup) then {_savedGroup set [count _savedGroup,_x];_updateGroup = true;};} count _groupUIDs;
	
	if (_updateGroup) then {
		profileNamespace setVariable["savedGroup",_savedGroup];saveProfileNamespace;
		player setVariable ["savedGroup",_savedGroup,true];
	};
	
	_purgeGroup = player getVariable["purgeGroup",0];
	if (isNil "_purgeGroup") then {_purgeGroup = 0;};
	if (typeName _purgeGroup == "ARRAY") then {
		_savedGroup = _savedGroup - _purgeGroup;
		profileNamespace setVariable["savedGroup",_savedGroup];saveProfileNamespace;
		player setVariable ["savedGroup",_savedGroup,true];
		player setVariable ["purgeGroup",0,true];
	};*/
	uiSleep 5;
};