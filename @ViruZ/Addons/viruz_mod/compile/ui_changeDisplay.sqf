private["_state"];
disableSerialization;
_state = uiNamespace getVariable ['DZ_displayUI', 0];

// Hard code the GUI on and the Debug Monitor off
if (viruzState != 0) then {
	3 cutRsc ["playerStatusGUI", "PLAIN",0];
	//Update GUI
	call player_updateGui;
	call ui_initDisplay;
	hintSilent "";
};
