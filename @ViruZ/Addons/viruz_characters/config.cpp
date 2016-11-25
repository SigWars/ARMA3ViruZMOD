#define true	1
#define false	0

#define private		0
#define protected		1
#define public		2

#define VSoft		0
#define VArmor		1
#define VAir		2

#define TEast		0
#define TWest		1
#define TGuerrila		2
#define TCivilian		3
#define TSideUnknown		4
#define TEnemy		5
#define TFriendly		6
#define TLogic		7

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define LockNo		0
#define LockCadet		1
#define LockYes		2

class CfgPatches {
	class A3_Viruz_Characters {
		units[] = {
			"B_Survivor_Base_F", "Survivor1_DZ", "Survivor2_DZ", "Survivor3_DZ", "Bandit1_DZ", "B_ManJeans1", "B_ManJeans2", "B_ManJeans3", "Maniken_Base", "Maniken_Civilian", "Maniken_Military",
			"B_Guerilla1_1_srv", "B_Guerilla2_1_srv", "B_Guerilla2_2_srv", "B_Guerilla2_3_srv", "B_Guerilla3_1_srv", "B_Guerilla3_2_srv", "B_leader_srv", "O_Soldier_F_srv", "O_sniper_F_srv", "O_diver_F_srv"
		};
		weapons[] = {
			"U_C_Citizen_clothes1", "U_C_Citizen_clothes2", "U_C_Citizen_clothes3",
			"U_B_Guerilla1_1_srv", "U_B_Guerilla2_2_srv", "U_B_Guerilla2_3_srv", "U_B_Guerilla3_1_srv", "U_B_Guerilla3_2_srv", "U_B_leader_srv", "U_O_CombatUniform_ocamo_srv", "U_O_GhillieSuit_srv", "U_O_Wetsuit_srv"
		};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_Characters_F"};
	};
};

class CfgVehicles {
	
	class Civilian;
	class B_Soldier_F;
	class Underwear_F;

	class B_Survivor_Base_F : B_Soldier_F {
		scope = private;
		weapons[] = {"Throw","Put"};
		respawnWeapons[] = {"Throw","Put"};
		backpack = "";
		magazines[] = {};
		respawnMagazines[] = {};
		linkeditems[] = {};
		respawnlinkeditems[] = {};
		Items[] = {};
		respawnItems[] = {};
		canHideBodies = 1;
		
		//allowedUniformSides[] = {};
		//allowedHeadgearSides[] = {};
	};
	
	class Survivor1_DZ: B_Survivor_Base_F {
		scope = public;
		displayName = "Survivor";
	};
	
	class Survivor2_DZ: Survivor1_DZ {
		displayName = "Survivor2";
		class HitPoints
		{
			class HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.1;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitFace
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.1;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
			};
			class HitHead: HitNeck
			{
				armor=1;
				material=-1;
				name="head";
				passThrough=0.1;
				radius=0.2;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
				depends="HitFace max HitNeck";
			};
			class HitPelvis
			{
				armor=1;
				material=-1;
				name="pelvis";
				passThrough=0.1;
				radius=0.2;
				explosionShielding=1;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitAbdomen: HitPelvis
			{
				armor=1;
				material=-1;
				name="spine1";
				passThrough=0.1;
				radius=0.15000001;
				explosionShielding=1;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=1;
				material=-1;
				name="spine2";
				passThrough=0.1;
				radius=0.15000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitChest: HitDiaphragm
			{
				armor=1;
				material=-1;
				name="spine3";
				passThrough=0.1;
				radius=0.15000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitChest
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=0.1;
				radius=0.16;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms
			{
				armor=1;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0.1;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
			};
			class HitHands: HitArms
			{
				armor=1;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0.1;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="HitArms";
			};
			class HitLegs
			{
				armor=1;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.12;
				explosionShielding=1;
				visual="injury_legs";
				minimalHit=0.0099999998;
			};
		};
		armor=0;
		armorStructural=0.40000001;
	};
	
	class Survivor3_DZ: Survivor1_DZ {
		displayName = "Survivor3";
	};
	
	class Bandit1_DZ : Survivor1_DZ {
		displayName = "Bandit";
	};
	
	class B_ManJeans1 : B_Survivor_Base_F {
		scope = public;
		model = "\A3\Characters_F\Civil\c_citizen5.p3d";
		displayName = "Survivor T-shirt brown";
		hiddenSelections[] = {"Camo1", "Camo2", "Camo3"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\basicbody_brown_co.paa", "\A3\characters_f\civil\data\c_cloth4_co.paa"};
		uniformClass = "U_C_Citizen_clothes1";
		
		class Wounds {
			tex[] = {};
			mat[] = {"A3\Characters_F\Civil\Data\c_cloth4.rvmat", "A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat", "A3\Characters_F\Civil\Data\c_cloth4_injury.rvmat"};
		};
	};
	
	class B_ManJeans2 : B_ManJeans1 {
		displayName = "Survivor T-shirt blue";
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\basicbody_blue_co.paa", "\A3\characters_f\civil\data\c_cloth4_v2_co.paa"};
		uniformClass = "U_C_Citizen_clothes2";
	};
	
	class B_ManJeans3 : B_ManJeans1 {
		displayName = "Survivor T-shirt black";
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Data\basicbody_black_co.paa", "\A3\characters_f\civil\data\c_cloth4_v3_co.paa"};
		uniformClass = "U_C_Citizen_clothes3";
	};
	
	class Maniken_Base : Underwear_F {
		scope = private;
		author = "SteelRat (ProjectTeam)";
		displayName = "Maniken Base";
		Items[] = {};
		RespawnItems[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
		
		// Обнулить, что бы не вертел башкой
		class HeadLimits {
			initAngleX = 5;
			minAngleX = -30;
			maxAngleX = 40;
			initAngleY = 0;
			minAngleY = -90;
			maxAngleY = 90;
			minAngleZ = -45;
			maxAngleZ = 45;
			rotZRadius = 0.2;
		};
		
		class EventHandlers {
			init = "(_this select 0) execVM 'a3\dayz_characters\scripts\maniken.sqf'";
		};
	};
	
	class Maniken_Civilian : Maniken_Base {
		scope = public;
		displayName = "Maniken Civilian";
	};
	
	class Maniken_Military : Maniken_Civilian {
		displayName = "Maniken Military";
	};
	
	#include "units.hpp"
};

class CfgWeapons {
	
	class Uniform_Base;
	class UniformItem;
	
	class U_C_Citizen_clothes1 : Uniform_Base {
		scope = public;
		displayName = "T-shirt brown";
		picture = "\A3\characters_f\data\ui\icon_U_Citizen_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		
		class ItemInfo : UniformItem {
			uniformModel = "-";
			uniformClass = "B_ManJeans1";
			containerClass = "Supply10";
			mass = 60;
		};
	};
	
	class U_C_Citizen_clothes2 : U_C_Citizen_clothes1 {
		displayName = "T-shirt blue";
		
		class ItemInfo : ItemInfo {
			uniformClass = "B_ManJeans2";
		};
	};
	
	class U_C_Citizen_clothes3 : U_C_Citizen_clothes1 {
		displayName = "T-shirt black";
		
		class ItemInfo : ItemInfo {
			uniformClass = "B_ManJeans3";
		};
	};
	
	#include "uniforms.hpp"
};
