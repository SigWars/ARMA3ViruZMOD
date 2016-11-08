private["_tabelaName","_display","_DetalhesTabela","_CraftingTabela"];
disableSerialization;
_tabelaName = _this;
_display = findDisplay 100000;
_DetalhesTabela = _display displayCtrl 100009;
_CraftingTabela = _display displayCtrl 100012;
switch (_tabelaName) do
{
	case "CRAFTING":
	{
		_DetalhesTabela ctrlShow false;
		_CraftingTabela ctrlShow true;
	};
	case "DESCRIPTION":
	{
		_DetalhesTabela ctrlShow true;
		_CraftingTabela ctrlShow false;
	};
};
_DetalhesTabela ctrlCommit 1;
_CraftingTabela ctrlCommit 1;
true