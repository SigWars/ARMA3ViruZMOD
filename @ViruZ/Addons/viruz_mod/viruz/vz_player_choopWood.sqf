/*********************
ViruZ Mod for Arma 3
Autor: SigWar
**********************/
private["_currentPos", "_object", "_type", "_objects", "_sel_object"]; 

_currentPos = player modelToWorld[0, 5, 0];
if !(surfaceIsWater _currentPos) then {
    _currentPos = ATLtoASL _currentPos;
};

//_objects = lineIntersectsObjs[eyePos player, _currentPos, player, objNull, true, 2];
_objects = lineIntersectsObjs [ATLToASL positionCameraToWorld [0,0,0], ATLToASL positionCameraToWorld[0,0,5], objNull, objNull, true, 32];
_object  = objNull;
_type    = "";
_item = "";
_texto = "";
_spawnRoll = random 1;
_maxQty = 1;
_spawnChance = 0; 
_quantidade = 0;

//chances
_spawnChanceWood = getNumber (missionConfigFile >> worldname >> "spawnChanceWood");
_maxQtyWood = getNumber (missionConfigFile >> worldname >> "maxQtyWood");
_spawnChanceCinder = getNumber (missionConfigFile >> worldname >> "spawnChanceCinder");
_maxQtyCinder = getNumber (missionConfigFile >> worldname >> "maxQtyCinder");

//Objects List
_treesLootList = getArray(missionConfigFile >> worldname >> "Trees");
_CinderLootList = getArray(missionConfigFile >> worldname >> "Cinder");
_WrecksLootList = getArray(missionConfigFile >> worldname >> "Wrecks");
_RocksLootList = getArray(missionConfigFile >> worldname >> "Rocks");
{
    _strObj = str _x;
	_sel_object = _x;	
	_findStart = _strObj find ": ";
	if (_findStart != -1) then{
		_p3dName = _strObj select[_findStart + 2, 999];
		if (_p3dName in _treesLootList) then{
			_type = "Trees";
			_object = _sel_object;
			_maxQty = _maxQtyWood;
			_spawnChance = _spawnChanceWood;
		};
		if (_p3dName in _CinderLootList) then{
			_type = "Cinder";
			_object = _sel_object;
			_maxQty = _maxQtyCinder;
			_spawnChance = _spawnChanceCinder;
		};
		if (_p3dName in _WrecksLootList) then{
			_type = "Wrecks";
			_object = _sel_object;
			_maxQty = 1;
			_spawnChance = _spawnChanceCinder;
		};
		if (_p3dName in _RocksLootList) then{
			_type = "Rocks";
			_object = _sel_object;
			_maxQty = _maxQtyCinder;
			_spawnChance = _spawnChanceCinder;
		};
	};
    if !(isNull _object) exitWith {};
}foreach _objects;

if (!isNull _object) then {
    if (alive _object) then {
     
		if (_spawnRoll <= _spawnChance) then {
			
		[player,60,false,(getPosATL player)] spawn player_alertZombies;
			
			switch (_type) do {
				case "Trees": { _item = "PartWoodPile"; _object setDamage 1; };
				case "Cinder": { _item = "ViruZ_Cinderblock";};
				case "Wrecks": { _item = "PartGeneric"; };
				case "Rocks": { _item = "ViruZ_Cinderblock"; };
				};
				
			//_quantidade = floor(random _maxQty);
			_quantidade = floor(random (_maxQty) +1);
			_nearByPile= nearestObjects [getPosATL player, ["GroundWeaponHolder"],2];
				if (count _nearByPile == 0) then { 
						_itemOut = createVehicle ["GroundWeaponHolder", getPosATL player, [], 1, "CAN_COLLIDE"];
						if ( isClass (configFile >> "CfgWeapons" >> _item)) then {
						    _itemOut addWeaponCargoGlobal [_item,_quantidade];
						};
						if ( isClass (configFile >> "CfgMagazines" >> _item)) then {
							_itemOut addMagazineCargoGlobal [_item,_quantidade];
						};
						player reveal _itemOut;
				}else{
						_itemOut = _nearByPile select 0;
						if ( isClass (configFile >> "CfgWeapons" >> _item)) then {
						    _itemOut addWeaponCargoGlobal [_item,_quantidade];
						};
						if ( isClass (configFile >> "CfgMagazines" >> _item)) then {
							_itemOut addMagazineCargoGlobal [_item,_quantidade];
						};
						player reveal _itemOut;						
				};
		};
	};
};