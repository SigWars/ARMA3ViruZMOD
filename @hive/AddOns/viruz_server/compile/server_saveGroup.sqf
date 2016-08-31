private ["_charID","_liderID","_membros","_tipo"];

_charID =		_this select 0;
_liderID = 		_this select 1;
_membros = 		_this select 2;
//_tipo = 		_this select 3;

_key = format["CHILD:999:INSERT INTO `viruz_group` (`PlayerUID`, `Lider`, `Membros`) VALUES ('%1', '%2', '%3') ON DUPLICATE KEY UPDATE `PlayerUID` = '%1', `Lider` = '%2', `Membros` = '%3' :[]:",_charID,_liderID,_membros];
//_key = format["CHILD:999:UPDATE `viruz_group` SET `PlayerUID` = '%1',`Lider` = '%2',`Membros` = '%3' WHERE `PlayerUID` = '%1' LIMIT 1:[]:",_charID,_liderID,_membros];
diag_log format["HIVEGROUP: key Query: %1",_key];
_result = _key call server_hiveReadWrite;
diag_log format["HIVEGROUP: result: %1",_result];






/*switch (_tipo) do {
	case "insert": { 
	
	
	};
				
				
				
	case "update": { 
	
		//_key = format["CHILD:999:UPDATE `viruz_group`` SET `PlayerUID` = '%1',`Lider` = '%2',`Membros` = '%3' WHERE `PlayerUID` = _charID LIMIT 1:[]:",_charID,_liderID,_membros];
		_result = _key call server_hiveReadWrite;
		diag_log ("HIVEGROUP: READ: "+ str(_key));
	};
};*/

/*_key = format["CHILD:999:SELECT `playerUID`,`Lider`,`Membros`FROM `viruz_group` WHERE `playerUID` = _charID LIMIT 1:[]:",_playerUID];
//_key = format["CHILD:308:%1:%2:%3:%4:%5:%6:%7:%8:%9:",viruZ_instance, _class, 0 , _charID, _worldspace, [], [], 0,_uid];
//diag_log ("HIVEGROUP: READ: "+ str(_key));
result = _key call server_hiveReadWrite;*/
