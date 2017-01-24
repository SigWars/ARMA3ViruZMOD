/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_display","_btnRespawn","_btnAbort","_timeOut","_timeMax"];
		disableSerialization;
		_display = findDisplay 49;
		
		//Wait for Esc menu
		waitUntil {
			!isNull _display;
		};
		
		//Close inventory if open, antidupe
		_null = [] spawn { 
				disableSerialization;
				while {!isnull (findDisplay 49)} do {
					closeDialog 602;
					sleep 0.5;	
				};
		};
		
		_btnRespawn = _display displayCtrl 1010;
		_btnAbort = _display displayCtrl 20004;
		_btnRespawn ctrlEnable true;
		_btnAbort ctrlEnable true;
		_timeOut = 0;
		_timeMax = 30;
		
		if(missionNamespace getVariable "r_player_dead") exitWith {_btnAbort ctrlEnable true};
		if(missionNamespace getVariable "r_fracture_legs") exitWith {_btnRespawn ctrlEnable true; _btnAbort ctrlEnable true};
		
		while {!isNull _display} do {
			switch true do {
				case ({isPlayer _x} count (player nearEntities ["AllVehicles", 6]) > 1) : {
					_btnAbort ctrlEnable false;
					_btnRespawn ctrlEnable false;
					cutText [format[localize "str_abort_playerclose"], "PLAIN DOWN"];
				};
				case (_timeOut < _timeMax && count (player nearEntities ["zZombie_Base", 35]) > 0) : {
					_btnAbort ctrlEnable false;
					_btnRespawn ctrlEnable false;
					cutText [format["Can Abort in %1", (_timeMax - _timeOut)], "PLAIN DOWN"];
				};
				case (player getVariable["combattimeout", 0] >= time) : {
					_btnAbort ctrlEnable false;
					_btnRespawn ctrlEnable false;
					cutText [format[localize "str_abort_playerincombat"], "PLAIN DOWN"];					
				};
				default {
					_btnAbort ctrlEnable true;
					_btnRespawn ctrlEnable true;
					cutText ["", "PLAIN DOWN"];				
				};
			};
			sleep 1;
			_timeOut = _timeOut + 1;
		};
		cutText ["", "PLAIN DOWN"];