_key = _this select 1;


_cur = uinamespace getvariable "cur_bind";

_mod = uinamespace getvariable "cur_mod";

_ctrl = (findDisplay 49) displayCtrl 212513;

_bind_change = profilenamespace getvariable (_mod+"_b"+(str _cur));

_keyinfo = _bind_change select 0;

_keys = _keyinfo select 1;

_datatype = _bind_change select 1;

_txt = _keyinfo select 0;

_txt = _keyinfo select 0;
	
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



_ctrl lnbSetText [[_cur,1], _keystr];

uinamespace setvariable ["cur_bind", nil];

EM_input_pls = false;
