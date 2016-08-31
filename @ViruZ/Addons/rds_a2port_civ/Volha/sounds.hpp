		//insideSoundCoef=0.95;
		insideSoundCoef = 1;
		//soundGear[]={"rhsafrf\addons\rhs_a2port_car\sounds\Gear_Change",2,1};

		soundGetIn[]={"rds_a2port_civ\data\sounds\lada_door",db+1,1,9};
		soundGetOut[]={"rds_a2port_civ\data\sounds\lada_door",db+1,1, 25};

		soundEngineOnInt[] = {"rds_a2port_civ\data\sounds\lada_int_start", db+15, 1.0};
		soundEngineOnExt[] = {"rds_a2port_civ\data\sounds\lada_ext_start", db+15, 1.0, 200};
		soundEngineOffInt[] = {"rds_a2port_civ\data\sounds\lada_int_stop", db+15, 1.0};
		soundEngineOffExt[] = {"rds_a2port_civ\data\sounds\lada_ext_stop", db+15, 1.0, 200};


class	Sounds
{

	// warp	factor
	#define	FACTOR(val,from,to)	(val factor[from,to])
	// RANGE(val,	begin, band, end,	band)
	#define	RANGE(val,from,band0,to,band1) GAZ24_FACTOR2(val,from,(from+band0),to,(to+band1))
	// GAZ24_FACTOR2(val,	0, 400,	1200,	2000)
	#define	GAZ24_FACTOR2(val,from0,to0,from1,to1) (FACTOR(val,from0,to0)	*	FACTOR(val,to1,from1))

	// redRpm
	#define	GAZ24_MAX_RPM	4900
	// scaled	rpm	to 0 - 1
	#define	GAZ24_RPM(rpm) (rpm/GAZ24_MAX_RPM)

	// specialized FACTOR	for	rpm
	#define	GAZ24_FACTOR_RPM(from,to)	FACTOR(GAZ24_RPM(rpm),GAZ24_RPM(from),GAZ24_RPM(to))
	// specialized peak	for	rpm
	#define	GAZ24_FACTOR2_RPM(from0,to0,from1,to1) (GAZ24_FACTOR_RPM(from0,to0)	*	GAZ24_FACTOR_RPM(to1,from1))
	// specialized peak, different definition, version for rpm
	#define	RANGE_RPM(from,band0,to,band1) GAZ24_FACTOR2_RPM(from,(from+band0),to,(to+band1))

	#define GAZ24_HZ_IDLE GAZ24_FACTOR_RPM(284,817)
	#define GAZ24_HZ_RPM1 GAZ24_FACTOR_RPM(639,1491)
	#define GAZ24_HZ_RPM2 GAZ24_FACTOR_RPM(923,2201)
	#define GAZ24_HZ_RPM3 GAZ24_FACTOR_RPM(1598,2166)
	#define GAZ24_HZ_RPM4 GAZ24_FACTOR_RPM(2343,3480)
	#define GAZ24_HZ_RPM5 GAZ24_FACTOR_RPM(2983,4403)
	#define GAZ24_HZ_RPM6 GAZ24_FACTOR_RPM(3622,4900)

	#define GAZ24_VOLUME_IDLE GAZ24_FACTOR2_RPM(284,497,639,781)
	#define GAZ24_VOLUME_RPM1 GAZ24_FACTOR2_RPM(618,781,923,1491)
	#define GAZ24_VOLUME_RPM2 GAZ24_FACTOR2_RPM(888,1456,1633,2201)
	#define GAZ24_VOLUME_RPM3 GAZ24_FACTOR2_RPM(1598,2166,2343,2912)
	#define GAZ24_VOLUME_RPM4 GAZ24_FACTOR2_RPM(2308,2876,2983,3458)
	#define GAZ24_VOLUME_RPM5 GAZ24_FACTOR2_RPM(2947,3409,3657,4367)
	#define GAZ24_VOLUME_RPM6 GAZ24_FACTOR_RPM(3622,4432)







