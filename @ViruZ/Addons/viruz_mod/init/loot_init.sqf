private["_cfgCount","_config","_i","_itemChances","_itemCount","_weighted","_j","_weight","_l","_k","_type","_canZombie","_canLoot"];
viruz_CBLChances = [];
viruz_CBLBase = [];

_config = missionConfigfile >> "CfgBuildingLoot";
for "_i" from 0 to ((count _config) - 1) do {
	_classname = configName (_config select _i);
	_itemChances = [] + getArray (_config >> _classname >> "ItemChance");
	_itemCount = count _itemChances;
	if (_itemCount > 0) then {
		if (viruz_CBLBase find _classname < 0) then {
			_weighted = [];
			_j = 0;
			for "_l" from 0 to ((count _itemChances) - 1) do {
			_weight = round ((_itemChances select _l) * 100);
				for "_k" from 0 to _weight - 1 do {
					_weighted set [_j + _k, _l];
				};
			_j = _j + _weight;
			};
		viruz_CBLChances set [count viruz_CBLChances, _weighted];
		viruz_CBLBase set [count viruz_CBLBase, _classname];
		} ;
	} else {
		viruz_CBLChances set [count viruz_CBLChances, [0]];
		viruz_CBLBase set [count viruz_CBLBase, _classname];
	};
};

viruz_CLChances = [];
viruz_CLBase = [];
_config = missionConfigfile >> "cfgLoot";
for "_i" from 0 to ((count (_config)) - 1) do {
	_itemChances = (getArray (_config select _i)) select 1;
	_weighted = [];
	_j = 0;
	for "_l" from 0 to ((count _itemChances) - 1) do {
		_weight = round ((_itemChances select _l) * 100);
		for "_k" from 0 to _weight - 1 do {
			_weighted set [_j + _k, _l];
		};
		_j = _j + _weight;
	};
	viruz_CLBase set [count viruz_CLBase, configName (_config select _i)]; //classes da cfgLoot
	viruz_CLChances set [count viruz_CLChances, _weighted];		//Chance de Spawn 
};

private["_i","_type","_config","_canZombie","_canLoot"];
viruz_ZombieBuildings = [];
viruz_LootBuildings = [];
for "_i" from 0 to (count (missionConfigfile >> "CfgBuildingLoot") - 1) do {
	_type = (missionConfigfile >> "CfgBuildingLoot") select _i;
	_canZombie = 	getNumber (_type >> "zombieChance") > 0;
	_canLoot = 		getNumber (_type >> "lootChance") > 0;
	if(_canZombie) then {
		if(!((configName _type) in viruz_ZombieBuildings)) then {
			viruz_ZombieBuildings set [count viruz_ZombieBuildings, configName _type];
		};
	};
	if(_canLoot) then {
		if(!((configName _type) in viruz_LootBuildings)) then {
			viruz_LootBuildings set [count viruz_LootBuildings, configName _type];
		};
	};
};