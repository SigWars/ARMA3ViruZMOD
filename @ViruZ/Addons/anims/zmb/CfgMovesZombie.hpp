class CfgMovesZombie : CfgMovesBasic {
	
	skeletonName = "OFP2_ManSkeleton";
	gestures = "CfgGesturesZombie";
	extended = "CfgExtendedAnimation";
	
	class Actions : Actions {
		
		class zombieStandActions : CivilStandActions {
			stop = "AidlPercMstp01";
			default = "AmovPercMstp";
			stopRelaxed = "AidlPercMstp01";
			walkF = "AmovPercMltrDf";
			walkLF = "";
			walkRF = "";
			PlayerWalkF = "AmovPercMltrDf";
			PlayerWalkLF = "";
			PlayerWalkRF = "";
			slowF = "AmovPercMalrDf";
			slowLF = "";
			slowRF = "";
			PlayerSlowF = "AmovPercMalrDf";
			PlayerSlowLF = "";
			PlayerSlowRF = "";
			fastF = "AmovPercMfrzDf";
			fastLF = "";
			fastRF = "";
			turnSpeed = 80;
			limitFast = 4;
			leanRRot = 0.57;
			leanRShift = 0.1;
			leanLRot = 0.57;
			leanLShift = 0.07;
			upDegree = "ManPosNoWeapon";
			Feed = "AfedPcroMstp_v1";
			FeedIn = "AfedPcroMstp_v1";
			AttackShort[] = {"GestureAttackRunning", "Gesture"};
			AttackLong = "Czm2AtckPercMfrz_charge";
			SniffAir = "AmovPercMstp_sniffing_randomizer";
			GetMad = "AmovPercMstp_aggravated";
			AttackShortLow = "Czm2AtckPercMstp_BothHandsLow";
			TurnL = "AmovPercMstp_TurnL";
			TurnR = "AmovPercMstp_TurnR";
			KnockDownBack = "knockDownBack_pose";
			KnockDownFront = "knockDownFront_pose";
		};
		
		class zombieSprintActions : zombieStandActions {
			AttackShort = "Czm2AtckPercMfrz";
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
			file = "\dz\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AmovPercMstp_FeedIn.rtm";
			speed = 1.5015;
			interpolationRestart = true;
			fileB = "\dz\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AmovPercMstp_FeedIn.rtm";
			fileC = "\dz\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AmovPercMstp_FeedIn.rtm";
			fileD = "\dz\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AmovPercMstp_FeedIn.rtm";
			speedB = 1.5015;
			speedC = 1.5015;
			speedD = 1.5015;
		};
		
		class Czm2AmovPcroMstp_FeedOut : Czm2AmovPercMstp_FeedIn {
			minPlayTime = 0.9;
			ConnectTo[] = {};
			file = "\dz\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AmovPcroMstp_FeedOut.rtm";
			speed = 1.2005;
			actions = "zombieStandActions";
			InterpolateTo[] = {"AmovPercMstp", 1.0};
			fileB = "\dz\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AmovPcroMstp_FeedOut.rtm";
			fileC = "\dz\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AmovPcroMstp_FeedOut.rtm";
			fileD = "\dz\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AmovPcroMstp_FeedOut.rtm";
			speedB = 1.2005;
			speedC = 1.2005;
			speedD = 1.2005;
		};
		
		class AmovPercMstp : Default {
			InterpolateTo[] = {"AmovPercMltrDf", 0.025, "AmovPercMalrDf", 0.025, "AmovPercMfrzDf", 0.025, "Czm2AmovPercMstp_FeedIn", 1.0, "AidlPercMstp01", 1.0, "AmovPercMstp_aggravated", 1.0, "AdthPercMstp_v1", 1.0, "Czm2AtckPercMstp_BothHandsLow", 1.0, "AmovPercMstp_TurnL", 0.025, "AmovPercMstp_TurnR", 0.025, "Czm2AmovPercMstp_knockDownFront", 1.0, "AmovPercMstp_knockDownBack", 1.0, "AidlPercMstp02", 1.0, "AidlPercMstp03", 1.0, "AmovPercMstp_sniffing_randomizer", 1.0, "Czm2AtckPercMfrz_charge", 1.0};
			actions = "zombieStandActions";
			file = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_pose_A.rtm";
			speed = 10000000;
			fileB = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_pose_B.rtm";
			fileC = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_pose_C.rtm";
			fileD = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_pose_D.rtm";
			speedB = 10000000;
			speedC = 10000000;
			speedD = 10000000;
			//collisionShape = "dz\anims\data\geom\zmb\zmbErc.p3d";
			collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wnon.p3d";
			ragdoll = 1;	// модификация
		};
		
		class AmovPercMstp_TurnL : AmovPercMstp {
			InterpolateTo[] = {"AmovPercMstp", 0.025};
			soundEnabled = false;
		};
		
		class AmovPercMstp_TurnR : AmovPercMstp_TurnL {};
		
		class AmovPercMfrzDf : AmovPercMstp {
			file = "\dz\anims\data\anim\zmb\Czm2\Amov\Perc\Mfrz\Czm2AmovPercMfrzDf_A.rtm";
			speed = 0.9091;
			soundEdge[] = {0.18, 0.45, 0.7, 0.94};
			duty = 0.1;
			soundOverride = "run";
			relSpeedMin = 1;
			relSpeedMax = 1;
			walkcycles = 3;
			disableWeapons = true;
			InterpolateTo[] = {"AmovPercMalrDf", 0.02, "AmovPercMfrzDf", 0.02, "AmovPercMstp", 0.025, "Czm2AtckPercMfrz", 1.0, "Czm2AtckPercMfrz_charge", 1.0, "AdthPercMstp_v1", 0.01};
			actions = "zombieSprintActions";
			interpolationSpeed = 5;
			fileB = "\dz\anims\data\anim\zmb\Czm2\Amov\Perc\Mfrz\Czm2AmovPercMfrzDf_A.rtm";
			fileC = "\dz\anims\data\anim\zmb\Czm2\Amov\Perc\Mfrz\Czm2AmovPercMfrzDf_A.rtm";
			fileD = "\dz\anims\data\anim\zmb\Czm2\Amov\Perc\Mfrz\Czm2AmovPercMfrzDf_A.rtm";
			speedB = 0.8333;
			speedC = 0.8826;
			speedD = 0.8333;
			soundEdgeB[] = {0.22, 0.5, 0.75, 0.97};
			soundEdgeC[] = {0.21, 0.44, 0.71, 0.94};
			soundEdgeD[] = {0.18, 0.45, 0.7, 0.94};
		};
		
		class AmovPercMltrDf : AmovPercMstp {
			file = "\DZ\anims\data\anim\zmb\Czm2\Amov\Perc\Mltr\Czm2AmovPercMltrDf_A.rtm";
			soundEdge[] = {0.06, 0.23, 0.41, 0.56, 0.73, 0.89};
			speed = 0.2256;
			duty = -0.1;
			soundOverride = "walk";
			walkcycles = 3;
			ConnectTo[] = {};
			InterpolateTo[] = {"AdthPercMltrDf", 1.0, "AmovPercMstp", 0.025, "AmovPercMalrDf", 0.03, "AdthPercMstp_v1", 1.0, "Czm2AtckPercMfrz_charge", 1.0};
			interpolationSpeed = 2.5;
			fileB = "\DZ\anims\data\anim\zmb\Czm2\Amov\Perc\Mltr\Czm2AmovPercMltrDf_A.rtm";
			fileC = "\DZ\anims\data\anim\zmb\Czm2\Amov\Perc\Mltr\Czm2AmovPercMltrDf_A.rtm";
			speedB = 0.3093;
			speedC = 0.2069;
			speedD = 0.2069;
			soundEdgeB[] = {0.12, 0.3, 0.44, 0.64, 0.78, 0.97};
			soundEdgeC[] = {0.06, 0.21, 0.39, 0.54, 0.73, 0.89};
			soundEdgeD[] = {0.06, 0.22, 0.38, 0.55, 0.71, 0.9};
			fileD = "\DZ\anims\data\anim\zmb\Czm2\Amov\Perc\Mltr\Czm2AmovPercMltrDf_A.rtm";
		};
		
		class AfedPcroMstp_v1 : Default {
			file = "\DZ\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AfedPcroMstp_v1.rtm";
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
			fileB = "\DZ\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AfedPcroMstp_v1.rtm";
			fileC = "\DZ\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AfedPcroMstp_v1.rtm";
			fileD = "\DZ\anims\data\anim\zmb\Czm2\Afed\Pcro\Mstp\Czm2AfedPcroMstp_v1.rtm";
			speedB = 0.2;
			speedC = 0.2;
			speedD = 0.2;
		};
		
		class DeadState : Default {
			actions = "DeadActions";
			file = "\DZ\anims\data\anim\zmb\Czm2\Adth\Perc\Czm2AdthPercMltrDnon_A.rtm";
			speed = 1.67;
			looped = false;
			onLandBeg = true;
			onLandEnd = true;
			soundEnabled = false;
			terminal = true;
			headBobMode = 2;
			speedB = 1.67;
			speedC = 1.67;
			speedD = 1.67;
		};
		
		class AmovPercMalrDf : AmovPercMstp {
			soundEdge[] = {0.15, 0.42, 0.64, 0.88};
			InterpolateTo[] = {"AmovPercMfrzDf", 0.03, "AmovPercMstp", 0.025, "AmovPercMltrDf", 0.03, "AdthPercMstp_v1", 1.0, "Czm2AtckPercMfrz_charge", 1.0};
			file = "\DZ\anims\data\anim\zmb\Czm2\Amov\Perc\Malr\Czm2AmovPercMalrDf_A.rtm";
			speed = 0.9091;
			interpolationSpeed = 2.5;
			fileB = "\DZ\anims\data\anim\zmb\Czm2\Amov\Perc\Malr\Czm2AmovPercMalrDf_A.rtm";
			fileC = "\DZ\anims\data\anim\zmb\Czm2\Amov\Perc\Malr\Czm2AmovPercMalrDf_A.rtm";
			fileD = "\DZ\anims\data\anim\zmb\Czm2\Amov\Perc\Malr\Czm2AmovPercMalrDf_A.rtm";
			speedB = 0.8576;
			speedC = 0.7899;
			speedD = 0.8333;
			soundEdgeB[] = {0.2, 0.49, 0.71, 0.97};
			soundEdgeC[] = {0.21, 0.45, 0.68, 0.95};
			soundEdgeD[] = {0.19, 0.44, 0.69, 0.94};
		};
		
		class AdthPercMstp_v1 : DefaultDie {
			file = "\DZ\anims\data\anim\zmb\Czm2\Adth\Perc\Czm2AdthPercMltrDnon_A.rtm";
			speed = 0.5171;
			equivalentTo = "AdthPercMstpSlowWlnrDnon_1";
			variantsPlayer[] = {"AdthPercMstpSlowWlnrDnon_1", 0.5};
			terminal = true;
			onLandEnd = true;
			looped = false;
			ConnectTo[] = {"DeadState", 1.0};
			actions = "DeadActions";
			speedC = 0.5171;
			speedB = 0.5171;
			speedD = 0.5171;
			interpolationSpeed = 10;
		};
		
		class AdthPercMalrDf_v1 : AdthPercMstp_v1 {
			file = "\DZ\anims\data\anim\zmb\Czm2\Adth\Perc\Czm2AdthPercMltrDnon_A.rtm";
			speed = 0.3159;
			equivalentTo = "AdthPercMrunSnonWnonDf_1";
			ArrayVariable_1194 = "";
			ArrayVariable_1193 = "";
			ArrayVariable_1192 = "";
			speedB = 0.3159;
			speedC = 0.3159;
			speedD = 0.3159;
			interpolationSpeed = 200;
		};
		
		class AdthPercMalrDf_v2 : AdthPercMstp_v1 {
			file = "\DZ\anims\data\anim\zmb\Czm2\Adth\Perc\Czm2AdthPercMltrDnon_A.rtm";
			speed = 0.3159;
			speedB = 0.3159;
			speedC = 0.3159;
		};
		
		class AdthPercMltrDf : AdthPercMstp_v1 {
			equivalentTo = "AdthPercMstpSnonWnonDnon_1";
			variantsPlayer[] = {};
		};
		
		class AdthPpneMstp_v1 : AdthPercMstp_v1 {
			interpolationSpeed = 200;
		};
		
		class Czm2AtckPercMfrz : AmovPercMfrzDf {
			minPlayTime = 0.95;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMalrDf_v1", 1.0};
			speed = 1.3636;
			looped = false;
			file = "\dz\anims\data\anim\zmb\Czm2\Atck\Perc\Mfrz\Czm2AtckPercMfrz_A.rtm";
			
			class AnimHooks {
				class Begin {
					param = "bhand";
					type = VArmor;
					time = 0.338983;
				};
				
				class End {
					param = "empty";
					type = VAir;
					time = 0.474576;
				};
			};
			interpolationRestart = true;
			fileB = "\dz\anims\data\anim\zmb\Czm2\Atck\Perc\Mfrz\Czm2AtckPercMfrz_A.rtm";
			fileC = "\dz\anims\data\anim\zmb\Czm2\Atck\Perc\Mfrz\Czm2AtckPercMfrz_A.rtm";
			fileD = "\dz\anims\data\anim\zmb\Czm2\Atck\Perc\Mfrz\Czm2AtckPercMfrz_A.rtm";
			speedB = 1.3636;
			speedC = 1.3636;
			speedD = 1.3636;
		};
		
		class Czm2AtckPercMfrz_charge : AmovPercMfrzDf {
			minPlayTime = 0.95;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMalrDf_v1", 1.0};
			speed = 0.6386;
			looped = false;
			file = "\dz\anims\data\anim\zmb\Czm2\Atck\Perc\Mfrz\Czm2AtckPercMfrz_charge_A.rtm";
			
			class AnimHooks {
				class Begin {
					param = "bhand";
					time = 0.365385;
					type = VArmor;
				};
				
				class End {
					param = "empty";
					type = VAir;
					time = 0.461538;
				};
			};
			interpolationRestart = true;
			interpolationSpeed = 6;
			fileB = "\dz\anims\data\anim\zmb\Czm2\Atck\Perc\Mfrz\Czm2AtckPercMfrz_charge_A.rtm";
			fileC = "\dz\anims\data\anim\zmb\Czm2\Atck\Perc\Mfrz\Czm2AtckPercMfrz_charge_A.rtm";
			fileD = "\dz\anims\data\anim\zmb\Czm2\Atck\Perc\Mfrz\Czm2AtckPercMfrz_charge_A.rtm";
			speedB = 0.6386;
			speedC = 0.6386;
			speedD = 0.6386;
		};
		
		class AidlPercMstp01 : AmovPercMstp {
			variantAfter[] = {0.3, 0.3, 0.3};
			variantsPlayer[] = {"AidlPercMstp01", 0.98, "AidlPercMstp02", 0.01, "AidlPercMstp03", 0.01};
			ConnectTo[] = {};
			file = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_A.rtm";
			speed = 0.2;
			interpolationRestart = true;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AidlPercMstp03", 1.0, "AidlPercMstp02", 1.0, "AdthPercMalrDf_v1", 0.01};
			fileB = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_B.rtm";
			fileC = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_C.rtm";
			fileD = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_D.rtm";
			speedB = 0.2362;
			speedC = 0.1685;
			speedD = 0.1987;
			soundEnabled = false;
		};
		
		class AidlPercMstp02 : AidlPercMstp01 {
			ConnectTo[] = {"AidlPercMstp01", 1.0};
			file = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_break01_A.rtm";
			speed = 0.3751;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMalrDf_v1", 0.01};
			interpolationSpeed = 100;
			fileB = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_break01_B.rtm";
			fileC = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_break01_C.rtm";
			fileD = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_break01_A.rtm";
			speedB = 0.2941;
			speedC = 0.1622;
			speedD = 0.2609;
		};
		
		class AidlPercMstp03 : AidlPercMstp01 {
			ConnectTo[] = {"AidlPercMstp01", 1.0};
			file = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_break02_A.rtm";
			speed = 0.3489;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMalrDf_v1", 0.01};
			interpolationSpeed = 100;
			fileB = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_break02_B.rtm";
			fileC = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_break02_C.rtm";
			fileD = "\DZ\anims\data\anim\zmb\Czm2\Aidl\Perc\Mltr\Czm2AidlPercMltr_break02_D.rtm";
			speedB = 0.4413;
			speedC = 0.3798;
			speedD = 0.3751;
		};
		
		class AmovPercMstp_sniffing_randomizer : AmovPercMstp {
			variantAfter[] = {0, 0, 0};
			variantsPlayer[] = {"AmovPercMstp_sniffing1", 0.5, "AmovPercMstp_sniffing2", 0.5};
			InterpolateTo[] = {"AmovPercMstp_sniffing1", 1.0, "AmovPercMstp_sniffing2", 1.0};
			ConnectTo[] = {"AmovPercMstp", 1.0};
			soundEnabled = false;
		};
		
		class AmovPercMstp_sniffing1 : AmovPercMstp {
			variantAfter[] = {0, 0, 0};
			file = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_sniffing1_A.rtm";
			speed = 0.1818;
			looped = false;
			InterpolateTo[] = {"AdthPercMstp_v1", 1.0};
			ConnectTo[] = {"AmovPercMstp", 1.0};
			interpolationRestart = true;
			equivalentTo = "AmovPercMstp_sniffing_randomizer";
			fileB = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_sniffing1_A.rtm";
			fileC = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_sniffing1_A.rtm";
			fileD = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_sniffing1_A.rtm";
			soundEnabled = false;
			speedB = 0.1818;
			speedC = 0.1818;
			speedD = 0.1818;
		};
		
		class AmovPercMstp_sniffing2 : AmovPercMstp_sniffing1 {
			InterpolateTo[] = {"AdthPercMstp_v1", 0.01};
			ConnectTo[] = {"AmovPercMstp", 1.0};
			file = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_sniffing2_A.rtm";
			speed = 0.1389;
			fileB = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_sniffing2_A.rtm";
			fileC = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_sniffing2_A.rtm";
			fileD = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_sniffing2_A.rtm";
			speedB = 0.1389;
			speedC = 0.1389;
		};
		
		class AmovPercMstp_aggravated : AmovPercMstp {
			minPlayTime = 0.95;
			InterpolateTo[] = {"AdthPercMstp_v1", 1.0, "AmovPercMfrzDf", 1.0};
			ConnectTo[] = {};
			looped = false;
			file = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_aggravated_A.rtm";
			speed = 0.6002;
			interpolationRestart = true;
			fileB = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_aggravated_A.rtm";
			fileC = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_aggravated_A.rtm";
			fileD = "\DZ\anims\data\anim\zmb\Czm2\Misc\Czm2AmovPercMstp_aggravated_A.rtm";
			soundEnabled = false;
			speedB = 0.6002;
			speedC = 0.6002;
			speedD = 0.6002;
		};
		
		class Czm2AtckPercMstp_BothHandsLow : AmovPercMstp {
			minPlayTime = 0.95;
			file = "\DZ\anims\data\anim\zmb\Czm2\Atck\Perc\Mstp\Czm2AtckPercMstp_LowBothHands_A.rtm";
			speed = 0.4762;
			
			class AnimHooks {
				class Begin {
					param = "bhand";
					type = VArmor;
					time = 0.297872;
				};
				
				class End {
					param = "empty";
					type = VAir;
					time = 0.404255;
				};
			};
			interpolationRestart = true;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMstp_v1", 0.01};
			looped = false;
			fileC = "\DZ\anims\data\anim\zmb\Czm2\Atck\Perc\Mstp\Czm2AtckPercMstp_LowBothHands_A.rtm";
			fileB = "\DZ\anims\data\anim\zmb\Czm2\Atck\Perc\Mstp\Czm2AtckPercMstp_LowBothHands_A.rtm";
			fileD = "\DZ\anims\data\anim\zmb\Czm2\Atck\Perc\Mstp\Czm2AtckPercMstp_LowBothHands_A.rtm";
			speedB = 0.4762;
			speedC = 0.4762;
			speedD = 0.4762;
		};
		
		class AmovPercMstp_knockDownBack : AmovPercMstp {
			file = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\Czm2AmovPercMstp_knockDownBack_A.rtm";
			looped = false;
			speed = 0.484;
			ConnectTo[] = {"knockDownBack_pose", 1.0};
			interpolationRestart = true;
			InterpolateTo[] = {"AdthPercMstp_v1", 1.0};
			actions = "ZombieKnockedDownActions";
			fileB = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\Czm2AmovPercMstp_knockDownBack_A.rtm";
			fileC = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\Czm2AmovPercMstp_knockDownBack_A.rtm";
			fileD = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\Czm2AmovPercMstp_knockDownBack_A.rtm";
			soundEnabled = false;
			speedB = 0.484;
			speedC = 0.484;
			speedD = 0.484;
		};
		
		class knockDownBack_pose : AmovPercMstp_knockDownBack {
			file = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownBack_pose_A.rtm";
			looped = false;
			ConnectTo[] = {"knockDownBack_Czm2AmovPercMstp", 1.0};
			speed = 1000000;
			InterpolateTo[] = {"AdthPpneMstp_v1", 1.0};
			fileB = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownBack_pose_A.rtm";
			fileC = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownBack_pose_A.rtm";
			fileD = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownBack_pose_A.rtm";
			speedB = 1000000;
			speedC = 1000000;
			speedD = 1000000;
		};
		
		class knockDownBack_Czm2AmovPercMstp : AmovPercMstp_knockDownBack {
			minPlayTime = 0.95;
			file = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownBack_Czm2AmovPercMstp_A.rtm";
			looped = false;
			speed = 0.2564;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMstp_v1", 1.0};
			ConnectTo[] = {};
			fileB = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownBack_Czm2AmovPercMstp_A.rtm";
			fileC = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownBack_Czm2AmovPercMstp_A.rtm";
			fileD = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownBack_Czm2AmovPercMstp_A.rtm";
			speedB = 0.2564;
			speedC = 0.2564;
			speedD = 0.2564;
		};
		
		class Czm2AmovPercMstp_knockDownFront : AmovPercMstp {
			file = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\Czm2AmovPercMstp_knockDownFront_A.rtm";
			looped = false;
			speed = 0.3846;
			InterpolateTo[] = {"AdthPercMstp_v1", 1.0};
			ConnectTo[] = {"knockDownFront_pose", 1.0};
			interpolationRestart = true;
			actions = "ZombieKnockedDownActions";
			fileB = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\Czm2AmovPercMstp_knockDownFront_A.rtm";
			fileC = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\Czm2AmovPercMstp_knockDownFront_A.rtm";
			fileD = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\Czm2AmovPercMstp_knockDownFront_A.rtm";
			soundEnabled = false;
			speedB = 0.3846;
			speedC = 0.3846;
			speedD = 0.3846;
		};
		
		class knockDownFront_pose : Czm2AmovPercMstp_knockDownFront {
			file = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownFront_pose_A.rtm";
			looped = false;
			InterpolateTo[] = {"AdthPpneMstp_v1", 1.0};
			ConnectTo[] = {"knockDownFront_Czm2AmovPercMstp", 1.0};
			speed = 1000000;
			fileB = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownFront_pose_A.rtm";
			fileC = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownFront_pose_A.rtm";
			fileD = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownFront_pose_A.rtm";
			speedB = 1000000;
			speedC = 1000000;
			speedD = 1000000;
		};
		
		class knockDownFront_Czm2AmovPercMstp : Czm2AmovPercMstp_knockDownFront {
			minPlayTime = 0.95;
			file = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownFront_Czm2AmovPercMstp_A.rtm";
			looped = false;
			speed = 0.3093;
			InterpolateTo[] = {"AmovPercMstp", 1.0, "AdthPercMstp_v1", 1.0};
			fileB = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownFront_Czm2AmovPercMstp_A.rtm";
			fileC = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownFront_Czm2AmovPercMstp_A.rtm";
			fileD = "\dz\anims\data\anim\zmb\Czm2\Misc\knockdown\knockDownFront_Czm2AmovPercMstp_A.rtm";
			speedB = 0.3093;
			speedC = 0.3093;
			speedD = 0.3093;
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
