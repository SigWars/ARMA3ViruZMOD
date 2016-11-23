class CfgWorlds {
	class DefaultWorld {
		class Grid;
		class DefaultClutter;
	};
 
	class CAWorld : DefaultWorld {

	};
 
	class Altis : CAWorld {
		cutscenes[] = {"Stratis_intro1"};
		description = "ViruZ Altis";
		pictureMap = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
		pictureShot = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
	};
	class Stratis : CAWorld {
		cutscenes[] = {"Stratis_intro1"};
		description = "ViruZ Stratis";
		pictureMap = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
		pictureShot = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
	};
	class Tanoa : CAWorld {
		cutscenes[] = {"Stratis_intro1"};
		description = "ViruZ Tanoa";
		pictureMap = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
		pictureShot = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
	};
	class Bornholm : CAWorld {
		cutscenes[] = {"Stratis_intro1"};
		description = "ViruZ Bornholm";
		pictureMap = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
		pictureShot = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
	};
		
	class Esseker: CAWorld {
		cutscenes[] = {"Stratis_intro1"};
		description = "ViruZ Esseker";
		pictureMap = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
		pictureShot = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
		worldName="Esseker\Esseker.wrp";
		clutterDist = 250;
		startTime="07:30";
		startDate="05/03/2001";
		startWeather=0.80000001;
		startFog=0;
		forecastWeather=0.80000001;
		forecastFog=0;
		centerPosition[]={2560,2560,500};
		seagullPos[]={2560,2560,500};
		longitude=65;
		latitude=-34;
		elevationOffset=2000;
		envTexture="A3\Data_f\env_land_ca.paa";
		loadingTexts[]=
		{
			"Special thanks to our biggest supporters: FRANKIEonPCin1080p, ePURGEUK, Gamers inc., Breaking Point, CCG... and all who donated",
			"We need your feedback and your support, go to http://a3esseker.info",
			"Esseker Beta Version 0.725 / Under heavy construction /"
		};
		minTreesInForestSquare=2;
		minRocksInRockSquare=2;
		newRoadsShape="\Esseker\data\roads\roads.shp";
		ilsPosition[]={1024,1024};
		ilsDirection[]={0.50749999,0.079999998,-0.86159998};
		ilsTaxiIn[]={};
		ilsTaxiOff[]={};
		drawTaxiway=0;
		class SecondaryAirports
		{
		};
		class Sea
		{
			seaTexture="a3\data_f\seatexture_co.paa";
			seaMaterial="#ES_water";
			shoreMaterial="#shore";
			shoreFoamMaterial="#shorefoam";
			shoreWetMaterial="#shorewet";
			WaterMapScale=20;
			WaterGrid=50;
			MaxTide=0;
			MinTide=0;
			MaxWave=1.5;
			SeaWaveXScale="2.0/50";
			SeaWaveZScale="1.0/50";
			SeaWaveHScale=0.5;
			SeaWaveXDuration=5000;
			SeaWaveZDuration=10000;
		};
		class Underwater
		{
			noWaterFog=-0.001;
			fullWaterFog=0.001;
			deepWaterFog=200;
			waterFogDistanceNear=10;
			waterFogDistance=40;
			waterColor[]={0.15000001,0.090000004,0.050000001,1};
			deepWaterColor[]={0.15000001,0.090000004,0.050000001,1};
			surfaceColor[]={0.15000001,0.090000004,0.050000001,1};
			deepSurfaceColor[]={0.15000001,0.090000004,0.050000001,1};
		};
		class SeaWaterShaderPars
		{
			refractionMoveCoef=0.029999999;
			minWaterOpacity=0;
			waterOpacityDistCoef=0.40000001;
			underwaterOpacity=0.5;
			waterOpacityFadeStart=60;
			waterOpacityFadeLength=120;
		};
		class Grid: Grid
		{
			offsetX=0;
			offsetY=5120;
			class Zoom1
			{
				zoomMax=0.15000001;
				format="XY";
				formatX="000";
				formatY="000";
				stepX=100;
				stepY=-100;
			};
			class Zoom2
			{
				zoomMax=0.85000002;
				format="XY";
				formatX="00";
				formatY="00";
				stepX=1000;
				stepY=-1000;
			};
			class Zoom3
			{
				zoomMax=1e+030;
				format="XY";
				formatX="0";
				formatY="0";
				stepX=10000;
				stepY=-10000;
			};
		};
		class clutter
		{
			class MainGrass: DefaultClutter
			{
				model="cst\cst_veg\clutter\clutter_grass_general.p3d";
				affectedByWind=0.69999999;
				swLighting=1;
				scaleMin=1.3;
				scaleMax=1.5;
			};
			class BrownBushPshonka: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_GrassTall.p3d";
				affectedByWind=0.80000001;
				swLighting=1;
				scaleMin=0.69999999;
				scaleMax=0.89999998;
			};
			class WhiteFlower: DefaultClutter
			{
				model="cst\cst_veg\clutter\clutter_white_flower.p3d";
				affectedByWind=0.69999999;
				swLighting=1;
				scaleMin=1.2;
				scaleMax=2.0999999;
			};
			class PlantYellow: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_plants_Yellow_EP1.p3d";
				affectedByWind=0.69999999;
				swLighting=1;
				scaleMin=0.80000001;
				scaleMax=1.2;
			};
			class GrassFlower: DefaultClutter
			{
				model="cst\cst_veg\clutter\clutter_grass_flowers.p3d";
				affectedByWind=0.69999999;
				swLighting=1;
				scaleMin=0.80000001;
				scaleMax=1.2;
			};
			class Fioletovo: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_Plant_Chicory.p3d";
				affectedByWind=0.69999999;
				swLighting=1;
				scaleMin=0.5;
				scaleMax=1;
			};
			class TriSuhie: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_Plant_Dock.p3d";
				affectedByWind=0.40000001;
				swLighting=1;
				scaleMin=0.69999999;
				scaleMax=0.89999998;
			};
			class WeedPole: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_weed2.p3d";
				affectedByWind=0.40000001;
				swLighting=1;
				scaleMin=0.69999999;
				scaleMax=0.89999998;
			};
			class Grassautumn: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_GrassAutumn.p3d";
				affectedByWind=0.69999999;
				swLighting=1;
				scaleMin=1.8;
				scaleMax=2.3;
			};
			class Vasilki: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_flower_brushmedium_blue.p3d";
				affectedByWind=0.2;
				swLighting=1;
				scaleMin=0.40000001;
				scaleMax=0.60000002;
			};
			class WeedCiv: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_weed_1_ep1.p3d";
				affectedByWind=0.69999999;
				swLighting=1;
				scaleMin=0.5;
				scaleMax=1.2;
			};
			class Hren: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_wideleafplant.p3d";
				affectedByWind=0.2;
				swLighting=1;
				scaleMin=0.5;
				scaleMax=1.2;
			};
			class WhiteSmallBudyak: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_plants_white_ep1.p3d";
				affectedByWind=0.2;
				swLighting=1;
				scaleMin=0.69999999;
				scaleMax=0.89999998;
			};
			class SmallPinkBudyak: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_plants_violet_ep1.p3d";
				affectedByWind=0.2;
				swLighting=1;
				scaleMin=0.89999998;
				scaleMax=1.5;
			};
			class BushPinkBudyak: DefaultClutter
			{
				model="cst\cst_veg\clutter\cwr2_a2_p_carduus.p3d";
				affectedByWind=0.69999999;
				swLighting=1;
				scaleMin=0.5;
				scaleMax=1;
			};
			class GroupYellowBlueFlowers: DefaultClutter
			{
				model="cst\cst_veg\clutter\clutter_smetanka.p3d";
				affectedByWind=0.2;
				swLighting=1;
				scaleMin=0.5;
				scaleMax=0.89999998;
			};
			class OduvanGrSmall: DefaultClutter
			{
				model="cst\cst_veg\clutter\mb_c_taraxacum01.p3d";
				affectedByWind=0.2;
				swLighting=1;
				scaleMin=0.19;
				scaleMax=0.20999999;
			};
			class OduvanGrBig: DefaultClutter
			{
				model="cst\cst_veg\clutter\mb_c_taraxacum02.p3d";
				affectedByWind=0.2;
				swLighting=1;
				scaleMin=0.07;
				scaleMax=0.15000001;
			};
			class Oduvan: DefaultClutter
			{
				model="cst\cst_veg\clutter\cwr_dandelion.p3d";
				affectedByWind=0.2;
				swLighting=1;
				scaleMin=0.89999998;
				scaleMax=1.1;
			};
			class LowDryGrass: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_strgrassdry.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.5;
				scaleMax=1.2;
			};
			class GrassCivBig: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_grassautumn_t.p3d";
				affectedByWind=0.69999999;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.80000001;
			};
			class GreenBushPshonka: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_grassbunch.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.30000001;
				scaleMax=0.69999999;
			};
			class RandomWeed: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_weed3.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.30000001;
				scaleMax=0.60000002;
			};
			class Chortopolokh: DefaultClutter
			{
				model="cst\cst_veg\clutter\bodlak_group.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.5;
				scaleMax=0.89999998;
			};
			class WhiteBigBudyak: DefaultClutter
			{
				model="cst\cst_veg\clutter\cwr_common_yarrow.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.5;
				scaleMax=0.75;
			};
			class MakSingle1: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_papaver_flower01_ep1.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.40000001;
				scaleMax=0.69999999;
			};
			class MakBush: DefaultClutter
			{
				model="cst\cst_veg\clutter\p_papaver_ep1.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.89999998;
				scaleMax=1.2;
			};
			class FlowerMix: DefaultClutter
			{
				model="cst\cst_veg\clutter\clutter_flower_mix.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.80000001;
				scaleMax=1.4;
			};
			class Trizub: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_plant_mullein.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class Muhomor: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_mushroommuchomurka.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class Grib1: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_mushroombabka.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class Grib2: DefaultClutter
			{
				model="cst\cst_veg\clutter\clutter_babka.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class GribGr1: DefaultClutter
			{
				model="cst\cst_veg\clutter\clutter_horcak.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class GribGr2: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_mushroomhorcak.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class PogankaGr: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_mushroomprasivky.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class IvySmall: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_blueberry.p3d";
				affectedByWind=0.1;
				swLighting=1;
				scaleMin=1;
				scaleMax=1.7;
			};
			class PineClutter: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_picea.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class PaporotnikBig: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_fern.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=1.5;
				scaleMax=1.8;
			};
			class PaporotnikSmall: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_fern.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.69999999;
				scaleMax=1.5;
			};
			class PaporotnikGr: DefaultClutter
			{
				model="cst\cst_veg\clutter\clutter_forest_fern.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class Elm1: DefaultClutter
			{
				model="cst\cst_veg\clutter\mb_c_ulmus01.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.30000001;
				scaleMax=0.40000001;
			};
			class Elm2: DefaultClutter
			{
				model="cst\cst_veg\clutter\mb_c_ulmus02.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.40000001;
				scaleMax=0.60000002;
			};
			class Elm3: DefaultClutter
			{
				model="cst\cst_veg\clutter\mb_c_ulmus03.p3d";
				affectedByWind=0.5;
				swLighting=1;
				scaleMin=0.5;
				scaleMax=0.80000001;
			};
			class Vetka1: DefaultClutter
			{
				model="cst\cst_veg\clutter\vetev_1_buk.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class Vetka2: DefaultClutter
			{
				model="cst\cst_veg\clutter\vetev_2_dub.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class Vetka3: DefaultClutter
			{
				model="cst\cst_veg\clutter\vetev_4_smrk.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class Vetka4: DefaultClutter
			{
				model="cst\cst_veg\clutter\vetev_3_borovice.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class Kamni1: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_stonemiddlegroupcamp_ep1.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class Kamni2: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_stonemiddlegroupmount_ep1.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class Kamni3: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_stonemiddlesharpsingle_ep1.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class Kamni4: DefaultClutter
			{
				model="cst\cst_veg\clutter\c_stonesmallrounded_ep1.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class KamenBig: DefaultClutter
			{
				model="cst\cst_veg\clutter\clutter_md_stonesmall.p3d";
				affectedByWind=0;
				swLighting=1;
				scaleMin=0.60000002;
				scaleMax=0.89999998;
			};
			class ES_grassLush: DefaultClutter
			{
				model="A3\plants_f\Clutter\c_GrassDesert_GroupHard.p3d";
				affectedByWind=0.80000001;
				swLighting="true";
				scaleMin=1.3;
				scaleMax=1.5;
			};
			class ES_GrassTall01: DefaultClutter
			{
				model="CST\CST_Veg\Clutter\c_weed3.p3d";
				affectedByWind=1.5;
				swLighting="true";
				scaleMin=0.69999999;
				scaleMax=1;
			};
			class ES_ClutterGrassGeneral: DefaultClutter
			{
				model="CST\CST_Veg\Clutter\clutter_grass_general.p3d";
				affectedByWind=1.5;
				swLighting="true";
				scaleMin=0.69999999;
				scaleMax=1;
			};
			class ES_GrassBunch: DefaultClutter
			{
				model="CST\CST_Veg\Clutter\c_grassBunch.p3d";
				affectedByWind=0.80000001;
				swLighting="true";
				scaleMin=0.69999999;
				scaleMax=1;
			};
			class ES_Dandelion: DefaultClutter
			{
				model="CST\CST_Veg\Clutter\cwr_dandelion.p3d";
				affectedByWind=0.80000001;
				swLighting="true";
				scaleMin=0.69999999;
				scaleMax=1;
			};
			class ES_StrGrassGreenGroup: DefaultClutter
			{
				model="A3\plants_f\Clutter\c_StrGrassGreen_group.p3d";
				affectedByWind=0.60000002;
				swLighting="true";
				scaleMin=0.69999999;
				scaleMax=1;
			};
		};
		class Names
		{
			class Posestra
			{
				name="Posestra";
				position[]={7654.21,6893.3901};
				type="NameCity";
				radiusA=600;
				radiusB=200;
				angle=0;
			};
			class Chokory
			{
				name="Chokory";
				position[]={4860.2002,8080.8101};
				type="NameCity";
				radiusA=550;
				radiusB=200;
				angle=0;
			};
			class tvrdja
			{
				name="Old Esseker";
				position[]={8680.3799,5473.9102};
				type="NameVillage";
				radiusA=350;
				radiusB=127.37;
				angle=0;
			};
			class PlominoPowerStation
			{
				name="Plomino Power Station";
				position[]={5146.5801,4684.6602};
				type="NameVillage";
				radiusA=800;
				radiusB=200;
				angle=0;
			};
			class Bayer
			{
				name="Bayer";
				position[]={3385.8501,4666.4102};
				type="FlatAreaCitySmall";
				radiusA=150;
				radiusB=150;
				angle=0;
			};
			class Scrapyard
			{
				name="Scrapyard";
				position[]={4733.4702,4691.0098};
				type="NameLocal";
				radiusA=100;
				radiusB=41.740002;
				angle=0;
			};
			class KamenQuarry
			{
				name="Kamen Quarry";
				position[]={11065.94,9034.8301};
				type="NameLocal";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class Lokve
			{
				name="Lokve";
				position[]={10081.16,10140.56};
				type="NameLocal";
				radiusA=150;
				radiusB=101.89;
				angle=0;
			};
			class IgmanmilitaryBase
			{
				name="Igman Military base";
				position[]={7641.77,10151.7};
				type="NameCity";
				radiusA=800;
				radiusB=300;
				angle=0;
			};
			class Zelengora
			{
				name="ZelenGora Mountains";
				position[]={10471.83,7092.8599};
				type="Hill";
				radiusA=1372.13;
				radiusB=948.95001;
				angle=0;
			};
			class Rama
			{
				name="Rama";
				position[]={2077.6299,7802.5};
				type="NameCity";
				radiusA=350;
				radiusB=248.75999;
				angle=0;
			};
			class Melina
			{
				name="Melina";
				position[]={3564.79,6982.8999};
				type="NameCity";
				radiusA=400;
				radiusB=300;
				angle=0;
			};
			class Focha
			{
				name="Focha";
				position[]={5511.4199,7439.7202};
				type="NameVillage";
				radiusA=450;
				radiusB=250;
				angle=0;
			};
			class AdelaAirfield
			{
				name="Adela Airfield";
				position[]={9984.8301,4866.3799};
				type="NameCity";
				radiusA=700;
				radiusB=159.21001;
				angle=0;
			};
			class InMemoriaMonument
			{
				name="In Memoria Titanis";
				position[]={8058.5298,9508.2695};
				type="ViewPoint";
				radiusA=800;
				radiusB=300;
				angle=0;
			};
			class Lug
			{
				name="Lug";
				position[]={6265.9102,6875.04};
				type="NameVillage";
				radiusA=350;
				radiusB=300;
				angle=0;
			};
			class ESPetrol
			{
				name="ES Petrol";
				position[]={4004.6101,9305.6299};
				type="NameVillage";
				radiusA=400;
				radiusB=199.00999;
				angle=0;
			};
			class Novidan
			{
				name="Novi Grad";
				position[]={11862.44,8002.9502};
				type="NameCity";
				radiusA=600;
				radiusB=200;
				angle=0;
			};
			class CahrdakResort
			{
				name="Chardak Resort";
				position[]={10131.86,7931.1499};
				type="NameVillage";
				radiusA=450;
				radiusB=80.559998;
				angle=0;
			};
			class Pilanasawmill
			{
				name="Pilana Sawmill";
				position[]={9014.5996,7945.77};
				type="NameVillage";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class Kula
			{
				name="Kula";
				position[]={4961,5241.46};
				type="NameCity";
				radiusA=250;
				radiusB=245.86;
				angle=0;
			};
			class CampSpencer
			{
				name="Camp Spencer";
				position[]={1159.49,10316.17};
				type="NameCity";
				radiusA=550;
				radiusB=300;
				angle=0;
			};
			class Borosh
			{
				name="Borosh";
				position[]={10010.08,9941.8604};
				type="NameCity";
				radiusA=450;
				radiusB=180;
				angle=0;
			};
			class Krupa
			{
				name="Krupa";
				position[]={1968.08,4217.8901};
				type="NameCity";
				radiusA=300;
				radiusB=150;
				angle=0;
			};
			class Kupres
			{
				name="Kupres";
				position[]={2680.0601,4688.4502};
				type="NameCity";
				radiusA=450;
				radiusB=200;
				angle=0;
			};
			class NeptuneResort
			{
				name="Neptune Resort";
				position[]={6433.3599,5525.8799};
				type="NameCity";
				radiusA=400;
				radiusB=199;
				angle=0;
			};
			class Tuk
			{
				name="Tuk";
				position[]={7153.4102,9348.54};
				type="NameCity";
				radiusA=300;
				radiusB=200;
				angle=0;
			};
			class Gulash
			{
				name="Gulash";
				position[]={6347.4302,6164.6401};
				type="NameCity";
				radiusA=400;
				radiusB=300;
				angle=0;
			};
			class GroznaPlanina
			{
				name="Grozna Mountain";
				position[]={2656.03,1269.24};
				type="Hill";
				radiusA=2788.6699;
				radiusB=1853.34;
				angle=0;
			};
			class Drava
			{
				name="River Drava";
				position[]={8838.21,5078.5801};
				type="NameMarine";
				radiusA=913.78998;
				radiusB=607.29999;
				angle=0;
			};
			class Nekrashuk
			{
				name="Nekrashuk";
				position[]={4972.9702,10318.58};
				type="NameCity";
				radiusA=400;
				radiusB=159.2;
				angle=0;
			};
			class MatijaWeissCollege
			{
				name="Matija Weiss College";
				position[]={7372.5298,5310.04};
				type="NameVillage";
				radiusA=130.32001;
				radiusB=86.610001;
				angle=0;
			};
			class Gromada
			{
				name="Gromada";
				position[]={9963.7002,10879.99};
				type="NameCity";
				radiusA=450;
				radiusB=300;
				angle=0;
			};
			class DanilovGrad
			{
				name="Danilov Grad";
				position[]={3104.1299,6156.7598};
				type="NameCity";
				radiusA=700;
				radiusB=250;
				angle=0;
			};
			class PlavaVrana
			{
				name="Plava Vrana Military Complex";
				position[]={6655.2202,3908.51};
				type="NameCity";
				radiusA=500;
				radiusB=300;
				angle=0;
			};
			class DoubleTapGunRange
			{
				name="DoubleTap Gun Range";
				position[]={2799.28,11262.96};
				type="Hill";
				radiusA=400;
				radiusB=52.169998;
				angle=0;
			};
			class LowerEsseker
			{
				name="Lower Esseker";
				position[]={10722.8,5503.3398};
				type="NameVillage";
				radiusA=731.03003;
				radiusB=485.84;
				angle=0;
			};
			class EssekerIndustry
			{
				name="Esseker Industrial Zone";
				position[]={8301.1504,5684.96};
				type="NameVillage";
				radiusA=731.03003;
				radiusB=485.84;
				angle=0;
			};
			class EssekerCenter
			{
				name="Esseker City Center";
				position[]={10074.41,5623.6001};
				type="CityCenter";
				radiusA=254;
				radiusB=169.16;
				angle=0;
			};
			class DonatorPark
			{
				name="Donator Park";
				position[]={8785.7402,5695.3501};
				type="VegetationBroadleaf";
				radiusA=150;
				radiusB=35.470001;
				angle=0;
			};
			class junkyard
			{
				name="Petlov JunkYard";
				position[]={4297.0801,3002.3799};
				type="Hill";
				radiusA=466.75;
				radiusB=310.95001;
				angle=0;
			};
			class PetlovGrad
			{
				name="Petlov Grad";
				position[]={4611.9199,3545.3401};
				type="Hill";
				radiusA=700;
				radiusB=700;
				angle=0;
			};
		};
	};

	class Chernarus: CAWorld {
		cutscenes[] = {"Stratis_intro1"};
		description = "ViruZ Chernarus"; 
		pictureMap = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
		pictureShot = "z\addons\viruz_mod\gui\viruz_logo_ca.paa";
	};

};
