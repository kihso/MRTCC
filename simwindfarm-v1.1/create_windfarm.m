function create_windfarm()
% WFCREATE - Interactive script for creating a wind farm model
%
% Copyright 2009 - Aalborg University
% Author Jacob Grunnet - grunnet@es.aau.dk

go=questdlg('Create a new wind farm model?','Wind farm creator','Continue','Cancel','Continue');
%Go forward?
switch(go)
    case 'Cancel'
        return
    otherwise
end

options.Resize='off';
options.WindowStyle='normal';
options.Interpreter='none';



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

parm = get_param(['libturbines/' str{s}],'UserData');
rotorRadius = parm.public.rotor.radius;
turbine=str{s};

%Number of rows and columns of turbines. Minimum 4 turbines in row
nGrid = max(ceil(sqrt(num)),4);
turbDist = 400;
[yvec xvec] = meshgrid(0:(nGrid-1),0:(nGrid-1));
xvec = xvec(1:num)*turbDist;
yvec = yvec(1:num)*turbDist + 100;
pos = [xvec(:) yvec(:)]';


while(true)
    dfl={mat2str(pos')};
    pos=inputdlg('Enter turbine position matrix (x1 y1 ; x2 y2 ; ... ; xn yn)','Wind Farm Creator',1,dfl,options);
    %if cancel quit
    if(isempty(pos))
        return
    end
    pos=str2num(pos{1})';
    %if invalid string ask again
    if(~isempty(num) && isempty(find((size(pos)==[2,num])==0,1)) && isempty(find(pos<0,1)) && isempty(find(pos(2,:)<rotorRadius)) )
        break
    end
    err=errordlg('Not a valid position matrix. Ensure that all turbines have positive coordinates and y position is at least equal to rotor radius.','Wind Farm Creator');
    uiwait(err);
end

wind=create_windfield(pos);

if(isempty(wind))
    [wfile,wpath,wfidx]=uigetfile('*.mat','Select a Wind Data File');

    if isequal(wfile,0) || isequal(wpath,0)
       %no dice then
       return;
    end

    %Loads wind profile data
    l=load([wpath wfile]);
    wind=l.wind;
end

[file,path]=uiputfile('*.mdl','Save Wind Farm Model As','windfarm.mdl');

if isequal(file,0) || isequal(path,0)
   return
end

if(exist([path file]))
    disp('file existed and is removed')
    delete([path file])
end

%%Create data structures for mdlcreate

for i=1:num
    farm.turbines{i}=turbine;
end


farm.pos=pos;

%close system stuff
gen_windfarm(file,path,farm,wind);
            

end