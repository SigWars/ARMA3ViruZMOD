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

	class Antiseptic: BulletCore {
		model = "\A3\Weapons_f\ammo\shell";
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
		soundHit[] = {"viruz_equip\sound\can_hit_0.ogg", 0.5, 1, 60};
	};
	
	class TinCan : ThrownObjects {
		model = "\viruz_equip\items\canspaghetti1E.p3d";
		CraterEffects = "NoCrater";
		explosionEffects = "NoExplosion";
		soundHit[] = {"viruz_equip\sound\can_hit_1.ogg", 0.5, 1, 60};
	};
	
};