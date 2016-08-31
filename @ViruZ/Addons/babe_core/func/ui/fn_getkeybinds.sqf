_ctrl = _this select 0;
_mod = _this select 1;

lnbClear _ctrl;

_binds = configFile >> "CfgModSettings" >> _mod >> "Keybinds";

_keybinds = [];


for "_i" from 0 to ((count _binds)-1) do 
{

  _base = inheritsFrom (configFile >> "CfgModSettings" >> str (_binds select _i));

  _keybinds = _keybinds + [configname (_keybinds select _i)];

};



_ctrl lnbAddRow ["Back",""];

_ctrl lnbSetValue [[0,0],3];

_in = 1;

{

	_varname = _mod+"_b"+(str _in);

	_bx = profilenamespace getVariable _varname;

	_keyinfo = _bx select 0;
	_datatype = _bx select 1;

	_txt = getarray (configFile >> "CfgModSettings" >> _mod >> "keybinds" >> "b"+(str _in));
	_keys = _keyinfo select 1;

	_keystr = "";
	
	for "_i" from 0 to (count _keys)-1 do
	{
		_key = _keys select _i;
		
		_str = (keyname _key);
		
		_str = toArray _str;
		
		_str resize (count _str)-1;
		
		reverse _str;
		
		_str resize (count _str)-1;
		
		reverse _str;
		
		_str = toString _str;
		
		if (_i != 0) then
		{
			_str = "+" + _str;
		};
		
		_keystr = _keystr + _str;
	};

	
	_ctrl lnbAddRow [_txt select 0,_keystr];

	_ctrl lnbSetValue [[_in,0],_datatype];

	_in = _in + 1;

}foreach _keybinds;