class Blueprint_Craft_Woodenplank : Recipe {
	displayName = "WoodBoard";
	input[] = 
	{
		{"PartWoodPile","CfgMagazines",1},
	};
	output[] = 
	{
		{"Viruz_Woodboard","CfgMagazines",2}
	};
	required[] = 
	{
			{"Viruz_Serrote","CfgMagazines",1}
	};
};