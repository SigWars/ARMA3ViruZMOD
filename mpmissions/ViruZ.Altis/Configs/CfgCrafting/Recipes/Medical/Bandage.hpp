class Blueprint_Craft_Bandage : Recipe {
	displayName = $STR_CRAFT_NAME_Bandage;
	descriptionShort = $STR_CRAFT_DESC_Bandage;
	input[] = 
	{
		{"rb_bandage","CfgMagazines",2}
	};
	output[] = 
	{
		{"ItemBandage","CfgMagazines",1}
	};
	required[] = 
	{
	};
};