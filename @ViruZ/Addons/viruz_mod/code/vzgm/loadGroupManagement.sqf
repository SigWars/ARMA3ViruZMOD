disableSerialization;
				
private ["_i","_dialog","_playerListBox","_groupListBox","_groupName","_namestr","_index","_clanInvite","_clanKick","_clanDisband","_clanLeaveButton","_pname","_pUnits","_ClanID",
"_onlineUID","_puid","_savedGroup","_onlinePlayerUID","_clanLeader","_createClanButton","_clanCreateOk","_clanCreateCancel","_groupInviteButton","_groupKickButton","_groupLeaveButton",
"_needClan","_clanName","_clanRank","_permissionLvl","_ok","_invType","_actualGroupName","_gclanID","_clanPermissionBox","_clanPermApply","_clanNameText","_cancelPendInvite"];

closeDialog 0;
_i="createDialog";createDialog "GroupManagement";	
groupManagmentActive = true;		

//Controls idc
_dialog = findDisplay 55510;
_playerListBox = _dialog displayCtrl 55511;
_groupListBox = _dialog displayCtrl 55512;
_clanNameText = _dialog displayCtrl 700013;
_cancelPendInvite = _dialog displayCtrl 700012;
_cancelPendInvite ctrlShow false;
//Clan controls
_groupName = _dialog displayCtrl 700001;
_groupName ctrlShow false;
_clanInvite = _dialog displayCtrl 55514;
_clanInvite ctrlShow false;
_clanKick = _dialog displayCtrl 55515;
_clanKick ctrlShow false;
_clanDisband = _dialog displayCtrl 55516;
_clanDisband ctrlShow false;
_clanLeaveButton = _dialog displayCtrl 55517;
_clanLeaveButton ctrlShow false;
_createClanButton = _dialog displayCtrl 700005;
_createClanButton ctrlShow false;
_clanCreateOk = _dialog displayCtrl 700006;
_clanCreateOk ctrlShow false;
_clanCreateCancel = _dialog displayCtrl 700007;
_clanCreateCancel ctrlShow false;
_clanPermissionBox = _dialog displayCtrl 700010;
_clanPermissionBox ctrlShow false;
_clanPermApply = _dialog displayCtrl 700011;
_clanPermApply ctrlShow false;
//Temp group controls
_groupInviteButton = _dialog displayCtrl 700002;
_groupInviteButton ctrlShow false;
_groupKickButton = _dialog displayCtrl 700003;
_groupKickButton ctrlShow false;
_groupLeaveButton = _dialog displayCtrl 700004;
_groupLeaveButton ctrlShow false;
//general controls
_groupAcceptInvite = _dialog displayCtrl 700008;
_groupAcceptInvite ctrlShow false;
_groupDeclineInvite = _dialog displayCtrl 700009;
_groupDeclineInvite ctrlShow false;
_clanAcceptInvite = _dialog displayCtrl 55518;
_clanAcceptInvite ctrlShow false;
_clanDeclineInvite = _dialog displayCtrl 55519;
_clanDeclineInvite ctrlShow false;
_groupInviteText = _dialog displayCtrl 55520;


_savedGroup = [];
_hasInvite = false;
_needClan = false;

//fill player listbox
{
	if ((!isNull _x) && {isPlayer _x}) then {
		_namestr = name _x;             
		_index = _playerListBox lbAdd _namestr;
		_playerListBox lbSetData [_index,str(_x)];
		_playerListBox lbSetPicture [_index,"\z\addons\viruz_mod\code\vzgm\ui\igui_viruzico_ca.paa"];
		_playerListBox lbSetPictureColor [_index,[0,1,0,1]];
		if (count units group _x > 1) then {_playerListBox lbSetPicture [_index,"\z\addons\viruz_mod\code\vzgm\ui\igui_viruzico_ca.paa"]; _playerListBox lbSetPictureColor [_index,[1,0,0,1]];};
	};
} count allUnits;

//fill permission Listbox
private _rankList = ["Initiate","Member","Officer","Leader"];
private _count = 0;
{
	_comboIndex = _clanPermissionBox lbAdd _x;
	_clanPermissionBox lbSetValue [_comboIndex,_count];
	_count = _count + 1;
}ForEach _rankList;

