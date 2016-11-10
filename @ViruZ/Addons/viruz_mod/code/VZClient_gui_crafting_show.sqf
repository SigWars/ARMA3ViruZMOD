private["_getcraftingClassName","_craftingConfig","_craftname","_imagemItemClassName","_cfgType","_craftingImagem","_OkCrafting","_CraftingQuantidade","_getItemMagazine","_componentes","_returnedItems","_ferramentas","_dialog","_description","_getcomponenteQuantity","_getcomponenteItemClassName","_getcomponenteItemName","_equippedComponentQuantity","_ferramentasItemClassName","_ferramentasItemName","_equippedferramentasQuantity","_interactionModelGroupClassName","_interactionModelGroupName","_interactionModelGroupModels","_foundObject","_listBoxIndex","_interactionModelGroupConfig"];

//Classes
_getcraftingClassName = _this;
_craftingConfig = missionConfigFile >> "CfgCrafting" >> _getcraftingClassName;
_craftname = getText(_craftingConfig >> "displayName");
_imagemItemClassName = getText(_craftingConfig >> "pictureItem");

_cfgType = _imagemItemClassName call ViruZClient_gear_getConfigNameByClassName;
_craftingImagem = getText(configFile >> _cfgType >> _imagemItemClassName >> "picture");

_OkCrafting = true;
_CraftingQuantidade = 99999;
_getItemMagazine = magazines player;
_componentes = getArray(_craftingConfig >> "componentes");
_returnedItems = getArray(_craftingConfig >> "returnedItems");
_ferramentas = getArray(_craftingConfig >> "ferramentas");

createDialog "RscDisplayShowCraftingDialog";
waitUntil { !isNull findDisplay 200000 };
uiNameSpace setVariable ["RscCraftingClassName", _getcraftingClassName];
_dialog = uiNameSpace getVariable ["RscDisplayShowCraftingDialog", displayNull];



_description = format["<t size='1.5'  align='left'>%1</t><br/><br/>", _craftname];
{
	_getcomponenteQuantity = _x select 0;
	_getcomponenteItemClassName = _x select 1;
	_getcomponenteItemName = getText(configFile >> "CfgMagazines" >> _getcomponenteItemClassName >> "displayName");
	_equippedComponentQuantity = { _x == _getcomponenteItemClassName } count _getItemMagazine;
	_description = _description + format["<t size='1'  align='left'>%1</t>", _getcomponenteItemName];
	_CraftingQuantidade = _CraftingQuantidade min (floor (_equippedComponentQuantity / _getcomponenteQuantity));
	if (_equippedComponentQuantity < _getcomponenteQuantity ) then
	{
		_OkCrafting = false;
		_description = _description + format["<t size='1'  align='right' color='%1'>%2/%3</t>", "#ea0000", _equippedComponentQuantity, _getcomponenteQuantity];
	}
	else
	{ 
		_description = _description + format["<t size='1'  align='right' color='%1'>%2/%3</t>", "#b2ec00", _equippedComponentQuantity, _getcomponenteQuantity];
	};
	_description = _description + "<br/>";
}forEach _componentes;

{
	_ferramentasItemClassName = _x;
	_ferramentasItemName = getText(configFile >> "CfgMagazines" >> _ferramentasItemClassName >> "displayName");
	_equippedferramentasQuantity = { _x == _ferramentasItemClassName } count _getItemMagazine;
	_description = _description + format["<t size='1'  align='left'>%1</t>", _ferramentasItemName];
	if (_equippedferramentasQuantity == 0 ) then {
		_description = _description + format["<t size='1'  align='right' color='%1'>%2</t>", "#ea0000", "NOT EQUIPPED"];
		_OkCrafting = false;
	}else{ 
		_description = _description + format["<t size='1'  align='right' color='%1'>%2</t>", "#b2ec00", "EQUIPPED"];
	};
	_description = _description + "<br/>";
}forEach _ferramentas;

if ( getNumber(_craftingConfig >> "requiresFire") == 1 ) then
{
	_description = _description + format["<t size='1' font='puristaMedium' align='left'>%1</t>", "Fire"];
	if( [player, 4] call VZClient_util_world_isFireInRange ) then 
	{
		_description = _description + format["<t size='1' font='puristaMedium' align='right' color='%1'>%2</t>", "#b2ec00", "FOUND"];
	}else{
		_description = _description + format["<t size='1' font='puristaMedium' align='right' color='%1'>%2</t>", "#ea0000", "NOT FOUND"];
		_OkCrafting = false;
	};
	_description = _description + "<br/>";
};
_interactionModelGroupClassName = getText(_craftingConfig >> "requiredInteractionModelGroup");
if ( _interactionModelGroupClassName != "" ) then {	
	_interactionModelGroupConfig = missionConfigFile >> worldname >> _interactionModelGroupClassName;
	_interactionModelGroupName = getText(_interactionModelGroupConfig >> "name");
	_interactionModelGroupModels = getArray(_interactionModelGroupConfig >> "models");
	_description = _description + format["<t size='1'  align='left'>%1</t>", _interactionModelGroupName];
	_foundObject = false;
	if ([ASLtoAGL (getPosASL player), 10, _interactionModelGroupModels] call VZClient_util_model_isNearby) then
	{
		_foundObject = true;	
	};
	/*
	else 
	{
		if ( _interactionModelGroupModels call VZClient_util_model_isLookingAt) then
		{
			_foundObject = true;
		};
	};
	*/
	if (_foundObject) then {
		_description = _description + format["<t size='1'  align='right' color='%1'>%2</t>", "#b2ec00", "FOUND"];
	}else{
		_description = _description + format["<t size='1'  align='right' color='%1'>%2</t>", "#ea0000", "NOT FOUND"];
		_OkCrafting = false;
	};
	_description = _description + "<br/>";
};

/*
if !([_componentes, _returnedItems] call VZClient_util_inventory_canExchangeItems) then
{
	_OkCrafting = false;
	_description = _description + format["<br/><t size='1'  align='left' color='%1'>%2</t>", "#ea0000", "Your inventory is full."];
};
*/

if( _OkCrafting ) then {
	switch (_CraftingQuantidade) do
	{
		case 1:	{
			_description = _description + format["<br/><t size='1' align='left' color='%1'>%2</t>", "#b2ec00", "You can craft this item once."];
		};
		case 99999:	{
			_description = _description + format["<br/><t size='1'  align='left' color='%1'>%2</t>", "#b2ec00", "You can craft this item whenever you like."];
			_CraftingQuantidade = 10; 
		};
		default {
			_description = _description + format["<br/><t size='1'  align='left' color='%1'>%2</t>", "#b2ec00", format["You can craft this item %1 times.", _CraftingQuantidade]];
		};
	};
	for "_i" from 1 to _CraftingQuantidade do {
		_listBoxIndex = lbAdd[200008, str(_i)]; 
		lbSetValue[200008, _listBoxIndex, _i];
	};
	lbSetCurSel[200008, 0];
}else{
	_description = _description + format["<br/><t size='1'  align='left' color='%1'>%2</t>", "#ea0000", "You cannot craft this item yet."];
	(_dialog displayCtrl 200008) ctrlEnable false; 
	(_dialog displayCtrl 200007) ctrlEnable false; 
};
(_dialog displayCtrl 200006) ctrlSetText _craftingImagem;
(_dialog displayCtrl 200009) ctrlSetStructuredText parseText _description;
(_dialog displayCtrl 200004) ctrlSetText _craftname; //Mostrar Nome do Item
true




