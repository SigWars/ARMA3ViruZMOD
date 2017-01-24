class W_RscEdit {
	type = 2;
	style = 0x00 + 0x40;
	font = "PuristaMedium";
	shadow = 2;
	sizeEx = "(((((safezoneW / safezoneH) min 1.0) / 1.0) / 25) * 1)";
	colorBackground[] = {0, 0, 0, 1};
	soundSelect[] = {"",0.1,1};
	soundExpand[] = {"",0.1,1};
	colorText[] = {0.95, 0.95, 0.95, 1};
	colorDisabled[] = {1, 1, 1, 0.25};
	autocomplete = false;
	colorSelection[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 1};
	canModify = 1;
};
class W_RscText {
	idc = -1;
	type = 0;
	style = 0x00;
	colorBackground[] = { 1 , 1 , 1 , 0 };
	colorText[] = { 1 , 1 , 1 , 1 };
	font = "PuristaLight";
	sizeEx = .028;
	h = .25;
	text = "";
};

class W_RscStructuredText
{
	access = 0;
	type = 13;
	idc = -1;
	style = 0;
	colorText[] = {.8784,.8471,.651,1};
	class Attributes
	{
		font = "PuristaLight";
		color = "#e0d8a6";
		align = "center";
		shadow = 1;
	};
	x = 0;
	y = 0;
	h = .035;
	w = .1;
	text = "";
	size = .03921;
	shadow = 2;
};

class W_RscList
{
	type = 5; //CT_SLIDER; //CT_XSLIDER; //5;
	style = ST_MULTI; //69;
	idc = -1;
	text = "";
	w = .275;
	h = .04;
	colorSelect[] = {1, 1, 1, 1};
	colorText[] = {1, 1, 1, 1};
	colorBackground[] = {1,1,1,0};
	colorSelectBackground[] = {.40, .43, .28, .5};
	colorScrollbar[] = {.2, .2, .2, 1};
	arrowEmpty = "\z\addons\viruz_mod\code\vzgm\ui\ui_arrow_combo_ca.paa";
	arrowFull = "\z\addons\viruz_mod\code\vzgm\ui\ui_arrow_combo_active_ca.paa";
	wholeHeight = .45;
	rowHeight = .04;
	color[] = {.7, .7, .7, 1};
	colorActive[] = {0,0,0,1};
	colorDisabled[] = {0,0,0,.3};
	colorPicture[] = {1,1,1,1};//viruz
	colorPictureSelected[] = {1,1,1,1};//viruz
	colorPictureDisabled[] = {1,1,1,1};//viruz
	font = "PuristaLight";
	sizeEx = .028;
	soundSelect[] = {"",.1,1};
	soundExpand[] = {"",.1,1};
	soundCollapse[] = {"",.1,1};
	maxHistoryDelay = 1;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	class listScrollBar //ScrollBar
	{
		color[] = {1, 1, 1, 1};
		colorActive[] = {1, 1, 1, 1};
		colorDisabled[] = {1, 1, 1, 1};
		thumb = "\z\addons\viruz_mod\code\vzgm\ui\ui_scrollbar_thumb_ca.paa";
		arrowFull = "\z\addons\viruz_mod\code\vzgm\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "\z\addons\viruz_mod\code\vzgm\ui\data\ui_arrow_top_ca.paa";
		border = "\z\addons\viruz_mod\code\vzgm\ui\ui_border_scroll_ca.paa";
	};
};

class W_RscPicture 
{
	idc = -1; 
	type = 0;
	style = 48;
	font = "PuristaLight";
	sizeEx = .023;	
	colorBackground[] = {};
	colorText[] = {};	
	x = .0; y = .2;
	w = .2; h = .2;	
	text = "";	
}; 

class W_RscButtonBase {
	idc = -1;
	type = 16;
	style = 0;	
	w = .183825;
	h = .104575;	
	color[] = {.95, .95, .95, 1};
	color2[] = {1, 1, 1, .4};
	colorBackground[] = {1, 1, 1, 1};
	colorbackground2[] = {1, 1, 1, .4};
	colorDisabled[] = {1, 1, 1, .25};	
	periodFocus = 1.2;
	periodOver = .8;	
	class HitZone {
		left = .004;
		top = .029;
		right = .004;
		bottom = .029;		
	};
	class ShortcutPos {
		left = .004;
		top = .026;
		w = .0392157;
		h = .0522876;		
	};
	class TextPos {	
		left = .05;
		top = .025;
		right = .005;
		bottom = .025;	
	};
	animTextureNormal = "\z\addons\viruz_mod\code\vzgm\ui\ui_button_normal_ca.paa";
	animTextureDisabled = "\z\addons\viruz_mod\code\vzgm\ui\ui_button_disabled_ca.paa";
	animTextureOver = "\z\addons\viruz_mod\code\vzgm\ui\ui_button_over_ca.paa";
	animTextureFocused = "\z\addons\viruz_mod\code\vzgm\ui\ui_button_focus_ca.01.paa";
	animTexturePressed = "\z\addons\viruz_mod\code\vzgm\ui\ui_button_down_ca.paa";
	animTextureDefault = "\z\addons\viruz_mod\code\vzgm\ui\ui_button_default_ca.paa";
	textureNoShortcut = "";
	period = .4;
	font = "PuristaLight";
	size = .028;
	sizeEx = .028;
	text = "";
	
