   _para = _this select 0;

   _fnc = _this select 1;

   _type = _this select 2;

   _receiver = _this select 3;

   _client = _this select 4;

   _local = _this select 5;

   _perst = _this select 6;
   
   babe_mp = [_para,_fnc,_type];

   switch (_receiver) do
   {
      case (1):
      {
          publicvariable "babe_mp";
      };
      case (2):
      {
          publicvariableServer "babe_mp";
      };
      case (3):
      {
         if (typeName _client == "SCALAR") then
         {
            _men = (player nearEntities [["CaManBase"], _client]) - [player];
            {
               _owner = owner _x;

               if (_owner == 0) then
               {
                  publicvariableServer "babe_mp";
               } else
               {
                  _owner publicvariableClient "babe_mp";
               };
            } foreach _men;
         } else
         {
               _owner = owner _client;

               if (_owner == 0) then
               {
                  publicvariableServer "babe_mp";
               } else
               {
                  _owner publicvariableClient "babe_mp";
               };
         };
      };
   };
   if (_perst) then
   {
         if (IsServer) then
         {
            BABE_JIP_array = BABE_JIP_array + [[_para, _fnc, _type]];
         } else
         {
            babe_set_JIP_array = [_para,_fnc,_type];
            
            publicvariableServer "babe_set_JIP_array";
         };
   };
   if (_local) then
   {
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
   };