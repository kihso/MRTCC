%% NREL 20MW 4TT data generation.
%
% Copyright 2018 - Vestas Wind Systems A/S -  
% Author Oliver Tierdad Filsoof and Kim Hylling Sørensen
%
% Version 1: 2018-10-22 - Vestas
%
% For questions contact:
% E-mail: kihso@vestas.com

%% Parameters TK part begin
WindVec = [4 6 8 10 12 14 16 18 20];
MRTCTs= 0.0125;                             % Standard NREL5MW controller sampling time
SimName = 'VestasControl';
%SimName = 'YOUR_SIMULATION_NAME';
%SimName = 'Baseline';

% Simulation configurations
UseSimulink = 1;
viewpar = 0; % Animation view angle - 1 : sideview, 0 : cornerview

% Load Model Parameters
run('./sim4TT-v1.0/modelParameters.m');
NDOF = 10;
Px_PowerMax = 6e6;
LNaz = par.LNaz;
ttilt=par.ttilt;
La02=par.La02;
La04=par.La04;
La12=par.La12;
La14=par.La14;
Lhub=par.Lhub;
Lt1=par.Lt1;
Lt2=par.Lt2;

% Simulink Control Parameters
Px_UseExternalTower = 1;
Px_UseExternalControl = 0;
Px_AddExternalDeltaPitch = 0;
% Px_disableThetaControl = 0;

% Vestas - Controller gains
        % 4   6   8  10  12  14  16   18  20 m/s
kgain = [0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1;
         3   3   3   3   1   3   3   3   3;
         0.1 0   0.1 0.1 0.1 0.1 0.1 0.1 0.1;
         1   1   0.5 1   3.6 5   5   1   1];

    
for k=1:size(WindVec,2)
AddExtPitch= 1;                 % 1 for add (gain in WT block)
Kgain = 1;                      % scale feedback signal

RadSec2Rpm = 30/pi;
k1 = kgain(1,k); k2 = kgain(2,k); k3 = kgain(3,k); k4 = kgain(4,k);


% Load NREL benchmarkwind
load(['./Wind/NTM/benchmarkwind_no_taylor_' num2str(WindVec(k)) '_NTM' '.mat'])
for i = 1:size(wind.ambient_wind.wind{1, 1},1)
wdata1(i,1) = mean(wind.ambient_wind.wind{1, 1}(i,:)); 
wdata2(i,1) = mean(wind.ambient_wind.wind{1, 2}(i,:)); 
wdata3(i,1) = mean(wind.ambient_wind.wind{1, 3}(i,:)); 
wdata4(i,1) = mean(wind.ambient_wind.wind{1, 4}(i,:)); 
end
tvec = (1:size(wdata1,1))';

% Import Linear Structure Model.
[A_4TT,B_4TT,C_4TT,D_4TT,Ms,Cs,Ks] = StructMatrix(par);

if UseSimulink == 1
    % Use simulink and NREL turbines to generate thrust forces for the 4TT
    % structure.
    TsAnimate = 100;
    Tsim = 200;
    Ts = 0.0125;                        % TK: Variabel time step used in Simulink
    Tau = 0.01;
    sim('NREL_20MW_4TT.slx');
    x = stateVec.data(:,1:NDOF);
    xdot = stateVec.data(:,NDOF+1:2*NDOF);
    T = stateVec.Time;
    U = Turbine_Output.Data(:,1:4);
else % Make a step response in the thrust
    % Use lsim to simulate the linear 4TT structure model.
    TsAnimate = 1;
    Ts = 1;
    Tend = 100;
    T = 0:Ts:(Tend-Ts);

    % Define step time.
    StepTime1 = 10;
    StepTime2 = StepTime1;
    StepTime3 = StepTime1;
    StepTime4 = StepTime1;

    % Define step thrust forces.
    KN=1000;
    fromStepVal1 = 0; toStepVal1 = 700*KN;
    fromStepVal2 = 0; toStepVal2 = 700*KN;
    fromStepVal3 = 0; toStepVal3 = 700*KN;
    fromStepVal4 = 0; toStepVal4 = 700*KN;

    U02_1 = ones(1,StepTime1/Ts)*fromStepVal1; U02_2 = ones(1,(Tend-StepTime1)/Ts)*toStepVal1; U02 = [U02_1 U02_2]; 
    U04_1 = ones(1,StepTime2/Ts)*fromStepVal2; U04_2 = ones(1,(Tend-StepTime2)/Ts)*toStepVal2; U04 = [U04_1 U04_2]; 
    U12_1 = ones(1,StepTime3/Ts)*fromStepVal3; U12_2 = ones(1,(Tend-StepTime3)/Ts)*toStepVal3; U12 = [U12_1 U12_2]; 
    U14_1 = ones(1,StepTime4/Ts)*fromStepVal4; U14_2 = ones(1,(Tend-StepTime4)/Ts)*toStepVal4; U14 = [U14_1 U14_2]; 
    U = [U02' U04' U12' U14'];
    X0 = zeros(par.NDOF*2,1);

    SYS = ss(A_4TT,B_4TT,C_4TT,D_4TT);
    Y = lsim(SYS,U,T,X0);
    [xdotdot,xdot,x,Fint] = postprocess(Y.',U.',A_4TT,B_4TT,Ms,Ks,par.NDOF);
    x = x';
    xdot = xdot';
end

% Save data to struct S and save mat files in results folder.
S = SimulinkOutput2Struct(WindVec,k,SimName,Turbine_Output,VHubVec,stateVec,forceVec,ControlSignalVec,PitchSignals,xdot_sim,x,xdot,T);

end




