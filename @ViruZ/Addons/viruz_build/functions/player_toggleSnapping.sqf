/*
ViruZ Mod for Arma 3
MaintainBuilds by items count
Autor: SigWar
This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/

if (SnappingEnabled) then {
	SnappingEnabled = false;
	//SnappingAttachedToPlayer = false;
	systemChat ("Snapping - DISABLED");
} else {
	SnappingEnabled = true;
	systemChat ("Snapping - ENABLED");
};