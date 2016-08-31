
class Bag_Base;


class RDS_Sparewheel_lada: Bag_Base
{
	AUTHOR_MACRO

	scope=2;
	displayName="Vaz-2103 Spare wheel";
	mass=922;
	isbackpack = 1;
	reversed = 0;
	model = "\rds_a2port_civ\sparewheels\rds_spare_lada.p3d";
	picture = "\rds_a2port_civ\sparewheels\pictures\rds_sparewheel_lada.paa";
	maximumLoad = 0;
	class UserActions
	{
		class SpareWheel
		{
			displayName = "Use spare wheel";
			priority = 0;
			shortcut ="";
			condition = "! ((objectParent this) iskindOf 'car')";
			statement = "[this,'RDS_Lada_Base'] spawn rds_fnc_spareWheel";
			displayNameDefault ="";
			position = "";
			radius = 2;
			onlyforplayer = 1;
		};
	};
};
#define WheelActionMacro(typeOf) \
	class UserActions: UserActions\
	{\
		class SpareWheel: SpareWheel\
		{\
			statement = "[this,'##typeOf##'] spawn rds_fnc_spareWheel";\
		};\
	};

class RDS_Sparewheel_s1203: RDS_Sparewheel_lada
{
	displayName="s1203 Spare wheel";
	AUTHOR_MACRO

	model = "\rds_a2port_civ\sparewheels\rds_spare_s1203.p3d";
	picture = "\rds_a2port_civ\sparewheels\pictures\rds_sparewheel_s1203.paa";
	WheelActionMacro(RDS_S1203_Base)
};
class RDS_Sparewheel_golf4: RDS_Sparewheel_lada
{
	displayName="Golf-4 Spare wheel";
	AUTHOR_MACRO

	model = "\rds_a2port_civ\sparewheels\rds_spare_golf4.p3d";
	picture = "\rds_a2port_civ\sparewheels\pictures\rds_sparewheel_golf4.paa";
	WheelActionMacro(RDS_Golf4_Base)
};
class RDS_Sparewheel_octavia: RDS_Sparewheel_lada
{
	displayName="Octavia II Spare wheel";
	AUTHOR_MACRO

	model = "\rds_a2port_civ\sparewheels\rds_spare_octavia.p3d";
	picture = "\rds_a2port_civ\sparewheels\pictures\rds_sparewheel_octavia.paa";
	WheelActionMacro(RDS_Octavia_Base)
};
class RDS_Sparewheel_gaz24: RDS_Sparewheel_lada
{
	displayName="Gaz-24 Spare wheel";
	AUTHOR_MACRO

	model = "\rds_a2port_civ\sparewheels\rds_spare_gaz24.p3d";
	picture = "\rds_a2port_civ\sparewheels\pictures\rds_sparewheel_gaz24.paa";
	WheelActionMacro(RDS_Gaz24_Base)
};
class RDS_Sparewheel_ikarus: RDS_Sparewheel_lada
{
	displayName="Ikarus Spare wheel";
	AUTHOR_MACRO

	model = "\rds_a2port_civ\sparewheels\rds_spare_ikarus.p3d";
	picture = "\rds_a2port_civ\sparewheels\pictures\rds_sparewheel_ikarus.paa";
	WheelActionMacro(RDS_Ikarus_Base)
};