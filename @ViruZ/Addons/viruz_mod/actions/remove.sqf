/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_obj","_objectID","_objectUID"];
_obj		= _this select 3;
_objectID 	= _obj getVariable ["ObjectID","0"];
_objectUID	= _obj getVariable ["ObjectUID","0"];

player playActionNow "Medic";
sleep 1;

	_dis=20;
	_sfx = "repair";
	[player,_sfx,0,false,_dis] call viruz_zombieSpeak;  
	[player,_dis,true,(getPosATL player)] spawn player_alertZombies;

sleep 5;
	
//["viruzDeleteObj",[_objectID,_objectUID]] call callRpcProcedure;
	viruzDeleteObj = [_objectID,_objectUID];
	publicVariable "viruzDeleteObj";
deleteVehicle _obj;