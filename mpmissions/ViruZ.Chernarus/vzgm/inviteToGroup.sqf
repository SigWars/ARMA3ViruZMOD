if (player != leader group player) exitWith {systemChat "You are not the leader and can not invite people.";};

disableSerialization;
#define CONTROL(disp,ctrl) ((findDisplay ##disp) displayCtrl ##ctrl)
private ["_dialog","_playerListBox","_pTarget","_index","_playerData","_groupName","_check","_hasInvite","_haveGroup","_gmembers","_ok"];

_dialog = findDisplay 55510;
_playerListBox = _dialog displayCtrl 55511;
_index = lbCurSel _playerListBox;
_playerData = _playerListBox lbData _index;
_hasInvite = false;
_check = 0;
_haveGroup = false;
_ClanID = player getVariable ["ClanID","0"];
_ok = true;
//Checks
{
	if ((!isNull _x) && {isPlayer _x} && {str(_x) == _playerData}) exitWith {_pTarget = _x;_check = 1;};
} forEach allUnits;

if (_check == 0) exitWith {systemChat "You must select someone to invite first.";};
if (_pTarget == player) exitWith {systemChat "You can not invite yourself.";};
//if (count units group _pTarget > 1) exitWith {systemChat "This player is already in a group.";};

{if (_x select 1 == getPlayerUID _pTarget) then {_hasInvite = true;};} forEach currentInvites;
if (_hasInvite) exitWith {systemChat "This player already has a pending invite.";};

{  
	_gmembers = _x select 4; 
	{   
		if (getPlayerUID _pTarget isEqualTo (_x select 0)) exitWith 
		{	
			_haveGroup = true; 
		};  
	} forEach _gmembers; 
  
	if (_haveGroup) exitWith 
	{ 
		_haveGroup = true;
	}; 
}forEach ViruZGroupsArray;

if (_haveGroup) exitWith {systemChat "This player is already in a group.";};

//Create a new group if first time invite
if (_ClanID isEqualTo (name player)) then
{
	_clanName = ctrlText (CONTROL(55510,700001));
	_length = count (toArray(_clanName));
	_chrByte = toArray (_clanName);
	_allowed = toArray("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_ ");
	if(_length > 32) exitWith {systemChat "The name size can not be greater than 32 characters."; _ok = false;};
	_badChar = false;
	{if(!(_x in _allowed)) exitWith {_badChar = true;};} forEach _chrByte;
	if(_badChar) exitWith {systemChat "Incompatible characters, only allowed to use: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_ "; _ok = false;};
	_newgroup = [[getPlayerUID player,3,name player]];
	player setVariable ["ClanID",getPlayerUID player,true];
	player setVariable ["ClanLeader",getPlayerUID player,true];
	
	group player setGroupIdGlobal [_clanName];
	ViruZGroupsArray pushback [getPlayerUID player,_clanName,getPlayerUID player,0,_newGroup];
	publicVariableServer "ViruZGroupsArray";
	//update database
	viruzAddGroup = [getPlayerUID player,_clanName,getPlayerUID player,0,_newGroup];
	publicVariable "viruzAddGroup";
};

if (_ok) then
{
	currentInvites set [count currentInvites,[getPlayerUID player,getPlayerUID _pTarget]];
	publicVariableServer "currentInvites";

	[nil,_pTarget,"loc", rTITLETEXT, format["You have received a group invite. press 'U' to accept."], "PLAIN", 0] call RE;

	systemChat format["You have invited %1 to join the group",name _pTarget];
	systemChat "Press left windows key to toggle group name tags";
};