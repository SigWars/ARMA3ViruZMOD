private ["_centerMap","_nearestRadius","_listLocations"];

_listLocations = getArray (configFile >> "CfgObjectSpawner" >> "listLocations");
//Fix for Multimaps suport anchor By SigWar
//Need add "center" mark on center of the map in editor
_mapaatual = worldName;
switch (_mapaatual) do {
	
	/*default { _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };*/
	case "Stratis": { _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };		 
	case "Bornholm": { _centerMap = getMarkerPos "center"; _nearestRadius = 10000; };
	case "Esseker": { _centerMap = getMarkerPos "center"; _nearestRadius = 6000; };
	case "Altis": { _centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };
	case "Chernarus": { _centerMap = getMarkerPos "center"; _nearestRadius = 7000; };
	case "Tanoa": {_centerMap	= getArray (configFile >> "cfgWorlds" >> worldName >> "safePositionAnchor"); _nearestRadius	= (getNumber (configFile >> "cfgWorlds" >> worldName >> "safePositionRadius")) * 2.5; };
	//Como disse não tem certeza se esse mapa tem cfgword safeposition
	case "xcam_taunus": { _centerMap = getMarkerPos "center"; _nearestRadius = 10000; };
	};

{
	_x spawn server_objectSpawnerMonitor;
} forEach (nearestLocations [_centerMap, _listLocations, _nearestRadius]);

//	[[[allMissionObjects "Maniken_Base"],"z\addons\viruz_mod\compile\DisableSimulation.sqf"],"BIS_fnc_execVM",nil,true] spawn BIS_fnc_MP;

//	nul = [] call server_ObjectInBuildingSpawner; //Start spawn object in buildings