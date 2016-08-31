if (IsDedicated) exitWith {};



0 = [] spawn {

disableSerialization;

waituntil {(!IsNull player) && (!isNull findDisplay 46 && !IsNil "babe_core_init")};

_mod = "babe_em";





if (!IsNil (_mod + "_init")) exitWith {systemchat (_mod + " already initialised...canceling reinit")};


_id = addMissionEventHandler ["loaded",{[] call babe_em_fnc_init}];




if (isClass(configFile >> "CfgPatches" >> "babe_fd")) then
{
systemchat "custom fall damage";
	player addeventhandler ["handledamage", 
	{
		_this call babe_em_fnc_handledamage;
	}];
} else
{
systemchat "default fall damage";
	player addeventhandler ["handledamage", 
	{
		_this call babe_em_fnc_handledamage_nofd;
	}];
};

player addeventhandler ["Respawn",
{

   _u = _this select 0; 
   _c = _this select 1;

   EM_Busy = false;

}];




player addeventhandler ["AnimDone", 
{
   _this call babe_em_fnc_animDone;
}]; 



"babe_EM" call babe_core_fnc_settings;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


EM_busy = false;

EM_climbing = false;

EM_heightsOn = [0.25,1,2,2.25,3];

EM_heightsOver = [0.25,1.1,1.7,2.25,3];

EM_weightlimits = [9999, 9999, 9999]; 

EM_debug = false;


babe_em_help = "babe_helper" createVehicleLocal [0,0,0];

babe_em_debug_a = "Sign_Arrow_Green_F" createVehicleLocal [0,0,0];
babe_em_debug_b = "Sign_Arrow_F" createVehicleLocal [0,0,0];
babe_em_debug_c = "Sign_Arrow_Yellow_F" createVehicleLocal [0,0,0];


["EH_em_loop", "EM_climbing", [], "{player setVelocity [0,0,0]; EM_travtime = 0;EM_oldpos = getposATL player;EM_newpos = getposATL player;}", [], false, "{}", [], -1] call babe_core_fnc_addEH;

["EH_MM", "!IsNull findDisplay 49", [], "babe_core_fnc_mod_menu", [], true, "{}", [], -1] call babe_core_fnc_addEH;

["EH_em_hud", "true", [], "babe_em_fnc_hudrefresh", [], false, "{}", [], -1] call babe_core_fnc_addEH;


babe_em_init = true;

};
