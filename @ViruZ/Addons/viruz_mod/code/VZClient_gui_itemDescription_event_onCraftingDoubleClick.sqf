private["_listBoxLabel","_listBoxLabelIndex","_craftingClassName"];
disableSerialization;
_listBoxLabel = _this select 0;
_listBoxLabelIndex = _this select 1;
_craftingClassName = _listBoxLabel lbData _listBoxLabelIndex;
_craftingClassName call VZClient_gui_crafting_show;
true;