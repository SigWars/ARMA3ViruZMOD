if (IsDedicated) exitWith {};


0 = [] spawn {

disableSerialization;

waituntil {(!IsNull player) and (!isNull findDisplay 46)};

_mod = "babe_core";

babe_core_keyhandler = false;

if !(IsNil "babe_core_keyhandlersaver") then 
{
	(findDisplay 46) displayRemoveEventHandler ['KeyDown', babe_core_keyhandlersaver];
};

babe_core_keyhandlersaver = (findDisplay 46) displayaddEventHandler ["KeyDown","if !(babe_core_keyhandler) then {(findDisplay 46) displayRemoveEventHandler ['KeyDown', babe_core_keyhandlersaver];call babe_core_fnc_addkeyhandler; systemchat 'babe_core key handler initialised'}"];

if (!IsNil (_mod + "_init")) exitWith 
{
	systemchat (_mod + " already initialised...canceling reinit");
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//call babe_core_fnc_addkeyhandler;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

_id = addMissionEventHandler ["loaded",{[] call babe_core_fnc_init}];

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


babe_core_keysdown = [];
babe_core_keysbusy = [];

babe_core_busy = false;

babe_core_EHs = [];

babe_core_escM_mousepos = [];

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

["BABE_MAINLOOP", "onEachFrame", 
{
	private ["_i"];

	for "_i" from 0 to (count babe_core_EHs)-1 do
	{
		_EH = babe_core_EHs select _i;
		_id = _EH select 0;
		_cond = _EH select 1;
		_condpars = _EH select 2;
		_fnc = _EH select 3;
		_pars = _EH select 4;
		_switch = _EH select 5;
		_switchfnc = _EH select 6;
		_switchpars = _EH select 7;
		_delay = _EH select 8;


		if (_delay == -1 or diag_tickTime - (call compile (_id+"_timer")) >= _delay) then 
		{
			call compile (_id + "_timer = diag_tickTime;");

			missionNameSpace setvariable ["babe_mainloop_pars", nil];

            if (_switch) then 
			{
				_var = missionNameSpace getvariable _id;	
				if (IsNil "_var") then
				{
					missionNameSpace setvariable [_id, false];
				};
				_var = missionNameSpace getvariable _id;

				if !(_var) then
				{
					//missionNameSpace setvariable [_id, true];
					//_pars call _fnc;
					missionNameSpace setvariable ["babe_mainloop_pars", _pars];
					call compile (format ["if (%1) then {(missionNameSpace getvariable toString %2) call %3; missionNameSpace setvariable [toString %4, true];}", _cond, toArray "babe_mainloop_pars", _fnc, toArray _id]);
				} else
				{
					//missionNameSpace setvariable [_id, false];
					//_switchpars call _switchfnc;
					missionNameSpace setvariable ["babe_mainloop_pars", _switchpars];
					call compile (format ["if !(%1) then {(missionNameSpace getvariable toString %2) call %3; missionNameSpace setvariable [toString %4, false];}", _cond, toArray "babe_mainloop_pars", _switchfnc, toArray _id]);
				};
			} else
			{
				//_pars call _fnc;
				missionNameSpace setvariable ["babe_mainloop_pars", _pars];
				call compile (format ["if (%1) then {(missionNameSpace getvariable toString %2) call %3;}", _cond, toArray "babe_mainloop_pars", _fnc]);
			};
		};
	};
}] call BIS_fnc_addStackedEventHandler;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

_id = addMissionEventHandler ["loaded",{[] call babe_core_fnc_init}];

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


["EH_ModMenu", "!IsNull findDisplay 49", [], "babe_core_fnc_modmenu", [], true, "babe_core_fnc_modmenu_exit", [], -1] call babe_core_fnc_addEH;


["EH_fd", "dialog", [], "{babe_core_keysdown = [];}", [], false, "{}", [], -1] call babe_core_fnc_addEH;
["EH_keyH", "true", [], "babe_core_fnc_keyH", [], false, "{}", [], -1] call babe_core_fnc_addEH;

babe_core_init = true;

};