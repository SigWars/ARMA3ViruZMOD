	class B_ManJeans1 : B_Soldier_F {
		scope = public;
		model = "\A3\Characters_F\Civil\c_citizen5.p3d";
		displayName = "Civilian Jeans brown";
		hiddenSelections[] = {"Camo1", "Camo2", "Camo3"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\basicbody_brown_co.paa", "\A3\characters_f\civil\data\c_cloth4_co.paa"};
		uniformClass = "U_C_Citizen_clothes1";
		linkeditems[] = {};
		respawnlinkeditems[] = {};
		
		class Wounds {
			tex[] = {};
			mat[] = {"A3\Characters_F\Civil\Data\c_cloth4.rvmat", "A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat", "A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat"};
		};
	};