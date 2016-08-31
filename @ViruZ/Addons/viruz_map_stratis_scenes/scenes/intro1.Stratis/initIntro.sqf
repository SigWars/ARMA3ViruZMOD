0 fadeSound 0;
titleCut ["", "BLACK IN", 5];
[] spawn {sleep 0.001; showCinemaBorder FALSE};

_camera = "Camera" camCreate [2878.66,5792.88,6.05012];
_camera cameraEffect ["Internal", "Back"];
_alvo = position player;
_texto = "";


while {TRUE} do {
	
	//titleCut ["", "BLACK IN", 5];
	playMusic ["viruz_track_intro_1", 16];
	addMusicEventHandler ["MusicStop", {[] spawn {sleep 10; playMusic "viruz_track_intro_1"}}];
	
	_textmensage = floor(random 5);
	switch (_textmensage) do {
		case 0: { _texto = "<t color='#ff0000' size = '.8'>Tudo tem o seu tempo determinado, e há tempo para todo o propósito debaixo do céu.</t><br /><t color='#FFFF00' size = '.4'>(Eclesiastes 3:1)</t>"; };
        case 1: { _texto = "<t color='#ff0000' size = '.8'>E se alguém não foi achado no Livro da Vida, esse foi lançado no lago de fogo e enxofre.</t><br /><t color='#FFFF00' size = '.4'>(Apocalipse 20:15)</t>"; };
        case 2: { _texto = "<t color='#ff0000' size = '.8'>Seja educado com um homem armado. É uma questão de bom senso!</t><br /><t color='#FFFF00' size = '.4'>(The Walking Dead)</t>"; };
        case 3: { _texto = "<t color='#ff0000' size = '.8'>Primeiro procuramos uma pessoa. Após 72 horas, procuramos um corpo...</t><br /><t color='#FFFF00' size = '.4'>(The Walking Dead)</t>"; };
		case 4: { _texto = "<t color='#ff0000' size = '.8'>Eles foram o milagre que fez com que eu desacreditasse em milagres!</t><br /><t color='#FFFF00' size = '.4'>(The Walking Dead)</t>"; };
	    case 5: { _texto = "<t color='#ff0000' size = '.8'>Temei a Deus e dai-lhe glória, pois é vinda a hora de seu juízo.</t><br /><t color='#FFFF00' size = '.4'>(Apocalipse 14:7)</t>"; };
	};


//<img size='10' color='#ff0000' image='z\addons\viruz_code\gui\viruz_logo_ca.paa'/><br />
[_texto,-1,-1,20,1,0,789] spawn BIS_fnc_dynamicText;
	
	_camera camPrepareTarget [2878.66,5792.88,6.05012];
	_camera camPreparePos [3900.66,2600.88,100.05012];
	_camera camPrepareFOV 0.561;
	_camera camCommitPrepared 0;
	
	_camera camPrepareTarget [2878.66,5792.88,6.05012];
	_camera camPreparePos [2878.66,5300.88,80.05012];
	_camera camPrepareFOV 0.561;
	_camera camCommitPrepared 40;
	
	waitUntil {camCommitted _camera};
	["<t color='#ff0000' size = '.8'>60 DIAS APÓS A PRIMEIRA CONTAMINAÇÃO.</t>",-1,-1,20,1,0,789] spawn BIS_fnc_dynamicText;
	_camera camPrepareTarget [2878.66,5792.88,6.05012];
	_camera camPreparePos [2878.66,5767.88,12.05012];
	_camera camPrepareFOV 0.561;
	_camera camCommitPrepared 12;
	
	waitUntil {camCommitted _camera};
	
	sleep 120;
	
};
