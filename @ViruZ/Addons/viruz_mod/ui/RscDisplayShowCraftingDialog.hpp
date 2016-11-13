class RscDisplayShowCraftingDialog
{
	idd = 200000;
	onLoad = "uiNamespace setVariable ['RscDisplayShowCraftingDialog', _this select 0]";
	onUnload = "uiNamespace setVariable ['RscDisplayShowCraftingDialog', displayNull]";
	class controlsBackground
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by Mateuus, v1.063, #Romewo)
		////////////////////////////////////////////////////////

		class BackGroundItemInfo: RscText
		{
			idc = 200001;
			x = 0.329878 * safezoneW + safezoneX;
			y = 0.258329 * safezoneH + safezoneY;
			w = 0.0876386 * safezoneW;
			h = 0.153931 * safezoneH;
			colorBackground[] = {0.05,0.05,0.05,0.7};
		};
		class BackgroundContent: RscText
		{
			idc = 200002;
			x = 0.420594 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.283594 * safezoneW;
			h = 0.462 * safezoneH;
			colorBackground[] = {0.05,0.05,0.05,0.7};
		};
		class BackGroundMenu: RscText
		{
			idc = 200003;
			x = 0.329878 * safezoneW + safezoneX;
			y = 0.418916 * safezoneH + safezoneY;
			w = 0.0876386 * safezoneW;
			h = 0.299612 * safezoneH;
			colorBackground[] = {0.05,0.05,0.05,0.7};
		};
		class TopBackGround: RscText
		{
			idc = 200004;
			text = "ITEM"; //--- ToDo: Localize;
			x = 0.329878 * safezoneW + safezoneX;
			y = 0.236119 * safezoneH + safezoneY;
			w = 0.37486 * safezoneW;
			h = 0.0219901 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
		class ButtonCloseCross: RscActiveText
		{
			idc = 200005;
			style = 2096;
			color[] = {1,1,1,0.7};
			action = "closeDialog 0;";
			text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa"; //--- ToDo: Localize;
			x = 0.691052 * safezoneW + safezoneX;
			y = 0.240077 * safezoneH + safezoneY;
			w = 0.0103125 * safezoneW;
			h = 0.011 * safezoneH;
			colorText[] = {1,1,1,0.7};
			colorActive[] = {1,1,1,1};
			tooltip = "Close"; //--- ToDo: Localize;
		};
	};
	class controls
	{
		class ItemPicture: RscPictureKeepAspect
		{
			idc = 200006;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 0.335033 * safezoneW + safezoneX;
			y = 0.269104 * safezoneH + safezoneY;
			w = 0.0773282 * safezoneW;
			h = 0.131941 * safezoneH;
		};
		class ButtonCraft: RscButton
		{
			idc = 200007;
			action = "[uiNamespace getVariable 'RscCraftingClassName', (lbCurSel 200008) + 1] call VZClient_object_item_craft; closeDialog 0;";
			text = "CRAFT"; //--- ToDo: Localize;
			x = 0.345344 * safezoneW + safezoneX;
			y = 0.554975 * safezoneH + safezoneY;
			w = 0.0567073 * safezoneW;
			h = 0.0549753 * safezoneH;
		};
		class DropdownQuantity: RscCombo
		{
			idc = 200008;
			x = 0.345344 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.022 * safezoneH;
		};
		
		class ButtonCancel: RscButtonMenuCancel
		{
			x = 0.345344 * safezoneW + safezoneX;
			y = 0.686916 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		class Description: RscStructuredText
		{
			idc = 200009;
			x = 0.427812 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.273281 * safezoneW;
			h = 0.44 * safezoneH;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////

	};
};