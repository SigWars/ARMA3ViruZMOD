_ctrl = _this select 0;

lnbClear _ctrl;

_mds = []; 
_mods = configFile >> "CfgModSettings";         

for "_i" from 0 to ((count _mods)-1) do      
{      
    
_base = inheritsFrom (configFile >> "CfgModsettings" >> str (_mods select _i));          
_mds = _mds + [configname (_mods select _i)];  
     
}; 

_rws = 0;


for "_i" from 0 to ((count _mds)-1) do      
{

	_mod = _mds select _i;


	_name = gettext (configfile >> "cfgmodsettings" >> _mod >> "name"); 
	
	_countsets = count (configfile >> "CfgModSettings" >> _mod >> "settings");
	
	_countkeys = count (configfile >> "CfgModSettings" >> _mod >> "keybinds");



	_ctrl lnbAddRow [_name, ""];

	_ctrl lnbSetValue [[_rws, 0], 2];

	_ctrl lnbSetData [[_rws, 0], _mod];


	_rgb = [(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69]), (profilenamespace getvariable ['GUI_BCG_RGB_G',0.75]), (profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])];

	_ctrl lnbSetColor [[_rws, 0], [_rgb select 0, _rgb select 1, _rgb select 2, 1]];

	if (_countkeys > 0) then
	{
		_rws = _rws + 1;

		_ctrl lnbAddRow ["Keys", ""];

		_ctrl lnbSetValue [[_rws, 0], 3];

		_ctrl lnbSetData [[_rws, 0], _mod];
	};

	
	if (_countsets > 0) then
	{
		_rws = _rws + 1;

		_ctrl lnbAddRow ["Settings", ""];

		_ctrl lnbSetValue [[_rws, 0], 3];

		_ctrl lnbSetData [[_rws, 0], _mod];
	};
	
	_rws = _rws + 1;

};




