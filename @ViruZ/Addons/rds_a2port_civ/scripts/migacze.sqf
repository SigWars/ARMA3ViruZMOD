sleep 0.1;
//systemChat "start";
if(isNull (uiNamespace getVariable ["RDS_Car_Ctrl",displayNull]) )then
{
	disableSerialization;
	uiNameSpace setVariable ["RDS_Car_Ctrl",_this select 0];

	_c = uiNamespace getVariable "RDS_Car_Ctrl";
	_s = (_c displayCtrl 113);

	_p = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
	_v = vehicle _p;

	while{not(isNull _s)}do
	{
		if(driver _v isEqualTo _p)then{
			if(inputAction "evasiveLeft" > 0)then{
				if(not(_v getVariable ["rds_blinker_left",false]))then{
					_v setVariable ["rds_blinker_left",true,true];
					_v setVariable ["rds_blinker_right",false,true];
					_v setVariable ["rds_blinker_emr",false,true];
					_v spawn {
						while{_this getVariable "rds_blinker_left"}do
						{
							_this animateDoor ["blinker_L",1];
							sleep 0.4;
							_this animateDoor ["blinker_L",0];
							sleep 0.4;
						};
					};
				}else{
					_v setVariable ["rds_blinker_left",false,true];
				};
				sleep 0.5;
			};
			if(inputAction "evasiveRight" > 0)then{
				if(not(_v getVariable ["rds_blinker_right",false]))then{
					_v setVariable ["rds_blinker_right",true,true];
					_v setVariable ["rds_blinker_left",false,true];
					_v setVariable ["rds_blinker_emr",false,true];
					_v spawn {
						while{_this getVariable "rds_blinker_right"}do
						{
							_this animateDoor ["blinker_R",1];
							sleep 0.4;
							_this animateDoor ["blinker_R",0];
							sleep 0.4;
						};
					};
				}else{
					_v setVariable ["rds_blinker_right",false,true];
				};
				sleep 0.5;
			};
			if(inputAction "reloadMagazine" > 0)then{
				if(not(_v getVariable ["rds_blinker_emr",false]))then{
					_v setVariable ["rds_blinker_emr",true,true];
					_v setVariable ["rds_blinker_right",false,true];
					_v setVariable ["rds_blinker_left",false,true];
					_v spawn {
						while{_this getVariable "rds_blinker_emr"}do
						{
							_this animateDoor ["blinker_R",1];
							_this animateDoor ["blinker_L",1];
							sleep 0.4;
							_this animateDoor ["blinker_R",0];
							_this animateDoor ["blinker_L",0];
							sleep 0.4;
						};
					};
				}else{
					_v setVariable ["rds_blinker_emr",false,true];
				};
				sleep 0.5;
			};
		};
		sleep 0.01;
	};
	//player globalChat "definitywny koniec";
	uiNameSpace setVariable ["RDS_Car_Ctrl",displayNull];
};