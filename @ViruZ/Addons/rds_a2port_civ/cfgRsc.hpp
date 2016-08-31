
class RscInGameUI
{
	class RscUnitInfo;

	class RDS_RscUnitInfoCar: RscUnitInfo
	{
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); ['onLoad',_this,'RscUnitInfo','IGUI'] call a3_ui_initDisplay; _this spawn RDS_fnc_migacze";
	};
};