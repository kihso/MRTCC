function [ output_args ] = plot_grass( arg1 )
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here

grassSize = arg1;

Xgrass = [ -grassSize  -grassSize   grassSize   grassSize];
Ygrass = [-grassSize grassSize grassSize -grassSize];
Zgrass = [0 0 0 0];
patch(Xgrass,Ygrass,Zgrass,[0 0.5 0])

end

