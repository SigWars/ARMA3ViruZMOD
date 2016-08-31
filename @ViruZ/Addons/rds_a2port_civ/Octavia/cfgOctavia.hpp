
	class RDS_Octavia_Base: Car_F
	{
		model="\rds_a2port_civ\Octavia\Octavia_ACR";
		icon="\rds_a2port_civ\data\map_ico\icon_Octavia_ca.paa";
		picture = "\rds_a2port_civ\data\ico\octavia_pic_ca.paa";
		mapsize=5;

		displayName="Skoda Octavia II 2.0 TDI";

		HiddenSelections[] = {"camo","camo1"};
		hiddenSelectionsTextures[] = {"\rds_a2port_civ\Octavia\Data\car_body_co.paa","\rds_a2port_civ\Octavia\Data\car_body_m_co.paa"};

		//driveraction = "Golf_Driver";
		getInRadius = 1.5;
		driverAction = "driver_offroad01";

		attenuationEffectType = "OpenCarAttenuation";
		armor=22;
		cost=10000;
		transportMaxBackpacks=6;
		transportSoldier=3;
		wheelDamageRadiusCoef=0.89999998;
		wheelDestroyRadiusCoef=0.40000001;
		maxFordingDepth=0.5;
		waterResistance=1;
		crewCrashProtection=0.25;

		driverLeftHandAnimName="drivewheel";
		driverRightHandAnimName="drivewheel";
		driverRightLegAnimName = "pedalR";

		memoryPointSupply = "supply";
		supplyRadius = 0.5;
		unitInfoType = "RDS_RscUnitInfoCar";

		//heat settings

		afmax = 200;
		htmax = 1800;
		htmin = 60;
		mfact = 0;
		mfmax = 100;
		tbody = 0;

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



		cargoaction[] = {"Golf_Cargo01", "Golf_Cargo02", "Golf_Cargo02", "Golf_Cargo03"};

		memorypointsgetincargo[] = {"pos cargo 1", "pos cargo 2", "pos cargo 3"};
		memorypointsgetincargodir[] = {"pos cargo dir 1", "pos cargo dir 2", "pos cargo dir 3"};
		driverDoor="Door_LF";
		cargoDoors[]=
		{
		};
		driverCompartments="Compartment1";
		cargoCompartments[]=
		{
			"Compartment1","Compartment2","Compartment2","Compartment3"
		};
		class AnimationSources: AnimationSources
		{
			class Trunk
			{
				source="door";
				animPeriod=1.0;
				sound = "RDS_Trunk";
				soundPosition = "trunk_axis";
			};
			class blinker_L: Trunk
			{
				sound = "RDS_Blinker";
				soundPosition = "water_axis";
				animPeriod=0.35;
			};
			class blinker_R: blinker_L  {};
		};
		class HitPoints: HitPoints
		{
			class HitLFWheel: HitLFWheel
			{
				armor=0.175;
				passThrough=0.30000001;
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				armor=0.175;
				passThrough=0.30000001;
			};
			class HitRFWheel: HitRFWheel
			{
				armor=0.175;
				passThrough=0.30000001;
			};
			class HitRF2Wheel: HitRF2Wheel
			{
				armor=0.175;
				passThrough=0.30000001;
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
				visual="glass5";
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

		class Damage {
			mat[] =
			{
				"rds_a2port_civ\Octavia\Data\car_body1.rvmat",
				"rds_a2port_civ\Octavia\Data\car_body1_damage.rvmat",
				"rds_a2port_civ\Octavia\Data\car_body1_destruct.rvmat",

				"rds_a2port_civ\Octavia\Data\car_body.rvmat",
				"rds_a2port_civ\Octavia\Data\car_body_damage.rvmat",
				"rds_a2port_civ\Octavia\Data\car_body_destruct.rvmat",

				"rds_a2port_civ\Octavia\Data\car_chrom.rvmat",
				"rds_a2port_civ\Octavia\Data\car_chrom_damage.rvmat",
				"rds_a2port_civ\Octavia\Data\car_chrom_destruct.rvmat",

				"rds_a2port_civ\Octavia\Data\car_interier.rvmat",
				"rds_a2port_civ\Octavia\Data\car_interier_damage.rvmat",
				"rds_a2port_civ\Octavia\Data\car_interier_destruct.rvmat",


				"A3\data_f\glass_veh_int.rvmat",
				"A3\data_f\Glass_veh_damage.rvmat",
				"A3\data_f\Glass_veh_damage.rvmat",

				"A3\data_f\glass_veh.rvmat",
				"A3\data_f\Glass_veh_damage.rvmat",
				"A3\data_f\Glass_veh_damage.rvmat",

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
			{"LSvetla","RSvetla"}
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
		class textureSources
		{
			class standard
			{
				displayName="White";
				AUTHOR_MACRO
				textures[]=
				{
					"\rds_a2port_civ\Octavia\Data\car_body_co.paa",
					"\rds_a2port_civ\Octavia\Data\car_body_m_co.paa"
				};
				factions[]=
				{
					rds_rus_civ
				};
			};
			class Black: standard
			{
				displayName="Black";
				AUTHOR_MACRO
				textures[]=
				{
					"\rds_a2port_civ\Octavia\Data\car_body_black_co.paa",
					"\rds_a2port_civ\Octavia\Data\car_body_m_black_co.paa"
				};
			};
			class Blue: standard
			{
				displayName="Blue";
				AUTHOR_MACRO
				textures[]=
				{
					"\rds_a2port_civ\Octavia\Data\car_body_blue_co.paa",
					"\rds_a2port_civ\Octavia\Data\car_body_m_blue_co.paa"
				};
			};
			class Yellow: standard
			{
				displayName="Yellow";
				AUTHOR_MACRO
				textures[]=
				{
					"\rds_a2port_civ\Octavia\Data\car_body_yellow_co.paa",
					"\rds_a2port_civ\Octavia\Data\car_body_m_yellow_co.paa"
				};
			};
		};
		textureList[]=
		{
			"standard", 0.25,
			"Black", 0.25,
			"Blue", 0.25,
			"Yellow", 0.25
		};
		#include "PhysX_Octavia.hpp"
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
			init="if (local (_this select 0)) then {[(_this select 0), """", [], false] call bis_fnc_initVehicle;};";
			class RDS_Civ_EH
			{
				init			= "[_this select 0,'RDS_Sparewheel_octavia'] spawn rds_fnc_random_spareWheel";
				containerOpened = " (_this + [0,'trunk']) call rds_fnc_containerActions";
				containerClosed = " (_this + [1,'trunk']) call rds_fnc_containerActions";
			};
		};
	};

	class RDS_Octavia_Civ_Base: RDS_Octavia_Base
	{
		accuracy = 0.5;
		crew = "RDS_Profiteer3";
		faction="rds_rus_civ";
		side = 3;
	};

	class RDS_Octavia_Civ_01: RDS_Octavia_Civ_Base
	{
		scope=2;
		AUTHOR_MACRO
	};

