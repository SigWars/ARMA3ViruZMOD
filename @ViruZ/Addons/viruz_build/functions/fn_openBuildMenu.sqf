if (vz_cant_Build) exitWith { cutText ["You can not open while building!", "PLAIN DOWN"];};
_cursorTarget = cursorTarget;

_dialog = createDialog "viruz_build_dialogMenu";
setMousePosition [0.5,0.5];
waitUntil {dialog};

if (VIRUZ_Build_alignToGround) then {ctrlSetText [1503, "Align to Horizon"]};


if (isNull _cursorTarget) then
{
	ctrlEnable [1500, false];
	ctrlEnable [1501, false];
	ctrlEnable [1502, false];
}
else
{
	private ["_name","_cfg","_DescShort"];
	_name = typeOf _cursorTarget;
    _cfg  = (configFile >>  "CfgVehicles" >>  _name);
	
    _DescShort = if (isText(_cfg >> "displayName")) then {
        getText(_cfg >> "displayName")
	} else {
        _name 
    };
	hint format ["Selected object: %1", _DescShort];
	
	
	if (!isNull attachedTo _cursorTarget) then
	{
		ctrlEnable [1501, false];
		ctrlEnable [1502, false];
	};
	if (!(_cursorTarget iskindOf "Man")) then
	{
		_countmagazines = count (magazineCargo cursorTarget);
		_countitems = count (itemCargo cursorTarget);
		_countweapons = count (weaponCargo cursorTarget);

		if ((_countmagazines == 0) and (_countitems == 0) and (_countweapons == 0)) then { ctrlEnable [1500, false]; };
		
		_type = typeof _cursorTarget;
		_classnameFound = false;
		{
			for "_i" from 1 to ((count _x) - 1) do
			{
				if (_type == (_x select _i) select 0) then
				{
					_classnameFound = true;
					_i = ((count _x) - 1);
				};
			};
		}
		foreach viruz_build_array;
		if (!(_classnameFound)) then 
		{
			ctrlEnable [1501, false];
			ctrlEnable [1502, false];
		};
	}
	else
	{
		ctrlEnable [1500, false];
		ctrlEnable [1501, false];
		ctrlEnable [1502, false];
	};
};
