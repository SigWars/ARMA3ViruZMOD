/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

_array = _this select 3;
_object = _array select 0;
_type = TypeOf(_object);
player playActionNow "Medic";
sleep 8;
player addBackpack format["%1_US_Bag_EP1",_type];
deleteVehicle _object;
r_action = false;
call fnc_usec_medic_removeActions;