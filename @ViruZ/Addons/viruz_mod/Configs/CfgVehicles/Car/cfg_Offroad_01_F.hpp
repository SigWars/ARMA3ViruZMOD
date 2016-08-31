
class Civilian_Offroad_01_base: C_Offroad_01_F {
	class EventHandlers : EventHandlers {
		init = "if (isServer) then {this animate ['HideConstruction', round (random 1)];this animate [(['HideBumper1','HideBumper2'] call BIS_fnc_selectRandom), round (random 1)];this animate ['HideDoor1', round (random 1)];this animate ['HideDoor3', round (random 1)];this animate ['HideGlass3', round (random 1)];};";
	};
};

class Civilian_Offroad_01_white : Civilian_Offroad_01_base {
//	animates[] = {};
	hiddenSelectionsTextures[] = {"\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE02_CO.paa","\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE02_CO.paa"};
//	textures[] = {"\A3\soft_F\Offroad_01\Data\Offroad_01_ext_co.paa", "\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE01_CO.paa", "\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE02_CO.paa", "\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE03_CO.paa", "\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE04_CO.paa", "\A3\soft_F\Offroad_01\Data\Offroad_01_ext_BASE05_CO.paa"};
};