class RscDisplayMain : RscStandardDisplay
{
	enableDisplay = 0;
	delete Spotlight;
	
	class controlsBackground 
	{
		/*class Mainback : RscPicture {
			idc = 1104;
			x = 0.631234 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.32937 * safezoneW;
			h = 0.700147 * safezoneH;
			text = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
		};*/
		
	};
	
	class controls 
	{
		
		delete Spotlight1;
		delete Spotlight2;
		delete Spotlight3;
		delete BackgroundSpotlightRight;
		delete BackgroundSpotlightLeft;
		delete BackgroundSpotlight;
		delete LogoApex;
		delete InfoDLCs;
		delete InfoDLCsOwned;
		delete InfoNews;
		
		class VersionNumber;
		class VIRUZ_Version : VersionNumber
		{
			/*idc = -1;
			text = "0.0.6";
			y = "22 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 			(safezoneY + safezoneH - 			(			((safezoneW / safezoneH) min 1.2) / 1.2))";*/
		};
		
		class LogoVZ: RscActivePicture
		{
			color[] = {0.9,0.9,0.9,1};
			shadow = 0;
			//onButtonClick = "if (scriptdone (missionnamespace getvariable ['RscDisplayMain_credits',scriptnull])) then {RscDisplayMain_credits = _this spawn (uinamespace getvariable 'bis_fnc_credits');};";
			onSetFocus = "(_this select 0) ctrlsettextcolor [1,1,1,1];";
			onKillFocus = "(_this select 0) ctrlsettextcolor [0.9,0.9,0.9,1];";
			onLoad = "(_this select 0) ctrlshow !isClass (configfile >> 'CfgPatches' >> 'A3_Map_Tanoabuka')";

			idc = 1005;
			text = "\a3\Ui_f\data\Logos\arma3_shadow_ca.paa"; //--- ToDo: Localize;
			x = 0.427835 * safezoneW + safezoneX;
			y = -0.0458901 * safezoneH + safezoneY;
			w = 0.144329 * safezoneW;
			h = 0.223955 * safezoneH;
			colorActive[] = {1,1,1,1};
			tooltip = "View game credits, see the names behind Arma 3."; //--- ToDo: Localize;
		};
		
		class LogoViruZ: LogoVZ
		{
			show = 1;
			onLoad = "(_this select 0) ctrlshow isClass (configfile >> 'CfgPatches' >> 'A3_Map_Tanoabuka')";

			idc = 17001;
			text = "z\addons\viruz_mod\gui\viruz_logo_ca.paa"; //--- ToDo: Localize;
			x = 0.427835 * safezoneW + safezoneX;
			y = -0.0458901 * safezoneH + safezoneY;
			w = 0.144329 * safezoneW;
			h = 0.223955 * safezoneH;
			colorActive[] = {1,1,1,1};
			tooltip = "View game site, see the names behind ViruZ."; //--- ToDo: Localize;
		};
		


		
	};
};