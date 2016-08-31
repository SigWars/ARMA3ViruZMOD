/*
ViruZ Mod for Arma 3
MaintainBuilds by items count
Autor: SigWar
This work is licensed under ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA). 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/
private ["_couldFix","_findTable","_findGen","_objects","_countCinder","_countWood","_countMetal","_WorkStation","_cindercount","_woodcount","_nailcount","_metalcount","_arrayWood","_arrayCinder","_arrayNail","_arrayMetal"];

_couldFix = true;

_WorkStation = objNull;
_generator = objNull;

_findTable = nearestObjects [player, ["ViruZ_WorkStand"], 5];
_WorkStation = _findTable select 0;
_inventoryHolder = _WorkStation;
_findGen = nearestObjects [_WorkStation, ["Land_Portable_generator_F"], 50];
_generator = _findGen select 0;
_objects = nearestObjects [_generator, [], 55];

if (count _findGen < 1) exitWith { cutText ["No generator found!!, Maintenance table need to be 50 meters from the generator", "PLAIN DOWN",2]; };


//count number of Houses
_countCinder = [];
_countWood = [];
_countMetal = [];

{
    if (typeOf _x in Maintain_MatCinder) then {
        _countCinder SET [count _countCinder,_objects];
    };
	
	if (typeOf _x in Maintain_MatWood) then {
        _countWood SET [count _countWood,_objects];
    };
	
	if (typeOf _x in Maintain_MatMetal) then {
        _countMetal SET [count _countMetal,_objects];
    };
	
} forEach _objects;

_ressNailreq = count _countMetal;
_ressCinderreq = count _countCinder;
_ressWooodreq = count _countWood;
_ressMetalreq = count _countMetal;

	
_Builds = + _countCinder + _countWood + _countMetal; 

		_cindercount=0;
		_woodcount =0;
		_nailcount=0;
		_metalcount=0;
			
		//get Cinders in Maintain table
		_ressCinder = "Viruz_CinderBlock";
		_arrayCinder = MagazineCargo _inventoryHolder;
		_cindercount = { _x == _ressCinder} count _arrayCinder;
		
		//get woods in Maintain table
		_ressWood = "PartWoodPile";
		_arrayWood = MagazineCargo _inventoryHolder;
		_woodcount = { _x == _ressWood} count _arrayWood;
		
		
		//get nails in Maintain table
		_ressNail = "equip_nails";
		_arrayNail = MagazineCargo _inventoryHolder;
		_nailcount = { _x == _ressNail} count _arrayNail;
		
		//get Metals in Maintain table
		_ressMetal = "PartGeneric";
		_arrayMetal = MagazineCargo _inventoryHolder;
		_metalcount = { _x == _ressMetal} count _arrayMetal;
				
		//check if have all items
		if(_cindercount < _ressCinderreq or _woodcount < _ressWooodreq or _nailcount < _ressNailreq or _metalcount < _ressMetalreq ) then 
		{ 
			_couldFix = false;
		};

//proced maintain 		
if (count _Builds >= 1 and _couldFix) then {
			
			//Remove cinders from crate
			if (_ressCinderreq > 0) then {
			[_inventoryHolder,_ressCinderreq,_ressCinder] call vz_RemoveMagazineCargoGlobal; //call vz_RemoveItemCargoGlobal;
			};
			
			//Remove Woods from crate
			if (_ressWooodreq > 0) then {
			[_inventoryHolder,_ressWooodreq,_ressWood] call vz_RemoveMagazineCargoGlobal;
			};
			
			//remove Nals from holder
			if (_ressNailreq > 0) then {
			[_inventoryHolder,_ressNailreq,_ressNail] call vz_RemoveMagazineCargoGlobal;
			};
			
			//Removes Metal from Build
			if (_ressMetalreq > 0) then {
			[_inventoryHolder,_ressMetalreq,_ressMetal] call vz_RemoveMagazineCargoGlobal;
			};			
			
			//save in database
			{
				_objectID 	= _x getVariable ["ObjectID","0"];
				_objectUID	= _x getVariable ["ObjectUID","0"];
				_OwnerUID	= _x getVariable ["OwnerUID","0"];
								
				if (_OwnerUID != "0") then {
					_x setDamage 0;
					viruzUpdateBuild = ["RepairBuild",_objectID,_objectUID,currentDate];
					publicVariable "viruzUpdateBuild";
				};
			}foreach _objects;
		
		cutText ["Maintenance made for more 7 Days","PLAIN DOWN"];
				
}else {
	//cutText [format["You need %1 Cinder Blocks + %2 Wooden Pile + %3 Metal Scraps + %4 Box of Nails to fix and update you builds",_ressCinderreq,_ressWooodreq,_ressMetalreq,_ressNailreq ],"PLAIN DOWN",2];
	_titulo = "<t color='#0033FF' size = '.7'>You Need:</t><br />";
	_cindertext = format["<t color='#FFFF00' size = '.5'>%1 Cinderblocks</t><br />",_ressCinderreq];
	_woodtext = format["<t color='#FFFF00' size = '.5'>%1 Wood Pile</t><br />",_ressWooodreq];
	_metaltext = format["<t color='#FFFF00' size = '.5'>%1 Metal Scraps</t><br />",_ressMetalreq];
	_nailtext = format["<t color='#FFFF00' size = '.5'>%1 Box of Nails</t><br />",_ressNailreq];
	_endtext = "<t color='#0033FF' size = '.4'>for maintenance of buildings for 7 days</t><br />";
	
	_finaltext = _titulo + _cindertext + _woodtext + _metaltext + _nailtext + _endtext;
	
	[
		_finaltext, //structured text
		0.24 * safezoneW + safezoneX, //number - x
		0.01 * safezoneH + safezoneY, //number - y
		5, //number - duration
		1, // number - fade in time
		0, // number - delta y
		0 //number - layer ID
	] spawn bis_fnc_dynamicText;
	
};
