disableSerialization;

private ["_dialog","_pTarget","_index","_playerData","_check","_oldClanGroup","_clanname","_needClan"];

_dialog = findDisplay 55510;
_groupListBox = _dialog displayCtrl 55512;
_index = lbCurSel _groupListBox;
_playerData = _groupListBox lbData _index;
_check = 0;
{
	if ((!isNull _x) && {isPlayer _x} && {str(_x) == _playerData}) exitWith {_pTarget = _x;_check = 1;};
} count allUnits;

if (_pTarget == player) exitWith {systemChat "You can not kick yourself";};
if (_check == 0) exitWith {systemChat "You must select someone to kick first";};

if (_check == 1)then{

	_oldClanGroup = _pTarget getVariable ["ClanID","0"];
	_needClan = (_oldClanGroup isEqualTo (name _pTarget));
	
	if !(_needClan)then
	{
		_clanname = _pTarget getVariable ["clanName",name player];
		
		{
			if (_clanname == groupID _x) exitWith { [_pTarget] join _x;};
		}forEach allGroups;

		systemChat format["You have kicked %1 from the GROUP",name _pTarget];
	}
	else
	{
		[_pTarget] join grpNull;
		systemChat format["You have kicked %1 from the GROUP",name _pTarget];
	};
};

