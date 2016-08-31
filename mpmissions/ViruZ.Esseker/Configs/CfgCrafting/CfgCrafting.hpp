class CfgCrafting {
	class Recipe {
		displayName = "Generic Recipe";
		input[] = {}; //Items consumed during crafting
		output[] = {}; //Items created from crafting
		required[] = {}; //Items needed for but not consumed during crafting
		failChance = 0;
	};
	//Medical
	//#include "Recipes\Medical\Bandage.hpp"
	
	//Traps
	#include "Recipes\Traps\BearTrap.hpp"
	
	//Weapons
	#include "Recipes\Weapons\Melee.hpp"
	
	//acessorios
	#include "Recipes\Misc\RangeFinder.hpp"
	#include "Recipes\Misc\Toolbox.hpp"
	#include "Recipes\Misc\ItemGPS.hpp"
	
	//Build
	#include "Build\Wooden_plank.hpp"
	
	/*
	data[] = {
		{{Item_1, count item},{Item_2,count item}, ...}, output, time, isWorkbench
	};
	
	{{Item_1, count item},{Item_2,count item}, ...} - List of items and the number of required for crafting
	output											- Class object obtained after crafting
	time											- Time needed for crafting, in seconds
	isWorkbench										- Do I need to be near the bench, 0 - no, 1 - yes
	
	*/
		
		class Survival {
		
			name = $STR_CRAFTING_ITEMS_FILTER_SURVIVAL;

			class CampFire {
//				name = $STR_ITEMS_LIST_CAMPFIRE;
				data[] = {
					{{"itemWood",5}},"Land_FirePlace_F",10,0
				};
			};
			class SleepingBag {
//				name = $STR_ITEMS_LIST_SLEEPINGBAG;
				data[] = {
					{{"itemCloth",15}},"itemSleepingBag",30,0
				};
			};
			class WoodStorageBox {
//				name = $STR_ITEMS_LIST_WOODSTORAGEBOX;
				data[] = {
					{{"itemWood",30}},"Land_WoodStorageBox",60,0
				};
			};
			class LowGradeFuel {
				name = $STR_ITEMS_LIST_LOWGRADEFUEL;
				data[] = {{"itemAnimalFat",2},{"itemCloth",1}};
			};
			class Workbench {
				name = $STR_ITEMS_LIST_WORKBENCH;
				data[] = {{"itemStones",8},{"itemWood",50}};
			};
			class Furnace {
				name = $STR_ITEMS_LIST_FURNACE;
				data[] = {{"itemStones",15},{"itemWood",20},{"itemLowGradeFuel",10}};
				output = "itemFurnace";
			};
			class LowQualityMetal {
				name = $STR_ITEMS_LIST_LOWQUALITYMETAL;
				data[] = {{"itemMetalFragments",15}};
				output = "itemLowQualityMetal";
				isWorkbench = 1;
			};
		};
		
		class Resource {
		
			name = $STR_CRAFTING_ITEMS_FILTER_RESOURCE;
			
			class Resource_base {
				isWorkbench = 0;
			};
			class Gunpowder {
//				name = $STR_ITEMS_LIST_GUNPOWDER;
				data[] = {{"itemCharcoal",2},{"itemSulfur",2}};
				output = "itemGunpowder";
			};
			class WoodPlanks {
//				name = $STR_ITEMS_LIST_WOODPLANKS;
				data[] = {{"itemWood",10}};
				output = "itemWoodPlanks";
			};
		};
};