_unit = _this select 0;

_veh = _this select 1;

_seat = _this select 2;

_inside = _this select 3;

_tur = _this select 4;


switch (_seat) do
{
   case (1):
   {
      if (_inside) then
      {
         if (local _veh) then
         {
            _unit action ["MoveToDriver", _veh];
         } else
         {
            0 = [[_unit, "action",["MoveToDriver", _veh]], "babe_em_fnc_command_abc", 1, 1, player, false, false] call babe_em_fnc_MP;
         };
      } else
      {
         _unit action ["GetInDriver", _veh];
      };
   };
   case (2):
   {
      if (_inside) then
      {
         if (local _veh) then
         {
            _unit action ["MoveToTurret", _veh, [_tur]];
         } else
         {
            0 = [[_unit, "action",["MoveToTurret", _veh, [_tur]]], "babe_em_fnc_command_abc", 1, 1, player, false, false] call babe_em_fnc_MP;
         };
      } else
      {
         _unit action ["GetInTurret", _veh, [_tur]];
      };
   };
   case (3):
   {
      _freeseats = [];
      _freeseat = 0;
      {
         _ind = _x getCargoIndex _veh;
         _freeseats pushback _ind;
      } foreach (crew _veh);

      if (count _freeseats > 0) then
      {
         _freeseat = _freeseats select floor (random (count _freeseats));
      };

      if (_inside) then
      {
         if (local _veh) then
         {
            _unit action ["MoveToCargo", _veh, _freeseat];
         } else
         {
            0 = [[_unit, "action",["MoveToCargo", _veh, _freeseat]], "babe_em_fnc_command_abc", 1, 1, player, false, false] call babe_em_fnc_MP;
         };
      } else
      {
         _unit action ["GetInCargo", _veh];
      };
   };
};




