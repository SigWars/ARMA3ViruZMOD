/*
ViruZCalc_precisepos.sqf
by SigWar
Return worldprecision for object based on object position, it return WorldSpace,Worldprecision,[vectordir,vectorup]
*/
private["_object","_isWater","_positionASL","_positionATL","_posicao","_posicao_calc","_posicao_final","_worldvectorDirUp"];

_object = _this;
_isWater = (surfaceIsWater position _object);
		
	if (_isWater) then {
		_positionASL =  getPosASL _object;
		_positionATL = ASLtoATL _positionASL;
		_posicao = [(_positionATL call viruz_preciseposcalc), vectordir _object, vectorup _object];
	} else {
		_positionATL = getposATL _object;
		_posicao = [(_positionATL call viruz_preciseposcalc), vectordir _object, vectorup _object];
	};
	_worldvectorDirUp = [_posicao select 1,_posicao select 2];
	_posicao_calc = _posicao deleteAt 0;
	_posicao_final = (_posicao_calc select 0) vectorAdd (_posicao_calc select 1);
	
[_posicao_final,_posicao,_worldvectorDirUp]