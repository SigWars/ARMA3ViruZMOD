private ["_characterID","_doLoop","_playerID","_playerName","_playerObj","_randomSpot","_spawnSelection","_primary","_key","_worldspace","_score","_position","_pos","_isIsland",
"_medical","_stats","_state","_dummy","_debug","_distance","_hit","_fractures","_w","_findSpot","_humanity","_clientID"];//Set Variables
//Wait for HIVE to be free
//diag_log ("SETUP: attempted with " + str(_this));

_characterID = _this select 0;
_playerObj = _this select 1;
_playerID = getPlayerUID _playerObj;
_playerName = name _playerObj;
_spawnSelection = _this select 3; // added 4 spawnselection

if (isNull _playerObj) exitWith {
	diag_log ("SETUP INIT FAILED: Exiting, player object null: " + str(_playerObj));
};

if (_playerID == "") then {
	_playerID = getPlayerUID _playerObj;
};

if (_playerID == "") exitWith {
	diag_log ("SETUP INIT FAILED: Exiting, no player ID: " + str(_playerObj));
};

private["_dummy"];
_dummy = getPlayerUID _playerObj;
if ( _playerID != _dummy ) then { 
	diag_log format["DEBUG: _playerID miscompare with UID! _playerID:%1",_playerID]; 
	_playerID = _dummy;
};

//Variables
_worldspace = 	[];


_state = 		[];

//Do Connection Attempt
_doLoop = 0;
while {_doLoop < 5} do {
	_key = format["CHILD:102:%1:",_characterID];
	_primary = _key call server_hiveReadWrite;
	if (count _primary > 0) then {
		if ((_primary select 0) != "ERROR") then {
			_doLoop = 9;
		};
	};
	_doLoop = _doLoop + 1;
};

if (isNull _playerObj or !isPlayer _playerObj) exitWith {
	diag_log ("SETUP RESULT: Exiting, player object null: " + str(_playerObj));
};

//Wait for HIVE to be free
//diag_log ("SETUP: RESULT: Successful with " + str(_primary));

_medical =		_primary select 1;
_stats =		_primary select 2;
_state =		_primary select 3;
_worldspace = 	_primary select 4;
_humanity =		_primary select 5;

//Set position
_randomSpot = false;

//diag_log ("WORLDSPACE: " + str(_worldspace));

if (count _worldspace > 0) then {

	_position = 	_worldspace select 1;
	if (count _position < 3) then {
		//prevent debug world!
		_randomSpot = true;
	};
	_debug = getMarkerpos "respawn_west";
	_distance = _debug distance _position;
	if (_distance < 2000) then {
		_randomSpot = true;
	};
	
	_distance = [0,0,0] distance _position;
	if (_distance < 500) then {
		_randomSpot = true;
	};

	//_playerObj setPosATL _position;
} else {
	_randomSpot = true;
};

//diag_log ("LOGIN: Location: " + str(_worldspace) + " doRnd?: " + str(_randomSpot));

//set medical values
if (count _medical > 0) then {
	_playerObj setVariable["USEC_isDead",(_medical select 0),true];
	_playerObj setVariable["NORRN_unconscious", (_medical select 1), true];
	_playerObj setVariable["USEC_infected",(_medical select 2),true];
	_playerObj setVariable["USEC_injured",(_medical select 3),true];
	_playerObj setVariable["USEC_inPain",(_medical select 4),true];
	_playerObj setVariable["USEC_isCardiac",(_medical select 5),true];
	_playerObj setVariable["USEC_lowBlood",(_medical select 6),true];
	_playerObj setVariable["USEC_BloodQty",(_medical select 7),true];
	
	_playerObj setVariable["unconsciousTime",(_medical select 10),true];
	
//	if (_playerID in viruz_disco) then {
//		_playerObj setVariable["NORRN_unconscious",true, true];
//		_playerObj setVariable["unconsciousTime",300,true];
//	} else {
//		_playerObj setVariable["unconsciousTime",(_medical select 10),true];
//	};
	
	//Add Wounds
	{
		_playerObj setVariable[_x,true,true];
		//["usecBleed",[_playerObj,_x,_hit]] call broadcastRpcCallAll;
		usecBleed = [_playerObj,_x,_hit];
		publicVariable "usecBleed";
	} forEach (_medical select 8);
	
	//Add fractures
	_fractures = (_medical select 9);
	_playerObj setVariable ["hit_legs",(_fractures select 0),true];
	_playerObj setVariable ["hit_hands",(_fractures select 1),true];
	
	if (count _medical > 11) then {
		//Additional medical stats
		_playerObj setVariable ["messing",(_medical select 11),true];
	};
	
} else {
	//Reset Fractures
	_playerObj setVariable ["hit_legs",0,true];
	_playerObj setVariable ["hit_hands",0,true];
	_playerObj setVariable ["USEC_injured",false,true];
	_playerObj setVariable ["USEC_inPain",false,true];
	_playerObj setVariable ["messing",[0,0],true];
};
	
