function wind=gen_windfield_no_taylor(Ua,Ti,d,Lx,Ly,farm,SimTime,desc)
% 
% Ua      : Average 10 min. u wind speed (default 12m/s)
% Ti      : Turbulence intensity for u wind speed (default 0.10)
% d       : Displacement (default 15 m)
% Lx      : Wind field length
% Ly      : Wind field width
% farm    : Farm layout
% SimeTime: Simulation time
% desc    : A description of the wind field
%
% To generate a new windfield with same parameters, then call the wrapper 
% function by: create_windfield_no_taylor(wind.input)
% 
% Based on Gerrit, Mohsen, Vedrana, and Torben
% Modified by Mikael Svenstrup

if(nargin == 7)%If no description is provided
    desc=['No Taylor - Mean:' num2str(Ua) ' m/s Turbulence: ' num2str(Ti) ' SimTime:' num2str(SimTime) ];
end


tic
debug = 0;
twfres=.01; %Resolution of Time sample
Ts = round(d/Ua/twfres)*twfres;   %[s] sample time for wind field calc'ns
Nx = ceil(Lx/d);   %[-] number of grid points in length
Ny = ceil(Ly/d);   %[-] number of grid points in width
N = ceil(SimTime/Ts) + Nx;   %[-] number of simulated time samples
    
wh = waitbar(0,'Please wait... generating wind field');

% Parameters
% IEC 61400-3 is specific for offshore turbines, however for wind
% conditions the parameters defined in IEC 61400-1 may be used with some
% modification. The parameters used in this work are, however, not
% affected and therefore IEC 61400-1 values are used.
% IEC 61400-1

cu= 7.1; cv=4.2; % Given by table 1 in "Lateral coherence in isotropic
                 % turbulence and in the natural wind" by Kristensen
                 % and Jensen, 1979.

% Definitions etc.
% IEC 61400-1
Lambdau = 42;             % Given by eq 5 page 24 IEC 61400-1(2005)
Lu= 8.1* Lambdau;         % Given in table B.1 in IEC 61400-1(2005) page 83
Lv= 2.7*Lambdau;          % Given in table B.1 in IEC 61400-1(2005) page 83
Sigmau= Ti*(0.75*Ua+5.6); % Given by eq 11 page 24 IEC 61400-1(2005)
% Sigmau= Ti*(0.75*Ua+5.6); % Given by eq 19 page 24 IEC 61400-1(2005)
Sigmav= 0.8*Sigmau;       % Given in table B.1 in IEC 61400-1(2005) page 83

Ns= 2^ceil(log(N)/log(2));
DF=1/(2*Ns*Ts);

% % Algorithm
F= (0:Ns)'*DF;

% Lateral wind part
Sv= Sigmav^2*4*Lv/Ua./(1+6*F*Lv/Ua).^(5/3); %Kaimal spectrum assumed
Cv= exp(-cv*d/Ua*F);

[V,t] = SimSpecVHom(Sv,Cv,Ny,DF);
waitbar(1/4,wh);
if debug
    disp('After V wind')
    toc
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

pos = farm.pos;
N_turb = size(farm.pos,2);

%Extract turbine data
load_system('libturbines'); %Load turbine library
partmp=get_param(['libturbines/' farm.turbines{1}],'UserData');
wtpar=partmp.public;
temp = 2*wtpar.rotor.radius/d;
if(mod(temp,2)>1)
   gridN = floor(temp);
else
   gridN = ceil(temp);
end
gridSize = d;
pos2 = pos;
pos = [];
for k=1:N_turb
  pos(:,((k-1)*gridN+1):k*gridN) = kron(ones(1,gridN),pos2(:,k))+[zeros(1,gridN);-floor(gridN/2):floor(gridN/2)]*gridSize; 
end

