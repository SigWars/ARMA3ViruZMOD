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
	sizeEx = .025;
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
	arrowEmpty = "vzgm\ui\ui_arrow_combo_ca.paa";
	arrowFull = "vzgm\ui\ui_arrow_combo_active_ca.paa";
	wholeHeight = .45;
	rowHeight = .04;
	color[] = {.7, .7, .7, 1};
	colorActive[] = {0,0,0,1};
	colorDisabled[] = {0,0,0,.3};
	font = "PuristaLight";
	sizeEx = .023;
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
		thumb = "vzgm\ui\ui_scrollbar_thumb_ca.paa";
		arrowFull = "vzgm\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "vzgm\ui\data\ui_arrow_top_ca.paa";
		border = "vzgm\ui\ui_border_scroll_ca.paa";
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
	animTextureNormal = "vzgm\ui\ui_button_normal_ca.paa";
	animTextureDisabled = "vzgm\ui\ui_button_disabled_ca.paa";
	animTextureOver = "vzgm\ui\ui_button_over_ca.paa";
	animTextureFocused = "vzgm\ui\ui_button_focus_ca.01.paa";
	animTexturePressed = "vzgm\ui\ui_button_down_ca.paa";
	animTextureDefault = "vzgm\ui\ui_button_default_ca.paa";
	textureNoShortcut = "";
	period = .4;
	font = "PuristaLight";
	size = .023;
	sizeEx = .023;
	text = "";
	
	soundEnter[] = {"\vzgm\ui\sound\mouse2", .09, 1};
	soundPush[] = {"\vzgm\ui\sound\new1", .09, 1};
	soundClick[] = {"\vzgm\ui\sound\mouse3", .07, 1};
	soundEscape[] = {"\vzgm\ui\sound\mouse1", .09, 1};
	
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
	
	animTextureNormal = "vzgm\ui\igui_button_normal_ca.paa";
	animTextureDisabled = "vzgm\ui\igui_button_disabled_ca.paa";
	animTextureOver = "vzgm\ui\igui_button_over_ca.paa";
	animTextureFocused = "vzgm\ui\igui_button_focus_ca.paa";
	animTexturePressed = "vzgm\ui\igui_button_down_ca.paa";
	animTextureDefault = "vzgm\ui\igui_button_normal_ca.paa";
	animTextureNoShortcut = "vzgm\ui\igui_button_normal_ca.paa";
	
	class Attributes {	
		font = "PuristaLight";
		color = "#E5E5E5";
		align = "center";
		shadow = "1";		
	};
};