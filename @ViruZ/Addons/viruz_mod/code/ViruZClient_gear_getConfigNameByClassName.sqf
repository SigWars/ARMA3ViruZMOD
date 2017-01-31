/*
    File: ViruZClient_gear_getConfigNameByClassName.sqf
    Atuthor: Mateus "Mateuus" Rodrigues
	
	Licence: 
	ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)
	
    Description:
	Verificar em qual classe o item está em alguma Classe Magazine, Vehicles..
*/

private["_className","_configName"];
_className = _this;
_configName = "";
switch (true) do
{
	case isClass(configFile >> "CfgMagazines" >> _className): 	{ _configName = "CfgMagazines"; };
	case isClass(configFile >> "CfgVehicles" >> _className): 	{ _configName = "CfgVehicles"; };
	case isClass(configFile >> "CfgAmmo" >> _className): 		{ _configName = "CfgAmmo"; };
	case isClass(configFile >> "CfgGlasses" >> _className): 	{ _configName = "CfgGlasses"; };
	default 											     	{ _configName = "CfgWeapons"; };
};
_configName