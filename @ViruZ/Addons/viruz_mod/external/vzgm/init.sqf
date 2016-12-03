private ["_loginGroup","_loginVar"];

_loginVar = "viruzLoginRecord";
waitUntil {uiSleep .25;(!isNil _loginVar)};
if (count units group player > 1) then {[player] join grpNull;};

_savedGroup = profileNamespace getVariable["savedGroup",[]];
//hintC format ["VZGROUP: _savedGroup = %1 ",_savedGroup];
player setVariable ["savedGroup",_savedGroup,true];
player setVariable ["purgeGroup",0,true];
if (count _savedGroup > 1) then {
	{
		if (((getPlayerUID _x) in _savedGroup) && (Alive _x) && {(getPlayerUID player) in (_x getVariable["savedGroup",[]])} && {_x != player}) exitWith {
			_loginGroup = group player;
			[player] join (group _x);
			if (count units _loginGroup < 1) then {deleteGroup _loginGroup;};
		};
	} count allUnits;
} else {
	[player] joinSilent grpNull;
};

//#include "\ca\editor\Data\Scripts\dikCodes.h"
//keyboard_keys set [DIK_LWIN,{if (tagName) then {tagName = false;titleText ["\n\nGroup name tags OFF","PLAIN DOWN"];titleFadeOut 4;} else {tagName = true;titleText ["\n\nGroup name tags ON","PLAIN DOWN"];titleFadeOut 4;};_handled = true;}];
//keyboard_keys set [(actionKeys "TacticalView") select 0,{_handled = true;}];
//keyboard_keys set [DIK_RWIN,{if (dialog) then {closeDialog 0;groupManagementActive = false;} else {execVM "vzgm\loadGroupManagement.sqf";};_handled = true;}];

acceptGroupInvite = compile preprocessFileLineNumbers "\z\addons\viruz_mod\external\vzgm\acceptGroupInvite.sqf";
declineGroupInvite = compile preprocessFileLineNumbers "\z\addons\viruz_mod\external\vzgm\declineGroupInvite.sqf";
disbandGroup = compile preprocessFileLineNumbers "\z\addons\viruz_mod\external\vzgm\disbandGroup.sqf";
vzgmSlowLoop = compile preprocessFileLineNumbers "\z\addons\viruz_mod\external\vzgm\slowLoop.sqf";
inviteToGroup = compile preprocessFileLineNumbers "\z\addons\viruz_mod\external\vzgm\inviteToGroup.sqf";
kickFromGroup = compile preprocessFileLineNumbers "\z\addons\viruz_mod\external\vzgm\kickFromGroup.sqf";
leaveGroup = compile preprocessFileLineNumbers "\z\addons\viruz_mod\external\vzgm\leaveGroup.sqf";
playerSelectChange = compile preprocessFileLineNumbers "\z\addons\viruz_mod\external\vzgm\playerSelectChange.sqf";
tagName = true;
updatePlayerList = compile preprocessFileLineNumbers "\z\addons\viruz_mod\external\vzgm\updatePlayerList.sqf";
	
if (isNil "vzgmInit") then {call compile preprocessFileLineNumbers "\z\addons\viruz_mod\external\vzgm\icons.sqf";};
uiSleep 1;
[] spawn vzgmInit;
[] spawn vzgmSlowLoop;
systemChat "Press 'HOME' key to open Help Menu";