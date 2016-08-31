
	class RDS_Zetor6945_Base: Car_F
	{
		AUTHOR_MACRO
		TextPlural = "Tractors";
		TextSingular = "Tractor";
		nameSound = "veh_Tractor";

		scope = 2;
		faction="rds_rus_civ";
		side = 3;

		model = "\rds_a2port_civ\tractor\tractor_2.p3d";
		picture = "\rds_a2port_civ\data\ico\zetor_pic_ca.paa";
		Icon = "\rds_a2port_civ\data\map_ico\icomap_traktor_CA.paa";

		mapSize = 6;
		class Damage
		{
			tex[] = {};
			mat[] =
			{
				"rds_a2port_civ\Tractor\data\traktor_2.rvmat",
				"rds_a2port_civ\Tractor\data\traktor_2.rvmat",
				"rds_a2port_civ\Tractor\data\traktor_2_destruct.rvmat",

				"rds_a2port_civ\Tractor\data\traktor_2_skla.rvmat",
				"rds_a2port_civ\Tractor\data\traktor_2_skla_destruct.rvmat",
				"rds_a2port_civ\Tractor\data\traktor_2_skla_destruct.rvmat"
			};
		};
		typicalCargo[] = {"Villager1"};
		crew = "rds_Villager1";
		displayName = "Tractor";

		driverAction = "Tractor_Driver";
		driverLeftHandAnimName = "drivewheel";
		driverRightHandAnimName = "gear_stick";
		driverLeftLegAnimName = "pedalL";
		driverRightLegAnimName = "pedalR";
		castDriverShadow = 1;
		unitInfoType = "RDS_RscUnitInfoCar";

		class Library
		{
			libTextDesc = "Agricultural tractor.";
		};

		driverDoor="Door_RF";
		cargoDoors[]=
		{
			"Door_RF",
			"Door_LF"
		};

		class AnimationSources: AnimationSources
		{
			class Door_LF
			{
				source="door";
				sound = "RDS_Tractor_Door";
				soundPosition = "door_1_1_axis";
				animPeriod=1.0;
			};
			class Door_RF: Door_LF
			{
				soundPosition = "door_1_2_axis";
			};
			class gearbox: Door_LF
			{
				sound = "RDS_Gearbox";
				soundPosition = "gear_stick_axis";
				animPeriod=0.8;
			};
			class blinker_L: Door_LF
			{
				sound = "RDS_Blinker";
				soundPosition = "water_axis";
				animPeriod=0.35;
			};
			class blinker_R: blinker_L  {};
			class blinker_switch: blinker_L  {
				source="user";
				animPeriod=0.2;
			};
			class light_cover1
			{
				source="user";
				sound = "RDS_Tractor_Cover";
				soundPosition = "light_cover1_axis";
				animPeriod=0.5;
			};
			class light_cover2: light_cover1 {
				soundPosition = "light_cover2_axis";
			};
		};
		hasGunner = 0;
		class Turrets {};
		class Reflectors
		{
			class Left
			{
				color[] = {900,800,800,1};
				ambient[] = {100,100,100,1};
				position = "L svetlo";
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 1;
				brightness = 0.5;
			};
			class Right: Left
			{
				position = "P svetlo";
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
			};
		};
		aggregateReflectors[]=
		{
			{"LSvetla"},{"RSvetla"}
		};
		class Exhausts
		{
			class Exhaust1
			{
				position="vyfuk start";
				direction="vyfuk konec";
                    		effect = "ExhaustEffectTractor";
                    		//effect = "ExhaustEffectHEMTT";
			};
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


		rarityUrban = 0.2;
		#include "sounds.hpp"
		#include "PhysX_Zetor.hpp"

		class EventHandlers: EventHandlers
		{
			engine="_this call SLX_XEH_EH_Engine;if(_this select 1)then{_this call RdS_fnc_gearSound};";
			dammaged="_this call SLX_XEH_EH_Dammaged;_this call rds_fnc_fuelLeak;";
			hitpart = "_this call SLX_XEH_EH_HitPart;_this call rds_fnc_hitHandler";
		};
	};