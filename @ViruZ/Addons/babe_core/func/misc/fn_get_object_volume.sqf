_o = _this select 0;
 
_bb = boundingboxreal _o;

_bb1 = _bb select 0;
_bb2 = _bb select 1;

_a = abs(bb1 select 0) + abs(_bb2 select 0);
_b = abs(bb1 select 1) + abs(_bb2 select 1);
_c = _bb2 select 2;

_vol = _a*_b*_c;

_vol