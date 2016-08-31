_ctrl = _this select 0;
_mod = _this select 1;

lnbClear _ctrl;

_sets = configFile >> "CfgModSettings" >> _mod >> "Settings";

_settings = [];


for "_i" from 0 to ((count _sets)-1) do 
{

  _base = inheritsFrom (configFile >> "CfgModSettings" >> str (_sets select _i));

  _settings = _settings + [configname (_settings select _i)];

};



_ctrl lnbAddRow ["Back",""];

_ctrl lnbSetValue [[0,0],3];

_in = 1;

{

  _varname = _mod+"_s"+(str _in);

  _sx = profilenamespace getVariable _varname;

  _setinfo = _sx select 0;
  _datatype = _sx select 1;

  _txt = getarray (configFile >> "CfgModSettings" >> _mod >> "settings" >> "s"+(str _in));  //_txt = _setinfo select 0;
  _set = _setinfo select 1;

  if (_set == 1) then {_set = "On"} else {_set = "Off"};

  _ctrl lnbAddRow [_txt select 0, _set];

  _ctrl lnbSetValue [[_in,0],_datatype];

  _in = _in + 1;

}foreach _settings;



