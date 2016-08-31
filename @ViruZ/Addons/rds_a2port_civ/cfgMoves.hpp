
#define SPEED_STATIC 1e10

class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		Ikarus_Driver = "Ikarus_Driver";
		Ikarus_Cargo = "Ikarus_Cargo";
		Golf_Driver = "Golf_Driver";
		Golf_Cargo01 = "Golf_Cargo01";
		Golf_Cargo02 = "Golf_Cargo02";
		Golf_Cargo03 = "Golf_Cargo03";
		S1203_cargo = "S1203_cargo";
		S1203_cargo01 = "S1203_cargo01";
		S1203_cargo02 = "S1203_cargo02";
		S1203_cargo03 = "S1203_cargo03";
		S1203_driver = "S1203_driver";
		volha_driver = "volha_driver";
		volha_cargo02 = "volha_cargo02";
		volha_cargo01 = "volha_cargo01";
		volha_cargo = "volha_cargo";
		Tractor_Driver = "Tractor_Driver";
		RDS_LyingWounded = "RDS_LyingWounded";

	};
};

class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class Ikarus_Driver: Crew
		{
			file = "\rds_a2port_civ\Ikarus\Data\Anim\Ikarus_driver.rtm";
			interpolateTo[] = {"KIA_Ikarus_Driver",1};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1}; 
			leftHandIKBeg = true;
			leftHandIKEnd = true;
		};
		class KIA_Ikarus_Driver: DefaultDie
		{
			actions = "DeadActions";
			file = "\rds_a2port_civ\Ikarus\Data\Anim\KIA_Ikarus_driver.rtm";
			speed = 0.5;
			looped = 0;
			terminal = 1;
			soundEnabled = 0;
			connectTo[]=
			{
				"Unconscious",
				0.1
			};
		};
		class Ikarus_Cargo: Crew
		{
			file = "\rds_a2port_civ\Ikarus\Data\Anim\Ikarus_cargo.rtm";
			interpolateTo[] = {"KIA_Ikarus_Cargo",1};
		};
		class KIA_Ikarus_Cargo: KIA_Ikarus_Driver
		{
			file = "\rds_a2port_civ\Ikarus\Data\Anim\KIA_Ikarus_Cargo.rtm";
		};


		class Golf_Driver: Ikarus_Driver
		{
			file = "\rds_a2port_civ\Data\Anim\Golf_driver.rtm";
			interpolateTo[] = {"KIA_Golf_Driver",1};
		};
		class KIA_Golf_Driver: KIA_Ikarus_Driver
		{
			file = "\rds_a2port_civ\Data\Anim\KIA_Golf_driver.rtm";
		};
		class Golf_Cargo01: Crew
		{
			file = "\rds_a2port_civ\Data\Anim\Golf_cargo1.rtm";
			interpolateTo[] = {"KIA_Golf_Cargo01",1};
		};
		class KIA_Golf_Cargo01: KIA_Ikarus_Driver
		{
			file = "\rds_a2port_civ\Data\Anim\KIA_Golf_cargo1.rtm";
		};
		class Golf_Cargo02: Crew
		{
			file = "\rds_a2port_civ\Data\Anim\Golf_cargo2.rtm";
			interpolateTo[] = {"KIA_Golf_Cargo02",1};
		};
		class KIA_Golf_Cargo02: KIA_Ikarus_Driver
		{
			file = "\rds_a2port_civ\Data\Anim\KIA_Golf_cargo2.rtm";
		};
		class Golf_Cargo03: Crew
		{
			file = "\rds_a2port_civ\Data\Anim\Golf_cargo3.rtm";
			interpolateTo[] = {"KIA_Golf_Cargo03",1};
		};
		class KIA_Golf_Cargo03: KIA_Ikarus_Driver
		{
			file = "\rds_a2port_civ\Data\Anim\KIA_Golf_cargo3.rtm";
		};
 
		class Tractor_Driver: Crew
		{
			file = "\rds_a2port_civ\Data\Anim\tractor_driver.rtm";
			interpolateTo[] = {"KIA_Truck_driver",1};
		};
