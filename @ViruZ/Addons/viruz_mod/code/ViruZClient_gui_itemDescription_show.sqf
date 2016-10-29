private["_GetConfigName","_GetItemClassName","_SelectItemConfig","_GetItemDisplayName","_GetItemImagem","_ferramentasRequired","_getItemMagazine","_TemAsFerramentas","_itemDescription","_GetferramentaItemName","_ferramentaItemName","_descriptionLabel","_craftingLabel","_craftingLabelListBox","_craftingSub","_buttonCrafting","_craftingClassName","_craftingName","_craftingPicture","_listItemIndex"];

//Get
_GetConfigName = _this select 0;
_GetItemClassName = _this select 1;

//Select
_SelectItemConfig = configFile >> _GetConfigName >> _GetItemClassName;

//Get
_GetItemDisplayName = getText(_SelectItemConfig >> "displayName");
_GetItemImagem = getText(_SelectItemConfig >> "picture");

//Ferramentas para Usar?
_ferramentasRequired = [];
//Pegar os itens do Inventory do Jogador 
_getItemMagazine = magazines player;


//Select Inventory
SelectedInventoryItem = [_GetItemClassName, _GetItemDisplayName, _GetItemImagem];

//Create Dialog
createDialog "RscDisplayShowItemDialog";
waitUntil { !isNull findDisplay 100000 };
_dialog = uiNameSpace getVariable ["RscDisplayShowItemDialog", displayNull];

//Buttons
(_dialog displayCtrl 100014) ctrlEnable false; //Consumir
(_dialog displayCtrl 100015) ctrlEnable false; //Usar
(_dialog displayCtrl 100016) ctrlEnable false; //Construir

//Itens Informações
(_dialog displayCtrl 100006) ctrlSetText _GetItemImagem; //Mostrar Foto
(_dialog displayCtrl 100004) ctrlSetText _GetItemDisplayName; //Mostrar Nome do Item

//Verificar se o item é consumivel ou não //Lembrar de adicionar um Sub Classe nos itens *--*
if( isClass(_SelectItemConfig >> "Event" >> "Consumivel") )  then
{
	_ferramentasRequired = getArray (_SelectItemConfig >> "Event" >> "Consumivel" >> "Ferramentas");
	_TemAsFerramentas = true;
	{
		//Verificar se ele tem as Ferramentas necessarias
		if !(_x in _getItemMagazine) exitWith 
		{
			_TemAsFerramentas = false;
		};
	}
	forEach _ferramentasRequired;
	(_dialog displayCtrl 100014) ctrlEnable _TemAsFerramentas;
};

//Verificar se o item é usavel?  se sim ativar o botão
if( isClass(_SelectItemConfig >> "Event" >> "Usavel") )  then
{
	(_dialog displayCtrl 100015) ctrlEnable true;
};

//Verificar se o tem é Construtivel? se sim ativar o botão
if( isClass(_SelectItemConfig >> "Event" >> "Construtivel") )  then
{
	(_dialog displayCtrl 100016) ctrlEnable true;
};

//Mostrar o nome do item na Tabela de Detalhes
(_dialog displayCtrl 100010) ctrlSetStructuredText parseText format["<t size='1.5' color='#ffffff' align='left'>%1</t><br/>", _GetItemDisplayName];

_itemDescription = ""; 

if (_itemDescription == "") then
{
	_itemDescription = getText(_SelectItemConfig >> "descriptionShort");
};

if !(_ferramentasRequired isEqualTo []) then 
{
	_itemDescription = _itemDescription + "<br/><br/>";
	{
		_ferramentaItemClassName = _x;
		_GetferramentaItemName = getText(configFile >> "CfgMagazines" >> _ferramentaItemClassName >> "displayName");
		_itemDescription = _itemDescription + format["<t size='1' font='puristaMedium' align='left'>%1</t>", _GetferramentaItemName];
		if (_ferramentaItemClassName in _getItemMagazine) then 
		{
			_itemDescription = _itemDescription + format["<t size='1' font='puristaMedium' align='right' color='%1'>%2</t>", "#b2ec00", "ON"];
		}
		else 
		{
			_itemDescription = _itemDescription + format["<t size='1' font='puristaMedium' align='right' color='%1'>%2</t>", "#ea0000", "OFF"];
		};
		_itemDescription = _itemDescription + "<br/>";
	}
	forEach _ferramentasRequired;
};

//Mostrar a Descrição
_descriptionLabel = (_dialog displayCtrl 100011);
_descriptionLabel ctrlSetStructuredText (parseText _itemDescription);
[_descriptionLabel] call BIS_fnc_ctrlFitToTextHeight;

//Mostrar os itens que poder Craftar
_craftingLabel = _GetItemClassName call VZClient_item_getCrafting;
_craftingLabelListBox = (_dialog displayCtrl 100013);
_buttonCrafting = (_dialog displayCtrl 100008);

if !(_craftingLabel isEqualTo []) then 
{
	_craftingLabelListBox ctrlShow true;
	_craftingSub ctrlShow true;
	lbClear _craftingLabelListBox;
	{
		//Get Variables
		_craftingClassName = _x select 0;
		_craftingName = _x select 1;
		_craftingPicture = _x select 2;
		
		
		_listItemIndex = _craftingLabelListBox lbAdd _craftingName;
		
		_craftingLabelListBox lbSetPicture [_listItemIndex, _craftingPicture];
		_craftingLabelListBox lbSetData [_listItemIndex, _craftingClassName];
	}
	forEach _craftingLabel;
	
	_buttonCrafting ctrlShow true;
	_craftingLabelListBox ctrlShow true;
}
else 
{
	_craftingLabelListBox ctrlShow false;
	_buttonCrafting ctrlShow false;
};

true
