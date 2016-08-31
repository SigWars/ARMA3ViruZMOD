/*
	Author: SigWar
*/

private["_inventory","_Uniform","_Vest","_Headgear","_Goggles","_Object"];

_inventory = _this select 0;
_Object = _this select 1;

if (count _inventory > 0) then {

	_Uniform =		_inventory select 0;
	_Vest =			_inventory select 1;
//	_Headgear =		_inventory select 2;
//	_Goggles =		_inventory select 3;

	if (_Uniform != "") then {
		if (uniform _Object != _Uniform) then {
			_Object addUniform _Uniform;
		};
	} else {
		if (uniform _Object != "") then {
			removeUniform _Object;
		};
	};

	if (_Vest != "") then {
		if (vest _Object != _Vest) then {
			_Object addVest _Vest;
		};
	} else {
		if (vest _Object != "") then {
			removeVest _Object;
		};
	};
/*
	if (_Headgear != "") then {
		if (Headgear _Object != _Headgear) then {
			_Object addHeadgear _Headgear;
		};
	} else {
		if (Headgear _Object != "") then {
			removeHeadgear _Object;
		};
	};
	
	if (_Goggles != "") then {
		if (goggles _Object != _Goggles) then {
			_Object addGoggles _Goggles;
		};
	} else {
		if (goggles _Object != "") then {
			removeGoggles _Object;
		};
	};
*/
};