/******************************************************************************************************************
ViruZ Mod for Arma 3
Update Object Position, Owner etc by type
Autor: SigWar
This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
********************************************************************************************************************/
private ["_Object","_mover","_hasPoles","_sameGroup","_ownerUid","_hasmags","_hasitems","_hasweapons","_totalcount"];
_hasPoles = true;
_sameGroup = false;
_Object = _this select 0;
//Pega o dono do objeto
_ownerUid = _Object getVariable ["OwnerUID","0"];
_mover = getPlayerUID player;

//checa se tem item dentro
_hasmags = MagazineCargo _Object;
_hasitems = ItemCargo _Object;
_hasweapons = WeaponCargo _Object;
	
_totalcount = + count _hasmags + count _hasitems + count _hasweapons;
		
if (_totalcount > 0) exitWith { 
	cutText ["You cant move objects with itens inside", "PLAIN DOWN"];
};

//checa o grupo
_savedGroup = profileNamespace getVariable["savedGroup",[]];
if (count _savedGroup > 1) then {
			
	if (_ownerUid in _savedGroup and _mover in _savedGroup ) then {
			_sameGroup = true;
	};
		
};

if ( _mover != _ownerUid and !_sameGroup) then { 
		cutText ["You are not the owner of this object or is not in the same group!", "PLAIN DOWN"];
} else {
	[_Object,"MoveObject",_hasPoles] spawn VZ_move_object;
};



