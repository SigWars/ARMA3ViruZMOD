params["_v"];

if(_v getVariable ["rds_civ_doors",false])then{
	{_v animateDoor [_x,1]}foreach ["doors_1","doors_2","doors_3"];
};