	soundEnter[] = {"\z\addons\viruz_mod\code\vzgm\ui\sound\mouse2", .09, 1};
	soundPush[] = {"\z\addons\viruz_mod\code\vzgm\ui\sound\new1", .09, 1};
	soundClick[] = {"\z\addons\viruz_mod\code\vzgm\ui\sound\mouse3", .07, 1};
	soundEscape[] = {"\z\addons\viruz_mod\code\vzgm\ui\sound\mouse1", .09, 1};
	
	action = "";
	
	class Attributes {
		font = "PuristaLight";
		color = "#E5E5E5";
		align = "left";
		shadow = "1";	
	};
	
	class AttributesImage {
		font = "PuristaLight";
		color = "#E5E5E5";
		align = "left";	
	};
};

class W_RscButton : W_RscButtonBase {

	w = .183825;
	h = .0522876;

	style = 2;

	color[] = {1, 1, 1, 1};
	color2[] = {1, 1, 1, .85};
	colorBackground[] = {1, 1, 1, 1};
	colorbackground2[] = {1, 1, 1, .85};
	colorDisabled[] = {1, 1, 1, .4};
	colorFocused[] = { 1, 1, 1, 1 };
	colorBackgroundFocused[] = { 1, 1, 1, 0 };
	
	class HitZone {	
		left = .002;
		top = .003;
		right = .002;
		bottom = .016;		
	};
	
	class ShortcutPos {	
		left = -.006;
		top = -.007;
		w = .0392157;
		h = .0522876;	
	};
	
	class TextPos {	
		left = .002;
		top = .014;
		right = .002;
		bottom = .005;
	};
	
	animTextureNormal = "\z\addons\viruz_mod\code\vzgm\ui\igui_button_normal_ca.paa";
	animTextureDisabled = "\z\addons\viruz_mod\code\vzgm\ui\igui_button_disabled_ca.paa";
	animTextureOver = "\z\addons\viruz_mod\code\vzgm\ui\igui_button_over_ca.paa";
	animTextureFocused = "\z\addons\viruz_mod\code\vzgm\ui\igui_button_focus_ca.paa";
	animTexturePressed = "\z\addons\viruz_mod\code\vzgm\ui\igui_button_down_ca.paa";
	animTextureDefault = "\z\addons\viruz_mod\code\vzgm\ui\igui_button_normal_ca.paa";
	animTextureNoShortcut = "\z\addons\viruz_mod\code\vzgm\ui\igui_button_normal_ca.paa";
	
	class Attributes {	
		font = "PuristaLight";
		color = "#E5E5E5";
		align = "center";
		shadow = "1";		
	};
};

class RscCombo {
	idc = -1;
	type = 4;
	style = 1;
	x = 0;
	y = 0;
	w = 0.3;
	h = 0.035;
	colorSelect[] = {1, 1, 1, 1};
	colorText[] = {1, 1, 1, 1};
	colorBackground[] = {1,1,1,0};
	colorSelectBackground[] = {.40, .43, .28, .5};
	colorScrollbar[] = {.2, .2, .2, 1};
	arrowEmpty = "\z\addons\viruz_mod\code\vzgm\ui\ui_arrow_combo_ca.paa";
	arrowFull = "\z\addons\viruz_mod\code\vzgm\ui\ui_arrow_combo_active_ca.paa";
	wholeHeight = 0.45;
	color[] = {0, 0, 0, 0.6};
	colorActive[] = {0, 0, 0, 1};
	colorDisabled[] = {0, 0, 0, 0.3};
	font = "Zeppelin32";
	sizeEx = 0.031;
	soundSelect[] = {"",.1,1};
	soundExpand[] = {"",.1,1};
	soundCollapse[] = {"",.1,1};
	maxHistoryDelay = 1.0;
	
	class ComboScrollBar {
		color[] = {1, 1, 1, 1};
		colorActive[] = {1, 1, 1, 1};
		colorDisabled[] = {1, 1, 1, 1};
		thumb = "\z\addons\viruz_mod\code\vzgm\ui\ui_scrollbar_thumb_ca.paa";
		arrowFull = "\z\addons\viruz_mod\code\vzgm\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "\z\addons\viruz_mod\code\vzgm\ui\data\ui_arrow_top_ca.paa";
		border = "\z\addons\viruz_mod\code\vzgm\ui\ui_border_scroll_ca.paa";
	};
};