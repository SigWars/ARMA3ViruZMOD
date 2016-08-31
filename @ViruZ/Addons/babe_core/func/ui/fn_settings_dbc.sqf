_ctrl = _this select 0;

_cur = lnbCurSelRow _ctrl;

uinamespace setvariable ["cur_bind", _cur];

_dta = _ctrl lnbValue [_cur,0];

_mod = _ctrl lnbdata [_cur, 0];


switch (_dta) do
{
   case 0:
   {
      [_ctrl, _mod] call babe_core_fnc_startbind;
   };
   case 1:
   {
      [_ctrl, _mod] call babe_core_fnc_changesetting;
   };
   case 2:
   {

   };
   case 3:
   {
      [_ctrl, _mod] call babe_core_fnc_submenu;

      uinamespace setvariable ["cur_mod", _mod];
   };
   case 4:
   {

   };
   case 5:
   {

   };
};