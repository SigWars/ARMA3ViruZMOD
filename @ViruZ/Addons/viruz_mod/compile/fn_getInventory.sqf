/*
	file: fn_getInventory.sqf
	
	Author: SigWAr
	

	[
		["uniform class", [array items in uniform]],
		["vest class", [array items in vest]],
		["backpack class", [array items in backpack]],
		"headgear class",
		"goggles class",
		"Binocular class",
		["class primary weapon", [array weapon Linked Items], "Magazine"],
		["class secondary weapon", [array weapon Linked Items], "Magazine"],
		["class handgun weapon", [array weapon Linked Items], "Magazine"],
		[array linked items]
	]
	

	_inventory = player call ptm_fnc_getInvenroty;
	
*/

_unit = [_this, 0, objNull, [objNull]] call BIS_fnc_param;
if (isNull _unit) exitWith {diag_log "GET INVENTORY ERROR: Object is null"; []};

#define MAGAZINE (if (_ammoCount == (getNumber (configFile/"CfgMagazines"/_className/"count"))) then {_className} else {[_className, _ammoCount]})

_primaryWeaponMagazine		= "";
_secondaryWeaponMagazine	= "";
_handgunMagazine			= "";
_uniformItems				= [];
_vestItems					= [];
_backpackItems				= [];

{
	_className		= _x select 0;
	_ammoCount		= _x select 1;
	_state			= _x select 2;
	_type			= _x select 3;
	_location		= _x select 4;
	
	switch (_type) do {
	
		case 1: {
			_primaryWeaponMagazine = MAGAZINE;
		};
		
		case 2: {
			_handgunMagazine = MAGAZINE;
		};
	
		case 4: {
			_secondaryWeaponMagazine = MAGAZINE;
		};
	};
} forEach magazinesAmmoFull _unit;

{
	_className		= _x select 0;
	_ammoCount		= _x select 1;
	
	_uniformItems pushBack MAGAZINE;
	
} forEach (magazinesAmmoCargo uniformContainer _unit);
{
	if !(isClass(configFile/"CfgMagazines"/_x)) then {	// исключаем магазины
		_uniformItems pushBack _x;
	};
} forEach (uniformItems _unit);

{
	_className		= _x select 0;
	_ammoCount		= _x select 1;
	
	_vestItems pushBack MAGAZINE;
	
} forEach (magazinesAmmoCargo vestContainer _unit);
{
	if !(isClass(configFile/"CfgMagazines"/_x)) then {	// исключаем магазины
		_vestItems pushBack _x;
	};
} forEach (vestItems _unit);

{
	_className		= _x select 0;
	_ammoCount		= _x select 1;
	
	_backpackItems pushBack MAGAZINE;
	
} forEach (magazinesAmmoCargo backpackContainer _unit);
{
	if !(isClass(configFile/"CfgMagazines"/_x)) then {	// исключаем магазины
		_backpackItems pushBack _x;
	};
} forEach (backpackItems _unit);

_primaryWeaponItems = [];
{
	if (_x != "") then {
		_primaryWeaponItems pushBack _x;
	};
} forEach (primaryWeaponItems _unit);

_secondaryWeaponItems = [];
{
	if (_x != "") then {
		_secondaryWeaponItems pushBack _x;
	};
} forEach (secondaryWeaponItems _unit);

_handgunItems = [];
{
	if (_x != "") then {
		_handgunItems pushBack _x;
	};
} forEach (handgunItems _unit);

_assignedItems	= [];
_binocular	= "";
{
	if (_x in ["Binocular", "Rangefinder", "Laserdesignator"]) then {
		_binocular = _x;
	} else {
		_assignedItems pushBack _x;
	};
} forEach (assignedItems _unit);

//	Return array
[
	[uniform _unit, _uniformItems],
	[vest _unit, _vestItems],
	[backpack _unit, _backpackItems],
	headgear _unit,
	goggles _unit,
	_binocular,
	[primaryWeapon _unit, _primaryWeaponItems, _primaryWeaponMagazine],
	[secondaryWeapon _unit, _secondaryWeaponItems, _secondaryWeaponMagazine],
	[handgunWeapon _unit, _handgunItems, _handgunMagazine],
	_assignedItems
]