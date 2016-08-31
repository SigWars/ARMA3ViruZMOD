_ctrl = _this select 0;

_mod = _this select 1;

_mod = uinamespace getvariable "cur_mod";

_cur = lnbCurSelRow _ctrl;

_set_change = profilenamespace getvariable (_mod+"_s"+(str _cur));

_txt = (_set_change select 0) select 0;

_dta = (_set_change select 0) select 1;

_datatype = _set_change select 1;

switch (_dta) do
{
   case (0):
   {
      _ctrl lnbSetText [[_cur,1],"On"];

      profilenamespace setvariable [(_mod+"_s"+(str _cur)), [[1, 1], _datatype]];
   };
   case (1):
   {
      _ctrl lnbSetText [[_cur,1],"Off"];

      profilenamespace setvariable [(_mod+"_s"+(str _cur)), [[1, 0], _datatype]];
   };
};

