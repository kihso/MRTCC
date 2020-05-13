%%%%%%% Model Parameters for 4TT %%%%%%%%%
% constants
Esteel = 210e9;
Deg2Rad = pi/180;
Rad2Deg  = 180/pi;

% Degree of freedoms
par.NDOF = 10;

% Damping Model
par.Spectral_damping = 0; % If 0, rayleigh damping model is chosen
par.zeta = 0.35; % damping in % for each mode in spectral damping. Convert to logarithmic decrement by zeta*2*pi i.e. 0.3*2*pi=1.885% log dec

% Geometry [m]
% Arm Lengths
par.La02 = 66.15;       % Length of arm 02; % 10 % arm spacing
par.La04 = 66.15;       % Lenght of arm 04;
par.La12 = 66.15;       % Length of arm 12;
par.La14 = 66.15;       % Length of arm 14;
par.LNaz = 1.96256;     % Vertical Distance along Yaw Axis from Yaw Bearing to Shaft
par.LNay = 1;           % Displacement length of nacelle eq. mass from COG in y.
par.Lhub = 5.01910;     % Distance along Shaft from Hub Center to Yaw Axis
par.Lt1=90;             % Length of tower section 1
par.Lt2=228.6-par.Lt1;  % Length of tower section 2
par.Lblade = 63;% 63
par.ttilt = -5*Deg2Rad;


% Bending stiffness for tower section 1 and 2.

par.EIz1 = Esteel*(pi/64*(8^4-7.9^4));
par.EIz2 = Esteel*(pi/64*(8^4-7.96^4));
%par.EIz2 = Esteel*9.866;

% Yaw Node stiffnesses
IxP0=pi/32*(8^4-7.9^4);
IxP1=pi/32*(8^4-7.96^4);
par.ktP0 = (Esteel*IxP0)/(2*par.Lt1*(0.3+1)); 
par.ktP1 = (Esteel*IxP1)/(2*par.Lt2*(0.3+1));

Ixarm = pi/32*(4^4-3.96^4);%0.005;
par.ktx02=(Esteel*Ixarm)/(2*par.La02*(0.3+1)); %0.00063
par.ktx04=(Esteel*Ixarm)/(2*par.La04*(0.3+1)); %0.00063
par.ktx12=(Esteel*Ixarm)/(2*par.La12*(0.3+1)); %0.00063
par.ktx14=(Esteel*Ixarm)/(2*par.La14*(0.3+1)); %0.00063
% par.ktx02=(Esteel/((1+0.3))*Ixarm) / par.La02*0.00063; %0.00063
% par.ktx04=(Esteel/((1+0.3))*Ixarm) / par.La04*0.00063; %0.00063
% par.ktx12=(Esteel/((1+0.3))*Ixarm) / par.La12*0.00063; %0.00063
% par.ktx14=(Esteel/((1+0.3))*Ixarm) / par.La14*0.00063; %0.00063
% par.ktx=(Esteel/(2*(1+0.3))*Ixarm) / Larm;
% par.ktx=(Esteel/(2*(1+0.3))*Ixarm) / Larm;
% par.ktx=(Esteel/(2*(1+0.3))*Ixarm) / Larm;

% Masses [kg]
MH = 56780;   % Hub mass
MBld = 17715.5; % Blade mass
par.MHB =  MH+(3*MBld); % Combined hub and blade masses 
par.Mnac = 215000; % Nacelle mass
par.Marm = 129029;       % Arm mass
par.MyawP0 = 25000;        % Yaw mass P0
par.MyawP1 = 25000;        % Yaw mass P1
par.mt1 = 901690;            % Tower section 1 mass
par.mt2 = 567065;            % Tower section 2 mass

% Tower Dampning 
par.alpha = 0.0; % Mass
par.beta = 0.12; % Stiffness12
%par.beta = 0.00;%12; % Stiffness12
