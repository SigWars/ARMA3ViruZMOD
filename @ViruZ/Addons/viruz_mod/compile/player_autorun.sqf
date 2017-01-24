/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private ["_surface"];
r_interrupt = false;
viruz_Holster = currentweapon player;
(findDisplay 46) displayRemoveEventHandler ["KeyDown", babe_core_keyhandlerDown];
(findDisplay 46) displayRemoveEventHandler ["KeyUp", babe_core_keyhandlerUp];
ehremoved = true;

if ((animationState player) != "amovpercmstpsnonwnondnon") then {
player action["switchWeapon", player, player, 100];

waitUntil {	((animationState player) == "amovpercmstpsnonwnondnon");};
};

while {vzautoRun > 0} do 
{
	_surface = surfaceisWater position player;
		
	if (viruz_glitchArea > 0) then {
		r_interrupt = false; 
		vzautoRun = -1;
		player switchmove "";
		player selectWeapon viruz_Holster;
		hintSilent "Cant run here!";
	};
	
	if (_surface) then
		{
			r_interrupt = false; 
			vzautoRun = -1;
			player switchmove "";
			player selectWeapon viruz_Holster;
			babe_core_keyhandlerDown = (findDisplay 46) displayaddEventHandler ["KeyDown", "_test = [_this, 'KeyDown'] call babe_core_fnc_keys; if _test then {true}"];
			babe_core_keyhandlerUp = (findDisplay 46) displayaddEventHandler ["KeyUp", "_test = [_this, 'KeyUp'] call babe_core_fnc_keys; if _test then {true}"];
			ehremoved = false;
			hintSilent "Cant run in water!";
		}else
		{
			if (r_interrupt) then 
				{
					r_interrupt = false;
					vzautoRun = -1; 
					player switchmove "";
					player selectWeapon viruz_Holster;
					babe_core_keyhandlerDown = (findDisplay 46) displayaddEventHandler ["KeyDown", "_test = [_this, 'KeyDown'] call babe_core_fnc_keys; if _test then {true}"];
					babe_core_keyhandlerUp = (findDisplay 46) displayaddEventHandler ["KeyUp", "_test = [_this, 'KeyUp'] call babe_core_fnc_keys; if _test then {true}"];
					ehremoved = false;
				} else
				{
					if ((player getVariable["combattimeout", 0] >= time)) then 
					{
						r_interrupt = false;
						vzautoRun = -1;
						player switchmove "";
						player selectWeapon viruz_Holster;
						babe_core_keyhandlerDown = (findDisplay 46) displayaddEventHandler ["KeyDown", "_test = [_this, 'KeyDown'] call babe_core_fnc_keys; if _test then {true}"];
						babe_core_keyhandlerUp = (findDisplay 46) displayaddEventHandler ["KeyUp", "_test = [_this, 'KeyUp'] call babe_core_fnc_keys; if _test then {true}"];
						ehremoved = false;
						hintSilent "Cant run in combat!"; 
					}
					else
					{
						player playActionNow "FastF";
					};
				};	
		};
	uiSleep  0.05;
};	
	
