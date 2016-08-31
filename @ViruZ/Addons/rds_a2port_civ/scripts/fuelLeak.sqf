_k = _this select 1;

if(_k == "palivo")then{

	[_this select 0,_this select 2] spawn
	{
		_v = _this select 0;
		_f = _this select 1;
		_d =_v getHitPointDamage "HITfuel";
		while{_d<=_v getHitPointDamage "HITfuel" && alive _v}do
		{
			_v setFuel ((fuel _v) - (_f/400));		sleep 0.5;
		};
	};
};