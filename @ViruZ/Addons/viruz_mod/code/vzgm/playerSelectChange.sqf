disableSerialization;

private ["_dialog","_playerListBox","_groupInvite","_clanInvite","_cancelPendInvite","_clanKick","_pTarget","_index","_playerData","_check","_unitCount","_ClanID","_clanLeader",
"_playerhaveClan","_pendInvite","_targetClanID","_targetHaveClan"];

_dialog = findDisplay 55510;
_playerListBox = _dialog displayCtrl 55511;
_groupInvite = _dialog displayCtrl 700002;
_groupInvite ctrlShow false;
_clanInvite = _dialog displayCtrl 55514;
_clanInvite ctrlShow false;
_cancelPendInvite = _dialog displayCtrl 700012;
_cancelPendInvite ctrlShow false;
_clanKick = _dialog displayCtrl 55515;
_clanKick ctrlShow false;
_index = lbCurSel _playerListBox;
_playerData = _playerListBox lbData _index;


_ClanID = player getVariable ["ClanID","0"];
_clanLeader = player getVariable ["ClanLeader","0"];
_playerhaveClan = player getVariable ["haveClan",false];
_pendInvite = false;


_check = 0;
{
	if ((!isNull _x) && {isPlayer _x} && {str(_x) == _playerData}) exitWith {_pTarget = _x; _check = 1;};
} count allUnits;

if (_check == 1) then {
	
	{if (_x select 1 == getPlayerUID _pTarget) then {_pendInvite = true};} forEach currentInvites;
	
	_targetClanID = _pTarget getVariable ["ClanID","0"];
	_targetHaveClan = _pTarget getVariable ["haveClan",false];
	
	_unitCount = count units group _pTarget;

	//If not in group
	if (_unitCount == 1) then 
	{
		//clan leader
		if (getPlayerUID player == _clanLeader) then 
		{
			//Not same player
			if (getPlayerUID player != getPlayerUID _pTarget)then
			{
				//Group Leader
				if (player == leader group player)then
				{
					_groupInvite ctrlShow true;
					if (_pendInvite)then{_cancelPendInvite ctrlShow true;};
				};
				//Target no have clan
				if (!_targetHaveClan and _playerhaveClan)then{_clanInvite ctrlShow true;}else{_clanInvite ctrlShow false;};
			}
			else
			{
				_groupInvite ctrlShow false; 
				_clanInvite ctrlShow false;
			};
		} 
		else 
		{	//Not clan leader but temp group leader
			if (player == leader group player) then 
			{
				_groupInvite ctrlShow true;
			}
			else //Not clan leander/groupleader
			{
				_groupInvite ctrlShow false;
				
			}; 
			_clanInvite ctrlShow false;
			_cancelPendInvite ctrlShow false;
		};
	} 
	else
	{
		_groupInvite ctrlShow false;
		_clanInvite ctrlShow false;		
		systemChat "Sorry, the selected player is already in a group";
	};
};