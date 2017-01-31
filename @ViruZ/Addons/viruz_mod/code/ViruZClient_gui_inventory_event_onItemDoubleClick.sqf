/*
    File: ViruZClient_gui_inventory_event_onItemDoubleClick.sqf
    Atuthor: Mateus "Mateuus" Rodrigues
	
	Licence: 
	ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
	
    Description:
	Pegar o item real que foi selecionado no inventario.
*/

private["_itemControl","_itemControlIndex","_itemClassName","_itemDisplayName","_configName","_configSearch"];
_itemControl = _this select 0;
_itemControlIndex = _this select 1;
_itemClassName = _itemControl lbData _itemControlIndex;
_itemDisplayName = _itemControl lbText _itemControlIndex;
_configName = "";
if( _itemClassName == "" ) then
{
	_configSearch = _itemDisplayName call ViruZClient_gear_getConfigEntryByDisplayName;
	_itemClassName = _configSearch select 0;
	_configName = _configSearch select 1;
}
else 
{
	_configName = _itemClassName call ViruZClient_gear_getConfigNameByClassName;
};
if( _configName != "" ) then
{
	[_configName, _itemClassName] call ViruZClient_gui_itemDescription_show;
};
true