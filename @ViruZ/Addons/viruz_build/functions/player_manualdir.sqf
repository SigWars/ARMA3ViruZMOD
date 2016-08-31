/*
ViruZ Mod for Arma 3
Autor: SigWar
This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/

if (ManualDir) then {
	ManualDir = false;
	VIRUZ_Build_object setVariable ["viruz_build_objectDir",0,true];
	//SnappingAttachedToPlayer = false;
	systemChat ("Manual Direction - DISABLED");
} else {
	ManualDir = true;
	VIRUZ_Build_object setVariable ["viruz_build_objectDir",0,true];
	systemChat ("Manual Direction - ENABLED");
	//hintSilent parseText format["<t size='0.8' font='Zeppelin33' color='#01DF01'>Use keys </t><t size='1' font='Zeppelin33' color='#FE642E'>J L </t><t size='0.8' font='Zeppelin33' color='#01DF01'>To set Direction</t>", 0];
	_text1 = "<t size='0.8' font='Zeppelin33' color='#01DF01'>Use keys </t>";
	_text2 = "<t size='1' font='Zeppelin33' color='#FE642E'>J L </t>";
	_text3 = "<t size='0.8' font='Zeppelin33' color='#01DF01'>To set Direction</t>";
	_finaltext = _text1 + _text2 + _text3;
	
	[
		_finaltext, //structured text
		0.24 * safezoneW + safezoneX, //number - x
		0.01 * safezoneH + safezoneY, //number - y
		5, //number - duration
		1, // number - fade in time
		0, // number - delta y
		0 //number - layer ID
	] spawn bis_fnc_dynamicText;
};