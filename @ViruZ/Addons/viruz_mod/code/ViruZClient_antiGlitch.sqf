/*
VIRUZ MOD ARMA 3 
ViruZClient_antiGlitch.sqf by SigWAr
Checks nearby builds and disable glitch movements if not owner or not in group of object owner.
*/
	if (isDedicated) exitWith {diag_log "Ignore antiglitch script in Dedicated Server";};
	
	private ["_sameGroup","_position","_walls","_wallsCount","_ownerUid","_mover","_wallOwner","_animation","_blockedAnims"];
	
	disableSerialization;
	waituntil {(!IsNull player) && (!isNull findDisplay 46 && !IsNil "babe_core_keyhandlerDown")};
	_blockedAnims = [	"amovppnemstpsraswrfldnon",
						//"amovppnemsprslowwrfldf",
						"amovppnemevaslowwrfldf",
						"amovppnemrunsnonwnondf",
						"amovppnemrunsnonwnondr",
						"amovppnemrunsnonwnondb",
						"amovppnemstpsnonwnondnon",
						//"amovppnemstpsraswrfldnon",
						"amovppnemrunslowwrfldf",
						"amovppnemrunslowwrfldl",
						"amovppnemrunslowwrfldr",
						"amovppnemrunslowwrfldb",
						"amovppnemsprslowwrfldl",
						//"amovppnemevaslowwrfldf",
						"amovppnemsprslowwrfldr",
						"amovppnemsprslowwrfldb",
						"amovppnemsprslowwrfldfr",
						"amovppnemsprslowwrfldfl",
						"amovppnemsprslowwrfldbl",
						"amovppnemsprslowwrfldbr",
						"amovppnemrunslowwrfldfl",
						"amovppnemrunslowwrfldbl",
						"amovppnemrunslowwrfldbr",
						"amovppnemsprslowwrfldf"
					];
	
	while {true} do {
		
		_sameGroup = false;
		_position = getPosATL player;
		_walls = nearestObjects [_position, VIRUZ_GATES+VIRUZ_WALLS, 8];
		_wallsCount = count _walls;
		_playerState = animationState player;
		
		if (_wallsCount > 0 ) then {
			
			_wallOwner = _walls select 0;
			_ownerUid =  _wallOwner getVariable ["OwnerUID","0"];
			_mover = getPlayerUID player;
			
			_savedGroup = profileNamespace getVariable["savedGroup",[]];
			if (count _savedGroup > 1) then {
						
				if (_ownerUid in _savedGroup && _mover in _savedGroup ) then {
					_sameGroup = true;
					viruz_glitchArea = -1;
				};
					
			};
		};
		
		//Activate if walls count > 0;
		if (_wallsCount > 0) then {
		
			if (vehicle player == player) then {
				if ((viruz_glitchArea > 0) and ( _playerState in _blockedAnims)) then {
					player switchMove "ActsPercMrunSlowWrflDf_FlipFlopPara";
				};
			};
	
			//Activate if not owner or in same group
			if ( !_sameGroup && (viruz_glitchArea < 1) && (_mover != _ownerUid) ) then {
					viruz_glitchArea = 1;
					(findDisplay 46) displayRemoveEventHandler ["KeyDown", babe_core_keyhandlerDown];
					(findDisplay 46) displayRemoveEventHandler ["KeyUp", babe_core_keyhandlerUp];
					//hint "ANTI GLITCH ENABLED";
			};
			
			//check if in group and habilite area again
			if (_sameGroup && viruz_glitchArea > 0) then {
				viruz_glitchArea = -1;
				babe_core_keyhandlerDown = (findDisplay 46) displayaddEventHandler ["KeyDown", "_test = [_this, 'KeyDown'] call babe_core_fnc_keys; if _test then {true}"];
				babe_core_keyhandlerUp = (findDisplay 46) displayaddEventHandler ["KeyUp", "_test = [_this, 'KeyUp'] call babe_core_fnc_keys; if _test then {true}"];
			};
			
		} else {
			if (viruz_glitchArea > 0) then {
				viruz_glitchArea = -1;
				babe_core_keyhandlerDown = (findDisplay 46) displayaddEventHandler ["KeyDown", "_test = [_this, 'KeyDown'] call babe_core_fnc_keys; if _test then {true}"];
				babe_core_keyhandlerUp = (findDisplay 46) displayaddEventHandler ["KeyUp", "_test = [_this, 'KeyUp'] call babe_core_fnc_keys; if _test then {true}"];
				//hint "ANTI GLITCH DISABLED";
			};
		};
		sleep 0.5;
	};
