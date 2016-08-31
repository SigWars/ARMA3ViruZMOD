class CfgSFX {
	class Generator1
	{
		sounds[] = {"Generator1"};
		name = "Generator1";
		//RandSamp0[] = {SOUNDFILE,VOLUME,PITCH,DISTANCE,PROBABILLITY,Min DELAY,Mid DELAY,Max DELAY}
		Generator1[] = 	{"\viruz_sound\effects\generator1",db+10,1,200,1,0,0,0};
		Empty[] = 	{"",0,0,0,0,0,0,0};
	};

	class FMradio_radio_static {
		sounds[] = {"radio_static"};
		name = "radio_static";
		radio_static[] = {"\viruz_sound\effects\radio_static.ogg", 1.0, 1, 100, 1, 0.0, 0.0, 0.0};
		empty[] = {"", 0, 0, 0, 0, 0, 0, 0};
	};
	
	class FMradio_radio1 {
		sounds[] = {"radio1"};
		name = "FMradio_radio1";
		radio1[] = {"A3\Sounds_F\sfx\radio\ambient_radio1", 1.0, 1, 100, 1, 0.0, 0.0, 0.0};
		empty[] = {"", 0, 0, 0, 0, 0, 0, 0};
	};

	class FMradio_Alarm {
		sounds[] = {"FMradio_Alarm"};
		name = "FMradio_Alarm";
		FMradio_Alarm[] = {"A3\Sounds_F\sfx\alarm", 1.0, 1, 100, 1, 0.0, 0.0, 0.0};
		empty[] = {"", 0, 0, 0, 0, 0, 0, 0};
	};
};