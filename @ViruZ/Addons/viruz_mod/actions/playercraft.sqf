//Let Zeds know
[player,4,true,(getPosATL player)] call player_alertZombies;
// _Survivors = playersNumber west;
//display gui (temp hint)

if (!viruz_isSwimming) then
{
	createDialog "RscDisplayCraftingMenu";
};