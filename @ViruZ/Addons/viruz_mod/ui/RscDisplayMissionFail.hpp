class RscDisplayMissionFail : RscStandardDisplay {
	class ControlsBackground {
		delete Vignette;
	};
	class controls {
		delete MainTitle;
		delete PlayerName;
		delete Section;
		delete MainBackground;
		delete MissionPicture;
		delete Summary;
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
		/*class MainTitle : RscText {
			text = "";
			x = "18 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "10 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "6 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
		};*/
		class ButtonCancel : RscButtonMenuOK {
			x = 0.454064 * safezoneW + safezoneX;
			y = 0.877952 * safezoneH + safezoneY;
			w = 0.0664544 * safezoneW;
			h = 0.0309546 * safezoneH;
		};

	};
};