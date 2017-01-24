/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_obj"];
_obj = _this select 3;
player playActionNow "Medic";
sleep 6;
if(_obj isKindOf "Land_FirePlace_F") then {
	viruz_hasFire = objNull;
	deleteVehicle _obj;
};
cutText [localize "str_fireplace_removed", "PLAIN DOWN"];
player removeAction s_player_fireout;
s_player_fireout = -1;