class CfgNonAIVehicles
{	
	class ProxyWeapon;
	class Proxyrds_apteczka_proxy : ProxyWeapon
	{
		model = "\rds_a2port_civ\items\rds_apteczka_proxy"; 
		simulation ="maverickweapon";
	};
	class Proxyrds_spare_lada_proxy : ProxyWeapon
	{
		model = "\rds_a2port_civ\sparewheels\rds_spare_lada_proxy"; 
		simulation ="maverickweapon";
	};
	class Proxyrds_to11_pudelko : Proxyrds_spare_lada_proxy
	{
		model = "\rds_a2port_civ\items\rds_to11_pudelko"; 
	};
};
