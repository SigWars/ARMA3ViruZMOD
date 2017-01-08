/*
ViruZClient_move_object
By SigWar
ViruZ Build Syetem With custom snap
*/
private ["_distance","_direction","_high","_adjustRack","_currentDistanceDiff","_distanceDiff","_search_range","_spot_positionA","_spot_positionB","_object", "_config", 
"_type", "_attachToPlayer", "_object_types", "_target_spots","_height_diff","_object_height","_target_height","_distance_diff","_object_pos","_target_pos",
"_best_distance_object","_best_height_object","_position", "_nearest_objects", "_closest_spot", "_closest_distance","_spot_marker","_target_object","_pos",
"_offsetDir","_possible_targets","_current_distance_diff","_current_height_diff","_spot_position","_calculated_pos","_best_spot_position","_best_spot","_location",
"_dir","_VecDir","_VecNormal","_novadir","_vectorOffset","_bbr","_maxSize","_offset","_isWater","_ownerTODB","_ownerUID","_objectID","_objectUID","_hasGenerator",
"_findObject","_metros","_cansave","_AttchPosition","_positionASL","_positionATL","_worldvectorDirUp","_posicao","_posicao_calc","_posicao_final","_direcao","_deltime"];
	
    VIRUZ_Build_object = _this select 0;
    VIRUZ_Build_action = _this select 1;
	_hasGenerator = _this select 2;
	VIRUZ_Build_type = typeOf VIRUZ_Build_object;
	_cansave = true;
	_AttchPosition = getPos Player;
	
	if (VIRUZ_Build_action == "MoveObject") then {
		private ["_hasmags", "_hasitems", "_hasweapons", "_totalcount"];
		
		_hasmags = MagazineCargo VIRUZ_Build_object;
		_hasitems = ItemCargo VIRUZ_Build_object;
		_hasweapons = WeaponCargo VIRUZ_Build_object;
		
		_totalcount = + count _hasmags + count _hasitems + count _hasweapons;
		
		if (_totalcount > 0) exitWith { 
			cutText ["You cant move objects with itens inside", "PLAIN DOWN"];
			_cansave = false;
			vz_cant_Build = false;
		};
	};
	
	if (_hasGenerator) then {
		
		_findObject = nearestObjects [player, ["Land_Portable_generator_F"], viruz_maxBuildDistance];
			
			if (count _findObject > 0 ) then {
				ViruZ_Generator = _findObject select 0;
				if !(isNull ViruZ_Generator) then {
					_GeneratorUID = ViruZ_Generator getVariable ["OwnerUID","0"];
					_ownerTODB = str( 'B'+ _GeneratorUID );
					_ownerUID = _GeneratorUID;
				};
				//cuttext [format ["Generator Detected! and Owner is %1 and to DB is %2",_GeneratorUID,_ownerTODB],"PLAIN DOWN",1];
			} else {
				//doubkle check to prevent crash!!
				_ownerTODB = str( 'B'+ getPlayerUID player );
				_ownerUID = getPlayerUID player;
			};
			
	} else {
			_ownerTODB = str( 'B'+ getPlayerUID player );
			_ownerUID = getPlayerUID player;
	};
	
    //hint format ["ObjetoNovo = %1 ", novoObjeto];

    _bbr = boundingBoxReal VIRUZ_Build_object;
    _p1 = _bbr select 0;
    _p2 = _bbr select 1;
    _maxWidth = abs ((_p2 select 0) - (_p1 select 0));
    _maxLength = abs ((_p2 select 1) - (_p1 select 1));
    _maxHeight = abs ((_p2 select 2) - (_p1 select 2));
    _maxSize = 0;
    if (_maxWidth >= _maxLength) then {_maxSize = _maxWidth} else {_maxSize = _maxLength};
	_distance = (_maxSize / 2) + 1;
	
	//snap function parms
    _offset = 	getArray (configFile >> "CfgVehicles" >> VIRUZ_Build_type >> "offset");
    if((count _offset) <= 0) then {
    	_offset = [0, _distance,1.7];
    };

    SnappingOffset = _offset;
    SnappingDir = 0;
	ManualDir = false;
    SnappingSpotMarkers = [];
    SnappingEnabled = false;
    SnappedOffsetZ = 0;
    SnappingResetPos = false;

    //Disable all Collisions with the Object
    [[VIRUZ_Build_object,"Disable"],"viruz_fnc_updateCollisions",true,false,true] call BIS_fnc_MP;

    //Attach the new Object to the player. The distance to the player is calculated with the Object sizes
    VIRUZ_Build_object attachTo [player,[0, _distance,1.7]];
    VIRUZ_Build_object setVariable ["viruz_build_distance",_distance,true];
    VIRUZ_Build_object setVariable ["viruz_build_additionalDistance",0,true];
    VIRUZ_Build_object setVariable ["viruz_build_objectDir",0,true];
	_eRack = VIRUZ_Build_type in VIRUZ_RACKS;
	if (_eRack) then {
		VIRUZ_Build_object allowDamage false;
	};

    //add Action for snap object, detach object and break the while loop
    s_build_detach =  player addAction ["Build Object",{Movendo = 2; detach (_this select 3);  player removeAction (_this select 2)},VIRUZ_Build_object];
	s_buil_manualdir = player addAction ["<t color=""#01DF01"">Toggle Direction Mode</t>", "\viruz_build\functions\player_manualdir.sqf",VIRUZ_Build_type, 3, true, false, "",""];
    if (isClass (missionConfigFile >> "SnapPoints" >> VIRUZ_Build_type)) then {
		    s_building_snapping = player addAction ["<t color=""#0000ff"">Toggle Snapping</t>", "\viruz_build\functions\player_toggleSnapping.sqf",VIRUZ_Build_type, 4, true, false, "",""];
			//SnappingEnabled = true;
	};
	
    // Private
    
    	Movendo = 0;
    	_direction = 0;
    	_high = 1.7;
	
	    _VecDir = [0,1,0];
	    _VecNormal = [0,0,1];
	
    	_config = (missionConfigFile >> "SnapPoints" >> VIRUZ_Build_type);
    	SnappingAttachedToPlayer = true;

    _object_types = getArray(_config >> "snap");
    _target_spots = getArray(_config >> "points");

    if ((count _target_spots) > 0) then {
    	_currentDistanceDiff = 0;
    	_search_range = 0;
	    {
		    _distanceDiff = [0,0,0] distance [(_x select 0) select 0, (_x select 0) select 1, 0];
		    if ((_distanceDiff) > 0 && (_distanceDiff) > _currentDistanceDiff) then {
    			_currentDistanceDiff = _distanceDiff;
			    _search_range = ((_distanceDiff) + 2);
		    };
	    } forEach _target_spots;
    }
    else
    {_search_range = 10;}; //10
	
	if (ViruzDebugMode > 2 or ViruzDebugType == "BUILD") then {
		diag_log format["Building Object: %1", VIRUZ_Build_object];
		diag_log format["TAMANHO = %1", _bbr];
		diag_log format["_p1 = %1", _p1];
		diag_log format["_p2 = %1", _p2];
		diag_log format["_maxHeight = %1", _maxHeight];
		diag_log format["_maxLength = %1", _maxLength];
	};
	
	vz_cant_Build = true;
		
    while {Movendo < 1} do 
	{
		
		//******************************************************************************************
		if (SnappingAttachedToPlayer) then {
			
			_distance = (VIRUZ_Build_object getVariable "viruz_build_distance") + (VIRUZ_Build_object getVariable "viruz_build_additionalDistance");
			_direction = ((acos ((ATLtoASL positionCameraToWorld [0, 0, 1] select 2) - (ATLtoASL positionCameraToWorld [0, 0, 0] select 2)) - 90)* -1);	
			if (!freeLook) then {_high = ((tan _direction) * _distance) + 1.7 + ((getPos Player) select 2);};
		
			if (_eRack) then {
				_adjustRack = _maxHeight / 2;
				if (_high > (_adjustRack + ((getPos Player) select 2))) then { _high = ((getPos Player) select 2) + _adjustRack};
				if (_high < (-_adjustRack  + ((getPos Player) select 2))) then { _high = ((getPos Player) select 2) + -_adjustRack};
			}else {
				if (_high > (6 + ((getPos Player) select 2))) then { _high = ((getPos Player) select 2) + 6};
				if (_high < (-6 + ((getPos Player) select 2))) then { _high = ((getPos Player) select 2) + -6};
			};
			VIRUZ_Build_object attachTo [player,[0, _distance,_high]];
			/*SnappingAttachedToPlayer = true;*/			
		};	

		//******************************************************************************************
						
		if (VIRUZ_Build_alignToGround) then	{
			
			_VecNormal = surfaceNormal (getPos VIRUZ_Build_object);
			_VecNormal = (player worldToModel ASLtoATL (_VecNormal vectorAdd getPosASL player)) vectorDiff (player worldToModel ASLtoATL (getPosASL player));
			_dir = VIRUZ_Build_object getVariable "viruz_build_objectDir";
			_VecDir = [-cos _dir, sin _dir, 0] vectorCrossProduct _VecNormal;
			
		} else {
			
			_VecNormal = [0,0,1];
			_dir = VIRUZ_Build_object getVariable "viruz_build_objectDir";
			_VecDir = [-cos _dir, sin _dir, 0] vectorCrossProduct _VecNormal;
			
		};
	
		_isWater = (surfaceIsWater position VIRUZ_Build_object);
		if (isClass _config and SnappingEnabled) then {
				_position = player modelToWorld SnappingOffset;
				if (!_isWater) then {
					_position = [(_position) select 0, (_position) select 1, (getPosATL VIRUZ_Build_object) select 2];
				} else {
					_position = [(_position) select 0, (_position) select 1, (getPosASL VIRUZ_Build_object) select 2];
				};	

				_nearest_objects = nearestObjects [_position, _object_types, _search_range] - [VIRUZ_Build_object];
				_current_distance_diff = 20;
				_best_distance_object = objNull;
				_target_object = objNull;
				_possible_targets = [];
				{
					if (_x != VIRUZ_Build_object) then {
						_object_pos = _position;
						_spot_position_array = [];
						_closest_spot_position = [];
						_closest_spot = [];
						_spot_position_array = [_x, _object_pos, _isWater] call ViruZClient_getSpotPosition;
						_closest_spot_position = _spot_position_array select 0;
						_closest_spot = _spot_position_array select 1;
						_distance_diff = _closest_spot_position distance _object_pos;
						if (_distance_diff < _current_distance_diff && _distance_diff < _search_range) then {
							_current_distance_diff = _distance_diff;
							_best_distance_object = _x;
							_closest_spot_position_array = [_best_distance_object, _object_pos, _isWater] call ViruZClient_getSpotPosition;
							_best_spot_position = _closest_spot_position_array select 0;
							_best_spot = _closest_spot_position_array select 1;
						};
					};
				} forEach _nearest_objects;
				if (!isNull _best_distance_object) then {
					_possible_targets set [(count _possible_targets), _best_distance_object];
				};
				if (count _possible_targets > 0) then {
					_target_object = _possible_targets select 0;
				};
				if (!isNull _target_object) then {
					_closest_distance = 0;
					_distance = (_position distance _best_spot_position);
					if (_closest_distance == 0 or _distance < _closest_distance) then {
						_closest_distance = _distance;
					};
					if (_closest_distance <= 2) then {
						if (SnappingAttachedToPlayer) then {
							detach VIRUZ_Build_object;
							if !(ManualDir) then {
							if ((_best_spot select 1) != 90 && (_best_spot select 1) != 270) then {
								_offsetDir = (getDir _target_object) + (_best_spot select 1);
								if (SnappingDir == 180) then {
									_offsetDir = (getDir _target_object) + SnappingDir; 
								};
								if ((getDir player - getDir _target_object) >= 50 || (getDir player - getDir _target_object) <= -50) then {
									_offsetDir = _offsetDir - 180;
								};
							} else {
								_offsetDir = (getDir _target_object) + (_best_spot select 1);
								if ((_best_spot select 1) == 90) then {
									if (SnappingDir == 180) then {
										_offsetDir = _offsetDir + 180;
									};
								} else {
									_offsetDir = _offsetDir - 180;
									if (SnappingDir == 180) then {
										_offsetDir = _offsetDir + 180;
									};
								};
								if ((getDir player - getDir _target_object - 90)  >= 90 || (getDir player - getDir _target_object - 90) <= -90) then {
									_offsetDir = _offsetDir -180;
								};
							};
							} else { _offsetDir = ( (VIRUZ_Build_object getVariable "viruz_build_objectDir") + getDir _target_object)};
							_offsetDir = if (_offsetDir > 360) then { _offsetDir - 360 } else { _offsetDir };
							_offsetDir = if (_offsetDir < 0) then { _offsetDir + 360 } else { _offsetDir };
							VIRUZ_Build_object setDir _offsetDir;
							
							SnappingAttachedToPlayer = false;
							SnappingResetPos = true;
						};	
						if (SnappingResetPos) then {
							if (_isWater) then {
								VIRUZ_Build_object setPosASL _best_spot_position;
							} else {
								VIRUZ_Build_object setPosATL _best_spot_position;
							};
							SnappingResetPos = false;
						};
					} else { 
							SnappingAttachedToPlayer = true;
					};
				} else { 
						SnappingAttachedToPlayer = true;
				};
		} else { 
				SnappingAttachedToPlayer = true;
		};
	
		if !(SnappingEnabled) then {	
			VIRUZ_Build_object setVectorDirAndUp [_VecDir, _VecNormal];
		};
		
		
		//Check move generator is near other player bases
		_distMoved = VIRUZ_Build_object distance _AttchPosition;
		if (_distMoved > 20 and (TypeOf VIRUZ_Build_object == "Land_Portable_generator_F") ) then {
			_cansave = false;
			hintSilent parseText format["<t size='1' font='Zeppelin33' color='#ff0000'>You can not move the Generator more than 20 meters. it will be removed if you keep moving apart. back to safezone</t>", 0];
		} else {
			_cansave = true;
			hint "";
		};
		
		if (_distMoved > 30 and (TypeOf VIRUZ_Build_object == "Land_Portable_generator_F") ) then {
			Movendo = 2;
			_cansave = false;
			player removeAction s_build_detach;
			
			if (isClass (missionConfigFile >> "SnapPoints" >> VIRUZ_Build_type)) then {
				player removeAction s_building_snapping;
			};
			player removeAction s_buil_manualdir;
			
			_objectID 	= VIRUZ_Build_object getVariable ["ObjectID","0"];
			_objectUID	= VIRUZ_Build_object getVariable ["ObjectUID","0"];
			if !(_objectID == "0" and _objectUID == "0") then {
				viruzDeleteObj = [_objectID,_objectUID];
				publicVariable "viruzDeleteObj";
			};
			
			deleteVehicle VIRUZ_Build_object;
		};
		
		
		//check if is far from generator
		if (_hasGenerator and !(TypeOf VIRUZ_Build_object == "Land_Portable_generator_F")) then {
			
			_metros =  VIRUZ_Build_object distance ViruZ_Generator;
			if (_metros > viruz_maxBuildDistance) then {
				hintSilent parseText format["<t size='1' font='Zeppelin33' color='#ff0000'>Object is far from the Generator. it will be removed if you keep moving apart. back to safezone!</t>", 0];
				_cansave = false;
			} else {
				_cansave = true;
				hint "";
			};
			
			if (_metros > viruz_maxBuildDistance + 10) then {
				Movendo = 2;
				_cansave = false;
				player removeAction s_build_detach;
				
				if (isClass (missionConfigFile >> "SnapPoints" >> VIRUZ_Build_type)) then {
					player removeAction s_building_snapping;
				};
				player removeAction s_buil_manualdir;
				
				_objectID 	= VIRUZ_Build_object getVariable ["ObjectID","0"];
				_objectUID	= VIRUZ_Build_object getVariable ["ObjectUID","0"];
				if !(_objectID == "0" and _objectUID == "0") then {
					viruzDeleteObj = [_objectID,_objectUID];
					publicVariable "viruzDeleteObj";
				};
				
				deleteVehicle VIRUZ_Build_object;
			};
		};
		
		
		sleep 0.01;
	};
		
	//player playActionNow "Medic";
	_sfx = "repair";
	[player,_sfx,0,false,20] call viruz_zombieSpeak;  
	[player,20,true,(getPosATL player)] spawn player_alertZombies;
	
	if (isClass (missionConfigFile >> "SnapPoints" >> VIRUZ_Build_type)) then {
		player removeAction s_building_snapping;
	};
	player removeAction s_buil_manualdir;
	
	//Calculate precision locate to save in DB
	if (_isWater) then {
		_positionASL =  getPosASL VIRUZ_Build_object;
		_positionATL = ASLtoATL _positionASL;
		_posicao = [(_positionATL call viruz_preciseposcalc), vectordir VIRUZ_Build_object, vectorup VIRUZ_Build_object];
	} else {
		_posicao = [(getposATL VIRUZ_Build_object call viruz_preciseposcalc), vectordir VIRUZ_Build_object, vectorup VIRUZ_Build_object];
	};
	_worldvectorDirUp = [_posicao select 1,_posicao select 2];
	_posicao_calc = _posicao deleteAt 0;
	_posicao_final = (_posicao_calc select 0) vectorAdd (_posicao_calc select 1);
	
	VIRUZ_Build_object setVectorDirAndUp _worldvectorDirUp;
	VIRUZ_Build_object setposATL _posicao_final;
	
	/*
	if (VIRUZ_Build_object in VIRUZ_GATES) then {
		VIRUZ_Build_object setVariable ["Locked", "0", true];
	};
		//ARMA builds or builds with more doors
	if (VIRUZ_Build_object in VIRUZ_BUILDS) then {
		VIRUZ_Build_object setVariable ["Locked", "0", true];
		VIRUZ_Build_object setVariable ["Door_1_Lock", "0", true];
		VIRUZ_Build_object setVariable ["Door_2_Lock", "0", true];
		VIRUZ_Build_object setVariable ["Door_3_Lock", "0", true];
		VIRUZ_Build_object setVariable ["Door_4_Lock", "0", true];
		VIRUZ_Build_object setVariable ["Door_5_Lock", "0", true];
		VIRUZ_Build_object setVariable ["Door_6_Lock", "0", true];
	};
	*/
	if (_cansave) then {
		deleteVehicle VIRUZ_Build_object;
		
		_storageObj = createVehicle[VIRUZ_Build_type, _posicao_final, [], 0, "CAN_COLLIDE"];
		
		if (_storageObj in VIRUZ_RACKS) then {
			_storageObj allowDamage false;
		};
		_storageObj setVectorDirAndUp _worldvectorDirUp;
		_storageObj setposATL _posicao_final;
		_direcao = getDir _storageObj;
		_deltime = time + 300;
		
		_storageObj setVariable ["ViruZMod",1,true];
		_storageObj setVariable ["backRessource",_deltime,true];
		_storageObj setVariable ["characterID",viruz_characterID,true];
		_storageObj setVariable ["OwnerUID",_ownerUID, true];
		_storageObj setVariable ["ownerTODB",_ownerTODB, true];
		_storageObj setVariable ["posicao_final",_posicao_final, true];
		_storageObj setVariable ["tipoObj",VIRUZ_Build_type, true];
		_storageObj setVariable ["WorldSpace",[_direcao,_posicao_final], true];
		_storageObj setVariable ["worldprecision",_posicao, true];
		_storageObj setVariable ["canDelete",false, true];
		_storageObj setVariable ["lastFix", currentDate, true];
		
		
		if (_storageObj in VIRUZ_GATES) then {
			_storageObj setVariable ["Locked", "0", true];
		};
			//ARMA builds or builds with more doors
		if (_storageObj in VIRUZ_BUILDS) then {
			_storageObj setVariable ["Locked", "0", true];
			_storageObj setVariable ["Door_1_Lock", "0", true];
			_storageObj setVariable ["Door_2_Lock", "0", true];
			_storageObj setVariable ["Door_3_Lock", "0", true];
			_storageObj setVariable ["Door_4_Lock", "0", true];
			_storageObj setVariable ["Door_5_Lock", "0", true];
			_storageObj setVariable ["Door_6_Lock", "0", true];
		};
		
		
		viruzUpdateVehicle = [_storageObj,"PublishBuild"];
		publicVariable "viruzUpdateVehicle";
		
	} else {
		deleteVehicle VIRUZ_Build_object;
	};
	
	hintSilent parseText format["<t size='1' font='Zeppelin33' color='#00FF04'>Build successfully!</t>", 0];
	sleep 1.5;
	hintSilent "";
	vz_cant_Build = false;
	
	
	VIRUZ_Build_object setVariable ["viruz_build_distance",Nil,false];
	VIRUZ_Build_object setVariable ["viruz_build_objectDir",Nil,false];
	VIRUZ_Build_object setVariable ["viruz_build_additionalDistance",Nil,false];
	
	VIRUZ_Build_object = Nil;
	VIRUZ_Build_action = Nil;
	VIRUZ_Build_type = Nil;
	SnappingDir = 0;
    SnappingSpotMarkers = [];
    SnappingEnabled = false;
    SnappedOffsetZ = 0;
    SnappingResetPos = false;
	SnappingOffset = 0;
  	
