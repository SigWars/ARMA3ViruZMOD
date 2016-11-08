#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define VSoft		0
#define VArmor		1
#define VAir		2

#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

class CfgPatches {
	class viruz_equip {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

class CfgVehicleClasses {
	class Survival {
		displayName = "Survival";
	};
};

class CfgWeapons {
	
	class Default;	// External class reference
	class ItemCore;	// External class reference
	class ItemInfo;
	//class InventoryItem_Base_F; //viruz_build
	
	class Loot : Default {
		scope = public;
		value = 0;
		type = VSoft;
		displayName = "Use";
		canDrop = false;
		muzzles[] = {this};
		magazines[] = {"ItemBandage", "ItemHeatPack", "PartFueltank", "PartWheel", "PartGeneric", "PartEngine", "PartVRotor", "PartGlass", "ItemWaterbottle", "ItemWaterbottleUnfilled", "ItemEpinephrine", "ItemMorphine", "ItemBloodbag", "ItemAntibiotic", "ItemPainkiller", "ItemJerrycan", "ItemGenerator", "ItemSandbag", "ItemTankTrap", "ItemWire", "FoodDrink", "ItemSodaOriginal", "ItemSodaOriginalEmpty", "FoodEdible", "FoodCanWBBeans", "FoodCanWBBeansEmpty", "FoodSteakRaw", "FoodmeatRaw", "FoodSteakCooked", "FoodmeatCooked"};
		modes[] = {this};
		useAction = false;
		useActionTitle = "";
		enableAttack = false;
		showToPlayer = false;
	};
	
	class ItemToolbox : ItemCore {
		scope = public;
		displayName="$STR_A3_cfgWeapons_ToolKit0";
		descriptionShort="$STR_A3_cfgWeapons_ToolKit1";
		picture="\A3\Weapons_F\Items\data\UI\gear_Toolkit_CA.paa";
		model="\A3\Weapons_F\Items\Toolkit";
		
		class ItemInfo {
			type = 620;
			allowedSlots[] = {701,801,901}; //only 901
			mass = 10;
			uniformModel = "\A3\Weapons_F\Items\Toolkit";
		};
	};

	class ItemKnife : ItemCore {
		scope = public;
		displayName = "Military Knife";
		model = "\viruz_equip\items\viruz_mknife.p3d";
		picture = "\viruz_equip\viruzico\mkinife.paa";
		descriptionShort = $STR_EQUIP_DESC_4;
		
		class ItemInfo {
			type = 620;
			allowedSlots[] = {701,801,901};
			mass = 10;
		};
	};
	
};

#include "CfgMagazines.hpp"

class CfgVehicles {
	class NonStrategic;	// External class reference
	
	class BuiltItems : NonStrategic {};
	
	class TrapItems : NonStrategic {};
	
	class Land_BagFence_Long_F;
	class Sandbag1_DZ :Land_BagFence_Long_F {
		destrType = "DestructNo";
	};
	
	class Land_Razorwire_F;
	class Wire_cat1 : Land_Razorwire_F {
		scope = public;
		displayName = "Wire (CAT1)";
		destrType = "DestructNo";
	};
	
	/*class BearTrap_DZ : TrapItems {
		scope = public;
		destrType = "DestructNo";
		displayName = "Bear Trap";
		model = "\viruz_equip\items\viruz_bear_trap.p3d";
		
		class Eventhandlers {
			init = "_this execFSM '\z\addons\viruz_mod\system\trap_monitor.fsm';";
		};
		
		class AnimationSources {
			class LeftShutter {
				source = "user";
				animPeriod = 0.1;
				initPhase = 1;
			};
			
			class RightShutter {
				source = "user";
				animPeriod = 0.1;
				initPhase = 1;
			};
		};
		
		class UserActions {
			class OpenTrap {
				position = "";
				displayName = "Reset Trap";
				radius = 1.5;
				onlyForPlayer = 0;
				condition = "this animationPhase 'LeftShutter' == 1";
				statement = "this animate ['LeftShutter', 0];this animate ['RightShutter', 0];";
			};
			
			class CloseTrap {
				position = "";
				displayName = "Activate Trap";
				radius = 1.5;
				onlyForPlayer = 0;
				condition = "this animationPhase 'LeftShutter' == 0";
				statement = "this animate ['LeftShutter', 1];this animate ['RightShutter', 1];";
			};
			
			class CollectTrap {
				position = "";
				displayName = "Take Trap";
				radius = 1.5;
				onlyForPlayer = 0;
				condition = "this animationPhase 'LeftShutter' == 1";
				statement = "[0,0,0,['cfgMagazines','TrapBear',this]] call object_pickup;";
			};
		};
	};*/
	class ReammoBox;	// External class reference

