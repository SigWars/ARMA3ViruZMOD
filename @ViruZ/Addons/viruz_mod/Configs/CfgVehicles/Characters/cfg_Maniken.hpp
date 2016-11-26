class Maniken_Base : Underwear_F {
	author = "SigWar";
	displayName = "Maniken Base";
	Items[] = {};
	RespawnItems[] = {};
	linkedItems[] = {};
	respawnLinkedItems[] = {};
	class EventHandlers {
		init = "(_this select 0) execVM 'z\addons\viruz_mod\configs\CfgVehicles\Characters\scripts\cfg_Maniken.sqf'";
	};
};
class Maniken_Civilian : Maniken_Base {
	displayName = "Maniken Civilian";
};
class Maniken_Military : Maniken_Base {
	displayName = "Maniken Military";
};
