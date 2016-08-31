class CfgGesturesZombie_B : CfgGesturesMale {
	skeletonName = "OFP2_ManSkeleton";
	
	class ManActions : ManActions {};
	
	class Actions : Actions {
		class NoActions : NoActions {
			turnSpeed = 0;
			upDegree = 0;
			limitFast = 1;
			useFastMove = 0;
		};
	};
	
	class Default : Default {
		actions = "NoActions";
		file = "";
		looped = true;
		relSpeedMin = 1;
		relSpeedMax = 1;
		soundEnabled = false;
		soundOverride = "";
		soundEdge[] = {0.5, 1};
		soundEdgeC[] = {0.5, 1};
		soundEdgeD[] = {0.5, 1};
		terminal = false;
		equivalentTo = "";
		connectAs = "";
		connectFrom[] = {};
		connectTo[] = {};
		interpolateWith[] = {};
		interpolateTo[] = {};
		interpolateFrom[] = {};
		mask = "empty";
		interpolationSpeed = 6;
		interpolationRestart = false;
		preload = false;
		disableWeapons = true;
		enableOptics = true;
		showWeaponAim = false;
		enableMissile = true;
		enableBinocular = true;
		showItemInHand = false;
		showItemInRightHand = false;
		showHandGun = false;
		canPullTrigger = false;
		walkcycles = 1;
		headBobMode = 0;
		headBobStrength = 0;
		leftHandIKBeg = false;
		leftHandIKEnd = false;
		rightHandIKBeg = false;
		rightHandIKEnd = false;
		leftHandIKCurve[] = {1};
		rightHandIKCurve[] = {1};
		forceAim = 0;
		
		class AnimHooks {};
		speed = 0.5;
		speedC = 0.5;
		speedD = 0.5;
	};
	
	class States : States {
		class GestureAttackRunning : Default {
			file = "\DZ\anims\data\anim\zmb\Czm2\Gst\Atck\Czm2AtckPercMstp_bothHandsGSTR_B.rtm";
			looped = false;
			mask = "fullUpperBodyNoPelvis";
			interpolationSpeed = 3;
			
			class AnimHooks {
				class Begin {
					type = VArmor;
					time = 0.38;
					param = "bhand";
				};
				
				class End {
					param = "empty";
					type = VAir;
					time = 0.42;
				};
			};
			interpolationRestart = true;
			speed = 0.5173;
			speedC = 0.5173;
			speedD = 0.5173;
		};
	};
	
	class BlendAnims : BlendAnims {
		JustRifle[] = {"weapon", 1};
		Test[] = {"Pelvis", 0, "Spine", 1, "Spine1", 1, "Spine2", 1, "Spine3", 1, "weapon", 1, "neck", 1, "neck1", 1, "head", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmExtra", 1, "LeftArmRoll", 1, "LeftElbowExtra", 1, "LeftForeArm", 1, "LeftElbowExtra", 1, "LeftForeArmRoll", 1, "LeftWristExtra", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "rightShoulder", 1, "rightArm", 1, "rightArmExtra", 1, "rightArmRoll", 1, "rightElbowExtra", 1, "rightForeArm", 1, "rightForeArmExtra", 1, "rightForeArmRoll", 1, "rightHand", 1, "rightHandRing", 1, "rightHandRing1", 1, "rightHandRing2", 1, "rightHandRing3", 1, "rightHandPinky1", 1, "rightHandPinky2", 1, "rightHandPinky3", 1, "rightHandMiddle1", 1, "rightHandMiddle2", 1, "rightHandMiddle3", 1, "rightHandIndex1", 1, "rightHandIndex2", 1, "rightHandIndex3", 1, "rightHandThumb1", 1, "rightHandThumb2", 1, "rightHandThumb3", 1};
		meleeSwing[] = {"head", 1, "neck1", 1, "neck", 1, "weapon", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 0.2, "Spine1", 0.3, "Spine2", 1, "Spine3", 1};
		FullUpperBodyNoPelvis[] = {"PropCamera1st", 1, "Launcher", 1, "Weapon", 1, "PropWeaponBody", 1, "PropWeaponSlide", 1, "PropWeaponMag", 1, "PropWeapon01", 1, "PropWeapon02", 1, "PropWeapon03", 1, "PropWeapon04", 1, "PropWeapon05", 1, "PropWeapon06", 1, "PropWeapon07", 1, "PropWeapon08", 1, "PropWeapon09", 1, "PropWeapon10", 1, "LeftHipExtra", 1, "RightHipExtra", 1, "PropBeltLeft", 1, "PropBeltRight", 1, "PropBeltCenter", 1, "TurningAxis", 1, "PropBackpackMain", 1, "PropBackpackTop", 1, "PropBackpackExtra", 1, "PropBackpackLeft", 1, "PropBackpackRight", 1, "Spine", 1, "Spine1", 1, "Spine2", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "PropVestLower", 1, "Spine3", 1, "PropVestUpper", 1, "PropVestBack", 1, "Neck", 1, "Neck1", 1, "Head", 1, "PropHelmet", 1, "PropHelmetVisor", 1, "PropMouth", 1, "PropMask", 1, "PropGlasses", 1, "PropHelmetChin", 1, "PropCamera1st", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmExtra", 1, "LeftArmRoll", 1, "LeftElbowExtra", 1, "LeftForeArm", 1, "LeftForeArmExtra", 1, "LeftForeArmRoll", 1, "LeftWristExtra", 1, "LeftHand", 1, "PropHandL", 1, "LeftHandRing", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandMiddle1", 1, "LeftHandIndex1", 1, "LeftHandThumb1", 1, "RightShoulder", 1, "RightArm", 1, "RightArmExtra", 1, "RightArmRoll", 1, "RightElbowExtra", 1, "RightForeArm", 1, "RightForeArmExtra", 1, "RightForeArmRoll", 1, "RightWristExtra", 1, "RightHand", 1, "PropHandR", 1, "RightHandRing", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandMiddle1", 1, "RightHandIndex1", 1, "RightHandThumb1", 1};
		meleeUpperBody[] = {"head", 1, "neck1", 1, "neck", 1, "weapon", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmExtra", 1, "LeftArmRoll", 1, "LeftElbowExtra", 1, "LeftForeArm", 1, "LeftForeArmExtra", 1, "LeftForeArmRoll", 1, "LeftWristExtra", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmExtra", 1, "RightArmRoll", 1, "RightElbowExtra", 1, "RightForeArm", 1, "RightForeArmExtra", 1, "RightForeArmRoll", 1, "RightWristExtra", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 1, "Spine1", 1, "Spine2", 1, "Spine3", 1};
		meleeLowerBody[] = {"Pelvis", 0, "Spine", 0, "Spine1", 0, "Spine2", 0, "Spine3", 0, "Camera", 0, "weapon", 0, "launcher", 0, "neck", 0, "neck1", 0, "head", 0, "LeftShoulder", 0, "LeftArm", 0, "LeftArmRoll", 0, "LeftForeArm", 0, "LeftForeArmRoll", 0, "LeftHand", 0, "LeftHandRing", 0, "LeftHandRing1", 0, "LeftHandRing2", 0, "LeftHandRing3", 0, "LeftHandPinky1", 0, "LeftHandPinky2", 0, "LeftHandPinky3", 0, "LeftHandMiddle1", 0, "LeftHandMiddle2", 0, "LeftHandMiddle3", 0, "LeftHandIndex1", 0, "LeftHandIndex2", 0, "LeftHandIndex3", 0, "LeftHandThumb1", 0, "LeftHandThumb2", 0, "LeftHandThumb3", 0, "RightShoulder", 0, "RightArm", 0, "RightArmRoll", 0, "RightForeArm", 0, "RightForeArmRoll", 0, "RightHand", 0, "RightHandRing", 0, "RightHandRing1", 0, "RightHandRing2", 0, "RightHandRing3", 0, "RightHandPinky1", 0, "RightHandPinky2", 0, "RightHandPinky3", 0, "RightHandMiddle1", 0, "RightHandMiddle2", 0, "RightHandMiddle3", 0, "RightHandIndex1", 0, "RightHandIndex2", 0, "RightHandIndex3", 0, "RightHandThumb1", 0, "RightHandThumb2", 0, "RightHandThumb3", 0, "LeftUpLeg", 1, "LeftUpLegRoll", 1, "LeftLeg", 1, "LeftLegRoll", 1, "LeftFoot", 1, "LeftToeBase", 1, "RightUpLeg", 1, "RightUpLegRoll", 1, "RightLeg", 1, "RightLegRoll", 1, "RightFoot", 1, "RightToeBase", 1};
		leftHand[] = {"LeftShoulder", 0.3, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1};
		launcher[] = {"LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "launcher", 1, "Spine3", 1, "Spine2", 0.75, "Spine1", 0.5, "Spine", 0.25, "weapon", 1};
		rightHand[] = {"RightShoulder", 0.3, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1};
		handsWeapon_pst[] = {"head", 1, "neck1", 1, "neck", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 0.2, "Spine1", 0.3, "Spine2", 1, "Spine3", 1};
		handsWeapon[] = {"head", 1, "neck1", 1, "neck", 1, "weapon", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmExtra", 1, "LeftArmRoll", 1, "LeftElbowExtra", 1, "LeftForeArm", 1, "LeftForeArmExtra", 1, "LeftForeArmRoll", 1, "LeftWristExtra", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmExtra", 1, "RightArmRoll", 1, "RightElbowExtra", 1, "RightForeArm", 1, "RightForeArmExtra", 1, "RightForeArmRoll", 1, "RightWristExtra", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 1, "Spine1", 1, "Spine2", 1, "Spine3", 1, "Pelvis", 1};
		leftHandInfluence[] = {"head", 0.2, "neck1", 0.3, "neck", 0.3, "weapon", 0.3, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "Spine", 0.2, "Spine1", 0.3, "Spine2", 1, "Spine3", 1};
		head[] = {"head", 1, "neck1", 0.8, "neck", 0.5};
		upperTorso[] = {"head", 1, "neck1", 1, "neck", 1, "weapon", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 1, "Spine1", 1, "Spine2", 1, "Spine3", 1};
		Legs[] = {"head", 0, "neck1", 0, "neck", 0, "weapon", 0, "LeftShoulder", 0, "LeftArm", 0, "LeftArmRoll", 0, "LeftForeArm", 0, "LeftForeArmRoll", 0, "LeftHand", 0, "LeftHandRing", 0, "LeftHandPinky1", 0, "LeftHandPinky2", 0, "LeftHandPinky3", 0, "LeftHandRing1", 0, "LeftHandRing2", 0, "LeftHandRing3", 0, "LeftHandMiddle1", 0, "LeftHandMiddle2", 0, "LeftHandMiddle3", 0, "LeftHandIndex1", 0, "LeftHandIndex2", 0, "LeftHandIndex3", 0, "LeftHandThumb1", 0, "LeftHandThumb2", 0, "LeftHandThumb3", 0, "Spine1", 0, "Spine2", 0, "Spine3", 0, "Spine", 0, "Pelvis", 0, "LeftLeg", 1, "LeftLegRoll", 1, "LeftUpLeg", 1, "LeftUpLegRoll", 1, "LeftFoot", 1, "LeftToeBase", 1, "RightLeg", 1, "RightLegRoll", 1, "RightUpLeg", 1, "RightUpLegRoll", 1, "RightFoot", 1, "RightToeBase", 1};
		LegRight[] = {"head", 0, "neck1", 0, "neck", 0, "weapon", 0, "LeftShoulder", 0, "LeftArm", 0, "LeftArmRoll", 0, "LeftForeArm", 0, "LeftForeArmRoll", 0, "LeftHand", 0, "LeftHandRing", 0, "LeftHandPinky1", 0, "LeftHandPinky2", 0, "LeftHandPinky3", 0, "LeftHandRing1", 0, "LeftHandRing2", 0, "LeftHandRing3", 0, "LeftHandMiddle1", 0, "LeftHandMiddle2", 0, "LeftHandMiddle3", 0, "LeftHandIndex1", 0, "LeftHandIndex2", 0, "LeftHandIndex3", 0, "LeftHandThumb1", 0, "LeftHandThumb2", 0, "LeftHandThumb3", 0, "Spine1", 0.3, "Spine2", 0, "Spine3", 0, "Spine", 0, "Pelvis", 0, "LeftLeg", 0, "LeftLegRoll", 0, "LeftUpLeg", 0, "LeftUpLegRoll", 0, "LeftFoot", 0, "LeftToeBase", 0, "RightLeg", 1, "RightLegRoll", 1, "RightUpLeg", 1, "RightUpLegRoll", 1, "RightFoot", 1, "RightToeBase", 1};
		LegLeft[] = {"head", 0, "neck1", 0, "neck", 0, "weapon", 0, "LeftShoulder", 0, "LeftArm", 0, "LeftArmRoll", 0, "LeftForeArm", 0, "LeftForeArmRoll", 0, "LeftHand", 0, "LeftHandRing", 0, "LeftHandPinky1", 0, "LeftHandPinky2", 0, "LeftHandPinky3", 0, "LeftHandRing1", 0, "LeftHandRing2", 0, "LeftHandRing3", 0, "LeftHandMiddle1", 0, "LeftHandMiddle2", 0, "LeftHandMiddle3", 0, "LeftHandIndex1", 0, "LeftHandIndex2", 0, "LeftHandIndex3", 0, "LeftHandThumb1", 0, "LeftHandThumb2", 0, "LeftHandThumb3", 0, "Spine1", 0, "Spine2", 0, "Spine3", 0, "Spine", 0, "Pelvis", 0, "LeftLeg", 1, "LeftLegRoll", 1, "LeftUpLeg", 1, "LeftUpLegRoll", 1, "LeftFoot", 1, "LeftToeBase", 1, "RightLeg", 0, "RightLegRoll", 0, "RightUpLeg", 0, "RightUpLegRoll", 0, "RightFoot", 0, "RightToeBase", 0};
		BodyFull[] = {"Pelvis", 1, "Spine", 1, "Spine1", 1, "Spine2", 1, "Spine3", 1, "Camera", 1, "weapon", 1, "launcher", 1, "neck", 1, "neck1", 1, "head", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmExtra", 1, "LeftArmRoll", 1, "LeftElbowExtra", 1, "LeftForeArm", 1, "LeftForeArmExtra", 1, "LeftForeArmRoll", 1, "LeftWristExtra", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmExtra", 1, "RightArmRoll", 1, "RightElbowExtra", 1, "RightForeArm", 1, "RightForeArmExtra", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "LeftUpLeg", 1, "LeftUpLegRoll", 1, "LeftLeg", 1, "LeftLegRoll", 1, "LeftFoot", 1, "LeftToeBase", 1, "RightUpLeg", 1, "RightUpLegRoll", 1, "RightLeg", 1, "RightLegRoll", 1, "RightFoot", 1, "RightToeBase", 1};
		BodyHalf[] = {"head", 0.01, "neck1", 0.01, "neck", 0.01, "weapon", 0.01, "LeftShoulder", 0.01, "LeftArm", 0.01, "LeftArmRoll", 0.01, "LeftForeArm", 0.01, "LeftForeArmRoll", 0.01, "LeftHand", 0.01, "LeftHandRing", 0.01, "LeftHandPinky1", 0.01, "LeftHandPinky2", 0.01, "LeftHandPinky3", 0.01, "LeftHandRing1", 0.01, "LeftHandRing2", 0.01, "LeftHandRing3", 0.01, "LeftHandMiddle1", 0.01, "LeftHandMiddle2", 0.01, "LeftHandMiddle3", 0.01, "LeftHandIndex1", 0.01, "LeftHandIndex2", 0.01, "LeftHandIndex3", 0.01, "LeftHandThumb1", 0.01, "LeftHandThumb2", 0.01, "LeftHandThumb3", 0.01, "Spine1", 0.01, "Spine2", 0.01, "Spine3", 0.01, "Spine", 0.01, "Pelvis", 0.01, "LeftLeg", 0.01, "LeftLegRoll", 0.01, "LeftUpLeg", 0.01, "LeftUpLegRoll", 0.01, "LeftFoot", 0.01, "LeftToeBase", 0.01, "RightLeg", 0.01, "RightLegRoll", 0.01, "RightUpLeg", 0.01, "RightUpLegRoll", 0.01, "RightFoot", 0.01, "RightToeBase", 0.01};
	};
	
	class Interpolations : Interpolations {};
	transitionsInterpolated[] = {};
	transitionsSimple[] = {};
	transitionsDisabled[] = {};
};
