@echo off
echo Stopping server
cd C:\Arma3Server
start /wait  @Premod_stop.bat
echo Starting BEC
cd C:\Arma3Server\BEC
start Bec.exe -f Config.cfg
echo Starting server
cd C:\Arma3Server
start "viruzserver" "viruzserver" /min /high "C:\Arma3Server\viruzserver.exe" -port=2302 "-config=C:\Arma3Server\ViruZ\serverchernarus.cfg" "-cfg=C:\Arma3Server\ViruZ\basic.cfg" "-profiles=ViruZ" -name=ViruZ -filePatching "-mod=@CBA_A3;@ViruZ;@CUP_Terrains_Core-1.2.0;@CUP_Terrains_Maps-1.2.0;@CUP_Weapons;" "-Servermod=@hive;@CBA_A3;@infiSTAR_A3;@ViruZ;@CUP_Terrains_Core-1.2.0;@CUP_Terrains_Maps-1.2.0;@CUP_Weapons;" -autoinit -loadmissiontomemory
ping 127.0.0.1 -n 5 >NUL