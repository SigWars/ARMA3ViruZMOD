class CfgFaces {
	class Default;	// External class reference

	class Zombie1 : Default {
		class Default;	// External class reference

		class Zombie1 : Default {
			texture = "\viruz_zombie\textures\faces\m_white_01_co.paa";			
			head = "DefaultHead_A3";
			identityTypes[] = {"Zombie1"};
			textureHL = "\viruz_zombie\textures\faces\hl_White_hairy_1_co.paa";
			textureHL2 = "\viruz_zombie\textures\faces\hl_White_hairy_1_co.paa";
			materialHL = "\A3\Characters_F\Heads\Data\hl_White_hairy_muscular.rvmat";
			materialHL2 = "\A3\Characters_F\Heads\Data\hl_White_hairy_muscular.rvmat";
		};
		class Zombie2: Default
		{
			name = "Zombie 2";
			texture = "\viruz_zombie\textures\faces\m_white_01_co.paa";	
			identityTypes[] = {"Zombie1"};	
			head = "DefaultHead_A3";
			textureHL = "\viruz_zombie\textures\faces\hl_White_hairy_1_co.paa";
			textureHL2 = "\viruz_zombie\textures\faces\hl_White_hairy_1_co.paa";
		};
		class Zombie3: Default
		{
			name = "Zombie 2";
			texture = "\viruz_zombie\textures\faces\m_white_01_co.paa";	
			identityTypes[] = {"Zombie1"};	
			head = "DefaultHead_A3";
			textureHL = "\viruz_zombie\textures\faces\hl_White_hairy_1_co.paa";
			textureHL2 = "\viruz_zombie\textures\faces\hl_White_hairy_1_co.paa";
		};
		class Zombie4: Default
		{
			name = "Zombie 2";
			texture = "\viruz_zombie\textures\faces\m_white_01_co.paa";	
			identityTypes[] = {"Zombie1"};	
			head = "DefaultHead_A3";
			textureHL = "\viruz_zombie\textures\faces\hl_White_hairy_1_co.paa";
			textureHL2 = "\viruz_zombie\textures\faces\hl_White_hairy_1_co.paa";
		};
	};
};