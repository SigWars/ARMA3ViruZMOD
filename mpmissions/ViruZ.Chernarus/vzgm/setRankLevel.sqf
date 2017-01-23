disableSerialization;

private ["_dialog","_pTarget","_index","_playerData","_clanPermissionBox","_comboindex","_pemLevel","_check","_haveData","_targetUID","_groupID","_groupName","_groupOwner",
"_groupRank","_toremove","_oldGroup","_ok","_targerPerm","_targetName","_toaddData","_removeData"];

_dialog = findDisplay 55510;
_groupListBox = _dialog displayCtrl 55512;
_index = lbCurSel _groupListBox;
_playerData = _groupListBox lbData _index;

_clanPermissionBox = _dialog displayCtrl 700010;
_comboindex = lbCurSel _clanPermissionBox;
_pemLevel = _clanPermissionBox lbValue _comboindex;


_check = 0;
_haveData = false;
_ok = false;

{
	if ((!isNull _x) && {isPlayer _x} && {str(_x) == _playerData}) exitWith {_pTarget = _x;_check = 1; _targetUID = getPlayerUID _x; _haveData = true;};
} count allUnits;
	
if (_check == 1) then
{
	if (_pTarget == player) exitWith {systemChat "You can change yourself";};
};

if (_check == 0) exitWith {systemChat "You must select someone to cheange Permission";};

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
		_removeData = +_toremove;
	
		//removing  member
		_oldGroup = _oldGroup - [[_targetUID,_targerPerm,_targetName]];
		_oldGroup pushback [_targetUID,_pemLevel,_targetName];
		_toaddData = [_groupID,_groupName,_groupOwner,_groupRank,_oldGroup];
		_pTarget setVariable ["LvL",_pemLevel,true];
		
		//update database		
		viruzupdateGroup = [_removeData,_toaddData,"UPDATE",[_groupID,_oldGroup]];
		publicVariableServer "viruzupdateGroup";
		
		systemChat format["You switched the %1 level of permission to %2",_targetName,_pemLevel];
	};

