function [x,t]= SimSpecVHom(S,C,Nc,df)
%SimSpecVHom simulates data from a given power spectrum.  Notice that the
% spectrum is assumed homogeneous in the sense that all channels has the
% same auto spectrum and all neighbors has the same coherence
%
% [x,t]= SimSpecVHom(S,C,Nc,df)
%
% S : Power spectrum to be simulated. The 1 dimensional S shall contain
%     the spectral values corresponding to frequencies 0,DF,2*DF,..,N*DF.
%     This auto spectrum is used for all channels.
% C:  Coherence from one channel to another.  Similar to S.  This is also 
%     supposed to be the same for all neighbour channels.
% Nc: Number of channels.
% df: Frequency interval
% x : A vector of simulated values for a stochastic process with the 
%     one sided power spectrum S. 
% t : The output vector corresponds to time instants Ts,2*Ts,...,N*Ts
%     where Ts equals 1/(2*N*df).
%
% The user can choose the simulation time N*Ts where N= 2^p, then
% df=1/(2*N*Ts). The time series is periodic with the period 1/df=(2*N*Ts),
% thus only half of the period is simulated.

% 
% External input: None

% Time-stamp: <2009-03-25 12:43:40 tk>
% Version 1: 2009-03-25 12:42:34 tk Based on WindSim and WindSimV
% Torben Knudsen
% Aalborg University, Dept. of Electronic Systems, Section of Automation
% and Control
% E-mail: tk@es.aau.dk

% setting up inputs
dfDef= 1;
NcDef= 2;
if nargin < 4; df= []; end;
if nargin < 3; Nc= []; end;
if nargin < 2; error('Error TK: To few input arguments'); end;
if isempty(df); df= dfDef; end;
if isempty(Nc); Nc= NcDef; end;

% Parameters

% Definitions etc.

% Algorithm

% Extend S with zeros until length is 2^p+1;
S= S(:);
Ns= length(S);                          % Number of frequencies
p= ceil(log(Ns-1)/log(2));
N= 2^p;
S= cat(1,S,zeros(N+1-Ns,1));
Ns= length(S);                          % New number of frequencies;

% Time instants corresponding to x values
t= 1/(2*N*df)*(1:N)';

% Calculate simulated values using fft
alpha= randn(Nc,Ns);
beta= randn(Nc,Ns);
beta(:,1)= 0;                           % I am not sure if this is right
alpha(:,1)= alpha(:,1)/sqrt(2);         % I am not sure if this is right
s= zeros(Nc,Ns);
parfor i= 1:Ns;
  % Calculate spectral matrix assuming homogenous turbulence
  r= zeros(Nc,1);
  r(1)= S(i);
  for k= 2:Nc;
    r(k)= r(k-1)*C(i);
  end;
  [E,L]= eig(toeplitz(r));
  G= E*sqrt(L);
  %notice 1i is complex j (changed on matlabs recommedation)
  s(:,i)= G*(alpha(:,i)+1i*beta(:,i)); 
end;
s= s*sqrt(df);                          % Scaling to get right std
x= fft(s',2*N);
x= real(x(1:N,:));
