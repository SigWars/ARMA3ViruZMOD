[] spawn {
while {1 == 1} do {
		waitUntil {!isnull (findDisplay 602)};
		
		{
			if ((isPlayer _x && _x != player) && (alive _x)) then {
				
				//BACKPACK
				_backpack=backpackContainer player;
				_backpack_x=backpackContainer _x;
				//VEST
				_vest=vestContainer player;
				_vest_x=vestContainer _x;
				//INIFORM
				_uniform=uniformContainer player;
				_uniform_x=uniformContainer _x;
			
				if(_backpack==_backpack_x)then{
					hint format ["Dupe Detected!, added to log: Player name %1 ",(name _x)];
					removeBackpack player;
					removeBackpack _x;
				};
				if(_vest==_vest_x)then{
					hint format ["Dupe Detected!, added to log: Player name %1 ",(name _x)];
					removeVest player;
					removeVest _x;
				};
				if(_uniform==_uniform_x)then{
					hint format ["Dupe Detected!, added to log: Player name %1 ",(name _x)];
					removeUniform player;
					removeUniform _x;
				};
				
				_holder = nearestObjects [player, ["GroundWeaponHolder"], 30];
				{
					if (count _holder > 0) then {
						_holderitems = everyContainer _x;
						if ((_backpack in _holderitems) or (_vest in _holderitems) or (_uniform in _holderitems)) then {
							deleteVehicle _x;
						};
					};
				} forEach _holder;	
				
			};
		} forEach nearestObjects [player, ["Survivor2_DZ"], 10];
		
		sleep 1;
	};
}; 