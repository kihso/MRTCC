function out=plot_turbine(x,par,viewAng,t)



% Geometry
La02=par.La02;
La04=par.La04;
La12=par.La12;
La14=par.La14;
LNaz=par.LNaz;
Lhub=par.Lhub;
Lt1=par.Lt1;
Lt2=par.Lt2;
Lblade=par.Lblade;
ttilt=par.ttilt;

x1=x(1);
x2=x(2);
x3=x(3);
x4=x(4);
x5=x(5);
x6=x(6);
x7=x(7);
x8=x(8);
x9=x(9);
x10=x(10);

% viewAng=0;
% La02=20;
% La04=20;
% La12=20;
% La14=20;
% LNaz=5;
% LNay=5;
% Lhub=5;
% Lt1=25;
% Lt2=25;
% Lblade=15;
% 
% x1=0;
% x2=0;
% x3=0;
% x4=0;
% x5=0;
% x6=0;
% x7=0;
% x8=0;


%% Rotation matricies and vectors
% Get bending mode shapes
Lt1vec = linspace(0,Lt1,100);
Lt2vec = linspace(0,Lt2,100);

wzt1 = (3*Lt1vec.^2/Lt1^2-2*Lt1vec.^3/Lt1^3)*x3+(-Lt1vec.^2/Lt1^2+Lt1vec.^3/Lt1^3)*Lt1*x5;
wzt2 = (1-3*Lt2vec.^2/Lt2^2+2*Lt2vec.^3/Lt2^3)*x3+(Lt2vec./Lt2-2*Lt2vec.^2/Lt2^2+Lt2vec.^3/Lt2^3)*Lt2*x5+(3*Lt2vec.^2/Lt2^2-2*Lt2vec.^3/Lt2^3)*x4+(-Lt2vec.^2/Lt2^2+Lt2vec.^3/Lt2^3)*Lt2*x6;
wzt3 = wzt2-wzt1(end);

%
Vtower1flex=[zeros(1,length(wzt1));wzt1; -Lt1vec];
Vtower2flex=[zeros(1,length(wzt2));wzt3; -Lt2vec];
Vtower2flex2=[zeros(1,length(wzt2));wzt2; -(Lt2vec-Vtower1flex(3,end))];

VtowerFlexos=[Vtower1flex Vtower2flex2];

Vtower1=Vtower1flex(:,end);
Vtower2=Vtower2flex(:,end);
Varm02=[-La02;0;0];
Varm04=[La04;0;0];
Varm12=[-La12;0;0];
Varm14=[La14;0;0];

VNacHz=[0;0;-LNaz];

VHuby=[0;-Lhub;0];


TyawP0=[cos(x1), sin(x1), 0; -sin(x1), cos(x1), 0; 0,0,1];
TyawP1=[cos(x2), sin(x2), 0; -sin(x2), cos(x2), 0; 0,0,1];
% TyawP0=eye(3);
% TyawP1=eye(3);

TbenxP0=[1,0,0;0,cos(x5),-sin(x5);0,sin(x5),cos(x5)];
TbenxP1=[1,0,0;0,cos(x6),-sin(x6);0,sin(x6),cos(x6)];
% TbenxP0=eye(3);
% TbenxP1=eye(3);

Ttorsion02=[1,0,0;0,cos(x7),sin(x7);0,-sin(x7),cos(x7)];
Ttorsion04=[1,0,0;0,cos(x8),sin(x8);0,-sin(x8),cos(x8)];
Ttorsion12=[1,0,0;0,cos(x9),sin(x9);0,-sin(x9),cos(x9)];
Ttorsion14=[1,0,0;0,cos(x10),sin(x10);0,-sin(x10),cos(x10)];

Ttilt=[1,0,0;0,cos(ttilt),sin(ttilt);0,-sin(ttilt),cos(ttilt)];
% Ttorsion02=eye(3);
% Ttorsion04=eye(3);
% Ttorsion12=eye(3);
% Ttorsion14=eye(3);
t1=t(1);
t2=t(2);
t3=t(3);
t4=t(4);


Tblade1_1=[cos(0+t1),0,sin(0+t1);0,1,0;-sin(0+t1),0,cos(0+t1)];
Tblade2_1=[cos(pi*(2/3)+t1),0,sin(pi*(2/3)+t1);0,1,0;-sin(pi*(2/3)+t1),0,cos(pi*(2/3)+t1)];
Tblade3_1=[cos(pi*(4/3)+t1),0,sin(pi*(4/3)+t1);0,1,0;-sin(pi*(4/3)+t1),0,cos(pi*(4/3)+t1)];

