[_this select 0] spawn {
	private["_v"];

	_v=_this select 0;
	while{isEngineOn _v}do
	{
		_g = _v animationPhase "shiftChange1";
		waitUntil {sleep 1;_g != _v animationPhase "shiftChange1" OR (not(isEngineOn _v))};
		if(_v doorPhase "gearbox" == 1)then{_v animateDoor ["gearbox",0]}else{_v animateDoor ["gearbox",1]};
		sleep 2.5;
	};
};