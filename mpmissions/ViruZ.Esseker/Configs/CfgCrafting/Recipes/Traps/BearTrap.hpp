class Blueprint_TrapTripwireSmoke : Recipe {
	displayName = $STR_ITEM_NAME_BEARTRAP;
	descriptionShort = $STR_ITEM_DESC_TRIPWIRE_SMOKE;
	input[] =
	{
		{"PartGeneric","CfgMagazines",2},
		{"ItemWire","CfgMagazines",1},
		{"equip_nails","CfgMagazines",1},
	};
	output[] =
	{
		{"TrapBear","CfgMagazines",1}
	};
	required[] =
	{
		{"Viruz_Hammer","CfgMagazines",1}
	};
};
