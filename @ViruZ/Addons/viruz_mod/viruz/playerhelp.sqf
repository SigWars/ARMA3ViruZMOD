/*
ViruZ Mod for Arma 3
MaintainBuilds by items count
Autor: SigWar

*/

_modname = "<br /><t align='center'><t shadow= 1 shadowColor='#000000'><t size='1.2'><t color='#ff0000'>ViruzMod BETA</t><br />";
_helpmsg = " 
<br /> 
<t align='center'><t size='1.2'><t shadow= 1 shadowColor='#000000'>HotKeys</t><br /> 
<br /> 
<t align='left'><t size='1.2'><t shadow= 1 shadowColor='#0000ff'>""U"" </t><t align='left'><t shadow= 1 shadowColor='#000000'><t size='1'>Group Menu</t><br />
<t align='left'><t size='1.2'><t shadow= 1 shadowColor='#0000ff'>""H"" </t><t align='left'><t shadow= 1 shadowColor='#000000'><t size='1'>Holster Weaapon</t><br />
<t align='left'><t size='1.2'><t shadow= 1 shadowColor='#0000ff'>""F4"" </t><t align='left'><t shadow= 1 shadowColor='#000000'><t size='1'>On/Off Earplugs</t><br />
<t align='left'><t size='1.2'><t shadow= 1 shadowColor='#0000ff'>""INSERT"" </t><t align='left'><t shadow= 1 shadowColor='#000000'><t size='1'>Auto Run</t><br /> 
<t align='left'><t size='1.2'><t shadow= 1 shadowColor='#0000ff'>""CTRL+B"" </t><t align='left'><t shadow= 1 shadowColor='#000000'><t size='1'>Build System</t><br /> 
<t align='left'><t size='1.2'><t shadow= 1 shadowColor='#0000ff'>""CTRL+R"" </t><t align='left'><t shadow= 1 shadowColor='#000000'><t size='1'>Mag Repack</t><br /> 
<t align='left'><t size='1.2'><t shadow= 1 shadowColor='#0000ff'>""WINDOWS"" </t><t align='left'><t shadow= 1 shadowColor='#000000'><t size='1'>Show/Hide Nametags</t><br />
<t align='center'><t shadow= 1 shadowColor='#000000'><t size='1.4'>""Enhanced Movement""</t><br /><t align='left'><t shadow= 1 shadowColor='#000000'><t size='1'>Set the key to jump walls/Obstacles by pressing 'ESC' and going to Enhanced Movement on the lower right side of the screen</t><br /> 
<br /> 
<t align='center'><t size='1.2'><t shadow= 1 shadowColor='#0000ff'>Have Fun!</t> 
<br /> 
<t align='center'><img size='6' shadow = 0 image='\z\addons\viruz_mod\viruz\helpmenu\logo.paa'/></t>"; 
 
hint parseText format ["<t align='center'>Welcome to %2 %3</t><br />%1",_helpmsg,_modname, name player];