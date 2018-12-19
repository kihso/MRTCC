clear; clc
% Load parameter file
run('./sim4TT-v1.0/modelParameters.m')

% Labels
ft1_idx = 1; ft2_idx = 2; ft3_idx = 3; ft4_idx = 4;
CT1_idx = 5; CT2_idx = 6; CT3_idx = 7; CT4_idx = 8;
GenSpd1_idx = 9; GenSpd2_idx = 10; GenSpd3_idx = 11; GenSpd4_idx = 12;
Power1_idx = 13; Power2_idx = 14; Power3_idx = 15; Power4_idx = 16;
Vhub1_idx = 17; Vhub2_idx = 18; Vhub3_idx = 19; Vhub4_idx = 20;
Pitch1_idx = 21; Pitch2_idx = 22; Pitch3_idx = 23; Pitch4_idx = 24;

M_yaw1_idx = 1; M_yaw2_idx = 2; F_twr1_idx = 3; F_twr2_idx = 4; M_twr1_idx = 5; M_twr2_idx = 6; 
M_arm02_idx = 7; M_arm04_idx = 8; M_arm12_idx = 9; M_arm14_idx = 10;


% Load simulation data and process
baselineFolderName = 'Baseline';
controllerFolderName = 'VestasControl';

Vvec = [4 6 8 10 12 14 16 18 20];
for l = 1:2
for k = 1:size(Vvec,2)
    if l == 1
    load(['./Results/',baselineFolderName,'/WS' num2str(Vvec(k)) '/TurbineData.mat']);
    else
    load(['./Results/',controllerFolderName,'/WS' num2str(Vvec(k)) '/TurbineData.mat'])
    end

Ft1 = Turbine_Output.Data(:,ft1_idx);
Ft2 = Turbine_Output.Data(:,ft2_idx);
Ft3 = Turbine_Output.Data(:,ft3_idx);
Ft4 = Turbine_Output.Data(:,ft4_idx);

gen1 = Turbine_Output.Data(:,GenSpd1_idx);
gen2 = Turbine_Output.Data(:,GenSpd2_idx);
gen3 = Turbine_Output.Data(:,GenSpd3_idx);
gen4 = Turbine_Output.Data(:,GenSpd4_idx);

gen1_mean = mean(gen1);
gen2_mean = mean(gen2);
gen3_mean = mean(gen3);
gen4_mean = mean(gen4);

gen1_var = var(gen1);
gen2_var = var(gen2);
gen3_var = var(gen3);
gen4_var = var(gen4);

vhub1 = Turbine_Output.Data(:,Vhub1_idx);
vhub2 = Turbine_Output.Data(:,Vhub2_idx);
vhub3 = Turbine_Output.Data(:,Vhub3_idx);
vhub4 = Turbine_Output.Data(:,Vhub4_idx);

vhub1_mean = mean(vhub1);
vhub2_mean = mean(vhub2);
vhub3_mean = mean(vhub3);
vhub4_mean = mean(vhub4);

vhub1_var = var(vhub1);
vhub2_var = var(vhub2);
vhub3_var = var(vhub3);
vhub4_var = var(vhub4);

Myaw1=forceVec.Data(:,M_yaw1_idx);
Myaw2=forceVec.Data(:,M_yaw2_idx);
F_twr1 = forceVec.Data(:,F_twr1_idx);
F_twr2 = forceVec.Data(:,F_twr2_idx);
M_twr1 = -forceVec.Data(:,M_twr1_idx);
M_twr2 = -forceVec.Data(:,M_twr2_idx);
M_02 = -forceVec.Data(:,M_arm02_idx);
M_04 = -forceVec.Data(:,M_arm04_idx);
M_12 = -forceVec.Data(:,M_arm12_idx);
M_14 = -forceVec.Data(:,M_arm14_idx);

TowerRootMoment = F_twr1*par.Lt1+F_twr2*(par.Lt1+par.Lt2)+(M_twr1+M_twr2+M_02+M_12+M_04+M_14);
TowerRootMoment_mean = mean(TowerRootMoment);
TowerRootMoment_var = var(TowerRootMoment);
TowerRootMoment_DEL = DEL_fun(TowerRootMoment,100,100,1);


Myaw1_mean = mean(Myaw1);
Myaw1_var = var(Myaw1);
Myaw1_DEL = DEL_fun(Myaw1,100,100,1);

Myaw2_mean = mean(Myaw2);
Myaw2_var = var(Myaw2);
Myaw2_DEL = DEL_fun(Myaw2,100,100,1);

M_02_mean = mean(M_02);
M_02_var = var(M_02);
M_02_DEL = DEL_fun(M_02,100,100,1);

M_04_mean = mean(M_04);
M_04_var = var(M_04);
M_04_DEL = DEL_fun(M_04,100,100,1);

M_12_mean = mean(M_12);
M_12_var = var(M_12);
M_12_DEL = DEL_fun(M_12,100,100,1);

M_14_mean = mean(M_14);
M_14_var = var(M_14);
M_14_DEL = DEL_fun(M_14,100,100,1);

