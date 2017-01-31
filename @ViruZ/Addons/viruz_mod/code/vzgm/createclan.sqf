if (player != leader group player) exitWith {systemChat "You are not the Clan leader and can not invite people.";};

disableSerialization;
#define CONTROL(disp,ctrl) ((findDisplay ##disp) displayCtrl ##ctrl)
private ["_dialog","_playerListBox","_pTarget","_index","_playerData","_clanName","_length","_chrByte","_allowed","_badChar","_newgroup","_toAdd"];

_dialog = findDisplay 55510;
_playerListBox = _dialog displayCtrl 55511;
_index = lbCurSel _playerListBox;
_playerData = _playerListBox lbData _index;
_badChar = false;
_sameName = false;


_clanName = ctrlText (CONTROL(55510,700001));
_length = count (toArray(_clanName));
_chrByte = toArray (_clanName);
_allowed = toArray("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_ ");

if(_length > 32) exitWith {systemChat "The name size can not be greater than 32 characters.";};
if (_length < 3) exitWith {systemChat "The name must have a minimum of 3 characters.";};
{if(!(_x in _allowed)) exitWith {_badChar = true;};} forEach _chrByte;
if(_badChar) exitWith {systemChat "Incompatible characters, only allowed to use: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_ ";};
if (_clanName isEqualTo "Type you Clan Name") exitWith {systemChat "Enter the name of your clan first";};
{ if ((_x select 1) isEqualTo _clanName) exitWith { _sameName = true;}; }forEach ViruZGroupsArray;
if (_sameName) exitWith {systemChat "The name you have chosen is already in use.";};



//new data to group
_newgroup = [[getPlayerUID player,3,name player]];

//sets player variables
player setVariable ["ClanID",getPlayerUID player,true];
player setVariable ["ClanLeader",getPlayerUID player,true];
player setVariable ["LvL",3,true];
player setVariable ["clanName",_clanName,true];
player setVariable ["haveClan",true,true];
player setVariable ["groupRank",0,true];

//set group id
//_clan = createGroup west;
(group player) setGroupIdGlobal [_clanName];
//[player] join _clan;

//add group to global array
_toAdd = [getPlayerUID player,_clanName,getPlayerUID player,0,_newGroup];

viruzupdateGroup = ["NOTHING",_toAdd,"CREATE","NOTHING"];
publicVariableServer "viruzupdateGroup";

systemChat format["You have created clan with name: %1",_clanName];
