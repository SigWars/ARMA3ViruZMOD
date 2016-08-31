/*
	Author: SteelRat ( ProjectTeam )
*/

/*
player addEventHandler ["take", 
	{
		
		_Object = cursorTarget;		
		if (_Object isKindOf "Maniken_Base") then {
			[(_Object call maniken_gearSync),"maniken_gearSyncMP"] spawn BIS_fnc_MP;
		};
	
	}];
*/