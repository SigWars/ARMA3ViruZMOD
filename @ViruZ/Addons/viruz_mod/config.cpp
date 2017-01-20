#define VSoft		0
#define VArmor		1
#define VAir		2

#define private		0
#define protected		1
#define public		2

#define ReadAndWrite		0
#define ReadAndCreate		1
#define ReadOnly		2
#define ReadOnlyVerified		3

#define EAST 0 // (Russian)

class RscStructuredText {
	class Attributes;
};
class RscPicture;
class RscButton;
class CA_Title;
class CA_IGUI_Title;
class RscText;
class RscControlsGroup;
class RscLineBreak;
class RscIGUIShortcutButton;
class RscGearShortcutButton;
class RscIGUIListNBox;
class RscActiveText;
class RscTitle;
class RscPictureKeepAspect;
class RscStandardDisplay;
class RscProgress;
class RscProgressNotFreeze;
class RscButtonTextOnly;
class CA_TextLanguage;
class RscXListBox;
class RscButtonMenu;
class RscShortcutButton;
class RscShortcutButtonMain;
class RscListBox;
class RscCombo;
class RscButtonMenuOK;
class RscActivePicture;
class HScrollbar; //ui
class BackgroundSlotPrimary;
class RscButtonMenuCancel;




//#include "Configs\RscDisplayGenderSelect.hpp" // Escolher Homem ou Mulher desabilitado na FSM
#include "Configs\RscDisplay\RscDisplayCantConnect.hpp" //server load
#include "Configs\RscDisplay\RscDisplaySpawnSelecterAltis.hpp" //Escolher Spawn Altis
#include "Configs\RscDisplay\RscDisplaySpawnEsseker.hpp" //Escolher Spawn Esseker
#include "Configs\RscDisplay\RscDisplaySpawnSelecterBorn.hpp" //Escolher Spawn BornHolm
#include "Configs\RscDisplay\RscDisplaySpawnRandom.hpp" //Escolher Spawn Random
#include "Configs\basicdefines.hpp"
#include "Configs\CfgPatches.hpp"
#include "Configs\CfgMods.hpp"
#include "Configs\CfgAddons.hpp"
#include "Configs\CfgAISkill.hpp"

//vzgm
//#include "external\vzgm\defines.hpp" 			
//#include "external\vzgm\extra_rc.hpp"			
//#include "external\vzgm\groupManagement.hpp"	

#include "ui\RscDisplayLoading.hpp" //Nova UI
#include "ui\CfgScriptPaths.hpp"
#include "ui\CfgInGameUI.hpp"
#include "ui\RscPictureGUI.hpp"
#include "ui\RscStructuredTextGUI.hpp"
#include "ui\RscTitles.hpp"
#include "ui\RscDisplayStart.hpp"
#include "ui\RscDisplayMain.hpp"
#include "ui\RscDisplayDebriefing.hpp"
#include "ui\RscDisplayMissionFail.hpp"
#include "ui\RscDisplayInventory.hpp"
#include "ui\RscDisplayShowItemDialog.hpp"
#include "ui\RscDisplayShowCraftingDialog.hpp"
#include "ui\RscDisplayMPInterrupt.hpp"


#include "Configs\CfgFunctions.hpp"
#include "Configs\CfgWorlds.hpp"
#include "Configs\CfgMissions.hpp"

#include "Configs\CfgVehicles.hpp"
#include "Configs\CfgWeapons.hpp"
#include "Configs\CfgConstruction.hpp"
#include "Configs\CfgObjectCheck.hpp"
#include "Configs\CfgSurvival.hpp"
