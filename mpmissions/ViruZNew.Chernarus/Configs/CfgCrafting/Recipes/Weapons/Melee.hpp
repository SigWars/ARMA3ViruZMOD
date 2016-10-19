class Blueprint_Machado : Recipe {
	displayName = "Hatchet";
	input[] = 
	{
		{"PartWoodPile","CfgMagazines",1},
		{"equip_nails","CfgMagazines",1},
		{"PartGeneric","CfgMagazines",1}
	};
	output[] = 
	{
		{"MeleeHatchet","CfgWeapons",1}
	};
	required[] = 
	{
	};
};