
  _xSum = 0;
  _ySum = 0;
  _zSum = 0;
  {
    _xSum = _xSum + (_x select 0);
    _ySum = _ySum + (_x select 1);
    _zSum = _zSum + (_x select 2);
  } forEach _this;
  _xSum = _xSum / count _this;
  _ySum = _ySum / count _this;
  _zSum = _zSum / count _this;
  [_xSum, _ySum, _zSum];
