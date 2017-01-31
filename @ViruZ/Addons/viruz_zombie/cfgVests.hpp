	class VestItem : InventoryItem_Base_F {
		type = 701;
		uniformType = "Default";
		hiddenSelections[] = {};
		armor = 5*0;
		passThrough = 1;
		hitpointName = "HitBody";
	};
	
	class Vest_Camo_Base : ItemCore {
		scope = 0;
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		picture = "\A3\characters_f\Data\UI\icon_V_BandollierB_CA.paa";
		model = "\A3\Weapons_F\Ammo\mag_univ.p3d";
		hiddenSelections[] = {"camo"};
		
		class ItemInfo : VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
			hiddenSelections[] = {"camo"};
			containerClass = "Supply0";
			mass = 0;
			armor = 0;
			passThrough = 1;
		};
	};
	
	class Vest_NoCamo_Base : ItemCore {
		scope = 0;
		weaponPoolAvailable = 1;
		allowedSlots[] = {901};
		picture = "\A3\characters_f\Data\UI\icon_V_BandollierB_CA.paa";
		model = "\A3\Weapons_F\Ammo\mag_univ.p3d";
		hiddenSelections[] = {};
		
		class ItemInfo : VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_bandolier";
			hiddenSelections[] = {};
			containerClass = "Supply0";
			mass = 0;
			armor = 0;
			passThrough = 1;
		};
	};
	class V_Rangemaster_belt : Vest_NoCamo_Base {
		scope = 2;
		displayName = "$STR_V_Rangemaster_belt0";
		picture = "\A3\Characters_F\data\ui\icon_V_Belt_CA.paa";
		model = "\A3\Characters_F\BLUFOR\equip_b_belt";
		
		class ItemInfo : ItemInfo {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_belt";
			containerClass = "Supply40";
			mass = 20;
			armor = 5*0.2;
			passThrough = 0.8;
		};
	};
	/*class VZ_Vest: V_Rangemaster_belt
	{	
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName  = "Survival vest"; /// how would the stuff be displayed in inventory and on ground
		picture = "\viruz_zombie\textures\viruz_logoico_ca.paa"; /// this icon fits the vest surprisingly well
		model   = "\viruz_zombie\models\vest.p3d"; /// what model does the vest use
		
		class ItemInfo: ItemInfo
		{
			uniformModel   = "\viruz_zombie\models\vest.p3d"; /// what model does the vest use
			mass = 20;
			armor = 5*0.2;
			passThrough = 0.8;
		};
	};*/