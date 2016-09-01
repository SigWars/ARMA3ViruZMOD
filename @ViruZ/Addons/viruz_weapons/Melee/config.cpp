class CfgPatches
{
	class viruz_weapons
	{
		units[]={};
		weapons[]=
		{
			"MeleeWeapon",
			"MeleeHatchet"
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Weapons_F",
			"A3_characters_F",
			"A3_Data_F"
		};
		magazines[]=
		{
			"Hatchet_Swing"
		};
		ammo[]=
		{
			"Melee",
			"Hatchet_Swing_Ammo"
		};
	};
};
class Mode_SemiAuto;
class Mode_FullAuto;
class Mode_Burst;
class CfgMovesBasic
{
	class ManActions
	{
		GestureSwing=" ";
	};
	class StandBase;
	class Actions
	{
		class NoActions: ManActions
		{
			GestureSwing[]=
			{
				"GestureSwing",
				"Gesture"
			};
			access=3;
			ladderOnDown="LadderCivilOn_Top";
			ladderOnUp="LadderCivilOn_Top";
			turnSpeed=1;
			upDegree=-1;
			stance="ManStanceUndefined";
			limitFast=5;
			leanRRot=0;
			leanRShift=0;
			leanLRot=0;
			leanLShift=0;
			useFastMove=0;
		};
	};
};
class CfgGesturesMale
{
	skeletonName="OFP2_ManSkeleton";
	class ManActions
	{
	};
	class Actions
	{
		class NoActions
		{
			turnSpeed=0;
			upDegree=0;
			limitFast=1;
			useFastMove=0;
		};
	};
	class Default
	{
		actions="NoActions";
		file="";
		looped=1;
		speed=0.5;
		relSpeedMin=1;
		relSpeedMax=1;
		soundEnabled=0;
		soundOverride="";
		soundEdge[]={0.5,1};
		terminal=0;
		equivalentTo="";
		connectAs="";
		connectFrom[]={};
		connectTo[]={};
		interpolateWith[]={};
		interpolateTo[]={};
		interpolateFrom[]={};
		mask="empty";
		interpolationSpeed=6;
		interpolationRestart=0;
		preload=0;
		disableWeapons=1;
		enableOptics=1;
		showWeaponAim=1;
		enableMissile=1;
		enableBinocular=1;
		showItemInHand=0;
		showItemInRightHand=0;
		showHandGun=0;
		canPullTrigger=1;
		walkcycles=1;
		headBobMode=0;
		headBobStrength=0;
		leftHandIKBeg=0;
		leftHandIKEnd=0;
		rightHandIKBeg=0;
		rightHandIKEnd=0;
		leftHandIKCurve[]={1};
		rightHandIKCurve[]={1};
		forceAim=0;
	};
	class States
	{
		class GestureSwing: Default
		{
			file="\viruz_weapons\melee\anim\melee_hatchet_swing.rtm";
			looped=0;
			speed=2.5820501;
			mask="handsWeapon";
			headBobStrength=0.2;
			headBobMode=2;
			disableWeapons=0;
			rightHandIKBeg=1;
			rightHandIKEnd=1;
			leftHandIKBeg=1;
			leftHandIKEnd=1;
		};
	};
	class BlendAnims
	{
		handsWeapon[]=
		{
			"head",
			1,
			"neck1",
			1,
			"neck",
			1,
			"launcher",
			1,
			"LeftShoulder",
			1,
			"LeftArm",
			1,
			"LeftArmRoll",
			1,
			"LeftForeArm",
			1,
			"LeftForeArmRoll",
			1,
			"LeftHand",
			1,
			"LeftHandRing",
			1,
			"LeftHandPinky1",
			1,
			"LeftHandPinky2",
			1,
			"LeftHandPinky3",
			1,
			"LeftHandRing1",
			1,
			"LeftHandRing2",
			1,
			"LeftHandRing3",
			1,
			"LeftHandMiddle1",
			1,
			"LeftHandMiddle2",
			1,
			"LeftHandMiddle3",
			1,
			"LeftHandIndex1",
			1,
			"LeftHandIndex2",
			1,
			"LeftHandIndex3",
			1,
			"LeftHandThumb1",
			1,
			"LeftHandThumb2",
			1,
			"LeftHandThumb3",
			1,
			"RightShoulder",
			1,
			"RightArm",
			1,
			"RightArmRoll",
			1,
			"RightForeArm",
			1,
			"RightForeArmRoll",
			1,
			"RightHand",
			1,
			"RightHandRing",
			1,
			"RightHandPinky1",
			1,
			"RightHandPinky2",
			1,
			"RightHandPinky3",
			1,
			"RightHandRing1",
			1,
			"RightHandRing2",
			1,
			"RightHandRing3",
			1,
			"RightHandMiddle1",
			1,
			"RightHandMiddle2",
			1,
			"RightHandMiddle3",
			1,
			"RightHandIndex1",
			1,
			"RightHandIndex2",
			1,
			"RightHandIndex3",
			1,
			"RightHandThumb1",
			1,
			"RightHandThumb2",
			1,
			"RightHandThumb3",
			1,
			"Spine",
			1,
			"Spine1",
			1,
			"Spine2",
			1,
			"Spine3",
			1
		};
	};
};
class CfgRecoils
{
	DZ_Swing[]={0,0.059999999,-0.1,0,0.1,-0.12,0.1,0,0};
};
class ItemActions
{
	class Use
	{
		text="";
		script="";
		use[]={};
	};
};
class DZ_Melee: Mode_SemiAuto
{
	multiplier=1;
	burst=5;
	displayName="Hack";
	dispersion=0.1;
	sound[]=
	{
		"",
		0,
		1
	};
	soundContinuous=1;
	reloadTime=1;
	magazineReloadTime=1;
	ffCount=1;
	optics=0;
	recoil="empty";
	autoFire=1;
	CraterEffects="NoCrater";
	explosionEffects="NoExplosion";
	aiRateOfFire=0.69999999;
	aiRateOfFireDistance=2.2;
	useAction=1;
	useActionTitle="GestureSwing";
	recoilProne="empty";
	showToPlayer=1;
	minRange=0;
	minRangeProbab=0.80000001;
	midRange=0.30000001;
	midRangeProbab=0.80000001;
	maxRange=3;
	maxRangeProbab=0;
	soundBurst=1;
};
class CfgWeapons
{
	class SlotInfo;
	class LinkedItems;
	class Default;
	class ItemCore;
	class InventoryMuzzleItem_Base_F;
	class InventoryOpticsItem_Base_F;
	class InventoryFlashLightItem_Base_F;
	class InventoryUnderItem_Base_F;
	class Snip;
	class GunParticles;
	class muzzle_snds_L;
	class muzzle_snds_H_MG;
	class muzzle_snds_H;
	class muzzle_snds_B;
	class muzzle_snds_M;
	class muzzle_snds_acp;
	class acc_pointer_IR;
	class acc_flashlight;
	class PistolCore;
	class Pistol;
	class Rifle;
	class RifleCore;
	class Pistol_Base_F;
	class Rifle_Base_F;
	class Rifle_Long_Base_F;
	class WeaponSlotsInfo;
	class ItemInfo;
	class CowsSlot;
	class PointerSlot;
	class UGL_F;
	class MeleeWeapon: Rifle
	{
		scope=2;
		UiPicture="viruz_weapons\Ico\i_regular_CA.paa";
		distanceZoomMin=50;
		distanceZoomMax=50;
		canDrop=0;
		cursor="EmptyCursor";
		cursorAim="throw";
		cursorSize=1;
		weaponInfoType="RscWeaponEmpty";
	};
	class MeleeHatchet: MeleeWeapon
	{
		autoreload=1;
		scope=2;
		type=4;
		primary=0;
		canShootInWater=1;
		weaponReloadtime=0.25;
		model="\viruz_weapons\melee\axe.p3d";
		picture="\viruz_weapons\melee\data\equip_axe.paa";
		displayName="$STR_EQUIP_NAME_41";
		descriptionUse="$STR_EQUIP_DESC_41";
		reloadAction="ReloadRPG";
		magazines[]=
		{
			"Hatchet_Swing"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\viruz_weapons\melee\anim\melee_hatchet_holding.rtm"
		};
		descriptionShort="$STR_EQUIP_DESC_41";
		swayDecaySpeed=1.25;
		cursor="mg";
		cursoraim="EmptyCursor";
		cursorSize=1;
		modes[]=
		{
			"Single"
		};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="DefaultRifle";
				closure1[]=
				{
					"",
					5.9999998e-005,
					1,
					10
				};
				closure2[]=
				{
					"",
					5.9999998e-005,
					1,
					10
				};
				soundClosure[]=
				{
					"closure1",
					0.5,
					"closure2",
					0.5
				};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"viruz_weapons\melee\sounds\swing_0.wss",
					1.994328,
					0.94999999,
					10
				};
				begin2[]=
				{
					"viruz_weapons\melee\sounds\swing_1.wss",
					1.994328,
					0.69999999,
					10
				};
				begin3[]=
				{
					"viruz_weapons\melee\sounds\swing_0.wss",
					1.994328,
					0.60000002,
					10
				};
				begin4[]=
				{
					"viruz_weapons\melee\sounds\swing_1.wss",
					1.994328,
					0.80000001,
					10
				};
				soundBegin[]=
				{
					"begin1",
					0.25,
					"begin2",
					0.25,
					"begin3",
					0.25,
					"begin4",
					0.25
				};
			};
			dispersion=0.0092000002;
			soundContinuous=0;
			reloadTime=0.60000002;
			recoil="recoil_single_primary_prone_1outof10";
			recoilProne="";
		};
		class ItemActions
		{
			class Use
			{
				text="$STR_ACTIONS_CHOPWOOD";
				script="spawn player_chopWood;";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=35;
			allowedSlots[]={901,801,701};
			class MuzzleSlot: SlotInfo
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]={};
				iconScale=0.1;
			};
			class CowsSlot: SlotInfo
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={};
				iconScale=0.1;
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]={};
				iconScale=0.1;
			};
		};
	};
};
class CfgMagazines
{
	class Default;
	class CA_Magazine;
	class Hatchet_Swing: CA_Magazine
	{
		scope=2;
		type=0;
		autoReload=0;
		flash="";
		flashSize=0;
		initSpeed=85;
		maxLeadSpeed=20;
		optics=0;
		distanceZoomMin=0;
		distanceZoomMax=0;
		count=100000;
		reloadTime=0.1;
		magazineReloadTime=0.1;
		ammo="Hatchet_Swing_Ammo";
		mass=0;
		drySound[]=
		{
			"",
			0,
			1
		};
		reloadMagazineSound[]=
		{
			"",
			0,
			1
		};
		modes[]=
		{
			"Single"
		};
		picture="\viruz_weapons\melee\data\viruz_swing_ca.paa";
		displayName="Hatchet Swing";
		displayNameMagazine="Hatchet Swing";
		shortNameMagazine="Hatchet Swing";
		class ItemActions
		{
			class Use
			{
				text="$STR_ACTIONS_CHOPWOOD";
				script="spawn player_chopWood;";
			};
		};
	};
};
class CfgAmmo
{
	class Default;
	class BulletCore;
	class BulletBase;
	class Melee: BulletBase
	{
		simulationStep=0.001;
		timeToLive=0.050000001;
		typicalSpeed=70;
		airFriction=-9.9999997e-006;
		proxyShape="";
		explosive=0;
		cartridge="";
		simulation="shotRocket";
		model="\A3\Weapons_F\empty.p3d";
		muzzleEffect="";
		soundFly[]=
		{
			"",
			0,
			1
		};
		soundEngine[]=
		{
			"",
			0,
			1
		};
		visibleFire=0.1;
		audibleFire=0.0099999998;
		caliber=0.22;
		visibleFireTime=0;
		maxControlRange=1;
		soundDefault1[]={};
		soundDefault2[]={};
		soundDefault3[]={};
		soundDefault4[]={};
		soundDefault5[]={};
		soundHitBody1[]={};
		soundHitBody2[]={};
		soundConcrete1[]={};
		soundConcrete2[]={};
		soundConcrete3[]={};
		soundGlass1[]=
		{
			"A3\sounds_f\weapons\hits\glass_5",
			1.812538,
			1,
			100
		};
		soundGlass2[]=
		{
			"A3\sounds_f\weapons\hits\glass_6",
			1.812538,
			1,
			100
		};
		soundGlass3[]=
		{
			"A3\sounds_f\weapons\hits\glass_arm_6",
			1.858925,
			1,
			10
		};
		soundGlass4[]=
		{
			"A3\sounds_f\weapons\hits\glass_arm_7",
			1.858925,
			1,
			10
		};
		soundGroundHard1[]={};
		soundGroundHard2[]={};
		soundRubber1[]=
		{
			"A3\sounds_f\weapons\hits\tyre_4",
			0.89125103,
			1,
			10
		};
		soundRubber2[]=
		{
			"A3\sounds_f\weapons\hits\tyre_7",
			0.89125103,
			1,
			10
		};
		soundWater1[]=
		{
			"A3\sounds_f\weapons\hits\water_4",
			1,
			1,
			10
		};
		bulletFly1[]=
		{
			"",
			8e-006,
			1,
			30
		};
		bulletFly2[]=
		{
			"",
			0.79432797,
			1,
			30
		};
		bulletFly3[]=
		{
			"",
			0.79432797,
			1,
			30
		};
		bulletFly4[]=
		{
			"",
			0.79432797,
			1,
			30
		};
		bulletFly5[]=
		{
			"",
			0.79432797,
			1,
			30
		};
		bulletFly6[]=
		{
			"",
			0.79432797,
			1,
			30
		};
		bulletFly7[]=
		{
			"",
			0.79432797,
			1,
			30
		};
		bulletFly8[]=
		{
			"",
			0.79432797,
			1,
			30
		};
		bulletFly[]=
		{
			"bulletFly1",
			0.16599999,
			"bulletFly2",
			0.16599999,
			"bulletFly3",
			0.16599999,
			"bulletFly4",
			0.16599999,
			"bulletFly5",
			0.16599999,
			"bulletFly6",
			0.167,
			"bulletFly7",
			0.16599999,
			"bulletFly8",
			0.167
		};
		hitDefault[]=
		{
			"soundDefault1",
			0.2,
			"soundDefault2",
			0.2,
			"soundDefault3",
			0.2,
			"soundDefault4",
			0.2,
			"soundDefault5",
			0.2
		};
		hitGlass[]=
		{
			"soundGlass1",
			0.40000001,
			"soundGlass2",
			0.40000001,
			"soundGlass3",
			0.1,
			"soundGlass4",
			0.1
		};
		hitGroundHard[]=
		{
			"soundGroundHard1",
			0.60000002,
			"soundGroundHard2",
			0.40000001
		};
		hitConcrete[]=
		{
			"soundConcrete1",
			0.33000001,
			"soundConcrete2",
			0.33000001,
			"soundConcrete3",
			0.34
		};
		hitRubber[]=
		{
			"soundRubber1",
			0.60000002,
			"soundRubber2",
			0.40000001
		};
		hitWater[]=
		{
			"soundWater1",
			0.125
		};
		hitMan[]=
		{
			"soundHitBody1",
			0.5,
			"soundHitBody2",
			0.5
		};
		supersonicCrackNear[]=
		{
			"",
			0.35481301,
			1,
			10
		};
		supersonicCrackFar[]=
		{
			"",
			0.281838,
			1,
			10
		};
		cost=0.0099999998;
		deflecting=0;
		effectsMissileInit="";
		effectsMissile="EmptyEffect";
		effectsSmoke="";
		explosionEffects="";
		craterEffects="";
		class HitEffects
		{
			Hit_Foliage_green="ImpactLeavesGreen";
			Hit_Foliage_Dead="ImpactLeavesDead";
			Hit_Foliage_Green_big="ImpactLeavesGreenBig";
			Hit_Foliage_Palm="ImpactLeavesPalm";
			Hit_Foliage_Pine="ImpactLeavesPine";
			hitFoliage="";
			hitGlass="ImpactGlass";
			hitGlassArmored="ImpactGlassThin";
			hitWood="ImpactWood";
			hitMetal="ImpactMetal";
			hitMetalPlate="ImpactMetal";
			hitBuilding="ImpactPlaster";
			hitPlastic="ImpactPlastic";
			hitRubber="ImpactRubber";
			hitConcrete="ImpactConcrete";
			hitMan="ImpactEffectsBlood";
			hitGroundSoft="";
			hitGroundHard="";
			hitWater="ImpactEffectsWater";
			default_mat="";
		};
	};
	class Hatchet_Swing_Ammo: Melee
	{
		hit=12;
		typicalSpeed=85;
		timeToLive=0.02;
		airFriction=-1e-006;
		soundFly[]=
		{
			"",
			0,
			1
		};
		soundEngine[]=
		{
			"",
			0,
			1
		};
		visibleFire=0.1;
		audibleFire=0.0099999998;
		caliber=1;
		deflecting=0;
		model="\A3\Weapons_F\empty.p3d";
		class Melee
		{
			damageHit=0.55000001;
			damageBlood=3500;
			anim="GestureSwing";
			radius=2.5;
			angle=50;
		};
		class Medical
		{
			InstantBleeding=1;
			MedicalState=3;
			MedicalChance=80;
			BleedingLevel=3;
			BleedingChance=50;
			Infection=0;
			InfectionChance=0;
			Knockout=0;
			KnockoutChance=0;
			scale=0;
		};
	};
};
