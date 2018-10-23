function [ ] = psetup()


p1 = genpath(fullfile(pwd,'Matlab'));
addpath(p1);

% Add path to multi-rotor model and Wind data
addpath(fullfile(pwd,'sim4TT-v1.0'));
addpath(fullfile(pwd,'Wind'));

% Run install script for SimWindFarm toolbox
run('./simwindfarm-v1.1/install.m')
end

    