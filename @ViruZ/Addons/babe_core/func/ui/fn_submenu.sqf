_ctrl = _this select 0;

_mod = _this select 1;

_cur = lnbCurSelRow _ctrl;

_dta = _ctrl lnbText [_cur, 0];

//_mod = _ctrl lnbdata [_cur, 0];


switch (_dta) do
{
   case "Keys":
   {
      [_ctrl, _mod] call babe_core_fnc_getkeybinds;
   };
   case "Settings":
   {
      [_ctrl, _mod] call babe_core_fnc_getsettings;
   };
   case "Back":
   {
      [_ctrl, _mod] call babe_core_fnc_initmenu;
   };
};