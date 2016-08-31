	if (babe_core_mbdown) then 
	{
		_bg = (finddisplay 49) displayctrl 21251327; 
		_menu = (finddisplay 49) displayctrl 212513;

		_cp = ctrlPosition _bg;		

		_bg ctrlSetPosition GetMousePosition; //babe_core_escM_mousepos;
		_bg ctrlcommit 0;
		_menu ctrlSetPosition GetMousePosition; //babe_core_escM_mousepos;
		_menu ctrlcommit 0;
	};