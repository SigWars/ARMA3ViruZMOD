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