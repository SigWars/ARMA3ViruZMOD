/*
ViruZ Mod for Arma 3
MaintainBuilds by items count
Autor: SigWar
This work is licensed under ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA). 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/
private ["_couldFix","_findTable","_findGen","_objects","_Structures","_countCinder","_countWood","_countMetal","_buildsTomaintain","_WorkStation","_cindercount","_woodcount","_nailcount",
"_metalcount","_arrayWood","_arrayCinder","_arrayNail","_arrayMetal"];

_couldFix = true;

//Get Maintanance table
/*_findTable = nearestObjects [player, ["ViruZ_WorkStand"], 5];
if (count _findTable < 1 ) exitWith { cutText ["ERROR WHEN FIND MAINTENANCE TABLE!!", "PLAIN DOWN",2];}
_WorkStation = _findTable select 0;*/
_WorkStation = _this select 3;

_findGen = nearestObjects [_WorkStation, ["Land_Portable_generator_F"], 50];
if (count  _findGen < 1) exitWith { cutText ["No generator found!!, Maintenance table need to be 50 meters from the generator", "PLAIN DOWN",2];};
_generator = _findGen select 0;
private _generatorOwner = _generator getVariable ["OwnerUID","0"];
private _lastMaintain = _generator getVariable ["lastFix", ["Never","Never","Never"]];

_objects = nearestObjects [_generator, [], 55];

_Structures = [];
{
	_Structures SET [count _Structures,_x select 1];
}forEach (getArray(configFile >> "CfgConstruction" >> "Structures"));

_countCinder = [];
_countWood = [];
_countMetal = [];
_buildsTomaintain = [];

{
    if ((typeOf _x in _Structures) && (typeOf _x in Maintain_MatCinder)) then {
        _countCinder SET [count _countCinder,_x];
    };
	
	if ((typeOf _x in _Structures) && (typeOf _x in Maintain_MatWood)) then {
        _countWood SET [count _countWood,_x];
    };
	
	if ((typeOf _x in _Structures) && (typeOf _x in Maintain_MatMetal)) then {
        _countMetal SET [count _countMetal,_x];
    };
	
	if (typeOf _x in _Structures) then {
        _buildsTomaintain SET [count _buildsTomaintain,_x];
    };
} forEach _objects;

if (ViruzDebugMode > 2 or ViruzDebugType == "MAINTAIN") then 
{
	diag_log format["VZ_UPDATE_OBJ_MAINTAIN: BUILDS TOMAINTAIN: %1",_buildsTomaintain];
	diag_log format["VZ_UPDATE_OBJ_MAINTAIN: BUILDS _countCinder: %1",_countCinder];
	diag_log format["VZ_UPDATE_OBJ_MAINTAIN: BUILDS _countWood: %1",_countWood];
	diag_log format["VZ_UPDATE_OBJ_MAINTAIN: BUILDS _countMetal: %1",_countMetal];
};

