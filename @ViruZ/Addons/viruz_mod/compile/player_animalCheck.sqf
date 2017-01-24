/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private["_list","_Pos","_randrefpoint","_PosList","_PosSelect","_Pos","_list","_animalssupported","_type","_root","_favouritezones","_GroupMarker","_agent","_id","_tame"];
_list = getposATL player nearEntities [["Animal_Base_F"],viruz_animalDistance];

if (count _list < viruz_maxAnimals) then {
	//Find where animal likes
//	_animalssupported = ["hen","hen","hen","Cow","Sheep","WildBoar","WildBoar","WildBoar","Goat","Rabbit","Rabbit"];
//cachorro ["Alsatian_Black_F","Alsatian_Sandblack_F","Alsatian_Random_F"]
_animalssupported = ["Fowl_Base_F","Hen_random_F","Cock_random_F","Rabbit_F","Goat_random_F","Goat_small_random_F","Sheep_random_F"];
	//_animalssupported = ["DZ_Pastor"];
	_type =  (_animalssupported select floor(random(count _animalssupported)));
//	if (_type == "Cow") then {
//		_animalssupported = ["Cow01","Cow02","Cow03","Cow04"];
//		_type =  (_animalssupported select floor(random(count _animalssupported)));
//	};
	_root = configFile >> "CfgVehicles" >> _type;
	_favouritezones = getText ( _root >> "favouritezones");
	//_randrefpoint = [position player, 10, viruz_animalDistance, 1, 0, 50, 0] call BIS_fnc_findSafePos;
	_favouritezones = "(1 + meadow) * (1 - forest) * (1 - trees)";
	_randrefpoint = getposATL player;
	_PosList = 		selectbestplaces [_randrefpoint,viruz_animalDistance,_favouritezones,10,5];
		_PosSelect = 	_PosList select (floor random (count _PosList));
	_Pos =  		_PosSelect select 0;
	_list = 		_Pos nearEntities [["Animal_Base_F","Man"],50];
	
	if (player distance _Pos < viruz_animalDistance and NOT surfaceIsWater _Pos and (count _list <= 1)) then {
		if (_type == "DZ_Pastor") then { _agent = createAgent [_type, _Pos, [], 0, "NONE"]; } else { _agent = createAgent [_type, _Pos, [], 0, "FORM"]; };
		_agent setpos _Pos;
		_id = [_pos,_agent] execFSM "\z\addons\viruz_mod\system\animal_agent.fsm";
	};
	sleep 1;
};