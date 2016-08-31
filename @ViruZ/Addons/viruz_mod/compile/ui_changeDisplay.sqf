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
viruzDebug = false;

/*
switch (_state) do {
	case 0: {
		if (viruzState != 0) then {
			3 cutRsc ["playerStatusGUI", "PLAIN",0];
			//Update GUI
			call player_updateGui;
			call ui_initDisplay;
			hintSilent "";
		};
		viruzDebug = false;
	};
	case 1: {
		if (viruzState != 1) then {
			3 cutRsc ["playerStatusGUI", "PLAIN",0];
			//Update GUI
			call player_updateGui;
			call ui_initDisplay;
		};
		viruzDebug = true;
	};
	case 2: {
		if (viruzState != 2) then {
			3 cutRsc ["default", "PLAIN",0];
			hintSilent "";
		};
		viruzDebug = false;
	};
};
viruzState = _state;
*/