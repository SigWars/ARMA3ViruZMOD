disableSerialization;

private ["_dialog","_pTarget","_index","_playerData","_check","_haveData","_targetUID","_targetName"];

_dialog = findDisplay 55510;
_playerListBox = _dialog displayCtrl 55511;
_index = lbCurSel _playerListBox;
_playerData = _playerListBox lbData _index;
_check = 0;
_haveData = false;

{
	if ((!isNull _x) && {isPlayer _x} && {str(_x) == _playerData}) exitWith {_pTarget = _x;_check = 1; _targetUID = getPlayerUID _x; _targetName = name _x};
} count allUnits;
	
if (_check == 1) then
{
		{
			if (getPlayerUID _pTarget == _x select 1) then {
				currentInvites set [_forEachIndex,"REMOVETHISCRAP"];
				currentInvites = currentInvites - ["REMOVETHISCRAP"];
				publicVariableServer "currentInvites";       
			};
		} forEach currentInvites;
		
		systemChat "You have canceled pending CLan invite";
}
else
{
	{
		if (getPlayerUID player == _x select 0) then {
			currentInvites set [_forEachIndex,"REMOVETHISCRAP"];
			currentInvites = currentInvites - ["REMOVETHISCRAP"];
			publicVariableServer "currentInvites";       
		};
	} forEach currentInvites;
	
	systemChat "You have canceled all pending clan invite, becouse the current player is no more online";
};




