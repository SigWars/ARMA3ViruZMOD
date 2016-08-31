_array = _this select 0;
_ref = _this select 1;
 
_dist = 9999999999;
_min = 0;

_stuffs = [];

{
   _o = getpos _x;
   _r = _ref;

   _d = _o distance _r;

   _min = _dist min _d;

   _dist = _min;

   if (_d == _min) then
   {
      _stuffs set [0, _x]; 
   } else
   {
      _stuffs pushback _x; 
   };

} foreach _array;