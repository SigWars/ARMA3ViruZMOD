private ["_query","_result","_group","_groupName"];

ViruZGroupsArray = [];
_query = "extDB3" callExtension "0:SQL:SELECT * FROM viruz_group";
diag_log "SERVER: Group Request sent";
_result = call compile _query;
ViruZGroupsArray = _result select 1;
	
{
	_groupName = _x select 1;
	_group = createGroup west;
	_group setGroupIdGlobal [_groupName];
	 diag_log format ["SERVER CREATED THE GROUP %1",_groupName];
} forEach ViruZGroupsArray;
	
publicVariable "ViruZGroupsArray";
"ViruZGroupsArray" addPublicVariableEventHandler {publicVariable "ViruZGroupsArray";};


currentInvites = [];
publicVariable "currentInvites";
"currentInvites" addPublicVariableEventHandler {publicVariable "currentInvites";};


/*
//Check group on login
_plrID = "76561198113211908";
_havegrp = false;
_groupName = "";
_groupLeader = "";
{
   diag_log format ["GROUP %1", _x ];
   _groupMembers = _x select 4;
   {
     if (_x select 0 == _plrID) then { _havegrp = true;}; 
   }forEach _groupMembers;
   if (_havegrp) exitWith { _groupName = _x select 1; _groupLeader = _x select 2;};

}forEach ViruZGoupsArray;

diag_log format ["HAVEGROUP=%1 NAME=%2 LEADER=%3", _havegrp , _groupName , _groupLeader ];
*/