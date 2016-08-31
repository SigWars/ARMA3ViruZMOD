	_str = _this;

	_arr = toArray _str;

	_newstr = "";

	for "_i" from 0 to (count _arr - 1) do
	{
		_num = _arr select _i;

		_newstr = _newstr + (str _num);
	};
	_idc = call compile _newstr;

	_idc