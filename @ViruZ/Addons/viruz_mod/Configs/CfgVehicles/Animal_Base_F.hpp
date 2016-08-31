class Animal_Base_F;
	class Rabbit_F: Animal_Base_F
	{
		author = "$STR_A3_Bohemia_Interactive";
		_generalMacro = "Rabbit_F";
		scope = 2;
		displayName = "$STR_A3_CfgVehicles_Rabbit_F0";
		model = "\A3\Animals_F\rabbit\rabbit_F.p3d";
		side = 3;
		moves = "CfgMovesRabbit_F";
		fsmFormation = "";
		fsmDanger = "";
		maxTurnAngularVelocity = 30;
		costTurnCoef = 1e-005;
		boneHead = "head";
		bonePrimaryWeapon = "head";
		weaponBone = "head";
		triggerAnim = "";
		class VariablesScalar
		{
			_threatMaxRadius = 20;
			_runDistanceMax = 50;
			_movePrefer = 0.7;
			_formationPrefer = 0.2;
			_scareLimit = 0.2;
			_dangerLimit = 1.0;
			_walkSpeed = 0.9;
		};
		class VariablesString
		{
			_expSafe = "(0.5 * meadow) * (0.5 *  trees) * (1 - forest) * (1 - houses) * (1 - sea)";
			_expDanger = "(trees) * (forest) * (1 - meadow) * (1 - houses) * (1 - sea)";
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"A3\Animals_F\Rabbit\data\Rabbit.rvmat","A3\Animals_F\Rabbit\data\W1_Rabbit.rvmat","A3\Animals_F\Rabbit\data\W2_Rabbit.rvmat"};
		};

	};
class Goat_Base_F: Animal_Base_F
	{
		displayName = "$STR_A3_CfgVehicles_Goat_Base_F0";
		model = "\A3\animals_f_beta\Goat\Goat_F.p3d";
		hasGeometry = 1;
		moves = "CfgMovesGoat_F";
		class VariablesScalar
		{
			_threatMaxRadius = 30;
			_runDistanceMax = 70;
			_movePrefer = 0.25;
			_formationPrefer = 0.8;
			_scareLimit = 0.2;
			_dangerLimit = 5.0;
			_walkSpeed = 1.2;
		};
		class VariablesString
		{
			_expSafe = "(0.5 * meadow) * (0.5 *  trees) * (1 - forest) * (1 - houses) * (1 - sea) * hills";
			_expDanger = "(1 - sea) * hills";
		};
		class Wounds
		{
			tex[] = {};
			mat[] = {"A3\animals_f_beta\Goat\data\goat.rvmat","A3\animals_f_beta\Goat\data\W1_goat.rvmat","A3\animals_f_beta\Goat\data\W2_goat.rvmat"};
		};
		class EventHandlers;
		hiddenSelections[] = {"camo"};
	};
class Goat_random_F: Goat_Base_F
	{
		scope = 2;
		side = 3;
		class EventHandlers: EventHandlers
		{
			init = "_FRnd = compile loadFile ""\A3\animals_f_beta\goat\scripts\randomize.sqf"";(_this select 0) call _FRnd;";
		};
	};
class Sheep_random_F: Animal_Base_F
	{
		scope = 2;
		side = 3;
		displayName = "$STR_A3_CfgVehicles_Sheep_random_F0";
		model = "\A3\animals_f_beta\Sheep\Sheep_F.p3d";
		hasGeometry = 1;
		moves = "CfgMovesSheep_F";
		class Wounds
		{
			tex[] = {};
			mat[] = {"A3\animals_f_beta\sheep\data\sheep.rvmat","A3\animals_f_beta\sheep\data\W1_sheep.rvmat","A3\animals_f_beta\sheep\data\W2_sheep.rvmat"};
		};
		hiddenSelections[] = {"camo"};
		class EventHandlers
		{
			init = "_FRnd = compile loadFile ""\A3\animals_f_beta\Sheep\scripts\randomize.sqf"";(_this select 0) call _FRnd;";
		};
		class VariablesScalar
		{
			_threatMaxRadius = 10;
			_runDistanceMax = 25;
			_movePrefer = 0.25;
			_formationPrefer = 0.85;
			_scareLimit = 0.2;
			_dangerLimit = 12.0;
			_walkSpeed = 0.81;
		};
		class VariablesString
		{
			_expSafe = "(0.5 * meadow) * (0.5 *  houses) * (1 - forest) * (1 - trees) * (1 - sea)";
			_expDanger = "(0.5 * meadow) * (0.5 *  houses) * (1 - forest) * (1 - trees) * (1 - sea)";
		};
	};
