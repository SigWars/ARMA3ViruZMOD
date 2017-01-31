/*
ViruZ Mod for Arma 3
Update Object Position, Owner etc by type
Autor: SigWar
This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/
private ["_ownerUid","_removeRUID","_objetodamage","_canDelete","_backRessource","_sameGroup"];

_object = _this select 0;

//Pega o dono do objeto
_ownerUid = _object getVariable ["OwnerUID","0"];
_removeRUID = getPlayerUID player;
_objetodamage = getDammage _object;
_canDelete = _object getVariable ["canDelete",false];
_backRessource = _object getVariable ["backRessource",0];
//checa o grupo
_sameGroup = false;

//check group
_savedGroup = player getVariable ["ClanID","0"];
_permission = player getVariable ["LvL",0];
if ((_savedGroup isEqualto _ownerUid) and (_permission > 1)) then {_sameGroup = true;};

if ( _removeRUID != _ownerUid and !_sameGroup) exitWith { 
		cutText ["You are not the owner of the object or you are not in the same group, or you do not have the permission required!", "PLAIN DOWN",2]
};

if (!_canDelete ) exitWith { 
		cutText ["This object is under construction, Wait to delete it", "PLAIN DOWN",2]
};


viruzUpdateVehicle = [_object,"DelObject"];
publicVariable "viruzUpdateVehicle";


if (time < _backRessource) then {

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
//deleteVehicle _object;
