/*
ViruZ Mod for Arma 3
Update Object Position, Owner etc by type
Autor: SigWar
This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/
_object = _this select 0;

//Pega o dono do objeto
_ownerUid = _object getVariable ["OwnerUID","0"];
_removeRUID = getPlayerUID player;
_objetodamage = getDammage _object;
_canDelete = _object getVariable ["canDelete",true];
_deleteTime = _object getVariable ["deleteTime",0];
//checa o grupo
_sameGroup = false;
_savedGroup = profileNamespace getVariable["savedGroup",[]];
if (count _savedGroup > 1) then {
			
	if (_ownerUid in _savedGroup and _removeRUID in _savedGroup ) then {
			_sameGroup = true;
	};
		
};

if ( _removeRUID != _ownerUid and !_sameGroup) exitWith { 
		cutText ["You are not the owner of this object or you are not in the same group!", "PLAIN DOWN",2]
};

if (!_canDelete ) exitWith { 
		cutText ["This object is under construction, Wait to delete it", "PLAIN DOWN",2]
};


viruzUpdateVehicle = [_object,"DelObject"];
publicVariable "viruzUpdateVehicle";


if (serverTime < _deleteTime) then {
	if (_objetodamage == 0) then {

		_pos = getPosATL player;
		_box = createVehicle ["GroundWeaponHolder", _pos, [], 0.0, "CAN_COLLIDE"];
		_box setPosATL _pos;


		{
			/*if (!(_classnameFound == -1)) then 
			{
				_place = (viruz_build_array select _categorieFound) select _classnameFound;
				_place set [1,[_array]];
			}
			else*/
			{
				_place = viruz_build_array select _categorieFound;
				_place set [count _place, [_classname,[_array]]];
			};
			
			{
				if (!(_foreachindex == 0)) then
				{
					if ((_x select 0) == typeOf _object) then
					{
						{
							_itemtype = (_x select 0);
							_counter = (_x select 1);
							_box addMagazineCargoGlobal [_itemtype,_counter];
						}
						foreach (_x select 1);
					};
				};
			}
			foreach _x;
		}foreach viruz_build_array;
	};
};
//deleteVehicle _object;