if (count _stats > 0) then {	
	//register stats
	_playerObj setVariable["zombieKills",(_stats select 0),true];
	_playerObj setVariable["headShots",(_stats select 1),true];
	_playerObj setVariable["humanKills",(_stats select 2),true];
	_playerObj setVariable["banditKills",(_stats select 3),true];
	_playerObj addScore (_stats select 1);
	
	//Save Score
	_score = score _playerObj;
	_playerObj addScore ((_stats select 0) - _score);
	
	//record for Server JIP checks
	_playerObj setVariable["zombieKills_CHK",(_stats select 0)];
	_playerObj setVariable["headShots_CHK",(_stats select 1)];
	_playerObj setVariable["humanKills_CHK",(_stats select 2)];
	_playerObj setVariable["banditKills_CHK",(_stats select 3)];
	if (count _stats > 4) then {
		if (!(_stats select 3)) then {
			_playerObj setVariable["selectSex",true,true];
		};
	} else {
		_playerObj setVariable["selectSex",true,true];
	};
} else {
	//Save initial loadout
	//register stats
	_playerObj setVariable["zombieKills",0,true];
	_playerObj setVariable["humanKills",0,true];
	_playerObj setVariable["banditKills",0,true];
	_playerObj setVariable["headShots",0,true];
	
	//record for Server JIP checks
	_playerObj setVariable["zombieKills_CHK",0];
	_playerObj setVariable["humanKills_CHK",0,true];
	_playerObj setVariable["banditKills_CHK",0,true];
	_playerObj setVariable["headShots_CHK",0];
};

if (_randomSpot) then {
	private["_counter","_position","_isNear","_isZero","_mkr"];
	if (!isDedicated) then {
		endLoadingScreen;
	};
	
	//spawn into random -> SigWar Selection menu code
	_findSpot = true;
	_mkr = "";
	while {_findSpot} do {
		_counter = 0;
		while {_counter < 20 and _findSpot} do {
			// switched to floor
			if (_spawnSelection == 9) then {
				// random spawn location selected, lets get the marker and spawn in somewhere
				//_mkr = "spawn" + str(ceil(random 5));
				//_mkr = [getMarkerPos "spawn1",getMarkerPos "spawn2",getMarkerPos "spawn3",getMarkerPos "spawn4",getMarkerPos "spawn5"] call BIS_fnc_selectRandom;
				_mkr = (playerSpawnPositions call BIS_fnc_selectRandom);
			} else {
				// spawn is not random, lets spawn in our location that was selected
				_mkr = "spawn" + str(_spawnSelection);
				_mkr = getMarkerPos _mkr;
			};
			_position = ([_mkr,0,1000,3,0,-1,0] call BIS_fnc_findSafePos);
			//_isNear = count (_position nearEntities ["Man",100]) == 0;
			_isZero = ((_position select 0) == 0) and ((_position select 1) == 0);
			
			if (!_isZero) then {_findSpot = false};
			_counter = _counter + 1;
		};
	};
	
	_position = [_position select 0,_position select 1,0];
	if (!_isZero) then {
		//_playerObj setPosATL _position;
		_worldspace = [0,_position];
	};
};

/*
NEW VIRUZ GROUP SYSTEM 
*/
private ["_havegrp","_groupID","_groupName","_groupLeader","_permission","_groupMembers","_groupExist","_newGroup"];
_havegrp = false;
_groupID = -1;
_groupName = "";
_groupLeader = "";
_permission = "";
_groupExist = false;
_groupRank = 0;

{
	diag_log format ["GROUP %1", _x ];
	_groupMembers = _x select 4;
	{
		if (_x select 0 == _playerID) then { _havegrp = true; _permission = _x select 1;}; 
	}forEach _groupMembers;
	if (_havegrp) exitWith { _groupName = _x select 1; _groupLeader = _x select 2; _groupID = _x select 0; _groupRank = _x select 3};

}forEach ViruZGroupsArray;

if (_havegrp) then
{
	//join player in group
	{
		_gname = groupID _x;
		if (_gname == _groupName) exitWith 
		{ 
			[_playerObj] join _x;
			_groupExist = true;
		};
	}forEach allGroups; 
	
	//Recreate arma fuck group if not alive in server
	if (!_groupExist)then{
		_newGroup = createGroup west;
		_newGroup setGroupIdGlobal [_groupName];
		[_playerObj] join _newGroup;
	};
	
	
	_playerObj setVariable ["ClanID",_groupID,true];
	_playerObj setVariable ["ClanLeader",_groupLeader,true];
	_playerObj setVariable ["LvL",_permission,true];
	_playerObj setVariable ["clanName",_groupName,true];
	_playerObj setVariable ["haveClan",true,true];
	_playerObj setVariable ["groupRank",_groupRank,true];

}
else
{ 
	[_playerObj] joinSilent grpNull; 
	_playerObj setVariable ["ClanID",name _playerObj,true];// if ClanID == playername, it will enable clan creation
	_playerObj setVariable ["ClanLeader",_playerID,true];
	_playerObj setVariable ["LvL",3,true];
	_playerObj setVariable ["clanName",name _playerObj,true];
	_playerObj setVariable ["haveClan",false,true];
	_playerObj setVariable ["groupRank",_groupRank,true];
};
/*
END OF GROUP SYSTEM
*/

//Record player for management
viruz_players set [count viruz_players,_playerObj];

//record player pos locally for server checking
_playerObj setVariable["characterID",_characterID,true];
_playerObj setVariable["humanity",_humanity,true];
_playerObj setVariable["humanity_CHK",_humanity];
//_playerObj setVariable["worldspace",_worldspace,true];
//_playerObj setVariable["state",_state,true];
_playerObj setVariable["lastPos",getPosATL _playerObj];

viruzPlayerLogin2 = [_worldspace,_state];
_clientID = owner _playerObj;
_clientID publicVariableClient "viruzPlayerLogin2";

//record time started
_playerObj setVariable ["lastTime",time];
//_playerObj setVariable ["model_CHK",typeOf _playerObj];

diag_log ("LOGIN PUBLISHING: " + str(_playerObj) + " Type: " + (typeOf _playerObj));

viruzLogin = null;
viruzLogin2 = null;

//Save Login