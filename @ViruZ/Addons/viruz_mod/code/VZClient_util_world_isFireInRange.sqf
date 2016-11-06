private["_position","_range","_isInRange"];
_position = _this select 0;
_range = _this select 1;
_isInRange = false;
{
	if (inflamed _x) exitWith
	{
		_isInRange = true;
	};
}
forEach (_position nearObjects _range);
_isInRange