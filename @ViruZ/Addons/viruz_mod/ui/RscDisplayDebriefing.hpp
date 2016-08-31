class RscDisplayDebriefing : RscStandardDisplay {
	class ControlsBackground {
		delete Vignette;
	};
	class controls {
		class MainTitle : RscText {
			text = "";
			x = "18 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		class ButtonCancel : RscButtonMenuOK {
			x = "18 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "11.2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		delete MainBackground;
		delete PlayerName;
		delete Section;
		delete MissionPicture;
		delete Summary;
		delete DLCGeneralGroup;
		delete DLCBar;
		delete DLCLockIcon;
		delete DLCCountdown;
		delete DescriptionBackground;
		delete Description;
		delete ObjectivesBackground;
		delete Objectives;
		delete StatBackground;
		delete Stat;
		delete Custom;
		delete Data;
		delete Sides;
		delete ButtonOK;
		delete ButtonSteamWorkshop;
	};
};