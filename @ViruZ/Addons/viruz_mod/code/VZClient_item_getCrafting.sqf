private["_GetItemClassName","_Items","_Craftings","_craftingConfig","_craftingClassName","_getcraftingName","_Itemimagem","_imagem","_componentes","_ferramentas"];

_GetItemClassName = _this;
_Items = [];
_Craftings = (missionConfigFile >> "CfgCrafting") call Bis_fnc_getCfgSubClasses;
{
		_craftingConfig = (missionConfigFile >> "CfgCrafting" >> _x);
		_craftingClassName = _x;
		_getcraftingName = getText(_craftingConfig >> "displayName");
		_Itemimagem = getText (_craftingConfig >> "pictureItem"); //Gostei desse codigo primeiro pega a classe do item
		_imagem = getText(configFile >> "CfgMagazines" >> _Itemimagem >> "picture"); //Para depois buscar a Foto *--*
		_componentes = getArray(_craftingConfig >> "componentes");
		_ferramentas = getArray(_craftingConfig >> "ferramentas");
		{
			if( _x select 1 == _GetItemClassName ) exitWith 
			{
				_Items pushBack [_craftingClassName, _getcraftingName, _imagem];
			};
		}
		forEach _componentes;
		{
			if( _x == _GetItemClassName ) exitWith 
			{
				_Items pushBack [_craftingClassName, _getcraftingName, _imagem];
			};
		}
		forEach _ferramentas;
}
forEach _Craftings;
_Items 