private ["_oldClanGroup","_needClan","_clanname"];

/*_oldClanGroup = player getVariable ["ClanID","0"];
_needClan = (_oldClanGroup isEqualTo (name player));

if !(_needClan)then
{
	_clanname = player getVariable ["clanName",name player];
	
	{
		if (_clanname == groupID _x) exitWith { [player] join _x;};
	}forEach allGroups; 
	
	systemChat "You have left the group";
}
else
{*/
	[player] join grpNull;
	player setVariable ["canInivite",time+30,true];
	systemChat "You have left the group";
//};