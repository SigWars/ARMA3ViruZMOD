private["_getcraftingClassName","_quantityToCraft","_quantityCrafted","_metSideConditions","_recipeConfig","_returnedItems","_interactionModelGroupClassName","_components","_tools","_equippedMagazines","_addedItems","_concreteMixer","_toolItemClassName","_equippedToolQuantity","_interactionModelGroupModels","_foundObject","_i","_hasAllComponents","_componentQuantity","_componentItemClassName","_equippedComponentQuantity","_returnedItemQuantity","_returnedItemClassName","_feedbackMessage","_returnedItemName","_nearByPile","_itemOut"];
_getcraftingClassName = _this select 0;
_quantityToCraft = _this select 1;
_quantityCrafted = 0;
_metSideConditions = true;
_recipeConfig = missionConfigFile >> "CfgCrafting" >> _getcraftingClassName;
_returnedItems = getArray(_recipeConfig >> "returnedItems");
_interactionModelGroupClassName = getText(_recipeConfig >> "requiredInteractionModelGroup");
_components = getArray(_recipeConfig >> "componentes");
_tools = getArray(_recipeConfig >> "ferramentas");
_equippedMagazines = magazines player;
_addedItems = [];
_concreteMixer = objNull;
{
	_toolItemClassName = _x;
	_equippedToolQuantity = { _x == _toolItemClassName } count _equippedMagazines;
	if (_equippedToolQuantity == 0 ) then
	{
		_metSideConditions = false;
	};
}
forEach _tools;

/*
if ( getNumber(_recipeConfig >> "requiresOcean") == 1 ) then
{
	if !(surfaceIsWater getPos player) then 
	{
		_metSideConditions = false;
	};
};

if ( getNumber(_recipeConfig >> "requiresConcreteMixer") == 1 ) then //FUTUROOOOOOOOOOOOOOOOOOO
{
	_concreteMixer = (ASLtoAGL (getPosASL player)) call ExileClient_util_world_getNearestConcreteMixer;
	if (isNull _concreteMixer) then 
	{
		_metSideConditions = false;
	};
};
*/

if ( getNumber(_recipeConfig >> "requiresFire") == 1 ) then
{
	if !([player, 4] call VZClient_util_world_isFireInRange) then 
	{
		_metSideConditions = false;
	};
};

if( _interactionModelGroupClassName != "" ) then
{
	_interactionModelGroupModels = getArray(missionConfigFile >> worldname >> _interactionModelGroupClassName >> "models");
	_foundObject = false;
	if ([ASLtoAGL (getPosASL player), 10, _interactionModelGroupModels] call VZClient_util_model_isNearby) then
	{
		_foundObject = true;	
	}
	else 
	{
		if ( _interactionModelGroupModels call VZClient_util_model_isLookingAt ) then
		{
			_foundObject = true;
		};
	};
	if !(_foundObject) then
	{
		_metSideConditions = false;
	};
};
if (_metSideConditions) then
{
	for "_i" from 1 to _quantityToCraft do 
	{
		_hasAllComponents = true;
		{
			_componentQuantity = _x select 0;
			_componentItemClassName = _x select 1;
			_equippedComponentQuantity = { _x == _componentItemClassName } count _equippedMagazines;
			if (_equippedComponentQuantity < _componentQuantity ) then
			{
				_hasAllComponents = false;
			};
		}
		forEach _components;
		if (_hasAllComponents) then
		{
		/*
			if !(isNull _concreteMixer) then 
			{
				["concreteMixerStartRequest", [netId _concreteMixer, _getcraftingClassName]] call ExileClient_system_network_send;
				_quantityCrafted = -1; 
			}
			
			else 
			{
			*/
			//	if ([_components, _returnedItems] call VZClient_util_inventory_canExchangeItems) then
			//	{
					{
						_componentQuantity = _x select 0;
						_componentItemClassName = _x select 1;
						for "_i" from 1 to _componentQuantity do 
						{
							player removeItem _componentItemClassName;
						};
					}
					forEach _components;
					{
						_returnedItemQuantity = _x select 0;
						_returnedItemClassName = _x select 1;
						_addedItems = [_addedItems, _returnedItemClassName, _returnedItemQuantity] call BIS_fnc_addToPairs;
						
						
						_nearByPile= nearestObjects [getPosATL player, ["GroundWeaponHolder"],2];
						if (count _nearByPile == 0) then { 
							_itemOut = createVehicle ["GroundWeaponHolder", getPosATL player, [], 1, "CAN_COLLIDE"];
						if ( isClass (configFile >> "CfgWeapons" >> _returnedItemClassName)) then {
								_itemOut addWeaponCargoGlobal [_returnedItemClassName,_returnedItemQuantity];
						};
						if ( isClass (configFile >> "CfgMagazines" >> _returnedItemClassName)) then {
								_itemOut addMagazineCargoGlobal [_returnedItemClassName,_returnedItemQuantity];
						};
							player reveal _itemOut;
							
						}else{
						
						_itemOut = _nearByPile select 0;
						if ( isClass (configFile >> "CfgWeapons" >> _returnedItemClassName)) then {
								_itemOut addWeaponCargoGlobal [_returnedItemClassName,_returnedItemQuantity];
						};
						if ( isClass (configFile >> "CfgMagazines" >> _returnedItemClassName)) then {
								_itemOut addMagazineCargoGlobal [_returnedItemClassName,_returnedItemQuantity];
						};
							player reveal _itemOut;	
						};
							//player addItem _returnedItemClassName;
					} 
					forEach _returnedItems;
					_quantityCrafted = _quantityCrafted + 1;
				};
			//};
		//};
	};
};
if (_quantityCrafted > -1) then 
{
	if (_quantityCrafted > 0) then
	{	
		//_feedbackMessage = "";
		{
			_returnedItemClassName = _x select 0;
			_returnedItemQuantity = _x select 1;
			_returnedItemName = getText(configFile >> "CfgMagazines" >> _returnedItemClassName >> "displayName");
			
			/*
			if (_feedbackMessage != "") then 
			{
				_feedbackMessage = _feedbackMessage + "<br/>";
			};
			_feedbackMessage = _feedbackMessage + format ["+%1x %2", _returnedItemQuantity, _returnedItemName];*/
		}
		forEach _addedItems;
		cutText [format["Crafting completed! %1 %2 Crafted",_returnedItemQuantity,_returnedItemName], "PLAIN DOWN"];
	}
	else 
	{
		cutText [format["Failed to craft!"], "PLAIN DOWN"];
	};
};
true