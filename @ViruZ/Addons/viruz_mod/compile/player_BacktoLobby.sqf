/*
ViruZ Mod
Atuthor: SigWar
Licence: ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
*/

private ["_inventory"];

//save inventory if player back to lobby
_inventory = player call ptm_fnc_getInventory;
viruzPlayerSave = [player,_inventory,false];
publicVariableServer "viruzPlayerSave";