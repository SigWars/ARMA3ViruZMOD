private["_body","_id","_position"];
_body = _this;
_position = getPosATL _body;
_id = [_position,0.1,1.5] call bis_fnc_flies;
//_id setVariable ["body",_body];
//viruz_flyMonitor set[count viruz_flyMonitor, _id];