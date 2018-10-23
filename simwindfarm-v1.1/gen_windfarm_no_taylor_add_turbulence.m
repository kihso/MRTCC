function mainsys=gen_windfarm_no_taylor_add_turbulence(mdlfile,path,farm,wind)
% MDLCREATE - creates wind farm model based on programmatic input
%
% Copyright 2009 - Aalborg University
% Author Jacob Grunnet - grunnet@es.aau.dk
% Modified Martin Kragelund mkr@es.aau.dk
%
% Todo: 
% 

%Extract grid information from wind struct
grid=wind.grid;
%Extract turbine grid positions
wind.xgrids=floor(farm.pos(1,:)/grid.size)+1;

%Remove mdlfile extension and stoe in mdlname
mdlname=mdlfile(1:end-4);

%Find the number of turbines
Nstr=int2str(length(farm.turbines));

%Load the aeolus library
load_system('libaeolus');
%Close the model if it is already open
bdclose(mdlname);
%Create the new model based on the template
mainsys=new_system(mdlname,'model','libaeolus/Farm Template - No Taylor Added Turbulence');
%Save and break all links in order to modify the new library
save_system(mainsys,[path mdlfile],'BreakUserLinks',true)

%Setup muxes according to number of turbines
set_param([mdlname '/Turbines/Pdemanddemux'],'Outputs',Nstr);
set_param([mdlname '/Turbines/Vrotdemux'],'Outputs',Nstr);
set_param([mdlname '/Turbines/Vnacdemux'],'Outputs',Nstr);
set_param([mdlname '/Turbines/Vnacmux'],'Inputs',Nstr);
set_param([mdlname '/Turbines/Pmux'],'Inputs',Nstr);
set_param([mdlname '/Turbines/wgenmux'],'Inputs',Nstr);
set_param([mdlname '/Turbines/auxmux'],'Inputs',Nstr);
set_param([mdlname '/Turbines/pitchmux'],'Inputs',Nstr);
set_param([mdlname '/Turbines/CTmux'],'Inputs',Nstr);
set_param([mdlname '/Turbines/mshaftmux'],'Inputs',Nstr);
set_param([mdlname '/Turbines/mtowmux'],'Inputs',Nstr);

%Set toolbox vesion
%Fake version atm
create_windfarm_paths = which('create_windfarm','-all');

if(isunix)
    create_windfarm_paths = create_windfarm_paths{end}(2:(end-18));
elseif(ispc)
    create_windfarm_paths = create_windfarm_paths{end}(4:(end-18));
end
try
    v=ver(create_windfarm_paths);
    p.version=v.Version;
catch me
    disp('Error in getting SimWindFarm Toolbox version - setting default version 0.0.0')
    p.version = '0.0.0';
end
set_param([mdlname '/Turbines'],'UserData',p);
set_param([mdlname '/Turbines'],'UserDataPersistent','on');



%% Add turbines
%Variables for block positioning
y=0;
x=150;
%Initial x and y
tl1x=50;
tl1y=50;
ptotal=0;
%Load turbine library
load_system('libturbines');


for i=1:length(farm.turbines)
    %Add a turbine block
    wt(i).block=add_block(['libturbines/' farm.turbines{i}],[mdlname '/Turbines/WT' int2str(i)]);
    
    %Extract turbine data
    partmp=get_param(wt(i).block,'UserData');
    %Save the public data
    wtpar(i)=partmp.public;
    
    %Set block position
    wtp=get_param(wt(i).block,'Position');
    set_param(wt(i).block,'Position',[tl1x+x tl1y+y,wtp(3)+x-wtp(1) wtp(4)+y-wtp(2)]);
       
    %Increase y position
    y=y+175;

    %Input - connect muxes
    add_line([mdlname '/Turbines'],['Vrotdemux/' int2str(i)],['WT' int2str(i) '/2'],'Autorouting','on')
    add_line([mdlname '/Turbines'],['Vnacdemux/' int2str(i)],['WT' int2str(i) '/3'],'Autorouting','on')
    add_line([mdlname '/Turbines'],['Pdemanddemux/' int2str(i)],['WT' int2str(i) '/1'],'Autorouting','on')
    
    
    %Output - connect muxes
    add_line([mdlname '/Turbines'],['WT' int2str(i) '/1'],['Pmux/' int2str(i)],'Autorouting','on')
    add_line([mdlname '/Turbines'],['WT' int2str(i) '/2'],['CTmux/' int2str(i)],'Autorouting','on')
    add_line([mdlname '/Turbines'],['WT' int2str(i) '/3'],['wgenmux/' int2str(i)],'Autorouting','on')
    add_line([mdlname '/Turbines'],['WT' int2str(i) '/4'],['Vnacmux/' int2str(i)],'Autorouting','on')
    add_line([mdlname '/Turbines'],['WT' int2str(i) '/5'],['pitchmux/' int2str(i)],'Autorouting','on')
    add_line([mdlname '/Turbines'],['WT' int2str(i) '/6'],['mshaftmux/' int2str(i)],'Autorouting','on')
    add_line([mdlname '/Turbines'],['WT' int2str(i) '/7'],['mtowmux/' int2str(i)],'Autorouting','on')
    add_line([mdlname '/Turbines'],['WT' int2str(i) '/8'],['auxmux/' int2str(i)],'Autorouting','on')
    
    
    %Farm controller parameters
    pfarm.radius(i)=wtpar(i).rotor.radius;
    pfarm.rated(i)=wtpar(i).rated;
    pfarm.Cp(i)=0.45; %Not currently available in turbines
    ptotal=ptotal+wtpar(i).rated;
