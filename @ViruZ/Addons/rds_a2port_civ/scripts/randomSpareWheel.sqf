/*
	random spare wheel adding
	params
	_v - vehicle
	_t - type of action: 0 - random add, 1 - always add, other - disabled
*/

params["_v","_t"];


switch(_v getVariable ["rds_random_spare",0])do
{
	case 0: 	{
					if(random(100)>50)then{

						_v addBackpackCargo [_t,1];
						_v addMagazine format["%1_proxy",_t];
					};
				};
	case 1: 	{
					_v addBackpackCargo [_t,1];
					_v addMagazine format["%1_proxy",_t];
				};

	default {};
};