//s1203


		class S1203_cargo: Crew
		{
			file = "\rds_a2port_civ\data\Anim\S1203_cargo01";
			interpolateTo[] = {"S1203_KIA_cargo",1};
			speed = 1e+010;
		};
		class S1203_KIA_cargo: DefaultDie
		{
			actions = "DeadActions";
			file = "\rds_a2port_civ\data\Anim\S1203_KIA_cargo01";
			speed = 1e+010;
			terminal = 1;
			soundEnabled = 0;
			looped = 0;
			connectTo[] = {"Unconscious",0.1};
		};
		class S1203_cargo01: Crew
		{
			file = "\rds_a2port_civ\data\Anim\S1203_cargo02";
			interpolateTo[] = {"S1203_KIA_cargo01",1};
			speed = 1e+010;
		};
		class S1203_KIA_cargo01: DefaultDie
		{
			actions = "DeadActions";
			file = "\rds_a2port_civ\data\Anim\S1203_KIA_cargo02";
			speed = 1e+010;
			terminal = 1;
			soundEnabled = 0;
			looped = 0;
			connectTo[] = {"Unconscious",0.1};
		};
		class S1203_cargo02: Crew
		{
			file = "\rds_a2port_civ\data\Anim\S1203_cargo03";
			interpolateTo[] = {"S1203_KIA_cargo02",1};
			speed = 1e+010;
		};
		class S1203_KIA_cargo02: DefaultDie
		{
			actions = "DeadActions";
			file = "\rds_a2port_civ\data\Anim\S1203_KIA_cargo03";
			speed = 1e+010;
			terminal = 1;
			soundEnabled = 0;
			looped = 0;
			connectTo[] = {"Unconscious",0.1};
		};
		class S1203_cargo03: Crew
		{
			file = "\rds_a2port_civ\data\Anim\S1203_KIA_Cargo04";
			interpolateTo[] = {"S1203_KIA_cargo03",1};
			speed = 1e+010;
		};
		class S1203_KIA_cargo03: DefaultDie
		{
			actions = "DeadActions";
			file = "\rds_a2port_civ\data\Anim\S1203_Cargo04";
			speed = 1e+010;
			terminal = 1;
			soundEnabled = 0;
			looped = 0;
			connectTo[] = {"Unconscious",0.1};
		};
		class S1203_driver: Ikarus_Driver
		{
			file = "\rds_a2port_civ\data\Anim\S1203_driver";
			interpolateTo[] = {"S1203_KIA_driver",1};
			speed = 1e+010;
		};
		class S1203_KIA_driver: DefaultDie
		{
			actions = "DeadActions";
			file = "\rds_a2port_civ\data\Anim\S1203_KIA_driver";
			speed = 1e+010;
			terminal = 1;
			soundEnabled = 0;
			looped = 0;
			connectTo[] = {"Unconscious",0.1};
		};
