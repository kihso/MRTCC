function S = SimulinkOutput2Struct(Vvec,k,SimName,Turbine_Output,VHubVec,stateVec,forceVec,ControlSignalVec,PitchSignals,xdot_sim,x,xdot,T)
% This function saves output data from simulink to a folder called results and struct S.

% Map output from Simulink to struct S.
% newName1 = strcat('Turbine_Output_',SimName);
% S.(newName1) = Turbine_Output;
% 
% newName2 = strcat('VHubVec_',SimName);
% S.(newName2) = VHubVec;
% 
% newName3 = strcat('stateVec_',SimName);
% S.(newName3) = stateVec;
% 
% newName4 = strcat('forceVec_',SimName);
% S.(newName4) = forceVec;
% 
% newName5 = strcat('ControlSignalVec_',SimName);
% S.(newName5) = ControlSignalVec;
% 
% newName6 = strcat('PitchSignals_',SimName);
% S.(newName6) = PitchSignals;
% 
% newName7 = strcat('xdot_sim_',SimName);
% S.(newName7) = xdot_sim;

newName1 = strcat('Turbine_Output');
S.(newName1) = Turbine_Output;

newName2 = strcat('VHubVec');
S.(newName2) = VHubVec;

newName3 = strcat('stateVec');
S.(newName3) = stateVec;

newName4 = strcat('forceVec');
S.(newName4) = forceVec;

newName5 = strcat('ControlSignalVec');
S.(newName5) = ControlSignalVec;

newName6 = strcat('PitchSignals');
S.(newName6) = PitchSignals;

newName7 = strcat('xdot_sim');
S.(newName7) = xdot_sim;

S.x = x;

S.xdot = xdot;

S.T = T;




% Save data in results folder
folderNames = strcat('./Results/',SimName);
if exist(folderNames) == 7
   cd(folderNames)
       name = ['WS',num2str(Vvec(k))];
	   if exist(name) == 7
	   cd(name);
        save(strcat('TurbineData.mat'), '-struct', 'S')  % EDITED                    
	   else
	   mkdir(name)
	   cd(name);
        save(strcat('TurbineData.mat'), '-struct', 'S')  % EDITED                     
	   end 
	   cd(['../../../'])
else
   mkdir(folderNames)
   cd(folderNames)
       name = ['WS',num2str(Vvec(k))];
	   if exist(name) == 7
	   cd(name);
        save(strcat('TurbineData.mat'), '-struct', 'S')  % EDITED                 
	   else
	   mkdir(name)
	   cd(name);
        save(strcat('TurbineData.mat'), '-struct', 'S')  % EDITED             
	   end 
	   cd(['../../../'])
end

end