amb_wind.wind_pos = pos;
[pom,index] = sortrows(pos');
pos=pom';
N_turb = N_turb*gridN;

d_turb=zeros(N_turb);tau=zeros(N_turb);alpha=zeros(N_turb);
for k=1:N_turb
    for h=k:N_turb
        d_turb(k,h)=norm(pos(:,k)-pos(:,h),2);  %distances between wind turbines
        d_turb(h,k)=d_turb(k,h);
        tau(k,h)=abs(pos(1,k)-pos(1,k))/Ua;  %time which takes for the turbulence to travel from WT j to WT i
        tau(h,k)=-tau(k,h);
        alpha(k,h)=atan2(abs(pos(2,k)-pos(2,h)),abs(pos(1,k)-pos(1,h))); %angle between turbine distance and x-axis
        alpha(h,k)=alpha(k,h);
    end;
end;
waitbar(2/4,wh);
if debug
    disp('After calc of distance, delay and angle')
    toc
end
%initialization for frequency space
fs=5;
dt=1/fs;
df=5e-4;
T=1/df;
f=0:df:fs/2;
Ns=2*length(f);

a=sqrt((cu*cos(alpha)).^2+(cv*sin(alpha)).^2); %decay factor
gamma=zeros(N_turb,N_turb,Ns/2);
for i=1:N_turb
   for j=1:N_turb
        gamma(i,j,1:Ns/2)=exp(-a(i,j)*d_turb(i,j)/Ua*f);
    end;
end;

Su= Sigmau^2*4*Lu/Ua./(1+6*f*Lu/Ua).^(5/3); %Kaimal spectrum assumed

if debug
    disp('After Spectrum u-direction')
    toc
end
waitbar(3/4,wh);

%power spectrum
S=zeros(N_turb,N_turb,Ns/2);
for i=1:N_turb
    S(i,i,1:Ns/2)=Su;
end;

S=S*Ns*fs/2;

if debug
    disp('Before generation sprectrum with delay')
    toc
end

for i=1:N_turb
    S_ii(1:Ns/2)=S(i,i,1:Ns/2);
    for j=1:N_turb
        S_jj(1:Ns/2)=S(j,j,1:Ns/2);
        if (i~=j)
            gamma_ij(1:Ns/2)=gamma(i,j,1:Ns/2);
            S(i,j,1:Ns/2)=gamma_ij.*sqrt(S_ii.*S_jj).*exp(sqrt(-1).*2.*pi.*f.*tau(i,j));
       end;
    end;
 end;
 S(1:N_turb,1:N_turb,1)=S(1:N_turb,1:N_turb,1).*eye(N_turb);
 
 if debug
     disp('After generation sprectrum with delay')
    toc
 end
 
 H=zeros(N_turb,N_turb,Ns/2);
 V_turb=zeros(N_turb,Ns/2);
 randn('state',sum(100*clock));

 for f=1:Ns/2   
    S_f(1:N_turb,1:N_turb)=S(:,:,f);
    H(1:N_turb,1:N_turb,f)=chol(S_f);
    phi_r=randn(N_turb,1).*(2*pi);
    X=exp(sqrt(-1).*phi_r);
    V_turb(1:N_turb,f)=H(:,:,f)*X;
    for i=1:N_turb
        V_turb(i,f)=V_turb(i,f)./abs(V_turb(i,f))*sqrt(S(i,i,f));
    end;
end;

if debug
    disp('After generation V_turb freq domain')
    toc
end

V_turb(1:N_turb,1)=zeros(1,N_turb);
   
%inverse Fourier
V_turb=[V_turb fliplr(conj(V_turb(1:N_turb,2:end)))];

v_turb=zeros(size(V_turb));
parfor i=1:N_turb
    v_turb(i,:)=ifft(V_turb(i,:));
end;

if debug
    disp('After generating v_turb time series')
    toc
end
    
%return the order of wind turbines that is stored in farm structure
for i=1:N_turb
    pom(index(i),1:size(v_turb,2))=v_turb(i,:);
end;
v_turb=pom;

%resampling
t=0:dt:T;
tsim=0:Ts:SimTime;
v_turb_sim=interp1(t,v_turb',tsim) + Ua;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
%%%%%%%%%%%%%%5 TEMP %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%55
% v_turb_sim=ones(size(v_turb_sim))*Ua;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
if debug
    disp('After interpolating')
    toc
end
waitbar(4/4,wh);

[M,N_turb] = size(v_turb_sim);
if M > N_turb
    for k = 1:N_turb/gridN
        wind_turb{k} = v_turb_sim(:,((k-1)*gridN+1):((k-1)*gridN+gridN));
    end
else
    for k = 1:N_turb/gridN
        wind_turb{k} = v_turb_sim(((k-1)*gridN+1):((k-1)*gridN+gridN),:);
    end
end
amb_wind.time = tsim;
amb_wind.num_of_turb = N_turb/gridN;
amb_wind.gridN = gridN;
amb_wind.gridSize = gridSize;
amb_wind.turb_pos = pos2;
amb_wind.wind = wind_turb;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Truncate to number of samples N specified in input
t= t(1:N);
V= V(1:N,:);

close(wh)
%Ux = U' + Ua;   %[m/s]
Uy = V';   %[m/s]

wind.Ts=Ts;
%wind.Ux=Ux;
wind.Uy=Uy;
wind.Umean = Ua;
wind.farm = farm;


wind.grid.size=d;
wind.grid.ysize=Ly;
wind.grid.xsize=Lx;
wind.ambient_wind = amb_wind;
%add sim time to wind structure 
wind.SimTime = SimTime;

wind.desc=desc;

%Save input for recreating wind field with same parameters
%To do this, call
%gen_windfield_no_taylor(wind.input)
wind.input = struct('Ua',Ua,'Ti',Ti,'d',d,'Lx',Lx,'Ly',Ly,'farm',farm,'SimTime',SimTime,'desc',desc);


if debug
    disp('Done')
    toc
end

end
