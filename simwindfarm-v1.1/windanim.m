function movie=windanim(model,logs,config)
%Animates the wind field including wake effects
%Currently suboptimal code as the design was for 1 frame. Many computations
%are repeated
%
%Author: Jacob D. Grunnet 
%Modified by: Mikael Svenstrup

cfg.movie.go=false;

if(nargin == 3)
    if(~isempty(config))
        cfg=config;
    end
end

if(cfg.movie.go)
    aviobj=avifile(cfg.movie.name,'fps',cfg.movie.fps,'compression',cfg.movie.compress);
end


%Load windfield
wind=get_param([model '/Wind Field/Ambient Field'],'Userdata');

xgrids=ceil(wind.grid.xsize/wind.grid.size);
ygrids=ceil(wind.grid.ysize/wind.grid.size);

%Get CT history
if(isa(logs,'Simulink.SimulationData.Dataset'))
    %New style Dataset
    CT=logs.getElement('CT').Values;
else
    %Old style ModelDataLogs
    CT=logs.CT;
end
N=size(CT.Data,2);

% Find turbine parameters
for i=1:N   
    wakedat{i}=get_param([model '/Wind Field/Wake' num2str(i)],'Userdata');
end
px=wakedat{1}.farm.x;

[X,Y]=meshgrid((0:xgrids)*wind.grid.size,(0:ygrids-1)*wind.grid.size);
fig=figure;
h=pcolor(X,Y,zeros(size(X)));
shading flat
%Add a button for stopping the simulation
han_button_stop = uicontrol('Style','pushbutton','String','Stop Simulation','Position',[150 10 100 20]);
set(han_button_stop,'Callback',{@push_button_stop_simulation_callback,'button pushed'})
% Add a button for pausing the simulation
han_button_pause = uicontrol('Style','pushbutton','String','Pause Simulation','Position',[350 10 100 20]);
set(han_button_pause,'Callback',{@push_button_pause_simulation_callback,'button pushed'})


%find maximum wind
wmax=max(max(wind.Ux));
wmin=min(min(wind.Ux));
caxis([wmin*.4 wmax]);
numframes=length(CT.Time);


for step=1:numframes-1
    timestep=step;
    gmin=timestep;
    gmax=timestep+xgrids;
    awx=wind.Ux(:,gmin:gmax);
    

    %Calculate a(g) at time timestep and centerline
    for j=1:N
        p=wakedat{j};
        p.grid.xgrids=xgrids;
        a{j}=deficit(CT.Data(:,j),p,timestep);
        wc{j}=wakecenter(wind.Uy,p,timestep);
    end

    av=ones(xgrids+1,ygrids);

    %Wake merging
    for j=1:N
        meand=wakedat{j}.wt.meand.r;
        g=ceil(px(j)/p.grid.size);
        for i=1:xgrids-g
            %compute the grid number for low meandering edge
            mn=floor((wc{j}(i)-meand(i))/wind.grid.size)+1;
            m_min=max(mn,1); 
            %compute the grid number for the high meandering edge
            mx=floor((wc{j}(i)+meand(i))/wind.grid.size)+1;
            m_max=min(mx,ceil(wind.grid.ysize/wind.grid.size));
            %Merge wakes
            for y=m_min:m_max
                av(i+1+g,y)=av(i+1+g,y)*a{j}(i+g);
            end
        end
    end

    %reverse wind field
    awxr=awx(:,end:-1:1);
    vx=awxr.*av';
    set(h,'CData',vx);
    title(['Wind Field at time ' num2str(ceil(CT.Time(timestep))) 's of ' num2str(CT.Time(end)) 's'])
    %pause(1/24);
    drawnow;
    if(cfg.movie.go)
       F=getframe(fig);
       aviobj=addframe(aviobj,F);
    end
    
    %Break if stop button is pressed
    while (strcmp(get(han_button_pause,'String'),'Resume') && strcmp(get(han_button_stop,'String'),'Stop Simulation'))
        % if we are en pause mode, just loop here
        pause(0.5)
    end

    if (strcmp(get(han_button_stop,'String'),'Stopped'))
        % if stop button has been pressed, the break out of the simulation loop
        break
    end

    
          
end


if(cfg.movie.go)
    aviobj=close(aviobj);
end


%% Function callback when pressing the stop simulation button
function push_button_stop_simulation_callback(hObject, eventdata, var1)
%Change the name of the button to stopping
set(hObject,'String','Stopped')


%% Function callback when pressing the pause button
function push_button_pause_simulation_callback(hObject, eventdata, var1)
%change the name of the button to pause or resume
if (strcmp(get(hObject,'String'),'Pause Simulation'))
    set(hObject,'String','Resume')
else
    set(hObject,'String','Pause Simulation')
end
