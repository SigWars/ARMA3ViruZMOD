class CfgPatches
{
	class viruz_builds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"A3_UI_F", "A3_Data_F","A3_Structures_F_Dominants"};
		version = 1.0;
		author = "SigWar";
		
	};
};

class CfgVehicleClasses
{
	class VIRUZ_Builds_A3
	{
		displayName = "ViruZ Builds";
	};
};

class CfgVehicles
{
	//class ReammoBox;
	class Strategic;
	class House_F;
	class Wall_F;
	class Static;
	class NonStrategic;
	
	class VIRUZ_Modules : Strategic
	{
		vehicleClass = "VIRUZ_Builds_A3";
		scope = 0;
		mapSize = 5.57744;
	};
	
	class VIRUZ_City_Gate_F: Wall_F
	{
		mapSize=4.6300001;
		author="$STR_A3_Bohemia_Interactive";
		_generalMacro="Land_City_Gate_F";
		scope=1;
		scopeCurator=2;
		displayName="$STR_A3_cfgVehicles_Land_City_Gate_F0";
		model="\A3\Structures_F\Walls\City_Gate_F.p3d";
		icon="iconObject_7x1";
		numberOfDoors=2;
		armor=4000;
		class AnimationSources
		{
			class LockedDoor_source
			{
				source="user";
				initPhase=0;
				animPeriod=0.1;
			};
			class Door_1_source
			{
				source="user";
				initPhase=0;
				animPeriod=1;
				sound="GateDoorsSound";
				soundPosition="Door_1_trigger";
			};
			class Door_1_handle_source
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
			class Door_2_source
			{
				source="user";
				initPhase=0;
				animPeriod=1;
				sound="GateDoorsSound";
				soundPosition="Door_2_trigger";
			};
			class Door_2_handle_source
			{
				source="user";
				initPhase=0;
				animPeriod=1;
			};
		};
		class UserActions
		{
			class OpenDoor_1
			{
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				displayName="$STR_DN_OUT_O_DOOR";
				position="Door_1_trigger";
				radius=3;
				onlyForPlayer=0;
				//condition="(this animationPhase ""Door_1_rot"" < 0.5) AND ((this getVariable ['bis_disabled_Door_1',0]) != 1) AND ((this animationPhase ""Door_2_rot"" < 0.01) OR (this animationPhase ""Door_2_rot"" > 0.03))";
				condition="((this animationPhase 'Door_1_rot') < 0.5) && ((this getVariable ['bis_disabled_Door_1',0]) != 1) && (cameraOn isKindOf 'CAManBase')";
				statement="this animate [""Door_1_rot"", 1]; this animate [""Door_Handle_1_rot_1"", 1]; this animate [""Door_Handle_1_rot_2"", 1]";
			};
			class CloseDoor_1
			{
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				displayName="$STR_DN_OUT_C_DOOR";
				position="Door_1_trigger";
				radius=3;
				onlyForPlayer=0;
				condition="this animationPhase ""Door_1_rot"" >= 0.5";
				statement="this animate [""Door_1_rot"", 0]; this animate [""Door_Handle_1_rot_1"", 0]; this animate [""Door_Handle_1_rot_2"", 0]";
			};
			class OpenDoor_2: OpenDoor_1
			{
				position="Door_2_trigger";
				//condition="(this animationPhase ""Door_2_rot"" < 0.5) AND ((this getVariable ['bis_disabled_Door_2',0]) != 1) AND ((this animationPhase ""Door_1_rot"" >= 0.1) OR ((this animationPhase ""Door_2_rot"" > 0.01) AND (this animationPhase ""Door_2_rot"" < 0.03)))";
				condition="((this animationPhase 'Door_2_rot') < 0.5) && ((this getVariable ['bis_disabled_Door_2',0]) != 1) && (cameraOn isKindOf 'CAManBase')";
				statement="this animate [""Door_2_rot"", 1]";
			};
			class CloseDoor_2: CloseDoor_1
			{
				position="Door_2_trigger";
				condition="(this animationPhase ""Door_2_rot"" >= 0.5) AND (this animationPhase ""Door_1_rot"" >= 0.1)";
				statement="this animate [""Door_2_rot"", 0]";
			};
			class CloseDoor_2_b: CloseDoor_2
			{
				condition="(this animationPhase ""Door_2_rot"" >= 0.5) AND (this animationPhase ""Door_1_rot"" < 0.1)";
				statement="this animate [""Door_2_rot"", 0.02]";
			};
		};
		actionBegin1="OpenDoor_1";
		actionEnd1="OpenDoor_1";
		actionBegin2="OpenDoor_2";
		actionEnd2="OpenDoor_2";
	};
	