	/*class CardboardBox : ReammoBox {
		accuracy = 1000;	// accuracy needed to recognize type of this target
		vehicleClass = "Survival";
		isGround = 0;
	};
	
	class FoodBox0 : CardboardBox {
		scope = public;
		displayName = $STR_VIRUZ_OBJ_1;
		model = "\viruz_equip\items\boxmre.p3d";
		
		class Eventhandlers {
			//init = "private ['_foods'];_foods = getArray (missionConfigfile >> 'CfgLoot' >> 'food') select 0;for '_i' from 1 to 5 do {(_this select 0) addMagazineCargoGlobal [_foods call BIS_fnc_selectRandom, round(random 5) + 1];};";
		};
	};*/
	
	class Land_FirePlace_F;	// External class reference	
	class Land_Fire_DZ : Land_FirePlace_F {
		transportMaxMagazines = 8;
		transportMaxWeapons = 0;
		transportMaxBackpacks = 0;
		
		class TransportMagazines {
			class _xx_PartWoodPile {
				magazine = "PartWoodPile";
				count = "1";
			};
		};
		
		class Eventhandlers {
			init = "_this call eh_localCleanup;";
		};
	};
	
};

//import viruzmod
class CfgAmmo {	

	class GrenadeHand;
	class BulletCore;
	class PipeBombBase;
	class SmokeShell;
	
	
	class UV_lamp_Base: SmokeShell {
		timeToLive = 60;
		typicalspeed = 14;
		grenadeFireSound[] = {};
		grenadeBurningSound[] = {};
	};
	
	class UV_lamp: UV_lamp_Base {
		model = "\A3\Weapons_f\chemlight\chemlight_blue_lit";
		effectsSmoke = "ChemlightLight_blue";
	};

	class Battery: BulletCore {
		visibleFire = 0;	// how much is visible when this weapon is fired
		audibleFire = 0;
		visibleFireTime = 0;	// how long is it visible
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		model = "\A3\Weapons_f\ammo\shell";
		caliber = 0;
		cartridge = "";
		cost = 1;
		timeToLive = 0;
		deflecting = 0;
		tracerStartTime = -1;
		muzzleEffect = "";
		waterEffectOffset = 0;
		effectFly = "0";
	};
	
	class ThrownObjects : GrenadeHand {
		hit = 0.5;
		indirectHit = 0.2;
		indirectHitRange = 1;
		cost = 1;
		whistleDist = 0;
		fuseDistance = 0;
		initTime = 0;
		explosive = true;
	};
	
	class SodaCan : ThrownObjects {
		model = "\viruz_equip\items\sodaoriginalE.p3d";
		CraterEffects = "NoCrater";
		explosionEffects = "NoExplosion";
		soundHit[] = {"viruz_equip\sound\can_hit_0", 0.5, 1, 60};
	};
	
	class TinCan : ThrownObjects {
		model = "\viruz_equip\items\canspaghetti1E.p3d";
		CraterEffects = "NoCrater";
		explosionEffects = "NoExplosion";
		soundHit[] = {"viruz_equip\sound\can_hit_1", 0.5, 1, 60};
	};
	
};

class CfgSounds {
	/*class trap_bear_0 {
		name = "";
		sound[] = {"\viruz_equip\sound\trap_bear_0", 1, 1, 100};
		titles[] = {};
	};*/
};
