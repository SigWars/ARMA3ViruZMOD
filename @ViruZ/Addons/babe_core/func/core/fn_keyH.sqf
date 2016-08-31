_count_mods = count (configfile >> "CfgModSettings");

_allmodkeys = [];

for "_i" from 0 to (_count_mods - 1) do
{
	_mod = configname ((configfile >> "CfgModSettings") select _i);

	_count_keys = count (configfile >> "CfgModSettings" >> _mod >> "keybinds");
	
	for "_k" from 0 to (_count_keys - 1) do
	{
		_modkeys = ((profilenamespace getvariable _mod + "_b" + (str (_k + 1))) select 0) select 1;
		_fnc = (getarray (configfile >> "CfgModSettings" >> _mod >> "keybinds" >> "b" + (str (_k + 1)))) select 2;
		
		_keyinfo = [_modkeys, _fnc];
		
		_allmodkeys pushback _keyinfo;
	};
};

_activemodkeys = [];

for "_i" from 0 to (count _allmodkeys)-1 do
{
	_keyset = (_allmodkeys select _i) select 0;
	_keyinfo = _allmodkeys select _i;
	
	_hits = [];
	
	for "_h" from 0 to (count _keyset)-1 do
	{
		_key = _keyset select _h;
		
		if (_key in babe_core_keysdown) then
		{
			_hits pushback _h;
		};
	};
	
	if (count _hits == count _keyset) then
	{
		_activemodkeys pushback _keyinfo;
	};
};

_combos = [];
for "_i" from 0 to (count _activemodkeys)-1 do
{
	_combo = (_activemodkeys select _i) select 0;
	_keyinfo = _activemodkeys select _i;
	if (_i == 0) then
	{
		_combos pushback _keyinfo;
	} else
	{
		if (count _combo > count ((_combos select 0) select 0)) then
		{
			_combos set [0, _keyinfo];
		};
	};
};


_biggestcombo = _combos select 0;
_keys = _biggestcombo select 0;
_fnc = _biggestcombo select 1;

for "_i" from 0 to (count _keys)-1 do
{
	_key = _keys select _i;
	
	babe_core_keysdown deleteAt (babe_core_keysdown find _key);
};


call compile (format ["call %1", _fnc]);

//systemchat str _biggestcombo;








