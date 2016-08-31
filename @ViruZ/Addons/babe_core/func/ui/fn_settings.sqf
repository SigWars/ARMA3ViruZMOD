_mod = _this;

_name = gettext (configFile >> "CfgModSettings" >> _mod >> "name");

_binds = configFile >> "CfgModSettings" >> _mod >> "Keybinds";

_sets = configFile >> "CfgModSettings" >> _mod >> "Settings";

_keybinds = [];

_settings = [];


for "_i" from 0 to ((count _binds)-1) do 
{

  _base = inheritsFrom (configFile >> "CfgModSettings" >> str (_binds select _i));

  _keybinds = _keybinds + [configname (_keybinds select _i)];

};

for "_i" from 0 to ((count _sets)-1) do 
{

  _base = inheritsFrom (configFile >> "CfgModSettings" >> str (_sets select _i));

  _settings = _settings + [configname (_settings select _i)];

};

_in = 1;

{

  _keyinfo = getArray (configFile >> "CfgModSettings" >> _mod >> "KeyBinds" >> "b"+(str _in));

  _varname = _mod+"_b"+(str _in);
  _bx = profilenamespace getVariable _varname;

  if (IsNil "_bx") then
  {
     profilenamespace setvariable [[_keyinfo, 0], 0];
  };
  
  if (typeName((_bx select 0) select 1) != "ARRAY") then
  {
	_bx = [[(_bx select 0) select 0, [(_bx select 0) select 1]], 0];
    profilenamespace setvariable [_varname, _bx];
  };
  
  _in = _in + 1;

} foreach _keybinds;

_in = 1;

{

  _setinfo = getArray (configFile >> "CfgModSettings" >> _mod >> "Settings" >> "s"+(str _in));

  _varname = _mod+"_s"+(str _in);
  _sx = profilenamespace getVariable _varname;

  if (IsNil "_sx") then
  {
     profilenamespace setvariable [_varname, [_setinfo, 1]];
  };
  
  _in = _in + 1;

} foreach _settings;