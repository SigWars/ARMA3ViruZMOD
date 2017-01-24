
	class HeadgearItem : InventoryItem_Base_F
	{
		allowedSlots[] = {BACKPACK_SLOT, HEADGEAR_SLOT}; /// defines where can be the cap placed, it is small enough to fit in backpack
		type = HEADGEAR_SLOT;		/// standard slot for the cap is on head
		hiddenSelections[] = {};	/// default caps don't have any changeable selections
		hitpointName = "HitHead";	/// what hitpoint is covered with the cap to have additional protection
	};
