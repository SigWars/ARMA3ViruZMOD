class RscDisplayLoadViruZ: RscStandardDisplay
{
	idd=101;
	onLoad="[""onLoad"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	onUnload="[""onUnload"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	class controlsBackground
	{
		delete CA_Vignette;
		delete Noise;
		class Black: RscText
		{
			colorBackground[]={0,0,0,1};
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneWAbs";
			h="safezoneH";
		};
		class Map: RscPicture
		{
			idc=999;
			text="\z\addons\viruz_mod\loading\loading_1.jpg";
			colorText[]={1,1,1,1};
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="safezoneH";
		};
	};
	class controls
	{
		delete Title;
		delete Name;
		delete Briefing;
		delete Progress;
		delete Progress2;
		delete Date;
		delete MapBackTop;
		delete MapName;
		delete MapAuthor;
		delete MapBackBottom;
		delete MapDescription;
		delete Mission;
		delete ProgressMap;
		delete ProgressMission;
		delete Disclaimer;
		class LoadingStart: RscControlsGroup
		{
			idc=2310;
			x="0 * safezoneW + safezoneX";
			y="0 * safezoneH + safezoneY";
			w="1 * safezoneW";
			h="1 * safezoneH";
			class controls
			{
				class Black: RscText
				{
					colorBackground[]={0,0,0,1};
					x="safezoneXAbs";
					y="safezoneY";
					w="safezoneWAbs";
					h="safezoneH";
				};
				delete Noise;
				class Logo: RscPicture
				{
					idc=1200;
					text="\z\addons\viruz_mod\loading\loading_1.jpg";
					colorText[]={1,1,1,1};
					x="0 * safezoneW";
					y="0 * safezoneH";
					w="1 * safezoneW";
					h="1 * safezoneH";
				};
			};
		};
	};
};



