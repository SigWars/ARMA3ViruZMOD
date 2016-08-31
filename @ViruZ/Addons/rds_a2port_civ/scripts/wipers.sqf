private ["_v"];

_v = _this select 0;
if((_this select 1) == 1)then{_v animate ["wipers", 0]}else
{
	_v animate ["wipers", 1];
	sleep 1;
	while {(alive _v) AND (_v animationPhase "wipers" == 1)} do
	{
		//_v say "RHS_gaz66_wipers";
		_v animateDoor ["wipers",1];
		sleep 1.5;
		_v animateDoor ["wipers",0];
		sleep 1.5;
	};
};