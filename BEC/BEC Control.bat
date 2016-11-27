:: KILL BATTLEYE
taskkill /im Bec.exe
timeout 1

TIMEOUT /T 180 /NOBREAK
cd\
cd "C:\Arma3Server\BEC\"
bec.exe -f Config.cfg --dsc
