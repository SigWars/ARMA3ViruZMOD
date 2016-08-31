_distanceValue = _this select 0;
_distance = VIRUZ_Build_object getVariable "viruz_build_additionalDistance";
_distance = _distance + _distanceValue;
if(_distance < -1) then { _distance = -1; };
if(_distance > 5) then { _distance = 5; };
VIRUZ_Build_object setVariable ["viruz_build_additionalDistance",_distance,true];