/*
a: spare wheel script
attached to spare wheel object
detects if there is valid car nearby the spare wheel and if so, then performs check if nearest wheel can be replaced.

_w - spare wheel object
_t - vehicle type to look for
_a - array of wheels, not used now
*/
params["_w","_t","_a"];

private _p = missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", player];
//search for nearest car
private _v = nearestObject [_p, _t];
if(isNull _v)exitWith{hint "No car detected nearby"};

//search for nearest mem point
private _h = [];
{_h pushBack [ _p distance (_v modelToWorld (_v selectionPosition [_x,"memory"]) ), _x] }foreach ["HitLFWheel","HitRFWheel","HitLF2Wheel","HitRF2Wheel"];
_h sort true;
_h = _h select 0;

if(_h select 0 > 2)exitWith{hint format["No wheels to replace nearby (max: 2m, nearest %1m)",_h select 0]};

//check wheel damage
_d = _v getHitPointDamage (_h select 1) ;

if(_d < 0.95)exitWith{hint "That wheel seems to be intact"};




//systemChat format["zaraz to naprawieee %1",_w];

private _d = "Sign_Sphere100cm_F" createVehicleLocal [0,0,0];
private _pos = (_v modelToWorld (_v selectionPosition [_h select 1,"memory"]));
_d setpos (_pos vectorAdd [0,0,0.2]);
_d setObjectTexture [0,""];
_p attachTo [_d,[0,0,0]];
_p playMove "Acts_carFixingWheel";
private _t = time +15;
private _c = true;
if(_d getRelDir _v > 180)then{_d setDir (getDir _v - 90)}else{_d setDir (getDir _v + 90)};
while{time<_t}do{
	if(_v distance (_v modelToWorld (_v selectionPosition [_h select 1,"memory"])) > 3)exitWith{_c=false};
	sleep 1;
};
if(!_c)exitWith{};

_p switchMove 'AinvPknlMstpSlayWrflDnon_medic';
deleteVehicle objectParent _w;
_v setHitPointDamage [(_h select 1) ,0];
sleep 2;

detach _p;
deleteVehicle _d;