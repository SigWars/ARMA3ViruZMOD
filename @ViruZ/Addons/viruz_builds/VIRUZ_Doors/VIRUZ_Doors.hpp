//Wall With Door
class VIRUZ_WoodDoor_new : VIRUZ_Door
{
	scope = 2;
	displayName = "Wood Wall Door";
	model = "\viruz_builds\VIRUZ_Doors\WoodWall_DoorLock.p3d";
	author = "SigWar";
	numberOfDoors=1;
	
	class AnimationSources
	{
		class door
		{
			source = "user";
			animPeriod = 1;
			initPhase = 0;
			sound = "GenericDoorsSound";
		};		
	};
	
	class UserActions
	{
		class Open
		{
			displayName = "Open Door";
			position = "door_axis";
			radius = 2.3;
			onlyforplayer = true;
			//condition = "this animationPhase ""door"" == 0;";
			condition="((this animationPhase 'door') == 0) && ((this getVariable ['bis_disabled_Door_1',0]) != 1)";
			statement = "this animate [""door"", 1];";
		};
		class Close
		{
			displayName = "Close Door";
			position = "door_axis";
			radius = 2.3;
			onlyforplayer = true;
			condition = "this animationPhase ""door"" == 1;";
			statement = "this animate [""door"", 0];";
		};		
	};			
};
//Wall with Window
class VIRUZ_WoodWindow_new : VIRUZ_Door
{
	scope = 2;
	displayName = "Wood Window";
	model = "\viruz_builds\VIRUZ_Doors\WoodWall_Window.p3d";
	author = "SigWar";
	numberOfDoors=1;
	
	class AnimationSources
	{
		class door
		{
			source = "user";
			animPeriod = 1;
			initPhase = 0;
			sound = "GenericDoorsSound";
		};		
	};
	
	class UserActions
	{
		class Open
		{
			displayName = "Open Window";
			position = "window_axis";
			radius = 2.3;
			onlyforplayer = true;
			//condition = "this animationPhase ""door"" == 0;";
			condition="((this animationPhase 'door') == 0) && ((this getVariable ['bis_disabled_Door_1',0]) != 1)";
			statement = "this animate [""door"", 1];";
		};
		class Close
		{
			displayName = "Close Window";
			position = "door_axis";
			radius = 2.3;
			onlyforplayer = true;
			condition = "this animationPhase ""door"" == 1;";
			statement = "this animate [""door"", 0];";
		};		
	};			
};

class VIRUZ_WoodGate_new : VIRUZ_Door
{
	scope = 2;
	displayName = "Garage Gate";
	model = "\viruz_builds\VIRUZ_Doors\Viruz_Gate_New.p3d";
	author = "SigWar";
	numberOfDoors=1;
	
	class AnimationSources
	{
		class door1
		{
			source = "user";
			animPeriod = 1;
			initPhase = 0;
			sound = "OldWoodDoorsSound";
		};
		class door2 : door1 {};
	};
	
	class UserActions
	{
		class Open
		{
			displayName = "Open Garage";
			position = "doors_handlers";
			radius = 4.0;
			onlyforplayer = true;
			condition="((this animationPhase 'door1') == 0) && ((this getVariable ['bis_disabled_Door_1',0]) != 1)";
			statement = "this animate [""door1"", 1];this animate [""door2"", 1];";
		};
		class Close
		{
			displayName = "Close Garage";
			position = "doors_handlers";
			radius = 4.0;
			onlyforplayer = true;
			condition = "this animationPhase ""door1"" == 1;";
			statement = "this animate [""door1"", 0];this animate [""door2"", 0];";
		};		
	};			
};

/*class VIRUZ_Generic_Door : VIRUZ_Door
{
	scope = 2;
	displayName = "Wood Door Lockable";
	hiddenSelectionsTextures[] = {"viruz_builds\VIRUZ_Doors\Data\Wood_DoorLock.paa","viruz_builds\VIRUZ_Doors\Data\Wood_DoorLock.paa"};
	model = "\viruz_builds\VIRUZ_Doors\Wall_DoorLock.p3d";
	author = "SigWar";
	
	class AnimationSources
	{
		class door
		{
			source = "user";
			animPeriod = 1;
			initPhase = 0;
			sound = "GenericDoorsSound";
		};		
	};
	
	class UserActions
	{
		class Open
		{
			displayName = "Open Door";
			position = "door_axis";
			radius = 2.3;
			onlyforplayer = true;
			//condition = "this animationPhase ""door"" == 0;";
			condition="((this animationPhase 'door') == 0) && ((this getVariable ['bis_disabled_Door_1',0]) != 1) && ((this getVariable ['Locked',""0""]) != ""1"")";
			statement = "this animate [""door"", 1];";
		};
		class Close
		{
			displayName = "Close Door";
			position = "door_axis";
			radius = 2.3;
			onlyforplayer = true;
			condition = "this animationPhase ""door"" == 1;";
			statement = "this animate [""door"", 0];";
		};		
	};			
};*/