class Fowl_Base_F: Animal_Base_F
	{
		class EventHandlers;
		class Wounds
		{
			tex[] = {};
			mat[] = {};
		};
		class VariablesScalar
		{
			_threatMaxRadius = 5;
			_runDistanceMax = 30;
			_movePrefer = 0.8;
			_formationPrefer = 0.5;
			_scareLimit = 0.2;
			_dangerLimit = 1.0;
			_walkSpeed = 0.31;
		};
		class VariablesString
		{
			_expSafe = "(1 - trees) * (1 - forest) * (houses) * (1 - sea)";
			_expDanger = "(1 - trees) * (1 - forest) * (houses) * (1 - sea)";
		};
	};
class Hen_random_F: Fowl_Base_F
	{
		scope = 2;
		side = 3;
		displayName = "$STR_A3_CfgVehicles_Hen_random_F0";
		model = "\A3\animals_f_beta\chicken\Hen_F.p3d";
		moves = "CfgMovesHen_F";
		class Wounds: Wounds
		{
			mat[] = {"A3\animals_f_beta\chicken\data\hen.rvmat","A3\animals_f_beta\chicken\data\W1_hen.rvmat","A3\animals_f_beta\chicken\data\W2_hen.rvmat"};
		};
	};
class Cock_random_F: Fowl_Base_F
	{
		scope = 2;
		side = 3;
		displayName = "$STR_A3_CfgVehicles_Cock_random_F0";
		model = "\A3\animals_f_beta\chicken\Cock_F.p3d";
		moves = "CfgMovesCock_F";
	};
	class Cock_white_F: Cock_random_F
	{
		scope = 2;
		side = 3;
		displayName = "$STR_A3_CfgVehicles_Cock_random_F0";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\animals_f_beta\Chicken\data\white_rooster_CO.paa"};
	};
class Snake_random_F: Animal_Base_F
	{
		scope = 2;
		side = 3;
		displayName = "$STR_A3_CfgVehicles_Snake_random_F0";
		model = "\A3\Animals_F\Snakes\snake_F.p3d";
		moves = "CfgMovesSnakes_F";
		fsmFormation = "";
		fsmDanger = "";
		maxTurnAngularVelocity = 30;
		costTurnCoef = 1e-005;
		boneHead = "head";
		bonePrimaryWeapon = "head";
		weaponBone = "head";
		triggerAnim = "";
		class VariablesScalar
		{
			_threatMaxRadius = 5;
			_runDistanceMax = 25;
			_movePrefer = 0.2;
			_formationPrefer = 0;
			_scareLimit = 0.2;
			_dangerLimit = 1.0;
			_walkSpeed = -1;
		};
		class VariablesString
		{
			_expSafe = "(0.5 * meadow) * (1 - forest) * (1 - houses) * (1 - sea)";
			_expDanger = "(0.5 * meadow) * (forest) * (1 - houses) * (1 - sea)";
		};
		hiddenSelections[] = {"camo"};
		class EventHandlers
		{
			init = "_FRnd = compile loadFile ""\A3\animals_f\Snakes\scripts\randomize.sqf"";(_this select 0) call _FRnd;";
		};
	};
