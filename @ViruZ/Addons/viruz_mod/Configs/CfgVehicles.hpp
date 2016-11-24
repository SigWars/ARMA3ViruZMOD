class CfgVehicles {
	//New APEX Additions
	class All {};
	class AllVehicles: All {};
	class Land: AllVehicles {};
	class Man:Land {};
	class CAManBase: Man {};
	//New APEX Additions end.
	
	class SoldierWB: CAManBase {
		class UniformSlotInfo;
	};
	
	
	class Civilian;
	class B_Soldier_F;

	class Underwear_F: SoldierWB {
		class EventHandlers;
	};
	class Camping_base_F;
	class Bag_Base;
	class B_VehicleBag_base : Bag_Base {};
	class Weapon_Bag_Base : Bag_Base {
		class assembleInfo;
	};
	class B_Boat_Transport_01_F;
	class O_Boat_Transport_01_F;
	class I_Boat_Transport_01_F;
	class B_Lifeboat;
	class C_Rubberboat;

	class NonStrategic;
	class House;
	class House_F;
	class ThingX;
	class NATO_Box_Base;
	class EAST_Box_Base;
	class IND_Box_Base;
	class Furniture_base_F;
	class WeaponHolder;
	class Items_base_F;
	class Wreck_Base;
	class FloatingStructure_F;
	class Lamps_base_F;
	
	//#include "CfgVehicles\Animal_Base_F.hpp"
	#include "CfgVehicles\Characters\cfg_NewPers.hpp"
	#include "CfgVehicles\Characters\cfgzZombie_Base.hpp"
	
	#include "CfgVehicles\House\cfgTentStorage.hpp"

	
	#include "CfgVehicles\Ammoboxes\cfg_Boat_Transport_Backpack.hpp"
//	#include "CfgVehicles\Ammoboxes\cfg_Generator_Backpack.hpp"
	#include "CfgVehicles\Ammoboxes\cfg_Holders.hpp"
	
	#include "CfgVehicles\Boat\cfg_B_Boat_Transport_01_F_SRV.hpp"
	#include "CfgVehicles\Boat\cfg_O_Boat_Transport_01_F_SRV.hpp"
	#include "CfgVehicles\Boat\cfg_I_Boat_Transport_01_F_SRV.hpp"
	#include "CfgVehicles\Boat\cfg_B_Lifeboat_SRV.hpp"
	#include "CfgVehicles\Boat\cfg_C_Rubberboat_SRV.hpp"
	
	#include "CfgVehicles\Furniture\cfg_Land_ShelvesMetal_F.hpp"
	#include "CfgVehicles\Furniture\cfg_Land_Metal_rack_F.hpp"
	#include "CfgVehicles\Furniture\cfg_Land_Icebox_F.hpp"
	#include "CfgVehicles\Furniture\cfg_Land_CashDesk_F.hpp"
	#include "CfgVehicles\Furniture\cfg_Land_CampingTable_F.hpp"
	#include "CfgVehicles\Furniture\cfg_Land_Metal_wooden_rack_F.hpp"
	#include "CfgVehicles\Furniture\cfg_ViruZ_Builds_Internal.hpp"
	
	#include "CfgVehicles\Electronics\cfg_Land_FMradio_F.hpp"
	#include "CfgVehicles\Electronics\cfg_Land_Camping_Light_F.hpp"
//	#include "CfgVehicles\Electronics\cfg_Land_Portable_generator_F.hpp"
};