end

%%Setup farm control block
pfarm.rho=1.2231;
pfarm.N=length(farm.turbines);

set_param([mdlname '/Farm Control'],'UserData',pfarm);
set_param([mdlname '/Farm Control'],'UserDataPersistent','on');

%Setup network operator block
set_param([mdlname '/Network Operator'],'pref',num2str(ptotal*0.8));
set_param([mdlname '/Network Operator'],'maxp',num2str(ptotal));
set_param([mdlname '/Network Operator'],'minp',num2str(ptotal/5));

%Setup network operator block
set_param([mdlname '/Grid'],'fgain',num2str(ptotal*1e-16));


%Setup Power load block
set_param([mdlname '/Network Load'],'maxp',num2str(ptotal));

%% Prepare wake and wind blocks

%Calculate common parameters
farmx=farm.pos(1,:);
farmy=farm.pos(2,:);

%Calculate static wake expansion
 for i=1:length(farm.turbines)
     %Meandering radius at all grid spacings down wind
     meand(i,:)=sqrt((wtpar(i).rotor.radius)^2+(0:grid.size:grid.xsize).*wtpar(i).rotor.radius/2);
 end

%Extract wake expansion at turbines
for i=1:length(farm.turbines)
    for j=1:length(farm.turbines)
        %Length from j to i
        gdelta=max(min(farm.pos(1,i)-farm.pos(1,j),grid.xsize),0);
        
        %For downwind turbines
        if (gdelta>0)
            %in grid points
            gdeltag=floor(gdelta/grid.size);
            %Calculate wake delays
            delays(j,i)=gdeltag;
        else %Upwind turbines
            delays(j,i)=0;
        end
    end
end

%Setup wind field block
%Name of block
wfname=[mdlname '/Wind Field'];

%Add ambient data
set_param([wfname '/Ambient Lateral Field'],'UserData',wind);
set_param([wfname '/Ambient Lateral Field'],'UserDataPersistent','on');

%Add farmlayout and windfield parameters to Windfield block
temp_p.farm.x = farmx;
temp_p.farm.y = farmy;
temp_p.rotor.r = pfarm.radius;

U0 = wind.Umean;
temp_p.U0 = U0; %mean windspeed
Key = 'Turbulence:';
Key_index = strfind(wind.desc,Key);
Key_index=Key_index{1};

desc_str = char(wind.desc);
sigma0 = sscanf(desc_str(Key_index+length(Key):end),'%g',1);
temp_p.sigma0 = sigma0;%wind speed variance

set_param(wfname,'UserData',temp_p)
set_param(wfname,'UserDataPersistent','on');

%Setup concatenators
%Set output logging
set_param([wfname '/wdconcat'],'NumInputs',Nstr);
h=get_param([wfname '/wdconcat'],'PortHandles');
set_param(h.Outport(1),'DataLogging','on');
set_param(h.Outport(1),'DataLoggingName','wakediameter');
set_param(h.Outport(1),'DataLoggingNameMode','Custom');
    
