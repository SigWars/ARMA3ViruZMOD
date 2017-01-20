disableSerialization;
				
private ["_dialog","_playerListBox","_groupListBox","_groupOffListBox","_onlinePlayerUID","_savedGroup","_ClanID","_namestr","_index","_onlineUID","_puid","_pname","_pUnits"];
	
_dialog = findDisplay 55510;
_playerListBox = _dialog displayCtrl 55511;
_groupListBox = _dialog displayCtrl 55512;
_groupOffListBox = _dialog displayCtrl 55571;
lbClear _playerListBox;
lbClear _groupListBox;
lbClear _groupOffListBox;

//GET SAVED GROUP
_savedGroup = [];
_ClanID = player getVariable ["ClanID","0"];
{
	if ((_x select 0) isEqualTo _ClanID) exitWith { _savedGroup = _x select 4;}; 
}forEach ViruZGroupsArray;

_onlinePlayerUID = [];
//fill player listbox
{
	if ((!isNull _x) && {isPlayer _x}) then {
		_namestr = name _x;             
		_index = _playerListBox lbAdd _namestr;
		_playerListBox lbSetData [_index,str(_x)];
		_playerListBox lbSetPicture [_index,"vzgm\ui\objective_complete_ca.paa"];
		if (count units group _x > 1) then {_playerListBox lbSetPicture [_index,"vzgm\ui\objective_incomplete_ca.paa"];};
	};	    
} count allUnits;

//fill the group listbox online
_pUnits = units group player;
{
	if ((!isNull _x) && {isPlayer _x} && {alive _x}) then {
		_namestr = name _x;             
		_index = _groupListBox lbAdd _namestr;
		_groupListBox lbSetData [_index,str(_x)];
		_groupListBox lbSetPicture [_index,"vzgm\ui\objective_complete_ca.paa"];
		_onlineUID = getPlayerUID _x;
		if !(_onlineUID in _onlinePlayerUID)then
		{
			_onlinePlayerUID set [count _onlinePlayerUID, _onlineUID];
		};
	};
} count _pUnits;

//fill the group listbox offline
{
	_puid = _x select 0;
	if !(_puid in _onlinePlayerUID) then
	{
		_pname = _x select 2;
		_index = _groupListBox lbAdd _pname;
		_groupListBox lbSetData [_index,_puid];
		_groupListBox lbSetPicture [_index,"vzgm\ui\objective_incomplete_ca.paa"];
	};
} forEach _savedGroup;

_onlinePlayerUID = [];
/*//fill offline group listbox
{
	_puid = _x select 0;
	if !(_puid in _onlinePlayerUID) then
	{
		_pname = _x select 2;
		_index = _groupOffListBox lbAdd _pname;
		_groupOffListBox lbSetData [_index,_puid];
		_groupOffListBox lbSetPicture [_index,"vzgm\ui\objective_incomplete_ca.paa"];
	};
} forEach _savedGroup;*/