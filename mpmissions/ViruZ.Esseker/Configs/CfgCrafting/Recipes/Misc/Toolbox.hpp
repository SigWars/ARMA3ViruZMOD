class Blueprint_craft_ItemToolbox : Recipe {
	displayName = "Toolbox";
	input[] = 
	{
		{"Viruz_Hammer","CfgMagazines",1},
		{"Viruz_Serrote","CfgMagazines",1},
		{"Viruz_Wrench","CfgMagazines",1},
		{"ItemWire","CfgMagazines",1}
	};
	output[] = 
	{
		{"ItemToolbox","CfgWeapons",1}
	};
	required[] = 
	{
	};
};