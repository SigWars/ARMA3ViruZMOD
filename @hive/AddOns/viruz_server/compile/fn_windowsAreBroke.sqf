private ["_radius","_objList","_windowObjList","_class","_pathWindow","_countWindow","_obj","_i"];

_radius = _this select 0;
_objList = (_this select 1) nearObjects ["House_F",_radius];
_windowObjList = [];

{
	_class = typeOf _x;
	_pathWindow = configFile >> "CfgVehicles" >> _class >> "numberOfWindows";
	_countWindow = getNumber _pathWindow;
	
	_windowObjList SET [count _windowObjList, [_x,_countWindow]];
	
} forEach _objList;

{
	_obj = _x select 0;
	if !(_obj getVariable ["checkWindow", false]) then {
		_countWindow = _x select 1;
		if (_countWindow != 0) then {
			_i = 0;
			while {_i < _countWindow} do {
				_i = _i + 1;
				_hitpoint = "Glass_" + (str _i) + "_hitpoint";
				_obj setHitPointDamage [_hitpoint,1];
			};
			_obj allowDamage false;
		};
		_obj setVariable ["checkWindow", true, true];
	};
} forEach _windowObjList;