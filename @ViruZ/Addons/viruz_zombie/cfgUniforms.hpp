	class UniformItem: InventoryItem_Base_F
	{
		type = UNIFORM_SLOT; /// to what slot does the uniform fit
	};

	/*class U_Test_uniform: Itemcore
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		allowedSlots[] = {BACKPACK_SLOT}; /// where does the uniform fit to when not equipped
		displayName = "Dirty survivor uniform"; /// how would the stuff be displayed in inventory and on ground
		picture = "\viruz_zombie\textures\icosurvivorunif.paa"; /// this icon fits the uniform surprisingly well
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver"; /// how does the uniform look when put on ground

		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformClass = Test_Soldier_base_F; /// what soldier class contains parameters of the uniform (such as model, camouflage, hitpoints and others)
			containerClass = Supply90; /// what fake vehicle is used to describe size of uniform container, there is quite a lot SupplyXX classes ready
			mass = 80; /// combined weight and volume
		};
	};*/
	/*class U_woman_survivor: Itemcore
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		allowedSlots[] = {}; /// where does the uniform fit to when not equipped
		displayName = "Woman survivor uniform"; /// how would the stuff be displayed in inventory and on ground
		picture = "\viruz_zombie\textures\icounifwomansurvivor.paa"; /// this icon fits the uniform surprisingly well
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver"; /// how does the uniform look when put on ground

		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformClass = VZ_womansurvivor; /// what soldier class contains parameters of the uniform (such as model, camouflage, hitpoints and others)
			containerClass = Supply90; /// what fake vehicle is used to describe size of uniform container, there is quite a lot SupplyXX classes ready
			mass = 80; /// combined weight and volume
		};
	};*/
	/*class U_zed_uniform: Itemcore
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		allowedSlots[] = {BACKPACK_SLOT}; /// where does the uniform fit to when not equipped
		displayName = "Dead cops uniform"; /// how would the stuff be displayed in inventory and on ground
		picture = "\viruz_zombie\textures\icocopsunif.paa"; /// this icon fits the uniform surprisingly well
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver"; /// how does the uniform look when put on ground

		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformClass = VZ_zed; /// what soldier class contains parameters of the uniform (such as model, camouflage, hitpoints and others)
			containerClass = Supply90; /// what fake vehicle is used to describe size of uniform container, there is quite a lot SupplyXX classes ready
			mass = 80; /// combined weight and volume
		};
	};*/
	class U_boomer_uniform: Itemcore
	{
		scope = 2; /// scope needs to be 2 to have a visible class
		allowedSlots[] = {BACKPACK_SLOT}; /// where does the uniform fit to when not equipped
		displayName = "Big dirty uniform"; /// how would the stuff be displayed in inventory and on ground
		picture = "\viruz_zombie\textures\viruz_logoico_ca.paa"; /// this icon fits the uniform surprisingly well
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver"; /// how does the uniform look when put on ground

		class ItemInfo: UniformItem
		{
			uniformModel = "-";
			uniformClass = VZ_boomer; /// what soldier class contains parameters of the uniform (such as model, camouflage, hitpoints and others)
			containerClass = Supply90; /// what fake vehicle is used to describe size of uniform container, there is quite a lot SupplyXX classes ready
			mass = 80; /// combined weight and volume
		};
	};
