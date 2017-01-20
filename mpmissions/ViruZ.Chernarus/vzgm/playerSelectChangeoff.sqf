disableSerialization;

private ["_dialog","_groupListBox","_groupKick","_pTarget","_index","_playerData","_check","_unitCount","_ClanID","_clanLeader"];

_dialog = findDisplay 55510;
_groupListBox = _dialog displayCtrl 55512;
_groupKick = _dialog displayCtrl 55515;
_index = lbCurSel _groupListBox;
_playerData = _groupListBox lbData _index;
_check = 0;
_ClanID = player getVariable ["ClanID","0"];
_clanLeader = player getVariable ["ClanLeader","0"];

if (typeName _playerData == "OBJECT") then {
	{
		if ((!isNull _x) && {isPlayer _x} && {str(_x) == _playerData}) exitWith {_pTarget = _x;_check = 1;};
	} count allUnits;
};

if (_check == 1) then {
	_unitCount = count units group _pTarget;

	if (_unitCount == 1) then {
		if (getPlayerUID player == _clanLeader) then {
			_groupKick ctrlShow true;
		} else {
			_groupKick ctrlShow false;
			systemChat "You must be the group leader to invite people!";
		};	    
	} else {
		_groupKick ctrlShow false;	   
		systemChat "Sorry, the selected player is already in a group";
	};
}
else
{
	if (getPlayerUID player == _clanLeader) then 
	{
		_groupKick ctrlShow true;
	}
	else
	{
		_groupKick ctrlShow false;
		systemChat "You must be the group leader to invite people!";
	};
};