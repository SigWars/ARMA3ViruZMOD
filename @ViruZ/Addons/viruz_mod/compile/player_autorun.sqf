private ["_surface"];
r_interrupt = false;
viruz_Holster = currentweapon player;

if ((animationState player) != "amovpercmstpsnonwnondnon") then {
player action["switchWeapon", player, player, 100];

waitUntil {	((animationState player) == "amovpercmstpsnonwnondnon");};
};

while {vzautoRun > 0} do {
	_surface = surfaceisWater position player;
	sleep 0.05;
	if (_surface) then {
			r_interrupt = false; vzautoRun = -1; player switchmove ""; player selectWeapon viruz_Holster; hintSilent "Cant run in water!"; 	
		} else {
			if (r_interrupt) then {
					r_interrupt = false; vzautoRun = -1; player switchmove ""; player selectWeapon viruz_Holster; //hintSilent "Autorun finished!"; 
				} else {
					if ((player getVariable["combattimeout", 0] >= time)) then {
						r_interrupt = false; vzautoRun = -1; player switchmove ""; player selectWeapon viruz_Holster; hintSilent "Cant run in combat!"; 
					} else {
					player playActionNow "FastF";
				};
			};	
		};	
			
};	
	
