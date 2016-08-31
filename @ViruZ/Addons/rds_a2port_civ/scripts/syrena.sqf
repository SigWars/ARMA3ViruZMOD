params["_v",["_m",-1]];

if(_m>0)then{
	switch(_m)do{
		case 0: {_v setVariable ["rds_siren",true,true]};
		case 1: {_v setVariable ["rds_siren",false,true]};
	};
};

private _d = createAgent ["VirtualMan_F", [0,0,0], [], 0, "FORM"];
//(group player) createUnit ["VirtualMan_F", position player, [], 100, "FORM"] ;
//createAgent ["VirtualMan_F", [0,0,0], [], 0, "FORM"];

_d moveInTurret [_v,[0]];

if(_v getVariable ["rds_siren",false])exitWith{
	_v setVariable ["rds_siren",false,true];
	_d action ["searchlightoff",_v];
	deleteVehicle _d;
};

_v setVariable ["rds_siren",true,true];
_v setVariable ["rds_siren_sound",true,true];

_d action ["searchlighton",_v];
deleteVehicle _d;


while{_v getVariable "rds_siren" AND (alive _v)}do{
	if(_v getVariable "rds_siren_sound")then{playSound3D ["rds_a2port_civ\scripts\police_siren.ogg", _v, false, getPosASL _v, 1, 1, 400]};
	sleep 2.521;
};
