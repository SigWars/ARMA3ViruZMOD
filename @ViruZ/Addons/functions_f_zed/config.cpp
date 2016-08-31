class CfgPatches {
	class A3_Functions_F_Zed {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

class CfgFunctions {
	class ZedA3 {
		tag = "ptm";
		
		class Init {
			file = "a3\functions_f\Zed\Init";
			class zombieInit {};
		};
		
		class Anims {
			file = "a3\functions_f\Zed\Anims";
			class zGetAnims {};
		};
	};
};