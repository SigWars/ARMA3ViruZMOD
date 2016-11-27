[] spawn {
while {1 == 1} do {
		waitUntil {!isnull (findDisplay 602)};
		{
			if ((isPlayer _x && _x != player) && (alive _x)) then {
				_backpack=backpackContainer player;
				_backpack_x=backpackContainer _x;
			
				if(_backpack==_backpack_x)then{
					hint format ["Dupe Detected!, added to log: Player name %1 ",(name _x)];
					removeBackpack player;
				};
			};
		} forEach nearestObjects [player, ["Survivor2_DZ"], 10];
		sleep 1;
	};
}; 