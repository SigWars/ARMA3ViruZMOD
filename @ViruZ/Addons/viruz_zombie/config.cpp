#include "BIS_AddonInfo.hpp"
#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define private		0
#define protected		1
#define public		2

#define true	1
#define false	0

#include "CfgPatches.hpp"
#include "UniformSlotInfo.hpp"
#include "CfgVehicleClasses.hpp"
class RscPicture;
#include "RscTitles.hpp"
class RscStandardDisplay;
//#include "CfgMovesBasic.hpp"
//#include "CfgMovesMaleSdr.hpp"
//#include "CfgMovesZombie.hpp"
//#include "CfgTownGeneratorUtes.hpp"
#include "CfgTownGenerator.hpp"
#include "CfgFaces.hpp"
#include "CfgVoice.hpp"
#include "CfgIdentities.hpp"
#include "CfgVehicles.hpp"

class CfgZombieAnims {
	class CfgMovesBase {
		speedFast = 4.1;
		speedWalk = 1;
		speedSlow = 3;
		attackDist = 2.5;
		feed[] = {};
	};
	class CfgMovesZombie : CfgMovesBase {
		idle[] = {"AidlPercMstp01", "AidlPercMstp02", "AidlPercMstp03"};
		attack[] = {"Czm2AtckPercMfrz", "Czm2AtckPercMstp_BothHandsLow", "Czm2AtckPercMfrz_charge"};
		aggra[] = {"AmovPercMstp_aggravated"};
		sniff[] = {"AmovPercMstp_sniffing1", "AmovPercMstp_sniffing2"};
	};
	class CfgMovesZombie_B : CfgMovesZombie {};
	class CfgMovesZombieCrouch : CfgMovesZombie {
		attackDist = 5;
		attack[] = {"Czm2AtckPercMfrz_charge", "AtckPcroMfrzDf_Alow1", "AtckPcroMfrzDf_Amid1", "AtckPcroMfrzDf_Ahigh1"};
	};
};

class cfgWeapons
{
	class InventoryItem_Base_F;
	class ItemCore;
	#include "cfgUniforms.hpp"	/// sample uniform is defined in a separate file to make it cleaner
	#include "cfgVests.hpp"		/// sample vest is defined in a separate file to make it cleaner
	#include "cfgHeadgear.hpp"	/// sample cap is defined in a separate file to make it cleaner
};