if sum(abs(diff(Turbine_Output.Data(:,Pitch1_idx)))) == 0
    PDT_02 = 1; 
else
	PDT_02 = sum(abs(diff(Turbine_Output.Data(:,Pitch1_idx))));
end

if sum(abs(diff(Turbine_Output.Data(:,Pitch2_idx)))) == 0
    PDT_04 = 1; 
else
	PDT_04 = sum(abs(diff(Turbine_Output.Data(:,Pitch2_idx))));
end

if round(sum(abs(diff(Turbine_Output.Data(:,Pitch3_idx))))) == 0
    PDT_12 = 1; 
else
	PDT_12 = sum(abs(diff(Turbine_Output.Data(:,Pitch3_idx))));
end

if sum(abs(diff(Turbine_Output.Data(:,Pitch4_idx)))) == 0
    PDT_14 = 1; 
else
	PDT_14 = sum(abs(diff(Turbine_Output.Data(:,Pitch4_idx))));
end

Power_02_mean = mean(Turbine_Output.Data(:,Power1_idx));
Power_02_var = var(Turbine_Output.Data(:,Power1_idx));
Power_04_mean = mean(Turbine_Output.Data(:,Power2_idx));
Power_04_var = var(Turbine_Output.Data(:,Power2_idx));
Power_12_mean = mean(Turbine_Output.Data(:,Power3_idx));
Power_12_var = var(Turbine_Output.Data(:,Power3_idx));
Power_14_mean = mean(Turbine_Output.Data(:,Power4_idx));
Power_14_var = var(Turbine_Output.Data(:,Power4_idx));

Res{1,2} = {'WS 4'};
Res{1,3} = {'WS 6'};
Res{1,4} = {'WS 8'};
Res{1,5} = {'WS 10'};
Res{1,6} = {'WS 12'};
Res{1,7} = {'WS 14'};
Res{1,8} = {'WS 16'};
Res{1,9} = {'WS 18'};
Res{1,10} = {'WS 20'};

% Means
Res{1,1} = {'Means'};

Res{2,1} = {'Tower Root Moment Mean'};
Res{2,k+1} = TowerRootMoment_mean;

Res{3,1} = {'Yaw Moment 1 Mean'};
Res{3,k+1} = Myaw1_mean;

Res{4,1} = {'Yaw Moment 2 Mean'};
Res{4,k+1} = Myaw2_mean;

Res{5,1} = {'Arm Moment 02 Mean'};
Res{5,k+1} = M_02_mean;

Res{6,1} = {'Arm Moment 04 Mean'};
Res{6,k+1} = M_04_mean;

Res{7,1} = {'Arm Moment 12 Mean'};
Res{7,k+1} = M_12_mean;

Res{8,1} = {'Arm Moment 14 Mean'};
Res{8,k+1} = M_14_mean;

Res{9,1} = {'Power 02 Mean'};
Res{9,k+1} = Power_02_mean;

Res{10,1} = {'Power 04 Mean'};
Res{10,k+1} = Power_04_mean;

Res{11,1} = {'Power 12 Mean'};
Res{11,k+1} = Power_12_mean;

Res{12,1} = {'Power 14 Mean'};
Res{12,k+1} = Power_14_mean;

% Variance
Res{13,1} = {'Variance'};

Res{14,1} = {'Tower Root Moment Var'};
Res{14,k+1} = TowerRootMoment_var;

Res{15,1} = {'Yaw Moment 1 Var'};
Res{15,k+1} = Myaw1_var;

Res{16,1} = {'Yaw Moment 2 Var'};
Res{16,k+1} = Myaw2_var;

Res{17,1} = {'Arm Moment 02 Var'};
Res{17,k+1} = M_02_var;

Res{18,1} = {'Arm Moment 04 Var'};
Res{18,k+1} = M_04_var;

Res{19,1} = {'Arm Moment 12 Var'};
Res{19,k+1} = M_12_var;

Res{20,1} = {'Arm Moment 14 Var'};
Res{20,k+1} = M_14_var;

Res{21,1} = {'Power 02 Var'};
Res{21,k+1} = Power_02_var;

Res{22,1} = {'Power 04 Var'};
Res{22,k+1} = Power_04_var;

Res{23,1} = {'Power 12 Var'};
Res{23,k+1} = Power_12_var;

Res{24,1} = {'Power 14 Var'};
Res{24,k+1} = Power_14_var;

Res{25,1} = {'Sum'};

Res{26,1} = {'Pitch Distance Traveled 02'};
Res{26,k+1} = PDT_02;

Res{27,1} = {'Pitch Distance Traveled 04'};
Res{27,k+1} = PDT_04;

Res{28,1} = {'Pitch Distance Traveled 12'};
Res{28,k+1} = PDT_12;

Res{29,1} = {'Pitch Distance Traveled 14'};
Res{29,k+1} = PDT_14;

Res{30,1} = {'DELs'};

Res{31,1} = {'Tower Root Moment Mean'};
Res{31,k+1} = TowerRootMoment_DEL;

