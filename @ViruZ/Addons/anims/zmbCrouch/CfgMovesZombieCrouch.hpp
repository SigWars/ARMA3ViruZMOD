class CfgMovesZombieCrouch : CfgMovesBasic {
	
	skeletonName = "OFP2_ManSkeleton";
	gestures = "CfgGesturesZombie";
	extended = "CfgExtendedAnimation";
	
	class Actions : Actions {
		
		class zombieStandActions : CivilStandActions {
			stop = "AidlPercMstp01";
			default = "AmovPercMstp";
			stopRelaxed = "AidlPercMstp01";
			walkF = "AmovPercMstp_AmovPercMltrDf";
			walkLF = "AmovPercMstp_AmovPercMltrDf";
			walkRF = "AmovPercMstp_AmovPercMltrDf";
			PlayerWalkF = "AmovPercMstp_AmovPercMltrDf";
			PlayerWalkLF = "AmovPercMstp_AmovPercMltrDf";
			PlayerWalkRF = "AmovPercMstp_AmovPercMltrDf";
			slowF = "AmovPercMstp_AmovPercMalrDf";
			slowLF = "AmovPercMstp_AmovPercMalrDf";
			slowRF = "AmovPercMstp_AmovPercMalrDf";
			PlayerSlowF = "AmovPercMstp_AmovPercMalrDf";
			PlayerSlowLF = "AmovPercMstp_AmovPercMalrDf";
			PlayerSlowRF = "AmovPercMstp_AmovPercMalrDf";
			fastF = "Czm2AidlPcroMltr_Czm2AmovPcroMfrzDf_A";
			fastLF = "Czm2AidlPcroMltr_Czm2AmovPcroMfrzDf_A";
			fastRF = "Czm2AidlPcroMltr_Czm2AmovPcroMfrzDf_A";
			turnSpeed = 80;
			limitFast = 4;
			leanRRot = 0.57;
			leanRShift = 0.1;
			leanLRot = 0.57;
			leanLShift = 0.07;
			upDegree = "ManPosNoWeapon";
			Feed = "AfedPcroMstp_v1";
			FeedIn = "AfedPcroMstp_v1";
			AttackLong = "Czm2AtckPercMfrz_charge";
			AttackShort = "AtckPcroMfrzDf_Amid1";
			SniffAir = "AmovPercMstp_sniffing_randomizer";
			GetMad = "AmovPercMstp_aggravated";
			AttackShortLow = "AtckPcroMfrzDf_Alow1";
			TurnL = "AmovPercMstp_TurnL";
			TurnR = "AmovPercMstp_TurnR";
			KnockDownBack = "knockDownBack_pose";
			KnockDownFront = "knockDownFront_pose";
			AttackShortHigh = "AtckPcroMfrzDf_Ahigh1";
		};
		
		class zombieWalkActions : zombieStandActions {
			SlowF = "AmovPercMalrDf";
			PlayerSlowF = "AmovPercMalrDf";
			WalkF = "AmovPercMltrDf";
			PlayerWalkF = "AmovPercMltrDf";
			FastF = "AmovPercMfrzDf";
			Stop = "AmovPercMstp";
			StopRelaxed = "AmovPercMstp";
		};
		
		class zombieRunActions : zombieWalkActions {
			Stop = "AidlPcroMltrA_Czm2AmovPcroMltrDfA";
			StopRelaxed = "AidlPcroMltrA_Czm2AmovPcroMltrDfA";
		};
		
		class zombieSprintActions : zombieRunActions {
			Stop = "Czm2AmovPcroMfrzDf_Czm2AidlPcroMltr_A";
			StopRelaxed = "Czm2AmovPcroMfrzDf_Czm2AidlPcroMltr_A";
		};
		
		class ZombieFeedActions : zombieStandActions {
			Stop = "AfedPcroMstp_v1";
			StopRelaxed = "AfedPcroMstp_v1";
			FeedOut = "Czm2AmovPcroMstp_FeedOut";
			FeedIn = "";
			AttackLong = "";
			AttackShort = "";
			SniffAir = "";
		};
		
		class ZombieKnockedDownActions : zombieStandActions {
			attackShort = "";
		};
	};
	
	class States {
		
		class TransAnimBase : Default {
			visibleSize = 0.500125;
			looped = false;
			enableOptics = false;
			leftHandIKBeg = true;
			leftHandIKCurve[] = {1};
			leftHandIKEnd = true;
			rightHandIKBeg = true;
			rightHandIKCurve[] = {1};
			rightHandIKEnd = true;
			soundEdge[] = {0.01};
			headBobStrength = 0.164179;
			headBobMode = 2;
		};
		
		class Czm2AmovPercMstp_FeedIn : TransAnimBase {
			ConnectTo[] = {"AfedPcroMstp_v1", 1.0};
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Afed\Pcro\Mstp\Czm2AmovPercMstp_FeedIn.rtm";
			speed = 1.5015;
			interpolationRestart = true;
		};
		
		class Czm2AmovPcroMstp_FeedOut : Czm2AmovPercMstp_FeedIn {
			minPlayTime = 0.9;
			ConnectTo[] = {};
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Afed\Pcro\Mstp\Czm2AmovPcroMstp_FeedOut.rtm";
			speed = 1.2005;
			actions = "zombieStandActions";
			InterpolateTo[] = {"AmovPercMstp", 1.0};
		};
		
		class AmovPercMstp : Default {
			InterpolateTo[] = {"Czm2AmovPercMstp_FeedIn", 1.0, "AidlPercMstp01", 1.0, "AmovPercMstp_aggravated", 1.0, "AdthPercMstp_v1", 1.0, "AmovPercMstp_TurnL", 0.025, "AmovPercMstp_TurnR", 0.025, "Czm2AmovPercMstp_knockDownFront", 1.0, "AmovPercMstp_knockDownBack", 1.0, "AidlPercMstp02", 1.0, "AidlPercMstp03", 1.0, "AmovPercMstp_sniffing_randomizer", 1.0, "AmovPercMstp_AmovPercMltrDf", 1.0, "AtckPcroMfrzDf_Amid1", 1.0, "AtckPcroMfrzDf_Alow1", 1.0, "AtckPcroMfrzDf_Ahigh1", 1.0, "Czm2AtckPercMfrz_charge", 1.0, "AmovPercMstp_AmovPercMalrDf", 1.0, "AmovPercMfrzDf", 1.0, "Czm2AidlPcroMltr_Czm2AmovPcroMfrzDf_A", 1.0};
			actions = "zombieStandActions";
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Amov\Pcro\Czm2AmovPcroMstp_pose_A.rtm";
			speed = 10000000;
			interpolationSpeed = 3;
			//collisionShape = "dz\anims\data\geom\zmbCrouch\zmbKnl.p3d";
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Pknl_Wnon.p3d";	// модификация
			ragdoll = 1;												// модификация
		};
		
		class Czm2AidlPcroMltr_Czm2AmovPcroMfrzDf_A : Default {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Aidl\Pcro\Czm2AidlPcroMltr_Czm2AmovPcroMfrzDf_A.rtm";
			speed = 1.5798;
			looped = false;
			ConnectTo[] = {"AmovPercMfrzDf", 1.0};
			actions = "zombieSprintActions";
			interpolationRestart = true;
			onLandBeg = true;
			InterpolateTo[] = {"AdthPercMstp_v1", 0.01};
			//collisionShape = "dz\anims\data\geom\zmbCrouch\zmbKnlRunSpr.p3d";
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Pknl_Wnon.p3d";	// модификация
		};
		
		class AmovPercMstp_AmovPercMltrDf : AmovPercMstp {
			InterpolateTo[] = {"AdthPercMstp_v1", 0.01};
			ConnectTo[] = {"AmovPercMltrDf", 1.0};
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Aidl\Pcro\Czm2AidlPcroMltr_Czm2AmovPcroMltrDf_A.rtm";
			looped = false;
			speed = 0.577;
			actions = "zombieRunActions";
			interpolationRestart = true;
		};
		
		class AmovPercMstp_AmovPercMalrDf : AmovPercMstp {
			ConnectTo[] = {"AmovPercMalrDf", 1.0};
			InterpolateTo[] = {"AdthPercMstp_v1", 0.01};
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Aidl\Pcro\Czm2AidlPcroMltr_Czm2AmovPcroMalrDf_A.rtm";
			speed = 1.4286;
			looped = false;
			actions = "zombieRunActions";
			minPlayTime = 1;
			interpolationRestart = true;
			//collisionShape = "dz\anims\data\geom\zmbCrouch\zmbKnlRunSpr.p3d";
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Pknl_Wnon.p3d";	// модификация
		};
		
		class AmovPercMstp_TurnL : AmovPercMstp {
			InterpolateTo[] = {"AmovPercMstp", 0.025};
		};
		
		class AmovPercMstp_TurnR : AmovPercMstp_TurnL {};
		
		class AmovPercMfrzDf : AmovPercMstp {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Amov\Pcro\Czm2AmovPcroMfrzDf_A.rtm";
			speed = 1.3643;
			soundEdge[] = {0.25, 0.5, 0.75, 1};
			duty = 0.1;
			soundOverride = "run";
			relSpeedMin = 1;
			relSpeedMax = 1;
			walkcycles = 3;
			disableWeapons = true;
			InterpolateTo[] = {"AmovPercMalrDf", 0.02, "AmovPercMfrzDf", 0.02, "AdthPercMalrDf_v1", 1.0, "Czm2AtckPercMfrz_charge", 1.0, "Czm2AmovPcroMfrzDf_Czm2AidlPcroMltr_A", 1.0};
			actions = "zombieSprintActions";
			interpolationSpeed = 5;
			//collisionShape = "dz\anims\data\geom\zmbCrouch\zmbKnlRunSpr.p3d";
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Pknl_Wnon.p3d";	// модификация
		};
		
		class Czm2AmovPcroMfrzDf_Czm2AidlPcroMltr_A : AmovPercMstp {
			InterpolateTo[] = {"AdthPercMstp_v1", 0.01};
			ConnectTo[] = {"AmovPercMstp", 1.0};
			interpolationRestart = true;
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Amov\Pcro\Czm2AmovPcroMfrzDf_Czm2AidlPcroMltr_A.rtm";
			speed = 1.0;
			looped = false;
			//collisionShape = "dz\anims\data\geom\zmbCrouch\zmbKnlRunSpr.p3d";
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Pknl_Wnon.p3d";	// модификация
		};
		
		class AmovPercMltrDf : AmovPercMstp {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Amov\Pcro\Czm2AmovPcroMltrDf_A.rtm";
			soundEdge[] = {0.25, 0.5, 0.75, 1};
			speed = 0.15;
			duty = -0.1;
			soundOverride = "walk";
			walkcycles = 3;
			ConnectTo[] = {};
			InterpolateTo[] = {"AdthPercMltrDf", 1.0, "AmovPercMalrDf", 0.03, "AdthPercMstp_v1", 1.0, "Czm2AtckPercMfrz_charge", 1.0, "AmovPercMstp", 1.0};
			interpolationSpeed = 2.5;
			actions = "zombieWalkActions";
		};
		
		class AidlPcroMltrA_Czm2AmovPcroMltrDfA : AmovPercMstp {
			InterpolateTo[] = {"AdthPercMstp_v1", 0.01};
			ConnectTo[] = {"AmovPercMstp", 0.25};
			speed = 0.8826;
			looped = false;
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Amov\Pcro\Czm2AmovPcroMalrDf_Czm2AidlPcroMltr_A.rtm";
			interpolationRestart = true;
			//collisionShape = "dz\anims\data\geom\zmbCrouch\zmbKnlRunSpr.p3d";
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Pknl_Wnon.p3d";	// модификация
		};
		
		class AfedPcroMstp_v1 : Default {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Afed\Pcro\Mstp\Czm2AfedPcroMstp_v1.rtm";
			speed = 0.2;
			ConnectTo[] = {"Czm2AmovPcroMstp_FeedOut", 1.0};
			//collisionShape = "dz\anims\data\Geom\Sdr\Pknl_Wnon.p3d";
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Pknl_Wnon.p3d";	// модификация
			actions = "ZombieFeedActions";
			
			class AnimHooks {
				class Begin1 {
					param = "bhand";
					type = VArmor;
					time = 0.145078;
				};
				
				class End1 {
					param = "empty";
					type = VAir;
					time = 0.186529;
				};
				
				class Begin2 : Begin1 {
					time = 0.222798;
				};
				
				class End2 : End1 {
					time = 0.243523;
				};
				
				class Begin3 : Begin1 {
					time = 0.305699;
				};
				
				class End3 : End1 {
					time = 0.326425;
				};
				
				class Begin4 : Begin1 {
					time = 0.725389;
				};
				
				class End4 : End1 {
					time = 0.777202;
				};
			};
		};
		
		class DeadState : Default {
			actions = "DeadActions";
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Adth\Czm2AdthPcroMstpDf_A.rtm";
			speed = 1.67;
			looped = false;
			onLandBeg = true;
			onLandEnd = true;
			soundEnabled = false;
			terminal = true;
			headBobMode = 2;
		};
		
		class AmovPercMalrDf : AmovPercMstp {
			InterpolateTo[] = {"AmovPercMfrzDf", 0.03, "AmovPercMltrDf", 0.03, "AdthPercMstp_v1", 1.0, "Czm2AtckPercMfrz_charge", 1.0, "AidlPcroMltrA_Czm2AmovPcroMltrDfA", 1.0};
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Amov\Pcro\Czm2AmovPcroMalrDf_A.rtm";
			speed = 0.811;
			interpolationSpeed = 2.5;
			actions = "zombieRunActions";
			//collisionShape = "dz\anims\data\geom\zmbCrouch\zmbKnlRunSpr.p3d";
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Pknl_Wnon.p3d";	// модификация
		};
		
		class AdthPercMstp_v1 : DefaultDie {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Adth\Czm2AdthPcroMstpDf_A.rtm";
			speed = 0.5171;
			equivalentTo = "AdthPercMstpSlowWlnrDnon_1";
			variantsPlayer[] = {"AdthPercMstpSlowWlnrDnon_1", 0.5};
			terminal = true;
			onLandEnd = true;
			looped = false;
			ConnectTo[] = {"DeadState", 1.0};
			actions = "DeadActions";
		};
		
		class AdthPercMalrDf_v1 : AdthPercMstp_v1 {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Adth\Czm2AdthPcroMstpDf_A.rtm";
			speed = 0.5171;
			equivalentTo = "AdthPercMrunSnonWnonDf_1";
			ArrayVariable_1194 = "";
			ArrayVariable_1193 = "";
			ArrayVariable_1192 = "";
		};
		
		class AdthPercMalrDf_v2 : AdthPercMstp_v1 {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Adth\Czm2AdthPcroMstpDf_A.rtm";
			speed = 0.3159;
		};
		
		class AdthPercMstp_v2 : AdthPercMstp_v1 {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Adth\Czm2AdthPcroMstpDf_A.rtm";
			speed = 0.5084;
			interpolationSpeed = 10;
		};
		
		class AdthPercMstp_v3 : AdthPercMstp_v1 {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Adth\Czm2AdthPcroMstpDf_A.rtm";
		};
		
		class AdthPercMltrDf : AdthPercMstp_v1 {
			equivalentTo = "AdthPercMstpSnonWnonDnon_1";
			variantsPlayer[] = {};
			speed = 0.5171;
		};
		
		class AdthPpneMstp_v1 : AdthPercMstp_v1 {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Adth\Czm2AdthPcroMstpDf_A.rtm";
		};
		
		class AtckPcroMfrzDf_Alow1 : AmovPercMstp {
			minPlayTime = 0.95;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMstp_v1", 1.0};
			looped = false;
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Atck\Pcro\Czm2AtckPcroMfrzDf_jump_low_A.rtm";
			speed = 0.5456;
			interpolationRestart = true;
			
			class AnimHooks {
				class Begin {
					param = "bhand";
					time = 0.25;
					type = VArmor;
				};
				
				class End : Begin {
					type = VAir;
					time = 0.29;
					param = "empty";
				};
			};
			//collisionShape = "dz\anims\data\geom\zmbCrouch\zmbKnlAttack.p3d";
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Pknl_Wnon.p3d";	// модификация
		};
		
		class AtckPcroMfrzDf_Amid1 : AtckPcroMfrzDf_Alow1 {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Atck\Pcro\Czm2AtckPcroMfrzDf_jump_mid_A.rtm";
			speed = 0.5456;
			
			class AnimHooks {
				class Begin {
					time = 0.37037;
					param = "bhand";
					type = VArmor;
				};
				
				class End : Begin {
					time = 0.4444;
					param = "empty";
					type = VAir;
				};
			};
		};
		
		class AtckPcroMfrzDf_Ahigh1 : AtckPcroMfrzDf_Alow1 {
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Atck\Pcro\Czm2AtckPcroMfrzDf_jump_high_A.rtm";
			speed = 0.7143;
			
			class AnimHooks {
				class Begin {
					time = 0.314286;
					type = VArmor;
					param = "bhand";
				};
				
				class End {
					param = "empty";
					time = 0.457143;
					type = VAir;
				};
			};
		};
		
		class ZombieGettingAggravated : Default {};
		
		class Czm2AtckPercMfrz_charge : AmovPercMfrzDf {
			minPlayTime = 0.95;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMalrDf_v1", 1.0};
			speed = 0.8826;
			looped = false;
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Atck\Pcro\Czm2AtckPcroMfrz_charge_A.rtm";
			
			class AnimHooks {
				class Begin {
					param = "bhand";
					time = 0.15789;
					type = VArmor;
				};
				
				class End {
					param = "empty";
					type = VAir;
					time = 0.47368;
				};
			};
			interpolationRestart = true;
			interpolationSpeed = 6;
		};
		
		class AidlPercMstp01 : AmovPercMstp {
			variantAfter[] = {0.3, 0.3, 0.3};
			variantsPlayer[] = {"AidlPercMstp01", 0.98, "AidlPercMstp02", 0.01, "AidlPercMstp03", 0.01};
			ConnectTo[] = {};
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Aidl\Pcro\Czm2AidlPcroMltr_A.rtm";
			speed = 0.2041;
			interpolationRestart = true;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AidlPercMstp03", 1.0, "AidlPercMstp02", 1.0, "AdthPercMstp_v1", 0.01};
		};
		
		class AidlPercMstp02 : AidlPercMstp01 {
			ConnectTo[] = {"AidlPercMstp01", 1.0};
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Aidl\Pcro\Czm2AidlPcroMltr_A.rtm";
			speed = 0.2041;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMstp_v1", 0.01};
			interpolationSpeed = 100;
		};
		
		class AidlPercMstp03 : AidlPercMstp01 {
			ConnectTo[] = {"AidlPercMstp01", 1.0};
			file = "\DZ\anims\data\anim\zmb\Czm2crouch\Aidl\Pcro\Czm2AidlPcroMltr_A.rtm";
			speed = 0.2041;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMstp_v1", 0.01};
			interpolationSpeed = 100;
		};
		
		class AmovPercMstp_sniffing_randomizer : AmovPercMstp {
			variantAfter[] = {0, 0, 0};
			variantsPlayer[] = {"AmovPercMstp_sniffing1", 0.5, "AmovPercMstp_sniffing2", 0.5};
			InterpolateTo[] = {"AmovPercMstp_sniffing1", 1.0, "AmovPercMstp_sniffing2", 1.0};
			ConnectTo[] = {"AmovPercMstp", 1.0};
		};
		
		class AmovPercMstp_sniffing1 : AmovPercMstp {
			variantAfter[] = {0, 0, 0};
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Amov\Pcro\Czm2AmovPcroMstp_sniffing1_A.rtm";
			speed = 0.1515;
			looped = false;
			InterpolateTo[] = {"AdthPercMstp_v1", 1.0};
			ConnectTo[] = {"AmovPercMstp", 1.0};
			interpolationRestart = true;
			equivalentTo = "AmovPercMstp_sniffing_randomizer";
		};
		
		class AmovPercMstp_sniffing2 : AmovPercMstp_sniffing1 {
			InterpolateTo[] = {"AdthPercMstp_v1", 0.01};
			ConnectTo[] = {"AmovPercMstp", 1.0};
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Amov\Pcro\Czm2AmovPcroMstp_sniffing2_A.rtm";
			speed = 0.1587;
		};
		
		class AmovPercMstp_aggravated : AmovPercMstp {
			minPlayTime = 0.95;
			InterpolateTo[] = {"AdthPercMstp_v1", 1.0, "AmovPercMfrzDf", 1.0};
			ConnectTo[] = {};
			looped = false;
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Amov\Pcro\Czm2AmovPcroMstp_aggravated_A.rtm";
			speed = 0.6002;
			interpolationRestart = true;
		};
		
		class AmovPercMstp_knockDownBack : AmovPercMstp {
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Misc\knockdown\Czm2AmovPknlMstp_knockDownBack_A.rtm";
			looped = false;
			speed = 0.484;
			ConnectTo[] = {"knockDownBack_pose", 1.0};
			interpolationRestart = true;
			InterpolateTo[] = {"AdthPercMstp_v1", 1.0};
			actions = "ZombieKnockedDownActions";
		};
		
		class knockDownBack_pose : AmovPercMstp_knockDownBack {
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Misc\knockdown\knockDownBack_pose_A.rtm";
			looped = false;
			ConnectTo[] = {"knockDownBack_Czm2AmovPercMstp", 1.0};
			speed = 1000000;
			InterpolateTo[] = {"AdthPpneMstp_v1", 1.0};
		};
		
		class knockDownBack_Czm2AmovPercMstp : AmovPercMstp_knockDownBack {
			minPlayTime = 0.95;
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Misc\knockdown\knockDownBack_Czm2AmovPknlMstp_A.rtm";
			looped = false;
			speed = 0.2564;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMstp_v1", 1.0};
			ConnectTo[] = {};
		};
		
		class Czm2AmovPercMstp_knockDownFront : AmovPercMstp {
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Misc\knockdown\Czm2AmovPknlMstp_knockDownFront_A.rtm";
			looped = false;
			speed = 0.3846;
			InterpolateTo[] = {"AdthPercMstp_v1", 1.0};
			ConnectTo[] = {"knockDownFront_pose", 1.0};
			interpolationRestart = true;
			actions = "ZombieKnockedDownActions";
		};
		
		class knockDownFront_pose : Czm2AmovPercMstp_knockDownFront {
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Misc\knockdown\knockDownFront_pose_A.rtm";
			looped = false;
			InterpolateTo[] = {"AdthPpneMstp_v1", 1.0};
			ConnectTo[] = {"knockDownFront_Czm2AmovPercMstp", 1.0};
			speed = 1000000;
		};
		
		class knockDownFront_Czm2AmovPercMstp : Czm2AmovPercMstp_knockDownFront {
			minPlayTime = 0.95;
			file = "\dz\anims\data\anim\zmb\Czm2crouch\Misc\knockdown\knockDownFront_Czm2AmovPknlMstp_A.rtm";
			looped = false;
			speed = 0.3093;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMstp_v1", 1.0};
		};
	};
	
	class BlendAnims : BlendAnims {
		wholeBody[] = {"Pelvis", 1, "Spine", 1, "Spine1", 1, "Spine2", 1, "Spine3", 1, "Camera", 1, "weapon", 1, "launcher", 1, "neck", 1, "neck1", 1, "head", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "LeftUpLeg", 1, "LeftUpLegRoll", 1, "LeftLeg", 1, "LeftLegRoll", 1, "LeftFoot", 1, "LeftToeBase", 1, "RightUpLeg", 1, "RightUpLegRoll", 1, "RightLeg", 1, "RightLegRoll", 1, "RightFoot", 1, "RightToeBase", 1};
		aimingDefault[] = {"head", 0.6, "neck1", 0.6, "neck", 0.6, "weapon", 1, "launcher", 1, "LeftShoulder", 0.8, "LeftArm", 0.8, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 0.8, "RightArm", 0.8, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 0.3, "Spine1", 0.4, "Spine2", 0.5, "Spine3", 0.6};
		aimingPistol[] = {"head", 0.6, "neck1", 0.6, "neck", 0.6, "LeftShoulder", 0.8, "launcher", 1, "weapon", 1, "LeftArm", 0.8, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 0.8, "RightArm", 0.8, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 0.3, "Spine1", 0.4, "Spine2", 0.5, "Spine3", 0.6};
		aimingLauncher[] = {"head", 0.6, "neck1", 0.6, "neck", 0.6, "launcher", 1, "weapon", 1, "LeftShoulder", 0.8, "LeftArm", 0.8, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 0.8, "RightArm", 0.8, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 0.3, "Spine1", 0.4, "Spine2", 0.5, "Spine3", 0.6};
		aimingCivil[] = {"neck1", 0.25, "neck", 0.25, "Spine", 0.3, "Spine1", 0.4, "Spine2", 0.5, "Spine3", 0.5};
		aimingLying[] = {"weapon", 1, "LeftShoulder", 0.8, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 0.8, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine2", 0.2, "Spine3", 0.6};
		aimingLyingPistol[] = {"LeftShoulder", 0.8, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 0.8, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine2", 0.2, "Spine3", 0.6};
		legsLyingAiming[] = {"weapon", 0, "LeftShoulder", 0.2, "LeftArm", 0, "LeftArmRoll", 0, "LeftForeArm", 0, "LeftForeArmRoll", 0, "LeftHand", 0, "LeftHandRing", 0, "LeftHandPinky1", 0, "LeftHandPinky2", 0, "LeftHandPinky3", 0, "LeftHandRing1", 0, "LeftHandRing2", 0, "LeftHandRing3", 0, "LeftHandMiddle1", 0, "LeftHandMiddle2", 0, "LeftHandMiddle3", 0, "LeftHandIndex1", 0, "LeftHandIndex2", 0, "LeftHandIndex3", 0, "LeftHandThumb1", 0, "LeftHandThumb2", 0, "LeftHandThumb3", 0, "RightShoulder", 0.2, "RightArm", 0, "RightArmRoll", 0, "RightForeArm", 0, "RightForeArmRoll", 0, "RightHand", 0, "RightHandRing", 0, "RightHandPinky1", 0, "RightHandPinky2", 0, "RightHandPinky3", 0, "RightHandRing1", 0, "RightHandRing2", 0, "RightHandRing3", 0, "RightHandMiddle1", 0, "RightHandMiddle2", 0, "RightHandMiddle3", 0, "RightHandIndex1", 0, "RightHandIndex2", 0, "RightHandIndex3", 0, "RightHandThumb1", 0, "RightHandThumb2", 0, "RightHandThumb3", 0, "Spine2", 0.8, "Spine3", 0.4, "spine1", 1, "pelvis", 1, "leftupleg", 1, "leftuplegroll", 1, "leftleg", 1, "leftlegroll", 1, "leftfoot", 1, "LeftToeBase", 1, "rightupleg", 1, "rightuplegroll", 1, "rightleg", 1, "rightlegroll", 1, "rightfoot", 1, "RightToeBase", 1};
		legsLyingAimingPistol[] = {"LeftShoulder", 0.2, "LeftArm", 0, "LeftArmRoll", 0, "LeftForeArm", 0, "LeftForeArmRoll", 0, "LeftHand", 0, "LeftHandRing", 0, "LeftHandPinky1", 0, "LeftHandPinky2", 0, "LeftHandPinky3", 0, "LeftHandRing1", 0, "LeftHandRing2", 0, "LeftHandRing3", 0, "LeftHandMiddle1", 0, "LeftHandMiddle2", 0, "LeftHandMiddle3", 0, "LeftHandIndex1", 0, "LeftHandIndex2", 0, "LeftHandIndex3", 0, "LeftHandThumb1", 0, "LeftHandThumb2", 0, "LeftHandThumb3", 0, "RightShoulder", 0.2, "RightArm", 0, "RightArmRoll", 0, "RightForeArm", 0, "RightForeArmRoll", 0, "RightHand", 0, "RightHandRing", 0, "RightHandPinky1", 0, "RightHandPinky2", 0, "RightHandPinky3", 0, "RightHandRing1", 0, "RightHandRing2", 0, "RightHandRing3", 0, "RightHandMiddle1", 0, "RightHandMiddle2", 0, "RightHandMiddle3", 0, "RightHandIndex1", 0, "RightHandIndex2", 0, "RightHandIndex3", 0, "RightHandThumb1", 0, "RightHandThumb2", 0, "RightHandThumb3", 0, "Spine2", 0.8, "Spine3", 0.4, "spine1", 1, "pelvis", 1, "leftupleg", 1, "leftuplegroll", 1, "leftleg", 1, "leftlegroll", 1, "leftfoot", 1, "LeftToeBase", 1, "rightupleg", 1, "rightuplegroll", 1, "rightleg", 1, "rightlegroll", 1, "rightfoot", 1, "RightToeBase", 1};
		headDefault[] = {"head", 1, "neck1", 0.5, "neck", 0.5};
		leaningDefault[] = {"PropCamera1st", 1, "weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmExtra", 1, "LeftArmRoll", 1, "LeftElbowExtra", 1, "LeftForeArm", 1, "LeftForeArmExtra", 1, "LeftForeArmRoll", 1, "LeftWristExtra", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmExtra", 1, "RightArmRoll", 1, "RightElbowExtra", 1, "RightForeArm", 1, "RightForeArmExtra", 1, "RightForeArmRoll", 1, "RightWristExtra", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7, "pelvis", 0.4};
		aimingUpDefault[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7};
		aimingUpLying[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.9, "spine2", 0.7, "spine1", 0.5};
		aimingUpPistol[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7};
		aimingUpCivil[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7};
		aimingUpLauncher[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7};
		legsDefault[] = {"LeftUpLeg", 0.9, "LeftUpLegRoll", 0.9, "LeftLeg", 0.95, "LeftLegRoll", 0.95, "LeftFoot", 1, "LeftToeBase", 1, "RightUpLeg", 0.9, "RightUpLegRoll", 0.9, "RightLeg", 0.95, "RightLegRoll", 0.95, "RightFoot", 1, "RightToeBase", 1};
	};
};
