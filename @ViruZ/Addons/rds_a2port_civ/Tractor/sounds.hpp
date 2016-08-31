		//insideSoundCoef=0.95;		
		insideSoundCoef = 0;
            attenuationEffectType = "CarAttenuation";

		soundGetIn[]={"rds_a2port_civ\data\sounds\lada_door",db+30,1,9};
		soundGetOut[]={"rds_a2port_civ\data\sounds\lada_door",db+30,1, 25};

		soundEngineOnInt[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-start-1", db+15, 1.0};
		soundEngineOnExt[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-start-1", db+15, 1.0, 200};
		soundEngineOffInt[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-stop-1", db+15, 1.0};
		soundEngineOffExt[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-stop-1", db+15, 1.0, 200};


class	Sounds
{

	// redRpm
	#define	Zetor_MAX_RPM	2500
	// scaled	rpm	to 0 - 1
	#define	Zetor_RPM(rpm) (rpm/Zetor_MAX_RPM)

	// specialized FACTOR	for	rpm
	#define	Zetor_FACTOR_RPM(from,to)	FACTOR(Zetor_RPM(rpm),Zetor_RPM(from),Zetor_RPM(to))
	// specialized peak	for	rpm
	#define	Zetor_FACTOR2_RPM(from0,to0,from1,to1) (Zetor_FACTOR_RPM(from0,to0)	*	Zetor_FACTOR_RPM(to1,from1))
	// specialized peak, different definition, version for rpm
	#define	Zetor_RANGE_RPM(from,band0,to,band1) Zetor_FACTOR2_RPM(from,(from+band0),to,(to+band1))
	

	#define Zetor_HZ_IDLE Zetor_FACTOR_RPM(200,700)
	#define Zetor_HZ_RPM1 Zetor_FACTOR_RPM(650,1000)
	#define Zetor_HZ_RPM2 Zetor_FACTOR_RPM(900,1400)
	#define Zetor_HZ_RPM3 Zetor_FACTOR_RPM(1300,1600)
	#define Zetor_HZ_RPM4 Zetor_FACTOR_RPM(1500,1800)
	#define Zetor_HZ_RPM5 Zetor_FACTOR_RPM(1700,2200)
	#define Zetor_HZ_RPM6 Zetor_FACTOR_RPM(2100,2600)
	
	#define Zetor_VOLUME_IDLE Zetor_FACTOR2_RPM(200,500,600,620)
	#define Zetor_VOLUME_RPM1 Zetor_FACTOR2_RPM(600,650,850,920)
	#define Zetor_VOLUME_RPM2 Zetor_FACTOR2_RPM(900,950,1300,1400)
	#define Zetor_VOLUME_RPM3 Zetor_FACTOR2_RPM(1350,1450,1500,1650)
	#define Zetor_VOLUME_RPM4 Zetor_FACTOR2_RPM(1550,1650,1700,1870)
	#define Zetor_VOLUME_RPM5 Zetor_FACTOR2_RPM(1750,1800,1950,2250)
	#define Zetor_VOLUME_RPM6 Zetor_FACTOR_RPM(2000,2700)
	

	
	class	Idle_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-Idle-4", db+11,	1, 150};
		frequency	=	0.9	+	Zetor_HZ_IDLE*0.2;
		volume = engineOn*camPos*Zetor_VOLUME_IDLE;
	};
	class	Engine
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-acce-1",	db+12,1, 200};
		frequency	=	0.8	+	Zetor_HZ_RPM1*0.2;
		volume = engineOn*camPos*Zetor_VOLUME_RPM1;
	};
	class	Engine1_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-4",	db+11,1, 240};
		frequency	=	0.8	+	Zetor_HZ_RPM2*0.2;
		volume = engineOn*camPos*Zetor_VOLUME_RPM2;
	};
	class	Engine2_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-3",	db+10,1, 280};
		frequency	=	0.8	+	Zetor_HZ_RPM3*0.2;
		volume = engineOn*camPos*Zetor_VOLUME_RPM3;
	};
	class	Engine3_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-1",	db+9,1, 320};
		frequency	=	0.8	+	Zetor_HZ_RPM4*0.2;
		volume = engineOn*camPos*Zetor_VOLUME_RPM4;
	};
	class	Engine4_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-high-2",	db+8,1, 360};
		frequency	=	0.8	+	Zetor_HZ_RPM5*0.2;
		volume = engineOn*camPos*Zetor_VOLUME_RPM5;
	};
	class	Engine5_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-high-2a",	db+8,1, 420};
		frequency	=	0.95	+	Zetor_HZ_RPM6*0.15;
		volume = engineOn*camPos*Zetor_VOLUME_RPM6;
	};
	
		/*   POD PLYNEM EXTERNI  */
		
  	class IdleThrust
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-Idle-5", db+6,1, 200};
		frequency	=	0.9	+	Zetor_HZ_IDLE*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_IDLE;
  	};
  	class EngineThrust
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-acce-1", db+5,1, 250};
		frequency	=	0.8	+	Zetor_HZ_RPM1*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM1;
  	};
  	class Engine1_Thrust_ext
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-2", db+4,1, 280};
		frequency	=	0.8	+	Zetor_HZ_RPM2*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM2;
  	};
  	class Engine2_Thrust_ext
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-2", db+3,1, 320};
		frequency	=	0.8	+	Zetor_HZ_RPM3*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM3;
  	};
  	class Engine3_Thrust_ext
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-2", db+2,1, 360};
		frequency	=	0.8	+	Zetor_HZ_RPM4*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM4;
  	};
  	class Engine4_Thrust_ext
 	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-high-1", db0,1, 400};
		frequency	=	0.8	+	Zetor_HZ_RPM5*0.3;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM5;
  	};
  	class Engine5_Thrust_ext
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-high-1", db2,1, 450};
		frequency	=	0.9	+	Zetor_HZ_RPM6*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM6;
  	};  

		/*  konec pod plynem externi */

		/* INTERNI OZVUCENI BEZ PLYNU */

	class	Idle_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-Idle-4", db+9,	1};
		frequency	=	0.9	+	Zetor_HZ_IDLE*0.2;
		volume = engineOn*(1-camPos)*Zetor_VOLUME_IDLE;
	};
	class	Engine_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-acce-1",	db+10,1 };
		frequency	=	0.8	+	Zetor_HZ_RPM1*0.2;
		volume = engineOn*(1-camPos)*Zetor_VOLUME_RPM1;
	};
	class	Engine1_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-4",	db+9,1 };
		frequency	=	0.8	+	Zetor_HZ_RPM2*0.2;
		volume = engineOn*(1-camPos)*Zetor_VOLUME_RPM2;
	};
	class	Engine2_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-3",	db+9,1 };
		frequency	=	0.8	+	Zetor_HZ_RPM3*0.2;
		volume = engineOn*(1-camPos)*Zetor_VOLUME_RPM3;
	};
	class	Engine3_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-3",	db+8,1 };
		frequency	=	0.8	+	Zetor_HZ_RPM4*0.2;
		volume = engineOn*(1-camPos)*Zetor_VOLUME_RPM4;
	};
	class	Engine4_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-high-2",	db+8,1 };
		frequency	=	0.8	+	Zetor_HZ_RPM5*0.2;
		volume = engineOn*(1-camPos)*Zetor_VOLUME_RPM5;
	};
	class	Engine5_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\tractor\ext-tractor-high-2a",	db+6,1 };
		frequency	=	0.95	+	Zetor_HZ_RPM6*0.15;
		volume = engineOn*(1-camPos)*Zetor_VOLUME_RPM6;
	};
	/*   POD PLYNEM   */
		
  	class IdleThrust_int
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-idle-5", db+9,1 };
		frequency	=	0.9	+	Zetor_HZ_IDLE*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_IDLE;
  	};
  	class EngineThrust_int
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-2", db+9,1 };
		frequency	=	0.8	+	Zetor_HZ_RPM1*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM1;
  	};
  	class Engine1_Thrust_int
  	{
   		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-3", db+8,1 };
		frequency	=	0.8	+	Zetor_HZ_RPM2*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM2;
  	};
  	class Engine2_Thrust_int
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-2", db+7,1 };
		frequency	=	0.8	+	Zetor_HZ_RPM3*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM3;
  	};
  	class Engine3_Thrust_int
  	{
   		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-low-2", db+6,1 };
		frequency	=	0.8	+	Zetor_HZ_RPM4*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM4;
  	};
  	class Engine4_Thrust_int
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-high-1", db+5,1 };
		frequency	=	0.8	+	Zetor_HZ_RPM5*0.3;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM5;
  	};
  	class Engine5_Thrust_int
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\tractor\ext-tractor-high-1", db+4,1 };
		frequency	=	0.9	+	Zetor_HZ_RPM6*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*Zetor_VOLUME_RPM6;
  	};  

	class	Movement
	{
		sound	=	"soundEnviron";
		frequency	=	"1";
		volume = "0";
	};
		/*   KONEC POD PLYNEM   */


	/*----------------------------------*/		
 	/*-----------  TIRES EXT ---------*/
	/*----------------------------------*/ 
	
 			class TiresRockOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1", db+6, 1.0, 60};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1", db+6, 1.0, 60};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2", db+6, 1.0, 60};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2", db+6, 1.0, 60};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1", db+6, 1.0, 60};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2", db+6, 1.0, 60};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3", db+8, 1.0, 90};
				frequency = "1";
				volume = "camPos*(damper0 max 0.02)*(speed factor[0, 8])";
			};
			
	/*----------------------------------*/
 	/*-----------  TIRES INT ---------*/
	/*----------------------------------*/

			class TiresRockIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1", db+6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2", db+6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2", db+6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2", db+6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1", db+6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2", db+6, 1.0};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3", db+12, 1.0};
				frequency = "1";
				volume = "(damper0 max 0.1)*(speed factor[0, 8])*(1-camPos)"; //definice INSIDE zvuku
			};
	
	/*------------------------------------------------------------------*/	
	/*-------------- ozvuceni piskani pneumatik EXT -------------*/
	/*------------------------------------------------------------------*/	
		
	/* zvuk na silnici */

		class breaking_ext_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04", db+3, 1, 80};
		frequency	=	1;
		volume = engineOn*camPos*asphalt*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
	};	
	
		class acceleration_ext_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db+3, 1, 80};
		frequency	=	1;
		volume = engineOn*camPos*asphalt*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
	};	
		class turn_left_ext_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db+3, 1, 80};
		frequency	=	1;
		volume = engineOn*camPos*asphalt*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
	};	

		class turn_right_ext_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db+3, 1, 80};
		frequency	=	1;
		volume = engineOn*camPos*asphalt*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
	};	

		/*-----------------------------------------------------------------*/
		/*ozvuceni piskani pneumatik na ostatnich povrsich EXT */
		/*-----------------------------------------------------------------*/
		
		class breaking_ext_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking", db+3, 1, 60};
		frequency	=	1;
		volume = engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15]);
	};	
		class acceleration_ext_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration", db+3,	1, 60};
		frequency	=	1;
		volume = engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1]);
	};	
		class turn_left_ext_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt", db+3, 1, 60};
		frequency	=	1;
		volume = engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15]);
	};	

		class turn_right_ext_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt", db+3, 1, 60};
		frequency	=	1;
		volume = engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15]);
	};	

	
	/*---------------------------------------------------------------------------*/	
	/*-------------- ozvuceni piskani pneumatik INT silnice --------------*/
	/*---------------------------------------------------------------------------*/	

		class breaking_int_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int", db+10, 1};
		frequency	=	1;
		volume = engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
	};	
	
		class acceleration_int_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db+10, 1};
		frequency	=	1;
		volume = engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
	};	
		class turn_left_int_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db+10, 1};
		frequency	=	1;
		volume = engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
	};	
		class turn_right_int_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db+10, 1};
		frequency	=	1;
		volume = engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
	};	

	/*--------------------------------------------------------------------------------------------*/	
	/*-------------- ozvuceni piskani pneumatik na ostatnich povrsich INT -------------*/
	/*--------------------------------------------------------------------------------------------*/	
		class breaking_int_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking_int", db+10, 1};
		frequency	=	1;
		volume = engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[-01, -0.4])*(Speed Factor[2, 15]);
	};	
		class acceleration_int_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration_int", db+10, 1};
		frequency	=	1;
		volume = engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
	};	
		class turn_left_int_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int", db+10,	1};
		frequency	=	1;
		volume = engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
	};	
		class turn_right_int_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int", db+10,	1};
		frequency	=	1;
		volume = engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
	};
};
