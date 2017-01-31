/*
    File: VZClient_util_model_isNearby.sqf
    Atuthor: Mateus "Mateuus" Rodrigues
	
	Licence: 
	ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
	
    Description:
	Verificar se o objeto está proximo
*/

private["_position","_radius","_modelNames","_objects","_result","_modelName","_modelCount"];
_position = _this select 0;
_radius = _this select 1;
_modelNames = _this select 2;

_objects = nearestObjects [player, [], _radius];
_modelCount = [];

_result = false;
{
	if (typeOf _x in _modelNames) then {
       _modelCount  SET [count _modelCount,_objects];
    };
	
	if (count _modelCount > 0) exitWith { 
		_result = true; 
	};
} 
foreach _objects;	
_result
