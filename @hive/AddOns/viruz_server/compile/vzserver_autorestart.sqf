/*=================================================================================================================
  Timed Restart Script
  
  by Weeks
 [15thMEU(SOC)]
 Edited by SigWar for ViruzMod server
=================================================================================================================*/

private ["_EnableAutorestart","_RconPassword","_ServerDuration","_Debug_ServerDuration","_UseBatfile","_timeStart","_timeSinceStart","_shutdownSuccess","_isDebug","_msg30mins","_msg15mins","_msg5mins","_timeUntilRestart","_30minspassed","_15minspassed","_5minspassed",
"_60secondspassed","_restartTittle","_restartKick","_kickall"];


_EnableAutorestart = getNumber(ConfigFile >> "viruzConfigs" >> "EnableAutorestart");
_RconPassword = getText(ConfigFile >> "viruzConfigs" >> "RconPassword");
_ServerDuration = getNumber(ConfigFile >> "viruzConfigs" >> "ServerDuration");
_Debug_ServerDuration = getNumber(ConfigFile >> "viruzConfigs" >> "DebugServerDuration");
_isDebug = getNumber(ConfigFile >> "viruzConfigs" >> "isDebug");
_UseBatfile = getNumber(ConfigFile >> "viruzConfigs" >> "UseBatfile");

if (_EnableAutorestart < 1) exitWith { diag_log "VIRUZ WARNNIG :: Auto Restart script disabled in viruz_config.pbo"};

if(_isDebug > 0) then
{
	_ServerDuration = _Debug_ServerDuration;
};

_restartTittle = "Server Restart";
_restartKick = ['#FFFF00',"The server will shut down in less than 30 minutes."];
_msg30mins = ['#FFFF00',"The server will shut down in less than 30 minutes."];
_msg15mins = ['#FFFF00',"The server will shut down in less than 15 minutes."];
_msg5mins = ['#FFFF00',"The server will shut down in less than 5 minutes."];
_msg1mins = ['#FFFF00',"The server will shut down in less than 60 seconds."];

_kickall = false;
_30minspassed = false;
_15minspassed = false;
_5minspassed = false;
_60secondspassed = false;

_timeStart = diag_tickTime;

while{true} do
{
	_timeSinceStart = diag_tickTime - _timeStart;
	_timeUntilRestart = _ServerDuration - _timeSinceStart;
	
	if(_isDebug > 0) then
	{
		diag_log format ["Time Since Start: %1, Time Until Restart: %2", _timeSinceStart, _timeUntilRestart];
		[_restartTittle,_msg1mins] call VIRUZ_GlobalTextBroadcast;
		
	};
	
	switch true do
	{
		case ((_timeUntilRestart < (0.5 * 60)) && !_60secondspassed && !_kickall) : 
		{
			[_restartTittle,_restartKick] call VIRUZ_GlobalTextBroadcast; // using Defent's mission broadcast format for our messages
			diag_log "Server will lock and kick all players now";
			_kickall = true;
			_60secondspassed = true;
			_5minspassed = true;
			_15minspassed = true;
			_30minspassed = true;
			_RconPassword serverCommand "#lock";
			
			{
				_RconPassword serverCommand format ["#kick %1",name _x];
			} forEach allPlayers;
		};
		case ((_timeUntilRestart < (1 * 60)) && !_60secondspassed) : 
		{
			[_restartTittle,_msg1mins] call VIRUZ_GlobalTextBroadcast; // using Defent's mission broadcast format for our messages
			diag_log "60 seconds until server restart.";
			_60secondspassed = true;
			_5minspassed = true;
			_15minspassed = true;
			_30minspassed = true;
		};
		case ((_timeUntilRestart < (5 * 60)) && !_5minspassed) : 
		{
			[_restartTittle,_msg5mins] call VIRUZ_GlobalTextBroadcast;
			diag_log "5 minutes until server restart.";
			_5minspassed = true;
			_15minspassed = true;
			_30minspassed = true;
		};
		case ((_timeUntilRestart < (15 * 60)) && !_15minspassed) : 
		{
			[_restartTittle,_msg15mins] call VIRUZ_GlobalTextBroadcast;
			diag_log "15 minutes until server restart.";
			_15minspassed = true;
			_30minspassed = true;
		};
		case ((_timeUntilRestart < (30 * 60)) && !_30minspassed) : 
		{
			[_restartTittle,_msg30mins] call VIRUZ_GlobalTextBroadcast;
			diag_log "30 minutes until server restart.";
			_30minspassed = true;
		};
	};
	
	if(_timeSinceStart > (_ServerDuration + 60)) then
	{
		
		if (_UseBatfile > 0) then {
					// in development
		} 
		else
		{
			diag_log "Restart timeout elapsed, attempting server shutdown.";
			_shutdownSuccess = _RconPassword serverCommand "#shutdown";
			if(_shutdownSuccess) then
			{
				diag_log "Shutting down server!";
			}
			else
			{
				diag_log "Shutdown failed!";
			};
		
		
		};
		
	};
	
	sleep 15;
};