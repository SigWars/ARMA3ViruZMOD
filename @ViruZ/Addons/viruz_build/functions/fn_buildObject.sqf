/******************************************************************************************************************
ViruZ Mod for Arma 3
Update Object Position, Owner etc by type
Autor: SigWar
This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
********************************************************************************************************************/
private ["_couldBuild","_sucess","_haveSlots","_hasPole","_builderUID","_BuilderPlayer","_ownerTODB","_location","_sameGroup","_generatorOwner","_canDelete",
"_findGenerator","_ViruZ_Generator","_savedGroup","_permission","_buildscount","_objectType","_ressourcetype","_count","_itemcount","_dir","_Object","_meters","_blockedArea","_vzBuildstoCount"];

//Define Vars
_couldBuild = true;
_sucess = true;
_haveSlots = true;
_hasPole = false;
_location = player modeltoworld [0,1.5,0];
_location set [2,0];
_sameGroup = false;
_canDelete = serverTime + 7200;
_builderUID = getPlayerUID player;
_BuilderPlayer = _builderUID;
_ownerTODB = str( 'B'+ _builderUID );
_buildscount = 0;
_vzBuildstoCount = + VIRUZ_BUILDS + VIRUZ_GATES + VIRUZ_WALLS + VIRUZ_SUPPLYES + VIRUZ_RACKS;
_meters = 151;
_playerPos = getPosASL player;
_blockedArea = false;
_permission = 0;

{
	_blockedPos = _x select 0;
	_blockedDistance = _x select 1;
	if ( (_playerPos distance _blockedPos) < _blockedDistance ) exitWith {_blockedArea = true;};
}forEach getArray(missionConfigFile >> worldName >> "blockedArea");

if (_blockedArea)exitWith{cutText ["You can not build in this area", "PLAIN DOWN",2];};

//Find Generator
_findGenerator = nearestObjects [player, ["Land_Portable_generator_F"], 150];
if (count _findGenerator > 0 ) then {
	_ViruZ_Generator = _findGenerator select 0;
	if !(isNull _ViruZ_Generator) then {
		_generatorOwner = _ViruZ_Generator getVariable ["OwnerUID","0"];
		
		_ownerTODB = str( 'B'+ _generatorOwner );
		_builderUID = _generatorOwner;

		//count builded items
		_findBuilds = nearestObjects [position _ViruZ_Generator, [], viruz_maxBuildDistance+20];
		_maxLimit = [];
		{
			if (typeOf _x in _vzBuildstoCount) then {
				_maxLimit SET [count _maxLimit,_findBuilds];
			};
		
		}foreach _findBuilds;
		
		_buildscount = count _maxLimit;
		
		//Check if reach max limit
		if (_buildscount > viruz_maxBuildCount ) exitWith { 
			_haveSlots = false;
			_sucess = false;
			cutText ["You have reach a maximum number of builds", "PLAIN DOWN",2];
		};
		
		_meters = player distance _ViruZ_Generator;
			
		//check group
		_savedGroup = player getVariable ["ClanID","0"];
		_permission = player getVariable ["LvL",0];
		if (_savedGroup isEqualto _generatorOwner) then {_sameGroup = true;};
		
		if ( (_meters < viruz_maxBuildDistance ) and (_generatorOwner == _BuilderPlayer)) then {
			_hasPole = true;
		}else{
			if ( _meters <= viruz_maxBuildDistance and _generatorOwner != _BuilderPlayer and _sameGroup) then {
				_hasPole = true;
			};
		};
		
	};
};

if (_sameGroup and _permission < 2) exitWith { cutText ["You do not have the permission required!", "PLAIN DOWN",2]; _sucess = false;};

//Check Ressources
_objectType = (((viruz_build_array select viruz_build_categorieId) select (viruz_build_classnameId + 1)) select 0);
{
	_ressourcetype = _x select 0;
	_count = _x select 1;
	_itemcount = 0;
	_string = "FAILED";
	
	if (viruz_build_inventoryHolder == player) then
	{
		{
			if(_x == _ressourcetype) then {_itemcount = _itemcount + 1};
		} foreach magazines player;
		if(_itemcount < _count) then 
		{ 
			_couldBuild = false;
		};
	}
	else
	{
		_array = getMagazineCargo viruz_build_inventoryHolder;
		{
			if(_x == _ressourcetype) then {_itemcount = ((_array select 1) select _forEachIndex)};
		} foreach (_array select 0);
		if(_itemcount < _count) then 
		{ 
			_couldBuild = false;
		};
	};
}
foreach (((viruz_build_array select viruz_build_categorieId) select (viruz_build_classnameId + 1)) select 1);

