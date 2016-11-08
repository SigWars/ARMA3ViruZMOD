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
			x = 0.29375 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.462 * safezoneH;
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
			x = 0.707281 * safezoneW + safezoneX;
			y = 0.258 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.462 * safezoneH;
			colorBackground[] = {0.05,0.05,0.05,0.7};
		};
		class BackgroundTop: RscText
		{
			idc = 100004;
			text = "ITEM"; //--- ToDo: Localize;
			x = 0.294781 * safezoneW + safezoneX;
			y = 0.2316 * safezoneH + safezoneY;
			w = 0.53625 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,1};
		};
		class ButtonClose: RscActiveText
		{
			idc = 100005;
			style = 2096;
			color[] = {1,1,1,0.7};
			action = "closeDialog 0;";
			text = "\A3\Ui_f\data\GUI\Rsc\RscDisplayArcadeMap\icon_exit_cross_ca.paa"; //--- ToDo: Localize;
			x = 0.814531 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
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
			x = 0.298906 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.198 * safezoneH;
		};
		class ButtonDescription: RscButton
		{
			idc = 100007;
			action = "'DESCRIPTION' call VZClient_gui_itemDescription_event_onTabelaButton;";
			text = "DESCRIPTION"; //--- ToDo: Localize;
			x = 0.737188 * safezoneW + safezoneX;
			y = 0.2888 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class ButtonCrafting: RscButton
		{
			idc = 100008;
			action = "'CRAFTING' call VZClient_gui_itemDescription_event_onTabelaButton;";
			text = "CRAFTING"; //--- ToDo: Localize;
			x = 0.737188 * safezoneW + safezoneX;
			y = 0.3284 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.022 * safezoneH;
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
			action = "closeDialog 0; [SelectedInventoryItem select 0] call object_item_consume;";
			text = "CONSUME"; //--- ToDo: Localize;
			x = 0.737188 * safezoneW + safezoneX;
			y = 0.4252 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class ButtonUse: RscButton
		{
			idc = 100015;
			action = "closeDialog 0; [SelectedInventoryItem select 0] call object_item_use;";
			text = "USE"; //--- ToDo: Localize;
			x = 0.737188 * safezoneW + safezoneX;
			y = 0.4626 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class ButtonConstruct: RscButton
		{
			idc = 100016;
			action = "closeDialog 0; [SelectedInventoryItem select 0] call object_item_construct;";
			text = "CONSTRUCT"; //--- ToDo: Localize;
			x = 0.737188 * safezoneW + safezoneX;
			y = 0.5044 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			x = 0.737188 * safezoneW + safezoneX;
			y = 0.6892 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
		};
		
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};