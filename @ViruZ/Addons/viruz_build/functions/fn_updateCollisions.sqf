_object = _this select 0;

if ((_this select 1) == "Disable") then
{
	{
		_object disableCollisionWith _x;
	} foreach allUnits;
	{
		_object disableCollisionWith _x;
	} foreach Vehicles;
}
else
{
	{
		_object enableCollisionWith _x;
	} foreach allUnits;
	{
		_object enableCollisionWith _x;
	} foreach Vehicles;
};