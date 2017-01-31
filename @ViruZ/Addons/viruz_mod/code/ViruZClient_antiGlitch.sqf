/*
    File: ViruZClient_antiGlitch.sqf
    Atuthor: Leonardo "SigWar" Pinheiro
	
	Licence: 
	ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
	
    Description:
	Checks nearby builds and disable glitch movements if not owner or not in group of object owner.
*/

	if (isDedicated) exitWith {diag_log "Ignore antiglitch script in Dedicated Server";};
	ehremoved = false;
	
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
			
			_savedGroup = player getVariable ["ClanID","0"];
			_permission = player getVariable ["LvL",0];	
			if ((_savedGroup isEqualto _ownerUid) and (_permission > 0)) then {_sameGroup = true;}else{_sameGroup = false;};
		
		
			//Activate if not owner or in same group
			if ( !_sameGroup && (_mover != _ownerUid) ) then {
				viruz_glitchArea = 1;
			}
			else
			{
				viruz_glitchArea = -1;
			};
			
			if (vehicle player == player) then {
				if ((viruz_glitchArea > 0) and ( _playerState in _blockedAnims)) then {
					player switchMove "ActsPercMrunSlowWrflDf_FlipFlopPara";
				};
			};			
			
			if ( viruz_glitchArea > 0 && !ehremoved )then{
				(findDisplay 46) displayRemoveEventHandler ["KeyDown", babe_core_keyhandlerDown];
				(findDisplay 46) displayRemoveEventHandler ["KeyUp", babe_core_keyhandlerUp];
				ehremoved = true;
			};
			
			if (viruz_glitchArea < 1 && ehremoved)then{
				babe_core_keyhandlerDown = (findDisplay 46) displayaddEventHandler ["KeyDown", "_test = [_this, 'KeyDown'] call babe_core_fnc_keys; if _test then {true}"];
				babe_core_keyhandlerUp = (findDisplay 46) displayaddEventHandler ["KeyUp", "_test = [_this, 'KeyUp'] call babe_core_fnc_keys; if _test then {true}"];
				ehremoved = false;
			};
			
		} else {
			if (viruz_glitchArea > 0) then {
				viruz_glitchArea = -1;
				babe_core_keyhandlerDown = (findDisplay 46) displayaddEventHandler ["KeyDown", "_test = [_this, 'KeyDown'] call babe_core_fnc_keys; if _test then {true}"];
				babe_core_keyhandlerUp = (findDisplay 46) displayaddEventHandler ["KeyUp", "_test = [_this, 'KeyUp'] call babe_core_fnc_keys; if _test then {true}"];
				ehremoved = false;
			};
		};
		sleep 0.5;
	};
