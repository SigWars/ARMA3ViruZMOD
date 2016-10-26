/* 
	Original Script Here: 
	http://forums.bistudio.com/showthread.php?190404-Chernarus-Takistan 

	Script edited by jakehekesfists[dmd] 08/05/15
	-rev 2.1a (for Arma III) 	
	Replacement buildings for use with ArmaIII Assets | AIA Chernarus Terrain. 	
	if you use this script ensure you include the default altis loot positions along with the cherno loot positions. 	
*/

FFA_CLOSEHOUSE = ["Land_HouseV_2L","Land_HouseV_3I3","Land_HouseV_3I1","Land_HouseV_3I4","Land_HouseV_3I2","Land_HouseV_1L1","Land_houseV_2T1","Land_houseV_2T2","Land_HouseV_1T","Land_HouseV2_03B","Land_HouseV2_03","Land_HouseV2_01A","Land_HouseV2_01B","Land_HouseV2_05","Land_Church_02","Land_Church_02a","Land_Church_01","Land_Ind_SawMill","Land_Ind_Workshop01_03","Land_HouseV_1I2","Land_HouseV_1I1","Land_SignB_Pub_CZ3","Land_Shed_W4","Land_HouseV_1I3","Land_HouseV_1L2","Land_Misc_WaterStation","Land_Farm_WTower","Land_HouseV_2I","Land_Mil_Barracks_L","Land_Mil_Barracks","Land_Mil_House","Land_A_Office02","Land_Tec","Land_Shed_W02","Land_Shed_W03","Land_SignB_Pub_RU3","Land_Sign_Bar_RU","Land_SignB_PostOffice","Land_Mil_Guardhouse","Land_Komin"];

_godModeBuildings = false; // set true if you want to make these replacement buildings have god mode. 

