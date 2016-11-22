class viruz_GUIBack
{
	idc=-1;
	type=0;
	style=2;
	x="safeZoneX";
	y="safeZoneY";
	h=1;
	w=1;
	font="PuristaMedium";
	sizeEx=0.029999999;
	colorBackground[]={1,1,1,1};
	colorText[]={0,0,1,1};
	text="";
};
class viruz_RscText
{
	type=0;
	idc=-1;
	w=0.1;
	colorBackground[]={0,0,0,0};
	colorText[]={0,0,0,1};
	text="";
	h=0.035;
	font="PuristaMedium";
	SizeEx="1.2 * 0.024";
	style=0;
};
class viruz_RscButton
{
	type=1;
	style=2;
	idc=-1;
	x=0;
	y=0;
	w=0.097499996;
	h=0.039999999;
	text="Button";
	font="PuristaMedium";
	sizeEx="1.5*0.022";
	colorText[]={0,0,0,1};
	colorDisabled[]={0.40000001,0.40000001,0.40000001,1};
	colorBackground[]={1,0.5,0,1};
	colorBackgroundDisabled[]={0.69999999,0.69999999,0.69999999,0.80000001};
	colorBackgroundActive[]={1,1,1,1};
	colorFocused[]={1,0.5,0,1};
	colorShadow[]={0.72000003,0.36000001,0,0.80000001};
	offsetX=0;
	offsetY=0;
	offsetPressedX=0;
	offsetPressedY=0;
	borderSize=0;
	colorBorder[]={0.72000003,0.36000001,0,0};
	soundEnter[]={};
	soundPush[]={};
	soundClick[]={};
	soundEscape[]={};
	action="";
	toolTip="";
};
class viruz_RscListBox
{
	idc=-1;
	access=0;
	type=5;
	w=0.40000001;
	h=0.40000001;
	rowHeight=0;
	colorText[]={1,1,1,1};
	colorScrollbar[]={1,1,1,1};
	colorSelect[]={0.75,0.75,0.75,1};
	colorSelect2[]={0.75,0.75,0.75,1};
	colorBackground[]={0,0,0,1};
	colorSelectBackground[]={1,1,1,1};
	colorSelectBackground2[]={1,1,1,1};
	soundSelect[]=
	{
		"",
		0.1,
		1
	};
	arrowEmpty="#(argb,8,8,3)color(1,1,1,1)";
	arrowFull="#(argb,8,8,3)color(1,1,1,1)";
	colorDisabled[]={};
	class ListScrollBar
	{
		color[]={1,1,1,0.60000002};
		colorActive[]={1,1,1,1};
		colorDisabled[]={1,1,1,0.30000001};
		shadow=0;
		thumb="\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowFull="\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		arrowEmpty="\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		border="\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
	style=16;
	font="PuristaMedium";
	shadow=2;
	sizeEx="1.5*0.022";
	color[]={1,1,1,1};
	period=1.2;
	maxHistoryDelay=1;
	autoScrollSpeed=-1;
	autoScrollDelay=5;
	autoScrollRewind=0;
};
class viruz_RscCombo
{
	idc=-1;
	access=0;
	type=4;
	style=0;
	colorSelect[]={0.5,0.5,0.5,1};
	colorText[]={1,1,1,1};
	colorBackground[]={0,0,0,1};
	colorScrollbar[]={1,1,1,1};
	soundSelect[]=
	{
		"",
		0.1,
		1
	};
	soundExpand[]=
	{
		"",
		0.1,
		1
	};
	soundCollapse[]=
	{
		"",
		0.1,
		1
	};
	maxHistoryDelay=1;
	class ComboScrollBar
	{
		color[]={1,1,1,0.60000002};
		colorActive[]={1,1,1,1};
		colorDisabled[]={1,1,1,0.30000001};
		shadow=0;
		thumb="\A3\ui_f\data\gui\cfg\scrollbar\thumb_ca.paa";
		arrowFull="\A3\ui_f\data\gui\cfg\scrollbar\arrowFull_ca.paa";
		arrowEmpty="\A3\ui_f\data\gui\cfg\scrollbar\arrowEmpty_ca.paa";
		border="\A3\ui_f\data\gui\cfg\scrollbar\border_ca.paa";
	};
	x=0;
	y=0;
	w=0.12;
	h=0.035;
	shadow=0;
	colorSelectBackground[]={0.87840003,0.84710002,0.65100002,1};
	arrowEmpty="\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_ca.paa";
	arrowFull="\A3\ui_f\data\GUI\RscCommon\rsccombo\arrow_combo_active_ca.paa";
	wholeHeight=0.44999999;
	color[]={0,0,0,0.60000002};
	colorActive[]={0,0,0,1};
	colorDisabled[]={0,0,0,0.30000001};
	font="PuristaMedium";
	sizeEx="1.5*0.022";
};
class viruz_build_dialogMenu
{
	idd=-1;
	movingenable=0;
	class controls
	{
		class RscText000: viruz_RscText
		{
			text="ViruZ Build Menu";
			x=0.25;
			y=0.14;
			h=0.1;
			w=0.5;
			colorBackground[]={1,0.5,0,1};
			SizeEx="2 * 0.024";
			style=2;
		};
		class GUIBack000: viruz_GUIBack
		{
			x=0.25;
			y=0.25;
			h=0.5;
			w=0.5;
			colorBackground[]={0,0,0,0.75};
		};
		class RscButton000: viruz_RscButton
		{
			text="Construction Menu";
			x=0.27000001;
			y=0.28999999;
			h=0.1;
			w=0.20999999;
			style=2;
			action="closeDialog 0; [player] call viruz_fnc_openconstructionmenu;";
		};
		class RscButton001: viruz_RscButton
		{
			idc=1500;
			text="Build from chest";
			x=0.51999998;
			y=0.28999999;
			h=0.1;
			w=0.20999999;
			style=2;
			action="closeDialog 0; [cursorTarget] call viruz_fnc_openconstructionmenu";
		};
		/*class RscButton002: viruz_RscButton
		{
			idc=1501;
			text="Move object";
			x=0.27000001;
			y=0.44999999;
			h=0.1;
			w=0.20999999;
			style=2;
			//action="[cursorTarget] call viruz_fnc_moveObject; closeDialog 0;";
		};*/
		class RscButton003: viruz_RscButton
		{
			idc=1502;
			text="Remove object";
			/*x=0.51999998;
			y=0.44999999;
			h=0.1;
			w=0.20999999;*/
			x = 0.3875;
			y = 0.44;
			w = 0.21;
			h = 0.1;
			style=2;
			action="[cursorTarget] call viruz_fnc_removeObject; closeDialog 0;";
		};
		/*class RscButton004: viruz_RscButton
		{
			idc=1503;
			text="Align to Ground";
			x=0.27000001;
			y=0.61000001;
			h=0.1;
			w=0.20999999;
			style=2;
			action="[] call viruz_fnc_alignObject; closeDialog 0;";
		};*/
		class RscButton005: viruz_RscButton
		{
			text="Cancel";
			/*x=0.51999998;
			y=0.61000001;
			h=0.1;
			w=0.20999999;*/
			x = 0.3875;
			y = 0.6;
			w = 0.21;
			h = 0.1;
			style=2;
			action="closeDialog 0;";
		};
	};
};
class viruz_build_dialogConstructionMenu
{
	idd=-1;
	movingenable=0;
	enableSimulation=1;
	onLoad="uiNamespace setVariable ['viruz_build_display',_this select 0];";
	class Objects
	{
		class Object
		{
			idc=1503;
			type=82;
			model="A3\Structures_F\Mil\BagFence\BagFence_Long_F.p3d";
			scale=1;
			direction[]={0,0,1};
			up[]={0,1,1};
			x=0.5;
			y=0.5;
			z=4.5;
			xBack=0.82499999;
			yBack=0.5;
			zBack=1.2;
			inBack=0;
			enableZoom=1;
			zoomDuration=0.001;
		};
	};
	class controls
	{
		class GUIBack001: viruz_GUIBack
		{
			x="safeZoneX + 0.01 * 3 / 4";
			y="safeZoneY + 0.12";
			h="safeZoneH - 0.13";
			w="0.75 * 3 / 4";
			colorBackground[]={0,0,0,0.69999999};
		};
		class GUIBack002: viruz_GUIBack
		{
			x="safeZoneX + safeZoneW - 1.01 * 3 / 4";
			y="safeZoneY + safeZoneH - 0.51";
			h=0.5;
			w="1 * 3 / 4";
			colorBackground[]={0,0,0,0.69999999};
		};
		class RscText000: viruz_RscText
		{
			text="Construction menu";
			x="safeZoneX + 0.01 * 3 / 4";
			y="safeZoneY + 0.01";
			h=0.1;
			w="0.75 * 3 / 4";
			colorBackground[]={1,0.5,0,1};
			SizeEx="2 * 0.024";
			style=2;
		};
		class RscText001: viruz_RscText
		{
			text="Requirments:";
			x="safeZoneX + safeZoneW - 0.99 * 3 / 4";
			y="safeZoneY + safeZoneH - 0.49";
			h=0.050000001;
			w="0.96 * 3 / 4";
			colorBackground[]={1,0.5,0,1};
			colorText[]={0,0,0,1};
			SizeEx="1.5 * 0.024";
			style=2;
		};
		class RscButton000: viruz_RscButton
		{
			text="cancel";
			x="safeZoneX + 0.035 * 3 / 4";
			y="safeZoneY + safeZoneH - 0.12";
			h=0.075000003;
			w="0.3 * 3 / 4";
			style=2;
			action="closeDialog 0";
		};
		class RscButton001: viruz_RscButton
		{
			text="build";
			x="safeZoneX + 0.425 * 3 / 4";
			y="safeZoneY + safeZoneH - 0.12";
			h=0.075000003;
			w="0.3 * 3 / 4";
			style=2;
			action="[] call viruz_fnc_buildObject; closeDialog 0;";
		};
		class RscText002: viruz_RscText
		{
			text="Categorie:";
			x="safeZoneX + 0.02 * 3 / 4";
			y="safeZoneY + 0.15";
			h=0.039999999;
			w="0.13 * 3 / 4";
			colorBackground[]={0,0,0,0};
			colorText[]={1,1,1,1};
			style=0;
		};
		class RscCombo000: viruz_RscCombo
		{
			idc=1500;
			x="safeZoneX + 0.15 * 3 / 4";
			y="safeZoneY + 0.15";
			h=0.039999999;
			w="0.56 * 3 / 4";
			colorBackground[]={0.1,0.1,0.1,1};
			onLBSelChanged="[_this select 1,'Categorie'] call viruz_fnc_updateConstructionMenu;";
		};
		class RscListBox000: viruz_RscListBox
		{
			idc=1501;
			x="safeZoneX + 0.04 * 3 / 4";
			y="safeZoneY + 0.22";
			h="safeZoneH - 0.40";
			w="0.68 * 3 / 4";
			colorBackground[]={0,0,0,1};
			onLBSelChanged="[_this select 1,'Classname'] call viruz_fnc_updateConstructionMenu;";
			onLBDblClick="[] call viruz_fnc_buildObject; closeDialog 0;";
		};
		class RscListBox001: viruz_RscListBox
		{
			idc=1502;
			x="safeZoneX + safeZoneW - 0.99 * 3 / 4";
			y="safeZoneY + safeZoneH - 0.41";
			h=0.38;
			w="0.96 * 3 / 4";
			colorBackground[]={0,0,0,1};
		};
		class GUIBack000: viruz_RscListBox
		{
			x="safeZoneX + 0.76 * 3 / 4";
			y="safeZoneY";
			h="safeZoneH";
			w="safeZoneW - 0.76 * 3 / 4";
			colorBackground[]={0,0,0,0};
		};
	};
	class controlsBackground
	{
		class GUIBack000: viruz_GUIBack
		{
			x="safeZoneX";
			y="safeZoneY";
			h="safeZoneH";
			w="safeZoneW";
			colorBackground[]={0.5,0.5,0.5,1};
		};
	};
};
class CfgPatches
{
	class viruz_build
	{
		units[]=
		{
			"viruz_build_ModuleAddBlueprint"
		};
		weapons[]={};
		requiredAddons[]=
		{
			"CBA_Main",
			"A3_Modules_F",
			"viruz_mod"
		};
		author[]=
		{
			"SigWar"
		};
	};
};
class CfgFunctions
{
	class VIRUZ
	{
		class build
		{
			file="\viruz_build\functions";
			class alignObject
			{
			};
			class addBlueprint
			{
			};
			class addConstructionsToZeus
			{
			};
			class clearBlueprints
			{
			};
			class buildObject
			{
			};
			class distanceObject
			{
			};
			class keyCheck
			{
			};
			class moveObject
			{
			};
			class openConstructionMenu
			{
			};
			class openBuildMenu
			{
			};
			class removeItemCargoGlobal
			{
			};
			class removeObject
			{
			};
			class turnObject
			{
			};
			class updateConstructionMenu
			{
			};
			class updateCollisions
			{
			};
		};
	};
};
class CfgFactionClasses
{
	class NO_CATEGORY;
	class viruz_build: NO_CATEGORY
	{
		displayName="Build";
	};
};
class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class ArgumentsBaseUnits
		{
			class Units;
		};
		class ModuleDescription
		{
			class AnyBrain;
		};
	};
	class viruz_build_ModuleAddBlueprint: Module_F
	{
		scope=2;
		displayName="Add Blueprint";
		category="viruz_build";
		function="viruz_fnc_addBlueprint";
		functionPriority=2;
		isGlobal=2;
		isTriggerActivated=1;
		isDisposable=0;
		class Arguments: ArgumentsBaseUnits
		{
			class Units: Units
			{
			};
			class categorie
			{
				displayName="Categorie";
				description="The Categorie where the blueprint item sould be shown";
				typeName="STRING";
				defaultValue="Generators and Maintain";
			};
			class classname
			{
				displayName="Classname";
				description="Classname of the Object you want to add";
				typeName="STRING";
				defaultValue="";
			};
			class ressoure1
			{
				displayName="Required Ressource";
				description="Add here the classname from one requirement, leave empty for not use this requirement";
				typeName="STRING";
				defaultValue="";
			};
			class quantity1
			{
				displayName="Quantity:";
				description="How much items you need";
				typeName="NUMBER";
				defaultValue=0;
			};
			class ressoure2
			{
				displayName="Required Ressource";
				description="Add here the classname from one requirement, leave empty for not use this requirement";
				typeName="STRING";
				defaultValue="";
			};
			class quantity2
			{
				displayName="Quantity";
				description="How much items you need";
				typeName="NUMBER";
				defaultValue=0;
			};
			class ressoure3
			{
				displayName="Required Ressource";
				description="Add here the classname from one requirement, leave empty for not use this requirement";
				typeName="STRING";
				defaultValue="";
			};
			class quantity3
			{
				displayName="Quantity";
				description="How much items you need";
				typeName="NUMBER";
				defaultValue=0;
			};
			class ressoure4
			{
				displayName="Required Ressource";
				description="Add here the classname from one requirement, leave empty for not use this requirement";
				typeName="STRING";
				defaultValue="";
			};
			class quantity4
			{
				displayName="Quantity";
				description="How much items you need";
				typeName="NUMBER";
				defaultValue=0;
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="Add your own Blueprint to the build construction menu";
			sync[]={};
		};
	};
	class viruz_build_ModuleClearBlueprint: Module_F
	{
		scope=2;
		displayName="Clear Blueprints";
		category="viruz_build";
		function="viruz_fnc_clearBlueprints";
		functionPriority=1;
		isGlobal=2;
		isTriggerActivated=1;
		isDisposable=0;
		class Arguments: ArgumentsBaseUnits
		{
			class Units: Units
			{
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="Clear all Blueprints from the build construction menu";
			sync[]={};
		};
	};
	class viruz_build_ModuleAddConstructionsToZeus: Module_F
	{
		scope=2;
		displayName="Add Structures to Zeus";
		category="viruz_build";
		function="viruz_fnc_addConstructionsToZeus";
		functionPriority=2;
		isGlobal=2;
		isTriggerActivated=0;
		isDisposable=0;
		class Arguments: ArgumentsBaseUnits
		{
			class Units: Units
			{
			};
			class which
			{
				displayName="Which zeus?";
				description="Which zeus module should get the objects?";
				typeName="STRING";
				class values
				{
					class All
					{
						name="all";
						value="all";
						default=1;
					};
					class Sync
					{
						name="synchronized";
						value="synchronized";
					};
				};
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description="Add constructed Objects to Zeus interface";
			sync[]=
			{
				"ModuleCurator_F"
			};
			class ModuleCurator_F
			{
				description="Sync with any Game Master module (needed when picked ""synchronized"")";
				displayName="Game Master";
				optional=1;
				duplicate=1;
				synced[]=
				{
					"AnyBrain"
				};
			};
		};
	};
};
class Extended_PostInit_EventHandlers
{
	viruz_build_init="[] execVM '\viruz_build\init.sqf'";
};
class cfgMods
{
	author="76561198113211909";
	timepacked="1432730749";
};