	class	Idle_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_ext_Idle", db+8,	1, 150};
		frequency	=	0.9	+	GAZ24_HZ_IDLE*0.2;
		volume = engineOn*camPos*GAZ24_VOLUME_IDLE;
	};
	class	Engine
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_ext_acceleration",	db+8,1, 200};
		frequency	=	0.8	+	GAZ24_HZ_RPM1*0.2;
		volume = engineOn*camPos*GAZ24_VOLUME_RPM1;
	};
	class	Engine1_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_ext_low",	db+7,1, 240};
		frequency	=	0.8	+	GAZ24_HZ_RPM2*0.2;
		volume = engineOn*camPos*GAZ24_VOLUME_RPM2;
	};
	class	Engine2_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_ext_low",	db+7,1, 280};
		frequency	=	0.8	+	GAZ24_HZ_RPM3*0.2;
		volume = engineOn*camPos*GAZ24_VOLUME_RPM3;
	};
	class	Engine3_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_ext_mid",	db+7,1, 320};
		frequency	=	0.8	+	GAZ24_HZ_RPM4*0.2;
		volume = engineOn*camPos*GAZ24_VOLUME_RPM4;
	};
	class	Engine4_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_ext_high",	db+7,1, 360};
		frequency	=	0.8	+	GAZ24_HZ_RPM5*0.2;
		volume = engineOn*camPos*GAZ24_VOLUME_RPM5;
	};
	class	Engine5_ext
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_ext_high",	db+7,1, 420};
		frequency	=	0.95	+	GAZ24_HZ_RPM6*0.15;
		volume = engineOn*camPos*GAZ24_VOLUME_RPM6;
	};

		/*   POD PLYNEM EXTERNI  */

  	class IdleThrust
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_ext_Idle", db+6,1, 200};
		frequency	=	0.9	+	GAZ24_HZ_IDLE*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_IDLE;
  	};
  	class EngineThrust
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_ext_acceleration", db+5,1, 250};
		frequency	=	0.8	+	GAZ24_HZ_RPM1*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM1;
  	};
  	class Engine1_Thrust_ext
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_ext_low", db+4,1, 280};
		frequency	=	0.8	+	GAZ24_HZ_RPM2*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM2;
  	};
  	class Engine2_Thrust_ext
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_ext_low", db+3,1, 320};
		frequency	=	0.8	+	GAZ24_HZ_RPM3*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM3;
  	};
  	class Engine3_Thrust_ext
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_ext_mid", db+2,1, 360};
		frequency	=	0.8	+	GAZ24_HZ_RPM4*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM4;
  	};
  	class Engine4_Thrust_ext
 	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_ext_high", db+0,1, 400};
		frequency	=	0.8	+	GAZ24_HZ_RPM5*0.3;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM5;
  	};
  	class Engine5_Thrust_ext
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_ext_high", db+2,1, 450};
		frequency	=	0.9	+	GAZ24_HZ_RPM6*0.2;
		volume = engineOn*camPos*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM6;
  	};

		/*  konec pod plynem externi */

		/* INTERNI OZVUCENI BEZ PLYNU */

	class	Idle_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_int_Idle", db+3,	1};
		frequency	=	0.9	+	GAZ24_HZ_IDLE*0.2;
		volume = engineOn*(1-camPos)*GAZ24_VOLUME_IDLE;
	};
	class	Engine_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_int_acceleration",	db+1,1 };
		frequency	=	0.8	+	GAZ24_HZ_RPM1*0.2;
		volume = engineOn*(1-camPos)*GAZ24_VOLUME_RPM1;
	};
	class	Engine1_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_int_low",	db+1,1 };
		frequency	=	0.8	+	GAZ24_HZ_RPM2*0.2;
		volume = engineOn*(1-camPos)*GAZ24_VOLUME_RPM2;
	};
	class	Engine2_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_int_low",	db+1,1 };
		frequency	=	0.8	+	GAZ24_HZ_RPM3*0.2;
		volume = engineOn*(1-camPos)*GAZ24_VOLUME_RPM3;
	};
	class	Engine3_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_int_mid",	db+1,1 };
		frequency	=	0.8	+	GAZ24_HZ_RPM4*0.2;
		volume = engineOn*(1-camPos)*GAZ24_VOLUME_RPM4;
	};
	class	Engine4_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_int_high",	db+1,1 };
		frequency	=	0.8	+	GAZ24_HZ_RPM5*0.2;
		volume = engineOn*(1-camPos)*GAZ24_VOLUME_RPM5;
	};
	class	Engine5_int
	{
		sound[]	=	{"rds_a2port_civ\data\sounds\lada_int_high",	db+1,1 };
		frequency	=	0.95	+	GAZ24_HZ_RPM6*0.15;
		volume = engineOn*(1-camPos)*GAZ24_VOLUME_RPM6;
	};
	/*   POD PLYNEM   */

  	class IdleThrust_int
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_int_acceleration", db+4,1 };
		frequency	=	0.9	+	GAZ24_HZ_IDLE*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_IDLE;
  	};
  	class EngineThrust_int
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_int_low", db+1,1 };
		frequency	=	0.8	+	GAZ24_HZ_RPM1*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM1;
  	};
  	class Engine1_Thrust_int
  	{
   		sound[] = {"rds_a2port_civ\data\sounds\lada_int_low", db+1,1 };
		frequency	=	0.8	+	GAZ24_HZ_RPM2*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM2;
  	};
  	class Engine2_Thrust_int
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_int_mid", db+1,1 };
		frequency	=	0.8	+	GAZ24_HZ_RPM3*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM3;
  	};
  	class Engine3_Thrust_int
  	{
   		sound[] = {"rds_a2port_civ\data\sounds\lada_int_mid", db+1,1 };
		frequency	=	0.8	+	GAZ24_HZ_RPM4*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM4;
  	};
  	class Engine4_Thrust_int
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_int_high", db+1,1 };
		frequency	=	0.8	+	GAZ24_HZ_RPM5*0.3;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM5;
  	};
  	class Engine5_Thrust_int
  	{
    		sound[] = {"rds_a2port_civ\data\sounds\lada_int_high", db+1,1 };
		frequency	=	0.9	+	GAZ24_HZ_RPM6*0.2;
		volume = engineOn*(1-camPos)*(0.4+(0.6*FACTOR(thrust,0.1,1)))*GAZ24_VOLUME_RPM6;
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
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1", db+4, 1.0, 60};
		frequency = "1";
		volume = "camPos*rock*(speed factor[2, 20])";
	};
	class TiresSandOut
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1", db+4, 1.0, 60};
		frequency = "1";
		volume = "camPos*sand*(speed factor[2, 20])";
	};
	class TiresGrassOut
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2", db+4, 1.0, 60};
		frequency = "1";
		volume = "camPos*grass*(speed factor[2, 20])";
	};
	class TiresMudOut
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2", db+4, 1.0, 60};
		frequency = "1";
		volume = "camPos*mud*(speed factor[2, 20])";
	};
	class TiresGravelOut
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1", db+4, 1.0, 60};
		frequency = "1";
		volume = "camPos*gravel*(speed factor[2, 20])";
	};
	class TiresAsphaltOut
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2", db+4, 1.0, 60};
		frequency = "1";
		volume = "camPos*asphalt*(speed factor[2, 20])";
	};
	class NoiseOut
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3", db+4, 1.0, 90};
		frequency = "1";
		volume = "camPos*(damper0 max 0.02)*(speed factor[0, 8])";
	};


