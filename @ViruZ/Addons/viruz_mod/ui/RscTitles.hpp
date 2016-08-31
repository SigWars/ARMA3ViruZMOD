class RscTitles
{
	class Default
	{
		idd = -1;
		movingEnable = 0;
		duration = 4;
	};
	class playerKillScore 
	{
		idd = 6902;
		movingEnable = 0;
		duration = 5;
		name = "playerKillScore";
		onLoad = "uiNamespace setVariable ['VIRUZ_GUI_kills', _this select 0];";
		class ControlsBackground {
			class RscPicture_1201: RscPictureGUI
			{
				idc = 1400;
				text = "\z\addons\viruz_mod\gui\stats_kills_human_ca.paa";
				x = 0.044687 * safezoneW + safezoneX;
				y = 0.934779 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1200: RscPictureGUI
			{
				idc = 1401;
				text = "\z\addons\viruz_mod\gui\stats_kills_zombie_ca.paa";
				x = 0.044687 * safezoneW + safezoneX;
				y = 0.876025 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
		};
		class Controls{
			class RscText1: RscStructuredTextGUI
			{
				idc = 1410;
				text = "10";
				x = (0.044687 * safezoneW + safezoneX) - 0.01;
				y = 0.934779 * safezoneH + safezoneY;
				w = 0.08;
				h = 0.08;
			};
			class RscText2: RscStructuredTextGUI
			{
				idc = 1411;
				text = "1000";
				x = (0.044687 * safezoneW + safezoneX) - 0.01;
				y = 0.876025 * safezoneH + safezoneY;
				w = 0.08;
				h = 0.08;
			};
		};
	};
	
	class playerStatusWaiting
	{
		idd = 6901;
		movingEnable = 0;
		duration = 100000;
		name = "playerStatusWaiting";
		onLoad = "uiNamespace setVariable ['VIRUZ_GUI_waiting', _this select 0];";
		class ControlsBackground {
			/*class RscText_1402: RscPictureGUI
			{
				idc = 1402;
				text = "#(argb,8,8,3)color(1,1,1,1)";
				x = 0.473572 * safezoneW + safezoneX;
				y = 0.418158 * safezoneH + safezoneY;
				w = 0.0634286 * safezoneW;
				h = 0.136829 * safezoneH;
				colorText[] = {1,1,1,1};
			};
			class RscText_1400: RscPictureGUI
			{
				idc = 1400;
				text = "#(argb,8,8,3)color(1,1,1,1)";
				x = 0.473572 * safezoneW + safezoneX;
				y = 0.418158 * safezoneH + safezoneY;
				w = 0.0634286 * safezoneW;
				h = 0; //0.136829 * safezoneH;
				colorText[] = {0,0,0,1};
			};*/
			class RscPicture_1401: RscPictureGUI
			{
				idc = 1401;
				text = "\z\addons\viruz_mod\gui\status_waiting_VZ2.paa";
				x = "0.00001 * safezoneW + safezoneX";
				y = "0.00001 * safezoneH + safezoneY";
				w = "1 * safezoneW";
				h = "1 * safezoneH";
			};
		};
		/*class Controls {
			class RscPicture_1401: RscPictureGUI
			{
				idc = 1401;
				text = "\z\addons\viruz_mod\gui\status_waiting_VZ2.paa";
				x = "0.00001 * safezoneW + safezoneX";
				y = "0.00001 * safezoneH + safezoneY";
				w = "1 * safezoneW";
				h = "1 * safezoneH";
			};
		};*/
	};

	class playerStatusGUI
	{
		idd = 6900;
		movingEnable = 0;
		duration = 100000;
		name = "statusBorder";
		onLoad = "uiNamespace setVariable ['VIRUZ_GUI_display', _this select 0];";
		class ControlsBackground {
			/*class RscPicture_1201: RscPictureGUI
			{
				idc = 1201;
				text = "\z\addons\viruz_mod\gui\status_food_border_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.93 * safezoneH + safezoneY; //1
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1200: RscPictureGUI
			{
				idc = 1200;
				text = "\z\addons\viruz_mod\gui\status_blood_border_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.86 * safezoneH + safezoneY;//2
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1202: RscPictureGUI
			{
				idc = 1202;
				text = "\z\addons\viruz_mod\gui\status_thirst_border_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.79 * safezoneH + safezoneY; //3
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1208: RscPictureGUI
			{
				idc = 1208;
				text = "\z\addons\viruz_mod\gui\status_temp_outside_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.72 * safezoneH + safezoneY; //3
				w = 0.06;
				h = 0.08;
			};*/
			/*class RscPicture_1207 : RscPictureGUI {
				idc = 1207;
				text = "\z\addons\viruz_mod\gui\status_combat_border_ca.paa";
				x = "0.955313 * safezoneW + safezoneX";
				y = "0.65 * safezoneH + safezoneY";
				w = 0.06;
				h = 0.08;
			};*/
			class RscPicture_1203: RscPictureGUI
			{
				//FRACTURE
				idc = 1203;
				text = "\z\addons\viruz_mod\gui\status_fracture_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.58 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
				colorText[] = {1,1,1,1};
			};
			class RscPicture_1204: RscPictureGUI
			{
				idc = 1204;
				text = "\z\addons\viruz_mod\gui\status_connection_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.51 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
				colorText[] = {1,1,1,1};
			};
			class RscPicture_1205: RscPictureGUI
			{
				idc = 1205;
				text = "\z\addons\viruz_mod\gui\status_ear_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.30 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1206: RscPictureGUI
			{
				idc = 1206;
				text = "\z\addons\viruz_mod\gui\status_eye_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.37 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
			/*class RscPicture_1501: RscPictureGUI
			{
				idc = 1501;
				text = "\z\addons\viruz_mod\gui\status_food_border_ca.paa";
				x = 0.945313 * safezoneW + safezoneX;
				y = 0.95 * safezoneH + safezoneY; //1
				w = 0.04;
				h = 0.053333;
			};
			class RscPicture_1502: RscPictureGUI
			{
				idc = 1502;
				text = "\z\addons\viruz_mod\gui\status_thirst_border_ca.paa";
				x = 0.945313 * safezoneW + safezoneX;
				y = 0.816666 * safezoneH + safezoneY; //3
				w = 0.04;
				h = 0.053333;
			};*/
		};
		class Controls{
			/*class RscPicture_1301: RscPictureGUI
			{
				idc = 1301;
				//text = "\z\addons\viruz_mod\gui\status_food_inside_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.93 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1300: RscPictureGUI
			{
				idc = 1300;
				//text = "\z\addons\viruz_mod\gui\status_blood_inside_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.86 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1302: RscPictureGUI
			{
				idc = 1302;
				//text = "\z\addons\viruz_mod\gui\status_thirst_inside_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.79 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1306: RscPictureGUI
			{
				idc = 1306;
				//text = "\z\addons\viruz_mod\gui\status_temp_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.72 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};*/
			class RscPicture_1303: RscPictureGUI
			{
				idc = 1303;
				text = "\z\addons\viruz_mod\gui\status_bleeding_ca.paa";
				x = 0.955313 * safezoneW + safezoneX;
				y = 0.86 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
				colorText[] = {1,1,1,0.5};
			};
			class RscPicture_1304: RscPictureGUI
			{
				idc = 1304;
				text = "";
				x = 0.935313 * safezoneW + safezoneX;
				y = 0.3 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1305: RscPictureGUI
			{
				idc = 1305;
				text = "";
				x = 0.935313 * safezoneW + safezoneX;
				y = 0.37 * safezoneH + safezoneY;
				w = 0.06;
				h = 0.08;
			};
			class RscPicture_1307 : RscPictureGUI {
				idc = 1307;
				text = "\z\addons\viruz_mod\gui\status_combat_inside_ca.paa";
				x = "0.955313 * safezoneW + safezoneX";
				y = "0.65 * safezoneH + safezoneY";
				w = 0.06;
				h = 0.08;
			};
			/*class RscPicture_1701: RscPictureGUI

			{
				idc = 1701;
				//text = "\z\addons\viruz_mod\gui\status_food_inside_ca.paa";
				x = 0.945313 * safezoneW + safezoneX;
				y = 0.95 * safezoneH + safezoneY;
				w = 0.04;
				h = 0.053333;
			};
			class RscPicture_1702: RscPictureGUI
			{
				idc = 1702;
				//text = "\z\addons\viruz_mod\gui\status_thirst_inside_ca.paa";
				x = 0.945313 * safezoneW + safezoneX;
				y = 0.816666 * safezoneH + safezoneY;
				w = 0.04;
				h = 0.053333;
			};*/
		};
	};
	// VZGM
	class VZGMHud_Rsc
	{
		idd = -1;
		movingEnable = 1;
		enableSimulation = 1;
		enableDisplay = 1;

		onLoad = "uiNamespace setVariable ['vzgmHudDisp',_this select 0];";

		duration = 99999999999999999;
		fadein  = 0;
		fadeout = 0;
		
		class controls
		{
			class Icons : w_RscStructuredText
			{
				idc = -1;
				style = 0x00;
				x = .9;
				y = .9;
				w = .9;
				h = .9;
				size = .08;
				colorBackground[] = {0,0,0,0};
				colortext[] = {0,0,0,.7};
				text ="";
				class Attributes {
					align = "left";
				};		
			};
			class PlayerIcon00:Icons {idc = 46300 +  0;};
			class PlayerIcon01:Icons {idc = 46300 +  1;};
			class PlayerIcon02:Icons {idc = 46300 +  2;};
			class PlayerIcon03:Icons {idc = 46300 +  3;};
			class PlayerIcon04:Icons {idc = 46300 +  4;};
			class PlayerIcon05:Icons {idc = 46300 +  5;};
			class PlayerIcon06:Icons {idc = 46300 +  6;};
			class PlayerIcon07:Icons {idc = 46300 +  7;};
			class PlayerIcon08:Icons {idc = 46300 +  8;};
			class PlayerIcon09:Icons {idc = 46300 +  9;};
			class PlayerIcon10:Icons {idc = 46300 + 10;};
			class PlayerIcon11:Icons {idc = 46300 + 11;};
			class PlayerIcon12:Icons {idc = 46300 + 12;};
			class PlayerIcon13:Icons {idc = 46300 + 13;};
			class PlayerIcon14:Icons {idc = 46300 + 14;};
			class PlayerIcon15:Icons {idc = 46300 + 15;};
			class PlayerIcon16:Icons {idc = 46300 + 16;};
			class PlayerIcon17:Icons {idc = 46300 + 17;};
			class PlayerIcon18:Icons {idc = 46300 + 18;};
			class PlayerIcon19:Icons {idc = 46300 + 19;};
			class PlayerIcon20:Icons {idc = 46300 + 20;};
			class PlayerIcon21:Icons {idc = 46300 + 21;};
			class PlayerIcon22:Icons {idc = 46300 + 22;};
			class PlayerIcon23:Icons {idc = 46300 + 23;};
			class PlayerIcon24:Icons {idc = 46300 + 24;};
			class PlayerIcon25:Icons {idc = 46300 + 25;};
			class PlayerIcon26:Icons {idc = 46300 + 26;};
			class PlayerIcon27:Icons {idc = 46300 + 27;};
			class PlayerIcon28:Icons {idc = 46300 + 28;};
			class PlayerIcon29:Icons {idc = 46300 + 29;};
			class PlayerIcon30:Icons {idc = 46300 + 30;};
			class PlayerIcon31:Icons {idc = 46300 + 31;};
			class PlayerIcon32:Icons {idc = 46300 + 32;};
			class PlayerIcon33:Icons {idc = 46300 + 33;};
			class PlayerIcon34:Icons {idc = 46300 + 34;};
			class PlayerIcon35:Icons {idc = 46300 + 35;};
			class PlayerIcon36:Icons {idc = 46300 + 36;};
			class PlayerIcon37:Icons {idc = 46300 + 37;};
			class PlayerIcon38:Icons {idc = 46300 + 38;};
			class PlayerIcon39:Icons {idc = 46300 + 39;};
			class PlayerIcon40:Icons {idc = 46300 + 40;};
		};
	};
};