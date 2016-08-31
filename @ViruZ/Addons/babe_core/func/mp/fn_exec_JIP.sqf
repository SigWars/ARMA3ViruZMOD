   babe_em_get_JIP_array = [player];

   publicVariableServer "babe_em_get_JIP_array";

   waituntil {!IsNil "BABE_JIP_array"};

   {
      _para = _x select 0;

      _fnc = _x select 1;

      _type = _x select 2;


      switch (_type) do
      {
         case (1):
         {
              _code = format["_para call %1",_fnc];
              call compile _code;
         };
         case (2):
         {
              _code = format["_para spawn %1",_fnc];
              call compile _code;																																																			
         };
      };
   } foreach BABE_JIP_array;