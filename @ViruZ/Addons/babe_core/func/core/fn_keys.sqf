_pars = _this select 0;
_mode = _this select 1;


_display = _pars select 0;
_key = _pars select 1;
_shift = _pars select 2;
_ctrl = _pars select 3;
_alt = _pars select 4;

switch _mode do
{
	case "KeyDown":
	{
		babe_core_keyhandler = true;

		if !(_key in babe_core_keysdown) then
		{
			babe_core_keysdown pushback _key;
		};
	};
	case "KeyUp":
	{
		babe_core_keyhandler = false;

		if (_key in babe_core_keysdown) then 
		{
			babe_core_keysdown deleteAt (babe_core_keysdown find _key);
		};
	};
};

_count_mods = count (configfile >> "CfgModSettings");

_allmodkeys = [];

_blockVanilla = false;

for "_i" from 0 to (_count_mods - 1) do
{
	_mod = configname ((configfile >> "CfgModSettings") select _i);

	_count_keys = count (configfile >> "CfgModSettings" >> _mod >> "keybinds");
	
	for "_k" from 0 to (_count_keys - 1) do
	{
		_modkeys = ((profilenamespace getvariable _mod + "_b" + (str (_k + 1))) select 0) select 1;
		
		if ({_x in babe_core_keysdown} count _modkeys == count _modkeys) then
		{
			_blockVanilla = true;
		};
	};
};
if (_key == 1) then
{
	_blockVanilla = false;
};
false

