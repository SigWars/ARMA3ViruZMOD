class RscDisplayShowItemDialog
{
	idd = 100000;
	onLoad = "uiNamespace setVariable ['RscDisplayShowItemDialog', _this select 0]";
	onUnload = "uiNamespace setVariable ['RscDisplayShowItemDialog', displayNull]";
	class controlsBackground
	{
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by Mateuus, v1.063, #Begaqu)
		////////////////////////////////////////////////////////
		class BackgroundItemInfo: RscText
		{
			idc = 100001;
			x = 0.329878 * safezoneW + safezoneX;
			y = 0.258329 * safezoneH + safezoneY;
			w = 0.0876386 * safezoneW;
			h = 0.153931 * safezoneH;
			colorBackground[] = {0.05,0.05,0.05,0.7};
		};
		class BackgroundContent: RscText
		{
			idc = 100002;
			x = 0.420594 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.283594 * safezoneW;
			h = 0.462 * safezoneH;
			colorBackground[] = {0.05,0.05,0.05,0.7};
		};
		class BackgroundMenu: RscText
		{
			idc = 100003;
			x = 0.329878 * safezoneW + safezoneX;
			y = 0.417543 * safezoneH + safezoneY;
			w = 0.0876386 * safezoneW;
			h = 0.302358 * safezoneH;
			colorBackground[] = {0.05,0.05,0.05,0.7};
		};
		class BackgroundTop: RscText
		{
			idc = 100004;
			text = "ITEM"; //--- ToDo: Localize;
			x = 0.329878 * safezoneW + safezoneX;
			y = 0.236119 * safezoneH + safezoneY;
			w = 0.37486 * safezoneW;
			h = 0.0219901 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
		class ButtonClose: RscActiveText
		{
			idc = 100005;
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
		class ItemImagen: RscPictureKeepAspect
		{
			idc = 100006;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 0.335033 * safezoneW + safezoneX;
			y = 0.269104 * safezoneH + safezoneY;
			w = 0.0773282 * safezoneW;
			h = 0.131941 * safezoneH;
		};
		class ButtonDescription: RscButton
		{
			idc = 100007;
			action = "'DESCRIPTION' call VZClient_gui_itemDescription_event_onTabelaButton;";
			text = "DESCRIPTION"; //--- ToDo: Localize;
			x = 0.349028 * safezoneW + safezoneX;
			y = 0.634676 * safezoneH + safezoneY;
			w = 0.0515521 * safezoneW;
			h = 0.0219901 * safezoneH;

		};
		class ButtonCrafting: RscButton
		{
			idc = 100008;
			action = "'CRAFTING' call VZClient_gui_itemDescription_event_onTabelaButton;";
			text = "CRAFTS"; //--- ToDo: Localize;
			x = 0.349055 * safezoneW + safezoneX;
			y = 0.556295 * safezoneH + safezoneY;
			w = 0.0515521 * safezoneW;
			h = 0.0219901 * safezoneH;
		};
		class DetalhesTabela: RscControlsGroup
		{
			idc = 100009;
			x = "13 * (0.025) + (0)";
			y = "2 * (0.04) + (0)";
			w = "26.5 * (0.025)";
			h = "20 * (0.04)";
			class controls
			{
				class ItemName: RscStructuredText
				{
					idc = 100010;
					text = "Item Name";
					x = 0;
					y = 0;
					w = "26.5 * (0.025)";
					h = "1.5 * (0.04)";
				};
				class Description: RscStructuredText
				{
					idc = 100011;
					x = 0;
					y = "1.5 * (0.04)";
					w = "26.5 * (0.025)";
					h = "17 * (0.04)";
				};
			};
		};
		class CraftingTabela: RscControlsGroup
		{
			idc = 100012;
			show = "false";
			x = 0.426781 * safezoneW + safezoneX;
			y = 0.2668 * safezoneH + safezoneY;
			w = 0.273281 * safezoneW;
			h = 0.44 * safezoneH;
			
			class controls
			{
				class CraftingListBox: RscListBox
				{
					idc = 100013;
					x = 0;
					y = 0;
					w = "26.5 * (0.025)";
					h = "20 * (0.04)";
					sizeEx = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx2 = "0.8 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					rowHeight = "2 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					canDrag = 0;
					colorText[] = {1,1,1,1};
					colorBackground[] = {0,0,0,0};
					itemBackground[] = {1,1,1,0.1};
					itemSpacing = 0.001;
					onLBDblClick = "closeDialog 0; _this call VZClient_gui_itemDescription_event_onCraftingDoubleClick";
				};
			};
		};
		class ButtonConsume: RscButton
		{
			idc = 100014;
			action = "closeDialog 0;";
			text = "CONSUME"; //--- ToDo: Localize;
			x = 0.329878 * safezoneW + safezoneX;
			y = 0.43403 * safezoneH + safezoneY;
			w = 0.0412417 * safezoneW;
			h = 0.0439802 * safezoneH;
		};
		class ButtonUse: RscButton
		{
			idc = 100015;
			action = "closeDialog 0;";
			text = "USE"; //--- ToDo: Localize;
			x = 0.376275 * safezoneW + safezoneX;
			y = 0.43403 * safezoneH + safezoneY;
			w = 0.0412417 * safezoneW;
			h = 0.0439802 * safezoneH;
		};
		class ButtonConstruct: RscButton
		{
			idc = 100016;
			action = "closeDialog 0; [SelectedInventoryItem select 0] call object_item_construct;";
			text = "BUILD"; //--- ToDo: Localize;
			x = 0.349055 * safezoneW + safezoneX;
			y = 0.586641 * safezoneH + safezoneY;
			w = 0.0515521 * safezoneW;
			h = 0.0219901 * safezoneH;
		};
		class ButtonFill: RscButton
		{
			idc = 100017;
			action = "closeDialog 0;";
			text = "FILL"; //--- ToDo: Localize;
			x = 0.349055 * safezoneW + safezoneX;
			y = 0.501319 * safezoneH + safezoneY;
			w = 0.0515521 * safezoneW;
			h = 0.0219901 * safezoneH;
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			x = 0.349055 * safezoneW + safezoneX;
			y = 0.685596 * safezoneH + safezoneY;
			w = 0.0515521 * safezoneW;
			h = 0.0219901 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};