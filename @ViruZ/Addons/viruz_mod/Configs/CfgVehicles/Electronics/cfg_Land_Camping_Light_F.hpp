class Land_Camping_Light_F : FloatingStructure_F {
	class EventHandlers {
		init = "if !(isServer) then {(_this select 0) execVM '\z\addons\viruz_mod\Configs\CfgVehicles\Electronics\scripts\CampingLight_init.sqf'}";
	};
};

class Land_Camping_Light_off_F : ThingX {
	class EventHandlers {
		init = "if !(isServer) then {(_this select 0) execVM '\z\addons\viruz_mod\Configs\CfgVehicles\Electronics\scripts\CampingLight_init.sqf'}";
	};
};