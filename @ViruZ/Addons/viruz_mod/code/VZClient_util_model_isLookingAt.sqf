private["_modelNames","_result","_objects","_modelName","_modelCount"];
_modelNames = _this;
_result = false;
_objects = lineIntersectsObjs [ATLToASL positionCameraToWorld [0,0,0], ATLToASL positionCameraToWorld[0,0,5], objNull, objNull, true, 32];
_modelCount [];
{
	if (typeOf _x in _modelNames) then {
       _modelCount  SET [count _modelCount,_objects];
    };
	
	if (count _modelCount > 0) exitWith 
	{ 
		_result = true; 
	};
} 
foreach _objects;
_result