Res{32,1} = {'Yaw Moment 1 Mean'};
Res{32,k+1} = Myaw1_DEL;

Res{33,1} = {'Yaw Moment 2 Mean'};
Res{33,k+1} = Myaw2_DEL;

Res{34,1} = {'Arm Moment 02 Mean'};
Res{34,k+1} = M_02_DEL;

Res{35,1} = {'Arm Moment 04 Mean'};
Res{35,k+1} = M_04_DEL;

Res{36,1} = {'Arm Moment 12 Mean'};
Res{36,k+1} = M_12_DEL;

Res{37,1} = {'Arm Moment 14 Mean'};
Res{37,k+1} = M_14_DEL;


Res{38,1} = {'Controls Mean/Var'};

Res{39,1} = {'Gen Spd 02 Mean'};
Res{39,k+1} = gen1_mean;

Res{40,1} = {'Gen Spd 04 Mean'};
Res{40,k+1} = gen2_mean;

Res{41,1} = {'Gen Spd 12 Mean'};
Res{41,k+1} = gen3_mean;

Res{42,1} = {'Gen Spd 14 Mean'};
Res{42,k+1} = gen4_mean;

Res{43,1} = {'Vhub 02 Mean'};
Res{43,k+1} = vhub1_mean;

Res{44,1} = {'Vhub 04 Mean'};
Res{44,k+1} = vhub2_mean;

Res{45,1} = {'Vhub 12 Mean'};
Res{45,k+1} = vhub3_mean;

Res{46,1} = {'Vhub 14 Mean'};
Res{46,k+1} = vhub4_mean;


Res{47,1} = {'Gen Spd 02 Var'};
Res{47,k+1} = gen1_var;

Res{48,1} = {'Gen Spd 04 Var'};
Res{48,k+1} = gen2_var;

Res{49,1} = {'Gen Spd 12 Var'};
Res{49,k+1} = gen3_var;

Res{50,1} = {'Gen Spd 14 Var'};
Res{50,k+1} = gen4_var;

Res{51,1} = {'Vhub 02 Var'};
Res{51,k+1} = vhub1_var;

Res{52,1} = {'Vhub 04 Var'};
Res{52,k+1} = vhub2_var;

Res{53,1} = {'Vhub 12 Var'};
Res{53,k+1} = vhub3_var;

Res{54,1} = {'Vhub 14 Var'};
Res{54,k+1} = vhub4_var;


meanmeans = mean(cell2mat(Res(2:12,2:10)),2);
varmeans = mean(cell2mat(Res(14:24,2:10)),2);
pdtmean = sum(cell2mat(Res(26:29,2:10)),2);
DELsmean = mean(cell2mat(Res(31:37,2:10)),2);
Controlssmean = mean(cell2mat(Res(39:54,2:10)),2);

Res{1,11} = {'MeansMeans'};
Res(2:12,11) = num2cell(meanmeans);
Res(14:24,11) = num2cell(varmeans);
Res(26:29,11) = num2cell(pdtmean);
Res(31:37,11) = num2cell(DELsmean);
Res(39:54,11) = num2cell(Controlssmean);



end
if l == 1
	ResBaseline = Res;
    save(['./Results/',baselineFolderName,'\ResBaseline'],'ResBaseline')
else
    ResControl = Res;
    save(['./Results/',controllerFolderName,'\ResControl'],'ResControl')
end
end

%%
StructureMeans = abs(cell2mat(ResControl(2:8,2:11)))./abs(cell2mat(ResBaseline(2:8,2:11)));
PowerMeans = abs(cell2mat(ResControl(9:12,2:11)))./abs(cell2mat(ResBaseline(9:12,2:11)));
StructureVar = abs(cell2mat(ResControl(14:20,2:11)))./abs(cell2mat(ResBaseline(14:20,2:11)));
PowerVar = abs(cell2mat(ResControl(21:24,2:11)))./abs(cell2mat(ResBaseline(21:24,2:11)));
PitchSums = abs(cell2mat(ResControl(26:29,2:11)))./abs(cell2mat(ResBaseline(26:29,2:11)));
StructureMeanDELs = abs(cell2mat(ResControl(31:37,2:11)))./abs(cell2mat(ResBaseline(31:37,2:11)));
ControlMeans = abs(cell2mat(ResControl(39:54,2:11)))./abs(cell2mat(ResBaseline(39:54,2:11)));

ResCompare = Res;
ResCompare(2:8,2:11) = num2cell(StructureMeans);
ResCompare(9:12,2:11) = num2cell(PowerMeans);
ResCompare(14:20,2:11) = num2cell(StructureVar);
ResCompare(21:24,2:11) = num2cell(PowerVar);
ResCompare(26:29,2:11) = num2cell(PitchSums);
ResCompare(31:37,2:11) = num2cell(StructureMeanDELs);
ResCompare(39:54,2:11) = num2cell(ControlMeans);
open ResCompare
save(['./Results/','ResCompare',baselineFolderName,'_',controllerFolderName],'ResCompare')



