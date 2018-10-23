function fatigue=calcFatigue(logs,config)
%Calculate fatigue
%Modified by: Mikael Svenstrup
wt=config.wt;




if(isa(logs,'Simulink.SimulationData.Dataset'))
    %Dataextraction using Dataset
    mdata{1}=logs.getElement('M_shaft').Values;
    mdata{2}=logs.getElement('M_tow').Values;
    wdata=logs.getElement('V_rot').Values.Data(:,wt);
    wtime=logs.getElement('V_rot').Values.Time;
else
    %Old dataextraction using ModelDataLogs
    mdata{1}=logs.Turbines.M_shaft;
    mdata{2}=logs.Turbines.M_tow;
    wdata=logs.V_rot.Data(:,wt);
    wtime=logs.V_rot.Time;
end



time=mdata{1}.Time;
Ts=max(time(2:end)-time(1:end-1));
equitime=0:Ts:time(end);
wind=interp1(wtime,wdata,equitime);

for i=1:length(mdata)
    m(:,i)=interp1(mdata{i}.time,mdata{i}.data(:,wt),equitime);
end
data=m;


units={'Nm','Nm'};
names={'Shaft Torsion Moment','Tower Bending Moment'};

%Debug
%global data wind;



fatigue=doMCrunch(equitime,wind,data,names,units,config);
%mcrunchdirect(equitime,wind,data,names,units);
end