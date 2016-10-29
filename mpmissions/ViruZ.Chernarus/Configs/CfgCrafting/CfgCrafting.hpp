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
	
	class Toolbox: ViruZ_ResumoCrafting
	{
		displayName = "Toolbox";
		pictureItem = "ItemToolbox"; //Classe do Item para chamar a imagem
		returnedItems[] =
		{
			{1, "ItemToolbox"}
		};
		ferramentas[] =
		{
			"Viruz_Maleta"
		};
		componentes[] = 
		{
			{1, "Viruz_Hammer"},
			{1, "Viruz_Serrote"},
			{1, "Viruz_Wrench"},
			{1, "ItemWire"}
		};
	};
	
};