class CfgVehicles {
	class All;
	class Sound: All {};
	
	class Sound_Generator1: Sound
	{
		scope = public;
		sound = "Generator1";
		displayName = "Generator";
	};

	class Sound_FMradio_static: Sound
	{
		scope = public;
		sound = "FMradio_radio_static";
		displayName = "FMradio_radio_static";
	};
	
	class Sound_FMradio_radio1: Sound
	{
		scope = public;
		sound = "FMradio_radio1";
		displayName = "FMradio_radio1";
	};

	class Sound_FMradio_Alarm: Sound
	{
		scope = public;
		sound = "FMradio_Alarm";
		displayName = "FMradio_Alarm";
	};
};