class RscDisplayLoadMission: RscStandardDisplay
{
	idd=101;
	onLoad="[""onLoad"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	onUnload="[""onUnload"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	class controlsBackground
	{
		delete CA_Vignette;
		delete Noise;
		class Black: RscText
		{
			colorBackground[]={0,0,0,1};
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneWAbs";
			h="safezoneH";
		};
		class Map: RscPicture
		{
			idc=999;
			text="\z\addons\viruz_mod\loading\loading_3.jpg";
			colorText[]={1,1,1,1};
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="safezoneH";
		};
	};
	class controls
	{
		delete Title;
		delete Name;
		delete Briefing;
		delete Progress;
		delete Progress2;
		delete Date;
		delete MapBackTop;
		delete MapName;
		delete MapAuthor;
		delete MapBackBottom;
		delete MapDescription;
		delete Mission;
		delete ProgressMap;
		delete ProgressMission;
		delete Disclaimer;
		class LoadingStart: RscControlsGroup
		{
			idc=2310;
			x="0 * safezoneW + safezoneX";
			y="0 * safezoneH + safezoneY";
			w="1 * safezoneW";
			h="1 * safezoneH";
			class controls
			{
				class Black: RscText
				{
					colorBackground[]={0,0,0,1};
					x="safezoneXAbs";
					y="safezoneY";
					w="safezoneWAbs";
					h="safezoneH";
				};
				delete Noise;
				class Logo: RscPicture
				{
					idc=1200;
					text="\z\addons\viruz_mod\loading\loading_3.jpg";
					colorText[]={1,1,1,1};
					x="0 * safezoneW";
					y="0 * safezoneH";
					w="1 * safezoneW";
					h="1 * safezoneH";
				};
			};
		};
	};
};
class RscDisplayLoadCustom: RscStandardDisplay
{
	idd=101;
	onLoad="[""onLoad"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	onUnload="[""onUnload"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	class controlsBackground
	{
		delete CA_Vignette;
		delete Noise;
		class Black: RscText
		{
			colorBackground[]={0,0,0,1};
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneWAbs";
			h="safezoneH";
		};
		class Map: RscPicture
		{
			idc=999;
			text="\z\addons\viruz_mod\loading\loading_3.jpg";
			colorText[]={1,1,1,1};
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="safezoneH";
		};
	};
	class controls
	{
		delete Title;
		delete Name;
		delete Briefing;
		delete Progress;
		delete Progress2;
		delete Date;
		delete MapBackTop;
		delete MapName;
		delete MapAuthor;
		delete MapBackBottom;
		delete MapDescription;
		delete Mission;
		delete ProgressMap;
		delete ProgressMission;
		delete Disclaimer;
		class LoadingStart: RscControlsGroup
		{
			idc=2310;
			x="0 * safezoneW + safezoneX";
			y="0 * safezoneH + safezoneY";
			w="1 * safezoneW";
			h="1 * safezoneH";
			class controls
			{
				class Black: RscText
				{
					colorBackground[]={0,0,0,1};
					x="safezoneXAbs";
					y="safezoneY";
					w="safezoneWAbs";
					h="safezoneH";
				};
				delete Noise;
				class Logo: RscPicture
				{
					idc=1200;
					text="\z\addons\viruz_mod\loading\loading_3.jpg";
					colorText[]={1,1,1,1};
					x="0 * safezoneW";
					y="0 * safezoneH";
					w="1 * safezoneW";
					h="1 * safezoneH";
				};
			};
		};
	};
};
class RscDisplayNotFreeze: RscStandardDisplay
{
	idd=101;
	onLoad="[""onLoad"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	onUnload="[""onUnload"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	class controlsBackground
	{
		delete CA_Vignette;
		delete Noise;
		class Black: RscText
		{
			colorBackground[]={0,0,0,1};
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneWAbs";
			h="safezoneH";
		};
		class Map: RscPicture
		{
			idc=999;
			text="\z\addons\viruz_mod\loading\loading_3.jpg";
			colorText[]={1,1,1,1};
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="safezoneH";
		};
	};
	class controls
	{
		delete Title;
		delete Name;
		delete Briefing;
		delete Progress;
		delete Progress2;
		delete Date;
		delete MapBackTop;
		delete MapName;
		delete MapAuthor;
		delete MapBackBottom;
		delete MapDescription;
		delete Mission;
		delete ProgressMap;
		delete ProgressMission;
		delete Disclaimer;
		class LoadingStart: RscControlsGroup
		{
			idc=2310;
			x="0 * safezoneW + safezoneX";
			y="0 * safezoneH + safezoneY";
			w="1 * safezoneW";
			h="1 * safezoneH";
			class controls
			{
				class Black: RscText
				{
					colorBackground[]={0,0,0,1};
					x="safezoneXAbs";
					y="safezoneY";
					w="safezoneWAbs";
					h="safezoneH";
				};
				delete Noise;
				class Logo: RscPicture
				{
					idc=1200;
					text="\z\addons\viruz_mod\loading\loading_3.jpg";
					colorText[]={1,1,1,1};
					x="0 * safezoneW";
					y="0 * safezoneH";
					w="1 * safezoneW";
					h="1 * safezoneH";
				};
			};
		};
	};
};
class RscDisplayClientWait: RscStandardDisplay
{
	idd=101;
	onLoad="[""onLoad"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	onUnload="[""onUnload"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	class controlsBackground
	{
		delete CA_Vignette;
		delete Noise;
		class Black: RscText
		{
			colorBackground[]={0,0,0,1};
			x="safezoneXAbs";
			y="safezoneY";
			w="safezoneWAbs";
			h="safezoneH";
		};
		class Map: RscPicture
		{
			idc=999;
			text="\z\addons\viruz_mod\loading\loading_1.jpg";
			colorText[]={1,1,1,1};
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="safezoneH";
		};
	};
	class controls
	{
		delete Title;
		delete Name;
		delete Briefing;
		delete Progress;
		delete Progress2;
		delete Date;
		delete MapBackTop;
		delete MapName;
		delete MapAuthor;
		delete MapBackBottom;
		delete MapDescription;
		delete Mission;
		delete ProgressMap;
		delete ProgressMission;
		delete Disclaimer;
		class LoadingStart: RscControlsGroup
		{
			idc=2310;
			x="0 * safezoneW + safezoneX";
			y="0 * safezoneH + safezoneY";
			w="1 * safezoneW";
			h="1 * safezoneH";
			class controls
			{
				class Black: RscText
				{
					colorBackground[]={0,0,0,1};
					x="safezoneXAbs";
					y="safezoneY";
					w="safezoneWAbs";
					h="safezoneH";
				};
				delete Noise;
				class Logo: RscPicture
				{
					idc=1200;
					text="\z\addons\viruz_mod\loading\loading_1.jpg";
					colorText[]={1,1,1,1};
					x="0 * safezoneW";
					y="0 * safezoneH";
					w="1 * safezoneW";
					h="1 * safezoneH";
				};
			};
		};
	};
};

