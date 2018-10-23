function wind=create_windfield(windData)
%wind = CREATE_WINDFIELD()
% creates a windfield for a model using taylors frozen hypothesis
% To create a new field with for your current farm, use or modify the farm data when calling
% the function:
%wind = CREATE_WINDFIELD(wind.input)
% To obtain your current wind field; click once on the "Wind Field" block
% in the simulink model and:
% wind=get_param([gcb '/Ambient Field'],'UserData');
%
% The default length and width of the wind field is 1000m. But if you
% provide the turbine positions in a farm struct. The wind field will be
% adjusted accordingly (farm.pos = [x1 x2...xn ; y1 y2 ... yn]):
%wind = CREATE_WINDFIELD(farmPos)


%Default length and width for wind field
Lx = 1000;
Ly = 1000;


if nargin==1
    if(isfield(windData,'Ua'))
        %If just information from old wind field is provided
        U0 =    windData.Ua;
        Ti =    windData.Ti;
        d =     windData.d;
        Lx =    windData.Lx;
        Ly =    windData.Ly;
        SimTime =   windData.SimTime;
        desc =   windData.desc;
    else %It must be farm coordinates either in a struct or as a matrix
        if(isfield(windData,'pos'))
            pos = windData.pos;
        else
            pos = windData;
        end
        Lx = max(pos(1,:)) + 100;
        Ly = max(pos(2,:)) + 200;
    end
end


options.Resize='off';
options.WindowStyle='normal';
options.Interpreter='none';
wfgen=questdlg('Generate a new wind field (can be time consuming)?','Wind farm creator','Yes','No','Yes');
error = 0;
switch(wfgen)
    case 'Yes'
        while(true)
            if(~exist('U0') | error)
                qs={'Mean wind speed [m/s]', ...
                    'Turbulence intensity',...
                    'Wind field length [m]',...
                    'Wind field width [m]',...
                    'Grid size [m]',...
                    'Simulation time [s]'};
                answer={'12','.1',num2str(Lx),num2str(Ly),'15','1000'};
                wndparm=inputdlg(qs,'Wind Farm Creator',1,answer,options);
                %if cancel quit
                if(isempty(wndparm))
                    warn=warndlg('Wind field generation canceled (using pre generated field).', 'Wind Farm Creator');
                    uiwait(warn);
                    wfgen=false;
                    break
                end
                U0=str2double(wndparm{1});
                Ti=str2double(wndparm{2});
                Lx=str2double(wndparm{3});
                Ly=str2double(wndparm{4});
                d=str2double(wndparm{5});
                SimTime=str2double(wndparm{6});
            end
            %if invalid string ask again
            error=isempty(U0) || isempty(Ti) || isempty(Lx) || isempty(Ly) || isempty(d) || isempty(SimTime);
            error= error || Ti<0 || Ti>1;
            error= error || U0<=0;
            error= error || Lx<=0;
            error= error || Ly<=0;
            error= error || d<=0 || d>Lx || d>Ly;
            error= error || SimTime<=0;
            if(~error)
                parallel=questdlg('Do you want to use Matlab parallel computation framwork?','Wind farm creator','Yes','No',{'No'});
                h=matlabpool('size');
                switch(parallel)
                    case 'Yes'
                        if(h==0)
                            matlabpool('open');
                        end
                    otherwise
                        if(h~=0)
                            matlabpool('close');
                        end
                end
                defdesc{1}=['Mean:' num2str(U0) ' m/s Turbulence: ' num2str(Ti) ' SimTime:' num2str(SimTime) ];
                desc=inputdlg('Enter wind field description','Wind Farm Creator',1,defdesc);
                if(isempty(desc))
                    desc=defdesc{1};
                end
                wind=gen_windfield(U0,Ti,d,Lx,Ly,SimTime,desc);
                pause(1)
                [file,path]=uiputfile('*.mat','Save wind field as','mywind.mat');
                if ~(isequal(file,0) || isequal(path,0))
                    save([path file],'wind');
                end
                wfgen=true;
                break;
            end
            err=errordlg('Invalid wind parameters.','Wind Farm Creator');
            uiwait(err);
        end
    otherwise
        wfgen=false;
end


if(~wfgen)
    wind={};
end
end