_set1 = profilenamespace getvariable "babe_EM_s1";
_fatigue = (_set1 select 0) select 1;

if (!IsMultiplayer) then
{
	if (_fatigue == 0) then
	{
		player enableStamina false;
	} else
	{
		player enableStamina true;
	};
};

