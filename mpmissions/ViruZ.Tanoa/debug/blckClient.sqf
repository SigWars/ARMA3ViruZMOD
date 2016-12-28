////////////////////////////////////////////
// Start Server-side functions and Create, Display Mission Messages for blckeagls mission system for Arma 3 Epoch
// Last Updated 11/20/16
// by Ghostrider-DbD-
//////////////////////////////////////////

if (hasInterface) then
{
	//diag_log "[blckeagls] initializing client variables";
	blck_MarkerPeristTime = 300;  
	blck_useHint = true;
	blck_useSystemChat = true;
	blck_useTitleText = false;
	blck_useDynamic = false;
	blck_useToast = false;  // Exile only
	blck_aiKilluseSystemChat = true;
	blck_aiKilluseDynamic = false;
	blck_aiKilluseTitleText = false;
	blck_processingMsg = -1;
	blck_processingKill = -1;
	blck_message = "";

	fn_killScoreNotification = {
		params["_bonus","_distanceBonus","_killStreak"];
		//diag_log format["fn_killScoreNotification::  --  >> _bonus = %1 | _distanceBonus = %2 | _killStreak = %3",_bonus,_distanceBonus,_killStreak];
		_msg2 = format["<t color ='#7CFC00' size = '1.4' align='right'>AI Killed</t><br/>"];
		if (typeName _bonus isEqualTo "SCALAR") then // add message for the bonus
		{
			if (_bonus > 0) then 
			{
				_msg2 = _msg2 + format["<t color = '#7CFC00' size ='1.4' align='right'>Bonus <t color = '#ffffff'>+%1<br/>",_bonus];
			};
		};
		if (typeName _distanceBonus isEqualTo "SCALAR") then // Add message for distance bonus
		{
			if (_distanceBonus > 0) then
			{
				_msg2 = _msg2 + format["<t color = '#7CFC00' size = '1.4' align = 'right'>Dist Bonus<t color = '#ffffff'> +%1<br/>",_distanceBonus];
			};
		};
		if (typeName _killStreak isEqualTo "SCALAR") then
		{
			if (_killStreak > 0) then
			{
				_msg2 = _msg2 + format["<t color = '#7CFC00' size = '1.4' align = 'right'>Killstreak <t color = '#ffffff'>%1X<br/>",_killStreak];
			};
		};
		[parseText _msg2,[0.0823437 * safezoneW + safezoneX,0.379 * safezoneH + safezoneY,0.0812109 * safezoneW,0.253 * safezoneH], nil, 7, 0.3, 0] spawn BIS_fnc_textTiles;	
	};
	
	fn_dynamicNotification = {
			private["_text","_screentime","_xcoord","_ycoord"];
			params["_mission","_message"];
			
			waitUntil {blck_processingMsg < 0};
			blck_processingMsg = 1;
			_screentime = 7;
			_text = format[
				"<t align='left' size='0.8' color='#4CC417'>%1</t><br/><br/>
				<t align='left' size='0.6' color='#F0F0F0'>%2</t><br/>",
				_mission,_message
				];
			_ycoord = [safezoneY + safezoneH - 0.8,0.7];
			_xcoord = [safezoneX + safezoneW - 0.5,0.35];
			[_text,_xcoord,_ycoord,_screentime,0.5] spawn BIS_fnc_dynamicText;
			uiSleep 3;  // 3 second delay before the next message
			blck_processingMsg = -1;
	};
	
	//diag_log "[blckeagls] initializing client functions";
	fn_missionNotification = {
		params["_event","_message","_mission"];

		if (blck_useSystemChat) then {systemChat format["%1",_message];};
		if (blck_useHint) then {
			hint parseText format[
			"<t align='center' size='2.0' color='#f29420'>%1</t><br/>
			<t size='1.5' color='#01DF01'>______________</t><br/><br/>
			<t size='1.5' color='#ffff00'>%2</t><br/>
			<t size='1.5' color='#01DF01'>______________</t><br/><br/>
			<t size='1.5' color='#FFFFFF'>Any loot you find is yours as payment for eliminating the threat!</t>",_mission,_message
			];	
		};
		if (blck_useDynamic) then {
			[_mission,_message] call fn_dynamicNotification;
		};		
		if (blck_useTitleText) then {
			[_message] spawn {
				params["_msg"];
				titleText [_msg, "PLAIN DOWN",5];uiSleep 5; titleText ["", "PLAIN DOWN",5]
			};
		};
		if (blck_useToast) then
		{
			["InfoTitleAndText", [_mission, _message]] call ExileClient_gui_toaster_addTemplateToast;
		};		
		//diag_log format["_fn_missionNotification ====]  Paremeters _event %1  _message %2 _mission %3",_event,_message,_mission];
	};

	fn_AI_KilledNotification = {
		private["_message","_text","_screentime","_xcoord","_ycoord"];
		_message = _this select 0;
		//diag_log format["_fn_AI_KilledNotification ====]  Paremeters _event %1  _message %2 _mission %3",_message];
		if (blck_aiKilluseSystemChat) then {systemChat format["%1",_message];};
		if (blck_aiKilluseTitleText) then {titleText [_message, "PLAIN DOWN",5];uiSleep 5; titleText ["", "PLAIN DOWN",5]};
		if (blck_aiKilluseDynamic) then {
			//diag_log format["blckClient.sqf:: dynamic messaging called for mission %2 with message of %1",_message];
			waitUntil{blck_processingKill < 0};
			blck_processingKill = 1;
			_text = format["<t align='left' size='0.5' color='#4CC417'>%1</t>",_message];
			_xcoord = [safezoneX,0.8];
			_ycoord = [safezoneY + safezoneH - 0.5,0.2];
			_screentime = 5;
			["   "+ _text,_xcoord,_ycoord,_screentime] spawn BIS_fnc_dynamicText;		
			uiSleep 3;
			blck_processingKill = -1;
		};
	};

	//"blck_Message" addPublicVariableEventHandler 
	
	fn_handleMessage = {
		//private["_event","_msg","_mission"];
		diag_log format["blck_Message ====]  Paremeters = _this = %1",_this];
		params["_event","_message",["_mission",""]];

		diag_log format["blck_Message ====]  Paremeters _event %1  _message %2 paramter #3 %3",_event,_message,_mission];
		diag_log format["blck_Message ====] _message isEqualTo  %1",_message];
		
		switch (_event) do 
		{
			case "start": 
					{
						playSound "UAV_05";
						diag_log "switch start";
						//_mission = _this select 1 select 2;
						[_event,_message,_mission] spawn fn_missionNotification;
					};
			case "end": 
					{
						playSound "UAV_03";
						diag_log "switch end";
						//_mission = _this select 1 select 2;
						[_event,_message,_mission] spawn fn_missionNotification;
					};
			case "aikilled": 
					{
						//diag_log "switch aikilled";
						[_message] spawn fn_AI_KilledNotification;
					};
			case "DLS":
					{
						if ( (player distance _mission) < 1000) then {playsound "AddItemOK"; hint _message;systemChat _message};
					};	
			case "reinforcements":
					{
						if ( (player distance _mission) < 1000) then {playsound "AddItemOK"; ["Alert",_message] call fn_dynamicNotification;};
						diag_log "---->>>>  Reinforcements Spotted";
					};
			case "IED":
					{
						[1] call BIS_fnc_Earthquake;
						//["IED","Bandits targeted your vehicle with an IED"] call fn_dynamicNotification;
						  ["Bandits targeted your vehicle with an IED.", 5] call Epoch_message;
						for "_i" from 1 to 3 do {playSound "BattlefieldExplosions3_3D";uiSleep 0.3;};
					};
			case "showScore":
					{
						[_message select 0, _message select 1, _message select 2] call fn_killScoreNotification;
					};
		};

	};
	
	//diag_log "[blckeagls] spawning JIP markers";
	if (!isNil "blck_OrangeMarker") then {[blck_OrangeMarker] execVM "debug\spawnMarker.sqf"};
	if (!isNil "blck_GreenMarker") then {[blck_GreenMarker] execVM "debug\spawnMarker.sqf"};
	if (!isNil "blck_RedMarker") then {[blck_RedMarker] execVM "debug\spawnMarker.sqf"};
	if (!isNil "blck_BlueMarker") then {[blck_BlueMarker] execVM "debug\spawnMarker.sqf"};
	
	diag_log "blck client loaded ver 8/14/16 1.0 7:47 AM";	
	//diag_log "[blckeagls] starting client loop";
	private["_start"];
	_start = diag_tickTime;
	while {true} do
	{
		if !(blck_Message isEqualTo "") then
		{
			diag_log format["[blckClient] blck_Message = %1", blck_message];
			private["_message"];
			_message = blck_message;
			_message spawn fn_handleMessage;
			blck_Message = "";
		} else
		{
			uiSleep 0.3;
		};	
	};
};