set_param([wfname '/wcconcat'],'NumInputs',Nstr);
h=get_param([wfname '/wcconcat'],'PortHandles');
set_param(h.Outport(1),'DataLogging','on');
set_param(h.Outport(1),'DataLoggingName','wakecenter');
set_param(h.Outport(1),'DataLoggingNameMode','Custom');

set_param([wfname '/ctconcat'],'NumInputs',Nstr);
h=get_param([wfname '/ctconcat'],'PortHandles');
set_param(h.Outport(1),'DataLogging','on');
set_param(h.Outport(1),'DataLoggingName','ct_down_wind');
set_param(h.Outport(1),'DataLoggingNameMode','Custom');

h=get_param([wfname '/Deficit and turbulence'],'PortHandles');
set_param(h.Outport(1),'DataLogging','on');
set_param(h.Outport(1),'DataLoggingName','deficit');
set_param(h.Outport(1),'DataLoggingNameMode','Custom');
set_param(h.Outport(2),'DataLogging','on');
set_param(h.Outport(2),'DataLoggingName','turb');
set_param(h.Outport(2),'DataLoggingNameMode','Custom');


%set_param([wfname '/defconcat'],'Inputs',Nstr);
%h=get_param([wfname '/defconcat'],'PortHandles');
%set_param(h.Outport(1),'DataLogging','on');
%set_param(h.Outport(1),'DataLoggingName','deficit');
%set_param(h.Outport(1),'DataLoggingNameMode','Custom');


%Setup muxes
set_param([wfname '/CTdemux'],'Outputs',Nstr);
set_param([wfname '/Vrotmux'],'Inputs',Nstr);
set_param([wfname '/Vnacmux'],'Inputs',Nstr);

%Setup sample time of rate transition blocks
set_param([wfname '/CTrate'],'OutPortSampleTime',num2str(wind.Ts));

%% Add wake and wind speed blocks
y=0;
x=150;
%Load wind library
load_system('libwind');
for i=1:length(farm.turbines)
    %Add wake block
    wtwk(i).block=add_block(['libwind/Wake effects - No Taylor' ],[mdlname '/Wind Field/Wake' int2str(i)]);
    
    %Set block position
    wkp=get_param(wtwk(i).block,'Position');
    set_param(wtwk(i).block,'Position',[wkp(1)+x wkp(2)+y,wkp(3)+x wkp(4)+y]);
    
    %Unlink block for modification
    set_param(wtwk(i).block,'LinkStatus','none');
    
    %Add wind speed block
    wtsp(i).block=add_block(['libwind/Wind speed - No Taylor Added Turbulence'],[mdlname '/Wind Field/Wind Speed' int2str(i)]);
    %Set block position
    
    wsp=get_param(wtsp(i).block,'Position');
    set_param(wtsp(i).block,'Position',[wsp(1)+x+300 wsp(2)+y,wsp(3)+x+300 wsp(4)+y]);
    %Unlink block for modification
    set_param(wtsp(i).block,'LinkStatus','none');
    
        
    %Add to y position
    y=y+175;
    
    %Input wake
    add_line(wfname,['CTdemux/' int2str(i)],['Wake' int2str(i) '/2'],'Autorouting','on')
    add_line(wfname,'Ambient Lateral Field/1',['Wake' int2str(i) '/1'],'Autorouting','on')
    
    %Input wind speed
    add_line(wfname,'Deficit and turbulence/1',['Wind Speed' int2str(i) '/1'],'Autorouting','on') %deficit
    add_line(wfname,'Deficit and turbulence/2',['Wind Speed' int2str(i) '/2'],'Autorouting','on') %added turbulence
    %add_line(wfname,'wdconcat/1',['Wind Speed' int2str(i) '/2'],'Autorouting','on')
    %add_line(wfname,'wcconcat/1',['Wind Speed' int2str(i) '/1'],'Autorouting','on')

    %add_line(wfname,'ctconcat/1',['Wind Speed' int2str(i) '/4'],'Autorouting','on')
    %add_line(wfname,'wdconcat/1',['Wind Speed' int2str(i) '/3'],'Autorouting','on')
    %add_line(wfname,'wcconcat/1',['Wind Speed' int2str(i) '/2'],'Autorouting','on')
    %add_line(wfname,'Ambient Lateral Field/1',['Wind Speed' int2str(i) '/1'],'Autorouting','on')
    
    
    %Output wake
    add_line(wfname,['Wake' int2str(i) '/1'],['wcconcat/' int2str(i)],'Autorouting','on')
    add_line(wfname,['Wake' int2str(i) '/2'],['wdconcat/' int2str(i)],'Autorouting','on')
    add_line(wfname,['Wake' int2str(i) '/3'],['ctconcat/' int2str(i)],'Autorouting','on')
    
    %Output wind speed
    add_line(wfname,['Wind Speed' int2str(i) '/1'],['Vrotmux/' int2str(i)],'Autorouting','on')
    add_line(wfname,['Wind Speed' int2str(i) '/2'],['Vnacmux/' int2str(i)],'Autorouting','on')
    %add_line(wfname,['Wind Speed' int2str(i) '/3'],['defconcat/' int2str(i)],'Autorouting','on')
    
    %Configure wake
    clear wp;
    
    wp.farm.x=farmx;
    wp.farm.y=farmy;
    wp.grid=grid;
    wp.wt.x=farm.pos(1,i);
    wp.wt.y=farm.pos(2,i);
    wp.wt.rotor.r=wtpar(i).rotor.radius;
    wp.wt.num=i;
    %wp.wt.exprad=exprad{i}.r;
    wp.wt.meand.r=meand(i,:);
    wp.alpha = 0.5; %approximated by 10*alpha_noj - if changed 'libwind/Wake effects - No Taylor/Wake center and diameter' might need modification
    wp.k = 2;
    wp.ts=wind.Ts;
    
    %Set wake parameters
    set_param(wtwk(i).block,'UserData',wp);
    set_param(wtwk(i).block,'UserDataPersistent','on');
    
    wp.wind_grid = wind.ambient_wind.gridN;
    wp.wind = wind.ambient_wind.wind{i};
    
    wp.U0 = U0;
    wp.sigma0 = sigma0;
    
    %Set wind speed parameters
    set_param(wtsp(i).block,'UserData',wp);
    set_param(wtsp(i).block,'UserDataPersistent','on');
    

    % Insert delays (wind travelling speed) 
    %Name of wake block
    wkstr=[wfname '/Wake' int2str(i)];
    %Setup muxes
    set_param([wkstr '/wddemux'],'Outputs',Nstr);
    set_param([wkstr '/wcdemux'],'Outputs',Nstr);
