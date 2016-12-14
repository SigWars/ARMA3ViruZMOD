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
					_textbackpack = format ["Backpack Dupe Detected!, added to log: Player name %1",(name _x)];
					"_textbackpack" remoteExec ["sideChat"];
					removeBackpack player;
				};
				if(_vest==_vest_x)then{
					_textvest = format ["Vest Dupe Detected!, added to log: Player name %1",(name _x)];
					"_textvest" remoteExec ["sideChat"];
					removeVest player;
				};
				if(_uniform==_uniform_x)then{
					//hint format ["Dupe Detected!, added to log: Player name %1 ",(name _x)];
					_textuniform = format ["Uniform Dupe Detected!, added to log: Player name %1",(name _x)];
					"_textuniform" remoteExec ["sideChat"];
					removeUniform player;
				};
				
			};
		} forEach nearestObjects [player, ["Survivor2_DZ"], 10];
		sleep 1;
	};
}; 