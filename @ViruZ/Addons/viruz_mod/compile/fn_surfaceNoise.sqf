/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_unit","_pos","_type","_typeA","_soundType","_soundVal","_array","_test"];
_unit = 	_this;
_pos = 		getPosATL _unit;
_type = 	surfaceType _pos;
_typeA = 	toArray _type;
_typeA 		set [0,"DEL"];
_typeA = 	_typeA - ["DEL"];
_type = 	toString _typeA;
_test = 	0;

//diag_log ("FINDME: " + _type);

_soundType = 	getText (configFile >> "CfgSurfaces" >> _type >> "soundEnviron");
_soundValCount = [((getArray (configFile >> "CfgVehicles" >> "CAManBase" >> "SoundEnvironExt" >> _soundType) select 0) select 1)];

if (count _soundValCount > 2) then {
	_soundVal =	parseNumber format["%1",(((getArray (configFile >> "CfgVehicles" >> "CAManBase" >> "SoundEnvironExt" >> _soundType) select 0) select 1) select 3)];
	} else {
		_soundVal = 25;
};

/*if (_soundVal == 0) then {
	_soundVal = 25;
};*/

_array = [_soundType,_soundVal];
_array