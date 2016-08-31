class RscGearTemplates
{
	class CA_Tooltip: RscStructuredText
	{
		idc=9999;
		x=0.5;
		y=0.5;
		w=0.5;
		h=0.17;
		colorBackground[]={0,0,0,0.85000002};
		size="(			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
		class Attributes: Attributes
		{
			align="left";
		};
	};
	class EmbossIcons
	{
		uniformTab="\z\addons\viruz_mod\inventory\slot_uniform.paa";
		vestTab="\z\addons\viruz_mod\inventory\slot_vest.paa";
		backpackTab="\z\addons\viruz_mod\inventory\slot_backpack.paa";
		headGearSlot="\z\addons\viruz_mod\inventory\slot_helmet.paa";
		gogglesSlot="\z\addons\viruz_mod\inventory\slot_glasses.paa";
		hmdSlot="\z\addons\viruz_mod\inventory\slot_nvg.paa";
		binocSlot="\z\addons\viruz_mod\inventory\slot_binocular.paa";
		primarySlot="\z\addons\viruz_mod\inventory\slot_primary.paa";
		secondarySlot="\z\addons\viruz_mod\inventory\slot_melee.paa";
		handgunSlot="\z\addons\viruz_mod\inventory\slot_hgun.paa";
		muzzleSlot="\z\addons\viruz_mod\inventory\slot_muzzle.paa";
		opticsSlot="\z\addons\viruz_mod\inventory\slot_top.paa";
		flashlightSlot="\z\addons\viruz_mod\inventory\slot_side.paa";
		magazineSlot="\z\addons\viruz_mod\inventory\slot_magazine.paa";
		mapSlot="\z\addons\viruz_mod\inventory\slot_map.paa";
		compassSlot="\z\addons\viruz_mod\inventory\slot_compass.paa";
		watchSlot="\z\addons\viruz_mod\inventory\slot_watch.paa";
		radioSlot="\z\addons\viruz_mod\inventory\slot_radio.paa";
		gpsSlot="\z\addons\viruz_mod\inventory\slot_gps.paa";
	};
};
	
class RscDisplayInventory
{
	onLoad = "[""onLoad"",_this,""RscDisplayInventory"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf"";call gear_ui_init; uiNamespace setVariable ['VIRUZ_INV_display', _this select 0];";
	onUnload = "[""onUnload"",_this,""RscDisplayInventory"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf"";call player_gearSync;";
	idd=602;
	enableSimulation=1;

