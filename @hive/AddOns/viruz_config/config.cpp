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
	EnableAutorestart = 1;
	RconPassword = "27091995";
	ServerDuration = (3 * 60 * 60); //(3 * 60 * 60);
	DebugServerDuration = (1 * 60); //20 * 60
	isDebug = 0;
	UseBatfile = 0;									// in development
	NotificationTips[] =  							// Can use all, or only one
	{
		"standardhintmessage",
		"systemchatmessage",
		"dynamictextmessage",
		"texttilesmessage"
	};	
};


#include "CfgObjectSpawner.hpp"
#include "CfgObjectInBuildingSpawner.hpp"
#include "CfgWreckSpawner.hpp"
