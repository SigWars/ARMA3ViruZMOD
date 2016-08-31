   _dam = damage (_this select 0);
   if (((IsNull (_this select 3) && (_this select 4) == "") or (_this select 3 == _this select 0 && (_this select 4) == "")) && player == vehicle player) then 
   {
      _dam
   };