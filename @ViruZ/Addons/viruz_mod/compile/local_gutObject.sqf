private["_animalbody","_qty","_rawfoodtype","_ehLoc"];
_animalbody = _this select 0;
_qty = _this select 1;
_rawfoodtype =   getText (configFile >> "CfgSurvival" >> "Meat" >> typeOf _animalbody >> "rawfoodtype");

if (local _animalbody) then {
// _meatpos = "GroundWeaponHolder" createVehicle getPos _animalbody;
 _meatpos = createVehicle ["GroundWeaponHolder",getPos _animalbody, [], 0, "CAN_COLLIDE"];

	for "_x" from 1 to _qty do {
	diag_log format ["animal animalbody %1, rawfoodtype %2",_animalbody,_rawfoodtype];
		
//		_animalbody addMagazine _rawfoodtype;
		_meatpos addMagazineCargoGlobal [_rawfoodtype,1];
	};
		
	[time, _animalbody] spawn { 
		private ["_timer", "_body"]; 
		_timer = _this select 0; 
		_body = _this select 1; 
		while {(count magazines _body >0) and (time - _timer < 300) } do { 
			sleep 5;
		}; 
		//["viruzHideBody",_body] call broadcastRpcCallAll;
		viruzHideBody = _body;
		hideBody _body; // local player
		publicVariable "viruzHideBody"; // remote player
		sleep 2;
		deleteVehicle _body;
		true;
	};
	
} else {
	_ehLoc = "client";
	if (isServer) then { _ehLoc = "server"; };
	diag_log format["gutObject EH on %1 item not local ! Type: %2",_ehLoc,str(_animalbody)];
};