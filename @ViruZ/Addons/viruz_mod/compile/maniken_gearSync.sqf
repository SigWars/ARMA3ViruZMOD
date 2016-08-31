/*
	Author: SigWar
*/

	private ["_Object","_magazineArray"];
	_Object = _this;
	_DataArray = [];
	
	_ManikenGear = [
		uniform _Object,
		vest _Object
//		headgear _Object,
//		goggles _Object
	];
	
	// Обработать данные о магазинах
	_magazines = magazinesAmmoFull _Object;
	_magazineArray = [];
	{
		_max = 	getNumber (configFile >> "CfgMagazines" >> (_x select 0) >> "count");
		_val = _x select 1;
	
		if (_val != _max) then {
			_magazineArray set [count _magazineArray,[_x select 0, _x select 1]];
		} else {
			_magazineArray set [count _magazineArray, _x select 0];
		};	
	} forEach _magazines;

	// Обработка данных о предметах
	_uniformItems = (uniformItems _Object);
	{
		_isOK = isClass(configFile >> "CfgMagazines" >> _x); // Исключаем класс магазины
		if (!_isOK) then {
			_magazineArray set [count _magazineArray, _x];
		};
	} forEach _uniformItems;
	
	_vestItems = (vestItems _Object);
	{
		_isOK = isClass(configFile >> "CfgMagazines" >> _x); // Исключаем класс магазины
		if (!_isOK) then {
			_magazineArray set [count _magazineArray, _x];
		};
	} forEach _vestItems;
	
	if (count _magazineArray > 0) then {	// Если в униформе или обвесе остались предметы, перемещяем их обратно клиенту
		
		if (count _uniformItems > 0) then {		// Предметы в униформе ?
			
			// для корректной синхронизации нужно снова добавить униформу клиенту
			_UniformPlayer = uniform player;
			player addUniform _UniformPlayer;
			
			// удаляем униформу с маникена, будет восстановлена позже методом BIS_fnc_MP
			removeUniform _Object;
			
		} else {								// Значит предметы в обвесе
			
			_VestPlayer = vest player;
			player addVest _VestPlayer;
			
			removeVest _Object;
			
		};
		
		// восстанавливаем предметы в инвенторе клиента
		{
			private ["_x","_item","_val","_isOK"];

			if (typeName _x == "ARRAY") then {
				_item = _x select 0;
				_val = 	_x select 1;
			} else {
				_item = _x;
				_val = -1;
			};

			_isOK = isClass(configFile >> "CfgMagazines" >> _item);

			if (_isOK) then {
				if (_val != -1) then {
					Player addMagazine [_item,_val];
				} else {
					Player addMagazine _item;
				};			
			} else {
				Player addItem _item;
			};

		} foreach _magazineArray;

	};
	
//	systemChat format["%1", "Maniken Gear : " + str(_ManikenGear)];

	_DataArray = [_ManikenGear,_Object];
	_DataArray