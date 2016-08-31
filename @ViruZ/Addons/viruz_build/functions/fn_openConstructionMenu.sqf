viruz_build_inventoryHolder = _this select 0;
_dialog = createDialog "viruz_build_dialogConstructionMenu";
setMousePosition [0.5,0.5];
waitUntil {dialog};

{
	lbAdd [1500, _x select 0];
}
foreach viruz_build_array;

_display = uiNamespace getVariable "viruz_build_display";
_ctrl = _display displayCtrl 1500;
_ctrl lbSetSelected [viruz_build_categorieId, true];
_ctrl ctrlCommit 0.01;

waitUntil {[viruz_build_categorieId,"Categorie"] call viruz_fnc_updateConstructionMenu};

_ctrl = _display displayCtrl 1501;
_ctrl lbSetSelected [viruz_build_classnameId, true];
_ctrl ctrlCommit 0.01;

[] spawn
{
	disableSerialization;
	_display = uiNamespace getVariable "viruz_build_display";
	_control = _display displayCtrl 1503;
	
	_VecDir = [1,0,0];
	_VecNormal = [0,-0.5,1];
	_dir = 0;
	
	while {dialog} do
	{
		_dir = _dir + 2;
		_dir = _dir mod 360;
		_VecDirX = cos _dir;
		_VecDirY = sin _dir;
		_VecDir = [_VecDirX,_VecDirY,0.5 * _VecDirY];
		_VecNormal = [0,-0.5,1];
		
		_control ctrlSetModelDirAndUp [_VecDir,_VecNormal];
		_control ctrlCommit 0;
		
		sleep 0.04;
	};
};