%    set_param([wkstr '/ctdemux'],'Outputs',Nstr);

    set_param([wkstr '/wdmux'],'Inputs',Nstr);
    set_param([wkstr '/wcmux'],'Inputs',Nstr);
    set_param([wkstr '/ctmux'],'Inputs',Nstr);
    
    %Load simulink to get delay block
    load_system('simulink')
    for j=1:length(delays(i,:))
        %If downwind
        if(delays(i,j)>0)
            %CT delay block
            ctd=add_block('simulink/Discrete/Integer Delay',[wfname '/Wake' int2str(i) '/ctDelay' int2str(j)], ...
                        'MakeNameUnique','on' ,...
                          'samptime',num2str(wind.Ts), ...
                          'NumDelays',int2str(delays(i,j)), ...
                          'vinit','0');
%                          'vinit','1');

                      
            %Wake center delay block          
            wcd=add_block('simulink/Discrete/Integer Delay',[wfname '/Wake' int2str(i) '/wcDelay' int2str(j)], ...
                          'MakeNameUnique','on' ,...
                          'samptime',num2str(wind.Ts), ...
                          'NumDelays',int2str(delays(i,j)), ...
                          'vinit','0');
%                          'vinit',int2str(farm.pos(2,i)));

            %Wake diameter delay block          
            wdd=add_block('simulink/Discrete/Integer Delay',[wfname '/Wake' int2str(i) '/wdDelay' int2str(j)], ...
                          'MakeNameUnique','on' ,...
                          'samptime',num2str(wind.Ts), ...
                          'NumDelays',int2str(delays(i,j)), ...
                          'vinit','0');
 %                         'vinit',int2str(farm.pos(2,i)));
          
            %Connect to muxes
            add_line([wfname '/Wake' int2str(i)],['wddemux/' int2str(j)],['wdDelay' int2str(j) '/1'],'Autorouting','on')
            add_line([wfname '/Wake' int2str(i)],['wdDelay' int2str(j) '/1'],['wdmux/' int2str(j)],'Autorouting','on')
            add_line([wfname '/Wake' int2str(i)],['wcdemux/' int2str(j)],['wcDelay' int2str(j) '/1'],'Autorouting','on')
            add_line([wfname '/Wake' int2str(i)],['wcDelay' int2str(j) '/1'],['wcmux/' int2str(j)],'Autorouting','on')
            add_line([wfname '/Wake' int2str(i)],['CT/1'],['ctDelay' int2str(j) '/1'],'Autorouting','on')
            add_line([wfname '/Wake' int2str(i)],['ctDelay' int2str(j) '/1'],['ctmux/' int2str(j)],'Autorouting','on')
            
        else
            %Hackish - avoids algebraic loop. No delay - Connect constant output 1 to muxes
            add_block('simulink/Sinks/Terminator',[wfname '/Wake' int2str(i) '/TermWdde' int2str(j)], ...
                        'MakeNameUnique','on');
            add_block('simulink/Sinks/Terminator',[wfname '/Wake' int2str(i) '/TermWcde' int2str(j)], ...
                        'MakeNameUnique','on');
            %add_block('simulink/Sinks/Terminator',[wfname '/Wake' int2str(i) '/TermCtde' int2str(j)], ...
            %            'MakeNameUnique','on');

            add_line([wfname '/Wake' int2str(i)],['wddemux/' int2str(j)],['TermWdde' int2str(j) '/1'],'Autorouting','on')
            add_line([wfname '/Wake' int2str(i)],['wcdemux/' int2str(j)],['TermWcde' int2str(j) '/1'],'Autorouting','on') 
            %add_line([wfname '/Wake' int2str(i)],['ctdemux/' int2str(j)],['TermCtde' int2str(j) '/1'],'Autorouting','on') 
 
            %%%%% ARE THESE CONNECTIONS CORRECT???????
            add_line([wfname '/Wake' int2str(i)],'Nodelay/1',['wdmux/' int2str(j)],'Autorouting','on')
            add_line([wfname '/Wake' int2str(i)],'Nodelay/1',['wcmux/' int2str(j)],'Autorouting','on')
            add_line([wfname '/Wake' int2str(i)],'Nodelay/1',['ctmux/' int2str(j)],'Autorouting','on')
        end
    end
    
