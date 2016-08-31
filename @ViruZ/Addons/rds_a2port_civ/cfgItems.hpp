class cfgAmmo
{
	class MissileBase;
	class rds_ammo_car_FirstAidKit_proxy : MissileBase
	{
		hit =0;cost=0;
		maverickweapon = 1;
		maverickWeaponIndexOffset=10;
		proxyShape="\rds_a2port_civ\items\rds_apteczka_proxy";
	};
	class rds_ammo_car_warning_triangle_to11_proxy : rds_ammo_car_FirstAidKit_proxy
	{
		maverickWeaponIndexOffset=20;
		proxyShape="\rds_a2port_civ\items\rds_to11_pudelko";
	};
	class rds_ammo_Sparewheel_lada_proxy : rds_ammo_car_FirstAidKit_proxy
	{
		maverickWeaponIndexOffset=30;
		proxyShape="\rds_a2port_civ\sparewheels\rds_spare_lada_proxy";
	};
	#define A_Pods(name) class rds_ammo_Sparewheel_##name##_proxy : rds_ammo_Sparewheel_lada_proxy {proxyShape=\rds_a2port_civ\sparewheels\rds_spare_##name##_proxy;};
	A_Pods(golf4)
	A_Pods(octavia)
	A_Pods(s1203)
	A_Pods(ikarus)
	A_Pods(gaz24)

	class rds_ammo_empty_proxy : rds_ammo_car_FirstAidKit_proxy
	{
		maverickWeaponIndexOffset=100;
		proxyShape="\A3\weapons_f\empty.p3d";
	};

};

#define R_Pods(name) class rds_##name##_proxy : VehicleMagazine {ammo = rds_ammo_##name##_proxy;count = 1;};

class cfgMagazines
{
	class VehicleMagazine;
	R_Pods(car_FirstAidKit)
	R_Pods(car_warning_triangle_to11)

	R_Pods(Sparewheel_lada)
	R_Pods(Sparewheel_golf4)
	R_Pods(Sparewheel_octavia)
	R_Pods(Sparewheel_s1203)
	R_Pods(Sparewheel_ikarus)
	R_Pods(Sparewheel_gaz24)

	R_Pods(empty)
};

class CfgWeapons
{
	class ItemCore;
	class InventoryFirstAidKitItem_Base_F;
	class InventoryFinsItem_Base_F;

	class rds_car_FirstAidKit : ItemCore {
		scope = 2;
		displayName = "Car First Aid Kit";
		picture = "\rds_a2port_civ\items\pic\pic_apteczka.paa";
		model = "\rds_a2port_civ\items\rds_apteczka";
		descriptionShort = "Use to treat heavy wounds.<br/>Usable on: Self, Others";
		class ItemInfo : InventoryFirstAidKitItem_Base_F {
			mass = 12;
		};
	};
	class rds_car_warning_triangle_to11 : ItemCore {
		scope = 2;
		displayName = "Warning Triangle TO-11";
		picture = "\rds_a2port_civ\items\pic\pic_trojkat_to11.paa";
		model = "\rds_a2port_civ\items\rds_to11";
		descriptionShort = "Place 30-100 m behind the car. On highways distance increase to 200m";
		class ItemInfo : InventoryFinsItem_Base_F {
			mass = 12;
            type = 301;
		};
	};
};