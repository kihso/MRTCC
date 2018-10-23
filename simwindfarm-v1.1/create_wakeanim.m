function create_wakeanim(sys,logsout)

%Get downidx upidx sampels and rtfactor
options.Resie='off';
options.WindowStyle='normal';
options.Interpreter='none';
qs={'Up stream turbine number', ...
            'Down stream turbine number',... 
            'Number of samples shown',...
            'Animation speed-up factor'};
answer={'[1,2]','3','10','5'};
animparm=inputdlg(qs,'Wind Animation',1,answer,options);
upidx=str2num(animparm{1});
downidx=str2double(animparm{2});
samples=str2double(animparm{3});
rtfactor=str2double(animparm{4});

  
%Get turbine parameters
down=get_param([sys '/Wind Field/Wind Speed' num2str(downidx)],'UserData');

                                                                       
wakeanimation(logsout,downidx,upidx,down.wt.y,down.wt.rotor.r,down.wt.exprad(upidx),samples,down.ts,rtfactor)
end