//////////////////////////////////////////////////////////////////////////
//START EARPLUGS CODE

5 fadeSound 1;
earplugsout = true;
removeAllActions inCaseofDeath;
removeAllActions theOneTrueName;
inCaseofDeath setVariable ["HasEarplugMenu","hasNoMenu"];
theOneTrueName setVariable ["HasEarplugMenu","hasNoMenu"];
player setVariable ["Has_EPEH_Loop", "Yep"];
//systemChat "Diablo's minions grow stronger...";

(findDisplay 46) displayRemoveEventHandler ["KeyDown", cmKeyPress];

//cmEARPLUGS CODE END
//////////////////////////////////////////////////////////////////////////
sleep 1;
for "_x" from 10 to 1 step -1 do {titleText [format["Returning to lobby in %1 second(s)...", _x], "PLAIN DOWN", 1]; sleep 1;};
//PVDZE_Server_Simulation = [_body, false];
//publicVariableServer "PVDZE_Server_Simulation";
endMission "END1";