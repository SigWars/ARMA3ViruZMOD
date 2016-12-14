/***********************************************************
ASSIGN DAMAGE HANDLER TO A UNIT
- Function set_EH
- unit call set_EH;
************************************************************/
private["_unit","_eh1","_eh2","_ehglitch","_dir","_location"];
_unit = _this;
_dir = getdir _this;
_location = getPosATL _this;

//Assign event handlers
_eh1 = _unit addeventhandler ["HandleDamage",{ _this call vehicle_handleDamage } ];
_eh2 = _unit addeventhandler ["Killed",{ _this call vehicle_handleKilled } ];
 
if (isServer) then {
	_ehglitch = _unit addEventHandler ["GetOut",{ _this call VIRUZ_getOutVehicle; } ]; //Getting out while IsMoveOutInProgress
	_eh3 = _unit addEventHandler ["GetOut", {[(_this select 0),"all"] call server_updateObject;}];
	//_eh4 = _unit addEventHandler ["GetIn", {[(_this select 0),"all"] call server_updateObject;}];
	_eh5 = _unit addEventHandler ["Killed",{ _this call vehicle_handleKilled } ];
	_eh6 = _unit addeventhandler ["HandleDamage",{ _this call vehicle_handleDamage } ];
};