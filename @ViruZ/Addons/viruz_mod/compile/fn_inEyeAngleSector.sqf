/*
	Author: SteelRat
	Modified by SigWAr:
	
	Returns true if <position> lies within the sector eye defined by <center position>,
	<center angle of sector> and <sector width>. Use this function to determine if
	a position lies within a certain angle from another position (ie the <center position>).
	
	Example:
	[player, targetObject, 30] call BIS_fnc_inEyeAngleSector
	will return true if the vehicle named targetObject is within 30 degrees of where the eye player is pointing.
*/

params[
	"_spotter",
	"_target",
	"_angle"
];

_eyePos = eyePos _spotter;
_eyePos set [2, 0];
_eyeDir = eyeDirection _spotter;

_eyePos_2 = [
	(_eyePos select 0) + (_eyeDir select 0),
	(_eyePos select 1) + (_eyeDir select 1),
	0
];

[
	_eyePos,
	[_eyePos, _eyePos_2] call BIS_fnc_dirTo,
	_angle,
	position _target
] call BIS_fnc_inAngleSector