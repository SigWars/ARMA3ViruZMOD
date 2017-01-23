params ["_toRemove","_toAdd","_type","_newData"];
private["_broadCast"];

diag_log format ["FUNCTION #TOADD= %1 #TOREMOVE= %2 #GROUPID= %3",_toAdd,_toRemove,_newData];

_broadCast = false;
 
if !(_toRemove isEqualto "NOTHING")then{ ViruZGroupsArray = ViruZGroupsArray - [_toRemove]; _broadCast = true;};
if !(_toAdd isEqualto "NOTHING")then{ ViruZGroupsArray pushback _toAdd;  _broadCast = true;};
if (_broadCast) then { publicVariable "ViruZGroupsArray";};

switch (_type) do 
{
	case "CREATE": { [_toAdd select 0,_toAdd select 1,_toAdd select 2,_toAdd select 3,_toAdd select 4] spawn vzserver_addGroup; };
	
	case "UPDATE": { [_newData select 0,_newData select 1] spawn vzserver_updateGroup; };
	
	case "FULL"	:	{
						if (_newData isEqualto "NOTHING") then {[_toAdd select 0,_toAdd select 1,_toAdd select 2,_toAdd select 3,_toAdd select 4] spawn vzserver_updateGroupFull;}
						else {[_toAdd select 0,_toAdd select 1,_toAdd select 2,_toAdd select 3,_toAdd select 4,_newData] spawn vzserver_updateGroupFull;};
					};
	case "DELETE": { _newData spawn vzserver_deleteGroup;};
	
	default { };
};



