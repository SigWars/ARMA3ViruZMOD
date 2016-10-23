private["_agent","_surfaceType","_isInside","_vel","_speed","_pos","_scaleLight","_scaleSound","_visibility","_audibility","_anim","_skeleton","_animPose","_visiblePose","_audiblePose","_visibleTerrain","_visibleSpeed","_audibleSpeed","_audibleTerrain","_audial","_visual","_array"];
private["_buildings","_building","_isOk","_i"];
/*
	Run for each player during each tick, checks the players stealth levels for sight and sound
	and then returns an array of values, used for zombie detection. Use is made of global variables
	that provide scales for values according to environmental factors.
	
	Created by SigWar
*/

//_buildings = nearestObjects [(vehicle player), ["Building"],50];
_buildings = nearestObjects [(vehicle player), ["House_F","House"],50];
_isOk = true;
_i = 0;

while {_isOk} do {

	if (_i > ((count _buildings) - 1)) exitWith {
		_isInside = false;
		_building = "No buildings";
	};
	
	if ((_buildings select _i) getVariable ["isBuilding",true]) then {
		_building = _buildings select _i;
		_isInside = [(vehicle player),_building] call fnc_isInsideBuilding;
		_isOk = false;
	} else {
		_i = _i + 1;
	};
};

_agent = 		player;
_surfaceType = 	viruz_surfaceType;
_vel = 			velocity (vehicle _agent);
_speed = 		(_vel distance [0,0,0]);
_pos = 			getPosATL player;

_scaleLight = (
//	(sunOrMoon * 2)		//add sunlight
	sunOrMoon
	+ moonIntensity		//add moonlight
	- (overcast * 0.2)	//remove for cloud state
	- (rain * 0.2)		//remove for rain state
	- (fog * 0.5));		//remove for fog state
	
viruz_scaleLight = _scaleLight;

if (_scaleLight < 0.9) then {
	//Assess if near lightsource
	private ["_nearFire","_nearFires","_scaler"];
	if (!_isInside) then {
		_nearFires = nearestObjects [(vehicle player),getArray(configFile >> "CfgObjectCheck" >> "fireObjects"),50];
		if (count _nearFires > 0) then {
			_scaler = 50 - ((_nearFires select 0) distance (vehicle player));
			_scaleLight = ((_scaler * 2) / 100) + _scaleLight;
		};
	};
};

_scaleSound = (1
	- (rain * 0.4)		//remove for rain state
	//+ (fog * 0.3) 		//add for fog state
	)
	max 0;

//Ensure zero or above
_visibility = 	100;
_audibility = 	50;
_scaleLight = 	_scaleLight max 0;

//Visibility
_anim = 	animationState _agent;
_anim4 = toArray _anim;
_anim4 resize 4;
_anim4 = toString _anim4;
//_skeleton = getText (configFile >> "CfgVehicles" >> typeOf _agent >> "moves");
//_animPose = getText (configFile >> _skeleton >> "states" >> _anim >> "bodyPosition");

_visiblePose = 1.0;
_audiblePose = 1.0;

if (["pknl",_anim] call fnc_inString) then {
	_visiblePose = 0.25;
	_audiblePose = 0.8;
} else {;
	if (["ppne",_anim] call fnc_inString) then {
		_visiblePose = 0.1;
		_audiblePose = 0.2;
	};
};

if (_anim4 == "aswm") then {
	viruz_isSwimming = true;
} else {
	viruz_isSwimming = false;
};
/*
_visiblePose =
	switch (_animPose) do 
	{ 
		case "down": 	{0.05};
		case "prone": 	{0.05};
		case "kneel": 	{0.25}; 
		case "stand": 	{1.00}; 
		default 		{1.00};
	};
_audiblePose =
	switch (_animPose) do 
	{ 
		case "down": 	{0.05};	
		case "prone": 	{0.3}; 
		case "kneel": 	{0.8}; 
		case "stand": 	{1.0}; 
		default 		{1.0};
	};
*/

//_visibleTerrain = 	getNumber (configFile >> "CfgSurfaces" >> _surfaceType >> "visible" >> _animPose);
_visibleTerrain =	1.0;
_visibleSpeed = 	_speed * (_visiblePose * 20);

//Audibility
_audibleSpeed = 	_speed * (_audiblePose * 10);
_audibleTerrain =	1.0;
//_audibleTerrain = getNumber (configFile >> "CfgSurfaces" >> _surfaceType >> "audibility");

if (_isInside) then {
	_visibleTerrain = 0.2;
	_audibleTerrain = 0.5;
	if (_scaleLight > 0) then {
		_scaleLight = _scaleLight / 4;
	};
} else {	
	if (["grass",viruz_surfaceType] call fnc_inString) then {
//		_visibleTerrain = 1.0;
		_audibleTerrain = 0.6;
	} else {
		if (["forest",viruz_surfaceType] call fnc_inString) then {
			_visibleTerrain = 0.2;
			_audibleTerrain = 0.2;
		} else {
			if (["concrete",viruz_surfaceType] call fnc_inString) then {
//				_visibleTerrain = 1.0;
				_audibleTerrain = 1.0;
			} else {
				if (["rock",viruz_surfaceType] call fnc_inString) then {
//					_visibleTerrain = 1.0;
					_audibleTerrain = 1.0;
				};
			};
		};
	};
};

//Work out result
_audial = 	round
	(
		(
			(_audibleSpeed * _audiblePose * _audibleTerrain)
		) * _scaleSound
	);
_visual = round
	(
		(
			(_visibility * _visiblePose * _visibleTerrain) + _visibleSpeed
		) * _scaleLight
	);
	
if ((_audial > VIRUZ_disAudial) or ((time - viruz_firedCooldown) > 0.3)) then {
	VIRUZ_disAudial = _audial;
};
VIRUZ_disVisual = 	_visual;
/*
systemChat format["_surfaceType = %1", _surfaceType];
systemChat format["_anim = %1", _anim];
systemChat format["_building = %1", _building];
systemChat format["_isInside = %1", _isInside];
systemChat format["_audial : %5 = (%1 * %2 * %3) * %4", _audibleSpeed,_audiblePose,_audibleTerrain,_scaleSound,_audial];
systemChat format["_visual : %6 = ((%1 * %2 * %3) + %4) * %5", _visibility,_visiblePose,_visibleTerrain,_visibleSpeed,_scaleLight,_visual];
