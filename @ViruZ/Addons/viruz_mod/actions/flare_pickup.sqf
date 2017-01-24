/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_flare"];
_flare = _this select 3;
player playActionNow "PutDown";
sleep 2;
_flare attachTo [player,[0,0,0],"granat2"];
[_flare, -90, -10] call object_setpitchbank;
_flare setPos (getPos _flare);
_flare setVariable ["owner",player,true];
player removeAction s_player_grabflare;
player removeAction s_player_removeflare;
viruz_hasLight = true;

//Add Drop Action
_text = getText (configFile >> "CfgAmmo" >> (typeOf _flare) >> "displayName");
s_player_dropflare = player addAction [format[localize "str_actions_medical_16",_text], "\z\addons\viruz_mod\actions\flare_drop.sqf",_flare, 1, false, true, "", ""];

while {(alive _flare) and viruz_hasLight} do {
	sleep 0.1;
};
if (viruz_hasLight) then {
	viruz_hasLight = false;
	player removeAction s_player_dropflare;
	s_player_grabflare = -1;
	s_player_removeflare = -1;
};
