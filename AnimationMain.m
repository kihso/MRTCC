%% Plot and Animate 
ScaleAnimationParam = 10; % Used to scale the movement of the animation
ShowAnimation = 1;
AnimateBenchMark = 1;

figure(1);
set(1,'Units', 'Normalized', 'OuterPosition', [0 0 1 1])

% Plot and Animate for Specific wind speed.
AniPlotWS = 'WS12';
BaselineName = 'Baseline';
BenchMarkName = 'VestasControl';

BaselineStruct = load(strcat('.\Results\',BaselineName,'\',AniPlotWS,'\','TurbineData.mat'))
wg1_bl = BaselineStruct.Turbine_Output.Data(:,9);
wg2_bl = BaselineStruct.Turbine_Output.Data(:,10);
wg3_bl = BaselineStruct.Turbine_Output.Data(:,11);
wg4_bl = BaselineStruct.Turbine_Output.Data(:,12);
x_bl = BaselineStruct.x;
T_bl = BaselineStruct.T;

if AnimateBenchMark == 1
BenchmarkStruct = load(strcat('.\Results\',BenchMarkName,'\',AniPlotWS,'\','TurbineData.mat'))
wg1_bm = BenchmarkStruct.Turbine_Output.Data(:,9);
wg2_bm = BenchmarkStruct.Turbine_Output.Data(:,10);
wg3_bm = BenchmarkStruct.Turbine_Output.Data(:,11);
wg4_bm = BenchmarkStruct.Turbine_Output.Data(:,12);
x_bm = BenchmarkStruct.x;
T_bm = BenchmarkStruct.T;
else
end

clear frameNum
count = 1;
rotscale=600;

if ShowAnimation == 1
    for i = 1:100:length(x_bl)
    figure(1)
    if AnimateBenchMark == 1
    subplot(1,2,2)
    else
    subplot(1,1,1)    
    end
    theta1_bl = -trapz(T_bl(1:i),wg1_bl(1:i))/(rotscale);
    theta2_bl = -trapz(T_bl(1:i),wg2_bl(1:i))/(rotscale);
    theta3_bl = -trapz(T_bl(1:i),wg3_bl(1:i))/(rotscale);
    theta4_bl = -trapz(T_bl(1:i),wg4_bl(1:i))/(rotscale);
    wg_bl = [theta1_bl theta2_bl theta3_bl theta4_bl];

    plot_turbine(x_bl(i,:).'*ScaleAnimationParam,par,viewpar,wg_bl); hold on
    plot_grass(120);
    xlim([-150 150])
    ylim([-150 150])    
    zlim([-300 1])   
    title('Baseline','fontsize',32)
    hold off; drawnow update

	if AnimateBenchMark == 1
    subplot(1,2,1)
    theta1_bm = -trapz(T_bm(1:i),wg1_bm(1:i))/(rotscale);
    theta2_bm = -trapz(T_bm(1:i),wg2_bm(1:i))/(rotscale);
    theta3_bm = -trapz(T_bm(1:i),wg3_bm(1:i))/(rotscale);
    theta4_bm = -trapz(T_bm(1:i),wg4_bm(1:i))/(rotscale);
    wg_bm = [theta1_bm theta2_bm theta3_bm theta4_bm];

    plot_turbine(x_bm(i,:).'*ScaleAnimationParam,par,viewpar,wg_bm); hold on
    plot_grass(120);
    xlim([-150 150])
    ylim([-150 150])    
    zlim([-300 1])   
    title('Benchmark','fontsize',32)
	else
	end
    %axis equal
    hold off; drawnow update
    frameNum(count)=getframe(gcf);
    count = count + 1;
    end
else

%     subplot(3,4,[3 4 7 8 11 12])
    plot_turbine(x(1,:).',par,viewpar,T(i)); hold on
    plot_grass(120);
    hold off; drawnow update
% $$$     frameNum(i)=getframe(gcf);          % TK: Skip this line?
end

%% Generate Video Code       
% MovieName='Baseline_at_rated';
% video = VideoWriter(MovieName,'MPEG-4');
% video.FrameRate=10.82;
% open(video) 
% writeVideo(video,frameNum);
% close(video) 

