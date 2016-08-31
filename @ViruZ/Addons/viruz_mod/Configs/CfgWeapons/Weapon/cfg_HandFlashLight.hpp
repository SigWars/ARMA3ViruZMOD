	
	class HandFlashlightCore : PistolCore {
		htMin = 1;
		htMax = 300;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 100;
		autoReload = false;
		opticsZoomMin = 0.375;
		opticsZoomMax = 1.1;
		opticsZoomInit = 0.75;
		discreteDistance[] = {50};
		discreteDistanceInitIndex = 0;
		magazineReloadTime = 2;
		opticsFlare = false;
		nameSound = "Pistol";
		soundBullet[] = {"bullet1", 0.083, "bullet2", 0.083, "bullet3", 0.083, "bullet4", 0.083, "bullet5", 0.083, "bullet6", 0.083, "bullet7", 0.083, "bullet8", 0.083, "bullet9", 0.083, "bullet10", 0.083, "bullet11", 0.083, "bullet12", 0.083};
		
		class WeaponSlotsInfo {
			allowedSlots[] = {801, 701, 901};
		};
	};
	
	class HandFlashlight_Base : HandFlashlightCore {
		bullet1[] = {"A3\sounds_f\weapons\shells\9mm\metal_9mm_01", 0.562341, 1, 15};
		bullet2[] = {"A3\sounds_f\weapons\shells\9mm\metal_9mm_02", 0.562341, 1, 15};
		bullet3[] = {"A3\sounds_f\weapons\shells\9mm\metal_9mm_03", 0.562341, 1, 15};
		bullet4[] = {"A3\sounds_f\weapons\shells\9mm\metal_9mm_04", 0.562341, 1, 15};
		bullet5[] = {"A3\sounds_f\weapons\shells\9mm\dirt_9mm_01", 0.562341, 1, 15};
		bullet6[] = {"A3\sounds_f\weapons\shells\9mm\dirt_9mm_02", 0.562341, 1, 15};
		bullet7[] = {"A3\sounds_f\weapons\shells\9mm\dirt_9mm_03", 0.562341, 1, 15};
		bullet8[] = {"A3\sounds_f\weapons\shells\9mm\dirt_9mm_04", 0.562341, 1, 15};
		bullet9[] = {"A3\sounds_f\weapons\shells\9mm\grass_9mm_01", 0.562341, 1, 15};
		bullet10[] = {"A3\sounds_f\weapons\shells\9mm\grass_9mm_02", 0.562341, 1, 15};
		bullet11[] = {"A3\sounds_f\weapons\shells\9mm\grass_9mm_03", 0.562341, 1, 15};
		bullet12[] = {"A3\sounds_f\weapons\shells\9mm\grass_9mm_04", 0.562341, 1, 15};
		soundBullet[] = {"bullet1", 0.083, "bullet2", 0.083, "bullet3", 0.083, "bullet4", 0.083, "bullet5", 0.083, "bullet6", 0.083, "bullet7", 0.083, "bullet8", 0.083, "bullet9", 0.083, "bullet10", 0.083, "bullet11", 0.083, "bullet12", 0.083};
		optics = true;
		modelOptics = "-";
		opticsZoomMin = 0.375;
		opticsZoomMax = 1.1;
		opticsZoomInit = 0.75;
		cursor = "hgun";
		cursoraim = "cursorAim";
		minRange = 0;
		minRangeProbab = 0.1;
		midRange = 30;
		midRangeProbab = 0.3;
		maxRange = 50;
		maxRangeProbab = 0.04;
		reloadAction = "GestureReloadPistol";
		weaponPoolAvailable = 1;
		
		class WeaponSlotsInfo : WeaponSlotsInfo {
			mass = 10;
			
			class PointerSlot : SlotInfo {
				linkProxy = "\A3\data_f\proxies\weapon_slots\SIDE";
				displayName = "$STR_A3_PointerSlot0";
				compatibleItems[] = {"acc_lampflashlight"};
			};	
		};
		textureType = "semi";
		
		class GunParticles {
			class FirstEffect {
				effectName = "PistolCloud";
				positionName = "Usti hlavne";
				directionName = "Konec hlavne";
			};
		};
		
	};

	class HandFlashlight : HandFlashlight_Base {
		scope = public;
		model = "\viruz_equip\items\viruz_lanterna.p3d";
		modelOptics = "-";
		picture = "\viruz_equip\viruzico\viruz_lanterna_ca.paa";
		magazines[] = {"Battery_mag"};
		displayName = "$STR_EQUIP_NAME_5";
		begin1[] = {};
		begin2[] = {};
		soundBegin[] = {"begin1", 0.5, "begin2", 0.5};
		reloadMagazineSound[] = {"A3\sounds_f\weapons\pistols\p07_reload", 0.562341, 1, 30};
		recoil = "recoil_single_pistol_2outof3";
		recoilProne = "recoil_single_pistol_prone_2outof3";
		distanceZoomMin = 50;
		distanceZoomMax = 50;
		
		class Library {
			libTextDesc = "A flashlight (or torch in British English) is a hand-held portable electric-powered light source. Usually the light source is a small incandescent light bulb or light-emitting diode (LED).";
		};
		descriptionShort = "$STR_EQUIP_DESC_5";
		autoFire = false;

		class FlashLight {
			color[] = {1800, 1500, 1200};
			ambient[] = {9, 7.5, 6};
			intensity = 1;
			size = 1;
			innerAngle = 20;
			outerAngle = 80;
			coneFadeCoef = 5;
			position = "flash dir";
			direction = "flash";
			useFlare = 1;
			flareSize = 0.4;
			flareMaxDistance = "100.0f";
			dayLight = 0;
		
			class Attenuation {
				start = 0.5;
				constant = 0;
				linear = 0;
				quadratic = 1;
				hardLimitStart = 20;
				hardLimitEnd = 30;
			};
			scale[] = {0};
		};
		minRange = 0;
		minRangeProbab = 0.1;
		midRange = 30;
		midRangeProbab = 0.3;
		maxRange = 50;
		maxRangeProbab = 0.04;
	};