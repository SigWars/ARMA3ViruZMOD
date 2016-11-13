class CfgCrafting
{
	class ViruZ_ResumoCrafting
	{
			sound ="repair";
			moveaction ="Medic";
			displayName = "";
			pictureItem = ""; 
			returnedItems[] = {};
			requiresFire = 0;
			componentes[] = {}; 
			ferramentas[] = {};
			requiredInteractionModelGroup = "";
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
	
	class Blueprint_WaterBottle: ViruZ_ResumoCrafting
	{
		displayName = "Water Bottle";
		pictureItem = "ItemWaterbottle"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "ItemWaterbottle"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "ItemWaterbottleBoiled"}
		};
	};
	
	class Blueprint_FoodSteakCooked: ViruZ_ResumoCrafting
	{
		displayName = "Food Steak Cooked";
		pictureItem = "FoodSteakCooked"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "FoodSteakCooked"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "FoodSteakRaw"}
		};
	};
	
	class Blueprint_FoodmeatCooked: ViruZ_ResumoCrafting
	{
		displayName = "Food Meat Cooked";
		pictureItem = "FoodmeatCooked"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "FoodmeatCooked"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "FoodmeatRaw"}
		};
	};
	
	class Blueprint_FishCookedTrout: ViruZ_ResumoCrafting
	{
		displayName = "Fish Cooked Trout";
		pictureItem = "FishCookedTrout"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "FishCookedTrout"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "FishRawTrout"}
		};
	};
	
	class Blueprint_FishCookedSeaBass: ViruZ_ResumoCrafting
	{
		displayName = "Fish Cooked SeaBass";
		pictureItem = "FishCookedSeaBass"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "FishCookedTrout"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "FishRawSeaBass"}
		};
	};
	
	class Blueprint_FishCookedTuna: ViruZ_ResumoCrafting
	{
		displayName = "Fish Cooked Tuna";
		pictureItem = "FishCookedTuna"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "FishCookedTuna"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "FishRawTuna"}
		};
	};
	
	class Blueprint_FoodmuttonCooked: ViruZ_ResumoCrafting
	{
		displayName = "Food Mutton Cooked";
		pictureItem = "FoodmuttonCooked"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "FoodmuttonCooked"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "FoodmuttonRaw"}
		};
	};
	
	class Blueprint_FoodchickenCooked: ViruZ_ResumoCrafting
	{
		displayName = "Food Chicken Cooked";
		pictureItem = "FoodchickenCooked"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "FoodchickenCooked"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "FoodchickenRaw"}
		};
	};
	
	class Blueprint_FoodbaconCooked: ViruZ_ResumoCrafting
	{
		displayName = "Food Bacon Cooked";
		pictureItem = "FoodbaconCooked"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "FoodbaconCooked"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "FoodbaconRaw"}
		};
	};
	
	class Blueprint_FoodrabbitCooked: ViruZ_ResumoCrafting
	{
		displayName = "Food Rabbit Cooked";
		pictureItem = "FoodrabbitCooked"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "FoodrabbitCooked"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "FoodrabbitRaw"}
		};
	};
	
	class Blueprint_FoodbeefCooked: ViruZ_ResumoCrafting
	{
		displayName = "Food Beef Cooked";
		pictureItem = "FoodbeefCooked"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "FoodbeefCooked"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "FoodbeefRaw"}
		};
	};
	
	class Blueprint_ItemJerrycan: ViruZ_ResumoCrafting
	{
		displayName = "Fill Jerrycan";
		pictureItem = "ItemJerrycan"; //Classe do Item para chamar a imagem
		requiredInteractionModelGroup = "FuelSource";
		returnedItems[] =
		{
			{1, "ItemJerrycan"}
		};
		ferramentas[] =
		{
			
		};
		componentes[] = 
		{
			{1, "ItemJerrycanEmpty"}
		};
	};
	
	class Blueprint_CementBag: ViruZ_ResumoCrafting
	{
		displayName = "Cement Bag";
		pictureItem = "Viruz_CementBag"; //Classe do Item para chamar a imagem
		returnedItems[] =
		{
			{1, "Viruz_CementBag"}
		};
		ferramentas[] =
		{
			"ItemEtool"
		};
		componentes[] = 
		{
			{5, "Viruz_Rock"},
			{3, "Viruz_Clinquer"},
			{1, "Viruz_CardBoardBox"}
		};
	};
	
	class Blueprint_CinderBlockMold: ViruZ_ResumoCrafting
	{
		displayName = "CinderBlock Mold";
		pictureItem = "Viruz_CinderBlockMold"; //Classe do Item para chamar a imagem
		returnedItems[] =
		{
			{1, "Viruz_CinderBlockMold"}
		};
		ferramentas[] =
		{
			"Viruz_Hammer",
			"Viruz_Serrote"
			
		};
		componentes[] = 
		{
			{2, "Viruz_Woodboard"},
			{1, "equip_nails"}
		};
	};
	
	class Blueprint_IronBar: ViruZ_ResumoCrafting
	{
		displayName = "IronBar";
		pictureItem = "Viruz_IronBar"; //Classe do Item para chamar a imagem
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "Viruz_IronBar"}
		};
		ferramentas[] =
		{
			"Viruz_Hammer",
			"Viruz_Pliers",
			"Viruz_Grinder",
			"Viruz_Gloves"
		};
		componentes[] = 
		{
			{4, "PartGeneric"}
		};
	};
	
	class Blueprint_Test: ViruZ_ResumoCrafting
	{

		displayName = "Test";
		pictureItem = "Viruz_CinderBlockMold"; //Classe do Item para chamar a imagem
		returnedItems[] =
		{
			{1, "Viruz_CinderBlockMold"},
			{1, "Viruz_Antiseptic"}
		};
		ferramentas[] =
		{			
			
		};
		componentes[] = 
		{
			{1, "Viruz_Antiseptic"}
		};
	};
	
	
};