while {groupManagmentActive} do {
    
	//Check group array
	_ClanID = player getVariable ["ClanID","0"];
	{
	   if ((_x select 0) isEqualTo _ClanID) exitWith { _savedGroup = _x select 4; }; 
	}forEach ViruZGroupsArray;
	
	
	_onlinePlayerUID = [];
	_playerUID = getPlayerUID player;
	_clanLeader = player getVariable ["ClanLeader","0"];
	_clanName =  player getVariable ["clanName",name player];
	_clanRank = player getVariable ["groupRank",0];
	_permissionLvl = player getVariable ["LvL",0];
	_needClan = (_ClanID isEqualTo (name player)); // if true no have clan
	_actualGroupName = groupId (group player);
	_pUnits = units group player;
	
	_stringRank = "";
	switch (_permissionLvl) do {
		case 0:  {_stringRank = "Initiate"};
		case 1:  {_stringRank = "Member"};
		case 2:  {_stringRank = "Officer"};
		case 3:  {_stringRank = "Leader"};
	
	};
	
	{if (_x select 1 == _playerUID) then {_hasInvite = true};} forEach currentInvites;
	{if ((player == leader group player) and (_x select 0 == _playerUID)) then {_cancelPendInvite ctrlShow true;}else{_cancelPendInvite ctrlShow false};} forEach currentInvites;
	if (!_needClan) then {_clanNameText ctrlSetStructuredText parseText (format ["CLAN NAME: %1  CLAN LEVEL: %2 PERMMISSION: %3",_clanName,_clanRank,_stringRank]);};
    
	//check clan leader and enable buttons
	if (_playerUID == _clanLeader) then 
	{
		if (_needClan)then{_createClanButton ctrlShow true;}; 
		if !(_needClan)then{_clanLeaveButton ctrlShow true;}else{_clanLeaveButton ctrlShow false};
		if (count _pUnits > 1)then{_groupLeaveButton ctrlShow true;}else{_groupLeaveButton ctrlShow false;};
	}
	else
	{
		if (_needClan)then{_createClanButton ctrlShow true;};
		if !(_needClan)then{_clanLeaveButton ctrlShow true;}else{_clanLeaveButton ctrlShow false};
		if (count _pUnits > 1)then{_groupLeaveButton ctrlShow true;}else{_groupLeaveButton ctrlShow false;}; 
	};
    
	//check if have invite
	_ok = false;
    if (_hasInvite) then {
        
        {
			_invite = _x;
			if (_invite select 1 == _playerUID) then {
				{
					if ((!isNull _x) && {_invite select 0 == getPlayerUID _x}) exitWith {_pName = name _x; _ok = true};
				} count allUnits;
			};
			if (_ok) exitWith {_invType = _invite select 2};
		} forEach currentInvites;
        
		switch (_invType) do {
			case "CLAN":{ 
				_groupInviteText ctrlShow true;
				_clanAcceptInvite ctrlShow true;
				_clanDeclineInvite ctrlShow true; 
				_groupInviteText ctrlSetStructuredText parseText (format ["CLAN Invite From<br/>%1",_pName]);
			};
			case "GROUP":{ 
				_groupInviteText ctrlShow true;
				_groupAcceptInvite ctrlShow true;
				_groupDeclineInvite ctrlShow true;
				_groupInviteText ctrlSetStructuredText parseText (format ["GROUP Invite From<br/>%1",_pName]);
			
			};
		};
		
	} else {
    	_clanAcceptInvite ctrlShow false;
        _clanDeclineInvite ctrlShow false;
		_groupAcceptInvite ctrlShow false;
		_groupDeclineInvite ctrlShow false;
        _groupInviteText ctrlShow false; 
    };
	
	//fill the group listbox online
	{
		if ((!isNull _x) && {isPlayer _x} && {alive _x}) then {
			_namestr = name _x;
			_gclanID = _x getVariable ["ClanID","0"];
			_index = _groupListBox lbAdd _namestr;
			_groupListBox lbSetData [_index,str(_x)];
			if (_playerUID isEqualTo _gclanID)then{
				_groupListBox lbSetPicture [_index,"\z\addons\viruz_mod\code\vzgm\ui\igui_viruzico_ca.paa"];
				_groupListBox lbSetPictureColor [_index,[0,1,0,1]];
			}
			else
			{	
				_groupListBox lbSetPicture [_index,"\z\addons\viruz_mod\code\vzgm\ui\igui_viruzico_ca.paa"];
				_groupListBox lbSetPictureColor [_index,[1,1,0,1]];
			};
			
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
			_groupListBox lbSetPicture [_index,"\z\addons\viruz_mod\code\vzgm\ui\igui_viruzico_ca.paa"];
			_groupListBox lbSetPictureColor [_index,[0.663,0.663,0.663,1]];
		};
	} forEach _savedGroup;
	
	uiSleep 1;
    _hasInvite = false;
	_onlinePlayerUID = [];
    lbClear _groupListBox;
	if (!dialog) then {groupManagmentActive = false;};
};