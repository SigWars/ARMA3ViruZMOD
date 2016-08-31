params["_v"];

if(_this select 1 > 0)then
{
	//open door
	{_v animateDoor [_x,1]}foreach ["doors_1","doors_2","doors_3"];
	_v setVariable ["rds_civ_doors",true,true];
	if(_v getVariable ["rds_lock_cargo",false])then{
		_v lockCargo false;
	};
}else
{
	//close door
	{_v animateDoor [_x,0]}foreach ["doors_1","doors_2","doors_3"];
	_v setVariable ["rds_civ_doors",false,true];
	if(_v getVariable ["rds_lock_cargo",false])then{
		_v lockCargo true;
	};
};