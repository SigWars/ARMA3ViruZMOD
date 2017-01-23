/*
	Author: SigWar
	sync player gear on close inventory
	sync nearest objects inventory on close player inventory
*/

private ["_objects","_inventory"];

_debug = false;

_objects = nearestObjects [getPosATL player, config_VehiclesCheck, 20];
{
	viruzUpdateVehicle = [_x,"gear"];
	publicVariableServer "viruzUpdateVehicle";
} foreach _objects;

_inventory = player call ptm_fnc_getInventory;

if (_debug) then {
	diag_log format ["DEBUG: player_gearSync: %1: %2", player, _inventory];
};

viruz_unsaved = true;
viruz_Magazines = _inventory;
