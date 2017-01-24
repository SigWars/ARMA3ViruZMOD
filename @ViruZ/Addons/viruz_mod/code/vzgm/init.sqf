private ["_loginGroup","_loginVar"];

_loginVar = "viruzLoginRecord";
waitUntil {uiSleep .25;(!isNil _loginVar)};
/*if (count units group player > 1) then {[player] join grpNull;};

_savedGroup = profileNamespace getVariable["savedGroup",[]];
//hintC format ["VZGROUP: _savedGroup = %1 ",_savedGroup];
player setVariable ["savedGroup",_savedGroup,true];
player setVariable ["purgeGroup",0,true];
if (count _savedGroup > 1) then {
	{
		if (((getPlayerUID _x) in _savedGroup) && {(getPlayerUID player) in (_x getVariable["savedGroup",[]])} && {_x != player}) exitWith {
			_loginGroup = group player;
			[player] join (group _x);
			if (count units _loginGroup < 1) then {deleteGroup _loginGroup;};
		};
	} count allUnits;
} else {
	[player] joinSilent grpNull;
};*/

//#include "\ca\editor\Data\Scripts\dikCodes.h"
//keyboard_keys set [DIK_LWIN,{if (tagName) then {tagName = false;titleText ["\n\nGroup name tags OFF","PLAIN DOWN"];titleFadeOut 4;} else {tagName = true;titleText ["\n\nGroup name tags ON","PLAIN DOWN"];titleFadeOut 4;};_handled = true;}];
//keyboard_keys set [(actionKeys "TacticalView") select 0,{_handled = true;}];
//keyboard_keys set [DIK_RWIN,{if (dialog) then {closeDialog 0;groupManagementActive = false;} else {execVM "\z\addons\viruz_mod\code\loadGroupManagement.sqf";};_handled = true;}];

createClan = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\createclan.sqf";
setRankLevel = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\setRankLevel.sqf";
cancelPendInvite = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\cancelPendInvite.sqf";
acceptGroupInvite = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\acceptGroupInvite.sqf";
declineGroupInvite = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\declineGroupInvite.sqf";
disbandGroup = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\disbandGroup.sqf";
tempGroupInvite = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\tempGroupInvite.sqf";
tempGroupKick = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\tempGroupKick.sqf";
tempGroupLeave = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\tempGroupLeave.sqf";
tempGroupAccept = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\tempGroupAccept.sqf";
tempGroupDecline = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\tempGroupDecline.sqf";
vzgmSlowLoop = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\slowLoop.sqf";
inviteToGroup = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\inviteToGroup.sqf";
kickFromGroup = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\kickFromGroup.sqf";
leaveGroup = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\leaveGroup.sqf";
playerSelectChange = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\playerSelectChange.sqf";
playerSelectChangeoff = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\playerSelectChangeoff.sqf";
tagName = true;
updatePlayerList = compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\updatePlayerList.sqf";
	
if (isNil "vzgmInit") then {call compile preprocessFileLineNumbers "\z\addons\viruz_mod\code\vzgm\icons.sqf";};
uiSleep 1;
[] spawn vzgmInit;
[] spawn vzgmSlowLoop;
systemChat "Press 'HOME' key to open Help Menu";