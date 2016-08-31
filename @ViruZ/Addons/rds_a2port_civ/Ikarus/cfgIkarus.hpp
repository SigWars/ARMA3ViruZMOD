
	class RDS_Ikarus_Base: Truck_F
	{
		model="\rds_a2port_civ\Ikarus\ikarus.p3d";
		icon = "\rds_a2port_civ\data\map_ico\icomap_Bus_CA.paa";
		picture = "\rds_a2port_civ\data\ico\ikarus_pic_ca.paa";
		mapsize=11;

		displayName="Ikarus 260.03";

		hiddenselections[] = {"Camo1","Camo2","Camo3"};
		hiddenselectionstextures[] = {
			"\rds_a2port_civ\Ikarus\data\bus_exterior_co.paa",
			"\rds_a2port_civ\ikarus\data\bus_interior_co.paa",
			"\rds_a2port_civ\ikarus\data\bus_windows_ca.paa"
		};

		driveraction = "Ikarus_Driver";

		attenuationEffectType = "OpenCarAttenuation";
//attenuationEffectType="CarAttenuation";
		armor=32;
		cost=50000;
		transportMaxBackpacks=6;
		transportSoldier=23;
		wheelDamageRadiusCoef=0.89999998;
		wheelDestroyRadiusCoef=0.40000001;
		maxFordingDepth=0.5;
		waterResistance=1;
		crewCrashProtection=0.25;

		driverLeftHandAnimName="drivewheel";
		driverRightHandAnimName="drivewheel";
		driverRightLegAnimName = "pedalR";

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
		unitInfoType = "RDS_RscUnitInfoCar";


		cargoaction[] = {"Truck_Cargo01", "Truck_Cargo01", "Truck_Cargo01", "Truck_Cargo01", "Truck_Cargo01", "Truck_Cargo01", "Truck_Cargo01", "Truck_Cargo01", "Truck_Cargo02", "Truck_Cargo02", "Truck_Cargo02", "Truck_Cargo02", "Truck_Cargo03", "Truck_Cargo03", "Truck_Cargo04", "Truck_Cargo04", "Truck_Cargo04", "Truck_Cargo04", "Truck_Cargo04", "Ikarus_Cargo", "Ikarus_Cargo", "Ikarus_Cargo", "Ikarus_Cargo"};
		memoryPointsGetInCargo[] =
		{
		//1-5
			"pos cargo1",
			"pos cargo",
			"pos cargo1",
			"pos cargo",
			"pos cargo2",
		//6-10
			"pos cargo1",
			"pos cargo1",
			"pos cargo1",
			"pos cargo2",
			"pos cargo2",
		//11-15
			"pos cargo",
			"pos cargo",
			"pos cargo2",
			"pos cargo",
			"pos cargo2",
		//16-20
			"pos cargo1",
			"pos cargo",
			"pos cargo",
			"pos cargo",
			"pos cargo",
		//21-23
			"pos cargo1",
			"pos cargo2",
			"pos cargo2"
		};
			memoryPointsGetInCargoDir[] =
		{
		//1-5
			"pos cargo1 dir",
			"pos cargo dir",
			"pos cargo1 dir",
			"pos cargo dir",
			"pos cargo2 dir",
		//6-10
			"pos cargo1 dir",
			"pos cargo1 dir",
			"pos cargo1 dir",
			"pos cargo2 dir",
			"pos cargo2 dir",
		//11-15
			"pos cargo dir",
			"pos cargo dir",
			"pos cargo2 dir",
			"pos cargo dir",
			"pos cargo2 dir",
		//16-20
			"pos cargo1 dir",
			"pos cargo dir",
			"pos cargo dir",
			"pos cargo dir",
			"pos cargo dir",

			"pos cargo1 dir",
			"pos cargo2 dir",
			"pos cargo2 dir"
		};
		driverDoor="Doors_1";
		cargoDoors[]=
		{
			"Doors_2",
			"Doors_1",
			"Doors_2",
			"Doors_1",
			"Doors_3",

			"Doors_2",
			"Doors_2",
			"Doors_2",
			"Doors_3",
			"Doors_3",

			"Doors_1",
			"Doors_1",
			"Doors_3",
			"Doors_1",
			"Doors_3",

			"Doors_2",
			"Doors_1",
			"Doors_1",
			"Doors_1",
			"Doors_1",

			"Doors_2",
			"Doors_1",
			"Doors_1",
			"Doors_2",
			"Doors_3",

			"Doors_2",
			"Doors_3",
			"Doors_3"
		};
		driverCompartments="Compartment1";
		cargoCompartments[]=
		{
			"Compartment1"
		};
		class AnimationSources: AnimationSources
		{
			class Doors_1
			{
				source="door";
				animPeriod=1.7;
				sound = "RDS_Ikarus_Door1";
				soundPosition = "pos cargo dir";
			};
			class Doors_2: Doors_1 {
				sound = "RDS_Ikarus_Door1";
				soundPosition = "pos cargo1 dir";
			};
			class Doors_3: Doors_1 {
				sound = "RDS_Ikarus_Door2";
				soundPosition = "pos cargo2 dir";
			};
			class blinker_L: Doors_1
			{
				sound = "RDS_Blinker";
				soundPosition = "blinker_sound";
				animPeriod=0.35;
			};
			class blinker_R: blinker_L  {};
		};

		class UserActions
		{
			class openDoors
			{
				displayName = Open Doors;
				position = "";
				radius = 5;
				showWindow = 0;
				condition = "(player == driver this) && (this animationPhase ""door_1"" < 0.5)";
				statement = "[vehicle player,1] call rds_fnc_ikarusDoors";
				onlyForPlayer = 1;
			};
			class closeDoors:  openDoors
			{
				displayName = Close Doors;
				condition = "(player == driver this) && (this animationPhase ""door_1"" > 0.5)";
				statement = "[vehicle player,0] call rds_fnc_ikarusDoors";
			};
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
				armor=0.05;
			};
			class HitGlass6: HitGlass6
			{
				armor=0.05;
			};
		};
		getInAction="GetInLow";
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
				"rds_a2port_civ\Ikarus\Data\Bus_exterior.rvmat",
				"rds_a2port_civ\Ikarus\Data\Bus_exterior_damage.rvmat",
				"rds_a2port_civ\Ikarus\Data\Bus_exterior_destruct.rvmat",

				"rds_a2port_civ\Ikarus\Data\Bus_interior.rvmat",
				"rds_a2port_civ\Ikarus\Data\Bus_interior_damage.rvmat",
				"rds_a2port_civ\Ikarus\Data\Bus_interior_destruct.rvmat",

				"rds_a2port_civ\Ikarus\Data\Bus_windows.rvmat",
				"rds_a2port_civ\Ikarus\Data\Bus_windows_damage.rvmat",
				"rds_a2port_civ\Ikarus\Data\Bus_windows_damage.rvmat",

				"rds_a2port_civ\Ikarus\Data\Bus_windows_in.rvmat",
				"rds_a2port_civ\Ikarus\Data\Bus_windows_in_damage.rvmat",
				"rds_a2port_civ\Ikarus\Data\Bus_windows_in_damage.rvmat",

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
			class RightMirrorSmall
			{
				renderTarget="rendertarget3";
				class CameraView1
				{
					pointPosition="m4p";
					pointDirection="m4d";
					renderQuality=2;
					renderVisionMode=4;
					fov=0.5;
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
				displayName="Brigadertrans";
				AUTHOR_MACRO
				textures[]=
				{
					"\rds_a2port_civ\Ikarus\data\bus_exterior_co.paa",
					"\rds_a2port_civ\ikarus\data\bus_interior_co.paa",
					"\rds_a2port_civ\ikarus\data\bus_windows_ca.paa"
				};
				factions[]=
				{
					rds_rus_civ
				};
			};
			class Desert: standard
			{
				displayName="Khan Mohad (TK)";
				AUTHOR_MACRO
				textures[]=
				{
					"\rds_a2port_civ\Ikarus\data\bus_exterior_eciv_co.paa",
					"\rds_a2port_civ\ikarus\data\bus_interior_eciv_co.paa",
					"\rds_a2port_civ\ikarus\data\bus_windows_eciv_ca.paa"
				};
			};
		};
		textureList[]=
		{
			"standard", 1,
			"Desert", 0
		};
		class Attributes {
			class ObjectTexture {
				control = "ObjectTexture";
				data = "ObjectTexture";
				displayName = "Skin";
				tooltip = "Texture and material set applied on the object.";
			};
			class rds_lock_cargo {
				collapsed = 1;
				displayName = "Driver door control";
				tooltip = "Define if passangers are able to get in/out on their own. If true, driver needs to open doors to allow passanger movement";
				property = "rds_lock_cargo";
				control = "Checkbox";
				expression = "_this setVariable ['%s', _value,true];_this lockCargo _value";
				defaultValue = "false";
			};
		};

		class EventHandlers: EventHandlers
		{
			class RDS_Civ_EH
			{
				//hitpart = "_this call rhsusf_fnc_hitPart";
				getIn = "_this call rds_fnc_ikarusDoors_handler";
				getOut = "_this call rds_fnc_ikarusDoors_handler";
			};
		};
		#include "PhysX_Ikarus.hpp"
	};

	class RDS_Ikarus_Civ_Base: RDS_Ikarus_Base
	{
		accuracy = 0.5;
		crew = "RDS_Worker1";
		faction="rds_rus_civ";
		side = 3;
	};

	class RDS_Ikarus_Civ_01: RDS_Ikarus_Civ_Base
	{
		scope=2;
		AUTHOR_MACRO
	};


	class RDS_Ikarus_Civ_02: RDS_Ikarus_Civ_01
	{
		AUTHOR_MACRO
		displayName="Ikarus 260.03 (TK)";
		hiddenselectionstextures[] = {
			"\rds_a2port_civ\Ikarus\data\bus_exterior_eciv_co.paa",
			"\rds_a2port_civ\ikarus\data\bus_interior_eciv_co.paa",
			"\rds_a2port_civ\ikarus\data\bus_windows_eciv_ca.paa"
		};
	};



