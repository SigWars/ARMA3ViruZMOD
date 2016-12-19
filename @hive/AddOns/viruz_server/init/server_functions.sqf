waituntil {!isnil "bis_fnc_init"};
/******************************************************************************************************************
ViruZ Mod for Arma 3
Server precompile functions
Autor: SigWar
This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
********************************************************************************************************************/
/*
BIS_MPF_remoteExecutionServer = {
	if ((_this select 1) select 2 == "JIPrequest") then {
		[nil,(_this select 1) select 0,"loc",rJIPEXEC,[any,any,"per","execVM","ca\Modules\Functions\init.sqf"]] call RE;
	};
};
*/
viruz_NotificationTips = getArray(ConfigFile >> "viruzConfigs" >> "NotificationTips");
BIS_Effects_Burn =						{};
server_playerLogin =					compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_playerLogin.sqf";
server_playerSetup =					compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_playerSetup.sqf";
server_onPlayerDisconnect = 			compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_onPlayerDisconnect.sqf";
server_updateObject =					compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_updateObject.sqf";
server_playerDied =						compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_playerDied.sqf";
server_publishObj = 					compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_publishObject.sqf";	//Creates the object in DB
server_saveGroup = 						compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_saveGroup.sqf";		//Saves the group in database
server_UpdateBuild = 					compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\vzserver_updateBuild.sqf"; 	//Update ViruZ building system parameters
server_deleteObj =						compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_deleteObj.sqf"; 	//Removes the object from the DB
server_playerSync =						compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_playerSync.sqf";
zombie_findOwner =						compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\zombie_findOwner.sqf";
server_updateNearbyObjects =			compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_updateNearbyObjects.sqf";
server_spawnCrashSite  =				compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\vzserver_Helicrash.sqf";
server_VehiclesSpawner  =   		 	compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_VehiclesSpawner.sqf";
server_ObjectInBuildingSpawner  =		compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_ObjectInBuildingSpawner.sqf";
server_objectSpawnerMonitor  =			compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_objectSpawnerMonitor.sqf";
server_objectSpawner  =					compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_objectSpawner.sqf";
server_WreckSpawner  =					compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_WreckSpawner.sqf";
PTm_fnc_modulePoster =					compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\fn_modulePoster.sqf";
server_StartSpawnBulds = 				compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\vzserver_spawnBuilds.sqf";
server_StartSpawnVehicles =				compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\vzserver_spawnVehicles.sqf";
server_autorestart = 					compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\vzserver_autorestart.sqf";
//PTm_fnc_windowsAreBroke =				compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\fn_windowsAreBroke.sqf";
//server_manikenSync =					compile preprocessFileLineNumbers "\z\addons\viruz_server\compile\server_manikenSync.sqf";

vehicle_handleInteract = {
	private["_object"];
	_object = _this select 0;
	needUpdate_objects = needUpdate_objects - [_object];
	[_object, "all"] call server_updateObject;
};

vehicle_handleServerKilled = {
	private["_unit","_killer"];
	_unit = _this select 0;
	_killer = _this select 1;
		
	[_unit, "killed"] call server_updateObject;
	
	_unit removeAllMPEventHandlers "MPKilled";
	_unit removeAllEventHandlers "Killed";
	_unit removeAllEventHandlers "HandleDamage";
	_unit removeAllEventHandlers "GetIn";
	_unit removeAllEventHandlers "GetOut";
};

check_publishobject = {
	private["_allowed","_allowedObjects","_object"];

	_object = _this select 0;
	_playername = _this select 1;
	_allowedObjects = [
	"TentStorage", 
	"Hedgehog_DZ", 
	"Sandbag1_DZ",
	"TrapBear",
	"Wire_cat1",
	"FlagSmall_F",
	"Land_Slum_House02_F","Land_Slum_House01_F","Land_i_House_Big_01_V1_F","Land_i_House_Big_01_V2_F","Land_i_House_Big_01_V3_F",
	"Land_i_House_Big_02_V2_F","Land_i_House_Big_02_V3_F","Land_i_Shop_02_V1_F","Land_i_House_Small_01_V1_F","Land_i_House_Small_01_V2_F",
	"Land_i_House_Small_01_V3_F","Land_i_House_Small_02_V1_F","Land_i_House_Small_02_V2_F","Land_i_House_Small_02_V3_F","Land_i_House_Small_03_V1_F",
	"Land_Airport_Tower_F","Land_i_Shed_Ind_F","Land_Cargo_House_V1_F","Land_Cargo_House_V3_F","Land_Cargo_HQ_V1_F","Land_Cargo_HQ_V2_F",
	"Land_Cargo_Tower_V1_No7_F"
	];
	_allowed = false;

	diag_log format ["DEBUG: Checking if Object: %1 is allowed published by %2", _object, _playername];

	if ((typeOf _object) in _allowedObjects) then {
		diag_log format ["DEBUG: Object: %1 published by %2 is Safe",_object, _playername];
		_allowed = true;
	};

	_allowed
};

