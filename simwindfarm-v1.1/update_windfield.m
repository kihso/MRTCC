function update_windfield()
[wfile,wpath,wfidx]=uigetfile('*.mat','Select a Wind Data File');           
if isequal(wfile,0) || isequal(wpath,0)                                     
   return                                                                   
end                                                                         
%Loads wind profile data                                                    
l=load([wpath wfile]);                                                      
                                                                            
p=get_param([gcb '/Ambient Field'],'UserData');                             
                                                                            
if(p.grid.size~=l.wind.grid.size)                                      
   errordlg('Cannot update wind field. The grid sizes needs to be identical.','Wind Field Update')
else                                                                        
   set_param([gcb '/Ambient Field'],'UserData',l.wind);                     
end          
end