if (isServer) then 
{
	/* Objects & Buildings to Delete */
	_dmdDeleteThis=[["Land_SignB_Pub_CZ3","Land_SignB_Gov","Land_SignB_Pub_CZ2","Land_SignB_GovSign","Land_SignB_Pub_RU3","Land_Sign_Bar_RU","Land_SignB_PostOffice","Land_Tec"],[""]];
	/* Buildings to Replace */
	_dmdRep0001=[["Land_HouseV_1I2"],["Land_i_Stone_Shed_V3_F"]];
	_dmdRep0002=[["Land_Ind_SawMill"],["Land_dp_mainFactory_F"]];
	_dmdRep0003=[["Land_HouseV_1I1"],["Land_i_House_Small_02_V1_F"]];
	_dmdRep0005=[["Land_Shed_W4"],["Land_Slum_House03_F"]];
	//_dmdRep0006=[["Land_HouseV_1I3"],["Land_i_House_Small_03_V1_dam_f"]];
	_dmdRep0006=[["Land_HouseV_1I3"],["Land_i_House_Small_03_V1_F"]];
	_dmdRep0007=[["Land_HouseV_1L2"],["Land_i_House_Big_02_V1_F"]];
	_dmdRep0008=[["Land_Misc_WaterStation"],["Land_Shed_02_F"]];
	_dmdRep0009=[["Land_Farm_WTower"],["Land_R_Minaret"]];
	_dmdRep0010=[["Land_HouseV_2I"],["Land_i_House_Big_01_V3_F"]];
	_dmdRep0011=[["Land_Mil_Barracks_L"],["Land_Cargo_HQ_V1_F"]];
	_dmdRep0012=[["Land_Mil_Barracks"],["Land_Mil_Barracks_i"]];
	_dmdRep0013=[["Land_Mil_House"],["Land_MilOffices_V1_F"]];
	_dmdRep0014=[["Land_A_Office02"],["Land_Offices_01_V1_F"]];
	_dmdRep0015=[["Land_Ind_Workshop01_03"],["Land_Ind_Workshop01_04"]];	
	_dmdRep0016=[["Land_Shed_W02"],["Land_Slum_House01_F"]];
	_dmdRep0017=[["Land_Shed_W03"],["Land_cargo_house_slum_F"]];
	_dmdRep0018=[["Land_HouseV_3I3"],["Land_i_Shop_01_V1_F"]];
	_dmdRep0019=[["Land_HouseV_3I1"],["Land_i_Shop_01_V2_F"]];
	_dmdRep0020=[["Land_HouseV_3I4"],["Land_i_Shop_02_V1_F"]];
	_dmdRep0021=[["Land_HouseV_3I2"],["Land_i_Shop_02_V3_F"]];
	_dmdRep0022=[["Land_HouseV_1L1"],["Land_i_Stone_HouseBig_V2_F"]];	
	_dmdRep0023=[["Land_houseV_2T1"],["Land_i_Stone_HouseBig_V3_F"]];
	_dmdRep0024=[["Land_houseV_2T2"],["Land_House_C_5_EP1"]];	
	_dmdRep0025=[["Land_HouseV_1T"],["Land_i_Stone_HouseSmall_V1_F"]];	
	_dmdRep0026=[["Land_HouseV_2L"],["Land_House_C_4_EP1"]];	
	_dmdRep0027=[["Land_HouseV2_03B"],["Land_Panelak2"]];
	_dmdRep0028=[["Land_HouseV2_01A"],["Land_i_House_Big_01_V1_F"]];
	_dmdRep0029=[["Land_HouseV2_01B"],["Land_Dum_mesto_in"]];	
	_dmdRep0030=[["Land_HouseV2_03"],["Land_i_Shed_Ind_F"]];	
	//_dmdRep0031=[["Land_HouseV2_02_Interier"],["Land_i_House_Big_02_V2_dam_F"]];
	//_dmdRep0032=[["Land_HouseV2_04_interier"],["Land_i_Shop_01_V3_dam_F"]];
	_dmdRep0031=[["Land_HouseV2_05"],["Land_u_Shop_01_V1_F"]];	
	_dmdRep0032=[["Land_Church_02","Land_Church_02a"],["Land_Church_03"]];
	_dmdRep0033=[["Land_Mil_Guardhouse"],["Land_Cargo_Tower_V1_No5_F"]];
	_dmdRep0034=[["Land_Komin"],["Land_ReservoirTower_F"]];

	
	_FFA_LHOUSEV=[];
	_FFA_HOUSES=[];

	if (worldName == "chernarus") then 
	{ 
 		_FFA_LHOUSEV=nearestObjects [getArray(configFile >> "CfgWorlds" >> worldName >> "centerPosition"),["house"],15000];
		for "_i" from 0 to (count _FFA_LHOUSEV)-1 do
		{
			_housev=_FFA_LHOUSEV select _i;
			if ((typeof _housev) in FFA_CLOSEHOUSE) then 
			{
				_FFA_HOUSES set [count _FFA_HOUSES,_housev];
			};
		};
		
		for "_i" from 0 to (count _FFA_HOUSES)-1 do
		{
			_nBuilding =_FFA_HOUSES select _i;
			_dirVector = vectorDir _nBuilding;
			_objVector = vectorUp _nBuilding;
			_pos = ASLtoATL getPosASL _nBuilding;
			_nBuilding hideObject true;
			deleteVehicle _nBuilding;
			
			_type="";
			call{
				if ((typeof _nBuilding) in (_dmdDeleteThis select 0)) exitwith {_type="";};
				
				if ((typeof _nBuilding) in (_dmdRep0001 select 0)) exitwith {_type=(_dmdRep0001 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0002 select 0)) exitwith {_type=(_dmdRep0002 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0003 select 0)) exitwith {_type=(_dmdRep0003 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0005 select 0)) exitwith {_type=(_dmdRep0005 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0006 select 0)) exitwith {_type=(_dmdRep0006 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0007 select 0)) exitwith {_type=(_dmdRep0007 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0008 select 0)) exitwith {_type=(_dmdRep0008 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0009 select 0)) exitwith {_type=(_dmdRep0009 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0010 select 0)) exitwith {_type=(_dmdRep0010 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0011 select 0)) exitwith {_type=(_dmdRep0011 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0012 select 0)) exitwith {_type=(_dmdRep0012 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0013 select 0)) exitwith {_type=(_dmdRep0013 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0014 select 0)) exitwith {_type=(_dmdRep0014 select 1) select 0;};				
				if ((typeof _nBuilding) in (_dmdRep0016 select 0)) exitwith {_type=(_dmdRep0016 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0017 select 0)) exitwith {_type=(_dmdRep0017 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0018 select 0)) exitwith {_type=(_dmdRep0018 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0019 select 0)) exitwith {_type=(_dmdRep0019 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0020 select 0)) exitwith {_type=(_dmdRep0020 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0021 select 0)) exitwith {_type=(_dmdRep0021 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0022 select 0)) exitwith {_type=(_dmdRep0022 select 1) select 0;};				
				if ((typeof _nBuilding) in (_dmdRep0023 select 0)) exitwith {_type=(_dmdRep0023 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0024 select 0)) exitwith {_type=(_dmdRep0024 select 1) select 0;};				
				if ((typeof _nBuilding) in (_dmdRep0025 select 0)) exitwith {_type=(_dmdRep0025 select 1) select 0;};				
				if ((typeof _nBuilding) in (_dmdRep0026 select 0)) exitwith {_type=(_dmdRep0026 select 1) select 0;};				
				if ((typeof _nBuilding) in (_dmdRep0027 select 0)) exitwith {_type=(_dmdRep0027 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0028 select 0)) exitwith {_type=(_dmdRep0028 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0029 select 0)) exitwith {_type=(_dmdRep0029 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0030 select 0)) exitwith {_type=(_dmdRep0030 select 1) select 0;};
				//if ((typeof _nBuilding) in (_dmdRep0031 select 0)) exitwith {_type=(_dmdRep0031 select 1) select 0;};
				//if ((typeof _nBuilding) in (_dmdRep0032 select 0)) exitwith {_type=(_dmdRep0032 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0031 select 0)) exitwith {_type=(_dmdRep0031 select 1) select 0;};				
				if ((typeof _nBuilding) in (_dmdRep0032 select 0)) exitwith {_type=(_dmdRep0032 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0033 select 0)) exitwith {_type=(_dmdRep0033 select 1) select 0;};
				if ((typeof _nBuilding) in (_dmdRep0034 select 0)) exitwith {_type=(_dmdRep0034 select 1) select 0;};
			};
			_house = createVehicle [_type, _pos, [], 0, "CAN_COLLIDE"];
			_house setVectorDirAndUp [ _dirVector, _objVector];
			
			if (_godModeBuildings) then {_house addEventHandler ["HandleDamage", {false}];};
		};
	};
};

if(!isServer || local player)then
{
	waitUntil{(player==player)};
	waitUntil{alive player};
	waitUntil{local player};
 	if (worldName == "chernarus") then 
	{ 
		_FFA_CHOUSEV=[];
		_FFA_CHOUSEV=nearestObjects [getArray(configFile >> "CfgWorlds" >> worldName >> "centerPosition"),["house"],15000];
		for "_i" from 0 to (count _FFA_CHOUSEV)-1 do
		{
			_housev=_FFA_CHOUSEV select _i;
			if ((typeof _housev) in FFA_CLOSEHOUSE) then 
			{
				_housev hideObject true;
				deleteVehicle _housev;
			};
		};
	};
};