//event Handlers used in fireplace and traps monitor to remove all ARMA handles
eh_localCleanup = {
	private ["_object"];
	_object = _this select 0;
	_object addEventHandler ["local", {
		if(_this select 1) then {
			private["_type","_unit"];
			_unit = _this select 0;
			_type = typeOf _unit;
			 _myGroupUnit = group _unit;
 			_unit removeAllMPEventHandlers "mpkilled";
 			_unit removeAllMPEventHandlers "mphit";
 			_unit removeAllMPEventHandlers "mprespawn";
 			_unit removeAllEventHandlers "FiredNear";
			_unit removeAllEventHandlers "HandleDamage";
			_unit removeAllEventHandlers "Killed";
			_unit removeAllEventHandlers "Fired";
			_unit removeAllEventHandlers "GetOut";
			_unit removeAllEventHandlers "GetIn";
			_unit removeAllEventHandlers "Local";
			//clearVehicleInit _unit;
			deleteVehicle _unit;
			deleteGroup _myGroupUnit;
			_unit = nil;
			diag_log ("CLEANUP: DELETED A " + str(_type) );
		};
	}];
};

server_hiveWrite = {
	private["_data"];
	//diag_log ("ATTEMPT WRITE: " + _this);
	_data = "HiveExt" callExtension _this;
	//diag_log ("WRITE: " +str(_data));
};

server_hiveReadWrite = {
	private["_key","_resultArray","_data"];
	_key = _this;
	//diag_log ("ATTEMPT READ/WRITE: " + _key);
	_data = "HiveExt" callExtension _key;
	//diag_log ("READ/WRITE: " +str(_data));
	_resultArray = call compile format ["%1",_data];
	_resultArray
};

/*server_characterSync = {
	private ["_characterID","_playerPos","_playerGear","_playerBackp","_medical","_currentState","_currentModel","_key"];
	_characterID = 	_this select 0;	
	_playerPos =	_this select 1;
	_playerGear =	_this select 2;
	_playerBackp =	_this select 3;
	_medical = 		_this select 4;
	_currentState =	_this select 5;
	_currentModel = _this select 6;
	
	_key = format["CHILD:201:%1:%2:%3:%4:%5:%6:%7:%8:%9:%10:%11:%12:%13:%14:%15:%16:",_characterID,_playerPos,_playerGear,_playerBackp,_medical,false,false,0,0,0,0,_currentState,0,0,_currentModel,0];
	//diag_log ("HIVE: WRITE: "+ str(_key) + " / " + _characterID);
	_key call server_hiveWrite;
};*/

//onPlayerConnected 		"[_uid,_name] spawn server_onPlayerConnect;";
onPlayerDisconnected 		"[_uid,_name] call server_onPlayerDisconnect;";
//addMissionEventHandler ["HandleDisconnect",{_this call server_onPlayerDisconnect;}];

server_getDiff =	{
	private["_variable","_object","_vNew","_vOld","_result"];
	_variable = _this select 0;
	_object = 	_this select 1;
	_vNew = 	_object getVariable[_variable,0];
	_vOld = 	_object getVariable[(_variable + "_CHK"),_vNew];
	_result = 	0;
	if (_vNew < _vOld) then {
		//JIP issues
		_vNew = _vNew + _vOld;
		_object getVariable[(_variable + "_CHK"),_vNew];
	} else {
		_result = _vNew - _vOld;
		_object setVariable[(_variable + "_CHK"),_vNew];
	};
	_result
};

server_getDiff2 =	{
	private["_variable","_object","_vNew","_vOld","_result"];
	_variable = _this select 0;
	_object = 	_this select 1;
	_vNew = 	_object getVariable[_variable,0];
	_vOld = 	_object getVariable[(_variable + "_CHK"),_vNew];
	_result = _vNew - _vOld;
	_object setVariable[(_variable + "_CHK"),_vNew];
	_result
};

viruz_objectUID = {
	private["_position","_dir","_key","_object"];
	_object = _this;
	_position = getPosATL _object;
	_dir = direction _object;
	_key = [_dir,_position] call viruz_objectUID2;
    _key
};

viruz_objectUID2 = {
	private["_position","_dir","_key"];
	_dir = _this select 0;
	_key = "";
	_position = _this select 1;
	{
		_x = _x * 10;
		if ( _x < 0 ) then { _x = _x * -10 };
		_key = _key + str(round(_x));
	} forEach _position;
	_key = _key + str(round(_dir));
	_key
};

viruz_recordLogin = {
	private["_key"];
	_key = format["CHILD:103:%1:%2:%3:",_this select 0,_this select 1,_this select 2];
	_key call server_hiveWrite;
};

VZserv_fnc_substr = {
		//substring = [string] call VZ_fnc_substr;
		private "_arr";
		_arr = toArray (_this select 0);
		_ElementsToErase = [91,93];  
		_Newarray = _arr - _ElementsToErase;
		toString _Newarray  
};
	
