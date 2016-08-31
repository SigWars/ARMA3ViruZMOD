class CfgFunctions
{
    class A3_DZ
	{
		tag = "PTm";
		class Vehicles
		{
			file = "z\addons\viruz_mod\functions\vehicles";
			class colorVehicle {description = "Color vehicles different colors";};
			class textureVehicle {description = "Set vehicle textures";};
			class materialeVehicle {description = "Set vehicle materiales";};
			class wreckInit {description = "Init vehicles wreck";};
		};
		class Inventory {
			file = "z\addons\viruz_mod\functions\Inventory";
			class loadInventory {};
		};
	};
	/*
	class A3 {
		class Inventory {
			class loadInventory {
				file = "z\addons\viruz_mod\functions\Inventory\fn_loadInventory.sqf";
			};
		};
	};
	*/
};  
