params["_o","_u","_m","_a"];

if(_m isEqualTo 0)then{

	if(!(isPlayer _u))exitWith{};
	_this spawn
	{
		params["_o","_u","_m","_a"];

		rds_cargo_action=true;

		private _backpack = backpack _u;
		private _backpacks = getBackpackCargo _o;
		private _items = getItemCargo _o;

		private _backpacksNew = _backpacks;
		private _itemsNew = _items;

		private _t1 = [];
		private _t2 = [];
		private _i = 0;
		private _i2 = "";

		while{not(isnil "rds_cargo_action")}do
		{
			if(! (_backpacksNew isEqualTo _backpacks))then{
				_t1 = _backpacks select 0;
				_t2 = _backpacksNew select 0;
				_i2="";

				if( count (_t2-_t1)!=0 or count (_t1-_t2)!=0)then{
				//systemChat "porownanie 1";
					if(count _t1 > count _t2)then{
						_i = _t1 - _t2;
						_t1 = _backpacks select 1;
						_t2 = _backpacksNew select 1;
						if(_backpack != "")then{_i2=backpack _u};
						//systemChat format["dodano %1 wymieniono?: %2 %3",_i select 0,_i2];
						_o addMagazine format["%1_proxy",_i select 0 ];
						_o removeMagazine format["%1_proxy",_i2];
					}else{
						_i = _t2 - _t1;
						_t1 = _backpacks select 1;
						_t2 = _backpacksNew select 1;
						if(_backpack != "")then{_i2=_backpack};
						//systemChat format["zabrano %1 wymieniono?: %2 %3",_i,_i2];
						_o removeMagazine format["%1_proxy",_i select 0 ];
						_o addMagazine format["%1_proxy",_i2];
					};
					_backpacksNew=_backpacks;
					_backpack = backpack _u;
				}else{
					_t1 = _backpacks select 1;
					_t2 = _backpacksNew select 1;
					_i = 0;

					if(count _t1 == 0 )then{_t1=[0]};
					if(count _t2 == 0 )then{_t2=[0]};
					{if( not(_x isEqualTo (_t2 select _forEachIndex)))exitWith{_i=_forEachIndex;}}foreach _t1;


					if(_t1 select _i > _t2 select _i)then{
						//systemChat format["dodano %1 wymieniono na: %2",_backpacks select 0 select _i,backpack _u];
						_o addMagazine format["%1_proxy",_backpacks select 0 select _i];
					}else{
						_i2=_backpacks;
						if(count _backpacks == 0)then{_i2=_backpacksNew;};
						//systemChat format["zabrano %1 wymieniono na: %2",_i2 select 0 select _i,_backpack];
						_o removeMagazine format["%1_proxy",_i2 select 0 select _i];
						_o addMagazine format["%1_proxy",_backpack];
					};
					_backpack = backpack _u;
				};
				_backpacksNew=_backpacks
			};


			if(! (_itemsNew isEqualTo _items) )then{
				_t1 = _items select 0;
				_t2 = _itemsNew select 0;

				if( !(_t1 isEqualTo _t2))then{
					if(count _t1 > count _t2)then{
						_i = _t1 - _t2;
						//systemChat format["dodano %1",_i select 0];
						_o addMagazine format["%1_proxy",_i select 0];
					}else{
						_i = _t2 - _t1;
						//systemChat format["zabrano %1",_i select 0];
						_o removeMagazine format["%1_proxy",_i select 0];
					};
					_itemsNew=_items;
				}else{
					_t1 = _items select 1;
					_t2 = _itemsNew select 1;

					{if( not(_x isEqualTo (_t2 select _forEachIndex)))exitWith{_i=_forEachIndex;}}foreach _t1;

					if(_t1 select _i > _t2 select _i)then{
						//systemChat format["dodano %1",_items select 0 select _i];
						_o addMagazine format["%1_proxy",_items select 0 select _i];
					}else{
						//systemChat format["zabrano %1",_items select 0 select _i];
						_o removeMagazine format["%1_proxy",_items select 0 select _i];
					};
				};

				_itemsNew=_items;
			};

			_backpacks = getBackpackCargo _o;
			_items = getItemCargo _o;

			sleep 0.01;
		};
	};
};

if(_u in _o)exitWith{};

if(_m isEqualTo 0)then{
	_o animateDoor [_a,1];
}else{
	_o animateDoor [_a,0];
	if(isPlayer _u)then{rds_cargo_action=nil};
};