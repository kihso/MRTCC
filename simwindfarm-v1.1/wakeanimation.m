function wakeanimation(log,downidx,upidx,center,rad,meanrad,samples,Ts,rtfactor)
figure('color','white');

if(isa(log,'Simulink.SimulationData.Dataset'))
    %Wake from "Dataset"
    wakeCenter=log.getElement('wakecenter').Values;
    wakeDeficit=log.getElement('deficit').Values;
else
    %Old wake from ModelDataLogs
    wakeCenter=log.('Wind Field').wakecenter;
    wakeDeficit=log.('Wind Field').deficit;
end

%axis off

%Number of upwind turbines

n=length(upidx);

caxis([0 .8])
wc=ones(n,samples)*center;
a=ones(n,samples);

%Turbine graphics
line([-.1 -.1], [center-rad center+rad], 'color', [.4 .4 .8],'LineWidth',5);
patch([-0.2 -2 -2 -0.2],[center+5 center+5 center-10 center-10],[.5 .5 .5]);


%Add a button for stopping the simulation
han_button_stop = uicontrol('Style','pushbutton','String','Stop Simulation','Position',[150 10 100 20]);
set(han_button_stop,'Callback',{@push_button_stop_simulation_callback,'button pushed'})
% Add a button for pausing the simulation
han_button_pause = uicontrol('Style','pushbutton','String','Pause Simulation','Position',[350 10 100 20]);
set(han_button_pause,'Callback',{@push_button_pause_simulation_callback,'button pushed'})

hold on

%Time axis

time=[(Ts*(samples-1)):-Ts:.2 .2];
x=[time(1:end-1)' time(2:end)' time(2:end)' time(1:end-1)'];


%Make axes
maxwc=max(max(wakeCenter.Data(downidx,upidx,:)));
minwc=min(min(wakeCenter.Data(downidx,upidx,:)));
axis([-2 time(1)+1 minwc-max(meanrad) maxwc+max(meanrad)])

y=zeros(n,samples-1,samples-1);
ht=zeros(n);
colr=zeros(n,samples-1,samples-1);

for i=1:n
    %Calculate color as 1-deficit
    colr=[1-a(i,1:end-1)' 1-a(i,2:end)' 1-a(i,2:end)' 1-a(i,1:end-1)']';
    y= [(wc(i,1:end-1)+meanrad(i))' (wc(i,2:end)+meanrad(i))' (wc(i,2:end)-meanrad(i))'  (wc(i,1:end-1)-meanrad(i))'];
    %draw
    ht(i) = patch(x',y',colr);
    set(ht(i),'EdgeAlpha',0)
end

%T-axis
t=[.2 .0 .0 .2];
%sumbar
wcmax=reshape(wc(:,end),1,n)+meanrad;
wcmin=reshape(wc(:,end),1,n)-meanrad;
[wcm,idx]=sort([wcmax wcmin],'descend');
%up corner
uy=wcm(1);
%color
c=a(idx(1),end);
for j=2:2*n
   ly=wcm(j);
   yp=[uy uy ly ly];
   cb(j)=patch(t,yp,1-c);
   set(cb(j),'EdgeAlpha',0)
   uy=ly;
   %min or max
   if(idx(j)>n) %min
    c=c/a(idx(j)-n,end);
   else %max
    c=c*a(idx(j),end);
   end
end

for j = 1:length(wakeCenter.time)
   %update deficit and center
   a(:,2:end)=a(:,1:end-1);
   a(:,1)=wakeDeficit.data(downidx,upidx,j);
   wc(:,2:end)=wc(:,1:end-1); 
   wc(:,1)=wakeCenter.Data(downidx,upidx,j);
   
   for i=1:n
       colr=[1-a(i,1:end-1)' 1-a(i,2:end)' 1-a(i,2:end)' 1-a(i,1:end-1)']';
       y = [(wc(i,1:end-1)+meanrad(i))' (wc(i,2:end)+meanrad(i))' (wc(i,2:end)-meanrad(i))'  (wc(i,1:end-1)-meanrad(i))'];
       %Make vector for set
       colr=reshape(colr,(samples-1)*4,1);
       %Update data
       set(ht(i),'FaceVertexCData',colr);
       set(ht(i),'YData',y')
   end
   
    %sumbar
    wcmax=reshape(wc(:,end),1,n)+meanrad;
    wcmin=reshape(wc(:,end),1,n)-meanrad;
    [wcm,idx]=sort([wcmax wcmin],'descend');
    %up corner
    uy=wcm(1);
    %color
    c=a(idx(1),end);
    for i=2:2*n
       ly=wcm(i);
       yp=[uy uy ly ly];
       set(cb(i),'CData',1-c);
       set(cb(i),'YData',yp')
       uy=ly;
       %min or max
       if(idx(i)>n) %min
        c=c/a(idx(i)-n,end);
       else %max
        c=c*a(idx(i),end);
       end
    end

   
   pause(Ts/rtfactor);
   %refresh graph
   drawnow   
   title(['Wake at time ' num2str(ceil(wakeCenter.time(j))) 's of ' num2str(wakeCenter.time(end)) 's'])

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