VZ_func_subDate	= {
	/*	Parameters:
        0 ARRAY        dateStart    start date in format [year, month, day]
        1 ARRAY        dateEnd        end date in format [year, month, day]
    
		Return:
        INTEGER        daysTotal    difference in days between the given dates
	*/	
		_dateStart = _this select 0 ; 
		_dateEnd = _this select 1 ; 

		_yearStart =  _dateStart select 0; 
		_monthStart =  _dateStart select 1; 
		_dayStart =  _dateStart select 2; 
		_hourStart =  _dateStart select 3; 
		_minStart =  _dateStart select 4; 

		_yearEnd =  _dateEnd select 0; 
		_monthEnd =  _dateEnd select 1; 
		_dayEnd =  _dateEnd select 2; 
		_hourEnd =  _dateEnd select 3; 
		_minEnd =  _dateEnd select 4; 

		_daysTotal = 0; 

		for "_i" from  _yearStart to   ( _yearEnd   - 1 )  do 
		{ 
 		    /*
		    Definition of a leap year:
		    - if year is dividable by 4, it is a leap year
 		   - if year is dividable by 100, it is NOT a leap year
 		   - if year is dividable by 400, it is a leap year
 		   - else, it is NOT a leap year
 		   */ 
 		   _isLeapYear =  if  ( _i mod 4 == 0 && { _i mod 100 != 0 || _i mod 400 == 0 }  )  then   {true} else {false}; 
		    if (_isLeapYear) then 
		    { 
		       _daysTotal = _daysTotal + 366; 
		    } 
		     else 
			{ 
 		       _daysTotal = _daysTotal + 365; 
			}; 
 		}; 

		_isLeapYear = if (_yearStart mod 4 == 0 && { _yearStart mod 100 != 0 || _yearStart mod 400 == 0 }) then {true} else {false}; 
		_daysSum = 0; 

		_daysOfMonths = [ 31 ,  if ( _isLeapYear )  then {29} else {28}, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; 
		{ 
		    if  ( _monthStart isEqualTo   (_forEachIndex + 1)) exitWith  {  }; 
				_daysSum   =  _daysSum   - _x;
		}forEach  _daysOfMonths; 

		_isLeapYear = if(_yearEnd mod 4 == 0 && { _yearEnd mod 100 != 0 || _yearEnd mod 400 == 0}) then {true} else {false}; 
		_daysOfMonths =  [31, if( _isLeapYear) then  {29} else {28}, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]; 
		{ 
		    if  ( _monthEnd isEqualTo  (_forEachIndex + 1)) exitWith {}; 
			_daysSum = _daysSum + _x;
		}forEach _daysOfMonths; 

		_daysTotal = _daysTotal - _dayStart + _dayEnd + _daysSum ; 

		_daysTotal 
 
};

VIRUZ_GlobalTextBroadcast = {
	//Based on ExileMod BroadCastMissionStatus.sqf
	if !(params["_messageTitle","_messageInfo"]) exitWith {	diag_log format ["VIRUZ ERROR :: Calling VIRUZ_GlobalTextBroadcast with invalid parameters: %1",_this];};

	_messageInfo params ["_titleColor",	"_message"];

	if !(_message isEqualType "") then {_message = str _message;};

	private _status =	if ((count _messageInfo)>2) then {	_messageInfo select 2 }	else { "start" };
	{
		switch (toLower _x) do
		{
			case "systemchatmessage":
			{
				format["%1: %2",toUpper _messageTitle,_message] remoteExecCall ["systemChat",-2];
			};

			case "standardhintmessage":
			{
				format
				[
					"<t color='%1' size='%2' font='%3'>%4</t><br/><t color='%5' size='%6' font='%7'>%8</t>",
					_titleColor,
					1.2,
					"puristaMedium",
					_messageTitle,
					"#FFFFFF",
					0.65,
					"Zeppelin33",
					_message
				] remoteExecCall ["VIRUZ_Client_fnc_hintSilent",-2];
			};

			case "dynamictextmessage":
			{
				(format
				[
					"<t color='%1' size='%2' font='%3'>%4</t><br/><t color='%5' size='%6' font='%7'>%8</t>",
					_titleColor,
					1.2,
					"puristaMedium",
					_messageTitle,
					"#FFFFFF",
					0.65,
					"Zeppelin33",
					_message
				]) remoteExecCall ["VIRUZ_Client_fnc_spawnDynamicText", -2];
			};

			case "texttilesmessage":
			{
				(format
				[
					"<t color='%1' size='%2' font='%3' align='center'>%4</t><br/><t color='%5' size='%6' font='%7' align='center'>%8</t>",
					_titleColor,
					1.2,
					"puristaMedium",
					_messageTitle,
					"#FFFFFF",
					0.65,
					"Zeppelin33",
					_message
				]) remoteExecCall ["VIRUZ_Client_fnc_spawnTextTiles", -2];
			};
		};
	} forEach viruz_NotificationTips;
};

currentDate = call compile ("real_date" callExtension "");
publicVariable "currentDate";

//VZgroup
currentInvites = [];
publicVariable "currentInvites";
"currentInvites" addPublicVariableEventHandler {publicVariable "currentInvites";};
//VZgroup end