/*
ViruZ Mod for Arma 3
MaintainBuilds by items count
Autor: SigWar

*/

_helpmsg = "
<t align='center'><t shadow= 1 shadowColor='#000000'><t size='1.2'><t color='#ff0000'>ViruzMod BETA</t>
<br />
<br />
<t align='center'><t size='1.2'><t shadow= 1 shadowColor='#000000'>HotKeys</t><br />
<br />
<t align='left'><img size='2' shadow = 0 image='\z\addons\viruz_mod\viruz\helpmenu\windows.paa'/></t><t align='left'><t size='1'><t shadow= 1 shadowColor='#000000'> Show/Hide NameTags</t><br />
<t align='left'><img size='2' shadow = 0 image='\z\addons\viruz_mod\viruz\helpmenu\f4.paa'/></t><t align='left'><t size='1'><t shadow= 1 shadowColor='#000000'> On/Off Earplugs</t><br />
<t align='left'><img size='2' shadow = 0 image='\z\addons\viruz_mod\viruz\helpmenu\h.paa'/></t><t align='left'><t size='1'><t shadow= 1 shadowColor='#000000'> Holster Weaapon</t><br />
<t align='left'><img size='2' shadow = 0 image='\z\addons\viruz_mod\viruz\helpmenu\insert.paa'/></t><t align='left'><t size='1'><t shadow= 1 shadowColor='#000000'> Auto RUN</t><br />
<t align='left'><img size='2' shadow = 0 image='\z\addons\viruz_mod\viruz\helpmenu\ctrlb.paa'/></t><t align='left'><t size='1'><t shadow= 1 shadowColor='#000000'> Build System</t><br />
<t align='left'><img size='2' shadow = 0 image='\z\addons\viruz_mod\viruz\helpmenu\u.paa'/></t><t align='left'><t size='1'><t shadow= 1 shadowColor='#000000'> Group Menu</t><br />
<t align='left'><img size='2' shadow = 0 image='\z\addons\viruz_mod\viruz\helpmenu\custom17.paa'/></t><t align='left'><t size='0.7'><t shadow= 1 shadowColor='#000000'> Switch betwen primary and secundary weapon while move</t><br />
<t align='left'><img size='2' shadow = 0 image='\z\addons\viruz_mod\viruz\helpmenu\custom18.paa'/></t><t align='left'><t size='0.7'><t shadow= 1 shadowColor='#000000'> Switch betwen primary/secondary to Axe while move</t><br />
<br />
<t align='center'><t size='1.2'><t shadow= 1 shadowColor='#0000ff'>Have Fun!</t>
<br />
<t align='center'><img size='6' shadow = 0 image='\z\addons\viruz_mod\viruz\helpmenu\logo.paa'/></t>";

hint parseText format ["<t align='center'>Welcome %2</t><br />%1",_helpmsg, name player];