/*----------------------------------*/
/*-----------  TIRES INT ---------*/
/*----------------------------------*/

	class TiresRockIn
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1", db+1, 1.0};
		frequency = "1";
		volume = "(1-camPos)*rock*(speed factor[2, 20])";
	};
	class TiresSandIn
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2", db+0, 1.0};
		frequency = "1";
		volume = "(1-camPos)*sand*(speed factor[2, 20])";
	};
	class TiresGrassIn
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2", db+0, 1.0};
		frequency = "1";
		volume = "(1-camPos)*grass*(speed factor[2, 20])";
	};
	class TiresMudIn
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2", db+1, 1.0};
		frequency = "1";
		volume = "(1-camPos)*mud*(speed factor[2, 20])";
	};
	class TiresGravelIn
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1", db+1, 1.0};
		frequency = "1";
		volume = "(1-camPos)*gravel*(speed factor[2, 20])";
	};
	class TiresAsphaltIn
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2", db+1, 1.0};
		frequency = "1";
		volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
	};
	class NoiseIn
	{
		sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3", db+2, 1.0};
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
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int", db-10, 1};
		frequency	=	1;
		volume = engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
	};

	class acceleration_int_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db-10, 1};
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
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking_int", db-10, 1};
		frequency	=	1;
		volume = engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[-01, -0.4])*(Speed Factor[2, 15]);
	};
	class acceleration_int_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration_int", db-10, 1};
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
