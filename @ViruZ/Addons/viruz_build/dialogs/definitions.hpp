//---------------------------------
// Common defines
//---------------------------------

#define true 1
#define false 0

#define ReadAndWrite 0 //! any modifications enabled
#define ReadAndCreate 1 //! only adding new class members is allowed
#define ReadOnly 2 //! no modifications enabled
#define ReadOnlyVerified 3 //! no modifications enabled, CRC test applied

//Types:
#define CT_STATIC 0
#define CT_BUTTON 1
#define CT_EDIT 2
#define CT_SLIDER 3
#define CT_COMBO 4
#define CT_LISTBOX 5
#define CT_TOOLBOX 6
#define CT_CHECKBOXES 7
#define CT_PROGRESS 8
#define CT_HTML 9
#define CT_STATIC_SKEW      10
#define CT_ACTIVETEXT 11
#define CT_TREE 12
#define CT_STRUCTURED_TEXT 13
#define CT_CONTEXT_MENU 14
#define CT_CONTROLS_GROUP 15
#define CT_SHORTCUTBUTTON 16
#define CT_XKEYDESC 40
#define CT_XBUTTON          41
#define CT_XLISTBOX 42
#define CT_XSLIDER 43
#define CT_XCOMBO 44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT 80
#define CT_OBJECT_ZOOM 81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK 98
#define CT_ANIMATED_USER 99
#define CT_MAP              100
#define CT_MAP_MAIN 101
#define CT_LISTNBOX 102
#define CT_ITEMSLOT         103
#define CT_CHECKBOX         77 //Arma 3

//Styles:
// Static styles
#define ST_POS            0x0F
#define ST_HPOS           0x03
#define ST_VPOS           0x0C
#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02
#define ST_DOWN           0x04
#define ST_UP             0x08
#define ST_VCENTER        0x0c

#define ST_TYPE           0xF0
#define ST_SINGLE         0
#define ST_MULTI          16
#define ST_TITLE_BAR      32
#define ST_PICTURE        48
#define ST_FRAME          64
#define ST_BACKGROUND     80
#define ST_GROUP_BOX      96
#define ST_GROUP_BOX2     112
#define ST_HUD_BACKGROUND 128
#define ST_TILE_PICTURE   144 //tileH and tileW params required for tiled image
#define ST_WITH_RECT      160
#define ST_LINE           176

#define ST_SHADOW         0x100
#define ST_NO_RECT        0x200 // this style works for CT_STATIC in conjunction with ST_MULTI
#define ST_KEEP_ASPECT_RATIO  0x800

#define ST_TITLE          ST_TITLE_BAR + ST_CENTER

// Slider styles
#define SL_DIR            0x400
#define SL_VERT           0
#define SL_HORZ           1024

#define SL_TEXTURES       0x10

// progress bar 
#define ST_VERTICAL       0x01
#define ST_HORIZONTAL     0

// Listbox styles
#define LB_TEXTURES       0x10
#define LB_MULTI          0x20

#define FontM             "PuristaMedium" // The standard font in Arma 3 is "PuristaMedium"

// Tree styles
#define TR_SHOWROOT       1
#define TR_AUTOCOLLAPSE   2

// MessageBox styles
#define MB_BUTTON_OK      1
#define MB_BUTTON_CANCEL  2
#define MB_BUTTON_USER    4

//---------------------------------
// Base classes for controls
//---------------------------------

//Standard static text.
class viruz_GUIBack
{    
	idc = -1;
	type = 0;
	style = 2; //centre text
	x = safeZoneX; 
	y = safeZoneY;
	h = 1;
	w = 1;
	font = "PuristaMedium";
	sizeEx = 0.03;
	colorBackground[] = {1,1,1,1};
	colorText[] = {0,0,1,1}; //blue text
	text = "";
};

class viruz_RscText
{
	type = CT_STATIC;
	idc = -1;
	w = 0.10;
	colorBackground[] = {0, 0, 0, 0};
	colorText[] = {0, 0, 0, 1};
	text = "";
	h = 0.0350;
	font = "PuristaMedium";
	SizeEx = "1.2 * 0.024";
	style = ST_LEFT;
};

//Standard button.
class viruz_RscButton
{
	type = CT_BUTTON;
	style = ST_CENTER;
	idc = -1;
	x = 0;
	y = 0;
	w = 0.0975;
	h = 0.04;
	text = "Button";
	font = "PuristaMedium";
	sizeEx = "1.5*0.022";

	colorText[] = {0, 0, 0, 1};
	colorDisabled[] = {0.40, 0.40, 0.40, 1};
	colorBackground[] = {1,0.5,0,1};
	colorBackgroundDisabled[] = {0.70, 0.70, 0.70, 0.80};
	colorBackgroundActive[] = {1,1,1,1};

	colorFocused[] = {1, 0.50, 0, 1};
	colorShadow[] = {0.72, 0.36, 0, 0.80};
	offsetX = 0;
	offsetY = 0;

	offsetPressedX = 0;
	offsetPressedY = 0;

	borderSize = 0.0;
	colorBorder[] = {0.72, 0.36, 0, 0};

	soundEnter[] = {};
	soundPush[] = {};
	soundClick[] = {};
	soundEscape[] = {};

	action = "";
	toolTip = "";
};

//Standard listbox.
class viruz_RscListBox
{
	idc = -1;
	access = 0;
	type = 5;
	w = 0.4;
	h = 0.4;
	rowHeight = 0;
	colorText[] = {1,1,1,1};
	colorScrollbar[] = {1,1,1,1};
	colorSelect[] = {0.75,0.75,0.75,1};
	colorSelect2[] = {0.75,0.75,0.75,1};
	colorBackground[] = {0,0,0,1};
	colorSelectBackground[] = {1,1,1,1};
	colorSelectBackground2[] = {1,1,1,1};
	soundSelect[] = {"",0.1,1};
	arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
	arrowFull = "#(argb,8,8,3)color(1,1,1,1)";
 	colorDisabled[] = {};
	class ListScrollBar
	{
		color[] = {1,1,1,0.6};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		shadow = 0;
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
	style = 16;
	font = "PuristaMedium";
	shadow = 2;
	sizeEx = "1.5*0.022";
	color[] = {1,1,1,1};
	period = 1.2;
	maxHistoryDelay = 1;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
};

class viruz_RscCombo
{
	idc = -1;
	access = 0;
	type = 4;
	style = 0;
	colorSelect[] = {0.5,0.5,0.5,1};
	colorText[] = {1,1,1,1};
	colorBackground[] = {0,0,0,1};
	colorScrollbar[] = {1,1,1,1};
	soundSelect[] = {"",0.1,1};
	soundExpand[] = {"",0.1,1};
	soundCollapse[] = {"",0.1,1};
	maxHistoryDelay = 1;
	class ComboScrollBar
	{
		color[] = {1,1,1,0.6};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		shadow = 0;
		thumb = "\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowFull = "\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		arrowEmpty = "\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		border = "\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
	x = 0;
	y = 0;
	w = 0.12;
	h = 0.035;
	shadow = 0;
	colorSelectBackground[] = {0.8784,0.8471,0.651,1};
	arrowEmpty = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa";
	arrowFull = "\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa";
	wholeHeight = 0.45;
	color[] = {0,0,0,0.6};
	colorActive[] = {0,0,0,1};
	colorDisabled[] = {0,0,0,0.3};
	font = "PuristaMedium";
	sizeEx = "1.5*0.022";
};