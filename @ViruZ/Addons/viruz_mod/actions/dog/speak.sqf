private ["_dog"];
_dog = _this select 3;

_dog playActionNow "GestureBark";
[_dog,"dog_bark",0,false] call viruz_zombieSpeak;