class RscDisplayLoading
{
	idd=102;
	onLoad="[""onLoad"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	onUnload="[""onUnload"",_this,""RscDisplayLoading""] call compile preprocessfilelinenumbers ""\z\addons\viruz_mod\ui\scripts\RscDisplayLoading.sqf""";
	class Variants
	{
		class LoadingOne: RscDisplayLoadViruZ
		{
		};
		class Loading: RscDisplayLoadViruZ
		{
		};
	};
};

class CfgLoadingScreens
{
	class World
	{
		General[]=
		{
			"\z\addons\viruz_mod\loading\loading_1.jpg",
			"\z\addons\viruz_mod\loading\loading_2.jpg",
			"\z\addons\viruz_mod\loading\loading_3.jpg"
			
		};
		Altis[]=
		{
			"\z\addons\viruz_mod\loading\Altis\loading_1.jpg",
			"\z\addons\viruz_mod\loading\Altis\loading_2.jpg",
			"\z\addons\viruz_mod\loading\Altis\loading_3.jpg"
		};
		Stratis[]=
		{
			"\z\addons\viruz_mod\loading\Stratis\loading_1.jpg"
		};
		thirsk[]=
		{
			"\z\addons\viruz_mod\loading\thrisk\loading_1.jpg",
			"\z\addons\viruz_mod\loading\thrisk\loading_2.jpg"
		};
		thirskw[]=
		{
			"\z\addons\viruz_mod\loading\thriskw\loading_1.jpg",
			"\z\addons\viruz_mod\loading\thriskw\loading_2.jpg"
		};
		newhaven[]=
		{
			"\z\addons\viruz_mod\loading\newhaven\loading_1.jpg",
			"\z\addons\viruz_mod\loading\newhaven\loading_2.jpg"
		};
		Bornholm[]=
		{
			"\z\addons\viruz_mod\loading\Bornholm\loading_1.jpg",
			"\z\addons\viruz_mod\loading\Bornholm\loading_2.jpg",
			"\z\addons\viruz_mod\loading\Bornholm\loading_3.jpg",
			"\z\addons\viruz_mod\loading\Bornholm\loading_4.jpg",
			"\z\addons\viruz_mod\loading\Bornholm\loading_5.jpg",
			"\z\addons\viruz_mod\loading\Bornholm\loading_6.jpg"
		};
		Esseker[]=
		{
			"\z\addons\viruz_mod\loading\Esseker\loading_1.jpg",
			"\z\addons\viruz_mod\loading\Esseker\loading_2.jpg",
			"\z\addons\viruz_mod\loading\Esseker\loading_3.jpg"
		};
		Taviana[]=
		{
			"\z\addons\viruz_mod\loading\Esseker\loading_1.jpg",
			"\z\addons\viruz_mod\loading\Esseker\loading_2.jpg",
			"\z\addons\viruz_mod\loading\Esseker\loading_3.jpg"
		};
		Chernarus[]=
		{
			"\z\addons\viruz_mod\loading\Chernarus\loading_1.jpg",
			"\z\addons\viruz_mod\loading\Chernarus\loading_2.jpg",
			"\z\addons\viruz_mod\loading\Chernarus\loading_3.jpg"
		};
		namalsk[]=
		{
			"\z\addons\viruz_mod\loading\Namalsk\loading_1.jpg",
			"\z\addons\viruz_mod\loading\Namalsk\loading_2.jpg",
			"\z\addons\viruz_mod\loading\Namalsk\loading_3.jpg"
		};
	};
};