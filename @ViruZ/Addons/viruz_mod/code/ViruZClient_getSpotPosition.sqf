/*
ViruZClient_getSpotPosition.sqf
By SigWar
ViruZ Build Syetem With custom snap

Return the closest snap point
*/
private ["_closest_test_spot_position","_closest_test_distance","_closest_test_spot","_spot_test_position","_test_distance","_on_water","_test_object","_test_position"];
    _closest_test_spot_position = [];
    _test_object = _this select 0;
    _test_position = _this select 1;
    _on_water = _this select 2;
    _closest_test_distance = 0;
    {
   		_spot_test_position = _test_object modelToWorld (_x select 0);
	    _test_distance = _test_position distance _spot_test_position;
	    if (_on_water) then {
   			_spot_test_position = [(_spot_test_position) select 0, (_spot_test_position) select 1, (getPosASL _test_object) select 2];
    	};
	    if ((_closest_test_distance == 0 or _test_distance < _closest_test_distance or _test_distance == 0) && (SnappingDir == (_x select 1) || (_x select 1) == 90 || (_x select 1) == 270)) then {
		    _closest_test_spot_position = _spot_test_position;
		    _closest_test_distance = _test_distance;
		    _closest_test_spot = _x;
	    };
    } forEach _target_spots;
[_closest_test_spot_position, _closest_test_spot];
    