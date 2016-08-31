_key = _this select 1;

if (EM_input_pls) then
{
	if !(_key in babe_core_modmenu_keysdown) then 
	{
		babe_core_modmenu_keysdown pushback _key;
	};

	_pressedkeys = babe_core_modmenu_keysdown;

	
	_mod = uinamespace getvariable "cur_mod";

	_cur = uinamespace getvariable "cur_bind";


	_bind_change = profilenamespace getvariable (_mod+"_b"+(str _cur));

	_keyinfo = _bind_change select 0;

	_datatype = _bind_change select 1;

	_txt = _keyinfo select 0;
	
	_txt = _keyinfo select 0;
	

	profilenamespace setvariable [(_mod+"_b"+(str _cur)), [[1, _pressedkeys], _datatype]];

};
