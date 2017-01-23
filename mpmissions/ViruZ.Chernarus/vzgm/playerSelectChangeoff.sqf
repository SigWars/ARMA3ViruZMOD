disableSerialization;

private ["_dialog","_groupListBox","_clanKick","_groupKickButton","_clanInvite","_groupInviteButton","_clanPermissionBox","_clanPermApply","_pTarget","_index","_playerData","_check",
"_ClanID","_clanLeader","_targetClanID","_targetPermission"];

_dialog = findDisplay 55510;
_groupListBox = _dialog displayCtrl 55512;
_clanKick = _dialog displayCtrl 55515;
_groupKickButton = _dialog displayCtrl 700003;
_clanInvite = _dialog displayCtrl 55514;
_clanInvite ctrlShow false;
_groupInviteButton = _dialog displayCtrl 700002;
_groupInviteButton ctrlShow false;
_clanPermissionBox = _dialog displayCtrl 700010;
_clanPermissionBox ctrlShow false;
_clanPermApply = _dialog displayCtrl 700011;
_clanPermApply ctrlShow false;

_index = lbCurSel _groupListBox;
_playerData = _groupListBox lbData _index;
_check = 0;
_ClanID = player getVariable ["ClanID","0"];
_clanLeader = player getVariable ["ClanLeader","0"];

{
	if ((!isNull _x) && {isPlayer _x} && {str(_x) == _playerData}) exitWith {_pTarget = _x;_check = 1;};
} count allUnits;

if (_check == 1) then
{	
	_targetClanID = _pTarget getVariable ["ClanID","0"];
	_targetPermission = _pTarget getVariable ["LvL",0];
	_clanPermissionBox lbSetCurSel _targetPermission;
	
	//Clan Leader
	if (getPlayerUID player == _clanLeader) then 
	{
		
		//Clan Leader and target have same clan
		if ((getPlayerUID player != getPlayerUID _pTarget) and (_targetClanID isEqualto _ClanID))then
		{
			_clanKick ctrlShow true;
			_clanPermissionBox ctrlShow true;
			_clanPermApply ctrlShow true;
		}
		else
		{
			_clankick ctrlShow false;
			_clanPermissionBox ctrlShow false;
			_clanPermApply ctrlShow false;
		};
		if (!(_targetClanID isEqualto _ClanID) and (player == leader group player))then{_groupKickButton ctrlShow true;}else{_groupKickButton ctrlShow false;};
	}
	else
	{
			_clanKick ctrlShow false;
			_groupKickButton ctrlShow false;
			_clanPermissionBox ctrlShow false;
			_clanPermApply ctrlShow false;
	};	    
}	
else
{
	if (getPlayerUID player == _clanLeader) then 
	{
		_clanKick ctrlShow true;
		_groupKickButton ctrlShow false;
	}
	else
	{
		_clanKick ctrlShow false;
		_groupKickButton ctrlShow false;
	};
};