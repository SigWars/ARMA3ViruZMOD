/*
    File: ViruZClient_gear_getConfigEntryByDisplayName.sqf
    Atuthor: Mateus "Mateuus" Rodrigues
	
	Licence: 
	ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
	
    Description:
	Pegar Display name caso vir nulo..
*/

private["_displayName","_result","_configSearch"];
_displayName = _this;
_result = ["", ""]; 
{
	_configSearch = ("getText (_x >> 'displayName') == _displayName") configClasses(configFile >> _x);
	if !(_configSearch isEqualTo[]) exitWith
	{
		_result = [configName(_configSearch select 0), _x];
	};
}
foreach ["CfgMagazines", "CfgWeapons", "CfgVehicles", "CfgAmmo"];
_result