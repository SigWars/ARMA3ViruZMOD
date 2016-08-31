/*
	Created by SteelRat ( ProjectTeam )
	Editor: SigWar
*/

private ["_curWeapon","_curMagazine","_countAmmo","_flag"];

_flag = true;

While {_flag} do {

	_curWeapon = currentWeapon player;
	_curMagazine = currentMagazine player;

//	if (_curWeapon == "HandFlashlight") then {
		if !(str(handgunItems player) == str(["","",""])) then {
			if (player isFlashlightOn _curWeapon) then {
				if !(_curMagazine == "") then {
					_countAmmo = player ammo _curWeapon;
					if (_countAmmo <= 0) then {
						player action ["GunLightOff", player];
						titleCut [localize "str_flashlight_battery_isLow","Plain Down"];
						_flag = false;
					} else {
						
						player setAmmo [handgunWeapon player, (_countAmmo - 1)];
						
						// Chance destroy lamp
						if (floor (random 3000) == 0) then {
							playSound3D ["A3\Sounds_F\sfx\Beep_Target.wss", player, true, getPos player, 10, 1, 10];
							player removeHandgunItem "acc_lampflashlight";
							player action ["GunLightOff", player];
							titleCut [localize "str_flashlight_missingLamp","Plain Down"];
							_flag = false;
						};
					};
				} else {
					player action ["GunLightOff", player];
					titleCut [localize "str_flashlight_battery_no","Plain Down"];
					_flag = false;
				};
			} else {
				_flag = false;
			};
		} else {
			player action ["GunLightOff", player];
			titleCut [localize "str_flashlight_noLamp","Plain Down"];
			_flag = false;
		};
//	};
	
	sleep 1;

};