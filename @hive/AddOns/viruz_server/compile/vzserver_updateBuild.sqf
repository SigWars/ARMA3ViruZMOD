/******************************************************************************************************************
ViruZ Mod for Arma 3
Update Object Position, Owner etc by type
Autor: SigWar
This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/
********************************************************************************************************************/

private ["_tipo","_objID","_objUID","_ownerUID","_objPosition","_object","_LastFix","_class","_worldspace","_worldprecision","_charID","_objOwner","_inventoryDB"];

_tipo = 		_this select 0;


switch (_tipo) do {
	case "UPDposition": {
		_objID =		_this select 1;
		_objUID = 		_this select 2;
		_ownerUID = 	_this select 3;
		_objPosition = 	_this select 4;
		_object = 		_this select 5;
		
		_key = format["CHILD:999:UPDATE `object_data` SET `Worldspace` = '%1' WHERE `ObjectUID` = '%2' or `ObjectID` = '%3' LIMIT 1:[]:",_objPosition,_objUID,_objID];
		diag_log format["VZ_UPDATE_OBJ_POSITION: key Query: %1",_key];
		_result = _key call server_hiveReadWrite;
		diag_log format["VZ_UPDATE_OBJ_POSITION: result: %1",_result];
	};
	case "UPDowner": {
		_objID =		_this select 1;
		_objUID = 		_this select 2;
		_ownerUID = 	_this select 3;
		_objPosition = 	_this select 4;
		_object = 		_this select 5;
		_LastFix = 		_this select 6;
		
		_key = format["CHILD:999:UPDATE `object_data` SET `OwnerUID` = %1, `LastFix` = '%4'  WHERE `ObjectUID` = '%2' or `ObjectID` = '%3' LIMIT 1:[]:",_ownerUID,_objUID,_objID,_LastFix];
		diag_log format["VZ_UPDATE_OBJ_OWNER: key Query: %1",_key];
		_result = _key call server_hiveReadWrite;
		diag_log format["VZ_UPDATE_OBJ_OWNER: result: %1",_result];
	};
	case "Lock": { 
		_objID =		_this select 1;
		_objUID = 		_this select 2;
		_ownerUID = 	_this select 3;
		_objPosition = 	_this select 4;
		_object = 		_this select 5;
		
		_key = format["CHILD:999:UPDATE `object_data` SET `Locked` = '1' WHERE `ObjectUID` = '%1' or `ObjectID` = '%2' LIMIT 1:[]:",_objUID,_objID];
		diag_log format["VZ_UPDATE_OBJ_LOCK: key Query: %1",_key];
		_result = _key call server_hiveReadWrite;
		diag_log format["VZ_UPDATE_OBJ_LOCK: result: %1",_result];
	};
	case "Unlock": {
		_objID =		_this select 1;
		_objUID = 		_this select 2;
		_ownerUID = 	_this select 3;
		_objPosition = 	_this select 4;
		_object = 		_this select 5;
		
		_key = format["CHILD:999:UPDATE `object_data` SET `Locked` = '0' WHERE `ObjectUID` = '%1' or `ObjectID` = '%2' LIMIT 1:[]:",_objUID,_objID];
		diag_log format["VZ_UPDATE_OBJ_UNLOCK: key Query: %1",_key];
		_result = _key call server_hiveReadWrite;
		diag_log format["VZ_UPDATE_OBJ_UNLOCK: result: %1",_result];
	};

	case "RepairBuild": {
		_objID =		_this select 1;
		_objUID = 		_this select 2;
		_LastFix = 		_this select 3;
		
		_key = format["CHILD:999:UPDATE `object_data` SET `LastFix` = '%1' WHERE `ObjectUID` = '%2' or `ObjectID` = '%3' LIMIT 1:[]:",_LastFix,_objUID,_objID];
		diag_log format["VZ_UPDATE_OBJ_UNLOCK: key Query: %1",_key];
		_result = _key call server_hiveReadWrite;
		diag_log format["VZ_UPDATE_OBJ_UNLOCK: result: %1",_result];
	};
	
	case "VZPublishBuild": {
		_object 	=		_this select 1;
		_class 		=		_this select 2;
		_worldspace =		_this select 3;
		_worldprecision = 	_this select 4;
		_charID =	 		_this select 5;
		_objOwner = 		_this select 6;
		_LastFix = 			_this select 7;
		_inventoryDB = "[]";
				
		//diag_log format["PUBLISH ACTION %1-%2-%3-%4-%5-%6-%7",_object,_class,_worldspace,_worldprecision,_charID,_objOwner,_LastFix];
		_uid = _worldspace call viruz_objectUID2;
		
		_object setVariable ["ObjectUID", _uid,true];
		_object setVariable ["ViruZMod",1];
		
		_key = format["CHILD:999:INSERT INTO object_data (ObjectUID, Instance, Classname, Datestamp, CharacterID, Worldspace, Inventory, OwnerUID, LastFix, Worldprecision) VALUES (%1, %2, '%3', now(), %4, '%5', '%6', %7, '%8', '%9') :[]:",_uid,viruZ_instance,_class,_charID,_worldspace,_inventoryDB,_objOwner,_LastFix,_worldprecision];
		diag_log format["VZ_PUBLISH_OBJ: key Query: %1",_key];
		_result = _key call server_hiveReadWrite;
		diag_log format["VZ_PUBLISH_OBJ: result: %1",_result];
		
		_idKey = ([arrayObjectID,1] call BIS_fnc_findExtreme) + 1;
		arrayObjectID set [count arrayObjectID, _idKey];
		_object setVariable ["ObjectID", str(_idKey), true];
		
		_object addMPEventHandler ["MPKilled",{_this call vehicle_handleServerKilled;}];
		
		viruz_serverObjectMonitor set [count viruz_serverObjectMonitor,_object];
	};
};

//_key = format["CHILD:999:SELECT `playerUID`,`Lider`,`Membros`FROM `viruz_group` WHERE `playerUID` = _charID LIMIT 1:[]:",_playerUID];
//_key = format["CHILD:308:%1:%2:%3:%4:%5:%6:%7:%8:%9:",viruZ_instance, _class, 0 , _charID, _worldspace, [], [], 0,_uid];
//key = format["CHILD:999:INSERT INTO `viruz_group` (`PlayerUID`, `Lider`, `Membros`) VALUES ('%1', '%2', '%3') ON DUPLICATE KEY UPDATE `PlayerUID` = '%1', `Lider` = '%2', `Membros` = '%3' :[]:",_charID,_liderID,_membros];
