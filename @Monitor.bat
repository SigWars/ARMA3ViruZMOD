@echo off
taskkill /F /IM arma3server.exe
taskkill /F /IM Bec.exe
call pkViruZChernarus.cmd
timeout 5
cls
echo Watching arma3server For Crashes/Restarts...
echo If you want to close arma3server and this script, close the arma3server window and type Y depending on your language followed by Enter.
title SigWar ViruZ Monitor
set becpath="C:\Arma3Server\BEC\"
cd /d %becpath%
:arma3server
start "BattleEye Extended Control" "BEC Control.bat"
echo (%time%) arma3server started.
start /wait "viruz" /min /high "C:\Arma3Server\arma3server.exe" -port=2302 "-config=C:\Arma3Server\ViruZ\serverchernarus.cfg" "-cfg=C:\Arma3Server\ViruZ\basic.cfg" "-profiles=ViruZ" -name=ViruZ "-mod=@CBA_A3;@ViruZ;@CUP_Terrains_Core-1.2.0;@CUP_Terrains_Maps-1.2.0;@CUP_Weapons;" "-Servermod=@hive;@CBA_A3;@infiSTAR_A3;@ViruZ;@CUP_Terrains_Core-1.2.0;@CUP_Terrains_Maps-1.2.0;@CUP_Weapons;" -enableHT -autoinit
echo (%time%) WARNING: arma3server closed or crashed, restarting.
// TIMEOUT /T 180 /NOBREAK
goto arma3server