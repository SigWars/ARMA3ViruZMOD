
	class HeadgearItem : InventoryItem_Base_F
	{
		allowedSlots[] = {BACKPACK_SLOT, HEADGEAR_SLOT}; /// defines where can be the cap placed, it is small enough to fit in backpack
		type = HEADGEAR_SLOT;		/// standard slot for the cap is on head
		hiddenSelections[] = {};	/// default caps don't have any changeable selections
		hitpointName = "HitHead";	/// what hitpoint is covered with the cap to have additional protection
	};
	class VZ_zedcap: ItemCore
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName  = "Police cap"; /// how would the stuff be displayed in inventory and on ground
		picture = "\viruz_zombie\textures\icopolicecap.paa"; /// this looks fairly similar
		model   = "\viruz_zombie\models\casque.p3d"; /// what model does the cap use
		hiddenSelections[] = {"camo"}; /// what selection in model could have different textures
		hiddenSelectionsTextures[] = {"\viruz_zombie\textures\Zombie_Policeman_head.paa"}; /// what texture is going to be used
		class ItemInfo : HeadgearItem
		{
			mass = 10; /// combined weight and volume of the cap, this equals to single magazine
			uniformModel = "\viruz_zombie\models\casque.p3d";	/// what model is used for this cap
			allowedSlots[] = {UNIFORM_SLOT, BACKPACK_SLOT, VEST_SLOT, HEADGEAR_SLOT};	/// this cap is so small and flexible that it fits everywhere
			modelSides[] = {6}; /// available for all sides
			armor = 0;	/// this cap doesn't provide any protection
			passThrough = 1; /// this cap doesn't provide any protection
			hiddenSelections[] = {"camo"}; /// what selection in model could have different textures
		};		
	};
	class VZ_hatofficer: ItemCore
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName  = "Officer Hat"; /// how would the stuff be displayed in inventory and on ground
		picture = "\viruz_zombie\textures\icohat.paa"; /// this looks fairly similar
		model   = "\viruz_zombie\models\hatofficer.p3d"; /// what model does the cap use
		hiddenSelections[] = {"camo"}; /// what selection in model could have different textures
		hiddenSelectionsTextures[] = {"\viruz_zombie\textures\hat_officer.paa"}; /// what texture is going to be used
		class ItemInfo : HeadgearItem
		{
			mass = 10; /// combined weight and volume of the cap, this equals to single magazine
			uniformModel = "\viruz_zombie\models\hatofficer.p3d";	/// what model is used for this cap
			allowedSlots[] = {UNIFORM_SLOT, BACKPACK_SLOT, VEST_SLOT, HEADGEAR_SLOT};	/// this cap is so small and flexible that it fits everywhere
			modelSides[] = {6}; /// available for all sides
			armor = 0;	/// this cap doesn't provide any protection
			passThrough = 1; /// this cap doesn't provide any protection
			hiddenSelections[] = {"camo"}; /// what selection in model could have different textures
		};		
	};
	class VZ_maskmed: ItemCore
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		displayName  = "Officer Hat"; /// how would the stuff be displayed in inventory and on ground
		picture = "\viruz_zombie\textures\icomaskmedic.paa"; /// this looks fairly similar
		model   = "\viruz_zombie\models\maskmed.p3d"; /// what model does the cap use
		hiddenSelections[] = {"camo"}; /// what selection in model could have different textures
		hiddenSelectionsTextures[] = {"\viruz_zombie\textures\medicmask.paa"}; /// what texture is going to be used
		class ItemInfo : HeadgearItem
		{
			mass = 10; /// combined weight and volume of the cap, this equals to single magazine
			uniformModel = "\viruz_zombie\models\maskmed.p3d";	/// what model is used for this cap
			allowedSlots[] = {UNIFORM_SLOT, BACKPACK_SLOT, VEST_SLOT, HEADGEAR_SLOT};	/// this cap is so small and flexible that it fits everywhere
			modelSides[] = {6}; /// available for all sides
			armor = 0;	/// this cap doesn't provide any protection
			passThrough = 1; /// this cap doesn't provide any protection
			hiddenSelections[] = {"camo"}; /// what selection in model could have different textures
		};		
	};