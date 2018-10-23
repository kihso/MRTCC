function [U,V,t]= WindSimHom(Ua,Ti,d,Nc,N,Ts,Info)
%WindSimHom simulates wind speed at a number of locations with a lateral
% displacement.  Notice that the spectrum is assumed homogeneous in the
% sense that all channels has the same auto spectrum and all neighbors
% has the same coherence
%
% [U,V,t]= WindSim(Ua,Ti,d,Nc,N,Ts,Info)
%
% U : Matrix with simulated longitudinal wind where the columns are u1,
%     ... uNc,
% V : Matrix with simulated lateral wind where the columns are v1,
%     ... vNc,
% t : Vector with time instants
% Ua: Average 10 min. u wind speed (default 10m/s)
% Ti: Turbulence intensity for u wind speed (default 0.10)
% d : Displacement (default 10 m)
% Nc: Number of channels (default 2)
% N : Number of simulated time samples (default 1024)
%     Internally the number of samples are the nearest  2^p >= N
% Ts: Sample time (default 1)
% Info: If Info=1 output some info (default 0)
% 
% External input: SimSpecV

% Time-stamp: <2009-03-25 12:42:58 tk>
% Version 1: 2009-03-25 12:38:58 tk Based on WindSim
% Torben Knudsen
% Aalborg University, Dept. of Electronic Systems, Section of Automation
% and Control
% E-mail: tk@es.aau.dk

h = waitbar(0,'Please wait... generating wind field');
% setting up inputs
UaDef= 10;
TiDef= 0.1;
dDef= 10;
NcDef= 2;
NDef= 1024;
TsDef= 1;
InfoDef= 0;
if nargin < 1; Ua= []; end;
if nargin < 2; Ti= []; end;
if nargin < 3; d= []; end;
if nargin < 4; Nc= []; end;
if nargin < 5; N= []; end;
if nargin < 6; Ts= []; end;
if nargin < 7; Info= []; end;
if isempty(Ua); Ua= UaDef; end;
if isempty(Ti); Ti= TiDef; end;
if isempty(d); d= dDef; end;
if isempty(Nc); Nc= NcDef; end;
if isempty(N); N= NDef; end;
if isempty(Ts); Ts= TsDef; end;
if isempty(Info); Info= InfoDef; end;

% Parameters
% IEC 61400-3 is specific for offshore turbines, however for wind
% conditions the parameters defined in IEC 61400-1 may be used with some
% modification. The parameters used in this work are, however, not
% affected and therefore IEC 61400-1 values are used.
% IEC 61400-1

% cu = 5; cv = 50; % OLD values

cu= 7.1; cv=4.2; % Given by table 1 in "Lateral coherence in isotropic
                 % turbulence and in the natural wind" by Kristensen
                 % and Jensen, 1979.

% Definitions etc.

% IEC 61400-1
%Lambdau= 21; OLD value
%Lambdav= 0.3333*Lambdau; % Lambdaw= 0.08148*Lambdau; %OLD value

Lambdau = 42; %Given by eq 5 page 24 IEC 61400-1(2005)
Lu= 8.1* Lambdau; %Given in table B.1 in IEC 61400-1(2005) page 83
%Lv = 8.1*Lambdav; OLD value
Lv= 2.7*Lambdau; %Given in table B.1 in IEC 61400-1(2005) page 83

Sigmau= Ti*(0.75*Ua+5.6); %Given by eq 11 page 24 IEC 61400-1(2005)
%Sigmau=Ti*Ua; %OLD value
Sigmav= 0.8*Sigmau; % Given in table B.1 in IEC 61400-1(2005) page 83

Ns= 2^ceil(log(N)/log(2));
DF=1/(2*Ns*Ts);

% Algorithm

% Longitudinal wind part
F= (0:Ns)'*DF;
Su= Sigmau^2*4*Lu/Ua./(1+6*F*Lu/Ua).^(5/3); %Kaimal spectrum assumed
Cu= exp(-cu*d/Ua*F);
waitbar(1/3);
[U,t]= SimSpecVHom(Su,Cu,Nc,DF);


waitbar(2/3);
% Lateral wind part
Sv= Sigmav^2*4*Lv/Ua./(1+6*F*Lv/Ua).^(5/3); %Kaimal spectrum assumed
Cv= exp(-cv*d/Ua*F);

V= SimSpecVHom(Sv,Cv,Nc,DF);

wh = waitbar(3/3);
% Truncate to number of samples N specified in input
t= t(1:N);
U= U(1:N,:);
V= V(1:N,:);


close(wh)
if Info;
  figure;
  subplot(221)
  plot(F,Su,'-*');
  title('Spectrum u');
  subplot(222)
  plot(F,Cu,'-*');
  title('Coherence u');
  subplot(223)
  plot(F,Sv,'-*');
  title('Spectrum v');
  subplot(224)
  plot(F,Cv,'-*');
  title('Coherence v');
  suptitle('WindSim plot');

  Res= [sqrt([sum(Su) sum(Sv)]*DF) DF Ns*DF];
  printmattk(Res,'WindSim: Std from spectra freq step and upper limit');
end;
