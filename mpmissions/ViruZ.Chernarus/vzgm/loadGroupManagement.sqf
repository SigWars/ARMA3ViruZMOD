disableSerialization;
				
private ["_i","_dialog","_playerListBox","_groupListBox","_groupName","_namestr","_index","_groupInvite","_groupKick","_groupDisband","_groupLeaveButton","_pname","_pUnits",
"_ClanID","_onlineUID","_puid","_savedGroup","_onlinePlayerUID","_clanLeader"];

closeDialog 0;
_i="createDialog";createDialog "GroupManagement";			
_dialog = findDisplay 55510;
groupManagmentActive = true;
_playerListBox = _dialog displayCtrl 55511;
_groupListBox = _dialog displayCtrl 55512;
_groupName = _dialog displayCtrl 700001;
_groupInvite = _dialog displayCtrl 55514;
_groupKick = _dialog displayCtrl 55515;
_groupDisband = _dialog displayCtrl 55516;
_groupLeaveButton = _dialog displayCtrl 55517;
_groupAcceptInvite = _dialog displayCtrl 55518;
_groupDeclineInvite = _dialog displayCtrl 55519;
_groupInviteText = _dialog displayCtrl 55520;
_groupName ctrlShow false;
_groupInvite ctrlShow false;
_groupKick ctrlShow false;
_groupDisband ctrlShow false;
_groupLeaveButton ctrlShow false;
_groupDeclineInvite ctrlShow false;
_groupAcceptInvite ctrlShow false;


_savedGroup = [];
_hasInvite = false;

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

//Check group array
_ClanID = player getVariable ["ClanID","0"];
{
   if ((_x select 0) isEqualTo _ClanID) exitWith { _savedGroup = _x select 4;}; 
}forEach ViruZGroupsArray;
//diag_log format ["_savedGroup = %1", _savedGroup ];

while {groupManagmentActive} do {
    _onlinePlayerUID = [];
	_clanLeader = player getVariable ["ClanLeader","0"];
	
	{if (_x select 1 == getPlayerUID player) then {_hasInvite = true};} forEach currentInvites;
    
	//check if player is group leader
	_pUnits = units group player;
    if (count _pUnits > 1) then {
        if (getPlayerUID player == _clanLeader) then {
			//_groupDisband ctrlShow true;
            _groupKick ctrlShow true;
			_groupLeaveButton ctrlShow true;
			if (_ClanID isEqualTo (name player)) then
			{
				_groupName ctrlShow true;
			};
        } else {
			_groupLeaveButton ctrlShow true;
			_groupName ctrlShow false;
        };
    } else {
		//_groupDisband ctrlShow false;
		_groupLeaveButton ctrlShow true;
		if (_ClanID isEqualTo (name player)) then
		{
			_groupName ctrlShow true;
		};
    };
    
	//check if have invite
    if (_hasInvite) then {
        _groupInviteText ctrlShow true;
        _groupAcceptInvite ctrlShow true;
        _groupDeclineInvite ctrlShow true;
        {
			_invite = _x;
			if (_invite select 1 == getPlayerUID player) then {
				{
					if ((!isNull _x) && {_invite select 0 == getPlayerUID _x}) exitWith {_pName = name _x;};
				} count allUnits;
			};
		} forEach currentInvites;
        _groupInviteText ctrlSetStructuredText parseText (format ["Group Invite From<br/>%1",_pName]);
    } else {
    	_groupAcceptInvite ctrlShow false;
        _groupDeclineInvite ctrlShow false;
        _groupInviteText ctrlShow false; 
    };
	
	//fill the group listbox online
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
	
	uiSleep 5;
    _hasInvite = false;
	_onlinePlayerUID = [];
    lbClear _groupListBox;
	if (!dialog) then {groupManagmentActive = false;};
};