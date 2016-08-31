class RscDisplayMain : RscStandardDisplay
{

	class controlsBackground 
	{
		class Mainback : RscPicture {
			idc = 1104;
			x = "SafeZoneX + 1.825";
			y = "SafeZoneY + 1.02";
			w = 0.627451;
			h = 1.000000;
			text = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
		};
/*		
		class CA_ARMA2 : RscPicture
		{
			text = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
		};
*/		
	};
	
	class controls 
	{
		class VersionNumber;
		class VIRUZ_Version : VersionNumber
		{
			idc = -1;
			text = "0.0.6";
			y = "22 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
		};
		/*
		delete GameLogo;
		delete ButtonPlay;
		//delete ButtonEditor;
		delete ButtonTutorialHints;
		delete ButtonCredits;
		
		class Title : RscTitle {
			text = "Menu";
		};
		
		class ButtonOptions : RscButtonMenu {
			//x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			w = "9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		class ButtonVideo : RscButtonMenu {
			//x = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			w = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		
		class ButtonAudio : RscButtonMenu {
			//x = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			w = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		
		class ButtonControls : RscButtonMenu {
			//x = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			w = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		
		class ButtonGame : RscButtonMenu {
			//x = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			w = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		
		class ButtonProfile : RscButtonMenu {
			//x = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			w = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		
		class ButtonExpansions : RscButtonMenu {
			//x = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			w = "8 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		class ButtonExit : RscButtonMenu {
			//x = "7 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			w = "9 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
		};
		
		class CA_MP : RscButtonMenu {
			idc = 105;
			x = "11 * 			(			((safezoneW / safezoneH) min 1.2) / 40) + 			(safezoneX)";
			y = "16.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";
			w = "5 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			//x = "SafeZoneX + 0.01";
			//y = "SafeZoneY + 1.05";
			text = "PLAY";
			class TextPos {
				left = 0.0;
				top = "(	4.8 *		(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) - 		(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)) / 2";
				right = 0.0;
				bottom = 0.0;
			};
			class Attributes {
				font = "PuristaLight";
				align = "center";
			};
		};
		*/
	};
};