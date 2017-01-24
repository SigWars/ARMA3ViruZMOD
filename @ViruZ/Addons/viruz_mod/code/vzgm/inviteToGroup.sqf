if (player != leader group player) exitWith {systemChat "You are not the Clan leader and can not invite people.";};

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
_pendInvite = false;

{
	if (getPlayerUID player == _x select 0) exitWith {
    	_pendInvite = true;
	};
} forEach currentInvites;

if (_pendInvite)exitWith {systemChat "You have a clan invitation that is still pending acceptance, You can cancel by clicking the pending player on online list";};
//Checks
{
	if ((!isNull _x) && {isPlayer _x} && {str(_x) == _playerData}) exitWith {_pTarget = _x;_check = 1;};
} forEach allUnits;

if (_check == 0) exitWith {systemChat "You must select someone to invite first.";};
if (_pTarget == player) exitWith {systemChat "You can not invite yourself.";};
if (count units group _pTarget > 1) exitWith {systemChat "This player is already in a group.";};

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

if (_haveGroup) exitWith {systemChat "This player is already in a CLAN.";};

currentInvites set [count currentInvites,[getPlayerUID player,getPlayerUID _pTarget,"CLAN"]];
publicVariableServer "currentInvites";

[nil,_pTarget,"loc", rTITLETEXT, format["You have received a CLAN INVITE. press 'U' to accept."], "PLAIN", 0] call RE;

systemChat format["You have invited %1 to join the CLAN",name _pTarget];
systemChat "Press left windows key to toggle group name tags";
