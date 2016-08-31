_turnValue = _this select 0;
_dir = VIRUZ_Build_object getVariable "viruz_build_objectDir";
_dir = _dir + _turnValue;
if(_dir >= 360) then {_dir = _dir - 360;};
if(_dir < 0) then {_dir = _dir + 360;};
//VIRUZ_Build_object setDir _dir;
VIRUZ_Build_object setVariable ["viruz_build_objectDir",_dir,true];