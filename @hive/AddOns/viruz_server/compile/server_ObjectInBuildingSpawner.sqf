private ["_ret","_inBuildingsObjects","_cfgBuildings","_BuildingsInConfig","_funcGetBuildings","_DisableSimulation","_City","_PositionCity","_RadiusCity","_Buildings","_Building","_dirBuilding","_cfgObjects","_cfgObject","_posObj","_Obj","_TypeObj"];

diag_log (format["OBJECTINBUILDINGSPAWNER: Spawn objects in buildings. Location : %1", text _this]);

_cfgBuildings = configFile >> "CfgObjectInBuildingSpawner";
_BuildingsInConfig = [];
_inBuildingsObjects = [];
_DisableSimulation = [];

_funcGetBuildings = 
{
	for "_i" from 0 to ((count _this) - 1) do 
	{
		private ["_Build"];
		_Build = configName (_this select _i);
		
		if (!(_Build in _BuildingsInConfig)) then 
		{
			_BuildingsInConfig set [count _BuildingsInConfig, _Build];
		};
	};
};

while {(configName _cfgBuildings) != ""} do 
{
	_cfgBuildings call _funcGetBuildings;
	_cfgBuildings = inheritsFrom _cfgBuildings;
};

_City = _this;
_PositionCity = locationPosition _City;
_RadiusCity = getNumber (configFile >> "cfgWorlds" >> worldName >> "Names" >> className _City >> "RadiusA");
_Buildings = nearestObjects [_PositionCity, _BuildingsInConfig, _RadiusCity];
	
	for "_i" from 0 to ((count _Buildings) - 1) do {
		
		_Building = _Buildings select _i;
		
		if (typeOf _Building in _BuildingsInConfig) then {
			
			if (!(_Building getVariable ["ObjectInBuilding", false]) and (_Building getVariable ["OwnerUID","0"] == "0")) then {
				
				_dirBuilding = getDir _Building;
				_cfgObjects = getArray (configFile >> "CfgObjectInBuildingSpawner" >> typeOf _Building >> "Objects");
				
				for "_i" from 0 to ((count _cfgObjects) - 1) do {
					
					_cfgObject = _cfgObjects select _i;
					
					if ( random 1 <= (_cfgObject select 3)) then {
					
						_TypeObj = (_cfgObject select 0) call BIS_fnc_selectRandom;
						_posObj = _Building modelToWorld (_cfgObject select 2);

						if (_TypeObj isKindOf "Maniken_Base") then {
							_Obj = createVehicle [_TypeObj, _posObj, [], 0, "NONE"];
							_DisableSimulation set [count _DisableSimulation, _Obj];
							_Obj switchmove "amovpercmstpsnonwnondnon";
							removeUniform _Obj;
						} else {
							_Obj = createVehicle [_TypeObj, _posObj, [], 0, "CAN_COLLIDE"];
							_Obj setVariable ["isBuilding", false, true];
						};
					
						_Obj setPosATL _posObj;
						_Obj setDir (_dirBuilding - (_cfgObject select 1));
						_inBuildingsObjects SET [count _inBuildingsObjects, _Obj];
						
//						diag_log(format["OBJECTINBUILDINGSPAWNER: Create object %2 in %1",_Building,_TypeObj]);
					};
				};
				_Building setVariable ["ObjectInBuilding", true, true];
			};
		};
	};
//	[[[_DisableSimulation],"z\addons\viruz_mod\compile\DisableSimulation.sqf"],"BIS_fnc_execVM",nil,true] spawn BIS_fnc_MP;
_ret = [_Buildings,	_inBuildingsObjects];
_ret