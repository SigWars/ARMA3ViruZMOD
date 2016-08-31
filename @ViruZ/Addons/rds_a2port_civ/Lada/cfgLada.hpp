
	class RDS_Lada_Base: Car_F
	{
		model="\rds_a2port_civ\Lada\Lada";
		icon="\rds_a2port_civ\data\map_ico\icon_skoda_ca.paa";
		picture = "\rds_a2port_civ\data\ico\vaz2103_pic_ca.paa";
		mapsize=5;

		displayName="VAZ-2103";

		driveraction = "Golf_Driver";
		getInRadius = 1.5;

		attenuationEffectType = "OpenCarAttenuation";
		armor=22;
		cost=10000;
		transportMaxBackpacks=6;
		transportSoldier=3;
		wheelDamageRadiusCoef=0.9;
		wheelDestroyRadiusCoef=0.4;
		maxFordingDepth=0.5;
		waterResistance=1;
		crewCrashProtection=0.25;

		driverLeftHandAnimName="drivewheel";
		driverRightHandAnimName="";
		driverRightLegAnimName = "pedalR";

		memoryPointSupply = "supply";
		supplyRadius = 0.5;
		unitInfoType = "RDS_RscUnitInfoCar";
		//showWeaponCargo=1;
		soundAttenuationCargo[]={0.5};
		#include "sounds.hpp"
		class Turrets
		{

		};
		class TransportItems {
			class _xx_rds_car_FirstAidKit {
				name = "rds_car_FirstAidKit";
				count = 1;
			};
			class _xx_rds_car_warning_triangle_to11 {
				name = "rds_car_warning_triangle_to11";
				count = 1;
			};
		};
		magazines[]=
		{
			"rds_empty_proxy",
			"rds_car_FirstAidKit_proxy",
			"rds_car_warning_triangle_to11_proxy"
		};



		cargoaction[] = {"Golf_Cargo01", "Golf_Cargo02", "Golf_Cargo02"};

		memorypointsgetincargo[] = {"pos cargo 1", "pos cargo 2", "pos cargo 3", "pos cargo 4"};
		memorypointsgetincargodir[] = {"pos cargo dir 1", "pos cargo dir 2", "pos cargo dir 3", "pos cargo dir 4"};
		driverDoor="Door_LF";
		cargoDoors[]=
		{
			"Door_RF",
			"Door_LB",
			"Door_RB"
		};
		driverCompartments="Compartment1";
		cargoCompartments[]=
		{
			"Compartment1"
		};
		class AnimationSources: AnimationSources
		{
			class Door_LF
			{
				source="door";
				animPeriod=1.0;
				sound = "RDS_Lada_Door";
				soundPosition = "door_1_1_axis";
			};
			class Door_LB: Door_LF {
				soundPosition = "door_1_2_axis";};
			class Door_RB: Door_LF {
				soundPosition = "door_2_2_axis";};
			class Door_RF: Door_LF {
				soundPosition = "door_2_1_axis";};
			class Trunk: Door_LF {
				sound = "RDS_Trunk";
				soundPosition = "tailgate_axis";
			};
			class blinker_L: Door_LF
			{
				sound = "RDS_Blinker";
				soundPosition = "water_axis";
				animPeriod=0.35;
			};
			class blinker_R: blinker_L  {};
		};
		class UserActions
		{
			class openDoors
			{
				displayName = Open Trunk;
				position = "pos cargo dir 4";
				radius = 1;
				showWindow = 0;
				condition = "(this animationPhase 'trunk' < 0.5)";
				statement = "this animateDoor ['trunk',1]";
				onlyForPlayer =0;
			};
			class closeDoors:  openDoors
			{
				displayName = Close Trunk;
				condition = "(this animationPhase 'trunk' > 0.5)";
				statement = "this animateDoor ['trunk',0]";
			};
		};
		class Attributes {
			class ObjectTexture {
				control = "ObjectTexture";
				data = "ObjectTexture";
				displayName = "Skin";
				tooltip = "Texture and material set applied on the object.";
			};
			class rds_random_spare {
				collapsed = 1;
				displayName = "Random spare wheel control";
				tooltip = "Define if spare wheels spawning behaviour.";
				property = "rds_random_spare";
				control = "Combo";
				expression = "_this setVariable ['%s', _value,true];";
				defaultValue = 0;
				typeName = "NUMBER";
				class values {
					class Random {
						name = "Random";
						value = 0;
						default = 0;
					};
					class Enabled {
						name = "Always";
						value = 1;
						default = 1;
					};
					class Disabled {
						name = "Never";
						default = 2;
						value = 2;
					};
				};
			};
		};
		class EventHandlers: EventHandlers
		{
			class RDS_Civ_EH
			{
				init			= "[_this select 0,'RDS_Sparewheel_lada'] spawn rds_fnc_random_spareWheel";
				containerOpened = " (_this + [0,'trunk']) call rds_fnc_containerActions";
				containerClosed = " (_this + [1,'trunk']) call rds_fnc_containerActions";
			};
		};
		class HitPoints: HitPoints
		{
			class HitLFWheel: HitLFWheel
			{
				armor=0.175;
				passThrough=0.3;
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				armor=0.175;
				passThrough=0.3;
			};
			class HitRFWheel: HitRFWheel
			{
				armor=0.175;
				passThrough=0.3;
			};
			class HitRF2Wheel: HitRF2Wheel
			{
				armor=0.175;
				passThrough=0.3;
			};
			class HitFuel
			{
				armor=0.5;
				material=-1;
				name="palivo";
				visual="";
				passThrough=0.2;
			};
			class HitEngine
			{
				armor=0.5;
				material=-1;
				name="motor";
				visual="";
				passThrough=0.2;
			};
			class HitBody: HitBody
			{
				name="karoserie";
				visual="camo1";
				passThrough=1;
			};
			class HitGlass1: HitGlass1
			{
				armor=0.1;
			};
			class HitGlass2: HitGlass2
			{
				armor=0.05;
			};
			class HitGlass3: HitGlass3
			{
				armor=0.05;
			};
			class HitGlass4: HitGlass4
			{
				visual="glass4";
				armor=0.05;
			};
			class HitGlass5: HitGlass5
			{
				armor=0.05;
			};
			class HitGlass6: HitGlass6
			{
				armor=0.05;
			};
		};
		getInAction="GetInOffroad";
		getOutAction="GetOutLow";
		cargoGetInAction[]=
		{
			"GetInLow"
		};
		cargoGetOutAction[]=
		{
			"GetOutLow"
		};
		memorypointtrackbll = "Stopa ZLL";
		memorypointtrackblr = "Stopa ZLP";
		memorypointtrackbrl = "Stopa ZPL";
		memorypointtrackbrr = "Stopa ZPP";
		memorypointtrackfll = "Stopa PLL";
		memorypointtrackflr = "Stopa PLP";
		memorypointtrackfrl = "Stopa PPL";
		memorypointtrackfrr = "Stopa PPP";

		dustFrontLeftPos = "Stopa PPL";
		dustFrontRightPos = "Stopa PLP";
		dustBackLeftPos = "Stopa ZLL";
		dustBackRightPos = "Stopa ZLP";

		class Damage {
			mat[] =
			{
				"rds_a2port_civ\Lada\Data\Lada_chrome.rvmat",
				"rds_a2port_civ\Lada\Data\Lada_chrome.rvmat",
				"rds_a2port_civ\Lada\Data\Lada_chrome_destruct.rvmat",

				"rds_a2port_civ\Lada\Data\Lada_glass.rvmat",
				"rds_a2port_civ\Lada\Data\Lada_glass_damage.rvmat",
				"rds_a2port_civ\Lada\Data\Lada_glass_damage.rvmat",

				"rds_a2port_civ\Lada\Data\Lada_glass_in.rvmat",
				"rds_a2port_civ\Lada\Data\Lada_glass_in_damage.rvmat",
				"rds_a2port_civ\Lada\Data\Lada_glass_in_damage.rvmat",

				"rds_a2port_civ\Lada\Data\Lada_mat.rvmat",
				"rds_a2port_civ\Lada\Data\Lada_mat_damage.rvmat",
				"rds_a2port_civ\Lada\Data\Lada_mat_destruct.rvmat",

				"a3\data_f\default.rvmat",
				"a3\data_f\default.rvmat",
				"a3\data_f\default_destruct.rvmat"
			};
			tex[] = {};
		};
		class Exhausts
		{
			class Exhaust1
			{
				position="vyfuk start";
				direction="vyfuk konec";
				effect="ExhaustEffectOffroad";
			};
		};
		class Reflectors
		{
			class LSvetla
			{
				color[]={800,900,650};
				ambient[]={2,2,2};
				position="L svetlo";
				direction="konec L svetla";
				hitpoint="L svetlo";
				selection="L svetlo";
				size=1;
				innerAngle=30;
				outerAngle=100;
				coneFadeCoef=10;
				intensity=1.5;
				useFlare=1;
				dayLight=0;
				flareSize=0.85000002;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=0.25;
					hardLimitStart=30;
					hardLimitEnd=60;
				};
			};
			class RSvetla: LSvetla
			{
				position="P svetlo";
				direction="konec P svetla";
				hitpoint="P svetlo";
				selection="P svetlo";
			};
		};
		aggregateReflectors[]=
		{
			{"LSvetla"},{"RSvetla"}
		};

		class RenderTargets
		{
			class LeftMirror
			{
				renderTarget="rendertarget0";
				class CameraView1
				{
					pointPosition="m1p";
					pointDirection="m1d";
					renderQuality=2;
					renderVisionMode=4;
					fov=0.5;
				};
			};
			class RightMirror
			{
				renderTarget="rendertarget1";
				class CameraView1
				{
					pointPosition="m2p";
					pointDirection="m2d";
					renderQuality=2;
					renderVisionMode=4;
					fov=0.7;
				};
			};
			class BackMirror
			{
				renderTarget="rendertarget2";
				class CameraView1
				{
					pointPosition="m3p";
					pointDirection="m3d";
					renderQuality=2;
					renderVisionMode=4;
					fov=0.7;
				};
			};
		};
		#include "PhysX_Lada.hpp"
		class textureSources
		{
			class standard
			{
				displayName="White";
				AUTHOR_MACRO
				textures[]=
				{
					"rds_a2port_civ\Lada\Data\lada_white_co.paa",
					"rds_a2port_civ\Lada\Data\lada_glass_ca.paa"
				};
				factions[]=
				{
					rds_rus_civ
				};
			};
			class Red: standard
			{
				displayName="Red";
				AUTHOR_MACRO
				textures[]=
				{
					"rds_a2port_civ\Lada\Data\lada_red_co.paa",
					"rds_a2port_civ\Lada\Data\lada_glass_ca.paa"
				};
			};
			class Green: standard
			{
				displayName="Green";
				AUTHOR_MACRO
				textures[]=
				{
					"rds_a2port_civ\Lada\Data\lada_eciv1_co.paa",
					"rds_a2port_civ\Lada\Data\Lada_glass_ECIV1_CA.paa"
				};
			};
			class Decorated: standard
			{
				displayName="Decorated";
				AUTHOR_MACRO
				textures[]=
				{
					"rds_a2port_civ\Lada\Data\lada_eciv2_co.paa",
					"rds_a2port_civ\Lada\Data\Lada_glass_ECIV2_CA.paa"
				};
			};
		};
		textureList[]=
		{
			"standard", 1,
			"Red", 0,
			"Green",0,
			"Decorated",0
		};
		hiddenselections[] = {"Camo1", "Camo2"};
		hiddenselectionstextures[] = {"rds_a2port_civ\Lada\Data\lada_white_co.paa","rds_a2port_civ\Lada\Data\lada_glass_ca.paa"};
	};
	class RDS_Lada_Civ_Base: RDS_Lada_Base
	{
		accuracy = 0.5;
		crew = "RDS_Citizen1";
		faction="rds_rus_civ";
		side = 3;
	};

	class RDS_Lada_Civ_01: RDS_Lada_Civ_Base
	{
		scope=2;
		AUTHOR_MACRO
	};
	class RDS_Lada_Civ_02: RDS_Lada_Civ_01
	{
		scope=2;
		AUTHOR_MACRO
		crew = "RDS_Citizen3";
		displayName="VAZ-2103 (Red)";
		hiddenselectionstextures[] = {"rds_a2port_civ\Lada\Data\Lada_red_CO.paa","rds_a2port_civ\Lada\Data\lada_glass_ca.paa"};
	};
	class RDS_Lada_Civ_03: RDS_Lada_Civ_01
	{
		crew = "RDS_Citizen2";
		AUTHOR_MACRO
		displayName="VAZ-2103 (Green)";
		hiddenselectionstextures[] = {"rds_a2port_civ\Lada\Data\lada_eciv1_co.paa","rds_a2port_civ\Lada\Data\Lada_glass_ECIV1_CA.paa"};
	};
	class RDS_Lada_Civ_04: RDS_Lada_Civ_03
	{
		crew = "RDS_Citizen4";
		AUTHOR_MACRO
		displayName="VAZ-2103 (Decorated)";
		hiddenselectionstextures[] = {"rds_a2port_civ\Lada\Data\lada_eciv2_co.paa","rds_a2port_civ\Lada\Data\Lada_glass_ECIV2_CA.paa"};
	};

	class RDS_Lada_Civ_05: RDS_Lada_Civ_01
	{
		crew = "RDS_Policeman";
		AUTHOR_MACRO
		displayName="VAZ-2103 (Militia)";
		model="\rds_a2port_civ\Lada\Lada_LM";
		picture = "\rds_a2port_civ\data\ico\vaz2103_police_pic_ca.paa";
		hiddenselectionstextures[] = {"rds_a2port_civ\Lada\Data\lada_lm_co.paa"};
		class Reflectors: Reflectors
		{
			class Left: LSvetla {};
			class Right: RSvetla {};
		};
		class textureSources
		{
			class standard
			{
				displayName="Police";
				AUTHOR_MACRO
				textures[]=
				{
					"\rds_a2port_civ\Lada\data\lada_lm_co.paa"
				};
				factions[]=
				{
					rds_rus_civ
				};
			};
		};
		textureList[]=
		{
			"standard", 1
		};
		class newTurret;
		class Turrets
		{
			class FakeTurret: newTurret
			{
				body = "";
				gun = "";
				gunnerName = "Siren handler turret";
				gunnerCompartments = "Compartment33";
                hasGunner = 0;
                dontCreateAI=1;
                cantCreateAI=1;
                commanding=7;
                primaryGunner = 0;
				class Reflectors
				{
					class Majak1 {
						//ambient[] = {0.01, 0.01, 0.1, 1};
						//color[] = {0.1, 0.2, 0.8, 1};
						color[] = {0.1, 0.25, 0.8};
						ambient[] = {0.001, 0.00025, 2e-005};
						intensity = 10000;
						size = 1;
						innerAngle = 125;
						outerAngle = 175;
						coneFadeCoef = 10;
						direction = "majak ligth 1 end";
						position = "majak ligth 1 start";
						useFlare = 1;
						flareSize = 1.5;
						flareMaxDistance = 50;
						selection = "majak";
						hitpoint = "";
						activeLight = 1;
						dayLight = 1;
						class Attenuation {
							start = 0;
							constant = 0;
							linear = 15;
							quadratic = 7;
							hardLimitStart = 7;
							hardLimitEnd = 10;
						};
					};
					class Majak2: Majak1 {
						direction = "majak ligth 2 end";
						hitpoint = "";
						position = "majak ligth 2 start";
						selection = "";
					};
				};
			};
		};
		class UserActions: UserActions
		{
			class Syrena
			{
				displayName = Siren toggle;
				position = "pos driver";
				radius = 3;
				showWindow = 0;
				condition = "player == driver this";
				statement = "[this] spawn rds_fnc_syrena";
				onlyForPlayer =1;
				shortcut="TactToggle";
			};
			class Syrena_dzwiek: Syrena
			{
				displayName = Siren toggle sound;
				condition = "player == driver this && this getVariable ['rds_siren',false]";
				statement = "this setVariable ['rds_siren_sound',not(this getVariable ['rds_siren_sound',false]),true] ";
				shortcut="binocular";
			};
		};
		class AnimationSources: AnimationSources
		{
			class siren_handler
			{
				source = "user";
				animPeriod = 0.000001;
				initPhase = 0;
				mass=1;
				displayName="turn on siren";
				onPhaseChanged="_this spawn rds_fnc_syrena";
			};
		};
	};

 	class RDS_Lada_Wreck: Wreck_base_F
	{
		_generalmacro = "RDS_Lada_Wreck";
		author = "Bohemia Interactive";
		displayname = "VAZ-2103 Wreck";
		icon = "iconObject_2x5";
		mapsize = 4.91;
		model="\rds_a2port_civ\Lada\Lada_wrecked";
		scope = 2;
	};
