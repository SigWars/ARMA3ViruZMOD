   _dam = damage (_this select 0);
   if ((_this select 0 == _this select 3 or (_this select 4) == "") && (EM_busy or EM_climbing)) then 
   {
      _dam
   };