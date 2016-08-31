private ["_pos","_surface"];
r_interrupt = false;
while {vzautoRun > 0} do {
	_surface = surfaceisWater position player;
	sleep 0.05;
	if (_surface or r_interrupt or (player getVariable["combattimeout", 0] >= time) ) then {r_interrupt = false; vzautoRun = -1; player switchmove ""; hintSilent "Cant run in water or in combat!";	
	} else {
		player playAction "FastF";
	};
};