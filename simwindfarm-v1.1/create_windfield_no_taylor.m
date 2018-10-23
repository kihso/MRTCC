function wind=create_windfield(farm)
%wind = CREATE_WINDFIELD_NO_TAYLOR()
% creates a windfield for a no-taylor simulation
%
% To create a new field with for your current farm, use or modify the farm data when calling
% the function:
%wind = CREATE_WINDFIELD_NO_TAYLOR(wind.input)
% To obtain your current wind field; click once on the "Wind Field" block
% in the simulink model and:
%wind=get_param([gcb '/Ambient Lateral Field'],'UserData');
%
% The default length and width of the wind field is 1000m. But if you
% provide the turbine positions in a farm struct. The wind field will be
% adjusted accordingly (farm.pos = [x1 x2...xn ; y1 y2 ... yn]):
%wind = CREATE_WINDFIELD_NO_TAYLOR(farmPos)
no_farm = 1;

%Default length and width for wind field
Lx = 1000;
Ly = 1000;

if nargin==1
    if(isfield(farm,'Ua'))
        %If just information from old wind field is provided
        U0 =    farm.Ua;
        Ti =    farm.Ti;
        d =     farm.d;
        Lx =    farm.Lx;
        Ly =    farm.Ly;
        SimTime =   farm.SimTime;
        desc =   farm.desc;
        farm =  farm.farm;
    else %It must be farm coordinates either in a struct or as a matrix
        if(isfield(farm,'pos'))
            pos = farm.pos;
        else
            pos = farm;
        end
        Lx = max(pos(1,:)) + 100;
        Ly = max(pos(2,:)) + 200;
    end
    no_farm = 0;
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
                    'Wind field lengt [m]',...
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
            if no_farm
                while(true)
                    num=inputdlg('Enter number of turbines','Wind Farm Creator',1,{'3'},options);
                    %if cancel quit
                    if(isempty(num))
                        return
                    end
                    num=str2double(num);
                    %if invalid string ask again
                    if(~isempty(num) && mod(num,1)==0 && num>0)
                        break
                    end
                    err=errordlg('Not a valid number.','Wind Farm Creator');
                    uiwait(err);
                end
                load_system('libturbines');
                str1=find_system('libturbines');
                str=cell(length(str1)-1,1);
                for i=2:length(str1)
                    st=str1{i};
                    str{i-1}=st(length('libturbines/')+1:end);
                end
                [s,v]=listdlg('PromptString','Select a turbine model',...
                    'SelectionMode','single',...
                    'ListString',str);
                
                
                if(~v)
                    return
                end
                farm.turbines{1}=str{s};
                while(true)
                    dfl={mat2str([(0:num-1)*100;ones(1,num)*100])};
                    pos=inputdlg('Enter turbine position matrix','Wind Farm Creator',1,dfl,options);
                    %if cancel quit
                    if(isempty(pos))
                        return
                    end
                    pos=str2num(pos{1});
                    %if invalid string ask again
                    if(~isempty(num) && isempty(find((size(pos)==[2,num])==0,1)) && isempty(find(pos<0,1)))
                        break
                    end
                    err=errordlg('Not a valid position matrix','Wind Farm Creator');
                    uiwait(err);
                end
                farm.pos = pos;
            end
            
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
                defdesc{1}=['No Taylor - Mean:' num2str(U0) ' m/s Turbulence: ' num2str(Ti) ' SimTime:' num2str(SimTime) ];
                desc=inputdlg('Enter wind field description','Wind Farm Creator',1,defdesc);
                if(isempty(desc))
                    desc=defdesc{1};
                end
                wind=gen_windfield_no_taylor(U0,Ti,d,Lx,Ly,farm,SimTime,desc);
                pause(1)
                [file,path]=uiputfile('*.mat','Save wind field as','mywind_no_taylor.mat');
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