end
% if(isunix)
     add_block('simulink/Sources/Clock',[mdlname '/Clock']);
     add_block('simulink/Sinks/Display',[mdlname '/Display']);
     set_param([mdlname '/Display'],'Position',[230 545 370 575]);
     set_param([mdlname '/Clock'],'Position',[40 550 60 570]);
     add_line(mdlname,['Clock/1'],['Display/1'],'Autorouting','on');
     set_param([mdlname '/Display'],'format','long');
     %set_param([mdlname '/Display'],'position',get_param([mdlname '/Display'],'position')+[0 0 45 0]);
% end

%Add display when generated model is opened in unix
%Is not included yet as it needs debugging/validation
%set_param(mainsys,'PostLoadFcn',sprintf('if(isunix)\n\tmdlname = gcs;\n\tadd_block(''simulink/Sources/Clock'',[mdlname ''/Clock'']);\n\tadd_block(''simulink/Sinks/Display'',[mdlname ''/Display'']);\n\tset_param([mdlname ''/Display''],''Position'',[230 545 370 575]);\n\tset_param([mdlname ''/Clock''],''Position'',[40 550 60 570]);\n\tadd_line(mdlname,[''Clock/1''],[''Display/1''],''Autorouting'',''on'');\n\tset_param([mdlname ''/Display''],''format'',''long'');\nend'));
%set_param(mainsys,'CloseFcn',sprintf('if(isunix)\n\tmdlname = gcs;\n\tdelete_line(mdlname,[''Clock/1''],[''Display/1'']);\n\tdelete_block([mdlname ''/Clock'']);\n\tdelete_block([mdlname ''/Display'']);\nend'))

% %Setting Default parameters in simulation configuration

if(isfield(wind,'SimTime'))
    set_param(mainsys,'StopTime',num2str(wind.SimTime));
else
    set_param(mainsys,'StopTime',num2str((size(wind.Ux,2)-round(wind.grid.xsize/wind.grid.size))*wind.Ts));
end
set_param(mainsys,'InlineParams','on');
set_param(mainsys,'EnhancedBackFolding','on')
set_param(mainsys,'SimulationMode','accelerator')



%Save model
save_system(mainsys);

bdclose(mdlname);

end
