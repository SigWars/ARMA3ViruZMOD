class CfgPatches {
	class viruz_config {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

class viruzConfigs {
	//server restart params
	EnableAutorestart = 0;							// Enable or disable autorestart function					
	RconPassword = "27091995";						// Rcon password, nned be the same of "serverCommandPassword" in config.cfg
	ServerDuration = (3 * 60 * 60); 				// Server restart time 3 * 60 * 60 = 3H restart
	DebugServerDuration = (20 * 60);				// isDebug = 1; Debug message to see time until restart and check if messages work!
	isDebug = 0;									// Enable debug mode
	UseBatfile = 0;									// In development
	NotificationTips[] =  							// Can use all, or oly one
	{
		"systemchatmessage",
		//"standardhintmessage",
		//"dynamictextmessage",
		"texttilesmessage"
	};	
};

#include "CfgObjectSpawner.hpp"
#include "CfgObjectInBuildingSpawner.hpp"
#include "CfgWreckSpawner.hpp"
