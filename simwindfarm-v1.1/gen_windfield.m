function wind=gen_windfield(Ua,Ti,d,Lx,Ly,SimTime,desc)
% 
% Ua      : Average 10 min. u wind speed (default 12m/s)
% Ti      : Turbulence intensity for u wind speed (default 0.10)
% d       : Displacement (default 15 m)
% Lx      : Wind field length
% Ly      : Wind field width
% SimeTime: Simulation time
% desc    : A description of the wind field
%
% To generate a new windfield with same parameters, then call the wrapper function
% by: create_windfield(wind.input)
% 
% Based on Gerrit, Mohsen
% Modified by Mikael Svenstrup

if(nargin == 6)%If no description is provided
    desc=['Mean:' num2str(Ua) ' m/s Turbulence: ' num2str(Ti) ' SimTime:' num2str(SimTime) ];
end

twfres=.01; %Resolution of Time sample
  Ts = round(d/Ua/twfres)*twfres;   %[s] sample time for wind field calc'ns
  Nx = ceil(Lx/d);   %[-] number of grid points in length
  Ny = ceil(Ly/d);   %[-] number of grid points in width
  N = ceil(SimTime/Ts) + Nx;   %[-] number of simulated time samples
    
  [U,V,t] = WindSimHom(Ua,Ti,d,Ny,N,Ts);   %wind speed simulation over grid
  Ux = U' + Ua;   %[m/s]
  Uy = V';   %[m/s]
  
  wind.Ts=Ts;
  wind.Ux=Ux;
  wind.Uy=Uy;
  wind.Umean=Ua;
  
  wind.grid.size=d;
  wind.grid.ysize=Ly;
  wind.grid.xsize=Lx;
  
  %add sim time to wind structure 
  wind.SimTime = SimTime;
  
  wind.desc=desc;
  
  %Save input for recreating wind field with same parameters
%To do this, call
%gen_windfield_no_taylor(wind.input)
wind.input = struct('Ua',Ua,'Ti',Ti,'d',d,'Lx',Lx,'Ly',Ly,'SimTime',SimTime,'desc',desc);

  
end