Tblade1_2=[cos(0+t2),0,sin(0+t2);0,1,0;-sin(0+t2),0,cos(0+t2)];
Tblade2_2=[cos(pi*(2/3)+t2),0,sin(pi*(2/3)+t2);0,1,0;-sin(pi*(2/3)+t2),0,cos(pi*(2/3)+t2)];
Tblade3_2=[cos(pi*(4/3)+t2),0,sin(pi*(4/3)+t2);0,1,0;-sin(pi*(4/3)+t2),0,cos(pi*(4/3)+t2)];

Tblade1_3=[cos(0+t3),0,sin(0+t3);0,1,0;-sin(0+t3),0,cos(0+t3)];
Tblade2_3=[cos(pi*(2/3)+t3),0,sin(pi*(2/3)+t3);0,1,0;-sin(pi*(2/3)+t3),0,cos(pi*(2/3)+t3)];
Tblade3_3=[cos(pi*(4/3)+t3),0,sin(pi*(4/3)+t3);0,1,0;-sin(pi*(4/3)+t3),0,cos(pi*(4/3)+t3)];

Tblade1_4=[cos(0+t4),0,sin(0+t4);0,1,0;-sin(0+t4),0,cos(0+t4)];
Tblade2_4=[cos(pi*(2/3)+t4),0,sin(pi*(2/3)+t4);0,1,0;-sin(pi*(2/3)+t4),0,cos(pi*(2/3)+t4)];
Tblade3_4=[cos(pi*(4/3)+t4),0,sin(pi*(4/3)+t4);0,1,0;-sin(pi*(4/3)+t4),0,cos(pi*(4/3)+t4)];

%% Body positions
% LOWER PLATFORM!!!!!
r1=Vtower1;

r2=Vtower1+TbenxP0*TyawP0*Varm02;
r3=Vtower1+TbenxP0*TyawP0*(Varm02+Ttorsion02*VNacHz);
r4=Vtower1+TbenxP0*TyawP0*(Varm02+Ttorsion02*(VNacHz+Ttilt*VHuby));

r5=Vtower1+TbenxP0*TyawP0*Varm04;
r6=Vtower1+TbenxP0*TyawP0*(Varm04+Ttorsion04*VNacHz);
r7=Vtower1+TbenxP0*TyawP0*(Varm04+Ttorsion04*(VNacHz+Ttilt*VHuby));

% Blades
r15=Vtower1+TbenxP0*TyawP0*(Varm02+Ttorsion02*(VNacHz+Ttilt*(VHuby+Tblade1_1*[0;0;-Lblade])));
r16=Vtower1+TbenxP0*TyawP0*(Varm02+Ttorsion02*(VNacHz+Ttilt*(VHuby+Tblade2_1*[0;0;-Lblade])));
r17=Vtower1+TbenxP0*TyawP0*(Varm02+Ttorsion02*(VNacHz+Ttilt*(VHuby+Tblade3_1*[0;0;-Lblade])));

r18=Vtower1+TbenxP0*TyawP0*(Varm04+Ttorsion04*(VNacHz+Ttilt*(VHuby+Tblade1_2*[0;0;-Lblade])));
r19=Vtower1+TbenxP0*TyawP0*(Varm04+Ttorsion04*(VNacHz+Ttilt*(VHuby+Tblade2_2*[0;0;-Lblade])));
r20=Vtower1+TbenxP0*TyawP0*(Varm04+Ttorsion04*(VNacHz+Ttilt*(VHuby+Tblade3_2*[0;0;-Lblade])));

% UPPER PLATFORM!!!!!
r8=Vtower1+Vtower2;

r9=Vtower1+Vtower2+TbenxP1*TyawP1*Varm12;
r10=Vtower1+Vtower2+TbenxP1*TyawP1*(Varm12+Ttorsion12*VNacHz);
r11=Vtower1+Vtower2+TbenxP1*TyawP1*(Varm12+Ttorsion12*(VNacHz+Ttilt*VHuby));

r12=Vtower1+Vtower2+TbenxP1*TyawP1*Varm14;
r13=Vtower1+Vtower2+TbenxP1*TyawP1*(Varm14+Ttorsion14*VNacHz);
r14=Vtower1+Vtower2+TbenxP1*TyawP1*(Varm14+Ttorsion14*(VNacHz+Ttilt*VHuby));

% Blades
r21=Vtower1+Vtower2+TbenxP1*TyawP1*(Varm12+Ttorsion12*(VNacHz+Ttilt*(VHuby+Tblade1_3*[0;0;-Lblade])));
r22=Vtower1+Vtower2+TbenxP1*TyawP1*(Varm12+Ttorsion12*(VNacHz+Ttilt*(VHuby+Tblade2_3*[0;0;-Lblade])));
r23=Vtower1+Vtower2+TbenxP1*TyawP1*(Varm12+Ttorsion12*(VNacHz+Ttilt*(VHuby+Tblade3_3*[0;0;-Lblade])));

