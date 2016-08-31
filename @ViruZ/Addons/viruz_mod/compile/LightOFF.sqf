_pos = getMarkerPos "center";
_Array = [
	"Land_LampDecor_F",
	"Land_LampHalogen_F",
	"Land_LampHarbour_F",
	"Land_LampShabby_F",
	"Land_LampStreet_F",
	"Land_LampStreet_small_F",
	"Land_PowerPoleWooden_L_F",
	"Land_Runway_PAPI",
	"Land_Runway_PAPI_2",
	"Land_Runway_PAPI_3",
	"Land_Runway_PAPI_4",
	"Land_Runway_edgelight",
	"Land_TTowerBig_1_F",
	"Land_TTowerBig_2_F",
	"Land_LightHouse_F"
];
_Lamps = nearestObjects [_pos, _Array, 10000];
{
	_x setHit ["Light_1_hitpoint", 1];
	_x setHit ["Light_2_hitpoint", 1];
	_x setHit ["Light_3_hitpoint", 1];
	_x setHit ["Light_4_hitpoint", 1];
} forEach _Lamps;