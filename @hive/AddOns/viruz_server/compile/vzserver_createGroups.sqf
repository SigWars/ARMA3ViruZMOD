private ["_query","_result","_groupsArray","_data"];

ViruZGroupsArray = [];
currentInvites = [];
_groupsArray = [];
_featchArray = [];

_query = "SELECT * FROM viruz_group";
_groupsArray = [_query,2] call viruz_asyncCall;

if (ViruzDebugMode > 2 or ViruzDebugType == "GROUP") then {diag_log format["GROUPARRAY = %1",_groupsArray];};

{
	_clanMemebers = _x select 4;
	if !(_clanMemebers isEqualto []) then {
		
		ViruZGroupsArray pushback _x;
	}
	
} forEach _groupsArray;

if (ViruzDebugMode > 2 or ViruzDebugType == "GROUP") then {diag_log format["ViruZGroupsArray = %1",ViruZGroupsArray];};
	
publicVariable "ViruZGroupsArray";
publicVariable "currentInvites";
"currentInvites" addPublicVariableEventHandler {publicVariable "currentInvites";};
