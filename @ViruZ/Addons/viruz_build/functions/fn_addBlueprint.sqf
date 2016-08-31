_logic = [_this,0,objNull,[objNull]] call BIS_fnc_param;
_activated = [_this,2,true,[true]] call BIS_fnc_param;
waituntil {!(isNil "viruz_build_array")};

if (_activated) then 
{
	_categorieFound = -1;
	_classnameFound = -1;
	_categorie = _logic getVariable "categorie";
	_classname = _logic getVariable "classname";
	_ressoure1 = _logic getVariable "ressoure1"; _quantity1 = _logic getVariable "quantity1";
	_ressoure2 = _logic getVariable "ressoure2"; _quantity2 = _logic getVariable "quantity2";
	_ressoure3 = _logic getVariable "ressoure3"; _quantity3 = _logic getVariable "quantity3";
	_ressoure4 = _logic getVariable "ressoure4"; _quantity4 = _logic getVariable "quantity4";
	_array = [];
	if (!(_ressoure1 == "")) then { _array = _array + [_ressoure1,_quantity1];};
	if (!(_ressoure2 == "")) then { _array = _array + [_ressoure2,_quantity2];};
	if (!(_ressoure3 == "")) then { _array = _array + [_ressoure3,_quantity3];};
	if (!(_ressoure4 == "")) then { _array = _array + [_ressoure4,_quantity4];};
	
	{
		if ((_x select 0) == _categorie) then {_categorieFound = _foreachindex;};
	} foreach viruz_build_array;
	
	if (!(_categorieFound == -1)) then
	{
		_searchArray = viruz_build_array select _categorieFound;
		{
			if (!(_foreachindex == 0)) then 
			{
				if ((_x select 0) == _classname) then {_classnameFound = _foreachindex;};
			};
		} foreach _searchArray;
		
		
		if (!(_classnameFound == -1)) then 
		{
			_place = (viruz_build_array select _categorieFound) select _classnameFound;
			_place set [1,[_array]];
		}
		else
		{
			_place = viruz_build_array select _categorieFound;
			_place set [count _place, [_classname,[_array]]];
		};
	}
	else
	{
		viruz_build_array = viruz_build_array + [[_categorie,[_classname,[_array]]]];
	};
};
true
