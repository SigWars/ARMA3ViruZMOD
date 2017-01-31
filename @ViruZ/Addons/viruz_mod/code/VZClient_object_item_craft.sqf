private["_getcraftingClassName","_quantityToCraft","_quantityCrafted","_metSideConditions","_recipeConfig","_sfx","_anim","_returnedItems","_interactionModelGroupClassName","_components","_tools","_cfgtype","_equippedMagazines","_addedItems","_concreteMixer","_toolItemClassName","_equippedToolQuantity","_interactionModelGroupModels","_foundObject","_i","_hasAllComponents","_componentQuantity","_componentItemClassName","_equippedComponentQuantity","_returnedItemQuantity","_returnedItemClassName","_feedbackMessage","_returnedItemName","_nearByPile","_itemOut","_sfx","_RetiredSize","_cansGear","_maxCount","_qtyCans"];
_getcraftingClassName = _this select 0;
_quantityToCraft = _this select 1;
_quantityCrafted = 0;
_metSideConditions = true;
_recipeConfig = missionConfigFile >> "CfgCrafting" >> _getcraftingClassName;
_sfx = getText(_recipeConfig >> "sound");
_anim = getText(_recipeConfig >> "moveaction");
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
	};
	
	if !(_foundObject) then {
		_metSideConditions = false;
	};
};
if (_metSideConditions) then {
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
		}forEach _components;
		
			if (_hasAllComponents) then	{
				
				//Play animation
				if !(_anim == "") then {
					player playActionNow _anim;
				};
				//Play sound
				if !(_sfx == "") then {
					[player,_sfx,0,false,5] call viruz_zombieSpeak;
				};
			
					{
						_componentQuantity = _x select 0;
						_componentItemClassName = _x select 1;
						
						for "_i" from 1 to _componentQuantity do 
						{
							_RetiredSize = getNumber(configFile >> "CfgMagazines" >> _componentItemClassName >> "RetiredSize");
							if (_RetiredSize > 0) then {
							
							_cansGear = [_componentItemClassName, player] call PTm_fnc_filterGear;
							_maxCount = getNumber (configFile >> "CfgMagazines" >> _componentItemClassName >> "count");
							_qtyCans = _cansGear select 0 select 1;
							
							if(_qtyCans > 0) then{
								_qtyCans = _qtyCans - _RetiredSize;
								
								player removeItem _componentItemClassName;
								
								_nearByPile= nearestObjects [getPosATL player, ["GroundWeaponHolder"],2];
								
								if (count _nearByPile == 0) then { 
									_itemOut = createVehicle ["GroundWeaponHolder", getPosATL player, [], 1, "CAN_COLLIDE"];
								if ( isClass (configFile >> "CfgMagazines" >> _componentItemClassName)) then {
									_itemOut addMagazineAmmoCargo [_componentItemClassName, 1, _qtyCans];
								};
									player reveal _itemOut;
								}else{
								
									_itemOut = _nearByPile select 0;
								if ( isClass (configFile >> "CfgMagazines" >> _componentItemClassName)) then {
									_itemOut addMagazineAmmoCargo [_componentItemClassName, 1, _qtyCans];
								};
									player reveal _itemOut;	
								};	
								
								//hint format ["_cansGear: %1  |  _qtyCans: %2",_cansGear,_qtyCans];
							};
						
							}else{
							
								player removeItem _componentItemClassName;
							};
						};
					}forEach _components;
					
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
					}forEach _returnedItems;
						//Chamar Som
					_quantityCrafted = _quantityCrafted + 1;
				};
			};
		};

if (_quantityCrafted > 0) then {	
		_txt = "";  
		{
			_nameitem =  _x select 0;
			_cfgtype = _nameitem call ViruZClient_gear_getConfigNameByClassName;
			_returnedItemName = getText(configFile >> _cfgtype >> _nameitem >> "displayName");

			_slct = parseText format["<t color='#FFFFFF'>%1 %2 Crafted</t>",_x select 1,_returnedItemName];
			_txt = format["%1 <br/> %2",_txt,_slct];
	
		}forEach _addedItems;
		
		hint parseText format["<t color='#0040FF'>Crafting completed!</t><br/><t color='#FFFFFF'>%1</t>",_txt];

	}else{
		cutText [format["Failed to craft!"], "PLAIN DOWN"];
	};
	[["Item1", ["My","Array","Elements"]],["Item2",["Smell","Like","Fromage"]]];
true