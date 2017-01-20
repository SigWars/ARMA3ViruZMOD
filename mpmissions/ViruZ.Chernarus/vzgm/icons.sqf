#define VZGM_CTRL ((uiNamespace getVariable "vzgmHudDisp") displayCtrl (46300 + _index))
#define SHOW_HUD (!visibleMap) && {(alive player) && (count units group player > 1)} && {cameraView in ["INTERNAL","EXTERNAL","GUNNER"]}

vzgmIconsName = {
    private ["_distance","_index","_makeIcons","_pName","_pIcons","_pGicon","_plist","_pPos","_removeIcon","_scale","_screen","_sx","_sy","_tag","_uc","_pUnits"];
    _pIcons = player getVariable "vzgmHudpIcons";
    _makeIcons = false;
	_removeIcon = false;
    _pUnits = [];
    _uc = 0;
	_plist = units group player;
	{
		if ((!isNull _x) && {isPlayer _x} && {alive _x}) then {_pUnits set [_uc,_x];_uc = _uc + 1;};
	} count _plist;

    if (isNil "_pIcons") then {
        _makeIcons = true;
    } else {
        if (count(_pIcons) < _uc) then {_makeIcons = true;};
        if (count(_pIcons) > _uc) then {_makeIcons = true;_removeIcon = true;};
    };
    if (_makeIcons)then {
        _pIcons = [];
		_pGicon = "vzgm\ui\igui_side_indep_ca.paa";
        for "_markerIndex" from 0 to (_uc - 1) do {_pIcons set [_markerIndex,_pGicon];};
        player setVariable ["vzgmHudpIcons",_pIcons];
    };

	_index = 0;
    {
		_pName = name _x;
		_pPos = getPosATL _x;
		if (surfaceIsWater _pPos) then {_pPos = getPosASL _x;};
        _distance = _pPos distance player;
		if ((_distance > 1) && {_distance < 2500}) then {
			_pPos set [2,(_pPos select 2) + 1.5];
			_screen = worldToScreen _pPos;
			_pIcon = _pIcons select _index;
			if (tagName) then {_tag = composeText [image _pIcon," ",_pName];} else {_tag = composeText [image _pIcon];};
			if ((count _screen) > 1) then {
				_scale = 0;
				_sx = _screen select 0;
				_sy = _screen select 1;
				if (_distance < 200) then {_scale = .3;} else {_scale = 1 min ((1 - ((_distance) - 3) / 15) max .3);};	
				VZGM_CTRL ctrlSetStructuredText _tag;
				VZGM_CTRL ctrlSetPosition [_sx,_sy,.99,.65];
				VZGM_CTRL ctrlSetScale _scale;
				VZGM_CTRL ctrlSetFade ((1 - _scale) / 2);
				VZGM_CTRL ctrlCommit 0;
				VZGM_CTRL ctrlShow true;
			} else {
				VZGM_CTRL ctrlShow false;
			};
		} else {
			VZGM_CTRL ctrlShow false;		
		};
        _index = _index + 1;
    } count _pUnits;
	if (_removeIcon) then {VZGM_CTRL ctrlShow false;};
};

vzgmInit = {	
    if (!isNil "vzgmHandle") then {terminate vzgmHandle;};
    vzgmHandle = [] spawn {
        uiSleep 1;
        while {true} do {
            waitUntil {uiSleep 1;SHOW_HUD};
			609 cutRsc ["VZGMHud_Rsc","PLAIN"];
            while {SHOW_HUD} do {
				call vzgmIconsName;
				if (commandingMenu in ["RscTeam","#User:BIS_Menu_GroupCommunication"]) then {showCommandingMenu "";};
                uiSleep .001;
            };
            609 cutText ["","PLAIN"];
        };
    };	
};