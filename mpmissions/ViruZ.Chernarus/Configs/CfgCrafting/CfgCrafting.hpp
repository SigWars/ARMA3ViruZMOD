class CfgCrafting
{
	
	class ViruZ_ResumoCrafting
	{
			displayName = "";
			pictureItem = ""; 
			returnedItems[] = {};
			componentes[] = {}; 
			ferramentas[] = {};
	};
	
	class Blueprint_Hatchet: ViruZ_ResumoCrafting
	{
		displayName = "Hatchet";
		pictureItem = "MeleeHatchet"; //Classe do Item para chamar a imagem
		returnedItems[] =
		{
			{1, "MeleeHatchet"}
		};
		ferramentas[] =
		{
			"Viruz_Hammer"
		};
		componentes[] = 
		{
			{1, "PartWoodPile"},
			{1, "equip_nails"},
			{1, "Viruz_Wrench"}
		};
	};
	
	class Blueprint_Rangefinder: ViruZ_ResumoCrafting
	{
		displayName = "Rangefinder";
		pictureItem = "Rangefinder"; //Classe do Item para chamar a imagem
		returnedItems[] =
		{
			{1, "Rangefinder"}
		};
		ferramentas[] =
		{
			"Viruz_Wrench"
		};
		componentes[] = 
		{
			{1, "Viruz_HandCan"},
			{2, "Battery_mag"},
			{1, "Viruz_MobilePhone"}
		};
	};
	
	class Blueprint_Toolbox: ViruZ_ResumoCrafting
	{
		displayName = "Toolbox";
		pictureItem = "ItemToolbox"; //Classe do Item para chamar a imagem
		returnedItems[] =
		{
			{1, "ItemToolbox"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "Viruz_Hammer"},
			{1, "Viruz_Serrote"},
			{1, "Viruz_Wrench"},
			{1, "ItemWire"},
			{1, "Viruz_Maleta"}
		};
	};
	
	class Blueprint_Gps: ViruZ_ResumoCrafting
	{
		displayName = "GPS";
		pictureItem = "ItemGPS"; //Classe do Item para chamar a imagem
		returnedItems[] =
		{
			{1, "ItemGPS"}
		};
		ferramentas[] =
		{
			"Viruz_Wrench"
		};
		componentes[] = 
		{
			{1, "Viruz_Laptop"},
			{5, "Battery_mag"}
		};
	};
	
	class Blueprint_WoodBoard: ViruZ_ResumoCrafting
	{
		displayName = "WoodBoard";
		pictureItem = "Viruz_Woodboard"; //Classe do Item para chamar a imagem
		returnedItems[] =
		{
			{2, "Viruz_Woodboard"}
		};
		ferramentas[] =
		{
			"Viruz_Serrote"
		};
		componentes[] = 
		{
			{1, "PartWoodPile"}
		};
	};
	
};