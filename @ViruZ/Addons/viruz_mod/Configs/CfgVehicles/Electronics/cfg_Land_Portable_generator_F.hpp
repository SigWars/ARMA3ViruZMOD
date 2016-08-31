class Land_Portable_generator_F : Items_base_F {
	fuelCapacity = 20;
	class EventHandlers {
		//init = "(_this select 0) execVM '\z\addons\viruz_mod\Configs\CfgVehicles\Electronics\scripts\PortableGenerator_init.sqf'";
		init = "(_this select 0) execVM '\scripts\viruz_mod\PortableGenerator_init.sqf'";
	};
};