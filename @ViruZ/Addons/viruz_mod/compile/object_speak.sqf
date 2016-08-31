private["_unit","_type","_chance","_rnd","_sound","_local","_dis"];
_unit = _this select 0;
_type = _this select 1;
_chance = _this select 2;
//_chance = round(_this select 2);

_num = switch (_type) do {
	default 			{0};
	case "cough": 		{2};
	case "chase": 		{14};
	case "spotted": 	{13};
	case "hit": 		{6};
	case "attack": 		{13};
	case "idle": 		{35};
	case "scream": 		{4};
	case "fracture":	{1};
	case "eat": 		{3};
	case "cook": 		{2};
	case "panic": 		{1};
	case "dog_bark":	{4};
	case "dog_growl":	{3};
	case "dog_qq":		{2};
};

if (count _this > 4) then {
	_dis = _this select 4;
	_local = ({isPlayer _x} count (_unit nearEntities ["AllVehicles",_dis]) < 2);
} else {
	_local = _this select 3;
	
	if (_type in ["shout","hit","attack","scream","breath","spotted","idle","chase"]) then {
		_dis = 100;
	} else {
		_dis = 40;
	};
};

_isWoman = getText(configFile >> "cfgVehicles" >> (typeOf _unit) >> "TextPlural") == "Women";
if (_isWoman and (_type in ["scream","panic"])) then {
	_type = _type + "_w";
};


//if ((round(random _chance) == _chance) or (_chance == 0)) then {
if (floor(random(_chance)) < 5) then {
	_rnd =(round(random _num));
	_sound = "z_" + _type + "_" + str(_rnd);
	if (_local) then {
		_unit say [_sound, _dis];
	} else {
//		[nil,_unit,rSAY,[_sound, _dis]] call RE;
		[[_unit,[_sound, _dis]],"MP_say"] spawn BIS_fnc_MP;
	};
	
//	systemChat format["%1", "Object_speak = " + str(_sound) + " : " + str(_dis) + " : " + str(_chance)];
};