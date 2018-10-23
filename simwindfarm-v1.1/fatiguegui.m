function fatigue=fatiguegui(log)

config=fatChoice();

if(isempty(config))
    %If it was canceled do nothing
    return 
end
%Get downidx upidx sampels and rtfactor
options.Resize='off';
options.WindowStyle='normal';
options.Interpreter='none';
qs={'Turbine #','Racetrack ratio','Unbinned Cycle Multiplier','Rainflow period [s]','Average Rayleigh wind speed [m/s]','Minimum Rayleigh wind speed [m/s]','Rayleigh delta wind speed [m/s]'};
answer={'1','0.05','.5','300','10','5','.5'};
fatparm=inputdlg(qs,'Fatigue Computation',1,answer,options);
config.wt=str2double(fatparm{1});
config.FiltRatio=str2double(fatparm{2});
config.UCMult=str2double(fatparm{3});
config.RF_Per=str2double(fatparm{4});
config.RayAverWS=str2double(fatparm{5});
config.WSmin=str2double(fatparm{6});
config.WSdel=str2double(fatparm{7});


fatigue=calcFatigue(log,config);


end