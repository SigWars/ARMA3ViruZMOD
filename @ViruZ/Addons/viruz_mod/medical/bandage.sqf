/*****************************************
	ViruZ Mod
	Bandage Script by SigWar
*****************************************/
_unit = (_this select 3) select 0;

_dis=6;
_sfx = "bandage";
[player,_sfx,0,false,_dis] call viruz_zombieSpeak;

player removeMagazine "ItemBandage";

call fnc_usec_medic_removeActions;
r_action = false;

if (vehicle player == player) then {
	//not in a vehicle
	player playActionNow "Medic";
};

_isOk = true;

while {_isOk} do {

		sleep 3; // Esperando pela animação

		[player,"bandage",0,false] call viruz_zombieSpeak;

		usecBandage = [_unit,player];
		publicVariable "usecBandage";
		
		if (_unit == player) then {
			//Self Healing
			_id = [player,player] execVM "\z\addons\viruz_mod\medical\publicEH\medBandaged.sqf";
			viruz_sourceBleeding =	objNull;
		} else {
			[player,20] call player_humanityChange;
		};

		{_unit setVariable[_x,false,true];} forEach USEC_woundHit;
		_unit setVariable ["USEC_injured",false,true];
		
		player playActionNow 'stop';
		_isOk = false;
	};