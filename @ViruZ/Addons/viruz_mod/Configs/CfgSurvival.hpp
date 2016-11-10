class CfgSurvival {

	class Meat {
		class Default {
			yield = 2;
			rawfoodtype = "FoodmeatRaw";
		};
		class Fowl_Base_F: Default { //мясо птицы
			yield = 2;
			rawfoodtype = "FoodmeatRaw";
		};
		class Cock_random_F: Default { //петух
			yield = 2;
			rawfoodtype = "FoodmeatRaw";
		};
		class Goat_Base_F: Default { //сам козел базовый класс на всякий пожарный
			yield = 3;
			rawfoodtype = "FoodmeatRaw";
		};
		class Sheep_random_F: Default { //овца
			yield = 3;
			rawfoodtype = "FoodmeatRaw";
		};
		class Goat_random_F: Default { //еще козел
			yield = 3;
			rawfoodtype = "FoodmeatRaw";
		};
		class Snake_random_F: Default { // змея
			yield = 1;
			rawfoodtype = "FoodmeatRaw";
		};
		class Goat_small_random_F: Default { // еще козел
			yield = 3;
			rawfoodtype = "FoodmeatRaw";
		};
		class Hen_random_F: Default { //курица
			yield = 2;
			rawfoodtype = "FoodmeatRaw";
		};
		class Rabbit_F: Default { // кролик
			yield = 1;
			rawfoodtype = "FoodmeatRaw";
		};
	};
};