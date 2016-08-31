private["_obj","_type","_OwnerUID","_config","_canLoot","_unitTypes","_min","_max","_num","_zombieChance","_rnd","_noPlayerNear","_position","_clean","_positions","_iPos","_nearBy","_nearByPlayer"];
_obj = _this select 0;
_type = 		typeOf _obj;
_OwnerUID = _obj getVariable ["OwnerUID","0"];
_config = 		missionConfigfile >> "CfgBuildingLoot" >> _type;
_canLoot = 		isClass (_config);

if (_OwnerUID == "0") then {

if (viruz_maxCurrentZeds > viruz_maxZeds) exitwith {};
if (viruz_CurrentZombies > viruz_maxGlobalZombies) exitwith {}; 
if (viruz_spawnZombies > viruz_maxLocalZombies) exitwith {}; 

if (_canLoot) then {
//Get zombie class
	_unitTypes = 	getArray (_config >> "zombieClass");
	_min = 			getNumber (_config >> "minRoaming");
	_max = 			getNumber (_config >> "maxRoaming");
//Walking Zombies
	//_num = round(random _max) min _min;
	_num = round(random _max) max _min;
	_config = 		missionConfigfile >> "CfgBuildingLoot" >> _type;
//Get zombie class
	_zombieChance =	getNumber (_config >> "zombieChance");
	_rnd = random 1;

	//if (_rnd < _zombieChance) then {
		
		_sizeObj = _obj call BIS_fnc_boundingCircle;
		_position = getPosATL _obj;
		_testPos = selectBestPlaces [_position, (_sizeObj * 1.5), "1 * (1 - houses) * (1 - sea)", 10, _num];
		//diag_log format["VIRUZ: selectBestPlaces : _obj (%1): _sizeObj (%2): _num (%3): _testPos (%4)", _obj, _sizeObj, _num, (count _testPos)];

		//for "_i" from 1 to _num do {
		for "_i" from 0 to (count _testPos) - 1 do {	
			_pos = _testPos select _i select 0;

			_noPlayerNear = {isPlayer _x} count (_pos nearEntities [["AllVehicles","CAManBase"], 30]) == 0;

			if (_noPlayerNear) then {
				[_pos, true, _unitTypes] spawn zombie_generate;
				sleep 1;
			};
		};
	//};

	
	//Add Internal Zombies
	_clean = {alive _x} count ((getPosATL _obj) nearEntities ["zZombie_Base",(sizeOf _type)]) == 0;
	if (_clean) then {
		_positions =	_obj call fnc_buildingPositions;
		_zombieChance =	getNumber (_config >> "zombieChance");
		//diag_log format["Building: %1 / Positions: %2 / Chance: %3",_type,_positions,_zombieChance];
		{
			_rnd = random 1;
			if (_rnd < _zombieChance) then {
				_iPos = _x;
				_nearBy = {alive _x} count nearestObjects [_iPos, ["zZombie_Base"],3] > 0;
				_nearByPlayer = ({isPlayer _x} count (_iPos nearEntities [["AllVehicles","CAManBase"],30])) > 0;
				//diag_log ("BUILDING: " + _type + " / " + str(_nearBy) + " / " + str(_nearByPlayer));
				if (!_nearByPlayer and !_nearBy) then {
					[_iPos, false, _unitTypes] spawn zombie_generate;
					sleep 1;
				};
			};
		} forEach _positions;
	};
	viruz_buildingMonitor set [count viruz_buildingMonitor,_obj];
};
};