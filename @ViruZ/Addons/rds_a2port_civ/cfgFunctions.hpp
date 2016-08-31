
class CfgFunctions
{
	class RDS
	{
		recompile=1;
		tag = "RDS";
		class functions
		{
			recompile=1;
			class ikarusDoors
			{
				file = "\rds_a2port_civ\Ikarus\Ikarus_Doors.sqf";
				description = "Doors sounds for Ikarus";
			};
			class ikarusDoors_handler
			{
				file = "\rds_a2port_civ\Ikarus\Ikarus_Doors_handler.sqf";
				description = "Doors handler for Ikarus";
			};
			class gearSound
			{
				file = "\rds_a2port_civ\scripts\gearSound.sqf";
				description = "Changing gears checker";
			};
			class fuelLeak
			{
				file = "\rds_a2port_civ\scripts\fuelLeak.sqf";
				description = "Fuel leak after hit";
			};
			class wipers
			{
				file = "\rds_a2port_civ\scripts\wipers.sqf";
				description = "Generic wipers function";
			};
			class containerActions
			{
				file = "\rds_a2port_civ\scripts\containerActions.sqf";
				description = "Open/close trunk on inventory access";
			};
			class syrena
			{
				file = "\rds_a2port_civ\scripts\syrena.sqf";
				description = "Emergency siren toggle";
			};
			class migacze
			{
				file = "\rds_a2port_civ\scripts\migacze.sqf";
				description = "Emergency siren toggle";
			};
			class spareWheel
			{
				file = "\rds_a2port_civ\scripts\spareWheel.sqf";
				description = "Spare wheel handler";
			};
			class random_spareWheel
			{
				file = "\rds_a2port_civ\scripts\randomSpareWheel.sqf";
				description = "Random spare wheel adding";
			};
		};
	};
};