private _ressNailreq = round(count _countWood / 5);
private _ressCinderreq = round(count _countCinder / 5);
private _ressWooodreq = round(count _countWood / 5);
private _ressMetalreq = round(count _countMetal / 4);

	
private _Builds = + _countCinder + _countWood + _countMetal; 

		_cindercount=0;
		_woodcount =0;
		_nailcount=0;
		_metalcount=0;
			
		//get Cinders in Maintain table
		_ressCinder = "Viruz_CinderBlock";
		private _arrayCinder = MagazineCargo _WorkStation;
		_cindercount = { _x == _ressCinder} count _arrayCinder;
		
		//get woods in Maintain table
		_ressWood = "Viruz_Woodboard";
		private _arrayWood = MagazineCargo _WorkStation;
		_woodcount = { _x == _ressWood} count _arrayWood;
		
		
		//get nails in Maintain table
		_ressNail = "equip_nails";
		private _arrayNail = MagazineCargo _WorkStation;
		_nailcount = { _x == _ressNail} count _arrayNail;
		
		//get Metals in Maintain table
		_ressMetal = "PartGeneric";
		private _arrayMetal = MagazineCargo _WorkStation;
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
			[_WorkStation,_ressCinderreq,_ressCinder] call vz_RemoveMagazineCargoGlobal; //call vz_RemoveItemCargoGlobal;
			};
			
			//Remove Woods from crate
			if (_ressWooodreq > 0) then {
			[_WorkStation,_ressWooodreq,_ressWood] call vz_RemoveMagazineCargoGlobal;
			};
			
			//remove Nals from holder
			if (_ressNailreq > 0) then {
			[_WorkStation,_ressNailreq,_ressNail] call vz_RemoveMagazineCargoGlobal;
			};
			
			//Removes Metal from Build
			if (_ressMetalreq > 0) then {
			[_WorkStation,_ressMetalreq,_ressMetal] call vz_RemoveMagazineCargoGlobal;
			};			
			
			//save in database
			{
				if (typeOf _x in _Structures) then 
				{
					_x setDamage 0;
					viruzUpdateVehicle = [_x,"maintainBuild"];
					publicVariableServer "viruzUpdateVehicle";
				};
				
				if (typeof _x == "Land_Portable_generator_F") then 
				{
					_x setVariable ["lastFix", currentDate, true];
				};
				
				_x setVariable ["OwnerUID", _generatorOwner, true];
			
			}foreach _buildsTomaintain;
		
		
		//Text mensage
		[
			"<t color='#0033FF' size = '.7'>Maintenance made for more 7 Days</t><br />", //structured text
			0.24 * safezoneW + safezoneX, //number - x
			0.01 * safezoneH + safezoneY, //number - y
			5, //number - duration
			1, // number - fade in time
			0, // number - delta y
			0 //number - layer ID
		] spawn bis_fnc_dynamicText;
				
}else {
	//cutText [format["You need %1 Cinder Blocks + %2 Wooden Pile + %3 Metal Scraps + %4 Box of Nails to fix and update you builds",_ressCinderreq,_ressWooodreq,_ressMetalreq,_ressNailreq ],"PLAIN DOWN",2];
	_titulo = "<t color='#0033FF' size = '.7'>You Need:</t><br />";
	_cindertext = format["<t color='#FFFF00' size = '.5'>%1 Cinderblocks</t><br />",_ressCinderreq];
	_woodtext = format["<t color='#FFFF00' size = '.5'>%1 WoodBoard</t><br />",_ressWooodreq];
	_metaltext = format["<t color='#FFFF00' size = '.5'>%1 Metal Scraps</t><br />",_ressMetalreq];
	_nailtext = format["<t color='#FFFF00' size = '.5'>%1 Box of Nails</t><br />",_ressNailreq];
	_endtext = "<t color='#0033FF' size = '.5'>for maintenance of buildings for 7 days</t><br />";
	_lastMaintainText = format[(localize  "STR_VIRUZ_CODE_DATE"),_lastMaintain select 2,_lastMaintain select 1,_lastMaintain select 0];
	
	//format["<t color='#FFFF00' size = '.5'>Last maintain made on: <br/> Day:%1 of Mounth:%2 of Year:%3 </t><br/>",_lastMaintain select 2,_lastMaintain select 1,_lastMaintain select 0];
						
	//_lastMaintain select [9,2],_lastMaintain select [6,2],_lastMaintain select [1,4]
	
	_finaltext = _titulo + _cindertext + _woodtext + _metaltext + _nailtext + _endtext + _lastMaintainText;
	
	[
		_finaltext, //structured text
		0.24 * safezoneW + safezoneX, //number - x
		0.01 * safezoneH + safezoneY, //number - y
		5, //number - duration
		1, // number - fade in time
		0, // number - delta y
		0  // number - layer ID
	] spawn bis_fnc_dynamicText;
	
};
