class RscDisplayMPInterrupt: RscStandardDisplay
{
	onLoad="[""onLoad"",_this,""RscDisplayMPInterrupt"",'GUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	onUnload="[""onUnload"",_this,""RscDisplayMPInterrupt"",'GUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	movingEnable=0;
	enableSimulation=1;
	
	
	class controls
	{
		delete ButtonAbort;
		
		class ButtonLobby: RscButtonMenu
		{
			idc = 20004;

			text = "Back to lobby"; //--- ToDo: Localize;
			x = 0.44094 * safezoneW + safezoneX;
			y = 0.835957 * safezoneH + safezoneY;
			w = 0.100836 * safezoneW;
			h = 0.0338065 * safezoneH;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0.8};
			onButtonClick = "call player_bakckTolobby; [""epicFail"",false,2] call BIS_fnc_endMission;";
		};
	};
	
};	