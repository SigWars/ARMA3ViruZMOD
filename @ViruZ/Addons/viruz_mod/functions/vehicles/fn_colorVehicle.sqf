private ["_vehicle","_colors","_colorCode","_colorCodeArray"];

_vehicle = [_this, 0, objNull, [objNull]] call BIS_fnc_param;
_colors = [_this, 1, ["BLACK"], [[]]] call BIS_fnc_param;
_colorCodeArray = [];

{
    _colorCode = switch toUpper(_x) do {
        case "TAN": {"#(argb,8,8,3)color(0.8,0.7,0.5,0.2)"};
        case "BLACK": {"#(argb,8,8,3)color(0,0,0,0.6)"};
        case "PINK": {"#(argb,8,8,3)color(1,0.75,0.84,0.2)"};
    };
	_colorCodeArray SET [count _colorCodeArray, _colorCode];
} forEach _colors;

{
	_vehicle setObjectTexture [_foreachIndex,_x];
} forEach _colorCodeArray;