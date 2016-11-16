private ["_inventory"];

//save inventory
_inventory = player call ptm_fnc_getInventory;
viruzPlayerSave = [player,_inventory,false];
publicVariableServer "viruzPlayerSave";