	class VIRUZ_Net_Fence_Gate_F: Wall_F
	{
		mapSize=6.1599998;
		author="$STR_A3_Bohemia_Interactive";
		_generalMacro="Land_Net_Fence_Gate_F";
		scope=1;
		scopeCurator=2;
		displayName="Fance Gate";
		model="\A3\Structures_F\Walls\Net_Fence_Gate_F.p3d";
		icon="iconObject_10x1";
		vehicleClass="Structures_Fences";
		numberOfDoors=2;
		armor=7000;
		class AnimationSources
		{
			class LockedDoor_source
			{
				source="user";
				initPhase=0;
				animPeriod=0.1;
			};
			class Door_1_source
			{
				source="user";
				initPhase=0;
				animPeriod=1;
				sound="FenceGateDoorsSound";
				soundPosition="Door_1_trigger";
			};
			class Door_2_source
			{
				source="user";
				initPhase=0;
				animPeriod=1;
				sound="FenceGateDoorsSound";
				soundPosition="Door_2_trigger";
			};
		};
		class UserActions
		{
			class OpenDoor_1
			{
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				displayName="$STR_DN_OUT_O_DOOR";
				priority=0.40000001;
				position="Door_1_trigger";
				radius=1.5;
				onlyForPlayer=0;
				condition="((this animationPhase 'Door_1_rot') < 0.5) && ((this getVariable ['bis_disabled_Door_1',0]) != 1) && (cameraOn isKindOf 'CAManBase')";
				statement="([this, 'Door_1_rot'] call BIS_fnc_DoorNoHandleOpen)";
			};
			class CloseDoor_1: OpenDoor_1
			{
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				displayName="$STR_DN_OUT_C_DOOR";
				priority=0.2;
				condition="((this animationPhase 'Door_1_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door_1',0]) != 1) && (cameraOn isKindOf 'CAManBase')";
				statement="([this, 'Door_1_rot'] call BIS_fnc_DoorNoHandleClose)";
			};
			class OpenLockedDoor_1: OpenDoor_1
			{
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				condition="((this animationPhase 'Door_1_rot') < 0.1) && ((this getVariable ['bis_disabled_Door_1',0]) == 1) && (cameraOn isKindOf 'CAManBase')";
				statement="([this, 'Door_Locked_1_rot'] call BIS_fnc_LockedDoorNoHandleOpen)";
			};
			class OpenDoor_2
			{
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				displayName="$STR_DN_OUT_O_DOOR";
				priority=0.40000001;
				position="Door_2_trigger";
				radius=1.5;
				onlyForPlayer=0;
				condition="((this animationPhase 'Door_2_rot') < 0.5) && ((this getVariable ['bis_disabled_Door_2',0]) != 1) && (cameraOn isKindOf 'CAManBase')";
				statement="([this, 'Door_2_rot'] call BIS_fnc_DoorNoHandleOpen)";
			};
			class CloseDoor_2: OpenDoor_2
			{
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				displayName="$STR_DN_OUT_C_DOOR";
				priority=0.2;
				condition="((this animationPhase 'Door_2_rot') >= 0.5) && ((this getVariable ['bis_disabled_Door_2',0]) != 1) && (cameraOn isKindOf 'CAManBase')";
				statement="([this, 'Door_2_rot'] call BIS_fnc_DoorNoHandleClose)";
			};
			class OpenLockedDoor_2: OpenDoor_2
			{
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
				condition="((this animationPhase 'Door_2_rot') < 0.1) && ((this getVariable ['bis_disabled_Door_2',0]) == 1) && (cameraOn isKindOf 'CAManBase')";
				statement="([this, 'Door_Locked_2_rot'] call BIS_fnc_LockedDoorNoHandleOpen)";
			};
		};
		actionBegin1="OpenDoor_1";
		actionEnd1="OpenDoor_1";
		actionBegin2="OpenDoor_2";
		actionEnd2="OpenDoor_2";
	};
	
