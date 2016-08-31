#define CONTROL (_display displayctrl _idc)

disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
//		with uinamespace do {

			systemChat "Display crafting open";

//		};
	};
	case "onUnload": {
			systemChat "Display crafting close";
	};
};