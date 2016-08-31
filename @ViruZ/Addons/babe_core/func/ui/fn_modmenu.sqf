	disableSerialization; 

	babe_core_mbdown = false;
	babe_core_mbblock = false;
	
	babe_core_modmenu_keysdown = [];
	
	_menuW = 3.5;
	_menuH = 4;


	_ctrlbg = findDisplay 49 ctrlCreate ["BABE_CORE_Listbg", 21251327];
	_ctrl = findDisplay 49 ctrlCreate ["BABE_CORE_List", 212513];

	(findDisplay 49) displayaddeventhandler ["MouseButtonDown", {if (_this select 4) then {babe_core_mbdown = true};}];
	(findDisplay 49) displayaddeventhandler ["MouseButtonUp", {babe_core_mbdown = false}];


	_ctrlbg CtrlsetPosition [safezoneX+safezoneW - safezoneW/_menuW - safezoneW/64, safezoneY+safeZoneH - safezoneH/_menuH - safezoneH/16, safezoneW/_menuW, safezoneH/_menuH];
	_ctrl CtrlsetPosition [safezoneX+safezoneW - safezoneW/_menuW - safezoneW/64, safezoneY+safeZoneH - safezoneH/_menuH - safezoneH/16, safezoneW/_menuW, safezoneH/_menuH];

	_ctrlbg ctrlcommit 0;
	_ctrl ctrlcommit 0;
  

	[_ctrl] call babe_core_fnc_initmenu;

	["EH_ModMenu2", "babe_core_mbdown", [], "babe_core_fnc_modmenu_loop", [], false, "", [], -1] call babe_core_fnc_addEH;