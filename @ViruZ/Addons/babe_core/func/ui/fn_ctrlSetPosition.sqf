_ctrl = _this select 0;
_w = _this select 1;
_h = _this select 2;
_pos = _this select 3;


switch _pos do
{
	case "TL":
	{
		_ctrl ctrlSetPosition [safeZoneX, safeZoneY+_h, safeZoneW*_w, safeZoneH*_h];
	};
	case "TR":
	{
		_ctrl ctrlSetPosition [safeZoneX+safeZoneW-_w, safeZoneY+_h, safeZoneW*_w, safeZoneH*_h];
	};
	case "BL":
	{
		_ctrl ctrlSetPosition [safeZoneX, safeZoneY+safeZoneH -_h, safeZoneW*_w, safeZoneH*_h];
	};
	case "BR":
	{
		_ctrl ctrlSetPosition [safeZoneX+safeZoneW-_w, safeZoneY+safeZoneH -_h, safeZoneW*_w, safeZoneH*_h];
	};
};