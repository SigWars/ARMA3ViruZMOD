disableSerialization;

private ["_dialog","_pTarget","_index","_playerData","_check","_haveData","_targetUID","_groupID","_groupName","_groupOwner","_groupRank","_toremove","_oldGroup","_ok","_targerPerm",
"_targetName"];

_dialog = findDisplay 55510;
_groupListBox = _dialog displayCtrl 55512;
_index = lbCurSel _groupListBox;
_playerData = _groupListBox lbData _index;
_check = 0;
_haveData = false;

{
	if ((!isNull _x) && {isPlayer _x} && {str(_x) == _playerData}) exitWith {_pTarget = _x;_check = 1; _targetUID = getPlayerUID _x; _haveData = true;};
} count allUnits;
	
if (_check == 1) then
{
	if (_pTarget == player) exitWith {systemChat "You can not kick yourself";};
};

if !(_haveData) then
{
	_targetUID = _playerData;
	if (_playerData != "")then{ _check = 1;};
	if (_playerData == getPlayerUID player) exitWith {systemChat "You can not kick yourself";};
};

if (_check == 0) exitWith {systemChat "You must select someone to kick first";};

_ok = false;
	{  
		_gmembers = _x select 4; 
		{   
			if (_targetUID isEqualto (_x select 0)) exitWith 
			{	
				_targerPerm = _x select 1;
				_targetName = _x select 2;
				_ok = true; 
			};  
		} forEach _gmembers; 
	  
		if (_ok) exitWith 
		{ 
			_groupID = _x select 0;  
			_groupName = _x select 1;  
			_groupOwner = _x select 2;  
			_groupRank = _x select 3;  
			_oldGroup = _x select 4; 
			_toremove = _x;
		}; 
	}forEach ViruZGroupsArray;
	
	if (_ok) then {
		//Remove from global array
		ViruZGroupsArray = ViruZGroupsArray - [_toremove];
		diag_log format["OLGROUP ANTES = %1",_oldGroup];
		//add group in array with new member
		_oldGroup = _oldGroup - [[_targetUID,_targerPerm,_targetName]];
		diag_log format["OLGROUP DEPOIS = %1",_oldGroup];
		ViruZGroupsArray pushback [_groupID,_groupName,_groupOwner,_groupRank,_oldGroup];
		publicVariableServer "ViruZGroupsArray";
		//update database
		viruzupdateGroup = [_groupID,_oldGroup];
		publicVariable "viruzupdateGroup";
	};

if (_haveData) then 
{
	[_pTarget] join grpNull;
	_pTarget setVariable ["ClanID",name _pTarget,true];
	_pTarget setVariable ["ClanLeader",_targetUID,true];
	systemChat format["You have kicked %1 from the group",name _pTarget];
}
else
{
	systemChat format["You have kicked offline %1 from the group",_targetName];
};
//{_x setVariable ["purgeGroup",[(getPlayerUID _pTarget)],true];} count units group player;

