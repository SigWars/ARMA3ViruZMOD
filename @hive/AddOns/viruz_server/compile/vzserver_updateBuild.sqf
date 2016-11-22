/******************************************************************************************************************
ViruZ Mod for Arma 3
Update Object Position, Owner etc by type
Autor: SigWar
This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/
********************************************************************************************************************/

private ["_tipo","_objID","_objUID","_idKey","_key","_result","_ownerUID","_objPosition","_object","_LastFix","_class","_worldspace","_worldprecision","_charID","_objOwner",
"_inventoryDB","_worldCalc"];

_tipo = 		_this select 0;


switch (_tipo) do {
	
	case "VZPublishBuild": {
		_object 	=		_this select 1;
		_class 		=		_object getVariable ["tipoObj","NOCLASS"];
		_worldspace =		_object getVariable ["WorldSpace","NOWORLD"];
		_worldprecision = 	_object getVariable ["worldprecision","NOWORLDPREC"];
		_charID =	 		_object getVariable ["characterID",0];
		_objOwner = 		_object getVariable ["ownerTODB",0];
		_LastFix = 			currentDate;
		_inventoryDB = "[]";
				
		//diag_log format["PUBLISH ACTION %1-%2-%3-%4-%5-%6-%7",_object,_class,_worldspace,_worldprecision,_charID,_objOwner,_LastFix];
		_objUID = _worldspace call viruz_objectUID2;
		
		_object setVariable ["ObjectUID", _objUID,true];
		_object setVariable ["ViruZMod",1];
		
		_idKey = ([arrayObjectID,1] call BIS_fnc_findExtreme) + 1;
		_object setVariable ["ObjectID", str(_idKey), true];
		
		_key = format["CHILD:999:INSERT INTO object_data (ObjectID, ObjectUID, Instance, Classname, Datestamp, CharacterID, Worldspace, Inventory, OwnerUID, LastFix, Worldprecision) VALUES (%1, %2, %3, '%4', now(), %5, '%6', '%7', %8, '%9', '%10') :[]:",str(_idKey),_objUID,viruZ_instance,_class,_charID,_worldspace,_inventoryDB,_objOwner,_LastFix,_worldprecision];
		diag_log format["VZ_PUBLISH_OBJ: key Query: %1",_key];
		_result = _key call server_hiveReadWrite;
		diag_log format["VZ_PUBLISH_OBJ: result: %1",_result];
		
		if (count _result > 2) exitWith { 
			diag_log format["VZ_PUBLISH_OBJ: RESULT FAILED!, READED TO NEEDUPDATEOBJECT: %1",_object];
			needUpdate_objects set [count needUpdate_objects, [_object,"monitorPublishBuild"]];
		};
		
		arrayObjectID set [count arrayObjectID, _idKey];
		_object addMPEventHandler ["MPKilled",{_this call vehicle_handleServerKilled;}];
		
		_object setVariable ["ownerTODB",Nil,false];
		_object setVariable ["posicao_final",Nil,false];
		_object setVariable ["tipoObj",Nil,false];
		_object setVariable ["WorldSpace",Nil,false];
		_object setVariable ["worldprecision",Nil,false];
		_object setVariable ["canDelete",true, true];
	};
};

//_key = format["CHILD:999:SELECT `playerUID`,`Lider`,`Membros`FROM `viruz_group` WHERE `playerUID` = _charID LIMIT 1:[]:",_playerUID];
//_key = format["CHILD:308:%1:%2:%3:%4:%5:%6:%7:%8:%9:",viruZ_instance, _class, 0 , _charID, _worldspace, [], [], 0,_uid];
//key = format["CHILD:999:INSERT INTO `viruz_group` (`PlayerUID`, `Lider`, `Membros`) VALUES ('%1', '%2', '%3') ON DUPLICATE KEY UPDATE `PlayerUID` = '%1', `Lider` = '%2', `Membros` = '%3' :[]:",_charID,_liderID,_membros];
