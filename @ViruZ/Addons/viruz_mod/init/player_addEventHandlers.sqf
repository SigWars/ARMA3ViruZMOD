/*
	Author: SigWar
	Add player eventHandles called by playerMonitor on process login
*/
private ["_ehglitch"];
_ehglitch = player addEventHandler ["GetOutMan",{ _this call VIRUZ_getOutVehicle; } ];
/*
player addEventHandler ["take", 
	{
		
		_Object = cursorTarget;		
		if (_Object isKindOf "Maniken_Base") then {
			[(_Object call maniken_gearSync),"maniken_gearSyncMP"] spawn BIS_fnc_MP;
		};
	
	}];
*/