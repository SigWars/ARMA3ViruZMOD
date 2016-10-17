@echo off
cls
echo Watching ViruZServer For Crashes/Restarts...
echo If you want to close ViruZServer and this script, close the ViruZServer window and type Y depending on your language followed by Enter.
title SigWar ViruZ Monitor
set becpath="C:\Arma3Server\BEC\"
cd /d %becpath%
:ViruZServer
start "BattleEye Extended Control" "BEC Control.bat"
echo (%time%) ViruZServer started.
start /wait "viruz" /min /high "C:\Arma3Server\viruzserver.exe" -port=2302 "-config=C:\Arma3Server\ViruZ\serverchernarus.cfg" "-cfg=C:\Arma3Server\ViruZ\basic.cfg" "-profiles=ViruZ" -name=ViruZ -filePatching "-mod=@CBA_A3;@ViruZ;@CUP_Terrains_Core-1.2.0;@CUP_Terrains_Maps-1.2.0;@CUP_Weapons;" "-Servermod=@hive;@CBA_A3;@infiSTAR_A3;@ViruZ;@CUP_Terrains_Core-1.2.0;@CUP_Terrains_Maps-1.2.0;@CUP_Weapons;" -autoinit -loadmissiontomemory
echo (%time%) WARNING: ViruZServer closed or crashed, restarting.
// TIMEOUT /T 180 /NOBREAK
goto ViruZServer