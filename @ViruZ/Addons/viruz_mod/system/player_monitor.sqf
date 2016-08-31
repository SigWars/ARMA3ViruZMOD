if (isServer) then {
	waitUntil{viruz_preloadFinished};
};
_id = [] execFSM "\z\addons\viruz_mod\system\player_monitor.fsm";