//Has generator or in same group
if (_hasPole and _haveSlots ) then {
	
	if (_generatorOwner != _BuilderPlayer and !_sameGroup) exitWith { cutText ["You are not in the same group, or you do not have the permission required!", "PLAIN DOWN",2]; _sucess = false;};
	if (_meters < 150 and _objectType == "Land_Portable_generator_F") exitWith { cutText ["You need to be at least 150m from other Generator!", "PLAIN DOWN",2]; _sucess = false;};
	
	if(_couldBuild and _objectType != "Land_Portable_generator_F") then
	{
		if (viruz_build_inventoryHolder == player) then
		{
			{	
				_ressourcetype = (_x select 0);
				_count = (_x select 1);
				while {_count > 0} do
				{
					player removeMagazine _ressourcetype;
					_count = _count - 1;
				};
			}
			foreach (((viruz_build_array select viruz_build_categorieId) select (viruz_build_classnameId + 1)) select 1);
		}
		else
		{
			{
				[viruz_build_inventoryHolder,_x] call viruz_fnc_removeItemCargoGlobal;
			}
			foreach (((viruz_build_array select viruz_build_categorieId) select (viruz_build_classnameId + 1)) select 1);
		};
	
		_dir = round(direction player);	
		
		_Object = createVehicle [_objectType, _location, [], 0, "CAN_COLLIDE"];
		_Object setDir _dir;
		_Object setposATL _location;
		player reveal _Object;
		
		_Object setVariable["ViruZMod",1];
		_Object setVariable ["characterID",viruz_characterID,true];
		_Object setVariable ["OwnerUID",_builderUID, true];
		_Object setVariable ["Locked", "0", true];
		_Object setVariable ["DeleteTime", _canDelete, true];
		
		
		[_Object,"CreateObject",_hasPole] spawn ViruZClient_move_object;
		
	}else{
		cutText ["You do not have enought ressources!", "PLAIN DOWN",2];
		_sucess = false;
	};
};		

if (!_hasPole and _haveSlots) then {	
	
	  if (_meters < 150) exitWith { cutText ["You need to be at least 150m from other Generator!", "PLAIN DOWN",2]; _sucess = false;};
	  if ( _objectType != "Land_Portable_generator_F" ) exitWith { cutText ["You need put a Generator!", "PLAIN DOWN",2]; _sucess = false;};
	
		if( _couldBuild and _objectType == "Land_Portable_generator_F") then
		{
			if (viruz_build_inventoryHolder == player) then
			{
				{	
					_ressourcetype = (_x select 0);
					_count = (_x select 1);
					while {_count > 0} do
					{
						player removeMagazine _ressourcetype;
						_count = _count - 1;
					};
				}
				foreach (((viruz_build_array select viruz_build_categorieId) select (viruz_build_classnameId + 1)) select 1);
			}
			else
			{
				{
					[viruz_build_inventoryHolder,_x] call viruz_fnc_removeItemCargoGlobal;
				}
				foreach (((viruz_build_array select viruz_build_categorieId) select (viruz_build_classnameId + 1)) select 1);
			};
	
			_dir = round(direction player);	
		
			_Object = createVehicle [_objectType, _location, [], 0, "CAN_COLLIDE"];
			_Object setDir _dir;
			_Object setposATL _location;
			player reveal _Object;
			
			_Object setVariable["ViruZMod",1];
			_Object setVariable ["characterID",viruz_characterID,true];
			_Object setVariable ["OwnerUID", _builderUID, true];
			_Object setVariable ["Locked", "0", true];
			_Object setVariable ["DeleteTime", _canDelete, true];
			
			[_Object,"CreateObject",_hasPole] spawn ViruZClient_move_object;
			
		}else{
			 cutText ["You do not have enought ressources!", "PLAIN DOWN",2];
			 _sucess = false;
		};	
		
};

if (_sucess) then {
	_text1 = "<t size='0.8' font='Zeppelin33' color='#01DF01'>Built</t>";
	_text2 = format ["<t size='0.8' font='Zeppelin33' color='#FE642E'> %1 of %2 </t>", _buildscount, viruz_maxBuildCount];
	_text3 = "<t size='0.8' font='Zeppelin33' color='#01DF01'>Objects</t>";
	_finaltext = _text1 + _text2 + _text3;
	
	[
		_finaltext, //structured text
		0.24 * safezoneW + safezoneX, //number - x
		0.01 * safezoneH + safezoneY, //number - y
		5, //number - duration
		1, // number - fade in time
		0, // number - delta y
		0 //number - layer ID
	] spawn bis_fnc_dynamicText;
};





	