//gaz24

		class volha_cargo: Crew
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo";
			interpolateTo[] = {"volha_KIA_cargo",1};
			speed = 1e+010;
		};
		class volha_KIA_cargo: DefaultDie
		{
			actions = "DeadActions";
			file = "\rds_a2port_civ\data\anim\volha_KIA_cargo01";
			speed = 1e+010;
			terminal = 1;
			soundEnabled = 0;
			looped = 0;
			connectTo[] = {"Unconscious",0.1};
		};
		class volha_cargo01: Crew
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo01";
			interpolateTo[] = {"volha_KIA_cargo01",1};
			connectTo[] = {"volha_cargo01",0.1,"volha_cargo01_V1",0.1,"volha_cargo01_V2",0.1,"volha_cargo01_V3",0.1};
			equivalentTo = "volha_cargo01";
			variantsAI[] = {"volha_cargo01",0.6,"volha_cargo01_V1",0.1,"volha_cargo01_V2",0.15,"volha_cargo01_V3",0.07};
			variantAfter[] = {5,10,20};
			speed = 0.3;
		};
		class volha_cargo01_v1: volha_cargo01
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo01_v1";
			interpolateTo[] = {"volha_KIA_cargo01",1};
			connectTo[] = {"volha_Cargo01",0.1};
			variantAfter[] = {4,4,4};
			speed = 0.246;
		};
		class volha_cargo01_v2: volha_cargo01
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo01_v2";
			interpolateTo[] = {"volha_KIA_cargo01",1};
			connectTo[] = {"volha_Cargo01",0.1};
			variantAfter[] = {4,4,4};
			speed = 0.246;
		};
		class volha_cargo01_v3: volha_cargo01
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo01_v3";
			interpolateTo[] = {"volha_KIA_cargo01",1};
			connectTo[] = {"volha_Cargo01",0.1};
			variantAfter[] = {4,4,4};
			speed = 0.246;
		};
		class volha_cargo01_v4: volha_cargo01
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo01_v4";
			interpolateTo[] = {"volha_KIA_cargo01",1};
			connectTo[] = {"volha_Cargo01",0.1};
			variantAfter[] = {4,4,4};
			speed = 0.246;
		};
		class volha_cargo01_v5: volha_cargo01
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo01_v5";
			interpolateTo[] = {"volha_KIA_cargo01",1};
			connectTo[] = {"volha_Cargo01",0.1};
			variantAfter[] = {4,4,4};
			speed = 0.246;
		};
		class volha_KIA_cargo01: DefaultDie
		{
			actions = "DeadActions";
			file = "\rds_a2port_civ\data\anim\volha_KIA_cargo02";
			speed = 1e+010;
			terminal = 1;
			soundEnabled = 0;
			looped = 0;
			connectTo[] = {"Unconscious",0.1};
		};
		class volha_cargo02: Crew
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo02";
			interpolateTo[] = {"volha_KIA_cargo02",1};
			connectTo[] = {"volha_cargo02",0.1,"volha_cargo02_V1",0.1,"volha_cargo02_V2",0.1,"volha_cargo02_V3",0.1};
			equivalentTo = "volha_cargo02";
			variantsAI[] = {"volha_cargo02",0.6,"volha_cargo02_V1",0.1,"volha_cargo02_V2",0.15,"volha_cargo02_V3",0.07};
			variantAfter[] = {5,10,20};
			speed = 0.3;
		};
		class volha_cargo02_v1: volha_cargo02
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo02_v1";
			interpolateTo[] = {"volha_KIA_cargo02",1};
			connectTo[] = {"volha_Cargo02",0.1};
			variantAfter[] = {4,4,4};
			speed = 0.246;
		};
		class volha_cargo02_v2: volha_cargo02
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo02_v2";
			interpolateTo[] = {"volha_KIA_cargo02",1};
			connectTo[] = {"volha_Cargo02",0.1};
			variantAfter[] = {4,4,4};
			speed = 0.246;
		};
		class volha_cargo02_v3: volha_cargo02
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo02_v3";
			interpolateTo[] = {"volha_KIA_cargo02",1};
			connectTo[] = {"volha_Cargo02",0.1};
			variantAfter[] = {4,4,4};
			speed = 0.246;
		};
		class volha_cargo02_v4: volha_cargo02
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo02_v4";
			interpolateTo[] = {"volha_KIA_cargo02",1};
			connectTo[] = {"volha_Cargo02",0.1};
			variantAfter[] = {4,4,4};
			speed = 0.246;
		};
		class volha_cargo02_v5: volha_cargo02
		{
			file = "\rds_a2port_civ\data\anim\volha_cargo02_v5";
			interpolateTo[] = {"volha_KIA_cargo02",1};
			connectTo[] = {"volha_Cargo02",0.1};
			variantAfter[] = {4,4,4};
			speed = 0.246;
		};

		class volha_KIA_cargo02: DefaultDie
		{
			actions = "DeadActions";
			file = "\rds_a2port_civ\data\anim\volha_KIA_cargo03";
			speed = 1e+010;
			terminal = 1;
			soundEnabled = 0;
			looped = 0;
			connectTo[] = {"Unconscious",0.1};
		};
		class volha_driver: Crew
		{
			file = "\rds_a2port_civ\data\anim\volha_driver";
			interpolateTo[] = {"volha_KIA_Driver",1};
			speed = 1e+010;
		};
		class volha_KIA_Driver: DefaultDie
		{
			actions = "DeadActions";
			file = "\rds_a2port_civ\data\anim\volha_KIA_Driver";
			speed = 1e+010;
			terminal = 1;
			soundEnabled = 0;
			looped = 0;
			connectTo[] = {"Unconscious",0.1};
		};