r24=Vtower1+Vtower2+TbenxP1*TyawP1*(Varm14+Ttorsion14*(VNacHz+Ttilt*(VHuby+Tblade1_4*[0;0;-Lblade])));
r25=Vtower1+Vtower2+TbenxP1*TyawP1*(Varm14+Ttorsion14*(VNacHz+Ttilt*(VHuby+Tblade2_4*[0;0;-Lblade])));
r26=Vtower1+Vtower2+TbenxP1*TyawP1*(Varm14+Ttorsion14*(VNacHz+Ttilt*(VHuby+Tblade3_4*[0;0;-Lblade])));

%% Plot tower componets
plot3(VtowerFlexos(1,:),VtowerFlexos(2,:),VtowerFlexos(3,:),'k','linewidth',3); hold on;
% plot3([0 r1(1)],[0 r1(2)],[0 r1(3)],'k','linewidth',3); hold on;

plot3([r1(1) r2(1)],[r1(2) r2(2)],[r1(3) r2(3)],'k','linewidth',3);
plot3([r2(1) r3(1)],[r2(2) r3(2)],[r2(3) r3(3)],'k','linewidth',3);
plot3([r3(1) r4(1)],[r3(2) r4(2)],[r3(3) r4(3)],'k','linewidth',3);

% Blades
plot3([r4(1) r15(1)],[r4(2) r15(2)],[r4(3) r15(3)],'k','linewidth',3);
plot3([r4(1) r16(1)],[r4(2) r16(2)],[r4(3) r16(3)],'k','linewidth',3);
plot3([r4(1) r17(1)],[r4(2) r17(2)],[r4(3) r17(3)],'k','linewidth',3);

plot3([r1(1) r5(1)],[r1(2) r5(2)],[r1(3) r5(3)],'k','linewidth',3);
plot3([r5(1) r6(1)],[r5(2) r6(2)],[r5(3) r6(3)],'k','linewidth',3);
plot3([r6(1) r7(1)],[r6(2) r7(2)],[r6(3) r7(3)],'k','linewidth',3);

% Blades
plot3([r7(1) r18(1)],[r7(2) r18(2)],[r7(3) r18(3)],'k','linewidth',3);
plot3([r7(1) r19(1)],[r7(2) r19(2)],[r7(3) r19(3)],'k','linewidth',3);
plot3([r7(1) r20(1)],[r7(2) r20(2)],[r7(3) r20(3)],'k','linewidth',3);

% plot3([r1(1) r8(1)],[r1(2) r8(2)],[r1(3) r8(3)],'k','linewidth',3);

plot3([r8(1) r9(1)],[r8(2) r9(2)],[r8(3) r9(3)],'k','linewidth',3);
plot3([r9(1) r10(1)],[r9(2) r10(2)],[r9(3) r10(3)],'k','linewidth',3);
plot3([r10(1) r11(1)],[r10(2) r11(2)],[r10(3) r11(3)],'k','linewidth',3);

% Blades
plot3([r11(1) r21(1)],[r11(2) r21(2)],[r11(3) r21(3)],'k','linewidth',3);
plot3([r11(1) r22(1)],[r11(2) r22(2)],[r11(3) r22(3)],'k','linewidth',3);
plot3([r11(1) r23(1)],[r11(2) r23(2)],[r11(3) r23(3)],'k','linewidth',3);

plot3([r8(1) r12(1)],[r8(2) r12(2)],[r8(3) r12(3)],'k','linewidth',3);
plot3([r12(1) r13(1)],[r12(2) r13(2)],[r12(3) r13(3)],'k','linewidth',3);
plot3([r13(1) r14(1)],[r13(2) r14(2)],[r13(3) r14(3)],'k','linewidth',3);

% Blades
plot3([r14(1) r24(1)],[r14(2) r24(2)],[r14(3) r24(3)],'k','linewidth',3);
plot3([r14(1) r25(1)],[r14(2) r25(2)],[r14(3) r25(3)],'k','linewidth',3);
plot3([r14(1) r26(1)],[r14(2) r26(2)],[r14(3) r26(3)],'k','linewidth',3);

xlim([-100 100])
ylim([-100 100])
zlim([-Lt2-Lt1-LNaz-LNaz-Lblade*2 0])
grid on
set(gca, 'ZDir', 'reverse')
xlabel('x axis')
ylabel('y axis')
if viewAng == 1
view(90,0)
else
end
axis equal

end