	class Colors {
		dragValidBgr[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 0.5};
		dragInvalidBgr[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])", 0.5};
		dragValidBar[] = {"(profilenamespace getvariable ['IGUI_WARNING_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_WARNING_RGB_G',0.5])", "(profilenamespace getvariable ['IGUI_WARNING_RGB_B',0.0])", 0.5};
		dragInvalidBar[] = {"(profilenamespace getvariable ['IGUI_ERROR_RGB_R',0.8])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_G',0.0])", "(profilenamespace getvariable ['IGUI_ERROR_RGB_B',0.0])", 0.5};
		progressBar[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 1};
		progressBarBgr[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])", "(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])", "(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])", 0.75};
		highlight[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])", "(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])", 0.5};
	};
	
	class controlsBackground
	{
		//status
/*class RscPicture_1201: RscPictureGUI
{
	idc = 1201;

	text = "\z\addons\viruz_mod\gui\status_food_border_ca.paa"; //--- ToDo: Localize;
	x = 0.404197 * safezoneW + safezoneX;
	y = 0.228339 * safezoneH + safezoneY;
	w = 0.0262474 * safezoneW;
	h = 0.0560125 * safezoneH;
};
class RscPicture_1200: RscPictureGUI
{
	idc = 1200;

	text = "\z\addons\viruz_mod\gui\status_blood_border_ca.paa"; //--- ToDo: Localize;
	x = 0.370075 * safezoneW + safezoneX;
	y = 0.228339 * safezoneH + safezoneY;
	w = 0.0262474 * safezoneW;
	h = 0.0560125 * safezoneH;
};*/
class RscPicture_1202: RscPictureGUI
{
	idc = 1202;

	text = "\z\addons\viruz_mod\gui\status_thirst_border_ca.paa"; //--- ToDo: Localize;
	x = 0.438319 * safezoneW + safezoneX;
	y = 0.228339 * safezoneH + safezoneY;
	w = 0.0262474 * safezoneW;
	h = 0.0560125 * safezoneH;
};
class RscPicture_1208: RscPictureGUI
{
	idc = 1208;

	text = "\z\addons\viruz_mod\gui\status_temp_outside_ca.paa"; //--- ToDo: Localize;
	x = 0.471128 * safezoneW + safezoneX;
	y = 0.228339 * safezoneH + safezoneY;
	w = 0.0262474 * safezoneW;
	h = 0.0560125 * safezoneH;
};
/*class RscPicture_1203: RscPictureGUI
{
	idc = 1203;

	text = "\z\addons\viruz_mod\gui\status_fracture_CA.paa"; //--- ToDo: Localize;
	x = 0.502625 * safezoneW + safezoneX;
	y = 0.228339 * safezoneH + safezoneY;
	w = 0.0262474 * safezoneW;
	h = 0.0560125 * safezoneH;
	colorText[] = {1,1,1,1};
};*/
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
			//status
		class Background: RscPicture
		{
			idc=1000;
			text="\z\addons\viruz_mod\inventory\background_inventory_vz2.paa";
			x="0.262815 * safezoneW + safezoneX";
			y="0.126 * safezoneH + safezoneY";
			w="0.510469 * safezoneW";
			h="0.748 * safezoneH";
		};
		class CA_ContainerBackground: RscText
		{
			idc=1001;
			style=48;
			text="\z\addons\viruz_mod\inventory\background_ground_1.paa";
			x="-0.227031 * safezoneW + safezoneX";
			y="0.148 * safezoneH + safezoneY";
			w="0.541406 * safezoneW";
			h="0.759 * safezoneH";
			color[]={1,1,1,1};
			colorActive[]={1,1,1,1};
			action="";
			onMouseEnter="";
			onMouseLeave="";
			onMouseDown="";
		};
		/*class BP_HealthHuman: RscPicture
		{
			idc=1229;
			text="\z\addons\viruz_mod\inventory\health_human.paa";
			x="0.329844 * safezoneW + safezoneX";
			y="0.1194 * safezoneH + safezoneY";
			w="0.12375 * safezoneW";
			h="0.176 * safezoneH";
		};
		class BP_HealthDog: RscPicture
		{
			idc=1230;
			text="\z\addons\viruz_mod\inventory\health_dog.paa";
			x="0.443281 * safezoneW + safezoneX";
			y="0.1194 * safezoneH + safezoneY";
			w="0.113437 * safezoneW";
			h="0.176 * safezoneH";
		};
		class Player_Food: RscPicture
		{
			idc=1233;
			text="\z\addons\viruz_mod\inventory\icon_food.paa";
			x="0.332938 * safezoneW + safezoneX";
			y="0.2602 * safezoneH + safezoneY";
			w="0.0154688 * safezoneW";
			h="0.033 * safezoneH";
		};
		class Player_Water: RscPicture
		{
			idc=1237;
			text="\z\addons\viruz_mod\inventory\icon_water.paa";
			x="0.342219 * safezoneW + safezoneX";
			y="0.2602 * safezoneH + safezoneY";
			w="0.020625 * safezoneW";
			h="0.033 * safezoneH";
		};
		class Dog_Food: RscPicture
		{
			idc=1235;
			text="\z\addons\viruz_mod\inventory\icon_food.paa";
			x="0.44225 * safezoneW + safezoneX";
			y="0.2602 * safezoneH + safezoneY";
			w="0.0154688 * safezoneW";
			h="0.033 * safezoneH";
		};
		class Dog_Water: RscPicture
		{
			idc=1236;
			text="\z\addons\viruz_mod\inventory\icon_water.paa";
			x="0.451532 * safezoneW + safezoneX";
			y="0.2602 * safezoneH + safezoneY";
			w="0.020625 * safezoneW";
			h="0.033 * safezoneH";
		};*/
	};
	class controls
	{
		delete Background;
		delete Title;
		delete ButtonOK;
		delete ButtonCancel;
		delete CA_ContainerBackground;
		delete CA_PlayerBackground;
		delete TitleBackground;
		delete PlayersName;
		delete RankBackground;
		delete RankPicture;
		delete ButtonBack;
	//status
class RscPicture_1301: RscPictureGUI
{
	idc = 1301;

	x = 0.404196 * safezoneW + safezoneX;
	y = 0.228339 * safezoneH + safezoneY;
	w = 0.0262474 * safezoneW;
	h = 0.0560125 * safezoneH;
};
class RscPicture_1300: RscPictureGUI
{
	idc = 1300;

	x = 0.370075 * safezoneW + safezoneX;
	y = 0.228339 * safezoneH + safezoneY;
	w = 0.0262474 * safezoneW;
	h = 0.0560125 * safezoneH;
};
class RscPicture_1302: RscPictureGUI
{
	idc = 1302;

	x = 0.437007 * safezoneW + safezoneX;
	y = 0.228339 * safezoneH + safezoneY;
	w = 0.0262474 * safezoneW;
	h = 0.0560125 * safezoneH;
};
class RscPicture_1306: RscPictureGUI
{
	idc = 1306;

	x = 0.471128 * safezoneW + safezoneX;
	y = 0.228339 * safezoneH + safezoneY;
	w = 0.0262474 * safezoneW;
	h = 0.0560125 * safezoneH;
};
/*class RscPicture_1303: RscPictureGUI
{
	idc = 1303;

	text = "\z\addons\viruz_mod\gui\status_bleeding_ca.paa"; //--- ToDo: Localize;
	x = 0.364819 * safezoneW + safezoneX;
	y = 0.205935 * safezoneH + safezoneY;
	w = 0.0262474 * safezoneW;
	h = 0.0560125 * safezoneH;
	colorText[] = {1,1,1,0.5};
};*/
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
	//status
class Button_Close: RscActiveText
{
	idc = 1229;
	style = 48;
	color[] = {0.5,0.5,0.5,1};
	action = "closeDialog 0;";
	onMouseEnter = "ctrlSetFocus (_this select 0)";

	text = "\z\addons\viruz_mod\inventory\button_close.paa"; //--- ToDo: Localize;
	x = 0.550394 * safezoneW + safezoneX;
	y = 0.702485 * safezoneH + safezoneY;
	w = 0.0309375 * safezoneW;
	h = 0.0880001 * safezoneH;
	colorActive[] = {1,1,1,1};
};
class Button_Craft: RscActiveText
{
	idc = 1230;
	style = 48;
	color[] = {0.5,0.5,0.5,1};
	onMouseEnter = "ctrlSetFocus (_this select 0)";
	//movingEnable = 1;
	//moving = 1;
	text = "\z\addons\viruz_mod\inventory\button_craft.paa"; //--- ToDo: Localize;
	action = "closeDialog 0; _nill = execVM '\z\addons\viruz_mod\actions\playercraft.sqf';";
	x = 0.588844 * safezoneW + safezoneX;
	y = 0.702485 * safezoneH + safezoneY;
	w = 0.0309375 * safezoneW;
	h = 0.0880001 * safezoneH;
	colorActive[] = {1,1,1,1};
};
class Button_Help: RscStructuredText
{
	idc = 1232;
	onMouseEnter="(_this select 0) ctrlSetStructuredText parseText ""<a href='http://www.facebook.com/ViruzBr/'><img size='2.72' image='\z\addons\viruz_mod\inventory\button_help_hover.paa'/></a>""";
	onMouseExit="(_this select 0) ctrlSetStructuredText parseText ""<a href='http://www.facebook.com/ViruzBr/'><img size='2.72' image='\z\addons\viruz_mod\inventory\button_help_normal.paa'/></a>""";
	text="<a href='http://www.facebook.com/ViruzBr/'><img size='3.0' image='\z\addons\viruz_mod\inventory\button_help_normal.paa'/></a>";
	x = "0.659715 * safezoneW + safezoneX";
	y = "0.702485 * safezoneH + safezoneY";
	w = "0.0309375 * safezoneW";
	h = "0.0880001 * safezoneH";
};
class Button_Book: RscActiveText
{
	idc = 1231;
	style = 48;
	color[] = {0.5,0.5,0.5,1};
	onMouseEnter = "ctrlSetFocus (_this select 0)";

	text = "\z\addons\viruz_mod\inventory\button_book.paa"; //--- ToDo: Localize;
	x = "0.624277 * safezoneW + safezoneX";
	y = "0.702485 * safezoneH + safezoneY";
	w = "0.0309375 * safezoneW";
	h = "0.0880001 * safezoneH";
	
	colorActive[] = {1,1,1,1};
	action = "closeDialog 0; _nill = execVM '\z\addons\viruz_mod\actions\playerstats.sqf';";
	
};
		class Button_TakeAll: RscActiveText
		{
			idc=1239;
			style=48;
			text="\z\addons\viruz_mod\inventory\button_takeall.paa";
			x="0.218471 * safezoneW + safezoneX";
			y="0.7662 * safezoneH + safezoneY";
			w="0.061875 * safezoneW";
			h="0.022 * safezoneH";
			color[]={1,1,1,1};
			colorActive[]={1,1,1,1};
			action="";
			onMouseEnter="ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\z\addons\viruz_mod\inventory\button_takeall_hover.paa'";
			onMouseExit="ctrlSetFocus (_this select 0); (_this select 0) ctrlSetText '\z\addons\viruz_mod\inventory\button_takeall.paa'";
		};
		//delete BackgroundSlotPrimary;
		delete BackgroundSlotPrimaryMuzzle;
		delete BackgroundSlotPrimaryFlashlight;
		delete BackgroundSlotPrimaryOptics;
		delete BackgroundSlotPrimaryMagazine;
		delete BackgroundSlotSecondary;
		delete BackgroundSlotSecondaryMuzzle;
		delete BackgroundSlotSecondaryFlashlight;
		delete BackgroundSlotSecondaryOptics;
		delete BackgroundSlotSecondaryMagazine;
		delete BackgroundSlotHandgun;
		delete BackgroundSlotHandgunMuzzle;
		delete BackgroundSlotHandgunFlashlight;
		delete BackgroundSlotHandgunOptics;
		delete BackgroundSlotHandgunMagazine;
		delete BackgroundSlotHeadgear;
		delete BackgroundSlotGoggles;
		delete BackgroundSlotHMD;
		delete BackgroundSlotBinoculars;
		delete BackgroundSlotMap;
		delete BackgroundSlotGPS;
		delete BackgroundSlotCompass;
		delete BackgroundSlotRadio;
		delete BackgroundSlotWatch;
		delete ExternalContainerBackground;
		delete PlayerContainerBackground;
		
		class BaseGroundTab: RscActiveText
		{
			idc=-1;
			colorBackgroundSelected[]={1,1,1,1};
			colorFocused[]={1,1,1,0};
			soundDoubleClick[]=
			{
				"",
				0.1,
				1
			};
			color[]={1,1,1,1};
			colorBackground[]={0,0,0,1};
		};
		class Image_Ground: RscText
		{
			idc=6320;
			style=48;
			text="\z\addons\viruz_mod\inventory\button_ground.paa";
			x="0.146281 * safezoneW + safezoneX";
			y="0.313 * safezoneH + safezoneY";
			w="0.0670312 * safezoneW";
			h="0.022 * safezoneH";
			color[]={255,255,255,0.5};
			colorActive[]={255,255,255,1};
		};
		class Image_Crate: RscText
		{
			idc=6400;
			style=48;
			text="\z\addons\viruz_mod\inventory\button_crate.paa";
			x="0.214347 * safezoneW + safezoneX";
			y="0.313 * safezoneH + safezoneY";
			w="0.0721875 * safezoneW";
			h="0.022 * safezoneH";
			color[]={255,255,255,0.5};
			colorActive[]={255,255,255,1};
		};
		class GroundTab: BaseGroundTab
		{
			idc=6321;
			style=48;
			x="0.146281 * safezoneW + safezoneX";
			y="0.313 * safezoneH + safezoneY";
			w="0.0670312 * safezoneW";
			h="0.022 * safezoneH";
			colorBackgroundSelected[]={0,0,0,0};
			colorFocused[]={0,0,0,0};
			color[]={0,0,0,0};
			colorBackground[]={0,0,0,0};
			onMouseButtonClick="";
		};
		class SoldierTab: BaseGroundTab
		{
			idc=6401;
			style=48;
			x="0.214347 * safezoneW + safezoneX";
			y="0.313 * safezoneH + safezoneY";
			w="0.0721875 * safezoneW";
			h="0.022 * safezoneH";
			colorBackgroundSelected[]={0,0,0,0};
			colorFocused[]={0,0,0,0};
			color[]={0,0,0,0};
			colorBackground[]={0,0,0,0};
			onMouseButtonClick="";
		};
		class GroundContainer: RscListBox
		{
			idc=632;
			sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			sizeEx2="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			rowHeight="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			canDrag=1;
			colorText[]={1,1,1,1};
			colorBackground[]={0,0,0,0};
			itemBackground[]={1,1,1,0};
			colorSelect[]={0,0,0,0.5};
			colorSelect2[]={0,0,0,0.5};
			colorSelectBackground[]={0.94999999,0.94999999,0.94999999,0.5};
			colorSelectBackground2[]={1,1,1,0.25};
			itemSpacing=0.001;
			x="0.147313 * safezoneW + safezoneX";
			y="0.3372 * safezoneH + safezoneY";
			w="0.139219 * safezoneW";
			h="0.407 * safezoneH";
			style=16;
			shadow=0;
			font="PuristaMedium";
			color[]={0.94999999,0.94999999,0.94999999,1};
			colorDisabled[]={1,1,1,0.25};
			period=1.2;
			arrowFull="\z\addons\viruz_mod\inventory\scrollbar\ground\arrowFull_ca.paa";
			arrowEmpty="\z\addons\viruz_mod\inventory\scrollbar\ground\arrowEmpty_ca.paa";
			class ListScrollBar
			{
				color[]={1,1,1,0.60000002};
				colorActive[]={1,1,1,1};
				colorDisabled[]={1,1,1,0.30000001};
				shadow=0;
				thumb="\z\addons\viruz_mod\inventory\scrollbar\ground\thumb_ca.paa";
				arrowFull="\z\addons\viruz_mod\inventory\scrollbar\ground\arrowFull_ca.paa";
				arrowEmpty="\z\addons\viruz_mod\inventory\scrollbar\ground\arrowEmpty_ca.paa";
				border="\z\addons\viruz_mod\inventory\scrollbar\ground\border_ca.paa";
			};
		};
		class SoldierContainer: GroundContainer
		{
			idc=640;
			arrowFull="\z\addons\viruz_mod\inventory\scrollbar\inventory\arrowFull_ca.paa";
			arrowEmpty="\z\addons\viruz_mod\inventory\scrollbar\inventory\arrowEmpty_ca.paa";
			class ListScrollBar
			{
				color[]={1,1,1,0.60000002};
				colorActive[]={1,1,1,1};
				colorDisabled[]={1,1,1,0.30000001};
				shadow=0;
				thumb="\z\addons\viruz_mod\inventory\scrollbar\inventory\thumb_ca.paa";
				arrowFull="\z\addons\viruz_mod\inventory\scrollbar\inventory\arrowFull_ca.paa";
				arrowEmpty="\z\addons\viruz_mod\inventory\scrollbar\inventory\arrowEmpty_ca.paa";
				border="\z\addons\viruz_mod\inventory\scrollbar\inventory\border_ca.paa";
			};
		};
		class GroundFilter: RscCombo
		{
			idc=6554;
			x=0;
			y=0;
			w=0;
			h=0;
		};
		class GroundLoad: RscProgress
		{
			idc=6307;
			texture="";
			textureExt="";
			colorBar[]={0.89999998,0.89999998,0.89999998,0.89999998};
			colorExtBar[]={1,1,1,1};
			colorFrame[]={1,1,1,1};
			x="0.224657 * safezoneW + safezoneX";
			y="0.7508 * safezoneH + safezoneY";
			w="0.0567187 * safezoneW";
			h="0.0055 * safezoneH";
		};
		class SlotPrimary: BaseGroundTab
		{
			idc=610;
			style="0x30 + 0x800";
			color[]={1,1,1,1};
			colorBackground[]={1,1,1,0};
			colorBackgroundSelected[]={1,1,1,0};
			colorFocused[]={0,0,0,0};
			canDrag=1;
			x="0.547438 * safezoneW + safezoneX";
			y="0.4318 * safezoneH + safezoneY";
			w="0.149531 * safezoneW";
			h="0.077 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotPrimaryMuzzle: SlotPrimary
		{
			idc=620;
			x="0.579406 * safezoneW + safezoneX";
			y="0.522 * safezoneH + safezoneY";
			w="0.0257812 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotPrimaryUnderBarrel: SlotPrimary
		{
			idc=641;
			x="0.639219 * safezoneW + safezoneX";
			y="0.522 * safezoneH + safezoneY";
			w="0.0257812 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotPrimaryGrip: SlotPrimary
		{
			idc=-1;
			w=0;
			h=0;
			x="39 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="20 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			colorText[]={0,0,0,0.5};
		};
		class SlotPrimaryFlashlight: SlotPrimary
		{
			idc=622;
			x="0.5495 * safezoneW + safezoneX";
			y="0.522 * safezoneH + safezoneY";
			w="0.0257812 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotPrimaryOptics: SlotPrimary
		{
			idc=621;
			x="0.609312 * safezoneW + safezoneX";
			y="0.522 * safezoneH + safezoneY";
			w="0.0257812 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotPrimaryMagazine: SlotPrimary
		{
			idc=623;
			x="0.669125 * safezoneW + safezoneX";
			y="0.522 * safezoneH + safezoneY";
			w="0.0257812 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		//teste
class BackgroundSlotPrimaryMagazineGL: BackgroundSlotPrimary
{
	idc = 1267;

	text = "#(argb,8,8,3)color(0,0,0,0)";
	x = "0.496719 * safezoneW + safezoneX";
	y = "0.685961 * safezoneH + safezoneY";
	w = "0.0320511 * safezoneW";
	h = "0.0162847 * safezoneH";
};
class SlotPrimaryMagazineGL: SlotPrimary
{
	idc = 644;

	x = "0.496719 * safezoneW + safezoneX";
	y = "0.685961 * safezoneH + safezoneY";
	w = "0.0320511 * safezoneW";
	h = "0.0162847 * safezoneH";
	colorText[] = {0,0,0,0.5};
	colorBackground[] = {1,1,1,0};
};
		class SlotSecondary: SlotPrimary
		{
			idc=611;
			x="0.547438 * safezoneW + safezoneX";
			y="0.3746 * safezoneH + safezoneY";
			w="0.149531 * safezoneW";
			h="0.055 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotSecondaryUnderBarrel: SlotPrimary
		{
			idc=642;
			x=0;
			y=0;
			w=0;
			h=0;
			colorText[]={0,0,0,0.5};
		};
		class SlotSecondaryMuzzle: SlotPrimary
		{
			idc=624;
			x=0;
			y=0;
			w=0;
			h=0;
			colorText[]={0,0,0,0.5};
		};
		class SlotSecondaryGrip: SlotPrimary
		{
			idc=-1;
			x=0;
			y=0;
			w=0;
			h=0;
			colorText[]={0,0,0,0.5};
		};
		class SlotSecondaryFlashlight: SlotPrimary
		{
			idc=626;
			x=0;
			y=0;
			w=0;
			h=0;
			colorText[]={0,0,0,0.5};
		};
		class SlotSecondaryOptics: SlotPrimary
		{
			idc=625;
			x=0;
			y=0;
			w=0;
			h=0;
			colorText[]={0,0,0,0.5};
		};
		class SlotSecondaryMagazine: SlotPrimary
		{
			idc=627;
			x=0;
			y=0;
			w=0;
			h=0;
			colorText[]={0,0,0,0.5};
		};
		class SlotHandgun: SlotPrimary
		{
			idc=612;
			x="0.55053 * safezoneW + safezoneX";
			y="0.5638 * safezoneH + safezoneY";
			w="0.144375 * safezoneW";
			h="0.077 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotHandgunMuzzle: SlotPrimary
		{
			idc=628;
			x="0.580438 * safezoneW + safezoneX";
			y="0.6518 * safezoneH + safezoneY";
			w="0.0257812 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotHandgunUnderBarrel: SlotPrimary
		{
			idc=643;
			x="0.639219 * safezoneW + safezoneX";
			y="0.6518 * safezoneH + safezoneY";
			w="0.0257812 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotHandgunGrip: SlotPrimary
		{
			idc=-1;
			w=0;
			h=0;
			x="39 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y="14.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			colorText[]={0,0,0,0.5};
		};
		class SlotHandgunFlashlight: SlotPrimary
		{
			idc=630;
			x="0.551561 * safezoneW + safezoneX";
			y="0.6496 * safezoneH + safezoneY";
			w="0.0309375 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotHandgunOptics: SlotPrimary
		{
			idc=629;
			x="0.609312 * safezoneW + safezoneX";
			y="0.6518 * safezoneH + safezoneY";
			w="0.0257812 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotHandgunMagazine: SlotPrimary
		{
			idc=631;
			x="0.666032 * safezoneW + safezoneX";
			y="0.6518 * safezoneH + safezoneY";
			w="0.0257812 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotHeadgear: SlotPrimary
		{
			idc=6240;
			x="0.547438 * safezoneW + safezoneX";
			y="0.3064 * safezoneH + safezoneY";
			w="0.0358875 * safezoneW";
			h="0.0638 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotGoggles: SlotPrimary
		{
			idc=6216;
			x="0.584564 * safezoneW + safezoneX";
			y="0.3064 * safezoneH + safezoneY";
			w="0.0358875 * safezoneW";
			h="0.0638 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotHMD: SlotPrimary
		{
			idc=6217;
			x="0.622728 * safezoneW + safezoneX";
			y="0.3064 * safezoneH + safezoneY";
			w="0.0358875 * safezoneW";
			h="0.0638 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotBinoculars: SlotPrimary
		{
			idc=6238;
			x="0.660876 * safezoneW + safezoneX";
			y="0.3064 * safezoneH + safezoneY";
			w="0.0358875 * safezoneW";
			h="0.0638 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotMap: SlotPrimary
		{
			idc=6211;
			x="0.345314 * safezoneW + safezoneX";
			y="0.7178 * safezoneH + safezoneY";
			w="0.061875 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotGPS: SlotPrimary
		{
			idc=6215;
			x="0.409251 * safezoneW + safezoneX";
			y="0.7178 * safezoneH + safezoneY";
			w="0.061875 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotCompass: SlotPrimary
		{
			idc=6212;
			x="0.473188 * safezoneW + safezoneX";
			y="0.7178 * safezoneH + safezoneY";
			w="0.061875 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotRadio: SlotPrimary
		{
			idc=6214;
			x="0.345314 * safezoneW + safezoneX";
			y="0.7596 * safezoneH + safezoneY";
			w="0.061875 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class SlotWatch: SlotPrimary
		{
			idc=6213;
			x="0.409251 * safezoneW + safezoneX";
			y="0.7596 * safezoneH + safezoneY";
			w="0.061875 * safezoneW";
			h="0.033 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class UniformTab: BaseGroundTab
		{
			idc=6332;
			x="0.330876 * safezoneW + safezoneX";
			y="0.3086 * safezoneH + safezoneY";
			w="0.0670312 * safezoneW";
			h="0.066 * safezoneH";
			colorBackground[]={1,1,1,0.5};
		};
		class UniformSlot: SlotPrimary
		{
			idc=6331;
			x="0.330876 * safezoneW + safezoneX";
			y="0.3086 * safezoneH + safezoneY";
			w="0.0670312 * safezoneW";
			h="0.066 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class UniformLoad: GroundLoad
		{
			idc=6304;
			x="0.332938 * safezoneW + safezoneX";
			y="0.3636 * safezoneH + safezoneY";
			w="0.061875 * safezoneW";
			h="0.011 * safezoneH";
		};
		class UniformContainer: SoldierContainer
		{
			idc=633;
			onMouseButtonDblClick = "_this call player_selectSlot;";
			x="0.331906 * safezoneW + safezoneX";
			y="0.3856 * safezoneH + safezoneY";
			w="0.201094 * safezoneW";
			h="0.286 * safezoneH";
		};
		class VestTab: UniformTab
		{
			idc=6382;
			x="0.398939 * safezoneW + safezoneX";
			y="0.3086 * safezoneH + safezoneY";
			w="0.0670312 * safezoneW";
			h="0.066 * safezoneH";
		};
		class VestSlot: SlotPrimary
		{
			idc=6381;
			x="0.398939 * safezoneW + safezoneX";
			y="0.3086 * safezoneH + safezoneY";
			w="0.0670312 * safezoneW";
			h="0.066 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class VestLoad: GroundLoad
		{
			idc=6305;
			x="0.402031 * safezoneW + safezoneX";
			y="0.3636 * safezoneH + safezoneY";
			w="0.061875 * safezoneW";
			h="0.011 * safezoneH";
		};
		class VestContainer: UniformContainer
		{
			idc=638;
		};
		class BackpackTab: UniformTab
		{
			idc=6192;
			x="0.468033 * safezoneW + safezoneX";
			y="0.3086 * safezoneH + safezoneY";
			w="0.0670312 * safezoneW";
			h="0.066 * safezoneH";
		};
		class BackpackSlot: SlotPrimary
		{
			idc=6191;
			x="0.468033 * safezoneW + safezoneX";
			y="0.3086 * safezoneH + safezoneY";
			w="0.0670312 * safezoneW";
			h="0.066 * safezoneH";
			colorText[]={0,0,0,0.5};
		};
		class BackpackLoad: GroundLoad
		{
			idc=6306;
			x="0.471124 * safezoneW + safezoneX";
			y="0.3636 * safezoneH + safezoneY";
			w="0.061875 * safezoneW";
			h="0.011 * safezoneH";
		};
		class BackpackContainer: UniformContainer
		{
			idc=619;
		};
		class TotalLoad: GroundLoad
		{
			idc=6308;
			x="0.478344 * safezoneW + safezoneX";
			y="0.7794 * safezoneH + safezoneY";
			w="0.0515625 * safezoneW";
			h="0.011 * safezoneH";
		};
		class ContainerMarker: BaseGroundTab
		{
			idc=6325;
			x=0;
			y=0;
			w=0;
			h=0;
		};
		class GroundMarker: ContainerMarker
		{
			idc=6385;
			x=0;
			y=0;
			w=0;
			h=0;
		};
		class SoldierMarker: ContainerMarker
		{
			idc=6405;
			x=0;
			y=0;
			w=0;
			h=0;
		};
		class G_Interaction: RscControlsGroup
		{
			idc = 6902;
			x = 0.502;
			y = 0.250 * safezoneH;
			w = 0.145 * safezoneW;
			h = 0; //0.250 * safezoneH;
			onMouseMoving = "_this call gear_ui_offMenu;";
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class RscButton_1600: RscButtonActionMenu
				{
					idc = 1600;
					text = "";
					x = 0;
					y = 0 * safezoneH;
				};
				class RscButton_1601: RscButtonActionMenu
				{
					idc = 1601;
					text = "";
					x = 0;
					y = 0.025 * safezoneH;
				};
				class RscButton_1602: RscButtonActionMenu
				{
					idc = 1602;
					text = "";
					x = 0;
					y = 0.05 * safezoneH;
				};
				class RscButton_1603: RscButtonActionMenu
				{
					idc = 1603;
					text = "";
					x = 0;
					y = 0.075 * safezoneH;
				};
				class RscButton_1604: RscButtonActionMenu
				{
					idc = 1604;
					text = "";
					x = 0;
					y = 0.1 * safezoneH;
				};
				class RscButton_1605: RscButtonActionMenu
				{
					idc = 1605;
					text = "";
					x = 0;
					y = 0.125 * safezoneH;
				};
				class RscButton_1606: RscButtonActionMenu
				{
					idc = 1606;
					text = "";
					x = 0;
					y = 0.15 * safezoneH;
				};
				class RscButton_1607: RscButtonActionMenu
				{
					idc = 1607;
					text = "";
					x = 0;
					y = 0.175 * safezoneH;
				};
				class RscButton_1608: RscButtonActionMenu
				{
					idc = 1608;
					text = "";
					x = 0;
					y = 0.2 * safezoneH;
				};
				class RscButton_1609: RscButtonActionMenu
				{
					idc = 1609;
					text = "";
					x = 0;
					y = 0.225 * safezoneH;
				};
			};
		};
	};
};