//a3 fix

		class KIA_Truck_Driver: DefaultDie
		{
			actions="DeadActions";
			speed=0.5;
			looped=0;
			terminal=1;
			file="A3\soft_f_beta\Truck_02\data\Anim\KIA_Truck_02_Driver.rtm";
			connectTo[]=
			{
				"Unconscious",
				0.1
			};
		};
		class KIA_Truck_Cargo01: KIA_Truck_Driver
		{
			file="A3\soft_f_beta\Truck_02\data\Anim\KIA_Truck_02_Cargo04.rtm";
		};
		class KIA_Truck_Cargo02: KIA_Truck_Driver
		{
			file="A3\soft_f_beta\Truck_02\data\Anim\KIA_Truck_02_Cargo04.rtm";
		};
		class KIA_Truck_Cargo03: KIA_Truck_Driver
		{
			file="A3\soft_f_beta\Truck_02\data\Anim\KIA_Truck_02_Cargo04.rtm";
		};
		class KIA_Truck_Cargo04: KIA_Truck_Driver
		{
			file="A3\soft_f_beta\Truck_02\data\Anim\KIA_Truck_02_Cargo04.rtm";
		};
		class Acts_LyingWounded_loop;
		class RDS_LyingWounded: Acts_LyingWounded_loop
		{
			actions = "CargoActions";
			collisionShape = "A3\anims_f\Data\Geom\Sdr\geom_empty.p3d";
			variantsPlayer[] = {"RDS_LyingWounded_loop1",0.33,"RDS_LyingWounded_loop2",0.33,"RDS_LyingWounded_loop3",0.34};
			equivalentTo = "RDS_LyingWounded";
		};
		class RDS_LyingWounded_loop1: RDS_LyingWounded
		{
			file = "\a3\Anims_F_EPA\data\Anim\sdr\cts\Custom\A_m01-02\Acts_LyingWounded01.rtm";
			speed = 0.04;
			looped = 0;
			ConnectTo[] = {"RDS_LyingWounded",0.0001};
			InterpolateTo[] = {"RDS_LyingWounded",0.0001};
		};
		class RDS_LyingWounded_loop2: RDS_LyingWounded
		{
			file = "\a3\Anims_F_EPA\data\Anim\sdr\cts\Custom\A_m01-02\Acts_LyingWounded02.rtm";
			speed = 0.0342;
			looped = 0;
			ConnectTo[] = {"RDS_LyingWounded",0.0001};
			InterpolateTo[] = {"RDS_LyingWounded",0.0001};
		};
		class RDS_LyingWounded_loop3: RDS_LyingWounded
		{
			file = "\a3\Anims_F_EPA\data\Anim\sdr\cts\Custom\A_m01-02\Acts_LyingWounded03.rtm";
			looped = 0;
			speed = 0.0405;
			ConnectTo[] = {"RDS_LyingWounded",0.0001};
			InterpolateTo[] = {"RDS_LyingWounded",0.0001};
		};


	};
};