	class ViruZ_PierLadder_F: Static
	{
		mapSize=1.47;
		author="$STR_A3_Bohemia_Interactive";
		_generalMacro="Land_PierLadder_F";
		scope=1;
		scopeCurator=2;
		displayName="Long Metal Stair";
		model="\A3\Structures_F\Naval\Piers\PierLadder_F.p3d";
		icon="iconObject_3x2";
		vehicleClass="Structures_Transport";
		armor=1000;
		ladders[]=
		{
			
			{
				"Ladder_1_start",
				"Ladder_1_end"
			}
		};
	};
	
	class VIRUZ_GH_Stairs_F: NonStrategic
	{
		mapSize=7.8499999;
		author="$STR_A3_Bohemia_Interactive";
		_generalMacro="Land_GH_Stairs_F";
		scope=2;
		scopeCurator=0;
		displayName="Cinder Stair";
		model="\A3\Structures_F_EPC\Dominants\GhostHotel\GH_Stairs_F.p3d";
		vehicleClass="Structures_Commercial";
		cost=10000;
		selectionDamage="DamT_1";
		armor=1500;
	};
	
	class VIRUZ_Floor 	:	VIRUZ_Modules {};	
	class VIRUZ_Door 	: 	VIRUZ_Modules {};
	class VIRUZ_Garage	: 	VIRUZ_Door {};
	class VIRUZ_Walls	: 	VIRUZ_Door {};
	
	#include "VIRUZ_Floors\VIRUZ_Floors.hpp"
	#include "VIRUZ_Walls\VIRUZ_Walls.hpp"
	//#include "VIRUZ_Garages\VIRUZ_Garages.hpp"
	#include "VIRUZ_Doors\VIRUZ_Doors.hpp"
	//#include "VIRUZ_Plots\VIRUZ_Plots.hpp"
	//#include "VIRUZ_Foundations\VIRUZ_Foundations.hpp"
	//#include "VIRUZ_Ladders\VIRUZ_Ladders.hpp"
	//#include "VIRUZ_Windows\VIRUZ_Windows.hpp"
	//#include "VIRUZ_Objects\VIRUZ_Objects.hpp"
	
};

class VIRUZ_Misc
{
	file = "viruz_builds\VIRUZ_Misc\Functions";
	postInit = 1;
};

class CfgSounds
{
	// List of sounds (.ogg files without the .ogg extension)
	sounds[] = {DoorOpen,GarageOpen,DoorClose,DoorLock,DoorLocked,Ham0,Ham1,Ham2,Built0,Abort0};

	// Definition for each sound
	class DoorOpen
	{
		name = "DoorOpen"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\DoorOpen.ogg, 1, 0.9, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};
	// Definition for each sound
	class GarageOpen
	{
		name = "GarageOpen"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\GarageOpen.ogg, 1, 0.9, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};	
	// Definition for each sound
	class DoorClose
	{
		name = "DoorClose"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\DoorClose.ogg, 0.4, 0.7, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};
	// Definition for each sound
	class DoorLock
	{
		name = "DoorLock"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\DoorLock.ogg, 0.2, 1, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};
	// Definition for each sound
	class DoorLocked
	{
		name = "DoorLocked"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\DoorLocked.ogg, 0.5, 1.2, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};
	// Definition for each sound
	class Ham0
	{
		name = "Ham0"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\Ham0.ogg, 1, 0.9, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};
	// Definition for each sound
	class Ham1
	{
		name = "Ham1"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\Ham1.ogg, 1, 0.9, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};
	// Definition for each sound
	class Ham2
	{
		name = "Ham2"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\Ham2.ogg, 1, 0.9, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};
	// Definition for each sound
	class Built0
	{
		name = "Built0"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\Built0.ogg, 1, 1, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};
	class Built1
	{
		name = "Built1"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\Built1.ogg, 1, 1, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};
	class Built2
	{
		name = "Built2"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\Built2.ogg, 1, 1, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};
	
	// Definition for each sound
	class Abort0
	{
		name = "Abort0"; // Name for mission editor
		sound[] = {\viruz_builds\VIRUZ_Sounds\Abort0.ogg, 1, 1, 175}; // {filname, volume, pitch, fade}
		titles[] = {};
	};		
};	