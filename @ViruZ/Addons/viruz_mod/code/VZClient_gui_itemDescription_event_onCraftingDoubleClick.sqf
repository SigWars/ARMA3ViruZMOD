/*
    File: VZClient_gui_itemDescription_event_onCraftingDoubleClick.sqf
    Atuthor: Mateus "Mateuus" Rodrigues
	
	Licence: 
	ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
	
    Description:
	Mostrar Lista de Craft
*/
private["_listBoxLabel","_listBoxLabelIndex","_craftingClassName"];
disableSerialization;
_listBoxLabel = _this select 0;
_listBoxLabelIndex = _this select 1;
_craftingClassName = _listBoxLabel lbData _listBoxLabelIndex;
_craftingClassName call VZClient_gui_crafting_show;
true;