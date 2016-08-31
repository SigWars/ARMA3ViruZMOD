class CraftingTitleBackground : RscText {
	idc = 1050;
	x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	colorBackground[] = {0.05, 0.05, 0.05, 0.7};
//	text = "Crafting";
};

class CraftingTitle : RscText {
	idc = 1051;
	x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "4 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	colorBackground[] = {0.05, 0.05, 0.05, 0};
	text = "Crafting";
};

class CraftingButtonOpen : RscActiveText {
	idc = 10;
	style = 48;
	color[] = {1, 1, 1, 0.7};
	text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_debug_ca.paa";
	x = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	colorText[] = {1, 1, 1, 0.7};
	colorActive[] = {1, 1, 1, 1};
//	tooltip = $STR_DISP_CLOSE;
	tooltip = "Open crafting window";
	onMouseButtonClick = "createDialog ""RscDisplayCrafting"";";
};

class CraftingActionBackground : RscText {
	idc = 1052;
	x = "14.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "24.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	colorBackground[] = {0.05, 0.05, 0.05, 0.7};
};

class CraftingActionProgress : RscProgress {
	idc = 12;
	texture = "";
	textureExt = "";
	colorBar[] = {0.9, 0.9, 0.9, 0.9};
	colorExtBar[] = {1, 1, 1, 1};
	colorFrame[] = {1, 1, 1, 1};
	x = "26.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "25.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "10 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
};

class CraftingButtonStop : CraftingButtonOpen {
	idc = 13;
	text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa";
	x = "37 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "25 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "2 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
//	tooltip = $STR_DISP_CLOSE;
	tooltip = "Stop crafting";
	onMouseButtonClick = "systemChat ""Stop crafting""";
};

/*
class Crafting_ContainerBackground : RscText {
	idc = 1050;
	x = "1 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "23 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	colorBackground[] = {0.05, 0.05, 0.05, 0.7};
};

class CraftingContainerBackground : ExternalContainerBackground {
	colorText[] = {1, 1, 1, 0.1};
	idc = 1299;
	x = "1.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "3.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "18.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
};

class CraftingTab: RscActiveText {
	idc = 63210;
	text = "Crafting";
	colorBackgroundSelected[] = {1, 1, 1, 1};
	colorActive[] = {1, 1, 1, 1};
	colorFocused[] = {1, 1, 1, 0};
	soundDoubleClick[] = {"", 0.1, 1};
	color[] = {1, 1, 1, 1};
	colorBackground[] = {0, 0, 0, 1};
	x = "5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
	y = "1.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
	w = "5.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
	h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
};

class CraftingContainer: GroundContainer {
	idc = 63220;
};

class CraftingFilter: GroundFilter {
	idc = 65540;
};
*/

