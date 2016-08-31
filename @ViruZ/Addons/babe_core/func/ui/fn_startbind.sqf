_ctrl = _this select 0;

_mod = _this select 1;

_cur = lnbCurSelRow _ctrl;

_bind_change = profilenamespace getvariable (_mod+"_b"+(str _cur));

_txt = (_bind_change select 0) select 0;

_ctrl lnbSetText [[_cur,1],"..."];

uinamespace setvariable ["cur_bind", _cur];

EM_input_pls = true;

babe_core_modmenu_keysdown = [];